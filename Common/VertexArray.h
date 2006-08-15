#ifndef _VERTEX_ARRAY_H_
#define _VERTEX_ARRAY_H_

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "List.h"

class VertexArray{
 public:
  int type, fill;
  List_T *vertices, *normals, *colors;
  VertexArray(int numNodesPerElement, int numElements);
  ~VertexArray();
  // return the number of nodes in the array
  int n();
  // add a node in the array
  void add(float x, float y, float z, 
	   float n0, float n1, float n2, unsigned int col);
  void add(float x, float y, float z, unsigned int col);
  // sort the elements back to fron wrt the eye position
  void sort(double eye[3]);
};

#endif
