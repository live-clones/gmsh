// $Id: meshGEdge.cpp,v 1.14 2006-08-26 15:13:22 remacle Exp $
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

#include "meshGEdge.h"
#include "GEdge.h"
#include "GFace.h"
#include "Gmsh.h"
#include "Utils.h"
#include "Mesh.h"
#include "Context.h"
#include "Message.h"

extern Context_T CTX;

static GEdge * _myGEdge;
static double  _myGEdgeLength, t_begin, t_end, lc_begin, lc_end;
static Range<double> _myGEdgeBounds;

double F_LC_ANALY (double xx, double yy, double zz)
{
  //  return 0.005 + 0.05*fabs (sin(5*xx) + sin(15*yy) + sin(15*zz));
  //  return 0.02;
  //  return 0.002 + 0.04*fabs (sin(6*xx) + sin(6*yy) + sin(6*zz));
  return 0.003 + 0.05*fabs (sin(8*xx) + sin(8*yy) + sin(8*zz));
  return 0.02 + 0.1*fabs (sin(3*xx) + sin(3*yy) + sin(3*zz));
  return 0.01 + 0.1*fabs(sin((xx*xx+(zz-0.7)*(zz-0.7)-.25))) ; 
  return 0.05 + .1*fabs(xx*yy) ;
}

double max_surf_curvature ( GPoint & gp )
{
  std::list<GFace *> faces = _myGEdge->faces();
  std::list<GFace *>::iterator it =  faces.begin();
  double curv = 0;
  while (it != faces.end())
    {
      SPoint2 par = (*it)->parFromPoint(SPoint3 (gp.x(),gp.y(),gp.z()));
      curv = std::max(curv, (*it)->curvature ( par ) );					
      ++it;
    }  
  return curv;
}

double F_Lc_bis(double t)
{
  //  const double nb_points_per_radius_of_curv = 2;
  GPoint point = _myGEdge -> point(t) ;      
  const double fact = (t-t_begin)/(t_end-t_begin);
  double lc_here = lc_begin + fact * (lc_end-lc_begin);
  SVector3 der  = _myGEdge -> firstDer(t) ;
  const double d      = norm(der);

  //  double curv = max_surf_curvature ( point );
  //  if (curv != 0)
  //    lc_here = std::min( 1./(curv * nb_points_per_radius_of_curv),lc_here);

  if(CTX.mesh.bgmesh_type == ONFILE) {
    const double Lc = BGMXYZ(point.x(), point.y(), point.z());
    if(CTX.mesh.constrained_bgmesh)
      return std::max(d / Lc, d / lc_here);
    else
      return d / Lc;
  }
  else
    return d/lc_here;
}

double F_Transfini_bis(double t)
{
  double val, r;

  SVector3 der = _myGEdge -> firstDer(t) ;
  double d = norm(der);

  double coef = _myGEdge->meshAttributes.coeffTransfinite;
  int    type = _myGEdge->meshAttributes.typeTransfinite;
  int    nbpt = _myGEdge->meshAttributes.nbPointsTransfinite;

  if(coef <= 0.0 || coef == 1.0) {
    // coef < 0 should never happen
    val = d * coef / _myGEdgeLength;
  }
  else {
    switch (abs(type)) {

    case 1: // Geometric progression ar^i; Sum of n terms = THEC->l = a (r^n-1)/(r-1)
      {
	if(sign(type) >= 0)
	  r = coef;
	else
	  r = 1. / coef;
	double a = _myGEdgeLength * (r - 1.) / (pow(r, nbpt - 1.) - 1.);
	int i = (int)(log(t * _myGEdgeLength / a * (r - 1.) + 1.) / log(r));
	val = d / (a * pow(r, (double)i));
      }
      break;
	
    case 2: // Bump
      {
	double a;
	if(coef > 1.0) {
	  a = -4. * sqrt(coef - 1.) *
	    atan2(1., sqrt(coef - 1.)) /
	    ((double)nbpt *  _myGEdgeLength);
	}
	else {
	  a = 2. * sqrt(1. - coef) *
	    log(fabs((1. + 1. / sqrt(1. - coef))
		     / (1. - 1. / sqrt(1. - coef))))
	    / ((double)nbpt * _myGEdgeLength);
	}
	double b = -a * _myGEdgeLength * _myGEdgeLength / (4. * (coef - 1.));
	val = d / (-a * DSQR(t * _myGEdgeLength - (_myGEdgeLength) * 0.5) + b);
      }
      break;
      
    default:
      Msg(WARNING, "Unknown case in Transfinite Line mesh");
      val = 1.;
    }
  }
  return val;
}

double F_One_bis(double t)
{
  SVector3 der = _myGEdge -> firstDer(t) ;
  return norm(der);
}

void deMeshGEdge :: operator() (GEdge *ge) 
{
  for (unsigned int i=0;i<ge->mesh_vertices.size();i++) delete ge->mesh_vertices[i];
  ge->mesh_vertices.clear();
  for (unsigned int i=0;i<ge->lines.size();i++) delete ge->lines[i];
  ge->lines.clear();
}

void meshGEdge :: operator() (GEdge *ge) 
{  
  if(ge->geomType() == GEntity::DiscreteCurve) return;

  // Send a messsage to the GMSH environment
  Msg(INFO, "Meshing curve %d", ge->tag());

  deMeshGEdge dem;
  dem(ge);

  // Create a list of integration points
  List_T *Points = List_Create(10, 10, sizeof(IntPoint));

  // For avoiding the global variable :
  // We have to change the Integration function in order
  // to pass an extra argument... 
  _myGEdge = ge;
    
  // first compute the length of the curve by integrating one
  _myGEdgeBounds = ge->parBounds(0) ;
  _myGEdgeLength = Integration(_myGEdgeBounds.low(), _myGEdgeBounds.high(), 
			       F_One_bis, Points, 1.e-4);
  List_Reset(Points);

  lc_begin  =  _myGEdge->getBeginVertex()->prescribedMeshSizeAtVertex();
  lc_end    =  _myGEdge->getEndVertex()->prescribedMeshSizeAtVertex();
    
  t_begin = _myGEdgeBounds.low();
  t_end   = _myGEdgeBounds.high();

  // Integrate detJ/lc du 
  double a;
  int N;
  if(ge->meshAttributes.Method == TRANSFINI){
    a = Integration(_myGEdgeBounds.low(), _myGEdgeBounds.high(), 
		    F_Transfini_bis, Points, 1.e-7);
    N = ge->meshAttributes.nbPointsTransfinite;
  }
  else{
    a = Integration(_myGEdgeBounds.low(), _myGEdgeBounds.high(), 
		    F_Lc_bis, Points, 1.e-4);
    N = std::max(ge->minimumMeshSegments() + 1, (int)(a + 1.));
  }
  const double b = a / (double)(N - 1);

  int count = 1, NUMP = 1;
  IntPoint P1, P2;

  // do not consider the first and the last vertex 
  // those are not classified on this mesh edge

  if(N > 2){
    ge->mesh_vertices.resize(N - 2);
    while(NUMP < N - 1) {
      List_Read(Points, count - 1, &P1);
      List_Read(Points, count, &P2);
      const double d = (double)NUMP *b;
      if((fabs(P2.p) >= fabs(d)) && (fabs(P1.p) < fabs(d))) {
	double dt = P2.t - P1.t;
	double dp = P2.p - P1.p;
	double t = P1.t + dt / dp * (d - P1.p);
	GPoint V = ge->point(t);
	ge->mesh_vertices[NUMP - 1] = new MEdgeVertex(V.x(), V.y(), V.z(), ge, t);
	NUMP++;
      }
      else {
	count++;
      }
    }
  }
  List_Delete(Points);

  for(unsigned int i = 0; i < ge->mesh_vertices.size() + 1; i++){
    MVertex *v0 = (i == 0) ? 
      ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices[i - 1];
    MVertex *v1 = (i == ge->mesh_vertices.size()) ? 
      ge->getEndVertex()->mesh_vertices[0] : ge->mesh_vertices[i];
    ge->lines.push_back(new MLine(v0, v1));
  }
}

