// $Id: VertexArray.cpp,v 1.2 2004-05-29 20:25:28 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "VertexArray.h"
#include "Context.h"
#include "Numeric.h"

triangleVertexArray::triangleVertexArray(int nb)
{
  num_triangles = fill = 0;
  if(!nb)
    nb = 1000;
  vertices = List_Create(nb * 3 * 3, 9000, sizeof(float));
  normals = List_Create(nb * 3 * 3, 9000, sizeof(float));
  colors = List_Create(nb * 3 * 4, 12000, sizeof(unsigned char));
}

triangleVertexArray::~triangleVertexArray()
{
  List_Delete(vertices);
  List_Delete(normals);
  List_Delete(colors);
}

void triangleVertexArray::add(float x, float y, float z, float n0, 
			      float n1, float n2, unsigned int col)
{
  unsigned char r = UNPACK_RED(col);
  unsigned char g = UNPACK_GREEN(col);
  unsigned char b = UNPACK_BLUE(col);
  unsigned char a = UNPACK_ALPHA(col);
  List_Add(vertices, &x);
  List_Add(vertices, &y);
  List_Add(vertices, &z);
  List_Add(normals, &n0);
  List_Add(normals, &n1);
  List_Add(normals, &n2);
  List_Add(colors, &r);
  List_Add(colors, &g);
  List_Add(colors, &b);
  List_Add(colors, &a);
}

static double theeye[3];

int compareTriEye(const void *a, const void *b)
{
  float *q = (float*)a;
  float *w = (float*)b;
  double d, dq, dw, cgq[3] = { 0., 0., 0. }, cgw[3] = { 0., 0., 0.};
  for(int i = 0; i < 3; i++) {
    cgq[0] += q[3*i];
    cgq[1] += q[3*i + 1];
    cgq[2] += q[3*i + 2];
    cgw[0] += w[3*i];
    cgw[1] += w[3*i + 1];
    cgw[2] += w[3*i + 2];
  }
  prosca(theeye, cgq, &dq);
  prosca(theeye, cgw, &dw);
  d = dq - dw;
  if(d > 0)
    return 1;
  if(d < 0)
    return -1;
  return 0;
}

void triangleVertexArray::sort(double eye[3])
{
  theeye[0] = eye[0];
  theeye[1] = eye[1];
  theeye[2] = eye[2];
  
  int nb = List_Nbr(vertices) + List_Nbr(normals) + List_Nbr(colors);
  float *tmp = new float[nb];
  
  int iv = 0, in = 0, ic = 0, k = 0;
  for(int i = 0; i < num_triangles; i++){
    for(int j = 0; j < 9; j++)
      List_Read(vertices, iv++, &tmp[k++]);
    for(int j = 0; j < 9; j++)
      List_Read(normals, in++, &tmp[k++]);
    for(int j = 0; j < 12; j++){
      unsigned char c;
      List_Read(colors, ic++, &c);
      tmp[k++] = c;
    }
  }

  List_Reset(vertices);
  List_Reset(normals);
  List_Reset(colors);

  qsort(tmp, num_triangles, (9+9+12)*sizeof(float), compareTriEye);

  k = 0;
  for(int i = 0; i < num_triangles; i++){
    for(int j = 0; j < 9; j++)
      List_Add(vertices, &tmp[k++]);
    for(int j = 0; j < 9; j++)
      List_Add(normals, &tmp[k++]);
    for(int j = 0; j < 12; j++){
      unsigned char c = (unsigned char)tmp[k++];
      List_Add(colors, &c);
    }
  }  

  delete [] tmp;
}
