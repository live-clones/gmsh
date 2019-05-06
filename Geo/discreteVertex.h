// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISCRETE_VERTEX_H
#define DISCRETE_VERTEX_H

#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

class Vertex;

class discreteVertex : public GVertex {
private:
  Vertex *_v;
public:
  discreteVertex(GModel *m, int num, double x = 0., double y = 0.,
                 double z = 0.);
  virtual ~discreteVertex();
  virtual GPoint point() const;
  virtual double x() const;
  virtual double y() const;
  virtual double z() const;
  virtual void setPosition(GPoint &p);
};

#endif
