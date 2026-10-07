// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HcurlTetrahedron.h"
#include "Blocks.h"

HcurlTetrahedron::HcurlTetrahedron(int order) : _order(order)
{
  _numVertex = 4;
  _numEdge = 6;
  _numTriFace = 4;
  _numQuadFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 6 * order + 6;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction =
    order ? 12 * (order - 1) + 4 * (order - 2) * (order - 1) : 0;
  _numBubbleFunction = order ? (order - 1) * (order - 2) * (order - 3) / 2 +
                                 2 * (order - 2) * (order - 1) :
                               0;
}

// the affine coordinates of the vertices
static void coordinates(const Dual *x, Dual *L)
{
  L[0] = 1. - x[0] - x[1] - x[2];
  L[1] = x[0];
  L[2] = x[1];
  L[3] = x[2];
}

void HcurlTetrahedron::functions(const Dual *x, std::vector<Vec> &vertex,
                                 std::vector<Vec> &edge, std::vector<Vec> &face,
                                 std::vector<Vec> &bubble)
{
  Dual L[4];
  coordinates(x, L);
  int n = 0;
  for(int e = 0; e < 6; e++)
    n += hcurlEdge(L[tetrahedronEdges[e][0]], L[tetrahedronEdges[e][1]], _order,
                   &edge[n]);
  n = 0;
  for(int f = 0; f < 4; f++) {
    const int *v = tetrahedronFaces[f];
    n += hcurlTriangle(L[v[0]], L[v[1]], L[v[2]], _order, &face[n]);
  }
  // the face-based bubble functions, along the gradient of the vertex
  // opposite to each face
  n = 0;
  for(int f = 0; f < 4; f++) {
    const int *v = tetrahedronFaces[f];
    const Dual &a = L[v[0]], &b = L[v[1]], &c = L[v[2]];
    Vec dir = grad(L[6 - v[0] - v[1] - v[2]]);
    for(int n1 = 0; n1 <= _order - 3; n1++)
      for(int n2 = 0; n2 <= _order - 3 - n1; n2++)
        bubble[n++] =
          a * b * c * legendre(n1, b - a) * legendre(n2, a - c) * dir;
  }
  // the interior bubble functions, along each coordinate
  Dual all = 2. * L[0] * L[1] * L[2] * L[3];
  for(int i = 0; i < 3; i++) {
    Vec dir = grad(x[i]);
    for(int n1 = 0; n1 <= _order - 4; n1++)
      for(int n2 = 0; n2 <= _order - 4 - n1; n2++)
        for(int n3 = 0; n3 <= _order - 4 - n1 - n2; n3++)
          bubble[n++] = all * kernel(n1, L[2] - L[0]) *
                        kernel(n2, L[1] - L[0]) * kernel(n3, L[3] - L[0]) * dir;
  }
}

void HcurlTetrahedron::faceFunctions(const Dual *x, int flag1, int flag2,
                                     int flag3, int faceNumber,
                                     std::vector<Vec> &face)
{
  Dual L[4];
  coordinates(x, L);
  const int *v = tetrahedronFaces[faceNumber], *r = triangleRoles(flag1, flag2);
  int perFace = _numTriFaceFunction / 4;
  hcurlTriangle(L[v[r[0]]], L[v[r[1]]], L[v[r[2]]], _order,
                &face[faceNumber * perFace]);
}

void HcurlTetrahedron::getKeysInfo(std::vector<int> &functionTypeInfo,
                                   std::vector<int> &orderInfo)
{
  int it = 0;
  for(int e = 0; e < 6; e++)
    for(int k = 0; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int f = 0; f < 4; f++) {
    for(int e = 0; e < 3; e++)
      for(int k = 2; k <= _order; k++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = k;
      }
    for(int g = 0; g < 2; g++)
      for(int n1 = 0; n1 <= _order - 3; n1++)
        for(int n2 = 0; n2 <= _order - 3 - n1; n2++, it++) {
          functionTypeInfo[it] = 2;
          orderInfo[it] = n1 + n2 + 3;
        }
  }
  for(int f = 0; f < 4; f++)
    for(int n1 = 0; n1 <= _order - 3; n1++)
      for(int n2 = 0; n2 <= _order - 3 - n1; n2++, it++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = n1 + n2 + 3;
      }
  for(int i = 0; i < 3; i++)
    for(int n1 = 0; n1 <= _order - 4; n1++)
      for(int n2 = 0; n2 <= _order - 4 - n1; n2++)
        for(int n3 = 0; n3 <= _order - 4 - n1 - n2; n3++, it++) {
          functionTypeInfo[it] = 3;
          orderInfo[it] = n1 + n2 + n3 + 4;
        }
}
