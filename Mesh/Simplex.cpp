// $Id: Simplex.cpp,v 1.47 2006-01-29 22:53:41 geuzaine Exp $
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
#include "Simplex.h"
#include "Context.h"

extern Context_T CTX;
extern Mesh *THEM;

extern Simplex MyNewBoundary;
extern int edges_tetra[6][2];

int FACE_DIMENSION = 2;

// Basic simplex (contains only pointers to the nodes)

SimplexBase::SimplexBase()
  : Element()
{
  V[0] = V[1] = V[2] = V[3] = NULL;
}

SimplexBase::SimplexBase(Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4)
  : Element()
{
  V[0] = v1; V[1] = v2; V[2] = v3; V[3] = v4;
}

double SimplexBase::Volume_Simplexe()
{
  double mat[3][3];

  if(V[3])
    return (matsimpl(mat) / 6.);
  else
    return (surfsimpl());
}

double SimplexBase::Volume_Simplexe2D()
{
  return ((V[1]->Pos.X - V[0]->Pos.X) *
          (V[2]->Pos.Y - V[1]->Pos.Y) -
          (V[2]->Pos.X - V[1]->Pos.X) * 
	  (V[1]->Pos.Y - V[0]->Pos.Y));
}

void SimplexBase::center_tet(double X[4], double Y[4], double Z[4], double res[3])
{
  double mat[3][3], b[3], dum;
  int i;
  b[0] = X[1] * X[1] - X[0] * X[0] +
    Y[1] * Y[1] - Y[0] * Y[0] + Z[1] * Z[1] - Z[0] * Z[0];
  b[1] = X[2] * X[2] - X[1] * X[1] +
    Y[2] * Y[2] - Y[1] * Y[1] + Z[2] * Z[2] - Z[1] * Z[1];
  b[2] = X[3] * X[3] - X[2] * X[2] +
    Y[3] * Y[3] - Y[2] * Y[2] + Z[3] * Z[3] - Z[2] * Z[2];

  for(i = 0; i < 3; i++)
    b[i] *= 0.5;

  mat[0][0] = X[1] - X[0];
  mat[0][1] = Y[1] - Y[0];
  mat[0][2] = Z[1] - Z[0];
  mat[1][0] = X[2] - X[1];
  mat[1][1] = Y[2] - Y[1];
  mat[1][2] = Z[2] - Z[1];
  mat[2][0] = X[3] - X[2];
  mat[2][1] = Y[3] - Y[2];
  mat[2][2] = Z[3] - Z[2];

  if(!sys3x3(mat, b, res, &dum)) {
    Msg(WARNING, "Coplanar points in circum sphere computation");
    Msg(WARNING, "(%g,%g,%g) (%g,%g,%g) (%g,%g,%g) (%g,%g,%g)",
        X[0], Y[0], Z[0], X[1], Y[1], Z[1], X[2], Y[2], Z[2], X[3], Y[3],
        Z[3]);
    res[0] = res[1] = res[2] = 10.0e10;
  }

}

double SimplexBase::matsimpl(double mat[3][3])
{
  mat[0][0] = V[1]->Pos.X - V[0]->Pos.X;
  mat[0][1] = V[2]->Pos.X - V[0]->Pos.X;
  mat[0][2] = V[3]->Pos.X - V[0]->Pos.X;
  mat[1][0] = V[1]->Pos.Y - V[0]->Pos.Y;
  mat[1][1] = V[2]->Pos.Y - V[0]->Pos.Y;
  mat[1][2] = V[3]->Pos.Y - V[0]->Pos.Y;
  mat[2][0] = V[1]->Pos.Z - V[0]->Pos.Z;
  mat[2][1] = V[2]->Pos.Z - V[0]->Pos.Z;
  mat[2][2] = V[3]->Pos.Z - V[0]->Pos.Z;
  return det3x3(mat);
}

double SimplexBase::AireFace(Vertex * V[3])
{
  double a[3], b[3], c[3];

  a[0] = V[2]->Pos.X - V[1]->Pos.X;
  a[1] = V[2]->Pos.Y - V[1]->Pos.Y;
  a[2] = V[2]->Pos.Z - V[1]->Pos.Z;

  b[0] = V[0]->Pos.X - V[1]->Pos.X;
  b[1] = V[0]->Pos.Y - V[1]->Pos.Y;
  b[2] = V[0]->Pos.Z - V[1]->Pos.Z;

  prodve(a, b, c);
  return (0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]));
}

double SimplexBase::surfsimpl()
{
  return AireFace(V);
}

double SimplexBase::rhoin()
{
  double s1, s2, s3, s4;

  if(V[3]) {
    Vertex *F[3];
    F[0] = V[0]; F[1] = V[1]; F[2] = V[2]; s1 = fabs(AireFace(F));
    F[0] = V[0]; F[1] = V[2]; F[2] = V[3]; s2 = fabs(AireFace(F));
    if(FACE_DIMENSION == 1) {
      V[0] = V[1]; V[1] = V[2]; V[2] = V[3]; s3 = fabs(AireFace(F));
      V[0] = V[0]; V[1] = V[1]; V[2] = V[3]; s4 = fabs(AireFace(F));
    }
    else {
      F[0] = V[0]; F[1] = V[1]; F[2] = V[3]; s3 = fabs(AireFace(F));
      F[0] = V[1]; F[1] = V[2]; F[2] = V[3]; s4 = fabs(AireFace(F));
    }
    return 3. * fabs(Volume_Simplexe()) / (s1 + s2 + s3 + s4);
  }
  else {
    return 1.0;
  }
}

double SimplexBase::maxEdge()
{
  double maxlij = 0.;
  int N = V[3] ? 6 : 3;

  if(V[3] || V[2])
    for(int i = 0; i < N; i++)
      maxlij = DMAX(maxlij, lij(V[edges_tetra[i][0]], V[edges_tetra[i][1]]));
  else if(V[1])
    maxlij = lij(V[0], V[1]);

  return maxlij;
}

double SimplexBase::minEdge()
{
  double minlij = 1.e25;
  int N = V[3] ? 6 : 3;

  if(V[3] || V[2])
    for(int i = 0; i < N; i++)
      minlij = DMIN(minlij, lij(V[edges_tetra[i][0]], V[edges_tetra[i][1]]));
  else if(V[1])
    minlij = lij(V[0], V[1]);

  return minlij;
}

double SimplexBase::EtaShapeMeasure()
{
  if(!V[3]) return 0.;

  double lij2 = 0.0;
  for(int i = 0; i <= 3; i++) {
    for(int j = i + 1; j <= 3; j++) {
      lij2 += DSQR(lij(V[i], V[j]));
    }
  }
  return 12. * pow(9. / 10. * DSQR(fabs(Volume_Simplexe())), 1./3.) / (lij2);
}

double SimplexBase::GammaShapeMeasure()
{
  if(!V[3]) return 0.;

  double maxlij = 0.0;
  for(int i = 0; i <= 3; i++) {
    for(int j = i + 1; j <= 3; j++) {
      if(i != j)
        maxlij = DMAX(maxlij, lij(V[i], V[j]));
    }
  }
  return 12. * rhoin() / (sqrt(6.) * maxlij);
}

void SimplexBase::ExportStatistics(FILE * f)
{
  int N = !V[2] ? 2 : (!V[3] ? 3 : 4);
  int NSUP = !VSUP ? 0 : (!V[2] ? 1 : (!V[3] ? 3 : 6));
  double g = GammaShapeMeasure();
  double e = EtaShapeMeasure();
  double r = RhoShapeMeasure();
  print_elm_stats(f, Num, iEnt, g, e, r, 
		  !V[2] ? "SL" : (!V[3] ? "ST" : "SS"), N, V, 
		  !V[2] ? "SL2" : (!V[3] ? "ST2" : "SS2"), NSUP, VSUP);
}

SimplexBase *Create_SimplexBase(Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4)
{
  return new SimplexBase(v1, v2, v3, v4);
}

void Free_SimplexBase(void *a, void *b)
{
  SimplexBase *s = *(SimplexBase **) a;
  if(s) {
    delete s;
    s = NULL;
  }
}

int compareSimplexBase(const void *a, const void *b)
{
  SimplexBase *q = *(SimplexBase **) a;
  SimplexBase *w = *(SimplexBase **) b;
  return (q->Num - w->Num);
}

// Mesh simplex (contains all the data necessary for mesh generation)

Simplex::Simplex()
  : SimplexBase()
{
  S[0] = S[1] = S[2] = S[3] = NULL;
  Quality = 0.;
}

Simplex::Simplex(Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4)
  : SimplexBase(v1, v2, v3, v4)
{
  S[0] = S[1] = S[2] = S[3] = NULL;
  Quality = 0.;
  Fourre_Simplexe(v1, v2, v3, v4);
}

int Simplex::CircumCircle(double x1, double y1, double x2, double y2,
                          double x3, double y3, double *xc, double *yc)
{
  double d, a1, a2, a3;

  d = 2. * (double)(y1 * (x2 - x3) + y2 * (x3 - x1) + y3 * (x1 - x2));
  if(d == 0.0) {
    *xc = *yc = -99999.;
    Msg(WARNING, "Degenerated simplex");
    return 0;
  }

  a1 = x1 * x1 + y1 * y1;
  a2 = x2 * x2 + y2 * y2;
  a3 = x3 * x3 + y3 * y3;
  *xc = (double)((a1 * (y3 - y2) + a2 * (y1 - y3) + a3 * (y2 - y1)) / d);
  *yc = (double)((a1 * (x2 - x3) + a2 * (x3 - x1) + a3 * (x1 - x2)) / d);

  return 1;
}

void Simplex::Center_Circum()
{
  /* Calcul du centre de la boule circonscrite */
  int i, N;
  double X[4], Y[4], Z[4];
  double res[3];

  if(!V[3])
    N = 3;
  else
    N = 4;

  for(i = 0; i < N; i++) {
    X[i] = V[i]->Pos.X;
    Y[i] = V[i]->Pos.Y;
    Z[i] = V[i]->Pos.Z;
  }

  if(N == 3) {
    CircumCircle(V[0]->Pos.X, V[0]->Pos.Y,
                 V[1]->Pos.X, V[1]->Pos.Y,
                 V[2]->Pos.X, V[2]->Pos.Y, &Center.X, &Center.Y);
    Center.Z = 0.0;
    if(fabs(Center.X) > 1.e10)
      Center.X = 1.e10;
    if(fabs(Center.Y) > 1.e10)
      Center.Y = 1.e10;
    Radius = sqrt((X[0] - Center.X) * (X[0] - Center.X) +
                  (Y[0] - Center.Y) * (Y[0] - Center.Y));
  }
  else {
    center_tet(X, Y, Z, res);

    Center.X = res[0];
    Center.Y = res[1];
    Center.Z = res[2];
    Radius = sqrt((X[0] - Center.X) * (X[0] - Center.X) +
                  (Y[0] - Center.Y) * (Y[0] - Center.Y) +
                  (Z[0] - Center.Z) * (Z[0] - Center.Z));
  }
}

int Simplex::Pt_In_Ellipse(Vertex * v, double Metric[3][3])
{
  double eps, d1, d2, x[2];

  Center_Ellipsum_2D(Metric);

  x[0] = Center.X - v->Pos.X;
  x[1] = Center.Y - v->Pos.Y;

  d1 = Radius;
  d2 = sqrt(x[0] * x[0] * Metric[0][0]
            + x[1] * x[1] * Metric[1][1]
            + 2. * x[0] * x[1] * Metric[0][1]);

  eps = fabs(d1 - d2) / (d1 + d2);
  if(eps < 1.e-12) {
    return (1); // Ou Zero ???
  }
  if(d2 < d1)
    return 1;
  return 0;

}

void Simplex::Fourre_Simplexe(Vertex * v1, Vertex * v2, Vertex * v3,
                              Vertex * v4)
{
  int i, N;
  V[0] = v1;
  V[1] = v2;
  V[2] = v3;
  V[3] = v4;
  VSUP = NULL;

  if(!v3) {
    F[0].V[0] = (v1->Num > v2->Num) ? v2 : v1;
    F[0].V[1] = (v1->Num > v2->Num) ? v1 : v2;
    F[0].V[2] = NULL;
    return;
  }

  F[0].V[0] = v1;
  F[0].V[1] = v2;
  F[0].V[2] = v3;

  F[1].V[0] = v1;
  F[1].V[1] = v3;
  F[1].V[2] = v4;
  if(FACE_DIMENSION == 1) {
    F[2].V[0] = v2;
    F[2].V[1] = v3;
    F[2].V[2] = v4;

    F[3].V[0] = v1;
    F[3].V[1] = v2;
    F[3].V[2] = v4;
  }
  else {
    F[2].V[0] = v1;
    F[2].V[1] = v2;
    F[2].V[2] = v4;

    F[3].V[0] = v2;
    F[3].V[1] = v3;
    F[3].V[2] = v4;
  }

  if(!v4) {
    N = 3;
    if(FACE_DIMENSION != 1) {
      qsort(F[0].V, 3, sizeof(Vertex *), compareVertex);
      return;
    }
  }
  else {
    N = 4;
  }

  Center_Circum();

  if(N == 4 && THEM && THEM->BackgroundMeshType == ONFILE){
    Quality = fabs(4. * Radius / BGMXYZ(Center.X, Center.Y, Center.Z));
  }
  else{
    Quality = (double)N *Radius / (V[0]->lc + V[1]->lc + V[2]->lc + 
				   ((V[3]) ? V[3]->lc : 0.0));
  }

  for(i = 0; i < N; i++)
    qsort(F[i].V, N - 1, sizeof(Vertex *), compareVertex);

  //qsort(F,N,sizeof(Face),compareFace);
}

Simplex *Create_Simplex(Vertex * v1, Vertex * v2, Vertex * v3, Vertex * v4)
{
  return new Simplex(v1, v2, v3, v4);
}

void Free_Simplex(void *a, void *b)
{
  Simplex *s = *(Simplex **) a;
  if(s) {
    delete s;
    s = NULL;
  }
}

int compareSimplex(const void *a, const void *b)
{
  Simplex *q = *(Simplex **) a;
  Simplex *w = *(Simplex **) b;
  return (q->Num - w->Num);
}

int compareSimplexBarycenter(const void *a, const void *b)
{
  Simplex *q = *(Simplex **) a;
  Simplex *w = *(Simplex **) b;
  int nq = q->V[3] ? 4 : q->V[2] ? 3 : q->V[1] ? 2 : 1;
  int nw = w->V[3] ? 4 : w->V[2] ? 3 : w->V[1] ? 2 : 1;
  double bq, bw, TOL = CTX.lc * 1.e-6;

  bq = bw = 0.;
  for(int i = 0; i < nq; i++) bq += q->V[i]->Pos.X;
  for(int i = 0; i < nw; i++) bw += w->V[i]->Pos.X;
  if(bq-bw > TOL) return 1; else if(bq-bw < -TOL) return -1;

  bq = bw = 0.;
  for(int i = 0; i < nq; i++) bq += q->V[i]->Pos.Y;
  for(int i = 0; i < nw; i++) bw += w->V[i]->Pos.Y;
  if(bq-bw > TOL) return 1; else if(bq-bw < -TOL) return -1;

  bq = bw = 0.;
  for(int i = 0; i < nq; i++) bq += q->V[i]->Pos.Z;
  for(int i = 0; i < nw; i++) bw += w->V[i]->Pos.Z;
  if(bq-bw > TOL) return 1; else if(bq-bw < -TOL) return -1;

  return 0;
}

int Simplex::Pt_In_Simplexe(Vertex * v, double uvw[3], double tol)
{
  double mat[3][3];
  double b[3], dum;

  matsimpl(mat);
  b[0] = v->Pos.X - V[0]->Pos.X;
  b[1] = v->Pos.Y - V[0]->Pos.Y;
  b[2] = v->Pos.Z - V[0]->Pos.Z;

  sys3x3(mat, b, uvw, &dum);
  if(uvw[0] >= -tol && uvw[1] >= -tol && uvw[2] >= -tol &&
     uvw[0] <= 1. + tol && uvw[1] <= 1. + tol && uvw[2] <= 1. + tol &&
     1. - uvw[0] - uvw[1] - uvw[2] > -tol) {
    return (1);
  }
  return (0);
}

void Simplex::Center_Ellipsum_2D(double m[3][3])
{
  double sys[2][2], x[2];
  double rhs[2], a, b, d;
  double x1, y1, x2, y2, x3, y3;

  x1 = V[0]->Pos.X;
  y1 = V[0]->Pos.Y;
  x2 = V[1]->Pos.X;
  y2 = V[1]->Pos.Y;
  x3 = V[2]->Pos.X;
  y3 = V[2]->Pos.Y;

  a = m[0][0];
  b = 0.5 * (m[0][1] + m[1][0]);
  d = m[1][1];

  sys[0][0] = 2. * a * (x1 - x2) + 2. * b * (y1 - y2);
  sys[0][1] = 2. * d * (y1 - y2) + 2. * b * (x1 - x2);
  sys[1][0] = 2. * a * (x1 - x3) + 2. * b * (y1 - y3);
  sys[1][1] = 2. * d * (y1 - y3) + 2. * b * (x1 - x3);

  rhs[0] =
    a * (x1 * x1 - x2 * x2) + d * (y1 * y1 - y2 * y2) + 2. * b * (x1 * y1 -
                                                                  x2 * y2);
  rhs[1] =
    a * (x1 * x1 - x3 * x3) + d * (y1 * y1 - y3 * y3) + 2. * b * (x1 * y1 -
                                                                  x3 * y3);

  sys2x2(sys, rhs, x);

  Center.X = x[0];
  Center.Y = x[1];

  Radius = sqrt((x[0] - x1) * (x[0] - x1) * a
                + (x[1] - y1) * (x[1] - y1) * d
                + 2. * (x[0] - x1) * (x[1] - y1) * b);
}

void Simplex::Center_Ellipsum_3D(double m[3][3])
{
  double sys[3][3], x[3];
  double rhs[3], det;
  double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

  x1 = V[0]->Pos.X;
  y1 = V[0]->Pos.Y;
  z1 = V[0]->Pos.Z;
  x2 = V[1]->Pos.X;
  y2 = V[1]->Pos.Y;
  z2 = V[1]->Pos.Z;
  x3 = V[2]->Pos.X;
  y3 = V[2]->Pos.Y;
  z3 = V[2]->Pos.Z;
  x4 = V[3]->Pos.X;
  y4 = V[3]->Pos.Y;
  z4 = V[3]->Pos.Z;

  sys[0][0] =
    2. * m[0][0] * (x1 - x2) + 2. * m[1][0] * (y1 - y2) + 2. * m[2][0] * (z1 -
                                                                          z2);
  sys[0][1] =
    2. * m[0][1] * (x1 - x2) + 2. * m[1][1] * (y1 - y2) + 2. * m[2][1] * (z1 -
                                                                          z2);
  sys[0][2] =
    2. * m[0][2] * (x1 - x2) + 2. * m[1][2] * (y1 - y2) + 2. * m[2][2] * (z1 -
                                                                          z2);

  sys[1][0] =
    2. * m[0][0] * (x1 - x3) + 2. * m[1][0] * (y1 - y3) + 2. * m[2][0] * (z1 -
                                                                          z3);
  sys[1][1] =
    2. * m[0][1] * (x1 - x3) + 2. * m[1][1] * (y1 - y3) + 2. * m[2][1] * (z1 -
                                                                          z3);
  sys[1][2] =
    2. * m[0][2] * (x1 - x3) + 2. * m[1][2] * (y1 - y3) + 2. * m[2][2] * (z1 -
                                                                          z3);

  sys[2][0] =
    2. * m[0][0] * (x1 - x4) + 2. * m[1][0] * (y1 - y4) + 2. * m[2][0] * (z1 -
                                                                          z4);
  sys[2][1] =
    2. * m[0][1] * (x1 - x4) + 2. * m[1][1] * (y1 - y4) + 2. * m[2][1] * (z1 -
                                                                          z4);
  sys[2][2] =
    2. * m[0][2] * (x1 - x4) + 2. * m[1][2] * (y1 - y4) + 2. * m[2][2] * (z1 -
                                                                          z4);

  rhs[0] = m[0][0] * (x1 * x1 - x2 * x2)
    + m[1][1] * (y1 * y1 - y2 * y2)
    + m[2][2] * (z1 * z1 - z2 * z2)
    + 2. * m[1][0] * (x1 * y1 - x2 * y2)
    + 2. * m[2][0] * (x1 * z1 - x2 * z2)
    + 2. * m[2][1] * (z1 * y1 - z2 * y2);
  rhs[1] = m[0][0] * (x1 * x1 - x3 * x3)
    + m[1][1] * (y1 * y1 - y3 * y3)
    + m[2][2] * (z1 * z1 - z3 * z3)
    + 2. * m[1][0] * (x1 * y1 - x3 * y3)
    + 2. * m[2][0] * (x1 * z1 - x3 * z3)
    + 2. * m[2][1] * (z1 * y1 - z3 * y3);
  rhs[2] = m[0][0] * (x1 * x1 - x4 * x4)
    + m[1][1] * (y1 * y1 - y4 * y4)
    + m[2][2] * (z1 * z1 - z4 * z4)
    + 2. * m[1][0] * (x1 * y1 - x4 * y4)
    + 2. * m[2][0] * (x1 * z1 - x4 * z4)
    + 2. * m[2][1] * (z1 * y1 - z4 * y4);

  sys3x3(sys, rhs, x, &det);

  Center.X = x[0];
  Center.Y = x[1];
  Center.Z = x[2];

  Radius = sqrt((x[0] - x1) * (x[0] - x1) * m[0][0]
                + (x[1] - y1) * (x[1] - y1) * m[1][1]
                + (x[2] - z1) * (x[2] - z1) * m[2][2]
                + 2. * (x[0] - x1) * (x[1] - y1) * m[0][1]
                + 2. * (x[0] - x1) * (x[2] - z1) * m[0][2]
                + 2. * (x[1] - y1) * (x[2] - z1) * m[1][2]);
}

int Simplex::Pt_In_Simplex_2D(Vertex * v)
{
  double Xmin, Xmax, Ymin, Ymax, Xtr[4], Ytr[4], A[2], B[2], X, Y, Signus[3];
  int i;

  X = v->Pos.X;
  Y = v->Pos.Y;
  Xtr[0] = Xmax = Xmin = V[0]->Pos.X;
  Xtr[3] = V[0]->Pos.X;
  Xtr[1] = V[1]->Pos.X;
  Xtr[2] = V[2]->Pos.X;
  Ytr[0] = Ymax = Ymin = V[0]->Pos.Y;
  Ytr[3] = V[0]->Pos.Y;
  Ytr[1] = V[1]->Pos.Y;
  Ytr[2] = V[2]->Pos.Y;

  for(i = 1; i < 3; i++) {
    Xmin = (Xtr[i] < Xmin) ? Xtr[i] : Xmin;
    Xmax = (Xtr[i] > Xmax) ? Xtr[i] : Xmax;
    Ymin = (Ytr[i] < Ymin) ? Ytr[i] : Ymin;
    Ymax = (Ytr[i] > Ymax) ? Ytr[i] : Ymax;
  }

  if(X > Xmax || X < Xmin || Y > Ymax || Y < Ymin)
    return (0);

  for(i = 0; i < 3; i++) {
    A[0] = Xtr[i + 1] - Xtr[i];
    A[1] = Ytr[i + 1] - Ytr[i];
    B[0] = X - Xtr[i];
    B[1] = Y - Ytr[i];
    Signus[i] = A[0] * B[1] - A[1] * B[0];
  }
  for(i = 0; i < 2; i++) {
    if((Signus[i] * Signus[i + 1]) < 0)
      return 0;
  }
  return 1;
}

bool Simplex::VertexIn(Vertex * v)
{
  if(!this || this == &MyNewBoundary)
    return false;
  int N = 4;
  if(!V[3])
    N = 3;
  for(int i = 0; i < N; i++)
    if(!compareVertex(&V[i], &v))
      return true;
  return false;
}

bool Simplex::EdgeIn(Vertex * v1, Vertex * v2, Vertex * v[2])
{
  if(!this || this == &MyNewBoundary)
    return false;
  int N = 4;
  if(!V[3])
    N = 3;
  int n = 0;
  for(int i = 0; i < N; i++) {
    if(compareVertex(&V[i], &v1) && compareVertex(&V[i], &v2)) {
      v[n++] = V[i];
      if(n > 2)
        return false;
    }
  }
  return true;
}

bool Simplex::ExtractOppositeEdges(int iFac, Vertex * p[2], Vertex * q[2])
{
  Simplex *s1 = this;
  if(!s1 || s1 == &MyNewBoundary || !s1->iEnt)
    return false;
  Simplex *s2 = s1->S[iFac];
  if(!s2 || s2 == &MyNewBoundary || !s2->iEnt)
    return false;
  int i, ip = 0, iq = 0;

  for(i = 0; i < 3; i++)
    if(s1->VertexIn(s2->V[i]))
      p[ip++] = s2->V[i];
    else
      q[iq++] = s2->V[i];

  for(i = 0; i < 3; i++)
    if(!s2->VertexIn(s1->V[i]))
      q[iq++] = s1->V[i];

  if(ip != 2 || iq != 2) {
    return false;
  }
  return true;
}

bool Simplex::SwapEdge(int iFac)
{
  Simplex *s1 = NULL, *s2 = NULL, *s11 = NULL, *s21 = NULL;
  Vertex *p[4] = { NULL, NULL, NULL, NULL };
  Vertex *q[4] = { NULL, NULL, NULL, NULL };
  int i, ip, iq;

  s1 = this;
  if(!s1 || s1 == &MyNewBoundary || !s1->iEnt)
    return false;
  s2 = s1->S[iFac];
  if(!s2 || s2 == &MyNewBoundary || !s2->iEnt)
    return false;
  ip = iq = 0;

  for(i = 0; i < 3; i++)
    if(s1->VertexIn(s2->V[i]))
      p[ip++] = s2->V[i];
    else
      q[iq++] = s2->V[i];

  for(i = 0; i < 3; i++)
    if(!s2->VertexIn(s1->V[i]))
      q[iq++] = s1->V[i];

  if(ip != 2 || iq != 2) {
    return false;
  }

  for(i = 0; i < 3; i++)
    if(s1->S[i]->VertexIn(p[1]) && s1->S[i]->VertexIn(q[1]))
      s11 = s1->S[i];

  for(i = 0; i < 3; i++)
    if(s2->S[i]->VertexIn(p[0]) && s2->S[i]->VertexIn(q[0]))
      s21 = s2->S[i];

  if(!s11 || !s21)
    return false;

  double vol1 = s1->Volume_Simplexe() + s2->Volume_Simplexe();

  s1->V[0] = p[0];
  s1->V[1] = q[0];
  s1->V[2] = q[1];
  s2->V[0] = p[1];
  s2->V[1] = q[0];
  s2->V[2] = q[1];

  double vol2 = s1->Volume_Simplexe() + s2->Volume_Simplexe();

  if(s1->Volume_Simplexe() == 0.0 || s2->Volume_Simplexe() == 0.0 ||
     fabs(fabs(vol1) - fabs(vol2)) > 1.e-5 * (fabs(vol1) + fabs(vol2))) {
    s1->V[0] = p[0];
    s1->V[1] = p[1];
    s1->V[2] = q[1];
    s2->V[0] = p[0];
    s2->V[1] = p[1];
    s2->V[2] = q[0];
    return false;
  }

  for(i = 0; i < 3; i++)
    if(s1->S[i] == s11)
      s1->S[i] = s21;
  for(i = 0; i < 3; i++)
    if(s2->S[i] == s21)
      s2->S[i] = s11;

  if(s21 != &MyNewBoundary && s21 && s21->iEnt)
    for(i = 0; i < 3; i++)
      if(s21->S[i] == s2)
        s21->S[i] = s1;
  if(s11 != &MyNewBoundary && s11 && s11->iEnt)
    for(i = 0; i < 3; i++)
      if(s11->S[i] == s1)
        s11->S[i] = s2;
  return true;
}

bool Simplex::SwapFace(int iFac, List_T * newsimp, List_T * delsimp)
{
  Simplex *s = S[iFac], *s1, *s2, *s3;
  Vertex *o[2] = {NULL, NULL};
  int i;

  if(!s || s == &MyNewBoundary || !s->iEnt)
    return false;
  if(!this || this == &MyNewBoundary || !this->iEnt)
    return false;

  for(i = 0; i < 4; i++)
    if(!VertexIn(s->V[i]))
      o[0] = s->V[i];
  for(i = 0; i < 4; i++)
    if(!s->VertexIn(V[i]))
      o[1] = V[i];

  s1 = Create_Simplex(s->F[iFac].V[0], s->F[iFac].V[1], o[0], o[1]);
  s2 = Create_Simplex(s->F[iFac].V[1], s->F[iFac].V[2], o[0], o[1]);
  s3 = Create_Simplex(s->F[iFac].V[2], s->F[iFac].V[0], o[0], o[1]);

  double vol1 = s->Volume_Simplexe() + Volume_Simplexe();
  double vol2 = s1->Volume_Simplexe() + s2->Volume_Simplexe() + s3->Volume_Simplexe();

  if(fabs(fabs(vol1) - fabs(vol2)) > 1.e-5 * (fabs(vol1) + fabs(vol2))) {
    delete s1;
    delete s2;
    delete s3;
    return false;
  }

  double gamma1 = GammaShapeMeasure();

  if(s1->GammaShapeMeasure() < gamma1 ||
     s2->GammaShapeMeasure() < gamma1 || 
     s3->GammaShapeMeasure() < gamma1)
    return false;

  return true;
}

// Transfer SimplexBase to Simplex

static Tree_T *simptree = NULL;

void Copy_SimplexBaseToSimplex(void *a, void *b)
{
  SimplexBase *base = *(SimplexBase**)a;
  Simplex *s = Create_Simplex(base->V[0], base->V[1], base->V[2], base->V[3]);
  s->iEnt = base->iEnt;
  s->Num = base->Num;
  s->iPart = base->iPart;
  s->Visible = base->Visible;
  if(base->VSUP){
    int ns;
    if(base->V[3])
      ns = 6;
    else if(base->V[2])
      ns = 3;
    else if(base->V[1])
      ns = 1;
    else
      ns = 0;
    if(ns){
      s->VSUP = (Vertex **) Malloc(ns * sizeof(Vertex *));
      memcpy(s->VSUP, base->VSUP, ns * sizeof(Vertex *));
    }
  }
  Tree_Insert(simptree, &s);
}

void Move_SimplexBaseToSimplex(Tree_T **base, Tree_T *simp)
{
  if(!Tree_Nbr(*base)) return;
  simptree = simp;
  Tree_Action(*base, Copy_SimplexBaseToSimplex);
  Tree_Action(*base, Free_SimplexBase);
  Tree_Delete(*base);
  *base = Tree_Create(sizeof(SimplexBase *), compareSimplexBase);
}

