#ifndef _GVERTEX_H_
#define _GVERTEX_H_

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

#include "GEntity.h"
#include "GPoint.h"
#include "SPoint2.h"

// A model vertex
class GVertex : public GEntity 
{
 protected:
  std::list<GEdge*> l_edges;
  double meshSize;
 public:
  GVertex(GModel *m, int tag, double ms=1.e22);
  virtual ~GVertex();
  virtual GPoint point() const = 0;
  virtual double x() const = 0;
  virtual double y() const = 0;
  virtual double z() const = 0;
  virtual void setPosition(GPoint &p);
  void addEdge(GEdge *e);
  void delEdge(GEdge *e);
  virtual int dim() const { return 0; }
  virtual GeomType geomType() const { return Point; }
  inline double prescribedMeshSizeAtVertex() const { return meshSize; }
  virtual void setPrescribedMeshSizeAtVertex(double l) { meshSize = l; }
  virtual SBoundingBox3d bounds(){ return SBoundingBox3d(SPoint3(x(), y(), z())); }
  virtual SPoint2 reparamOnFace(GFace *gf, int) const;
  virtual std::string getAdditionalInfoString();
  virtual std::list<GEdge*> edges() const{ return l_edges; }
};

#endif

