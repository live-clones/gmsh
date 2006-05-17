/* $Id: gl2ppm.cpp,v 1.14 2006-05-17 01:19:06 geuzaine Exp $ */
/*
 * GL2PPM, an OpenGL to PPM Printing Library
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
 * version 2 of the License, or (at your option) any later version.
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

#include "gl2ppm.h"

void create_ppm(FILE *outfile, PixelBuffer *buffer)
{
  if(buffer->GetFormat() != GL_RGB || buffer->GetType() != GL_UNSIGNED_BYTE){
    Msg(GERROR, "PPM only implemented for GL_RGB and GL_UNSIGNED_BYTE");
    return;
  }

  int width = buffer->GetWidth();
  int height = buffer->GetHeight();
  unsigned char *pixels = (unsigned char*)buffer->GetPixels();

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
