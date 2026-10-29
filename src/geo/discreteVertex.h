// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_VERTEX_H
#define DISCRETE_VERTEX_H

#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

class Vertex;

class discreteVertex : public GVertex {
private:
  Vertex *_v;
  // the position, when it is not held by a point of the GEO internals
  bool _hasPosition;
  double _position[3];
  ModelType _nativeType = UnknownModel;

public:
  // (geo: also create the point in the GEO internals, so that scripts can
  // refer to it)
  discreteVertex(GModel *m, int num, double x = 0., double y = 0.,
                 double z = 0., bool geo = true);
  discreteVertex(GModel *m);
  virtual ~discreteVertex();
  virtual GPoint point() const;
  virtual double x() const;
  virtual double y() const;
  virtual double z() const;
  virtual void setPosition(GPoint &p);
  // UnknownModel, or the modeler that created the entity (the discrete CAD
  // modeler); a GEO synchronize removes the discrete entities of unknown
  // origin that the GEO internals do not hold
  void setNativeType(ModelType type) { _nativeType = type; }
  virtual ModelType getNativeType() const { return _nativeType; }
};

#endif
