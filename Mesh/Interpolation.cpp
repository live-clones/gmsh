// $Id: Interpolation.cpp,v 1.23 2004-02-07 01:40:22 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
#include "CAD.h"
#include "Mesh.h"
#include "Utils.h"
#include "Interpolation.h"

extern Mesh *THEM;

// Curves

Vertex InterpolateCurve(Curve * Curve, double u, int derivee)
{
  int N, i, j;
  Vertex D[2], V;
  Vertex *v[5];
  double eps = 1.e-3, T[4], W, teta, t1, t2, t;
  double vec[4];
  Vertex temp1, temp2;

  V.u = u;

  if(derivee) {
    D[0] = InterpolateCurve(Curve, u, 0);
    D[1] = InterpolateCurve(Curve, u + eps, 0);
    V.Pos.X = (D[1].Pos.X - D[0].Pos.X) / eps;
    V.Pos.Y = (D[1].Pos.Y - D[0].Pos.Y) / eps;
    V.Pos.Z = (D[1].Pos.Z - D[0].Pos.Z) / eps;
    return V;
  }

  switch (Curve->Typ) {

  case MSH_SEGM_LINE:
    N = List_Nbr(Curve->Control_Points);
    i = (int)((double)(N - 1) * u);
    while(i >= N - 1)
      i--;
    while(i < 0)
      i++;
    t1 = (double)(i) / (double)(N - 1);
    t2 = (double)(i + 1) / (double)(N - 1);
    t = (u - t1) / (t2 - t1);
    List_Read(Curve->Control_Points, i, &v[1]);
    List_Read(Curve->Control_Points, i + 1, &v[2]);
    V.Pos.X = v[1]->Pos.X + t * (v[2]->Pos.X - v[1]->Pos.X);
    V.Pos.Y = v[1]->Pos.Y + t * (v[2]->Pos.Y - v[1]->Pos.Y);
    V.Pos.Z = v[1]->Pos.Z + t * (v[2]->Pos.Z - v[1]->Pos.Z);
    V.w = (1. - t) * v[1]->w + t * v[2]->w;
    V.lc = (1. - t) * v[1]->lc + t * v[2]->lc;
    return V;

  case MSH_SEGM_PARAMETRIC:
    V.Pos.X = evaluate_scalarfunction("t", u, Curve->functu);
    V.Pos.Y = evaluate_scalarfunction("t", u, Curve->functv);
    V.Pos.Z = evaluate_scalarfunction("t", u, Curve->functw);
    V.w = (1. - u) * Curve->beg->w + u * Curve->end->w;
    V.lc = (1. - u) * Curve->beg->lc + u * Curve->end->lc;
    return V;

  case MSH_SEGM_CIRC:
  case MSH_SEGM_CIRC_INV:
  case MSH_SEGM_ELLI:
  case MSH_SEGM_ELLI_INV:
    if(Curve->Typ == MSH_SEGM_CIRC_INV || Curve->Typ == MSH_SEGM_ELLI_INV) {
      V.u = 1. - u;
      u = V.u;
    }

    teta = Curve->Circle.t1 - (Curve->Circle.t1 - Curve->Circle.t2) * u;
    /* pour les ellipses */
    teta -= Curve->Circle.incl;

    V.Pos.X =
      Curve->Circle.f1 * cos(teta) * cos(Curve->Circle.incl) -
      Curve->Circle.f2 * sin(teta) * sin(Curve->Circle.incl);
    V.Pos.Y =
      Curve->Circle.f1 * cos(teta) * sin(Curve->Circle.incl) +
      Curve->Circle.f2 * sin(teta) * cos(Curve->Circle.incl);
    V.Pos.Z = 0.0;
    Projette(&V, Curve->Circle.invmat);
    V.Pos.X += Curve->Circle.v[1]->Pos.X;
    V.Pos.Y += Curve->Circle.v[1]->Pos.Y;
    V.Pos.Z += Curve->Circle.v[1]->Pos.Z;
    V.w = (1. - u) * Curve->beg->w + u * Curve->end->w;
    V.lc = (1. - u) * Curve->beg->lc + u * Curve->end->lc;
    return V;

  case MSH_SEGM_BSPLN:
  case MSH_SEGM_BEZIER:
    return InterpolateUBS(Curve, u, derivee);

  case MSH_SEGM_NURBS:
    return InterpolateNurbs(Curve, u, derivee);

  case MSH_SEGM_SPLN:
    N = List_Nbr(Curve->Control_Points);

    /* 
       0                   i    P     i+1                  N-1
       vfirst*---------*---------*----X-----*----------*----------* vlast
       0                  t1   absc   t2                    1
       0    t     1

       Splines uniformes -> Le point se trouve entre v[1] et v[2] 
       -> Calcul de l'abcisse curviligne locale t ( entre 0 et 1 )

       0           -> t1 
       1           -> t2
       u -> t

       Splines Lineiques -> Multilines
     */

    i = (int)((double)(N - 1) * u);
    if(i < 0)
      i = 0;
    if(i >= N - 1)
      i = N - 2;

    t1 = (double)(i) / (double)(N - 1);
    t2 = (double)(i + 1) / (double)(N - 1);

    t = (u - t1) / (t2 - t1);

    List_Read(Curve->Control_Points, i, &v[1]);
    List_Read(Curve->Control_Points, i + 1, &v[2]);

    V.lc = (1. - t) * v[1]->lc + t * v[2]->lc;
    V.w = (1. - t) * v[1]->w + t * v[2]->w;

    if(!i) {
      v[0] = &temp1;
      v[0]->Pos.X = 2. * v[1]->Pos.X - v[2]->Pos.X;
      v[0]->Pos.Y = 2. * v[1]->Pos.Y - v[2]->Pos.Y;
      v[0]->Pos.Z = 2. * v[1]->Pos.Z - v[2]->Pos.Z;
    }
    else {
      List_Read(Curve->Control_Points, i - 1, &v[0]);
    }

    if(i == N - 2) {
      v[3] = &temp2;
      v[3]->Pos.X = 2. * v[2]->Pos.X - v[1]->Pos.X;
      v[3]->Pos.Y = 2. * v[2]->Pos.Y - v[1]->Pos.Y;
      v[3]->Pos.Z = 2. * v[2]->Pos.Z - v[1]->Pos.Z;
    }
    else {
      List_Read(Curve->Control_Points, i + 2, &v[3]);
    }

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

    V.Pos.X = V.Pos.Y = V.Pos.Z = W = 0.0;
    for(i = 0; i < 4; i++) {
      vec[i] = 0.0;
    }

    /* X */
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 4; j++) {
        vec[i] += Curve->mat[i][j] * v[j]->Pos.X;
      }
    }

    for(j = 0; j < 4; j++) {
      V.Pos.X += T[j] * vec[j];
      vec[j] = 0.0;
    }

    /* Y */
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 4; j++) {
        vec[i] += Curve->mat[i][j] * v[j]->Pos.Y;
      }
    }

    for(j = 0; j < 4; j++) {
      V.Pos.Y += T[j] * vec[j];
      vec[j] = 0.0;
    }

    /* Z */
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 4; j++) {
        vec[i] += Curve->mat[i][j] * v[j]->Pos.Z;
      }
    }
    for(j = 0; j < 4; j++) {
      V.Pos.Z += T[j] * vec[j];
      vec[j] = 0.0;
    }

    /* W */
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 4; j++) {
        vec[i] += Curve->mat[i][j] * v[j]->lc;
      }
    }
    for(j = 0; j < 4; j++) {
      W += T[j] * vec[j];
    }

    if(derivee) {
      V.Pos.X /= (t2 - t1);
      V.Pos.Y /= (t2 - t1);
      V.Pos.Z /= (t2 - t1);
    }
    else {
      // V.Pos.X /= W;
      // V.Pos.Y /= W;
      // V.Pos.Z /= W;
    }
    return V;

  default:
    Msg(FATAL, "Unknown curve type in interpolation");
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

Vertex InterpolateSurface(Surface * s, double u, double v,
                          int derivee, int u_v)
{
  Vertex *c1, *c2, T, D[4], V[4], *S[4];
  Curve *C[4];
  int i, issphere;
  double eps = 1.e-6;

  if(derivee) {
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
    else if(u_v == 2) {
      if(v - eps < 0.0) {
        D[0] = InterpolateSurface(s, u, v, 0, 0);
        D[1] = InterpolateSurface(s, u, v + eps, 0, 0);
      }
      else {
        D[0] = InterpolateSurface(s, u, v - eps, 0, 0);
        D[1] = InterpolateSurface(s, u, v, 0, 0);
      }
    }
    else {
      Msg(WARNING, "Arbitrary InterpolateSurface for derivative not done");
      /*
         double epsc = eps * cos (t);
         double epss = eps * sin (t);
         if (v - epss < 0.0 && u - epsc < 0.0){
         D[0] = InterpolateSurface (s, u, v, 0, 0);
         D[1] = InterpolateSurface (s, u + epsc, v + epss, 0, 0);
         }
         else if (v - epss < 0.0){
         D[0] = InterpolateSurface (s, u - epsc, v, 0, 0);
         D[1] = InterpolateSurface (s, u, v + epss, 0, 0);
         }
         else if (u - epsc < 0.0){
         D[0] = InterpolateSurface (s, u, v - epss, 0, 0);
         D[1] = InterpolateSurface (s, u + epsc, v, 0, 0);
         }
         else{
         D[0] = InterpolateSurface (s, u - epsc, v - epss, 0, 0);
         D[1] = InterpolateSurface (s, u, v, 0, 0);
         }
       */
    }
    T.Pos.X = (D[1].Pos.X - D[0].Pos.X) / eps;
    T.Pos.Y = (D[1].Pos.Y - D[0].Pos.Y) / eps;
    T.Pos.Z = (D[1].Pos.Z - D[0].Pos.Z) / eps;
    return T;
  }

  Vertex x(u, v, .0);
  Vertex *xx = &x, *dum;

  if(s->Extrude && s->Extrude->geo.Mode == EXTRUDED_ENTITY &&
     s->Typ != MSH_SURF_PLAN) {
    Curve *c = FindCurve(s->Extrude->geo.Source, THEM);
    Vertex v1 = InterpolateCurve(c, u, 0);
    s->Extrude->Extrude(v, v1.Pos.X, v1.Pos.Y, v1.Pos.Z);
    return v1;
  }

  switch (s->Typ) {

  case MSH_SURF_PLAN:

    Calcule_Z_Plan(&xx, &dum);
    //Projette_Inverse(&xx, &dum);
    return x;

  case MSH_SURF_REGL:
    issphere = 1;
    for(i = 0; i < 4; i++) {
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

    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    S[3] = C[3]->beg;
    V[0] =
      InterpolateCurve(C[0], C[0]->ubeg + (C[0]->uend - C[0]->ubeg) * u, 0);
    V[1] =
      InterpolateCurve(C[1], C[1]->ubeg + (C[1]->uend - C[1]->ubeg) * v, 0);
    V[2] =
      InterpolateCurve(C[2],
                       C[2]->ubeg + (C[2]->uend - C[2]->ubeg) * (1. - u), 0);
    V[3] =
      InterpolateCurve(C[3],
                       C[3]->ubeg + (C[3]->uend - C[3]->ubeg) * (1. - v), 0);

    T =
      TransfiniteQua(V[0], V[1], V[2], V[3], *S[0], *S[1], *S[2], *S[3], u,
                     v);
    if(issphere)
      TransfiniteSph(*S[0], *c1, &T);

    return (T);

  case MSH_SURF_NURBS:
    return InterpolateNurbsSurface(s, u, v);

  case MSH_SURF_TRIC:
    issphere = 1;
    for(i = 0; i < 3; i++) {
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

    S[0] = C[0]->beg;
    S[1] = C[1]->beg;
    S[2] = C[2]->beg;
    V[0] = InterpolateCurve(C[0], u, 0);
    V[1] = InterpolateCurve(C[1], v, 0);
    V[2] = InterpolateCurve(C[2], 1. - u, 0);

    T = TransfiniteTri(V[0], V[1], V[2], *S[0], *S[1], *S[2], u, v);
    if(issphere)
      TransfiniteSph(*S[0], *c1, &T);

    return (T);

  default:
    Msg(FATAL, "Unknown surface type in interpolation");
    return T;
  }

}

// Volumes

/* Interpolation transfinie sur un hexaedre 
                                   prisme (avec s1=s4=a4, s5=s8=a8, a9=a12=f4) 
   f(u,v) = (1-u) f4(v,w) + u f2(v,w) 
          + (1-v) f1(u,w) + v f3(u,w) 
          + (1-w) f5(u,v) + w f6(u,v) 
          - [ (1-u)(1-v) c9(w) + (1-u)v c12(w) + u(1-v) c10(w) + uv c11(w) ]
          - [ (1-v)(1-w) c1(u) + (1-v)w c5(u)  + v(1-w) c3(u)  + vw c7(u)  ]
          - [ (1-u)(1-w) c4(v) + (1-w)u c2(v)  + w(1-u) c8(v)  + uw c6(v)  ]
          + [ (1-u)(1-v)(1-w) s1 + u(1-v)(1-w) s2 + uv(1-w) s3 + (1-u)v(1-w) s4 + 
	      (1-u)(1-v)w     s5 + u(1-v)w     s6 + uvw     s7 + (1-u)vw     s8 ]
*/

#define TRAN_HEX(f1,f2,f3,f4,f5,f6,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,s1,s2,s3,s4,s5,s6,s7,s8,u,v,w) (1-u)*f4+u*f2+(1-v)*f1+v*f3+(1-w)*f5+w*f6-((1-u)*(1-v)*c9+(1-u)*v*c12+u*(1-v)*c10+u*v*c11)-((1-v)*(1-w)*c1+(1-v)*w*c5+v*(1-w)*c3+v*w*c7)-((1-u)*(1-w)*c4+(1-w)*u*c2+w*(1-u)*c8+u*w*c6)+(1-u)*(1-v)*(1-w)*s1+u*(1-v)*(1-w)*s2+u*v*(1-w)*s3+(1-u)*v*(1-w)*s4+(1-u)*(1-v)*w*s5+u*(1-v)*w*s6+u*v*w*s7+(1-u)*v*w*s8

Vertex TransfiniteHex(Vertex f1, Vertex f2, Vertex f3, Vertex f4, Vertex f5,
                      Vertex f6, Vertex c1, Vertex c2, Vertex c3, Vertex c4,
                      Vertex c5, Vertex c6, Vertex c7, Vertex c8, Vertex c9,
                      Vertex c10, Vertex c11, Vertex c12, Vertex s1,
                      Vertex s2, Vertex s3, Vertex s4, Vertex s5, Vertex s6,
                      Vertex s7, Vertex s8, double u, double v, double w)
{
  Vertex V;

  V.lc = TRAN_HEX(f1.lc, f2.lc, f3.lc, f4.lc, f5.lc, f6.lc,
                  c1.lc, c2.lc, c3.lc, c4.lc, c5.lc, c6.lc,
                  c7.lc, c8.lc, c9.lc, c10.lc, c11.lc, c12.lc,
                  s1.lc, s2.lc, s3.lc, s4.lc, s5.lc, s6.lc, s7.lc, s8.lc,
                  u, v, w);

  V.Pos.X =
    TRAN_HEX(f1.Pos.X, f2.Pos.X, f3.Pos.X, f4.Pos.X, f5.Pos.X, f6.Pos.X,
             c1.Pos.X, c2.Pos.X, c3.Pos.X, c4.Pos.X, c5.Pos.X, c6.Pos.X,
             c7.Pos.X, c8.Pos.X, c9.Pos.X, c10.Pos.X, c11.Pos.X, c12.Pos.X,
             s1.Pos.X, s2.Pos.X, s3.Pos.X, s4.Pos.X, s5.Pos.X, s6.Pos.X,
             s7.Pos.X, s8.Pos.X, u, v, w);

  V.Pos.Y =
    TRAN_HEX(f1.Pos.Y, f2.Pos.Y, f3.Pos.Y, f4.Pos.Y, f5.Pos.Y, f6.Pos.Y,
             c1.Pos.Y, c2.Pos.Y, c3.Pos.Y, c4.Pos.Y, c5.Pos.Y, c6.Pos.Y,
             c7.Pos.Y, c8.Pos.Y, c9.Pos.Y, c10.Pos.Y, c11.Pos.Y, c12.Pos.Y,
             s1.Pos.Y, s2.Pos.Y, s3.Pos.Y, s4.Pos.Y, s5.Pos.Y, s6.Pos.Y,
             s7.Pos.Y, s8.Pos.Y, u, v, w);

  V.Pos.Z =
    TRAN_HEX(f1.Pos.Z, f2.Pos.Z, f3.Pos.Z, f4.Pos.Z, f5.Pos.Z, f6.Pos.Z,
             c1.Pos.Z, c2.Pos.Z, c3.Pos.Z, c4.Pos.Z, c5.Pos.Z, c6.Pos.Z,
             c7.Pos.Z, c8.Pos.Z, c9.Pos.Z, c10.Pos.Z, c11.Pos.Z, c12.Pos.Z,
             s1.Pos.Z, s2.Pos.Z, s3.Pos.Z, s4.Pos.Z, s5.Pos.Z, s6.Pos.Z,
             s7.Pos.Z, s8.Pos.Z, u, v, w);

  return (V);
}

void Normal2Surface(Surface * s, double u, double v, double n[3])
{
  Vertex du, dv;
  double t1[3], t2[3];
  du = InterpolateSurface(s, u, v, 1, 1);
  dv = InterpolateSurface(s, u, v, 1, 2);
  t1[0] = du.Pos.X;
  t1[1] = du.Pos.Y;
  t1[2] = du.Pos.Z;
  t2[0] = dv.Pos.X;
  t2[1] = dv.Pos.Y;
  t2[2] = dv.Pos.Z;
  prodve(t1, t2, n);
  norme(n);
}

void HessianNormal2Surface(Surface * s, double u, double v, double n[3])
{
  Vertex du, dv;
  double t1[3], t2[3];
  du = InterpolateSurface(s, u, v, 1, 1);
  dv = InterpolateSurface(s, u, v, 1, 2);
  t1[0] = du.Pos.X;
  t1[1] = du.Pos.Y;
  t1[2] = du.Pos.Z;
  t2[0] = dv.Pos.X;
  t2[1] = dv.Pos.Y;
  t2[2] = dv.Pos.Z;
  prodve(t1, t2, n);
  norme(n);
}
