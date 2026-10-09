// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "H1Tetrahedron.h"
#include "Blocks.h"

H1Tetrahedron::H1Tetrahedron(int order) : _order(order)
{
  _numVertex = 4;
  _numEdge = 6;
  _numTriFace = 4;
  _numQuadFace = 0;
  _numVertexFunction = 4;
  _numEdgeFunction = 6 * order - 6;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction = (order >= 3) ? 2 * (order - 2) * (order - 1) : 0;
  _numBubbleFunction =
    (order >= 4) ? (order - 1) * (order - 2) * (order - 3) / 6 : 0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1] - x[2];
  L[1] = x[0];
  L[2] = x[1];
  L[3] = x[2];
}

void H1Tetrahedron::functions(const Dual *x, std::vector<Dual> &vertex,
                              std::vector<Dual> &edge, std::vector<Dual> &face,
                              std::vector<Dual> &bubble)
{
  Dual L[4];
  coordinates(x, L);
  for(int i = 0; i < 4; i++) vertex[i] = L[i];
  int n = 0;
  for(int e = 0; e < 6; e++)
    n += h1Edge(L[tetrahedronEdges[e][0]], L[tetrahedronEdges[e][1]], _order,
                &edge[n]);
  n = 0;
  for(int f = 0; f < 4; f++)
    n += h1Triangle(L[tetrahedronFaces[f][0]], L[tetrahedronFaces[f][1]],
                    L[tetrahedronFaces[f][2]], Dual(1.), _order, &face[n]);
  Dual all = L[0] * L[1] * L[2] * L[3];
  n = 0;
  // by increasing n1 + n2 + n3, then increasing n1 and n2
  for(int d = 0; d <= _order - 4; d++)
    for(int n1 = 0; n1 <= d; n1++)
      for(int n2 = 0; n2 <= d - n1; n2++)
        bubble[n++] = all * kernel(n1, L[2] - L[0]) * kernel(n2, L[1] - L[0]) *
                      kernel(d - n1 - n2, L[3] - L[0]);
}

void H1Tetrahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                  int flag3, int faceNumber,
                                  std::vector<Dual> &face)
{
  Dual L[4];
  coordinates(x, L);
  const int *f = tetrahedronFaces[faceNumber], *r = triangleRoles(flag1, flag2);
  int perFace = _numTriFaceFunction / 4;
  h1Triangle(L[f[r[0]]], L[f[r[1]]], L[f[r[2]]], Dual(1.), _order,
             &face[faceNumber * perFace]);
}

void H1Tetrahedron::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int i = 0; i < 4; i++) info.push_back({0, 1, false});
  for(int e = 0; e < 6; e++) h1EdgeInfo(1, _order, info);
  for(int f = 0; f < 4; f++) h1TriangleInfo(2, _order, info);
  for(int d = 0; d <= _order - 4; d++)
    for(int k = 0; k < (d + 1) * (d + 2) / 2; k++)
      info.push_back({3, d + 4, false});
}
