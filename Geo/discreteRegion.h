// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DISCRETE_REGION_H_
#define _DISCRETE_REGION_H_

#include "GModel.h"
#include "GRegion.h"
#include "MFace.h"

class discreteRegion : public GRegion {
 public:
  discreteRegion(GModel *model, int num);
  virtual ~discreteRegion() {}
  virtual GeomType geomType() const { return DiscreteVolume; }
  void setBoundFaces(std::set<int> tagFaces);
  void findFaces(std::map<MFace, std::vector<int>, Less_Face> &map_faces);
  virtual void remesh();
};

#endif
