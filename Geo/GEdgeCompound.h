// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GEDGE_COMPOUND_H_
#define _GEDGE_COMPOUND_H_

#include "GFace.h"
#include "GEdge.h"

/*
A GEdgeCompound is a model edge that is the compound of model edges.
*/

class GEdgeCompound : public GEdge {
 protected:
  std::vector<GEdge*> _compound;
  std::vector<int> _orientation;
  std::vector<double> _pars;
  void parametrize() ;
  void orderEdges()  ;
  
public:
  void getLocalParameter ( const double &t,
			   int &iEdge,
			   double & tLoc) const;
  GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound);
  virtual ~GEdgeCompound();
  Range<double> parBounds(int i) const;
  virtual GPoint point(double par) const; 
  virtual SVector3 firstDer(double par) const; 
  virtual GEntity::GeomType geomType() const { return CompoundCurve; }
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return 0; }
  virtual double curvature(double t) const;
  virtual int minimumMeshSegments() const;
  virtual int minimumDrawSegments() const;
  std::vector<GEdge*>  getEdgesOfCompound() const { return _compound; }
};

#endif
