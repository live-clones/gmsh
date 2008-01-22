#ifndef _NUMERIC_EMBEDDED_H_
#define _NUMERIC_EMBEDDED_H_

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

#include <math.h>

#define RADTODEG      57.295779513082321
#define RacineDeDeux  1.4142135623730950
#define RacineDeTrois 1.7320508075688773
#define Pi            3.1415926535897932
#define Deux_Pi       6.2831853071795865

#if !defined(M_PI)
#define M_PI Pi
#endif

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define SQR(a)   ((a)*(a))

#define IMIN MIN
#define LMIN MIN
#define FMIN MIN
#define DMIN MIN

#define IMAX MAX
#define LMAX MAX
#define FMAX MAX
#define DMAX MAX

#define DSQR SQR
#define FSQR SQR

#define THRESHOLD(a,b,c) (((a)>(c))?(c):((a)<(b)?(b):(a)))

#define myhypot(a,b) (sqrt((a)*(a)+(b)*(b)))
#define sign(x)      (((x)>=0)?1:-1)
#define Pred(x)      ((x)->prev)
#define Succ(x)      ((x)->next)
#define square(x)    ((x)*(x))

double myatan2(double a, double b);
double myasin(double a);
double myacos(double a);
inline void prodve(double a[3], double b[3], double c[3])
{
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}
inline void prosca(double a[3], double b[3], double *c)
{
  *c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
void matvec(double mat[3][3], double vec[3], double res[3]);
inline double norm3(double a[3])
{
  return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}
inline double norme(double a[3])
{
  const double mod = norm3(a);
  if(mod != 0.0){
    const double one_over_mod = 1./mod;
    a[0] *= one_over_mod;
    a[1] *= one_over_mod;
    a[2] *= one_over_mod;
  }
  return mod;
}
void normal3points(double x0, double y0, double z0,
		   double x1, double y1, double z1,
		   double x2, double y2, double z2,
		   double n[3]);
int sys2x2(double mat[2][2], double b[2], double res[2]);
int sys3x3(double mat[3][3], double b[3], double res[3], double *det);
int sys3x3_with_tol(double mat[3][3], double b[3], double res[3], double *det);
double det2x2(double mat[2][2]);
double det2x3(double mat[2][3]);
double det3x3(double mat[3][3]);
double trace3x3(double mat[3][3]);
double trace2 (double mat[3][3]);
double inv3x3(double mat[3][3], double inv[3][3]);
double inv2x2(double mat[2][2], double inv[2][2]);
double angle_02pi(double A3);
double angle_plan(double V[3], double P1[3], double P2[3], double n[3]);
double triangle_area(double p0[3], double p1[3], double p2[3]);
char float2char(float f);
float char2float(char c);
void eigenvalue(double mat[3][3], double re[3]);
void FindCubicRoots(const double coeff[4], double re[3], double im[3]);
void eigsort(double d[3]);
double InterpolateIso(double *X, double *Y, double *Z, 
		      double *Val, double V, int I1, int I2, 
		      double *XI, double *YI ,double *ZI);
void gradSimplex(double *x, double *y, double *z, double *v, double *grad);
double ComputeVonMises(double *val);
double ComputeScalarRep(int numComp, double *val);

#endif
