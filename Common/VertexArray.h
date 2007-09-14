#ifndef _VERTEX_ARRAY_H_
#define _VERTEX_ARRAY_H_

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

#include <vector>
#include <set>
#include "SVector3.h"

class MElement;

class Barycenter {
 private:
  float _x, _y, _z;
 public:
  Barycenter(double x, double y, double z) : _x(x), _y(y), _z(z){}
  float x() const { return _x; }
  float y() const { return _y; }
  float z() const { return _z; }
  void operator+=(const Barycenter &p){ _x += p.x(); _y += p.y(); _z += p.z(); }
};

class BarycenterLessThan{
 public:
  static float tolerance;
  bool operator()(const Barycenter &p1, const Barycenter &p2) const
  {
    if(p1.x() - p2.x() >  tolerance) return true;
    if(p1.x() - p2.x() < -tolerance) return false;
    if(p1.y() - p2.y() >  tolerance) return true;
    if(p1.y() - p2.y() < -tolerance) return false;
    if(p1.z() - p2.z() >  tolerance) return true;
    return false;
  }
};

class VertexArray{
 private:
  int _numVerticesPerElement;
  std::vector<float> _vertices;
  std::vector<char> _normals;
  std::vector<unsigned char> _colors;
  std::vector<MElement*> _elements;
  std::set<Barycenter, BarycenterLessThan> _barycenters;
 public:
  VertexArray(int numVerticesPerElement, int numElements);
  ~VertexArray(){}
  // returns the number of vertices in the array
  int getNumVertices() { return _vertices.size() / 3; }
  // returns the number of vertices per element
  int getNumVerticesPerElement() { return _numVerticesPerElement; }
  // returns the number of element pointers
  int getNumElementPointers() { return _elements.size(); }
  // returns a pointer to the raw vertex array
  float *getVertexArray(int i=0){ return &_vertices[i]; }
  // returns a pointer to the raw normal array
  char *getNormalArray(int i=0){ return &_normals[i]; }
  // returns a pointer to the raw color array
  unsigned char *getColorArray(int i=0){ return &_colors[i]; }
  // returns a pointer to the raw element array
  MElement **getElementPointerArray(int i=0){ return &_elements[i]; }
  // adds a vertex in the arrays
  void add(float x, float y, float z, float n0, float n1, float n2, 
	   unsigned int col, MElement *ele=0);
  void add(float x, float y, float z, unsigned int col, MElement *ele=0);
  // add a complete element in the arrays (if unique is set, only add
  // the element if another one with the same barycenter is not
  // already present)
  void add(double *x, double *y, double *z, SVector3 *n, unsigned int *col,
	   MElement *ele=0, bool unique=true);
  // sorts the elements back to front wrt the eye position
  void sort(double x, double y, double z);
  // regain temporay memory once the array is constructed
  void finalize(){ _barycenters.clear(); }
};

#endif
