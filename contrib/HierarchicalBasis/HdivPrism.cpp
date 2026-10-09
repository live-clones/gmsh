// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// References: Solin, P., Segeth, K., & Dolezel, I. (2003). Higher-Order Finite
// Element Methods. Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041
// Zaglmayr, S. (2006). High Order Finite Element Methods for Electromagnetic
// Field Computation. PhD thesis, Johannes Kepler University Linz.

#include "HdivPrism.h"
#include "Blocks.h"

// the edges of the triangle under the quadrilateral faces s0, s1, s2
static const int quadEdges[3][2] = {{0, 1}, {0, 2}, {1, 2}};

HdivPrism::HdivPrism(int order) : _order(order), _hcurl(order), _triangle(order)
{
  _numVertex = 6;
  _numEdge = 9;
  _numTriFace = 2;
  _numQuadFace = 3;
  _numVertexFunction = 0;
  _numEdgeFunction = 0;
  _numQuadFaceFunction = 3 * (order + 1) * (order + 1);
  _numTriFaceFunction = (order + 1) * (order + 2);
  _numBubbleFunction =
    order ? (order + 1) * (3 * order * order + 2 * order - 2) / 2 : 0;
}

// the affine coordinates L0, L1, L2 of the triangle, and B and T
static void coordinates(const Dual *x, Dual *L, Dual &B, Dual &T)
{
  L[0] = 1. - x[0] - x[1];
  L[1] = x[0];
  L[2] = x[1];
  B = 0.5 * (1. - x[2]);
  T = 0.5 * (1. + x[2]);
}

// the order of the i-th face function of HdivTriangle (of HcurlTriangle): l
// for the (l - 1)^2 - 1-th to the l^2 - 2-th functions
static int triangleFaceOrder(int i)
{
  int l = 2;
  while(l * l - 1 <= i) l++;
  return l;
}

void HdivPrism::_quadrangle(const Dual *x, int f, int flag1, int flag2,
                            int flag3, const Vec *c, Vec *out)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  // the lowest order function: the H(div) function of the edge (a, b) of the
  // triangle, a grad(b) x grad(w) - b grad(a) x grad(w), times 2 and the signs
  // of the orientation: its normal trace is that of grad(s) x grad(t) on the
  // face of coordinates (s, t), as on the faces of the hexahedron
  int ia = quadEdges[f][0], ib = quadEdges[f][1];
  if(flag1 == -1) std::swap(ia, ib);
  const Dual &a = L[ia], &b = L[ib];
  Vec gw = grad(x[2]);
  double sign = 2. * flag2 * (flag3 == -1 ? -1. : 1.);
  int n = 0, nc = 0;
  out[n++] = sign * (a * cross(grad(b), gw) - b * cross(grad(a), gw));
  for(int l = 1; l <= _order; l++) {
    nc += 2 * l - 1;
    for(int k = 0; k < 2 * l + 1; k++) out[n++] = curlVec(c[nc++]);
  }
}

void HdivPrism::_triangleFace(const Dual *x, int f, const int *r, Vec *out)
{
  Dual L[3], B, T;
  coordinates(x, L, B, T);
  const Dual &blend = (f == 0) ? B : T;
  std::vector<Vec> R((_order + 1) * (_order + 1));
  hcurlTriangleRotational(L[r[0]], L[r[1]], L[r[2]], Dual(1.), _order + 1,
                          R.data());
  int n = 0, nr = 0;
  out[n++] = blend * whitney2(L[r[0]], L[r[1]], L[r[2]]);
  for(int l = 1; l <= _order; l++)
    for(int k = 0; k < l + 1; k++) out[n++] = blend * curlVec(R[nr++]);
}

void HdivPrism::functions(const Dual *x, std::vector<Vec> &vertex,
                          std::vector<Vec> &edge, std::vector<Vec> &face,
                          std::vector<Vec> &bubble)
{
  std::vector<Vec> cv, ce, cf, cb;
  hcurlFunctions(_hcurl, x, cv, ce, cf, cb);
  const int p = _order, perQuad = (p + 1) * (p + 1),
            perCurlQuad = 2 * p * (p + 1), perTri = (p + 1) * (p + 2) / 2;
  for(int f = 0; f < 3; f++)
    _quadrangle(x, f, 1, 1, 1, &cf[f * perCurlQuad], &face[f * perQuad]);
  const int roles[3] = {0, 1, 2};
  for(int f = 0; f < 2; f++)
    _triangleFace(x, f, roles, &face[3 * perQuad + f * perTri]);
  // the interior, the products q of Legendre polynomials being ordered like
  // the H1 functions of a triangle (of orders 3, 4, ...)
  std::vector<Vec> dv, de, df, db;
  hcurlFunctions(_triangle, x, dv, de, df, db);
  std::vector<Dual> q;
  Dual y[2] = {2. * x[0] - 1., 2. * x[1] - 1.};
  for(int d = 0; d <= p; d++)
    for(int j = 0; j <= d; j++)
      q.push_back(legendre(d - j, y[0]) * legendre(j, y[1]));
  Vec gw = grad(x[2]);
  int n = 0;
  for(int l = 1; l <= p; l++) {
    for(std::size_t i = 0; i < df.size(); i++)
      for(int k = 0; k <= p; k++)
        if(std::max(triangleFaceOrder(i), k) == l)
          bubble[n++] = legendre(k, x[2]) * df[i];
    for(std::size_t i = 0; i < q.size(); i++)
      for(int k = 2; k <= p + 1; k++)
        if(std::max(triangleOrder(i) - 3, k - 1) == l)
          bubble[n++] = (q[i] * lobatto(k, x[2])) * gw;
  }
}

void HdivPrism::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                              int faceNumber, std::vector<Vec> &face)
{
  const int p = _order, perQuad = (p + 1) * (p + 1),
            perCurlQuad = 2 * p * (p + 1), perTri = (p + 1) * (p + 2) / 2;
  if(faceNumber < 3) {
    std::vector<Vec> cf;
    hcurlFaceFunctions(_hcurl, x, flag1, flag2, flag3, faceNumber, cf);
    _quadrangle(x, faceNumber, flag1, flag2, flag3,
                &cf[faceNumber * perCurlQuad], &face[faceNumber * perQuad]);
  }
  else
    _triangleFace(x, faceNumber - 3, triangleRoles(flag1, flag2),
                  &face[3 * perQuad + (faceNumber - 3) * perTri]);
}

void HdivPrism::functionInfo(std::vector<FunctionInfo> &info)
{
  const int p = _order;
  for(int f = 0; f < 3; f++) {
    info.push_back({2, 0, false});
    for(int l = 1; l <= p; l++)
      for(int k = 0; k < 2 * l + 1; k++) info.push_back({2, l, false});
  }
  for(int f = 0; f < 2; f++) {
    info.push_back({2, 0, false});
    for(int l = 1; l <= p; l++)
      for(int k = 0; k < l + 1; k++) info.push_back({2, l, false});
  }
  const int nd = p ? (p - 1) * (p + 1) : 0, nq = (p + 1) * (p + 2) / 2;
  for(int l = 1; l <= p; l++) {
    for(int i = 0; i < nd; i++)
      for(int k = 0; k <= p; k++)
        if(std::max(triangleFaceOrder(i), k) == l)
          info.push_back({3, l, false});
    for(int i = 0; i < nq; i++)
      for(int k = 2; k <= p + 1; k++)
        if(std::max(triangleOrder(i) - 3, k - 1) == l)
          info.push_back({3, l, false});
  }
}
