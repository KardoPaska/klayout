
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


#include "dbDXFWriter.h"
#include "dbReader.h"
#include "dbTestSupport.h"
#include "tlUnitTest.h"

#include <stdlib.h>

static void do_run_test (tl::TestBase *_this, const std::string &fn, const std::string &fn_au, const db::DXFWriterOptions &opt)
{
  db::Layout layout, layout_read;

  std::string tmp_file = _this->tmp_file ("tmp.dxf");

  {
    tl::InputStream stream (fn);
    db::Reader reader (stream);
    reader.read (layout);
  }

  {
    db::SaveLayoutOptions options;
    options.set_options (opt);
    options.set_format ("DXF");

    tl::OutputStream stream (tmp_file.c_str ());
    db::Writer writer (options);
    writer.write (const_cast<db::Layout &> (layout), stream);
  }

  {
    tl::InputStream stream (tmp_file);
    db::LoadLayoutOptions options;
    db::DXFReaderOptions dxf_opt;
    dxf_opt.polyline_mode = 2;  //  maintains LINE for writer5 test
    options.set_options (dxf_opt);
    db::Reader reader (stream);
    reader.read (layout_read, options);
  }

  db::compare_layouts (_this, layout_read, fn_au, db::WriteOAS, 1);
}

static void run_test (tl::TestBase *_this, const char *file, const char *file_au, const db::DXFWriterOptions &opt = db::DXFWriterOptions ())
{
  std::string fn = tl::testsrc () + "/testdata/dxf/" + file;
  std::string fn_au = tl::testsrc () + std::string ("/testdata/dxf/") + file_au;

  do_run_test (_this, fn, fn_au, opt);
}

TEST(Writer1)
{
  db::DXFWriterOptions opt;
  run_test (_this, "writer1.oas", "writer1_au.oas", opt);
}

TEST(Writer1z)
{
  db::DXFWriterOptions opt;
  run_test (_this, "writer1z.oas", "writer1_au.oas", opt);
}

TEST(Writer2)
{
  db::DXFWriterOptions opt;
  opt.polygon_mode = 1;  // LWPOLYLINE
  run_test (_this, "writer2.oas", "writer2_au.oas", opt);
}

TEST(Writer3)
{
  db::DXFWriterOptions opt;
  opt.polygon_mode = 2;  // SOLIDs
  run_test (_this, "writer3.oas", "writer3_au.oas", opt);
}

TEST(Writer3z)
{
  db::DXFWriterOptions opt;
  opt.polygon_mode = 2;  // SOLIDs
  run_test (_this, "writer3z.oas", "writer3_au.oas", opt);
}

TEST(Writer4)
{
  db::DXFWriterOptions opt;
  opt.polygon_mode = 3;  // HATCH
  run_test (_this, "writer4.oas", "writer4_au.oas", opt);
}

TEST(Writer5)
{
  db::DXFWriterOptions opt;
  opt.polygon_mode = 4;  // LINE
  run_test (_this, "writer5.oas", "writer5_au.oas", opt);
}


