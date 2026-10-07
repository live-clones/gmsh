// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
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
  std::vector<std::vector<double>> f(_numEdgeFunction,
                                     std::vector<double>(3, 1.));
  orientEdgeFunctionsForNegativeFlag(f);
  std::vector<int> signs(_numEdgeFunction);
  for(int i = 0; i < _numEdgeFunction; i++) signs[i] = (f[i][0] < 0) ? -1 : 1;
  return signs;
}

// zero values and copies of scalar and vector basis functions
static void zero(double &v) { v = 0.; }
static void zero(std::vector<double> &v) { v.assign(3, 0.); }
static void copy(double v, double *out) { out[0] = v; }
static void copy(const std::vector<double> &v, double *out)
{
  out[0] = v[0];
  out[1] = v[1];
  out[2] = v[2];
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

template <class T>
void HierarchicalBasis::_evaluate(const std::vector<double> &uvw,
                                  const std::vector<int> &wantedOrientations,
                                  std::vector<double> &values)
{
  const std::size_t numPoints = uvw.size() / 3;
  const std::size_t vSize = _numVertexFunction, eSize = _numEdgeFunction,
                    quadfSize = _numQuadFaceFunction,
                    trifSize = _numTriFaceFunction,
                    fSize = trifSize + quadfSize, bSize = _numBubbleFunction;
  const std::size_t numFunctions = vSize + eSize + fSize + bSize;
  const int nc = getNumComponents();
  const int maxOrientation = getNumberOfOrientations();
  values.resize(
    (wantedOrientations.empty() ? maxOrientation : wantedOrientations.size()) *
    numPoints * numFunctions * nc);

  T z;
  zero(z);
  auto table = [&](std::size_t n) {
    return std::vector<std::vector<T>>(numPoints, std::vector<T>(n, z));
  };
  // the functions in the reference orientation
  std::vector<std::vector<T>> vTable = table(vSize), eTable = table(eSize),
                              fTable = table(fSize), bTable = table(bSize);
  for(std::size_t q = 0; q < numPoints; ++q)
    generateBasis(uvw[3 * q], uvw[3 * q + 1], uvw[3 * q + 2], vTable[q],
                  eTable[q], fTable[q], bTable[q]);
  // the edge functions for the reversed edges, and the face functions for all
  // the orientations of the faces, computed once
  std::vector<std::vector<T>> eTableNegativeFlag(eTable);
  if(eSize)
    for(std::size_t q = 0; q < numPoints; ++q)
      orientEdgeFunctionsForNegativeFlag(eTableNegativeFlag[q]);
  std::vector<std::vector<T>> quadAll = table(quadfSize * 8),
                              triAll = table(trifSize * 6);
  if(fSize)
    for(std::size_t q = 0; q < numPoints; ++q)
      addAllOrientedFaceFunctions(uvw[3 * q], uvw[3 * q + 1], uvw[3 * q + 2],
                                  fTable[q], quadAll[q], triAll[q]);

  // the orientations are the permutations of the vertices of the element, in
  // the order generated by nextPermutation()
  std::vector<MVertex *> vertices(_numVertex);
  for(int i = 0; i < _numVertex; ++i)
    vertices[i] = new MVertex(0., 0., 0., nullptr, i + 1);
  MElement *element = referenceElement(_familyType, vertices);
  std::vector<std::vector<T>> eTableCopy = table(eSize),
                              fTableCopy = table(fSize);
  for(int iOrientation = 0; iOrientation < maxOrientation; ++iOrientation) {
    std::size_t index = iOrientation;
    if(!wantedOrientations.empty()) {
      auto it = std::find(wantedOrientations.begin(), wantedOrientations.end(),
                          iOrientation);
      if(it == wantedOrientations.end()) {
        nextPermutation(vertices, element);
        continue;
      }
      index = it - wantedOrientations.begin();
    }
    if(eSize) {
      for(int iEdge = 0; iEdge < _numEdge; ++iEdge) {
        MEdge edge = element->getEdge(iEdge);
        MEdge edgeSolin = element->getEdgeSolin(iEdge);
        const int flag =
          (edge.getMinVertex() != edgeSolin.getVertex(0) ? -1 : 1);
        for(std::size_t q = 0; q < numPoints; ++q)
          orientEdge(flag, iEdge, eTableCopy[q], eTable[q],
                     eTableNegativeFlag[q]);
      }
    }
    if(fSize) {
      for(int iFace = 0; iFace < _numTriFace + _numQuadFace; ++iFace) {
        MFace face = element->getFaceSolin(iFace);
        std::vector<int> flags(3);
        face.getOrientationFlagForFace(flags);
        for(std::size_t q = 0; q < numPoints; ++q)
          orientFace(flags[0], flags[1], flags[2], iFace, quadAll[q], triAll[q],
                     fTableCopy[q]);
      }
    }
    for(std::size_t q = 0; q < numPoints; ++q) {
      double *out = &values[((index * numPoints) + q) * numFunctions * nc];
      for(std::size_t i = 0; i < vSize; ++i, out += nc) copy(vTable[q][i], out);
      for(std::size_t i = 0; i < eSize; ++i, out += nc)
        copy(eTableCopy[q][i], out);
      for(std::size_t i = 0; i < fSize; ++i, out += nc)
        copy(fTableCopy[q][i], out);
      for(std::size_t i = 0; i < bSize; ++i, out += nc) copy(bTable[q][i], out);
    }
    nextPermutation(vertices, element);
  }
  for(auto v : vertices) delete v;
  delete element;
}

void HierarchicalBasis::evaluate(const std::vector<double> &uvw,
                                 const std::vector<int> &orientations,
                                 std::vector<double> &values)
{
  // H1 values and H(div) divergences are scalars, all the others are vectors
  if(getNumComponents() == 1)
    _evaluate<double>(uvw, orientations, values);
  else
    _evaluate<std::vector<double>>(uvw, orientations, values);
}
