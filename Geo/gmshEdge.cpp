// $Id: gmshEdge.cpp,v 1.26 2007-01-31 14:33:05 remacle Exp $
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

#include "GFace.h"
#include "gmshEdge.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Message.h"
#include "Context.h"

extern Context_T CTX;
extern Mesh *THEM;

gmshEdge::gmshEdge(GModel *model, Curve *edge, GVertex *v1, GVertex *v2)
  : GEdge(model, edge->Num, v1, v2), c(edge)
{
  resetMeshAttributes();
}

gmshEdge::gmshEdge(GModel *model, int num)
  : GEdge(model, num, 0, 0)
{
  c = Create_Curve(num, MSH_SEGM_DISCRETE, 0, NULL, NULL, -1, -1, 0., 1.);
  Tree_Add(THEM->Curves, &c);
  CreateReversedCurve(c);
}

void gmshEdge::resetMeshAttributes()
{
  meshAttributes.Method = c->Method;
  meshAttributes.nbPointsTransfinite = c->ipar[0];
  meshAttributes.coeffTransfinite = c->dpar[0];
  meshAttributes.typeTransfinite = c->ipar[1];
  meshAttributes.extrude = c->Extrude;
}

Range<double> gmshEdge::parBounds(int i) const
{ 
  return(Range<double>(c->ubeg, c->uend));
}

GPoint gmshEdge::point(double par) const
{
  Vertex a = InterpolateCurve(c, par, 0);
  return GPoint(a.Pos.X,a.Pos.Y,a.Pos.Z,this,par);
}

GPoint gmshEdge::closestPoint(const SPoint3 & qp)
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = qp.x();
  v.Pos.Y = qp.y();
  v.Pos.Z = qp.z();
  ProjectPointOnCurve(c, &v, &a, &der);
  return GPoint(a.Pos.X, a.Pos.Y, a.Pos.Z, this, a.u);
}

int gmshEdge::containsParam(double pt) const
{
  Range<double> rg = parBounds(0);
  return (pt >= rg.low() && pt <= rg.high());
}

SVector3 gmshEdge::firstDer(double par) const
{
  Vertex a = InterpolateCurve(c, par, 1);
  return SVector3(a.Pos.X, a.Pos.Y, a.Pos.Z);
}

double gmshEdge::parFromPoint(const SPoint3 &pt) const
{
  Vertex v;
  Vertex a;
  Vertex der;
  v.Pos.X = pt.x();
  v.Pos.Y = pt.y();
  v.Pos.Z = pt.z();
  ProjectPointOnCurve(c, &v, &a, &der);
  return a.u;
}

GEntity::GeomType gmshEdge::geomType() const
{
  switch (c->Typ){
  case MSH_SEGM_LINE : return Line;
  case MSH_SEGM_PARAMETRIC : return ParametricCurve;
  case MSH_SEGM_CIRC :  
  case MSH_SEGM_CIRC_INV : return Circle;
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV: return Ellipse;
  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER: 
  case MSH_SEGM_NURBS:
  case MSH_SEGM_SPLN: return Nurb; 
  case MSH_SEGM_DISCRETE: return DiscreteCurve; 
  default : return Unknown;
  }
}

int gmshEdge::minimumMeshSegments () const
{
  if(geomType() == Circle || geomType() == Ellipse)
    return (int)(fabs(c->Circle.t1 - c->Circle.t2) *
		 (double)CTX.mesh.min_circ_points / Pi) - 1;
  else
    return GEdge::minimumMeshSegments () ;
}

int gmshEdge::minimumDrawSegments () const
{
  int n = List_Nbr(c->Control_Points) - 1;
  if(!n) n = GEdge::minimumDrawSegments();

  if(geomType() == Line  && ! c->geometry)
    return n;
  else if(geomType() == Circle || geomType() == Ellipse)
    return CTX.geom.circle_points;
  else
    return 10 * n;
}

SPoint2 gmshEdge::reparamOnFace(GFace *face, double epar,int dir) const
{
  Surface *s = (Surface*) face->getNativePtr();

  if (s->geometry)
    {
      Vertex *v[3];
      List_Read(c->Control_Points, 0, &v[1]);
      List_Read(c->Control_Points, 1, &v[2]);
      SPoint2 p =  v[1] -> pntOnGeometry +  (v[2] -> pntOnGeometry - v[1] -> pntOnGeometry) * epar;
      return p;
    }

  if (s->Typ ==  MSH_SURF_REGL){
    Curve *C[4];
    for(int i = 0; i < 4; i++)
      List_Read(s->Generatrices, i, &C[i]);

    double U, V;
    if (C[0]->Num == c->Num) {
      U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[0]->Num == -c->Num) {
      U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[1]->Num == c->Num) {
      V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[1]->Num == -c->Num) {
      V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[2]->Num == c->Num) {
      U =  1 - (epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[2]->Num == -c->Num) {
      U =  1 - ( C[2]->uend -epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[3]->Num == c->Num) {
      V = 1-(epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg) ;
      U = 0;
    }
    else if (C[3]->Num == -c->Num) {
      V = 1-(C[3]->uend - epar - C[3]->ubeg) / (C[3]->uend - C[3]->ubeg) ;
      U = 0;
    }
    else{
      Msg(INFO, "Reparameterizing edge %d on face %d", c->Num, s->Num);
      return GEdge::reparamOnFace(face, epar, dir);
    }
    return SPoint2(U, V);
  }
  else if (s->Typ ==  MSH_SURF_TRIC){
    Curve *C[3];
    for(int i = 0; i < 3; i++)
      List_Read(s->Generatrices, i, &C[i]);

    double U, V;    
    if (C[0]->Num == c->Num) {
      U = (epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[0]->Num == -c->Num) {
      U = (C[0]->uend - epar - C[0]->ubeg) / (C[0]->uend - C[0]->ubeg) ;
      V = 0;
    }
    else if (C[1]->Num == c->Num) {
      V = (epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[1]->Num == -c->Num) {
      V = (C[1]->uend - epar - C[1]->ubeg) / (C[1]->uend - C[1]->ubeg) ;
      U = 1;
    }
    else if (C[2]->Num == c->Num) {
      U = 1-(epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else if (C[2]->Num == -c->Num) {
      U = 1-(C[2]->uend - epar - C[2]->ubeg) / (C[2]->uend - C[2]->ubeg) ;
      V = 1;
    }
    else{
      Msg(INFO, "Reparameterizing edge %d on face %d", c->Num, s->Num);
      return GEdge::reparamOnFace(face, epar, dir);
    }
    return SPoint2(U, V);
  }
  else
    return GEdge::reparamOnFace(face, epar, dir);
}
