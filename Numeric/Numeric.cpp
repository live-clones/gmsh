// $Id: Numeric.cpp,v 1.34 2007-10-25 08:55:07 geuzaine Exp $
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

// this file should contain only purely numerical routines (that do
// not depend on any Gmsh structures)

#include "Gmsh.h"
#include "Numeric.h"

// Check GSL version. We need at least 1.2, since all versions <=
// 1.1.1 have a buggy SVD routine (infinite loop fixed on Sun Jun 16
// 11:45:29 2002 in GSL's cvs tree). We check this at run time since
// Gmsh could be distributed with the gsl dynamically linked.

#if defined(HAVE_GSL)

#include <gsl/gsl_version.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>

void new_handler(const char *reason, const char *file, int line,
                 int gsl_errno)
{
  Msg(GERROR, "GSL: %s (%s, line %d)", reason, file, line);
}

int check_gsl()
{
  // check version
  int major, minor;
  if(!sscanf(gsl_version, "%d.%d", &major, &minor)){
    Msg(FATAL, "Cannot retreive GSL version");
    return 0;
  }
  if(major < 1 || (major == 1 && minor < 2)) {
    Msg(FATAL1, "Your GSL version (%d.%d.X) has a bug in the singular value",
        major, minor);
    Msg(FATAL2, "decomposition code. Please upgrade to version 1.2 or above.");
    Msg(FATAL3, "You can download the GSL from http://sources.redhat.com/gsl/");
    return 0;
  }
  // set new error handler
  gsl_set_error_handler(&new_handler);

  // initilize robust geometric predicates
  gmsh::exactinit() ;
  return 1;
}

#else

#define NRANSI
#include "nrutil.h"
void dsvdcmp(double **a, int m, int n, double w[], double **v);
int check_gsl()
{
  // initilize robust geometric predicates
  gmsh::exactinit() ;
  return 1;
}

#endif

double myatan2(double a, double b)
{
  if(a == 0.0 && b == 0)
    return 0.0;
  return atan2(a, b);
}

double myasin(double a)
{
  if(a <= -1.)
    return -Pi / 2.;
  else if(a >= 1.)
    return Pi / 2.;
  else
    return asin(a);
}

double myacos(double a)
{
  if(a <= -1.)
    return Pi;
  else if(a >= 1.)
    return 0.;
  else
    return acos(a);
}

void prodve(double a[3], double b[3], double c[3])
{
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

void matvec(double mat[3][3], double vec[3], double res[3])
{
  res[0] = mat[0][0] * vec[0] + mat[0][1] * vec[1] + mat[0][2] * vec[2];
  res[1] = mat[1][0] * vec[0] + mat[1][1] * vec[1] + mat[1][2] * vec[2];
  res[2] = mat[2][0] * vec[0] + mat[2][1] * vec[1] + mat[2][2] * vec[2];
}

void prosca(double a[3], double b[3], double *c)
{
  *c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double norm3(double a[3])
{
  return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}

double norme(double a[3])
{
  double mod = norm3(a);
  if(mod != 0.0){
    a[0] /= mod;
    a[1] /= mod;
    a[2] /= mod;
  }
  return mod;
}

void normal3points(double x0, double y0, double z0,
		   double x1, double y1, double z1,
		   double x2, double y2, double z2,
		   double n[3])
{
  double t1[3] = {x1 - x0, y1 - y0, z1 - z0};
  double t2[3] = {x2 - x0, y2 - y0, z2 - z0};
  prodve(t1, t2, n);
  norme(n);
}

int sys2x2(double mat[2][2], double b[2], double res[2])
{
  double det, ud, norm;
  int i;

  norm = DSQR(mat[0][0]) + DSQR(mat[1][1]) + DSQR(mat[0][1]) + DSQR(mat[1][0]);
  det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];


  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || fabs(det) / norm < 1.e-12) {
    if(norm)
      Msg(DEBUG, "Assuming 2x2 matrix is singular (det/norm == %.16g)",
          fabs(det) / norm);
    res[0] = res[1] = 0.0;
    return 0;
  }
  ud = 1. / det;

  res[0] = b[0] * mat[1][1] - mat[0][1] * b[1];
  res[1] = mat[0][0] * b[1] - mat[1][0] * b[0];

  for(i = 0; i < 2; i++)
    res[i] *= ud;

  return (1);
}

double det3x3(double mat[3][3])
{
  return (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
	  mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
	  mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
}

double trace3x3(double mat[3][3])
{
  return mat[0][0] + mat[1][1] + mat[2][2];
}

double trace2 (double mat[3][3])
{
  double a00 =  mat[0][0] * mat[0][0] + mat[1][0] * mat[0][1] + mat[2][0] * mat[0][2]; 
  double a11 =  mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1] + mat[1][2] * mat[2][1]; 
  double a22 =  mat[2][0] * mat[0][2] + mat[2][1] * mat[1][2] + mat[2][2] * mat[2][2];
  
  return a00 + a11 + a22;
}

int sys3x3(double mat[3][3], double b[3], double res[3], double *det)
{
  double ud;
  int i;

  *det = det3x3(mat);

  if(*det == 0.0) {
    res[0] = res[1] = res[2] = 0.0;
    return (0);
  }

  ud = 1. / (*det);

  res[0] = b[0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
    mat[0][1] * (b[1] * mat[2][2] - mat[1][2] * b[2]) +
    mat[0][2] * (b[1] * mat[2][1] - mat[1][1] * b[2]);

  res[1] = mat[0][0] * (b[1] * mat[2][2] - mat[1][2] * b[2]) -
    b[0] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
    mat[0][2] * (mat[1][0] * b[2] - b[1] * mat[2][0]);

  res[2] = mat[0][0] * (mat[1][1] * b[2] - b[1] * mat[2][1]) -
    mat[0][1] * (mat[1][0] * b[2] - b[1] * mat[2][0]) +
    b[0] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

  for(i = 0; i < 3; i++)
    res[i] *= ud;
  return (1);

}

int sys3x3_with_tol(double mat[3][3], double b[3], double res[3], double *det)
{
  int out;
  double norm;

  out = sys3x3(mat, b, res, det);
  norm =
    DSQR(mat[0][0]) + DSQR(mat[0][1]) + DSQR(mat[0][2]) +
    DSQR(mat[1][0]) + DSQR(mat[1][1]) + DSQR(mat[1][2]) +
    DSQR(mat[2][0]) + DSQR(mat[2][1]) + DSQR(mat[2][2]);

  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || fabs(*det) / norm < 1.e-12) {
    if(norm)
      Msg(DEBUG, "Assuming 3x3 matrix is singular (det/norm == %.16g)",
          fabs(*det) / norm);
    res[0] = res[1] = res[2] = 0.0;
    return 0;
  }

  return out;
}

double det2x2(double mat[2][2])
{
  return mat[0][0] *mat[1][1] -mat[1][0] *mat[0][1];
}

double inv2x2(double mat[2][2], double inv[2][2])
{
  const double det = det2x2 ( mat );
  if(det){
    double ud = 1. / det;
    inv[0][0] =  ( mat[1][1] ) * ud ;
    inv[1][0] = -( mat[1][0] ) * ud ;
    inv[0][1] = -( mat[0][1] ) * ud ;
    inv[1][1] =  ( mat[0][0] ) * ud ;
  }
  else{
    Msg(GERROR, "Singular matrix");
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
	inv[i][j] = 0.;
  }
  return det;
}

double inv3x3(double mat[3][3], double inv[3][3])
{
  double det = det3x3(mat);
  if(det){
    double ud = 1. / det;
    inv[0][0] =  ( mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1] ) * ud ;
    inv[1][0] = -( mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0] ) * ud ;
    inv[2][0] =  ( mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0] ) * ud ;
    inv[0][1] = -( mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1] ) * ud ;
    inv[1][1] =  ( mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0] ) * ud ;
    inv[2][1] = -( mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0] ) * ud ;
    inv[0][2] =  ( mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1] ) * ud ;
    inv[1][2] = -( mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0] ) * ud ;
    inv[2][2] =  ( mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] ) * ud ;
  }
  else{
    Msg(GERROR, "Singular matrix");
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	inv[i][j] = 0.;
  }
  return det;
}

void invert_singular_matrix3x3(double MM[3][3], double II[3][3])
{
  int i, j, k, n = 3;
  double TT[3][3];

  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      II[i - 1][j - 1] = 0.0;
      TT[i - 1][j - 1] = 0.0;
    }
  }

#if defined(HAVE_GSL)
  gsl_matrix *M = gsl_matrix_alloc(3, 3);
  gsl_matrix *V = gsl_matrix_alloc(3, 3);
  gsl_vector *W = gsl_vector_alloc(3);
  gsl_vector *TMPVEC = gsl_vector_alloc(3);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      gsl_matrix_set(M, i - 1, j - 1, MM[i - 1][j - 1]);
    }
  }
  gsl_linalg_SV_decomp(M, V, W, TMPVEC);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      double ww = gsl_vector_get(W, i - 1);
      if(fabs(ww) > 1.e-16) {   //singular value precision
        TT[i - 1][j - 1] += gsl_matrix_get(M, j - 1, i - 1) / ww;
      }
    }
  }
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      for(k = 1; k <= n; k++) {
        II[i - 1][j - 1] +=
          gsl_matrix_get(V, i - 1, k - 1) * TT[k - 1][j - 1];
      }
    }
  }
  gsl_matrix_free(M);
  gsl_matrix_free(V);
  gsl_vector_free(W);
  gsl_vector_free(TMPVEC);
#else
  double **M = dmatrix(1, 3, 1, 3);
  double **V = dmatrix(1, 3, 1, 3);
  double *W = dvector(1, 3);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      M[i][j] = MM[i - 1][j - 1];
    }
  }
  dsvdcmp(M, n, n, W, V);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      if(fabs(W[i]) > 1.e-16) { //singular value precision
        TT[i - 1][j - 1] += M[j][i] / W[i];
      }
    }
  }
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      for(k = 1; k <= n; k++) {
        II[i - 1][j - 1] += V[i][k] * TT[k - 1][j - 1];
      }
    }
  }
  free_dmatrix(M, 1, n, 1, n);
  free_dmatrix(V, 1, n, 1, n);
  free_dvector(W, 1, n);
#endif
}

double angle_02pi(double A3)
{
  double DP = 2 * Pi;
  while(A3 > DP || A3 < 0.) {
    if(A3 > 0)
      A3 -= DP;
    else
      A3 += DP;
  }
  return A3;
}

double angle_plan(double V[3], double P1[3], double P2[3], double n[3])
{
  double PA[3], PB[3], angplan;
  double cosc, sinc, c[3];

  PA[0] = P1[0] - V[0];
  PA[1] = P1[1] - V[1];
  PA[2] = P1[2] - V[2];

  PB[0] = P2[0] - V[0];
  PB[1] = P2[1] - V[1];
  PB[2] = P2[2] - V[2];

  norme(PA);
  norme(PB);

  prodve(PA, PB, c);

  prosca(PA, PB, &cosc);
  prosca(c, n, &sinc);
  angplan = myatan2(sinc, cosc);

  return angplan;
}

double triangle_area(double p0[3], double p1[3], double p2[3])
{
  double a[3], b[3], c[3];
  
  a[0] = p2[0] - p1[0];
  a[1] = p2[1] - p1[1];
  a[2] = p2[2] - p1[2];
  
  b[0] = p0[0] - p1[0];
  b[1] = p0[1] - p1[1];
  b[2] = p0[2] - p1[2];
  
  prodve(a, b, c);
  return (0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]));
}

char float2char(float f)
{
  // f is supposed to be normalized in [-1, 1]
  f = (f > 1.) ? 1. : (f < -1.) ? -1. : f;
  // char is in [-128, 127]
  return (char)(-128 + (f + 1.) / 2. * 255);
}

float char2float(char c)
{
  float f = c;
  return -1. + 2. * (f + 128.) / 255.;
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

void gradSimplex(double *x, double *y, double *z, double *v, double *grad)
{
  // p = p1 * (1-u-v-w) + p2 u + p3 v + p4 w

  double mat[3][3];
  double det, b[3];
  mat[0][0] = x[1] - x[0];
  mat[1][0] = x[2] - x[0];
  mat[2][0] = x[3] - x[0];
  mat[0][1] = y[1] - y[0];
  mat[1][1] = y[2] - y[0];
  mat[2][1] = y[3] - y[0];
  mat[0][2] = z[1] - z[0];
  mat[1][2] = z[2] - z[0];
  mat[2][2] = z[3] - z[0];
  b[0] = v[1] - v[0];
  b[1] = v[2] - v[0];
  b[2] = v[3] - v[0];
  sys3x3(mat, b, grad, &det);
}

double ComputeVonMises(double *V)
{
  double tr = (V[0] + V[4] + V[8]) / 3.;
  double v11 = V[0] - tr, v12 = V[1],      v13 = V[2];
  double v21 = V[3],      v22 = V[4] - tr, v23 = V[5];
  double v31 = V[6],      v32 = V[7],      v33 = V[8] - tr;
  return sqrt(1.5 * (v11 * v11 + v12 * v12 + v13 * v13 +
                     v21 * v21 + v22 * v22 + v23 * v23 +
                     v31 * v31 + v32 * v32 + v33 * v33));
}

double ComputeScalarRep(int numComp, double *val)
{
  if(numComp == 1)
    return val[0];
  else if(numComp == 3)
    return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
  else if(numComp == 9)
    return ComputeVonMises(val);
  return 0.;
}

void eigenvalue(double mat[3][3], double v[3])
{            
  // characteristic polynomial of T : find v root of
  // v^3 - I1 v^2 + I2 T - I3 = 0
  // I1 : first invariant , trace(T)
  // I2 : second invariant , 1/2 (I1^2 -trace(T^2))
  // I3 : third invariant , det T

  double c[4];
  c[3] = 1.0;
  c[2] = - trace3x3(mat);
  c[1] = 0.5 * (c[2]*c[2] - trace2(mat));
  c[0] = - det3x3(mat);
  
  //printf("%g %g %g\n", mat[0][0], mat[0][1], mat[0][2]);
  //printf("%g %g %g\n", mat[1][0], mat[1][1], mat[1][2]);
  //printf("%g %g %g\n", mat[2][0], mat[2][1], mat[2][2]);
  //printf("%g x^3 + %g x^2 + %g x + %g = 0\n", c[3], c[2], c[1], c[0]);
  
  double imag[3];
  FindCubicRoots(c, v, imag);
  eigsort(v);
}

void FindCubicRoots(const double coef[4], double real[3], double imag[3])
{
  double a = coef[3];
  double b = coef[2];
  double c = coef[1];
  double d = coef[0];

  if(!a || !d){
    Msg(GERROR, "Degenerate cubic: use a second degree solver!");
    return;
  }

  b /= a;
  c /= a;
  d /= a;
  
  double q = (3.0*c - (b*b))/9.0;
  double r = -(27.0*d) + b*(9.0*c - 2.0*(b*b));
  r /= 54.0;

  double discrim = q*q*q + r*r;
  imag[0] = 0.0; // The first root is always real.
  double term1 = (b/3.0);

  if (discrim > 0) { // one root is real, two are complex
    double s = r + sqrt(discrim);
    s = ((s < 0) ? -pow(-s, (1.0/3.0)) : pow(s, (1.0/3.0)));
    double t = r - sqrt(discrim);
    t = ((t < 0) ? -pow(-t, (1.0/3.0)) : pow(t, (1.0/3.0)));
    real[0] = -term1 + s + t;
    term1 += (s + t)/2.0;
    real[1] = real[2] = -term1;
    term1 = sqrt(3.0)*(-t + s)/2;
    imag[1] = term1;
    imag[2] = -term1;
    return;
  }

  // The remaining options are all real
  imag[1] = imag[2] = 0.0;
  
  double r13;
  if (discrim == 0){ // All roots real, at least two are equal.
    r13 = ((r < 0) ? -pow(-r,(1.0/3.0)) : pow(r,(1.0/3.0)));
    real[0] = -term1 + 2.0*r13;
    real[1] = real[2] = -(r13 + term1);
    return;
  }

  // Only option left is that all roots are real and unequal (to get
  // here, q < 0)
  q = -q;
  double dum1 = q*q*q;
  dum1 = acos(r/sqrt(dum1));
  r13 = 2.0*sqrt(q);
  real[0] = -term1 + r13*cos(dum1/3.0);
  real[1] = -term1 + r13*cos((dum1 + 2.0*M_PI)/3.0);
  real[2] = -term1 + r13*cos((dum1 + 4.0*M_PI)/3.0);
}

void  eigsort(double d[3])
{
  int k, j, i;
  double p;
  
  for (i=0; i<3; i++) {
    p=d[k=i];
    for (j=i+1;j<3;j++)
      if (d[j] >= p) p=d[k=j];
    if (k != i) {
      d[k]=d[i];
      d[i]=p;
    }
  }
}
