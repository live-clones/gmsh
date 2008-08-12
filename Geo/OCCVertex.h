// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OCC_VERTEX_H_
#define _OCC_VERTEX_H_

#include "GModel.h"
#include "OCCIncludes.h"
#include "GVertex.h"

#if defined(HAVE_OCC)

class OCCVertex : public GVertex {
 protected:
  TopoDS_Vertex v;
  double _x, _y, _z;
  mutable double max_curvature;
  double max_curvature_of_surfaces() const;
 public:
  OCCVertex(GModel *m, int num, TopoDS_Vertex _v);
  virtual ~OCCVertex() {}
  virtual GPoint point() const { return GPoint(x(), y(), z()); }
  virtual double x() const { return _x; }
  virtual double y() const { return _y; }
  virtual double z() const { return _z; }
  virtual void setPosition(GPoint &p);
  ModelType getNativeType() const { return OpenCascadeModel; }
  void * getNativePtr() const { return (void*)&v; }
  virtual SPoint2 reparamOnFace(GFace *gf, int) const;
};

#endif

#endif
