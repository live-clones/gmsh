// $Id: gl2ppm.cpp,v 1.15 2006-12-04 03:27:31 geuzaine Exp $
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
