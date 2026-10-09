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

#include "HcurlQuadrangle.h"
#include "Blocks.h"

HcurlQuadrangle::HcurlQuadrangle(int order) : _order(order), _h1(order + 1)
{
  _numVertex = 4;
  _numEdge = 4;
  _numQuadFace = 1;
  _numTriFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 4 * order + 4;
  _numQuadFaceFunction = 2 * order * (order + 1);
  _numTriFaceFunction = 0;
  _numBubbleFunction = 0;
}

void HcurlQuadrangle::functions(const Dual *x, std::vector<Vec> &vertex,
                                std::vector<Vec> &edge, std::vector<Vec> &face,
                                std::vector<Vec> &bubble)
{
  const Dual &u = x[0], &v = x[1];
  Dual a1 = 0.5 * (1. + u), a2 = 0.5 * (1. - u), a3 = 0.5 * (1. + v),
       a4 = 0.5 * (1. - v);
  std::vector<Dual> hv, he, hf, hb;
  h1Functions(_h1, x, hv, he, hf, hb);
  // each edge: the coordinate along it, and the blending across it
  const Dual *along[4] = {&u, &v, &u, &v}, *across[4] = {&a4, &a1, &a3, &a2};
  int n = 0;
  for(int e = 0; e < 4; e++)
    n += hcurlEdge(*across[e] * grad(*along[e]), &he[e * _order], _order,
                   &edge[n]);
  hcurlQuadrangle(u, v, Dual(1.), hf.data(), _order, face.data());
}

void HcurlQuadrangle::faceFunctions(const Dual *x, int flag1, int flag2,
                                    int flag3, int faceNumber,
                                    std::vector<Vec> &face)
{
  Dual s, t;
  quadrangleCoordinates(x[0], x[1], flag1, flag2, flag3, s, t);
  std::vector<Dual> hf;
  h1FaceFunctions(_h1, x, flag1, flag2, flag3, 0, hf);
  hcurlQuadrangle(s, t, Dual(1.), hf.data(), _order, face.data());
}

void HcurlQuadrangle::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int e = 0; e < 4; e++) hcurlEdgeInfo(_order, info);
  hcurlQuadrangleInfo(_order, info);
}
