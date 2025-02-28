// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef XY_EDGE_H
#define XY_EDGE_H

#include "GEdge.h"

class xyEdge : public GEdge {
public:
  xyEdge(GModel *gm, int t) : GEdge(gm, t){};
  virtual ~xyEdge() {}
  virtual Range<double> parBounds(int i) const { return Range<double>(0, 1); }
  virtual GeomType geomType() const { return GEntity::Line; }
  virtual GPoint point(double p) const { return GPoint(); }
  virtual SVector3 firstDer(double par) const { return SVector3(); }
  virtual SVector3 secondDer(double par) const { return SVector3(); }
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return nullptr; }
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const
  {
    return SPoint2();
  }
  virtual bool degenerate(int dim) const { return false; }
  virtual bool isMeshDegenerated() const { return false; }
};

#endif
