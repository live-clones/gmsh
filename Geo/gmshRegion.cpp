// $Id: gmshRegion.cpp,v 1.11 2006-12-02 19:29:36 geuzaine Exp $
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

extern Mesh *THEM;

gmshRegion::gmshRegion(GModel *m, ::Volume * volume)
  : GRegion(m, volume->Num), v(volume)
{
  Surface *s;
  int ori;
  for(int i = 0; i < List_Nbr(v->Surfaces); i++){
    List_Read(v->Surfaces, i, &s);
    List_Read(v->SurfacesOrientations, i, &ori);
    GFace *f = m->faceByTag(abs(s->Num));
    if(!f) throw;
    l_faces.push_back(f);
    l_dirs.push_back(ori);
  }

  meshAttributes.Method = volume->Method;
  meshAttributes.extrude = volume->Extrude;
  if(meshAttributes.Method == TRANSFINI){
    for(int i = 0; i < List_Nbr(volume->TrsfPoints); i++){
      Vertex *corn;
      List_Read(volume->TrsfPoints, i, &corn);
      GVertex *gv = m->vertexByTag(corn->Num);
      if(!gv) throw;
      meshAttributes.corners.push_back(gv);
    }
  }
}

gmshRegion::gmshRegion(GModel *m, int num)
  : GRegion(m, num)
{
  v = Create_Volume(num, MSH_VOLUME_DISCRETE);
  Tree_Add(THEM->Volumes, &v);
}

GEntity::GeomType gmshRegion::geomType() const
{
  switch (v->Typ){
  case MSH_VOLUME_DISCRETE : return DiscreteVolume;
  default : return Volume;
  }
}
