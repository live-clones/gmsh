/*
 * GL2YUV, an OpenGL to YUV Printing Library
 * Copyright (C) 1999-2002  Christophe Geuzaine 
 *
 * $Id: gl2yuv.cpp,v 1.7 2002-05-25 19:17:45 geuzaine Exp $
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

/*
 * This code is based on the rgbtoycc.c code from the MPEG-1 Video
 * Software Encoder (Version 1.5; February 1, 1995), by Lawrence
 * A. Rowe, Kevin Gong, Eugene Hung, Ketan Patel, Steve Smoot and Dan
 * Wallach Computer Science Division-EECS, Univ. of Calif. at Berkeley
 * 
 * Copyright (c) 1995 The Regents of the University of California.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice and the following
 * two paragraphs appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF
 * CALIFORNIA HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */


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

