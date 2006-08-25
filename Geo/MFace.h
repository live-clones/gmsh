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

#include <vector>
#include "MVertex.h"
#include "SVector3.h"
#include "Numeric.h"
#include "Context.h"

extern Context_T CTX;

// A mesh face.
class MFace {
 private:
  MVertex *_v[4];
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
  }
  inline int getNumVertices() const { return _v[3] ? 4 : 3; }
  inline MVertex *getVertex(int i) const { return _v[i]; }
  void getOrderedVertices(std::vector<MVertex*> &verts)
  {
    for(int i = 0; i < getNumVertices(); i++)
      verts.push_back(getVertex(i));
    std::sort(verts.begin(), verts.end());
  }
  SVector3 normal()
  {
    double n[3];
    normal3points(_v[0]->x(), _v[0]->y(), _v[0]->z(),
		  _v[1]->x(), _v[1]->y(), _v[1]->z(),
		  _v[2]->x(), _v[2]->y(), _v[2]->z(), n);
    return SVector3(n[0], n[1], n[2]);
  }
  SPoint3 barycenter()
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

#endif
