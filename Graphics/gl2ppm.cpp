
#include "Gmsh.h"
#include "GmshUI.h"

void create_ppm(FILE *outfile, int width, int height){
  unsigned char *red, *green, *blue;
  register int x, y;
  unsigned char   r, g, b;

  red = (unsigned char *)malloc(height*width*sizeof(unsigned char));
  green = (unsigned char *)malloc(height*width*sizeof(unsigned char));
  blue = (unsigned char *)malloc(height*width*sizeof(unsigned char));

  glReadPixels(0,0,width,height,GL_RED,GL_UNSIGNED_BYTE,red);
  glReadPixels(0,0,width,height,GL_GREEN,GL_UNSIGNED_BYTE,green);
  glReadPixels(0,0,width,height,GL_BLUE,GL_UNSIGNED_BYTE,blue);

  fprintf(outfile, "P6\n");
  fprintf(outfile, "%d %d\n", width, height);
  fprintf(outfile, "%d\n", 255);

  for ( y = height-1; y >= 0; y-- ){
    for ( x = 0; x < width; x++ ){
      r = red[y*width+x];
      g = green[y*width+x];
      b = blue[y*width+x];
      fwrite(&r, 1, 1, outfile);
      fwrite(&g, 1, 1, outfile);
      fwrite(&b, 1, 1, outfile);
    }
  }

  Free(red);
  Free(green);
  Free(blue);
}

