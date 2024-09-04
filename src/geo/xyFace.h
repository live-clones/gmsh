// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// a face in the XY plane for simple 2D interface meshing

#ifndef XY_FACE_H
#define XY_FACE_H

#include "xyEdge.h"
#include "GFace.h"

class xyFace : public GFace {
public:
  xyFace(GModel *gm, int t, xyEdge *e) : GFace(gm, t) { l_edges.push_back(e); }
  virtual ~xyFace() {}
  Range<double> parBounds(int i) const { return Range<double>(0, 1); }
  virtual GPoint point(double par1, double par2) const
  {
    double pp[2] = {par1, par2};
    return GPoint(par1, par2, 0.0, this, pp);
  }
  virtual GPoint closestPoint(const SPoint3 &queryPoint,
                              const double initialGuess[2]) const
  {
    double u[2] = {queryPoint.x(), queryPoint.y()};
    return GPoint(queryPoint.x(), queryPoint.y(), 0.0, this, u);
  }
  virtual bool containsPoint(const SPoint3 &pt) const { return true; }
  virtual SVector3 normal(const SPoint2 &param) const
  {
    SVector3 n(0, 0, 1);
    return n;
  }
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const
  {
    SVector3 t1(1, 0, 0);
    SVector3 t2(0, 1, 0);
    return Pair<SVector3, SVector3>(t1, t2);
  }
  virtual void secondDer(const SPoint2 &, SVector3 &a, SVector3 &b,
                         SVector3 &c) const
  {
    SVector3 v(0, 0, 0);
    a = v;
    b = v;
    c = v;
  }
  virtual GEntity::GeomType geomType() const { return GEntity::Plane; }
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return nullptr; }
  virtual SPoint2 parFromPoint(const SPoint3 &p, bool onSurface = true,
                               bool convTestXYZ = false) const
  {
    return SPoint2(p.x(), p.y());
  }
  bool degenerate(int dim) const { return false; }
};

#endif
