/*
 * GL2PPM, an OpenGL to PPM Printing Library
 * Copyright (C) 1999-2002  Christophe Geuzaine 
 *
 * $Id: gl2ppm.cpp,v 1.6 2002-05-18 07:18:02 geuzaine Exp $
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

#include "Gmsh.h"
#include "GmshUI.h"

void create_ppm(FILE *outfile, int width, int height){
  unsigned char *pixels;
  int i, row_stride;

  glPixelStorei(GL_PACK_ALIGNMENT,1);
  glPixelStorei(GL_UNPACK_ALIGNMENT,1);
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

