#ifndef _MEDGE_H_
#define _MEDGE_H_

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

#include "MVertex.h"
#include "SVector3.h"

class MElement;

class MEdge {
 private:
  MVertex *_v[2];
  
 public:
  MEdge(MVertex *v0, MVertex *v1, MElement *e) 
  {
    _v[0] = v0; _v[1] = v1;
  }
  inline int getNumVertices() const { return 2; }
  inline MVertex *getVertex(int i) const { return _v[i]; }
  inline MVertex *getMinVertex() const { return std::min(_v[0], _v[1]); }
  inline MVertex *getMaxVertex() const { return std::max(_v[0], _v[1]); }
  SVector3 tangent()
  {
    SVector3 t(_v[1]->x() - _v[0]->x(), 
	       _v[1]->y() - _v[0]->y(),
	       _v[1]->z() - _v[0]->z());
    t.normalize();
    return t;
  }
  SPoint3 barycenter()
  {
    return SPoint3(0.5 * (_v[0]->x() + _v[1]->x()), 
		   0.5 * (_v[0]->y() + _v[1]->y()), 
		   0.5 * (_v[0]->z() + _v[1]->z()));
  }
};

class MEdgeLessThan {
 public:
  bool operator()(const MEdge &e1, const MEdge &e2) const
  {
    int e10 = e1.getVertex(0)->getNum();
    int e11 = e1.getVertex(1)->getNum();
    int e20 = e2.getVertex(0)->getNum();
    int e21 = e2.getVertex(1)->getNum();
    int i1 = std::min(e10, e11);
    int i2 = std::min(e20, e21);
    if(i1 < i2)
      return true;
    if(i1 > i2)
      return false;
    int j1 = std::max(e10, e11);
    int j2 = std::max(e20, e21);
    if(j1 < j2)
      return true;
    return false;
  }
};

#endif
