// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_EDGE_H
#define GMSH_EDGE_H

#include "GCurve.h"

class Curve;

class gmshEdge : public GCurve {
private:
  Curve *_c;

public:
  gmshEdge(GModel *model, Curve *c, GPoint *v1, GPoint *v2);
  virtual ~gmshEdge() {}
  virtual Range<double> parBounds(int i) const;
  virtual GeomType geomType() const;
  virtual bool haveParametrization();
  virtual GVertex point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual SVector3 secondDer(double par) const;
  virtual ModelType getNativeType() const { return GmshModel; }
  virtual void *getNativePtr() const { return _c; }
  virtual std::string getAdditionalInfoString(bool multline = false);
  virtual int minimumMeshSegments() const;
  virtual int minimumDrawSegments() const;
  virtual void resetMeshAttributes();
  virtual SPoint2 reparamOnFace(const GSurface *face, double epar, int dir) const;
  virtual void writeGEO(FILE *fp);
  virtual void discretize(double tol, std::vector<SPoint3> &dpts,
                          std::vector<double> &ts);
  virtual bool degenerate(int dim) const;
  void resetNativePtr(Curve *edge, GPoint *v1, GPoint *v2);
};

#endif
