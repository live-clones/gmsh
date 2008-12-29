// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISCRETE_REGION_H_
#define _DISCRETE_REGION_H_

#include "GModel.h"
#include "GRegion.h"

class discreteRegion : public GRegion {
 public:
  discreteRegion(GModel *model, int num);
  virtual ~discreteRegion() {}
  virtual GeomType geomType() const { return DiscreteVolume; }
};

#endif
