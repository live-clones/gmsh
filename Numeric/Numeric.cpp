// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "Numeric.h"

#define SQU(a)      ((a)*(a))

double myatan2(double a, double b)
{
  if(a == 0.0 && b == 0)
    return 0.0;
  return atan2(a, b);
}


double myasin(double a)
{
  if(a <= -1.)
    return -M_PI / 2.;
  else if(a >= 1.)
    return M_PI / 2.;
  else
    return asin(a);
}

double myacos(double a)
{
  if(a <= -1.)
    return M_PI;
  else if(a >= 1.)
    return 0.;
  else
    return acos(a);
}

void matvec(double mat[3][3], double vec[3], double res[3])
{
  res[0] = mat[0][0] * vec[0] + mat[0][1] * vec[1] + mat[0][2] * vec[2];
  res[1] = mat[1][0] * vec[0] + mat[1][1] * vec[1] + mat[1][2] * vec[2];
  res[2] = mat[2][0] * vec[0] + mat[2][1] * vec[1] + mat[2][2] * vec[2];
}

void matmat(double mat1[3][3], double mat2[3][3], double res[3][3])
{
  res[0][0] = mat1[0][0]*mat2[0][0] + mat1[0][1]*mat2[1][0] + mat1[0][2]*mat2[2][0];
  res[0][1] = mat1[0][0]*mat2[0][1] + mat1[0][1]*mat2[1][1] + mat1[0][2]*mat2[2][1];
  res[0][2] = mat1[0][0]*mat2[0][2] + mat1[0][1]*mat2[1][2] + mat1[0][2]*mat2[2][2];
  res[1][0] = mat1[1][0]*mat2[0][0] + mat1[1][1]*mat2[1][0] + mat1[1][2]*mat2[2][0];
  res[1][1] = mat1[1][0]*mat2[0][1] + mat1[1][1]*mat2[1][1] + mat1[1][2]*mat2[2][1];
  res[1][2] = mat1[1][0]*mat2[0][2] + mat1[1][1]*mat2[1][2] + mat1[1][2]*mat2[2][2];
  res[2][0] = mat1[2][0]*mat2[0][0] + mat1[2][1]*mat2[1][0] + mat1[2][2]*mat2[2][0];
  res[2][1] = mat1[2][0]*mat2[0][1] + mat1[2][1]*mat2[1][1] + mat1[2][2]*mat2[2][1];
  res[2][2] = mat1[2][0]*mat2[0][2] + mat1[2][1]*mat2[1][2] + mat1[2][2]*mat2[2][2];
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

  norm = SQU(mat[0][0]) + SQU(mat[1][1]) + SQU(mat[0][1]) + SQU(mat[1][0]);
  det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];

  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || fabs(det) / norm < 1.e-12) {
    if(norm)
      Msg::Debug("Assuming 2x2 matrix is singular (det/norm == %.16g)",
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
    SQU(mat[0][0]) + SQU(mat[0][1]) + SQU(mat[0][2]) +
    SQU(mat[1][0]) + SQU(mat[1][1]) + SQU(mat[1][2]) +
    SQU(mat[2][0]) + SQU(mat[2][1]) + SQU(mat[2][2]);

  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || fabs(*det) / norm < 1.e-12) {
    if(norm)
      Msg::Debug("Assuming 3x3 matrix is singular (det/norm == %.16g)",
          fabs(*det) / norm);
    res[0] = res[1] = res[2] = 0.0;
    return 0;
  }

  return out;
}

double det2x2(double mat[2][2])
{
  return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

double det2x3(double mat[2][3])
{
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double n[3];
  
  prodve(v1, v2, n);
  return norm3(n);
}

double inv2x2(double mat[2][2], double inv[2][2])
{
  const double det = det2x2(mat);
  if(det){
    double ud = 1. / det;
    inv[0][0] =  mat[1][1] * ud;
    inv[1][0] = -mat[1][0] * ud;
    inv[0][1] = -mat[0][1] * ud;
    inv[1][1] =  mat[0][0] * ud;
  }
  else{
    Msg::Error("Singular matrix");
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
    inv[0][0] =  (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] =  (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] =  (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] =  (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] =  (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
  }
  else{
    Msg::Error("Singular matrix");
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        inv[i][j] = 0.;
  }
  return det;
}

double angle_02pi(double A3)
{
  double DP = 2 * M_PI;
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
  return 0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
}

double triangle_area2d(double p0[2], double p1[2], double p2[2])
{
  const double c =  
    (p2[0] - p1[0])*(p0[1] - p1[1]) - 
    (p2[1] - p1[1])*(p0[0] - p1[0]);

  return 0.5 * sqrt(c*c);
}

double triangle_polar_inertia(double p0[2], double p1[2], double p2[2])
{
  throw;
}


void circumCenterXY(double *p1, double *p2, double *p3, double *res)
{
  double d, a1, a2, a3;

  const double x1 = p1[0];
  const double x2 = p2[0];
  const double x3 = p3[0];
  const double y1 = p1[1];
  const double y2 = p2[1];
  const double y3 = p3[1];

  d = 2. * (double)(y1 * (x2 - x3) + y2 * (x3 - x1) + y3 * (x1 - x2));
  if(d == 0.0) {
    //    Msg::Warning("Colinear points in circum circle computation");
    res[0] = res[1] = -99999.;
    return ;
  }

  a1 = x1 * x1 + y1 * y1;
  a2 = x2 * x2 + y2 * y2;
  a3 = x3 * x3 + y3 * y3;
  res[0] = (double)((a1 * (y3 - y2) + a2 * (y1 - y3) + a3 * (y2 - y1)) / d);
  res[1] = (double)((a1 * (x2 - x3) + a2 * (x3 - x1) + a3 * (x1 - x2)) / d);
}


void circumCenterXYZ(double *p1, double *p2, double *p3, double *res, double *uv)
{
  double v1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double v2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3]; prodve(vx, vy, vz); prodve(vz, vx, vy);
  norme(vx); norme(vy); norme(vz);
  double p1P[2] = {0.0, 0.0};
  double p2P[2]; prosca(v1, vx, &p2P[0]); prosca(v1, vy, &p2P[1]);
  double p3P[2]; prosca(v2, vx, &p3P[0]); prosca(v2, vy, &p3P[1]);
  double resP[2];

  circumCenterXY(p1P, p2P, p3P,resP);

  if(uv){
    double mat[2][2] = {{p2P[0] - p1P[0], p3P[0] - p1P[0]},
                        {p2P[1] - p1P[1], p3P[1] - p1P[1]}};
    double rhs[2] = {resP[0] - p1P[0], resP[1] - p1P[1]};
    sys2x2(mat, rhs, uv);
  }
  
  res[0] = p1[0] + resP[0] * vx[0] + resP[1] * vy[0];
  res[1] = p1[1] + resP[0] * vx[1] + resP[1] * vy[1];
  res[2] = p1[2] + resP[0] * vx[2] + resP[1] * vy[2];
}

void planarQuad_xyz2xy(double *x, double *y, double *z, double *xn, double *yn)
{
        double v1[3] = {x[1] - x[0], y[1] - y[0], z[1] - z[0]};
        double v2[3] = {x[2] - x[0], y[2] - y[0], z[2] - z[0]};
        double v3[3] = {x[3] - x[0], y[3] - y[0], z[3] - z[0]};
        
        double vx[3] = {x[1] - x[0], y[1] - y[0], z[1] - z[0]};
        double vy[3] = {x[2] - x[0], y[2] - y[0], z[2] - z[0]};
        double vz[3]; prodve(vx, vy, vz); prodve(vz, vx, vy);
        
        norme(vx); norme(vy); norme(vz);
        
        double p1P[2] = {0.0, 0.0};
        double p2P[2]; prosca(v1, vx, &p2P[0]); prosca(v1, vy, &p2P[1]);
        double p3P[2]; prosca(v2, vx, &p3P[0]); prosca(v2, vy, &p3P[1]);
        double p4P[2]; prosca(v3, vx, &p4P[0]); prosca(v3, vy, &p4P[1]);
        
        xn[0] = p1P[0];
        xn[1] = p2P[0];
        xn[2] = p3P[0];
        xn[3] = p4P[0];
        yn[0] = p1P[1];
        yn[1] = p2P[1];
        yn[2] = p3P[1];
        yn[3] = p4P[1];
}

double computeInnerRadiusForQuad(double *x, double *y, int i){
        
        // parameters of the equations of the 3 edges   
        double a1 = y[(4+i)%4]-y[(5+i)%4];
        double a2 = y[(5+i)%4]-y[(6+i)%4];
        double a3 = y[(6+i)%4]-y[(7+i)%4];

        double b1 = x[(5+i)%4]-x[(4+i)%4];
        double b2 = x[(6+i)%4]-x[(5+i)%4];
        double b3 = x[(7+i)%4]-x[(6+i)%4];

        double c1 = y[(5+i)%4]*x[(4+i)%4]-y[(4+i)%4]*x[(5+i)%4];
        double c2 = y[(6+i)%4]*x[(5+i)%4]-y[(5+i)%4]*x[(6+i)%4];
        double c3 = y[(7+i)%4]*x[(6+i)%4]-y[(6+i)%4]*x[(7+i)%4];

        // length of the 3 edges
        double l1 = sqrt(a1*a1+b1*b1);
        double l2 = sqrt(a2*a2+b2*b2);
        double l3 = sqrt(a3*a3+b3*b3);
        
        // parameters of the 2 bisectors
        double a12 = a1/l1-a2/l2;
        double a23 = a2/l2-a3/l3;
        
        double b12 = b1/l1-b2/l2;
        double b23 = b2/l2-b3/l3;
        
        double c12 = c1/l1-c2/l2;
        double c23 = c2/l2-c3/l3;
        
        // compute the coordinates of the center of the incircle, 
        // that is the point where the 2 bisectors meet
        double x_s = (c12*b23-c23*b12)/(a23*b12-a12*b23);
        double y_s = 0.;
        if (b12 != 0) {
                y_s = -a12/b12*x_s-c12/b12;
        }
        else {
                y_s = -a23/b23*x_s-c23/b23;
        }
 
        // finally get the radius of the circle 
        double r = (a1*x_s+b1*y_s+c1)/l1;

        return r;
}


char float2char(float f)
{
  // float normalized in [-1, 1], char in [-127, 127]
  f *= 127.;
  if(f > 127.) return 127;
  else if(f < -127.) return -127;
  else return (char)f;
}

float char2float(char c)
{
  float f = c;
  f /= 127.;
  if(f > 1.) return 1.;
  else if(f < -1) return -1.;
  else return f;
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
  c[1] = 0.5 * (c[2] * c[2] - trace2(mat));
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
    Msg::Error("Degenerate cubic: use a second degree solver!");
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

void eigsort(double d[3])
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

  fullMatrix<double> M(3, 3), V(3, 3);
  fullVector<double> W(3);
  for(i = 1; i <= n; i++){
    for(j = 1; j <= n; j++){
      M(i - 1, j - 1) = MM[i - 1][j - 1];
    }
  }
  M.svd(V, W);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      double ww = W(i - 1);
      if(fabs(ww) > 1.e-16) { // singular value precision
        TT[i - 1][j - 1] += M(j - 1, i - 1) / ww;
      }
    }
  }
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      for(k = 1; k <= n; k++) {
        II[i - 1][j - 1] += V(i - 1, k - 1) * TT[k - 1][j - 1];
      }
    }
  }
}

bool newton_fd(void (*func)(fullVector<double> &, fullVector<double> &, void *),
               fullVector<double> &x, void *data, double relax, double tolx)
{
  const int MAXIT = 50;
  const double EPS = 1.e-4;
  const int N = x.size();
  
  fullMatrix<double> J(N, N);
  fullVector<double> f(N), feps(N), dx(N);
  
  for (int iter = 0; iter < MAXIT; iter++){
     func(x, f, data);
     
     bool isZero = false;
     for (int k=0; k<N; k++) {
         if (f(k) == 0. ) isZero = true;
         else isZero = false;
         if (isZero == false) break;
       }
     if (isZero) break;

    for (int j = 0; j < N; j++){
      double h = EPS * fabs(x(j));
      if(h == 0.) h = EPS;
      x(j) += h;
      func(x, feps, data);
      for (int i = 0; i < N; i++){
        J(i, j) = (feps(i) - f(i)) / h;
      }
      x(j) -= h;
    }
    
    if (N == 1)
      dx(0) = f(0) / J(0, 0);
    else
      J.luSolve(f, dx);
    
    for (int i = 0; i < N; i++)
      x(i) -= relax * dx(i);

    if(dx.norm() < tolx) return true; 
  }
  return false;
}

/*
min_a f(x+a*d);

f(x+a*d) = f(x) + f'(x) (

*/

void gmshLineSearch(double (*func)(fullVector<double> &, void *), void* data, 
                    fullVector<double> &x, fullVector<double> &p,  
                    fullVector<double> &g, double &f, 
                    double stpmax, int &check)
{
  int i;
  double alam, alam2 = 1., alamin, f2 = 0., fold2 = 0., rhs1, rhs2, temp, tmplam = 0.;

  const double ALF = 1.0e-4;
  const double TOLX = 1.0e-9;

  fullVector<double> xold(x);
  const double fold = (*func)(xold,data);
  
  check=0;
  int n = x.size();
  double norm = p.norm();
  if (norm > stpmax)p.scale(stpmax/norm);
  double slope=0.0;
  for (i=0;i<n;i++)slope += g(i)*p(i);
  double test=0.0;
  for (i=0;i<n;i++) {
    temp=fabs(p(i))/std::max(fabs(xold(i)),1.0);
    if (temp > test) test=temp;
  }
  /*
  for (int j=0;j<100;j++){
    double sx = (double)j/99;
    for (i=0;i<n;i++) x(i)=xold(i)+10*sx*p(i);    
    double jzede = (*func)(x,data); 
  }
  */

  alamin=TOLX/test;
  alam=1.0;
  while(1) {
    for (i=0;i<n;i++) x(i)=xold(i)+alam*p(i);
    f=(*func)(x,data);
    //    printf("f = %g x = %g %g alam = %g p = %g %g\n",f,x(0),x(1),alam,p(0),p(1));
   if (alam < alamin) {
      for (i=0;i<n;i++) x(i)=xold(i);
      //      printf("ALERT : alam %g alamin %g\n",alam,alamin);
      check=1;
      return;
    } 
    else if (f <= fold + ALF*alam*slope) return;
    else {
      if (alam == 1.0)
        tmplam = -slope/(2.0*(f-fold-slope));
      else {
        rhs1 = f-fold-alam*slope;
        rhs2=f2-fold2-alam2*slope;
        const double a=(rhs1/(alam*alam)-rhs2/(alam2*alam2))/(alam-alam2);
        const double b=(-alam2*rhs1/(alam*alam)+alam*rhs2/(alam2*alam2))/(alam-alam2);
        if (a == 0.0) tmplam = -slope/(2.0*b);
        else {
          const double disc=b*b-3.0*a*slope;
          if (disc<0.0) Msg::Error("Roundoff problem in gmshLineSearch.");
          else tmplam=(-b+sqrt(disc))/(3.0*a);
        }
        if (tmplam>0.5*alam)
          tmplam=0.5*alam;
      }
    }
    alam2=alam;
    f2 = f;
    fold2=fold;
    alam=std::max(tmplam,0.1*alam);
  }
}

double minimize_grad_fd(double (*func)(fullVector<double> &, void *),
                        fullVector<double> &x, void *data)
{
  const int MAXIT = 3;
  const double EPS = 1.e-4;
  const int N = x.size();
  
  fullVector<double> grad(N);
  fullVector<double> dir(N);
  double f,feps,finit;

  for (int iter = 0; iter < MAXIT; iter++){
    // compute gradient of func
    f = func(x,data);
    if (iter == 0)finit = f;
    //    printf("Opti iter %d x = (%g %g) f = %g\n",iter,x(0),x(1),f);
    //    printf("grad = (");
    for (int j = 0; j < N; j++){
      double h = EPS * fabs(x(j));
      if(h == 0.) h = EPS;
      x(j) += h;
      feps = func(x, data);
      grad(j) = (feps - f) / h;
      //      printf("%g ",grad(j));
      dir(j) = -grad(j);
      x(j) -= h;
    }
    //    printf(")\n ");
    // do a 1D line search to fine the minimum
    // of f(x - \alpha \nabla f)
    double f, stpmax=100000;
    int check;
    gmshLineSearch (func, data, x,dir,grad,f,stpmax,check);
    //    printf("Line search done x = (%g %g) f = %g\n",x(0),x(1),f);
    if (check == 1)break;
  }
  
  return f;
}

/*

P(p) = p1 + t1 xi + t2 eta

t1 = (p2-p1) ; t2 = (p3-p1) ; 

(P(p) - p) = d n

(p1 + t1 xi + t2 eta - p) = d n
t1 xi + t2 eta + d n = p - p1

| t1x t2x -nx | |xi  |   |px-p1x|
| t1y t2y -ny | |eta | = |py-p1y|
| t1z t2z -nz | |d   |   |pz-p1z|

distance to segment

   P(p) = p1 + t (p2-p1)
   
   (p - P(p)) * (p2-p1) = 0
   (p - p1 - t (p2-p1) ) * (p2-p1) = 0
   - t ||p2-p1||^2 + (p-p1)(p2-p1) = 0
   
   t = (p-p1)*(p2-p1)/||p2-p1||^2
  

*/

void signedDistancesPointsTriangle(std::vector<double>&distances,
                                   std::vector<SPoint3>&closePts,
                                   const std::vector<SPoint3> &pts,
                                   const SPoint3 &p1,
                                   const SPoint3 &p2,
                                   const SPoint3 &p3)
{
  SVector3 t1 = p2 - p1;
  SVector3 t2 = p3 - p1;
  SVector3 t3 = p3 - p2;
  SVector3 n = crossprod(t1, t2);
  n.normalize();
	
  double mat[3][3] = {{t1.x(), t2.x(), -n.x()},
                      {t1.y(), t2.y(), -n.y()},
                      {t1.z(), t2.z(), -n.z()}};
  double inv[3][3];
  double det = inv3x3(mat, inv);
  const unsigned pts_size=pts.size();
  distances.clear();
  distances.resize(pts_size);
  closePts.clear();
  closePts.resize(pts_size);

  for (unsigned int i = 0; i < pts_size; ++i)
    distances[i] = 1.e22;

  if(det == 0.0) return;

  const double n2t1 = dot(t1, t1);
  const double n2t2 = dot(t2, t2);
  const double n2t3 = dot(t3, t3);

  double u, v, d;
  for (unsigned int i = 0; i < pts_size;++i){
    const SPoint3 &p = pts[i];
    SVector3 pp1 = p - p1;
    u = (inv[0][0] * pp1.x() + inv[0][1] * pp1.y() + inv[0][2] * pp1.z());
    v = (inv[1][0] * pp1.x() + inv[1][1] * pp1.y() + inv[1][2] * pp1.z());
    d = (inv[2][0] * pp1.x() + inv[2][1] * pp1.y() + inv[2][2] * pp1.z());
    double sign = (d > 0) ? 1. : -1.;
    if (d == 0) sign = 1.e10;
    if (u >= 0 && v >= 0 && 1.-u-v >= 0.0){
      distances[i] = d;
      closePts[i] = SPoint3(0.,0.,0.);//TO DO
    }
    else {
      const double t12 = dot(pp1, t1) / n2t1;
      const double t13 = dot(pp1, t2) / n2t2;
      SVector3 pp2 = p - p2;
      const double t23 = dot(pp2, t3) / n2t3;
      d = 1.e10;
      bool found = false;
      SPoint3 closePt;
      if (t12 >= 0 && t12 <= 1.){
        d = sign * std::min(fabs(d), p.distance(p1 + (p2 - p1) * t12));  
        closePt = p1 + (p2 - p1) * t12;
        found = true;
      }
      if (t13 >= 0 && t13 <= 1.){
        if (p.distance(p1 + (p3 - p1) * t13) < fabs(d))   closePt = p1 + (p3 - p1) * t13;
        d = sign * std::min(fabs(d), p.distance(p1 + (p3 - p1) * t13));      
        found = true;
      }      
      if (t23 >= 0 && t23 <= 1.){
        if (p.distance(p2 + (p3 - p2) * t23) < fabs(d))   closePt = p2 + (p3 - p2) * t23;
        d = sign * std::min(fabs(d), p.distance(p2 + (p3 - p2) * t23));      
        found = true;
      }
      if (p.distance(p1) < fabs(d)){
        closePt = p1;
        d = sign * std::min(fabs(d), p.distance(p1));
       }
      if (p.distance(p2) < fabs(d)){
        closePt = p2;
        d = sign * std::min(fabs(d), p.distance(p2));
       }
      if (p.distance(p3) < fabs(d)){
        closePt = p3;
        d = sign * std::min(fabs(d), p.distance(p3));
      }
      //d = sign * std::min(fabs(d), std::min(std::min(p.distance(p1), p.distance(p2)),p.distance(p3)));
      distances[i] = d;
      closePts[i] = closePt;
    }
  }                                        
}

void signedDistancePointLine(const SPoint3 &p1,const SPoint3 &p2,const SPoint3 &p, double &d, SPoint3 &closePt){
  SVector3 t1 = p2 - p1;
  const double n2t1 = dot(t1, t1);
  SVector3 pp1 = p - p1;
  const double t12 = dot(pp1, t1) / n2t1;
  d = 1.e10;
  bool found = false;
  if (t12 >= 0 && t12 <= 1.){
    d =  std::min(fabs(d), p.distance(p1 + (p2 - p1) * t12)); 
    closePt = p1 + (p2 - p1) * t12;
    found = true;
  }
  if (p.distance(p1) < fabs(d)){
    closePt = p1;
    d =  std::min(fabs(d), p.distance(p1));
  }
  if (p.distance(p2) < fabs(d)){
    closePt = p2;
    d =  std::min(fabs(d), p.distance(p2));
  }
}

void signedDistancesPointsLine (std::vector<double>&distances,
				std::vector<SPoint3>&closePts,
				const std::vector<SPoint3> &pts,
				const SPoint3 &p1,
				const SPoint3 &p2){

  distances.clear();
  distances.resize(pts.size());
  closePts.clear();
  closePts.resize(pts.size());

  double d;
  for (unsigned int i = 0; i < pts.size();i++){
    SPoint3 closePt;
    const SPoint3 &p = pts[i];
    signedDistancePointLine(p1,p2,p,d,closePt);
    distances[i] = d;
    closePts[i] = closePt;
  }
}

void changeReferential(const int direction,const SPoint3 &p,const SPoint3 &closePt,const SPoint3 &p1,const SPoint3 &p2,double* xp,double* yp,double* otherp,double* x,double* y,double* other){
  if (direction==1){
    const SPoint3 &d1=SPoint3(1.0,0.0,0.0);
    const SPoint3 &d=SPoint3(p2.x()-p1.x(),p2.y()-p1.y(),p2.z()-p1.z());
    double norm=sqrt( d.x()*d.x()+d.y()*d.y()+d.z()*d.z() );
    const SPoint3 &dn=SPoint3(d.x()/norm,d.y()/norm,d.z()/norm);
    const SPoint3 &d3=SPoint3(d1.y()*dn.z()-d1.z()*dn.y(),d1.z()*dn.x()-d1.x()*dn.z(),d1.x()*dn.y()-d1.y()*dn.x());
    norm=sqrt( d3.x()*d3.x()+d3.y()*d3.y()+d3.z()*d3.z() );
    const SPoint3 &d3n=SPoint3(d3.x()/norm,d3.y()/norm,d3.z()/norm);
    const SPoint3 &d2=SPoint3(d3n.y()*d1.z()-d3n.z()*d1.y(),d3n.z()*d1.x()-d3n.x()*d1.z(),d3n.x()*d1.y()-d3n.y()*d1.x());
    norm=sqrt( d2.x()*d2.x()+d2.y()*d2.y()+d2.z()*d2.z() );
    const SPoint3 &d2n=SPoint3(d2.x()/norm,d2.y()/norm,d2.z()/norm);
    *xp=p.x()*d1.x()+p.y()*d1.y()+p.z()*d1.z();
    *yp=p.x()*d3n.x()+p.y()*d3n.y()+p.z()*d3n.z();
    *otherp=p.x()*d2n.x()+p.y()*d2n.y()+p.z()*d2n.z();
    *x=closePt.x()*d1.x()+closePt.y()*d1.y()+closePt.z()*d1.z();
    *y=closePt.x()*d3n.x()+closePt.y()*d3n.y()+closePt.z()*d3n.z();
    *other=closePt.x()*d2n.x()+closePt.y()*d2n.y()+closePt.z()*d2n.z();
  }else{
    const SPoint3 &d2=SPoint3(0.0,1.0,0.0);
    const SPoint3 &d=SPoint3(p2.x()-p1.x(),p2.y()-p1.y(),p2.z()-p1.z());
    double norm=sqrt( d.x()*d.x()+d.y()*d.y()+d.z()*d.z() );
    const SPoint3 &dn=SPoint3(d.x()/norm,d.y()/norm,d.z()/norm);
    const SPoint3 &d3=SPoint3(dn.y()*d2.z()-dn.z()*d2.y(),dn.z()*d2.x()-dn.x()*d2.z(),dn.x()*d2.y()-dn.y()*d2.x());
    norm=sqrt( d3.x()*d3.x()+d3.y()*d3.y()+d3.z()*d3.z() );
    const SPoint3 &d3n=SPoint3(d3.x()/norm,d3.y()/norm,d3.z()/norm);
    const SPoint3 &d1=SPoint3(d2.y()*d3n.z()-d2.z()*d3n.y(),d2.z()*d3n.x()-d2.x()*d3n.z(),d2.x()*d3n.y()-d2.y()*d3n.x());
    norm=sqrt( d1.x()*d1.x()+d1.y()*d1.y()+d1.z()*d1.z() );
    const SPoint3 &d1n=SPoint3(d1.x()/norm,d1.y()/norm,d1.z()/norm);
    *xp=p.x()*d2.x()+p.y()*d2.y()+p.z()*d2.z();
    *yp=p.x()*d3n.x()+p.y()*d3n.y()+p.z()*d3n.z();
    *otherp=p.x()*d1n.x()+p.y()*d1n.y()+p.z()*d1n.z();
    *x=closePt.x()*d2.x()+closePt.y()*d2.y()+closePt.z()*d2.z();
    *y=closePt.x()*d3n.x()+closePt.y()*d3n.y()+closePt.z()*d3n.z();
    *other=closePt.x()*d1n.x()+closePt.y()*d1n.y()+closePt.z()*d1n.z();
  }
}

int computeDistanceRatio(const double &y, const double &yp,const double &x,const double &xp, double *distance, const double &r1, const double &r2){
  double b;
  double a;
  if (y==yp){
    b=-y;
    a=0.0;
  }else{
    if (x==xp){
      b=-x;
      a==0.0;
    }else{
      b=(xp*y-x*yp)/(yp-y);
      if (yp==0.0){
        a=-(b+x)/y;
      }else{
        a=-(b+xp)/yp;
      }
    }
  }
  double ae;
  double be;
  double ce;
  double da=r1*r1;
  double db=r2*r2;
  if (y==yp){
    ae=1.0/da;
    be=-(2*x)/da;
    ce=(x*x/da)-1.0;
  }else{
    if (x==xp){
      ae = 1.0/db;
      be = -(2.0*y)/db;
      ce = (y*y/db)-1.0;
    }else{
      if (fabs(a)<0.00001){
        ae = 1.0/db;
        be = -(2.0*y)/db;
        ce = (y*y/db)-1.0;
      }else{
        double a2=a*a;
        ae=(1.0/da)+(1.0/(db*a2));
        be=(2.0*y)/(db*a)+(2.0*b)/(a2*db)-((2.0*x)/da);
        ce=(x*x)/da+(b*b)/(db*a2)+(2.0*b*y)/(a*db)+(y*y/db)-1.0;
      }
    }
  }
  double rho=be*be-4*ae*ce;
  double x1,x2,y1,y2,propdist;
  if (rho<0) {
    return 1;
  }else{
    x1=-(be+sqrt(rho))/(2.0*ae);
    x2=(-be+sqrt(rho))/(2.0*ae);
    if (y==yp){
      y1=-b;
      y2=-b;
    }else{
      if (x==xp){
	y1=x1;
        y2=x2;
	x1=-b;
        x2=-b;
      }else{
        if (fabs(a)<0.00001){
          y1=x1;
          y2=x2;
          x1=-b;
          x2=-b;
        }else{
          y1=-(b+x1)/a;
          y2=-(b+x2)/a;
	}
      }
    }
    if (x1==x2){
      propdist=(y1-y)/(yp-y);
      if(propdist<0.0){
	propdist=(y2-y)/(yp-y);
      }
    }else{
      if (xp!=x){
        propdist=(x1-x)/(xp-x);
	if (propdist<0.0){
	  propdist=(x2-x)/(xp-x);
	}
      }else{
	if (yp!=y){
	  propdist=(y1-y)/(yp-y);
	  if(propdist<0.0){
	    propdist=(y2-y)/(yp-y);
	  }
	}else{
	  propdist=0.01;
	}
      }
    }
    *distance=propdist;
    return 0;
  }
}

void signedDistancesPointsEllipseLine (std::vector<double>&distances,
				std::vector<double> &distancesE,
				std::vector<int>&isInYarn,
				std::vector<SPoint3>&closePts,
				const std::vector<SPoint3> &pts,
				const SPoint3 &p1,
				const SPoint3 &p2){
  
  distances.clear();
  distances.resize(pts.size());
  distancesE.clear();
  distancesE.resize(pts.size());
  isInYarn.clear();
  isInYarn.resize(pts.size());
  closePts.clear();
  closePts.resize(pts.size());
  double d;
  for (unsigned int i = 0; i < pts.size();i++){
    SPoint3 closePt;
    const SPoint3 &p = pts[i];
    signedDistancePointLine(p1,p2,p,d,closePt);
    
    distances[i] = d;
    closePts[i] = closePt;
    int direction;
    double distancesMin;
    if (!(p.x()==closePt.x() && p.y()==closePt.y() && p.z()==closePt.z())){
      double xp,yp,x,y,otherp,other,propdist;
      if (p1.x()==p2.x()){
        direction=1;
        if (fabs(closePt.x()-0.0)<0.00000001) isInYarn[i]=1;
        if (fabs(closePt.x()-2.2)<0.00000001) isInYarn[i]=4;
        if (fabs(closePt.x()-4.4)<0.00000001) isInYarn[i]=2;
        if (fabs(closePt.x()-6.6)<0.00000001) isInYarn[i]=5;
        if (fabs(closePt.x()-8.8)<0.00000001) isInYarn[i]=3;
	if (fabs(closePt.x()-11.0)<0.00000001) isInYarn[i]=1;
      }else{
        if (p1.y()==p2.y()){
          direction=2;
	  if (fabs(closePt.y()-0.0)<0.00000001) isInYarn[i]=6;
	  if (fabs(closePt.y()-2.2)<0.00000001) isInYarn[i]=7;
	  if (fabs(closePt.y()-4.4)<0.00000001) isInYarn[i]=8;
	  if (fabs(closePt.y()-6.6)<0.00000001) isInYarn[i]=9;
	  if (fabs(closePt.y()-8.8)<0.00000001) isInYarn[i]=10;
	  if (fabs(closePt.y()-11.0)<0.00000001) isInYarn[i]=6;
        }else{
	  printf("WTF %lf %lf\n",closePt.x(),closePt.y());
        }
      }
      changeReferential(direction,p,closePt,p1,p2,&xp,&yp,&otherp,&x,&y,&other);
      int result;
      if (fabs(other-otherp)>0.01){
	result=1;
      }else{
        result=computeDistanceRatio(y,yp,x,xp,&propdist,1.1,0.0875);
      }
      if (result==1){
          distancesE[i] = 1.e10;
          isInYarn[i]=0;
      }else{
        if (propdist<1.0){
          isInYarn[i]=0;
          distancesE[i]=(1.0/propdist)-1.0;
        }else{
	  distancesE[i]=(1.0-(1.0/propdist))/3.0;
        }
      }
    }else{
        isInYarn[i]=0;
        distancesE[i]=1000000.0;
    }
  }
}
