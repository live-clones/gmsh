// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <limits>
#include "MHexahedron.h"
#include "Numeric.h"
#include "Context.h"
#include "BasisFactory.h"
#include "polynomialBasis.h"
#include "MQuadrangle.h"
#include "pointsGenerators.h"

#if defined(HAVE_MESH)
#include "qualityMeasures.h"
#endif

std::map<int, IndicesReversed> MHexahedronN::_order2indicesReversedHex;

void MHexahedron::getEdgeRep(bool curved, int num, double *x, double *y,
                             double *z, SVector3 *n)
{
  // don't use MElement::_getEdgeRep: it's slow due to the creation of MFaces
  MVertex *v0 = _v[edges_hexa(num, 0)];
  MVertex *v1 = _v[edges_hexa(num, 1)];
  x[0] = v0->x();
  y[0] = v0->y();
  z[0] = v0->z();
  x[1] = v1->x();
  y[1] = v1->y();
  z[1] = v1->z();
  if(CTX::instance()->mesh.lightLines > 1) {
    static const int vv[12] = {2, 2, 3, 3, 2, 0, 1, 0, 6, 5, 4, 4};
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

int MHexahedron::getVolumeSign()
{
  double mat[3][3];
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[3]->x() - _v[0]->x();
  mat[0][2] = _v[4]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[3]->y() - _v[0]->y();
  mat[1][2] = _v[4]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[3]->z() - _v[0]->z();
  mat[2][2] = _v[4]->z() - _v[0]->z();
  double d = det3x3(mat);
  if(d < 0.)
    return -1;
  else if(d > 0.)
    return 1;
  else
    return 0;
}

void MHexahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQHPts(pOrder);
  *pts = getGQHPts(pOrder);
}

double MHexahedron::angleShapeMeasure()
{
#if defined(HAVE_MESH)
  return qmHexahedron::angles(this);
#else
  return 0.;
#endif
}
double MHexahedron::getInnerRadius()
{
  // Only for vertically aligned elements (not inclined)
  double innerRadius = std::numeric_limits<double>::max();
  for(int i = 0; i < getNumFaces(); i++) {
    MQuadrangle quad(getFace(i).getVertex(0), getFace(i).getVertex(1),
                     getFace(i).getVertex(2), getFace(i).getVertex(3));
    innerRadius = std::min(innerRadius, quad.getInnerRadius());
  }
  return innerRadius;
}

bool MHexahedron::getFaceInfo(const MFace &face, int &ithFace, int &sign,
                              int &rot) const
{
  for(ithFace = 0; ithFace < 6; ithFace++) {
    if(_getFaceInfo(getFace(ithFace), face, sign, rot)) return true;
  }
  Msg::Error("Could not get face information for hexahedron %d", getNum());
  return false;
}

int MHexahedron::numCommonNodesInDualGraph(const MElement *const other) const
{
  switch(other->getType()) {
  case TYPE_PNT: return 1;
  case TYPE_LIN: return 2;
  case TYPE_TRI: return 3;
  default: return 4;
  }
}

static void _myGetEdgeRep(MHexahedron *hex, int num, double *x, double *y,
                          double *z, SVector3 *n, int numSubEdges)
{
  // const int numSubEdges = CTX::instance()->mesh.numSubEdges;
  static double pp[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
                            {-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1}};
  static int ed[12][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2}, {1, 5}, {2, 3},
                          {2, 6}, {3, 7}, {4, 5}, {4, 7}, {5, 6}, {7, 6}};
  int iEdge = num / numSubEdges;
  int iSubEdge = num % numSubEdges;

  int iVertex1 = ed[iEdge][0];
  int iVertex2 = ed[iEdge][1];
  double t1 = (double)iSubEdge / (double)numSubEdges;
  double u1 = pp[iVertex1][0] * (1. - t1) + pp[iVertex2][0] * t1;
  double v1 = pp[iVertex1][1] * (1. - t1) + pp[iVertex2][1] * t1;
  double w1 = pp[iVertex1][2] * (1. - t1) + pp[iVertex2][2] * t1;

  double t2 = (double)(iSubEdge + 1) / (double)numSubEdges;
  double u2 = pp[iVertex1][0] * (1. - t2) + pp[iVertex2][0] * t2;
  double v2 = pp[iVertex1][1] * (1. - t2) + pp[iVertex2][1] * t2;
  double w2 = pp[iVertex1][2] * (1. - t2) + pp[iVertex2][2] * t2;

  SPoint3 pnt1, pnt2;
  hex->pnt(u1, v1, w1, pnt1);
  hex->pnt(u2, v2, w2, pnt2);
  x[0] = pnt1.x();
  x[1] = pnt2.x();
  y[0] = pnt1.y();
  y[1] = pnt2.y();
  z[0] = pnt1.z();
  z[1] = pnt2.z();

  // not great, but better than nothing
  // static const int f[6] = {0, 0, 0, 1, 2, 3};
  n[0] = n[1] = 1;
}

void MHexahedron20::getEdgeRep(bool curved, int num, double *x, double *y,
                               double *z, SVector3 *n)
{
  if(curved)
    _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MHexahedron::getEdgeRep(false, num, x, y, z, n);
}

void MHexahedron27::getEdgeRep(bool curved, int num, double *x, double *y,
                               double *z, SVector3 *n)
{
  if(curved)
    _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MHexahedron::getEdgeRep(false, num, x, y, z, n);
}

void MHexahedronN::getEdgeRep(bool curved, int num, double *x, double *y,
                              double *z, SVector3 *n)
{
  if(curved)
    _myGetEdgeRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MHexahedron::getEdgeRep(false, num, x, y, z, n);
}

int MHexahedron20::getNumEdgesRep(bool curved)
{
  return curved ? 12 * CTX::instance()->mesh.numSubEdges : 12;
}

int MHexahedron27::getNumEdgesRep(bool curved)
{
  return curved ? 12 * CTX::instance()->mesh.numSubEdges : 12;
}

int MHexahedronN::getNumEdgesRep(bool curved)
{
  return curved ? 12 * CTX::instance()->mesh.numSubEdges : 12;
}

void _myGetFaceRep(MHexahedron *hex, int num, double *x, double *y, double *z,
                   SVector3 *n, int numSubEdges)
{
  static double pp[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1},
                            {-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1}};

  int iFace = num / (2 * numSubEdges * numSubEdges);
  int iSubFace = num % (2 * numSubEdges * numSubEdges);

  int iVertex1 = hex->faces_hexa(iFace, 0);
  int iVertex2 = hex->faces_hexa(iFace, 1);
  int iVertex3 = hex->faces_hexa(iFace, 2);
  int iVertex4 = hex->faces_hexa(iFace, 3);

  SPoint3 pnt1, pnt2, pnt3;
  // double J1[3][3], J2[3][3], J3[3][3];

  /*
    0
    0 1
    0 1 2
    0 1 2 3
    0 1 2 3 4
    0 1 2 3 4 5
  */

  // on each layer, we have (numSubEdges) * 2 triangles
  // ix and iy are the coordinates of the sub-quadrangle

  int io = iSubFace % 2;
  int ix = (iSubFace / 2) / numSubEdges;
  int iy = (iSubFace / 2) % numSubEdges;

  const double d = 2. / numSubEdges;
  double ox = -1. + d * ix;
  double oy = -1. + d * iy;

  if(io == 0) {
    double U1 = pp[iVertex1][0] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][0] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][0] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][0] * (1. - ox) * (1 + oy) * .25;
    double V1 = pp[iVertex1][1] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][1] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][1] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][1] * (1. - ox) * (1 + oy) * .25;
    double W1 = pp[iVertex1][2] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][2] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][2] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][2] * (1. - ox) * (1 + oy) * .25;

    ox += d;

    double U2 = pp[iVertex1][0] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][0] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][0] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][0] * (1. - ox) * (1 + oy) * .25;
    double V2 = pp[iVertex1][1] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][1] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][1] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][1] * (1. - ox) * (1 + oy) * .25;
    double W2 = pp[iVertex1][2] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][2] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][2] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][2] * (1. - ox) * (1 + oy) * .25;

    oy += d;

    double U3 = pp[iVertex1][0] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][0] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][0] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][0] * (1. - ox) * (1 + oy) * .25;
    double V3 = pp[iVertex1][1] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][1] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][1] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][1] * (1. - ox) * (1 + oy) * .25;
    double W3 = pp[iVertex1][2] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][2] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][2] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][2] * (1. - ox) * (1 + oy) * .25;

    hex->pnt(U1, V1, W1, pnt1);
    hex->pnt(U2, V2, W2, pnt2);
    hex->pnt(U3, V3, W3, pnt3);
  }
  else {
    double U1 = pp[iVertex1][0] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][0] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][0] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][0] * (1. - ox) * (1 + oy) * .25;
    double V1 = pp[iVertex1][1] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][1] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][1] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][1] * (1. - ox) * (1 + oy) * .25;
    double W1 = pp[iVertex1][2] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][2] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][2] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][2] * (1. - ox) * (1 + oy) * .25;

    ox += d;
    oy += d;

    double U2 = pp[iVertex1][0] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][0] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][0] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][0] * (1. - ox) * (1 + oy) * .25;
    double V2 = pp[iVertex1][1] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][1] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][1] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][1] * (1. - ox) * (1 + oy) * .25;
    double W2 = pp[iVertex1][2] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][2] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][2] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][2] * (1. - ox) * (1 + oy) * .25;

    ox -= d;

    double U3 = pp[iVertex1][0] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][0] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][0] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][0] * (1. - ox) * (1 + oy) * .25;
    double V3 = pp[iVertex1][1] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][1] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][1] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][1] * (1. - ox) * (1 + oy) * .25;
    double W3 = pp[iVertex1][2] * (1. - ox) * (1 - oy) * .25 +
                pp[iVertex2][2] * (1. + ox) * (1 - oy) * .25 +
                pp[iVertex3][2] * (1. + ox) * (1 + oy) * .25 +
                pp[iVertex4][2] * (1. - ox) * (1 + oy) * .25;

    hex->pnt(U1, V1, W1, pnt1);
    hex->pnt(U2, V2, W2, pnt2);
    hex->pnt(U3, V3, W3, pnt3);
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

  SVector3 d1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
  SVector3 d2(x[2] - x[0], y[2] - y[0], z[2] - z[0]);
  n[0] = crossprod(d1, d2);
  n[0].normalize();
  n[1] = n[0];
  n[2] = n[0];
}

void MHexahedron::getFaceRep(bool curved, int num, double *x, double *y,
                             double *z, SVector3 *n)
{
#if defined(HAVE_VISUDEV)
  static const int fquad[24][4] = {
    {0, 3, 2, 1}, {3, 2, 1, 0}, {2, 1, 0, 3}, {1, 0, 3, 2}, {0, 1, 5, 4},
    {1, 5, 4, 0}, {5, 4, 0, 1}, {4, 0, 1, 5}, {0, 4, 7, 3}, {4, 7, 3, 0},
    {7, 3, 0, 4}, {3, 0, 4, 7}, {1, 2, 6, 5}, {2, 6, 5, 1}, {6, 5, 1, 2},
    {5, 1, 2, 6}, {2, 3, 7, 6}, {3, 7, 6, 2}, {7, 6, 2, 3}, {6, 2, 3, 7},
    {4, 5, 6, 7}, {5, 6, 7, 4}, {6, 7, 4, 5}, {7, 4, 5, 6}};
  if(CTX::instance()->heavyVisu) {
    if(CTX::instance()->mesh.numSubEdges > 1) {
      _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
      return;
    }
    _getFaceRepQuad(getVertex(fquad[num][0]), getVertex(fquad[num][1]),
                    getVertex(fquad[num][2]), getVertex(fquad[num][3]), x, y, z,
                    n);
    return;
  }
#endif
  static const int f[12][3] = {{0, 3, 2}, {0, 2, 1}, {0, 1, 5}, {0, 5, 4},
                               {0, 4, 7}, {0, 7, 3}, {1, 2, 6}, {1, 6, 5},
                               {2, 3, 7}, {2, 7, 6}, {4, 5, 6}, {4, 6, 7}};
  _getFaceRep(_v[f[num][0]], _v[f[num][1]], _v[f[num][2]], x, y, z, n);
}

void MHexahedron20::getFaceRep(bool curved, int num, double *x, double *y,
                               double *z, SVector3 *n)
{
  if(curved)
    _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MHexahedron::getFaceRep(false, num, x, y, z, n);
}

void MHexahedron27::getFaceRep(bool curved, int num, double *x, double *y,
                               double *z, SVector3 *n)
{
  if(curved)
    _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MHexahedron::getFaceRep(false, num, x, y, z, n);
}

void MHexahedronN::getFaceRep(bool curved, int num, double *x, double *y,
                              double *z, SVector3 *n)
{
  if(curved)
    _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MHexahedron::getFaceRep(false, num, x, y, z, n);
}

int MHexahedron::getNumFacesRep(bool curved)
{
#if defined(HAVE_VISUDEV)
  if(CTX::instance()->heavyVisu) {
    if(CTX::instance()->mesh.numSubEdges == 1) return 24;
    return 12 * std::pow(CTX::instance()->mesh.numSubEdges, 2);
  }
#endif
  return 12;
}

int MHexahedron20::getNumFacesRep(bool curved)
{
  return curved ? 12 * std::pow(CTX::instance()->mesh.numSubEdges, 2) :
                  MHexahedron::getNumFacesRep(curved);
}

int MHexahedron27::getNumFacesRep(bool curved)
{
  return curved ? 12 * std::pow(CTX::instance()->mesh.numSubEdges, 2) :
                  MHexahedron::getNumFacesRep(curved);
}

int MHexahedronN::getNumFacesRep(bool curved)
{
  return curved ? 12 * std::pow(CTX::instance()->mesh.numSubEdges, 2) :
                  MHexahedron::getNumFacesRep(curved);
}

void _getIndicesReversedHex(int order, IndicesReversed &indices)
{
  fullMatrix<double> ref = gmshGenerateMonomialsHexahedron(order);

  indices.resize(ref.size1());
  for(int i = 0; i < ref.size1(); ++i) {
    const double u = ref(i, 0);
    const double v = ref(i, 1);
    const double w = ref(i, 2);
    for(int j = 0; j < ref.size1(); ++j) {
      if(u == ref(j, 1) && v == ref(j, 0) && w == ref(j, 2)) {
        indices[i] = j;
        break;
      }
    }
  }
}

void MHexahedronN::reverse()
{
  auto it = _order2indicesReversedHex.find(_order);
  if(it == _order2indicesReversedHex.end()) {
    IndicesReversed indices;
    _getIndicesReversedHex(_order, indices);
    _order2indicesReversedHex[_order] = indices;
    it = _order2indicesReversedHex.find(_order);
  }

  IndicesReversed &indices = it->second;

  // copy vertices
  std::vector<MVertex *> oldv(8 + _vs.size());
  std::copy(_v, _v + 8, oldv.begin());
  std::copy(_vs.begin(), _vs.end(), oldv.begin() + 8);

  // reverse
  for(int i = 0; i < 8; ++i) { _v[i] = oldv[indices[i]]; }
  for(std::size_t i = 0; i < _vs.size(); ++i) { _vs[i] = oldv[indices[8 + i]]; }
}

// void _getIndicesHighOrderFace(int order, int numFace, int sign, int rot,
//                              IndicesHighOrderFace &indices)
//{
//  fullMatrix<double> ref = gmshGenerateMonomialsHexahedron(order);
//
// faceClosure ???
//
//  indices.resize(ref.size1());
//  for (int i = 0; i < ref.size1(); ++i) {
//    const double u = ref(i, 0);
//    const double v = ref(i, 1);
//    const double w = ref(i, 2);
//    for (int j = 0; j < ref.size1(); ++j) {
//      if (u == ref(j, 1) && v == ref(j, 0) && w == ref(j, 2)) {
//        indices[i] = j;
//        break;
//      }
//    }
//  }
//}
