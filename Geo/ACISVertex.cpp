// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
  Msg::Fatal("NOT DONE !!!!!!!!!!!\n");
}

GVertex *getACISVertexByNativePtr(GModel *model, VERTEX* toFind)
{
  GModel::viter it =model->firstVertex();
  for (; it != model->lastVertex(); it++){
    ACISVertex *av = dynamic_cast<ACISVertex*>(*it);
    if (av){
      if (toFind == av->getVERTEX()){
	return *it;
      }
    }
  }
  return 0;
}

#endif
