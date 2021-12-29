// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef NUMERIC_H
#define NUMERIC_H

#include <cmath>
#include <vector>

#include "SPoint2.h"
#include "SPoint3.h"
#include "SVector3.h"

template <class scalar> class fullVector;

template <class T> inline double myhypot(const T &a, const T &b)
{
  return std::sqrt(a * a + b * b);
}

template <class T> inline double hypotenuse(T const &a, T const &b, T const &c)
{
  return std::sqrt(a * a + b * b + c * c);
}

template <typename T> inline int gmsh_sign(T const &value)
{
  return (T(0) < value) - (value < T(0));
}

struct mean_plane {
  double plan[3][3];
  double a, b, c, d;
  double x, y, z;
};

inline double pow_int(const double &a, const int &n)
{
  if(n < 0) return pow_int(1 / a, -n);

  switch(n) {
  case 0: return 1.0;
  case 1: return a;
  case 2: return a * a;
  case 3: return a * a * a;
  case 4: {
    const double a2 = a * a;
    return a2 * a2;
  }
  case 5: {
    const double a2 = a * a;
    return a2 * a2 * a;
  }
  case 6: {
    const double a3 = a * a * a;
    return a3 * a3;
  }
  case 7: {
    const double a3 = a * a * a;
    return a3 * a3 * a;
  }
  case 8: {
    const double a2 = a * a;
    const double a4 = a2 * a2;
    return a4 * a4;
  }
  case 9: {
    const double a3 = a * a * a;
    return a3 * a3 * a3;
  }
  case 10: {
    const double a2 = a * a;
    const double a4 = a2 * a2;
    return a4 * a4 * a2;
  }
  default: return pow_int(a, n - 10) * pow_int(a, 10);
  }
}

inline double pow_int(const double &a, const double &d)
{
  // Round double !
  int n = static_cast<int>(d + .5);
  return pow_int(a, n);
}

double myatan2(double a, double b);
double myasin(double a);
double myacos(double a);

inline double crossProd(double a[3], double b[3], int i)
{
  int i1 = (i + 1) % 3;
  int i2 = (i + 2) % 3;
  return a[i1] * b[i2] - a[i2] * b[i1];
}

inline double scalProd(double a[3], double b[3])
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

inline void prodve(double a[3], double b[3], double c[3])
{
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

inline double prosca(double const a[3], double const b[3])
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void matvec(double mat[3][3], double vec[3], double res[3]);
void matmat(double mat1[3][3], double mat2[3][3], double res[3][3]);
inline double norm3(double a[3])
{
  return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}
inline double norme(double a[3])
{
  const double mod = norm3(a);
  if(mod != 0.0) {
    const double one_over_mod = 1. / mod;
    a[0] *= one_over_mod;
    a[1] *= one_over_mod;
    a[2] *= one_over_mod;
  }
  return mod;
}
double norm2(double a[3][3]);

void normal3points(double x0, double y0, double z0, double x1, double y1,
                   double z1, double x2, double y2, double z2, double n[3]);
void normal2points(double x0, double y0, double z0, double x1, double y1,
                   double z1, double n[3]);
int sys2x2(double mat[2][2], double b[2], double res[2]);
int sys3x3(double mat[3][3], double b[3], double res[3], double *det);
int sys3x3_with_tol(double mat[3][3], double b[3], double res[3], double *det);
double det2x2(double mat[2][2]);
double det2x3(double mat[2][3]);
double det3x3(double mat[3][3]);
double trace3x3(double mat[3][3]);
double trace2(double mat[3][3]);
double inv3x3(double mat[3][3], double inv[3][3]);
double inv2x2(double mat[2][2], double inv[2][2]);
double angle_02pi(double A3);
double angle_plan(double v[3], double p1[3], double p2[3], double n[3]);
double triangle_area(double p0[3], double p1[3], double p2[3]);
double triangle_area2d(double p0[2], double p1[2], double p2[2]);
void circumCenterXY(double *p1, double *p2, double *p3, double *res);
void circumCenterXYZ(double *p1, double *p2, double *p3, double *res,
                     double *uv = nullptr);
// operate a transformation on the 4 points of a Quad in 3D, to have an
// equivalent Quad in 2D
void planarQuad_xyz2xy(double *x, double *y, double *z, double *xn, double *yn);
// compute the radius of the circle that is tangent to the 3 edges defined by 4
// points edge_1=(x0,y0)->(x1,y1); edge_2=(x1,y1)->(x2,y2);
// edge_3=(x2,y2)->(x3,y3)
double computeInnerRadiusForQuad(double *x, double *y, int i);
char float2char(float f);
float char2float(char c);
void eigenvalue2x2(double mat[2][2], double v[2]);
void eigenvalue(double mat[3][3], double re[3]);
void FindCubicRoots(const double coeff[4], double re[3], double im[3]);
void eigsort(double d[3]);
void gradSimplex(double *x, double *y, double *z, double *v, double *grad);
double ComputeVonMises(double *val);
double ComputeScalarRep(int numComp, double *val, int tensorRep = 0);
void invert_singular_matrix3x3(double MM[3][3], double II[3][3]);
bool newton_fd(bool (*func)(fullVector<double> &, fullVector<double> &, void *),
               fullVector<double> &x, void *data, double relax = 1.,
               double tolx = 1.e-6);

void signedDistancePointTriangle(const SPoint3 &p1, const SPoint3 &p2,
                                 const SPoint3 &p3, const SPoint3 &p, double &d,
                                 SPoint3 &closePt);

void signedDistancesPointsTriangle(std::vector<double> &distances,
                                   std::vector<SPoint3> &closePts,
                                   const std::vector<SPoint3> &pts,
                                   const SPoint3 &p1, const SPoint3 &p2,
                                   const SPoint3 &p3);

void signedDistancePointLine(const SPoint3 &p1, const SPoint3 &p2,
                             const SPoint3 &p, double &distance,
                             SPoint3 &closePt);
void signedDistancesPointsLine(std::vector<double> &distances,
                               std::vector<SPoint3> &closePts,
                               const std::vector<SPoint3> &pts,
                               const SPoint3 &p1, const SPoint3 &p2);

void changeReferential(const int direction, const SPoint3 &p,
                       const SPoint3 &closePt, const SPoint3 &p1,
                       const SPoint3 &p2, double *xp, double *yp,
                       double *otherp, double *x, double *y, double *other);
int computeDistanceRatio(const double &y, const double &yp, const double &x,
                         const double &xp, double *distance, const double &r1,
                         const double &r2);

void signedDistancesPointsEllipsePoint(std::vector<double> &distances,
                                       std::vector<double> &distancesE,
                                       std::vector<int> &isInYarn,
                                       std::vector<SPoint3> &closePts,
                                       const std::vector<SPoint3> &pts,
                                       const SPoint3 &p1, const SPoint3 &p2,
                                       const double radius);

void signedDistancesPointsEllipseLine(
  std::vector<double> &distances, std::vector<double> &distancesE,
  std::vector<int> &isInYarn, std::vector<SPoint3> &closePts,
  const std::vector<SPoint3> &pts, const SPoint3 &p1, const SPoint3 &p2,
  const double maxA, const double minA, const double maxB, const double minB,
  const int typeLevelSet);

int intersection_segments(const SPoint3 &p1, const SPoint3 &p2,
                          const SPoint3 &q1, const SPoint3 &q2, double x[2]);
int intersection_segments(const SPoint2 &p1, const SPoint2 &p2,
                          const SPoint2 &q1, const SPoint2 &q2, double x[2]);

// tools for projection onto plane
void fillMeanPlane(double res[4], double t1[3], double t2[3],
                   mean_plane &meanPlane);
void computeMeanPlaneSimple(const std::vector<SPoint3> &points,
                            mean_plane &meanPlane);
void projectPointToPlane(const SPoint3 &pt, SPoint3 &ptProj,
                         const mean_plane &meanPlane);
void projectPointsToPlane(const std::vector<SPoint3> &pts,
                          std::vector<SPoint3> &ptsProj,
                          const mean_plane &meanPlane);
void transformPointsIntoOrthoBasis(const std::vector<SPoint3> &ptsProj,
                                   std::vector<SPoint3> &pointsUV,
                                   const SPoint3 &ptCG,
                                   const mean_plane &meanPlane);

bool catenary(double x0, double x1, double y0, double y1, double ys, int N,
              double *yp);

#endif
