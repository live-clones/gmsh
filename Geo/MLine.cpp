// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshDefines.h"
#include "MLine.h"
#include "nodalBasis.h"
#include "BasisFactory.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "decasteljau.h"
#include "bezierBasis.h"

void MLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQLPts(pOrder);
  *pts = getGQLPts(pOrder);
}

double MLine::getInnerRadius() { return _v[0]->distance(_v[1]) * .5; }

double MLine::getLength() { return _v[0]->distance(_v[1]); }

double MLine::getVolume() { return getLength(); }

int MLine3::getNumEdgesRep(bool curved)
{
  return curved ? CTX::instance()->mesh.numSubEdges : 1;
}

void MLine3::getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                        SVector3 *n)
{
  if(curved) {
    int numSubEdges = CTX::instance()->mesh.numSubEdges;
    SPoint3 pnt1, pnt2;
    pnt(-1. + 2 * (double)num / numSubEdges, 0., 0., pnt1);
    pnt(-1. + 2 * (double)(num + 1) / numSubEdges, 0., 0, pnt2);
    x[0] = pnt1.x();
    x[1] = pnt2.x();
    y[0] = pnt1.y();
    y[1] = pnt2.y();
    z[0] = pnt1.z();
    z[1] = pnt2.z();
    n[0] = n[1] = MEdge(_v[0], _v[1]).normal();
  }
  else
    MLine::getEdgeRep(false, num, x, y, z, n);
}

int MLineN::getNumEdgesRep(bool curved)
{
  return curved ? CTX::instance()->mesh.numSubEdges : 1;
}

void MLineN::getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                        SVector3 *n)
{
  if(curved) {
    int numSubEdges = CTX::instance()->mesh.numSubEdges;
    SPoint3 pnt1, pnt2;
    pnt(-1. + 2 * (double)num / numSubEdges, 0., 0., pnt1);
    pnt(-1. + 2 * (double)(num + 1) / numSubEdges, 0., 0, pnt2);
    x[0] = pnt1.x();
    x[1] = pnt2.x();
    y[0] = pnt1.y();
    y[1] = pnt2.y();
    z[0] = pnt1.z();
    z[1] = pnt2.z();
    n[0] = n[1] = MEdge(_v[0], _v[1]).normal();
  }
  else
    MLine::getEdgeRep(false, num, x, y, z, n);
}

void MLine::discretize(double tol, std::vector<SPoint3> &dpts,
                       std::vector<double> &ts)
{
  ts.clear();
  ts.push_back(-1);
  ts.push_back(1);
  dpts.clear();
  dpts.push_back(getVertex(0)->point());
  dpts.push_back(getVertex(1)->point());
}

void MLine3::discretize(double tol, std::vector<SPoint3> &dpts,
                        std::vector<double> &ts)
{
  SPoint3 p0 = getVertex(0)->point();
  SPoint3 p2 = getVertex(1)->point();
  SPoint3 p1 = getVertex(2)->point() * 2 - (p0 + p2) * 0.5;
  decasteljau(tol, p0, p1, p2, dpts, ts);
  for(size_t i = 0; i < ts.size(); ++i) ts[i] = -1 + 2 * ts[i];
}

void MLineN::discretize(double tol, std::vector<SPoint3> &dpts,
                        std::vector<double> &ts)
{
  int order = getPolynomialOrder();
  if(order == 3) {
    SPoint3 p0 = getVertex(0)->point();
    SPoint3 p3 = getVertex(1)->point();
    SPoint3 p1 = p0 * (-5. / 6) + p3 * (1. / 3) + getVertex(2)->point() * 3. -
                 getVertex(3)->point() * 1.5;
    SPoint3 p2 = p0 * (1. / 3) + p3 * (-5. / 6) - getVertex(2)->point() * 1.5 +
                 getVertex(3)->point() * 3.;
    decasteljau(tol, p0, p1, p2, p3, dpts, ts);
    for(size_t i = 0; i < ts.size(); ++i) ts[i] = -1 + 2 * ts[i];
    return;
  }
  fullMatrix<double> lagNodes(order + 1, 3), bezNodes(order + 1, 3);
  for(int i = 0; i < order + 1; ++i) {
    MVertex *v = getVertex(i);
    lagNodes(i, 0) = v->x();
    lagNodes(i, 1) = v->y();
    lagNodes(i, 2) = v->z();
  }
  bezierCoeff bezNodes2(getFuncSpaceData(), lagNodes);
  std::vector<SPoint3> pts(bezNodes.size1());
  pts[0][0] = bezNodes(0, 0);
  pts[0][1] = bezNodes(0, 1);
  pts[0][2] = bezNodes(0, 2);
  pts[order][0] = bezNodes(1, 0);
  pts[order][1] = bezNodes(1, 1);
  pts[order][2] = bezNodes(1, 2);
  for(int i = 0; i < order - 1; ++i) {
    pts[i + 1][0] = bezNodes(i + 2, 0);
    pts[i + 1][1] = bezNodes(i + 2, 1);
    pts[i + 1][2] = bezNodes(i + 2, 2);
  }
  decasteljau(tol, pts, dpts, ts);
  for(size_t i = 0; i < ts.size(); ++i) ts[i] = -1 + 2 * ts[i];
}
