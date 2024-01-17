// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_EDGE_H
#define DISCRETE_EDGE_H

#include "GModel.h"
#include "GEdge.h"

class discreteEdge : public GEdge {
private:
  std::vector<double> _pars;
  std::vector<SPoint3> _discretization;
  bool _getLocalParameter(const double &t, int &iEdge, double &tLoc) const;

public:
  discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1);
  discreteEdge(GModel *model, int num);
  discreteEdge(GModel *model);
  virtual ~discreteEdge() {}
  virtual GeomType geomType() const { return DiscreteCurve; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual bool haveParametrization() { return !_pars.empty(); }
  virtual Range<double> parBounds(int) const;
  int createGeometry();
  virtual void mesh(bool verbose);
  int minimumDrawSegments() const { return 2 * _pars.size(); }
  virtual int minimumMeshSegments() const { return periodic(0) ? 3 : 2; }
  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const;
  bool writeParametrization(FILE *fp, bool binary);
  bool readParametrization(FILE *fp, bool binary);
};

#endif
