/* $Id: gl2ppm.cpp,v 1.3 2000-12-21 10:29:45 geuzaine Exp $ */

#include "Gmsh.h"
#include "GmshUI.h"

void create_ppm(FILE *outfile, int width, int height){
  unsigned char *pixels;
  int i, row_stride;
  
  pixels=(unsigned char *)Malloc(height*width*3);
  glReadPixels(0,0,width,height,GL_RGB,GL_UNSIGNED_BYTE,pixels);

  fprintf(outfile, "P6\n");
  fprintf(outfile, "%d %d\n", width, height);
  fprintf(outfile, "%d\n", 255);

  row_stride = width * 3;
  i = height-1;
  while (i >= 0) {
    fwrite(&pixels[i * row_stride], 1, row_stride, outfile);
    i--;
  }

  Free(pixels);
}

