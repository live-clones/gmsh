// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "H1Quadrangle.h"

H1Quadrangle::H1Quadrangle(int order) : _order(order)
{
  _dual = true;
  _numVertex = 4;
  _numEdge = 4;
  _numQuadFace = 1;
  _numTriFace = 0;
  _numVertexFunction = 4;
  _numEdgeFunction = 4 * order - 4;
  _numQuadFaceFunction = (order - 1) * (order - 1);
  _numTriFaceFunction = 0;
  _numBubbleFunction = 0;
}

void H1Quadrangle::functions(const Dual *x, std::vector<Dual> &vertex,
                             std::vector<Dual> &edge, std::vector<Dual> &face,
                             std::vector<Dual> &bubble)
{
  const Dual &u = x[0], &v = x[1];
  Dual a1 = 0.5 * (1. + u), a2 = 0.5 * (1. - u), a3 = 0.5 * (1. + v),
       a4 = 0.5 * (1. - v);
  vertex[0] = a2 * a4;
  vertex[1] = a1 * a4;
  vertex[2] = a1 * a3;
  vertex[3] = a2 * a3;
  // each edge: the coordinate along it, and the blending across it
  const Dual *along[4] = {&u, &v, &u, &v}, *across[4] = {&a4, &a1, &a3, &a2};
  int n = 0;
  for(int e = 0; e < 4; e++)
    for(int k = 2; k <= _order; k++)
      edge[n++] = *across[e] * lobatto(k, *along[e]);
  _faceFunctions(u, v, face);
}

void H1Quadrangle::_faceFunctions(const Dual &s, const Dual &t,
                                  std::vector<Dual> &face)
{
  int n = 0;
  for(int n1 = 2; n1 <= _order; n1++) {
    Dual l1 = lobatto(n1, s);
    for(int n2 = 2; n2 <= _order; n2++) face[n++] = l1 * lobatto(n2, t);
  }
}

void H1Quadrangle::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                                 int faceNumber, std::vector<Dual> &face)
{
  // flag1 and flag2 reverse u and v, flag3 = -1 exchanges them
  Dual s = flag1 * x[0], t = flag2 * x[1];
  if(flag3 == 1)
    _faceFunctions(s, t, face);
  else
    _faceFunctions(t, s, face);
}

void H1Quadrangle::getKeysInfo(std::vector<int> &functionTypeInfo,
                               std::vector<int> &orderInfo)
{
  int it = 0;
  for(int i = 0; i < 4; i++, it++) {
    functionTypeInfo[it] = 0;
    orderInfo[it] = 1;
  }
  for(int e = 0; e < 4; e++)
    for(int k = 2; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int n1 = 2; n1 <= _order; n1++)
    for(int n2 = 2; n2 <= _order; n2++, it++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = std::max(n1, n2);
    }
}
