// $Id: BackgroundMesh.cpp,v 1.37 2008-02-21 09:45:15 remacle Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include "Message.h"
#include "BackgroundMesh.h"
#include "Numeric.h"
#include "Context.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GModel.h"
#include "Field.h"

extern Context_T CTX;
MinField lc_field;

#define MAX_LC 1.e22

bool BGMExists() 
{
  return !lc_field.empty();
}

void BGMAddField(Field *field)
{
  lc_field.push_front(field);
}

void BGMReset()
{
  lc_field.clear();
}

// computes the characteristic length of the mesh at a vertex in order
// to have the geometry captured with accuracy. A parameter called
// CTX.mesh.min_circ_points tells the minimum number of points per
// radius of curvature

static double max_edge_curvature(const GVertex *gv)
{
  double max_curvature = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);      
    double cc;
    if (gv == _myGEdge->getBeginVertex())cc = _myGEdge->curvature (range.low());
    else cc = _myGEdge->curvature (range.high());
    max_curvature = std::max(max_curvature,cc);
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

static double max_surf_curvature(const GVertex *gv)
{
  double max_curvature = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> bounds = _myGEdge->parBounds(0);
    if (gv == _myGEdge->getBeginVertex())
      max_curvature = std::max(max_curvature, max_surf_curvature(_myGEdge,bounds.low()));
    else
      max_curvature = std::max(max_curvature, max_surf_curvature(_myGEdge,bounds.high()));
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
    //Crv = max_edge_curvature ( (const GVertex *)ge);
    //  Crv = std::max(max_surf_curvature ( (const GVertex *)ge),Crv);
    Crv = max_surf_curvature ( (const GVertex *)ge);
    //    printf("point %d coucou %g\n",ge->tag(),Crv);
    break;
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      //      Crv = ged->curvature(U);
      //      printf("coucou %12.5E %d\n",Crv,CTX.mesh.min_circ_points);
      //      Crv = std::max(Crv,max_surf_curvature(ged, U));
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
 
  double lc = Crv > 0 ? 2*M_PI / Crv / CTX.mesh.min_circ_points : MAX_LC;

  //  double lc_min = CTX.lc /300;


  return lc;

}


// compute the mesh size at a given vertex due to prescribed sizes at
// mesh vertices
double LC_MVertex_PNTS(GEntity *ge, double U, double V)
{
  switch(ge->dim()){
  case 0:
    {
      GVertex *gv = (GVertex *)ge;
      double lc = gv->prescribedMeshSizeAtVertex();
      if(lc >= MAX_LC) return CTX.lc / 10.;
      return lc;
    }
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      GVertex *v1 = ged->getBeginVertex();
      GVertex *v2 = ged->getEndVertex();
      Range<double> range = ged->parBounds(0);      
      double a = (U - range.low())/(range.high() - range.low()); 
      double lc = (1-a) * v1->prescribedMeshSizeAtVertex() +
	(a) * v2->prescribedMeshSizeAtVertex() ;
      if(lc >= MAX_LC) return CTX.lc / 10.;
      return lc;
    }
  default:
    return MAX_LC;
  }
}

// This is the only function that is used by the meshers
double BGM_MeshSize(GEntity *ge, double U, double V, double X, double Y, double Z)
{
  double l1 = MAX_LC;
  double l2 = MAX_LC;
  double l3 = CTX.lc;
  double l4 = lc_field.empty() ? MAX_LC : lc_field(X, Y, Z);


  double lc;
  if(l4 < MAX_LC && !CTX.mesh.constrained_bgmesh){
    // use the fields unconstrained by other characteristic lengths
    lc = l4 * CTX.mesh.lc_factor;
  }
  else{
    if(ge->dim() < 2) 
      l2 = LC_MVertex_PNTS(ge, U, V);
    lc = std::min(std::min(std::min(l1, l2), l3), l4) * CTX.mesh.lc_factor;
  }

  if(CTX.mesh.lc_from_curvature && ge->dim() <= 2 )
    lc = std::min (lc,LC_MVertex_CURV(ge, U, V));

  lc = std::max(lc,CTX.mesh.lc_min*CTX.mesh.lc_factor);
  lc = std::min(lc,CTX.mesh.lc_max*CTX.mesh.lc_factor);

  if(lc <= 0.){
    Msg(GERROR, "Incorrect char. length lc = %g: using default instead", lc);
    return l3 * CTX.mesh.lc_factor;
  }
  
  return lc;
}

// we extend the 1d mesh in surfaces if no background mesh exists
// in this case, it is the only way to have something smooth
// we do it also if CTX.mesh.constrained_bgmesh is true;
bool Extend1dMeshIn2dSurfaces()
{
  if(lc_field.empty()) return true;
  if(CTX.mesh.constrained_bgmesh) return true;
  return false;
}

bool Extend2dMeshIn3dVolumes()
{
  return Extend1dMeshIn2dSurfaces();
}
