// $Id: BackgroundMesh.cpp,v 1.16 2007-02-02 17:16:46 remacle Exp $
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

#include "Gmsh.h"
#include "Views.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "Context.h"
#include "OctreePost.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "Attractors.h"

extern Context_T CTX;

static OctreePost *BGM_OCTREE = NULL;

const double MAX_LC = 1.e22;

int BGMWithView(Post_View * ErrView)
{
  Msg(INFO, "Applying '%s' as background mesh", ErrView->Name);
  if(BGM_OCTREE) delete BGM_OCTREE;
  BGM_OCTREE = new OctreePost(ErrView);
  CTX.mesh.bgmesh_view_num = ErrView->Num; // view numbers are unique
  return 1 ;
}

int BGMExists()
{
  if(!BGM_OCTREE || CTX.mesh.bgmesh_view_num < 0) return 0;

  for(int i = 0; i < List_Nbr(CTX.post.list); i++){
    Post_View *v = *(Post_View**)List_Pointer_Fast(CTX.post.list, i);
    if(v->Num == CTX.mesh.bgmesh_view_num) return 1;
  }
  CTX.mesh.bgmesh_view_num = -1;
  return 0;
}

// computes the characteristic length of the mesh at a vertex in order
// to have the geometry captured with accuracy. A parameter called
// CTX.mesh.min_circ_points tells the minimum number of points per
// radius of curvature

static double max_surf_curvature(const GVertex *gv)
{
  double max_curvature = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    std::list<GFace *> faces = _myGEdge->faces();
    std::list<GFace *>::iterator it = faces.begin();
    while (it != faces.end()){
      SPoint2 par = gv->reparamOnFace((*it),1);
      double cc = (*it)->curvature ( par );
      max_curvature = std::max ( cc , max_curvature);  
      ++it;
    }  
  }
  return max_curvature;
}

static double max_surf_curvature(const GEdge *ge, double u)
{
  double max_curvature = 0;
  std::list<GFace *> faces = ge->faces();
  std::list<GFace *>::iterator it = faces.begin();
  while(it != faces.end()){
    SPoint2 par = ge->reparamOnFace((*it),u,1);
    double cc = (*it)->curvature(par);
    max_curvature = std::max(cc, max_curvature);
    ++it;
  }  
  return max_curvature;
}

// the mesh vertex is classified on a model vertex.  we compute the
// maximum of the curvature of model faces surrounding this point if
// it is classified on a model edge, we do the same for all model
// faces surrounding it if it is on a model face, we compute the
// curvature at this location

double LC_MVertex_CURV(GEntity *ge, double U, double V)
{
  double Crv = 0;
  switch(ge->dim()){
  case 0:
    Crv = max_surf_curvature ( (const GVertex *)ge);
    break;
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      //Crv = ged->curvature(U);
      Crv = max_surf_curvature(ged, U);
    }
    break;
  case 2:
    {
      GFace *gf = (GFace *)ge;
      Crv = gf->curvature(SPoint2(U, V));
    }
    break;
  }
  
  if(Crv > 0) return 2*M_PI / Crv / CTX.mesh.min_circ_points;
  else return MAX_LC;
}

// compute the mesh size at a given point in space using a background
// mesh on file
double LC_MVertex_BGM(GEntity *ge, double X, double Y, double Z)
{
  if(!BGMExists()) return MAX_LC;

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
  if(l <= 0) return MAX_LC;
  return l;
}

// compute the mesh size at a given vertex due to prescribed sizes at
// mesh vertices
double LC_MVertex_PNTS(GEntity *ge, double U, double V)
{
  double a;
  switch(ge->dim()){
  case 0:
    {
      GVertex *gv = (GVertex *)ge;
      return gv->prescribedMeshSizeAtVertex();
    }
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      GVertex *v1 = ged->getBeginVertex();
      GVertex *v2 = ged->getEndVertex();
      Range<double> range = ged->parBounds(0);      
      a = (U - range.low())/(range.high() - range.low()); 
      return (1-a) * v1->prescribedMeshSizeAtVertex() +
	(a) * v2->prescribedMeshSizeAtVertex() ;
    }
  default:
    return MAX_LC;
  }
}

// This is the only function that is used by the meshers
double BGM_MeshSize(GEntity *ge, double U, double V, double X, double Y, double Z)
{
  double l2 = MAX_LC;
  double l3 = CTX.lc / 10.;
  double l4 = LC_MVertex_BGM(ge, X, Y, Z);
  double l5 = Attractor::lc (X,Y,Z);

  if(l4 < MAX_LC && !CTX.mesh.constrained_bgmesh)
    return l4 * CTX.mesh.lc_factor;

  if(ge->dim() < 2) l2 = LC_MVertex_PNTS(ge, U, V);

  double l = std::min(std::min(std::min(l2, l4), l3), l5);

  l *= CTX.mesh.lc_factor ;

  double l1 = MAX_LC;
  if(CTX.mesh.lc_from_curvature && ge->dim() < 3)
    l1 = std::max(l3/100, LC_MVertex_CURV(ge, U, V));

  return std::min(l, l1) ;
}
