// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "gl2ppm.h"

void create_ppm(FILE *outfile, PixelBuffer *buffer)
{
  if(buffer->getFormat() != GL_RGB || buffer->getType() != GL_UNSIGNED_BYTE){
    Msg::Error("PPM only implemented for GL_RGB and GL_UNSIGNED_BYTE");
    return;
  }

  int width = buffer->getWidth();
  int height = buffer->getHeight();
  unsigned char *pixels = (unsigned char*)buffer->getPixels();

  fprintf(outfile, "P6\n");
  fprintf(outfile, "%d %d\n", width, height);
  fprintf(outfile, "%d\n", 255);

  int row_stride = width * 3;
  int i = height - 1;
  while(i >= 0) {
    fwrite(&pixels[i * row_stride], 1, row_stride, outfile);
    i--;
  }
}
