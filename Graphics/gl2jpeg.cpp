// $Id: gl2jpeg.cpp,v 1.30 2008-05-04 08:31:15 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "gl2jpeg.h"
#undef EXTERN

#if !defined(HAVE_LIBJPEG)

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality, int smoothing)
{
  Msg::Error("This version of Gmsh was compiled without JPEG support");
}

#else

/* Some releases of the Cygwin JPEG libraries (as well as the JPEG
   library bundled with FLTK) don't have a correctly updated header
   file for the INT32 data type; the following define from Shane Hill
   seems to be a usable workaround... */

#if defined(WIN32)
#define XMD_H
#define boolean char
#endif

extern "C"
{
#include <jpeglib.h>
#include <jerror.h>
}

void my_output_message(j_common_ptr cinfo)
{
  char buffer[JMSG_LENGTH_MAX];

  (*cinfo->err->format_message) (cinfo, buffer);

  Msg::Debug("%s", buffer);
}

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality, int smoothing)
{
  if(buffer->GetFormat() != GL_RGB || buffer->GetType() != GL_UNSIGNED_BYTE){
    Msg::Error("JPEG only implemented for GL_RGB and GL_UNSIGNED_BYTE");
    return;
  }

  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  cinfo.err = jpeg_std_error(&jerr);
  cinfo.err->output_message = my_output_message;

  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, outfile);
  cinfo.image_width = buffer->GetWidth();
  cinfo.image_height = buffer->GetHeight();
  cinfo.input_components = 3;
  cinfo.in_color_space = JCS_RGB;
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, quality, TRUE);
  cinfo.optimize_coding = TRUE;
  cinfo.smoothing_factor = smoothing;
  jpeg_start_compress(&cinfo, TRUE);

  unsigned char *pixels = (unsigned char*)buffer->GetPixels();
  JSAMPROW row_pointer[1]; 
  int row_stride = cinfo.image_width * cinfo.input_components;
  int i = cinfo.image_height - 1;
  while(i >= 0) {
    row_pointer[0] = &pixels[i * row_stride];
    (void)jpeg_write_scanlines(&cinfo, row_pointer, 1);
    i--;
  }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);
}

#endif
