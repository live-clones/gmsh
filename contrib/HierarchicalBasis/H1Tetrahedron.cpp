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

static const int edges[6][2] = {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {2, 3}, {1, 3}};
static const int faces[4][3] = {{0, 1, 2}, {0, 1, 3}, {0, 2, 3}, {1, 2, 3}};

H1Tetrahedron::H1Tetrahedron(int order) : _order(order)
{
  _dual = true;
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
    n += h1Edge(L[edges[e][0]], L[edges[e][1]], _order, &edge[n]);
  n = 0;
  for(int f = 0; f < 4; f++)
    n += h1Triangle(L[faces[f][0]], L[faces[f][1]], L[faces[f][2]], Dual(1.),
                    _order, &face[n]);
  Dual all = L[0] * L[1] * L[2] * L[3];
  n = 0;
  for(int n1 = 0; n1 <= _order - 4; n1++)
    for(int n2 = 0; n2 <= _order - 4 - n1; n2++)
      for(int n3 = 0; n3 <= _order - 4 - n1 - n2; n3++)
        bubble[n++] = all * kernel(n1, L[2] - L[0]) * kernel(n2, L[1] - L[0]) *
                      kernel(n3, L[3] - L[0]);
}

void H1Tetrahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                  int flag3, int faceNumber,
                                  std::vector<Dual> &face)
{
  Dual L[4];
  coordinates(x, L);
  const int *f = faces[faceNumber], *r = triangleRoles(flag1, flag2);
  int perFace = _numTriFaceFunction / 4;
  h1Triangle(L[f[r[0]]], L[f[r[1]]], L[f[r[2]]], Dual(1.), _order,
             &face[faceNumber * perFace]);
}

void H1Tetrahedron::getKeysInfo(std::vector<int> &functionTypeInfo,
                                std::vector<int> &orderInfo)
{
  int it = 0;
  for(int i = 0; i < 4; i++, it++) {
    functionTypeInfo[it] = 0;
    orderInfo[it] = 1;
  }
  for(int e = 0; e < 6; e++)
    for(int k = 2; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int f = 0; f < 4; f++)
    for(int n1 = 0; n1 <= _order - 3; n1++)
      for(int n2 = 0; n2 <= _order - 3 - n1; n2++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = n1 + n2 + 3;
      }
  for(int n1 = 0; n1 <= _order - 4; n1++)
    for(int n2 = 0; n2 <= _order - 4 - n1; n2++)
      for(int n3 = 0; n3 <= _order - 4 - n1 - n2; n3++, it++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = n1 + n2 + n3 + 4;
      }
}
