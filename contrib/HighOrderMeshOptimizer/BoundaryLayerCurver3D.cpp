// Copyright (C) 2017 ULg-UCL
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
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Amaury Johnen

#include "BoundaryLayerCurver.h"
#include "MQuadrangle.h"
#include "MTriangle.h"
#include "BasisFactory.h"
#include "GFace.h"
#include "legendrePolynomials.h"
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
#include "InteriorNodePlacement.h"

namespace
{
  void draw3DFrame(SPoint3 &p, SVector3 &t, SVector3 &n, SVector3 &w,
                   double unitDimension, GFace *gFace)
  {
    // Make sure to have 2 vector that are perpendicular to t assuming n != alpha * t, forall alpha
    SVector3 a = n;
    SVector3 b = crossprod(t, n).unit();
    a = crossprod(t, b).unit();
    a *= unitDimension;
    b *= unitDimension;

    SPoint3 pnt = p + a;
    MVertex *previous = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);
   gFace->addMeshVertex(previous);

    const int N = 30;
    for (int j = 1; j <= N; ++j) {
      const double theta = (double) j / N * 2 * M_PI;
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
    gFace->addMeshVertex(v);
    gFace->addMeshVertex(vn);
    gFace->addMeshVertex(vw);
    MLine *line = new MLine(v, vn);
    gFace->edges().front()->addLine(line);
    line = new MLine(v, vw);
    gFace->edges().front()->addLine(line);
  }

  void drawIdealPositionEdge(const MElement *bottom1, const MElement *bottom2,
                             const MEdgeN &baseEdge,
                             const BoundaryLayerCurver::Parameters3DCurve &parameters,
                             GFace *gFace,
                             int triDirection = 0)
  {
    int N = 40;

    MVertex *previous = NULL;

    for (int i = 0; i < N+1; ++i) {
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
        SVector3 n2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

        if (dot(n, n2) < 0) {
          Msg::Warning("Boundary elements have opposite normals (2) %d -- %d",
                       bottom1->getNum(), bottom2->getNum());
          n.negate();
        }
        n.axpy(1, n2);
        n.normalize();
      }

      SVector3 w = crossprod(t, n);

      int &d = triDirection;
      SVector3 h = parameters.thicknessAtPoint(u, d) * n
                   + parameters.coeffbAtPoint(u, d) * t
                   + parameters.coeffcAtPoint(u, d) * w;
      double x = pnt.x() + h.x();
      double y = pnt.y() + h.y();
      double z = pnt.z() + h.z();

      MVertex *current = new MVertex(x, y, z, gFace);
      gFace->addMeshVertex(current);
      if (previous) {
        MLine *line = new MLine(previous, current);
        gFace->edges().front()->addLine(line);
      }
      previous = current;
    }
  }
}

namespace BoundaryLayerCurver
{
  namespace InteriorNodePlacementMatrices {
    fullMatrix<double>* triangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                        NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double>* quadrangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                          NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double>* linearTriangle0[10] = {NULL, NULL, NULL, NULL, NULL,
                                               NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double>* linearTriangle2[10] = {NULL, NULL, NULL, NULL, NULL,
                                               NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double>* linearQuadrangle[10] = {NULL, NULL, NULL, NULL, NULL,
                                                NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double>* hexahedron[10] = {NULL, NULL, NULL, NULL, NULL,
                                          NULL, NULL, NULL, NULL, NULL};
    fullMatrix<double>* linearHexahedron[3][10] = {{NULL, NULL, NULL, NULL, NULL,
                                                    NULL, NULL, NULL, NULL, NULL},
                                                   {NULL, NULL, NULL, NULL, NULL,
                                                    NULL, NULL, NULL, NULL, NULL},
                                                   {NULL, NULL, NULL, NULL, NULL,
                                                    NULL, NULL, NULL, NULL, NULL}};

    const fullMatrix<double>* forTriangle(int order, bool linear, int edge = 2)
    {
      if (!linear) {
        if (!triangle[order]) {
          triangle[order] = new fullMatrix<double>();
          *triangle[order] = gmshGenerateInteriorNodePlacementTriangle(order);
        }
        return triangle[order];
      }
      else if (edge == 0) {
        if (!linearTriangle0[order]) {
          linearTriangle0[order] = new fullMatrix<double>();
          *linearTriangle0[order] =
              gmshGenerateInteriorNodePlacementTriangleLinear(order, 0);
        }
        return linearTriangle0[order];
      }
      else if (edge == 2) {
        if (!linearTriangle2[order]) {
          linearTriangle2[order] = new fullMatrix<double>();
          *linearTriangle2[order] =
              gmshGenerateInteriorNodePlacementTriangleLinear(order, 2);
        }
        return linearTriangle2[order];
      }
    }

    const fullMatrix<double>* forQuadrangle(int order, bool linear)
    {
      if (!linear) {
        if (!quadrangle[order]) {
          quadrangle[order] = new fullMatrix<double>();
          *quadrangle[order] = gmshGenerateInteriorNodePlacementQuadrangle(order);
        }
        return quadrangle[order];
      }
      else {
        if (!linearQuadrangle[order]) {
          linearQuadrangle[order] = new fullMatrix<double>();
          *linearQuadrangle[order] =
              gmshGenerateInteriorNodePlacementQuadrangleLinear(order);
        }
        return linearQuadrangle[order];
      }
    }

    const fullMatrix<double>* forHexahedron(int order, bool linear, int face = 0)
    {
      if (!linear) {
        if (!hexahedron[order]) {
          hexahedron[order] = new fullMatrix<double>();
          *hexahedron[order] = gmshGenerateInteriorNodePlacementHexahedron(order);
        }
        return hexahedron[order];
      }
      else {
        int dir;
        switch (face) {
          default:
          case 0: case 5: dir = 3; break;
          case 1: case 4: dir = 1; break;
          case 2: case 3: dir = 0; break;
        }
        if (!linearHexahedron[dir][order]) {
          linearHexahedron[dir][order] = new fullMatrix<double>();
          *linearHexahedron[dir][order] =
              gmshGenerateInteriorNodePlacementHexahedronLinear(order, dir);
        }
        return linearHexahedron[dir][order];
      }
    }
  }

  void Parameters3DSurface::computeParameters(const MFaceN &baseFace,
                                           const MFaceN &topFace)
  {
    _nCorner = baseFace.getNumCorners();
    _order = baseFace.getOrder();
    int nVerticesOnBoundary = _nCorner * _order;
    int sizeParameters = nVerticesOnBoundary;
    bool incomplete = true;
    // Currently, incomplete polynomial space of triangles is not symmetrical,
    // we use complete space
    if (_nCorner == 3) {
      sizeParameters = (_order + 1) * (_order + 2) / 2;
      incomplete = false;
    }
    _thickness.assign(sizeParameters, 0);
    _coeffb.assign(sizeParameters, 0);
    _coeffc.assign(sizeParameters, 0);

    int tagPrimary = ElementType::getTag(_nCorner == 4 ? TYPE_QUA : TYPE_TRI, 1);
    _primaryFs = BasisFactory::getNodalBasis(tagPrimary);

    int tag = ElementType::getTag(_nCorner == 4 ? TYPE_QUA : TYPE_TRI, _order,
                                  incomplete);
    _fs = BasisFactory::getNodalBasis(tag);
    const fullMatrix<double> &refPoints = _fs->getReferenceNodes();
    for (int i = 0; i < nVerticesOnBoundary; ++i) {
      // FIXME Better idea?
      const double &u = refPoints(i, 0);
      const double &v = refPoints(i, 1);
      SVector3 t0, t1, n, h;
      baseFace.frame(u, v, t0, t1, n);
      MVertex *vBase = baseFace.getVertex(i);
      MVertex *vTop = topFace.getVertex(i);
      h = SVector3(vTop->x() - vBase->x(),
                   vTop->y() - vBase->y(),
                   vTop->z() - vBase->z());

      _thickness[i] = dot(h, n);
      _coeffb[i] = dot(h, t0);
      _coeffc[i] = dot(h, t1);
    }

    // Compute interior values for triangle (this is needed if we use complete
    // polynomial space to interpolate on triangles)
    if (_nCorner == 3) {
      const fullMatrix<double> *interpolator;
      interpolator = InteriorNodePlacementMatrices::forTriangle(_order, false);
      for (int i = nVerticesOnBoundary; i < sizeParameters; ++i) {
        for (int j = 0; j < interpolator->size2(); ++j) {
          const double coeff = (*interpolator)(i - nVerticesOnBoundary, j);
          _thickness[i] += coeff * _thickness[j];
          _coeffb[i] += coeff * _coeffb[j];
          _coeffc[i] += coeff * _coeffc[j];
        }
      }
    }

    // Reset factorDegenerate
    for (int i = 0; i < 4; ++i) {
      _factorDegenerate[i] = 1;
    }
  }

  SPoint3 Parameters3DSurface::computeIdealPositionTopFace(const MFaceN &baseFace,
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
    for (int j = 0; j < _fs->getNumShapeFunctions(); j++) {
      thickness += f[j] * _thickness[j];
      coeffb    += f[j] * _coeffb[j];
      coeffc    += f[j] * _coeffc[j];
    }

    _primaryFs->f(u, v, 0, f);

    double factorThickness = 0;
    for (int j = 0; j < _primaryFs->getNumShapeFunctions(); j++) {
      factorThickness += f[j] * _factorDegenerate[j];
    }

    return p + n * factorThickness * thickness
             + t0 * coeffb
             + t1 * coeffc;
  }

// compute adjacencies of boundary elements, thus of columns
  void computeAdjacencies(VecPairMElemVecMElem &bndEl2column,
                          std::vector<std::pair<int, int> > &adjacencies)
  {
    std::map<MEdge, int, Less_Edge> edge2element;
    for (unsigned int i = 0; i < bndEl2column.size(); ++i) {
      MElement *el = bndEl2column[i].first;
      for (unsigned int j = 0; j < el->getNumEdges(); ++j) {
        MEdge e = el->getEdge(j);
        std::map<MEdge, int, Less_Edge>::iterator it = edge2element.find(e);
        if (it != edge2element.end()) {
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
    int nVertices = f1.getNumVertices();
    if (f2.getNumVertices() != nVertices) return false;

    MVertex *v = f1.getVertex(0);

    // Find the vertex in f2
    int k = 0;
    while (k < nVertices && f2.getVertex(k) != v) ++k;
    if (k == nVertices) return false;

    // Just in case
    if (nVertices == 1) return true;

    // Determine which orientation
    int inc = 0;
    if (f2.getVertex((k+1)%nVertices) == f1.getVertex(1)) inc = 1;
    else if (f2.getVertex((k+nVertices-1)%nVertices) == f1.getVertex(1)) inc = -1;
    if (inc == 0) return false;

    for (int i = 2; i < nVertices; ++i) {
      if (f1.getVertex(i) != f2.getVertex((k+nVertices+inc*i) % nVertices))
        return false;
    }
    return true;
  }


  bool computeCommonFace(MElement *e1, MElement *e2, MFace &f)
  {
    for (int i = 0; i < e1->getNumFaces(); ++i) {
      f = e1->getFace(i);
      for (int j = 0; j < e2->getNumFaces(); ++j) {
        MFace f2 = e2->getFace(j);
        if (areSameFaces(f, f2)) return true;
      }
    }
    f = MFace();
    return false;
  }


  bool faceContainsVertex(MFace &f, MVertex *v)
  {
    for (int i = 0; i < f.getNumVertices(); ++i) {
      if (f.getVertex(i) == v) return true;
    }
    return false;
  }


  void computeStackPrimaryVertices(const PairMElemVecMElem &c1,
                                   std::vector<MVertex*> &stack)
  {
    int numVertexPerLayer = c1.first->getNumPrimaryVertices();
    unsigned int numLayers = c1.second.size();
    stack.assign(numVertexPerLayer * numLayers, NULL);

    int k = 0;
    for (int i = 0; i < numVertexPerLayer; ++i) {
      stack[k++] = c1.first->getVertex(i);
    }
    MFace bottomFace = c1.first->getFace(0);
    for (unsigned int i = 0; i < numLayers - 1; ++i) {
      MElement *currentElement = c1.second[i];
      MFace topFace;
      if (!computeCommonFace(currentElement, c1.second[i+1], topFace)) {
        Msg::Error("Did not find common face");
      }

      // Eeach edge that is not in bottom face nor in top face links a bottom
      // node with the corresponding top node
      for (int j = 0; j < currentElement->getNumEdges(); ++j) {
        MEdge edge = currentElement->getEdge(j);
        bool v0InBottomFace = faceContainsVertex(bottomFace, edge.getVertex(0));
        bool v1InBottomFace = faceContainsVertex(bottomFace, edge.getVertex(1));
        bool v0InTopFace = faceContainsVertex(topFace, edge.getVertex(0));
        bool v1InTopFace = faceContainsVertex(topFace, edge.getVertex(1));
        if (   (v0InBottomFace && v1InBottomFace)
               || (v0InTopFace && v1InTopFace)      ) continue;

        MVertex *vbot, *vtop;
        if (v0InBottomFace) {
          vbot = edge.getVertex(0);
          vtop = edge.getVertex(1);
        }
        else {
          vbot = edge.getVertex(1);
          vtop = edge.getVertex(0);
        }

        for (int l = k-numVertexPerLayer; l < k; ++l) {
          if (stack[l] == vbot) {
            stack[l+numVertexPerLayer] = vtop;
          }
        }
      }

      // If there remains NULL values, it is because the vertex is the same
      // on bottom face and top face.
      for (int l = k; l < k+numVertexPerLayer; ++l) {
        if (stack[l] == NULL) {
          stack[l] = stack[l-numVertexPerLayer];
        }
      }

      k += numVertexPerLayer;
      bottomFace = topFace;
    }
  }


  bool computeCommonEdge(MElement *el1, MElement *el2, MEdge &e)
  {
    for (int i = 0; i < el1->getNumEdges(); ++i) {
      e = el1->getEdge(i);
      for (int j = 0; j < el2->getNumEdges(); ++j) {
        MEdge thisEdge = el2->getEdge(j);
        if (thisEdge == e) return true;
      }
    }
  }


  void computeInterface(const PairMElemVecMElem &c1, const PairMElemVecMElem &c2,
                        std::vector<MFaceN> &interface, MEdgeN &bottomEdge,
                        MEdgeN &topEdge)
  {
    // Find common edge on boundary
    MElement *bottomElement1 = c1.first;
    MElement *bottomElement2 = c2.first;
    MEdge commonEdge;
    if (!computeCommonEdge(bottomElement1, bottomElement2, commonEdge)) {
      Msg::Error("Couldn't find common edge on bottom elements");
      return;
    }
    bottomEdge = bottomElement1->getHighOrderEdge(commonEdge);

    // Choose biggest column
    PairMElemVecMElem column;
    std::vector<MElement*> stackElements;
    MElement *bottomElement;
    if (c1.second.size() < c2.second.size()) {
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
    std::vector<MVertex*> allPrimaryVertices;
    computeStackPrimaryVertices(column, allPrimaryVertices);

    std::vector<MVertex*> interfacePrimaryVertices;
    {
      int nVertexPerLayer = bottomElement->getNumPrimaryVertices();
      int n0 = -1;
      int n1 = -1;
      for (int i = 0; i < nVertexPerLayer; ++i) {
        if (bottomEdge.getVertex(0) == allPrimaryVertices[i]) n0 = i;
        if (bottomEdge.getVertex(1) == allPrimaryVertices[i]) n1 = i;
      }
      if (n0 == -1 || n1 == -1) {
        Msg::Error("Error in computeInterface");
        return;
      }
      interfacePrimaryVertices.resize(2*(stackElements.size()));
      for (unsigned int i = 0; i < stackElements.size(); ++i) {
        interfacePrimaryVertices[2*i+0] = allPrimaryVertices[nVertexPerLayer*i+n0];
        interfacePrimaryVertices[2*i+1] = allPrimaryVertices[nVertexPerLayer*i+n1];
      }
    }

    // Compute interface
    interface.clear();
    for (int i = 0; i < stackElements.size() - 1; ++i) {
      MVertex *v0 = interfacePrimaryVertices[2*i+0];
      MVertex *v1 = interfacePrimaryVertices[2*i+1];
      MVertex *v2 = interfacePrimaryVertices[2*i+3];
      MVertex *v3 = interfacePrimaryVertices[2*i+2];
      if (v2 == v1 && v3 == v0) {
        Msg::Error("Error in computeInterface: not an element");
      }
      if (v2 == v1) {
        v2 = v3;
        v3 = NULL;
      }
      else if (v3 == v0) {
        v3 = NULL;
      }
      if (v3 == NULL) {
        interface.push_back(stackElements[i]->getHighOrderFace(MFace(v0, v1, v2)));
        if (   v0 != interface.back().getVertex(0)
               || v1 != interface.back().getVertex(1)
               || v2 != interface.back().getVertex(2))
          Msg::Error("did not get the faceN I wanted!");
//      std::cout << "vertices: " << v0->getNum() << " " << v1->getNum() << " " << v2->getNum() << std::endl;
//      std::cout << "vertices: " << interface.back().getVertex(0)->getNum() << " " << interface.back().getVertex(1)->getNum() << " ";
//      std::cout <<                 interface.back().getVertex(2)->getNum() << std::endl;
      }
      else {
        interface.push_back(stackElements[i]->getHighOrderFace(MFace(v0, v1, v2, v3)));
        if (   v0 != interface.back().getVertex(0)
               || v1 != interface.back().getVertex(1)
               || v2 != interface.back().getVertex(2)
               || v3 != interface.back().getVertex(3))
          Msg::Error("did not get the faceN I wanted!");
//      std::cout << "vertices: " << v0->getNum() << " " << v1->getNum() << " " << v2->getNum() << " " << v3->getNum() << std::endl;
//      std::cout << "vertices: " << interface.back().getVertex(0)->getNum() << " " << interface.back().getVertex(1)->getNum() << " ";
//      std::cout <<                 interface.back().getVertex(2)->getNum() << " " << interface.back().getVertex(3)->getNum() << std::endl;
      }
    }
    topEdge = interface.back().getHighOrderEdge(0, 1);
  }


  SVector3 getBisectorAtCommonCornerVertex(const MElement *surface1,
                                           const MElement *surface2,
                                           MVertex *corner)
  {
    // Assume that 't' is the tangent of the common edge between the two surfaces.
    // This function return the vector 'n' that is normal to 't' and such that
    // the plane generated by 't' and 'n' is the bisector plane of the two
    // surfaces at vertex 'corner'...
    int i1, i2;
    for (i1 = 0; i1 < surface1->getNumPrimaryVertices(); ++i1) {
      if (surface1->getVertex(i1) == corner) break;
    }
    for (i2 = 0; i2 < surface2->getNumPrimaryVertices(); ++i2) {
      if (surface2->getVertex(i2) == corner) break;
    }
    if (i1 > 3 || i2 > 3)
      Msg::Error("Incoherence for computeExtremityCoefficients");

    SVector3 n1, n2;

    double u, v, w;
    double gradients[3][3];

    surface1->getNode(i1, u, v, w);
    surface1->getJacobian(u, v, w, gradients);
    n1 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
//  Msg::Info("surf1 (%g, %g, %g)", u, v, w);

    surface2->getNode(i2, u, v, w);
    surface2->getJacobian(u, v, w, gradients);
    n2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
//  Msg::Info("surf2 (%g, %g, %g)", u, v, w);

    if (dot(n1, n2) < 0) {
      // This should never happen!
      Msg::Warning("Boundary elements have opposite normals (1) %d -- %d",
                   surface1->getNum(), surface2->getNum());
      // If really cannot prevent opposite normals, then  we should ideally
      // compare to the geometry normal or something... For now, arbitrarily
      // negate one of the normals.
      n1.negate();
    }

    n1.axpy(1, n2);
    n1.normalize();
    return n1;
  }


  void idealPositionEdge(const MElement *bottom1, const MElement *bottom2,
                         const MEdgeN &baseEdge,
                         const Parameters3DCurve &parameters,
                         int nbPoints, const IntPt *points,
                         fullMatrix<double> &xyz, int triDirection = 0,
                         GFace *gFace = NULL)
  {
//  static int ITER = 0;
//  ++ITER;
//  int MOD = 1;
//  int START = 0;

    for (int i = 0; i < nbPoints; ++i) {
      const double &u = points[i].pt[0];
      SPoint3 pnt = baseEdge.pnt(u);
      SVector3 t = baseEdge.tangent(u);

      SVector3 n;
      {
        double xyz[3], uvw[3];
        pnt.position(xyz);

        // TODO: more efficient function? (than xyz2uvw)
        double gradients[3][3];
        bottom1->xyz2uvw(xyz, uvw);
        bottom1->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        n = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);
        bottom2->xyz2uvw(xyz, uvw);
        bottom2->getJacobian(uvw[0], uvw[1], uvw[2], gradients);
        SVector3 n2 = SVector3(gradients[2][0], gradients[2][1], gradients[2][2]);

        if (dot(n, n2) < 0) {
          Msg::Warning("Boundary elements have opposite normals (2) %d -- %d",
                       bottom1->getNum(), bottom2->getNum());
          n.negate();
        }
        n.axpy(1, n2);
        n.normalize();
      }

      SVector3 w = crossprod(t, n);

//    if (ITER % MOD == START)
//      draw3DFrame(pnt, t, n, w, .25, gFace);

      int &d = triDirection;
      SVector3 h = parameters.thicknessAtPoint(u, d) * n
                   + parameters.coeffbAtPoint(u, d) * t
                   + parameters.coeffcAtPoint(u, d) * w;
      xyz(i, 0) = pnt.x() + h.x();
      xyz(i, 1) = pnt.y() + h.y();
      xyz(i, 2) = pnt.z() + h.z();
    }
  }


  void computePosition3DEdge(const MElement *bottom1, const MElement *bottom2,
                             const MEdgeN &baseEdge, MEdgeN &topEdge,
                             const Parameters3DCurve &parameters,
                             int triDirection, double dampingFactor,
                             GFace *gFace)
  {
    // Let (t, n, w) be the local reference frame on 'baseEdge'
    // where t(u) is the unit tangent of the 'baseEdge'
    //       n(u) is unit, normal to 't' and such that (t, n) is bisector of faces
    //            'bottom1' and 'bottom2' at corresponding point
    //       w = t x n
    // We seek for each component the polynomial function that fit the best
    //   x1(u) = x0(u) + h(u) * n(u) + b(u) * t(u) + c(u) * w(u)
    // in the least square sense.
    // where x0(u) is the position of 'baseEdge' and h, b, c are given by
    //       'parameters'

    const int orderCurve = baseEdge.getOrder();
    const int orderGauss = orderCurve * 2;
    const int sizeSystem = getNGQLPts(orderGauss);
    const IntPt *gaussPnts = getGQLPts(orderGauss);

    fullMatrix<double> xyz(sizeSystem + 2, 3);
    idealPositionEdge(bottom1, bottom2, baseEdge, parameters, sizeSystem,
                      gaussPnts, xyz, triDirection, gFace);
//  drawIdealPositionEdge(bottom1, bottom2, baseEdge, parameters, gFace, triDirection);
    for (int i = 0; i < 2; ++i) {
      MVertex *v = topEdge.getVertex(i);
      xyz(sizeSystem+i, 0) = v->x();
      xyz(sizeSystem+i, 1) = v->y();
      xyz(sizeSystem+i, 2) = v->z();
    }

    BoundaryLayerCurver::LeastSquareData *data =
        BoundaryLayerCurver::getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);
    fullMatrix<double> newxyz(orderCurve + 1, 3);
    data->invA.mult(xyz, newxyz);

    for (int i = 2; i < topEdge.getNumVertices(); ++i) {
      MVertex *v = topEdge.getVertex(i);
      v->x() = newxyz(i, 0);
      v->y() = newxyz(i, 1);
      v->z() = newxyz(i, 2);
    }
  }


  void computeExtremityCoefficients(const MElement *bottom1, const MElement *bottom2,
                                    const MEdgeN &baseEdge, const MEdgeN &topEdge,
                                    Parameters3DCurve &parameters)
  {
    MVertex *vBase, *vTop;
    SVector3 t, n, w, h;

    vBase = baseEdge.getVertex(0);
    vTop = topEdge.getVertex(0);
    t = baseEdge.tangent(-1);
    n = getBisectorAtCommonCornerVertex(bottom1, bottom2, vBase);
    w = crossprod(t, n);
    h = SVector3(vTop->x() - vBase->x(),
                 vTop->y() - vBase->y(),
                 vTop->z() - vBase->z());

    parameters.thickness[0] = dot(h, n);
    parameters.coeffb[0] = dot(h, t);
    parameters.coeffc[0] = dot(h, w);

    vBase = baseEdge.getVertex(1);
    vTop = topEdge.getVertex(1);
    t = baseEdge.tangent(1);
    n = getBisectorAtCommonCornerVertex(bottom1, bottom2, vBase);
    w = crossprod(t, n);
    h = SVector3(vTop->x() - vBase->x(),
                 vTop->y() - vBase->y(),
                 vTop->z() - vBase->z());

    parameters.thickness[1] = dot(h, n);
    parameters.coeffb[1] = dot(h, t);
    parameters.coeffc[1] = dot(h, w);
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
    if (std::abs(dY) > std::abs(dX)) {
      if (std::abs(dZ) > std::abs(dY)) componentToLookAt = 2;
      else componentToLookAt = 1;
    }
    else if(std::abs(dZ) > std::abs(dX)) componentToLookAt = 2;

    // Go trough the whole column and compute TFI position of topVertices
    for (int i = 1; i < (int)column.size() - 1; ++i) {
      MEdgeN e = column[i].getHighOrderEdge(0, 1);
      MVertex *v = e.getVertex(0);
      double factor;
      switch (componentToLookAt) {
        case 0: factor = (v->x() - vbot->x()) / dX; break;
        case 1: factor = (v->y() - vbot->y()) / dY; break;
        case 2: factor = (v->z() - vbot->z()) / dZ; break;
      }
      for (int j = 2; j < e.getNumVertices(); ++j) {
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
    for (unsigned int i = 0; i < column.size(); ++i) {
      MFaceN &f = column[i];
      const fullMatrix<double> *placement = NULL;
      if (f.isTriangular()) {
        // TODO Determine if edge 0 or 2
      }
      else {
        placement = InteriorNodePlacementMatrices::forQuadrangle(f.getOrder(), true);
      }
      f.repositionInteriorNodes(placement);
    }
  }


  bool curveInterface(std::vector<MFaceN> &column,
                      const MElement *bottom1, const MElement *bottom2,
                      const MEdgeN &baseEdge, MEdgeN &topEdge,
                      double dampingFactor, GFace *bndEnt,
                      bool linear)
  {
    // inspired from curve2DQuadColumnTFI

    Parameters3DCurve parameters;
    computeExtremityCoefficients(bottom1, bottom2, baseEdge, topEdge, parameters);
    computePosition3DEdge(bottom1, bottom2, baseEdge, topEdge, parameters,
                          0, dampingFactor, bndEnt);

    computePositionInteriorEdgesLinearTFI(column, baseEdge, topEdge);
    repositionInteriorNodes(column);
  }

// compute then curve interfaces between columns
  void curveInterfaces(VecPairMElemVecMElem &bndEl2column,
                       std::vector<std::pair<int, int> > &adjacencies,
                       GFace *boundary)
  {
    for (unsigned int i = 0; i < adjacencies.size(); ++i) {
      MEdgeN bottomEdge, topEdge;
      std::vector<MFaceN> interface;
      PairMElemVecMElem &column1 = bndEl2column[adjacencies[i].first];
      PairMElemVecMElem &column2 = bndEl2column[adjacencies[i].second];
//      bool doIt = true;
//    if (column1.first->getNum() != 861 && column1.first->getNum() != 467)
//      doIt = false;
//    if (column2.first->getNum() != 861 && column2.first->getNum() != 467)
//      doIt = false;

//      if (doIt) {
        computeInterface(column1, column2, interface, bottomEdge, topEdge);
        curveInterface(interface, column1.first, column2.first, bottomEdge,
                       topEdge, 0, boundary, true);
//      Msg::Error("RETURN"); return;
//      }
    }
  }


  void computeStackHighOrderFaces(const PairMElemVecMElem &bndEl2column,
                                  std::vector<MFaceN> &stack)
  {
    const std::vector<MElement*> &column = bndEl2column.second;
    stack.resize(column.size());

    std::vector<MVertex *> allPrimaryVertices;
    computeStackPrimaryVertices(bndEl2column, allPrimaryVertices);
    // FIXME already calculated in computeInterfaces. Reuse them?

    int nVertexPerLayer = bndEl2column.first->getNumPrimaryVertices();
    for (unsigned int j = 0; j < stack.size(); ++j) {
      MFace f;
      if (nVertexPerLayer == 3)
        f = MFace(allPrimaryVertices[j*3+0],
                  allPrimaryVertices[j*3+1],
                  allPrimaryVertices[j*3+2]);
      else
        f = MFace(allPrimaryVertices[j*4+0],
                  allPrimaryVertices[j*4+1],
                  allPrimaryVertices[j*4+2],
                  allPrimaryVertices[j*4+3]);
      stack[j] = column[j]->getHighOrderFace(f);
    }
  }

  void idealPositionFace(const MFaceN &baseFace,
                         const Parameters3DSurface &parameters,
                         int nbPoints, const IntPt *points,
                         fullMatrix<double> &xyz)
  {
    for (int i = 0; i < nbPoints; ++i) {
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
                             GFace *gFace)
  {
    // Let (t0, t1, n) be the local reference frame on 'baseFace'
    // We seek, for each component, the polynomial function that fit the best
    //   x1(u) = x0(u) + h(u) * n(u) + b(u) * t0(u) + c(u) * t1(u)
    // in the least square sense.
    // where x0(u) is the position of 'baseFace' and h, b, c are given by
    //       'parameters'

    if (baseFace.getType() == TYPE_TRI)
      return;

    const int orderSurface = baseFace.getOrder();
    const int orderGauss = orderSurface * 2;
    const int nVerticesBoundary = baseFace.getNumVerticesOnBoundary();
    int sizeSystem;
    IntPt *gaussPnts;
    if (baseFace.isTriangular()) {
      sizeSystem = getNGQTPts(orderGauss);
      gaussPnts = getGQTPts(orderGauss);
    }
    else {
      sizeSystem = getNGQQPts(orderGauss);
      gaussPnts = getGQQPts(orderGauss);
    }

    fullMatrix<double> xyz(sizeSystem + nVerticesBoundary, 3);
    idealPositionFace(baseFace, parameters, sizeSystem, gaussPnts, xyz);
    for (int i = 0; i < nVerticesBoundary; ++i) {
      MVertex *v = topFace.getVertex(i);
      xyz(sizeSystem+i, 0) = v->x();
      xyz(sizeSystem+i, 1) = v->y();
      xyz(sizeSystem+i, 2) = v->z();
    }

    BoundaryLayerCurver::LeastSquareData *data =
        BoundaryLayerCurver::getLeastSquareData(baseFace.getType(), orderSurface,
                                                orderGauss);
    fullMatrix<double> newxyz(data->invA.size1(), 3);
    data->invA.mult(xyz, newxyz);

    for (int i = nVerticesBoundary; i < topFace.getNumVertices(); ++i) {
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
    if (std::abs(dY) > std::abs(dX)) {
      if (std::abs(dZ) > std::abs(dY)) componentToLookAt = 2;
      else componentToLookAt = 1;
    }
    else if(std::abs(dZ) > std::abs(dX)) componentToLookAt = 2;

    // Go trough the whole column and compute TFI position of topVertices
    for (int i = 1; i < (int)column.size() - 1; ++i) {
      MFaceN &f = column[i];
      MVertex *v = f.getVertex(0);
      double factor;
      switch (componentToLookAt) {
        case 0: factor = (v->x() - vbot->x()) / dX; break;
        case 1: factor = (v->y() - vbot->y()) / dY; break;
        case 2: factor = (v->z() - vbot->z()) / dZ; break;
      }
      for (int j = f.getNumVerticesOnBoundary(); j < f.getNumVertices(); ++j) {
        MVertex *vbot = baseFace.getVertex(j);
        MVertex *vtop = topFace.getVertex(j);
        MVertex *v = f.getVertex(j);
        v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
        v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
        v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
      }
    }
  }

  void repositionInteriorNodes(MElement *el, const fullMatrix<double> &placement)
  {
    int start = el->getNumVertices() - el->getNumVolumeVertices();
    for (int i = start; i < el->getNumVertices(); ++i) {
      MVertex *v = el->getVertex(i);
      v->x() = 0;
      v->y() = 0;
      v->z() = 0;
      for (int j = 0; j < placement.size2(); ++j) {
        const double coeff = placement(i - start, j);
        MVertex *other = el->getVertex(j);
        v->x() += coeff * other->x();
        v->y() += coeff * other->y();
        v->z() += coeff * other->z();
      }
    }
  }

  void repositionInteriorNodes(const std::vector<MFaceN> &stackFaces,
                               const std::vector<MElement*> &column)
  {
    for (unsigned int i = 0; i < column.size(); ++i) {
      MElement *el = column[i];
      const fullMatrix<double> *placement = NULL;
      const int order = el->getPolynomialOrder();
      int nFace, sign, rot;
      switch(el->getType()) {
        case TYPE_TET:
//          placement = InteriorNodePlacementMatrices::forQuadrangle(order, true);
          break;
        case TYPE_HEX:
          el->getFaceInfo(stackFaces[i].getFace(), nFace, sign, rot);
          placement = InteriorNodePlacementMatrices::forHexahedron(order, true, nFace);
          break;
      }
      if (placement)
        repositionInteriorNodes(el, *placement);
      else
        Msg::Error("Implement placement for type %d", el->getType());
    }
  }

  void curveColumns(VecPairMElemVecMElem &bndEl2column,
                    GFace *boundary)
  {
    Parameters3DSurface parameters;
    for (unsigned int i = 0; i < bndEl2column.size(); ++i) {
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
}


void curve3DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, GFace *boundary)
{
  std::vector<std::pair<int, int> > adjacencies;
  BoundaryLayerCurver::computeAdjacencies(bndEl2column, adjacencies);

  BoundaryLayerCurver::curveInterfaces(bndEl2column, adjacencies, boundary);

  BoundaryLayerCurver::curveColumns(bndEl2column, boundary);

  for (int i = 0; i < bndEl2column.size(); ++i) {
    Msg::Info("el %d, size %d", bndEl2column[i].first->getNum(), bndEl2column[i].second.size());
  }
}
