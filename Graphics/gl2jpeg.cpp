/* $Id: gl2jpeg.cpp,v 1.27 2006-05-17 01:19:06 geuzaine Exp $ */
/*
 * GL2JPEG, an OpenGL to JPEG Printing Library
 * Copyright (C) 1999-2003 Christophe Geuzaine <geuz@geuz.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of either:
 *
 * a) the GNU Library General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or (at your
 * option) any later version; or
 *
 * b) the GL2PS License as published by Christophe Geuzaine, either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See either
 * the GNU Library General Public License or the GL2PS License for
 * more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library in the file named "COPYING.LGPL";
 * if not, write to the Free Software Foundation, Inc., 675 Mass Ave,
 * Cambridge, MA 02139, USA.
 *
 * You should have received a copy of the GL2PS License with this
 * library in the file named "COPYING.GL2PS"; if not, I will be glad
 * to provide one.
 */

#include "gl2jpeg.h"
#undef EXTERN

#if !defined(HAVE_LIBJPEG)

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality, int smoothing)
{
  Msg(GERROR, "This version of Gmsh was compiled without JPEG support");
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

  Msg(DEBUG, "%s", buffer);
}

void create_jpeg(FILE *outfile, PixelBuffer *buffer, int quality, int smoothing)
{
  if(buffer->GetFormat() != GL_RGB || buffer->GetType() != GL_UNSIGNED_BYTE){
    Msg(GERROR, "JPEG only implemented for GL_RGB and GL_UNSIGNED_BYTE");
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
