// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OCC_VERTEX_H_
#define _OCC_VERTEX_H_

#include "GModel.h"
#include "OCCIncludes.h"
#include "GVertex.h"
#include "MVertex.h"

#if defined(HAVE_OCC)

class OCCVertex : public GVertex {
 protected:
  TopoDS_Vertex v;
  double _x, _y, _z;
  mutable double max_curvature;
  double max_curvature_of_surfaces() const;
 public:
  OCCVertex(GModel *m, int num, TopoDS_Vertex _v) : GVertex(m, num), v(_v)
  {
    max_curvature = -1;
    gp_Pnt pnt = BRep_Tool::Pnt(v);
    _x = pnt.X();
    _y = pnt.Y();
    _z = pnt.Z();
    mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  }
  virtual ~OCCVertex() {}
  virtual GPoint point() const { return GPoint(x(), y(), z()); }
  virtual double x() const { return _x; }
  virtual double y() const { return _y; }
  virtual double z() const { return _z; }
  virtual void setPosition(GPoint &p)
  {
    _x = p.x();
    _y = p.y();
    _z = p.z();
    delete mesh_vertices[0];
    mesh_vertices.clear();
    mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  }
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*)&v; }
  virtual SPoint2 reparamOnFace ( GFace *gf , int) const;
};

#endif

#endif
