// $Id: gmshRegion.cpp,v 1.14 2007-02-12 08:36:11 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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
#include "gmshFace.h"
#include "gmshRegion.h"
#include "Geo.h"
#include "Message.h"

extern Mesh *THEM;

gmshRegion::gmshRegion(GModel *m, ::Volume * volume)
  : GRegion(m, volume->Num), v(volume)
{
  for(int i = 0; i < List_Nbr(v->Surfaces); i++){
    Surface *s;
    List_Read(v->Surfaces, i, &s);
    int ori;
    List_Read(v->SurfacesOrientations, i, &ori);
    GFace *f = m->faceByTag(abs(s->Num));
    if(f){
      l_faces.push_back(f);
      l_dirs.push_back(ori);
    }
    else
      Msg(GERROR, "Unknown surface %d", s->Num);
  }
  for(int i = 0; i < List_Nbr(v->SurfacesByTag); i++){
    int is;
    List_Read(v->SurfacesByTag, i, &is);
    GFace *f = m->faceByTag(abs(is));
    if(f){
      l_faces.push_back(f);
      l_dirs.push_back(sign(is));
    }
    else
      Msg(GERROR, "Unknown surface %d", is);
  }

  resetMeshAttributes();
}

gmshRegion::gmshRegion(GModel *m, int num)
  : GRegion(m, num)
{
  v = Create_Volume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(THEM->Volumes, &v);
}

void gmshRegion::resetMeshAttributes()
{
  meshAttributes.Method = v->Method;
  meshAttributes.extrude = v->Extrude;
  if(meshAttributes.Method == TRANSFINI){
    meshAttributes.corners.clear();
    for(int i = 0; i < List_Nbr(v->TrsfPoints); i++){
      Vertex *corn;
      List_Read(v->TrsfPoints, i, &corn);
      GVertex *gv = model()->vertexByTag(corn->Num);
      if(gv)
	meshAttributes.corners.push_back(gv);
      else
	Msg(GERROR, "Unknown vertex %d in transfinite attributes", corn->Num);
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
