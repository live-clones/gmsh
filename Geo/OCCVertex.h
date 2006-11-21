#ifndef _OCC_VERTEX_H_
#define _OCC_VERTEX_H_

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

#include "Mesh.h"
#include "GModel.h"
#include "OCCIncludes.h"
#include "GVertex.h"
#include "Context.h"

#if defined(HAVE_OCC)

class OCCVertex : public GVertex {
 protected:
  TopoDS_Vertex v;
  mutable double max_curvature;
  double max_curvature_of_surfaces() const;
 public:
  OCCVertex(GModel *m, int num, TopoDS_Vertex _v) : GVertex(m, num), v(_v)
  {
    max_curvature = -1;
    mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  }
  virtual ~OCCVertex() {}
  virtual GPoint point() const 
  {
    return GPoint(x(),y(),z());
  }
  virtual double x() const 
  {
    gp_Pnt pnt = BRep_Tool::Pnt (v);
    return pnt.X();
  }
  virtual double y() const 
  {
    gp_Pnt pnt = BRep_Tool::Pnt (v);
    return pnt.Y();
  }
  virtual double z() const 
  {
    gp_Pnt pnt = BRep_Tool::Pnt (v);
    return pnt.Z();
  }
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*) &v; }
  virtual double prescribedMeshSizeAtVertex() const;
  virtual SPoint2 reparamOnFace ( GFace *gf , int) const;
};

#endif

#endif
