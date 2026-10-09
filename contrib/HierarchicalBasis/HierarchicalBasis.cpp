// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <array>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "HierarchicalBasis.h"
#include "H1Point.h"
#include "H1Line.h"
#include "HcurlLine.h"
#include "H1Triangle.h"
#include "HcurlTriangle.h"
#include "HdivTriangle.h"
#include "H1Quadrangle.h"
#include "HcurlQuadrangle.h"
#include "HdivQuadrangle.h"
#include "H1Tetrahedron.h"
#include "HcurlTetrahedron.h"
#include "H1Hexahedron.h"
#include "HcurlHexahedron.h"
#include "HdivHexahedron.h"
#include "HdivTetrahedron.h"
#include "HdivPrism.h"
#include "H1Prism.h"
#include "HcurlPrism.h"
#include "L2Element.h"

HierarchicalBasis *HierarchicalBasis::create(const std::string &fsName,
                                             int familyType, int order)
{
  static const struct {
    const char *name;
    Space space;
    Part part;
  } names[] = {{"H1Legendre", H1, ALL},
               {"GradH1Legendre", GRAD_H1, ALL},
               {"HcurlLegendre", HCURL, ALL},
               {"HcurlLegendreGrad", HCURL, KERNEL},
               {"HcurlLegendreNoGrad", HCURL, COMPLEMENT},
               {"CurlHcurlLegendre", CURL_HCURL, ALL},
               {"CurlHcurlLegendreGrad", CURL_HCURL, KERNEL},
               {"CurlHcurlLegendreNoGrad", CURL_HCURL, COMPLEMENT},
               {"HdivLegendre", HDIV, ALL},
               {"HdivLegendreCurl", HDIV, KERNEL},
               {"HdivLegendreNoCurl", HDIV, COMPLEMENT},
               {"DivHdivLegendre", DIV_HDIV, ALL},
               {"DivHdivLegendreCurl", DIV_HDIV, KERNEL},
               {"DivHdivLegendreNoCurl", DIV_HDIV, COMPLEMENT},
               {"L2Legendre", L2, ALL}};
  Space space = H1;
  Part part = ALL;
  bool known = false;
  for(auto &n : names) {
    if(fsName == n.name) {
      space = n.space;
      part = n.part;
      known = true;
    }
  }
  if(!known) {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    return nullptr;
  }

  bool h1 = (space == H1 || space == GRAD_H1);
  int minOrder = h1 ? 1 : 0;
  if(order < minOrder) {
    Msg::Error("Order %d of function space '%s' is not available (minimum %d)",
               order, fsName.c_str(), minOrder);
    return nullptr;
  }

  HierarchicalBasis *basis = nullptr;
  if(h1) {
    switch(familyType) {
    case TYPE_PNT: basis = new H1Point(); break;
    case TYPE_LIN: basis = new H1Line(order); break;
    case TYPE_TRI: basis = new H1Triangle(order); break;
    case TYPE_QUA: basis = new H1Quadrangle(order); break;
    case TYPE_TET: basis = new H1Tetrahedron(order); break;
    case TYPE_PRI: basis = new H1Prism(order); break;
    case TYPE_HEX: basis = new H1Hexahedron(order); break;
    }
  }
  else if(space == HCURL || space == CURL_HCURL) {
    switch(familyType) {
    case TYPE_LIN: basis = new HcurlLine(order); break;
    case TYPE_TRI: basis = new HcurlTriangle(order); break;
    case TYPE_QUA: basis = new HcurlQuadrangle(order); break;
    case TYPE_TET: basis = new HcurlTetrahedron(order); break;
    case TYPE_PRI: basis = new HcurlPrism(order); break;
    case TYPE_HEX: basis = new HcurlHexahedron(order); break;
    }
  }
  else if(space == L2) {
    switch(familyType) {
    case TYPE_LIN:
    case TYPE_TRI:
    case TYPE_QUA:
    case TYPE_TET:
    case TYPE_PRI:
    case TYPE_HEX: basis = new L2Element(familyType, order); break;
    }
  }
  else if(space == HDIV || space == DIV_HDIV) {
    switch(familyType) {
    case TYPE_TRI: basis = new HdivTriangle(order); break;
    case TYPE_QUA: basis = new HdivQuadrangle(order); break;
    case TYPE_TET: basis = new HdivTetrahedron(order); break;
    case TYPE_PRI: basis = new HdivPrism(order); break;
    case TYPE_HEX: basis = new HdivHexahedron(order); break;
    }
  }
  if(!basis) {
    Msg::Error("Unknown familyType %i for basis function type %s", familyType,
               fsName.c_str());
    return nullptr;
  }
  basis->_space = space;
  basis->_part = part;
  basis->_familyType = familyType;
  if(!basis->_select()) {
    Msg::Error("Function space '%s' is not available on elements of family "
               "%i",
               fsName.c_str(), familyType);
    delete basis;
    return nullptr;
  }
  return basis;
}

bool HierarchicalBasis::_select()
{
  const int nf = _numAllFunctions();
  if(_part != ALL && !hasParts()) return false;
  std::vector<FunctionInfo> info;
  functionInfo(info);
  if((int)info.size() != nf) {
    Msg::Error("Wrong number of hierarchical basis functions (%d for %d)",
               (int)info.size(), nf);
    return false;
  }
  // the entity of each function and its position there, from the layout of
  // the functions: one per vertex, then edge by edge, face by face
  // (quadrilateral faces first) and the bubbles
  const int perEdge = _numEdge ? _numEdgeFunction / _numEdge : 0;
  const int perQuad = _numQuadFace ? _numQuadFaceFunction / _numQuadFace : 0;
  const int perTri = _numTriFace ? _numTriFaceFunction / _numTriFace : 0;
  _functions.clear();
  _selected.clear();
  for(int i = 0; i < nf; i++) {
    Function f = {info[i].type, 0, 0, info[i].order};
    int j = i;
    if(j < _numVertexFunction) { f.entity = j; }
    else if((j -= _numVertexFunction) < _numEdgeFunction) {
      f.entity = j / perEdge;
      f.position = j % perEdge;
    }
    else if((j -= _numEdgeFunction) < _numQuadFaceFunction) {
      f.entity = j / perQuad;
      f.position = j % perQuad;
    }
    else if((j -= _numQuadFaceFunction) < _numTriFaceFunction) {
      f.entity = _numQuadFace + j / perTri;
      f.position = j % perTri;
    }
    else
      f.position = j - _numTriFaceFunction;
    if(_part == ALL || info[i].kernel == (_part == KERNEL)) {
      _functions.push_back(f);
      _selected.push_back(i);
    }
  }
  return true;
}

void HierarchicalBasis::getKeysInfo(std::vector<int> &functionTypeInfo,
                                    std::vector<int> &orderInfo) const
{
  functionTypeInfo.resize(_functions.size());
  orderInfo.resize(_functions.size());
  for(std::size_t i = 0; i < _functions.size(); i++) {
    functionTypeInfo[i] = _functions[i].type;
    orderInfo[i] = _functions[i].order;
  }
}

int HierarchicalBasis::getNumberOfOrientations() const
{
  int n = 1;
  for(int i = 2; i <= _numVertex; i++) n *= i;
  return n;
}

int HierarchicalBasis::getEdgeFunctionSignForReversedEdge(int position) const
{
  // the functions of each edge are ordered by increasing degree, and change
  // sign with the edge when their degree is odd: for H1 (degree k + 2 for the
  // k-th function of the edge) every other function from the second one, for
  // H(curl) and H(div) (degree k) every other function from the first one
  if(_space == L2) return 1; // the functions do not depend on orientation
  bool h1 = (_space == H1 || _space == GRAD_H1);
  return (position % 2 == (h1 ? 1 : 0)) ? -1 : 1;
}

// the version of the functions an element does not need does nothing
void HierarchicalBasis::functions(const Dual *, std::vector<Dual> &,
                                  std::vector<Dual> &, std::vector<Dual> &,
                                  std::vector<Dual> &)
{
}
void HierarchicalBasis::functions(const Dual *, std::vector<Vec> &,
                                  std::vector<Vec> &, std::vector<Vec> &,
                                  std::vector<Vec> &)
{
}
void HierarchicalBasis::faceFunctions(const Dual *, int, int, int, int,
                                      std::vector<Dual> &)
{
}
void HierarchicalBasis::faceFunctions(const Dual *, int, int, int, int,
                                      std::vector<Vec> &)
{
}

// the flags of an orientation of a quadrilateral face (0 to 7) or of a
// triangular face (0 to 5), and the reverse:
//
//  quadrilateral faces                 triangular faces
//  flag1   flag2   flag3   index       flag1   flag2   index
//   +1      +1      +1       0           0      +1       0
//   -1      +1      +1       1           1      +1       1
//   +1      -1      +1       2           2      +1       2
//   -1      -1      +1       3           0      -1       3
//   +1      +1      -1       4           1      -1       4
//   -1      +1      -1       5           2      -1       5
//   +1      -1      -1       6
//   -1      -1      -1       7
static std::array<int, 3> quadFaceFlags(int index)
{ return {(index & 1) ? -1 : 1, (index & 2) ? -1 : 1, (index & 4) ? -1 : 1}; }
static std::array<int, 3> triFaceFlags(int index)
{ return {index % 3, (index < 3) ? 1 : -1, 1}; }
static int quadFaceIndex(const std::vector<int> &flags)
{
  return (flags[0] == -1 ? 1 : 0) | (flags[1] == -1 ? 2 : 0) |
         (flags[2] == -1 ? 4 : 0);
}
static int triFaceIndex(const std::vector<int> &flags)
{ return flags[0] + (flags[1] == -1 ? 3 : 0); }

// the value or the derivative of a function, depending on the space
void HierarchicalBasis::_store(const Dual &f, double *out) const
{
  if(_space == H1 || _space == L2) { out[0] = f.v; }
  else {
    for(int i = 0; i < 3; i++) out[i] = f.d[i];
  }
}

void HierarchicalBasis::_store(const Vec &f, double *out) const
{
  if(_space == DIV_HDIV) { out[0] = f.div(); }
  else if(_space == CURL_HCURL) {
    for(int i = 0; i < 3; i++) out[i] = f.curl(i);
  }
  else {
    for(int i = 0; i < 3; i++) out[i] = f.c[i].v;
  }
}

template <class E>
void HierarchicalBasis::_generate(const double *uvw, double *vertex,
                                  double *edge, double *face, double *bubble,
                                  double *quadFaces, double *triFaces)
{
  const int nc = getNumComponents(), nQ = _numQuadFaceFunction,
            nT = _numTriFaceFunction;
  const Dual x[3] = {Dual::coordinate(0, uvw[0]), Dual::coordinate(1, uvw[1]),
                     Dual::coordinate(2, uvw[2])};
  std::vector<E> v(_numVertexFunction), e(_numEdgeFunction), f(nQ + nT),
    b(_numBubbleFunction);
  functions(x, v, e, f, b);
  for(std::size_t i = 0; i < v.size(); i++) _store(v[i], vertex + nc * i);
  for(std::size_t i = 0; i < e.size(); i++) _store(e[i], edge + nc * i);
  for(std::size_t i = 0; i < f.size(); i++) _store(f[i], face + nc * i);
  for(std::size_t i = 0; i < b.size(); i++) _store(b[i], bubble + nc * i);
  // the face functions for all the orientations of the quadrilateral faces,
  // then of the triangular faces
  for(int o = 0; o < (nQ ? 8 : 0); o++) {
    std::vector<E> oriented(f);
    std::array<int, 3> fl = quadFaceFlags(o);
    for(int i = 0; i < _numQuadFace; i++)
      faceFunctions(x, fl[0], fl[1], fl[2], i, oriented);
    for(int r = 0; r < nQ; r++)
      _store(oriented[r], quadFaces + nc * (o * nQ + r));
  }
  for(int o = 0; o < (nT ? 6 : 0); o++) {
    std::vector<E> oriented(f);
    std::array<int, 3> fl = triFaceFlags(o);
    for(int i = _numQuadFace; i < _numQuadFace + _numTriFace; i++)
      faceFunctions(x, fl[0], fl[1], fl[2], i, oriented);
    for(int r = 0; r < nT; r++)
      _store(oriented[nQ + r], triFaces + nc * (o * nT + r));
  }
}

// a reference element of the given family, with vertices tagged 1, 2, ...
static MElement *referenceElement(int familyType,
                                  std::vector<MVertex *> &vertices)
{
  switch(familyType) {
  case TYPE_HEX: return new MHexahedron(vertices);
  case TYPE_PRI: return new MPrism(vertices);
  case TYPE_TET: return new MTetrahedron(vertices);
  case TYPE_QUA: return new MQuadrangle(vertices);
  case TYPE_TRI: return new MTriangle(vertices);
  case TYPE_LIN: return new MLine(vertices);
  case TYPE_PNT: return new MPoint(vertices);
  }
  return nullptr;
}

// give the element the next permutation of its vertices, in the increasing
// order of their tags (e.g. 2 5 8 -> 2 8 5 -> 5 2 8 -> 5 8 2 -> 8 2 5 -> 8 5 2)
static void nextPermutation(std::vector<MVertex *> &vertices, MElement *element)
{
  std::next_permutation(vertices.begin(), vertices.end(), MVertexPtrLessThan());
  for(std::size_t i = 0; i < vertices.size(); ++i)
    element->setVertex(i, vertices[i]);
}

void HierarchicalBasis::evaluate(const std::vector<double> &uvw,
                                 const std::vector<int> &wantedOrientations,
                                 std::vector<double> &values)
{
  const int nq = uvw.size() / 3, nc = getNumComponents();
  const int nV = _numVertexFunction, nE = _numEdgeFunction,
            nQ = _numQuadFaceFunction, nT = _numTriFaceFunction, nF = nQ + nT,
            nB = _numBubbleFunction, nf = nV + nE + nF + nB;
  const int numOrientations = getNumberOfOrientations();
  const int ns = _selected.size();
  values.resize(
    (wantedOrientations.empty() ? numOrientations : wantedOrientations.size()) *
    std::size_t(nq) * ns * nc);

  // the functions in the reference orientation, by point, function and
  // component; the face functions for all the orientations of the faces
  std::vector<double> vertex(nq * nV * nc), edge(nq * nE * nc),
    face(nq * nF * nc), bubble(nq * nB * nc), quadFaces(nq * 8 * nQ * nc),
    triFaces(nq * 6 * nT * nc);
  for(int q = 0; q < nq; q++) {
    const double *p = &uvw[3 * q];
    double *v = vertex.data() + q * nV * nc, *e = edge.data() + q * nE * nc,
           *f = face.data() + q * nF * nc, *b = bubble.data() + q * nB * nc;
    double *qf = quadFaces.data() + q * 8 * nQ * nc,
           *tf = triFaces.data() + q * 6 * nT * nc;
    if(_space == H1 || _space == GRAD_H1 || _space == L2)
      _generate<Dual>(p, v, e, f, b, qf, tf);
    else
      _generate<Vec>(p, v, e, f, b, qf, tf);
  }
  const int perEdge = _numEdge ? nE / _numEdge : 0;
  std::vector<int> signs(nE);
  for(int i = 0; i < nE; i++)
    signs[i] = getEdgeFunctionSignForReversedEdge(i % perEdge);
  std::vector<double> all(nf * nc);
  const int perQuadFace = _numQuadFace ? nQ / _numQuadFace : 0;
  const int perTriFace = _numTriFace ? nT / _numTriFace : 0;

  // the orientations are the permutations of the vertices of the element, in
  // the order generated by nextPermutation()
  std::vector<MVertex *> vertices(_numVertex);
  for(int i = 0; i < _numVertex; ++i)
    vertices[i] = new MVertex(0., 0., 0., nullptr, i + 1);
  MElement *element = referenceElement(_familyType, vertices);
  std::vector<int> edgeFlags(_numEdge), faceIndex(_numQuadFace + _numTriFace);
  for(int o = 0; o < numOrientations; ++o) {
    std::size_t index = o;
    if(!wantedOrientations.empty()) {
      auto it =
        std::find(wantedOrientations.begin(), wantedOrientations.end(), o);
      if(it == wantedOrientations.end()) {
        nextPermutation(vertices, element);
        continue;
      }
      index = it - wantedOrientations.begin();
    }
    // the edges oriented differently from the reference element, and the
    // orientation of each face
    for(int i = 0; i < _numEdge && nE; ++i) {
      MEdge edge = element->getEdge(i);
      MEdge edgeSolin = element->getEdgeSolin(i);
      edgeFlags[i] = (edge.getMinVertex() != edgeSolin.getVertex(0)) ? -1 : 1;
    }
    for(int i = 0; i < _numQuadFace + _numTriFace && nF; ++i) {
      std::vector<int> flags(3);
      element->getFaceSolin(i).getOrientationFlagForFace(flags);
      faceIndex[i] =
        (i < _numQuadFace) ? quadFaceIndex(flags) : triFaceIndex(flags);
    }
    for(int q = 0; q < nq; ++q) {
      double *out = all.data();
      for(int i = 0; i < nV * nc; i++) *out++ = vertex[q * nV * nc + i];
      for(int i = 0; i < nE; i++) {
        const double *e = &edge[(q * nE + i) * nc];
        bool reversed = (edgeFlags[i / perEdge] == -1);
        for(int c = 0; c < nc; c++) *out++ = reversed ? e[c] * signs[i] : e[c];
      }
      for(int i = 0; i < nF; i++) {
        // the i-th face function comes from the table of the orientation of
        // its face
        const double *f;
        if(i < nQ)
          f = &quadFaces[((q * 8 + faceIndex[i / perQuadFace]) * nQ + i) * nc];
        else
          f = &triFaces[((q * 6 +
                          faceIndex[_numQuadFace + (i - nQ) / perTriFace]) *
                           nT +
                         i - nQ) *
                        nc];
        for(int c = 0; c < nc; c++) *out++ = f[c];
      }
      for(int i = 0; i < nB * nc; i++) *out++ = bubble[q * nB * nc + i];
      // the functions of the part of the space
      double *selected = &values[(index * nq + q) * ns * nc];
      for(int i = 0; i < ns; i++)
        for(int c = 0; c < nc; c++)
          selected[i * nc + c] = all[_selected[i] * nc + c];
    }
    nextPermutation(vertices, element);
  }
  for(auto v : vertices) delete v;
  delete element;
}
