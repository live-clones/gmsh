// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "H1Hexahedron.h"
#include "Blocks.h"

// for each vertex, its three affine coordinates
static const int vertices[8][3] = {{1, 3, 5}, {0, 3, 5}, {0, 2, 5}, {1, 2, 5},
                                   {1, 3, 4}, {0, 3, 4}, {0, 2, 4}, {1, 2, 4}};

H1Hexahedron::H1Hexahedron(int order) : _order(order)
{
  _numVertex = 8;
  _numEdge = 12;
  _numQuadFace = 6;
  _numTriFace = 0;
  _numVertexFunction = 8;
  _numEdgeFunction = 12 * (order - 1);
  _numQuadFaceFunction = 6 * (order - 1) * (order - 1);
  _numTriFaceFunction = 0;
  _numBubbleFunction = (order - 1) * (order - 1) * (order - 1);
}

void H1Hexahedron::functions(const Dual *x, std::vector<Dual> &vertex,
                             std::vector<Dual> &edge, std::vector<Dual> &face,
                             std::vector<Dual> &bubble)
{
  Dual a[6];
  hexahedronCoordinates(x, a);
  for(int i = 0; i < 8; i++)
    vertex[i] = a[vertices[i][0]] * a[vertices[i][1]] * a[vertices[i][2]];
  int n = 0;
  for(int e = 0; e < 12; e++) {
    Dual across = a[hexahedronEdges[e][1]] * a[hexahedronEdges[e][2]];
    for(int k = 2; k <= _order; k++)
      edge[n++] = lobatto(k, x[hexahedronEdges[e][0]]) * across;
  }
  n = 0;
  for(int f = 0; f < 6; f++)
    n += h1Quadrangle(x[hexahedronFaces[f][0]], x[hexahedronFaces[f][1]],
                      a[hexahedronFaces[f][2]], _order, &face[n]);
  n = 0;
  // by increasing max(n1, n2, n3), then increasing n1, n2 and n3
  std::vector<Dual> l[3] = {lobattos(_order, x[0]), lobattos(_order, x[1]),
                            lobattos(_order, x[2])};
  for(int m = 2; m <= _order; m++)
    for(int n1 = 2; n1 <= m; n1++)
      for(int n2 = 2; n2 <= m; n2++)
        for(int n3 = 2; n3 <= m; n3++)
          if(std::max(std::max(n1, n2), n3) == m)
            bubble[n++] = l[0][n1] * l[1][n2] * l[2][n3];
}

void H1Hexahedron::faceFunctions(const Dual *x, int flag1, int flag2, int flag3,
                                 int faceNumber, std::vector<Dual> &face)
{
  Dual a[6], s, t;
  hexahedronCoordinates(x, a);
  const int *f = hexahedronFaces[faceNumber];
  quadrangleCoordinates(x[f[0]], x[f[1]], flag1, flag2, flag3, s, t);
  int perFace = _numQuadFaceFunction / 6;
  h1Quadrangle(s, t, a[f[2]], _order, &face[faceNumber * perFace]);
}

void H1Hexahedron::functionInfo(std::vector<FunctionInfo> &info)
{
  for(int i = 0; i < 8; i++) info.push_back({0, 1, false});
  for(int e = 0; e < 12; e++) h1EdgeInfo(1, _order, info);
  for(int f = 0; f < 6; f++) h1QuadrangleInfo(2, _order, info);
  for(int m = 2; m <= _order; m++)
    for(int k = 0;
        k < (m - 1) * (m - 1) * (m - 1) - (m - 2) * (m - 2) * (m - 2); k++)
      info.push_back({3, m, false});
}
