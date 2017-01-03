// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DISCRETE_EDGE_H_
#define _DISCRETE_EDGE_H_

#include "GModel.h"
#include "GEdge.h"
#include "discreteVertex.h"

class discreteEdge : public GEdge {
 protected:
  std::map<MVertex*,MVertex*> v2v;
  std::vector<double> _pars;
  std::vector<int> _orientation;// ?
  std::map<MVertex*, MLine*> boundv;
  bool createdTopo;
  std::vector<MVertex*> discrete_vertices;
  std::vector<MLine*>  discrete_lines;
 public:
  discreteEdge(GModel *model, int num, GVertex *_v0, GVertex *_v1);
  virtual ~discreteEdge() {}
  virtual GeomType geomType() const { return DiscreteCurve; }
  virtual GPoint point(double p) const;
  virtual SVector3 firstDer(double par) const;
  virtual double curvature(double par) const;
  virtual double curvatures(const double par, SVector3 *dirMax, SVector3 *dirMin,
                            double *curvMax, double *curvMin) const;
  virtual bool haveParametrization(){ return !_pars.empty(); }
  virtual Range<double> parBounds(int) const;

  bool getLocalParameter(const double &t, int &iEdge, double &tLoc) const;
  void interpolateInGeometry (MVertex *v, MVertex **v1, MVertex **v2, double &xi) const; 
  void parametrize(std::map<GFace*, std::map<MVertex*, MVertex*,
                   std::less<MVertex*> > > &face2Verts,
                   std::map<GRegion*, std::map<MVertex*, MVertex*,
                   std::less<MVertex*> > > &region2Vert);
  void parametrize(std::map<MVertex*,MVertex*>& old2New);
  
  void orderMLines();
  void setBoundVertices();
  void setTopo(std::vector<MLine*>);
  void createTopo();
  void createGeometry();
  void computeNormals () const;
  virtual void mesh(bool) ;
  void writeGEO(FILE *fp);
  int minimumDrawSegments() const {return 2*_pars.size();}
  MVertex * getGeometricalVertex (MVertex *v);
};

#endif
