// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_FACE_H
#define GMSH_FACE_H

#include "GFace.h"

class Surface;

class gmshFace : public GFace {
private:
  Surface *_s;
  Range<double> _parBounds[2];

public:
  gmshFace(GModel *m, Surface *s);
  virtual ~gmshFace() {}
  virtual Range<double> parBounds(int i) const { return _parBounds[i]; }
  using GFace::point;
  virtual GPoint point(double par1, double par2) const;
  virtual GPoint closestPoint(const SPoint3 &queryPoint,
                              const double initialGuess[2]) const;
  virtual bool containsPoint(const SPoint3 &pt) const;
  virtual double getMetricEigenvalue(const SPoint2 &);
  virtual SVector3 normal(const SPoint2 &param) const;
  virtual Pair<SVector3, SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &, SVector3 &, SVector3 &,
                         SVector3 &) const;
  virtual GEntity::GeomType geomType() const;
  virtual bool haveParametrization();
  virtual ModelType getNativeType() const { return GmshModel; }
  virtual void *getNativePtr() const { return _s; }
  virtual SPoint2 parFromPoint(const SPoint3 &, bool onSurface = true,
                               bool convTestXYZ = false) const;
  virtual void resetMeshAttributes();
  void resetNativePtr(Surface *s);
  bool degenerate(int dim) const;
};

#endif
