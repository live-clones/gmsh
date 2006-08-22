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

#include "vector"

class VertexArray{
 public:
  int fill; // this must/will be removed
 private:
  int _type;
  std::vector<float> _vertices;
  std::vector<char> _normals;
  std::vector<unsigned char> _colors;
 public:
  VertexArray(int numNodesPerElement, int numElements);
  ~VertexArray(){}
  // returns the number of nodes in the array
  int getNumVertices() { return _vertices.size() / 3; }
  // returns the type of the array
  int getType() { return _type; }
  // returns a pointer to the raw vertex array
  float *getVertexArray(){ return &_vertices[0]; }
  // returns a pointer to the raw normal array
  char *getNormalArray(){ return &_normals[0]; }
  // returns a pointer to the raw color array
  unsigned char *getColorArray(){ return &_colors[0]; }
  // adds a vertex in the arrays
  void add(float x, float y, float z, 
	   float n0, float n1, float n2, unsigned int col);
  void add(float x, float y, float z, unsigned int col);
  // sorts the elements back to front wrt the eye position
  void sort(double eye[3]);
};

#endif
