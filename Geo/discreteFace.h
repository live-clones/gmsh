// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISCRETE_FACE_H_
#define _DISCRETE_FACE_H_

#include "GModel.h"
#include "GFace.h"

class discreteFace : public GFace {
 public:
  discreteFace(GModel *model, int num);
  virtual ~discreteFace() {}
  virtual GPoint point(double par1, double par2) const;
  virtual SPoint2 parFromPoint(const SPoint3 &p) const;
  virtual SVector3 normal(const SPoint2 &param) const;
  virtual GEntity::GeomType geomType() const { return DiscreteSurface; }
  virtual Pair<SVector3,SVector3> firstDer(const SPoint2 &param) const;
};

#endif
