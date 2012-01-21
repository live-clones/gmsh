// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISCRETE_EDGE_H_
#define _DISCRETE_EDGE_H_

#include "GModel.h"
#include "GEdge.h"
#include "discreteVertex.h"

class discreteEdge : public GEdge {
 protected:
  std::vector<double> _pars;
  std::vector<int> _orientation;
  std::map<MVertex*, MLine*> boundv;
  bool createdTopo;
 public:
  discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1);
  virtual ~discreteEdge() {}
  virtual GeomType geomType() const { return DiscreteCurve; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual bool haveParametrization(){ return !_pars.empty(); }
  virtual Range<double> parBounds(int) const;

  bool getLocalParameter(const double &t, int &iEdge, double &tLoc) const;
  void parametrize(std::map<GFace*, std::map<MVertex*, MVertex*, 
                   std::less<MVertex*> > > &face2Verts, 
                   std::map<GRegion*, std::map<MVertex*, MVertex*,
                   std::less<MVertex*> > > &region2Vert);
  void orderMLines();
  void setBoundVertices();
  void createTopo();
  void computeNormals () const;
  void writeGEO(FILE *fp);
};

#endif
