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

#include "HdivHexahedron.h"
#include "Blocks.h"

HdivHexahedron::HdivHexahedron(int order) : _order(order), _hcurl(order)
{
  _numVertex = 8;
  _numEdge = 12;
  _numQuadFace = 6;
  _numTriFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 0;
  _numQuadFaceFunction = 6 * (order + 1) * (order + 1);
  _numTriFaceFunction = 0;
  _numBubbleFunction = 3 * order * (order + 1) * (order + 1);
}

// The functions of a face, from the H(curl) functions c of the face: the
// lowest order function w, then by increasing order l the curls of the
// rotational functions of order l, after the 2 l - 1 gradients
static void faceBlock(const Vec &w, const Vec *c, int order, Vec *f)
{
  int n = 0, nc = 0;
  f[n++] = w;
  for(int l = 1; l <= order; l++) {
    nc += 2 * l - 1;
    for(int k = 0; k < 2 * l + 1; k++) f[n++] = curlVec(c[nc++]);
  }
}

void HdivHexahedron::functions(const Dual *x, std::vector<Vec> &vertex,
                               std::vector<Vec> &edge, std::vector<Vec> &face,
                               std::vector<Vec> &bubble)
{
  Dual a[6];
  hexahedronCoordinates(x, a);
  std::vector<Vec> cv, ce, cf, cb;
  hcurlFunctions(_hcurl, x, cv, ce, cf, cb);
  const int perFace = (_order + 1) * (_order + 1),
            perCurlFace = 2 * _order * (_order + 1);
  for(int f = 0; f < 6; f++) {
    const int *h = hexahedronFaces[f];
    Vec w = a[h[2]] * cross(grad(x[h[0]]), grad(x[h[1]]));
    faceBlock(w, &cf[f * perCurlFace], _order, &face[f * perFace]);
  }
  int n = 0, nc = 0;
  for(int l = 1; l <= _order; l++) {
    int m = l + 1,
        layer = (m - 1) * (m - 1) * (m - 1) - (m - 2) * (m - 2) * (m - 2);
    nc += layer;
    for(int k = 0; k < 3 * (2 * m - 3) + 2 * layer; k++)
      bubble[n++] = curlVec(cb[nc++]);
    for(int n1 = 0; n1 <= l; n1++)
      for(int n2 = 0; n2 <= l; n2++)
        for(int n3 = 0; n3 <= l; n3++) {
          if(std::max(std::max(n1, n2), n3) != l) continue;
          int k[3] = {n1, n2, n3}, d = n1 ? 0 : (n2 ? 1 : 2);
          Dual f(1.);
          for(int i = 0; i < 3; i++)
            f = f * (i == d ? lobatto(k[i] + 1, x[i]) : legendre(k[i], x[i]));
          bubble[n++] = f * grad(x[d]);
        }
  }
}

void HdivHexahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                   int flag3, int faceNumber,
                                   std::vector<Vec> &face)
{
  Dual a[6], s, t;
  hexahedronCoordinates(x, a);
  const int *h = hexahedronFaces[faceNumber];
  quadrangleCoordinates(x[h[0]], x[h[1]], flag1, flag2, flag3, s, t);
  std::vector<Vec> cf;
  hcurlFaceFunctions(_hcurl, x, flag1, flag2, flag3, faceNumber, cf);
  const int perFace = (_order + 1) * (_order + 1),
            perCurlFace = 2 * _order * (_order + 1);
  faceBlock(a[h[2]] * cross(grad(s), grad(t)), &cf[faceNumber * perCurlFace],
            _order, &face[faceNumber * perFace]);
}

void HdivHexahedron::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int f = 0; f < 6; f++) {
    info.push_back({2, 0, false});
    for(int l = 1; l <= _order; l++)
      for(int k = 0; k < 2 * l + 1; k++) info.push_back({2, l, true});
  }
  for(int l = 1; l <= _order; l++) {
    for(int k = 0; k < 6 * l * l - 1; k++) info.push_back({3, l, true});
    for(int k = 0; k < 3 * l * l + 3 * l + 1; k++)
      info.push_back({3, l, false});
  }
}
