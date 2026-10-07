// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <array>
#include <type_traits>
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
#include "Point/HierarchicalBasisH1Point.h"
#include "Line/HierarchicalBasisH1Line.h"
#include "Line/HierarchicalBasisHcurlLine.h"
#include "Triangle/HierarchicalBasisH1Tria.h"
#include "Triangle/HierarchicalBasisHcurlTria.h"
#include "Triangle/HierarchicalBasisHdivTria.h"
#include "Quadrilateral/HierarchicalBasisH1Quad.h"
#include "Quadrilateral/HierarchicalBasisHcurlQuad.h"
#include "Tetrahedron/HierarchicalBasisH1Tetra.h"
#include "Tetrahedron/HierarchicalBasisHcurlTetra.h"
#include "Hexahedron/HierarchicalBasisH1Brick.h"
#include "Hexahedron/HierarchicalBasisHcurlBrick.h"
#include "Prism/HierarchicalBasisH1Pri.h"
#include "Prism/HierarchicalBasisHcurlPri.h"

HierarchicalBasis *HierarchicalBasis::create(const std::string &fsName,
                                             int familyType, int order)
{
  Space space;
  if(fsName == "H1Legendre")
    space = H1;
  else if(fsName == "GradH1Legendre")
    space = GRAD_H1;
  else if(fsName == "HcurlLegendre")
    space = HCURL;
  else if(fsName == "CurlHcurlLegendre")
    space = CURL_HCURL;
  else if(fsName == "HdivLegendre")
    space = HDIV;
  else if(fsName == "DivHdivLegendre")
    space = DIV_HDIV;
  else {
    Msg::Error("Unknown function space named '%s'", fsName.c_str());
    return nullptr;
  }

  // the Lobatto and Legendre polynomials are tabulated up to orders 15 and 10
  bool h1 = (space == H1 || space == GRAD_H1);
  int minOrder = h1 ? 1 : 0, maxOrder = h1 ? 15 : 10;
  if(order < minOrder || order > maxOrder) {
    Msg::Error("Order %d of function space '%s' is not available (%d to %d)",
               order, fsName.c_str(), minOrder, maxOrder);
    return nullptr;
  }

  HierarchicalBasis *basis = nullptr;
  if(h1) {
    switch(familyType) {
    case TYPE_PNT: basis = new HierarchicalBasisH1Point(); break;
    case TYPE_LIN: basis = new HierarchicalBasisH1Line(order); break;
    case TYPE_TRI: basis = new HierarchicalBasisH1Tria(order); break;
    case TYPE_QUA: basis = new HierarchicalBasisH1Quad(order); break;
    case TYPE_TET: basis = new HierarchicalBasisH1Tetra(order); break;
    case TYPE_PRI: basis = new HierarchicalBasisH1Pri(order); break;
    case TYPE_HEX: basis = new HierarchicalBasisH1Brick(order); break;
    }
  }
  else if(space == HCURL || space == CURL_HCURL) {
    switch(familyType) {
    case TYPE_LIN: basis = new HierarchicalBasisHcurlLine(order); break;
    case TYPE_TRI: basis = new HierarchicalBasisHcurlTria(order); break;
    case TYPE_QUA: basis = new HierarchicalBasisHcurlQuad(order); break;
    case TYPE_TET: basis = new HierarchicalBasisHcurlTetra(order); break;
    case TYPE_PRI: basis = new HierarchicalBasisHcurlPri(order); break;
    case TYPE_HEX: basis = new HierarchicalBasisHcurlBrick(order); break;
    }
  }
  else {
    switch(familyType) {
    case TYPE_TRI: basis = new HierarchicalBasisHdivTria(order); break;
    }
  }
  if(!basis) {
    Msg::Error("Unknown familyType %i for basis function type %s", familyType,
               fsName.c_str());
    return nullptr;
  }
  basis->_space = space;
  basis->_familyType = familyType;
  return basis;
}

int HierarchicalBasis::getNumberOfOrientations() const
{
  int n = 1;
  for(int i = 2; i <= _numVertex; i++) n *= i;
  return n;
}

std::vector<int> HierarchicalBasis::getEdgeFunctionSignsForReversedEdges()
{
  // the functions of each edge are ordered by increasing degree, and change
  // sign with the edge when their degree is odd: for H1 (degree k + 2 for the
  // k-th function of the edge) every other function from the second one, for
  // H(curl) and H(div) (degree k) every other function from the first one
  int perEdge = _numEdge ? _numEdgeFunction / _numEdge : 0;
  bool h1 = (_space == H1 || _space == GRAD_H1);
  std::vector<int> signs(_numEdgeFunction);
  for(int i = 0; i < _numEdgeFunction; i++)
    signs[i] = ((i % perEdge) % 2 == (h1 ? 1 : 0)) ? -1 : 1;
  return signs;
}

// the versions of the operations an element does not need do nothing
typedef std::vector<double> S;
typedef std::vector<std::vector<double>> V;
void HierarchicalBasis::generateBasis(double, double, double, S &, S &, S &,
                                      S &)
{
}
void HierarchicalBasis::generateBasis(double, double, double, V &, V &, V &,
                                      V &)
{
}
void HierarchicalBasis::orientOneFace(double, double, double, int, int, int,
                                      int, S &)
{
}
void HierarchicalBasis::orientOneFace(double, double, double, int, int, int,
                                      int, V &)
{
}

// conversions between the scalar and vector functions of the elements and the
// arrays of values
static void zero(double &v) { v = 0.; }
static void zero(std::vector<double> &v) { v.assign(3, 0.); }
static void copy(double v, double *out) { out[0] = v; }
static void copy(const std::vector<double> &v, double *out)
{
  out[0] = v[0];
  out[1] = v[1];
  out[2] = v[2];
}
static void copy(const double *in, double &v) { v = in[0]; }
static void copy(const double *in, std::vector<double> &v)
{
  v[0] = in[0];
  v[1] = in[1];
  v[2] = in[2];
}
template <class T> static void copyAll(const std::vector<T> &v, double *out)
{
  int nc = std::is_same<T, double>::value ? 1 : 3;
  for(std::size_t i = 0; i < v.size(); i++) copy(v[i], out + nc * i);
}

template <class T>
void HierarchicalBasis::_generate(const double *uvw, double *vertex,
                                  double *edge, double *face, double *bubble)
{
  T z;
  zero(z);
  std::vector<T> vt(_numVertexFunction, z), et(_numEdgeFunction, z),
    ft(_numQuadFaceFunction + _numTriFaceFunction, z),
    bt(_numBubbleFunction, z);
  generateBasis(uvw[0], uvw[1], uvw[2], vt, et, ft, bt);
  copyAll(vt, vertex);
  copyAll(et, edge);
  copyAll(ft, face);
  copyAll(bt, bubble);
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

template <class T>
void HierarchicalBasis::_orientFaces(const double *uvw, const double *face,
                                     double *quadFaces, double *triFaces)
{
  const int nc = getNumComponents(), nQ = _numQuadFaceFunction,
            nT = _numTriFaceFunction;
  T z;
  zero(z);
  std::vector<T> oriented(nQ + nT, z);
  // all the quadrilateral faces in the same orientation, then all the
  // triangular faces
  for(int o = 0; o < (nQ ? 8 : 0); o++) {
    for(int r = 0; r < nQ + nT; r++) copy(face + nc * r, oriented[r]);
    std::array<int, 3> f = quadFaceFlags(o);
    for(int i = 0; i < _numQuadFace; i++)
      orientOneFace(uvw[0], uvw[1], uvw[2], f[0], f[1], f[2], i, oriented);
    for(int r = 0; r < nQ; r++)
      copy(oriented[r], quadFaces + nc * (o * nQ + r));
  }
  for(int o = 0; o < (nT ? 6 : 0); o++) {
    for(int r = 0; r < nQ + nT; r++) copy(face + nc * r, oriented[r]);
    std::array<int, 3> f = triFaceFlags(o);
    for(int i = _numQuadFace; i < _numQuadFace + _numTriFace; i++)
      orientOneFace(uvw[0], uvw[1], uvw[2], f[0], f[1], f[2], i, oriented);
    for(int r = 0; r < nT; r++)
      copy(oriented[nQ + r], triFaces + nc * (o * nT + r));
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
  values.resize(
    (wantedOrientations.empty() ? numOrientations : wantedOrientations.size()) *
    std::size_t(nq) * nf * nc);

  // the functions in the reference orientation, by point, function and
  // component; the face functions for all the orientations of the faces
  std::vector<double> vertex(nq * nV * nc), edge(nq * nE * nc),
    face(nq * nF * nc), bubble(nq * nB * nc), quadFaces(nq * 8 * nQ * nc),
    triFaces(nq * 6 * nT * nc);
  bool scalar = (nc == 1);
  for(int q = 0; q < nq; q++) {
    const double *p = &uvw[3 * q];
    double *v = vertex.data() + q * nV * nc, *e = edge.data() + q * nE * nc,
           *f = face.data() + q * nF * nc, *b = bubble.data() + q * nB * nc;
    if(scalar)
      _generate<double>(p, v, e, f, b);
    else
      _generate<std::vector<double>>(p, v, e, f, b);
    if(!nF) continue;
    double *qf = quadFaces.data() + q * 8 * nQ * nc,
           *tf = triFaces.data() + q * 6 * nT * nc;
    if(scalar)
      _orientFaces<double>(p, f, qf, tf);
    else
      _orientFaces<std::vector<double>>(p, f, qf, tf);
  }
  const std::vector<int> signs = getEdgeFunctionSignsForReversedEdges();
  const int perEdge = _numEdge ? nE / _numEdge : 0;
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
      double *out = &values[(index * nq + q) * nf * nc];
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
    }
    nextPermutation(vertices, element);
  }
  for(auto v : vertices) delete v;
  delete element;
}
