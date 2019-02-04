// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _XY_EDGE_H_
#define _XY_EDGE_H_

#include "GEdge.h"

class xyEdge : public GEdge {
public:
  xyEdge(GModel *gm, int t) : GEdge(gm, t) {};
  virtual ~xyEdge() {}
  virtual Range<double> parBounds(int i) const{
    return Range<double>(0, 1);
  }

  virtual GeomType geomType() const {
    return GEntity::Line;
  }

  virtual GPoint point(double p) const {
    throw;
  }
  
  virtual SVector3 firstDer(double par) const {
    throw;
  }

  virtual SVector3 secondDer(double par) const {
    throw;
  }
  
  ModelType getNativeType() const { return GmshModel; }
  void *getNativePtr() const { return NULL; }

  virtual SPoint2 reparamOnFace(const GFace *face, double epar, int dir) const {
    printf("NOOOOOOH\n");
  }

  virtual bool degenerate(int dim) const {return false;}

  virtual bool isMeshDegenerated() const {return false;}

};

#endif
