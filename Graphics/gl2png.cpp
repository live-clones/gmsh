/*
 * GL2PNG, an OpenGL to PNG Printing Library
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

#if !defined(HAVE_LIBPNG)

void create_png(FILE * file, int width, int height, int quality)
{
  Msg(GERROR, "This version of Gmsh was compiled without PNG support");
}

#else

#include <png.h>

#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#endif

/*
  compression_level = Z_DEFAULT_COMPRESSION;
  compression_level = Z_BEST_SPEED;
  compression_level = Z_BEST_COMPRESSION;
  compression_level = Z_NO_COMPRESSION;
*/

void create_png(FILE * file, int width, int height, int quality)
{
  int row;
  int compression_level = Z_DEFAULT_COMPRESSION;
  png_structp png_ptr;
  png_infop info_ptr;
  png_text text_ptr[10];
  unsigned char *pixels;
  time_t now;

  time(&now);
  
  png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  
  if(png_ptr == NULL) {
    Msg(GERROR, "Could not create PNG write struct");
    return;
  }
  
  info_ptr = png_create_info_struct(png_ptr);

  if(info_ptr == NULL) {
    png_destroy_write_struct(&png_ptr, NULL);
    Msg(GERROR, "Could not create PNG info struct");
    return;
  }
  
  if(setjmp(png_jmpbuf(png_ptr))) {
    png_destroy_write_struct(&png_ptr, &info_ptr);
    Msg(GERROR, "Could not setjmp in PNG");
    return;
  }
  
  png_init_io(png_ptr, file);
  
  png_set_compression_level(png_ptr, compression_level);

  png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB,
	       PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  
  text_ptr[0].key = "Creator";
  text_ptr[0].text = "Gmsh";
  text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
  text_ptr[1].key = "Date";
  text_ptr[1].text = ctime(&now);
  text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;
  png_set_text(png_ptr, info_ptr, text_ptr, 2);
  
  png_write_info(png_ptr, info_ptr);
  
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  pixels = (unsigned char *)Malloc(width * 3 * sizeof(unsigned char));
  for(row = height - 1; row >= 0; row--) {
    glReadPixels(0, row, width, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels);
    png_write_row(png_ptr, (png_bytep)pixels);
  }
  Free(pixels);

  png_write_end(png_ptr, info_ptr);
  
  png_destroy_write_struct(&png_ptr, &info_ptr);
}

#endif

