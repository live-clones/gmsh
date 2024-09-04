// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OCC_VERTEX_H
#define OCC_VERTEX_H

#include "GmshConfig.h"
#include "GModel.h"
#include "GVertex.h"

#if defined(HAVE_OCC)

#include <TopoDS_Vertex.hxx>

class OCCVertex : public GVertex {
private:
  TopoDS_Vertex _v;
  double _x, _y, _z;

public:
  OCCVertex(GModel *m, TopoDS_Vertex v, int num, double lc = MAX_LC);
  virtual ~OCCVertex() {}
  virtual GPoint point() const { return GPoint(x(), y(), z()); }
  virtual double x() const { return _x; }
  virtual double y() const { return _y; }
  virtual double z() const { return _z; }
  virtual void setPosition(GPoint &p);
  virtual ModelType getNativeType() const { return OpenCascadeModel; }
  virtual void *getNativePtr() const { return (void *)&_v; }
  virtual SPoint2 reparamOnFace(const GFace *gf, int) const;
  TopoDS_Vertex getShape() { return _v; }
};

#endif

#endif
