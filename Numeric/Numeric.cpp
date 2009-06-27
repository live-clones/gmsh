// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
    Msg::Warning("Colinear points in circum circle computation");
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

  gmshMatrix<double> M(3, 3), V(3, 3);
  gmshVector<double> W(3);
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

bool newton_fd(void (*func)(gmshVector<double> &, gmshVector<double> &, void *),
               gmshVector<double> &x, void *data, double relax, double tolx)
{
  const int MAXIT = 50;
  const double EPS = 1.e-4;
  const int N = x.size();
  
  gmshMatrix<double> J(N, N);
  gmshVector<double> f(N), feps(N), dx(N);
  
  for (int iter = 0; iter < MAXIT; iter++){
     func(x, f, data);
     
     printf("coucou av break !! \n");
     bool isZero = false;
     for (int k=0; k<N; k++) {
	 if (f(k) == 0. ) isZero = true;
	 else isZero = false;
	 if (isZero == false) break;
       }
     if (isZero) break;
     printf("coucou ap break !! \n");
    //printf("**** fffffff0=%g %g %g %g %g %g %g %g %g\n", f(0), f(1), f(2),  f(3), f(4),  f(5), f(6),  f(7), f(8));

    for (int j = 0; j < N; j++){
      double h = EPS * fabs(x(j));
      if(h == 0.) h = EPS;
      x(j) += h;
      func(x, feps, data);
      for (int i = 0; i < N; i++)
        J(i, j) = (feps(i) - f(i)) / h;
      x(j) -= h;
    }
    
    if (N == 1)
      dx(0) = f(0) / J(0, 0);
    else
      J.lu_solve(f, dx);
    
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

void gmshLineSearch(double (*func)(gmshVector<double> &, void *), void* data, 
                    gmshVector<double> &x, gmshVector<double> &p,  
                    gmshVector<double> &g, double &f, 
                    double stpmax, int &check)
{
  int i;
  double alam, alam2 = 1., alamin, f2 = 0., fold2 = 0., rhs1, rhs2, temp, tmplam;

  const double ALF = 1.0e-4;
  const double TOLX = 1.0e-9;

  gmshVector<double> xold(x);
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

double minimize_grad_fd (double (*func)(gmshVector<double> &, void *),
		       gmshVector<double> &x, void *data)
{
  const int MAXIT = 3;
  const double EPS = 1.e-4;
  const int N = x.size();
  
  gmshVector<double> grad(N);
  gmshVector<double> dir(N);
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

