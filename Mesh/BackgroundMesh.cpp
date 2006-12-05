// $Id: BackgroundMesh.cpp,v 1.10 2006-12-05 14:22:05 remacle Exp $
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

extern Context_T CTX;

static OctreePost *BGM_OCTREE = NULL;
static double BGM_MAX = 0.;

// computes the characteristic length of the
// mesh at a vertex in order to have the geometry
// captured with accuracy. A parameter called
// CTX.mesh.min_circ_points tells the minimum
// number of points per radius of curvature 

static double max_surf_curvature ( const GVertex *gv )
{
  double max_curvature = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*> :: const_iterator ite = l_edges.begin() ; ite != l_edges.end() ; ++ite )
    {
      GEdge *_myGEdge = *ite;
      std::list<GFace *> faces = _myGEdge->faces();
      std::list<GFace *>::iterator it =  faces.begin();
      while (it != faces.end())
	{
	  SPoint2 par = gv->reparamOnFace((*it),1);
	  double cc = (*it)->curvature ( par );
	  max_curvature = std::max ( cc , max_curvature);  
	  ++it;
	}  
    }
  return max_curvature;
}

static double max_surf_curvature ( const GEdge *ge , double u)
{
  double max_curvature = 0;
  std::list<GFace *> faces = ge->faces();
  std::list<GFace *>::iterator it =  faces.begin();
  while (it != faces.end())
    {
      SPoint2 par = ge->reparamOnFace((*it),u,1);
      double cc = (*it)->curvature ( par );
      max_curvature = std::max ( cc , max_curvature);  
      ++it;
    }  
  return max_curvature;
}


// the mesh vertex is classified on a model vertex.
// we compute the maximum of the curvature
// of model faces surrounding this point  
// if it is classified on a model edge, 
// we do the same for all model faces surrounding it
// if it is on a model face, we compute the curvature
// at this location

const double MAX_LC = 1.e22;

double LC_MVertex_CURV ( GEntity *ge, double U, double V )
{
  double Crv=0;
  switch (ge->dim ())
    {
    case 0:
      Crv = max_surf_curvature ( (const GVertex *)ge);
      break;
    case 1:
      {
	GEdge *ged = (GEdge *)ge;
	//Crv = ged->curvature(  U );
	Crv = max_surf_curvature ( (const GEdge *)ge, U);
      }
      break;
    case 2:
      {
	GFace *gf = (GFace *)ge;
	Crv = gf->curvature( SPoint2( U, V) );
      }
      break;
    }
  
  if (Crv > 0) return 2*M_PI/Crv/CTX.mesh.min_circ_points;
  else return MAX_LC;
}


// compute the mesh size at a given
// vertex due to prescribed sizes at mesh vertices
double LC_MVertex_BGM ( GEntity *ge, double X, double Y, double Z )
{
//   if (X > CTX.min[0] + 0.5 * (CTX.max[0] -CTX.min[0]))
//     return 0.3*ge->model()->getMeshSize();
//   else
//     return 1.e22;
  if (BGMExists())
    {
      return BGMXYZ(X,Y,Z);
    }
  else
    return 1.e22;
}

// compute the mesh size at a given
// vertex due to prescribed sizes at mesh vertices
double LC_MVertex_PNTS ( GEntity *ge, double U, double V )
{
  double a;
  switch (ge->dim ())
    {
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
	return (1-a) * v1->prescribedMeshSizeAtVertex() + (a) * v2->prescribedMeshSizeAtVertex() ;
      }
    default:
      return 1.e22;
    }
}



double BGM_MeshSize ( GEntity *ge, double U, double V , double X, double Y, double Z)
{
  // FIXME
  // This should be controlled by the interface

  if(CTX.mesh.bgmesh_type == ONFILE && !CTX.mesh.constrained_bgmesh){
    // unconstrained background mesh
    return CTX.mesh.lc_factor * BGMXYZ(X,Y,Z) ;
  }

  double l2 = 1.e22;
  double l3 = ge->model()->getMeshSize();
  double l4 = LC_MVertex_BGM ( ge, X, Y , Z );
  if (ge->dim() < 2) l2 = LC_MVertex_PNTS ( ge, U, V );
  double l = std::min(std::min(l2,l4),l3);

  l *= CTX.mesh.lc_factor ;
  double l1 = 1.e22;

  if(CTX.mesh.lc_from_curvature && ge->dim() < 3)
    l1 = std::max(l3/100,LC_MVertex_CURV ( ge, U, V ));

  return std::min(l,l1) ;
}

int BGMWithView(Post_View * ErrView)
{
  Msg(INFO, "Applying '%s' as background mesh", ErrView->Name);
  if(BGM_OCTREE) delete BGM_OCTREE;
  BGM_OCTREE = new OctreePost(ErrView);
  BGM_MAX = ErrView->Max;
  CTX.mesh.bgmesh_type = ONFILE;
  return 1 ;
}

int BGMExists()
{
  return BGM_OCTREE != 0;
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
  if(l <= 0) return MAX_LC;

  return l;
}

