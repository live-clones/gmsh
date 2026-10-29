// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_REGION_H
#define DISCRETE_REGION_H

#include "GModel.h"
#include "GRegion.h"
#include "MFace.h"

class discreteRegion : public GRegion {
private:
  bool _geometry;
  ModelType _nativeType = UnknownModel;

public:
  // (geo: also create the volume in the GEO internals, so that scripts can
  // refer to it)
  discreteRegion(GModel *model, int num, bool geo = true);
  discreteRegion(GModel *model);
  virtual ~discreteRegion() {}
  virtual GeomType geomType() const { return DiscreteVolume; }
  virtual bool haveParametrization() { return _geometry; }
  int createGeometry();
  // UnknownModel, or the modeler that created the entity (the discrete CAD
  // modeler); a GEO synchronize removes the discrete entities of unknown
  // origin that the GEO internals do not hold
  void setNativeType(ModelType type) { _nativeType = type; }
  virtual ModelType getNativeType() const { return _nativeType; }
};

#endif
