// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "MTriangle.h"
#include "Numeric.h"
#include "Context.h"
#include "GmshDefines.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#endif

#define SQU(a)      ((a)*(a))

SPoint3 MTriangle::circumcenter()
{
  double p1[3] = {_v[0]->x(), _v[0]->y(), _v[0]->z()};
  double p2[3] = {_v[1]->x(), _v[1]->y(), _v[1]->z()};
  double p3[3] = {_v[2]->x(), _v[2]->y(), _v[2]->z()};
  double res[3];
  circumCenterXYZ(p1, p2, p3, res);
  return SPoint3(res[0], res[1], res[2]);
}

double MTriangle::distoShapeMeasure()
{
#if defined(HAVE_MESH)
  //return qmTriangleAngles(this);
  return qmDistorsionOfMapping(this);
#else
  return 0.;
#endif
}

double MTriangle::angleShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmTriangleAngles(this);
#else
  return 0.;
#endif
}

double MTriangle::gammaShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmTriangle(this, QMTRI_RHO);
#else
  return 0.;
#endif
}

const polynomialBasis* MTriangle::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;

  int nf = getNumFaceVertices();  

  if ((nf == 0) && (o == -1)) {
    switch (order) {
    case 1: return &polynomialBases::find(MSH_TRI_3);
    case 2: return &polynomialBases::find(MSH_TRI_6);
    case 3: return &polynomialBases::find(MSH_TRI_9);
    case 4: return &polynomialBases::find(MSH_TRI_12);
    case 5: return &polynomialBases::find(MSH_TRI_15I);
    default: Msg::Error("Order %d triangle function space not implemented", order);
    }
  }
  else { 
    switch (order) {
    case 1: return &polynomialBases::find(MSH_TRI_3);
    case 2: return &polynomialBases::find(MSH_TRI_6);
    case 3: return &polynomialBases::find(MSH_TRI_10);
    case 4: return &polynomialBases::find(MSH_TRI_15);
    case 5: return &polynomialBases::find(MSH_TRI_21);
    default: Msg::Error("Order %d triangle function space not implemented", order);
    }
  }
  return 0;
}

int MTriangleN::getNumEdgesRep(){ return 3 * CTX::instance()->mesh.numSubEdges; }
int MTriangle6::getNumEdgesRep(){ return 3 * CTX::instance()->mesh.numSubEdges; }

static void _myGetEdgeRep(MTriangle *t, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{
  n[0] = n[1] = n[2] = t->getFace(0).normal();

  if (num < numSubEdges){
    SPoint3 pnt1, pnt2;
    t->pnt((double)num / numSubEdges, 0., 0.,pnt1);
    t->pnt((double)(num + 1) / numSubEdges, 0., 0, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return;
  }  
  if (num < 2 * numSubEdges){
    SPoint3 pnt1, pnt2;
    num -= numSubEdges;
    t->pnt(1. - (double)num / numSubEdges, (double)num / numSubEdges, 0, pnt1);
    t->pnt(1. - (double)(num + 1) / numSubEdges, (double)(num + 1) / numSubEdges, 0, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return ;
  }  
  {
    SPoint3 pnt1, pnt2;
    num -= 2 * numSubEdges;
    t->pnt(0, (double)num / numSubEdges, 0,pnt1);
    t->pnt(0, (double)(num + 1) / numSubEdges, 0,pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
  }
}

void MTriangleN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

void MTriangle6::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

int MTriangle6::getNumFacesRep(){ return SQU(CTX::instance()->mesh.numSubEdges); }
int MTriangleN::getNumFacesRep(){ return SQU(CTX::instance()->mesh.numSubEdges); }

static void _myGetFaceRep(MTriangle *t, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{

  // on the first layer, we have (numSubEdges-1) * 2 + 1 triangles
  // on the second layer, we have (numSubEdges-2) * 2 + 1 triangles
  // on the ith layer, we have (numSubEdges-1-i) * 2 + 1 triangles
  int ix = 0, iy = 0;
  int nbt = 0;
  for (int i = 0; i < numSubEdges; i++){
    int nbl = (numSubEdges - i - 1) * 2 + 1;
    nbt += nbl;
    if (nbt > num){
      iy = i;
      ix = nbl - (nbt - num);
      break;
    }
  }

  const double d = 1. / numSubEdges;

  SPoint3 pnt1, pnt2, pnt3;
  double J1[3][3], J2[3][3], J3[3][3];
  if (ix % 2 == 0){
    t->pnt(ix / 2 * d, iy * d, 0, pnt1);
    t->pnt((ix / 2 + 1) * d, iy * d, 0, pnt2);
    t->pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    t->getJacobian(ix / 2 * d, iy * d, 0, J1);
    t->getJacobian((ix / 2 + 1) * d, iy * d, 0, J2);
    t->getJacobian(ix / 2 * d, (iy + 1) * d, 0, J3);
  }
  else{
    t->pnt((ix / 2 + 1) * d, iy * d, 0, pnt1);
    t->pnt((ix / 2 + 1) * d, (iy + 1) * d, 0, pnt2);
    t->pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    t->getJacobian((ix / 2 + 1) * d, iy * d, 0, J1);
    t->getJacobian((ix / 2 + 1) * d, (iy + 1) * d, 0, J2);
    t->getJacobian(ix / 2 * d, (iy + 1) * d, 0, J3);
  }
  {
    SVector3 d1(J1[0][0], J1[0][1], J1[0][2]);
    SVector3 d2(J1[1][0], J1[1][1], J1[1][2]);
    n[0] = crossprod(d1, d2);
    n[0].normalize();
  }
  {
    SVector3 d1(J2[0][0], J2[0][1], J2[0][2]);
    SVector3 d2(J2[1][0], J2[1][1], J2[1][2]);
    n[1] = crossprod(d1, d2);
    n[1].normalize();
  }
  {
    SVector3 d1(J3[0][0], J3[0][1], J3[0][2]);
    SVector3 d2(J3[1][0], J3[1][1], J3[1][2]);
    n[2] = crossprod(d1, d2);
    n[2].normalize();
  }

  x[0] = pnt1.x(); x[1] = pnt2.x(); x[2] = pnt3.x();
  y[0] = pnt1.y(); y[1] = pnt2.y(); y[2] = pnt3.y();
  z[0] = pnt1.z(); z[1] = pnt2.z(); z[2] = pnt3.z();
}

void MTriangleN::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}
void MTriangle6::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
}

void MTriangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQTPts(pOrder);
  *pts = getGQTPts(pOrder);
}

