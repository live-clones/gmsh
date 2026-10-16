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

#include "HcurlHexahedron.h"
#include "Blocks.h"

HcurlHexahedron::HcurlHexahedron(int order) : _order(order), _h1(order + 1)
{
  _numVertex = 8;
  _numEdge = 12;
  _numQuadFace = 6;
  _numTriFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 12 * order + 12;
  _numQuadFaceFunction = 12 * order * (order + 1);
  _numTriFaceFunction = 0;
  _numBubbleFunction = 3 * order * order * (order + 1);
}

// The rotational bubble functions of order l, with m = l + 1 and the Lobatto
// polynomials l_k: l_j(v) l_k(w) grad(u), l_i(u) l_k(w) grad(v) and l_i(u)
// l_j(v) grad(w), the pairs of indices in [2, m]^2 with max = m; then, with A
// = l_i(u), B = l_j(v), C = l_k(w), grad(A) B C - A grad(B) C + A B grad(C),
// then grad(A) B C + A grad(B) C - A B grad(C), (i, j, k) in [2, m]^3 with
// max(i, j, k) = m; the indices by increasing order
static int rotationalBubbles(const Dual *x, const std::vector<Dual> *lob, int l,
                             Vec *f)
{
  const int m = l + 1;
  int n = 0;
  for(int d = 0; d < 3; d++) {
    int p = (d + 1) % 3, q = (d + 2) % 3;
    if(p > q) std::swap(p, q);
    for(int j = 2; j <= m; j++)
      for(int k = 2; k <= m; k++)
        if(std::max(j, k) == m) f[n++] = lob[p][j] * lob[q][k] * grad(x[d]);
  }
  for(int type = 0; type < 2; type++)
    for(int i = 2; i <= m; i++)
      for(int j = 2; j <= m; j++)
        for(int k = 2; k <= m; k++)
          if(std::max(std::max(i, j), k) == m) {
            const Dual &A = lob[0][i], &B = lob[1][j], &C = lob[2][k];
            double s = (type == 0) ? -1. : 1.;
            f[n++] =
              (B * C) * grad(A) + s * (A * C) * grad(B) - s * (A * B) * grad(C);
          }
  return n;
}

void HcurlHexahedron::functions(const Dual *x, std::vector<Vec> &vertex,
                                std::vector<Vec> &edge, std::vector<Vec> &face,
                                std::vector<Vec> &bubble)
{
  Dual a[6];
  hexahedronCoordinates(x, a);
  std::vector<Dual> hv, he, hf, hb;
  h1Functions(_h1, x, hv, he, hf, hb);
  int n = 0;
  for(int e = 0; e < 12; e++) {
    const int *h = hexahedronEdges[e];
    n += hcurlEdge(a[h[1]] * a[h[2]] * grad(x[h[0]]), &he[e * _order], _order,
                   &edge[n]);
  }
  n = 0;
  for(int f = 0; f < 6; f++) {
    const int *h = hexahedronFaces[f];
    n += hcurlQuadrangle(x[h[0]], x[h[1]], a[h[2]], &hf[f * _order * _order],
                         _order, &face[n]);
  }
  std::vector<Dual> lob[3] = {lobattos(_order + 1, x[0]),
                              lobattos(_order + 1, x[1]),
                              lobattos(_order + 1, x[2])};
  n = 0;
  for(int l = 1; l <= _order; l++) {
    for(int k = (l - 1) * (l - 1) * (l - 1); k < l * l * l; k++)
      bubble[n++] = grad(hb[k]);
    n += rotationalBubbles(x, lob, l, &bubble[n]);
  }
}

void HcurlHexahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                    int flag3, int faceNumber,
                                    std::vector<Vec> &face)
{
  Dual a[6], s, t;
  hexahedronCoordinates(x, a);
  const int *h = hexahedronFaces[faceNumber];
  quadrangleCoordinates(x[h[0]], x[h[1]], flag1, flag2, flag3, s, t);
  std::vector<Dual> hf;
  h1FaceFunctions(_h1, x, flag1, flag2, flag3, faceNumber, hf);
  int perFace = _numQuadFaceFunction / 6;
  hcurlQuadrangle(s, t, a[h[2]], &hf[faceNumber * _order * _order], _order,
                  &face[faceNumber * perFace]);
}

void HcurlHexahedron::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int e = 0; e < 12; e++) hcurlEdgeInfo(_order, info);
  for(int f = 0; f < 6; f++) hcurlQuadrangleInfo(_order, info);
  for(int l = 1; l <= _order; l++) {
    int m = l + 1,
        layer = (m - 1) * (m - 1) * (m - 1) - (m - 2) * (m - 2) * (m - 2);
    for(int k = 0; k < layer; k++) info.push_back({3, l, true});
    for(int k = 0; k < 3 * (2 * m - 3) + 2 * layer; k++)
      info.push_back({3, l, false});
  }
}
