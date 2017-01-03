// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _GEDGE_COMPOUND_H_
#define _GEDGE_COMPOUND_H_

#include "GFace.h"
#include "GEdge.h"

// A GEdgeCompound is a model edge that is the compound of model edges.

class GEdgeCompound : public GEdge {
 protected:
  std::vector<GEdge*> _compound;
  std::vector<int> _orientation;
  std::vector<double> _pars;
  void orderEdges();
 public:
  void parametrize();
  bool getLocalParameter(const double &t, int &iEdge, double & tLoc) const;
  GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound);
  GEdgeCompound(GModel *m, int tag, std::vector<GEdge*> &compound,
                std::vector<int> &orientation); // confidence in the input
  virtual ~GEdgeCompound();
  Range<double> parBounds(int i) const;
  virtual GPoint point(double par) const;
  virtual SVector3 firstDer(double par) const;
  virtual GEntity::GeomType geomType() const { return CompoundCurve;  }
  ModelType getNativeType() const { return GmshModel; }
  void * getNativePtr() const { return 0; }
  virtual double curvature(double t) const;
  virtual double curvatures(const double par, SVector3 *dirMax, SVector3 *dirMin,
   double *curvMax, double *curvMin) const;
  virtual int minimumMeshSegments() const;
  virtual int minimumDrawSegments() const;
  std::vector<GEdge*>  getCompounds() const { return _compound; }
};

void replaceMeshCompound(GFace*, std::list<GEdge*>&);

#endif
