// $Id: gl2yuv.cpp,v 1.3 2001-01-08 08:05:44 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"

void create_yuv(FILE *outfile, int width, int height){

  register int x, y;
  register unsigned char *dy0, *dy1;
  register unsigned char *dcr, *dcb;
  register unsigned char *src0, *src1;
  register int cdivisor;

  static int first = 1;
  static float mult299[1024], mult587[1024], mult114[1024];
  static float mult16874[1024], mult33126[1024], mult5[1024];
  static float mult41869[1024], mult08131[1024];

  unsigned char  *pixels;
  unsigned char  **orig_y, **orig_cr, **orig_cb;
  int row_stride;
  
  if (first){
    register int index;
    register int maxValue;
    
    maxValue = 255;

    for (index = 0; index <= maxValue; index++){
      mult299[index] = index*0.29900;
      mult587[index] = index*0.58700;
      mult114[index] = index*0.11400;
      mult16874[index] = -0.16874*index;
      mult33126[index] = -0.33126*index;
      mult5[index] = index*0.50000;
      mult41869[index] = -0.41869*index;
      mult08131[index] = -0.08131*index;
    }
   
    first = 0;
  }

  // yuv format assumes even number of rows and columns
  height -= height%2;
  width -= width%2;

  glPixelStorei(GL_PACK_ALIGNMENT,1);
  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
  pixels=(unsigned char *)Malloc(height*width*3);
  glReadPixels(0,0,width,height,GL_RGB,GL_UNSIGNED_BYTE,pixels);
  row_stride = width * 3;

  orig_y = (unsigned char **) Malloc(sizeof(unsigned char *) * height);
  for (y = 0; y < height; y++) {
    orig_y[y] = (unsigned char *) Malloc(sizeof(unsigned char) * width);
  }

  orig_cr = (unsigned char **) Malloc(sizeof(char *) * height / 2);
  for (y = 0; y < height / 2; y++) {
    orig_cr[y] = (unsigned char *) Malloc(sizeof(char) * width / 2);
  }
  
  orig_cb = (unsigned char **) Malloc(sizeof(char *) * height / 2);
  for (y = 0; y < height / 2; y++) {
    orig_cb[y] = (unsigned char *) Malloc(sizeof(char) * width / 2);
  }
  
  // assume ydivisor = 1, so cdivisor = 4
  cdivisor = 4;
  
  for (y = 0; y < height; y += 2){
    src0 = &(pixels[y * row_stride]);
    src1 = &(pixels[(y+1) * row_stride]);
    dy0 = orig_y[y];
    dy1 = orig_y[y + 1];
    dcr = orig_cr[y / 2];
    dcb = orig_cb[y / 2];
    
    for (x = 0; x < width; x += 2, dy0 += 2, dy1 += 2, dcr++,
                                   dcb++, src0 += 6, src1 += 6){
      *dy0 = (unsigned char)(mult299[*src0] +
			     mult587[src0[1]] +
			     mult114[src0[2]]);
      
      *dy1 = (unsigned char)(mult299[*src1] +
			     mult587[src1[1]] +
			     mult114[src1[2]]);
      
      dy0[1] = (unsigned char)(mult299[src0[3]] +
			       mult587[src0[4]] +
			       mult114[src0[5]]);
      
      dy1[1] = (unsigned char)(mult299[src1[3]] +
			       mult587[src1[4]] +
			       mult114[src1[5]]);
      
      *dcb = (unsigned char)((mult16874[*src0] +
			      mult33126[src0[1]] +
			      mult5[src0[2]] +
			      mult16874[*src1] +
			      mult33126[src1[1]] +
			      mult5[src1[2]] +
			      mult16874[src0[3]] +
			      mult33126[src0[4]] +
			      mult5[src0[5]] +
			      mult16874[src1[3]] +
			      mult33126[src1[4]] +
			      mult5[src1[5]]) / cdivisor) + 128;
      
      *dcr = (unsigned char)((mult5[*src0] +
			      mult41869[src0[1]] +
			      mult08131[src0[2]] +
			      mult5[*src1] +
			      mult41869[src1[1]] +
			      mult08131[src1[2]] +
			      mult5[src0[3]] +
			      mult41869[src0[4]] +
			      mult08131[src0[5]] +
			      mult5[src1[3]] +
			      mult41869[src1[4]] +
			      mult08131[src1[5]]) / cdivisor) + 128;
    }
  }

  // Y
  for (y = height-1; y >=0; y--) fwrite(orig_y[y], 1, width, outfile);
  
  // U
  for (y = height/2-1; y >=0; y--) fwrite(orig_cb[y], 1, width / 2, outfile);
  
  // V
  for (y = height/2-1; y >=0; y--) fwrite(orig_cr[y], 1, width / 2, outfile);

  Free(pixels);

  for (y = 0; y < height; y++) Free(orig_y[y]);
  Free(orig_y);

  for (y = 0; y < height / 2; y++) Free(orig_cr[y]);
  Free(orig_cr);
  
  for (y = 0; y < height / 2; y++) Free(orig_cb[y]);
  Free(orig_cb);

}

