// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISCRETE_VERTEX_H_
#define _DISCRETE_VERTEX_H_

#include "GModel.h"
#include "GVertex.h"
#include "MVertex.h"

class discreteVertex : public GVertex {
 public:
  discreteVertex(GModel *m, int num) : GVertex(m, num) {}
  virtual ~discreteVertex() {}
  virtual GPoint point() const { return GPoint(x(), y(), z(), this); }
  virtual double x() const 
  { 
    return mesh_vertices.size() ? mesh_vertices[0]->x() : 0.;
  }
  virtual double y() const
  { 
    return mesh_vertices.size() ? mesh_vertices[0]->y() : 0.;
  }
  virtual double z() const
  { 
    return mesh_vertices.size() ? mesh_vertices[0]->z() : 0.;
  }
};

#endif
