
/*

  KLayout Layout Viewer
  Copyright (C) 2006-2020 Matthias Koefferlein

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*/

/*
  @@@ TODO:
  * Make 3DFACE vs. SOLID configurable, document
*/

#include "dbDXFWriter.h"
#include "dbPolygonGenerators.h"
#include "dbPolygonTools.h"
#include "tlStream.h"
#include "tlUtils.h"
#include "tlUniqueName.h"

#include <time.h>
#include <string.h>
#include <ctype.h>

namespace db
{

// ---------------------------------------------------------------------------------
//  DXFWriter implementation

DXFWriter::DXFWriter ()
  : mp_stream (0),
    m_progress (tl::to_string (tr ("Writing DXF file")), 10000),
    m_use_zinfo (true)
{
  m_progress.set_format (tl::to_string (tr ("%.0f MB")));
  m_progress.set_unit (1024 * 1024);
}

DXFWriter &
DXFWriter::operator<<(const char *s)
{
  mp_stream->put(s, strlen(s));
  return *this;
}

DXFWriter &
DXFWriter::operator<<(const std::string &s)
{
  mp_stream->put(s.c_str(), s.size());
  return *this;
}

DXFWriter &
DXFWriter::operator<<(endl_tag)
{
#ifdef _WIN32
  *this << "\r\n";
#else
  *this << "\n";
#endif
  return *this;
}

void
DXFWriter::write (const db::Layout &layout, const db::Cell &cref, const std::set <db::cell_index_type> &cell_set, const std::vector <std::pair <unsigned int, db::LayerProperties> > &layers, double sf)
{
  m_dxf_zstart_id = layout.properties_repository ().get_id_of_name (tl::Variant ("dxf_zstart"));
  m_dxf_zstop_id = layout.properties_repository ().get_id_of_name (tl::Variant ("dxf_zstop"));

  //  instances
  for (db::Cell::const_iterator inst = cref.begin (); ! inst.at_end (); ++inst) {

    //  write only instances to selected cells
    if (cell_set.find (inst->cell_index ()) != cell_set.end ()) {

      m_progress.set (mp_stream->pos ());

      // resolve instance arrays
      for (db::Cell::cell_inst_array_type::iterator pp = inst->begin (); ! pp.at_end (); ++pp) {

        // convert the transformation into DXF's notation
        db::DCplxTrans t (inst->complex_trans (*pp));
        db::DVector d (t.disp());

        *this << 0 << endl << "INSERT" << endl;
        *this << 8 << endl << 0 << endl;  // required by TrueView
        *this << 2 << endl << m_cell_names [inst->cell_index ()] << endl;
        *this << 10 << endl << d.x () * sf << endl;
        *this << 20 << endl << d.y () * sf << endl;
        if (m_use_zinfo) {
            *this << 30 << endl << 0.0 << endl;
        }
        *this << 41 << endl << t.mag () << endl;
        *this << 42 << endl << (t.is_mirror () ? -t.mag () : t.mag ()) << endl;
        *this << 50 << endl << t.angle () << endl;

      }

    }

  }

  //  shapes
  for (std::vector <std::pair <unsigned int, db::LayerProperties> >::const_iterator l = layers.begin (); l != layers.end (); ++l) {

    m_layer = l->second;

    write_texts (layout, cref, l->first, sf);
    write_polygons (layout, cref, l->first, sf);
    write_paths (layout, cref, l->first, sf);
    write_boxes (layout, cref, l->first, sf);

    m_progress.set (mp_stream->pos ());

  }
}

static std::string legal_name (const char *name, std::set<std::string> &used_names)
{
  //  some empirical value
  const int legal_name_length = 30;

  std::string n;
  n.reserve (strlen (name));

  for (const char *cp = name; *cp; ++cp) {
    if (isalnum (*cp) || *cp == '_' || *cp == '*') {
      n += *cp;
    } else {
      n += "_";
    }
  }

  return tl::unique_name_store (n, used_names, "_", legal_name_length);
}

void 
DXFWriter::write (db::Layout &layout, tl::OutputStream &stream, const db::SaveLayoutOptions &options)
{
  m_options = options.get_options<DXFWriterOptions> ();
  mp_stream = &stream;

  //  compute the scale factor 
  double sf = options.scale_factor () * layout.dbu ();

  std::vector <std::pair <unsigned int, db::LayerProperties> > layers;
  options.get_valid_layers (layout, layers, db::SaveLayoutOptions::LP_AssignName);

  std::set <db::cell_index_type> cell_set;
  options.get_cells (layout, cell_set, layers);

  //  create a cell index vector sorted bottom-up and determine top cell
  std::vector <db::cell_index_type> cells;
  cells.reserve (cell_set.size ());
  const db::Cell *top_cell = 0;

  for (db::Layout::bottom_up_const_iterator cell = layout.begin_bottom_up (); cell != layout.end_bottom_up (); ++cell) {

    if (cell_set.find (*cell) != cell_set.end ()) {

      //  determine if the current cell is a top-level cell
      bool is_top_cell = true;
      std::set <db::cell_index_type> caller_cells;
      layout.cell (*cell).collect_caller_cells(caller_cells);
      for (std::set <db::cell_index_type>::const_iterator cc = caller_cells.begin (); cc != caller_cells.end () && is_top_cell; ++cc) {
        if (cell_set.find (*cc) != cell_set.end ()) {
          is_top_cell = false;
        }
      }

      if (is_top_cell) {
        if (top_cell) {
          throw tl::Exception (tl::to_string (tr ("Top-level cell is not unique - DXF can only store a single top cell")));
        } else {
          top_cell = &layout.cell (*cell);
        }
      } else {
        cells.push_back (*cell);
      }

    }

  }

  db::Box ext (0, 0, 0, 0);
  if (top_cell) {
    ext = top_cell->bbox ();
  }

  //  build a name map for legal names
  
  std::set<std::string> used_names;
  m_cell_names.clear ();

  for (std::vector<db::cell_index_type>::const_iterator cell = cells.begin (); cell != cells.end (); ++cell) {
    m_cell_names.insert (std::make_pair (*cell, legal_name (layout.cell_name (*cell), used_names)));
  }

  //  header
  *this << 0 << endl << "SECTION" << endl;
  *this << 2 << endl << "HEADER" << endl;
  //  fake a dummy AutoCAD version (apparent required by some tools)
  *this << 9 << endl << "$ACADVER" << endl;
  *this << 1 << endl << "AC1006" << endl;
  //  extensions
  //  TODO: z extension too?
  *this << 9 << endl << "$INSBASE" << endl;
  *this << 10 << endl << 0 << endl;
  *this << 20 << endl << 0 << endl;
  *this << 30 << endl << 0 << endl;
  *this << 9 << endl << "$EXTMIN" << endl;
  *this << 10 << endl << ext.left () * sf << endl;
  *this << 20 << endl << ext.bottom () * sf << endl;
  *this << 30 << endl << 0 << endl;
  *this << 9 << endl << "$EXTMAX" << endl;
  *this << 10 << endl << ext.right () * sf << endl;
  *this << 20 << endl << ext.top () * sf << endl;
  *this << 30 << endl << 0 << endl;
  *this << 0 << endl << "ENDSEC" << endl;

  //  layer table
  *this << 0 << endl << "SECTION" << endl;
  *this << 2 << endl << "TABLES" << endl;
  *this << 0 << endl << "TABLE" << endl;
  *this << 2 << endl << "LAYER" << endl;
  *this << 70 << endl << layers.size () << endl;

  //  colors are simply numbered starting from 1 currently, linestyle is "CONTINUOUS" currently.
  int color = 1;
  std::string linestyle = "CONTINUOUS";

  for (std::vector <std::pair <unsigned int, db::LayerProperties> >::const_iterator l = layers.begin (); l != layers.end (); ++l) {

    *this << 0 << endl << "LAYER" << endl;
    *this << 70 << endl << 0 << endl;               //  flags: seems to be required by some tools
    *this << 62 << endl << color << endl;           //  color
    *this << 6 << endl << linestyle << endl;     //  line style
    *this << 2 << endl;
    emit_layer (l->second);

    color += 1;

  }

  *this << 0 << endl << "ENDTAB" << endl;
  *this << 0 << endl << "ENDSEC" << endl;

  //  body
  *this << 0 << endl << "SECTION" << endl;
  *this << 2 << endl << "BLOCKS" << endl;

  for (std::vector<db::cell_index_type>::const_iterator cell = cells.begin (); cell != cells.end (); ++cell) {

    m_progress.set (mp_stream->pos ());

    //  cell body 
    const db::Cell &cref (layout.cell (*cell));
    const std::string &cell_name = m_cell_names [*cell];

    *this << 0 << endl << "BLOCK" << endl;
    *this << 2 << endl << cell_name << endl;

    //  this has been determined empirically with TrueView:
    int flags = (cell_name [0] == '*' ? 1 : 0); 
    *this << 70 << endl << flags << endl;

    //  base point x, y
    *this << 10 << endl << 0.0 << endl;
    *this << 20 << endl << 0.0 << endl;
    if (m_use_zinfo) {
        *this << 30 << endl << 0.0 << endl;
    }

    //  write cell
    write (layout, cref, cell_set, layers, sf);

    //  end of cell
    *this << 0 << endl << "ENDBLK" << endl;

  }

  *this << 0 << endl << "ENDSEC" << endl;

  //  entities (empty)
  *this << 0 << endl << "SECTION" << endl;
  *this << 2 << endl << "ENTITIES" << endl;

  m_progress.set (mp_stream->pos ());

  //  write top cell
  if (top_cell) {
    write (layout, *top_cell, cell_set, layers, sf);
  }

  *this << 0 << endl << "ENDSEC" << endl;

  //  end of file
  *this << 0 << endl << "EOF" << endl;

  m_progress.set (mp_stream->pos ());

}

void 
DXFWriter::emit_layer(const db::LayerProperties &lp)
{
  if (lp.layer == 0 && lp.datatype == 0 && lp.name == "L0D0") {
    // zero layer
    *this << "0" << endl;
  } else {
    *this << lp.name << endl;
  }
}

const DXFWriter::ZInfo *
DXFWriter::zinfo (const db::Layout &layout, db::properties_id_type prop_id)
{
  if (! m_use_zinfo) {
    return 0;
  }

  static ZInfo flat (0, 0);

  if (! prop_id || ! m_dxf_zstart_id.first || ! m_dxf_zstop_id.first) {
    return &flat;
  }

  std::map<db::properties_id_type, const ZInfo *>::const_iterator p = m_zinfo_from_prop_id.find (prop_id);
  if (p != m_zinfo_from_prop_id.end ()) {
    return p->second;
  }

  const db::PropertiesRepository::properties_set &ps = layout.properties_repository ().properties (prop_id);

  db::PropertiesRepository::properties_set::const_iterator i, j;
  i = ps.find (m_dxf_zstart_id.second);
  j = ps.find (m_dxf_zstop_id.second);
  if (i != ps.end () && i->first == m_dxf_zstart_id.second && j != ps.end () && j->first == m_dxf_zstop_id.second) {

    db::Coord zstart = i->second.to<db::Coord> ();
    db::Coord zstop = j->second.to<db::Coord> ();

    m_zinfo.push_back (ZInfo (zstart, zstop));
    m_zinfo_from_prop_id.insert (std::make_pair (prop_id, &m_zinfo.back ()));

    return &m_zinfo.back ();

  } else {
    return &flat;
  }
}

void 
DXFWriter::write_texts (const db::Layout & /*layout*/, const db::Cell &cell, unsigned int layer, double sf)
{
  db::ShapeIterator shape (cell.shapes (layer).begin (db::ShapeIterator::Texts));
  while (! shape.at_end ()) {

    m_progress.set (mp_stream->pos ());

    db::Vector p (shape->text_trans ().disp ());

    // use MTEXT if the text contains line feeds.
    // split the text into chunks with less than 250 characters
    std::string s = shape->text_string ();
    std::vector<std::string> chunks;
    chunks.push_back (std::string ());
    bool use_mtext = false;
    for (const char *c = s.c_str (); *c; c++) {
      if (*c == '\n') {
        use_mtext = true;
        if (chunks.back ().size () > 248) {
          chunks.push_back (std::string ());
        }
        chunks.back () += "\\P";
      } else if ((unsigned char)*c >= (unsigned char)32) {
        if (chunks.back ().size () > 249) {
          chunks.push_back (std::string ());
        }
        chunks.back () += *c;
      }
    }

    if (use_mtext) {

      *this << 0 << endl << "MTEXT" << endl;
      *this << 8 << endl; emit_layer (m_layer);
      *this << 10 << endl << p.x () * sf << endl;
      *this << 20 << endl << p.y () * sf << endl;
      if (m_use_zinfo) {
        //  TODO: enable z position?
        *this << 30 << endl << 0.0 << endl;
      }
      *this << 40 << endl << shape->text_size () * sf << endl;

      int v = 1;
      db::HAlign halign = shape->text_halign ();
      if (halign == db::HAlignLeft) {
        v += 0;
      } else if (halign == db::HAlignCenter) {
        v += 1;
      } else if (halign == db::HAlignRight) {
        v += 2;
      }
      db::VAlign valign = shape->text_valign ();
      if (valign == db::VAlignTop) {
        v += 0;
      } else if (valign == db::VAlignCenter) {
        v += 3;
      } else if (valign == db::VAlignBottom) {
        v += 6;
      }
      *this << 71 << endl << v << endl;
      *this << 72 << endl << 0 << endl;

      for (size_t i = 0; i + 1 < chunks.size (); ++i) {
        *this << 3 << endl << chunks [i] << endl;
      }
      *this << 1 << endl << chunks.back () << endl;

      *this << 50 << endl << (shape->text_trans ().rot () % 4) * 90.0 << endl;

    } else {

      *this << 0 << endl << "TEXT" << endl;
      *this << 8 << endl; emit_layer (m_layer);
      *this << 10 << endl << p.x () * sf << endl;
      *this << 20 << endl << p.y () * sf << endl;
      if (m_use_zinfo) {
        //  TODO: enable z position?
        *this << 30 << endl << 0.0 << endl;
      }
      *this << 40 << endl << shape->text_size () * sf << endl;
      *this << 1 << endl << chunks.front () << endl;
      *this << 50 << endl << (shape->text_trans ().rot () % 4) * 90.0 << endl;

      db::HAlign halign = shape->text_halign ();
      if (halign == db::HAlignLeft) {
        *this << 72 << endl << 0 << endl;
      } else if (halign == db::HAlignCenter) {
        *this << 72 << endl << 1 << endl;
      } else if (halign == db::HAlignRight) {
        *this << 72 << endl << 2 << endl;
      }

      *this << 11 << endl << p.x () * sf << endl;
      *this << 21 << endl << p.y () * sf << endl;

      db::VAlign valign = shape->text_valign ();
      if (valign == db::VAlignTop) {
        *this << 73 << endl << 3 << endl;
      } else if (valign == db::VAlignCenter) {
        *this << 73 << endl << 2 << endl;
      } else if (valign == db::VAlignBottom) {
        *this << 73 << endl << 0 << endl;
      }

    }

    ++shape;

  }
}

void 
DXFWriter::write_polygons (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double sf)
{
  db::ShapeIterator shape (cell.shapes (layer).begin (db::ShapeIterator::Polygons));
  while (! shape.at_end ()) {

    m_progress.set (mp_stream->pos ());

    db::Polygon poly;
    shape->polygon (poly);
    write_polygon (poly, sf, zinfo (layout, shape->prop_id ()));

    ++shape;

  }
}

void 
DXFWriter::write_polygon (const db::Polygon &polygon, double sf, const ZInfo *zinfo, bool internal)
{
  if (m_options.polygon_mode == 0) {

    for (unsigned int c = 0; c < polygon.holes () + 1; ++c) {

      *this << 0 << endl << "POLYLINE" << endl;
      *this << 8 << endl; emit_layer (m_layer);
      if (zinfo) {
        *this << 30 << endl << zinfo->z () * sf << endl;
        *this << 39 << endl << zinfo->dz () * sf << endl;
      }
      *this << 70 << endl << 1 << endl;
      *this << 40 << endl << 0.0 << endl;
      *this << 41 << endl << 0.0 << endl;
      *this << 66 << endl << 1 << endl;  //  required by TrueView

      for (db::Polygon::polygon_contour_iterator p = polygon.contour (c).begin (); p != polygon.contour (c).end (); ++p) {
        *this << 0 << endl << "VERTEX" << endl;
        *this << 8 << endl; emit_layer (m_layer);  //  required by TrueView
        *this << 10 << endl << (*p).x () * sf << endl;
        *this << 20 << endl << (*p).y () * sf << endl;
      }

      *this << 0 << endl << "SEQEND" << endl;

    }

  } else if (m_options.polygon_mode == 1) {

    for (unsigned int c = 0; c < polygon.holes () + 1; ++c) {

      *this << 0 << endl << "LWPOLYLINE" << endl;
      *this << 8 << endl; emit_layer (m_layer);
      if (zinfo) {
        *this << 38 << endl << zinfo->z () * sf << endl;
        *this << 39 << endl << zinfo->dz () * sf << endl;
      }
      *this << 90 << endl << polygon.contour (0).size () << endl;
      *this << 70 << endl << 1 << endl;
      *this << 43 << endl << 0.0 << endl;

      for (db::Polygon::polygon_contour_iterator p = polygon.contour (c).begin (); p != polygon.contour (c).end (); ++p) {
        *this << 10 << endl << (*p).x () * sf << endl;
        *this << 20 << endl << (*p).y () * sf << endl;
      }

    }

  } else if (m_options.polygon_mode == 2) {

    if (polygon.holes () > 0 || ! internal) {

      //  resolve holes or merge polygon as a preparation step for split_polygon which only works properly
      //  on merged polygons ...
      std::vector<db::Polygon> polygons;

      db::EdgeProcessor ep;
      ep.insert_sequence (polygon.begin_edge ());
      db::PolygonContainer pc (polygons);
      db::PolygonGenerator out (pc, true /*resolve holes*/, false /*min coherence for splitting*/);
      db::SimpleMerge op;
      ep.process (out, op);

      for (std::vector<db::Polygon>::const_iterator p = polygons.begin (); p != polygons.end (); ++p) {
        write_polygon (*p, sf, zinfo, true);
      }

      if (zinfo && zinfo->dz () > 0) {

        //  For the walls use the polygons with holes
        ep.clear ();
        polygons.clear ();

        ep.insert_sequence (polygon.begin_edge ());
        db::PolygonContainer pc (polygons);
        db::PolygonGenerator out (pc, false /*don't resolve holes*/, false /*min coherence for splitting*/);
        db::SimpleMerge op;
        ep.process (out, op);

        for (std::vector<db::Polygon>::const_iterator p = polygons.begin (); p != polygons.end (); ++p) {

          double z1 = zinfo->z () * sf;
          double z2 = (zinfo->z () + zinfo->dz ()) * sf;

          //  build a SOLID/3DFACE wall from the edges
          for (db::Polygon::polygon_edge_iterator e = p->begin_edge (); ! e.at_end (); ++e) {

            db::DEdge ee = db::DEdge (*e) * sf;

            *this << 0 << endl << (!m_use_zinfo ? "SOLID" : "3DFACE") << endl;
            *this << 8 << endl; emit_layer (m_layer);

            *this << 10 << endl << ee.p1 ().x () << endl;
            *this << 20 << endl << ee.p1 ().y () << endl;
            *this << 30 << endl << z1 << endl;

            *this << 11 << endl << ee.p2 ().x () << endl;
            *this << 21 << endl << ee.p2 ().y () << endl;
            *this << 31 << endl << z1 << endl;

            *this << 12 << endl << ee.p2 ().x () << endl;
            *this << 22 << endl << ee.p2 ().y () << endl;
            *this << 32 << endl << z2 << endl;

            *this << 13 << endl << ee.p1 ().x () << endl;
            *this << 23 << endl << ee.p1 ().y () << endl;
            *this << 33 << endl << z2 << endl;

          }

        }

      }

    } else if (polygon.vertices () > 4) {

      std::vector <db::Polygon> polygons;
      db::split_polygon (polygon, polygons);
      for (std::vector<db::Polygon>::const_iterator p = polygons.begin (); p != polygons.end (); ++p) {
        write_polygon (*p, sf, zinfo, true);
      }

    } else if (polygon.vertices () >= 3) {

      for (int with_z = 0; with_z < 2; ++with_z) {

        if (with_z > 0 && (! zinfo || zinfo->dz () <= 0)) {
          break;
        }

        *this << 0 << endl << (!m_use_zinfo ? "SOLID" : "3DFACE") << endl;
        *this << 8 << endl; emit_layer (m_layer);

        double x [4], y [4];
        unsigned int i = 0;
        for (db::Polygon::polygon_contour_iterator p = polygon.begin_hull (); p != polygon.end_hull (); ++p) {
          x [i] = (*p).x () * sf;
          y [i] = (*p).y () * sf;
          ++i;
        }
        std::reverse (x, x + i);
        std::reverse (y, y + i);

        double z = 0.0;
        if (zinfo) {
          if (with_z == 0) {
            z = zinfo->z () * sf;
          } else {
            z = (zinfo->z () + zinfo->dz ()) * sf;
          }
        }

        *this << 10 << endl << x[0] << endl;
        *this << 20 << endl << y[0] << endl;
        if (zinfo) {
          *this << 30 << endl << z << endl;
        }
        *this << 11 << endl << x[1] << endl;
        *this << 21 << endl << y[1] << endl;
        if (zinfo) {
          *this << 31 << endl << z << endl;
        }
        *this << 12 << endl << x[2] << endl;
        *this << 22 << endl << y[2] << endl;
        if (zinfo) {
          *this << 32 << endl << z << endl;
        }
        *this << 13 << endl << x[i == 4 ? 3 : 2] << endl;
        *this << 23 << endl << y[i == 4 ? 3 : 2] << endl;
        if (zinfo) {
          *this << 33 << endl << z << endl;
        }

      }

    }

  } else if (m_options.polygon_mode == 3) {

    *this << 0 << endl << "HATCH" << endl;
    *this << 8 << endl; emit_layer (m_layer);
    if (zinfo) {
      *this << 39 << endl << zinfo->dz () * sf << endl;
    }
    *this << 70 << endl << 1 << endl; // solid fill

    *this << 91 << endl << polygon.holes () + 1 << endl;

    for (unsigned int c = 0; c < polygon.holes () + 1; ++c) {
      *this << 92 << endl << 3 << endl; // external polyline
      *this << 72 << endl << 0 << endl; // has bulge flag
      *this << 73 << endl << 1 << endl; // closed flag
      *this << 93 << endl << polygon.contour (c).size () << endl;
      for (db::Polygon::polygon_contour_iterator p = polygon.contour (c).begin (); p != polygon.contour (c).end (); ++p) {
        *this << 10 << endl << (*p).x () * sf << endl;
        *this << 20 << endl << (*p).y () * sf << endl;
        if (zinfo) {
          *this << 30 << endl << zinfo->z () * sf << endl;
        }
      }
    }

  } else if (m_options.polygon_mode == 4) {
    //--------------------------------------------------------------------------------------
    // Last modified by: Kazzz-S on October 21, 2018 (newly added)
    //
    // Description: When importing a DXF file comprising POLYLINEs or LWPOLYLINEs into 
    //              Abaqus CAE, they are forcibly converted to points! 
    //                *** This is a "specification" of Abaqus CAE. ***
    //              In contrast, LINEs are kept as lines, which will be then assembled into 
    //              polygonal objects internally if required.
    //--------------------------------------------------------------------------------------
    for (unsigned int c = 0; c < polygon.holes () + 1; ++c) {

      for (db::Polygon::polygon_contour_iterator p = polygon.contour (c).begin (); p != polygon.contour (c).end (); ++p) {
        db::Polygon::polygon_contour_iterator q = p + 1;

        if (q == polygon.contour (c).end ()) {
          q = polygon.contour (c).begin ();
        }

        *this << 0 << endl << "LINE" << endl;
        *this << 8 << endl; emit_layer (m_layer);
        if (zinfo) {
          *this << 39 << endl << zinfo->dz () * sf << endl;
        }
        *this << 66 << endl << 1 << endl;  //  required by TrueView
        *this << 10 << endl << (*p).x () * sf << endl;
        *this << 20 << endl << (*p).y () * sf << endl;
        if (zinfo) {
          *this << 30 << endl << zinfo->z () * sf << endl;
        }
        *this << 11 << endl << (*q).x () * sf << endl;
        *this << 21 << endl << (*q).y () * sf << endl;
        if (zinfo) {
          *this << 31 << endl << zinfo->z () * sf << endl;
        }
      }
    }
  }
  
}

void 
DXFWriter::write_boxes (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double sf)
{
  db::ShapeIterator shape (cell.shapes (layer).begin (db::ShapeIterator::Boxes));
  while (! shape.at_end ()) {

    //  TODO: write as SOLID's?
    m_progress.set (mp_stream->pos ());
    db::Polygon p (shape->bbox ());
    write_polygon (p, sf, zinfo (layout, shape->prop_id ()));

    ++shape;

  }
}

void 
DXFWriter::write_paths (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double sf)
{
  db::ShapeIterator shape (cell.shapes (layer).begin (db::ShapeIterator::Paths));
  while (! shape.at_end ()) {

    const ZInfo *zi = zinfo (layout, shape->prop_id ());

    m_progress.set (mp_stream->pos ());

    size_t npts = 0;
    for (db::Shape::point_iterator p = shape->begin_point (); p != shape->end_point (); ++p) {
      ++npts;
    }

    if (m_options.path_mode == 2) {

      //  convert paths to polygons - polygon mode applies
      db::Polygon poly;
      shape->polygon (poly);
      write_polygon (poly, sf, zi);

    } else if (shape->round_path () && npts == 1) {

      db::Point pp (*shape->begin_point ());

      *this << 0 << endl << "CIRCLE" << endl;
      *this << 8 << endl; emit_layer (m_layer);
      if (zi) {
        *this << 39 << endl << zi->dz () * sf << endl;
      }
      *this << 10 << endl << pp.x () * sf << endl;
      *this << 20 << endl << pp.y () * sf << endl;
      if (zi) {
        *this << 30 << endl << zi->z () * sf << endl;
      }
      *this << 40 << endl << shape->path_width () * sf * 0.5 << endl;

    } else if (shape->round_path ()) {

      //  emit round paths as polygons
      db::Polygon poly;
      shape->polygon (poly);
      write_polygon (poly, sf, zi);

    } else {

      if (m_options.path_mode == 1) {

        *this << 0 << endl << "LWPOLYLINE" << endl;
        *this << 8 << endl; emit_layer (m_layer);
        if (zi) {
          *this << 38 << endl << zi->z () * sf << endl;
          *this << 39 << endl << zi->dz () * sf << endl;
        }
        size_t n = 0;
        for (db::Shape::point_iterator p = shape->begin_point (); p != shape->end_point (); ++p, ++n)
          ;
        *this << 90 << endl << n << endl;
        *this << 70 << endl << 0 << endl;
        *this << 43 << endl << shape->path_width () * sf << endl;

      } else {

        *this << 0 << endl << "POLYLINE" << endl;
        *this << 8 << endl; emit_layer (m_layer);
        if (zi) {
          *this << 30 << endl << zi->z () * sf << endl;
          *this << 39 << endl << zi->dz () * sf << endl;
        }
        *this << 70 << endl << 0 << endl;
        *this << 40 << endl << shape->path_width () * sf << endl;
        *this << 41 << endl << shape->path_width () * sf << endl;
        *this << 66 << endl << 1 << endl;  //  required by TrueView

      }

      size_t n = 0;
      std::pair<db::Coord, db::Coord> ext = shape->path_extensions ();

      db::DPoint plast;

      for (db::Shape::point_iterator p = shape->begin_point (); p != shape->end_point (); ++p) {

        db::DPoint pp (db::DPoint (*p) * sf);

        //  correct extensions if required
        if (n == 0 && ext.first != 0) {

          db::Shape::point_iterator q = shape->begin_point ();
          db::DPoint pnext;
          if (q != shape->end_point ()) {
            ++q;
            if (q != shape->end_point ()) {
              pnext = db::DPoint (*q) * sf;
            }
          }

          db::DVector v (pnext - pp);
          double lv = v.double_length ();
          if (lv >= 1e-6) {
            v = v * (1.0 / lv);
            pp = pp + v * (-ext.first * sf);
          }

        } else if (n == npts - 1 && ext.second != 0) {

          db::DVector v (pp - plast);
          double lv = v.double_length ();
          if (lv >= 1e-6) {
            v = v * (1.0 / lv);
            pp = pp + v * (ext.second * sf);
          }

        }

        if (m_options.path_mode != 1) {
          *this << 0 << endl << "VERTEX" << endl;
          *this << 8 << endl; emit_layer (m_layer);  //  required by TrueView
        }
        *this << 10 << endl << pp.x () << endl;
        *this << 20 << endl << pp.y () << endl;

        plast = pp;
        ++n;

      }

      *this << 0 << endl << "SEQEND" << endl;

    }

    ++shape;

  }
}

}


