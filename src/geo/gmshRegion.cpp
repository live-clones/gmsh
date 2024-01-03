// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GModel.h"
#include "gmshRegion.h"
#include "Geo.h"
#include "GmshMessage.h"

gmshRegion::gmshRegion(GModel *m, ::Volume *v) : GRegion(m, v->Num)
{
  resetNativePtr(v);
  gmshRegion::resetMeshAttributes();
}

void gmshRegion::resetNativePtr(::Volume *v)
{
  _v = v;
  l_faces.clear();
  l_dirs.clear();
  for(int i = 0; i < List_Nbr(_v->Surfaces); i++) {
    Surface *s;
    List_Read(_v->Surfaces, i, &s);
    int ori;
    List_Read(_v->SurfacesOrientations, i, &ori);
    GFace *f = model()->getFaceByTag(abs(s->Num));
    if(f) {
      l_faces.push_back(f);
      l_dirs.push_back(ori);
      f->addRegion(this);
    }
    else
      Msg::Error("Unknown surface %d", s->Num);
  }
  for(int i = 0; i < List_Nbr(_v->SurfacesByTag); i++) {
    int is;
    List_Read(_v->SurfacesByTag, i, &is);
    GFace *f = model()->getFaceByTag(abs(is));
    if(f) {
      l_faces.push_back(f);
      l_dirs.push_back(gmsh_sign(is));
      f->addRegion(this);
    }
    else
      Msg::Error("Unknown surface %d", is);
  }
}

void gmshRegion::resetMeshAttributes()
{
  meshAttributes.recombine3D = _v->Recombine3D;
  meshAttributes.method = _v->Method;
  meshAttributes.QuadTri = _v->QuadTri;
  meshAttributes.extrude = _v->Extrude;
  if(meshAttributes.method == MESH_TRANSFINITE) {
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(_v->TrsfPoints); i++) {
      Vertex *corn;
      List_Read(_v->TrsfPoints, i, &corn);
      GVertex *gv = model()->getVertexByTag(corn->Num);
      if(gv)
        meshAttributes.corners.push_back(gv);
      else
        Msg::Error("Unknown point %d in transfinite attributes", corn->Num);
    }
  }
}

GEntity::GeomType gmshRegion::geomType() const
{
  switch(_v->Typ) {
  case MSH_VOLUME_DISCRETE: return DiscreteVolume;
  default: return Volume;
  }
}
