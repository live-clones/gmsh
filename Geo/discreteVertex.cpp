// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "discreteVertex.h"
#include "MPoint.h"
#include "GModelIO_GEO.h"
#include "Geo.h"

discreteVertex::discreteVertex(GModel *m, int num, double x, double y, double z)
  : GVertex(m, num), _x(x), _y(y), _z(z)
{
  Vertex *v = CreateVertex(num, x, y, z, 0, 0);
  Tree_Add(m->getGEOInternals()->Points, &v);
}

discreteVertex::~discreteVertex()
{
}

GPoint discreteVertex::point() const
{
  return GPoint(x(), y(), z(), this);
}

double discreteVertex::x() const
{
  return mesh_vertices.size() ? mesh_vertices[0]->x() : _x;
}

double discreteVertex::y() const
{
  return mesh_vertices.size() ? mesh_vertices[0]->y() : _y;
}

double discreteVertex::z() const
{
  return mesh_vertices.size() ? mesh_vertices[0]->z() : _z;
}
