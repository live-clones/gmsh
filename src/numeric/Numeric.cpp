// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "fullMatrix.h"
#include "Numeric.h"

double myatan2(double a, double b)
{
  if(a == 0.0 && b == 0) return 0.0;
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

double norm2(double a[3][3])
{
  double norm2sq =
    std::pow(a[0][0], 2) + std::pow(a[0][1], 2) + std::pow(a[0][2], 2) +
    std::pow(a[1][0], 2) + std::pow(a[1][1], 2) + std::pow(a[1][2], 2) +
    std::pow(a[2][0], 2) + std::pow(a[2][1], 2) + std::pow(a[2][2], 2);
  return std::sqrt(norm2sq);
}

void matvec(double mat[3][3], double vec[3], double res[3])
{
  res[0] = mat[0][0] * vec[0] + mat[0][1] * vec[1] + mat[0][2] * vec[2];
  res[1] = mat[1][0] * vec[0] + mat[1][1] * vec[1] + mat[1][2] * vec[2];
  res[2] = mat[2][0] * vec[0] + mat[2][1] * vec[1] + mat[2][2] * vec[2];
}

void matmat(double mat1[3][3], double mat2[3][3], double res[3][3])
{
  res[0][0] =
    mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0] + mat1[0][2] * mat2[2][0];
  res[0][1] =
    mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1] + mat1[0][2] * mat2[2][1];
  res[0][2] =
    mat1[0][0] * mat2[0][2] + mat1[0][1] * mat2[1][2] + mat1[0][2] * mat2[2][2];
  res[1][0] =
    mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0] + mat1[1][2] * mat2[2][0];
  res[1][1] =
    mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1] + mat1[1][2] * mat2[2][1];
  res[1][2] =
    mat1[1][0] * mat2[0][2] + mat1[1][1] * mat2[1][2] + mat1[1][2] * mat2[2][2];
  res[2][0] =
    mat1[2][0] * mat2[0][0] + mat1[2][1] * mat2[1][0] + mat1[2][2] * mat2[2][0];
  res[2][1] =
    mat1[2][0] * mat2[0][1] + mat1[2][1] * mat2[1][1] + mat1[2][2] * mat2[2][1];
  res[2][2] =
    mat1[2][0] * mat2[0][2] + mat1[2][1] * mat2[1][2] + mat1[2][2] * mat2[2][2];
}

void normal3points(double x0, double y0, double z0, double x1, double y1,
                   double z1, double x2, double y2, double z2, double n[3])
{
  double t1[3] = {x1 - x0, y1 - y0, z1 - z0};
  double t2[3] = {x2 - x0, y2 - y0, z2 - z0};
  prodve(t1, t2, n);
  norme(n);
}

void normal2points(double x0, double y0, double z0, double x1, double y1,
                   double z1, double n[3])
{
  // this computes one of the normals to the edge
  double t[3] = {x1 - x0, y1 - y0, z1 - z0};
  double ex[3] = {0., 0., 0.};
  if(t[0] == 0.)
    ex[0] = 1.;
  else if(t[1] == 0.)
    ex[1] = 1.;
  else
    ex[2] = 1.;
  prodve(t, ex, n);
  norme(n);
}

int sys2x2(double mat[2][2], double b[2], double res[2])
{
  double const norm = std::pow(mat[0][0], 2) + std::pow(mat[1][1], 2) +
                      std::pow(mat[0][1], 2) + std::pow(mat[1][0], 2);

  double const det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];

  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || std::abs(det) / norm < 1.e-16) {
    //    if(norm)
    //      Msg::Debug("Assuming 2x2 matrix is singular (det/norm == %.16g)",
    //		 std::abs(det) / norm);
    res[0] = res[1] = 0.0;
    return 0;
  }
  double const ud = 1.0 / det;

  res[0] = b[0] * mat[1][1] - mat[0][1] * b[1];
  res[1] = mat[0][0] * b[1] - mat[1][0] * b[0];

  for(int i = 0; i < 2; i++) res[i] *= ud;

  return 1;
}

double det3x3(double mat[3][3])
{
  return (mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
          mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
          mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]));
}

double trace3x3(double mat[3][3]) { return mat[0][0] + mat[1][1] + mat[2][2]; }

double trace2(double mat[3][3])
{
  double a00 =
    mat[0][0] * mat[0][0] + mat[1][0] * mat[0][1] + mat[2][0] * mat[0][2];
  double a11 =
    mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1] + mat[1][2] * mat[2][1];
  double a22 =
    mat[2][0] * mat[0][2] + mat[2][1] * mat[1][2] + mat[2][2] * mat[2][2];

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

  for(i = 0; i < 3; i++) res[i] *= ud;
  return (1);
}

int sys3x3_with_tol(double mat[3][3], double b[3], double res[3], double *det)
{
  int out;
  double norm;

  out = sys3x3(mat, b, res, det);
  norm =
    std::pow(mat[0][0], 2) + std::pow(mat[0][1], 2) + std::pow(mat[0][2], 2) +
    std::pow(mat[1][0], 2) + std::pow(mat[1][1], 2) + std::pow(mat[1][2], 2) +
    std::pow(mat[2][0], 2) + std::pow(mat[2][1], 2) + std::pow(mat[2][2], 2);

  // TOLERANCE ! WARNING WARNING
  if(norm == 0.0 || std::abs(*det) / norm < 1.e-12) {
    if(norm)
      Msg::Debug("Assuming 3x3 matrix is singular (det/norm == %.16g)",
                 std::abs(*det) / norm);
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
  if(det) {
    double ud = 1. / det;
    inv[0][0] = mat[1][1] * ud;
    inv[1][0] = -mat[1][0] * ud;
    inv[0][1] = -mat[0][1] * ud;
    inv[1][1] = mat[0][0] * ud;
  }
  else {
    Msg::Error("Singular matrix 2x2");
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++) inv[i][j] = 0.;
  }
  return det;
}

double inv3x3(double mat[3][3], double inv[3][3])
{
  double det = det3x3(mat);
  if(det) {
    double ud = 1. / det;
    inv[0][0] = (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) * ud;
    inv[1][0] = -(mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) * ud;
    inv[2][0] = (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]) * ud;
    inv[0][1] = -(mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1]) * ud;
    inv[1][1] = (mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0]) * ud;
    inv[2][1] = -(mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0]) * ud;
    inv[0][2] = (mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1]) * ud;
    inv[1][2] = -(mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0]) * ud;
    inv[2][2] = (mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]) * ud;
  }
  else {
    Msg::Error("Singular matrix 3x3");
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++) inv[i][j] = 0.;
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

double angle_plan(double v[3], double p1[3], double p2[3], double n[3])
{
  double PA[3], PB[3], angplan;

  PA[0] = p1[0] - v[0];
  PA[1] = p1[1] - v[1];
  PA[2] = p1[2] - v[2];

  PB[0] = p2[0] - v[0];
  PB[1] = p2[1] - v[1];
  PB[2] = p2[2] - v[2];

  norme(PA);
  norme(PB);

  double c[3];
  prodve(PA, PB, c);

  double const cosc = prosca(PA, PB);
  double const sinc = prosca(c, n);

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
  return 0.5 * std::sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
}

double triangle_area2d(double p0[2], double p1[2], double p2[2])
{
  const double c =
    (p2[0] - p1[0]) * (p0[1] - p1[1]) - (p2[1] - p1[1]) * (p0[0] - p1[0]);

  return 0.5 * std::sqrt(c * c);
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
    return;
  }

  a1 = x1 * x1 + y1 * y1;
  a2 = x2 * x2 + y2 * y2;
  a3 = x3 * x3 + y3 * y3;
  res[0] = (double)((a1 * (y3 - y2) + a2 * (y1 - y3) + a3 * (y2 - y1)) / d);
  res[1] = (double)((a1 * (x2 - x3) + a2 * (x3 - x1) + a3 * (x1 - x2)) / d);
}

void circumCenterXYZ(double *p1, double *p2, double *p3, double *res,
                     double *uv)
{
  double v1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double v2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3];
  prodve(vx, vy, vz);
  prodve(vz, vx, vy);
  norme(vx);
  norme(vy);
  norme(vz);

  double p1P[2] = {0.0, 0.0};
  double p2P[2] = {prosca(v1, vx), prosca(v1, vy)};
  double p3P[2] = {prosca(v2, vx), prosca(v2, vy)};

  double resP[2];

  circumCenterXY(p1P, p2P, p3P, resP);

  if(uv) {
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
  double vz[3];
  prodve(vx, vy, vz);
  prodve(vz, vx, vy);

  norme(vx);
  norme(vy);
  norme(vz);

  double p1P[2] = {0.0, 0.0};
  double p2P[2] = {prosca(v1, vx), prosca(v1, vy)};
  double p3P[2] = {prosca(v2, vx), prosca(v2, vy)};
  double p4P[2] = {prosca(v3, vx), prosca(v3, vy)};

  xn[0] = p1P[0];
  xn[1] = p2P[0];
  xn[2] = p3P[0];
  xn[3] = p4P[0];
  yn[0] = p1P[1];
  yn[1] = p2P[1];
  yn[2] = p3P[1];
  yn[3] = p4P[1];
}

double computeInnerRadiusForQuad(double *x, double *y, int i)
{
  // parameters of the equations of the 3 edges
  double a1 = y[(4 + i) % 4] - y[(5 + i) % 4];
  double a2 = y[(5 + i) % 4] - y[(6 + i) % 4];
  double a3 = y[(6 + i) % 4] - y[(7 + i) % 4];

  double b1 = x[(5 + i) % 4] - x[(4 + i) % 4];
  double b2 = x[(6 + i) % 4] - x[(5 + i) % 4];
  double b3 = x[(7 + i) % 4] - x[(6 + i) % 4];

  double c1 = y[(5 + i) % 4] * x[(4 + i) % 4] - y[(4 + i) % 4] * x[(5 + i) % 4];
  double c2 = y[(6 + i) % 4] * x[(5 + i) % 4] - y[(5 + i) % 4] * x[(6 + i) % 4];
  double c3 = y[(7 + i) % 4] * x[(6 + i) % 4] - y[(6 + i) % 4] * x[(7 + i) % 4];

  // length of the 3 edges
  double l1 = std::sqrt(a1 * a1 + b1 * b1);
  double l2 = std::sqrt(a2 * a2 + b2 * b2);
  double l3 = std::sqrt(a3 * a3 + b3 * b3);

  // parameters of the 2 bisectors
  double a12 = a1 / l1 - a2 / l2;
  double a23 = a2 / l2 - a3 / l3;

  double b12 = b1 / l1 - b2 / l2;
  double b23 = b2 / l2 - b3 / l3;

  double c12 = c1 / l1 - c2 / l2;
  double c23 = c2 / l2 - c3 / l3;

  // compute the coordinates of the center of the incircle,
  // that is the point where the 2 bisectors meet
  double x_s = (c12 * b23 - c23 * b12) / (a23 * b12 - a12 * b23);
  double y_s = 0.;
  if(b12 != 0) { y_s = -a12 / b12 * x_s - c12 / b12; }
  else {
    y_s = -a23 / b23 * x_s - c23 / b23;
  }

  // finally get the radius of the circle
  double r = (a1 * x_s + b1 * y_s + c1) / l1;

  return r;
}

char float2char(float f)
{
  // float normalized in [-1, 1], char in [-127, 127]
  float c = f * 127.;
  if(c > 127.)
    return 127;
  else if(c < -127.)
    return -127;
  else
    return (int)c;
}

float char2float(char c)
{
  float f = c;
  if(f > 127.)
    return 1.;
  else if(f < -127)
    return -1.;
  else
    return f / 127.;
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
  double v11 = V[0] - tr, v12 = V[1], v13 = V[2];
  double v21 = V[3], v22 = V[4] - tr, v23 = V[5];
  double v31 = V[6], v32 = V[7], v33 = V[8] - tr;
  return sqrt(1.5 * (v11 * v11 + v12 * v12 + v13 * v13 + v21 * v21 + v22 * v22 +
                     v23 * v23 + v31 * v31 + v32 * v32 + v33 * v33));
}

double ComputeScalarRep(int numComp, double *val, int tensorRep)
{
  if(numComp == 1)
    return val[0];
  else if(numComp == 3)
    return sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
  else if(numComp == 9) {
    if(tensorRep == 0) { // Von-Mises
      return ComputeVonMises(val);
    }
    else {
      fullMatrix<double> tensor(3, 3);
      fullVector<double> S(3), imS(3);
      fullMatrix<double> V(3, 3);
      fullMatrix<double> rightV(3, 3);
      for(int j = 0; j < 3; j++) {
        tensor(j, 0) = val[0 + j * 3];
        tensor(j, 1) = val[1 + j * 3];
        tensor(j, 2) = val[2 + j * 3];
      }
      tensor.eig(S, imS, V, rightV, true);
      if(tensorRep == 1) { // max eigenvalue
        return S(2);
      }
      else { // min eigenvalue
        return S(0);
      }
    }
  }
  return 0.;
}

void eigenvalue2x2(double mat[2][2], double v[2])
{
  double a = 1;
  double b = -(mat[0][0] + mat[1][1]);
  double c = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);

  double det = b * b - 4. * a * c;

  v[0] = (-b + sqrt(det)) / (2 * a);
  v[1] = (-b - sqrt(det)) / (2 * a);
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
  c[2] = -trace3x3(mat);
  c[1] = 0.5 * (c[2] * c[2] - trace2(mat));
  c[0] = -det3x3(mat);

  // printf("%g %g %g\n", mat[0][0], mat[0][1], mat[0][2]);
  // printf("%g %g %g\n", mat[1][0], mat[1][1], mat[1][2]);
  // printf("%g %g %g\n", mat[2][0], mat[2][1], mat[2][2]);
  // printf("%g x^3 + %g x^2 + %g x + %g = 0\n", c[3], c[2], c[1], c[0]);

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

  if(!a || !d) {
    // Msg::Error("Degenerate cubic: use a second degree solver!");
    return;
  }

  b /= a;
  c /= a;
  d /= a;

  double q = (3.0 * c - (b * b)) / 9.0;
  double r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b));
  r /= 54.0;

  double discrim = q * q * q + r * r;
  imag[0] = 0.0; // The first root is always real.
  double term1 = (b / 3.0);

  if(discrim > 0) { // one root is real, two are complex
    double s = r + sqrt(discrim);
    s = ((s < 0) ? -pow(-s, (1.0 / 3.0)) : pow(s, (1.0 / 3.0)));
    double t = r - sqrt(discrim);
    t = ((t < 0) ? -pow(-t, (1.0 / 3.0)) : pow(t, (1.0 / 3.0)));
    real[0] = -term1 + s + t;
    term1 += (s + t) / 2.0;
    real[1] = real[2] = -term1;
    term1 = sqrt(3.0) * (-t + s) / 2;
    imag[1] = term1;
    imag[2] = -term1;
    return;
  }

  // The remaining options are all real
  imag[1] = imag[2] = 0.0;

  double r13;
  if(discrim == 0) { // All roots real, at least two are equal.
    r13 = ((r < 0) ? -pow(-r, (1.0 / 3.0)) : pow(r, (1.0 / 3.0)));
    real[0] = -term1 + 2.0 * r13;
    real[1] = real[2] = -(r13 + term1);
    return;
  }

  // Only option left is that all roots are real and unequal (to get
  // here, q < 0)
  q = -q;
  double dum1 = q * q * q;
  dum1 = acos(r / sqrt(dum1));
  r13 = 2.0 * sqrt(q);
  real[0] = -term1 + r13 * cos(dum1 / 3.0);
  real[1] = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
  real[2] = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
}

void eigsort(double d[3])
{
  int k, j, i;
  double p;

  for(i = 0; i < 3; i++) {
    p = d[k = i];
    for(j = i + 1; j < 3; j++)
      if(d[j] >= p) p = d[k = j];
    if(k != i) {
      d[k] = d[i];
      d[i] = p;
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
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) { M(i - 1, j - 1) = MM[i - 1][j - 1]; }
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

bool newton_fd(bool (*func)(fullVector<double> &, fullVector<double> &, void *),
               fullVector<double> &x, void *data, double relax, double tolx)
{
  const int MAXIT = 100;
  const double EPS = 1.e-4;
  const int N = x.size();

  fullMatrix<double> J(N, N);
  fullVector<double> f(N), feps(N), dx(N);

  for(int iter = 0; iter < MAXIT; iter++) {
    if(x.norm() > 1.e6) return false;
    if(!func(x, f, data)) { return false; }

    bool isZero = false;
    for(int k = 0; k < N; k++) {
      if(f(k) == 0.)
        isZero = true;
      else
        isZero = false;
      if(isZero == false) break;
    }
    if(isZero) break;

    for(int j = 0; j < N; j++) {
      double h = EPS * fabs(x(j));
      if(h == 0.) h = EPS;
      x(j) += h;
      if(!func(x, feps, data)) { return false; }
      for(int i = 0; i < N; i++) { J(i, j) = (feps(i) - f(i)) / h; }
      x(j) -= h;
    }

    if(N == 1)
      dx(0) = f(0) / J(0, 0);
    else if(!J.luSolve(f, dx)) {
      return false;
    }

    for(int i = 0; i < N; i++) x(i) -= relax * dx(i);

    if(dx.norm() < tolx) { return true; }
  }
  return false;
}

/*
  distance to triangle

  P(p) = p1 + t1 xi + t2 eta

  t1 = (p2-p1) ; t2 = (p3-p1) ;

  (P(p) - p) = d n

  (p1 + t1 xi + t2 eta - p) = d n
  t1 xi + t2 eta - d n = p - p1

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

void signedDistancePointTriangle(const SPoint3 &p1, const SPoint3 &p2,
                                 const SPoint3 &p3, const SPoint3 &p, double &d,
                                 SPoint3 &closePt)
{
  SVector3 t1 = p2 - p1;
  SVector3 t2 = p3 - p1;
  SVector3 t3 = p3 - p2;
  SVector3 n = crossprod(t1, t2);
  n.normalize();
  const double n2t1 = dot(t1, t1);
  const double n2t2 = dot(t2, t2);
  const double n2t3 = dot(t3, t3);
  double mat[3][3] = {{t1.x(), t2.x(), -n.x()},
                      {t1.y(), t2.y(), -n.y()},
                      {t1.z(), t2.z(), -n.z()}};
  double inv[3][3];
  double det = inv3x3(mat, inv);
  if(det == 0.0) return;

  double u, v;
  SVector3 pp1 = p - p1;
  u = (inv[0][0] * pp1.x() + inv[0][1] * pp1.y() + inv[0][2] * pp1.z());
  v = (inv[1][0] * pp1.x() + inv[1][1] * pp1.y() + inv[1][2] * pp1.z());
  d = (inv[2][0] * pp1.x() + inv[2][1] * pp1.y() + inv[2][2] * pp1.z());
  double sign = (d > 0) ? 1. : -1.;
  if(d == 0.) sign = 1.;
  if(u >= 0. && v >= 0. && 1. - u - v >= 0.0) { // P(p) inside triangle
    closePt = p1 + (p2 - p1) * u + (p3 - p1) * v;
  }
  else {
    const double t12 = dot(pp1, t1) / n2t1;
    const double t13 = dot(pp1, t2) / n2t2;
    SVector3 pp2 = p - p2;
    const double t23 = dot(pp2, t3) / n2t3;
    d = 1.e10;
    if(t12 >= 0 && t12 <= 1.) {
      d = sign * std::min(fabs(d), p.distance(p1 + (p2 - p1) * t12));
      closePt = p1 + (p2 - p1) * t12;
    }
    if(t13 >= 0 && t13 <= 1.) {
      if(p.distance(p1 + (p3 - p1) * t13) < fabs(d))
        closePt = p1 + (p3 - p1) * t13;
      d = sign * std::min(fabs(d), p.distance(p1 + (p3 - p1) * t13));
    }
    if(t23 >= 0 && t23 <= 1.) {
      if(p.distance(p2 + (p3 - p2) * t23) < fabs(d))
        closePt = p2 + (p3 - p2) * t23;
      d = sign * std::min(fabs(d), p.distance(p2 + (p3 - p2) * t23));
    }
    if(p.distance(p1) < fabs(d)) {
      closePt = p1;
      d = sign * std::min(fabs(d), p.distance(p1));
    }
    if(p.distance(p2) < fabs(d)) {
      closePt = p2;
      d = sign * std::min(fabs(d), p.distance(p2));
    }
    if(p.distance(p3) < fabs(d)) {
      closePt = p3;
      d = sign * std::min(fabs(d), p.distance(p3));
    }
  }
}

void signedDistancesPointsTriangle(std::vector<double> &distances,
                                   std::vector<SPoint3> &closePts,
                                   const std::vector<SPoint3> &pts,
                                   const SPoint3 &p1, const SPoint3 &p2,
                                   const SPoint3 &p3)
{
  const unsigned pts_size = pts.size();
  distances.clear();
  distances.resize(pts_size);
  closePts.clear();
  closePts.resize(pts_size);

  for(std::size_t i = 0; i < pts_size; ++i) distances[i] = 1.e22;

  SVector3 t1 = p2 - p1;
  SVector3 t2 = p3 - p1;
  SVector3 t3 = p3 - p2;
  SVector3 n = crossprod(t1, t2);
  n.normalize();
  const double n2t1 = dot(t1, t1);
  const double n2t2 = dot(t2, t2);
  const double n2t3 = dot(t3, t3);
  double mat[3][3] = {{t1.x(), t2.x(), -n.x()},
                      {t1.y(), t2.y(), -n.y()},
                      {t1.z(), t2.z(), -n.z()}};
  double inv[3][3];
  double det = inv3x3(mat, inv);
  if(det == 0.0) return;

  for(std::size_t i = 0; i < pts.size(); i++) {
    double d;
    SPoint3 closePt;
    const SPoint3 &p = pts[i];

    // signedDistancePointTrianglePrecomputed(p1, p2, p3, p, d, closePt);
    double u, v;
    SVector3 pp1 = p - p1;
    u = (inv[0][0] * pp1.x() + inv[0][1] * pp1.y() + inv[0][2] * pp1.z());
    v = (inv[1][0] * pp1.x() + inv[1][1] * pp1.y() + inv[1][2] * pp1.z());
    d = (inv[2][0] * pp1.x() + inv[2][1] * pp1.y() + inv[2][2] * pp1.z());
    double sign = (d > 0) ? 1. : -1.;
    if(d == 0.) sign = 1.;
    if(u >= 0 && v >= 0 && 1. - u - v >= 0.0) {
      closePt = SPoint3(0., 0., 0.); // TO DO
    }
    else {
      const double t12 = dot(pp1, t1) / n2t1;
      const double t13 = dot(pp1, t2) / n2t2;
      SVector3 pp2 = p - p2;
      const double t23 = dot(pp2, t3) / n2t3;
      d = 1.e10;
      SPoint3 closePt;
      if(t12 >= 0 && t12 <= 1.) {
        d = sign * std::min(fabs(d), p.distance(p1 + (p2 - p1) * t12));
        closePt = p1 + (p2 - p1) * t12;
      }
      if(t13 >= 0 && t13 <= 1.) {
        if(p.distance(p1 + (p3 - p1) * t13) < fabs(d))
          closePt = p1 + (p3 - p1) * t13;
        d = sign * std::min(fabs(d), p.distance(p1 + (p3 - p1) * t13));
      }
      if(t23 >= 0 && t23 <= 1.) {
        if(p.distance(p2 + (p3 - p2) * t23) < fabs(d))
          closePt = p2 + (p3 - p2) * t23;
        d = sign * std::min(fabs(d), p.distance(p2 + (p3 - p2) * t23));
      }
      if(p.distance(p1) < fabs(d)) {
        closePt = p1;
        d = sign * std::min(fabs(d), p.distance(p1));
      }
      if(p.distance(p2) < fabs(d)) {
        closePt = p2;
        d = sign * std::min(fabs(d), p.distance(p2));
      }
      if(p.distance(p3) < fabs(d)) {
        closePt = p3;
        d = sign * std::min(fabs(d), p.distance(p3));
      }
    }
    // end signedDistance

    distances[i] = d;
    closePts[i] = closePt;
  }
}

void signedDistancePointLine(const SPoint3 &p1, const SPoint3 &p2,
                             const SPoint3 &p, double &d, SPoint3 &closePt,
                             const SVector3 &perp)
{
  SVector3 v12 = p2 - p1;
  SVector3 v1p = p - p1;
  const double alpha = dot(v1p, v12) / dot(v12, v12);
  if(alpha <= 0.)
    closePt = p1;
  else if(alpha >= 1.)
    closePt = p2;
  else
    closePt = p1 + (p2 - p1) * alpha;
  d = p.distance(closePt);

  if(perp.normSq() > 0) { // perpendicular direction is given, we can orient
    SVector3 vcp = p - closePt;
    SVector3 n = crossprod(v12, perp);
    double sign = dot(vcp, n);
    if(sign < 0) d *= -1.;
  }
}

void signedDistancesPointsLine(std::vector<double> &distances,
                               std::vector<SPoint3> &closePts,
                               const std::vector<SPoint3> &pts,
                               const SPoint3 &p1, const SPoint3 &p2,
                               const SVector3 &perp)
{
  distances.clear();
  distances.resize(pts.size());
  closePts.clear();
  closePts.resize(pts.size());
  for(std::size_t i = 0; i < pts.size(); i++) {
    double d;
    SPoint3 closePt;
    const SPoint3 &p = pts[i];
    signedDistancePointLine(p1, p2, p, d, closePt, perp);
    distances[i] = d;
    closePts[i] = closePt;
  }
}

void changeReferential(const int direction, const SPoint3 &p,
                       const SPoint3 &closePt, const SPoint3 &p1,
                       const SPoint3 &p2, double *xp, double *yp,
                       double *otherp, double *x, double *y, double *other)
{
  if(direction == 1) {
    const SPoint3 &d1 = SPoint3(1.0, 0.0, 0.0);
    const SPoint3 &d =
      SPoint3(p2.x() - p1.x(), p2.y() - p1.y(), p2.z() - p1.z());
    double norm = sqrt(d.x() * d.x() + d.y() * d.y() + d.z() * d.z());
    const SPoint3 &dn = SPoint3(d.x() / norm, d.y() / norm, d.z() / norm);
    const SPoint3 &d3 = SPoint3(d1.y() * dn.z() - d1.z() * dn.y(),
                                d1.z() * dn.x() - d1.x() * dn.z(),
                                d1.x() * dn.y() - d1.y() * dn.x());
    norm = sqrt(d3.x() * d3.x() + d3.y() * d3.y() + d3.z() * d3.z());
    const SPoint3 &d3n = SPoint3(d3.x() / norm, d3.y() / norm, d3.z() / norm);
    const SPoint3 &d2 = SPoint3(d3n.y() * d1.z() - d3n.z() * d1.y(),
                                d3n.z() * d1.x() - d3n.x() * d1.z(),
                                d3n.x() * d1.y() - d3n.y() * d1.x());
    norm = sqrt(d2.x() * d2.x() + d2.y() * d2.y() + d2.z() * d2.z());
    const SPoint3 &d2n = SPoint3(d2.x() / norm, d2.y() / norm, d2.z() / norm);
    *xp = p.x() * d1.x() + p.y() * d1.y() + p.z() * d1.z();
    *yp = p.x() * d3n.x() + p.y() * d3n.y() + p.z() * d3n.z();
    *otherp = p.x() * d2n.x() + p.y() * d2n.y() + p.z() * d2n.z();
    *x = closePt.x() * d1.x() + closePt.y() * d1.y() + closePt.z() * d1.z();
    *y = closePt.x() * d3n.x() + closePt.y() * d3n.y() + closePt.z() * d3n.z();
    *other =
      closePt.x() * d2n.x() + closePt.y() * d2n.y() + closePt.z() * d2n.z();
  }
  else {
    const SPoint3 &d2 = SPoint3(0.0, 1.0, 0.0);
    const SPoint3 &d =
      SPoint3(p2.x() - p1.x(), p2.y() - p1.y(), p2.z() - p1.z());
    double norm = sqrt(d.x() * d.x() + d.y() * d.y() + d.z() * d.z());
    const SPoint3 &dn = SPoint3(d.x() / norm, d.y() / norm, d.z() / norm);
    const SPoint3 &d3 = SPoint3(dn.y() * d2.z() - dn.z() * d2.y(),
                                dn.z() * d2.x() - dn.x() * d2.z(),
                                dn.x() * d2.y() - dn.y() * d2.x());
    norm = sqrt(d3.x() * d3.x() + d3.y() * d3.y() + d3.z() * d3.z());
    const SPoint3 &d3n = SPoint3(d3.x() / norm, d3.y() / norm, d3.z() / norm);
    const SPoint3 &d1 = SPoint3(d2.y() * d3n.z() - d2.z() * d3n.y(),
                                d2.z() * d3n.x() - d2.x() * d3n.z(),
                                d2.x() * d3n.y() - d2.y() * d3n.x());
    norm = sqrt(d1.x() * d1.x() + d1.y() * d1.y() + d1.z() * d1.z());
    const SPoint3 &d1n = SPoint3(d1.x() / norm, d1.y() / norm, d1.z() / norm);
    *xp = p.x() * d2.x() + p.y() * d2.y() + p.z() * d2.z();
    *yp = p.x() * d3n.x() + p.y() * d3n.y() + p.z() * d3n.z();
    *otherp = p.x() * d1n.x() + p.y() * d1n.y() + p.z() * d1n.z();
    *x = closePt.x() * d2.x() + closePt.y() * d2.y() + closePt.z() * d2.z();
    *y = closePt.x() * d3n.x() + closePt.y() * d3n.y() + closePt.z() * d3n.z();
    *other =
      closePt.x() * d1n.x() + closePt.y() * d1n.y() + closePt.z() * d1n.z();
  }
}

int computeDistanceRatio(const double &y, const double &yp, const double &x,
                         const double &xp, double *distance, const double &r1,
                         const double &r2)
{
  double b;
  double a;
  if(y == yp) {
    b = -y;
    a = 0.0;
  }
  else {
    if(x == xp) {
      b = -x;
      a = 0.0;
    }
    else {
      b = (xp * y - x * yp) / (yp - y);
      if(yp == 0.0) { a = -(b + x) / y; }
      else {
        a = -(b + xp) / yp;
      }
    }
  }
  double ae;
  double be;
  double ce;
  double da = r1 * r1;
  double db = r2 * r2;
  if(y == yp) {
    ae = 1.0 / da;
    be = -(2 * x) / da;
    ce = (x * x / da) - 1.0;
  }
  else {
    if(x == xp) {
      ae = 1.0 / db;
      be = -(2.0 * y) / db;
      ce = (y * y / db) - 1.0;
    }
    else {
      if(fabs(a) < 0.00001) {
        ae = 1.0 / db;
        be = -(2.0 * y) / db;
        ce = (y * y / db) - 1.0;
      }
      else {
        double a2 = a * a;
        ae = (1.0 / da) + (1.0 / (db * a2));
        be = (2.0 * y) / (db * a) + (2.0 * b) / (a2 * db) - ((2.0 * x) / da);
        ce = (x * x) / da + (b * b) / (db * a2) + (2.0 * b * y) / (a * db) +
             (y * y / db) - 1.0;
      }
    }
  }
  double rho = be * be - 4 * ae * ce;
  double x1, x2, y1, y2, propdist;
  if(rho < 0) { return 1; }
  else {
    x1 = -(be + sqrt(rho)) / (2.0 * ae);
    x2 = (-be + sqrt(rho)) / (2.0 * ae);
    if(y == yp) {
      y1 = -b;
      y2 = -b;
    }
    else {
      if(x == xp) {
        y1 = x1;
        y2 = x2;
        x1 = -b;
        x2 = -b;
      }
      else {
        if(fabs(a) < 0.00001) {
          y1 = x1;
          y2 = x2;
          x1 = -b;
          x2 = -b;
        }
        else {
          y1 = -(b + x1) / a;
          y2 = -(b + x2) / a;
        }
      }
    }
    if(x1 == x2) {
      propdist = (y1 - y) / (yp - y);
      if(propdist < 0.0) { propdist = (y2 - y) / (yp - y); }
    }
    else {
      if(xp != x) {
        propdist = (x1 - x) / (xp - x);
        if(propdist < 0.0) { propdist = (x2 - x) / (xp - x); }
      }
      else {
        if(yp != y) {
          propdist = (y1 - y) / (yp - y);
          if(propdist < 0.0) { propdist = (y2 - y) / (yp - y); }
        }
        else {
          propdist = 0.01;
        }
      }
    }
    *distance = propdist;
    return 0;
  }
}

void signedDistancesPointsEllipsePoint(std::vector<double> &distances,
                                       std::vector<double> &distancesE,
                                       std::vector<int> &isInYarn,
                                       std::vector<SPoint3> &closePts,
                                       const std::vector<SPoint3> &pts,
                                       const SPoint3 &p1, const SPoint3 &p2,
                                       const double radius)
{
  distances.clear();
  distances.resize(pts.size());
  distancesE.clear();
  distancesE.resize(pts.size());
  isInYarn.clear();
  isInYarn.resize(pts.size());
  closePts.clear();
  closePts.resize(pts.size());
  double d;
  for(std::size_t i = 0; i < pts.size(); i++) {
    SPoint3 closePt;
    const SPoint3 &p = pts[i];
    signedDistancePointLine(p1, p2, p, d, closePt);
    closePts[i] = closePt;
    distances[i] = d;
    if(d <= radius) {
      isInYarn[i] = 1;
      distancesE[i] = radius - d;
    }
    else {
      isInYarn[i] = 0;
      distancesE[i] = d - radius;
    }
  }
}

void signedDistancesPointsEllipseLine(
  std::vector<double> &distances, std::vector<double> &distancesE,
  std::vector<int> &isInYarn, std::vector<SPoint3> &closePts,
  const std::vector<SPoint3> &pts, const SPoint3 &p1, const SPoint3 &p2,
  const double maxA, const double minA, const double maxB, const double minB,
  const int typeLevelSet)
{
  distances.clear();
  distances.resize(pts.size());
  distancesE.clear();
  distancesE.resize(pts.size());
  isInYarn.clear();
  isInYarn.resize(pts.size());
  closePts.clear();
  closePts.resize(pts.size());
  double d;
  for(std::size_t i = 0; i < pts.size(); i++) {
    SPoint3 closePt;
    const SPoint3 &p = pts[i];
    signedDistancePointLine(p1, p2, p, d, closePt);

    distances[i] = d;
    closePts[i] = closePt;
    int direction = 0;
    if(!(p.x() == closePt.x() && p.y() == closePt.y() &&
         p.z() == closePt.z())) {
      double xp, yp, x, y, otherp, other, propdist;
      if(typeLevelSet == 2) {
        if(p1.x() == p2.x()) {
          direction = 1;
          if(fabs(closePt.x() - 0.0) < 0.00000001) isInYarn[i] = 1;
          if(fabs(closePt.x() - 2.2) < 0.00000001) isInYarn[i] = 1;
        }
        else {
          if(p1.y() == p2.y()) {
            direction = 2;
            if(fabs(closePt.y() - 0.0) < 0.00000001) isInYarn[i] = 6;
            if(fabs(closePt.y() - 2.2) < 0.00000001) isInYarn[i] = 6;
          }
          else {
            printf("Error %lf %lf\n", closePt.x(), closePt.y());
          }
        }
      }
      if(typeLevelSet == 1) {
        if(p1.x() == p2.x()) {
          direction = 1;
          // if (fabs(closePt.x() - 0.0) < 0.00000001) isInYarn[i] = 1;
          if(fabs(closePt.x() - 2.2) < 0.00000001) isInYarn[i] = 4;
          // if (fabs(closePt.x() - 4.4) < 0.00000001) isInYarn[i] = 2;
          // if (fabs(closePt.x() - 6.6) < 0.00000001) isInYarn[i] = 5;
          // if (fabs(closePt.x() - 8.8) < 0.00000001) isInYarn[i] = 3;
          // if (fabs(closePt.x() - 11.0) < 0.00000001) isInYarn[i] = 1;
        }
        else {
          if(p1.y() == p2.y()) {
            direction = 2;
            // if (fabs(closePt.y() - 0.0) < 0.00000001) isInYarn[i] = 6;
            if(fabs(closePt.y() - 2.2) < 0.00000001) isInYarn[i] = 7;
            // if (fabs(closePt.y() - 4.4) < 0.00000001) isInYarn[i] = 8;
            // if (fabs(closePt.y() - 6.6) < 0.00000001) isInYarn[i] = 9;
            // if (fabs(closePt.y() - 8.8) < 0.00000001) isInYarn[i] = 10;
            // if (fabs(closePt.y() - 11.0) < 0.00000001) isInYarn[i] = 6;
          }
          else {
            printf("Error %lf %lf\n", closePt.x(), closePt.y());
          }
        }
      }
      if(typeLevelSet == 4) {
        if(p1.x() == p2.x()) {
          direction = 1;
          if(fabs(closePt.x() - 0.0) < 0.00000001 && closePt.z() <= 0.35)
            isInYarn[i] = 1;
          if(fabs(closePt.x() - 2.2) < 0.00000001 && closePt.z() <= 0.35)
            isInYarn[i] = 4;
          if(fabs(closePt.x() - 4.4) < 0.00000001 && closePt.z() <= 0.35)
            isInYarn[i] = 2;
          if(fabs(closePt.x() - 6.6) < 0.00000001 && closePt.z() <= 0.35)
            isInYarn[i] = 5;
          if(fabs(closePt.x() - 8.8) < 0.00000001 && closePt.z() <= 0.35)
            isInYarn[i] = 3;
          if(fabs(closePt.x() - 11.0) < 0.00000001 && closePt.z() <= 0.35)
            isInYarn[i] = 1;
          if(fabs(closePt.x() - 0.0) < 0.00000001 && closePt.z() > 0.35)
            isInYarn[i] = 11;
          if(fabs(closePt.x() - 2.2) < 0.00000001 && closePt.z() > 0.35)
            isInYarn[i] = 14;
          if(fabs(closePt.x() - 4.4) < 0.00000001 && closePt.z() > 0.35)
            isInYarn[i] = 12;
          if(fabs(closePt.x() - 6.6) < 0.00000001 && closePt.z() > 0.35)
            isInYarn[i] = 15;
          if(fabs(closePt.x() - 8.8) < 0.00000001 && closePt.z() > 0.35)
            isInYarn[i] = 13;
          if(fabs(closePt.x() - 11.0) < 0.00000001 && closePt.z() > 0.35)
            isInYarn[i] = 11;
        }
        else {
          if(p1.y() == p2.y()) {
            direction = 2;
            if(fabs(closePt.y() - 0.0) < 0.00000001 && closePt.z() <= 0.35)
              isInYarn[i] = 6;
            if(fabs(closePt.y() - 2.2) < 0.00000001 && closePt.z() <= 0.35)
              isInYarn[i] = 7;
            if(fabs(closePt.y() - 4.4) < 0.00000001 && closePt.z() <= 0.35)
              isInYarn[i] = 8;
            if(fabs(closePt.y() - 6.6) < 0.00000001 && closePt.z() <= 0.35)
              isInYarn[i] = 9;
            if(fabs(closePt.y() - 8.8) < 0.00000001 && closePt.z() <= 0.35)
              isInYarn[i] = 10;
            if(fabs(closePt.y() - 11.0) < 0.00000001 && closePt.z() <= 0.35)
              isInYarn[i] = 6;
            if(fabs(closePt.y() - 0.0) < 0.00000001 && closePt.z() > 0.35)
              isInYarn[i] = 16;
            if(fabs(closePt.y() - 2.2) < 0.00000001 && closePt.z() > 0.35)
              isInYarn[i] = 17;
            if(fabs(closePt.y() - 4.4) < 0.00000001 && closePt.z() > 0.35)
              isInYarn[i] = 18;
            if(fabs(closePt.y() - 6.6) < 0.00000001 && closePt.z() > 0.35)
              isInYarn[i] = 19;
            if(fabs(closePt.y() - 8.8) < 0.00000001 && closePt.z() > 0.35)
              isInYarn[i] = 20;
            if(fabs(closePt.y() - 11.0) < 0.00000001 && closePt.z() > 0.35)
              isInYarn[i] = 16;
          }
          else {
            printf("Error %lf %lf\n", closePt.x(), closePt.y());
          }
        }
      }
      if(typeLevelSet == 3) {
        direction = 3;
        isInYarn[i] = 1;
      }
      if(typeLevelSet == 5) {
        if(p1.x() == p2.x()) {
          direction = 1;
          if(fabs(closePt.x() - 0.0) < 0.00000001) isInYarn[i] = 1;
          if(fabs(closePt.x() - 3.225) < 0.00000001) isInYarn[i] = 2;
          if(fabs(closePt.x() - 6.45) < 0.00000001) isInYarn[i] = 3;
          if(fabs(closePt.x() - 9.675) < 0.00000001) isInYarn[i] = 4;
          if(fabs(closePt.x() - 12.9) < 0.00000001) isInYarn[i] = 1;
        }
        else {
          if(p1.y() == p2.y()) {
            direction = 2;
            if(fabs(closePt.y() - 0.0) < 0.00000001) isInYarn[i] = 5;
            if(fabs(closePt.y() - 1.665) < 0.00000001) isInYarn[i] = 6;
            if(fabs(closePt.y() - 3.33) < 0.00000001) isInYarn[i] = 7;
            if(fabs(closePt.y() - 4.995) < 0.00000001) isInYarn[i] = 8;
            if(fabs(closePt.y() - 6.66) < 0.00000001) isInYarn[i] = 5;
          }
          else {
            printf("Error %lf %lf\n", closePt.x(), closePt.y());
          }
        }
      }
      changeReferential(direction, p, closePt, p1, p2, &xp, &yp, &otherp, &x,
                        &y, &other);
      int result = 1;
      if(fabs(other - otherp) > 0.01) { result = 1; }
      else {
        if(direction == 1) {
          result = computeDistanceRatio(y, yp, x, xp, &propdist, maxA, minA);
        }
        else {
          if(direction == 2) {
            result = computeDistanceRatio(y, yp, x, xp, &propdist, maxB, minB);
          }
        }
      }
      if(result == 1) {
        distancesE[i] = 1.e10;
        isInYarn[i] = 0;
      }
      else {
        if(propdist < 1.0) {
          isInYarn[i] = 0;
          distancesE[i] = (1.0 / propdist) - 1.0;
        }
        else {
          distancesE[i] = (1.0 - (1.0 / propdist));
        }
      }
    }
    else {
      isInYarn[i] = 0;
      distancesE[i] = 1000000.0;
    }
  }
}

int intersection_segments(const SPoint2 &p1, const SPoint2 &p2,
                          const SPoint2 &q1, const SPoint2 &q2, double x[2])
{
  double xp_max = std::max(p1.x(), p2.x());
  double yp_max = std::max(p1.y(), p2.y());
  double xq_max = std::max(q1.x(), q2.x());
  double yq_max = std::max(q1.y(), q2.y());

  double xp_min = std::min(p1.x(), p2.x());
  double yp_min = std::min(p1.y(), p2.y());
  double xq_min = std::min(q1.x(), q2.x());
  double yq_min = std::min(q1.y(), q2.y());
  if(yq_min > yp_max || xq_min > xp_max || yq_max < yp_min || xq_max < xp_min) {
    return 0;
  }
  else {
    double A[2][2];
    A[0][0] = p2.x() - p1.x();
    A[0][1] = q1.x() - q2.x();
    A[1][0] = p2.y() - p1.y();
    A[1][1] = q1.y() - q2.y();
    double b[2] = {q1.x() - p1.x(), q1.y() - p1.y()};
    sys2x2(A, b, x);
    return (x[0] >= 0.0 && x[0] <= 1. && x[1] >= 0.0 && x[1] <= 1.);
  }
}
/// 3D VERSION
int intersection_segments(const SPoint3 &p1, const SPoint3 &p2,
                          const SPoint3 &q1, const SPoint3 &q2, double x[2])
{
  SVector3 v1(p2, p1), v2(q2, q1);
  double n1 = v1.norm();
  double n2 = v2.norm();
  double EPS = 1.e-10 * std::max(n1, n2);
  double A[2][2];
  A[0][0] = p2.x() - p1.x();
  A[0][1] = q1.x() - q2.x();
  A[1][0] = p2.y() - p1.y();
  A[1][1] = q1.y() - q2.y();
  double a[2] = {q1.x() - p1.x(), q1.y() - p1.y()};
  double B[2][2];
  B[0][0] = p2.z() - p1.z();
  B[0][1] = q1.z() - q2.z();
  B[1][0] = p2.y() - p1.y();
  B[1][1] = q1.y() - q2.y();
  double b[2] = {q1.z() - p1.z(), q1.y() - p1.y()};
  double C[2][2];
  C[0][0] = p2.z() - p1.z();
  C[0][1] = q1.z() - q2.z();
  C[1][0] = p2.x() - p1.x();
  C[1][1] = q1.x() - q2.x();
  double c[2] = {q1.z() - p1.z(), q1.x() - p1.x()};
  double detA = fabs(det2x2(A));
  double detB = fabs(det2x2(B));
  double detC = fabs(det2x2(C));
  //  printf("%12.5E %12.5E %12.5E\n",detA,detB,detC);
  if(detA > detB && detA > detC)
    sys2x2(A, a, x);
  else if(detB > detA && detB > detC)
    sys2x2(B, b, x);
  else
    sys2x2(C, c, x);
  if(x[0] >= 0.0 && x[0] <= 1. && x[1] >= 0.0 && x[1] <= 1.) {
    SPoint3 x1(p1.x() * (1. - x[0]) + p2.x() * x[0],
               p1.y() * (1. - x[0]) + p2.y() * x[0],
               p1.z() * (1. - x[0]) + p2.z() * x[0]);
    SPoint3 x2(q1.x() * (1. - x[1]) + q2.x() * x[1],
               q1.y() * (1. - x[1]) + q2.y() * x[1],
               q1.z() * (1. - x[1]) + q2.z() * x[1]);

    SVector3 d(x2, x1);
    double nd = norm(d);
    if(nd > EPS) {
      x[0] = x[1] = 1.e22;
      return false;
    }
    return true;
  }
  return false;
}

void fillMeanPlane(double res[4], double t1[3], double t2[3],
                   mean_plane &meanPlane)
{
  for(int i = 0; i < 3; i++) meanPlane.plan[0][i] = t1[i];
  for(int i = 0; i < 3; i++) meanPlane.plan[1][i] = t2[i];
  for(int i = 0; i < 3; i++) meanPlane.plan[2][i] = res[i];

  meanPlane.a = res[0];
  meanPlane.b = res[1];
  meanPlane.c = res[2];
  meanPlane.d = res[3];

  meanPlane.x = meanPlane.y = meanPlane.z = 0.;
  if(fabs(meanPlane.a) >= fabs(meanPlane.b) &&
     fabs(meanPlane.a) >= fabs(meanPlane.c)) {
    meanPlane.x = meanPlane.d / meanPlane.a;
  }
  else if(fabs(meanPlane.b) >= fabs(meanPlane.a) &&
          fabs(meanPlane.b) >= fabs(meanPlane.c)) {
    meanPlane.y = meanPlane.d / meanPlane.b;
  }
  else {
    meanPlane.z = meanPlane.d / meanPlane.c;
  }
}

void computeMeanPlaneSimple(const std::vector<SPoint3> &points,
                            mean_plane &meanPlane)
{
  double xm = 0., ym = 0., zm = 0.;
  int ndata = points.size();
  int na = 3;
  for(int i = 0; i < ndata; i++) {
    xm += points[i].x();
    ym += points[i].y();
    zm += points[i].z();
  }
  xm /= (double)ndata;
  ym /= (double)ndata;
  zm /= (double)ndata;

  fullMatrix<double> U(ndata, na), V(na, na);
  fullVector<double> sigma(na);
  for(int i = 0; i < ndata; i++) {
    U(i, 0) = points[i].x() - xm;
    U(i, 1) = points[i].y() - ym;
    U(i, 2) = points[i].z() - zm;
  }
  U.svd(V, sigma);
  double res[4], svd[3];
  svd[0] = sigma(0);
  svd[1] = sigma(1);
  svd[2] = sigma(2);
  int min;
  if(fabs(svd[0]) < fabs(svd[1]) && fabs(svd[0]) < fabs(svd[2]))
    min = 0;
  else if(fabs(svd[1]) < fabs(svd[0]) && fabs(svd[1]) < fabs(svd[2]))
    min = 1;
  else
    min = 2;
  res[0] = V(0, min);
  res[1] = V(1, min);
  res[2] = V(2, min);
  norme(res);

  double ex[3], t1[3], t2[3];

  ex[0] = ex[1] = ex[2] = 0.0;
  if(res[0] == 0.)
    ex[0] = 1.0;
  else if(res[1] == 0.)
    ex[1] = 1.0;
  else
    ex[2] = 1.0;

  prodve(res, ex, t1);
  norme(t1);
  prodve(t1, res, t2);
  norme(t2);

  res[3] = (xm * res[0] + ym * res[1] + zm * res[2]);

  fillMeanPlane(res, t1, t2, meanPlane);
}

void projectPointToPlane(const SPoint3 &pt, SPoint3 &ptProj,
                         const mean_plane &meanPlane)
{
  double u = pt.x();
  double v = pt.y();
  double w = pt.z();
  double a = meanPlane.a;
  double b = meanPlane.b;
  double c = meanPlane.c;
  double d = meanPlane.d;
  double t0 = -(a * u + b * v + c * w + d) / (a * a + b * b + c * c);

  ptProj[0] = u + a * t0;
  ptProj[1] = v + b * t0;
  ptProj[2] = w + c * t0;
}

void projectPointsToPlane(const std::vector<SPoint3> &pts,
                          std::vector<SPoint3> &ptsProj,
                          const mean_plane &meanPlane)
{
  ptsProj.resize(pts.size());
  for(std::size_t i = 0; i < pts.size(); i++) {
    projectPointToPlane(pts[i], ptsProj[i], meanPlane);
  }
}

void transformPointsIntoOrthoBasis(const std::vector<SPoint3> &ptsProj,
                                   std::vector<SPoint3> &pointsUV,
                                   const SPoint3 &ptCG,
                                   const mean_plane &meanPlane)
{
  pointsUV.resize(ptsProj.size());
  SVector3 normal(meanPlane.a, meanPlane.b, meanPlane.c);
  SVector3 tangent, binormal;
  buildOrthoBasis(normal, tangent, binormal);

  for(std::size_t i = 0; i < ptsProj.size(); i++) {
    SVector3 pp(ptsProj[i][0] - ptCG[0], ptsProj[i][1] - ptCG[1],
                ptsProj[i][2] - ptCG[2]);
    pointsUV[i][0] = dot(pp, tangent);
    pointsUV[i][1] = dot(pp, binormal);
    pointsUV[i][2] = dot(pp, normal);
  }
}

static bool catenary_fct(fullVector<double> &x, fullVector<double> &res,
                         void *data)
{
  double *param = (double *)data;
  double x0 = param[0], x1 = param[1], y0 = param[2], y1 = param[3],
         ys = param[4];
  res(0) = (ys - 1 / x(0)) + 1 / x(0) * cosh(x(0) * (x0 - x(1))) - y0;
  res(1) = (ys - 1 / x(0)) + 1 / x(0) * cosh(x(0) * (x1 - x(1))) - y1;
  return true;
}

bool catenary(double x0, double x1, double y0, double y1, double ys, int N,
              double *yp)
{
  // In the z=0 plane, catenary equation is y(x) = a + 1/b cosh(b(x-c))
  //
  // Three parameters a, b, c determined by imposing
  // - left point: y0 = y(x0) = a + 1/b cosh(b(x0-c))
  // - right point: y1 = y(x1) = a + 1/b cosh(b(x1-c))
  // - lowest point: ys = y(c) = a + 1/b , i.e. a = ys - 1/b
  //
  // Thus solve syst of 2 nl equations with 2 unknowns b and c:
  //
  // ys - 1/b + 1/b cosh(b(x0-c)) - y0 = 0
  // ys - 1/b + 1/b cosh(b(x1-c)) - y1 = 0
  double param[5] = {x0, x1, y0, y1, ys};
  fullVector<double> x(2);
  bool success = false, physical = true;
  double tolx = 1e-6 * fabs(x1 - x0);
  double toly = 1e-6 * fabs(std::max(y0, y1) - ys);
  if(x0 != x1) {
    x(0) = 1. / (x1 - x0);
    x(1) = (x0 + x1) / 2.;
    success = newton_fd(catenary_fct, x, param, 1, tolx);
  }
  if(success) {
    double a = ys - 1 / x(0);
    for(int i = 0; i < N; i++) {
      double r = x0 + (i + 1) * (x1 - x0) / (N + 1);
      yp[i] = a + 1 / x(0) * cosh(x(0) * (r - x(1)));
      if(yp[i] > std::max(y0, y1) + toly || yp[i] < ys - toly) {
        physical = false;
        break;
      }
    }
  }
  if(physical) return true;

  // could not solve: return linear interpolation
  for(int i = 0; i < N; i++) { yp[i] = y0 + (i + 1) * (y1 - y0) / (N + 1); }
  return false;
}
