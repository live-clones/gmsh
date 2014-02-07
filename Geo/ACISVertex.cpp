// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "ACISVertex.h"
#include "MPoint.h"

#if defined(HAVE_ACIS)
#include <point.hxx>

ACISVertex::ACISVertex(GModel *m, int num, VERTEX *v)
  : GVertex(m, num), _v(v)
{
  APOINT *p = _v->geometry();
  const SPAposition &pos = p->coords();
  _x = pos.coordinate(0);
  _y = pos.coordinate(1);
  _z = pos.coordinate(2);
}

void ACISVertex::setPosition(GPoint &p)
{
  _x = p.x();
  _y = p.y();
  _z = p.z();
  if(mesh_vertices.size()){
    mesh_vertices[0]->x() = p.x();
    mesh_vertices[0]->y() = p.y();
    mesh_vertices[0]->z() = p.z();
  }
}

SPoint2 ACISVertex::reparamOnFace(const GFace *gf, int dir) const
{
