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
};

#endif
