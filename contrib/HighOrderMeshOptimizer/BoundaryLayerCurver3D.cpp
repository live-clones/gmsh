// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
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
#include "Options.h"
#include "AnalyseMeshQuality.h"
#include "InnerVertexPlacement.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

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

    MVertex *previous = nullptr;

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
    fullMatrix<double> *_triangle[10] = {nullptr, nullptr, nullptr, nullptr,
                                         nullptr, nullptr, nullptr, nullptr,
                                         nullptr, nullptr};
    fullMatrix<double> *_quadrangle[10] = {nullptr, nullptr, nullptr, nullptr,
                                           nullptr, nullptr, nullptr, nullptr,
                                           nullptr, nullptr};
    fullMatrix<double> *_linearTriangle0[10] = {
      nullptr, nullptr, nullptr, nullptr, nullptr,
      nullptr, nullptr, nullptr, nullptr, nullptr};
    fullMatrix<double> *_linearTriangle2[10] = {
      nullptr, nullptr, nullptr, nullptr, nullptr,
      nullptr, nullptr, nullptr, nullptr, nullptr};
    fullMatrix<double> *_linearQuadrangle[10] = {
      nullptr, nullptr, nullptr, nullptr, nullptr,
      nullptr, nullptr, nullptr, nullptr, nullptr};
    fullMatrix<double> *_hexahedron[10] = {nullptr, nullptr, nullptr, nullptr,
                                           nullptr, nullptr, nullptr, nullptr,
                                           nullptr, nullptr};
    fullMatrix<double> *_linearHexahedron[3][10] = {
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr}};
    fullMatrix<double> *_prism[10] = {nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr, nullptr, nullptr,
                                      nullptr, nullptr};
    fullMatrix<double> *_linearPrism[4][10] = {
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr}};
    fullMatrix<double> *_tetrahedron[10] = {nullptr, nullptr, nullptr, nullptr,
                                            nullptr, nullptr, nullptr, nullptr,
                                            nullptr, nullptr};
    fullMatrix<double> *_linearTet[6][10] = {
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr},
      {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
       nullptr, nullptr}};

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
        int dir;
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
        int dir;
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
        int dir;
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
    for(int i = 0; i < 4; ++i) { _factorDegenerate[i] = 1; }
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

  // compute adjacencies of boundary elements, thus of columns
  void computeAdjacencies(VecPairMElemVecMElem &bndEl2column,
                          std::vector<std::pair<int, int> > &adjacencies)
  {
    std::map<MEdge, int, MEdgeLessThan> edge2element;
    for(std::size_t i = 0; i < bndEl2column.size(); ++i) {
      MElement *el = bndEl2column[i].first;
      for(std::size_t j = 0; j < el->getNumEdges(); ++j) {
        MEdge e = el->getEdge(j);
        auto it = edge2element.find(e);
        if(it != edge2element.end()) {
          adjacencies.push_back(std::make_pair(i, it->second));
          // This is for debug purpose, we expect that two elements at most
          // share a given edge.
          it->second = -1;
        }
        else {
          edge2element[e] = i;
        }
      }
    }
  }

  bool areSameFaces(MFace &f1, MFace &f2)
  {
    // NB: f1 == f2 will return true for "twisted" quad (having same vertices
    // but the quads are different)
    int nVertices = f1.getNumVertices();
    if(f2.getNumVertices() != nVertices) return false;

    MVertex *v = f1.getVertex(0);

    // Find the vertex in f2
    int k = 0;
    while(k < nVertices && f2.getVertex(k) != v) ++k;
    if(k == nVertices) return false;

    // Just in case
    if(nVertices == 1) return true;

    // Determine which orientation
    int inc = 0;
    if(f2.getVertex((k + 1) % nVertices) == f1.getVertex(1))
      inc = 1;
    else if(f2.getVertex((k + nVertices - 1) % nVertices) == f1.getVertex(1))
      inc = -1;
    if(inc == 0) return false;

    for(int i = 2; i < nVertices; ++i) {
      if(f1.getVertex(i) != f2.getVertex((k + nVertices + inc * i) % nVertices))
        return false;
    }
    return true;
  }

  bool computeCommonFace(MElement *e1, MElement *e2, MFace &f)
  {
    for(int i = 0; i < e1->getNumFaces(); ++i) {
      f = e1->getFace(i);
      for(int j = 0; j < e2->getNumFaces(); ++j) {
        MFace f2 = e2->getFace(j);
        // if (areSameFaces(f, f2)) return true;
        // If the mesh is conformal, f==f2 is sufficient
        if(f == f2) return true;
      }
    }
    f = MFace();
    return false;
  }

  bool faceContainsVertex(const MFace &f, const MVertex *v)
  {
    for(int i = 0; i < f.getNumVertices(); ++i) {
      if(f.getVertex(i) == v) return true;
    }
    return false;
  }

  bool faceContainsEdge(const MFace &f, const MEdge &e)
  {
    MVertex *v0 = e.getMinVertex();
    MVertex *v1 = e.getMaxVertex();
    bool v0In = false;
    bool v1In = false;
    for(int i = 0; i < f.getNumVertices(); ++i) {
      if(f.getVertex(i) == v0) v0In = true;
      if(f.getVertex(i) == v1) v1In = true;
    }
    return v0In && v1In;
  }

  void computeStackPrimaryVertices(const PairMElemVecMElem &c1,
                                   std::vector<MVertex *> &stack)
  {
    int numVertexPerLayer = c1.first->getNumPrimaryVertices();
    std::size_t numLayers = c1.second.size();
    stack.assign(numVertexPerLayer * numLayers, nullptr);

    int k = 0;
    for(int i = 0; i < numVertexPerLayer; ++i) {
      stack[k++] = c1.first->getVertex(i);
    }
    MFace bottomFace = c1.first->getFace(0);
    for(std::size_t i = 0; i < numLayers - 1; ++i) {
      MElement *currentElement = c1.second[i];
      MFace topFace;
      if(!computeCommonFace(currentElement, c1.second[i + 1], topFace)) {
        Msg::Error("Did not find common face");
      }

      // Eeach edge that is not in bottom face nor in top face links a bottom
      // node with the corresponding top node
      for(int j = 0; j < currentElement->getNumEdges(); ++j) {
        MEdge edge = currentElement->getEdge(j);
        if(faceContainsEdge(bottomFace, edge) ||
           faceContainsEdge(topFace, edge))
          continue;

        MVertex *vbot, *vtop;
        if(faceContainsVertex(bottomFace, edge.getVertex(0))) {
          vbot = edge.getVertex(0);
          vtop = edge.getVertex(1);
        }
        else {
          vbot = edge.getVertex(1);
          vtop = edge.getVertex(0);
        }

        for(int l = k - numVertexPerLayer; l < k; ++l) {
          if(stack[l] == vbot) {
            stack[l + numVertexPerLayer] = vtop;
            break;
          }
        }
      }

      // If there remains NULL values, it is because the vertex is the same
      // on bottom face and top face.
      for(int l = k; l < k + numVertexPerLayer; ++l) {
        if(stack[l] == nullptr) stack[l] = stack[l - numVertexPerLayer];
      }

      k += numVertexPerLayer;
      bottomFace = topFace;
    }
  }

  //  bool computeCommonEdge(MElement *el1, MElement *el2, MEdge &e)
  //  {
  //    for (int i = 0; i < el1->getNumEdges(); ++i) {
  //      e = el1->getEdge(i);
  //      for (int j = 0; j < el2->getNumEdges(); ++j) {
  //        MEdge thisEdge = el2->getEdge(j);
  //        if (thisEdge == e) return true;
  //      }
  //    }
  //    e = MEdge();
  //    return false;
  //  }

  void computeInterface(const PairMElemVecMElem &c1,
                        const PairMElemVecMElem &c2,
                        std::vector<MFaceN> &interface, MEdgeN &bottomEdge,
                        MEdgeN &topEdge)
  {
    // Find common edge on boundary
    MElement *bottomElement1 = c1.first;
    MElement *bottomElement2 = c2.first;
    MEdge commonEdge;
    if(!computeCommonEdge(bottomElement1, bottomElement2, commonEdge)) {
      Msg::Error("Couldn't find common edge on bottom elements");
      return;
    }
    bottomEdge = bottomElement1->getHighOrderEdge(commonEdge);

    // Choose biggest column
    PairMElemVecMElem column;
    std::vector<MElement *> stackElements;
    MElement *bottomElement;
    if(c1.second.size() < c2.second.size()) {
      column = c2;
      stackElements = c2.second;
      bottomElement = bottomElement2;
    }
    else {
      column = c1;
      stackElements = c1.second;
      bottomElement = bottomElement1;
    }

    // Compute stack of Primary vertices
    std::vector<MVertex *> allPrimaryVertices;
    computeStackPrimaryVertices(column, allPrimaryVertices);

    std::vector<MVertex *> interfacePrimaryVertices;
    {
      int nVertexPerLayer = bottomElement->getNumPrimaryVertices();
      int n0 = -1;
      int n1 = -1;
      for(int i = 0; i < nVertexPerLayer; ++i) {
        if(bottomEdge.getVertex(0) == allPrimaryVertices[i]) n0 = i;
        if(bottomEdge.getVertex(1) == allPrimaryVertices[i]) n1 = i;
      }
      if(n0 == -1 || n1 == -1) {
        Msg::Error("Error in computeInterface");
        return;
      }
      interfacePrimaryVertices.resize(2 * (stackElements.size()));
      for(std::size_t i = 0; i < stackElements.size(); ++i) {
        interfacePrimaryVertices[2 * i + 0] =
          allPrimaryVertices[nVertexPerLayer * i + n0];
        interfacePrimaryVertices[2 * i + 1] =
          allPrimaryVertices[nVertexPerLayer * i + n1];
      }
    }

    // Compute interface
    interface.clear();
    for(int i = 0; i < stackElements.size() - 1; ++i) {
      MVertex *v0 = interfacePrimaryVertices[2 * i + 0];
      MVertex *v1 = interfacePrimaryVertices[2 * i + 1];
      MVertex *v2 = interfacePrimaryVertices[2 * i + 3];
      MVertex *v3 = interfacePrimaryVertices[2 * i + 2];
      if(v2 == v1 && v3 == v0) {
        Msg::Error("Error in computeInterface: not an element");
      }
      if(v2 == v1) {
        v2 = v3;
        v3 = nullptr;
      }
      else if(v3 == v0) {
        v3 = nullptr;
      }
      interface.push_back(
        stackElements[i]->getHighOrderFace(MFace(v0, v1, v2, v3)));
      //      if (v3 == NULL) {
      //        if (   v0 != interface.back().getVertex(0)
      //               || v1 != interface.back().getVertex(1)
      //               || v2 != interface.back().getVertex(2))
      //          Msg::Error("did not get the faceN I wanted!");
      //        std::cout << "vertices: " << v0->getNum() << " " << v1->getNum()
      //        << " " << v2->getNum() << std::endl; std::cout << "vertices: "
      //        << interface.back().getVertex(0)->getNum() << " " <<
      //        interface.back().getVertex(1)->getNum() << " "; std::cout <<
      //        interface.back().getVertex(2)->getNum() << std::endl;
      //      }
      //      else {
      //        if (   v0 != interface.back().getVertex(0)
      //               || v1 != interface.back().getVertex(1)
      //               || v2 != interface.back().getVertex(2)
      //               || v3 != interface.back().getVertex(3))
      //          Msg::Error("did not get the faceN I wanted!");
      //        std::cout << "vertices: " << v0->getNum() << " " << v1->getNum()
      //        << " " << v2->getNum() << " " << v3->getNum() << std::endl;
      //        std::cout << "vertices: " <<
      //        interface.back().getVertex(0)->getNum() << " " <<
      //        interface.back().getVertex(1)->getNum() << " "; std::cout <<
      //        interface.back().getVertex(2)->getNum() << " " <<
      //        interface.back().getVertex(3)->getNum() << std::endl;
      //      }
    }
    topEdge = interface.back().getHighOrderEdge(0, 1);
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

    // First normal
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

    // Second normal
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
                         int triDirection = 0, const GFace *gFace = nullptr)
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
    //       faces
    //            'bottom1' and 'bottom2' at corresponding point
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

    for(int i = 2; i < topEdge.getNumVertices(); ++i) {
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

  void computePositionInteriorEdgesLinearTFI(std::vector<MFaceN> &column,
                                             const MEdgeN &baseEdge,
                                             const MEdgeN &topEdge)
  {
    // Here, we assume that "thickness" is identical on the left and on the
    // right part of the column => identical eta_i
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

    // Go trough the whole column and compute TFI position of topVertices
    for(int i = 1; i < (int)column.size() - 1; ++i) {
      MEdgeN e = column[i].getHighOrderEdge(0, 1);
      MVertex *v = e.getVertex(0);
      double factor;
      switch(componentToLookAt) {
      case 0: factor = (v->x() - vbot->x()) / dX; break;
      case 1: factor = (v->y() - vbot->y()) / dY; break;
      case 2: factor = (v->z() - vbot->z()) / dZ; break;
      }
      for(int j = 2; j < e.getNumVertices(); ++j) {
        MVertex *vbot = baseEdge.getVertex(j);
        MVertex *vtop = topEdge.getVertex(j);
        MVertex *v = e.getVertex(j);
        v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
        v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
        v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
      }
    }
  }

  void repositionInteriorNodes(std::vector<MFaceN> &column)
  {
    for(std::size_t i = 0; i < column.size(); ++i) {
      MFaceN &f = column[i];
      const fullMatrix<double> *placement = nullptr;
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

  void curveInterface(std::vector<MFaceN> &column, const MElement *bottom1,
                      const MElement *bottom2, const MEdgeN &baseEdge,
                      MEdgeN &topEdge, double dampingFactor,
                      const GFace *bndEnt, bool linear)
  {
    // inspired from curve2DQuadColumnTFI

    Parameters3DCurve parameters;
    computeExtremityCoefficients(bottom1, bottom2, baseEdge, topEdge,
                                 parameters);
    computePosition3DEdge(bottom1, bottom2, baseEdge, topEdge, parameters, 0,
                          dampingFactor, bndEnt);

    computePositionInteriorEdgesLinearTFI(column, baseEdge, topEdge);
    repositionInteriorNodes(column);
  }

  // compute then curve interfaces between columns
  void curveInterfaces(VecPairMElemVecMElem &bndEl2column,
                       std::vector<std::pair<int, int> > &adjacencies,
                       const GFace *boundary)
  {
    for(std::size_t i = 0; i < adjacencies.size(); ++i) {
      MEdgeN bottomEdge, topEdge;
      std::vector<MFaceN> interface;
      PairMElemVecMElem &column1 = bndEl2column[adjacencies[i].first];
      PairMElemVecMElem &column2 = bndEl2column[adjacencies[i].second];
      //      bool doIt = true;
      //      if (column1.first->getNum() != 861 && column1.first->getNum() !=
      //      467)
      //        doIt = false;
      //      if (column2.first->getNum() != 861 && column2.first->getNum() !=
      //      467)
      //        doIt = false;

      //      if (column1.first->getNum() != 5184 || column2.first->getNum() !=
      //      4750) continue;

      //      if (doIt) {
      computeInterface(column1, column2, interface, bottomEdge, topEdge);
      curveInterface(interface, column1.first, column2.first, bottomEdge,
                     topEdge, 0, boundary, true);
      //        Msg::Error("RETURN"); return;
      //      }
    }
  }

  void computeStackHighOrderFaces(const PairMElemVecMElem &bndEl2column,
                                  std::vector<MFaceN> &stack)
  {
    const std::vector<MElement *> &column = bndEl2column.second;
    stack.resize(column.size());

    std::vector<MVertex *> allPrimaryVertices;
    computeStackPrimaryVertices(bndEl2column, allPrimaryVertices);
    // FIXME already calculated in computeInterfaces. Reuse them?

    int nVertexPerLayer = bndEl2column.first->getNumPrimaryVertices();
    for(std::size_t j = 0; j < stack.size(); ++j) {
      MFace f;
      if(nVertexPerLayer == 3)
        f = MFace(allPrimaryVertices[j * 3 + 0], allPrimaryVertices[j * 3 + 1],
                  allPrimaryVertices[j * 3 + 2]);
      else
        f = MFace(allPrimaryVertices[j * 4 + 0], allPrimaryVertices[j * 4 + 1],
                  allPrimaryVertices[j * 4 + 2], allPrimaryVertices[j * 4 + 3]);
      stack[j] = column[j]->getHighOrderFace(f);
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

    for(int i = nVerticesBoundary; i < topFace.getNumVertices(); ++i) {
      MVertex *v = topFace.getVertex(i);
      v->x() = newxyz(i, 0);
      v->y() = newxyz(i, 1);
      v->z() = newxyz(i, 2);
    }
  }

  void computePositionInteriorFacesLinearTFI(std::vector<MFaceN> &column,
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

    // Go trough the whole column and compute TFI position of topVertices
    for(int i = 1; i < (int)column.size() - 1; ++i) {
      MFaceN &f = column[i];
      MVertex *v = f.getVertex(0);
      double factor;
      switch(componentToLookAt) {
      case 0: factor = (v->x() - vbot->x()) / dX; break;
      case 1: factor = (v->y() - vbot->y()) / dY; break;
      case 2: factor = (v->z() - vbot->z()) / dZ; break;
      }
      for(int j = f.getNumVerticesOnBoundary(); j < f.getNumVertices(); ++j) {
        MVertex *vbot = baseFace.getVertex(j);
        MVertex *vtop = topFace.getVertex(j);
        MVertex *v = f.getVertex(j);
        v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
        v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
        v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
      }
    }
  }

  void repositionInteriorNodes(MElement *el,
                               const fullMatrix<double> &placement)
  {
    int start = el->getNumVertices() - el->getNumVolumeVertices();
    for(int i = start; i < el->getNumVertices(); ++i) {
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

  void repositionInteriorNodes(const std::vector<MFaceN> &stackFaces,
                               const std::vector<MElement *> &column)
  {
    // TODO: reposition last elements
    for(std::size_t i = 0; i < column.size() - 1; ++i) {
      MElement *el = column[i];
      const fullMatrix<double> *placement = nullptr;
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

  void curveColumns(VecPairMElemVecMElem &bndEl2column, const GFace *boundary)
  {
    Parameters3DSurface parameters;
    for(std::size_t i = 0; i < bndEl2column.size(); ++i) {
      //      if (bndEl2column[i].first->getNum() != 855) continue;

      std::vector<MFaceN> stackFaces;
      computeStackHighOrderFaces(bndEl2column[i], stackFaces);

      MFaceN &baseFace = stackFaces[0];
      MFaceN &topFace = stackFaces.rbegin()[1]; // last but one element
      parameters.computeParameters(baseFace, topFace);
      computePosition3DFace(baseFace, topFace, parameters, boundary);

      computePositionInteriorFacesLinearTFI(stackFaces, baseFace, topFace);
      repositionInteriorNodes(stackFaces, bndEl2column[i].second);
    }
  }
} // namespace BoundaryLayerCurver

void curve3DBoundaryLayer(VecPairMElemVecMElem &bndEl2column,
                          const GFace *boundary)
{
  std::vector<std::pair<int, int> > adjacencies;
  BoundaryLayerCurver::computeAdjacencies(bndEl2column, adjacencies);

  BoundaryLayerCurver::curveInterfaces(bndEl2column, adjacencies, boundary);

  BoundaryLayerCurver::curveColumns(bndEl2column, boundary);

  //  Msg::Info("size %d", bndEl2column.size());
  for(int i = 0; i < bndEl2column.size(); ++i) {
    bndEl2column[i].first->setVisibility(1);
    //    Msg::Info("el %d, size %d", bndEl2column[i].first->getNum(),
    //    bndEl2column[i].second.size());
    for(std::size_t j = 0; j < bndEl2column[i].second.size(); ++j) {
      bndEl2column[i].second[j]->setVisibility(1);
    }
  }
}
