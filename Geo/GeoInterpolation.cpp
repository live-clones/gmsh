// $Id: GeoInterpolation.cpp,v 1.28 2007-08-29 07:57:39 geuzaine Exp $
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
#include "Geo.h"
#include "GeoInterpolation.h"
#include "GeoStringInterface.h"
#include "Numeric.h"

// Curves

Vertex InterpolateCubicSpline(Vertex * v[4], double t, double mat[4][4],
                              int derivee, double t1, double t2)
{
  Vertex V;
  int i, j;
  double vec[4], T[4];

  V.Pos.X = V.Pos.Y = V.Pos.Z = 0.0;
  V.lc = (1 - t) * v[1]->lc + t * v[2]->lc;
  V.w = (1 - t) * v[1]->w + t * v[2]->w;

  if(derivee) {
    T[3] = 0.;
    T[2] = 1.;
    T[1] = 2. * t;
    T[0] = 3. * t * t;
  }
  else {
    T[3] = 1.;
    T[2] = t;
    T[1] = t * t;
    T[0] = t * t * t;
  }

  for(i = 0; i < 4; i++) {
    vec[i] = 0.0;
  }

  /* X */
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      vec[i] += mat[i][j] * v[j]->Pos.X;
    }
  }

  for(j = 0; j < 4; j++) {
    V.Pos.X += T[j] * vec[j];
    vec[j] = 0.0;
  }

  /* Y */
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      vec[i] += mat[i][j] * v[j]->Pos.Y;
    }
  }

  for(j = 0; j < 4; j++) {
    V.Pos.Y += T[j] * vec[j];
    vec[j] = 0.0;
  }

  /* Z */
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      vec[i] += mat[i][j] * v[j]->Pos.Z;
    }
  }
  for(j = 0; j < 4; j++) {
    V.Pos.Z += T[j] * vec[j];
    vec[j] = 0.0;
  }

  if(derivee) {
    V.Pos.X /= ((t2 - t1));
    V.Pos.Y /= ((t2 - t1));
    V.Pos.Z /= ((t2 - t1));
  }

  return V;
}

// interpolation in the parametric space !
SPoint2 InterpolateCubicSpline(Vertex * v[4], double t, double mat[4][4],
                              int derivee, double t1, double t2, gmshSurface *s)
{
  Vertex V;
  int i, j;
  double T[4];

  if(derivee) throw;

  T[3] = 1.;
  T[2] = t;
  T[1] = t * t;
  T[0] = t * t * t;
  
  SPoint2 coord [4], p;

  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      coord[i] +=  v[j]->pntOnGeometry * mat[i][j] ;
    }
  }

  for(j = 0; j < 4; j++) {
    p += coord[j] * T[j] ;
  }
  return p;

}

// Uniform BSplines
Vertex InterpolateUBS(Curve * Curve, double u, int derivee) 
{
  bool periodic = (Curve->end == Curve->beg);
  int NbControlPoints = List_Nbr(Curve->Control_Points);
  int NbCurves = NbControlPoints + (periodic ? -1 : 1);
  int iCurve = (int)floor(u * (double)NbCurves);
  if(iCurve == NbCurves) iCurve -= 1; // u = 1
  double t1 = (double)(iCurve) / (double)(NbCurves);
  double t2 = (double)(iCurve+1) / (double)(NbCurves);
  double t = (u - t1) / (t2 - t1);
  Vertex *v[4];
  for(int i = 0; i < 4; i++) {
    int k = iCurve - (periodic ? 1 : 2) + i;
    if(k < 0) k = periodic ? k + NbControlPoints - 1 : 0;
    if(k >= NbControlPoints) k = periodic ? k - NbControlPoints + 1: NbControlPoints - 1;
    List_Read(Curve->Control_Points, k , &v[i]);
  }

  if(Curve->geometry){
    SPoint2 pp = InterpolateCubicSpline(v, t, Curve->mat, 0, t1, t2,Curve->geometry);
    SPoint3 pt = Curve->geometry->point(pp);
    Vertex V;
    V.Pos.X = pt.x();
    V.Pos.Y = pt.y();
    V.Pos.Z = pt.z();
    return V;
  } 
  else
    return InterpolateCubicSpline(v, t, Curve->mat, 0, t1, t2);
}

// Non Uniform BSplines
int findSpan(double u, int deg, int n, float *U)
{
  if(u >= U[n])
    return n - 1;
  if(u <= U[0])
    return deg;

  int low = deg;
  int high = n + 1;
  int mid = (low + high) / 2;

  while(u < U[mid] || u >= U[mid + 1]) {
    if(u < U[mid])
      high = mid;
    else
      low = mid;
    mid = (low + high) / 2;
  }
  return mid;
}

void basisFuns(double u, int i, int deg, float *U, double *N)
{
  double left[1000];
  double *right = &left[deg + 1];

  double temp, saved;

  N[0] = 1.0;
  for(int j = 1; j <= deg; j++) {
    left[j] = u - U[i + 1 - j];
    right[j] = U[i + j] - u;
    saved = 0.0;
    for(int r = 0; r < j; r++) {
      temp = N[r] / (right[r + 1] + left[j - r]);
      N[r] = saved + right[r + 1] * temp;
      saved = left[j - r] * temp;
    }
    N[j] = saved;
  }
}

Vertex InterpolateNurbs(Curve * Curve, double u, int derivee)
{
  static double Nb[1000];
  int span = findSpan(u, Curve->degre, List_Nbr(Curve->Control_Points), Curve->k);
  basisFuns(u, span, Curve->degre, Curve->k, Nb);
  Vertex p;
  p.Pos.X = p.Pos.Y = p.Pos.Z = p.w = p.lc = 0.0;
  for(int i = Curve->degre; i >= 0; --i) {
    Vertex *v;
    List_Read(Curve->Control_Points, span - Curve->degre + i, &v);
    p.Pos.X += Nb[i] * v->Pos.X;
    p.Pos.Y += Nb[i] * v->Pos.Y;
    p.Pos.Z += Nb[i] * v->Pos.Z;
    p.w += Nb[i] * v->w;
    p.lc += Nb[i] * v->lc;
  }
  return p;
}

Vertex InterpolateCurve(Curve * c, double u, int derivee)
{
  if(c->Num < 0) {
    Curve *C0 = FindCurve(-c->Num);
    if(!C0){
      Msg(GERROR, "Unknown curve %d", -c->Num);
      return Vertex(0., 0., 0.);
    }
    return InterpolateCurve(C0, C0->ubeg + (C0->uend - C0->ubeg) * (1.-u), derivee);
  }
  
  Vertex V;
  V.u = u;

  if(derivee) {
    double eps = 1.e-5;
    Vertex D[2];
    D[0] = InterpolateCurve(c, u, 0);
    D[1] = InterpolateCurve(c, u + eps, 0);
    V.Pos.X = (D[1].Pos.X - D[0].Pos.X) / eps;
    V.Pos.Y = (D[1].Pos.Y - D[0].Pos.Y) / eps;
    V.Pos.Z = (D[1].Pos.Z - D[0].Pos.Z) / eps;
    return V;
  }

  int N, i;
  Vertex *v[5];
  double theta, t1, t2, t;
  Vertex temp1, temp2;

  switch (c->Typ) {

  case MSH_SEGM_LINE:
    N = List_Nbr(c->Control_Points);
    i = (int)((double)(N - 1) * u);
    while(i >= N - 1)
      i--;
    while(i < 0)
      i++;
    t1 = (double)(i) / (double)(N - 1);
    t2 = (double)(i + 1) / (double)(N - 1);
    t = (u - t1) / (t2 - t1);
    List_Read(c->Control_Points, i, &v[1]);
    List_Read(c->Control_Points, i + 1, &v[2]);
    if(!c->geometry){
      V.Pos.X = v[1]->Pos.X + t * (v[2]->Pos.X - v[1]->Pos.X);
      V.Pos.Y = v[1]->Pos.Y + t * (v[2]->Pos.Y - v[1]->Pos.Y);
      V.Pos.Z = v[1]->Pos.Z + t * (v[2]->Pos.Z - v[1]->Pos.Z);
      V.w = (1. - t) * v[1]->w + t * v[2]->w;
      V.lc = (1. - t) * v[1]->lc + t * v[2]->lc;
    }
    else{
      SPoint2 p = v[1]->pntOnGeometry +  (v[2]->pntOnGeometry - v[1]->pntOnGeometry) * t;
      SPoint3 pp = c->geometry->point(p);
      V.Pos.X = pp.x();
      V.Pos.Y = pp.y();
      V.Pos.Z = pp.z();
    }
    return V;

  case MSH_SEGM_PARAMETRIC:
    V.Pos.X = evaluate_scalarfunction("t", u, c->functu);
    V.Pos.Y = evaluate_scalarfunction("t", u, c->functv);
    V.Pos.Z = evaluate_scalarfunction("t", u, c->functw);
    V.w = (1. - u) * c->beg->w + u * c->end->w;
    V.lc = (1. - u) * c->beg->lc + u * c->end->lc;
    return V;

  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    if(c->Typ == MSH_SEGM_CIRC_INV || c->Typ == MSH_SEGM_ELLI_INV) {
      V.u = 1. - u;
      u = V.u;
    }
    theta = c->Circle.t1 - (c->Circle.t1 - c->Circle.t2) * u;
    theta -= c->Circle.incl; // for ellipses
    V.Pos.X =
      c->Circle.f1 * cos(theta) * cos(c->Circle.incl) -
      c->Circle.f2 * sin(theta) * sin(c->Circle.incl);
    V.Pos.Y =
      c->Circle.f1 * cos(theta) * sin(c->Circle.incl) +
      c->Circle.f2 * sin(theta) * cos(c->Circle.incl);
    V.Pos.Z = 0.0;
    Projette(&V, c->Circle.invmat);
    V.Pos.X += c->Circle.v[1]->Pos.X;
    V.Pos.Y += c->Circle.v[1]->Pos.Y;
    V.Pos.Z += c->Circle.v[1]->Pos.Z;
    V.w = (1. - u) * c->beg->w + u * c->end->w;
    V.lc = (1. - u) * c->beg->lc + u * c->end->lc;
    return V;

  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
    return InterpolateUBS(c, u, 0);

  case MSH_SEGM_NURBS:
    return InterpolateNurbs(c, u, 0);

  case MSH_SEGM_SPLN:
    N = List_Nbr(c->Control_Points);
    i = (int)((double)(N - 1) * u);
    if(i < 0)
      i = 0;
    if(i >= N - 1)
      i = N - 2;
    t1 = (double)(i) / (double)(N - 1);
    t2 = (double)(i + 1) / (double)(N - 1);
    t = (u - t1) / (t2 - t1);
    List_Read(c->Control_Points, i, &v[1]);
    List_Read(c->Control_Points, i + 1, &v[2]);
    if(!i) {
      if(c->beg == c->end){
	List_Read(c->Control_Points, N - 2, &v[0]);
      }
      else{
	v[0] = &temp1;
	v[0]->Pos.X = 2. * v[1]->Pos.X - v[2]->Pos.X;
	v[0]->Pos.Y = 2. * v[1]->Pos.Y - v[2]->Pos.Y;
	v[0]->Pos.Z = 2. * v[1]->Pos.Z - v[2]->Pos.Z;
	v[0]->pntOnGeometry = v[1]->pntOnGeometry * 2. - v[2]->pntOnGeometry;
      }
    }
    else {
      List_Read(c->Control_Points, i - 1, &v[0]);
    }
    if(i == N - 2) {
      if(c->beg == c->end){
	List_Read(c->Control_Points, 1, &v[3]);
      }
      else{
	v[3] = &temp2;
	v[3]->Pos.X = 2. * v[2]->Pos.X - v[1]->Pos.X;
	v[3]->Pos.Y = 2. * v[2]->Pos.Y - v[1]->Pos.Y;
	v[3]->Pos.Z = 2. * v[2]->Pos.Z - v[1]->Pos.Z;
	v[3]->pntOnGeometry = v[2]->pntOnGeometry * 2. - v[1]->pntOnGeometry;
      }
    }
    else {
      List_Read(c->Control_Points, i + 2, &v[3]);
    }
    if(c->geometry){
      SPoint2 pp = InterpolateCubicSpline(v, t, c->mat, 0, t1, t2,c->geometry);
      SPoint3 pt = c->geometry->point(pp);
      V.Pos.X = pt.x();
      V.Pos.Y = pt.y();
      V.Pos.Z = pt.z();
      return V;
    }
    else
      return InterpolateCubicSpline(v, t, c->mat, 0, t1, t2);

  default:
    Msg(GERROR, "Unknown curve type in interpolation");
    return V;
  }

}

// Surfaces

/* Interpolation transfinie sur un quadrangle :
   f(u,v) = (1-u)c4(v) + u c2(v) + (1-v)c1(u) + v c3(u)
            - [ (1-u)(1-v)s1 + u(1-v)s2 + uv s3 + (1-u)v s4 ] */

#define TRAN_QUA(c1,c2,c3,c4,s1,s2,s3,s4,u,v) \
   (1.-u)*c4+u*c2+(1.-v)*c1+v*c3-((1.-u)*(1.-v)*s1+u*(1.-v)*s2+u*v*s3+(1.-u)*v*s4)

Vertex TransfiniteQua(Vertex c1, Vertex c2, Vertex c3, Vertex c4,
                      Vertex s1, Vertex s2, Vertex s3, Vertex s4,
                      double u, double v)
{
  Vertex V;

  V.lc = TRAN_QUA(c1.lc, c2.lc, c3.lc, c4.lc,
                  s1.lc, s2.lc, s3.lc, s4.lc, u, v);
  V.w = TRAN_QUA(c1.w, c2.w, c3.w, c4.w, s1.w, s2.w, s3.w, s4.w, u, v);
  V.Pos.X = TRAN_QUA(c1.Pos.X, c2.Pos.X, c3.Pos.X, c4.Pos.X,
                     s1.Pos.X, s2.Pos.X, s3.Pos.X, s4.Pos.X, u, v);
  V.Pos.Y = TRAN_QUA(c1.Pos.Y, c2.Pos.Y, c3.Pos.Y, c4.Pos.Y,
                     s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, s4.Pos.Y, u, v);
  V.Pos.Z = TRAN_QUA(c1.Pos.Z, c2.Pos.Z, c3.Pos.Z, c4.Pos.Z,
                     s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, s4.Pos.Z, u, v);
  return (V);
}

/* Interpolation transfinie sur un triangle : TRAN_QUA avec s1=s4=c4
   f(u,v) = u c2 (v) + (1-v) c1(u) + v c3(u) - u(1-v) s2 - uv s3 */

#define TRAN_TRI(c1,c2,c3,s1,s2,s3,u,v) u*c2+(1.-v)*c1+v*c3-(u*(1.-v)*s2+u*v*s3);

Vertex TransfiniteTri(Vertex c1, Vertex c2, Vertex c3,
                      Vertex s1, Vertex s2, Vertex s3, double u, double v)
{
  Vertex V;

  V.lc = TRAN_TRI(c1.lc, c2.lc, c3.lc, s1.lc, s2.lc, s3.lc, u, v);
  V.w = TRAN_TRI(c1.w, c2.w, c3.w, s1.w, s2.w, s3.w, u, v);
  V.Pos.X = TRAN_TRI(c1.Pos.X, c2.Pos.X, c3.Pos.X,
                     s1.Pos.X, s2.Pos.X, s3.Pos.X, u, v);
  V.Pos.Y = TRAN_TRI(c1.Pos.Y, c2.Pos.Y, c3.Pos.Y,
                     s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, u, v);
  V.Pos.Z = TRAN_TRI(c1.Pos.Z, c2.Pos.Z, c3.Pos.Z,
                     s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, u, v);
  return (V);
}

void TransfiniteSph(Vertex S, Vertex center, Vertex * T)
{
  double r, s, dirx, diry, dirz;

  r = sqrt(DSQR(S.Pos.X - center.Pos.X) + DSQR(S.Pos.Y - center.Pos.Y)
           + DSQR(S.Pos.Z - center.Pos.Z));

  s = sqrt(DSQR(T->Pos.X - center.Pos.X) + DSQR(T->Pos.Y - center.Pos.Y)
           + DSQR(T->Pos.Z - center.Pos.Z));

  dirx = (T->Pos.X - center.Pos.X) / s;
  diry = (T->Pos.Y - center.Pos.Y) / s;
  dirz = (T->Pos.Z - center.Pos.Z) / s;

  T->Pos.X = center.Pos.X + r * dirx;
  T->Pos.Y = center.Pos.Y + r * diry;
  T->Pos.Z = center.Pos.Z + r * dirz;
}

Vertex InterpolateRuledSurface(Surface * s, double u, double v)
{
  Curve *C[4];
  Vertex *c1, *c2;
  int issphere = 1;
  for(int i = 0; i < List_Nbr(s->Generatrices); i++) {
    if(i == 4) break; // we accept holes in ruled surfaces!
    List_Read(s->Generatrices, i, &C[i]);
    if(C[i]->Typ != MSH_SEGM_CIRC && C[i]->Typ != MSH_SEGM_CIRC_INV) {
      issphere = 0;
    }
    else if(issphere) {
      if(!i) {
	List_Read(C[i]->Control_Points, 1, &c1);
      }
      else {
	List_Read(C[i]->Control_Points, 1, &c2);
	if(compareVertex(&c1, &c2))
	  issphere = 0;
      }
    }
  }

  Vertex *S[4], V[4], T;

  if(s->Typ == MSH_SURF_REGL && List_Nbr(s->Generatrices) >= 4){
    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    S[3] = C[3]->beg;
    V[0] = InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    V[1] = InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] = InterpolateCurve(C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
    V[3] = InterpolateCurve(C[3], C[3]->ubeg + (C[3]->uend - C[3]->ubeg) * (1. - v), 0);
    T = TransfiniteQua(V[0], V[1], V[2], V[3], *S[0], *S[1], *S[2], *S[3], u, v);
    if(issphere) TransfiniteSph(*S[0], *c1, &T);
  }
  else if(List_Nbr(s->Generatrices) >= 3){
    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    V[0] = InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    V[1] = InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] = InterpolateCurve(C[2], C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1.-u), 0);
    T = TransfiniteTri(V[0], V[1], V[2], *S[0], *S[1], *S[2], u, v);
    if(issphere) TransfiniteSph(*S[0], *c1, &T);
  }

  return T;
}

Vertex InterpolateExtrudedSurface(Surface * s, double u, double v)
{
  Curve *c = FindCurve(s->Extrude->geo.Source);

  // find position of c in the list of generatrices
  int num = -1;
  for(int i = 0; i < List_Nbr(s->Generatrices); i++){
    if(c == *(Curve**)List_Pointer(s->Generatrices, i)){
      num = i;
      break;
    }
  }

  if(num < 0)
    Msg(GERROR, "Unknown curve in extruded surface");
  
  Vertex T;

  switch(num){
  case 0: 
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * u, 0);
    s->Extrude->Extrude(v, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  case 1:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * v, 0);
    s->Extrude->Extrude(1. - u, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  case 2:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * (1. - u), 0);
    s->Extrude->Extrude(1. - v, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  default:
    T = InterpolateCurve(c, c->ubeg + (c->uend - c->ubeg) * (1. - v), 0);
    s->Extrude->Extrude(u, T.Pos.X, T.Pos.Y, T.Pos.Z);
    return T;
  }
}

Vertex InterpolateSurface(Surface * s, double u, double v, int derivee, int u_v)
{

  if(derivee) {
    double eps = 1.e-6;
    Vertex D[4], T;
    if(u_v == 1) {
      if(u - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u + eps, v, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u - eps, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    else {
      if(v - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v + eps, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - eps, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    T.Pos.X = (D[1].Pos.X - D[0].Pos.X) / eps;
    T.Pos.Y = (D[1].Pos.Y - D[0].Pos.Y) / eps;
    T.Pos.Z = (D[1].Pos.Z - D[0].Pos.Z) / eps;
    return T;
  }

  if(s->geometry){
    Vertex T;
    SPoint3 p = s->geometry->point(u, v);
    T.Pos.X = p.x();
    T.Pos.Y = p.y();
    T.Pos.Z = p.z();
    return T;
  }

  // use the exact extrusion formula if the surface is extruded
  if(s->Extrude && s->Extrude->geo.Mode == EXTRUDED_ENTITY && 
     s->Typ != MSH_SURF_PLAN)
    return InterpolateExtrudedSurface(s, u, v);
  
  switch (s->Typ) {
  case MSH_SURF_REGL:
  case MSH_SURF_TRIC: 
    return InterpolateRuledSurface(s, u, v);
  case MSH_SURF_PLAN:
    {
      Vertex T(u, v, .0);
      Vertex V(s->a, s->b, s->c);
      Projette(&V, s->plan);
      if(V.Pos.Z != 0.)
	T.Pos.Z = (s->d - V.Pos.X * T.Pos.X - V.Pos.Y * T.Pos.Y) / V.Pos.Z;
      else
	T.Pos.Z = 0.;
      return T;
    }
  default:
    {
      Msg(GERROR, "Unknown surface type in interpolation");
      Vertex T(0., 0., 0.);
      return T;
    }
  }
}

