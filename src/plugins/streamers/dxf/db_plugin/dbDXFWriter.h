
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

#ifndef HDR_dbDXFWriter
#define HDR_dbDXFWriter

#include "dbPluginCommon.h"
#include "dbWriter.h"
#include "dbDXF.h"
#include "dbDXFFormat.h"
#include "dbSaveLayoutOptions.h"
#include "tlProgress.h"

namespace tl
{
  class OutputStream;
}

namespace db
{

class Layout;
class SaveLayoutOptions;

/**
 *  @brief A DXF writer abstraction
 */
class DB_PLUGIN_PUBLIC DXFWriter
  : public db::WriterBase
{
public:
  /**
   *  @brief Instantiate the writer
   */
  DXFWriter ();

  /**
   *  @brief Write the layout object
   */
  void write (db::Layout &layout, tl::OutputStream &stream, const db::SaveLayoutOptions &options);

private:
  struct endl_tag { };

  struct ZInfo {

    ZInfo () : zstart (0), zstop (0) {}
    ZInfo (db::Coord _zstart, db::Coord _zstop) : zstart (_zstart), zstop (_zstop) {}

    db::Coord zstart, zstop;

    db::Coord z() const { return zstart < zstop ? zstart : zstop; }
    db::Coord dz() const { return zstart < zstop ? zstop - zstart : zstart - zstop; }

  };

  tl::OutputStream *mp_stream;
  db::DXFWriterOptions m_options;
  tl::AbsoluteProgress m_progress;
  endl_tag endl;
  db::LayerProperties m_layer;
  std::map<db::properties_id_type, const ZInfo *> m_zinfo_from_prop_id;
  std::list<ZInfo> m_zinfo;
  bool m_use_zinfo;
  std::pair<bool, db::property_names_id_type> m_dxf_zstart_id, m_dxf_zstop_id;
  
  DXFWriter &operator<<(const char *s);
  DXFWriter &operator<<(const std::string &s);
  DXFWriter &operator<<(endl_tag); 

  template<class X> DXFWriter &operator<<(const X &x) 
  {
    return (*this << tl::to_string(x));
  }

  void write_texts (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double tl_scale);
  void write_polygons (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double tl_scale);
  void write_polygon (const db::Polygon &polygon, double tl_scale, const ZInfo *zinfo, bool internal = false);
  void write_boxes (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double tl_scale);
  void write_paths (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double tl_scale);
  void write_edges (const db::Layout &layout, const db::Cell &cell, unsigned int layer, double tl_scale);
  void write (const db::Layout &layout, const db::Cell &cref, const std::set <db::cell_index_type> &cell_set, const std::vector <std::pair <unsigned int, db::LayerProperties> > &layers, double sf);
  const ZInfo *zinfo (const db::Layout &layout, properties_id_type prop_id);

  void emit_layer(const db::LayerProperties &lp);
};

} // namespace db

#endif

