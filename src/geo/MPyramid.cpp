// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MPyramid.h"
#include "Numeric.h"
#include "Context.h"
#include "BergotBasis.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"

std::map<int, IndicesReversed> MPyramidN::_order2indicesReversedPyr;

int MPyramid::getVolumeSign()
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

void MPyramid::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQPyrPts(pOrder);
  *pts = getGQPyrPts(pOrder);
}

bool MPyramid::getFaceInfo(const MFace &face, int &ithFace, int &sign,
                           int &rot) const
{
  for(ithFace = 0; ithFace < 5; ++ithFace) {
    if(_getFaceInfo(getFace(ithFace), face, sign, rot)) return true;
  }
  Msg::Error("Could not get face information for pyramid %d", getNum());
  return false;
}

MPyramidN::~MPyramidN() {}

int MPyramidN::getNumEdgesRep(bool curved)
{
  // FIXME: remove !getIsAssimilatedSerendipity() when serendip are implemented
  return (curved && !getIsAssimilatedSerendipity()) ?
           8 * CTX::instance()->mesh.numSubEdges :
           8;
}

void MPyramidN::getEdgeRep(bool curved, int num, double *x, double *y,
                           double *z, SVector3 *n)
{
  // FIXME: remove !getIsAssimilatedSerendipity() when serendip are implemented
  if(curved && !getIsAssimilatedSerendipity()) {
    int numSubEdges = CTX::instance()->mesh.numSubEdges;
    static double pp[5][3] = {
      {-1, -1, 0}, {1, -1, 0}, {1, 1, 0}, {-1, 1, 0}, {0, 0, 1}};
    static int ed[8][2] = {{0, 1}, {0, 3}, {0, 4}, {1, 2},
                           {1, 4}, {2, 3}, {2, 4}, {3, 4}};
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
    pnt(u1, v1, w1, pnt1);
    pnt(u2, v2, w2, pnt2);
    x[0] = pnt1.x();
    x[1] = pnt2.x();
    y[0] = pnt1.y();
    y[1] = pnt2.y();
    z[0] = pnt1.z();
    z[1] = pnt2.z();

    // not great, but better than nothing
    static const int f[8] = {0, 1, 0, 2, 2, 3, 2, 3};
    n[0] = n[1] = getFace(f[iEdge]).normal();
  }
  else
    MPyramid::getEdgeRep(false, num, x, y, z, n);
}

int MPyramid::getNumFacesRep(bool curved)
{
#if defined(HAVE_VISUDEV)
  if(CTX::instance()->heavyVisu) {
    if(CTX::instance()->mesh.numSubEdges == 1) return 8;
    return 6 * std::pow(CTX::instance()->mesh.numSubEdges, 2);
  }
#endif
  return 6;
}

int MPyramidN::getNumFacesRep(bool curved)
{
  // FIXME: remove !getIsAssimilatedSerendipity() when serendip are implemented
  return (curved && !getIsAssimilatedSerendipity()) ?
           6 * std::pow(CTX::instance()->mesh.numSubEdges, 2) :
           MPyramid::getNumFacesRep(curved);
}

static void _myGetFaceRep(MPyramid *pyr, int num, double *x, double *y,
                          double *z, SVector3 *n, int numSubEdges)
{
  static double pp[5][3] = {
    {-1, -1, 0}, {1, -1, 0}, {1, 1, 0}, {-1, 1, 0}, {0, 0, 1}};
  int iFace = num / (numSubEdges * numSubEdges);
  int iSubFace = num % (numSubEdges * numSubEdges);

  if(iFace > 3) {
    iFace = 4;
    iSubFace = num % (2 * numSubEdges * numSubEdges);
  }

  int iVertex1, iVertex2, iVertex3, iVertex4;

  if(iFace < 4) {
    iVertex1 = pyr->faces_pyramid(iFace, 0);
    iVertex2 = pyr->faces_pyramid(iFace, 1);
    iVertex3 = pyr->faces_pyramid(iFace, 2);
  }
  else {
    iVertex1 = 0;
    iVertex2 = 1;
    iVertex3 = 2;
    iVertex4 = 3;
  }

  SPoint3 pnt1, pnt2, pnt3;

  if(iFace < 4) {
    int ix = 0, iy = 0;
    int nbt = 0;
    for(int i = 0; i < numSubEdges; i++) {
      int nbl = (numSubEdges - i - 1) * 2 + 1;
      nbt += nbl;
      if(nbt > iSubFace) {
        iy = i;
        ix = nbl - (nbt - iSubFace);
        break;
      }
    }

    const double d = 1. / numSubEdges;

    double u1, v1, u2, v2, u3, v3;
    if(ix % 2 == 0) {
      u1 = ix / 2 * d;
      v1 = iy * d;
      u2 = (ix / 2 + 1) * d;
      v2 = iy * d;
      u3 = ix / 2 * d;
      v3 = (iy + 1) * d;
    }
    else {
      u1 = (ix / 2 + 1) * d;
      v1 = iy * d;
      u2 = (ix / 2 + 1) * d;
      v2 = (iy + 1) * d;
      u3 = ix / 2 * d;
      v3 = (iy + 1) * d;
    }

    double U1 = pp[iVertex1][0] * (1. - u1 - v1) + pp[iVertex2][0] * u1 +
                pp[iVertex3][0] * v1;
    double U2 = pp[iVertex1][0] * (1. - u2 - v2) + pp[iVertex2][0] * u2 +
                pp[iVertex3][0] * v2;
    double U3 = pp[iVertex1][0] * (1. - u3 - v3) + pp[iVertex2][0] * u3 +
                pp[iVertex3][0] * v3;

    double V1 = pp[iVertex1][1] * (1. - u1 - v1) + pp[iVertex2][1] * u1 +
                pp[iVertex3][1] * v1;
    double V2 = pp[iVertex1][1] * (1. - u2 - v2) + pp[iVertex2][1] * u2 +
                pp[iVertex3][1] * v2;
    double V3 = pp[iVertex1][1] * (1. - u3 - v3) + pp[iVertex2][1] * u3 +
                pp[iVertex3][1] * v3;

    double W1 = pp[iVertex1][2] * (1. - u1 - v1) + pp[iVertex2][2] * u1 +
                pp[iVertex3][2] * v1;
    double W2 = pp[iVertex1][2] * (1. - u2 - v2) + pp[iVertex2][2] * u2 +
                pp[iVertex3][2] * v2;
    double W3 = pp[iVertex1][2] * (1. - u3 - v3) + pp[iVertex2][2] * u3 +
                pp[iVertex3][2] * v3;

    pyr->pnt(U1, V1, W1, pnt1);
    pyr->pnt(U2, V2, W2, pnt2);
    pyr->pnt(U3, V3, W3, pnt3);
  }
  else {
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

      pyr->pnt(U1, V1, W1, pnt1);
      pyr->pnt(U2, V2, W2, pnt2);
      pyr->pnt(U3, V3, W3, pnt3);
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

      pyr->pnt(U1, V1, W1, pnt1);
      pyr->pnt(U2, V2, W2, pnt2);
      pyr->pnt(U3, V3, W3, pnt3);
    }
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

void MPyramid::getFaceRep(bool curved, int num, double *x, double *y, double *z,
                          SVector3 *n)
{
#if defined(HAVE_VISUDEV)
  static const int fquad[4][4] = {
    {0, 3, 2, 1}, {3, 2, 1, 0}, {2, 1, 0, 3}, {1, 0, 3, 2}};
  if(CTX::instance()->heavyVisu) {
    if(CTX::instance()->mesh.numSubEdges > 1) {
      _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
      return;
    }
    if(num > 3) {
      int i = num - 4;
      _getFaceRepQuad(getVertex(fquad[i][0]), getVertex(fquad[i][1]),
                      getVertex(fquad[i][2]), getVertex(fquad[i][3]), x, y, z,
                      n);
      return;
    }
  }
#endif
  static const int f[6][3] = {{0, 1, 4}, {3, 0, 4}, {1, 2, 4},
                              {2, 3, 4}, {0, 3, 2}, {0, 2, 1}};
  _getFaceRep(getVertex(f[num][0]), getVertex(f[num][1]), getVertex(f[num][2]),
              x, y, z, n);
}

int MPyramid::numCommonNodesInDualGraph(const MElement *const other) const
{
  switch(other->getType()) {
  case TYPE_PNT: return 1;
  case TYPE_LIN: return 2;
  case TYPE_QUA: return 4;
  case TYPE_HEX: return 4;
  default: return 3;
  }
}

void MPyramidN::getFaceRep(bool curved, int num, double *x, double *y,
                           double *z, SVector3 *n)
{
  // FIXME: remove !getIsAssimilatedSerendipity() when serendip are implemented
  if(curved && !getIsAssimilatedSerendipity())
    _myGetFaceRep(this, num, x, y, z, n, CTX::instance()->mesh.numSubEdges);
  else
    MPyramid::getFaceRep(false, num, x, y, z, n);
}

void _getIndicesReversedPyr(int order, IndicesReversed &indices)
{
  fullMatrix<double> ref = gmshGenerateMonomialsPyramid(order);

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

void MPyramidN::reverse()
{
  auto it = _order2indicesReversedPyr.find(_order);
  if(it == _order2indicesReversedPyr.end()) {
    IndicesReversed indices;
    _getIndicesReversedPyr(_order, indices);
    _order2indicesReversedPyr[_order] = indices;
    it = _order2indicesReversedPyr.find(_order);
  }

  IndicesReversed &indices = it->second;

  // copy vertices
  std::vector<MVertex *> oldv(5 + _vs.size());
  std::copy(_v, _v + 5, oldv.begin());
  std::copy(_vs.begin(), _vs.end(), oldv.begin() + 5);

  // reverse
  for(int i = 0; i < 5; ++i) { _v[i] = oldv[indices[i]]; }
  for(std::size_t i = 0; i < _vs.size(); ++i) { _vs[i] = oldv[indices[5 + i]]; }
}

void MPyramidN::_addHOEdgePoints(int num, std::vector<MVertex *> &v,
                                 bool fwd) const
{
  int minVtx = num * (_order - 1);
  int maxVtx = (num + 1) * (_order - 1) - 1;

  if(fwd)
    for(int i = minVtx; i <= maxVtx; i++) v.push_back(_vs[i]);
  else
    for(int i = maxVtx; i >= minVtx; i--) v.push_back(_vs[i]);
}

void MPyramidN::getFaceVertices(const int num, std::vector<MVertex *> &v) const
{
  bool complete = !getIsAssimilatedSerendipity();

  int nbQ = (_order - 1) * (_order - 1);
  int nbT = (_order - 1) * (_order - 2) / 2;

  int nb = ((num == 4) ? 4 : 3) * _order;
  if(complete) nb += (num == 4) ? nbQ : nbT;

  v.reserve(nb);

  if(num < 4) {
    v.push_back(_v[faces_pyramid(num, 0)]);
    v.push_back(_v[faces_pyramid(num, 1)]);
    v.push_back(_v[faces_pyramid(num, 2)]);
  }
  else {
    v.push_back(_v[0]);
    v.push_back(_v[3]);
    v.push_back(_v[2]);
    v.push_back(_v[1]);
  }

  switch(num) {
  case 0: // 0 1 4
  {
    _addHOEdgePoints(0, v);
    _addHOEdgePoints(4, v);
    _addHOEdgePoints(2, v, false);
    break;
  }
  case 1: // 3 0 4
  {
    _addHOEdgePoints(1, v, false);
    _addHOEdgePoints(2, v);
    _addHOEdgePoints(7, v, false);
    break;
  }
  case 2: // 1 2 4
  {
    _addHOEdgePoints(3, v);
    _addHOEdgePoints(6, v);
    _addHOEdgePoints(4, v, false);
    break;
  }
  case 3: // 2 3 4
  {
    _addHOEdgePoints(5, v);
    _addHOEdgePoints(7, v);
    _addHOEdgePoints(6, v, false);
    break;
  }
  case 4: // 0 3 2 1
  {
    _addHOEdgePoints(1, v);
    _addHOEdgePoints(5, v, false);
    _addHOEdgePoints(3, v, false);
    _addHOEdgePoints(0, v, false);
    break;
  }
  }

  if(complete) {
    int start = 8 * (_order - 1) + num * nbT;
    int nbPoints = (num == 4) ? nbQ : nbT;
    for(int i = start; i < start + nbPoints; i++) v.push_back(_vs[i]);
  }
}
