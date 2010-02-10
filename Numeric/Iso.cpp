// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "Numeric.h"

static void affect(double *xi, double *yi, double *zi, int i,
                   double *xp, double *yp, double *zp, int j)
{
  xi[i] = xp[j];
  yi[i] = yp[j];
  zi[i] = zp[j];
}

double InterpolateIso(double *X, double *Y, double *Z,
                      double *Val, double V, int I1, int I2,
                      double *XI, double *YI, double *ZI)
{
  if(Val[I1] == Val[I2]) {
    *XI = X[I1];
    *YI = Y[I1];
    *ZI = Z[I1];
    return 0;
  }
  else {
    double coef = (V - Val[I1]) / (Val[I2] - Val[I1]);
    *XI = coef * (X[I2] - X[I1]) + X[I1];
    *YI = coef * (Y[I2] - Y[I1]) + Y[I1];
    *ZI = coef * (Z[I2] - Z[I1]) + Z[I1];
    return coef;
  }
}

// Compute an iso-point in a line

int IsoLine(double *X, double *Y, double *Z, double *Val, double V,
            double *Xp, double *Yp, double *Zp)
{
  if(Val[0] == Val[1])
    return 0;

  if((Val[0] >= V && Val[1] <= V) || (Val[1] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 1, Xp, Yp, Zp);
    return 1;
  }
  return 0;
}

// Compute an iso-line inside a triangle

int IsoTriangle(double *X, double *Y, double *Z, double *Val, double V, 
                double *Xp, double *Yp, double *Zp)
{
  if(Val[0] == Val[1] && Val[0] == Val[2]) return 0;

  int nb = 0;
  if((Val[0] >= V && Val[1] <= V) || (Val[1] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 1, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[0] >= V && Val[2] <= V) || (Val[2] >= V && Val[0] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 0, 2, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  if((Val[1] >= V && Val[2] <= V) || (Val[2] >= V && Val[1] <= V)) {
    InterpolateIso(X, Y, Z, Val, V, 1, 2, &Xp[nb], &Yp[nb], &Zp[nb]);
    nb++;
  }
  
  if(nb == 2) return 2;
  return 0;
}

// Compute an iso-polygon inside a tetrahedron

int IsoSimplex(double *X, double *Y, double *Z, double *Val, double V,
               double *Xp, double *Yp, double *Zp, double n[3])
{
  if(Val[0] == Val[1] && Val[0] == Val[2] && Val[0] == Val[3])
    return 0;

  int nb = 0;
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

  // Remove identical nodes (this can happen if an edge belongs to the
  // zero levelset). We should be doing this even for nb < 4, but it
  // would slow us down even more (and we don't really care if some
  // nodes in a postprocessing element are identical)
  if(nb > 4) {
    double xi[6], yi[6], zi[6];
    affect(xi, yi, zi, 0, Xp, Yp, Zp, 0);
    int ni = 1;
    for(int j = 1; j < nb; j++) {
      for(int i = 0; i < ni; i++) {
        if(fabs(Xp[j] - xi[i]) < 1.e-12 &&
           fabs(Yp[j] - yi[i]) < 1.e-12 &&
           fabs(Zp[j] - zi[i]) < 1.e-12) {
          break;
        }
        if(i == ni - 1) {
          affect(xi, yi, zi, i + 1, Xp, Yp, Zp, j);
          ni++;
        }
      }
    }
    for(int i = 0; i < ni; i++)
      affect(Xp, Yp, Zp, i, xi, yi, zi, i);
    nb = ni;
  }

  if(nb < 3 || nb > 4)
    return 0;

  // 3 possible quads at this point: (0,2,5,3), (0,1,5,4) or
  // (1,2,4,3), so simply invert the 2 last vertices for having the
  // quad ordered
  if(nb == 4) {
    double x = Xp[3], y = Yp[3], z = Zp[3];
    Xp[3] = Xp[2];
    Yp[3] = Yp[2];
    Zp[3] = Zp[2];
    Xp[2] = x;
    Yp[2] = y;
    Zp[2] = z;
  }

  // to get a nice isosurface, we should have n . grad v > 0, where n
  // is the normal to the polygon and v is the unknown field we want
  // to draw
  double v1[3] = {Xp[2] - Xp[0], Yp[2] - Yp[0], Zp[2] - Zp[0]};
  double v2[3] = {Xp[1] - Xp[0], Yp[1] - Yp[0], Zp[1] - Zp[0]};
  prodve(v1, v2, n);
  norme(n);

  double g[3];
  gradSimplex(X, Y, Z, Val, g);

  double gdotn;
  prosca(g, n, &gdotn);

  if(gdotn > 0.) {
    double Xpi[6], Ypi[6], Zpi[6];
    for(int i = 0; i < nb; i++) {
      Xpi[i] = Xp[i];
      Ypi[i] = Yp[i];
      Zpi[i] = Zp[i];
    }
    for(int i = 0; i < nb; i++) {
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

  return nb;
}

// Compute the line between the two iso-points V1 and V2 in a line

int CutLine(double *X, double *Y, double *Z, double *Val,
            double V1, double V2, 
            double *Xp2, double *Yp2, double *Zp2, double *Vp2)
{
  int io[2];
  if(Val[0] < Val[1]) {
    io[0] = 0;
    io[1] = 1;
  }
  else {
    io[0] = 1;
    io[1] = 0;
  }

  if(Val[io[0]] > V2 || Val[io[1]] < V1) return 0;

  if(V1 <= Val[io[0]] && Val[io[1]] <= V2) {
    for(int i = 0; i < 2; i++) {
      Vp2[i] = Val[i];
      Xp2[i] = X[i];
      Yp2[i] = Y[i];
      Zp2[i] = Z[i];
    }
    return 2;
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

  return 2;
}

// Compute the polygon between the two iso-lines V1 and V2 in a
// triangle

int CutTriangle(double *X, double *Y, double *Z, double *Val,
                double V1, double V2, 
                double *Xp2, double *Yp2, double *Zp2, double *Vp2)
{
  // fill io so that it contains an indexing of the nodes such that
  // Val[io[i]] > Val[io[j]] if i > j
  int io[3] = {0, 1, 2};
  for(int i = 0; i < 2; i++) {
    for(int j = i + 1; j < 3; j++) {
      if(Val[io[i]] > Val[io[j]]) {
        int iot = io[i];
        io[i] = io[j];
        io[j] = iot;
      }
    }
  }

  if(Val[io[0]] > V2 || Val[io[2]] < V1) return 0;

  if(V1 <= Val[io[0]] && Val[io[2]] <= V2) {
    for(int i = 0; i < 3; i++) {
      Vp2[i] = Val[i];
      Xp2[i] = X[i];
      Yp2[i] = Y[i];
      Zp2[i] = Z[i];
    }
    return 3;
  }

  int Np = 0, Fl = 0;
  double Xp[10], Yp[10], Zp[10], Vp[10];

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
    return 0;
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

  int Np2 = 1;

  for(int i = 1; i < Np; i++) {
    if((Xp[i] != Xp2[Np2 - 1]) || (Yp[i] != Yp2[Np2 - 1]) || 
       (Zp[i] != Zp2[Np2 - 1])){
      Vp2[Np2] = Vp[i];
      Xp2[Np2] = Xp[i];
      Yp2[Np2] = Yp[i];
      Zp2[Np2] = Zp[i];
      Np2++;
    }
  }

  if(Xp2[0] == Xp2[Np2 - 1] && Yp2[0] == Yp2[Np2 - 1] && 
     Zp2[0] == Zp2[Np2 - 1]) {
    Np2--;
  }

  // check and fix orientation
  double in1[3] = {X[1] - X[0], Y[1] - Y[0], Z[1] - Z[0]};
  double in2[3] = {X[2] - X[0], Y[2] - Y[0], Z[2] - Z[0]};
  double inn[3];
  prodve(in1, in2, inn);
  double out1[3] = {Xp2[1] - Xp2[0], Yp2[1] - Yp2[0], Zp2[1] - Zp2[0]};
  double out2[3] = {Xp2[2] - Xp2[0], Yp2[2] - Yp2[0], Zp2[2] - Zp2[0]};
  double outn[3];
  prodve(out1, out2, outn);
  double res;
  prosca(inn, outn, &res);
  if(res < 0){
    for(int i = 0; i < Np2; i++){
      Vp[i] = Vp2[Np2 - i - 1];
      Xp[i] = Xp2[Np2 - i - 1];
      Yp[i] = Yp2[Np2 - i - 1];
      Zp[i] = Zp2[Np2 - i - 1];
    }
    for(int i = 0; i < Np2; i++){
      Vp2[i] = Vp[i];
      Xp2[i] = Xp[i];
      Yp2[i] = Yp[i];
      Zp2[i] = Zp[i];
    }
  }

  return Np2;
}
