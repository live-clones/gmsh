// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "gl2png.h"

#if !defined(HAVE_LIBPNG)

void create_png(FILE *file, PixelBuffer *buffer, int quality)
{
  Msg::Error("This version of Gmsh was compiled without PNG support");
}

#else

#include <png.h>

#ifndef png_jmpbuf
#  define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)
#endif

void create_png(FILE *file, PixelBuffer *buffer, int quality)
{
  if((buffer->getFormat() != GL_RGB && buffer->getFormat() != GL_RGBA) ||
     buffer->getType() != GL_UNSIGNED_BYTE){
    Msg::Error("PNG only implemented for GL_RGB/GL_RGBA and GL_UNSIGNED_BYTE");
    return;
  }

  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  
  if(png_ptr == NULL) {
    Msg::Error("Could not create PNG write struct");
    return;
  }
  
  png_infop info_ptr = png_create_info_struct(png_ptr);

  if(info_ptr == NULL) {
    png_destroy_write_struct(&png_ptr, NULL);
    Msg::Error("Could not create PNG info struct");
    return;
  }
  
  if(setjmp(png_jmpbuf(png_ptr))) {
    png_destroy_write_struct(&png_ptr, &info_ptr);
    Msg::Error("Could not setjmp in PNG");
    return;
  }
  
  png_init_io(png_ptr, file);
  
  int height = buffer->getHeight();
  int width = buffer->getWidth();
  int numcomp = buffer->getNumComp();

  // Z_DEFAULT_COMPRESSION, Z_BEST_SPEED, Z_BEST_COMPRESSION, Z_NO_COMPRESSION
  png_set_compression_level(png_ptr, Z_DEFAULT_COMPRESSION);
  png_set_IHDR(png_ptr, info_ptr, width, height, 8, 
               (numcomp == 3) ? PNG_COLOR_TYPE_RGB : PNG_COLOR_TYPE_RGBA,
               PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
  time_t now;
  time(&now);
  png_text text_ptr[10];  
  text_ptr[0].key = (char*)"Creator";
  text_ptr[0].text = (char*)"Gmsh";
  text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;
  text_ptr[1].key = (char*)"Date";
  text_ptr[1].text = ctime(&now);
  text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;
  png_set_text(png_ptr, info_ptr, text_ptr, 2);
  png_write_info(png_ptr, info_ptr);

  unsigned char *pixels = (unsigned char *)buffer->getPixels();
  for(int row = height - 1; row >= 0; row--) {
    unsigned char *row_pointer = &pixels[row * width * numcomp];
    png_write_row(png_ptr, (png_bytep)row_pointer);
  }
  png_write_end(png_ptr, info_ptr);
  png_destroy_write_struct(&png_ptr, &info_ptr);
}

#endif
