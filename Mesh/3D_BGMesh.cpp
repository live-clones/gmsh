// $Id: 3D_BGMesh.cpp,v 1.48 2006-08-05 13:31:28 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "Mesh.h"
#include "Views.h"
#include "Numeric.h"
#include "Context.h"
#include "OctreePost.h"

extern Mesh *THEM;
extern Context_T CTX;

static OctreePost *BGM_OCTREE = NULL;
static double BGM_MAX = 0.;

int BGMWithView(Post_View * ErrView)
{
  Msg(INFO, "Applying '%s' as background mesh", ErrView->Name);
  if(BGM_OCTREE) delete BGM_OCTREE;
  BGM_OCTREE = new OctreePost(ErrView);
  BGM_MAX = ErrView->Max;
  CTX.mesh.bgmesh_type = ONFILE;
  return 1 ;
}

double BGMXYZ(double X, double Y, double Z)
{
  if(!BGM_OCTREE){
    Msg(GERROR, "Missing background mesh");
    CTX.mesh.bgmesh_type = WITHPOINTS;
    return 1.;
  }

  double l = 0.;
  double fact[9] = {0.001, 0.0025, 0.005, 0.0075, 0.01, 0.025, 0.05, 0.075, 0.1};

  if(!BGM_OCTREE->searchScalar(X, Y, Z, &l, 0)){
    // try really hard to find an element around the point
    for(int i = 0; i < 9; i++){
      double eps = CTX.lc * fact[i];
      if(BGM_OCTREE->searchScalar(X + eps, Y, Z, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X - eps, Y, Z, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X, Y + eps, Z, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X, Y - eps, Z, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X, Y, Z + eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X, Y, Z - eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X + eps, Y - eps, Z - eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X + eps, Y + eps, Z - eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X - eps, Y - eps, Z - eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X - eps, Y + eps, Z - eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X + eps, Y - eps, Z + eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X + eps, Y + eps, Z + eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X - eps, Y - eps, Z + eps, &l, 0)) break;
      if(BGM_OCTREE->searchScalar(X - eps, Y + eps, Z + eps, &l, 0)) break;
    }
  }
  if(l <= 0) l = BGM_MAX;

  return CTX.mesh.lc_factor * l;
}

