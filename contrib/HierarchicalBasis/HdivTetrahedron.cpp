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

#include "HdivTetrahedron.h"
#include "Blocks.h"

HdivTetrahedron::HdivTetrahedron(int order) : _order(order), _hcurl(order + 1)
{
  _numVertex = 4;
  _numEdge = 6;
  _numTriFace = 4;
  _numQuadFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 0;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction = 2 * (order + 1) * (order + 2);
  _numBubbleFunction = order ? (order + 1) * (order + 2) * (order - 1) / 2 : 0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1] - x[2];
  L[1] = x[0];
  L[2] = x[1];
  L[3] = x[2];
}

// The functions of a face, from the H(curl) functions c of the face (of order
// order + 1): the Whitney 2-form w, then by increasing order l the curls of the
// l + 1 rotational H(curl) functions of order l + 1, after the l gradients
static void faceBlock(const Vec &w, const Vec *c, int order, Vec *f)
{
  int n = 0, nc = 0;
  f[n++] = w;
  for(int l = 1; l <= order; l++) {
    nc += l;
    for(int k = 0; k < l + 1; k++) f[n++] = curlVec(c[nc++]);
  }
}

void HdivTetrahedron::functions(const Dual *x, std::vector<Vec> &vertex,
                                std::vector<Vec> &edge, std::vector<Vec> &face,
                                std::vector<Vec> &bubble)
{
  Dual L[4];
  coordinates(x, L);
  std::vector<Vec> cv, ce, cf, cb;
  hcurlFunctions(_hcurl, x, cv, ce, cf, cb);
  const int perFace = (_order + 1) * (_order + 2) / 2,
            perCurlFace = _order * (_order + 2);
  for(int f = 0; f < 4; f++) {
    const int *v = tetrahedronFaces[f];
    faceBlock(whitney2(L[v[0]], L[v[1]], L[v[2]]), &cf[f * perCurlFace], _order,
              &face[f * perFace]);
  }
  // the Whitney 2-forms of the faces opposite to L0, L1 and L2
  Vec opposite[3];
  for(int i = 0; i < 3; i++) {
    const int *v = tetrahedronFaces[3 - i];
    opposite[i] = whitney2(L[v[0]], L[v[1]], L[v[2]]);
  }
  int n = 0, nc = 0;
  for(int l = 2; l <= _order; l++) {
    // the H(curl) bubbles of order l + 1: the gradients, then the rotational
    // functions
    nc += (l - 1) * l / 2;
    for(int k = 0; k < (l - 1) * (l + 1); k++) bubble[n++] = curlVec(cb[nc++]);
    for(int i = l - 1; i >= 0; i--)
      for(int j = l - 1 - i; j >= 0; j--) {
        int k = l - 1 - i - j, d = i ? 0 : (j ? 1 : 2);
        Dual p = Dual(1.);
        for(int e = 0; e < i; e++) p = p * L[0];
        for(int e = 0; e < j; e++) p = p * L[1];
        for(int e = 0; e < k; e++) p = p * L[2];
        bubble[n++] = p * opposite[d];
      }
  }
}

void HdivTetrahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                    int flag3, int faceNumber,
                                    std::vector<Vec> &face)
{
  Dual L[4];
  coordinates(x, L);
  std::vector<Vec> cf;
  hcurlFaceFunctions(_hcurl, x, flag1, flag2, flag3, faceNumber, cf);
  const int *v = tetrahedronFaces[faceNumber], *r = triangleRoles(flag1, flag2);
  const int perFace = (_order + 1) * (_order + 2) / 2,
            perCurlFace = _order * (_order + 2);
  faceBlock(whitney2(L[v[r[0]]], L[v[r[1]]], L[v[r[2]]]),
            &cf[faceNumber * perCurlFace], _order, &face[faceNumber * perFace]);
}

void HdivTetrahedron::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int f = 0; f < 4; f++) {
    info.push_back({2, 0, false});
    for(int l = 1; l <= _order; l++)
      for(int k = 0; k < l + 1; k++) info.push_back({2, l, true});
  }
  for(int l = 2; l <= _order; l++) {
    for(int k = 0; k < (l - 1) * (l + 1); k++) info.push_back({3, l, true});
    for(int k = 0; k < l * (l + 1) / 2; k++) info.push_back({3, l, false});
  }
}
