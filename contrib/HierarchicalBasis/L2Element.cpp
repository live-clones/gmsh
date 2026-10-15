// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "GmshDefines.h"
#include "L2Element.h"

L2Element::L2Element(int familyType, int order)
{
  _familyType = familyType;
  const bool simplex = (familyType == TYPE_LIN || familyType == TYPE_TRI ||
                        familyType == TYPE_TET);
  _dim = (familyType == TYPE_LIN)                           ? 1 :
         (familyType == TYPE_TRI || familyType == TYPE_QUA) ? 2 :
                                                              3;
  _numVertex = (familyType == TYPE_LIN)                           ? 2 :
               (familyType == TYPE_TRI)                           ? 3 :
               (familyType == TYPE_QUA || familyType == TYPE_TET) ? 4 :
               (familyType == TYPE_PRI)                           ? 6 :
                                                                    8;
  // the exponents (n1, n2, n3) by increasing order l, then lexicographically:
  // the total degree on simplices, the largest degree on quadrangles and
  // hexahedra, max(n1 + n2, n3) on prisms
  for(int l = 0; l <= order; l++)
    for(int n1 = 0; n1 <= l; n1++)
      for(int n2 = 0; n2 <= (_dim >= 2 ? l : 0); n2++)
        for(int n3 = 0; n3 <= (_dim == 3 ? l : 0); n3++) {
          int level = (familyType == TYPE_PRI) ? std::max(n1 + n2, n3) :
                      simplex                  ? n1 + n2 + n3 :
                                                 std::max(std::max(n1, n2), n3);
          if(level == l) _indices.push_back({n1, n2, n3, l});
        }
  _numEdge = (_dim == 1) ? 1 : 0;
  _numQuadFace = (familyType == TYPE_QUA) ? 1 : 0;
  _numTriFace = (familyType == TYPE_TRI) ? 1 : 0;
  _numVertexFunction = 0;
  _numEdgeFunction = (_dim == 1) ? _indices.size() : 0;
  _numQuadFaceFunction = _numQuadFace ? _indices.size() : 0;
  _numTriFaceFunction = _numTriFace ? _indices.size() : 0;
  _numBubbleFunction = (_dim == 3) ? _indices.size() : 0;
}

void L2Element::functions(const Dual *x, std::vector<Dual> &vertex,
                          std::vector<Dual> &edge, std::vector<Dual> &face,
                          std::vector<Dual> &bubble)
{
  // the coordinates in [-1, 1]: u, v on the triangles of simplices and prisms,
  // and w on tetrahedra
  Dual y[3] = {x[0], x[1], x[2]};
  if(_familyType == TYPE_TRI || _familyType == TYPE_TET ||
     _familyType == TYPE_PRI)
    for(int i = 0; i < 2; i++) y[i] = 2. * x[i] - 1.;
  if(_familyType == TYPE_TET) y[2] = 2. * x[2] - 1.;
  std::vector<Dual> &out = (_dim == 1) ? edge : (_dim == 2) ? face : bubble;
  for(std::size_t i = 0; i < _indices.size(); i++) {
    Dual f(1.);
    for(int c = 0; c < _dim; c++) f = f * legendre(_indices[i][c], y[c]);
    out[i] = f;
  }
}

void L2Element::functionInfo(std::vector<FunctionInfo> &info)
{
  for(auto &i : _indices) info.push_back({_dim, i[3], false});
}
