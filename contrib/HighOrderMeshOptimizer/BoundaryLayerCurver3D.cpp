// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Contributors: Amaury Johnen

#include "BoundaryLayerCurver.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "BasisFactory.h"
#include "GFace.h"
#include "bezierBasis.h"

#include "gmshVertex.h"
#include "Geo.h"
#include "MLine.h"
#include "GModel.h"
#if defined(HAVE_POST)
#include "PView.h"
#endif
#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif
#include "Options.h"
#include "AnalyseCurvedMesh.h"
#include "InnerVertexPlacement.h"
#include "qualityMeasuresJacobian.h"

namespace {
  void draw3DFrame(SPoint3 &p, SVector3 &t, SVector3 &n, SVector3 &w,
                   double unitDimension, GFace *gFace)
  {
    // Make sure to have 2 vector that are perpendicular to t assuming n !=
    // alpha * t, forall alpha
    SVector3 a = n;
    SVector3 b = crossprod(t, n).unit();
    a = crossprod(t, b).unit();
    a *= unitDimension;
    b *= unitDimension;

    SPoint3 pnt = p + a;
    MVertex *previous = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    gFace->addMeshVertex(previous);

    const int N = 30;
    for(int j = 1; j <= N; ++j) {
      const double theta = (double)j / N * 2 * M_PI;
      SPoint3 pnt = p + a * std::cos(theta) + b * std::sin(theta);
      MVertex *current = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
      gFace->addMeshVertex(current);
      MLine *line = new MLine(previous, current);
      gFace->edges().front()->addLine(line);
      previous = current;
    }

    MVertex *v = new MVertex(p.x(), p.y(), p.z(), gFace);
    pnt = p + n * unitDimension;
    MVertex *vn = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    pnt = p + w * unitDimension;
    MVertex *vw = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    pnt = p + t * unitDimension;
    MVertex *vt = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    gFace->addMeshVertex(v);
    gFace->addMeshVertex(vn);
    gFace->addMeshVertex(vw);
    MLine *line = new MLine(v, vn);
    gFace->edges().front()->addLine(line);
    line = new MLine(v, vw);
    gFace->edges().front()->addLine(line);
    line = new MLine(v, vt);
    gFace->edges().front()->addLine(line);
  }

  void drawIdealPositionEdge(
    const MElement *bottom1, const MElement *bottom2, const MEdgeN &baseEdge,
    const BoundaryLayerCurver::Parameters3DCurve &parameters, GFace *gFace,
    int triDirection = 0)
  {
    int N = 40;

    MVertex *previous = NULL;

    for(int i = 0; i < N + 1; ++i) {
      const double u = (double)i / N * 2 - 1;
      SPoint3 pnt = baseEdge.pnt(u);
      SVector3 t = baseEdge.tangent(u);

      SVector3 n;
      {
        double xyz[3];
        pnt.position(xyz);

        // TODO: more efficient function? (than xyz2uvw)
        double uvw[3], gradients[3][3];
        bottom1->xyz2uvw(xyz, uvw);
        bottom1->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        n = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
        bottom2->xyz2uvw(xyz, uvw);
        bottom2->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        SVector3 n2 =
          SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

        if(dot(n, n2) < 0) {
          Msg::Warning("Boundary elements have opposite normals (3) %d -- %d",
                       bottom1->getNum(), bottom2->getNum());
          n.negate();
        }
        n.axpy(1, n2);
        n.normalize();
      }

      SVector3 w = crossprod(t, n);

      int &d = triDirection;
      SVector3 h = parameters.thicknessAtPoint(u, d) * n +
                   parameters.coeffbAtPoint(u, d) * t +
                   parameters.coeffcAtPoint(u, d) * w;
      double x = pnt.x() + h.x();
      double y = pnt.y() + h.y();
      double z = pnt.z() + h.z();

      MVertex *current = new MVertex(x, y, z, gFace);
      gFace->addMeshVertex(current);
      if(previous) {
        MLine *line = new MLine(previous, current);
        gFace->edges().front()->addLine(line);
      }
      previous = current;
    }
  }

  void drawNormal(SPoint3 &p, SVector3 &n, double unitDimension, GFace *gFace)
  {
    SPoint3 pnt = p + n * unitDimension;
    MVertex *v = new MVertex(p.x(), p.y(), p.z(), gFace);
    MVertex *vn = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
    gFace->addMeshVertex(v);
    gFace->addMeshVertex(vn);
    MLine *line = new MLine(v, vn);
    gFace->edges().front()->addLine(line);
  }
} // namespace

namespace BoundaryLayerCurver {
  namespace InnerVertPlacementMatrices {
    fullMatrix<double> *_triangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                         NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_quadrangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                           NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_linearTriangle0[10] = {NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_linearTriangle2[10] = {NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_linearQuadrangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                                 NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_hexahedron[10] = {NULL, NULL, NULL, NULL, NULL,
                                           NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_linearHexahedron[3][10] = {
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}};
    fullMatrix<double> *_prism[10] = {NULL, NULL, NULL, NULL, NULL,
                                      NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_linearPrism[4][10] = {
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}};
    fullMatrix<double> *_tetrahedron[10] = {NULL, NULL, NULL, NULL, NULL,
                                            NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double> *_linearTet[6][10] = {
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
      {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}};

    const fullMatrix<double> *triangle(int order, bool linear, int edge)
    {
      if(!linear) {
        if(!_triangle[order]) {
          _triangle[order] = new fullMatrix<double>();
          *_triangle[order] = gmshGenerateInnerVertexPlacementTriangle(order);
        }
        return _triangle[order];
      }
      else if(edge == 0) {
        if(!_linearTriangle0[order]) {
          _linearTriangle0[order] = new fullMatrix<double>();
          *_linearTriangle0[order] =
            gmshGenerateInnerVertexPlacementTriangleLinear(order, 0);
        }
        return _linearTriangle0[order];
      }
      else if(edge == 2) {
        if(!_linearTriangle2[order]) {
          _linearTriangle2[order] = new fullMatrix<double>();
          *_linearTriangle2[order] =
            gmshGenerateInnerVertexPlacementTriangleLinear(order, 2);
        }
        return _linearTriangle2[order];
      }
    }

    const fullMatrix<double> *quadrangle(int order, bool linear)
    {
      if(!linear) {
        if(!_quadrangle[order]) {
          _quadrangle[order] = new fullMatrix<double>();
          *_quadrangle[order] =
            gmshGenerateInnerVertexPlacementQuadrangle(order);
        }
        return _quadrangle[order];
      }
      else {
        if(!_linearQuadrangle[order]) {
          _linearQuadrangle[order] = new fullMatrix<double>();
          *_linearQuadrangle[order] =
            gmshGenerateInnerVertexPlacementQuadrangleLinear(order);
        }
        return _linearQuadrangle[order];
      }
    }

    const fullMatrix<double> *tetrahedron(int order, bool linear, int face,
                                          int otherFace)
    {
      if(!linear) {
        if(!_tetrahedron[order]) {
          _tetrahedron[order] = new fullMatrix<double>();
          *_tetrahedron[order] =
            gmshGenerateInnerVertexPlacementTetrahedron(order);
        }
        return _tetrahedron[order];
      }
      else {
        std::size_t dir;
        const int hash = face * 4 + otherFace;
        switch(hash) {
        case 4 * 0 + 1:
        case 4 * 1 + 0: dir = 4; break;
        case 4 * 0 + 2:
        case 4 * 2 + 0: dir = 5; break;
        default:
        case 4 * 0 + 3:
        case 4 * 3 + 0: dir = 3; break;
        case 4 * 1 + 2:
        case 4 * 2 + 1: dir = 1; break;
        case 4 * 1 + 3:
        case 4 * 3 + 1: dir = 2; break;
        case 4 * 2 + 3:
        case 4 * 3 + 2: dir = 0; break;
        }
        if(!_linearTet[dir][order]) {
          _linearTet[dir][order] = new fullMatrix<double>();
          *_linearTet[dir][order] =
            gmshGenerateInnerVertexPlacementTetrahedronLinear(order, dir);
        }
        return _linearTet[dir][order];
      }
    }

    const fullMatrix<double> *hexahedron(int order, bool linear, int face)
    {
      if(!linear) {
        if(!_hexahedron[order]) {
          _hexahedron[order] = new fullMatrix<double>();
          *_hexahedron[order] =
            gmshGenerateInnerVertexPlacementHexahedron(order);
        }
        return _hexahedron[order];
      }
      else {
        std::size_t dir;
        switch(face) {
        default:
        case 0:
        case 5: dir = 2; break;
        case 1:
        case 4: dir = 1; break;
        case 2:
        case 3: dir = 0; break;
        }
        if(!_linearHexahedron[dir][order]) {
          _linearHexahedron[dir][order] = new fullMatrix<double>();
          *_linearHexahedron[dir][order] =
            gmshGenerateInnerVertexPlacementHexahedronLinear(order, dir);
        }
        return _linearHexahedron[dir][order];
      }
    }

    const fullMatrix<double> *prism(int order, bool linear, int face)
    {
      if(!linear) {
        if(!_prism[order]) {
          _prism[order] = new fullMatrix<double>();
          *_prism[order] = gmshGenerateInnerVertexPlacementPrism(order);
        }
        return _prism[order];
      }
      else {
        std::size_t dir;
        switch(face) {
        default:
        case 0:
        case 1: dir = 3; break;
        case 2: dir = 1; break;
        case 3: dir = 0; break;
        case 4: dir = 0; break;
        }
        if(!_linearPrism[dir][order]) {
          _linearPrism[dir][order] = new fullMatrix<double>();
          *_linearPrism[dir][order] =
            gmshGenerateInnerVertexPlacementPrismLinear(order, dir);
        }
        return _linearPrism[dir][order];
      }
    }
  } // namespace InnerVertPlacementMatrices

  void repositionInteriorNodes(MElement *el,
                               const fullMatrix<double> &placement)
  {
    std::size_t start = el->getNumVertices() - el->getNumVolumeVertices();
    for(std::size_t i = start; i < el->getNumVertices(); ++i) {
      MVertex *v = el->getVertex(i);
      v->x() = 0;
      v->y() = 0;
      v->z() = 0;
      for(int j = 0; j < placement.size2(); ++j) {
        const double coeff = placement(i - start, j);
        MVertex *other = el->getVertex(j);
        v->x() += coeff * other->x();
        v->y() += coeff * other->y();
        v->z() += coeff * other->z();
      }
    }
  }

  void repositionInnerVertices3D(MElement *el)
  {
      const fullMatrix<double> *placement = NULL;
      const int order = el->getPolynomialOrder();
      int nFace, nOtherFace, sign, rot;
      switch(el->getType()) {
      case TYPE_TET:
        placement = InnerVertPlacementMatrices::tetrahedron(order, false);
        break;
      case TYPE_HEX:
        placement = InnerVertPlacementMatrices::hexahedron(order, false);
        break;
      case TYPE_PRI:
        placement = InnerVertPlacementMatrices::prism(order, false);
        break;
      }
      if(placement)
        repositionInteriorNodes(el, *placement);
      else
        Msg::Error("Implement placement for type %d", el->getType());
  }

  // Returns the stack of faces that are shared by two successive elements
  void computeStackHighOrderFaces(const PairMElemVecMElem &column,
                                  std::vector<MFaceN> &stack)
  {
    const std::vector<MElement *> &stackElements = column.second;
    stack.resize(stackElements.size());

    std::vector<MVertex *> allPrimaryVertices;
    computeStackPrimaryVertices(column, allPrimaryVertices);
    // FIXME already calculated in computeInterfaces. Reuse them?

    int nVertexPerLayer = column.first->getNumPrimaryVertices();
    for(std::size_t j = 0; j < stack.size(); ++j) {
      MFace f;
      if(nVertexPerLayer == 3)
        f = MFace(allPrimaryVertices[j * 3 + 0], allPrimaryVertices[j * 3 + 1],
                  allPrimaryVertices[j * 3 + 2]);
      else
        f = MFace(allPrimaryVertices[j * 4 + 0], allPrimaryVertices[j * 4 + 1],
                  allPrimaryVertices[j * 4 + 2], allPrimaryVertices[j * 4 + 3]);
      stack[j] = stackElements[j]->getHighOrderFace(f);
    }
  }

  Column3DBL::Column3DBL(PairMElemVecMElem &col)
  : _stackElements(col.second), _boundaryElement(col.first), _gface(NULL)
  {
    computeStackHighOrderFaces(col, _stackOrientedFaces);
    _externalElement = _stackElements.back();
    _stackElements.pop_back();
    int i = _boundaryElement->getNumVertices();
    while(--i >= 0) {
      GEntity *ent = _boundaryElement->getVertex(i)->onWhat();
      if(ent && ent->dim() == 2) {
        _gface = ent->cast2Face();
        break;
      }
    }
    // FIXME compute _orientationElements
  }

  bool Column3DBL::repositionInnerVertices(std::size_t num) const
  {
    if(_stackElements.size() <= num) return false;
    MElement *el = _stackElements[num];
    MFace bottomFace = _stackOrientedFaces[num].getFace();
    MFace topFace = _stackOrientedFaces[num + 1].getFace();
    const fullMatrix<double> *placement = NULL;
    const int order = el->getPolynomialOrder();
    int nFace, nOtherFace, sign, rot;
    switch(el->getType()) {
    case TYPE_TET:
      el->getFaceInfo(bottomFace, nFace, sign, rot);
      el->getFaceInfo(topFace, nOtherFace, sign, rot);
      placement = InnerVertPlacementMatrices::tetrahedron(order, true, nFace,
                                                          nOtherFace);
      break;
    case TYPE_HEX:
      el->getFaceInfo(bottomFace, nFace, sign, rot);
      placement = InnerVertPlacementMatrices::hexahedron(order, true, nFace);
      break;
    case TYPE_PRI:
      el->getFaceInfo(bottomFace, nFace, sign, rot);
      if(nFace > 1) {
        el->getFaceInfo(topFace, nOtherFace, sign, rot);
        if(nFace != 2 && nOtherFace != 2)
          nFace = 2;
        else if(nFace != 3 && nOtherFace != 3)
          nFace = 3;
        else
          nFace = 4;
      }
      placement = InnerVertPlacementMatrices::prism(order, true, nFace);
      break;
    }
    if(placement)
      repositionInteriorNodes(el, *placement);
    else
      Msg::Error("Implement placement for type %d", el->getType());
  }

  void intersect(const std::vector<MElement *> &v1,
                 const std::vector<MElement *> &v2,
                 std::vector<MElement *> &result)
  {
    result.resize(std::min(v1.size(), v2.size()));
    std::vector<MElement *>::iterator it;
    it = std::set_intersection(v1.begin(), v1.end(), v2.begin(),
                               v2.end(), result.begin());
    result.resize(it - result.begin());
  }

  void merge(const std::vector<MElement *> &v1,
             const std::vector<MElement *> &v2,
             std::vector<MElement *> &result)
  {
    result.resize(std::min(v1.size(), v2.size()));
    std::vector<MElement *>::iterator it;
    it = std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(),
                        result.begin());
    result.resize(it - result.begin());
  }

  void computeFacesTouchingEdges(const std::vector<MElement *> &elements,
                                 const std::vector<MEdge> &edges,
                                 std::vector<MFaceN> &faces)
  {
    for(std::size_t i = 0; i < elements.size(); ++i) {
      for(std::size_t j = 0; j < edges.size(); ++j) {
        // Loop over faces. Add a face if touches the edge and is not already in
        int n = 0;
        for(int k = 0; k < elements[i]->getNumFaces(); ++k) {
          MFace f = elements[i]->getFace(k);
          // loop on edges of face 'f':
          for(std::size_t l = 0; l < f.getNumVertices(); ++l) {
            if(f.getEdge(l) == edges[j]) {
              ++n;
              bool alreadyIn = false;
              for(std::size_t l = 0; l < faces.size(); ++l) {
                if(f == faces[l].getFace()) {
                  alreadyIn = true;
                  break;
                }
              }
              if(!alreadyIn) faces.push_back(elements[i]->getHighOrderFace(f));
              break;
            }
          }
          // Only 2 faces of an element can touch a given edge
          if(n == 2) break;
        }
      }
    }
  }

  // Returns the stack of edges and faces of the interface (i.e. the border
  // of the column) that is above bottomEdge
  void computeStackHOEdgesFaces(const Column3DBL &column,
                                const MEdge &bottomEdge,
                                std::vector<MEdgeN> &stackEdges,
                                std::vector<MFaceN> &stackFaces)
  {
    // stackEdges is the stack of bottom edge of each face in stackFaces. Each
    // edge in stackEdges have the same orientation
    const std::size_t nLayers = column.getNumBLElements();

    // Compute stack of Primary vertices
    std::vector<MVertex *> allPrimaryVertices;
    computeStackPrimaryVerticesNew(column, allPrimaryVertices);

    std::vector<MVertex *> interfacePrimaryVertices;
    {
      int nVertexPerLayer = column.getBoundaryElement()->getNumPrimaryVertices();
      int n0 = -1;
      int n1 = -1;
      for(int i = 0; i < nVertexPerLayer; ++i) {
        if(bottomEdge.getVertex(0) == allPrimaryVertices[i]) n0 = i;
        if(bottomEdge.getVertex(1) == allPrimaryVertices[i]) n1 = i;
      }
      if(n0 == -1 || n1 == -1) {
        Msg::Error("Error in computeStackHOEdgesFaces");
        return;
      }
      interfacePrimaryVertices.resize(2 * nLayers);
      for(std::size_t i = 0; i < nLayers; ++i) {
        MVertex *v0 = allPrimaryVertices[nVertexPerLayer * i + n0];
        MVertex *v1 = allPrimaryVertices[nVertexPerLayer * i + n1];
        interfacePrimaryVertices[2 * i + 0] = v0;
        interfacePrimaryVertices[2 * i + 1] = v1;
      }
    }

    // Compute stack of high order faces
    stackEdges.clear();
    stackFaces.clear();
    MVertex *v0, *v1, *v2, *v3;
    for(std::size_t i = 0; i < nLayers - 1; ++i) {
      v0 = interfacePrimaryVertices[2 * i + 0];
      v1 = interfacePrimaryVertices[2 * i + 1];
      v2 = interfacePrimaryVertices[2 * i + 3];
      v3 = interfacePrimaryVertices[2 * i + 2];

      // Check if triangular face
      if(v2 == v1 && v3 == v0) {
        Msg::Error("Error in computeStackHOEdgesFaces: not an element");
      }
      if(v2 == v1) {
        v2 = v3;
        v3 = NULL;
      }
      else if(v3 == v0) {
        v3 = NULL;
      }

      MElement *el = column.getBLElement(i);
      stackEdges.push_back(el->getHighOrderEdge(MEdge(v0, v1)));
      stackFaces.push_back(el->getHighOrderFace(MFace(v0, v1, v2, v3)));
    }
    MElement *el = column.getBLElement(nLayers - 1);
    stackEdges.push_back(el->getHighOrderEdge(MEdge(v3, v2)));
  }

  Interface3DBL::Interface3DBL(const Column3DBL &col, const MEdge &edge,
                               const MapMEdgeVecMElem &touchedElems)
  : _numFace(col.getNumBLElements()), _col1(&col), _col2(NULL),
    _boundaryElem2(NULL), _gface(NULL), _gedge(NULL)
  {
    computeStackHOEdgesFaces(col, edge, _stackOrientedEdges, _stackOrientedFaces);
    _classifyExternalElements(touchedElems);
    _computeExternalFaces(touchedElems);
    _checkGFaceGEdge();

    _type = _stackOrientedFaces[0].getType();
  }

  Interface3DBL::Interface3DBL(const Column3DBL &col1, const Column3DBL &col2,
                               const MapMEdgeVecMElem &touchedElems)
    : _col1(&col1), _col2(&col1), _boundaryElem2(NULL), _gface(NULL),
      _gedge(NULL)
  {
    MEdge commonEdge;
    {
      MElement *botEl1 = col1.getBoundaryElement();
      MElement *botEl2 = col2.getBoundaryElement();
      if(!computeCommonEdge(botEl1, botEl2, commonEdge)) {
        Msg::Error("Couldn't find common edge on bottom elements");
        return;
      }
    }

    const Column3DBL *col;
    if(col1.getNumBLElements() > col2.getNumBLElements()) col = &col1;
    else col = &col2;
    _numFace = col->getNumBLElements();
    computeStackHOEdgesFaces(*col, commonEdge, _stackOrientedEdges, _stackOrientedFaces);

    _classifyExternalElements(touchedElems);
    _computeExternalFaces(touchedElems);
    _checkGFaceGEdge();
    _checkBoundaryElement(touchedElems);

    _type = _stackOrientedFaces[0].getType();
  }

  void Interface3DBL::_classifyExternalElements(const MapMEdgeVecMElem &map)
  {
    MapMEdgeVecMElem::const_iterator it;
    std::vector<MElement *> &last = _elementsAtLastEdge;
    std::vector<MElement *> &others = _elementsAtInteriorEdges;
    std::vector<MElement *> common;

    MEdge edge = _stackOrientedEdges[_numFace].getEdge();
    it = map.find(edge);
    if(it != map.end()) {
      last = it->second;
    }
    edge = _stackOrientedEdges[_numFace - 1].getEdge();
    it = map.find(edge);
    if(it != map.end()) {
      others = it->second;
    }

    _elementAtLastFace = NULL;
    intersect(last, others, common);
    if(common.size()) {
      _elementAtLastFace = common[0];
      if(common.size() > 1) {
        //FIXMEDEBUG
        Msg::Error("More than 1 common element is not possible");
      }
      for(std::size_t i = 0; i < last.size(); ++i) {
        if(last[i] == _elementAtLastFace) {
          last[i] = last.back();
          last.pop_back();
        }
      }
      for(std::size_t i = 0; i < others.size(); ++i) {
        if(others[i] == _elementAtLastFace) {
          others[i] = others.back();
          others.pop_back();
        }
      }
    }

    for(std::size_t i = 0; i < _numFace - 1; ++i) {
      std::vector<MElement *> tmp;
      it = map.find(_stackOrientedEdges[i].getEdge());
      if(it != map.end()) {
        merge(it->second, others, tmp);
      }
      others = tmp;
    }
  }

  void Interface3DBL::_computeExternalFaces(const MapMEdgeVecMElem &map)
  {
    _externalFaces.resize(_stackOrientedEdges.size());

    // NB: Edge 0 is not modified so we do not need to know the faces it touches
    for(std::size_t i = 1; i < _stackOrientedEdges.size(); ++i) {
      MEdge edge = _stackOrientedEdges[i].getEdge();
      std::vector<MFaceN> &faces = _externalFaces[i];

      // Compute elements touching edge
      std::vector<MElement *> elements;
      {
        MElement *el;
        if(i > 0) {
          if(el = _col1->getBLElement(i - 1)) elements.push_back(el);
          if(_col2 && (el = _col2->getBLElement(i - 1))) elements.push_back(el);
        }
        if(el = _col1->getBLElement(i)) elements.push_back(el);
        if(_col2 && (el = _col2->getBLElement(i))) elements.push_back(el);

        MapMEdgeVecMElem::const_iterator it = map.find(edge);
        if(it != map.end())
          elements.insert(elements.end(), it->second.begin(), it->second.end());
      }

      // Find faces to add
      for(std::size_t i = 0; i < elements.size(); ++i) {
        // Loop over faces. Add a face if touches the edge and is not already in
        int n = 0;
        for(int k = 0; k < elements[i]->getNumFaces(); ++k) {
          MFace f = elements[i]->getFace(k);
          // loop on edges of face 'f':
          for(std::size_t l = 0; l < f.getNumVertices(); ++l) {
            if(f.getEdge(l) == edge) {
              ++n;
              bool alreadyIn = false;
              for(std::size_t l = 0; l < faces.size(); ++l) {
                if(f == faces[l].getFace()) {
                  alreadyIn = true;
                  break;
                }
              }
              if(!alreadyIn) faces.push_back(elements[i]->getHighOrderFace(f));
              break;
            }
          }
          // Only 2 faces of an element can touch a given edge
          if(n == 2) break;
        }
      }
    }
  }

  void Interface3DBL::_checkGFaceGEdge()
  {
    // Get an interior vertex and check if it is on a GFace:
    MFaceN &face = _stackOrientedFaces.back();
    int i = face.getNumVertices();
    while(--i >= 0) {
      GEntity *ent = face.getVertex(i)->onWhat();
      if(ent && ent->dim() == 2) {
        _gface = ent->cast2Face();
        break;
      }
    }

    // Get a vertex at the bottom and check if it is on a GEdge:
    MEdgeN &edge = _stackOrientedEdges[0];
    i = edge.getNumVertices();
    while(--i >= 0) {
      GEntity *ent = edge.getVertex(i)->onWhat();
      if(ent && ent->dim() == 1) {
        _gedge = ent->cast2Edge();
        break;
      }
    }
  }

  void Interface3DBL::_checkBoundaryElement(const MapMEdgeVecMElem &map)
  {
    if(_col2) return;

    MEdge bottomEdge = _stackOrientedEdges[0].getEdge();
    MapMEdgeVecMElem::const_iterator it = map.find(bottomEdge);
    if(it == map.end() || it->second.empty()) return;

    const std::vector<MElement *> &elements = it->second;

    std::map<MFace, MFaceN, Less_Face> faces;
    faces[_stackOrientedFaces[0].getFace()] = _stackOrientedFaces[0];
    for(std::size_t i = 0; i < elements.size(); ++i) {
      MElement *el = elements[i];
      for(int j = 0; j < el->getNumFaces(); ++j) {
        MFaceN fn = el->getHighOrderFace(j, 1, 0);
        MFace f = fn.getFace();
        bool toAdd = false;
        for(std::size_t k = 0; k < f.getNumVertices(); ++k) {
          MEdge e = f.getEdge(k);
          if(e == bottomEdge) {
            toAdd = true;
            break;
          }
        }
        std::map<MFace, MFaceN>::iterator it = faces.find(f);
        if(toAdd) {
          if(it == faces.end())
            faces[f] = fn;
          else
            faces.erase(it);
        }
      }
    }
    if(faces.size() != 1) {
      // FIXMEDEBUG
      Msg::Error("We should have exactly one face!!");
      return;
    }

    // MFace f = faces.begin()->first;
    MFaceN fn = faces.begin()->second;
    std::vector<MVertex *> vertices = fn.getVertices();
    MElementFactory factory;
    _boundaryElem2 = factory.create(fn.getType(), vertices);
  }

  void Interface3DBL::curve()
  {
    // FIXME:NOW

    // computeInterface(col1, col2, stackEdges, stackFaces);
    //
    // MEdgeN baseEdge = _stackOrientedEdges[0];
    // MEdgeN topEdge = _stackOrientedEdges.back();
    // // FIXME We should check that _stackOrientedEdges.back() is not in a GFace
    //
    // const MElement *bottomEl1 = _col1->getBoundaryElement();
    // const MElement *bottomEl2 = _boundaryElem2; // may be NULL
    // if(_col2) bottomEl2 = _col2->getBoundaryElement();
    //
    // // FIXME:NOW
    //
    // Parameters3DCurve parameters;
    // _computeExtremityCoefficients(parameters);
    // _positionTopEdge(parameters);
    // _recoverQualityTopEdge();
    // _positionInteriorEdges();
    // _repositionInteriorNodes();
    // _checkQuality();
    //
    // // FIXME quid GFace?
    // // FIXME computeExtremityCoefficients should handle if bottomEl2 == NULL
    // computeExtremityCoefficients(bottomEl1, bottomEl2, baseEdge, topEdge, parameters);
    // computePosition3DEdge(bottomEl1, bottomEl2, baseEdge, topEdge, parameters, 0, 0, boundary);
    //
    // computePositionInteriorEdgesLinearTFI(stackFaces, baseEdge, topEdge);
    // repositionInteriorNodes(stackFaces);
  }

  bool qualityOk(double qualLinear, double qualCurved)
  {
    return qualCurved >= .75 || qualCurved > .8 * qualLinear;
  }

  bool qualityOk(std::vector<double> &qualLinear,
                 std::vector<double> &qualCurved)
  {
    if(qualLinear.size() != qualCurved.size()) {
      // FIXMEDEBUG
      Msg::Error("must be same size");
      return true;
    }
    for(std::size_t i = 0; i < qualLinear.size(); ++i) {
      if(!qualityOk(qualLinear[i], qualCurved[i])) return false;
    }
    return true;
  }

  void Interface3DBL::_computeElementsTouchingLastFace(std::vector<MElement *> &v) const
  {
    v.clear();
    v.reserve(2);
    if(_elementAtLastFace) v.push_back(_elementAtLastFace);
    MElement *tmp;
    tmp = _col1->getBLElement(_numFace - 1);
    if(tmp) v.push_back(tmp);
    tmp = _col2->getBLElement(_numFace - 1);
    if(tmp) v.push_back(tmp);
  }

  void Interface3DBL::_upQualityForLastFaceCheck(std::vector<double> &qual,
                                                 const std::vector<MElement *> &elements) const
  {
    const std::size_t numFaces = _stackOrientedFaces.size();
    repositionInnerVertices(_stackOrientedFaces.back(), _gface, true);
    repositionInnerVertices(_externalFaces[numFaces], _gface, false);
    repositionInnerVertices(_externalFaces[numFaces - 1], _gface, false);
    _col1->repositionInnerVertices(numFaces - 1);
    _col2->repositionInnerVertices(numFaces - 1);
    if(_elementAtLastFace) repositionInnerVertices3D(_elementAtLastFace);
    qual.resize(elements.size());
    for(std::size_t i = 0; i < elements.size(); ++i) {
      qual[i] = jacobianBasedQuality::minIGEMeasure(elements[i]);
    }
  }

  void Interface3DBL::_upQualityForLastEdgeCheck(std::vector<double> &qual) const
  {
    const std::size_t numFaces = _stackOrientedFaces.size();
    repositionInnerVertices(_externalFaces[numFaces], _gface, false);
    qual.resize(_elementsAtLastEdge.size());
    for(std::size_t i = 0; i < _elementsAtLastEdge.size(); ++i) {
      MElement *el = _elementsAtLastEdge[i];
      repositionInnerVertices3D(el);
      qual[i] = jacobianBasedQuality::minIGEMeasure(el);
    }
  }

  void Interface3DBL::recoverQualityElements()
  {
    std::size_t iFirstEdge = 1;
    if(_type == TYPE_TRI) iFirstEdge = 2;
    const std::size_t iLastEdge = _numFace;
    std::vector<MEdgeN> subsetEdges(4);
    subsetEdges[0] = _stackOrientedEdges[0];
    subsetEdges[1] = _stackOrientedEdges[iFirstEdge];
    subsetEdges[2] = _stackOrientedEdges[iLastEdge - 1];
    subsetEdges[3] = _stackOrientedEdges[iLastEdge];
    MEdgeN &lastEdge = subsetEdges[3];

    // 1. Get sure that elements touching last face of the BL are of
    // good quality

    // Get elements touching last face and compute their linear quality
    std::vector<MElement *> lastElements;
    _computeElementsTouchingLastFace(lastElements);
    std::vector<double> qualLinear(lastElements.size());
    for(std::size_t i = 0; i < lastElements.size(); ++i) {
      MElement *linear = createPrimaryElement(lastElements[i]);
      qualLinear[i] = jacobianBasedQuality::minIGEMeasure(linear);
      delete linear;
    }

    // Compute curving and quality of elements touching last face of the BL
    std::vector<double> qualCurved;
    InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, _gface);
    _upQualityForLastFaceCheck(qualCurved, lastElements);

    // Reduce order if quality not met (surely due to oscillations)
    int currentOrder = lastEdge.getPolynomialOrder();
    while(currentOrder > 2 && !qualityOk(qualLinear, qualCurved)) {
      reduceOrderCurve(lastEdge, --currentOrder, _gface);
      InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, _gface);
      _upQualityForLastFaceCheck(qualCurved, lastElements);
    }

    // Further reduce curving if quality not met
    int iter = 0;
    const int maxIter = 15;
    while(iter++ < maxIter && !qualityOk(qualLinear, qualCurved)) {
      reduceCurving(lastEdge, .25, _gface);
      InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, _gface);
      _upQualityForLastFaceCheck(qualCurved, lastElements);
    }

    // 2. Get sure that external elements touching last edge are of
    // good quality

    if(iter < maxIter) {
      qualLinear.resize(_elementsAtLastEdge.size());
      for(std::size_t i = 0; i < _elementsAtLastEdge.size(); ++i) {
        MElement *linear = createPrimaryElement(_elementsAtLastEdge[i]);
        qualLinear[i] = jacobianBasedQuality::minIGEMeasure(linear);
        delete linear;
      }

      _upQualityForLastEdgeCheck(qualCurved);
      while(!qualityOk(qualLinear, qualCurved) && iter++ < maxIter) {
        reduceCurving(lastEdge, .25, _gface);
        _upQualityForLastEdgeCheck(qualCurved);
      }
    }

    if(iter == maxIter) reduceCurving(lastEdge, 1, _gface); // force linear
  }

  void Parameters3DSurface::computeParameters(const MFaceN &baseFace,
                                              const MFaceN &topFace)
  {
    _nCorner = baseFace.getNumCorners();
    _order = baseFace.getPolynomialOrder();
    int nVerticesOnBoundary = _nCorner * _order;
    int sizeParameters = nVerticesOnBoundary;
    bool incomplete = true;
    // Currently, incomplete polynomial space of triangles is not symmetrical,
    // we use complete space
    if(_nCorner == 3) {
      sizeParameters = (_order + 1) * (_order + 2) / 2;
      incomplete = false;
    }
    _thickness.assign(sizeParameters, 0);
    _coeffb.assign(sizeParameters, 0);
    _coeffc.assign(sizeParameters, 0);

    int tagPrimary =
      ElementType::getType(_nCorner == 4 ? TYPE_QUA : TYPE_TRI, 1);
    _primaryFs = BasisFactory::getNodalBasis(tagPrimary);

    int tag = ElementType::getType(_nCorner == 4 ? TYPE_QUA : TYPE_TRI, _order,
                                   incomplete);
    _fs = BasisFactory::getNodalBasis(tag);
    const fullMatrix<double> &refPoints = _fs->getReferenceNodes();
    for(int i = 0; i < nVerticesOnBoundary; ++i) {
      // FIXME Better idea?
      const double &u = refPoints(i, 0);
      const double &v = refPoints(i, 1);
      SVector3 t0, t1, n, h;
      baseFace.frame(u, v, t0, t1, n);
      MVertex *vBase = baseFace.getVertex(i);
      MVertex *vTop = topFace.getVertex(i);
      h = SVector3(vTop->x() - vBase->x(), vTop->y() - vBase->y(),
                   vTop->z() - vBase->z());

      _thickness[i] = dot(h, n);
      _coeffb[i] = dot(h, t0);
      _coeffc[i] = dot(h, t1);
    }

    // Compute interior values for triangle (this is needed if we use complete
    // polynomial space to interpolate on triangles)
    if(_nCorner == 3) {
      const fullMatrix<double> *interpolator;
      interpolator = InnerVertPlacementMatrices::triangle(_order, false);
      for(int i = nVerticesOnBoundary; i < sizeParameters; ++i) {
        for(int j = 0; j < interpolator->size2(); ++j) {
          const double coeff = (*interpolator)(i - nVerticesOnBoundary, j);
          _thickness[i] += coeff * _thickness[j];
          _coeffb[i] += coeff * _coeffb[j];
          _coeffc[i] += coeff * _coeffc[j];
        }
      }
    }

    // Reset factorDegenerate
    for(int i = 0; i < 4; ++i) {
      _factorDegenerate[i] = 1;
    }
  }

  SPoint3
  Parameters3DSurface::computeIdealPositionTopFace(const MFaceN &baseFace,
                                                   double u, double v) const
  {
    SPoint3 p;
    SVector3 t0, t1, n;
    baseFace.frame(u, v, p, t0, t1, n);

    double f[100];
    _fs->f(u, v, 0, f);

    double thickness = 0;
    double coeffb = 0;
    double coeffc = 0;
    for(int j = 0; j < _fs->getNumShapeFunctions(); j++) {
      thickness += f[j] * _thickness[j];
      coeffb += f[j] * _coeffb[j];
      coeffc += f[j] * _coeffc[j];
    }

    _primaryFs->f(u, v, 0, f);

    double factorThickness = 0;
    for(int j = 0; j < _primaryFs->getNumShapeFunctions(); j++) {
      factorThickness += f[j] * _factorDegenerate[j];
    }

    return p + n * factorThickness * thickness + t0 * coeffb + t1 * coeffc;
  }

  Positioner3DCurve::Positioner3DCurve(const MEdgeN &bottomEdge,
                                       MEdgeN &topEdge,
                                       const MElement *bottomEl1,
                                       const MElement *bottomEl2)
  : _el1(bottomEl1), _el2(bottomEl2), _baseEdge(bottomEdge), _topEdge(topEdge)
  {
    _computeExtremityCoefficients();
  }

  Positioner3DCurve::Positioner3DCurve(const MEdgeN &bottomEdge,
                                       MEdgeN &topEdge,
                                       const GFace *gf)
  {

  }

  void Positioner3DCurve::_computeExtremityCoefficients()
  {
    MVertex *vBase, *vTop;
    SVector3 t, n1, n2, w, h;
  
    getBisectorsAtCommonCorners(bottom1, bottom2, baseEdge, n1, n2);

    vBase = _baseEdge.getVertex(0);
    vTop = _topEdge.getVertex(0);
    t = _baseEdge.tangent(-1);
    w = crossprod(t, n1);
    h = SVector3(vTop->x() - vBase->x(), vTop->y() - vBase->y(),
                 vTop->z() - vBase->z());

    _thickness[0] = dot(h, n1);
    _coeffb[0] = dot(h, t);
    _coeffc[0] = dot(h, w);
    //
    //    SPoint3 p1(vBase->x(), vBase->y(), vBase->z());
    //    draw3DFrame(p1, t, n1, w, .1, *GModel::current()->firstFace());

    vBase = _baseEdge.getVertex(1);
    vTop = _topEdge.getVertex(1);
    t = _baseEdge.tangent(1);
    w = crossprod(t, n2);
    h = SVector3(vTop->x() - vBase->x(), vTop->y() - vBase->y(),
                 vTop->z() - vBase->z());

    _thickness[1] = dot(h, n2);
    _coeffb[1] = dot(h, t);
    _coeffc[1] = dot(h, w);
    //
    //    SPoint3 p2(vBase->x(), vBase->y(), vBase->z());
    //    draw3DFrame(p2, t, n2, w, .1, *GModel::current()->firstFace());
  }

  void Positioner3DCurve::_computeBisector(double xi, SVector3 &n)
  {
    if(_gface) {
      // FIXME:NOW Compute normal of gface
    }
    else if(!_el2) {
      // FIXME:NOW Compute normal of el1
    }
    else {
      // FIXME:NOW Compute bisector
    }
  }

  // compute adjacencies of boundary elements, thus of columns
  void computeAdjacencies(const std::vector<Column3DBL> &columns,
                          std::vector<std::pair<int, int> > &adjacencies,
                          std::vector<std::pair<int, MEdge> > &borderEdges)
  {
    std::map<MEdge, int, Less_Edge> edge2element;
    std::map<MEdge, int, Less_Edge>::iterator it;
    for(std::size_t i = 0; i < columns.size(); ++i) {
      MElement *el = columns[i].getBoundaryElement();
      for(std::size_t j = 0; j < el->getNumEdges(); ++j) {
        MEdge e = el->getEdge(j);
        it = edge2element.find(e);
        if(it != edge2element.end()) {
          adjacencies.push_back(std::make_pair(i, it->second));
          edge2element.erase(it);
        }
        else {
          edge2element[e] = i;
        }
      }
    }
    borderEdges.reserve(edge2element.size());
    for(it = edge2element.begin(); it != edge2element.end(); ++it) {
      borderEdges.push_back(std::make_pair(it->second, it->first));
    }
  }

  void computeInterface(const PairMElemVecMElem &col1,
                        const PairMElemVecMElem &col2,
                        std::vector<MEdgeN> &stackEdges,
                        std::vector<MFaceN> &stackFaces)
  {
    MEdge commonEdge;
    if(!computeCommonEdge(col1.first, col2.first, commonEdge)) {
      Msg::Error("Couldn't find common edge on bottom elements");
      return;
    }

    if(col1.second.size() > col2.second.size()) {
      // computeStackHOEdgesFaces(col1, commonEdge, stackEdges, stackFaces);
    }
    else {
      // computeStackHOEdgesFaces(col2, commonEdge, stackEdges, stackFaces);
    }
  }

  void getBisectorsAtCommonCorners(const MElement *surface1,
                                   const MElement *surface2,
                                   MEdgeN const &commonEdge, SVector3 &n1,
                                   SVector3 &n2)
  {
    // Assume that 't' is the tangent of the common edge between the two
    // surfaces. This function return the vector 'n' that is normal to 't' and
    // such that the plane generated by 't' and 'n' is the bisector plane of the
    // two surfaces at vertex 'corner'...

    // Dertermine if the two surfaces have the same orientation
    int nEdge1, sign1;
    int nEdge2, sign2;
    surface1->getEdgeInfo(commonEdge.getEdge(), nEdge1, sign1);
    surface2->getEdgeInfo(commonEdge.getEdge(), nEdge2, sign2);
    bool sameOrientation = (sign1 != sign2);

    SVector3 ns1, ns2;

    int iNode;
    double u, v, w;
    double gradients[3][3];
    const int nVertices1 = surface1->getNumPrimaryVertices();
    const int nVertices2 = surface2->getNumPrimaryVertices();

    // 1st normal
    iNode = sign1 > 0 ? nEdge1 : (nEdge1 + 1) % nVertices1;
    surface1->getNode(iNode, u, v, w);
    surface1->getJacobian(u, v, w, gradients);
    ns1 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

    iNode = sign2 > 0 ? nEdge2 : (nEdge2 + 1) % nVertices2;
    surface2->getNode(iNode, u, v, w);
    surface2->getJacobian(u, v, w, gradients);
    ns2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
    if(!sameOrientation) ns2.negate();

    n1 = ns1;
    n1.axpy(1, ns2);
    n1.normalize();

    // 2nd normal
    iNode = sign1 > 0 ? (nEdge1 + 1) % nVertices1 : nEdge1;
    surface1->getNode(iNode, u, v, w);
    surface1->getJacobian(u, v, w, gradients);
    ns1 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

    iNode = sign2 > 0 ? (nEdge2 + 1) % nVertices2 : nEdge2;
    surface2->getNode(iNode, u, v, w);
    surface2->getJacobian(u, v, w, gradients);
    ns2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
    if(!sameOrientation) ns2.negate();

    n2 = ns1;
    n2.axpy(1, ns2);
    n2.normalize();
  }

  void idealPositionEdge(const MElement *bottom1, const MElement *bottom2,
                         const MEdgeN &baseEdge,
                         const Parameters3DCurve &parameters, int nbPoints,
                         const IntPt *points, fullMatrix<double> &xyz,
                         int triDirection = 0, const GFace *gFace = NULL)
  {
    //  static int ITER = 0;
    //  ++ITER;
    //  int MOD = 1;
    //  int START = 0;

    // Dertermine if the two surfaces have the same orientation
    int nEdge1, sign1;
    int nEdge2, sign2;
    bottom1->getEdgeInfo(baseEdge.getEdge(), nEdge1, sign1);
    bottom2->getEdgeInfo(baseEdge.getEdge(), nEdge2, sign2);
    bool sameOrientation = (sign1 != sign2);

    // Dertermine parametric coordinate of two base vertices in both surfaces
    const int nVertices1 = bottom1->getNumPrimaryVertices();
    const int nVertices2 = bottom2->getNumPrimaryVertices();

    double uvwS1beg[3], uvwS1end[3];
    double uvwS2beg[3], uvwS2end[3];

    int iNodeBeg, iNodeEnd;

    iNodeBeg = sign1 > 1 ? nEdge1 : (nEdge1 + 1) % nVertices1;
    iNodeEnd = sign1 > 1 ? (nEdge1 + 1) % nVertices1 : nEdge1;
    bottom1->getNode(iNodeBeg, uvwS1beg[0], uvwS1beg[1], uvwS1beg[2]);
    bottom1->getNode(iNodeEnd, uvwS1end[0], uvwS1end[1], uvwS1end[2]);

    iNodeBeg = sign2 > 1 ? nEdge2 : (nEdge2 + 1) % nVertices2;
    iNodeEnd = sign2 > 1 ? (nEdge2 + 1) % nVertices2 : nEdge2;
    bottom2->getNode(iNodeBeg, uvwS2beg[0], uvwS2beg[1], uvwS2beg[2]);
    bottom2->getNode(iNodeEnd, uvwS2end[0], uvwS2end[1], uvwS2end[2]);

    // fill matrix xyz
    for(int i = 0; i < nbPoints; ++i) {
      const double &u = points[i].pt[0];
      const double coeff = .5 * (1 + u);
      SPoint3 pnt = baseEdge.pnt(u);
      SVector3 t = baseEdge.tangent(u);

      SVector3 n;
      {
        double uvw[3];
        double gradients[3][3];

        uvw[0] = (1 - coeff) * uvwS1beg[0] + coeff * uvwS1end[0];
        uvw[1] = (1 - coeff) * uvwS1beg[1] + coeff * uvwS1end[1];
        uvw[2] = (1 - coeff) * uvwS1beg[2] + coeff * uvwS1end[2];
        bottom1->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        SVector3 ns1 =
          SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

        uvw[0] = (1 - coeff) * uvwS2beg[0] + coeff * uvwS2end[0];
        uvw[1] = (1 - coeff) * uvwS2beg[1] + coeff * uvwS2end[1];
        uvw[2] = (1 - coeff) * uvwS2beg[2] + coeff * uvwS2end[2];
        bottom2->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        SVector3 ns2 =
          SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
        if(!sameOrientation) ns2.negate();

        n = ns1;
        n.axpy(1, ns2);
        n.normalize();
      }

      SVector3 w = crossprod(t, n);

      //    if (ITER % MOD == START)
      //      draw3DFrame(pnt, t, n, w, .25, gFace);

      int &d = triDirection;
      SVector3 h = parameters.thicknessAtPoint(u, d) * n +
                   parameters.coeffbAtPoint(u, d) * t +
                   parameters.coeffcAtPoint(u, d) * w;
      xyz(i, 0) = pnt.x() + h.x();
      xyz(i, 1) = pnt.y() + h.y();
      xyz(i, 2) = pnt.z() + h.z();
    }
  }

  void computePosition3DEdge(const MElement *bottom1, const MElement *bottom2,
                             const MEdgeN &baseEdge, MEdgeN &topEdge,
                             const Parameters3DCurve &parameters,
                             int triDirection, double dampingFactor,
                             const GFace *gFace)
  {
    // Let (t, n, w) be the local reference frame on 'baseEdge'
    // where t(u) is the unit tangent of the 'baseEdge'
    //       n(u) is unit, normal to 't' and such that (t, n) is bisector of
    //            faces 'bottom1' and 'bottom2' at corresponding point
    //       w = t x n
    // We seek for each component the polynomial function that fit the best
    //   x1(u) = x0(u) + h(u) * n(u) + b(u) * t(u) + c(u) * w(u)
    // in the least square sense.
    // where x0(u) is the position of 'baseEdge' and h, b, c are given by
    //       'parameters'

    const int orderCurve = baseEdge.getPolynomialOrder();
    const int orderGauss = orderCurve * 2;
    const int sizeSystem = getNGQLPts(orderGauss);
    const IntPt *gaussPnts = getGQLPts(orderGauss);

    fullMatrix<double> xyz(sizeSystem + 2, 3);
    idealPositionEdge(bottom1, bottom2, baseEdge, parameters, sizeSystem,
                      gaussPnts, xyz, triDirection, gFace);
    //  drawIdealPositionEdge(bottom1, bottom2, baseEdge, parameters, gFace,
    //  triDirection);
    for(int i = 0; i < 2; ++i) {
      MVertex *v = topEdge.getVertex(i);
      xyz(sizeSystem + i, 0) = v->x();
      xyz(sizeSystem + i, 1) = v->y();
      xyz(sizeSystem + i, 2) = v->z();
    }

    BoundaryLayerCurver::LeastSquareData *data =
      BoundaryLayerCurver::getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);
    fullMatrix<double> newxyz(orderCurve + 1, 3);
    data->invA.mult(xyz, newxyz);

    for(std::size_t i = 2; i < topEdge.getNumVertices(); ++i) {
      MVertex *v = topEdge.getVertex(i);
      v->x() = newxyz(i, 0);
      v->y() = newxyz(i, 1);
      v->z() = newxyz(i, 2);
    }
  }

  void computeExtremityCoefficients(const MElement *bottom1,
                                    const MElement *bottom2,
                                    const MEdgeN &baseEdge,
                                    const MEdgeN &topEdge,
                                    Parameters3DCurve &parameters)
  {
    MVertex *vBase, *vTop;
    SVector3 t, n1, n2, w, h;

    getBisectorsAtCommonCorners(bottom1, bottom2, baseEdge, n1, n2);

    vBase = baseEdge.getVertex(0);
    vTop = topEdge.getVertex(0);
    t = baseEdge.tangent(-1);
    w = crossprod(t, n1);
    h = SVector3(vTop->x() - vBase->x(), vTop->y() - vBase->y(),
                 vTop->z() - vBase->z());

    parameters.thickness[0] = dot(h, n1);
    parameters.coeffb[0] = dot(h, t);
    parameters.coeffc[0] = dot(h, w);
    //
    //    SPoint3 p1(vBase->x(), vBase->y(), vBase->z());
    //    draw3DFrame(p1, t, n1, w, .1, *GModel::current()->firstFace());

    vBase = baseEdge.getVertex(1);
    vTop = topEdge.getVertex(1);
    t = baseEdge.tangent(1);
    w = crossprod(t, n2);
    h = SVector3(vTop->x() - vBase->x(), vTop->y() - vBase->y(),
                 vTop->z() - vBase->z());

    parameters.thickness[1] = dot(h, n2);
    parameters.coeffb[1] = dot(h, t);
    parameters.coeffc[1] = dot(h, w);
    //
    //    SPoint3 p2(vBase->x(), vBase->y(), vBase->z());
    //    draw3DFrame(p2, t, n2, w, .1, *GModel::current()->firstFace());
  }

  void computePositionInteriorEdgesLinearTFI(std::vector<MFaceN> &stackFaces,
                                             const MEdgeN &baseEdge,
                                             const MEdgeN &topEdge)
  {
    // Here, we assume that "thickness" is identical on the left and on the
    // right part of the stack => identical eta_i
    MVertex *vbot = baseEdge.getVertex(0);
    MVertex *vtop = topEdge.getVertex(0);
    double dX = vtop->x() - vbot->x();
    double dY = vtop->y() - vbot->y();
    double dZ = vtop->z() - vbot->z();
    int componentToLookAt = 0;
    if(std::abs(dY) > std::abs(dX)) {
      if(std::abs(dZ) > std::abs(dY))
        componentToLookAt = 2;
      else
        componentToLookAt = 1;
    }
    else if(std::abs(dZ) > std::abs(dX))
      componentToLookAt = 2;

    // Go trough the whole stack and compute TFI position of topVertices
    for(std::size_t i = 1; i < (int)stackFaces.size() - 1; ++i) {
      MEdgeN e = stackFaces[i].getHighOrderEdge(0, 1);
      MVertex *v = e.getVertex(0);
      double factor;
      switch(componentToLookAt) {
      case 0: factor = (v->x() - vbot->x()) / dX; break;
      case 1: factor = (v->y() - vbot->y()) / dY; break;
      case 2: factor = (v->z() - vbot->z()) / dZ; break;
      }
      for(std::size_t j = 2; j < e.getNumVertices(); ++j) {
        MVertex *vbot = baseEdge.getVertex(j);
        MVertex *vtop = topEdge.getVertex(j);
        MVertex *v = e.getVertex(j);
        v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
        v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
        v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
      }
    }
  }

  void repositionInteriorNodes(std::vector<MFaceN> &stackFaces)
  {
    for(std::size_t i = 0; i < stackFaces.size(); ++i) {
      MFaceN &f = stackFaces[i];
      const fullMatrix<double> *placement = NULL;
      if(f.isTriangular()) {
        // TODO Determine if edge 0 or 2
      }
      else {
        placement =
          InnerVertPlacementMatrices::quadrangle(f.getPolynomialOrder(), true);
      }
      f.repositionInnerVertices(placement);
    }
  }

  void idealPositionFace(const MFaceN &baseFace,
                         const Parameters3DSurface &parameters, int nbPoints,
                         const IntPt *points, fullMatrix<double> &xyz)
  {
    for(int i = 0; i < nbPoints; ++i) {
      const double &u = points[i].pt[0];
      const double &v = points[i].pt[1];
      SPoint3 p = parameters.computeIdealPositionTopFace(baseFace, u, v);
      xyz(i, 0) = p.x();
      xyz(i, 1) = p.y();
      xyz(i, 2) = p.z();
    }
  }

  void computePosition3DFace(const MFaceN &baseFace, MFaceN &topFace,
                             const Parameters3DSurface &parameters,
                             const GFace *gFace)
  {
    // Let (t0, t1, n) be the local reference frame on 'baseFace'
    // We seek, for each component, the polynomial function that fit the best
    //   x1(u) = x0(u) + h(u) * n(u) + b(u) * t0(u) + c(u) * t1(u)
    // in the least square sense.
    // where x0(u) is the position of 'baseFace' and h, b, c are given by
    //       'parameters'

    const int orderSurface = baseFace.getPolynomialOrder();
    const int orderGauss = orderSurface * 2;
    const int nVerticesBoundary = baseFace.getNumVerticesOnBoundary();
    int sizeSystem;
    IntPt *gaussPnts;
    if(baseFace.isTriangular()) {
      sizeSystem = getNGQTPts(orderGauss);
      gaussPnts = getGQTPts(orderGauss);
    }
    else {
      sizeSystem = getNGQQPts(orderGauss);
      gaussPnts = getGQQPts(orderGauss);
    }

    fullMatrix<double> xyz(sizeSystem + nVerticesBoundary, 3);
    idealPositionFace(baseFace, parameters, sizeSystem, gaussPnts, xyz);
    for(int i = 0; i < nVerticesBoundary; ++i) {
      MVertex *v = topFace.getVertex(i);
      xyz(sizeSystem + i, 0) = v->x();
      xyz(sizeSystem + i, 1) = v->y();
      xyz(sizeSystem + i, 2) = v->z();
    }

    BoundaryLayerCurver::LeastSquareData *data =
      BoundaryLayerCurver::getLeastSquareData(baseFace.getType(), orderSurface,
                                              orderGauss);
    fullMatrix<double> newxyz(data->invA.size1(), 3);
    data->invA.mult(xyz, newxyz);

    for(std::size_t i = nVerticesBoundary; i < topFace.getNumVertices(); ++i) {
      MVertex *v = topFace.getVertex(i);
      v->x() = newxyz(i, 0);
      v->y() = newxyz(i, 1);
      v->z() = newxyz(i, 2);
    }
  }

  void computePositionInteriorFacesLinearTFI(std::vector<MFaceN> &stackFaces,
                                             const MFaceN &baseFace,
                                             const MFaceN &topFace)
  {
    // Here, we assume that "thickness" is identical on the boundary
    // => identical eta_i
    MVertex *vbot = baseFace.getVertex(0);
    MVertex *vtop = topFace.getVertex(0);
    double dX = vtop->x() - vbot->x();
    double dY = vtop->y() - vbot->y();
    double dZ = vtop->z() - vbot->z();
    int componentToLookAt = 0;
    if(std::abs(dY) > std::abs(dX)) {
      if(std::abs(dZ) > std::abs(dY))
        componentToLookAt = 2;
      else
        componentToLookAt = 1;
    }
    else if(std::abs(dZ) > std::abs(dX))
      componentToLookAt = 2;

    // Go trough the whole stack and compute TFI position of topVertices
    for(std::size_t i = 1; i < (int)stackFaces.size() - 1; ++i) {
      MFaceN &f = stackFaces[i];
      MVertex *v = f.getVertex(0);
      double factor;
      switch(componentToLookAt) {
      case 0: factor = (v->x() - vbot->x()) / dX; break;
      case 1: factor = (v->y() - vbot->y()) / dY; break;
      case 2: factor = (v->z() - vbot->z()) / dZ; break;
      }
      for(std::size_t j = f.getNumVerticesOnBoundary(); j < f.getNumVertices(); ++j) {
        MVertex *vbot = baseFace.getVertex(j);
        MVertex *vtop = topFace.getVertex(j);
        MVertex *v = f.getVertex(j);
        v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
        v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
        v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
      }
    }
  }

  void repositionInteriorNodes(const std::vector<MFaceN> &stackFaces,
                               const std::vector<MElement *> &stackElements)
  {
    // TODO: reposition last elements
    for(std::size_t i = 0; i < stackElements.size() - 1; ++i) {
      MElement *el = stackElements[i];
      const fullMatrix<double> *placement = NULL;
      const int order = el->getPolynomialOrder();
      int nFace, nOtherFace, sign, rot;
      switch(el->getType()) {
      case TYPE_TET:
        el->getFaceInfo(stackFaces[i].getFace(), nFace, sign, rot);
        el->getFaceInfo(stackFaces[i + 1].getFace(), nOtherFace, sign, rot);
        placement = InnerVertPlacementMatrices::tetrahedron(order, true, nFace,
                                                            nOtherFace);
        break;
      case TYPE_HEX:
        el->getFaceInfo(stackFaces[i].getFace(), nFace, sign, rot);
        placement = InnerVertPlacementMatrices::hexahedron(order, true, nFace);
        break;
      case TYPE_PRI:
        el->getFaceInfo(stackFaces[i].getFace(), nFace, sign, rot);
        if(nFace > 1) {
          el->getFaceInfo(stackFaces[i + 1].getFace(), nOtherFace, sign, rot);
          if(nFace != 2 && nOtherFace != 2)
            nFace = 2;
          else if(nFace != 3 && nOtherFace != 3)
            nFace = 3;
          else
            nFace = 4;
        }
        placement = InnerVertPlacementMatrices::prism(order, true, nFace);
        break;
      }
      if(placement)
        repositionInteriorNodes(el, *placement);
      else
        Msg::Error("Implement placement for type %d", el->getType());
    }
  }

  void curveColumns(VecPairMElemVecMElem &columns, const GFace *boundary)
  {
    Parameters3DSurface parameters;
    for(std::size_t i = 0; i < columns.size(); ++i) {
      //      if (columns[i].first->getNum() != 855) continue;

      std::vector<MFaceN> stackFaces;
      computeStackHighOrderFaces(columns[i], stackFaces);

      MFaceN &baseFace = stackFaces[0];
      MFaceN &topFace = stackFaces.rbegin()[1]; // last but one element
      parameters.computeParameters(baseFace, topFace);
      computePosition3DFace(baseFace, topFace, parameters, boundary);

      computePositionInteriorFacesLinearTFI(stackFaces, baseFace, topFace);
      repositionInteriorNodes(stackFaces, columns[i].second);
    }
  }

  void curveBorders(VecPairMElemVecMElem &columns,
                    std::vector<std::pair<int, MEdge> > &borderEdges)
  {
    for(size_t i = 0; i < borderEdges.size(); ++i) {
      // std::size_t idx = borderEdges[i].first;
      // MEdge &edge = borderEdges[i].second;
      //
      // std::vector<MFaceN> stackFaces;
      // std::vector<MEdgeN> stackEdges;
      // computeStackHOEdgesFaces(columns[idx], edge, stackEdges, stackFaces);
      // if(stackEdges[0].getPolynomialOrder() < 2) continue;
      //
      // // Get an interior vertex and check if the border of the column is on a
      // // GFace. Then do the same for the bottom of column.
      // GFace *gf = NULL;
      // {
      //   MFaceN &face = stackFaces.back();
      //   MVertex *v = face.getVertex(face.getNumVertices() - 1);
      //   GEntity *entity = v->onWhat();
      //   if(entity && entity->dim() == 2) gf = entity->cast2Face();
      // }
      // GEdge *ge = NULL;
      // {
      //   MEdgeN &edge = stackEdges[0];
      //   MVertex *v = edge.getVertex(2);
      //   GEntity *entity = v->onWhat();
      //   if(entity && entity->dim() == 1) ge = entity->cast2Edge();
      // }
      //
      // if(gf) {
      //   // curveInterface(stackEdges, mapEdgeToElements, gf, ge);
      //   // SVector3 n;
      //   // if(gf->uniqueNormal(n, false))
      //   //   curve2Dcolumn(columns[idx], NULL, ge, n);
      //   // else
      //   //   curve2Dcolumn(columns[idx], gf, ge, n);
      // }
      // else {
      //   // FIXME:NOW
      // }
    }
  }

  void createColumns3D(const VecPairMElemVecMElem &cols,
                       std::vector<Column3DBL> &columns)
  {
    columns.clear();
    columns.reserve(cols.size());
    for(std::size_t i = 0; i < cols.size(); ++i) {
      columns.push_back(Column3DBL(cols[i]));
    }
  }

  void curveInterfaces(std::vector<Column3DBL> &columns,
                       const MapMEdgeVecMElem &touchedElements)
  {
    // We could detect and create all the Interface3DBL objects and then curve
    // them one by one. We choose instead to compute the adjacencies and to
    // create the Interface3DBL on the fly to reduce memory consumption.
    std::vector<std::pair<int, int> > adjacencies;
    std::vector<std::pair<int, MEdge> > borderEdges;
    BoundaryLayerCurver::computeAdjacencies(columns, adjacencies, borderEdges);

    for(std::size_t i = 0; i < borderEdges.size(); ++i) {
      std::size_t idx = borderEdges[i].first;
      MEdge &edge = borderEdges[i].second;
      Interface3DBL interface(columns[idx], edge, touchedElements);

      // FIXME:NOW curve interface
    }

    for(std::size_t i = 0; i < adjacencies.size(); ++i) {
      Column3DBL &col1 = columns[adjacencies[i].first];
      Column3DBL &col2 = columns[adjacencies[i].second];
      Interface3DBL interface(col1, col2, touchedElements);

      // FIXME:NOW curve interface
    }

    // FIXME:RM
    // // compute then curve interfaces between columns
    // for(std::size_t i = 0; i < adjacencies.size(); ++i) {
    //   std::vector<MEdgeN> stackEdges;
    //   std::vector<MFaceN> stackFaces;
    //   PairMElemVecMElem &col1 = columns[adjacencies[i].first];
    //   PairMElemVecMElem &col2 = columns[adjacencies[i].second];
    //   // bool doIt = true;
    //   // if (col1.first->getNum() != 861 && col1.first->getNum() != 467)
    //   //   doIt = false;
    //   // if (col2.first->getNum() != 861 && col2.first->getNum() != 467)
    //   //   doIt = false;
    //   // if (col1.first->getNum() != 5184 || col2.first->getNum() != 4750)
    //   //   continue;
    //
    //   // if (doIt) {
    //   computeInterface(col1, col2, stackEdges, stackFaces);
    //
    //   MEdgeN baseEdge = stackEdges[0];
    //   MEdgeN topEdge = stackEdges.back();
    //   const MElement *bottomEl1 = col1.first;
    //   const MElement *bottomEl2 = col2.first;
    //   Parameters3DCurve parameters;
    //   computeExtremityCoefficients(bottomEl1, bottomEl2, stackEdges[0], stackEdges.back(), parameters);
    //   computePosition3DEdge(bottomEl1, bottomEl2, baseEdge, topEdge, parameters, 0, 0, boundary);
    //
    //   computePositionInteriorEdgesLinearTFI(stackFaces, baseEdge, topEdge);
    //   repositionInteriorNodes(stackFaces);
    //   // Msg::Error("RETURN"); return;
    //   // }
    // }
  }
} // namespace BoundaryLayerCurver

void curve3DBoundaryLayer(VecPairMElemVecMElem &columns,
                          const GFace *boundary)
{
  std::vector<std::pair<int, int> > adjacencies;
  // BoundaryLayerCurver::computeAdjacencies(columns, adjacencies);

  // BoundaryLayerCurver::curveInterfaces(columns, adjacencies, boundary);

  BoundaryLayerCurver::curveColumns(columns, boundary);

  //  Msg::Info("size %d", columns.size());
  for(std::size_t i = 0; i < columns.size(); ++i) {
    columns[i].first->setVisibility(1);
    //    Msg::Info("el %d, size %d", columns[i].first->getNum(),
    //    columns[i].second.size());
    for(std::size_t j = 0; j < columns[i].second.size(); ++j) {
      columns[i].second[j]->setVisibility(1);
    }
  }
}

void curve3DBoundaryLayer(VecPairMElemVecMElem &cols,
                          MapMEdgeVecMElem &touchedElements)
{
  std::vector<BoundaryLayerCurver::Column3DBL> columns;
  BoundaryLayerCurver::createColumns3D(cols, columns);

  BoundaryLayerCurver::curveInterfaces(columns, touchedElements);


  // FIXME we should check that the border interface is not in a GFace in
  //  which case we should call curve2DBoundaryLayer. In the other case, we can
  //  use the same algo than for internal interfaces.
  // BoundaryLayerCurver::curveBorders(columns, borderEdges);

  // NOTE: We can obtain the boundary geometry from boundary element.
  // BoundaryLayerCurver::curveInterfaces(columns, adjacencies, boundary);

  // BoundaryLayerCurver::curveColumns(columns, boundary);

  // FIXME: to implement
}

// FIXME? Est-ce qu'un MVertex connait toujours l'entité dans laquelle elle se trouve ?
// FIXME? Que se passe-t-il si un maillage est chargé sans géométrie ?
// FIXME? Si on charge un maillage avec la géométrie, il y a une différence si
//        le maillage contient des parametric nodes ou pas. Si oui,
//        des MFaceVertex et MEdgeVertex sont créés. Sinon, non.
//        Si on charge juste un maillage, mais que les faces sont plans, on doit
//        pouvoir courber aussi. La seule situation ou on ne peut rien faire,
//        c'est si on n'a pas la géométrie et que les surfaces ne sont pas plans
// FIXME? A: Vertex connait sa face et sa paramétrisation
//        B: Vertex connait sa face mais pas sa paramétrisation
//        C: Vertex se trouve dans une face discrète (la paramétrisation ne sert à rien)
//                         +-----------+---------------+
//                         | Géométrie | Pas Géométrie |
//        -----------------+-----------+---------------+
//        Pas maillage     |     A     | xxxxxxxxxxxxx |
//        -----------------+-----------+---------------+
//        Maillage par     |     A     |      C        |
//        -----------------+-----------+---------------+
//        Maillage non par |     B     |      C        |
//        -----------------+-----------+---------------+