// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteVertex.h"
#include "MPoint.h"
#include "GModelIO_GEO.h"
#include "Geo.h"

discreteVertex::discreteVertex(GModel *m, int num, double x, double y, double z)
  : GVertex(m, num)
{
  _v = CreateVertex(num, x, y, z, 0, 0);
  Tree_Add(m->getGEOInternals()->Points, &_v);
}

discreteVertex::discreteVertex(GModel *m) : GVertex(m, 0), _v(nullptr)
{
  // used for temporary discrete vertices, that should not lead to the creation
  // of the corresponding entity in GEO internals
}

discreteVertex::~discreteVertex() {}

GPoint discreteVertex::point() const { return GPoint(x(), y(), z(), this); }

void discreteVertex::setPosition(GPoint &p)
{
  if(_v) {
    _v->Pos.X = p.x();
    _v->Pos.Y = p.y();
    _v->Pos.Z = p.z();
  }
  if(mesh_vertices.size()) {
    mesh_vertices[0]->x() = p.x();
    mesh_vertices[0]->y() = p.y();
    mesh_vertices[0]->z() = p.z();
  }
}

double discreteVertex::x() const
{
  if(mesh_vertices.size()) return mesh_vertices[0]->x();
  if(_v) return _v->Pos.X;
  Msg::Warning("No coordinate in discrete point %d", tag());
  return 0.;
}

double discreteVertex::y() const
{
  if(mesh_vertices.size()) return mesh_vertices[0]->y();
  if(_v) return _v->Pos.Y;
  Msg::Warning("No coordinate in discrete point %d", tag());
  return 0.;
}

double discreteVertex::z() const
{
  if(mesh_vertices.size()) return mesh_vertices[0]->z();
  if(_v) return _v->Pos.Z;
  Msg::Warning("No coordinate in discrete point %d", tag());
  return 0.;
}
