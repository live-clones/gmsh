#ifndef _DISCRETE_VERTEX_H_
#define _DISCRETE_VERTEX_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

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
