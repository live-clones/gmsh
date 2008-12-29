// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "GModel.h"
#include "gmshRegion.h"
#include "Geo.h"
#include "GmshMessage.h"

gmshRegion::gmshRegion(GModel *m, ::Volume *volume)
  : GRegion(m, volume->Num), v(volume)
{
  for(int i = 0; i < List_Nbr(v->Surfaces); i++){
    Surface *s;
    List_Read(v->Surfaces, i, &s);
    int ori;
    List_Read(v->SurfacesOrientations, i, &ori);
    GFace *f = m->getFaceByTag(abs(s->Num));
    if(f){
      l_faces.push_back(f);
      l_dirs.push_back(ori);
    }
    else
      Msg::Error("Unknown surface %d", s->Num);
  }
  for(int i = 0; i < List_Nbr(v->SurfacesByTag); i++){
    int is;
    List_Read(v->SurfacesByTag, i, &is);
    GFace *f = m->getFaceByTag(abs(is));
    if(f){
      l_faces.push_back(f);
      l_dirs.push_back(sign(is));
    }
    else
      Msg::Error("Unknown surface %d", is);
  }

  resetMeshAttributes();
}

void gmshRegion::resetMeshAttributes()
{
  meshAttributes.Method = v->Method;
  meshAttributes.extrude = v->Extrude;
  if(meshAttributes.Method == MESH_TRANSFINITE){
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(v->TrsfPoints); i++){
      Vertex *corn;
      List_Read(v->TrsfPoints, i, &corn);
      GVertex *gv = model()->getVertexByTag(corn->Num);
      if(gv)
        meshAttributes.corners.push_back(gv);
      else
        Msg::Error("Unknown vertex %d in transfinite attributes", corn->Num);
    }
  }
}

GEntity::GeomType gmshRegion::geomType() const
{
  switch (v->Typ){
  case MSH_VOLUME_DISCRETE : return DiscreteVolume;
  default : return Volume;
  }
}
