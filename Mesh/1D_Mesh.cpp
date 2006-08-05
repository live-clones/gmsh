// $Id: 1D_Mesh.cpp,v 1.50 2006-08-05 13:31:28 geuzaine Exp $
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
#include "Numeric.h"
#include "Geo.h"
#include "Mesh.h"
#include "Utils.h"
#include "Context.h"
#include "Interpolation.h"

extern Mesh *THEM;
extern Context_T CTX;

static Curve *THEC = NULL;

// ipar[0] = nbpoints
// abs(ipar[1]) = method
// sign(ipar[1]) = orientation
// dpar[0] = parameter

double F_One(double t)
{
  Vertex der;
  double d;
  der = InterpolateCurve(THEC, t, 1);
  d =
    sqrt(der.Pos.X * der.Pos.X + der.Pos.Y * der.Pos.Y +
         der.Pos.Z * der.Pos.Z);
  return (d);
}


double F_Transfini(double t)
{
  Vertex der;
  double d, a, b, val, r;
  int i;

  der = InterpolateCurve(THEC, t, 1);
  d = sqrt(der.Pos.X * der.Pos.X + der.Pos.Y * der.Pos.Y +
           der.Pos.Z * der.Pos.Z);

  if(THEC->dpar[0] <= 0.0 || THEC->dpar[0] == 1.0) {
    // dpar[0] < 0 should never happen
    val = d * (double)THEC->ipar[0] / THEC->l;
  }
  else {
    switch (abs(THEC->ipar[1])) {

    case 1:    // Geometric progression ar^i; Sum of n terms = THEC->l = a (r^n-1)/(r-1)
      if(sign(THEC->ipar[1]) >= 0)
	r = THEC->dpar[0];
      else
	r = 1. / THEC->dpar[0];
      a = THEC->l * (r - 1.) / (pow(r, THEC->ipar[0] - 1.) - 1.);
      i = (int)(log(t * THEC->l / a * (r - 1.) + 1.) / log(r));
      val = d / (a * pow(r, (double)i));
      break;

    case 2:    // Bump
      if(THEC->dpar[0] > 1.0) {
        a = -4. * sqrt(THEC->dpar[0] - 1.) *
          atan2(1., sqrt(THEC->dpar[0] - 1.)) /
          ((double)THEC->ipar[0] * THEC->l);
      }
      else {
        a = 2. * sqrt(1. - THEC->dpar[0]) *
          log(fabs((1. + 1. / sqrt(1. - THEC->dpar[0]))
                   / (1. - 1. / sqrt(1. - THEC->dpar[0]))))
          / ((double)THEC->ipar[0] * THEC->l);
      }
      b = -a * THEC->l * THEC->l / (4. * (THEC->dpar[0] - 1.));
      val = d / (-a * DSQR(t * THEC->l - (THEC->l) * 0.5) + b);
      break;

    default:
      Msg(WARNING, "Unknown case in Transfinite Line mesh");
      val = 1.;
    }
  }

  return val;
}

double F_Lc(double t)
{
  Vertex der, point;
  double Lc, d;

  if(CTX.mesh.bgmesh_type == ONFILE) {
    der = InterpolateCurve(THEC, t, 1);
    point = InterpolateCurve(THEC, t, 0);
    Lc = BGMXYZ(point.Pos.X, point.Pos.Y, point.Pos.Z);
    d = sqrt(DSQR(der.Pos.X) + DSQR(der.Pos.Y) + DSQR(der.Pos.Z));
    if(CTX.mesh.constrained_bgmesh)
      return MAX(d / Lc, THEM->Metric->getLc(t, THEC));
    else
      return d / Lc;
  }
  else
    return THEM->Metric->getLc(t, THEC);
}

void Maillage_Curve(void *data, void *dummy)
{
  Curve *c;
  Simplex *s;
  double b, a, d, dt, dp, t;
  int i, N, count, NUMP;
  Vertex **v, **vexist, *pV, V, *v1, *v2;
  List_T *Points;
  IntPoint P1, P2;

  THEC = c = *(Curve **) data;

  if(c->Num < 0)
    return;

  Msg(STATUS2, "Meshing curve %d", c->Num);

  if(MeshDiscreteCurve(c)){
    return;
  }
  
  Points = List_Create(10, 10, sizeof(IntPoint));
  c->l = Integration(c->ubeg, c->uend, F_One, Points, 1.e-4);
  List_Delete(Points);

  if(!c->l) {
    Msg(GERROR, "Zero length Curve %d", c->Num);
    return;
  }

  if(Extrude_Mesh(c)){
    return;
  }

  if(c->Method == TRANSFINI) {
    Points = List_Create(10, 10, sizeof(IntPoint));
    a = Integration(c->ubeg, c->uend, F_Transfini, Points, 1.e-7);
    N = c->ipar[0];
  }
  else {
    Points = List_Create(10, 10, sizeof(IntPoint));
    a = Integration(c->ubeg, c->uend, F_Lc, Points, 1.e-4);
    N = IMAX(2, (int)(a + 1.));
    
    if(c->Typ == MSH_SEGM_CIRC ||
       c->Typ == MSH_SEGM_CIRC_INV ||
       c->Typ == MSH_SEGM_ELLI || c->Typ == MSH_SEGM_ELLI_INV) {
      N = IMAX(N, (int)(fabs(c->Circle.t1 - c->Circle.t2) *
			(double)CTX.mesh.min_circ_points / Pi));
    }
    else if(c->Typ == MSH_SEGM_NURBS) {
      N = IMAX(N, 2);
    }
  }
  b = a / (double)(N - 1);
  
  v = &c->beg;
  if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, v))) {
    (*vexist)->u = c->ubeg;
    if((*vexist)->ListCurves)
      List_Add((*vexist)->ListCurves, &c);
    List_Add(c->Vertices, vexist);
  }
  else {
    pV = Create_Vertex((*v)->Num, (*v)->Pos.X, (*v)->Pos.Y,
		       (*v)->Pos.Z, (*v)->lc, c->ubeg);
    pV->ListCurves = List_Create(1, 1, sizeof(Curve *));
    List_Add(pV->ListCurves, &c);
    Tree_Add(THEM->Vertices, &pV);
    List_Add(c->Vertices, &pV);
  }
  
  count = NUMP = 1;
  while(NUMP < N - 1) {
    List_Read(Points, count - 1, &P1);
    List_Read(Points, count, &P2);
    d = (double)NUMP *b;
    
    if((fabs(P2.p) >= fabs(d)) && (fabs(P1.p) < fabs(d))) {
      dt = P2.t - P1.t;
      dp = P2.p - P1.p;
      t = P1.t + dt / dp * (d - P1.p);
      V = InterpolateCurve(c, t, 0);
      pV = Create_Vertex(++THEM->MaxPointNum, V.Pos.X, V.Pos.Y, V.Pos.Z, V.lc, t);
      pV->w = V.w;
      pV->ListCurves = List_Create(1, 1, sizeof(Curve *));
      List_Add(pV->ListCurves, &c);
      Tree_Add(THEM->Vertices, &pV);
      List_Add(c->Vertices, &pV);
      NUMP++;
    }
    else {
      count++;
    }
  }
  
  List_Delete(Points);
  
  v = &c->end;
  if((vexist = (Vertex **) Tree_PQuery(THEM->Vertices, v))) {
    (*vexist)->u = c->uend;
    if((*vexist)->ListCurves)
      List_Add((*vexist)->ListCurves, &c);
    List_Add(c->Vertices, vexist);
  }
  else {
    pV = Create_Vertex((*v)->Num, (*v)->Pos.X, (*v)->Pos.Y,
		       (*v)->Pos.Z, (*v)->lc, c->uend);
    pV->ListCurves = List_Create(1, 1, sizeof(Curve *));
    List_Add(pV->ListCurves, &c);
    Tree_Add(THEM->Vertices, &pV);
    List_Add(c->Vertices, &pV);
  }
  
  for(i = 0; i < List_Nbr(c->Vertices) - 1; i++) {
    List_Read(c->Vertices, i, &v1);
    List_Read(c->Vertices, i + 1, &v2);
    s = Create_Simplex(v1, v2, NULL, NULL);
    s->iEnt = c->Num;
    Tree_Add(c->Simplexes, &s);
  }

}
