#ifndef _MEDGE_H_
#define _MEDGE_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "MVertex.h"
#include "SVector3.h"

// A mesh edge.
class MEdge {
 private:
  MVertex *_v[2];
  char _si[2];                          // sorted indices

 public:
  MEdge(MVertex *v0, MVertex *v1)
  {
    _v[0] = v0; _v[1] = v1;
    if(_v[1] < _v[0]) {
      _si[0] = 1;
      _si[1] = 0;
    }
    else {
      _si[0] = 0;
      _si[1] = 1;
    }
  }
  inline int getNumVertices() const { return 2; }
  inline MVertex *getVertex(const int i) const { return _v[i]; }
  inline MVertex *getSortedVertex(const int i) const { return _v[int(_si[i])]; }
  inline MVertex *getMinVertex() const { return _v[int(_si[0])]; }
  inline MVertex *getMaxVertex() const { return _v[int(_si[1])]; }
  SVector3 tangent() const
  {
    SVector3 t(_v[1]->x() - _v[0]->x(), 
	       _v[1]->y() - _v[0]->y(),
	       _v[1]->z() - _v[0]->z());
    t.normalize();
    return t;
  }
  SVector3 normal() const 
  {
    // this computes one of the normals to the edge
    SVector3 t = tangent(), ex(0., 0., 0.);
    if(t[0] == 0.)
      ex[0] = 1.;
    else if(t[1] == 0.)
      ex[1] = 1.;
    else
      ex[2] = 1.;
    SVector3 n = crossprod(t, ex);
    n.normalize();
    return n;
  }
  inline SPoint3 barycenter() const
  {
    return interpolate(0.5);
  }
  inline SPoint3 interpolate(const double &t) const
  {
    return SPoint3(t * _v[1]->x() + (1. - t) * _v[0]->x(),
                   t * _v[1]->y() + (1. - t) * _v[0]->y(),
		   t * _v[1]->z() + (1. - t) * _v[0]->z());
  }
};

inline bool operator!=(const MEdge &e1, const MEdge &e2)
{
  return (e1.getMinVertex() != e2.getMinVertex() ||
          e1.getMaxVertex() != e2.getMaxVertex());
}
  
struct Equal_Edge : public std::binary_function<MEdge, MEdge, bool> {
  bool operator()(const MEdge &e1, const MEdge &e2) const
  {
    return (e1.getMinVertex() == e2.getMinVertex() &&
            e1.getMaxVertex() == e2.getMaxVertex());
  }
};

struct Less_Edge : public std::binary_function<MEdge, MEdge, bool> {
  bool operator()(const MEdge &e1, const MEdge &e2) const
  {
    if(e1.getMinVertex() < e2.getMinVertex()) return true;
    if(e1.getMinVertex() > e2.getMinVertex()) return false;
    if(e1.getMaxVertex() < e2.getMaxVertex()) return true;
    return false;
  }
};

#endif
