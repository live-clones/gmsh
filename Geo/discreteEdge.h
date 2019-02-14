// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _DISCRETE_EDGE_H_
#define _DISCRETE_EDGE_H_

#include "GModel.h"
#include "GEdge.h"

class discreteEdge : public GEdge {
protected:
  std::vector<double> _pars;
  std::vector<MVertex *> discrete_vertices;
  std::vector<MLine *> discrete_lines;
  void orderMLines();
  bool getLocalParameter(const double &t, int &iEdge, double &tLoc) const;
  discreteEdge *_split[2];

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
  virtual int minimumMeshSegments() const { return periodic(0) ? 3: 2;}
  void setSplit (discreteEdge *e0, discreteEdge *e1) {
    _split[0] = e0;
    _split[1] = e1;
  }
  void getSplit (std::vector<GEdge*> & s) {
    if (_split[0] == NULL){
      if (std::find(s.begin(),s.end(),this) == s.end())
	s.push_back(this);
    }
    else {
      _split[0]->getSplit(s);
      _split[1]->getSplit(s);
    }
  }

};

#endif
