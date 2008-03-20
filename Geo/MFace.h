#ifndef _MFACE_H_
#define _MFACE_H_

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
#include <vector>
#include "MVertex.h"
#include "SVector3.h"

// A mesh face.
class MFace {
 private:
  MVertex *_v[4];
  char _si[4]; // sorted indices

 public:
  MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3=0);
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
  SVector3 normal() const;
  SVector3 tangent(int num) const
  {
    SVector3 t0(_v[1]->x() - _v[0]->x(), 
                _v[1]->y() - _v[0]->y(),
                _v[1]->z() - _v[0]->z());
    t0.normalize();
    if(!num) return t0;
    SVector3 n = normal();
    SVector3 t1 = crossprod(n, t0);
    return t1;
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
  SPoint3 interpolate(const double &u, const double &v) const
  {
    SPoint3 p(0., 0., 0.);
    int n = getNumVertices();
    if(n == 3){
      const double ff[3] = {1. - u - v, u, v};
      for(int i = 0; i < n; i++) {
        MVertex *v = getVertex(i);
        p[0] += v->x() * ff[i];
        p[1] += v->y() * ff[i];
        p[2] += v->z() * ff[i];
      }
    }
    else if(n == 4){
      const double ff[4] = {(1 - u) * (1. - v),
                            (1 + u) * (1. - v),
                            (1 + u) * (1. + v),
                            (1 - u) * (1. + v)};        
      for(int i = 0; i < n; i++) {
        MVertex *v = getVertex(i);
        p[0] += v->x() * ff[i] * .25;
        p[1] += v->y() * ff[i] * .25;
        p[2] += v->z() * ff[i] * .25;
      } 
    }
    else throw;
    return p;
  }
};

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

#endif
