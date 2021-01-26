// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "curvature.h"

#define tolerance 0.1e-20

static bool Inv4x4ColumnMajor(double m[16], double inv[16], double *det)
{
  int i;

  inv[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] +
           m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
  inv[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] -
           m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
  inv[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] +
           m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
  inv[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] -
            m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
  inv[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] -
           m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
  inv[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] +
           m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
  inv[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] -
           m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
  inv[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] +
            m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
  inv[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] +
           m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
  inv[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] -
           m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
  inv[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] +
            m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
  inv[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] -
            m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
  inv[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] -
           m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
  inv[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] +
           m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
  inv[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] -
            m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
  inv[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] +
            m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

  *det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

  if(*det == 0) return false;

  double invDet = 1.0 / *det;

  for(i = 0; i < 16; i++) inv[i] *= invDet;

  return true;
}

static void solveEig(double A, double B, double C, double D, double *lambda1,
                     double *v1x, double *v1y, double *lambda2, double *v2x,
                     double *v2y)
{
  if(B * C <= tolerance) {
    *lambda1 = A;
    *v1x = 1;
    *v1y = 0;
    *lambda2 = D;
    *v2x = 0;
    *v2y = 1;
    return;
  }

  double tr = A + D;
  double det = A * D - B * C;
  double S = sqrt((tr * tr / 4) - det);
  *lambda1 = tr / 2 + S;
  *lambda2 = tr / 2 - S;

  double temp = ((A - D) * (A - D) / 4) + B * C;

  double SS = sqrt(temp > 0 ? temp : 0.0);
  if(A - D < 0) {
    *v1x = C;
    *v1y = -(A - D) / 2 + SS;
    *v2x = +(A - D) / 2 - SS;
    *v2y = B;
  }
  else {
    *v2x = C;
    *v2y = -(A - D) / 2 - SS;
    *v1x = +(A - D) / 2 + SS;
    *v1y = B;
  }

  double n1 = sqrt((*v1x) * (*v1x) + (*v1y) * (*v1y));
  *v1x /= n1;
  *v1y /= n1;
  double n2 = sqrt((*v2x) * (*v2x) + (*v2y) * (*v2y));
  *v2x /= n2;
  *v2y /= n2;
}

static inline int node2trianglescmp(const void *p0, const void *p1)
{
  const std::size_t *e0 = (const std::size_t *)p0;
  const std::size_t *e1 = (const std::size_t *)p1;

  if(e0[0] < e1[0]) return -1;
  if(e0[0] > e1[0]) return 1;
  return 0;
}

static inline double normalize(double *n)
{
  double d = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
  if(d != 0.0) {
    n[0] /= d;
    n[1] /= d;
    n[2] /= d;
  }
  return fabs(d);
}

static inline void makevector(const double *a, const double *b, double *ba)
{
  ba[0] = b[0] - a[0];
  ba[1] = b[1] - a[1];
  ba[2] = b[2] - a[2];
}

static inline double dotprod(double *a, double *b)
{
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

static inline void crossprod(double *a, double *b, double *n)
{
  n[0] = a[1] * b[2] - a[2] * b[1];
  n[1] = -(a[0] * b[2] - a[2] * b[0]);
  n[2] = a[0] * b[1] - a[1] * b[0];
}

static inline void unitNormal2Triangle(const double *x1, const double *x2,
                                       const double *x3, double *n, double *s)
{
  double a[3] = {x2[0] - x1[0], x2[1] - x1[1], x2[2] - x1[2]};
  double b[3] = {x3[0] - x1[0], x3[1] - x1[1], x3[2] - x1[2]};

  crossprod(a, b, n);
  *s = 2 * normalize(n);
}

static void computeLocalFrame(double *n, double *u, double *v)
{
  if(fabs(n[0]) > fabs(n[1]) && fabs(n[0]) > fabs(n[2])) {
    u[0] = 0;
    u[1] = 0;
    u[2] = 1;
  }
  else {
    u[0] = 1;
    u[1] = 0;
    u[2] = 0;
  }
  crossprod(n, u, v);
  normalize(v);
  crossprod(v, n, u);
}

bool CurvatureRusinkiewicz(
  const std::vector<int> &triangles, const std::vector<SPoint3> &nodes,
  std::vector<std::pair<SVector3, SVector3> > &nodalCurvatures)
{
  std::size_t nTriangles = triangles.size() / 3;
  std::size_t nVertices = nodes.size();

  nodalCurvatures.resize(nVertices);

  // for(int i = 0; i < nodes.size(); ++i){
  //   nodalCurvatures[i] = std::make_pair(0.0,0.0);
  // }

  std::vector<std::size_t> node2tri(3 * 2 * nTriangles);

  // first compute node normals and node-to-triangle connectivity

  std::vector<double> nodeNormals(3 * nVertices, 0.);
  std::size_t counter = 0;
  double n[3], surf;

  for(std::size_t i = 0; i < nTriangles; i++) {
    node2tri[counter++] = triangles[3 * i + 0];
    node2tri[counter++] = i;
    node2tri[counter++] = triangles[3 * i + 1];
    node2tri[counter++] = i;
    node2tri[counter++] = triangles[3 * i + 2];
    node2tri[counter++] = i;
    unitNormal2Triangle(nodes[triangles[3 * i + 0]].data(),
                        nodes[triangles[3 * i + 1]].data(),
                        nodes[triangles[3 * i + 2]].data(), n, &surf);
    double *n0 = &nodeNormals[3 * triangles[3 * i + 0]];
    double *n1 = &nodeNormals[3 * triangles[3 * i + 1]];
    double *n2 = &nodeNormals[3 * triangles[3 * i + 2]];
    for(std::size_t i1 = 0; i1 < 3; i1++) {
      n0[i1] += n[i1];
      n1[i1] += n[i1];
      n2[i1] += n[i1];
    }
  }
  for(std::size_t i = 0; i < nVertices; i++) normalize(&nodeNormals[3 * i]);

  qsort(&node2tri[0], 3 * nTriangles, 2 * sizeof(std::size_t),
        node2trianglescmp);

  // compute the second fundamental tensor on each triangle using least squares

  std::vector<double> CURV(4 * nTriangles);

  for(std::size_t i = 0; i < nTriangles; i++) {
    double *n0 = &nodeNormals[3 * triangles[3 * i + 0]];
    double *n1 = &nodeNormals[3 * triangles[3 * i + 1]];
    double *n2 = &nodeNormals[3 * triangles[3 * i + 2]];

    double e0[3], e1[3], e2[3];
    makevector(nodes[triangles[3 * i + 2]].data(),
               nodes[triangles[3 * i + 1]].data(), e0);
    makevector(nodes[triangles[3 * i + 0]].data(),
               nodes[triangles[3 * i + 2]].data(), e1);
    makevector(nodes[triangles[3 * i + 1]].data(),
               nodes[triangles[3 * i + 0]].data(), e2);
    unitNormal2Triangle(nodes[triangles[3 * i + 0]].data(),
                        nodes[triangles[3 * i + 1]].data(),
                        nodes[triangles[3 * i + 2]].data(), n, &surf);
    double u[3], v[3];
    makevector(nodes[triangles[3 * i + 0]].data(),
               nodes[triangles[3 * i + 1]].data(), u);
    normalize(u);
    crossprod(n, u, v);

    double sys[6][4], rhs[6], temp[3], invA[16], A[16], B[4];
    sys[0][0] = sys[1][2] = dotprod(e0, u);
    sys[0][1] = sys[1][3] = dotprod(e0, v);
    sys[0][2] = sys[0][3] = sys[1][0] = sys[1][1] = 0;
    makevector(n2, n1, temp);
    rhs[0] = dotprod(temp, u);
    rhs[1] = dotprod(temp, v);

    sys[2][0] = sys[3][2] = dotprod(e1, u);
    sys[2][1] = sys[3][3] = dotprod(e1, v);
    sys[2][2] = sys[2][3] = sys[3][0] = sys[3][1] = 0;
    makevector(n0, n2, temp);
    rhs[2] = dotprod(temp, u);
    rhs[3] = dotprod(temp, v);

    sys[4][0] = sys[5][2] = dotprod(e2, u);
    sys[4][1] = sys[5][3] = dotprod(e2, v);
    sys[4][2] = sys[4][3] = sys[5][0] = sys[5][1] = 0;
    makevector(n1, n0, temp);
    rhs[4] = dotprod(temp, u);
    rhs[5] = dotprod(temp, v);

    for(std::size_t i1 = 0; i1 < 4; i1++) {
      B[i1] = 0.0;
      for(std::size_t i3 = 0; i3 < 6; i3++) { B[i1] += sys[i3][i1] * rhs[i3]; }
      for(std::size_t i2 = 0; i2 < 4; i2++) {
        A[i1 + 4 * i2] = 0.0;
        for(std::size_t i3 = 0; i3 < 6; i3++) {
          A[i1 + 4 * i2] += sys[i3][i2] * sys[i3][i1];
        }
      }
    }
    double det;
    Inv4x4ColumnMajor(A, invA, &det);
    for(std::size_t i1 = 0; i1 < 4; i1++) {
      CURV[4 * i + i1] = 0.0;
      for(std::size_t i2 = 0; i2 < 4; i2++) {
        CURV[4 * i + i1] += invA[i1 + 4 * i2] * B[i2];
      }
    }
    CURV[4 * i + 1] = CURV[4 * i + 2] =
      0.5 * (CURV[4 * i + 1] + CURV[4 * i + 2]);
  }

  uint64_t count = 0;
  double uP[3] = {0., 0., 0.}, vP[3] = {0., 0., 0.};
  double A = 0., B = 0., D = 0.;
  uint64_t iTriangle;
  uint64_t ind = 0;
  for(uint64_t iVert = 0; iVert < nVertices; ++iVert) {
    count = 0;
    A = 0.0;
    B = 0.0;
    D = 0.0;
    while(node2tri[2 * ind + 0] == iVert) {
      iTriangle = node2tri[2 * ind + 1];
      computeLocalFrame(&nodeNormals[3 * iVert], uP, vP);
      // computing each curvature around a vertex
      unitNormal2Triangle(nodes[triangles[3 * iTriangle + 0]].data(),
                          nodes[triangles[3 * iTriangle + 1]].data(),
                          nodes[triangles[3 * iTriangle + 2]].data(), n, &surf);
      double uF[3], vF[3];
      makevector(nodes[triangles[3 * iTriangle + 0]].data(),
                 nodes[triangles[3 * iTriangle + 1]].data(), uF);
      normalize(uF);
      crossprod(n, uF, vF);
      double *c = &CURV[4 * iTriangle];
      double UP[3] = {dotprod(uP, uF), dotprod(uP, vF), 0};
      normalize(UP);
      double VP[3] = {dotprod(vP, uF), dotprod(vP, vF), 0};
      normalize(VP);
      A += (UP[0] * UP[0] * c[0] + 2 * UP[0] * UP[1] * c[1] +
            UP[1] * UP[1] * c[3]);
      D += (VP[0] * VP[0] * c[0] + 2 * VP[0] * VP[1] * c[1] +
            VP[1] * VP[1] * c[3]);
      B += (VP[0] * UP[0] * c[0] + (VP[1] * UP[0] + VP[0] * UP[1]) * c[1] +
            VP[1] * UP[1] * c[3]);
      ++count;
      ++ind;
      if(ind >= 3 * nTriangles) break;
    }

    A /= (double)count;
    B /= (double)count;
    D /= (double)count;
    double lambda1, lambda2, v1x, v1y, v2x, v2y;
    solveEig(A, B, B, D, &lambda1, &v1x, &v1y, &lambda2, &v2x, &v2y);
    SVector3 cMax(fabs(lambda1) * (v1x * uP[0] + v1y * vP[0]),
                  fabs(lambda1) * (v1x * uP[1] + v1y * vP[1]),
                  fabs(lambda1) * (v1x * uP[2] + v1y * vP[2]));
    SVector3 cMin(fabs(lambda2) * (v2x * uP[0] + v2y * vP[0]),
                  fabs(lambda2) * (v2x * uP[1] + v2y * vP[1]),
                  fabs(lambda2) * (v2x * uP[2] + v2y * vP[2]));
    nodalCurvatures[iVert] = std::make_pair(cMax, cMin);
  } // for iVert

  return true;
}

bool CurvatureRusinkiewicz(
  const std::vector<int> &triangles, const std::vector<SPoint3> &nodes,
  std::vector<std::pair<SVector3, SVector3> > &nodalCurvatures,
  std::vector<double> &nodeNormals)
{
  std::size_t nTriangles = triangles.size() / 3;
  std::size_t nVertices = nodes.size();

  nodalCurvatures.resize(nVertices);

  // for(int i = 0; i < nodes.size(); ++i){
  //   nodalCurvatures[i] = std::make_pair(0.0,0.0);
  // }

  std::vector<std::size_t> node2tri(3 * 2 * nTriangles);

  // first compute node normals and node-to-triangle connectivity

  // std::vector<double> nodeNormals(3 * nVertices, 0.);
  std::size_t counter = 0;
  double n[3], surf;

  for(std::size_t i = 0; i < nTriangles; i++) {
    node2tri[counter++] = triangles[3 * i + 0];
    node2tri[counter++] = i;
    node2tri[counter++] = triangles[3 * i + 1];
    node2tri[counter++] = i;
    node2tri[counter++] = triangles[3 * i + 2];
    node2tri[counter++] = i;
    unitNormal2Triangle(nodes[triangles[3 * i + 0]].data(),
                        nodes[triangles[3 * i + 1]].data(),
                        nodes[triangles[3 * i + 2]].data(), n, &surf);
    double *n0 = &nodeNormals[3 * triangles[3 * i + 0]];
    double *n1 = &nodeNormals[3 * triangles[3 * i + 1]];
    double *n2 = &nodeNormals[3 * triangles[3 * i + 2]];
    for(std::size_t i1 = 0; i1 < 3; i1++) {
      n0[i1] += n[i1];
      n1[i1] += n[i1];
      n2[i1] += n[i1];
    }
  }
  for(std::size_t i = 0; i < nVertices; i++) normalize(&nodeNormals[3 * i]);

  qsort(&node2tri[0], 3 * nTriangles, 2 * sizeof(std::size_t),
        node2trianglescmp);

  // compute the second fundamental tensor on each triangle using least squares

  std::vector<double> CURV(4 * nTriangles);

  for(std::size_t i = 0; i < nTriangles; i++) {
    double *n0 = &nodeNormals[3 * triangles[3 * i + 0]];
    double *n1 = &nodeNormals[3 * triangles[3 * i + 1]];
    double *n2 = &nodeNormals[3 * triangles[3 * i + 2]];

    double e0[3], e1[3], e2[3];
    makevector(nodes[triangles[3 * i + 2]].data(),
               nodes[triangles[3 * i + 1]].data(), e0);
    makevector(nodes[triangles[3 * i + 0]].data(),
               nodes[triangles[3 * i + 2]].data(), e1);
    makevector(nodes[triangles[3 * i + 1]].data(),
               nodes[triangles[3 * i + 0]].data(), e2);
    unitNormal2Triangle(nodes[triangles[3 * i + 0]].data(),
                        nodes[triangles[3 * i + 1]].data(),
                        nodes[triangles[3 * i + 2]].data(), n, &surf);
    double u[3], v[3];
    makevector(nodes[triangles[3 * i + 0]].data(),
               nodes[triangles[3 * i + 1]].data(), u);
    normalize(u);
    crossprod(n, u, v);

    double sys[6][4], rhs[6], temp[3], invA[16], A[16], B[4];
    sys[0][0] = sys[1][2] = dotprod(e0, u);
    sys[0][1] = sys[1][3] = dotprod(e0, v);
    sys[0][2] = sys[0][3] = sys[1][0] = sys[1][1] = 0;
    makevector(n2, n1, temp);
    rhs[0] = dotprod(temp, u);
    rhs[1] = dotprod(temp, v);

    sys[2][0] = sys[3][2] = dotprod(e1, u);
    sys[2][1] = sys[3][3] = dotprod(e1, v);
    sys[2][2] = sys[2][3] = sys[3][0] = sys[3][1] = 0;
    makevector(n0, n2, temp);
    rhs[2] = dotprod(temp, u);
    rhs[3] = dotprod(temp, v);

    sys[4][0] = sys[5][2] = dotprod(e2, u);
    sys[4][1] = sys[5][3] = dotprod(e2, v);
    sys[4][2] = sys[4][3] = sys[5][0] = sys[5][1] = 0;
    makevector(n1, n0, temp);
    rhs[4] = dotprod(temp, u);
    rhs[5] = dotprod(temp, v);

    for(std::size_t i1 = 0; i1 < 4; i1++) {
      B[i1] = 0.0;
      for(std::size_t i3 = 0; i3 < 6; i3++) { B[i1] += sys[i3][i1] * rhs[i3]; }
      for(std::size_t i2 = 0; i2 < 4; i2++) {
        A[i1 + 4 * i2] = 0.0;
        for(std::size_t i3 = 0; i3 < 6; i3++) {
          A[i1 + 4 * i2] += sys[i3][i2] * sys[i3][i1];
        }
      }
    }
    double det;
    Inv4x4ColumnMajor(A, invA, &det);
    for(std::size_t i1 = 0; i1 < 4; i1++) {
      CURV[4 * i + i1] = 0.0;
      for(std::size_t i2 = 0; i2 < 4; i2++) {
        CURV[4 * i + i1] += invA[i1 + 4 * i2] * B[i2];
      }
    }
    CURV[4 * i + 1] = CURV[4 * i + 2] =
      0.5 * (CURV[4 * i + 1] + CURV[4 * i + 2]);
  }

  uint64_t count = 0;
  double uP[3] = {0., 0., 0.}, vP[3] = {0., 0., 0.};
  double A = 0., B = 0., D = 0.;
  uint64_t iTriangle;
  uint64_t ind = 0;
  for(uint64_t iVert = 0; iVert < nVertices; ++iVert) {
    count = 0;
    A = 0.0;
    B = 0.0;
    D = 0.0;
    while(node2tri[2 * ind + 0] == iVert) {
      iTriangle = node2tri[2 * ind + 1];
      computeLocalFrame(&nodeNormals[3 * iVert], uP, vP);
      // computing each curvature around a vertex
      unitNormal2Triangle(nodes[triangles[3 * iTriangle + 0]].data(),
                          nodes[triangles[3 * iTriangle + 1]].data(),
                          nodes[triangles[3 * iTriangle + 2]].data(), n, &surf);
      double uF[3], vF[3];
      makevector(nodes[triangles[3 * iTriangle + 0]].data(),
                 nodes[triangles[3 * iTriangle + 1]].data(), uF);
      normalize(uF);
      crossprod(n, uF, vF);
      double *c = &CURV[4 * iTriangle];
      double UP[3] = {dotprod(uP, uF), dotprod(uP, vF), 0};
      normalize(UP);
      double VP[3] = {dotprod(vP, uF), dotprod(vP, vF), 0};
      normalize(VP);
      A += (UP[0] * UP[0] * c[0] + 2 * UP[0] * UP[1] * c[1] +
            UP[1] * UP[1] * c[3]);
      D += (VP[0] * VP[0] * c[0] + 2 * VP[0] * VP[1] * c[1] +
            VP[1] * VP[1] * c[3]);
      B += (VP[0] * UP[0] * c[0] + (VP[1] * UP[0] + VP[0] * UP[1]) * c[1] +
            VP[1] * UP[1] * c[3]);
      ++count;
      ++ind;
      if(ind >= 3 * nTriangles) break;
    }

    A /= (double)count;
    B /= (double)count;
    D /= (double)count;
    double lambda1, lambda2, v1x, v1y, v2x, v2y;
    solveEig(A, B, B, D, &lambda1, &v1x, &v1y, &lambda2, &v2x, &v2y);
    SVector3 cMax(fabs(lambda1) * (v1x * uP[0] + v1y * vP[0]),
                  fabs(lambda1) * (v1x * uP[1] + v1y * vP[1]),
                  fabs(lambda1) * (v1x * uP[2] + v1y * vP[2]));
    SVector3 cMin(fabs(lambda2) * (v2x * uP[0] + v2y * vP[0]),
                  fabs(lambda2) * (v2x * uP[1] + v2y * vP[1]),
                  fabs(lambda2) * (v2x * uP[2] + v2y * vP[2]));
    nodalCurvatures[iVert] = std::make_pair(cMax, cMin);
  } // for iVert

  return true;
}