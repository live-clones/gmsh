// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Paul-Emile Bernard

#include <algorithm>
#include "GModel.h"
#include "MVertex.h"
#include "MPoint.h"
#include "GenericVertex.h"
#include "GenericEdge.h"
#include "GenericFace.h"

GenericVertex::ptrfunction_int_vector GenericVertex::VertexXYZ = NULL;
GenericVertex::ptrfunction_int_doubleptr_voidptr GenericVertex::VertexMeshSize = NULL;

GenericVertex::GenericVertex(GModel *m, int num, int _native_id)
 : GVertex(m, num), id(_native_id)
{
  if (!VertexXYZ)
    Msg::Fatal("GenericVertex::ERROR: Callback not set");

  std::vector<double> vec(3,0.);
  bool ok = VertexXYZ(id,vec);
  if (!ok) Msg::Error("GenericVertex::ERROR from callback VertexXYZ ");
  _x=vec[0];
  _y=vec[1];
  _z=vec[2];
}

GenericVertex::GenericVertex(GModel *m, int num, int _native_id, const std::vector<double> &vec)
 : GVertex(m, num), id(_native_id)
{
  if (!VertexXYZ)
    Msg::Fatal("GenericVertex::ERROR: Callback not set");
  _x=vec[0];
  _y=vec[1];
  _z=vec[2];
}

GenericVertex::~GenericVertex(){

}

SPoint2 GenericVertex::reparamOnFace(const GFace *gf, int dir) const
{
  SPoint3 pt(_x,_y,_z);
  return gf->parFromPoint(pt,true);
}

void GenericVertex::setPosition(GPoint &p)
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

