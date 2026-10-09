// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia (2019) and Nawfel BENATIA (2025).

// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include "HcurlHexahedron.h"
#include "Blocks.h"

HcurlHexahedron::HcurlHexahedron(int order) : _order(order)
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

// the degrees of the Legendre polynomial (0 to the order) of the coordinate d
// along a bubble function, and of the Lobatto polynomials (2 to the order + 1)
// of the two other coordinates
static void bubbleRange(int d, int order, int *lo, int *hi)
{
  for(int i = 0; i < 3; i++) {
    lo[i] = (i == d) ? 0 : 2;
    hi[i] = (i == d) ? order : order + 1;
  }
}

void HcurlHexahedron::functions(const Dual *x, std::vector<Vec> &vertex,
                                std::vector<Vec> &edge, std::vector<Vec> &face,
                                std::vector<Vec> &bubble)
{
  Dual a[6];
  hexahedronCoordinates(x, a);
  int n = 0;
  for(int e = 0; e < 12; e++) {
    const int *h = hexahedronEdges[e];
    n += hcurlTensorEdge(x[h[0]], a[h[1]] * a[h[2]], _order, &edge[n]);
  }
  n = 0;
  for(int f = 0; f < 6; f++) {
    const int *h = hexahedronFaces[f];
    n += hcurlQuadrangle(x[h[0]], x[h[1]], a[h[2]], _order, &face[n]);
  }
  // the bubble functions along e_u, e_v and e_w: the Legendre polynomial of
  // the coordinate along the function, the Lobatto polynomials of the others
  n = 0;
  for(int d = 0; d < 3; d++) {
    int lo[3], hi[3];
    bubbleRange(d, _order, lo, hi);
    for(int n1 = lo[0]; n1 <= hi[0]; n1++)
      for(int n2 = lo[1]; n2 <= hi[1]; n2++)
        for(int n3 = lo[2]; n3 <= hi[2]; n3++) {
          int k[3] = {n1, n2, n3};
          Dual f(1.);
          for(int i = 0; i < 3; i++)
            f = f * (i == d ? legendre(k[i], x[i]) : lobatto(k[i], x[i]));
          bubble[n++] = f * grad(x[d]);
        }
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
  int perFace = _numQuadFaceFunction / 6;
  hcurlQuadrangle(s, t, a[h[2]], _order, &face[faceNumber * perFace]);
}

void HcurlHexahedron::keysInfo(std::vector<int> &functionTypeInfo,
                               std::vector<int> &orderInfo)
{
  int it = 0;
  for(int e = 0; e < 12; e++)
    for(int k = 0; k <= _order; k++, it++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = k;
    }
  for(int f = 0; f < 6; f++) {
    for(int n1 = 0; n1 <= _order; n1++)
      for(int n2 = 2; n2 <= _order + 1; n2++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(n1, n2);
      }
    for(int n1 = 2; n1 <= _order + 1; n1++)
      for(int n2 = 0; n2 <= _order; n2++, it++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(n1, n2);
      }
  }
  for(int d = 0; d < 3; d++) {
    int lo[3], hi[3];
    bubbleRange(d, _order, lo, hi);
    for(int n1 = lo[0]; n1 <= hi[0]; n1++)
      for(int n2 = lo[1]; n2 <= hi[1]; n2++)
        for(int n3 = lo[2]; n3 <= hi[2]; n3++, it++) {
          functionTypeInfo[it] = 3;
          orderInfo[it] = std::max(std::max(n1, n2), n3);
        }
  }
}
