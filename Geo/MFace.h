#ifndef _MFACE_H_
#define _MFACE_H_

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

#include <functional>
#include <vector>
#include "MVertex.h"
#include "SVector3.h"
#include "Numeric.h"
#include "Context.h"
#include "Hash.h"

extern Context_T CTX;

// A mesh face.
class MFace {
 private:
  MVertex *_v[4];
  char _si[4];                          // sorted indices

 public:
  MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3=0) 
  {
    if(CTX.mesh.reverse_all_normals){
      // Note that we cannot simply change the normal computation,
      // since OpenGL wants the normal to a polygon to be coherent
      // with the ordering of its vertices
      if(v3){
	_v[0] = v0; _v[1] = v3; _v[2] = v2; _v[3] = v1;
      }
      else{
	_v[0] = v0; _v[1] = v2; _v[2] = v1; _v[3] = v3;
      }
    }
    else{
      _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
    }
    // This is simply an unrolled insertion sort (hopefully fast).  Note that if
    // _v[3] == 0, _v[3] is not sorted.
    if(_v[1] < _v[0]) {
      _si[0] = 1;
      _si[1] = 0;
    }
    else {
      _si[0] = 0;
      _si[1] = 1;
    }
    if(_v[2] < _v[int(_si[1])]) {
      _si[2] = _si[1];
      if(_v[2] < _v[int(_si[0])]) {
        _si[1] = _si[0];
        _si[0] = 2;
      }
      else
        _si[1] = 2;
    }
    else
      _si[2] = 2;
    if( _v[3] && _v[3] < _v[int(_si[2])]) {
      _si[3] = _si[2];
      if(_v[3] < _v[int(_si[1])]) {
        _si[2] = _si[1];
        if(_v[3] < _v[int(_si[0])]) {
          _si[1] = _si[0];
          _si[0] = 3;
        }
        else
          _si[1] = 3;
      }
      else
        _si[2] = 3;
    }
    else
      _si[3] = 3;
  }
  inline int getNumVertices() const { return _v[3] ? 4 : 3; }
  inline MVertex *getVertex(const int i) const { return _v[i]; }
  inline MVertex *getSortedVertex(const int i) const { return _v[int(_si[i])]; }
  void getOrderedVertices(std::vector<MVertex*> &verts) const
  {
    for(int i = 0; i < getNumVertices(); i++)
      verts.push_back(getSortedVertex(i));
  }
  void getOrderedVertices(const MVertex **const verts) const
  {
    verts[0] = getSortedVertex(0);
    verts[1] = getSortedVertex(1);
    verts[2] = getSortedVertex(2);
    verts[3] = getSortedVertex(3);
  }
  SVector3 normal() const
  {
    double n[3];
    normal3points(_v[0]->x(), _v[0]->y(), _v[0]->z(),
		  _v[1]->x(), _v[1]->y(), _v[1]->z(),
		  _v[2]->x(), _v[2]->y(), _v[2]->z(), n);
    return SVector3(n[0], n[1], n[2]);
  }
  SPoint3 barycenter() const
  {
    SPoint3 p(0., 0., 0.);
    int n = getNumVertices();
    for(int i = 0; i < n; i++) {
      MVertex *v = getVertex(i);
      p[0] += v->x();
      p[1] += v->y();
      p[2] += v->z();
    }
    p[0] /= (double)n;
    p[1] /= (double)n;
    p[2] /= (double)n;
    return p;
  }
};

//--The following function objects compare the addresses of the mesh vertices.
//--Equal, Less, and a Hash are defined.

struct Equal_Face : public std::binary_function<MFace, MFace, bool> {
  bool operator()(const MFace &f1, const MFace &f2) const
  {
    return (f1.getSortedVertex(0) == f2.getSortedVertex(0) &&
            f1.getSortedVertex(1) == f2.getSortedVertex(1) &&
            f1.getSortedVertex(2) == f2.getSortedVertex(2) &&
            f1.getSortedVertex(3) == f2.getSortedVertex(3));
  }
};

struct Less_Face : public std::binary_function<MFace, MFace, bool> {
  bool operator()(const MFace &f1, const MFace &f2) const
  {
    if(f1.getSortedVertex(0) < f2.getSortedVertex(0)) return true;
    if(f1.getSortedVertex(0) > f2.getSortedVertex(0)) return false;
    if(f1.getSortedVertex(1) < f2.getSortedVertex(1)) return true;
    if(f1.getSortedVertex(1) > f2.getSortedVertex(1)) return false;
    if(f1.getSortedVertex(2) < f2.getSortedVertex(2)) return true;
    if(f1.getSortedVertex(2) > f2.getSortedVertex(2)) return false;
    if(f1.getSortedVertex(3) < f2.getSortedVertex(3)) return true;
    return false;
  }
};

struct Hash_Face : public std::unary_function<MFace, size_t> {
  size_t operator()(const MFace &f) const
  {
    const MVertex *v[4];
    f.getOrderedVertices(v);
    return HashFNV1a<sizeof(MVertex*[4])>::eval(v);
  }
};

#endif
