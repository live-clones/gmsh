// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
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
#include "GmshDefines.h"
#include "Context.h"

discreteVertex::discreteVertex(GModel *m, int num, double x, double y, double z,
                               bool geo)
  : GVertex(m, num), _v(nullptr), _hasPosition(!geo), _position{x, y, z}
{
  if(!geo) return;
  _v = CreateVertex(num, x, y, z, 0, 0);
  Tree_Add(m->getGEOInternals()->Points, &_v);
}

discreteVertex::discreteVertex(GModel *m)
  : GVertex(m, 0), _v(nullptr), _hasPosition(false), _position{0., 0., 0.}
{
  // used for temporary discrete vertices, that should not lead to the creation
  // of the corresponding entity in GEO internals
}

discreteVertex::~discreteVertex() {}

GPoint discreteVertex::point() const { return GPoint(x(), y(), z(), this); }

void discreteVertex::setPosition(GPoint &p)
{
  CTX::instance()->geomChanged();
  if(_v) {
    _v->Pos.X = p.x();
    _v->Pos.Y = p.y();
    _v->Pos.Z = p.z();
  }
  _position[0] = p.x();
  _position[1] = p.y();
  _position[2] = p.z();
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
  if(_hasPosition) return _position[0];
  Msg::Warning("No coordinate in discrete point %d", tag());
  return 0.;
}

double discreteVertex::y() const
{
  if(mesh_vertices.size()) return mesh_vertices[0]->y();
  if(_v) return _v->Pos.Y;
  if(_hasPosition) return _position[1];
  Msg::Warning("No coordinate in discrete point %d", tag());
  return 0.;
}

double discreteVertex::z() const
{
  if(mesh_vertices.size()) return mesh_vertices[0]->z();
  if(_v) return _v->Pos.Z;
  if(_hasPosition) return _position[2];
  Msg::Warning("No coordinate in discrete point %d", tag());
  return 0.;
}
