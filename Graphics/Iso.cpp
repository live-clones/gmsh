// $Id: Iso.cpp,v 1.23 2004-05-08 00:19:47 geuzaine Exp $
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
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Views.h"
#include "Numeric.h"

extern Context_T CTX;

// Iso line computation for triangles.

void CutTriangle1D(double *X, double *Y, double *Z, double *Val,
                   double V, double *Xp, double *Yp, double *Zp, int *nb)
{
  *nb = 0;
  if((Val[0] >= V && Val[1] <= V) || (Val[1] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 1, &Xp[*nb], &Yp[*nb], &Zp[*nb]);
    (*nb)++;
  }
  if((Val[0] >= V && Val[2] <= V) || (Val[2] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 2, &Xp[*nb], &Yp[*nb], &Zp[*nb]);
    (*nb)++;
  }
  if((Val[1] >= V && Val[2] <= V) || (Val[2] >= V && Val[1] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 1, 2, &Xp[*nb], &Yp[*nb], &Zp[*nb]);
    (*nb)++;
  }

}

// Contour computation for triangles

void CutTriangle2D(double *X, double *Y, double *Z, double *Val,
                   double V1, double V2, double *Xp2, double *Yp2,
                   double *Zp2, int *Np2, double *Vp2)
{
  int i, io[3], j, iot, Np, Fl;
  double Xp[10], Yp[10], Zp[10], Vp[10];

  *Np2 = 0;

  for(i = 0; i < 3; i++)
    io[i] = i;

  for(i = 0; i < 2; i++) {
    for(j = i + 1; j < 3; j++) {
      if(Val[io[i]] > Val[io[j]]) {
        iot = io[i];
        io[i] = io[j];
        io[j] = iot;
      }
    }
  }

  // io[] contains an indexing of nodes such that Val[io[i]] > Val[io[j]] if i > j

  if(Val[io[0]] > V2)
    return;
  if(Val[io[2]] < V1)
    return;

  if(V1 <= Val[io[0]] && Val[io[2]] <= V2) {
    for(i = 0; i < 3; i++) {
      Vp2[i] = Val[i];
      Xp2[i] = X[i];
      Yp2[i] = Y[i];
      Zp2[i] = Z[i];
    }
    *Np2 = 3;
    return;
  }

  Np = 0;
  if(V1 <= Val[io[0]]) {
    Vp[Np] = Val[io[0]];
    Xp[Np] = X[io[0]];
    Yp[Np] = Y[io[0]];
    Zp[Np] = Z[io[0]];
    Np++;
    Fl = 1;
  }
  else if(Val[io[0]] < V1 && V1 <= Val[io[1]]) {
    Vp[Np] = V1;
    InterpolateIso(X, Y, Z, Val, V1, io[0], io[2], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
    Vp[Np] = V1;
    InterpolateIso(X, Y, Z, Val, V1, io[0], io[1], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
    Fl = 1;
  }
  else {
    Vp[Np] = V1;
    InterpolateIso(X, Y, Z, Val, V1, io[0], io[2], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
    Vp[Np] = V1;
    InterpolateIso(X, Y, Z, Val, V1, io[1], io[2], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
    Fl = 0;
  }

  if(V2 == Val[io[0]]) {
    return;
  }
  else if((Val[io[0]] < V2) && (V2 < Val[io[1]])) {
    Vp[Np] = V2;
    InterpolateIso(X, Y, Z, Val, V2, io[0], io[1], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
    Vp[Np] = V2;
    InterpolateIso(X, Y, Z, Val, V2, io[0], io[2], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
  }
  else if(V2 < Val[io[2]]) {
    if(Fl) {
      Vp[Np] = Val[io[1]];
      Xp[Np] = X[io[1]];
      Yp[Np] = Y[io[1]];
      Zp[Np] = Z[io[1]];
      Np++;
    }
    Vp[Np] = V2;
    InterpolateIso(X, Y, Z, Val, V2, io[1], io[2], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
    Vp[Np] = V2;
    InterpolateIso(X, Y, Z, Val, V2, io[0], io[2], &Xp[Np], &Yp[Np], &Zp[Np]);
    Np++;
  }
  else {
    if(Fl) {
      Vp[Np] = Val[io[1]];
      Xp[Np] = X[io[1]];
      Yp[Np] = Y[io[1]];
      Zp[Np] = Z[io[1]];
      Np++;
    }
    Vp[Np] = Val[io[2]];
    Xp[Np] = X[io[2]];
    Yp[Np] = Y[io[2]];
    Zp[Np] = Z[io[2]];
    Np++;
  }

  Vp2[0] = Vp[0];
  Xp2[0] = Xp[0];
  Yp2[0] = Yp[0];
  Zp2[0] = Zp[0];
  *Np2 = 1;

  for(i = 1; i < Np; i++) {
    if((Xp[i] != Xp2[(*Np2) - 1]) || (Yp[i] != Yp2[(*Np2) - 1]) || 
       (Zp[i] != Zp2[(*Np2) - 1])) {
      Vp2[*Np2] = Vp[i];
      Xp2[*Np2] = Xp[i];
      Yp2[*Np2] = Yp[i];
      Zp2[*Np2] = Zp[i];
      (*Np2)++;
    }
  }

  if(Xp2[0] == Xp2[(*Np2) - 1] && Yp2[0] == Yp2[(*Np2) - 1] && 
     Zp2[0] == Zp2[(*Np2) - 1]) {
    (*Np2)--;
  }

  // check and fix orientation
  double in1[3] = { X[1]-X[0], Y[1]-Y[0], Z[1]-Z[0]};
  double in2[3] = { X[2]-X[0], Y[2]-Y[0], Z[2]-Z[0]};
  double inn[3];
  prodve(in1, in2, inn);
  double out1[3] = { Xp2[1]-Xp2[0], Yp2[1]-Yp2[0], Zp2[1]-Zp2[0]};
  double out2[3] = { Xp2[2]-Xp2[0], Yp2[2]-Yp2[0], Zp2[2]-Zp2[0]};
  double outn[3];
  prodve(out1, out2, outn);
  double res;
  prosca(inn, outn, &res);
  if(res < 0){
    for(i = 0; i < *Np2; i++){
      Vp[i] = Vp2[*Np2-i-1];
      Xp[i] = Xp2[*Np2-i-1];
      Yp[i] = Yp2[*Np2-i-1];
      Zp[i] = Zp2[*Np2-i-1];
    }
    for(i = 0; i < *Np2; i++){
      Vp2[i] = Vp[i];
      Xp2[i] = Xp[i];
      Yp2[i] = Yp[i];
      Zp2[i] = Zp[i];
    }
  }
}

// Iso for lines

void CutLine0D(double *X, double *Y, double *Z, double *Val,
               double V, double *Xp, double *Yp, double *Zp, int *nb)
{
  *nb = 0;

  if((Val[0] >= V && Val[1] <= V) || (Val[1] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 1, Xp, Yp, Zp);
    *nb = 1;
  }
}

void CutLine1D(double *X, double *Y, double *Z, double *Val,
               double V1, double V2, double *Xp2, double *Yp2, double *Zp2,
               int *Np2, double *Vp2)
{
  int i, io[2];

  if(Val[0] < Val[1]) {
    io[0] = 0;
    io[1] = 1;
  }
  else {
    io[0] = 1;
    io[1] = 0;
  }

  // io[] contains an indexing of nodes such that Val[io[i]] > Val[io[j]] if i > j

  *Np2 = 0;

  if(Val[io[0]] > V2)
    return;
  if(Val[io[1]] < V1)
    return;

  *Np2 = 2;

  if(V1 <= Val[io[0]] && Val[io[1]] <= V2) {
    for(i = 0; i < 2; i++) {
      Vp2[i] = Val[i];
      Xp2[i] = X[i];
      Yp2[i] = Y[i];
      Zp2[i] = Z[i];
    }
    return;
  }

  if(V1 <= Val[io[0]]) {
    Vp2[0] = Val[io[0]];
    Xp2[0] = X[io[0]];
    Yp2[0] = Y[io[0]];
    Zp2[0] = Z[io[0]];
  }
  else {
    Vp2[0] = V1;
    InterpolateIso(X, Y, Z, Val, V1, io[0], io[1], &Xp2[0], &Yp2[0], &Zp2[0]);
  }

  if(V2 >= Val[io[1]]) {
    Vp2[1] = Val[io[1]];
    Xp2[1] = X[io[1]];
    Yp2[1] = Y[io[1]];
    Zp2[1] = Z[io[1]];
  }
  else {
    Vp2[1] = V2;
    InterpolateIso(X, Y, Z, Val, V2, io[0], io[1], &Xp2[1], &Yp2[1], &Zp2[1]);
  }

}

// compute the gradient of a linear interpolation in a tetrahedron

void EnhanceSimplexPolygon(Post_View * View, int nb,    // nb of points in polygon 
                           double *Xp,  // x positions
                           double *Yp,  // y positions
                           double *Zp,  // z positions
                           double *Valp,        // values at points
                           double *X,   // x positions of the simplex
                           double *Y,   // y positions of the simplex
                           double *Z,   // z posistions of the simplex
                           double *Val, // values at simplex points
                           double *norms,       // output : normals at points
                           int preproNormals    // do we compute normals or do we get them
  )
{
  /*
     3 possibilities for quads
     -) 0,2,5,3
     -) 0,1,5,4
     -) 1,2,4,3
     in all cases, simply invert the 2 last ones
     for having the quads ordered      
   */
  int i;
  double Xpi[6], Ypi[6], Zpi[6];

  if(nb == 4) {
    double xx = Xp[3];
    double yy = Yp[3];
    double zz = Zp[3];
    Xp[3] = Xp[2];
    Yp[3] = Yp[2];
    Zp[3] = Zp[2];
    Xp[2] = xx;
    Yp[2] = yy;
    Zp[2] = zz;
  }

  /*
     for having a nice isosurface, we should have n . grad v > 0
     n = normal to the polygon
     v = unknown field we wanna draw
   */

  if(!View->Light) {
    norms = NULL;       // we don't need to compute these
    return;
  }

  double v1[3] = { Xp[2] - Xp[0], Yp[2] - Yp[0], Zp[2] - Zp[0] };
  double v2[3] = { Xp[1] - Xp[0], Yp[1] - Yp[0], Zp[1] - Zp[0] };
  double gr[3];
  double n[3], xx;
  prodve(v1, v2, n);
  norme(n);
  gradSimplex(X, Y, Z, Val, gr);
  prosca(gr, n, &xx);

  if(xx > 0) {
    for(i = 0; i < nb; i++) {
      Xpi[i] = Xp[i];
      Ypi[i] = Yp[i];
      Zpi[i] = Zp[i];
    }
    for(i = 0; i < nb; i++) {
      Xp[i] = Xpi[nb - i - 1];
      Yp[i] = Ypi[nb - i - 1];
      Zp[i] = Zpi[nb - i - 1];
    }
  }
  else {
    n[0] = -n[0];
    n[1] = -n[1];
    n[2] = -n[2];
  }

  if(View->SmoothNormals) {
    if(preproNormals) {
      for(i = 0; i < nb; i++) {
        View->add_normal(Xp[i], Yp[i], Zp[i], n[0], n[1], n[2]);
      }
      return;
    }
    else {
      for(i = 0; i < nb; i++) {
        norms[3 * i] = n[0];
        norms[3 * i + 1] = n[1];
        norms[3 * i + 2] = n[2];
        if(!View->
           get_normal(Xp[i], Yp[i], Zp[i], norms[3 * i], norms[3 * i + 1],
                      norms[3 * i + 2])) {
          //Msg(WARNING, "Oups, did not find smoothed normal");
        }
      }
    }
  }
  else {
    for(i = 0; i < nb; i++) {
      norms[3 * i] = n[0];
      norms[3 * i + 1] = n[1];
      norms[3 * i + 2] = n[2];
    }
  }

}

void IsoSimplex(Post_View * View,
                int preproNormals,
                double *X, double *Y, double *Z, double *Val,
                double V)
{
  int nb;
  double Xp[6], Yp[6], Zp[6], PVals[6];
  double norms[12];

  nb = 0;
  if((Val[0] >= V && Val[1] <= V) || (Val[1] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 1, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[0] >= V && Val[2] <= V) || (Val[2] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 2, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[0] >= V && Val[3] <= V) || (Val[3] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 3, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[1] >= V && Val[2] <= V) || (Val[2] >= V && Val[1] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 1, 2, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[1] >= V && Val[3] <= V) || (Val[3] >= V && Val[1] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 1, 3, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[2] >= V && Val[3] <= V) || (Val[3] >= V && Val[2] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 2, 3, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }

  if(nb < 3 || nb > 4)
    return;

  EnhanceSimplexPolygon(View, nb, Xp, Yp, Zp, PVals, X, Y, Z, Val, norms,
                        preproNormals);

  if(preproNormals)
    return;

  double Raise[3][8];
  for(int i = 0; i < 3; i++)
    for(int k = 0; k < nb; k++)
      Raise[i][k] = View->Raise[i] * V;

  if(nb == 3)
    Draw_Triangle(Xp, Yp, Zp, norms, Raise, View->Light, false);
  else if(nb == 4)
    Draw_Quadrangle(Xp, Yp, Zp, norms, Raise, View->Light, false);
}
