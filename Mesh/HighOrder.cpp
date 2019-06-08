// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Koen Hillewaert
//

#include <sstream>
#include <vector>
#include "GmshConfig.h"
#include "HighOrder.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "GmshMessage.h"
#include "OS.h"
#include "fullMatrix.h"
#include "BasisFactory.h"
#include "InnerVertexPlacement.h"
#include "Context.h"

#if defined(HAVE_OPTHOM)
#include "HighOrderMeshFastCurving.h"
#include "HighOrderMeshPeriodicity.h"
#endif

// Functions that help optimizing placement of points on geometry

// The aim here is to build a polynomial representation that consist
// in polynomial segments of equal length

static double mylength(GEdge *ge, int i, double *u)
{
  return ge->length(u[i], u[i + 1], 10);
}

static void myresid(int N, GEdge *ge, double *u, fullVector<double> &r,
                    double *weight = NULL)
{
  double L[100];
  for(int i = 0; i < N - 1; i++) L[i] = mylength(ge, i, u);
  if(weight)
    for(int i = 0; i < N - 2; i++)
      r(i) = L[i + 1] / weight[i + 1] - L[i] / weight[i];
  else
    for(int i = 0; i < N - 2; i++) r(i) = L[i + 1] - L[i];
}

static bool computeEquidistantParameters(GEdge *ge, double u0, double uN, int N,
                                         double *u, double underRelax)
{
  const double PRECISION = 1.e-6;
  const int MAX_ITER = 50;
  const double eps = (uN - u0) * 1.e-5;

  // newton algorithm
  // N is the total number of points (3 for quadratic, 4 for cubic ...)
  // u[0] = u0;
  // u[N-1] = uN;
  // initialize as equidistant in parameter space
  u[0] = u0;
  double du = (uN - u0) / (N - 1);
  for(int i = 1; i < N; i++) {
    u[i] = u[i - 1] + du;
  }

  // return true;

  // create the tangent matrix
  const int M = N - 2;
  fullMatrix<double> J(M, M);
  fullVector<double> DU(M);
  fullVector<double> R(M);
  fullVector<double> Rp(M);

  int iter = 1;

  while(iter < MAX_ITER) {
    iter++;
    myresid(N, ge, u, R);

    for(int i = 0; i < M; i++) {
      u[i + 1] += eps;
      myresid(N, ge, u, Rp);
      for(int j = 0; j < M; j++) {
        J(i, j) = (Rp(j) - R(j)) / eps;
      }
      u[i + 1] -= eps;
    }

    if(M == 1)
      DU(0) = R(0) / J(0, 0);
    else
      J.luSolve(R, DU);

    for(int i = 0; i < M; i++) {
      u[i + 1] -= underRelax * DU(i);
    }

    if(u[1] < u0) break;
    if(u[N - 2] > uN) break;

    double newt_norm = DU.norm();
    if(newt_norm < PRECISION) {
      return true;
    }
  }
  return false;
}

static bool computeGLLParametersP6(GEdge *ge, double u0, double uN, int N,
                                   double *u, double underRelax)
{
  static const double GLLQL[7] = {
    -1.000000000000000, -0.830223896278567, -0.468848793470714, 0,
    0.468848793470714,  0.830223896278567,  1.000000000000000};
  double weight[6];
  for(int i = 0; i < 6; ++i) {
    weight[i] = GLLQL[i + 1] - GLLQL[i];
  }

  const double PRECISION = 1.e-6;
  const int MAX_ITER = 50;
  const double eps = (uN - u0) * 1.e-5;

  // newton algorithm
  // N is the total number of points (3 for quadratic, 4 for cubic ...)
  // u[0] = u0;
  // u[N-1] = uN;
  // initialize as equidistant in parameter space
  u[0] = u0;
  u[N - 1] = uN;
  double uMiddle = .5 * (u0 + uN);
  double du = .5 * (uN - u0);
  for(int i = 1; i < N - 1; i++) {
    u[i] = uMiddle + GLLQL[i] * du;
  }

  // create the tangent matrix
  const int M = N - 2;
  fullMatrix<double> J(M, M);
  fullVector<double> DU(M);
  fullVector<double> R(M);
  fullVector<double> Rp(M);

  int iter = 1;

  while(iter < MAX_ITER) {
    iter++;
    myresid(N, ge, u, R, weight);

    for(int i = 0; i < M; i++) {
      u[i + 1] += eps;
      myresid(N, ge, u, Rp, weight);
      for(int j = 0; j < M; j++) {
        J(i, j) = (Rp(j) - R(j)) / eps;
      }
      u[i + 1] -= eps;
    }

    if(M == 1)
      DU(0) = R(0) / J(0, 0);
    else
      J.luSolve(R, DU);

    for(int i = 0; i < M; i++) {
      u[i + 1] -= underRelax * DU(i);
    }

    if(u[1] < u0) break;
    if(u[N - 2] > uN) break;

    double newt_norm = DU.norm();
    if(newt_norm < PRECISION) {
      return true;
    }
  }
  return false;
}

static bool computeEquidistantParameters(GFace *gf, double u0, double uN,
                                         double v0, double vN, SPoint3 &p0,
                                         SPoint3 &pN, int N, bool geodesic,
                                         double *u, double *v)
{
  const int NI = N - 1;
  u[0] = u0;
  v[0] = v0;
  u[NI] = uN;
  v[NI] = vN;
  const double fact = 1. / (double)NI;
  for(int i = 1; i < NI; i++) {
    const double t = i * fact;
    u[i] = u0 + (uN - u0) * t;
    v[i] = v0 + (vN - v0) * t;
    if(geodesic) {
      SPoint3 pc(t * pN + (1. - t) * p0);
      double guess[2] = {u[i], v[i]};
      GPoint gp = gf->closestPoint(pc, guess);
      if(gp.succeeded()) {
        u[i] = gp.u();
        v[i] = gp.v();
      }
    }
  }
  return true;
}

static fullMatrix<double> *lob2lagP6 = NULL;

void createMatLob2LagP6()
{
  const double lobPt[7] = {
    -1.000000000000000, -0.830223896278567, -0.468848793470714, 0,
    0.468848793470714,  0.830223896278567,  1.000000000000000};
  const double lagPt[7] = {
    -1.000000000000000, -0.666666666666666, -0.333333333333333, 0,
    0.333333333333333,  0.666666666666666,  1.000000000000000};
  const int ndofs = 7;

  const double monomial[7] = {0, 1, 2, 3, 4, 5, 6};

  fullMatrix<double> Vandermonde(ndofs, ndofs);
  for(int i = 0; i < ndofs; i++) {
    for(int j = 0; j < ndofs; j++) {
      Vandermonde(i, j) = pow_int(lobPt[i], monomial[j]);
    }
  }

  fullMatrix<double> coefficient(ndofs, ndofs);
  Vandermonde.invert(coefficient);

  lob2lagP6 = new fullMatrix<double>(ndofs, ndofs);

  for(int i = 0; i < ndofs; i++) {
    for(int j = 0; j < ndofs; j++) {
      Vandermonde(i, j) = pow_int(lagPt[i], monomial[j]);
    }
  }

  Vandermonde.mult(coefficient, (*lob2lagP6));
}

// Creation of high-order edge vertices

static bool getEdgeVerticesOnGeo(GEdge *ge, MVertex *v0, MVertex *v1,
                                 std::vector<MVertex *> &ve, int nPts = 1)
{
  static bool GLLquad = false;
  static const double relaxFail = 1e-2;
  double u0 = 0., u1 = 0., US[100];
  bool reparamOK = reparamMeshVertexOnEdge(v0, ge, u0);
  if(ge->periodic(0) && ge->getEndVertex() &&
     ge->getEndVertex()->getNumMeshVertices() > 0 &&
     v1 == ge->getEndVertex()->mesh_vertices[0])
    u1 = ge->parBounds(0).high();
  else
    reparamOK &= reparamMeshVertexOnEdge(v1, ge, u1);

  if(reparamOK) {
    double uMin = std::min(u0, u1), uMax = std::max(u0, u1);
    bool failed = true;
    double relax = 1.;
    while(failed && (relax > relaxFail)) {
      if(GLLquad)
        failed = !computeGLLParametersP6(ge, uMin, uMax, nPts + 2, US, relax);
      else
        failed =
          !computeEquidistantParameters(ge, uMin, uMax, nPts + 2, US, relax);
      relax *= 0.5;
    }
    if(failed) {
      Msg::Warning(
        "Failed to compute equidistant parameters (relax = %g, value = %g) "
        "for edge %d-%d parametrized with %g %g on curve %d",
        relax, US[1], v0->getNum(), v1->getNum(), u0, u1, ge->tag());
      US[0] = uMin;
      const double du = (uMax - uMin) / (nPts + 1);
      for(int i = 1; i <= nPts; i++) US[i] = US[i - 1] + du;
    }
  }
  else
    Msg::Error("Cannot reparametrize a mesh node in high order meshing");

  if(!reparamOK) return false;

  if(GLLquad) {
    fullMatrix<double> M(7, 3);
    M(0, 0) = u0 < u1 ? v0->x() : v1->x();
    M(0, 1) = u0 < u1 ? v0->y() : v1->y();
    M(0, 2) = u0 < u1 ? v0->z() : v1->z();
    M(6, 0) = u0 < u1 ? v1->x() : v0->x();
    M(6, 1) = u0 < u1 ? v1->y() : v0->y();
    M(6, 2) = u0 < u1 ? v1->z() : v0->z();
    for(int j = 0; j < nPts; j++) {
      int count = u0 < u1 ? j + 1 : nPts + 1 - (j + 1);
      GPoint pc = ge->point(US[count]);
      M(j + 1, 0) = pc.x();
      M(j + 1, 1) = pc.y();
      M(j + 1, 2) = pc.z();
    }
    fullMatrix<double> Mlag(7, 3);
    if(!lob2lagP6) createMatLob2LagP6();
    lob2lagP6->mult(M, Mlag);

    for(int j = 0; j < nPts; j++) {
      MVertex *v;
      int count = u0 < u1 ? j + 1 : nPts + 1 - (j + 1);
      // FIXME US[count] false!!!
      v = new MEdgeVertex(Mlag(count, 0), Mlag(count, 1), Mlag(count, 2), ge,
                          US[count]);
      // this destroys the ordering of the mesh vertices on the edge
      ve.push_back(v);
    }
  }
  else {
    for(int j = 0; j < nPts; j++) {
      MVertex *v;
      int count = u0 < u1 ? j + 1 : nPts + 1 - (j + 1);
      GPoint pc = ge->point(US[count]);
      v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge, US[count]);
      // this destroys the ordering of the mesh vertices on the edge
      ve.push_back(v);
    }
  }

  //  GLLquad = false;
  return true;
}

static bool getEdgeVerticesOnGeo(GFace *gf, MVertex *v0, MVertex *v1,
                                 std::vector<MVertex *> &ve, int nPts = 1)
{
  SPoint2 p0, p1;
  double US[100], VS[100];
  bool reparamOK = reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
  if(reparamOK) {
    SPoint3 pnt0, pnt1;
    if(nPts >= 30)
      computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1], pnt0, pnt1,
                                   nPts + 2, false, US, VS);
    else {
      pnt0 = v0->point();
      pnt1 = v1->point();
      // FIXME: using the geodesic is sometimes a bad idea when the edge is "far
      // away" from the surface (e.g. on the diameter of a circle!)
      computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1], pnt0, pnt1,
                                   nPts + 2, true, US, VS);
    }
  }
  else {
    Msg::Error("Cannot reparametrize mesh edge %lu-%lu on surface %d",
               v0->getNum(), v1->getNum(), gf->tag());
    return false;
  }

  for(int j = 0; j < nPts; j++) {
    GPoint pc = gf->point(US[j + 1], VS[j + 1]);
    MVertex *v =
      new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, US[j + 1], VS[j + 1]);
    ve.push_back(v);
  }

  return true;
}

static void interpVerticesInExistingEdge(GEntity *ge, const MElement *edgeEl,
                                         std::vector<MVertex *> &veEdge,
                                         int nPts)
{
  fullMatrix<double> points;
  points = edgeEl->getFunctionSpace(nPts + 1)->points;
  for(int k = 2; k < nPts + 2; k++) {
    SPoint3 pos;
    edgeEl->pnt(points(k, 0), 0., 0., pos);
    MVertex *v = new MVertex(pos.x(), pos.y(), pos.z(), ge);
    veEdge.push_back(v);
  }
}

inline static bool getMinMaxVert(MVertex *v0, MVertex *v1, MVertex *&vMin,
                                 MVertex *&vMax)
{
  const bool increasing = (v0->getNum() < v1->getNum());
  if(increasing) {
    vMin = v0;
    vMax = v1;
  }
  else {
    vMin = v1;
    vMax = v0;
  }
  return increasing;
}

// Get new interior vertices for a 1D element
static void getEdgeVertices(GEdge *ge, MElement *ele,
                            std::vector<MVertex *> &ve,
                            std::vector<MVertex *> &newHOVert,
                            edgeContainer &edgeVertices, bool linear,
                            int nPts = 1)
{
  if(!ge->haveParametrization()) linear = true;

  std::vector<MVertex *> veOld;
  ele->getVertices(veOld);
  MVertex *vMin, *vMax;
  const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
  std::pair<MVertex *, MVertex *> p(vMin, vMax);
  std::vector<MVertex *> veEdge;
  // Get vertices on geometry if asked
  bool gotVertOnGeo =
    linear ? false : getEdgeVerticesOnGeo(ge, veOld[0], veOld[1], veEdge, nPts);
  // If not on geometry, create from mesh interpolation
  if(!gotVertOnGeo) interpVerticesInExistingEdge(ge, ele, veEdge, nPts);
  newHOVert.insert(newHOVert.end(), veEdge.begin(), veEdge.end());
  if(edgeVertices.count(p) == 0) {
    if(increasing) // Add newly created vertices to list
      edgeVertices[p].insert(edgeVertices[p].end(), veEdge.begin(),
                             veEdge.end());
    else
      edgeVertices[p].insert(edgeVertices[p].end(), veEdge.rbegin(),
                             veEdge.rend());
  }
  else if(p.first != p.second) {
    // Vertices already exist and edge is not a degenerated edge
    Msg::Error("Mesh edges from different entities share nodes: create a finer mesh "
               "(curve involved: %d)", ge->tag());
  }
  ve.insert(ve.end(), veEdge.begin(), veEdge.end());
}

// Get new interior vertices for an edge in a 2D element
static void getEdgeVertices(GFace *gf, MElement *ele,
                            std::vector<MVertex *> &ve,
                            std::vector<MVertex *> &newHOVert,
                            edgeContainer &edgeVertices, bool linear,
                            int nPts = 1)
{
  if(!gf->haveParametrization()) linear = true;

  for(int i = 0; i < ele->getNumEdges(); i++) {
    std::vector<MVertex *> veOld;
    ele->getEdgeVertices(i, veOld);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
    std::pair<MVertex *, MVertex *> p(vMin, vMax);
    std::vector<MVertex *> veEdge;

    edgeContainer::iterator eIter = edgeVertices.find(p);

    if(eIter != edgeVertices.end()) { // Vertices already exist
      std::vector<MVertex *> &eVtcs = eIter->second;
      if(increasing)
        veEdge.assign(eVtcs.begin(), eVtcs.end());
      else
        veEdge.assign(eVtcs.rbegin(), eVtcs.rend());
    }
    else { // Vertices do not exist, create them
      // Get vertices on geometry if asked
      bool gotVertOnGeo =
        linear ? false :
                 getEdgeVerticesOnGeo(gf, veOld[0], veOld[1], veEdge, nPts);
      if(!gotVertOnGeo) {
        // If not on geometry, create from mesh interpolation
        const MLineN edgeEl(veOld, ele->getPolynomialOrder());
        interpVerticesInExistingEdge(gf, &edgeEl, veEdge, nPts);
      }
      newHOVert.insert(newHOVert.end(), veEdge.begin(), veEdge.end());

      std::vector<MVertex *> &eVtcs = edgeVertices[p];

      if(increasing) // Add newly created vertices to list
        eVtcs.insert(eVtcs.end(), veEdge.begin(), veEdge.end());
      else
        eVtcs.insert(eVtcs.end(), veEdge.rbegin(), veEdge.rend());
    }
    ve.insert(ve.end(), veEdge.begin(), veEdge.end());
  }
}

// Get new interior vertices for an edge in a 3D element
static void getEdgeVertices(GRegion *gr, MElement *ele,
                            std::vector<MVertex *> &ve,
                            std::vector<MVertex *> &newHOVert,
                            edgeContainer &edgeVertices, int nPts = 1)
{
  for(int i = 0; i < ele->getNumEdges(); i++) {
    std::vector<MVertex *> veOld;
    ele->getEdgeVertices(i, veOld);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
    std::pair<MVertex *, MVertex *> p(vMin, vMax);
    std::vector<MVertex *> veEdge;
    if(edgeVertices.count(p)) { // Vertices already exist
      if(increasing)
        veEdge.assign(edgeVertices[p].begin(), edgeVertices[p].end());
      else
        veEdge.assign(edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else { // Vertices do not exist, create them
      const MLineN edgeEl(veOld, ele->getPolynomialOrder());
      interpVerticesInExistingEdge(gr, &edgeEl, veEdge, nPts);
      newHOVert.insert(newHOVert.end(), veEdge.begin(), veEdge.end());
      if(increasing) // Add newly created vertices to list
        edgeVertices[p].insert(edgeVertices[p].end(), veEdge.begin(),
                               veEdge.end());
      else
        edgeVertices[p].insert(edgeVertices[p].end(), veEdge.rbegin(),
                               veEdge.rend());
    }
    ve.insert(ve.end(), veEdge.begin(), veEdge.end());
  }
}

// Creation of high-order face vertices

static void reorientTrianglePoints(std::vector<MVertex *> &vtcs,
                                   int orientation, bool swap)
{
  int nbPts = vtcs.size();
  if(nbPts <= 1) return;
  std::vector<MVertex *> tmp(nbPts);
  int interiorOrder = (int)((sqrt(1. + 8. * nbPts) - 3) / 2);
  int pos = 0;
  for(int o = interiorOrder; o > 0; o -= 3) {
    if(swap) {
      tmp[pos] = vtcs[pos];
      tmp[pos + 1] = vtcs[pos + 2];
      tmp[pos + 2] = vtcs[pos + 1];
      for(int i = 0; i < 3 * (o - 1); i++)
        tmp[pos + 3 + i] = vtcs[pos + 3 * o - i - 1];
    }
    else {
      for(int i = 0; i < 3 * o; i++) tmp[pos + i] = vtcs[pos + i];
    }
    for(int i = 0; i < 3; i++) {
      int ri = (i + orientation) % 3;
      vtcs[pos + ri] = tmp[pos + i];
      for(int j = 0; j < o - 1; j++)
        vtcs[pos + 3 + (o - 1) * ri + j] = tmp[pos + 3 + (o - 1) * i + j];
    }
    pos += 3 * o;
  }
}

static void reorientQuadPoints(std::vector<MVertex *> &vtcs, int orientation,
                               bool swap, int order)
{
  int nbPts = vtcs.size();
  if(nbPts <= 1) return;
  std::vector<MVertex *> tmp(nbPts);

  int start = 0;
  while(1) {
    // CORNERS
    int index = 0;
    if(order == 0) {
      start++;
    }
    else {
      int i1(0), i2(0), i3(0), i4(0);
      if(!swap) {
        if(orientation == 0) {
          i1 = 0;
          i2 = 1;
          i3 = 2;
          i4 = 3;
        }
        else if(orientation == 1) {
          i1 = 3;
          i2 = 0;
          i3 = 1;
          i4 = 2;
        }
        else if(orientation == 2) {
          i1 = 2;
          i2 = 3;
          i3 = 0;
          i4 = 1;
        }
        else if(orientation == 3) {
          i1 = 1;
          i2 = 2;
          i3 = 3;
          i4 = 0;
        }
      }
      else {
        if(orientation == 0) {
          i1 = 0;
          i2 = 3;
          i3 = 2;
          i4 = 1;
        }
        else if(orientation == 3) {
          i1 = 3;
          i2 = 2;
          i3 = 1;
          i4 = 0;
        }
        else if(orientation == 2) {
          i1 = 2;
          i2 = 1;
          i3 = 0;
          i4 = 3;
        }
        else if(orientation == 1) {
          i1 = 1;
          i2 = 0;
          i3 = 3;
          i4 = 2;
        }
      }

      int indices[4] = {i1, i2, i3, i4};
      for(int i = 0; i < 4; i++) tmp[i] = vtcs[start + indices[i]];
      for(int i = 0; i < 4; i++) vtcs[start + i] = tmp[i];

      // EDGES
      start += 4;
      for(int iEdge = 0; iEdge < 4; iEdge++) {
        int p1 = indices[iEdge];
        int p2 = indices[(iEdge + 1) % 4];
        int nbP = order - 1;
        if(p1 == 0 && p2 == 1) {
          for(int i = start + 0 * nbP; i < start + 1 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 1 && p2 == 2) {
          for(int i = start + 1 * nbP; i < start + 2 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 2 && p2 == 3) {
          for(int i = start + 2 * nbP; i < start + 3 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 3 && p2 == 0) {
          for(int i = start + 3 * nbP; i < start + 4 * nbP; i++)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 1 && p2 == 0) {
          for(int i = start + 1 * nbP - 1; i >= start + 0 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 2 && p2 == 1) {
          for(int i = start + 2 * nbP - 1; i >= start + 1 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 3 && p2 == 2) {
          for(int i = start + 3 * nbP - 1; i >= start + 2 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else if(p1 == 0 && p2 == 3) {
          for(int i = start + 4 * nbP - 1; i >= start + 3 * nbP; i--)
            tmp[index++] = vtcs[i];
        }
        else
          Msg::Error("Something wrong in reorientQuadPoints");
      }
      for(int i = 0; i < index; i++) vtcs[start + i] = tmp[i];
      start += index;
    }

    order -= 2;
    if(start >= (int)vtcs.size()) break;
  }
}

static void getFaceVerticesOnGeo(GFace *gf,
                                 const fullMatrix<double> &coefficients,
                                 const std::vector<MVertex *> &vertices,
                                 std::vector<MVertex *> &vf)
{
  SPoint2 pts[1000];
  bool reparamOK = true;
  for(std::size_t k = 0; k < vertices.size(); ++k)
    reparamOK &= reparamMeshVertexOnFace(vertices[k], gf, pts[k]);
  for(int k = 0; k < coefficients.size1(); k++) {
    double X(0), Y(0), Z(0), GUESS[2] = {0, 0};
    for(int j = 0; j < coefficients.size2(); j++) {
      MVertex *vt = vertices[j];
      X += coefficients(k, j) * vt->x();
      Y += coefficients(k, j) * vt->y();
      Z += coefficients(k, j) * vt->z();
      if(reparamOK) {
        GUESS[0] += coefficients(k, j) * pts[j][0];
        GUESS[1] += coefficients(k, j) * pts[j][1];
      }
    }
    MVertex *v;
    if(reparamOK) {
      // GPoint gp = gf->point(SPoint2(GUESS[0], GUESS[1]));
      // closest point is not necessary (slow and for high quality HO
      // meshes it should be optimized anyway afterwards + closest point
      // is still buggy (e.g. BFGS for a plane "Ruled Surface")
      GPoint gp = gf->closestPoint(SPoint3(X, Y, Z), GUESS);
      // AJ: ClosestPoint is absolutely necessary when the parameterization
      // is degenerate...
      if(gp.g()) {
        v = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
      }
      else {
        v = new MVertex(X, Y, Z, gf);
      }
    }
    else {
      GPoint gp = gf->closestPoint(SPoint3(X, Y, Z), GUESS);
      if(gp.succeeded())
        v = new MVertex(gp.x(), gp.y(), gp.z(), gf);
      else
        v = new MVertex(X, Y, Z, gf);
    }
    vf.push_back(v);
  }
}

static void interpVerticesInExistingFace(GEntity *ge,
                                         const fullMatrix<double> &coefficients,
                                         const std::vector<MVertex *> &vertices,
                                         std::vector<MVertex *> &vFace)
{
  for(int k = 0; k < coefficients.size1(); k++) {
    double x(0), y(0), z(0);
    for(int j = 0; j < coefficients.size2(); j++) {
      MVertex *v = vertices[j];
      x += coefficients(k, j) * v->x();
      y += coefficients(k, j) * v->y();
      z += coefficients(k, j) * v->z();
    }
    vFace.push_back(new MVertex(x, y, z, ge));
  }
}

// Get new interior vertices for a 2D element
static void getFaceVertices(GFace *gf, MElement *ele,
                            std::vector<MVertex *> &newVertices,
                            std::vector<MVertex *> &newHOVert,
                            faceContainer &faceVertices, bool linear,
                            int nPts = 1)
{
  if(!gf->haveParametrization()) linear = true;

  std::vector<MVertex *> boundaryVertices;
  {
    int nCorner = ele->getNumPrimaryVertices();
    boundaryVertices.reserve(nCorner + newVertices.size());
    ele->getVertices(boundaryVertices);
    boundaryVertices.resize(nCorner);
    boundaryVertices.insert(boundaryVertices.end(), newVertices.begin(),
                            newVertices.end());
  }
  int type = ele->getType();
  fullMatrix<double> *coefficients = getInnerVertexPlacement(type, nPts + 1);
  std::vector<MVertex *> vFace;
  if(!linear) { // Get vertices on geometry if asked...
    getFaceVerticesOnGeo(gf, *coefficients, boundaryVertices, vFace);
  }
  else { // ... otherwise, create from mesh interpolation
    interpVerticesInExistingFace(gf, *coefficients, boundaryVertices, vFace);
  }

  MFace face = ele->getFace(0);
  faceVertices[face].insert(faceVertices[face].end(), vFace.begin(),
                            vFace.end());
  newVertices.insert(newVertices.end(), vFace.begin(), vFace.end());
  newHOVert.insert(newHOVert.end(), vFace.begin(), vFace.end());
}

static int retrieveFaceBoundaryVertices(int k, int type, int nPts,
                                        const std::vector<MVertex *> &vCorner,
                                        const std::vector<MVertex *> &vEdges,
                                        std::vector<MVertex *> &v)
{
  v.clear();
  int nCorner;
  switch(type) {
  case TYPE_TET:
    v.push_back(vCorner[MTetrahedron::faces_tetra(k, 0)]);
    v.push_back(vCorner[MTetrahedron::faces_tetra(k, 1)]);
    v.push_back(vCorner[MTetrahedron::faces_tetra(k, 2)]);
    for(int i = 0; i < 3; ++i) {
      int edge = MTetrahedron::faces2edge_tetra(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return TYPE_TRI;
  case TYPE_HEX:
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 0)]);
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 1)]);
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 2)]);
    v.push_back(vCorner[MHexahedron::faces_hexa(k, 3)]);
    for(int i = 0; i < 4; ++i) {
      int edge = MHexahedron::faces2edge_hexa(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return TYPE_QUA;
  case TYPE_PRI:
    nCorner = k < 2 ? 3 : 4;
    v.push_back(vCorner[MPrism::faces_prism(k, 0)]);
    v.push_back(vCorner[MPrism::faces_prism(k, 1)]);
    v.push_back(vCorner[MPrism::faces_prism(k, 2)]);
    if(nCorner == 4) v.push_back(vCorner[MPrism::faces_prism(k, 3)]);
    for(int i = 0; i < nCorner; ++i) {
      int edge = MPrism::faces2edge_prism(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return nCorner == 3 ? TYPE_TRI : TYPE_QUA;
  case TYPE_PYR:
    nCorner = k < 4 ? 3 : 4;
    v.push_back(vCorner[MPyramid::faces_pyramid(k, 0)]);
    v.push_back(vCorner[MPyramid::faces_pyramid(k, 1)]);
    v.push_back(vCorner[MPyramid::faces_pyramid(k, 2)]);
    if(nCorner == 4) v.push_back(vCorner[MPyramid::faces_pyramid(k, 3)]);
    for(int i = 0; i < nCorner; ++i) {
      int edge = MPyramid::faces2edge_pyramid(k, i);
      int n = std::abs(edge) - 1;
      v.insert(v.end(), vEdges.begin() + n * nPts,
               vEdges.begin() + (n + 1) * nPts);
      if(edge < 0) std::reverse(v.end() - nPts, v.end());
    }
    return nCorner == 3 ? TYPE_TRI : TYPE_QUA;
  default: return -1;
  }
}

// Get new face (excluding edge) vertices for a face of a 3D element
static void getFaceVertices(GRegion *gr, MElement *ele,
                            std::vector<MVertex *> &newVertices,
                            std::vector<MVertex *> &newHOVert,
                            faceContainer &faceVertices, int nPts = 1)
{
  std::vector<MVertex *> vCorner;
  ele->getVertices(vCorner);
  // NB: We can get more than corner vertices but we use only corners

  for(int i = 0; i < ele->getNumFaces(); i++) {
    MFace face = ele->getFace(i);
    std::vector<MVertex *> vFace;
    faceContainer::iterator fIter = faceVertices.find(face);
    if(fIter != faceVertices.end()) { // Vertices already exist
      std::vector<MVertex *> vtcs = fIter->second;
      int orientation;
      bool swap;
      if(fIter->first.computeCorrespondence(face, orientation, swap)) {
        // Check correspondence and apply permutation if needed
        if(face.getNumVertices() == 3 && nPts > 1)
          reorientTrianglePoints(vtcs, orientation, swap);
        else if(face.getNumVertices() == 4)
          reorientQuadPoints(vtcs, orientation, swap, nPts - 1);
      }
      else
        Msg::Error(
          "Error in face lookup for retrieval of high order face nodes");
      vFace.assign(vtcs.begin(), vtcs.end());
    }
    else { // Vertices do not exist, create them by interpolation
      std::vector<MVertex *> faceBoundaryVertices;
      int type = retrieveFaceBoundaryVertices(
        i, ele->getType(), nPts, vCorner, newVertices, faceBoundaryVertices);
      fullMatrix<double> *coefficients =
        getInnerVertexPlacement(type, nPts + 1);
      interpVerticesInExistingFace(gr, *coefficients, faceBoundaryVertices,
                                   vFace);
      newHOVert.insert(newHOVert.end(), vFace.begin(), vFace.end());
      faceVertices[face].insert(faceVertices[face].end(), vFace.begin(),
                                vFace.end());
    }
    newVertices.insert(newVertices.end(), vFace.begin(), vFace.end());
  }
}

// Get new interior vertices for a 3D element
static void getVolumeVertices(GRegion *gr, MElement *ele,
                              std::vector<MVertex *> &newVertices,
                              std::vector<MVertex *> &newHOVert, int nPts = 1)
{
  std::vector<MVertex *> boundaryVertices;
  {
    int nCorner = ele->getNumPrimaryVertices();
    boundaryVertices.reserve(nCorner + newVertices.size());
    ele->getVertices(boundaryVertices);
    boundaryVertices.resize(nCorner);
    boundaryVertices.insert(boundaryVertices.end(), newVertices.begin(),
                            newVertices.end());
  }
  int type = ele->getType();
  fullMatrix<double> &coefficients = *getInnerVertexPlacement(type, nPts + 1);

  for(int k = 0; k < coefficients.size1(); k++) {
    double x(0), y(0), z(0);
    for(int j = 0; j < coefficients.size2(); j++) {
      MVertex *v = boundaryVertices[j];
      x += coefficients(k, j) * v->x();
      y += coefficients(k, j) * v->y();
      z += coefficients(k, j) * v->z();
    }
    MVertex *v = new MVertex(x, y, z, gr);
    newHOVert.push_back(v);
    newVertices.push_back(v);
  }
}

// Creation of high-order elements

static void setHighOrder(GEdge *ge, std::vector<MVertex *> &newHOVert,
                         edgeContainer &edgeVertices, bool linear,
                         int nbPts = 1)
{
  std::vector<MLine *> lines2;
  for(std::size_t i = 0; i < ge->lines.size(); i++) {
    MLine *l = ge->lines[i];
    std::vector<MVertex *> ve;
    getEdgeVertices(ge, l, ve, newHOVert, edgeVertices, linear, nbPts);
    if(nbPts == 1)
      lines2.push_back(
        new MLine3(l->getVertex(0), l->getVertex(1), ve[0], l->getPartition()));
    else
      lines2.push_back(
        new MLineN(l->getVertex(0), l->getVertex(1), ve, l->getPartition()));
    delete l;
  }
  ge->lines = lines2;
  ge->deleteVertexArrays();
}

static MTriangle *setHighOrder(MTriangle *t, GFace *gf,
                               std::vector<MVertex *> &newHOVert,
                               edgeContainer &edgeVertices,
                               faceContainer &faceVertices, bool linear,
                               bool incomplete, int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gf, t, v, newHOVert, edgeVertices, linear, nPts);
  if(nPts == 1) {
    return new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          v[0], v[1], v[2], 0, t->getPartition());
  }
  else {
    if(!incomplete)
      getFaceVertices(gf, t, v, newHOVert, faceVertices, linear, nPts);
    return new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2), v,
                          nPts + 1, 0, t->getPartition());
  }
}

static MQuadrangle *setHighOrder(MQuadrangle *q, GFace *gf,
                                 std::vector<MVertex *> &newHOVert,
                                 edgeContainer &edgeVertices,
                                 faceContainer &faceVertices, bool linear,
                                 bool incomplete, int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gf, q, v, newHOVert, edgeVertices, linear, nPts);
  if(incomplete) {
    if(nPts == 1) {
      return new MQuadrangle8(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v[0], v[1], v[2], v[3], 0,
                              q->getPartition());
    }
    else {
      return new MQuadrangleN(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v, nPts + 1, 0,
                              q->getPartition());
    }
  }
  else {
    getFaceVertices(gf, q, v, newHOVert, faceVertices, linear, nPts);
    if(nPts == 1) {
      return new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v[0], v[1], v[2], v[3], v[4], 0,
                              q->getPartition());
    }
    else {
      return new MQuadrangleN(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), v, nPts + 1, 0,
                              q->getPartition());
    }
  }
}

static void setHighOrder(GFace *gf, std::vector<MVertex *> &newHOVert,
                         edgeContainer &edgeVertices,
                         faceContainer &faceVertices, bool linear,
                         bool incomplete, int nPts = 1)
{
  std::vector<MTriangle *> triangles2;
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    MTriangle *t = gf->triangles[i];
    MTriangle *tNew = setHighOrder(t, gf, newHOVert, edgeVertices, faceVertices,
                                   linear, incomplete, nPts);
    triangles2.push_back(tNew);
    delete t;
  }
  gf->triangles = triangles2;

  std::vector<MQuadrangle *> quadrangles2;
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    MQuadrangle *q = gf->quadrangles[i];
    MQuadrangle *qNew = setHighOrder(q, gf, newHOVert, edgeVertices,
                                     faceVertices, linear, incomplete, nPts);
    quadrangles2.push_back(qNew);
    delete q;
  }
  gf->quadrangles = quadrangles2;
  gf->deleteVertexArrays();
}

static MTetrahedron *setHighOrder(MTetrahedron *t, GRegion *gr,
                                  std::vector<MVertex *> &newHOVert,
                                  edgeContainer &edgeVertices,
                                  faceContainer &faceVertices, bool incomplete,
                                  int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, t, v, newHOVert, edgeVertices, nPts);
  if(nPts == 1) {
    return new MTetrahedron10(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                              t->getVertex(3), v[0], v[1], v[2], v[3], v[4],
                              v[5], 0, t->getPartition());
  }
  else {
    if(!incomplete) {
      getFaceVertices(gr, t, v, newHOVert, faceVertices, nPts);
      getVolumeVertices(gr, t, v, newHOVert, nPts);
    }
    return new MTetrahedronN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                             t->getVertex(3), v, nPts + 1, 0,
                             t->getPartition());
  }
}

static MHexahedron *setHighOrder(MHexahedron *h, GRegion *gr,
                                 std::vector<MVertex *> &newHOVert,
                                 edgeContainer &edgeVertices,
                                 faceContainer &faceVertices, bool incomplete,
                                 int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, h, v, newHOVert, edgeVertices, nPts);
  if(incomplete) {
    if(nPts == 1) {
      return new MHexahedron20(
        h->getVertex(0), h->getVertex(1), h->getVertex(2), h->getVertex(3),
        h->getVertex(4), h->getVertex(5), h->getVertex(6), h->getVertex(7),
        v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10],
        v[11], 0, h->getPartition());
    }
    else {
      return new MHexahedronN(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                              h->getVertex(3), h->getVertex(4), h->getVertex(5),
                              h->getVertex(6), h->getVertex(7), v, nPts + 1, 0,
                              h->getPartition());
    }
  }
  else {
    getFaceVertices(gr, h, v, newHOVert, faceVertices, nPts);
    getVolumeVertices(gr, h, v, newHOVert, nPts);
    if(nPts == 1) {
      return new MHexahedron27(
        h->getVertex(0), h->getVertex(1), h->getVertex(2), h->getVertex(3),
        h->getVertex(4), h->getVertex(5), h->getVertex(6), h->getVertex(7),
        v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10],
        v[11], v[12], v[13], v[14], v[15], v[16], v[17], v[18], 0,
        h->getPartition());
    }
    else {
      return new MHexahedronN(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                              h->getVertex(3), h->getVertex(4), h->getVertex(5),
                              h->getVertex(6), h->getVertex(7), v, nPts + 1, 0,
                              h->getPartition());
    }
  }
}

static MPrism *setHighOrder(MPrism *p, GRegion *gr,
                            std::vector<MVertex *> &newHOVert,
                            edgeContainer &edgeVertices,
                            faceContainer &faceVertices, bool incomplete,
                            int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, p, v, newHOVert, edgeVertices, nPts);
  if(incomplete) {
    if(nPts == 1) {
      return new MPrism15(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                          p->getVertex(3), p->getVertex(4), p->getVertex(5),
                          v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                          0, p->getPartition());
    }
    else {
      return new MPrismN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                         p->getVertex(3), p->getVertex(4), p->getVertex(5), v,
                         nPts + 1, 0, p->getPartition());
    }
  }
  else {
    getFaceVertices(gr, p, v, newHOVert, faceVertices, nPts);
    if(nPts == 1) {
      return new MPrism18(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                          p->getVertex(3), p->getVertex(4), p->getVertex(5),
                          v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
                          v[9], v[10], v[11], 0, p->getPartition());
    }
    else {
      getVolumeVertices(gr, p, v, newHOVert, nPts);
      return new MPrismN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                         p->getVertex(3), p->getVertex(4), p->getVertex(5), v,
                         nPts + 1, 0, p->getPartition());
    }
  }
}

static MPyramid *setHighOrder(MPyramid *p, GRegion *gr,
                              std::vector<MVertex *> &newHOVert,
                              edgeContainer &edgeVertices,
                              faceContainer &faceVertices, bool incomplete,
                              int nPts)
{
  std::vector<MVertex *> v;
  getEdgeVertices(gr, p, v, newHOVert, edgeVertices, nPts);
  if(!incomplete) {
    getFaceVertices(gr, p, v, newHOVert, faceVertices, nPts);
    if(nPts > 1) {
      getVolumeVertices(gr, p, v, newHOVert, nPts);
    }
  }
  return new MPyramidN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                       p->getVertex(3), p->getVertex(4), v, nPts + 1, 0,
                       p->getPartition());
}

static void setHighOrder(GRegion *gr, std::vector<MVertex *> &newHOVert,
                         edgeContainer &edgeVertices,
                         faceContainer &faceVertices, bool incomplete,
                         int nPts = 1)
{
  std::vector<MTetrahedron *> tetrahedra2;
  for(std::size_t i = 0; i < gr->tetrahedra.size(); i++) {
    MTetrahedron *t = gr->tetrahedra[i];
    MTetrahedron *tNew = setHighOrder(t, gr, newHOVert, edgeVertices,
                                      faceVertices, incomplete, nPts);
    tetrahedra2.push_back(tNew);
    delete t;
  }
  gr->tetrahedra = tetrahedra2;

  std::vector<MHexahedron *> hexahedra2;
  for(std::size_t i = 0; i < gr->hexahedra.size(); i++) {
    MHexahedron *h = gr->hexahedra[i];
    MHexahedron *hNew = setHighOrder(h, gr, newHOVert, edgeVertices,
                                     faceVertices, incomplete, nPts);
    hexahedra2.push_back(hNew);
    delete h;
  }
  gr->hexahedra = hexahedra2;

  std::vector<MPrism *> prisms2;
  for(std::size_t i = 0; i < gr->prisms.size(); i++) {
    MPrism *p = gr->prisms[i];
    MPrism *pNew = setHighOrder(p, gr, newHOVert, edgeVertices, faceVertices,
                                incomplete, nPts);
    prisms2.push_back(pNew);
    delete p;
  }
  gr->prisms = prisms2;

  std::vector<MPyramid *> pyramids2;
  for(std::size_t i = 0; i < gr->pyramids.size(); i++) {
    MPyramid *p = gr->pyramids[i];
    MPyramid *pNew = setHighOrder(p, gr, newHOVert, edgeVertices, faceVertices,
                                  incomplete, nPts);
    pyramids2.push_back(pNew);
    delete p;
  }
  gr->pyramids = pyramids2;

  gr->deleteVertexArrays();
}

// High-level functions

template <class T>
static void setFirstOrder(GEntity *e, std::vector<T *> &elements,
                          bool onlyVisible)
{
  if(onlyVisible && !e->getVisibility()) return;
  std::vector<T *> elements1;
  for(std::size_t i = 0; i < elements.size(); i++) {
    T *ele = elements[i];
    int n = ele->getNumPrimaryVertices();
    std::vector<MVertex *> v1;
    v1.reserve(n);
    for(int j = 0; j < n; j++) v1.push_back(ele->getVertex(j));
    elements1.push_back(new T(v1, 0, ele->getPartition()));
    delete ele;
  }
  elements = elements1;
  e->deleteVertexArrays();
}

static void updateHighOrderVertices(GEntity *e,
                                    const std::vector<MVertex *> &newHOVert,
                                    bool onlyVisible)
{
  if(onlyVisible && !e->getVisibility()) return;
  std::vector<MVertex *> v1;
  for(std::size_t i = 0; i < e->mesh_vertices.size(); i++) {
    if(e->mesh_vertices[i]->getPolynomialOrder() > 1)
      delete e->mesh_vertices[i];
    else
      v1.push_back(e->mesh_vertices[i]);
  }
  v1.insert(v1.end(), newHOVert.begin(), newHOVert.end());
  e->mesh_vertices = v1;
  e->deleteVertexArrays();
}

static void updatePeriodicEdgesAndFaces(GModel *m)
{
  // Edges

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    GEdge *tgt = *it;

    // non complete periodic info (e.g. through extrusion)
    if(tgt->vertexCounterparts.empty()) continue;

    GEdge *src = dynamic_cast<GEdge *>(tgt->getMeshMaster());

    if(src != NULL && src != tgt) {
      std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;
      std::map<MVertex *, MVertex *> &p2p = tgt->correspondingHOPoints;
      p2p.clear();

      Msg::Info("Reconstructing periodicity for curve connection %d - %d",
                tgt->tag(), src->tag());

      std::map<MEdge, MLine *, Less_Edge> srcEdges;
      for(std::size_t i = 0; i < src->getNumMeshElements(); i++) {
        MLine *srcLine = dynamic_cast<MLine *>(src->getMeshElement(i));
        if(!srcLine) {
          Msg::Error("Master element %d is not a line",
                     src->getMeshElement(i)->getNum());
          return;
        }
        srcEdges[MEdge(srcLine->getVertex(0), srcLine->getVertex(1))] = srcLine;
      }

      for(std::size_t i = 0; i < tgt->getNumMeshElements(); ++i) {
        MLine *tgtLine = dynamic_cast<MLine *>(tgt->getMeshElement(i));
        MVertex *vtcs[2];
        if(!tgtLine) {
          Msg::Error("Slave element %d is not a line",
                     tgt->getMeshElement(i)->getNum());
          return;
        }
        for(int iVtx = 0; iVtx < 2; iVtx++) {
          MVertex *vtx = tgtLine->getVertex(iVtx);
          std::map<MVertex *, MVertex *>::iterator tIter = v2v.find(vtx);
          if(tIter == v2v.end()) {
            Msg::Error("Cannot find periodic counterpart of node %d"
                       " of curve %d on curve %d", vtx->getNum(), tgt->tag(),
                       src->tag());
            return;
          }
          else
            vtcs[iVtx] = tIter->second;
        }

        std::map<MEdge, MLine *, Less_Edge>::iterator srcIter =
          srcEdges.find(MEdge(vtcs[0], vtcs[1]));
        if(srcIter == srcEdges.end()) {
          Msg::Error("Can't find periodic counterpart of mesh edge %d-%d "
                     "on curve %d, connected to mesh edge %d-%d on curve %d",
                     tgtLine->getVertex(0)->getNum(),
                     tgtLine->getVertex(1)->getNum(), tgt->tag(),
                     vtcs[0]->getNum(), vtcs[1]->getNum(), src->tag());
          return;
        }
        else {
          MLine *srcLine = srcIter->second;
          if(tgtLine->getNumVertices() != srcLine->getNumVertices()) throw;
          for(std::size_t i = 2; i < tgtLine->getNumVertices(); i++)
            p2p[tgtLine->getVertex(i)] = srcLine->getVertex(i);
        }
      }
    }
  }

  if(CTX::instance()->mesh.hoPeriodic) {
#if defined(HAVE_OPTHOM)
    std::vector<GEntity *> modelEdges(m->firstEdge(), m->lastEdge());
    HighOrderMeshPeriodicity edgePeriodicity(modelEdges);
    edgePeriodicity.fixPeriodicity();
    edgePeriodicity.fixPeriodicity(); // apply twice for operation order effects
#else
    Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *tgt = *it;

    // non complete periodic info (e.g. through extrusion)
    if(tgt->vertexCounterparts.empty()) continue;

    GFace *src = dynamic_cast<GFace *>(tgt->getMeshMaster());
    if(src != NULL && src != tgt) {
      Msg::Info("Reconstructing periodicity for surface connection %d - %d",
                tgt->tag(), src->tag());

      std::map<MVertex *, MVertex *> &v2v = tgt->correspondingVertices;
      std::map<MVertex *, MVertex *> &p2p = tgt->correspondingHOPoints;
      p2p.clear();

      std::map<MFace, MElement *, Less_Face> srcFaces;

      for(std::size_t i = 0; i < src->getNumMeshElements(); ++i) {
        MElement *srcElmt = src->getMeshElement(i);
        int nbVtcs = 0;
        if(dynamic_cast<MTriangle *>(srcElmt)) nbVtcs = 3;
        if(dynamic_cast<MQuadrangle *>(srcElmt)) nbVtcs = 4;
        std::vector<MVertex *> vtcs;
        vtcs.reserve(nbVtcs);
        for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
          vtcs.push_back(srcElmt->getVertex(iVtx));
        }
        srcFaces[MFace(vtcs)] = srcElmt;
      }

      for(std::size_t i = 0; i < tgt->getNumMeshElements(); ++i) {
        MElement *tgtElmt = tgt->getMeshElement(i);
        int nbVtcs = 0;
        if(dynamic_cast<MTriangle *>(tgtElmt)) nbVtcs = 3;
        if(dynamic_cast<MQuadrangle *>(tgtElmt)) nbVtcs = 4;
        std::vector<MVertex *> vtcs;
        for(int iVtx = 0; iVtx < nbVtcs; iVtx++) {
          MVertex *vtx = tgtElmt->getVertex(iVtx);

          std::map<MVertex *, MVertex *>::iterator tIter = v2v.find(vtx);
          if(tIter == v2v.end()) {
            Msg::Error("Cannot find periodic counterpart of node %d "
                       "of surface %d on surface %d",
                       vtx->getNum(), tgt->tag(), src->tag());
            return;
          }
          else
            vtcs.push_back(tIter->second);
        }

        std::map<MFace, MElement *, Less_Face>::iterator srcIter =
          srcFaces.find(MFace(vtcs));
        if(srcIter == srcFaces.end()) {
          std::ostringstream faceDef;
          for(int iVtx = 0; iVtx < nbVtcs; iVtx++)
            faceDef << vtcs[iVtx]->getNum() << " ";
          Msg::Error("Cannot find periodic counterpart of mesh face %s in "
                     "surface %d on surface %d",
                     faceDef.str().c_str(), tgt->tag(), src->tag());
          return;
        }
        else {
          MElement *srcElmt = srcIter->second;
          for(std::size_t i = nbVtcs; i < srcElmt->getNumVertices(); i++) {
            p2p[tgtElmt->getVertex(i)] = srcElmt->getVertex(i);
          }
        }
      }
    }
  }

  if(CTX::instance()->mesh.hoPeriodic) {
#if defined(HAVE_OPTHOM)
    std::vector<GEntity *> modelFaces;
    modelFaces.insert(modelFaces.end(), m->firstFace(), m->lastFace());
    HighOrderMeshPeriodicity facePeriodicity(modelFaces);
    facePeriodicity.fixPeriodicity();
#else
    Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }

  Msg::Debug("Finalized topology of periodic connections");
}

void SetOrder1(GModel *m, bool onlyVisible)
{
  m->destroyMeshCaches();

  // replace all elements with first order elements
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    setFirstOrder(*it, (*it)->lines, onlyVisible);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    setFirstOrder(*it, (*it)->triangles, onlyVisible);
    setFirstOrder(*it, (*it)->quadrangles, onlyVisible);
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    setFirstOrder(*it, (*it)->tetrahedra, onlyVisible);
    setFirstOrder(*it, (*it)->hexahedra, onlyVisible);
    setFirstOrder(*it, (*it)->prisms, onlyVisible);
    setFirstOrder(*it, (*it)->pyramids, onlyVisible);
  }

  // remove all high order vertices
  std::vector<MVertex *> newHOVert;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    updateHighOrderVertices(*it, newHOVert, onlyVisible);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    updateHighOrderVertices(*it, newHOVert, onlyVisible);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    updateHighOrderVertices(*it, newHOVert, onlyVisible);

  updatePeriodicEdgesAndFaces(m);
}

void checkHighOrderTriangles(const char *cc, GModel *m,
                             std::vector<MElement *> &bad, double &minJGlob)
{
  bad.clear();
  minJGlob = 1.0;
  double minGGlob = 1.0;
  double avg = 0.0;
  int count = 0, nbfair = 0;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      double disto_ = t->distoShapeMeasure();
      double gamma_ = t->gammaShapeMeasure();
      double disto = disto_;
      minJGlob = std::min(minJGlob, disto);
      minGGlob = std::min(minGGlob, gamma_);
      avg += disto;
      count++;
      if(disto < 0)
        bad.push_back(t);
      else if(disto < 0.2)
        nbfair++;
    }
    /*
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++){
      MQuadrangle *t = (*it)->quadrangles[i];
      double disto_ = t->distoShapeMeasure();
      double gamma_ = t->gammaShapeMeasure();
      double disto = disto_;
      minJGlob = std::min(minJGlob, disto);
      minGGlob = std::min(minGGlob, gamma_);
      avg += disto; count++;
      if (disto < 0) bad.push_back(t);
      else if (disto < 0.2) nbfair++;
    }
    */
  }
  if(!count) return;
  if(minJGlob > 0)
    Msg::Info(
      "%s: worst distortion = %g (%d elements in ]0, 0.2]); worst gamma = %g",
      cc, minJGlob, nbfair, minGGlob);
  else
    Msg::Warning(
      "%s: worst distortion = %g (avg = %g, %d elements with jac. < 0); "
      "worst gamma = %g",
      cc, minJGlob, avg / (count ? count : 1), bad.size(), minGGlob);
}

void checkHighOrderTetrahedron(const char *cc, GModel *m,
                               std::vector<MElement *> &bad, double &minJGlob)
{
  bad.clear();
  minJGlob = 1.0;
  double avg = 0.0;
  int count = 0, nbfair = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++) {
      MTetrahedron *t = (*it)->tetrahedra[i];
      double disto_ = t->distoShapeMeasure();
      minJGlob = std::min(minJGlob, disto_);
      avg += disto_;
      count++;
      if(disto_ < 0)
        bad.push_back(t);
      else if(disto_ < 0.2)
        nbfair++;
    }
  }
  if(!count) return;

  if(minJGlob > 0)
    Msg::Info("%s: worst distortion = %g (%d elements in ]0, 0.2])", cc,
              minJGlob, nbfair);
  else
    Msg::Warning(
      "%s: worst distortion = %g (avg = %g, %d elements with jac. < 0)", cc,
      minJGlob, avg / (count ? count : 1), bad.size());
}

void getMeshInfoForHighOrder(GModel *gm, int &meshOrder, bool &complete,
                             bool &CAD)
{
  meshOrder = -1;
  CAD = true;
  complete = true;
  // The following code does not allow to determine accurately if elements
  // are complete or not. To be more precise, we should try to find a hexahedron
  // if order = 2+, a prism or a pyramid if order = 3+ or a tet if order = 4+
  // and so on...
  // But it is more likely that we want complete elements so always
  // setting true to 'complete' variable is acceptable.
  for(GModel::riter itr = gm->firstRegion(); itr != gm->lastRegion(); ++itr) {
    if((*itr)->getNumMeshElements()) {
      meshOrder = (*itr)->getMeshElement(0)->getPolynomialOrder();
      // complete = (meshOrder <= 2) ? 1 :
      //   (*itr)->getMeshElement(0)->getNumVolumeVertices();
      break;
    }
  }
  for(GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
    if((*itf)->getNumMeshElements()) {
      if(meshOrder == -1) {
        meshOrder = (*itf)->getMeshElement(0)->getPolynomialOrder();
        // complete = (meshOrder <= 2) ? 1 :
        //   (*itf)->getMeshElement(0)->getNumFaceVertices();
        // if((*itf)->geomType() == GEntity::DiscreteSurface) CAD = false;
        break;
      }
    }
  }
}

void SetOrderN(GModel *m, int order, bool linear, bool incomplete,
               bool onlyVisible)
{
  // replace all the elements in the mesh with second order elements
  // by creating unique vertices on the edges/faces of the mesh:
  //
  // - if linear is set to true, new vertices are created by linear
  //   interpolation between existing ones. If not, new vertices are
  //   created on the exact geometry, provided that the geometrical
  //   edges/faces are discretized with 1D/2D elements. (I.e., if
  //   there are only 3D elements in the mesh then any new vertices on
  //   the boundary will always be created by linear interpolation,
  //   whether linear is set or not.)
  //
  // - if incomplete is set to true, we only create new vertices on
  //   edges (creating 8-node quads, 20-node hexas, etc., instead of
  //   9-node quads, 27-node hexas, etc.)

  // - if onlyVisible is true, then only the visible entities will be curved.

  int nPts = order - 1;

  char msg[256];
  sprintf(msg, "Meshing order %d (curvilinear %s)...", order,
          linear ? "off" : "on");

  Msg::StatusBar(true, msg);

  double t1 = Cpu();

  m->destroyMeshCaches();

  // Keep track of vertex/entities created
  edgeContainer edgeVertices;
  faceContainer faceVertices;
  std::map<GEntity *, std::vector<MVertex *> > newHOVert;

  Msg::ResetProgressMeter();

  int counter = 0,
      nTot = m->getNumEdges() + m->getNumFaces() + m->getNumRegions();

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    Msg::Info("Meshing curve %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, nTot, false, msg);
    if(onlyVisible && !(*it)->getVisibility()) continue;
    setHighOrder(*it, newHOVert[*it], edgeVertices, linear, nPts);
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    Msg::Info("Meshing surface %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, nTot, false, msg);
    if(onlyVisible && !(*it)->getVisibility()) continue;
    setHighOrder(*it, newHOVert[*it], edgeVertices, faceVertices, linear,
                 incomplete, nPts);
    if((*it)->getColumns() != 0) (*it)->getColumns()->clearElementData();
  }

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    Msg::Info("Meshing volume %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, nTot, false, msg);
    if(onlyVisible && !(*it)->getVisibility()) continue;
    setHighOrder(*it, newHOVert[*it], edgeVertices, faceVertices, incomplete,
                 nPts);
    if((*it)->getColumns() != 0) (*it)->getColumns()->clearElementData();
  }

  // Update all high order vertices
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    updateHighOrderVertices(*it, newHOVert[*it], onlyVisible);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    updateHighOrderVertices(*it, newHOVert[*it], onlyVisible);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    updateHighOrderVertices(*it, newHOVert[*it], onlyVisible);

  if(CTX::instance()->mesh.hoOptimize) {
#if defined(HAVE_OPTHOM)
    // Determine mesh dimension and curve BL elements
    FastCurvingParameters p;
    p.dim = 0;
    p.curveOuterBL = FastCurvingParameters::OUTER_CURVE;
    p.thickness = false;
    // p.optimizeGeometry = true;
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
      if((*it)->getNumMeshElements() > 0) {
        p.dim = 3;
        break;
      }
    if(p.dim == 0)
      for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
        if((*it)->getNumMeshElements() > 0) {
          p.dim = 2;
          break;
        }
    if(p.dim == 2) HighOrderMeshFastCurving(GModel::current(), p, true);
#else
  // Msg::Error("High-order mesh optimization requires the OPTHOM module");
#endif
  }

  updatePeriodicEdgesAndFaces(m);

  double t2 = Cpu();

  std::vector<MElement *> bad;
  double worst;
  checkHighOrderTriangles("Surface mesh", m, bad, worst);
  checkHighOrderTetrahedron("Volume mesh", m, bad, worst);
  // FIXME : add other element check

  Msg::StatusBar(true, "Done meshing order %d (%g s)", order, t2 - t1);
}

void SetHighOrderComplete(GModel *m, bool onlyVisible)
{
  faceContainer faceVertices;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    if(onlyVisible && !(*it)->getVisibility()) continue;
    std::vector<MVertex *> dumNewHOVert;
    std::vector<MTriangle *> newT;
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      std::vector<MVertex *> vv;
      for(std::size_t j = 3; j < t->getNumVertices() - t->getNumFaceVertices();
          j++)
        vv.push_back(t->getVertex(j));
      int nPts = t->getPolynomialOrder() - 1;
      getFaceVertices(*it, t, vv, dumNewHOVert, faceVertices, false, nPts);
      newT.push_back(new MTriangleN(t->getVertex(0), t->getVertex(1),
                                    t->getVertex(2), vv, nPts + 1, 0,
                                    t->getPartition()));
      delete t;
    }
    (*it)->triangles = newT;

    std::vector<MQuadrangle *> newQ;
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++) {
      MQuadrangle *t = (*it)->quadrangles[i];

      std::vector<MVertex *> vv;
      vv.reserve(t->getNumVertices() - t->getNumFaceVertices() - 4);

      for(std::size_t j = 4; j < t->getNumVertices() - t->getNumFaceVertices();
          j++)
        vv.push_back(t->getVertex(j));

      int nPts = t->getPolynomialOrder() - 1;
      getFaceVertices(*it, t, vv, dumNewHOVert, faceVertices, false, nPts);
      newQ.push_back(new MQuadrangleN(t->getVertex(0), t->getVertex(1),
                                      t->getVertex(2), t->getVertex(3), vv,
                                      nPts + 1, 0, t->getPartition()));
      delete t;
    }
    (*it)->quadrangles = newQ;

    std::set<MVertex *> newV;
    for(std::size_t i = 0; i < (*it)->getNumMeshElements(); ++i) {
      MElement *e = (*it)->getMeshElement(i);
      for(std::size_t j = 0; j < e->getNumVertices(); j++)
        newV.insert(e->getVertex(j));
    }
    (*it)->mesh_vertices.clear();
    (*it)->mesh_vertices.insert((*it)->mesh_vertices.begin(), newV.begin(),
                                newV.end());
  }

  updatePeriodicEdgesAndFaces(m);
}

void SetHighOrderIncomplete(GModel *m, bool onlyVisible)
{
  std::set<MVertex *> toDelete;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    if(onlyVisible && !(*it)->getVisibility()) continue;
    std::vector<MTriangle *> newT;

    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      std::vector<MVertex *> vt;
      int order = t->getPolynomialOrder();
      for(std::size_t j = 3; j < t->getNumVertices() - t->getNumFaceVertices();
          j++)
        vt.push_back(t->getVertex(j));
      for(std::size_t j = t->getNumVertices() - t->getNumFaceVertices();
          j < t->getNumVertices(); j++)
        toDelete.insert(t->getVertex(j));
      newT.push_back(new MTriangleN(t->getVertex(0), t->getVertex(1),
                                    t->getVertex(2), vt, order, 0,
                                    t->getPartition()));
      delete t;
    }
    (*it)->triangles = newT;

    std::vector<MQuadrangle *> newQ;
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++) {
      MQuadrangle *q = (*it)->quadrangles[i];
      std::vector<MVertex *> vt;
      int nPts = q->getPolynomialOrder() - 1;
      for(std::size_t j = 4; j < q->getNumVertices() - q->getNumFaceVertices();
          j++)
        vt.push_back(q->getVertex(j));
      for(std::size_t j = q->getNumVertices() - q->getNumFaceVertices();
          j < q->getNumVertices(); j++)
        toDelete.insert(q->getVertex(j));
      newQ.push_back(new MQuadrangleN(q->getVertex(0), q->getVertex(1),
                                      q->getVertex(2), q->getVertex(3), vt,
                                      nPts + 1, 0, q->getPartition()));
      delete q;
    }
    (*it)->quadrangles = newQ;

    std::vector<MVertex *> newV;
    int numd = 0;
    for(std::size_t i = 0; i < (*it)->mesh_vertices.size(); ++i) {
      if(toDelete.find((*it)->mesh_vertices[i]) == toDelete.end())
        newV.push_back((*it)->mesh_vertices[i]);
      else {
        delete(*it)->mesh_vertices[i];
        numd++;
      }
    }
    (*it)->mesh_vertices = newV;
  }

  updatePeriodicEdgesAndFaces(m);
}
