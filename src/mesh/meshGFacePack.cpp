// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <vector>
#include <cstdint>
#include "gmsh.h"
#include "SPoint2.h"
#include "SVector3.h"
#include "meshTriangulation.h"
#include "robustPredicates.h"

static void analyze2dMetric(std::vector<double> &val, double &C, double &S,
                            double &h1, double &h2)
{
  double a = val[0];
  double c = val[1];
  double b = val[4];
  double l1 = 0.5 * (a + b + sqrt((a - b) * (a - b) + 4 * c * c));
  double l2 = 0.5 * (a + b - sqrt((a - b) * (a - b) + 4 * c * c));
  //  printf("%12.5E %12.5E %12.5E %12.5E %12.5E\n",l1,l2,a,b,c);
  h1 = 1. / sqrt(l1);
  h2 = 1. / sqrt(l2);
  double theta = 0.5 * atan2(2 * c, a - b);
  C = cos(theta);
  S = sin(theta);
}

double bestParabola(double x0, double y0, double x1, double y1, double &xmid,
                    double &ymid, int VIEW_TAG);
double objectiveFunction_L(double x0, double y0, double xt, double yt,
                           double x1, double y1, int VIEW_TAG);

static double maxDir(double &c, double &s, double &h, const double &C,
                     const double &S, const double &H1, const double &H2)
{
  double PV1 = c * C + s * S;
  double PV2 = s * C - c * S;
  double PV3 = -c * C - s * S;
  double PV4 = -s * C + c * S;
  if(PV1 > PV2 && PV1 > PV3 && PV1 > PV4) {
    c = C;
    s = S;
    h = H1;
    return PV1;
  }
  else if(PV2 > PV3 && PV2 > PV4) {
    c = -S;
    s = C;
    h = H2;
    return PV2;
  }
  else if(PV3 > PV4) {
    c = -C;
    s = -S;
    h = H1;
    return PV3;
  }
  else {
    c = S;
    s = -C;
    h = H2;
    return PV4;
  }
}

static int check_triangle_validity_2d(double *xa, double *xb, double *xc)
{
  return -robustPredicates::orient2d(xa, xb, xc) > 1.e-16;
}

static double interpolateTriangleP2(double xi, double eta, double v0, double v1,
                                    double v2, double v3, double v4, double v5)
{
  double L0 = (1 - xi - eta) * (1 - 2 * xi - 2 * eta);
  double L1 = xi * (2 * xi - 1);
  double L2 = eta * (2 * eta - 1);
  double L3 = 4 * xi * (1 - xi - eta);
  double L4 = 4 * xi * eta;
  double L5 = 4 * eta * (1 - xi - eta);

  return L0 * v0 + L1 * v1 + L2 * v2 + L3 * v3 + L4 * v4 + L5 * v5;
}

static void derivativeP2(double u, double v, double dfdu[6], double dfdv[6])
{
  /*  const double sf[6][6] = { { 1, -3, -3,  4,  2,  2},
                                { 0, -1,  0,  0,  2,  0},
                                { 0,  0, -1,  0,  0,  2},
                                { 0,  4,  0, -4, -4,  0},
                                { 0,  0,  0,  4,  0,  0},
                                { 0,  0,  4, -4,  0, -4} };
  */
  dfdu[0] = -3 + 4 * v + 4 * u;
  dfdu[1] = -1 + 4 * u;
  dfdu[2] = 0;
  dfdu[3] = 4 - 4 * v - 8 * u;
  dfdu[4] = 4 * v;
  dfdu[5] = -4 * v;

  dfdv[0] = -3 + 4 * u + 4 * v;
  dfdv[1] = 0;
  dfdv[2] = -1 + 4 * v;
  dfdv[3] = -4 * u;
  dfdv[4] = 4 * u;
  dfdv[5] = 4 - 4 * u - 8 * v;
}

static void jac_corners_p2(double *xa, double *xb, double *xc, double *xab,
                           double *xbc, double *xca, double J[6])
{
  double *x[6] = {xa, xb, xc, xab, xbc, xca};
  double nodes[6][2] = {{0, 0}, {1, 0}, {0, 1}, {0.5, 0}, {0.5, 0.5}, {0, 0.5}};
  for(int i = 0; i < 6; i++) {
    double u = nodes[i][0];
    double v = nodes[i][1];
    double dfdu[6], dfdv[6];
    derivativeP2(u, v, dfdu, dfdv);
    double dxdu = 0, dxdv = 0, dydu = 0, dydv = 0;
    for(int j = 0; j < 6; j++) {
      dxdu += x[j][0] * dfdu[j];
      dxdv += x[j][0] * dfdv[j];
      dydu += x[j][1] * dfdu[j];
      dydv += x[j][1] * dfdv[j];
    }
    J[i] = -(dxdu * dydv - dydu * dxdv);
  }
}

static void jac_points_p2(double *xa, double *xb, double *xc, double *xab,
                          double *xbc, double *xca, double *xis, double *etas,
                          double detJ[6], double J[6][4])
{
  double *x[6] = {xa, xb, xc, xab, xbc, xca};
  for(int i = 0; i < 6; i++) {
    double u = xis[i];
    double v = etas[i];
    double dfdu[6], dfdv[6];
    derivativeP2(u, v, dfdu, dfdv);
    double dxdu = 0, dxdv = 0, dydu = 0, dydv = 0;
    for(int j = 0; j < 6; j++) {
      dxdu += x[j][0] * dfdu[j];
      dxdv += x[j][0] * dfdv[j];
      dydu += x[j][1] * dfdu[j];
      dydv += x[j][1] * dfdv[j];
    }
    J[i][0] = dxdu;
    J[i][1] = dxdv;
    J[i][2] = dydu;
    J[i][3] = dydv;
    detJ[i] = -(dxdu * dydv - dydu * dxdv);
  }
}

static double validity_p2triangle_formula(double *xa, double *xb, double *xc,
                                          double *xab, double *xbc, double *xca)
{
  double J[6];
  jac_corners_p2(xa, xb, xc, xab, xbc, xca, J);
  double bez[6] = {J[0],
                   J[1],
                   J[2],
                   2 * J[3] - 0.5 * (J[0] + J[1]),
                   2 * J[4] - 0.5 * (J[1] + J[2]),
                   2 * J[5] - 0.5 * (J[0] + J[2])};
  double _MIN = 1.e22;
  for(int i = 0; i < 6; i++) _MIN = bez[i] < _MIN ? bez[i] : _MIN;
  return _MIN;
}

FILE *FF = NULL;

static double closest(double t, double u)
{
  const double D = M_PI / 2;
  double U0 = fabs(u - 2 * D - t);
  double U1 = fabs(u - D - t);
  double U2 = fabs(u - t);
  double U3 = fabs(u + D - t);
  double U4 = fabs(u + 2 * D - t);
  if(U0 < U1 && U0 < U2 && U0 < U3 && U0 < U4) return u - 2 * D;
  if(U1 < U2 && U1 < U3 && U1 < U4) return u - D;
  if(U2 < U3 && U2 < U4) return u;
  if(U3 < U4) return u + D;
  return u + 2 * D;
}

static double p2triangle_alignment_quality_measure(double *xa, double *xb,
                                                   double *xc, double *xab,
                                                   double *xbc, double *xca,
                                                   int VIEW_TAG)
{
  double xis[6] = {0, .2, .4, .6, .8, 1};
  double etas[6] = {0, 0, 0, 0., 0., 0.};
  double J[6];
  double Js[6][4];
  jac_points_p2(xa, xb, xc, xab, xbc, xca, xis, etas, J, Js);

  double SUM = 0;

  double THETA[6];
  double THETAM[6];
  double x[6][2];

  for(uint32_t j = 0; j < 6; j++) {
    double xi = xis[j];
    double eta = etas[j];

    x[j][0] = interpolateTriangleP2(xi, eta, xa[0], xb[0], xc[0], xab[0],
                                    xbc[0], xca[0]);
    x[j][1] = interpolateTriangleP2(xi, eta, xa[1], xb[1], xc[1], xab[1],
                                    xbc[1], xca[1]);

    std::vector<double> val(9);
    double dist;
    gmsh::view::probe(VIEW_TAG, x[j][0], x[j][1], 0.0, val, dist);
    double dxdu = Js[j][0];
    double dydu = Js[j][2];

    double C, S, h1, h2;
    analyze2dMetric(val, C, S, h1, h2);

    if(j == 0)
      THETAM[j] = atan2(S, C);
    else
      THETAM[j] = closest(THETAM[j - 1], atan2(S, C));

    if(j == 0)
      THETA[j] = atan2(dydu, dxdu);
    else
      THETA[j] = closest(THETA[j - 1], atan2(dydu, dxdu));
  }
  for(uint32_t j = 1; j < 5; j++) {
    double dtheta = THETA[j + 1] - THETA[j - 1];
    double dthetam = THETAM[j + 1] - THETAM[j - 1];
    double D2 = (dtheta - dthetam) * (dtheta - dthetam);
    SUM += exp(-(D2));
  }
  return SUM;
}

static double p1triangle_quality_metric(int VIEW_TAG, PolyMesh::Vertex *v0,
                                        PolyMesh::Vertex *v1,
                                        PolyMesh::Vertex *v2)
{
  double *xa = v0->position;
  double *xb = v1->position;
  double *xc = v2->position;

  std::vector<double> val(9);
  double dist;
  gmsh::view::probe(VIEW_TAG, (xa[0] + xb[0] + xc[0]) / 3,
                    (xa[1] + xb[1] + xc[1]) / 3, 0.0, val, dist);
  double M[3] = {val[0], val[4], val[1]};
  val.clear();

  //  printf("%g %g %g\n", M[0],M[1],M[2]);

  double area = fabs(robustPredicates::orient2d(xa, xb, xc));

  double det = sqrt(M[0] * M[1] - M[2] * M[2]);

  double d1[2] = {xb[0] - xa[0], xb[1] - xa[1]};
  double d2[2] = {xc[0] - xb[0], xc[1] - xb[1]};
  double d3[2] = {xa[0] - xc[0], xa[1] - xc[1]};

  double tmp1 = d1[0] * d1[0] + d2[0] * d2[0] + d3[0] * d3[0];
  double tmp2 = d1[1] * d1[1] + d2[1] * d2[1] + d3[1] * d3[1];
  double tmp3 = 2 * (d1[0] * d1[1] + d2[0] * d2[1] + d3[0] * d3[1]);

  double l2 = (tmp1 * M[0] + tmp2 * M[1] + tmp3 * M[2]);

  //  printf("%g\n",det);

  return det * area / 3.0 / l2;
}

int lengthPathInMetricField(double lagrangianPoints[3][2],
                            double *lengthInMetricField, int VIEW_TAG)
{
  *lengthInMetricField = 0.0;

  size_t n = 8;

  static double GL_pt8[8] = {-9.602898564975363e-01, -7.966664774136268e-01,
                             -5.255324099163290e-01, -1.834346424956498e-01,
                             1.834346424956498e-01,  5.255324099163290e-01,
                             7.966664774136268e-01,  9.602898564975363e-01};

  static double GL_wt8[8] = {1.012285362903768e-01, 2.223810344533745e-01,
                             3.137066458778874e-01, 3.626837833783620e-01,
                             3.626837833783620e-01, 3.137066458778874e-01,
                             2.223810344533745e-01, 1.012285362903768e-01};

  //  double gaussPoints[2][2] = {{-1/sqrt(3.0),1},{1/sqrt(3.0),1}};

  for(size_t i = 0; i < n; ++i) {
    double t = GL_pt8[i];
    double w = GL_wt8[i];

    double x[2] = {-0.5 * t * (1 - t) * lagrangianPoints[0][0] +
                     (1 + t) * (1 - t) * lagrangianPoints[1][0] +
                     0.5 * t * (1 + t) * lagrangianPoints[2][0],
                   -0.5 * t * (1 - t) * lagrangianPoints[0][1] +
                     (1 + t) * (1 - t) * lagrangianPoints[1][1] +
                     0.5 * t * (1 + t) * lagrangianPoints[2][1]};

    double dx = -0.5 * (1 - 2 * t) * lagrangianPoints[0][0] -
                2 * t * lagrangianPoints[1][0] +
                0.5 * (1 + 2 * t) * lagrangianPoints[2][0];
    double dy = -0.5 * (1 - 2 * t) * lagrangianPoints[0][1] -
                2 * t * lagrangianPoints[1][1] +
                0.5 * (1 + 2 * t) * lagrangianPoints[2][1];

    std::vector<double> val(9);
    double dist;
    gmsh::view::probe(VIEW_TAG, x[0], x[1], 0.0, val, dist);
    if(val.empty()) { *lengthInMetricField = 1.e22; }
    else {
      double M[3] = {val[0], val[4], val[1]};
      *lengthInMetricField =
        *lengthInMetricField +
        w * sqrt(M[0] * dx * dx + 2 * M[2] * dx * dy + M[1] * dy * dy);
    }
  }
  return 0;
}

double objectiveFunction_L(double x0, double y0, double xt, double yt,
                           double x1, double y1, int VIEW_TAG)
{
  double lagrangianPoints[3][2] = {{x0, y0}, {xt, yt}, {x1, y1}};
  double lengthInMetricField;

  lengthPathInMetricField(lagrangianPoints, &lengthInMetricField, VIEW_TAG);

  return lengthInMetricField;
}

/*
  An straight edge

*/

double objectiveFunction(double x0, double y0, double x1, double y1, double x2,
                         double y2, int VIEW_TAG)
{
  return objectiveFunction_L(x0, y0, x1, y1, x2, y2, VIEW_TAG);
}

double goldenSection(double x0, double y0, double &xt, double &yt, double x1,
                     double y1, double astart, double bstart, double &gamma1,
                     double direction[2], // rename direction instead of jF?
                     int VIEW_TAG)
{
  double tol = 1.e-7;
  double fstart, f, f1, f2;

  fstart = objectiveFunction(x0, y0, xt, yt, x1, y1, VIEW_TAG);
  double Lstart = objectiveFunction_L(x0, y0, xt, yt, x1, y1, VIEW_TAG);
  //  return Lstart;
  if(Lstart > 2) return Lstart;

  double lambda = 1.0 / (0.5 * (sqrt(5) + 1.0));

  double a = astart;
  double b = bstart;

  double xi = 0.0;
  double xi1 = b - lambda * (b - a);
  double xi2 = a + lambda * (b - a);

  f1 = objectiveFunction(x0, y0, xt - xi1 * direction[0],
                         yt - xi1 * direction[1], x1, y1, VIEW_TAG);
  f2 = objectiveFunction(x0, y0, xt - xi2 * direction[0],
                         yt - xi2 * direction[1], x1, y1, VIEW_TAG);

  while(fabs(xi2 - xi1) > tol) {
    if(f1 < f2) {
      b = xi2;
      xi2 = xi1;
      f2 = f1;
      xi1 = b - lambda * (b - a);
      f1 = objectiveFunction(x0, y0, xt - xi1 * direction[0],
                             yt - xi1 * direction[1], x1, y1, VIEW_TAG);
    }
    else {
      a = xi1;
      xi1 = xi2;
      f1 = f2;
      xi2 = a + lambda * (b - a);
      f2 = objectiveFunction(x0, y0, xt - xi2 * direction[0],
                             yt - xi2 * direction[1], x1, y1, VIEW_TAG);
    }
  }

  if(f1 < f2) {
    xi = xi1;
    f = f1;
  }
  else {
    xi = xi2;
    f = f2;
  }

  if(fstart <= f) { // we don't want to move if we are on the minimum
    xi = 0;
  }
  gamma1 = xi;

  //  double Lend = objectiveFunction_L( x0, y0, xt-xi*direction[0],
  //  yt-xi*direction[1], x1, y1, VIEW_TAG); if (Lstart < 1.2) printf("xi =
  //  %12.5E fstart %12.5E f %12.5E\n",xi, Lstart, Lend);
  return f;
}

int shortestParabola(double *xstart, double *xend, int VIEW_TAG, double *xmid,
                     double *lengthGeodesicsTwoPoints)
{
  double x0 = xstart[0];
  double x1 = xend[0];
  double y0 = xstart[1];
  double y1 = xend[1];

  // double XM = (x0 + x1)/2;
  // double YM = (y0 + y1)/2;

  // double Lstart = objectiveFunction_L( x0, y0, XM, YM, x1, y1, VIEW_TAG );
  // double KK;
  // if (Lstart > 3) KK = Lstart ;
  // else KK = bestParabola( x0, y0, x1, y1, XM, YM, VIEW_TAG);

  //  xmid[0] = XM;
  //  xmid[1] = YM;

  //  *lengthGeodesicsTwoPoints = KK;
  //  return 0;

  xmid[0] = (x0 + x1) / 2;
  xmid[1] = (y0 + y1) / 2;

  double direction[2] = {y1 - y0, x0 - x1};
  double gamma1 = 0.0;
  //  double astart = -.01;
  //  double bstart = .01;

  //  precompute  (x0, y0, x1, y1, VIEW_TAG);

  //  goldenSection(x0, y0, xmid[0], xmid[1], x1, y1, astart, bstart, gamma1,
  //  direction, VIEW_TAG);

  xmid[0] = xmid[0] - gamma1 * direction[0];
  xmid[1] = xmid[1] - gamma1 * direction[1];

  *lengthGeodesicsTwoPoints =
    objectiveFunction_L(x0, y0, xmid[0], xmid[1], x1, y1, VIEW_TAG);

  return 0;

  //  printf("%12.5E %12.5E %12.5E %12.5E %12.5E\n",gamma1,
  //  direction[0],direction[1],xmid[0],xmid[1]); return 0;
}

static double smallestLengthParabola(int VIEW_TAG, SPoint2 &p1, SPoint2 &p2,
                                     SPoint2 &p3)
{
  double lengthGeodesicsTwoPoints;
  shortestParabola(p1, p2, VIEW_TAG, p3, &lengthGeodesicsTwoPoints);
  //  printf("LENGTH %12.5E\n",lengthGeodesicsTwoPoints);
  return lengthGeodesicsTwoPoints;
}

static double _LIMIT = 0.7;
static double closestPoint(int VIEW_TAG, std::vector<SPoint2> &_points,
                           SPoint2 &p, SPoint2 &c)
{
  double closest = 2 * _LIMIT;
  for(size_t i = 0; i < _points.size(); i++) {
    SPoint2 pp = _points[i];
    SPoint2 pmid;
    double dist = smallestLengthParabola(VIEW_TAG, pp, p, pmid);
    if(dist < closest) {
      closest = dist;
      c = pp;
    }
  }
  return closest;
}

static bool computeNeighbor(int VIEW_TAG, const SPoint2 &p, int DIR,
                            double adimensionalLength, SPoint2 &n)
{
  std::vector<double> val;
  double dist;
  gmsh::view::probe(VIEW_TAG, p.x(), p.y(), 0.0, val, dist);
  if(val.empty()) return false;
  double C, S, h1, h2;
  analyze2dMetric(val, C, S, h1, h2);
  double A[4] = {C, -C, S, -S};
  double B[4] = {S, -S, -C, C};
  double H[4] = {h1, h1, h2, h2};

  size_t N = 50;
  double dx = A[DIR];
  double dy = B[DIR];
  double h = H[DIR];
  std::vector<SPoint2> path;
  SPoint2 PP = p;
  for(size_t iter = 0; iter < N; iter++) {
    SPoint2 pp(PP.x() + dx * h * adimensionalLength / N,
               PP.y() + dy * h * adimensionalLength / N);
    double Cpp, Spp, h1pp, h2pp;
    val.clear();
    gmsh::view::probe(VIEW_TAG, pp.x(), pp.y(), 0.0, val, dist);
    if(val.empty()) { iter = N + 1; }
    else {
      analyze2dMetric(val, Cpp, Spp, h1pp, h2pp);
      maxDir(dx, dy, h, Cpp, Spp, h1pp, h2pp);
      path.push_back(pp);
      PP = pp;
    }
  }
  if(path.size() == N) {
    n = path[N - 1];
    return true;
  }
  return false;
}

static int delaunayEdgeCriterionAnIsotropic(PolyMesh::HalfEdge *he,
                                            int VIEW_TAG)
{
  if(!he->f) return -1;
  if(he->opposite == NULL) return -1;
  if(he->opposite->data != he->data) return -1;
  if(he->f->data < 0) return -1;

  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v3 = he->opposite->next->next->v;

  if(!check_triangle_validity_2d(v3->position, v1->position, v2->position) ||
     !check_triangle_validity_2d(v3->position, v2->position, v0->position))
    return -1;

  double q012 = p1triangle_quality_metric(VIEW_TAG, v0, v1, v2);
  double q103 = p1triangle_quality_metric(VIEW_TAG, v1, v0, v3);

  double q312 = p1triangle_quality_metric(VIEW_TAG, v3, v1, v2);
  double q320 = p1triangle_quality_metric(VIEW_TAG, v3, v2, v0);

  if(std::min(q312, q320) > std::min(q012, q103)) return 1;
  return 0;
}

double
triangleValidityP2(PolyMesh::HalfEdge *hea,
                   std::map<PolyMesh::HalfEdge *, SPoint2> *midPoints = nullptr)
{
  PolyMesh::HalfEdge *heb = hea->next;
  PolyMesh::HalfEdge *hec = heb->next;
  SPoint2 ab(0.5 * (hea->v->position.x() + heb->v->position.x()),
             0.5 * (hea->v->position.y() + heb->v->position.y()));
  SPoint2 bc(0.5 * (heb->v->position.x() + hec->v->position.x()),
             0.5 * (heb->v->position.y() + hec->v->position.y()));
  SPoint2 ca(0.5 * (hec->v->position.x() + hea->v->position.x()),
             0.5 * (hec->v->position.y() + hea->v->position.y()));
  if(midPoints) {
    ab = (*midPoints)[hea];
    bc = (*midPoints)[heb];
    ca = (*midPoints)[hec];
  }
  return validity_p2triangle_formula(hea->v->position, heb->v->position,
                                     hec->v->position, ab, bc, ca);
}

double
triangleQualityP2(int VIEW_TAG, PolyMesh::HalfEdge *hea,
                  std::map<PolyMesh::HalfEdge *, SPoint2> *midPoints = nullptr)
{
  //  hea = hea->f->he->next->next;
  PolyMesh::HalfEdge *heb = hea->next;
  PolyMesh::HalfEdge *hec = heb->next;
  SPoint2 ab(0.5 * (hea->v->position.x() + heb->v->position.x()),
             0.5 * (hea->v->position.y() + heb->v->position.y()));
  SPoint2 bc(0.5 * (heb->v->position.x() + hec->v->position.x()),
             0.5 * (heb->v->position.y() + hec->v->position.y()));
  SPoint2 ca(0.5 * (hec->v->position.x() + hea->v->position.x()),
             0.5 * (hec->v->position.y() + hea->v->position.y()));
  if(midPoints) {
    ab = (*midPoints)[hea];
    bc = (*midPoints)[heb];
    ca = (*midPoints)[hec];
  }

  if(FF) {
    std::vector<double> val0(9), val1(9), val2(9), val3(9), val4(9), val5(9);
    double dist;
    gmsh::view::probe(VIEW_TAG, hea->v->position.x(), hea->v->position.y(), 0.0,
                      val0, dist);
    gmsh::view::probe(VIEW_TAG, heb->v->position.x(), heb->v->position.y(), 0.0,
                      val1, dist);
    gmsh::view::probe(VIEW_TAG, hec->v->position.x(), hec->v->position.y(), 0.0,
                      val2, dist);
    gmsh::view::probe(VIEW_TAG, ab.x(), ab.y(), 0.0, val3, dist);
    gmsh::view::probe(VIEW_TAG, bc.x(), bc.y(), 0.0, val4, dist);
    gmsh::view::probe(VIEW_TAG, ca.x(), ca.y(), 0.0, val5, dist);

    fprintf(FF,
            "ST2(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,0,%g,%g,0,%g,%g,0){%g,%g,%g,%"
            "g,%g,%g};\n",
            hea->v->position.x(), hea->v->position.y(), hea->v->position.z(),
            heb->v->position.x(), heb->v->position.y(), heb->v->position.z(),
            hec->v->position.x(), hec->v->position.y(), hec->v->position.z(),
            ab.x(), ab.y(), bc.x(), bc.y(), ca.x(), ca.y(), val0[8], val1[8],
            val2[8], val3[8], val4[8], val5[8]);
  }

  double validity = triangleValidityP2(hea, midPoints);
  if(validity < 0) return validity;
  return p2triangle_alignment_quality_measure(
    hea->v->position, heb->v->position, hec->v->position, ab, bc, ca, VIEW_TAG);
}

double triangleValidityP1(PolyMesh::HalfEdge *hea)
{
  PolyMesh::HalfEdge *heb = hea->next;
  PolyMesh::HalfEdge *hec = heb->next;
  return -robustPredicates::orient2d(hea->v->position, heb->v->position,
                                     hec->v->position);
}

double LENGTH(PolyMesh::HalfEdge *he,
              std::map<PolyMesh::HalfEdge *, SPoint2> &midPoints, int VIEW_TAG,
              bool straight = false)
{
  double x0 = he->v->position[0];
  double x1 = he->next->v->position[0];
  double y0 = he->v->position[1];
  double y1 = he->next->v->position[1];
  SPoint2 mid =
    straight ? SPoint2(0.5 * (x0 + x1), 0.5 * (y0 + y1)) : midPoints[he];
  return objectiveFunction_L(x0, y0, mid.x(), mid.y(), x1, y1, VIEW_TAG);
}

static double bestParabola(PolyMesh::HalfEdge *he, int VIEW_TAG,
                           std::map<PolyMesh::HalfEdge *, SPoint2> &midPoints,
                           double ximax = .2)
{
  double XI_MIN = -ximax;
  double XI_MAX = ximax;

  double x0 = he->v->position[0];
  double x1 = he->next->v->position[0];
  double y0 = he->v->position[1];
  double y1 = he->next->v->position[1];

  double xmid = (x0 + x1) / 2;
  double ymid = (y0 + y1) / 2;

  double direction[2] = {y1 - y0, x0 - x1};

  const int N = 31;

  SPoint2 CUR = midPoints[he->opposite];
  double Q1 = triangleQualityP2(VIEW_TAG, he, &midPoints);
  double Q2 = triangleQualityP2(VIEW_TAG, he->opposite, &midPoints);
  double QMIN = std::min(Q1, Q2);
  //  printf("-----------------  iterating START %4d %4d %12.5E %12.5E
  //  --------------------- \n",he->v->data, he->next->v->data, Q1, Q2); return;
  for(int i = 0; i < N; i++) {
    double t = (double)i / (N - 1);
    double xi = XI_MIN + (XI_MAX - XI_MIN) * t;
    SPoint2 X(xmid - xi * direction[0], ymid - xi * direction[1]);
    midPoints[he] = midPoints[he->opposite] = X;
    Q1 = triangleQualityP2(VIEW_TAG, he, &midPoints);
    Q2 = triangleQualityP2(VIEW_TAG, he->opposite, &midPoints);
    if(std::min(Q1, Q2) > QMIN) {
      QMIN = std::min(Q1, Q2);
      CUR = X;
    }
  }
  midPoints[he] = midPoints[he->opposite] = CUR;
  return QMIN;
  //  printf("%12.5E %12.5E %12.5E %12.5E\n",ximin,QMIN,triangleQualityP2
  //  (VIEW_TAG, he, &midPoints), triangleQualityP2 (VIEW_TAG, he->opposite,
  //  &midPoints));
}

static double bestParabola(PolyMesh::HalfEdge *he,
                           std::map<PolyMesh::HalfEdge *, SPoint2> &midPoints,
                           double er(double *, double *, double *, double *,
                                     double *, double *),
                           double ximax = 0.2)
{
  double XI_MIN = -ximax;
  double XI_MAX = ximax;

  double x0 = he->v->position[0];
  double x1 = he->next->v->position[0];
  double y0 = he->v->position[1];
  double y1 = he->next->v->position[1];

  double xmid = (x0 + x1) / 2;
  double ymid = (y0 + y1) / 2;

  double direction[2] = {y1 - y0, x0 - x1};

  const int N = 81;

  SPoint2 CUR = midPoints[he->opposite];
  double Q1 =
    er(he->v->position, he->next->v->position, he->next->next->v->position,
       midPoints[he], midPoints[he->next], midPoints[he->next->next]);
  double Q2 =
    er(he->opposite->v->position, he->opposite->next->v->position,
       he->opposite->next->next->v->position, midPoints[he->opposite],
       midPoints[he->opposite->next], midPoints[he->opposite->next->next]);
  double V1 = triangleValidityP2(he, &midPoints);
  double V2 = triangleValidityP2(he->opposite, &midPoints);
  if(V1 <= 0) Q1 = 1.e22;
  if(V2 <= 0) Q2 = 1.e22;

  double QSUM = Q1 + Q2;
  //  printf("-----------------  iterating START %4d %4d %12.5E %12.5E
  //  --------------------- \n",he->v->data, he->next->v->data, Q1, Q2); return;
  for(int i = 0; i < N; i++) {
    double t = (double)i / (N - 1);
    double xi = XI_MIN + (XI_MAX - XI_MIN) * t;
    SPoint2 X(xmid - xi * direction[0], ymid - xi * direction[1]);
    midPoints[he] = midPoints[he->opposite] = X;

    double Q1 =
      er(he->v->position, he->next->v->position, he->next->next->v->position,
         midPoints[he], midPoints[he->next], midPoints[he->next->next]);
    double Q2 =
      er(he->opposite->v->position, he->opposite->next->v->position,
         he->opposite->next->next->v->position, midPoints[he->opposite],
         midPoints[he->opposite->next], midPoints[he->opposite->next->next]);

    double V1 = triangleValidityP2(he, &midPoints);
    double V2 = triangleValidityP2(he->opposite, &midPoints);

    if(V1 <= 0) Q1 = 1.e22;
    if(V2 <= 0) Q2 = 1.e22;

    if(Q1 + Q2 < QSUM) {
      QSUM = Q1 + Q2;
      CUR = X;
    }
  }
  midPoints[he] = midPoints[he->opposite] = CUR;
  return QSUM;
  //  printf("%12.5E %12.5E %12.5E %12.5E\n",ximin,QMIN,triangleQualityP2
  //  (VIEW_TAG, he, &midPoints), triangleQualityP2 (VIEW_TAG, he->opposite,
  //  &midPoints));
}

double bestParabola(double x0, double y0, double x1, double y1, double &xmid,
                    double &ymid, int VIEW_TAG)
{
  double XI_MIN = -0.2;
  double XI_MAX = 0.2;

  SPoint2 P0(x0, y0);
  SPoint2 P1(x1, y1);

  xmid = (x0 + x1) / 2;
  ymid = (y0 + y1) / 2;
  SPoint2 PM(xmid, ymid);
  SPoint2 CUR = PM;
  double direction[2] = {y1 - y0, x0 - x1};

  const int N = 11;

  double QMAX = -1.e22;
  //  printf("-----------------  iterating START %4d %4d %12.5E %12.5E
  //  --------------------- \n",he->v->data, he->next->v->data, Q1, Q2); return;
  for(int i = 0; i < N; i++) {
    double t = (double)i / (N - 1);
    double xi = XI_MIN + (XI_MAX - XI_MIN) * t;
    SPoint2 X(xmid - xi * direction[0], ymid - xi * direction[1]);
    double Q =
      p2triangle_alignment_quality_measure(P0, P1, P0, PM, PM, PM, VIEW_TAG);
    if(Q > QMAX) {
      QMAX = Q;
      CUR = X;
    }
  }
  xmid = CUR.x();
  ymid = CUR.y();
  return objectiveFunction_L(x0, y0, xmid, ymid, x1, y1, VIEW_TAG);
  //  printf("%12.5E %12.5E %12.5E %12.5E\n",ximin,QMIN,triangleQualityP2
  //  (VIEW_TAG, he, &midPoints), triangleQualityP2 (VIEW_TAG, he->opposite,
  //  &midPoints));
}

int computePointsUsingScaledCrossFieldPlanarP2(
  const char *modelForMetric, const char *modelForMesh, int VIEW_TAG,
  int faceTag, std::vector<double> &pts,
  double er(double *, double *, double *, double *, double *, double *))
{
  PolyMesh *pm;

  FILE *f = fopen("PTS.pos", "w");
  fprintf(f, "View \" \"{\n");

  gmsh::model::setCurrent(modelForMesh);
  int result = GFace2PolyMesh(faceTag, &pm);
  if(result) return result;

  //  std::queue<SPoint2> _q;
  std::stack<SPoint2> _q;
  std::vector<SPoint2> _points;
  for(auto v : pm->vertices) {
    if(pm->degree(v) < 0) {
      SPoint2 pp(v->position.x(), v->position.y());
      _q.push(pp);
      _points.push_back(pp);
    }
  }

  gmsh::model::setCurrent(modelForMetric);

  std::vector<double> additional;

  while(!_q.empty()) {
    //    SPoint2 p = _q.front();
    SPoint2 p = _q.top();
    _q.pop();
    //    std::vector<SPoint2> n;
    //    computeNeighbors (VIEW_TAG,  p , n);
    for(int DIR = 0; DIR < 4; DIR++) {
      SPoint2 pp;
      if(computeNeighbor(VIEW_TAG, p, DIR, sqrt(_LIMIT), pp)) {
        //      printf("%12.5E %12.5E\n",pp.x(), pp.y());
        SPoint2 close;
        double dist = closestPoint(VIEW_TAG, _points, pp, close);
        if(dist > _LIMIT) {
          additional.push_back(pp.x());
          additional.push_back(pp.y());
          _q.push(pp);
          fprintf(f, "SL(%22.15E,%22.15E,0,%22.15E,%22.15E,0){%g,%g};\n",
                  pp.x(), pp.y(), p.x(), p.y(), dist, dist);
          _points.push_back(pp);
          fprintf(f, "SP(%22.15E,%22.15E,0){%lu};\n", pp.x(), pp.y(),
                  _points.size());
        }
        else {
          //	  fprintf(f,"SL(%22.15E,%22.15E,0,%22.15E,%22.15E,0){%g,%g};\n",close.x(),close.y(),pp.x(),pp.y(),dist,
          //dist);
        }
      }
      //    if (_points.size() > 1900)break;
      if(_points.size() % 100 == 0)
        printf("q size %lu p size %lu\n", _q.size(), _points.size());
    }
  }
  fprintf(f, "};\n");
  fclose(f);

  gmsh::model::setCurrent(modelForMesh);
  PolyMesh *newMesh = GFaceInitialMesh(faceTag, 1, &additional);
  newMesh->print4debug(100);
  gmsh::model::setCurrent(modelForMetric);

  while(1) {
    int count = 0;
    for(auto he : newMesh->hedges) {
      if(delaunayEdgeCriterionAnIsotropic(he, VIEW_TAG) == 1) {
        newMesh->swap_edge(he);
        count++;
      }
    }
    //    printf("count %3d\n",count);
    if(count == 0) break;
  }
  newMesh->print4debug(200);

  std::map<PolyMesh::HalfEdge *, SPoint2> midPoints;
  std::map<PolyMesh::HalfEdge *, double> LS;
  for(auto he : newMesh->hedges) {
    SPoint2 p_0(he->v->position.x(), he->v->position.y());
    SPoint2 p_1(he->next->v->position.x(), he->next->v->position.y());
    SPoint2 p_m = (p_0 + p_1) * .5;
    midPoints[he] = p_m;
  }

  int iter = 0;
  double ximax = 0.3 / 5;
  while(iter++ < 6) {
    for(auto he : newMesh->hedges) {
      SPoint2 p_0(he->v->position.x(), he->v->position.y());
      SPoint2 p_1(he->next->v->position.x(), he->next->v->position.y());
      SPoint2 p_m = (p_0 + p_1) * .5;
      if(he->opposite && he->f->data >= 0 && he->opposite->f->data >= 0) {
        if(er && iter > 14)
          bestParabola(he, midPoints, er, ximax);
        else
          bestParabola(he, VIEW_TAG, midPoints, ximax);
        double L = LENGTH(he, midPoints, VIEW_TAG);
        LS[he] = L;
        LS[he->opposite] = L;
      }
    }
    ximax += 0.3 / 5;
  }

  iter = 0;
  while(iter++ < 3) {
    int count = 0;
    for(auto he : newMesh->hedges) {
      if(!he->f || he->opposite == NULL || he->opposite->data != he->data ||
         he->f->data < 0 || he->opposite->f->data < 0)
        continue;
      double LA = LENGTH(he, midPoints, VIEW_TAG);
      SPoint2 old = midPoints[he];
      if(LA > 1) {
        double A = er ? bestParabola(he, midPoints, er) :
                        bestParabola(he, VIEW_TAG, midPoints);
        newMesh->swap_edge(he);
        double B = er ? bestParabola(he, midPoints, er) :
                        bestParabola(he, VIEW_TAG, midPoints);

        double LB = LENGTH(he, midPoints, VIEW_TAG);
        bool invalid = false;
        bool better = false;
        if(er && B > 1.e10) invalid = true;
        if(er && B > A) better = true;
        if(!er && B < 0) invalid = true;
        if(!er && B < A) better = true;
        if(invalid) {
          newMesh->swap_edge(he);
          midPoints[he] = midPoints[he->opposite] = old;
        }
        else if(better) {
          newMesh->swap_edge(he);
          if(er)
            bestParabola(he, midPoints, er);
          else
            bestParabola(he, VIEW_TAG, midPoints);
        }
        else {
          count++;
          printf("%12.5E %12.5E %12.5E %12.5E %12.5E \n", A, LA, B, LB,
                 LENGTH(he, midPoints, VIEW_TAG));
        }
      }
    }
    printf("count %3d\n", count);
    if(count == 0) break;
  }

  {
    FILE *FFF = fopen("meshMetric.pos", "w");
    fprintf(FFF, "View \" metric \"{\n");

    for(auto he : newMesh->hedges) {
      if(he->opposite && he->f->data >= 0 && he->opposite->f->data >= 0) {
        FF = FFF;
        triangleQualityP2(VIEW_TAG, he, &midPoints);
        FF = NULL;
      }
    }
    fprintf(FFF, "};\n");
    fclose(FFF);
  }

  {
    char name[256];
    sprintf(name, "polyMeshCurved%d.pos", 200);
    FILE *f = fopen(name, "w");
    sprintf(name, "polyMeshCurved%d.pos", 300);
    FILE *f2 = fopen(name, "w");
    fprintf(f, "View \" %s \"{\n", name);
    fprintf(f2, "View \" %s \"{\n", name);
    for(auto he : newMesh->hedges) {
      SPoint2 p = midPoints[he];
      newMesh->high_order_nodes.push_back(SVector3(p.x(), p.y(), 0.0));
      if(he->f->data >= 0) {
        //      printf("%g %g %g\n",p[0], p[1],LS[he]);
        double Lhe = LENGTH(he, midPoints, VIEW_TAG);
        double Lhe2 = LENGTH(he, midPoints, VIEW_TAG, true);
        fprintf(f, "SL2(%g,%g,0,%g,%g,0,%g,%g,0){%g,%g,%g};\n",
                he->v->position.x(), he->v->position.y(),
                he->next->v->position.x(), he->next->v->position.y(), p.x(),
                p.y(), Lhe, Lhe, Lhe);
        fprintf(f2, "SL(%g,%g,0,%g,%g,0){%g,%g};\n", he->v->position.x(),
                he->v->position.y(), he->next->v->position.x(),
                he->next->v->position.y(), Lhe2, Lhe2);
      }
    }
    fprintf(f, "};\n");
    fclose(f);
    fprintf(f2, "};\n");
    fclose(f2);
  }

  gmsh::model::setCurrent(modelForMesh);
  PolyMesh2GFace(newMesh, faceTag);

  return 0;
}
