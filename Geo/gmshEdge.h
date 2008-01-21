#ifndef _GMSH_EDGE_H_
#define _GMSH_EDGE_H_

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

#include "Geo.h"
#include "GEdge.h"

class gmshEdge : public GEdge {
 protected:
  Curve *c; 

 public:
  gmshEdge(GModel *model, Curve *edge, GVertex *v1, GVertex *v2);
  virtual ~gmshEdge() {}
  virtual Range<double> parBounds(int i) const;
  virtual GeomType geomType() const;
  virtual GPoint point(double p) const;
  virtual GPoint closestPoint(const SPoint3 & queryPoint) const;
  virtual int containsParam(double pt) const;
  virtual SVector3 firstDer(double par) const;
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return c; }
  virtual double parFromPoint(const SPoint3 &pt) const;
  virtual int minimumMeshSegments() const;
  virtual int minimumDrawSegments() const;
  virtual void resetMeshAttributes();
  virtual SPoint2 reparamOnFace(GFace *face, double epar, int dir) const;
};

#endif
