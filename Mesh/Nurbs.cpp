// $Id: Nurbs.cpp,v 1.9 2002-05-18 16:31:16 geuzaine Exp $
//
// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

#include "Gmsh.h"
#include "Mesh.h"

// Cubic spline

Vertex InterpolateCubicSpline (Vertex * v[4], double t, double mat[4][4],
                               int derivee, double t1, double t2){
  Vertex V;
  int i, j;
  double vec[4], T[4];

  V.Pos.X = V.Pos.Y = V.Pos.Z = 0.0;
  V.lc = (1-t) * v[1]->lc + t * v[2]->lc;
  V.w = (1-t) * v[1]->w + t * v[2]->w;

  if (derivee){
    T[3] = 0.;
    T[2] = 1.;
    T[1] = 2. * t;
    T[0] = 3. * t * t;
  }
  else{
    T[3] = 1.;
    T[2] = t;
    T[1] = t * t;
    T[0] = t * t * t;
  }

  for (i = 0; i < 4; i++){
    vec[i] = 0.0;
  }
  
  /* X */
  for (i = 0; i < 4; i++){
      for (j = 0; j < 4; j++){
        vec[i] += mat[i][j] * v[j]->Pos.X;
      }
  }

  for (j = 0; j < 4; j++){
    V.Pos.X += T[j] * vec[j];
    vec[j] = 0.0;
  }

  /* Y */
  for (i = 0; i < 4; i++){
    for (j = 0; j < 4; j++){
      vec[i] += mat[i][j] * v[j]->Pos.Y;
    }
  }
  
  for (j = 0; j < 4; j++){
    V.Pos.Y += T[j] * vec[j];
    vec[j] = 0.0;
  }
  
  /* Z */
  for (i = 0; i < 4; i++){
    for (j = 0; j < 4; j++){
      vec[i] += mat[i][j] * v[j]->Pos.Z;
    }
  }
  for (j = 0; j < 4; j++){
    V.Pos.Z += T[j] * vec[j];
    vec[j] = 0.0;
  }
  
  if (derivee){
    V.Pos.X /= ((t2 - t1));
    V.Pos.Y /= ((t2 - t1));
    V.Pos.Z /= ((t2 - t1));
  }
  
  return V;
}


// Uniform BSplines

Vertex InterpolateUBS (Curve * Curve, double u, int derivee){

  int NbControlPoints, NbCurves, iCurve;
  double t, t1, t2;
  Vertex *v[4];

  NbControlPoints = List_Nbr (Curve->Control_Points);
  NbCurves = NbControlPoints - 3;

  iCurve = (int) (u * (double) NbCurves) + 1;

  if (iCurve > NbCurves)
    iCurve = NbCurves;

  t1 = (double) (iCurve - 1) / (double) (NbCurves);
  t2 = (double) (iCurve) / (double) (NbCurves);

  t = (u - t1) / (t2 - t1);

  List_Read (Curve->Control_Points, iCurve - 1, &v[0]);
  List_Read (Curve->Control_Points, iCurve, &v[1]);
  List_Read (Curve->Control_Points, iCurve + 1, &v[2]);
  List_Read (Curve->Control_Points, iCurve + 2, &v[3]);

  return InterpolateCubicSpline (v, t, Curve->mat, derivee, t1, t2);
}

// Non Uniform BSplines

int findSpan (double u, int deg, int n, float *U){
  if (u >= U[n])
    return n - 1;
  if (u <= U[0])
    return deg;

  int low = deg;
  int high = n + 1;
  int mid = (low + high) / 2;

  while (u < U[mid] || u >= U[mid + 1]){
    if (u < U[mid])
      high = mid;
    else
      low = mid;
    mid = (low + high) / 2;
  }
  return mid;
}

void basisFuns (double u, int i, int deg, float *U, double *N){

  double left[1000];
  double *right = &left[deg + 1];

  double temp, saved;

  //N.resize(deg+1) ;

  N[0] = 1.0;
  for (int j = 1; j <= deg; j++){
    left[j] = u - U[i + 1 - j];
    right[j] = U[i + j] - u;
    saved = 0.0;
    for (int r = 0; r < j; r++){
      temp = N[r] / (right[r + 1] + left[j - r]);
      N[r] = saved + right[r + 1] * temp;
      saved = left[j - r] * temp;
    }
    N[j] = saved;
  }
}

Vertex InterpolateNurbs (Curve * Curve, double u, int derivee){
  static double Nb[1000];
  int span = findSpan (u, Curve->degre, List_Nbr (Curve->Control_Points), Curve->k);
  Vertex p, *v;

  basisFuns (u, span, Curve->degre, Curve->k, Nb);
  p.Pos.X = p.Pos.Y = p.Pos.Z = p.w = p.lc = 0.0;
  for (int i = Curve->degre; i >= 0; --i){
    List_Read (Curve->Control_Points, span - Curve->degre + i, &v);
    p.Pos.X += Nb[i] * v->Pos.X;
    p.Pos.Y += Nb[i] * v->Pos.Y;
    p.Pos.Z += Nb[i] * v->Pos.Z;
    p.w += Nb[i] * v->w;
    p.lc += Nb[i] * v->lc;
  }
  return p;
}

Vertex InterpolateNurbsSurface (Surface * s, double u, double v){
  int uspan = findSpan (u, s->OrderU, s->Nu, s->ku);
  int vspan = findSpan (v, s->OrderV, s->Nv, s->kv);
  double Nu[1000], Nv[1000];
  Vertex sp, temp[1000], *pv;

  basisFuns (u, uspan, s->OrderU, s->ku, Nu);
  basisFuns (v, vspan, s->OrderV, s->kv, Nv);

  int l, ll, kk;
  for (l = 0; l <= s->OrderV; l++){
    temp[l].Pos.X = temp[l].Pos.Y = temp[l].Pos.Z = temp[l].w = temp[l].lc = 0.0;
    for (int k = 0; k <= s->OrderU; k++){
      kk = uspan - s->OrderU + k;
      ll = vspan - s->OrderV + l;
      List_Read (s->Control_Points, kk + s->Nu * ll, &pv);
      temp[l].Pos.X += Nu[k] * pv->Pos.X;
      temp[l].Pos.Y += Nu[k] * pv->Pos.Y;
      temp[l].Pos.Z += Nu[k] * pv->Pos.Z;
      temp[l].w += Nu[k] * pv->w;
      temp[l].lc += Nu[k] * pv->lc;
    }
  }
  sp.Pos.X = sp.Pos.Y = sp.Pos.Z = sp.w = sp.lc = 0.0;
  for (l = 0; l <= s->OrderV; l++){
    sp.Pos.X += Nv[l] * temp[l].Pos.X;
    sp.Pos.Y += Nv[l] * temp[l].Pos.Y;
    sp.Pos.Z += Nv[l] * temp[l].Pos.Z;
    sp.w += Nv[l] * temp[l].w;
    sp.lc += Nv[l] * temp[l].lc;
  }
  return sp;
}
