// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Context.h"
#include "BasisFactory.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#endif

#include <cstring>

#define SQU(a)      ((a)*(a))

void MTriangle::getEdgeRep(bool curved, int num, double *x, double *y, double *z,
                           SVector3 *n)
{
  // don't use MElement::_getEdgeRep: it's slow due to the creation of MFace
  // could speed this up by computing and storing the normal only if num==0; we
  // always call getEdgeRep in sequence
  MVertex *v0 = _v[edges_tri(num, 0)];
  MVertex *v1 = _v[edges_tri(num, 1)];
  x[0] = v0->x(); y[0] = v0->y(); z[0] = v0->z();
  x[1] = v1->x(); y[1] = v1->y(); z[1] = v1->z();
  if(CTX::instance()->mesh.lightLines){
    static const int vv[3] = {2, 0, 1};
    MVertex *v2 = _v[vv[num]];
    SVector3 t1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
    SVector3 t2(v2->x() - x[0], v2->y() - y[0], v2->z() - z[0]);
    SVector3 normal = crossprod(t1, t2);
    normal.normalize();
    n[0] = n[1] = normal;
  }
  else{
    n[0] = n[1] = SVector3(0., 0., 1.);
  }
}

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
  return qmTriangle::angles(this);
#else
  return 0.;
#endif
}

double MTriangle::etaShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmTriangle::eta(this);
#else
  return 0.;
#endif
}


double MTriangle::gammaShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmTriangle::gamma(this);
#else
  return 0.;
#endif
}

void MTriangle::xyz2uvw(double xyz[3], double uvw[3]) const
{
  const double O[3] = {_v[0]->x(), _v[0]->y(), _v[0]->z()};
  const double d[3] = {xyz[0] - O[0], xyz[1] - O[1], xyz[2] - O[2]};
  const double d1[3] = {_v[1]->x() - O[0], _v[1]->y() - O[1], _v[1]->z() - O[2]};
  const double d2[3] = {_v[2]->x() - O[0], _v[2]->y() - O[1], _v[2]->z() - O[2]};
  const double Jxy = d1[0] * d2[1] - d1[1] * d2[0];
  const double Jxz = d1[0] * d2[2] - d1[2] * d2[0];
  const double Jyz = d1[1] * d2[2] - d1[2] * d2[1];
  if ((fabs(Jxy) > fabs(Jxz)) && (fabs(Jxy) > fabs(Jyz))){
    uvw[0] = (d[0] * d2[1] - d[1] * d2[0]) / Jxy;
    uvw[1] = (d[1] * d1[0] - d[0] * d1[1]) / Jxy;
  }
  else if (fabs(Jxz) > fabs(Jyz)){
    uvw[0] = (d[0] * d2[2] - d[2] * d2[0]) / Jxz;
    uvw[1] = (d[2] * d1[0] - d[0] * d1[2]) / Jxz;
  }
  else{
    uvw[0] = (d[1] * d2[2] - d[2] * d2[1]) / Jyz;
    uvw[1] = (d[2] * d1[1] - d[1] * d1[2]) / Jyz;
  }
  uvw[2] = 0.;
}

int MTriangleN::getNumEdgesRep(bool curved) {
  return curved ? 3 * CTX::instance()->mesh.numSubEdges : 3;
}

int MTriangle6::getNumEdgesRep(bool curved) {
  return curved ? 3 * CTX::instance()->mesh.numSubEdges : 3;
}

static void _myGetEdgeRep(MTriangle *t, int num, double *x, double *y, double *z,
                          SVector3 *n, int numSubEdges)
{
  n[0] = n[1] = t->getFace(0).normal();

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

void MTriangleN::getEdgeRep(bool curved, int num,
                            double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MTriangle::getEdgeRep(false, num, x, y, z, n);
}

void MTriangle6::getEdgeRep(bool curved, int num,
                            double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MTriangle::getEdgeRep(false, num, x, y, z, n);
}

int MTriangle6::getNumFacesRep(bool curved)
{
  return curved ? SQU(CTX::instance()->mesh.numSubEdges) : 1;
}
int MTriangleN::getNumFacesRep(bool curved)
{
  return curved ? SQU(CTX::instance()->mesh.numSubEdges) : 1;
}

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

void MTriangleN::getFaceRep(bool curved, int num,
                            double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MTriangle::getFaceRep(false, num, x, y, z, n);
}

void MTriangle6::getFaceRep(bool curved, int num,
                            double *x, double *y, double *z, SVector3 *n)
{
  if (curved) _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else MTriangle::getFaceRep(false, num, x, y, z, n);
}

void MTriangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQTPts(pOrder);
  *pts = getGQTPts(pOrder);
}

void MTriangle::reorient(int rot,bool swap)
{
  if (rot == 0 && !swap) return;

  MVertex* tmp[3];
  std::memcpy(tmp,_v,3*sizeof(MVertex*));
  if (swap) for (int i=0;i<3;i++) _v[i] = tmp[(3-i+rot)%3];
  else      for (int i=0;i<3;i++) _v[i] = tmp[(3+i-rot)%3];
}

#include "HighOrder.h"

void MTriangle6::reorient(int rot, bool swap)
{
  if (rot == 0 && !swap) return;

  MTriangle::reorient(rot,swap);
  MVertex* tmp[3];
  std::memcpy(tmp,_vs,3*sizeof(MVertex*));
  if (swap) for (int i=0;i<3;i++) _vs[i] = tmp[(5+rot-i)%3];
  else      for (int i=0;i<3;i++) _vs[i] = tmp[(3-rot+i)%3];
}

void MTriangleN::reorient(int rot, bool swap)
{
  if (rot == 0 && !swap) return;

  MTriangle::reorient(rot,swap);

  std::vector<MVertex*> tmp;
  int order  = getPolynomialOrder();
  int nbEdge =  order - 1;
  unsigned int idx = 0;

  if (swap) {
    for (int iEdge=0;iEdge<3;iEdge++) {
      int edgeIdx = ((5-iEdge+rot)%3)*nbEdge;
      for (int i=nbEdge-1;i>=0;i--) tmp.push_back(_vs[edgeIdx + i]);
    }
  }
  else {
    for (int iEdge=0;iEdge<3;iEdge++) {
      int edgeIdx = ((3+iEdge-rot)%3)*nbEdge;
      for (int i=0;i<nbEdge;i++) tmp.push_back(_vs[edgeIdx + i]);
    }
  }

  idx += 3*nbEdge;

  if (_vs.size() > idx ) {
    if (order == 3) tmp.push_back(_vs[idx]);
    if (order == 4) {
      if (swap) for(int i=0;i<3;i++) tmp.push_back(_vs[idx+(3+rot-i)%3]);
      else      for(int i=0;i<3;i++) tmp.push_back(_vs[idx+(3+i-rot)%3]);
    }
    if (order >=5)
      Msg::Error("Reorientation of a triangle not supported above order 4");
  }
  _vs = tmp;
}
