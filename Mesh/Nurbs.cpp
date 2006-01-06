// $Id: Nurbs.cpp,v 1.17 2006-01-06 00:34:26 geuzaine Exp $
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
#include "Nurbs.h"
#include "Mesh.h"
#include "Geo.h"
#include "GeoUtils.h"
#include "Create.h"
#include "CAD.h"

extern Mesh *THEM;

// Cubic spline

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


// Uniform BSplines

Vertex InterpolateUBS(Curve * Curve, double u, int derivee)
{
  int NbControlPoints, NbCurves, iCurve;
  double t, t1, t2;
  Vertex *v[4];

  NbControlPoints = List_Nbr(Curve->Control_Points);
  NbCurves = NbControlPoints - 3;

  iCurve = (int)(u * (double)NbCurves) + 1;

  if(iCurve > NbCurves)
    iCurve = NbCurves;

  t1 = (double)(iCurve - 1) / (double)(NbCurves);
  t2 = (double)(iCurve) / (double)(NbCurves);

  t = (u - t1) / (t2 - t1);

  List_Read(Curve->Control_Points, iCurve - 1, &v[0]);
  List_Read(Curve->Control_Points, iCurve, &v[1]);
  List_Read(Curve->Control_Points, iCurve + 1, &v[2]);
  List_Read(Curve->Control_Points, iCurve + 2, &v[3]);

  return InterpolateCubicSpline(v, t, Curve->mat, derivee, t1, t2);
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

  //N.resize(deg+1) ;

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
  int span =
    findSpan(u, Curve->degre, List_Nbr(Curve->Control_Points), Curve->k);
  Vertex p, *v;

  basisFuns(u, span, Curve->degre, Curve->k, Nb);
  p.Pos.X = p.Pos.Y = p.Pos.Z = p.w = p.lc = 0.0;
  for(int i = Curve->degre; i >= 0; --i) {
    List_Read(Curve->Control_Points, span - Curve->degre + i, &v);
    p.Pos.X += Nb[i] * v->Pos.X;
    p.Pos.Y += Nb[i] * v->Pos.Y;
    p.Pos.Z += Nb[i] * v->Pos.Z;
    p.w += Nb[i] * v->w;
    p.lc += Nb[i] * v->lc;
  }
  return p;
}

Vertex InterpolateNurbsSurface(Surface * s, double u, double v)
{
  int uspan = findSpan(u, s->OrderU, s->Nu, s->ku);
  int vspan = findSpan(v, s->OrderV, s->Nv, s->kv);
  double Nu[1000], Nv[1000];
  Vertex sp, temp[1000], *pv;

  basisFuns(u, uspan, s->OrderU, s->ku, Nu);
  basisFuns(v, vspan, s->OrderV, s->kv, Nv);

  int l, ll, kk;
  for(l = 0; l <= s->OrderV; l++) {
    temp[l].Pos.X = temp[l].Pos.Y = temp[l].Pos.Z = temp[l].w = temp[l].lc =
      0.0;
    for(int k = 0; k <= s->OrderU; k++) {
      kk = uspan - s->OrderU + k;
      ll = vspan - s->OrderV + l;
      List_Read(s->Control_Points, kk + s->Nu * ll, &pv);
      temp[l].Pos.X += Nu[k] * pv->Pos.X;
      temp[l].Pos.Y += Nu[k] * pv->Pos.Y;
      temp[l].Pos.Z += Nu[k] * pv->Pos.Z;
      temp[l].w += Nu[k] * pv->w;
      temp[l].lc += Nu[k] * pv->lc;
    }
  }
  sp.Pos.X = sp.Pos.Y = sp.Pos.Z = sp.w = sp.lc = 0.0;
  for(l = 0; l <= s->OrderV; l++) {
    sp.Pos.X += Nv[l] * temp[l].Pos.X;
    sp.Pos.Y += Nv[l] * temp[l].Pos.Y;
    sp.Pos.Z += Nv[l] * temp[l].Pos.Z;
    sp.w += Nv[l] * temp[l].w;
    sp.lc += Nv[l] * temp[l].lc;
  }
  return sp;
}


// Surface creation helpers

void CreateNurbsSurfaceSupport(int Num, int Order1, int Order2,
                               List_T * List, List_T * ku, List_T * kv)
{
  // This routine has been heavily modified to fit the new interfaces,
  // but has not been tested since then. It's probably full of bugs
  // now.
  List_T *ListOfDouble_L;
  List_T *ListCP = List_Create(2, 2, sizeof(int));

  for(int j = 0; j < List_Nbr(List); j++) {
    List_Read(List, j, &ListOfDouble_L);
    for(int i = 0; i < List_Nbr(ListOfDouble_L); i++) {
      double d;
      List_Read(ListOfDouble_L, i, &d);
      int N = (int)d;
      List_Add(ListCP, &N);
    }
  }
  List_Read(List, 0, &ListOfDouble_L);
  int Nu = List_Nbr(List);
  int Nv = List_Nbr(ListOfDouble_L);

  Surface *s = Create_Surface(Num, MSH_SURF_NURBS);
  s->Support = NULL;
  s->Control_Points = List_Create(4, 1, sizeof(Vertex *));
  s->OrderU = Order1;
  s->OrderV = Order2;
  s->Nu = Nu;
  s->Nv = Nv;
  for(int i = 0; i < List_Nbr(ListCP); i++) {
    int j;
    List_Read(ListCP, i, &j);
    Vertex *v = FindPoint(j, THEM);
    if(v){
      List_Add(s->Control_Points, &v);
    }
    else{
      Msg(GERROR, "Unknown control point %d in nurbs surface", j);
    }
  }

  s->ku = (float *)malloc(List_Nbr(ku) * sizeof(float));
  s->kv = (float *)malloc(List_Nbr(kv) * sizeof(float));

  double kumin = 0., kumax = 1.;
  double kvmin = 0., kvmax = 1.;

  for(int i = 0; i < List_Nbr(ku); i++) {
    double d;
    List_Read(ku, i, &d);
    float f = (float)((d - kumin) / (kumax - kumin));
    s->ku[i] = f;
  }
  for(int i = 0; i < List_Nbr(kv); i++) {
    double d;
    List_Read(kv, i, &d);
    float f = (float)((d - kvmin) / (kvmax - kvmin));
    s->kv[i] = f;
  }

  List_Delete(ListCP);

  End_Surface(s);
  Tree_Add(THEM->Surfaces, &s);
}

void CreateNurbsSurface(int Num, int Order1, int Order2, List_T * List,
                        List_T * ku, List_T * kv)
{
  // This routine has been heavily modified to fit the new interfaces,
  // but has not been tested since then. It's probably full of bugs
  // now.

  List_T *ListOfDouble_L, *Listint, *ListCP;
  int Loop[4];

  ListCP = List_Create(2, 2, sizeof(int));

  double kumin, kumax;
  List_Read(ku, 0, &kumin);
  List_Read(ku, List_Nbr(ku) - 1, &kumax);
  double kvmin, kvmax;
  List_Read(kv, 0, &kvmin);
  List_Read(kv, List_Nbr(kv) - 1, &kvmax);
  for(int j = 0; j < List_Nbr(List); j++) {
    List_Read(List, j, &ListOfDouble_L);
    for(int i = 0; i < List_Nbr(ListOfDouble_L); i++) {
      double d;
      List_Read(ListOfDouble_L, i, &d);
      int N = (int)d;
      List_Add(ListCP, &N);
    }
  }

  // 1st and 3rd gen
  List_Read(List, 0, &ListOfDouble_L);
  Listint = ListOfDouble2ListOfInt(ListOfDouble_L);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[0])) {
  }
  else {
    Loop[0] = NEWREG();
    Curve *c = Create_Curve(Loop[0], MSH_SEGM_NURBS, Order1, Listint, NULL, 
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(THEM, c);
    c->k = (float *)malloc(4 * List_Nbr(ku) * sizeof(float));
    for(int i = 0; i < List_Nbr(ku); i++) {
      double d;
      List_Read(ku, i, &d);
      c->k[i] = (float)d /*((d-kumin)/(kumax-kumin)) */ ;
    }
  }
  List_Delete(Listint);

  List_Read(List, List_Nbr(List) - 1, &ListOfDouble_L);
  Listint = ListOfDouble2ListOfInt(ListOfDouble_L);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[2])) {
  }
  else {
    Loop[2] = NEWREG();
    Curve *c = Create_Curve(Loop[2], MSH_SEGM_NURBS, Order1, Listint, NULL, 
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(THEM, c);
    c->k = (float *)malloc(4 * List_Nbr(ku) * sizeof(float));
    for(int i = 0; i < List_Nbr(ku); i++) {
      double d;
      List_Read(ku, i, &d);
      c->k[i] = (float)d /*((d-kumin)/(kumax-kumin)) */ ;
    }
  }
  List_Delete(Listint);

  // 2nd and 4th gen
  List_T *List1 = List_Create(List_Nbr(List), 1, sizeof(double));
  List_T *List2 = List_Create(List_Nbr(List), 1, sizeof(double));
  for(int i = 0; i < List_Nbr(List); i++) {
    List_Read(List, i, &ListOfDouble_L);
    List_Add(List1, List_Pointer(ListOfDouble_L, 0));
    List_Add(List2, List_Pointer(ListOfDouble_L, List_Nbr(ListOfDouble_L) - 1));
  }

  Listint = ListOfDouble2ListOfInt(List1);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[1])) {
  }
  else {
    Loop[1] = NEWREG();
    Curve *c = Create_Curve(Loop[1], MSH_SEGM_NURBS, Order2, Listint, NULL, 
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(THEM, c);
    c->k = (float *)malloc(4 * List_Nbr(kv) * sizeof(float));
    for(int i = 0; i < List_Nbr(kv); i++) {
      double d;
      List_Read(kv, i, &d);
      c->k[i] = (float)d /*((d-kvmin)/(kvmax-kvmin)) */ ;
    }
  }
  List_Delete(Listint);

  Listint = ListOfDouble2ListOfInt(List2);
  if(recognize_seg(MSH_SEGM_NURBS, Listint, &Loop[3])) {
  }
  else {
    Loop[3] = NEWREG();
    Curve *c = Create_Curve(Loop[3], MSH_SEGM_NURBS, Order2, Listint, NULL,
			    -1, -1, kumin, kumax);
    Tree_Add(THEM->Curves, &c);
    CreateReversedCurve(THEM, c);
    c->k = (float *)malloc(4 * List_Nbr(kv) * sizeof(float));
    for(int i = 0; i < List_Nbr(kv); i++) {
      double d;
      List_Read(kv, i, &d);
      c->k[i] = (float)d /*((d-kvmin)/(kvmax-kvmin)) */ ;
    }
  }
  List_Delete(Listint);
  List_Delete(List1);
  List_Delete(List2);

  Listint = List_Create(10, 10, sizeof(int));
  int l0 = -Loop[0];
  List_Add(Listint, &l0);
  List_Add(Listint, &Loop[1]);
  List_Add(Listint, &Loop[2]);
  int l3 = -Loop[3];
  List_Add(Listint, &l3);

  int topnew = NEWREG();
  CreateNurbsSurfaceSupport(topnew, Order1, Order2, List, ku, kv);

  int il = NEWREG();
  SurfaceLoop *l = Create_SurfaceLoop(il, Listint);
  Tree_Add(THEM->SurfaceLoops, &l);
  List_Reset(Listint);
  List_Add(Listint, &il);

  Surface *s = Create_Surface(NEWREG(), MSH_SURF_TRIMMED);
  setSurfaceGeneratrices(s, Listint);
  s->Support = s;
  End_Surface(s);
  Tree_Add(THEM->Surfaces, &s);

  List_Delete(Listint);
  List_Delete(ListCP);
}

