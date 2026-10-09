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

#include "HcurlTriangle.h"
#include "Blocks.h"

HcurlTriangle::HcurlTriangle(int order) : _order(order), _h1(order + 1)
{
  _numVertex = 3;
  _numEdge = 3;
  _numTriFace = 1;
  _numQuadFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 3 * order + 3;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction = order ? (order - 1) * (order + 1) : 0;
  _numBubbleFunction = 0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1];
  L[1] = x[0];
  L[2] = x[1];
}

void HcurlTriangle::functions(const Dual *x, std::vector<Vec> &vertex,
                              std::vector<Vec> &edge, std::vector<Vec> &face,
                              std::vector<Vec> &bubble)
{
  Dual L[3];
  coordinates(x, L);
  std::vector<Dual> hv, he, hf, hb;
  h1Functions(_h1, x, hv, he, hf, hb);
  int n = 0;
  for(int e = 0; e < 3; e++)
    n += hcurlEdge(whitney(L[e], L[(e + 1) % 3]), &he[e * _order], _order,
                   &edge[n]);
  hcurlTriangle(L[0], L[1], L[2], Dual(1.), hf.data(), _order, face.data());
}

void HcurlTriangle::faceFunctions(const Dual *x, int flag1, int flag2,
                                  int flag3, int faceNumber,
                                  std::vector<Vec> &face)
{
  Dual L[3];
  coordinates(x, L);
  std::vector<Dual> hf;
  h1FaceFunctions(_h1, x, flag1, flag2, flag3, 0, hf);
  const int *r = triangleRoles(flag1, flag2);
  hcurlTriangle(L[r[0]], L[r[1]], L[r[2]], Dual(1.), hf.data(), _order,
                face.data());
}

void HcurlTriangle::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int e = 0; e < 3; e++) hcurlEdgeInfo(_order, info);
  hcurlTriangleInfo(_order, info);
}
