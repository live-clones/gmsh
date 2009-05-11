// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GModel.h"
#include "GFace.h"
#include "discreteEdge.h"

class discreteFace : public GFace {
 public:
  discreteFace(GModel *model, int num);
  virtual ~discreteFace() {}
  virtual GPoint point(double par1, double par2) const;
  virtual SPoint2 parFromPoint(const SPoint3 &p) const;
  virtual SVector3 normal(const SPoint2 &param) const;
  virtual GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const;
  virtual void secondDer(const SPoint2 &param, 
                         SVector3 *dudu, SVector3 *dvdv, SVector3 *dudv) const;
  void setBoundEdges( std::vector<discreteEdge*> edges );
};

#endif
