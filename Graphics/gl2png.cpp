// $Id: gl2png.cpp,v 1.7 2006-12-04 03:27:31 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "gl2png.h"

#if !defined(HAVE_LIBPNG)

void create_png(FILE *file, PixelBuffer *buffer, int quality)
{
  Msg(GERROR, "This version of Gmsh was compiled without PNG support");
}

#else

#include <png.h>

#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#endif

void create_png(FILE *file, PixelBuffer *buffer, int quality)
{
  if((buffer->GetFormat() != GL_RGB && buffer->GetFormat() != GL_RGBA) ||
     buffer->GetType() != GL_UNSIGNED_BYTE){
    Msg(GERROR, "PNG only implemented for GL_RGB/GL_RGBA and GL_UNSIGNED_BYTE");
    return;
  }

  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  
  if(png_ptr == NULL) {
    Msg(GERROR, "Could not create PNG write struct");
    return;
  }
  
  png_infop info_ptr = png_create_info_struct(png_ptr);

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
  
  int height = buffer->GetHeight();
  int width = buffer->GetWidth();
  int numcomp = buffer->GetNumComp();

  // Z_DEFAULT_COMPRESSION, Z_BEST_SPEED, Z_BEST_COMPRESSION, Z_NO_COMPRESSION
  png_set_compression_level(png_ptr, Z_DEFAULT_COMPRESSION);
  png_set_IHDR(png_ptr, info_ptr, width, height, 8, 
	       (numcomp == 3) ? PNG_COLOR_TYPE_RGB : PNG_COLOR_TYPE_RGBA,
	       PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  time_t now;
  time(&now);
  png_text text_ptr[10];  
  text_ptr[0].key = "Creator";
  text_ptr[0].text = "Gmsh";
  text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
  text_ptr[1].key = "Date";
  text_ptr[1].text = ctime(&now);
  text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;
  png_set_text(png_ptr, info_ptr, text_ptr, 2);
  png_write_info(png_ptr, info_ptr);

  unsigned char *pixels = (unsigned char *)buffer->GetPixels();
  for(int row = height - 1; row >= 0; row--) {
    unsigned char *row_pointer = &pixels[row * width * numcomp];
    png_write_row(png_ptr, (png_bytep)row_pointer);
  }
  png_write_end(png_ptr, info_ptr);
  png_destroy_write_struct(&png_ptr, &info_ptr);
}

#endif
