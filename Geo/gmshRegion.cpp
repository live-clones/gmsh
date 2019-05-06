// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GModel.h"
#include "gmshRegion.h"
#include "Geo.h"
#include "GmshMessage.h"

gmshRegion::gmshRegion(GModel *m, ::Volume *volume) : GRegion(m, volume->Num)
{
  resetNativePtr(volume);
  gmshRegion::resetMeshAttributes();
}

void gmshRegion::resetNativePtr(::Volume *volume)
{
  v = volume;
  l_faces.clear();
  l_dirs.clear();
  for(int i = 0; i < List_Nbr(v->Surfaces); i++) {
    Surface *s;
    List_Read(v->Surfaces, i, &s);
    int ori;
    List_Read(v->SurfacesOrientations, i, &ori);
    GFace *f = model()->getFaceByTag(abs(s->Num));
    if(f) {
      l_faces.push_back(f);
      l_dirs.push_back(ori);
      f->addRegion(this);
    }
    else
      Msg::Error("Unknown surface %d", s->Num);
  }
  for(int i = 0; i < List_Nbr(v->SurfacesByTag); i++) {
    int is;
    List_Read(v->SurfacesByTag, i, &is);
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
  meshAttributes.recombine3D = v->Recombine3D;
  meshAttributes.method = v->Method;
  meshAttributes.QuadTri = v->QuadTri;
  meshAttributes.extrude = v->Extrude;
  if(meshAttributes.method == MESH_TRANSFINITE) {
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(v->TrsfPoints); i++) {
      Vertex *corn;
      List_Read(v->TrsfPoints, i, &corn);
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
  switch(v->Typ) {
  case MSH_VOLUME_DISCRETE: return DiscreteVolume;
  default: return Volume;
  }
}
