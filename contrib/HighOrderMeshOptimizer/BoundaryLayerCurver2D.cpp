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
#include "orthogonalBasis.h"
#include "bezierBasis.h"
#include "gmshVertex.h"
#include "Geo.h"
#include "MLine.h"
#include "GModel.h"
#include "Options.h"
#include "AnalyseMeshQuality.h"
#include "InnerVertexPlacement.h"
#include "pointsGenerators.h"
#include "qualityMeasuresJacobian.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#endif

namespace {
  void drawEquidistantPoints(GEdge *gedge, int N)
  {
    return;
    const std::size_t numLine = gedge->getNumMeshElements();
    for(std::size_t i = 0; i < numLine; ++i) {
      gedge->getMeshElement(i)->setVisibility(0);
    }

    const double umin = gedge->getLowerBound();
    const double umax = gedge->getUpperBound();
    const double step = (umax - umin) / (N - 1);

    for(int i = 0; i < N; ++i) {
      const double u = umin + i * step;
      const GPoint p = gedge->point(u);
      MVertex *v = new MVertex(p.x(), p.y(), p.z());
      gedge->addMeshVertex(v);
      gedge->addLine(new MLine(v, v));
    }
  }

  void drawBezierControlPolygon(const bezierCoeff &controlPoints, GEdge *gedge)
  {
    const int nVert = controlPoints.getNumCoeff();

    MVertex *previous = nullptr;
    for(int i = 0; i < nVert; ++i) {
      MVertex *v = new MVertex(controlPoints(i, 0), controlPoints(i, 1),
                               controlPoints(i, 2), gedge);
      if(previous) {
        MLine *line = new MLine(v, previous);
        gedge->addLine(line);
      }
      gedge->addMeshVertex(v);
      previous = v;
    }
  }

  void drawBezierControlPolygon(const std::vector<MVertex *> &vertices,
                                GEdge *gedge = nullptr)
  {
    if(!gedge) { gedge = *GModel::current()->firstEdge(); }

    const int nVert = (int)vertices.size();
    fullMatrix<double> xyz(nVert, 3);
    for(int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }

    bezierCoeff *controlPoints =
      new bezierCoeff(FuncSpaceData(TYPE_LIN, nVert - 1, false), xyz);
    std::vector<bezierCoeff *> allControlPoints(1, controlPoints);

    int numSubdivision = 0; // change this to choose num subdivision
    while(numSubdivision-- > 0) {
      std::vector<bezierCoeff *> gatherSubs;
      for(std::size_t i = 0; i < allControlPoints.size(); ++i) {
        std::vector<bezierCoeff *> tmp;
        allControlPoints[i]->subdivide(tmp);
        gatherSubs.insert(allControlPoints.end(), tmp.begin(), tmp.end());
      }
      allControlPoints.swap(gatherSubs);
    }

    for(std::size_t i = 0; i < allControlPoints.size(); ++i) {
      drawBezierControlPolygon(*allControlPoints[i], gedge);
    }
  }

  void draw3DFrame(SPoint3 &p, SVector3 &t, SVector3 &n, SVector3 &w,
                   double unitDimension, GFace *gFace = nullptr)
  {
    return;
    if(!gFace) gFace = *GModel::current()->firstFace();

    MVertex *v = new MVertex(p.x(), p.y(), p.z(), gFace);

    SPoint3 pnt = p + n * unitDimension * .75;
    MVertex *vn = new MVertex(pnt.x(), pnt.y(), pnt.z(), gFace);

    pnt = p + w * unitDimension * 2;
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
} // namespace

namespace BoundaryLayerCurver {
  void projectVertexIntoGFace(MVertex *v, const GFace *gface)
  {
    SPoint3 p = v->point();
    SPoint2 param = gface->parFromPoint(p);
    GPoint projected = gface->point(param);
    v->x() = projected.x();
    v->y() = projected.y();
    v->z() = projected.z();
  }

  void projectVerticesIntoGFace(const MEdgeN *edge, const GFace *gface,
                                bool alsoExtremity = true)
  {
    int i = alsoExtremity ? 0 : 2;

    for(; i < edge->getNumVertices(); ++i)
      projectVertexIntoGFace(edge->getVertex(i), gface);
  }

  void projectVerticesIntoGFace(const MFaceN *face, const GFace *gface,
                                bool alsoBoundary = true)
  {
    int i = alsoBoundary ? 0 : face->getNumVerticesOnBoundary();

    for(; i < face->getNumVertices(); ++i)
      projectVertexIntoGFace(face->getVertex(i), gface);
  }

  namespace EdgeCurver2D {
    // TODO: smooth normals if CAD not available
    // TODO: check quality of elements

    _Frame::_Frame(const MEdgeN *edge, const GFace *gface, const GEdge *gedge,
                   const SVector3 &normal)
      : _normalToTheMesh(normal), _gface(gface), _gedge(gedge),
        _edgeOnBoundary(edge)
    {
      const int nVert = (int)edge->getNumVertices();

      if(gface) {
        for(int i = 0; i < nVert; ++i) {
          SPoint2 param;
          bool success =
            reparamMeshVertexOnFace(edge->getVertex(i), gface, param, true);
          _paramVerticesOnGFace[2 * i + 0] = param[0];
          _paramVerticesOnGFace[2 * i + 1] = param[1];
          if(!success) {
            Msg::Warning("Could not compute param of node %d on surface %d",
                         edge->getVertex(i)->getNum(), gface->tag());
          }
          // TODO: Check if periodic face
        }
      }

      if(gedge) {
        for(int i = nVert - 1; i >= 0; --i) {
          bool success = reparamMeshVertexOnEdge(edge->getVertex(i), gedge,
                                                 _paramVerticesOnGEdge[i]);
          if(!success) {
            Msg::Warning("Could not compute param of node %d on edge %d",
                         edge->getVertex(i)->getNum(), gedge->tag());
          }
          else if(gedge->periodic(0) && gedge->getBeginVertex() &&
                  edge->getVertex(i) ==
                    gedge->getBeginVertex()->mesh_vertices[0]) {
            double u0 = gedge->getLowerBound();
            double un = gedge->getUpperBound();
            int k = (nVert == 2 ? 1 - i : (i == 0 ? 2 : nVert - 1));
            double uk = _paramVerticesOnGEdge[k];
            _paramVerticesOnGEdge[i] = uk - u0 < un - uk ? u0 : un;
          }
        }
      }
    }

    void _Frame::computeFrame(double paramEdge, SVector3 &t, SVector3 &n,
                              SVector3 &w, bool atExtremity) const
    {
      if(_gedge) {
        double paramGeoEdge;
        if(atExtremity) {
          if(paramEdge < 0)
            paramGeoEdge = _paramVerticesOnGEdge[0];
          else
            paramGeoEdge = _paramVerticesOnGEdge[1];
        }
        else
          paramGeoEdge =
            _edgeOnBoundary->interpolate(_paramVerticesOnGEdge, paramEdge);

        t = _gedge->firstDer(paramGeoEdge);
        t.normalize();
      }
      if(!_gedge || t.norm() == 0) { t = _edgeOnBoundary->tangent(paramEdge); }

      if(_gface) {
        SPoint2 paramGFace;
        if(atExtremity) {
          if(paramEdge < 0)
            paramGFace =
              SPoint2(_paramVerticesOnGFace[0], _paramVerticesOnGFace[1]);
          else
            paramGFace =
              SPoint2(_paramVerticesOnGFace[2], _paramVerticesOnGFace[3]);
        }
        else {
          paramGFace = SPoint2(
            _edgeOnBoundary->interpolate(_paramVerticesOnGFace, paramEdge, 2),
            _edgeOnBoundary->interpolate(_paramVerticesOnGFace + 1, paramEdge,
                                         2));
        }
        w = _gface->normal(paramGFace);
      }
      else {
        w = _normalToTheMesh;
      }
      if(w.norm() == 0) {
        Msg::Error("normal to the CAD or 2Dmesh is nul. BL curving will fail.");
      }
      n = crossprod(w, t);
    }

    SPoint3 _Frame::pnt(double u) const
    {
      if(!_gedge) return SPoint3();

      double paramGeoEdge =
        _edgeOnBoundary->interpolate(_paramVerticesOnGEdge, u);
      GPoint p = _gedge->point(paramGeoEdge);
      return SPoint3(p.x(), p.y(), p.z());
    }

    void _computeParameters(const MEdgeN *baseEdge, const MEdgeN *otherEdge,
                            const _Frame &frame, double coeffs[2][3])
    {
      SVector3 t, n, w, h;
      MVertex *vb, *vt;

      frame.computeFrame(-1, t, n, w, true);
      vb = baseEdge->getVertex(0);
      vt = otherEdge->getVertex(0);
      h = SVector3(vt->x() - vb->x(), vt->y() - vb->y(), vt->z() - vb->z());
      coeffs[0][0] = dot(h, n);
      coeffs[0][1] = dot(h, t);
      coeffs[0][2] = dot(h, w);

      SPoint3 p1 = frame.pnt(-1);
      //      SPoint3 p1(vb->x(), vb->y(), vb->z());
      draw3DFrame(p1, t, n, w, .0004);

      frame.computeFrame(1, t, n, w, true);
      vb = baseEdge->getVertex(1);
      vt = otherEdge->getVertex(1);
      h = SVector3(vt->x() - vb->x(), vt->y() - vb->y(), vt->z() - vb->z());
      coeffs[1][0] = dot(h, n);
      coeffs[1][1] = dot(h, t);
      coeffs[1][2] = dot(h, w);
      //
      SPoint3 p2 = frame.pnt(1);
      //      SPoint3 p2(vb->x(), vb->y(), vb->z());
      draw3DFrame(p2, t, n, w, .0004);
    }

    void _idealPositionEdge(const MEdgeN *baseEdge, const _Frame &frame,
                            double coeffs[2][3], int nbPoints,
                            const IntPt *points, fullMatrix<double> &xyz)
    {
      for(int i = 0; i < nbPoints; ++i) {
        double u = points[i].pt[0];
        SPoint3 p = baseEdge->pnt(u);
        SVector3 t, n, w;
        frame.computeFrame(u, t, n, w);

        //        draw3DFrame(p, t, n, w, .0002);
        SPoint3 pp = frame.pnt(u);
        draw3DFrame(pp, t, n, w, .0002);

        double interpolatedCoeffs[3];
        for(int j = 0; j < 3; ++j) {
          interpolatedCoeffs[j] =
            coeffs[0][j] * (1 - u) / 2 + coeffs[1][j] * (1 + u) / 2;
        }
        SVector3 h;
        h = interpolatedCoeffs[0] * n + interpolatedCoeffs[1] * t +
            interpolatedCoeffs[2] * w;
        xyz(i, 0) = p.x() + h.x();
        xyz(i, 1) = p.y() + h.y();
        xyz(i, 2) = p.z() + h.z();
      }
    }

    void _drawIdealPositionEdge(const MEdgeN *baseEdge, const _Frame &frame,
                                double coeffs[2][3], GEdge *gedge)
    {
      int N = 100;
      MVertex *previous = nullptr;

      for(int i = 0; i < N + 1; ++i) {
        const double u = (double)i / N * 2 - 1;
        SPoint3 p = baseEdge->pnt(u);
        SVector3 t, n, w;
        frame.computeFrame(u, t, n, w);

        double interpolatedCoeffs[3];
        for(int j = 0; j < 3; ++j) {
          interpolatedCoeffs[j] =
            coeffs[0][j] * (1 - u) / 2 + coeffs[1][j] * (1 + u) / 2;
        }
        SVector3 h;
        h = interpolatedCoeffs[0] * n + interpolatedCoeffs[1] * t +
            interpolatedCoeffs[2] * w;
        double x = p.x() + h.x();
        double y = p.y() + h.y();
        double z = p.z() + h.z();

        MVertex *current = new MVertex(x, y, z, gedge);
        gedge->addMeshVertex(current);
        if(previous) {
          MLine *line = new MLine(previous, current);
          gedge->addLine(line);
        }
        //        MVertex *base = new MVertex(p.x(), p.y(), p.z(), gedge);
        //        MLine *line = new MLine(base, current);
        //        gedge->addLine(line);
        previous = current;
      }
    }

    void curveEdge(const MEdgeN *baseEdge, MEdgeN *edge, const GFace *gface,
                   const GEdge *gedge, const SVector3 &normal)
    {
      _Frame frame(baseEdge, gface, gedge, normal);

      double coeffs[2][3];
      _computeParameters(baseEdge, edge, frame, coeffs);

      const int orderCurve = baseEdge->getPolynomialOrder();
      const int orderGauss = orderCurve * 2;
      const int sizeSystem = getNGQLPts(orderGauss);
      const IntPt *gaussPnts = getGQLPts(orderGauss);

      // Least square projection
      fullMatrix<double> xyz(sizeSystem + 2, 3);
      _idealPositionEdge(baseEdge, frame, coeffs, sizeSystem, gaussPnts, xyz);
      //      _drawIdealPositionEdge(baseEdge, frame, coeffs, (GEdge*)gedge);
      for(int i = 0; i < 2; ++i) {
        xyz(sizeSystem + i, 0) = edge->getVertex(i)->x();
        xyz(sizeSystem + i, 1) = edge->getVertex(i)->y();
        xyz(sizeSystem + i, 2) = edge->getVertex(i)->z();
      }

      LeastSquareData *data =
        getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);
      fullMatrix<double> newxyz(orderCurve + 1, 3);
      data->invA.mult(xyz, newxyz);

      for(int i = 2; i < edge->getNumVertices(); ++i) {
        edge->getVertex(i)->x() = newxyz(i, 0);
        edge->getVertex(i)->y() = newxyz(i, 1);
        edge->getVertex(i)->z() = newxyz(i, 2);
      }

      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void _reduceCurving(MEdgeN *edge, double factor, const GFace *gface)
    {
      int order = edge->getPolynomialOrder();

      MVertex *v0 = edge->getVertex(0);
      MVertex *v1 = edge->getVertex(1);

      for(int i = 2; i < order + 1; ++i) {
        double f = (double)(i - 1) / order;
        MVertex *v = edge->getVertex(i);
        v->x() =
          (1 - factor) * v->x() + factor * ((1 - f) * v0->x() + f * v1->x());
        v->y() =
          (1 - factor) * v->y() + factor * ((1 - f) * v0->y() + f * v1->y());
        v->z() =
          (1 - factor) * v->z() + factor * ((1 - f) * v0->z() + f * v1->z());
      }
      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void _reduceOrderCurve(MEdgeN *edge, int order, const GFace *gface)
    {
      const int orderCurve = edge->getPolynomialOrder();
      const int orderGauss = order * 2;
      const int sizeSystem = getNGQLPts(orderGauss);
      const IntPt *gaussPnts = getGQLPts(orderGauss);

      // Least square projection
      fullMatrix<double> xyz(sizeSystem + 2, 3);
      for(int i = 0; i < sizeSystem; ++i) {
        SPoint3 p = edge->pnt(gaussPnts[i].pt[0]);
        xyz(i, 0) = p.x();
        xyz(i, 1) = p.y();
        xyz(i, 2) = p.z();
      }
      for(int i = 0; i < 2; ++i) {
        xyz(sizeSystem + i, 0) = edge->getVertex(i)->x();
        xyz(sizeSystem + i, 1) = edge->getVertex(i)->y();
        xyz(sizeSystem + i, 2) = edge->getVertex(i)->z();
      }

      LeastSquareData *data = getLeastSquareData(TYPE_LIN, order, orderGauss);
      fullMatrix<double> newxyzLow(order + 1, 3);
      data->invA.mult(xyz, newxyzLow);

      std::vector<MVertex *> vertices = edge->getVertices();
      vertices.resize(static_cast<std::size_t>(order) + 1);
      MEdgeN lowOrderEdge(vertices);

      for(std::size_t i = 2; i < vertices.size(); ++i) {
        vertices[i]->x() = newxyzLow(i, 0);
        vertices[i]->y() = newxyzLow(i, 1);
        vertices[i]->z() = newxyzLow(i, 2);
      }

      const int tagLine = ElementType::getType(TYPE_LIN, orderCurve);
      const nodalBasis *nb = BasisFactory::getNodalBasis(tagLine);
      const fullMatrix<double> &refpnts = nb->getReferenceNodes();

      fullMatrix<double> newxyz(edge->getNumVertices(), 3);
      for(std::size_t i = 2; i < edge->getNumVertices(); ++i) {
        SPoint3 p = lowOrderEdge.pnt(refpnts(i, 0));
        newxyz(i, 0) = p.x();
        newxyz(i, 1) = p.y();
        newxyz(i, 2) = p.z();
      }

      for(int i = 2; i < edge->getNumVertices(); ++i) {
        edge->getVertex(i)->x() = newxyz(i, 0);
        edge->getVertex(i)->y() = newxyz(i, 1);
        edge->getVertex(i)->z() = newxyz(i, 2);
      }

      if(gface) projectVerticesIntoGFace(edge, gface, false);
    }

    void recoverQualityElements(std::vector<MEdgeN> &stackEdges,
                                std::vector<MFaceN> &stackFaces,
                                std::vector<MElement *> &stackElements,
                                int iFirst, int iLast, const GFace *gface)
    {
      std::vector<MEdgeN> subsetEdges(4);
      subsetEdges[0] = stackEdges[0];
      subsetEdges[1] = stackEdges[iFirst];
      subsetEdges[2] = stackEdges[iLast - 1];
      subsetEdges[3] = stackEdges[iLast];
      MEdgeN *lastEdge = &stackEdges[iLast];
      std::vector<MFaceN> subsetFaces;
      subsetFaces.push_back(stackFaces[iLast - 1]);
      subsetFaces.push_back(stackFaces[iLast]);
      // Warning: subsetFaces should contain 2 faces since
      // repositionInnerVertices() need a column of BL faces + the exterior face

      // First get sure that last element of the BL is of good quality
      MElement *lastElementBL = stackElements[iLast - 1];
      MElement *linear = createPrimaryElement(lastElementBL);
      double qualLinear = jacobianBasedQuality::minIGEMeasure(linear);
      delete linear;

      InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, gface);
      repositionInnerVertices(subsetFaces, gface);
      double qual = jacobianBasedQuality::minIGEMeasure(lastElementBL);
      int currentOrder = lastEdge->getPolynomialOrder();
      while(qual < .75 && qual < .8 * qualLinear && currentOrder > 2) {
        _reduceOrderCurve(lastEdge, --currentOrder, gface);
        InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, gface);
        repositionInnerVertices(subsetFaces, gface);
        qual = jacobianBasedQuality::minIGEMeasure(lastElementBL);
      }
      int iter = 0;
      const int maxIter = 15;
      while(qual < .75 && qual < .8 * qualLinear && ++iter < maxIter) {
        _reduceCurving(lastEdge, .25, gface);
        InteriorEdgeCurver::curveEdges(subsetEdges, 1, 3, gface);
        repositionInnerVertices(subsetFaces, gface);
        qual = jacobianBasedQuality::minIGEMeasure(lastElementBL);
      }

      // Now, get sure the exterior element is of good quality
      MElement *lastElement = stackElements[iLast];
      linear = createPrimaryElement(lastElement);
      qualLinear = jacobianBasedQuality::minIGEMeasure(linear);
      delete linear;

      qual = jacobianBasedQuality::minIGEMeasure(lastElement);
      while(qual < .75 && qual < .8 * qualLinear && ++iter < maxIter) {
        _reduceCurving(lastEdge, .25, gface);
        repositionInnerVertices(subsetFaces, gface);
        qual = jacobianBasedQuality::minIGEMeasure(lastElement);
      }
      if(iter == maxIter) _reduceCurving(lastEdge, 1, gface);
    }
  } // namespace EdgeCurver2D

  namespace InteriorEdgeCurver {
    static std::map<std::pair<int, int>, TFIData *> tfiData;

    TFIData *_constructTFIData(int typeElement, int order)
    {
      TFIData *data = new TFIData;
      int nbDof = order + 1;

      fullMatrix<double> Mh; // lag coeff p n -> lag coeff p (n+1)
      fullMatrix<double> M0; // lag coeff p (n+1) c -> (1-xi) * c
      fullMatrix<double> M1; // lag coeff p (n+1) c ->    xi  * c
      fullMatrix<double> Ml; // lag coeff p (n+1) -> leg coeff p n
      fullMatrix<double> Me; // leg coeff p n -> lag coeff p n

      if(typeElement == TYPE_LIN) {
        int tagLine = ElementType::getType(TYPE_LIN, order);
        const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
        const fullMatrix<double> &refNodes = fs->getReferenceNodes();
        const fullMatrix<double> refNodesh = gmshGeneratePointsLine(order + 1);

        int nbDofh = refNodesh.size1();

        //      refNodesh.print("refNodesh");

        Mh.resize(nbDofh, nbDof);
        for(int i = 0; i < nbDofh; ++i) {
          double sf[100];
          fs->f(refNodesh(i, 0), refNodesh(i, 1), refNodesh(i, 2), sf);
          for(int j = 0; j < nbDof; ++j) { Mh(i, j) = sf[j]; }
        }
        //      Mh.print("Mh");

        M0.resize(nbDofh, nbDofh, true);
        M1.resize(nbDofh, nbDofh, true);
        for(int i = 0; i < nbDofh; ++i) {
          M0(i, i) = .5 - refNodesh(i, 0) / 2;
          M1(i, i) = .5 + refNodesh(i, 0) / 2;
        }
        //      M0.print("M0");
        //      M1.print("M1");

        Ml.resize(nbDof, nbDofh);
        {
          fullMatrix<double> vandermonde(nbDofh, nbDofh);

          double *val = new double[nbDofh];
          for(int i = 0; i < nbDofh; ++i) {
            LegendrePolynomials::fc(order + 1, refNodesh(i, 0), val);
            for(int j = 0; j < nbDofh; ++j) { vandermonde(i, j) = val[j]; }
          }
          delete val;

          fullMatrix<double> tmp;
          vandermonde.invert(tmp);
          //        vandermonde.print("vandermonde");
          //        tmp.print("tmp");
          Ml.copy(tmp, 0, nbDof, 0, nbDofh, 0, 0);
        }
        //      Ml.print("Ml");

        Me.resize(nbDof, nbDof);
        {
          double *val = new double[nbDof];
          for(int i = 0; i < nbDof; ++i) {
            LegendrePolynomials::fc(order, refNodes(i, 0), val);
            for(int j = 0; j < nbDof; ++j) { Me(i, j) = val[j]; }
          }
          delete val;
        }
        //      Me.print("Me");

        fullMatrix<double> tmp0(nbDofh, nbDof);
        fullMatrix<double> tmp1(nbDofh, nbDof);
        M0.mult(Mh, tmp0);
        M1.mult(Mh, tmp1);
        fullMatrix<double> tmp(nbDof, nbDofh);
        Me.mult(Ml, tmp);
        //      tmp.print("tmp");
        data->T0.resize(nbDof, nbDof);
        data->T1.resize(nbDof, nbDof);
        tmp.mult(tmp0, data->T0);
        tmp.mult(tmp1, data->T1);

        //      data->T0.print("data->T0");
        //      data->T1.print("data->T1");
      }

      //    fullVector<double> x(nbDof);
      //    x.setAll(1);
      //    fullVector<double> b1(nbDof);
      //    fullVector<double> b2(nbDof);
      //    data->T0.mult(x, b1);
      //    b1.print("b");
      //    data->T1.mult(x, b1);
      //    b1.print("b");
      //
      //    x(0) = 0;
      //    x(2) = 1/6.;
      //    x(3) = 2/6.;
      //    x(4) = 3/6.;
      //    x(5) = 4/6.;
      //    x(6) = 5/6.;
      //    x(1) = 1;
      //    data->T0.mult(x, b1);
      //    b1.print("b1");
      //    data->T1.mult(x, b2);
      //    b2.print("b2");
      //    b1.axpy(b2);
      //    b1.print("b");
      //
      //    x(0) = 0;
      //    x(2) = 0.000021433470508;
      //    x(3) = 0.001371742112483;
      //    x(4) = 0.015625000000000;
      //    x(5) = 0.087791495198903;
      //    x(6) = 0.334897976680384;
      //    x(1) = 1.000000000000000;
      //    data->T0.mult(x, b1);
      //    b1.print("b1");
      //    data->T1.mult(x, b2);
      //    b2.print("b2");
      //    b1.axpy(b2);
      //    b1.print("b");

      return data;
    }

    TFIData *_getTFIData(int typeElement, int order)
    {
      std::pair<int, int> typeOrder(typeElement, order);
      std::map<std::pair<int, int>, TFIData *>::iterator it;
      it = tfiData.find(typeOrder);

      if(it != tfiData.end()) return it->second;

      TFIData *data = _constructTFIData(typeElement, order);

      tfiData[typeOrder] = data;
      return data;
    }

    void _linearize(const fullMatrix<double> &x, fullMatrix<double> &lin)
    {
      int n = x.size1();
      lin.copy(x, 0, 2, 0, 3, 0, 0);
      for(int i = 2; i < n; ++i) {
        double fact = ((double)i - 1) / (n - 1);
        for(int j = 0; j < 3; ++j)
          lin(i, j) = (1 - fact) * x(0, j) + fact * x(1, j);
      }
    }

    void _computeEtas(const std::vector<MEdgeN> &stack,
                      std::vector<std::pair<double, double> > &eta)
    {
      eta.resize(stack.size());
      eta[0] = std::make_pair(0, 0);
      MVertex *vb0 = stack[0].getVertex(0);
      MVertex *vb1 = stack[0].getVertex(1);

      for(std::size_t i = 1; i < stack.size(); ++i) {
        MVertex *v0 = stack[i].getVertex(0);
        MVertex *v1 = stack[i].getVertex(1);
        eta[i].first = vb0->distance(v0);
        eta[i].second = vb1->distance(v1);
      }

      for(int i = 1; i < eta.size(); ++i) {
        eta[i].first /= eta.back().first;
        eta[i].second /= eta.back().second;
      }
    }

    void _computeDeltaForTFI(const std::vector<MEdgeN> &stack, int iFirst,
                             int iLast, fullMatrix<double> &delta0,
                             fullMatrix<double> &delta1,
                             fullMatrix<double> &deltaN)
    {
      const int numVertices = stack[0].getNumVertices();

      fullMatrix<double> x0(numVertices, 3);
      fullMatrix<double> x1(numVertices, 3);
      fullMatrix<double> xN(numVertices, 3);
      for(int k = 0; k < numVertices; ++k) {
        x0(k, 0) = stack[0].getVertex(k)->x();
        x0(k, 1) = stack[0].getVertex(k)->y();
        x0(k, 2) = stack[0].getVertex(k)->z();
        x1(k, 0) = stack[iFirst].getVertex(k)->x();
        x1(k, 1) = stack[iFirst].getVertex(k)->y();
        x1(k, 2) = stack[iFirst].getVertex(k)->z();
        xN(k, 0) = stack[iLast].getVertex(k)->x();
        xN(k, 1) = stack[iLast].getVertex(k)->y();
        xN(k, 2) = stack[iLast].getVertex(k)->z();
      }

      fullMatrix<double> x0linear(numVertices, 3);
      fullMatrix<double> x1linear(numVertices, 3);
      fullMatrix<double> xNlinear(numVertices, 3);
      _linearize(x0, x0linear);
      _linearize(x1, x1linear);
      _linearize(xN, xNlinear);
      delta0 = x0;
      delta0.add(x0linear, -1);
      delta1 = x1;
      delta1.add(x1linear, -1);
      deltaN = xN;
      deltaN.add(xNlinear, -1);
    }

    void _computeTerms(const fullMatrix<double> &delta0,
                       const fullMatrix<double> &delta1,
                       const fullMatrix<double> &deltaN, double eta1,
                       fullMatrix<double> terms[8])
    {
      fullMatrix<double> &term0 = terms[0];
      fullMatrix<double> &term1d10 = terms[1];
      fullMatrix<double> &term1d11 = terms[2];
      fullMatrix<double> &term1dN0 = terms[3];
      fullMatrix<double> &term1dN1 = terms[4];
      fullMatrix<double> &term20 = terms[5];
      fullMatrix<double> &term21 = terms[6];
      fullMatrix<double> &term22 = terms[7];

      const int numVertices = delta0.size1();

      fullMatrix<double> delta10 = delta1;
      delta10.add(delta0, -1);
      delta10.scale(1 / eta1);
      fullMatrix<double> deltaN0 = deltaN;
      deltaN0.add(delta0, -1);

      term0.resize(numVertices, 3);
      term1d10.resize(numVertices, 3);
      term1d11.resize(numVertices, 3);
      term1dN0.resize(numVertices, 3);
      term1dN1.resize(numVertices, 3);
      term20.resize(numVertices, 3);
      term21.resize(numVertices, 3);
      term22.resize(numVertices, 3);

      TFIData *tfiData = _getTFIData(TYPE_LIN, numVertices - 1);

      term0.copy(delta0);
      tfiData->T0.mult(delta10, term1d10);
      tfiData->T1.mult(delta10, term1d11);
      tfiData->T0.mult(deltaN0, term1dN0);
      tfiData->T1.mult(deltaN0, term1dN1);
      fullMatrix<double> diff(numVertices, 3);
      fullMatrix<double> dum0(numVertices, 3);
      fullMatrix<double> dum1(numVertices, 3);
      diff.copy(deltaN0);
      diff.add(delta10, -1);
      tfiData->T0.mult(diff, dum0);
      tfiData->T1.mult(diff, dum1);
      tfiData->T0.mult(dum0, term20);
      tfiData->T1.mult(dum0, term21);
      tfiData->T1.mult(dum1, term22);
    }

    void _generalTFI(std::vector<MEdgeN> &stack, int iLast,
                     const std::vector<std::pair<double, double> > &eta,
                     const fullMatrix<double> terms[8], double coeffHermite,
                     const GFace *gface)
    {
      // Let L() be the linear TFI transformation
      // Let H() be the semi-Hermite TFI transformation
      // This function return (1-coeffHermite) * L() + coeffHermite * H()

      const fullMatrix<double> &term0 = terms[0];
      const fullMatrix<double> &term1d10 = terms[1];
      const fullMatrix<double> &term1d11 = terms[2];
      const fullMatrix<double> &term1dN0 = terms[3];
      const fullMatrix<double> &term1dN1 = terms[4];
      const fullMatrix<double> &term20 = terms[5];
      const fullMatrix<double> &term21 = terms[6];
      const fullMatrix<double> &term22 = terms[7];

      int numVertices = stack[0].getNumVertices();

      for(std::size_t i = 1; i < stack.size(); ++i) {
        if(i == iLast) continue;
        // we want to change stack[iFirst] but not stack[iLast]

        fullMatrix<double> x(numVertices, 3);
        for(int j = 0; j < numVertices; ++j) {
          MVertex *v = stack[i].getVertex(j);
          x(j, 0) = v->x();
          x(j, 1) = v->y();
          x(j, 2) = v->z();
        }
        _linearize(x, x);

        double &c = coeffHermite;
        x.axpy(term0);
        x.axpy(term1d10, c * eta[i].first);
        x.axpy(term1d11, c * eta[i].second);
        x.axpy(term1dN0, (1 - c) * eta[i].first);
        x.axpy(term1dN1, (1 - c) * eta[i].second);
        x.axpy(term20, c * eta[i].first * eta[i].first);
        x.axpy(term21, c * 2 * eta[i].first * eta[i].second);
        x.axpy(term22, c * eta[i].second * eta[i].second);

        for(int j = 2; j < numVertices; ++j) {
          MVertex *v = stack[i].getVertex(j);
          v->x() = x(j, 0);
          v->y() = x(j, 1);
          v->z() = x(j, 2);
        }
        if(gface) projectVerticesIntoGFace(&stack[i], gface, false);
      }
    }

    void _computeEtaAndTerms(std::vector<MEdgeN> &stack, int iFirst, int iLast,
                             std::vector<std::pair<double, double> > &eta,
                             fullMatrix<double> terms[8])
    {
      // Compute eta_i^k, k=0,1
      _computeEtas(stack, eta);

      // Precompute Delta(x_i), i=0,1,n
      fullMatrix<double> delta0, delta1, deltaN;
      _computeDeltaForTFI(stack, iFirst, iLast, delta0, delta1, deltaN);

      // Compute terms
      double eta1 = .5 * (eta[iFirst].first + eta[iFirst].second);
      _computeTerms(delta0, delta1, deltaN, eta1, terms);
    }

    void curveEdges(std::vector<MEdgeN> &stack, int iFirst, int iLast,
                    const GFace *gface)
    {
      std::vector<std::pair<double, double> > eta;
      fullMatrix<double> terms[8];
      _computeEtaAndTerms(stack, iFirst, iLast, eta, terms);

      _generalTFI(stack, iLast, eta, terms, 1, gface);
    }

    void curveEdgesAndPreserveQuality(std::vector<MEdgeN> &stackEdges,
                                      std::vector<MFaceN> &stackFaces,
                                      std::vector<MElement *> &stackElements,
                                      int iFirst, int iLast, const GFace *gface)
    {
      std::vector<std::pair<double, double> > eta;
      fullMatrix<double> terms[8];
      _computeEtaAndTerms(stackEdges, iFirst, iLast, eta, terms);

      // Compute quality of primary elements
      unsigned long numElements = stackElements.size() - 1;
      std::vector<double> qualitiesLinear(numElements);
      for(std::size_t i = 0; i < numElements; ++i) {
        MElement *linear = createPrimaryElement(stackElements[i]);
        qualitiesLinear[i] = jacobianBasedQuality::minIGEMeasure(linear);
        delete linear;
      }

      static double coeffHermite[11] = {1,  .9, .8, .7, .6, .5,
                                        .4, .3, .2, .1, 0};
      for(int i = 0; i < 11; ++i) {
        _generalTFI(stackEdges, iLast, eta, terms, coeffHermite[i], gface);
        repositionInnerVertices(stackFaces, gface);

        bool allOk = true;
        if(coeffHermite[i]) {
          for(std::size_t i = 0; i < numElements; ++i) {
            double qual = jacobianBasedQuality::minIGEMeasure(stackElements[i]);
            if(qual < .5 && qual < .8 * qualitiesLinear[i]) {
              allOk = false;
              break;
            }
          }
        }

        if(allOk) return;
      }
    }
  } // namespace InteriorEdgeCurver

  MElement *createPrimaryElement(MElement *el)
  {
    int tagLinear = ElementType::getType(el->getType(), 1);
    std::vector<MVertex *> vertices;
    el->getVertices(vertices);
    MElementFactory f;
    return f.create(tagLinear, vertices, -1);
  }

  LeastSquareData *constructLeastSquareData(int typeElement, int order,
                                            int orderGauss)
  {
    // invM1 gives
    //     value of coefficients in Legendre basis
    //   + value of Lagrange multipliers
    // from
    //     Ij + value of function f at extremities
    // M2 gives
    //     Ij = integral of product function f with Legendre polynomial j
    //   + value of function f at extremities
    // from
    //     the values of function f at Gauss points
    //   + value of function f at extremities

    orthogonalBasis basis(typeElement, order);
    LeastSquareData *data = new LeastSquareData;

    if(typeElement == TYPE_LIN) {
      data->nbPoints = getNGQLPts(orderGauss);
      data->intPoints = getGQLPts(orderGauss);

      const int szSpace = order + 1;
      const int nGP = data->nbPoints;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace + 2, nGP + 2, true);
      {
        for(int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], 0, 0, val);
          for(int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        M2(szSpace, nGP) = M2(szSpace + 1, nGP + 1) = 1;
      }

      fullMatrix<double> M1(szSpace + 2, szSpace + 2, true);
      {
        basis.integralfSquared(val);
        for(int k = 0; k < szSpace; ++k) M1(k, k) = val[k];

        basis.f(-1, 0, 0, val);
        for(int k = 0; k < szSpace; ++k)
          M1(szSpace, k) = M1(k, szSpace) = val[k];

        basis.f(1, 0, 0, val);
        for(int k = 0; k < szSpace; ++k)
          M1(szSpace + 1, k) = M1(k, szSpace + 1) = val[k];
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        int tagLine = ElementType::getType(TYPE_LIN, order);
        const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
        const fullMatrix<double> &refNodes = fs->getReferenceNodes();
        for(int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), 0, 0, val);
          for(int j = 0; j < szSpace; ++j) { Leg2Lag(i, j) = val[j]; }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace + 2, nGP + 2, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP + 2, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP + 2, 0, 0);

      data->invA.resize(szSpace, nGP + 2, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }

    else if(typeElement == TYPE_QUA) {
      data->nbPoints = getNGQQPts(orderGauss);
      data->intPoints = getGQQPts(orderGauss);

      fullMatrix<double> refNodes = gmshGeneratePointsQuadrangle(order);

      const int szSpace = (order + 1) * (order + 1);
      const int nGP = data->nbPoints;
      const int nConstraint = 4 * order;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace + nConstraint, nGP + nConstraint, true);
      {
        for(int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], data->intPoints[j].pt[1], 0, val);
          for(int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        for(int i = 0; i < nConstraint; ++i) { M2(szSpace + i, nGP + i) = 1; }
      }

      fullMatrix<double> M1(szSpace + nConstraint, szSpace + nConstraint, true);
      {
        basis.integralfSquared(val);
        for(int k = 0; k < szSpace; ++k) M1(k, k) = val[k];

        for(int i = 0; i < nConstraint; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int k = 0; k < szSpace; ++k) {
            M1(szSpace + i, k) = M1(k, szSpace + i) = val[k];
          }
        }
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        for(int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int j = 0; j < szSpace; ++j) { Leg2Lag(i, j) = val[j]; }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace + nConstraint, nGP + nConstraint, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP + nConstraint, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP + nConstraint, 0, 0);

      data->invA.resize(szSpace, nGP + nConstraint, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }

    else if(typeElement == TYPE_TRI) {
      data->nbPoints = getNGQTPts(orderGauss);
      data->intPoints = getGQTPts(orderGauss);

      fullMatrix<double> refNodes = gmshGeneratePointsTriangle(order);

      const int szSpace = (order + 1) * (order + 2) / 2;
      const int nGP = data->nbPoints;
      const int nConstraint = 3 * order;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace + nConstraint, nGP + nConstraint, true);
      {
        for(int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], data->intPoints[j].pt[1], 0, val);
          for(int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        for(int i = 0; i < nConstraint; ++i) { M2(szSpace + i, nGP + i) = 1; }
      }

      fullMatrix<double> M1(szSpace + nConstraint, szSpace + nConstraint, true);
      {
        basis.integralfSquared(val);
        for(int k = 0; k < szSpace; ++k) M1(k, k) = val[k];

        for(int i = 0; i < nConstraint; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int k = 0; k < szSpace; ++k) {
            M1(szSpace + i, k) = M1(k, szSpace + i) = val[k];
          }
        }
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        for(int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for(int j = 0; j < szSpace; ++j) { Leg2Lag(i, j) = val[j]; }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace + nConstraint, nGP + nConstraint, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP + nConstraint, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP + nConstraint, 0, 0);

      data->invA.resize(szSpace, nGP + nConstraint, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }
  }

  LeastSquareData *getLeastSquareData(int typeElement, int order,
                                      int orderGauss)
  {
    TupleLeastSquareData typeOrder(typeElement,
                                   std::make_pair(order, orderGauss));
    std::map<TupleLeastSquareData, LeastSquareData *>::iterator it;
    it = leastSquareData.find(typeOrder);

    if(it != leastSquareData.end()) return it->second;

    LeastSquareData *data =
      constructLeastSquareData(typeElement, order, orderGauss);
    leastSquareData[typeOrder] = data;
    return data;
  }

  bool computeCommonEdge(MElement *el1, MElement *el2, MEdge &e)
  {
    for(int i = 0; i < el1->getNumEdges(); ++i) {
      e = el1->getEdge(i);
      for(int j = 0; j < el2->getNumEdges(); ++j) {
        MEdge e2 = el2->getEdge(j);
        if(e == e2) return true;
      }
    }
    e = MEdge();
    return false;
  }

  void compute2DstackPrimaryVertices(const PairMElemVecMElem &column,
                                     std::vector<MVertex *> &stack)
  {
    MElement *bottomElement = column.first;
    const std::vector<MElement *> &stackElements = column.second;
    int numVertexPerLayer = 2;
    unsigned long numLayers = stackElements.size();
    stack.assign(numVertexPerLayer * numLayers, nullptr);

    int k = 0;
    for(int i = 0; i < numVertexPerLayer; ++i) {
      stack[k++] = bottomElement->getVertex(i);
    }
    MEdge bottomEdge = bottomElement->getEdge(0);
    for(std::size_t i = 0; i < numLayers - 1; ++i) {
      MElement *currentElement = stackElements[i];
      MEdge topEdge;
      if(!computeCommonEdge(currentElement, stackElements[i + 1], topEdge)) {
        Msg::Error("Did not find common edge");
      }

      // Eeach edge that is not the bottom edge nor the top edge links a bottom
      // node with the corresponding top node
      for(int j = 0; j < currentElement->getNumEdges(); ++j) {
        MEdge edge = currentElement->getEdge(j);
        if(edge == bottomEdge || edge == topEdge) continue;

        MVertex *vbot, *vtop;
        if(edge.getVertex(0) == bottomEdge.getVertex(0) ||
           edge.getVertex(0) == bottomEdge.getVertex(1)) {
          vbot = edge.getVertex(0);
          vtop = edge.getVertex(1);
        }
        else {
          vbot = edge.getVertex(1);
          vtop = edge.getVertex(0);
        }

        for(int l = k - numVertexPerLayer; l < k; ++l) {
          if(stack[l] == vbot) { stack[l + numVertexPerLayer] = vtop; }
        }
      }

      // If there remains NULL values, it is because the vertex is the same
      // on bottom face and top face.
      for(int l = k; l < k + numVertexPerLayer; ++l) {
        if(stack[l] == nullptr) { stack[l] = stack[l - numVertexPerLayer]; }
      }

      k += numVertexPerLayer;
      bottomEdge = topEdge;
    }
  }

  void computeStackHOEdgesFaces(const PairMElemVecMElem &column,
                                std::vector<MEdgeN> &stackEdges,
                                std::vector<MFaceN> &stackFaces)
  {
    const std::vector<MElement *> &stackElements = column.second;
    const int numElements = (int)stackElements.size();
    stackEdges.resize(numElements);
    stackFaces.resize(numElements);

    std::vector<MVertex *> primVert;
    compute2DstackPrimaryVertices(column, primVert);

    for(std::size_t i = 0; i < numElements; ++i) {
      MEdge e(primVert[2 * i + 0], primVert[2 * i + 1]);
      stackEdges[i] = stackElements[i]->getHighOrderEdge(e);
    }
    for(std::size_t i = 0; i < numElements - 1; ++i) {
      MFace face;
      if(primVert[2 * i + 0] == primVert[2 * i + 2])
        face =
          MFace(primVert[2 * i + 1], primVert[2 * i + 0], primVert[2 * i + 3]);
      else if(primVert[2 * i + 1] == primVert[2 * i + 3])
        face =
          MFace(primVert[2 * i + 0], primVert[2 * i + 1], primVert[2 * i + 2]);
      else
        face = MFace(primVert[2 * i + 0], primVert[2 * i + 1],
                     primVert[2 * i + 3], primVert[2 * i + 2]);
      stackFaces[i] = stackElements[i]->getHighOrderFace(face);
    }
    // We don't care about the orientation of the last element
    stackFaces.back() = stackElements.back()->getHighOrderFace(0, 0, 0);
  }

  bool edgesShareVertex(MEdgeN *e0, MEdgeN *e1)
  {
    MVertex *v = e0->getVertex(0);
    MVertex *v0 = e1->getVertex(0);
    if(v == v0) return true;
    MVertex *v1 = e1->getVertex(1);
    if(v == v1) return true;
    v = e0->getVertex(1);
    if(v == v0) return true;
    if(v == v1) return true;
    return false;
  }

  void repositionInnerVertices(const std::vector<MFaceN> &stackFaces,
                               const GFace *gface)
  {
    if(stackFaces.empty()) return;

    int order = stackFaces[0].getPolynomialOrder();
    const fullMatrix<double> *placementTri, *placementQua, *placement;

    placementTri = InnerVertPlacementMatrices::triangle(order, true);
    placementQua = InnerVertPlacementMatrices::quadrangle(order, true);

    for(std::size_t i = 0; i < stackFaces.size() - 1; ++i) {
      const MFaceN &face = stackFaces[i];
      if(face.getType() == TYPE_QUA)
        face.repositionInnerVertices(placementQua);
      else
        face.repositionInnerVertices(placementTri);
      if(gface) projectVerticesIntoGFace(&face, gface, false);
    }

    if(stackFaces.back().getType() == TYPE_QUA) {
      placement = InnerVertPlacementMatrices::quadrangle(order, false);
    }
    else {
      placement = InnerVertPlacementMatrices::triangle(order, false);
    }
    stackFaces.back().repositionInnerVertices(placement);
    if(gface) projectVerticesIntoGFace(&stackFaces.back(), gface, false);
  }

  bool curve2Dcolumn(PairMElemVecMElem &column, const GFace *gface,
                     const GEdge *gedge, const SVector3 &normal)
  {
    // Here, either gface is defined and not normal, or the normal
    // is defined and not gface!

    if(column.second.size() < 2) return true;

    // Compute stack high order edges and faces
    std::vector<MEdgeN> stackEdges;
    std::vector<MFaceN> stackFaces;
    computeStackHOEdgesFaces(column, stackEdges, stackFaces);

    // Curve topEdge of first element and last edge
    int iFirst = 1, iLast = (int)stackEdges.size() - 1;
    MEdgeN *baseEdge = &stackEdges[0];
    MEdgeN *firstEdge = &stackEdges[iFirst];
    if(edgesShareVertex(baseEdge, firstEdge)) {
      iFirst = 2;
      firstEdge = &stackEdges[iFirst];
    }
    MEdgeN *topEdge = &stackEdges[iLast];

    EdgeCurver2D::curveEdge(baseEdge, firstEdge, gface, gedge, normal);
    EdgeCurver2D::curveEdge(baseEdge, topEdge, gface, gedge, normal);
    EdgeCurver2D::recoverQualityElements(stackEdges, stackFaces, column.second,
                                         iFirst, iLast, gface);

    // Curve interior edges and inner vertices
    InteriorEdgeCurver::curveEdgesAndPreserveQuality(
      stackEdges, stackFaces, column.second, iFirst, iLast, gface);
    return true;
  }

  void computeThicknessQuality(std::vector<MVertex *> &bottomVertices,
                               std::vector<MVertex *> &topVertices,
                               std::vector<double> &thickness, SVector3 &w)
  {
    int nVertices = (int)bottomVertices.size();
    int tagLine = ElementType::getType(TYPE_LIN, nVertices - 1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

    for(int i = 0; i < nVertices; ++i) {
      const MVertex *v0 = bottomVertices[i];
      const MVertex *v1 = topVertices[i];
      SVector3 t, n, h;
      h = SVector3(v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z());

      double xi = fs->points(i, 0);
      double xc = 0, yc = 0, zc = 0;
      double dx = 0, dy = 0, dz = 0;
      {
        double f[100];
        double sf[100][3];
        fs->f(xi, 0, 0, f);
        fs->df(xi, 0, 0, sf);
        for(int j = 0; j < fs->getNumShapeFunctions(); j++) {
          const MVertex *v = bottomVertices[j];
          xc += f[j] * v->x();
          yc += f[j] * v->y();
          zc += f[j] * v->z();
          dx += sf[j][0] * v->x();
          dy += sf[j][0] * v->y();
          dz += sf[j][0] * v->z();
        }
      }
      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);
      thickness.push_back(dot(h, n));
    }

    double t0 = thickness[0];
    double t1 = thickness[1];
    thickness[0] = 1;
    thickness[1] = 1;
    for(int j = 2; j < nVertices; ++j) {
      double fact = ((double)j - 1) / (nVertices - 1);
      double idealThickness = (1 - fact) * t0 + fact * t1;
      int sign = gmsh_sign(idealThickness);
      if(sign * thickness[j] < 0)
        thickness[j] = 0;
      else if(sign * thickness[j] < sign * idealThickness)
        thickness[j] = thickness[j] / idealThickness;
      else
        thickness[j] = idealThickness / thickness[j];
    }
  }

  void computeThicknessPView(MElement *el, SVector3 &w,
                             std::map<int, std::vector<double> > &data)
  {
    //    if (el->getType() == TYPE_QUA) {
    //      std::vector<MVertex *> bottomVertices, topVertices;
    //
    //      el->getEdgeVertices(0, bottomVertices);
    //      el->getEdgeVertices(2, topVertices);
    //      std::reverse(topVertices.begin(), topVertices.begin() + 2);
    //      std::reverse(topVertices.begin() + 2, topVertices.end());
    //
    //      std::vector<double> thickness[2];
    //      computeThicknessQuality(bottomVertices, topVertices, thickness[0],
    //      w); computeThicknessQuality(topVertices, bottomVertices,
    //      thickness[1], w);
    //
    //      std::map<int, double> v2q;
    //      v2q[0] = thickness[0][0];
    //      v2q[1] = thickness[0][1];
    //      v2q[2] = thickness[1][1];
    //      v2q[3] = thickness[1][0];
    //      int nEdgeVertex = (int)topVertices.size()-2;
    //      for (int i = 2; i < (int)thickness[0].size(); ++i) {
    //        v2q[4+i-2] = thickness[0][i];
    //        v2q[3+3*nEdgeVertex-i+2] = thickness[1][i];
    //      }
    //
    //      double q00 = v2q[0];
    //      double q10 = v2q[1];
    //      double q11 = v2q[2];
    //      double q01 = v2q[3];
    //      for (int i = 0; i < nEdgeVertex; ++i) {
    //        double fact = ((double)i+1)/(nEdgeVertex+1);
    //        v2q[4+nEdgeVertex+i]   = (1-fact) * q10 + fact * q11;
    //        v2q[4+3*nEdgeVertex+i] = (1-fact) * q01 + fact * q00;
    //      }
    //
    //      int tag = el->getTypeForMSH();
    //      InteriorPlacementData *pData;
    //      std::map<int, InteriorPlacementData*>::iterator it;
    //      it = interiorPlacementData.find(tag);
    //      if (it != interiorPlacementData.end()) pData = it->second;
    //      else {
    //        pData = constructInteriorPlacementData(tag);
    //        interiorPlacementData[tag] = pData;
    //      }
    //      for (int i = 0; i < pData->iToMove.size(); ++i) {
    //        int idx = pData->iToMove[i];
    //        double q0 = v2q[pData->i0[i]];
    //        double q1 = v2q[pData->i1[i]];
    //        v2q[idx] = pData->factor[i] * q0 + (1-pData->factor[i]) * q1;
    //      }
    //
    //      std::vector<double> &vData = data[el->getNum()];
    //      std::map<int, double>::iterator it2;
    //      for (it2 = v2q.begin(); it2 != v2q.end(); ++it2) {
    //        vData.push_back(it2->second);
    //      }
    //    }
  }
} // namespace BoundaryLayerCurver

void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, SVector3 normal,
                          const GEdge *gedge)
{
  double length = normal.normalize();
  if(length == 0) {
    Msg::Error("normal must be non-zero for boundary layer curving");
    return;
  }

  //  for (int i = 0; i < bndEl2column.size(); ++i) {
  //    bndEl2column[i].first->setVisibility(1);
  //    for (std::size_t j = 0; j < bndEl2column[i].second.size(); ++j) {
  //      bndEl2column[i].second[j]->setVisibility(1);
  //    }
  //  }

  for(int i = 0; i < bndEl2column.size(); ++i) {
    //    if (bndEl2column[i].first->getNum() != 205) continue; // t161
    //    if (bndEl2column[i].first->getNum() != 316) continue; // t161
    //    if (bndEl2column[i].first->getNum() != 1156) continue; // trimesh
    //    if (   bndEl2column[i].first->getNum() != 1156
    //        && bndEl2column[i].first->getNum() != 1079
    //        && bndEl2column[i].first->getNum() != 1102
    //        && bndEl2column[i].first->getNum() != 1119) continue;
    //    std::cout << std::endl;
    //    std::cout << "column " << bndEl2column[i].first->getNum() <<
    //    std::endl; if (bndEl2column[i].first->getNum() != 1079) continue; //
    //    Good if (bndEl2column[i].first->getNum() != 1078) continue; // Next to
    //    good if (bndEl2column[i].first->getNum() != 1099) continue; // Long on
    //    corner if (bndEl2column[i].first->getNum() != 1102) continue; // Bad
    //    HO if (bndEl2column[i].first->getNum() != 1136) continue; // Bad
    //    linear if (bndEl2column[i].first->getNum() != 1149) continue; //
    //    shorter if (bndEl2column[i].first->getNum() != 1150) continue; //
    //    concave if (bndEl2column[i].first->getNum() != 1151) continue; //
    //    symetric of concave if (bndEl2column[i].first->getNum() != 1156)
    //    continue; // Strange if (bndEl2column[i].first->getNum() != 1157)
    //    continue; // next to Strange
    BoundaryLayerCurver::curve2Dcolumn(bndEl2column[i], nullptr, gedge, normal);
  }
}

void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column,
                          const GFace *gface, const GEdge *gedge)
{
  if(!gface || !gedge) {
    Msg::Error("both gface and gedge are needed for boundary layer curving "
               "(%d, %d)",
               gface, gedge);
    return;
  }

  //  for (int i = 0; i < bndEl2column.size(); ++i) {
  //    bndEl2column[i].first->setVisibility(1);
  //    for (std::size_t j = 0; j < bndEl2column[i].second.size(); ++j) {
  //      bndEl2column[i].second[j]->setVisibility(1);
  //    }
  //  }

  for(int i = 0; i < bndEl2column.size(); ++i)
    BoundaryLayerCurver::curve2Dcolumn(bndEl2column[i], gface, gedge,
                                       SVector3());
}
