// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "MTriangle.h"
#include "Numeric.h"
#include "Context.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#include "HighOrder.h"
#endif

#include <cmath>
#include <cstring>

void MTriangle::getEdgeRep(bool curved, int num, double *x, double *y,
                           double *z, SVector3 *n)
{
  // don't use MElement::_getEdgeRep: it's slow due to the creation of MFace
  // could speed this up by computing and storing the normal only if num==0; we
  // always call getEdgeRep in sequence
  MVertex *v0 = _v[edges_tri(num, 0)];
  MVertex *v1 = _v[edges_tri(num, 1)];
  x[0] = v0->x();
  y[0] = v0->y();
  z[0] = v0->z();
  x[1] = v1->x();
  y[1] = v1->y();
  z[1] = v1->z();
  if(CTX::instance()->mesh.lightLines) {
    static const int vv[3] = {2, 0, 1};
    MVertex *v2 = _v[vv[num]];
    SVector3 t1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
    SVector3 t2(v2->x() - x[0], v2->y() - y[0], v2->z() - z[0]);
    SVector3 normal = crossprod(t1, t2);
    normal.normalize();
    n[0] = n[1] = normal;
  }
  else {
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
  if(getNumVertices() > 3) return MElement::getVolume();
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
  for(int i = 0; i < 3; i++) {
    MEdge e = getEdge(i);
    dist[i] = e.getVertex(0)->distance(e.getVertex(1));
    k += 0.5 * dist[i];
  }
  double const area =
    std::sqrt(k * (k - dist[0]) * (k - dist[1]) * (k - dist[2]));
  return area / k;
}

double MTriangle::getOuterRadius()
{
  // radius of circle circumscribing a triangle
  double dist[3], k = 0.0;
  for(int i = 0; i < 3; i++) {
    MEdge e = getEdge(i);
    dist[i] = e.getVertex(0)->distance(e.getVertex(1));
    k += 0.5 * dist[i];
  }
  double const area =
    std::sqrt(k * (k - dist[0]) * (k - dist[1]) * (k - dist[2]));
  return dist[0] * dist[1] * dist[2] / (4 * area);
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
  //  double M[2][2], R[2];
  //  const SPoint2 p0 (getVertex(0)->x(),getVertex(0)->y());
  //  const SPoint2 p1 (getVertex(1)->x(),getVertex(1)->y());
  //  const SPoint2 p2 (getVertex(2)->x(),getVertex(2)->y());
  //  M[0][0] = p1.x() - p0.x();
  //  M[0][1] = p2.x() - p0.x();
  //  M[1][0] = p1.y() - p0.y();
  //  M[1][1] = p2.y() - p0.y();
  //  R[0] = (xyz[0] - p0.x());
  //  R[1] = (xyz[1] - p0.y());
  //  sys2x2(M, R, uvw);
  //  return;
  const double O[3] = {_v[0]->x(), _v[0]->y(), _v[0]->z()};

  const double d[3] = {xyz[0] - O[0], xyz[1] - O[1], xyz[2] - O[2]};
  const double d1[3] = {_v[1]->x() - O[0], _v[1]->y() - O[1],
                        _v[1]->z() - O[2]};
  const double d2[3] = {_v[2]->x() - O[0], _v[2]->y() - O[1],
                        _v[2]->z() - O[2]};

  const double Jxy = d1[0] * d2[1] - d1[1] * d2[0];
  const double Jxz = d1[0] * d2[2] - d1[2] * d2[0];
  const double Jyz = d1[1] * d2[2] - d1[2] * d2[1];

  if((std::abs(Jxy) > std::abs(Jxz)) && (std::abs(Jxy) > std::abs(Jyz))) {
    uvw[0] = (d[0] * d2[1] - d[1] * d2[0]) / Jxy;
    uvw[1] = (d[1] * d1[0] - d[0] * d1[1]) / Jxy;
  }
  else if(std::abs(Jxz) > std::abs(Jyz)) {
    uvw[0] = (d[0] * d2[2] - d[2] * d2[0]) / Jxz;
    uvw[1] = (d[2] * d1[0] - d[0] * d1[2]) / Jxz;
  }
  else {
    uvw[0] = (d[1] * d2[2] - d[2] * d2[1]) / Jyz;
    uvw[1] = (d[2] * d1[1] - d[1] * d1[2]) / Jyz;
  }
  uvw[2] = 0.0;
}

int MTriangle::numCommonNodesInDualGraph(const MElement *const other) const
{
  switch(other->getType()) {
  case TYPE_PNT: return 1;
  case TYPE_LIN: return 2;
  case TYPE_TRI: return 2;
  case TYPE_QUA: return 2;
  default: return 3;
  }
}

double MTriangle::getAngleAtVertex(MVertex *v)
{
  if(v == _v[0])
    return angle3Vertices(_v[2], _v[0], _v[1]);
  else if(v == _v[1])
    return angle3Vertices(_v[0], _v[1], _v[2]);
  else if(v == _v[2])
    return angle3Vertices(_v[1], _v[2], _v[0]);
  Msg::Warning("Unknown node in triangle for angle computation");
  return 0.;
}

int MTriangleN::getNumEdgesRep(bool curved)
{
  return curved ? 3 * CTX::instance()->mesh.numSubEdges : 3;
}

int MTriangle6::getNumEdgesRep(bool curved)
{
  return curved ? 3 * CTX::instance()->mesh.numSubEdges : 3;
}

static void _myGetEdgeRep(MTriangle *t, int num, double *x, double *y,
                          double *z, SVector3 *n, int numSubEdges)
{
  n[0] = n[1] = t->getFace(0).normal();

  if(num < numSubEdges) {
    SPoint3 pnt1, pnt2;
    t->pnt((double)num / numSubEdges, 0., 0., pnt1);
    t->pnt((double)(num + 1) / numSubEdges, 0., 0, pnt2);
    x[0] = pnt1.x();
    x[1] = pnt2.x();
    y[0] = pnt1.y();
    y[1] = pnt2.y();
    z[0] = pnt1.z();
    z[1] = pnt2.z();
    return;
  }
  if(num < 2 * numSubEdges) {
    SPoint3 pnt1, pnt2;
    num -= numSubEdges;
    t->pnt(1. - (double)num / numSubEdges, (double)num / numSubEdges, 0, pnt1);
    t->pnt(1. - (double)(num + 1) / numSubEdges,
           (double)(num + 1) / numSubEdges, 0, pnt2);
    x[0] = pnt1.x();
    x[1] = pnt2.x();
    y[0] = pnt1.y();
    y[1] = pnt2.y();
    z[0] = pnt1.z();
    z[1] = pnt2.z();
    return;
  }
  {
    SPoint3 pnt1, pnt2;
    num -= 2 * numSubEdges;
    t->pnt(0, (double)num / numSubEdges, 0, pnt1);
    t->pnt(0, (double)(num + 1) / numSubEdges, 0, pnt2);
    x[0] = pnt1.x();
    x[1] = pnt2.x();
    y[0] = pnt1.y();
    y[1] = pnt2.y();
    z[0] = pnt1.z();
    z[1] = pnt2.z();
  }
}

void MTriangleN::getEdgeRep(bool curved, int num, double *x, double *y,
                            double *z, SVector3 *n)
{
  if(curved)
    _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MTriangle::getEdgeRep(false, num, x, y, z, n);
}

void MTriangle6::getEdgeRep(bool curved, int num, double *x, double *y,
                            double *z, SVector3 *n)
{
  if(curved)
    _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MTriangle::getEdgeRep(false, num, x, y, z, n);
}

bool MTriangle::getFaceInfo(const MFace &face, int &ithFace, int &sign,
                            int &rot) const
{
  ithFace = 0;
  if(_getFaceInfo(MFace(_v[0], _v[1], _v[2]), face, sign, rot)) return true;
  Msg::Error("Could not get face information for triangle %d", getNum());
  return false;
}

int MTriangle6::getNumFacesRep(bool curved)
{
  return curved ? std::pow(CTX::instance()->mesh.numSubEdges, 2) : 1;
}
int MTriangleN::getNumFacesRep(bool curved)
{
  return curved ? std::pow(CTX::instance()->mesh.numSubEdges, 2) : 1;
}

static void _myGetFaceRep(MTriangle *t, int num, double *x, double *y,
                          double *z, SVector3 *n, int numSubEdges)
{
  // on the first layer, we have (numSubEdges-1) * 2 + 1 triangles
  // on the second layer, we have (numSubEdges-2) * 2 + 1 triangles
  // on the ith layer, we have (numSubEdges-1-i) * 2 + 1 triangles
  int ix = 0, iy = 0;
  int nbt = 0;
  for(int i = 0; i < numSubEdges; i++) {
    int nbl = (numSubEdges - i - 1) * 2 + 1;
    nbt += nbl;
    if(nbt > num) {
      iy = i;
      ix = nbl - (nbt - num);
      break;
    }
  }

  const double d = 1. / numSubEdges;

  SPoint3 pnt1, pnt2, pnt3;
  double J1[3][3], J2[3][3], J3[3][3];
  if(ix % 2 == 0) {
    t->pnt(ix / 2 * d, iy * d, 0, pnt1);
    t->pnt((ix / 2 + 1) * d, iy * d, 0, pnt2);
    t->pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    t->getJacobian(ix / 2 * d, iy * d, 0, J1);
    t->getJacobian((ix / 2 + 1) * d, iy * d, 0, J2);
    t->getJacobian(ix / 2 * d, (iy + 1) * d, 0, J3);
  }
  else {
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

  x[0] = pnt1.x();
  x[1] = pnt2.x();
  x[2] = pnt3.x();
  y[0] = pnt1.y();
  y[1] = pnt2.y();
  y[2] = pnt3.y();
  z[0] = pnt1.z();
  z[1] = pnt2.z();
  z[2] = pnt3.z();
}

void MTriangleN::getFaceRep(bool curved, int num, double *x, double *y,
                            double *z, SVector3 *n)
{
  if(curved)
    _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MTriangle::getFaceRep(false, num, x, y, z, n);
}

void MTriangle6::getFaceRep(bool curved, int num, double *x, double *y,
                            double *z, SVector3 *n)
{
  if(curved)
    _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MTriangle::getFaceRep(false, num, x, y, z, n);
}

void MTriangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQTPts(pOrder);
  *pts = getGQTPts(pOrder);
}

void MTriangleN::reverse()
{
  MVertex *tmp;
  tmp = _v[1];
  _v[1] = _v[2];
  _v[2] = tmp;

  int npts = _order - 1, base = 0;
  auto begin = _vs.begin() + base;

  while(npts > 0) {
    std::reverse(begin, begin + 3 * npts);
    base += 3 * npts;
    if(npts > 2) {
      tmp = _vs[base + 1];
      _vs[base + 1] = _vs[base + 2];
      _vs[base + 2] = tmp;
    }
    npts -= 3;
    begin = _vs.begin() + base + 3;
  }
}

void MTriangle::reorient(int rot, bool swap)
{
  if(rot == 0 && !swap) return;

  MVertex *tmp[3];
  std::memcpy(tmp, _v, 3 * sizeof(MVertex *));
  if(swap)
    for(int i = 0; i < 3; i++) _v[i] = tmp[(3 - i + rot) % 3];
  else
    for(int i = 0; i < 3; i++) _v[i] = tmp[(3 + i - rot) % 3];
}

void MTriangle6::reorient(int rot, bool swap)
{
  if(rot == 0 && !swap) return;

  MTriangle::reorient(rot, swap);
  MVertex *tmp[3];
  std::memcpy(tmp, _vs, 3 * sizeof(MVertex *));
  if(swap)
    for(int i = 0; i < 3; i++) _vs[i] = tmp[(5 + rot - i) % 3];
  else
    for(int i = 0; i < 3; i++) _vs[i] = tmp[(3 - rot + i) % 3];
}

std::map<TupleReorientation, IndicesReoriented>
  MTriangleN::_tuple2indicesReoriented;

namespace {
  void _getIndicesReorientedTri(int order, int rot, bool swap,
                                IndicesReoriented &indices)
  {
    fullMatrix<double> ref = gmshGenerateMonomialsTriangle(order);

    indices.resize(ref.size1());
    for(int i = 0; i < ref.size1(); ++i) {
      double u = ref(i, 0);
      double v = ref(i, 1);
      double tmp;
      if(swap) {
        tmp = u;
        u = v;
        v = tmp;
      }
      switch(rot) {
      case 1:
        tmp = u;
        u = order - u - v;
        v = tmp;
        break;
      case 2:
        tmp = v;
        v = order - u - v;
        u = tmp;
        break;
      }
      for(int j = 0; j < ref.size1(); ++j) {
        if(u == ref(j, 0) && v == ref(j, 1)) {
          indices[i] = j;
          break;
        }
      }
    }
  }
} // namespace

void MTriangleN::reorient(int rot, bool swap)
{
  if(rot == 0 && !swap) return;

  TupleReorientation mytuple(getTypeForMSH(), std::make_pair(rot, swap));
  auto it = _tuple2indicesReoriented.find(mytuple);
  if(it == _tuple2indicesReoriented.end()) {
    IndicesReoriented indices;
    _getIndicesReorientedTri(_order, rot, swap, indices);
    _tuple2indicesReoriented[mytuple] = indices;
    it = _tuple2indicesReoriented.find(mytuple);
  }

  IndicesReoriented &indices = it->second;

  // copy vertices
  std::vector<MVertex *> oldv(3 + _vs.size());
  std::copy(_v, _v + 3, oldv.begin());
  std::copy(_vs.begin(), _vs.end(), oldv.begin() + 3);

  // reorient
  for(int i = 0; i < 3; ++i) { _v[i] = oldv[indices[i]]; }
  for(std::size_t i = 0; i < _vs.size(); ++i) { _vs[i] = oldv[indices[3 + i]]; }
}

MFaceN MTriangle::getHighOrderFace(int num, int sign, int rot)
{
  const bool swap = sign == -1;
  std::vector<MVertex *> vertices(getNumVertices());

  if(swap)
    for(int i = 0; i < 3; i++) vertices[i] = _v[(3 - i + rot) % 3];
  else
    for(int i = 0; i < 3; i++) vertices[i] = _v[(3 + i - rot) % 3];

  return MFaceN(TYPE_TRI, 1, vertices);
}

MFaceN MTriangle6::getHighOrderFace(int num, int sign, int rot)
{
  const bool swap = sign == -1;
  std::vector<MVertex *> vertices(getNumVertices());

  if(swap) {
    for(int i = 0; i < 3; i++) {
      vertices[i] = _v[(3 - i + rot) % 3];
      vertices[3 + i] = _vs[(5 - i + rot) % 3];
    }
  }
  else {
    for(int i = 0; i < 3; i++) {
      vertices[i] = _v[(3 + i - rot) % 3];
      vertices[3 + i] = _vs[(3 + i - rot) % 3];
    }
  }
  return MFaceN(TYPE_TRI, 2, vertices);
}

MFaceN MTriangleN::getHighOrderFace(int num, int sign, int rot)
{
  const bool swap = sign == -1;

  TupleReorientation mytuple(TYPE_TRI, std::make_pair(rot, swap));
  auto it = _tuple2indicesReoriented.find(mytuple);
  if(it == _tuple2indicesReoriented.end()) {
    IndicesReoriented indices;
    _getIndicesReorientedTri(_order, rot, swap, indices);
    _tuple2indicesReoriented[mytuple] = indices;
    it = _tuple2indicesReoriented.find(mytuple);
  }

  IndicesReoriented &indices = it->second;

  std::vector<MVertex *> vertices(getNumVertices());
  for(std::size_t i = 0; i < getNumVertices(); ++i) {
    vertices[i] = getVertex(indices[i]);
  }
  return MFaceN(TYPE_TRI, _order, vertices);
}
