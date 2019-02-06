// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _DISCRETE_VERTEX_H_
#define _DISCRETE_VERTEX_H_

#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

class discreteVertex : public GVertex {
private:
  double _x, _y, _z;
public:
  discreteVertex(GModel *m, int num, double x = 0., double y = 0.,
                 double z = 0.);
  virtual ~discreteVertex();
  virtual GPoint point() const;
  virtual double x() const;
  virtual double y() const;
  virtual double z() const;
};

#endif
