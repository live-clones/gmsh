/* $Id: gl2jpeg.cpp,v 1.19 2003-10-29 19:51:43 geuzaine Exp $ */
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
 * version 1 of the License, or (at your option) any later version.
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

#include "Gmsh.h"
#include "GmshUI.h"

#if !defined(HAVE_LIBJPEG)

void create_jpeg(FILE * outfile, int width, int height, int quality)
{
  Msg(GERROR, "This version of Gmsh was compiled without JPEG support");
}

#else

/* Some releases of the Cygwin JPEG libraries don't have a correctly
   updated header file for the INT32 data type; the following define
   from Shane Hill seems to be a usable workaround... */

#if defined(WIN32)
#define XMD_H
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

void create_jpeg(FILE * outfile, int width, int height, int quality)
{
  int i;
  unsigned char *pixels;
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  JSAMPROW row_pointer[1];
  int row_stride;

  cinfo.err = jpeg_std_error(&jerr);
  cinfo.err->output_message = my_output_message;

  jpeg_create_compress(&cinfo);
  jpeg_stdio_dest(&cinfo, outfile);
  cinfo.image_width = width;    // in pixels
  cinfo.image_height = height;
  cinfo.input_components = 3;   // 3 color components per pixel
  cinfo.in_color_space = JCS_RGB;
  jpeg_set_defaults(&cinfo);
  jpeg_set_quality(&cinfo, quality, TRUE);
  jpeg_start_compress(&cinfo, TRUE);

  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  pixels = (unsigned char *)Malloc(height * width * 3);
  glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

  row_stride = width * 3;
  i = cinfo.image_height - 1;
  while(i >= 0) {
    row_pointer[0] = &pixels[i * row_stride];
    (void)jpeg_write_scanlines(&cinfo, row_pointer, 1);
    i--;
  }
  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

  Free(pixels);
}

#endif
