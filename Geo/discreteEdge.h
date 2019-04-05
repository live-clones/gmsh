// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_EDGE_H
#define DISCRETE_EDGE_H

#include "GModel.h"
#include "GEdge.h"

class discreteEdge : public GEdge {
protected:
  std::vector<double> _pars;
  std::vector<SPoint3> _discretization;
  void orderMLines();
  bool getLocalParameter(const double &t, int &iEdge, double &tLoc) const;
  discreteEdge *_split[3];
  GVertex *_vsplit;

public:
  discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1);
  discreteEdge(GModel *model, int num);
  virtual ~discreteEdge();
  virtual GeomType geomType() const { return DiscreteCurve; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual bool haveParametrization() { return !_pars.empty(); }
  virtual Range<double> parBounds(int) const;
  void createGeometry();
  virtual void mesh(bool verbose);
  int minimumDrawSegments() const { return 2 * _pars.size(); }
  virtual int minimumMeshSegments() const { return periodic(0) ? 3 : 2; }
  void setSplit(discreteEdge *e0, discreteEdge *e1, GVertex *vs)
  {
    _split[0] = e0;
    _split[1] = e1;
    e0->_split[2] = this;
    e1->_split[2] = this;
    _vsplit = vs;
  }
  void getSplit(std::vector<GEdge *> &s, std::vector<GVertex *> &vs)
  {
    if(_split[0] == NULL) {
      if(std::find(s.begin(), s.end(), this) == s.end()) { s.push_back(this); }
    }
    else {
      vs.push_back(_vsplit);
      _split[0]->getSplit(s, vs);
      _split[1]->getSplit(s, vs);
    }
  }
  void unsplit();
  bool split(MVertex *v, GVertex *gv, int &TAG);
  void writeParametrization (FILE *fp, bool binary);
  void readParametrization (FILE *fp, bool binary);
};

#endif
