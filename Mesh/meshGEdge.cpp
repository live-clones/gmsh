// $Id: meshGEdge.cpp,v 1.34 2007-04-21 22:26:51 geuzaine Exp $
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
#include "meshGEdge.h"
#include "GEdge.h"
#include "GFace.h"
#include "MRep.h"
#include "BackgroundMesh.h"
#include "Message.h"

double F_Lc(GEdge *ge, double t)
{
  GPoint p = ge->point(t);
  double lc_here;

  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();

  if(t == t_begin)
    lc_here = BGM_MeshSize(ge->getBeginVertex(), t, 0, p.x(), p.y(), p.z());
  else if(t == t_end)
    lc_here = BGM_MeshSize(ge->getEndVertex(), t, 0, p.x(), p.y(), p.z());
  else
    lc_here = BGM_MeshSize(ge, t, 0, p.x(), p.y(), p.z());

  SVector3 der = ge->firstDer(t);
  const double d = norm(der);
  return d / lc_here;
}

double F_Transfinite(GEdge *ge, double t)
{
  double val, r;

  SVector3 der = ge->firstDer(t) ;
  double d = norm(der);

  double coef = ge->meshAttributes.coeffTransfinite;
  int type = ge->meshAttributes.typeTransfinite;
  int nbpt = ge->meshAttributes.nbPointsTransfinite;

  if(coef <= 0.0 || coef == 1.0) {
    // coef < 0 should never happen
    val = d * coef / ge->length();
  }
  else {
    switch (abs(type)) {

    case 1: // Geometric progression ar^i; Sum of n terms = length = a (r^n-1)/(r-1)
      {
	if(sign(type) >= 0)
	  r = coef;
	else
	  r = 1. / coef;
	double a = ge->length() * (r - 1.) / (pow(r, nbpt - 1.) - 1.);
	int i = (int)(log(t * ge->length() / a * (r - 1.) + 1.) / log(r));
	val = d / (a * pow(r, (double)i));
      }
      break;
	
    case 2: // Bump
      {
	double a;
	if(coef > 1.0) {
	  a = -4. * sqrt(coef - 1.) *
	    atan2(1., sqrt(coef - 1.)) /
	    ((double)nbpt *  ge->length());
	}
	else {
	  a = 2. * sqrt(1. - coef) *
	    log(fabs((1. + 1. / sqrt(1. - coef))
		     / (1. - 1. / sqrt(1. - coef))))
	    / ((double)nbpt * ge->length());
	}
	double b = -a * ge->length() * ge->length() / (4. * (coef - 1.));
	val = d / (-a * DSQR(t * ge->length() - (ge->length()) * 0.5) + b);
      }
      break;
      
    default:
      Msg(WARNING, "Unknown case in Transfinite Line mesh");
      val = 1.;
      break;
    }
  }
  return val;
}

double F_One(GEdge *ge, double t)
{
  SVector3 der = ge->firstDer(t) ;
  return norm(der);
}

typedef struct{
  int Num;
  double t, lc, p;
}IntPoint;

double trapezoidal(IntPoint * P1, IntPoint * P2)
{
  return (0.5 * (P1->lc + P2->lc) * (P2->t - P1->t));
}

void RecursiveIntegration(GEdge *ge, IntPoint * from, IntPoint * to,
                          double (*f) (GEdge *e, double X), List_T * pPoints,
                          double Prec, int *depth)
{
  IntPoint P, p1;

  (*depth)++;

  P.t = 0.5 * (from->t + to->t);
  P.lc = f(ge, P.t);

  double val1 = trapezoidal(from, to);
  double val2 = trapezoidal(from, &P);
  double val3 = trapezoidal(&P, to);
  double err = fabs(val1 - val2 - val3);

  if(((err < Prec) && (*depth > 1)) || (*depth > 25)) {
    List_Read(pPoints, List_Nbr(pPoints) - 1, &p1);
    P.p = p1.p + val2;
    List_Add(pPoints, &P);

    List_Read(pPoints, List_Nbr(pPoints) - 1, &p1);
    to->p = p1.p + val3;
    List_Add(pPoints, to);
  }
  else {
    RecursiveIntegration(ge, from, &P, f, pPoints, Prec, depth);
    RecursiveIntegration(ge, &P, to, f, pPoints, Prec, depth);
  }

  (*depth)--;
}

double Integration(GEdge *ge, double t1, double t2, 
		   double (*f) (GEdge *e, double X),
                   List_T * pPoints, double Prec)
{
  IntPoint from, to;

  int depth = 0;

  from.t = t1;
  from.lc = f(ge, from.t);
  from.p = 0.0;
  List_Add(pPoints, &from);

  to.t = t2;
  to.lc = f(ge, to.t);
  RecursiveIntegration(ge, &from, &to, f, pPoints, Prec, &depth);

  List_Read(pPoints, List_Nbr(pPoints) - 1, &to);
  return to.p;
}

void deMeshGEdge::operator() (GEdge *ge) 
{
  if(ge->geomType() == GEntity::DiscreteCurve) return;

  for (unsigned int i = 0; i < ge->mesh_vertices.size(); i++) 
    delete ge->mesh_vertices[i];
  ge->mesh_vertices.clear();
  for (unsigned int i = 0; i < ge->lines.size(); i++) 
    delete ge->lines[i];
  ge->lines.clear();
  if(ge->meshRep) ge->meshRep->destroy();
}

double GPointDist(GPoint &p1,GPoint &p2){
  double dx=p1.x()-p2.x();
  double dy=p1.y()-p2.y();
  double dz=p1.z()-p2.z();
  return sqrt(dx*dx+dy*dy+dz*dz);
}

void meshGEdge::operator() (GEdge *ge) 
{  
  if(ge->geomType() == GEntity::DiscreteCurve) return;
  if(ge->geomType() == GEntity::BoundaryLayerCurve) return;

  // Send a messsage to the GMSH environment
  Msg(INFO, "Meshing curve %d", ge->tag());

  deMeshGEdge dem;
  dem(ge);

  if(MeshExtrudedCurve(ge)) return;

  // Create a list of integration points
  List_T *Points = List_Create(10, 10, sizeof(IntPoint));

  // compute bounds
  Range<double> bounds = ge->parBounds(0);
  double t_begin = bounds.low();
  double t_end = bounds.high();
  
  // first compute the length of the curve by integrating one
  double length = Integration(ge, t_begin, t_end, F_One, Points, 1.e-8);
  ge->setLength(length);

  List_Reset(Points);
    
  // Integrate detJ/lc du 
  double a;
  int N;
  if(ge->meshAttributes.Method == TRANSFINI){
    a = Integration(ge, t_begin, t_end, F_Transfinite, Points, 1.e-8);
    N = ge->meshAttributes.nbPointsTransfinite;
  }
  else{
    a = Integration(ge, t_begin, t_end, F_Lc, Points, 1.e-7);
    N = std::max(ge->minimumMeshSegments() + 1, (int)(a + 1.));
  }
  const double b = a / (double)(N - 1);

  MVertex *v0 = ge->getBeginVertex()->mesh_vertices[0];
  MVertex *v1 = ge->getEndVertex()->mesh_vertices[0];

  // if the curve is periodic and if the begin vertex is identical to the end vertex
  // and if this vertex has only one model curve adjacent to it, then the vertex is
  // not connecting any other curve. So, the mesh vertex and its associated  geom vertex
  // are not necessary at the same location
  GPoint beg_p,end_p;
  if(ge->getBeginVertex() == ge->getEndVertex() && 
     ge->getBeginVertex()->edges().size() == 1){
    end_p = beg_p = ge->point(t_begin);
  }
  else{
    beg_p = GPoint(v0->x(), v0->y(), v0->z());
    end_p = GPoint(v1->x(), v1->y(), v1->z());
  }

  int count = 1, NUMP = 1, NUMP2 = 1;
  IntPoint P1, P2;

  // do not consider the first and the last vertex (those are not
  // classified on this mesh edge)
  if(N > 1){
    ge->mesh_vertices.resize(N - 2);
    GPoint last_p = beg_p;
    while(NUMP < N - 1) {
      List_Read(Points, count - 1, &P1);
      List_Read(Points, count, &P2);
      const double d = (double)NUMP *b;
      if((fabs(P2.p) >= fabs(d)) && (fabs(P1.p) < fabs(d))) {
        double dt = P2.t - P1.t;
        double dp = P2.p - P1.p;
        double t = P1.t + dt / dp * (d - P1.p);
        GPoint V = ge->point(t);
	if(ge->meshAttributes.Method == TRANSFINI){
	  ge->mesh_vertices[NUMP2 - 1] = new MEdgeVertex(V.x(), V.y(), V.z(), ge, t);
	  NUMP2++;
	}
	else{
	  double lc = BGM_MeshSize(ge, t, 0, V.x(), V.y(), V.z());
	  if(GPointDist(V, last_p) > 0.7 * lc && 
	     !(NUMP == N - 2 && GPointDist(V, end_p) < 0.7 * lc)){
	    last_p = V;
	    ge->mesh_vertices[NUMP2 - 1] = new MEdgeVertex(V.x(), V.y(), V.z(), ge, t);
	    NUMP2++;
	  }
	}
        NUMP++;
      }
      else {
        count++;
      }
    }
    ge->mesh_vertices.resize(NUMP2 - 1);
  }
  List_Delete(Points);

  for(unsigned int i = 0; i < ge->mesh_vertices.size() + 1; i++){
    MVertex *v0 = (i == 0) ? 
      ge->getBeginVertex()->mesh_vertices[0] : ge->mesh_vertices[i - 1];
    MVertex *v1 = (i == ge->mesh_vertices.size()) ? 
      ge->getEndVertex()->mesh_vertices[0] : ge->mesh_vertices[i];
    ge->lines.push_back(new MLine(v0, v1));
  }
  v0->x() = beg_p.x();
  v0->y() = beg_p.y();
  v0->z() = beg_p.z();

}
