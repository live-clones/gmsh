// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
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

double MTriangle::getVolume()
{
  if(getNumVertices() > 3)
    return MElement::getVolume();
  SPoint3 p0(_v[0]->x(), _v[0]->y(), _v[0]->z());
  SPoint3 p1(_v[1]->x(), _v[1]->y(), _v[1]->z());
  SPoint3 p2(_v[2]->x(), _v[2]->y(), _v[2]->z());
  SVector3 v1(p0, p1), v2(p0, p2);
  return norm(crossprod(v1, v2)) / 2.;
}

double MTriangle::distoShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmDistorsionOfMapping(this);
#else
  return 0.;
#endif
}

double MTriangle::getInnerRadius()
{
  // radius of inscribed circle = 2 * Area / sum(Line_i)
  double dist[3], k = 0.;
  for (int i = 0; i < 3; i++){
    MEdge e = getEdge(i);
    dist[i] = e.getVertex(0)->distance(e.getVertex(1));
    k += 0.5 * dist[i];
  }
  double area = sqrt(k*(k-dist[0])*(k-dist[1])*(k-dist[2]));
  return area/k;
}

double MTriangle::getOuterRadius()
{
  // radius of circle circumscribing a triangle
  double dist[3], k = 0.;
  for (int i = 0; i < 3; i++){
    MEdge e = getEdge(i);
    dist[i] = e.getVertex(0)->distance(e.getVertex(1));
    k += 0.5 * dist[i];
  }
  double area = sqrt(k*(k-dist[0])*(k-dist[1])*(k-dist[2]));
  return dist[0]*dist[1]*dist[2]/(4*area);
}

double MTriangle::angleShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmTriangleAngles(this);
#else
  return 0.;
#endif
}

double MTriangle::etaShapeMeasure()
{
  double a1 = 180 * angle3Vertices(_v[0], _v[1], _v[2]) / M_PI;
  double a2 = 180 * angle3Vertices(_v[1], _v[2], _v[0]) / M_PI;
  double a3 = 180 * angle3Vertices(_v[2], _v[0], _v[1]) / M_PI;

  double amin = std::min(std::min(a1,a2),a3);
  double angle = fabs(60. - amin);
  return 1.-angle/60;
}


double MTriangle::gammaShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmTriangle(this, QMTRI_RHO);
#else
  return 0.;
#endif
}

 void MTriangle::xyz2uvw(double xyz[3], double uvw[3])
 {
   const double O[3] = {_v[0]->x(), _v[0]->y(), _v[0]->z()};
   const double d[3] = {xyz[0] - O[0], xyz[1] - O[1], xyz[2] - O[2]};
   const double d1[3] = {_v[1]->x() - O[0], _v[1]->y() - O[1], _v[1]->z() - O[2]};
   const double d2[3] = {_v[2]->x() - O[0], _v[2]->y() - O[1], _v[2]->z() - O[2]};
   const double Jxy = d1[0] * d2[1] - d1[1] * d2[0];
   const double Jxz = d1[0] * d2[2] - d1[2] * d2[0];
   const double Jyz = d1[1] * d2[2] - d1[2] * d2[1];
   if ((fabs(Jxy) > fabs(Jxz)) && (fabs(Jxy) > fabs(Jyz)))
   {
     uvw[0] = (d[0] * d2[1] - d[1] * d2[0]) / Jxy;
     uvw[1] = (d[1] * d1[0] - d[0] * d1[1]) / Jxy;
   }
   else if (fabs(Jxz) > fabs(Jyz))
   {
     uvw[0] = (d[0] * d2[2] - d[2] * d2[0]) / Jxz;
     uvw[1] = (d[2] * d1[0] - d[0] * d1[2]) / Jxz;
   }
   else
   {
     uvw[0] = (d[1] * d2[2] - d[2] * d2[1]) / Jyz;
     uvw[1] = (d[2] * d1[1] - d[1] * d1[2]) / Jyz;
   }
   uvw[2] = 0.;
}

const polynomialBasis* MTriangle::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;

  int nf = getNumFaceVertices();

  if ((nf == 0) && (o == -1)) {
    switch (order) {
    case 0: return polynomialBases::find(MSH_TRI_1);
    case 1: return polynomialBases::find(MSH_TRI_3);
    case 2: return polynomialBases::find(MSH_TRI_6);
    case 3: return polynomialBases::find(MSH_TRI_9);
    case 4: return polynomialBases::find(MSH_TRI_12);
    case 5: return polynomialBases::find(MSH_TRI_15I);
    case 6: return polynomialBases::find(MSH_TRI_18);
    case 7: return polynomialBases::find(MSH_TRI_21I);
    case 8: return polynomialBases::find(MSH_TRI_24);
    case 9: return polynomialBases::find(MSH_TRI_27);
    case 10: return polynomialBases::find(MSH_TRI_30);
    default: Msg::Error("Order %d triangle incomplete function space not implemented", order);
    }
  }
  else {
    switch (order) {
    case 0: return polynomialBases::find(MSH_TRI_1);
    case 1: return polynomialBases::find(MSH_TRI_3);
    case 2: return polynomialBases::find(MSH_TRI_6);
    case 3: return polynomialBases::find(MSH_TRI_10);
    case 4: return polynomialBases::find(MSH_TRI_15);
    case 5: return polynomialBases::find(MSH_TRI_21);
    case 6: return polynomialBases::find(MSH_TRI_28);
    case 7: return polynomialBases::find(MSH_TRI_36);
    case 8: return polynomialBases::find(MSH_TRI_45);
    case 9: return polynomialBases::find(MSH_TRI_55);
    case 10: return polynomialBases::find(MSH_TRI_66);
    default: Msg::Error("Order %d triangle function space not implemented", order);
    }
  }
  return 0;
}

const JacobianBasis* MTriangle::getJacobianFuncSpace(int o) const
{

  int order = (o == -1) ? getPolynomialOrder() : o;

  int nf = getNumFaceVertices();

  if ((nf == 0) && (o == -1)) {
    switch (order) {
    case 0: return JacobianBasis::find(MSH_TRI_1);
    case 1: return JacobianBasis::find(MSH_TRI_3);
    case 2: return JacobianBasis::find(MSH_TRI_6);
    case 3: return JacobianBasis::find(MSH_TRI_9);
    case 4: return JacobianBasis::find(MSH_TRI_12);
    case 5: return JacobianBasis::find(MSH_TRI_15I);
    case 6: return JacobianBasis::find(MSH_TRI_18);
    case 7: return JacobianBasis::find(MSH_TRI_21I);
    case 8: return JacobianBasis::find(MSH_TRI_24);
    case 9: return JacobianBasis::find(MSH_TRI_27);
    case 10: return JacobianBasis::find(MSH_TRI_30);
    default: Msg::Error("Order %d triangle incomplete function space not implemented", order);
    }
  }
  else {
    switch (order) {
    case 1: return JacobianBasis::find(MSH_TRI_3);
    case 2: return JacobianBasis::find(MSH_TRI_6);
    case 3: return JacobianBasis::find(MSH_TRI_10);
    case 4: return JacobianBasis::find(MSH_TRI_15);
    case 5: return JacobianBasis::find(MSH_TRI_21);
    case 6: return JacobianBasis::find(MSH_TRI_28);
    case 7: return JacobianBasis::find(MSH_TRI_36);
    case 8: return JacobianBasis::find(MSH_TRI_45);
    case 9: return JacobianBasis::find(MSH_TRI_55);
    case 10: return JacobianBasis::find(MSH_TRI_66);
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
