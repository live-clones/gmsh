// $Id: BackgroundMesh.cpp,v 1.52 2008-04-18 16:40:29 geuzaine Exp $
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

#define MAX_LC 1.e22

// computes the characteristic length of the mesh at a vertex in order
// to have the geometry captured with accuracy. A parameter called
// CTX.mesh.min_circ_points tells the minimum number of points per
// radius of curvature

static double max_edge_curvature(const GVertex *gv)
{
  double val = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> range = _myGEdge->parBounds(0);      
    double cc;
    if (gv == _myGEdge->getBeginVertex()) cc = _myGEdge->curvature(range.low());
    else cc = _myGEdge->curvature(range.high());
    val = std::max(val, cc);
  }
  return val;
}

static double max_surf_curvature(const GEdge *ge, double u)
{
  double val = 0;
  std::list<GFace *> faces = ge->faces();
  std::list<GFace *>::iterator it = faces.begin();
  while(it != faces.end()){
    SPoint2 par = ge->reparamOnFace((*it), u, 1);
    double cc = (*it)->curvature(par);
    val = std::max(cc, val);
    ++it;
  }  
  return val;
}

static double max_surf_curvature(const GVertex *gv)
{
  double val = 0;
  std::list<GEdge*> l_edges = gv->edges();
  for (std::list<GEdge*>::const_iterator ite = l_edges.begin(); 
       ite != l_edges.end(); ++ite){
    GEdge *_myGEdge = *ite;
    Range<double> bounds = _myGEdge->parBounds(0);
    if (gv == _myGEdge->getBeginVertex())
      val = std::max(val, max_surf_curvature(_myGEdge, bounds.low()));
    else
      val = std::max(val, max_surf_curvature(_myGEdge, bounds.high()));
  }
  return val;
}

// the mesh vertex is classified on a model vertex.  we compute the
// maximum of the curvature of model faces surrounding this point if
// it is classified on a model edge, we do the same for all model
// faces surrounding it if it is on a model face, we compute the
// curvature at this location

static double LC_MVertex_CURV(GEntity *ge, double U, double V)
{
  double Crv = 0;
  switch(ge->dim()){
  case 0:        
    // Crv = max_edge_curvature((const GVertex *)ge);
    // Crv = std::max(max_surf_curvature((const GVertex *)ge), Crv);
    Crv = max_surf_curvature((const GVertex *)ge);
    break;
  case 1:
    {
      GEdge *ged = (GEdge *)ge;
      Crv = ged->curvature(U);
      Crv = std::max(Crv, max_surf_curvature(ged, U));
      //Crv = max_surf_curvature(ged, U);      
    }
    break;
  case 2:
    {
      GFace *gf = (GFace *)ge;
      Crv = gf->curvature(SPoint2(U, V));
    }
    break;
  }
 
  double lc = Crv > 0 ? 2 * M_PI / Crv / CTX.mesh.min_circ_points : MAX_LC;
  return lc;
}

// compute the mesh size at a given vertex due to prescribed sizes at
// mesh vertices
static double LC_MVertex_PNTS(GEntity *ge, double U, double V)
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
      double a = (U - range.low()) / (range.high() - range.low()); 
      double lc = (1 - a) * v1->prescribedMeshSizeAtVertex() +
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
  // default lc (mesh size == size of the domain)
  double l1 = CTX.lc;

  // lc from points
  double l2 = MAX_LC;
  if(CTX.mesh.lc_from_points && ge->dim() < 2) 
    l2 = LC_MVertex_PNTS(ge, U, V);

  // lc from curvature
  double l3 = MAX_LC;
  if(CTX.mesh.lc_from_curvature && ge->dim() < 3)
    l3 = LC_MVertex_CURV(ge, U, V);

  // lc from fields
  double l4 = MAX_LC;
  FieldManager *fields = GModel::current()->getFields();
  if(fields->background_field > 0){
    Field *f = fields->get(fields->background_field);
    if(f) l4 = (*f)(X, Y, Z);
  }

  // take the minimum, then contrain by lc_min and lc_max
  double lc = std::min(std::min(std::min(l1, l2), l3), l4);
  lc = std::max(lc, CTX.mesh.lc_min);
  lc = std::min(lc, CTX.mesh.lc_max);

  if(lc <= 0.){
    Msg(GERROR, "Wrong characteristic length lc = %g", lc);
    lc = l1;
  }

  return lc * CTX.mesh.lc_factor;
}

bool Extend1dMeshIn2dSurfaces()
{
  // don't extend 1d mesh in surfaces if there is a background field
  if(GModel::current()->getFields()->background_field != -1) return false;

  return CTX.mesh.lc_extend_from_boundary ? true : false;
}

bool Extend2dMeshIn3dVolumes()
{
  return Extend1dMeshIn2dSurfaces();
}
