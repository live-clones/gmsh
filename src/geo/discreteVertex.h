// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_VERTEX_H
#define DISCRETE_VERTEX_H

#include "GModel.h"
#include "GPoint.h"
#include "MNode.h"

class Vertex;

class discreteVertex : public GPoint {
private:
  Vertex *_v;

public:
  discreteVertex(GModel *m, int num, double x = 0., double y = 0.,
                 double z = 0.);
  discreteVertex(GModel *m);
  virtual ~discreteVertex();
  virtual GVertex point() const;
  virtual double x() const;
  virtual double y() const;
  virtual double z() const;
  virtual void setPosition(GVertex &p);
};

#endif
