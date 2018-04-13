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
#include "orthogonalBasis.h"
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
#include "pointsGenerators.h"

namespace
{
  void drawAmplifiedDiffWithLin(const std::vector<MVertex *> &vertices,
                                GEntity *entity, double amp = 100,
                                bool drawBasisLines = false, int cnt = 100)
  {
    MLineN l(vertices);
    MVertex *v0 = vertices[0];
    MVertex *v1 = vertices[1];
    MVertex *previous = NULL;
    for (int i = 0; i < cnt; ++i) {
      double xi = -1 + 2 * i / (cnt - 1.);
      double c1 = i / (cnt - 1.);
      double c0 = 1 - c1;
      SPoint3 pLin(v0->x() * c0 + v1->x() * c1,
                   v0->y() * c0 + v1->y() * c1,
                   v0->z() * c0 + v1->z() * c1);
      SPoint3 p;
      l.pnt(xi, 0, 0, p);
      MVertex *vLin = new MVertex(pLin.x(), pLin.y(), pLin.z(), entity);
      MVertex *v = new MVertex(amp * p.x() - (amp - 1) * pLin.x(),
                               amp * p.y() - (amp - 1) * pLin.y(),
                               amp * p.z() - (amp - 1) * pLin.z(), entity);
      if (previous) {
        MLine *line = new MLine(v, previous);
        ((GEdge *) entity)->addLine(line);
      }
      if (drawBasisLines) {
        MLine *line = new MLine(v, vLin);
        ((GEdge *) entity)->addLine(line);
        ((GEdge *) entity)->addMeshVertex(vLin);
      }
      ((GEdge *) entity)->addMeshVertex(v);
      previous = v;
    }
  }

  void drawBezierControlPolygon(const fullMatrix<double> &controlPoints,
                                GEntity *entity)
  {
    const int nVert = controlPoints.size1();
    std::vector<int> idx(nVert);
    idx[0] = 0;
    for (int i = 1; i < nVert-1; ++i) idx[i] = i+1;
    idx[nVert-1] = 1;

    MVertex *previous = NULL;
    for (int i = 0; i < nVert; ++i) {
      MVertex *v = new MVertex(controlPoints(idx[i], 0), controlPoints(idx[i], 1),
                               controlPoints(idx[i], 2), entity);
      if (previous) {
        MLine *line = new MLine(v, previous);
        ((GEdge *) entity)->addLine(line);
      }
      ((GEdge *) entity)->addMeshVertex(v);
      previous = v;
    }
  }

  void drawBezierControlPolygon(const std::vector<MVertex *> &vertices,
                                GEntity *entity)
  {
    const int nVert = (int)vertices.size();
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);

    fullMatrix<double> xyz(nVert, 3);
    for (int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }
    fullMatrix<double> controlPoints(nVert, 3);
    fs->lag2Bez(xyz, controlPoints);

    bool subdivide = true;
    bool subdivide2 = true;
    if (subdivide) {
      fullMatrix<double> allSubs(2*nVert, 3);
      fs->subdivideBezCoeff(controlPoints, allSubs);
      fullMatrix<double> sub(nVert, 3);
      sub.copy(allSubs, 0, nVert, 0, 3, 0, 0);
      if (subdivide2) {
        fullMatrix<double> allSubs2(2*nVert, 3);
        fs->subdivideBezCoeff(sub, allSubs2);
        fullMatrix<double> sub2(nVert, 3);
        sub2.copy(allSubs2, 0, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
        sub2.copy(allSubs2, nVert, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
      }
      else
        drawBezierControlPolygon(sub, entity);
      sub.copy(allSubs, nVert, nVert, 0, 3, 0, 0);
      if (subdivide2) {
        fullMatrix<double> allSubs2(2*nVert, 3);
        fs->subdivideBezCoeff(sub, allSubs2);
        fullMatrix<double> sub2(nVert, 3);
        sub2.copy(allSubs2, 0, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
        sub2.copy(allSubs2, nVert, nVert, 0, 3, 0, 0);
        drawBezierControlPolygon(sub2, entity);
      }
      else
        drawBezierControlPolygon(sub, entity);
    }
    else {
      drawBezierControlPolygon(controlPoints, entity);
    }
  }

  void drawBezierDerivative(const std::vector<MVertex *> &vertices,
                            GEntity *entity, SPoint3 p, int *onlyN = NULL,
                            double fact = 1)
  {
    MVertex *v = new MVertex(p.x(), p.y(), p.z(), entity);
    MLine *line = new MLine(v, v);
    ((GEdge *) entity)->addLine(line);
    ((GEdge *) entity)->addMeshVertex(v);

    const int nVert = vertices.size();

    fullMatrix<double> controlPoints(nVert, 3);
    {
      const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);
      fullMatrix<double> xyz(nVert, 3);
      for (int i = 0; i < nVert; ++i) {
        xyz(i, 0) = vertices[i]->x();
        xyz(i, 1) = vertices[i]->y();
        xyz(i, 2) = vertices[i]->z();
      }
      fs->lag2Bez(xyz, controlPoints);
    }

    fullMatrix<double> deriv(nVert, 3);
    deriv(0, 0) = controlPoints(0, 0);
    deriv(0, 1) = controlPoints(0, 1);
    deriv(0, 2) = controlPoints(0, 2);
    for (int i = 1; i < nVert-1; ++i) {
      deriv(i, 0) = controlPoints(i+1, 0);
      deriv(i, 1) = controlPoints(i+1, 1);
      deriv(i, 2) = controlPoints(i+1, 2);
    }
    deriv(nVert-1, 0) = controlPoints(1, 0);
    deriv(nVert-1, 1) = controlPoints(1, 1);
    deriv(nVert-1, 2) = controlPoints(1, 2);
    deriv.scale(fact);

    for (int n = nVert - 1; n > 0; --n) {
      for (int i = 0; i < n; ++i) {
        deriv(i, 0) = deriv(i+1, 0) - deriv(i, 0);
        deriv(i, 1) = deriv(i+1, 1) - deriv(i, 1);
        deriv(i, 2) = deriv(i+1, 2) - deriv(i, 2);
      }
      deriv.scale(n);
      fullMatrix<double> controlPointsDeriv(n, 3);
      controlPointsDeriv(0, 0) = p.x() + deriv(0, 0);
      controlPointsDeriv(0, 1) = p.y() + deriv(0, 1);
      controlPointsDeriv(0, 2) = p.z() + deriv(0, 2);
      controlPointsDeriv(1, 0) = p.x() + deriv(n-1, 0);
      controlPointsDeriv(1, 1) = p.y() + deriv(n-1, 1);
      controlPointsDeriv(1, 2) = p.z() + deriv(n-1, 2);
      for (int i = 2; i < n; ++i) {
        controlPointsDeriv(i, 0) = p.x() + deriv(i-1, 0);
        controlPointsDeriv(i, 1) = p.y() + deriv(i-1, 1);
        controlPointsDeriv(i, 2) = p.z() + deriv(i-1, 2);
      }
      if (!onlyN || *onlyN == n) {
        bool subdivide = true;
        bool subdivide2 = true;
        if (subdivide) {
          const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, n-1);
          fullMatrix<double> allSubs(2*n, 3);
          fs->subdivideBezCoeff(controlPointsDeriv, allSubs);
          fullMatrix<double> sub(n, 3);
          sub.copy(allSubs, 0, n, 0, 3, 0, 0);
          if (subdivide2) {
            fullMatrix<double> allSubs2(2*n, 3);
            fs->subdivideBezCoeff(sub, allSubs2);
            fullMatrix<double> sub2(n, 3);
            sub2.copy(allSubs2, 0, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
            sub2.copy(allSubs2, n, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
          }
          else
            drawBezierControlPolygon(sub, entity);
          sub.copy(allSubs, n, n, 0, 3, 0, 0);
          if (subdivide2) {
            fullMatrix<double> allSubs2(2*n, 3);
            fs->subdivideBezCoeff(sub, allSubs2);
            fullMatrix<double> sub2(n, 3);
            sub2.copy(allSubs2, 0, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
            sub2.copy(allSubs2, n, n, 0, 3, 0, 0);
            drawBezierControlPolygon(sub2, entity);
          }
          else
            drawBezierControlPolygon(sub, entity);
        }
        else {
          drawBezierControlPolygon(controlPointsDeriv, entity);
        }
      }
    }
  }

  void drawAngleChange(const std::vector<MVertex *> &vertices,
                       GEntity *entity, SVector3 w, double fact = 1)
  {
    const int nVert = vertices.size();

    fullMatrix<double> controlPoints(nVert, 3);
    {
      const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);
      fullMatrix<double> xyz(nVert, 3);
      for (int i = 0; i < nVert; ++i) {
        xyz(i, 0) = vertices[i]->x();
        xyz(i, 1) = vertices[i]->y();
        xyz(i, 2) = vertices[i]->z();
      }
      fs->lag2Bez(xyz, controlPoints);
    }
//    controlPoints.print("controlPoints");

    fullMatrix<double> deriv1(nVert-1, 3);
    fullMatrix<double> deriv2(nVert-2, 3);
    for (int j = 0; j < 3; ++j) {
      deriv1(0, j) = controlPoints(2, j) - controlPoints(0, j);
      deriv1(1, j) = controlPoints(1, j) - controlPoints(nVert-1, j);
      for (int i = 2; i < nVert-1; ++i) {
        deriv1(i, j) = controlPoints(i+1, j) - controlPoints(i, j);
      }
      deriv1.scale(nVert-1);
      deriv2(0, j) = deriv1(2, j) - deriv1(0, j);
      deriv2(1, j) = deriv1(1, j) - deriv1(nVert-2, j);
      for (int i = 2; i < nVert-2; ++i) {
        deriv2(i, j) = deriv1(i+1, j) - deriv1(i, j);
      }
      deriv2.scale(nVert-2);
    }
//    deriv1.print("deriv1");
//    deriv2.print("deriv2");

    fullMatrix<double> points(2*nVert-4, 3);
    {
      fullMatrix<double> interp1;
      fullMatrix<double> interp2;
      const int order = 2 * nVert - 5;
      fullMatrix<double> refPoints = gmshGeneratePointsLine(order);
//      refPoints.print("refPoints");
      const bezierBasis *fs1 = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 2);
      const bezierBasis *fs2 = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 3);
      fs1->interpolate(deriv1, refPoints, interp1);
      fs2->interpolate(deriv2, refPoints, interp2);
//      interp1.print("interp1");
//      interp2.print("interp2");

      fullVector<double> angleChangeBez(order+1);
      for (int i = 0; i < order+1; ++i) {
        angleChangeBez(i) = interp1(i, 0) * interp2(i, 1)
                          - interp1(i, 1) * interp2(i, 0);
//        angleChangeBez(i) /= interp1(i, 0) * interp1(i, 0)
//                           + interp1(i, 1) * interp1(i, 1);
      }
//      angleChangeBez.print("angleChangeBez");

      fullVector<double> angleChange(order+1);
      const bezierBasis *fs3 = BasisFactory::getBezierBasis(TYPE_LIN, order);
      fs3->matrixBez2Lag.mult(angleChangeBez, angleChange);
      angleChange.scale(fact);
//      angleChange.print("angleChange");

      const bezierBasis *fs0 = BasisFactory::getBezierBasis(TYPE_LIN, 1);
      fs0->interpolate(controlPoints, refPoints, points);

      SVector3 v = SVector3(vertices[1]->x() - vertices[0]->x(),
                            vertices[1]->y() - vertices[0]->y(),
                            vertices[1]->z() - vertices[0]->z());
      SVector3 n = crossprod(w, v).unit();
      for (int i = 0; i < 2*nVert-4; ++i) {
        points(i, 0) += n.x() * angleChange(i);
        points(i, 1) += n.y() * angleChange(i);
        points(i, 2) += n.z() * angleChange(i);
      }
    }
//    points.print("points");

    std::vector<MVertex*> newVert(2*nVert-4);
    for (int i = 0; i < (int)newVert.size(); ++i) {
      newVert[i] = new MVertex(points(i, 0), points(i, 1), points(i, 2));
    ((GEdge *) entity)->addMeshVertex(newVert[i]);
    }
    MLineN *line = new MLineN(newVert);
    ((GEdge *) entity)->addLine(line);

    {
      MLine *line = new MLine(vertices[0], vertices[1]);
      ((GEdge *) entity)->addLine(line);
      line = new MLine(vertices[0], newVert[0]);
      ((GEdge *) entity)->addLine(line);
      line = new MLine(vertices[1], newVert[1]);
      ((GEdge *) entity)->addLine(line);
    }
  }

  void drawBezierOffsets(fullMatrix<double> controlPoints,
                         GEdge *entity, SPoint3 p, double fact = 1)
  {
    MVertex *v = new MVertex(p.x(), p.y(), p.z(), entity);
    entity->addLine(new MLine(v, v));
    entity->addMeshVertex(v);

    int order = controlPoints.size1() - 1;
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, order);

    controlPoints.scale(fact);
    for (int i = 0; i < order + 1; ++i) {
      controlPoints(i, 0) += p.x();
      controlPoints(i, 1) += p.y();
      controlPoints(i, 2) += p.z();
    }

    fullMatrix<double> xyz(order+1, 3);
    fs->matrixBez2Lag.mult(controlPoints, xyz);

    std::vector<MVertex *> vertices(order + 1);
    for (int i = 0; i < order + 1; ++i) {
      vertices[i] = new MVertex(xyz(i, 0), xyz(i, 1), xyz(i, 2));
      entity->addMeshVertex(vertices[i]);
    }

    MLineN *line = new MLineN(vertices);
    entity->addLine(line);

    MVertex *previous = NULL;
    int idx[100];
    idx[0] = 0;
    idx[order] = 1;
    for (int i = 1; i < order; ++i) {
      idx[i] = i+1;
    }
    for (int i = 0; i < order + 1; ++i) {
      MVertex *v = new MVertex(controlPoints(idx[i], 0), controlPoints(idx[i], 1), controlPoints(idx[i], 2));
      if (previous) {
        MLine *line = new MLine(v, previous);
        entity->addLine(line);
        entity->addMeshVertex(v);
      }
      previous = v;
    }
  }

  void drawIdealCurve(const std::vector<MVertex *> &baseVert,
                      BoundaryLayerCurver::Parameters2DCurve &parameters,
                      SVector3 w, GEntity *entity, bool drawVertLines = false,
                      bool drawh = true,
                      bool drawn = false, bool drawt = false, int cnt = 100)
  {
    int tagLine = ElementType::getTag(TYPE_LIN, baseVert.size() - 1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

    MVertex *vh0 = NULL;
    MVertex *vn0 = NULL;
    MVertex *vt0 = NULL;

    for (int i = 0; i < cnt; ++i) {
      double xi = -1 + 2 * i / (cnt - 1.);
      double xc = 0, yc = 0, zc = 0;
      double dx = 0, dy = 0, dz = 0;
      {
        double f[100];
        double sf[100][3];
        fs->f(xi, 0, 0, f);
        fs->df(xi, 0, 0, sf);
        for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
          const MVertex *v = baseVert[j];
          xc += f[j] * v->x();
          yc += f[j] * v->y();
          zc += f[j] * v->z();
          dx += sf[j][0] * v->x();
          dy += sf[j][0] * v->y();
          dz += sf[j][0] * v->z();
        }
      }
      SVector3 t, n, h;
      double x, y, z;
      MVertex *v;
      MLine *line;
      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);

      if (drawh) {
        h = parameters.thicknessAtPoint(xi) * n +
            parameters.coeffbAtPoint(xi) * t;
        x = xc + h.x();
        y = yc + h.y();
        z = zc + h.z();
        v = new MVertex(x, y, z, entity);
        ((GEdge *) entity)->addMeshVertex(v);
        if (vh0) {
          line = new MLine(v, vh0);
          ((GEdge *) entity)->addLine(line);
        }
        if (drawVertLines) {
          MVertex *vbase = new MVertex(xc, yc, zc, entity);
          line = new MLine(vbase, v);
          ((GEdge *) entity)->addLine(line);
        }
        vh0 = v;
      }

      if (drawn) {
        h = parameters.thicknessAtPoint(xi) * n;
        x = xc + h.x();
        y = yc + h.y();
        z = zc + h.z();
        v = new MVertex(x, y, z, entity);
        if (vn0) {
          line = new MLine(v, vn0);
          ((GEdge *) entity)->addLine(line);
        }
        if (drawVertLines) {
          MVertex *vbase = new MVertex(xc, yc, zc, entity);
          line = new MLine(vbase, v);
          ((GEdge *) entity)->addLine(line);
        }
        ((GEdge *) entity)->addMeshVertex(v);
        vn0 = v;
      }

      if (drawt) {
        h = parameters.coeffbAtPoint(xi) * t;
        x = xc + h.x();
        y = yc + h.y();
        z = zc + h.z();
        v = new MVertex(x, y, z, entity);
        if (vt0) {
          line = new MLine(v, vt0);
          ((GEdge *) entity)->addLine(line);
        }
        ((GEdge *) entity)->addMeshVertex(v);
        vt0 = v;
      }
    }
  }

  void drawMLineN(const std::vector<MVertex *> &vertices_, GEdge *ent,
                  bool newHOvert = false)
  {
    std::vector<MVertex *> vertices = vertices_;
    if (newHOvert) {
      for (int j = 2; j < vertices.size(); ++j) {
        MVertex *v = vertices[j];
        vertices[j] = new MVertex(v->x(), v->y(), v->z());
        ent->addMeshVertex(vertices[j]);
      }
    }
    MLineN *line = new MLineN(vertices);
    ent->addLine(line);
  }

  /*             A
   *             *
   *           ,/ \
   *       c ,/    \ b
   *       ,/       \
   *     ,/          \
   *    *-------------*
   *  B        a        C
   */

  bool solveASDtriangle(double angleB, const SVector3 &sideA,
                        const SVector3 &dirSideB, double &lengthSideB,
                        const SVector3 &w, bool positiveLengths = true)
  {
    // Assuming:
    // - angleB is the signed angle from a to c in range [-pi, pi]
    // - sideA is the vector from B to C
    // - dirSideB is a vector from C in the direction of A
    // positiveLengths=true implies that all angles have to be of the same sign
    if (dirSideB.norm() < 1e-12) return false;
    if (std::abs(angleB) > M_PI) {
      Msg::Warning("angle greater than pi in solveASDtriangle");
    }
    int sign = gmsh_sign(angleB);

    double angleC = signedAngle(dirSideB, -sideA, w);
    if (positiveLengths && sign * angleC < 0) return false;

    double angleA = sign * M_PI - angleB - angleC;
    if (std::abs(angleA) < 1e-12) return false;
    if (positiveLengths && (sign * angleA < 0 || sign * angleA > M_PI)) return false;

    lengthSideB = sideA.norm() / std::sin(angleA) * std::sin(angleB);
    return true;
  }

  bool solveLSDtriangle(double lengthSideC, const SVector3 &sideA,
                        const SVector3 &dirSideB, double &lengthSideB,
                        const SVector3 &w)
  {
    // Assuming:
    // - sideA is the vector from B to C
    // - dirSideB is a vector from C in the direction of A
    // - positive lengths, i.e. all angles have to be of the same sign
    // - lengthSideC > length(sideA). Otherwise, ambiguous (0, 1 or 2 solutions)
    if (lengthSideC < sideA.norm()) return false;
    if (dirSideB.norm() < 1e-12) return false;

    double angleC = signedAngle(dirSideB, -sideA, w);
    int sign = gmsh_sign(angleC);

    double sinAngleA = sideA.norm() / lengthSideC * std::sin(angleC);
    double angleA = std::asin(sinAngleA);

    double angleB = sign * M_PI - angleA - angleC;
    lengthSideB = sideA.norm() / sinAngleA * std::sin(angleB);
    if (lengthSideB < 0) std::cout << "AARRAFGAGGAE" << std::endl;
    // TODO remove this
    return true;
  }
}

namespace BoundaryLayerCurver
{
  static std::map<int, InteriorPlacementData*> interiorPlacementData;
  static std::map<std::pair<int, int>, TFIData*> tfiData;

  LeastSquareData* constructLeastSquareData(int typeElement, int order,
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

    if (typeElement == TYPE_LIN) {
      data->nbPoints = getNGQLPts(orderGauss);
      data->intPoints = getGQLPts(orderGauss);

      const int szSpace = order + 1;
      const int nGP = data->nbPoints;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace+2, nGP+2, true);
      {
        for (int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], 0, 0, val);
          for (int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        M2(szSpace, nGP) = M2(szSpace+1, nGP+1) = 1;
      }

      fullMatrix<double> M1(szSpace+2, szSpace+2, true);
      {
        basis.integralfSquared(val);
        for (int k = 0; k < szSpace; ++k)
          M1(k, k) = val[k];

        basis.f(-1, 0, 0, val);
        for (int k = 0; k < szSpace; ++k)
          M1(szSpace, k) = M1(k, szSpace) = val[k];

        basis.f( 1, 0, 0, val);
        for (int k = 0; k < szSpace; ++k)
          M1(szSpace+1, k) = M1(k, szSpace+1) = val[k];
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        int tagLine = ElementType::getTag(TYPE_LIN, order);
        const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
        const fullMatrix<double> &refNodes = fs->getReferenceNodes();
        for (int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), 0, 0, val);
          for (int j = 0; j < szSpace; ++j) {
            Leg2Lag(i, j) = val[j];
          }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace+2, nGP+2, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP+2, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP+2, 0, 0);

      data->invA.resize(szSpace, nGP+2, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }

    else if (typeElement == TYPE_QUA) {
      data->nbPoints = getNGQQPts(orderGauss);
      data->intPoints = getGQQPts(orderGauss);

      fullMatrix<double> refNodes = gmshGeneratePointsQuadrangle(order);

      const int szSpace = (order + 1) * (order + 1);
      const int nGP = data->nbPoints;
      const int nConstraint = 4 * order;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace+nConstraint, nGP+nConstraint, true);
      {
        for (int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], data->intPoints[j].pt[1], 0, val);
          for (int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        for (int i = 0; i < nConstraint; ++i) {
          M2(szSpace+i, nGP+i) = 1;
        }
      }

      fullMatrix<double> M1(szSpace+nConstraint, szSpace+nConstraint, true);
      {
        basis.integralfSquared(val);
        for (int k = 0; k < szSpace; ++k)
          M1(k, k) = val[k];

        for (int i = 0; i < nConstraint; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for (int k = 0; k < szSpace; ++k) {
            M1(szSpace+i, k) = M1(k, szSpace+i) = val[k];
          }
        }
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        for (int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for (int j = 0; j < szSpace; ++j) {
            Leg2Lag(i, j) = val[j];
          }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace+nConstraint, nGP+nConstraint, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP+nConstraint, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP+nConstraint, 0, 0);

      data->invA.resize(szSpace, nGP+nConstraint, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }

    else if (typeElement == TYPE_TRI) {
      data->nbPoints = getNGQTPts(orderGauss);
      data->intPoints = getGQTPts(orderGauss);

      fullMatrix<double> refNodes = gmshGeneratePointsTriangle(order);

      const int szSpace = (order + 1) * (order + 2) / 2;
      const int nGP = data->nbPoints;
      const int nConstraint = 3 * order;

      double *val = new double[szSpace];

      fullMatrix<double> M2(szSpace+nConstraint, nGP+nConstraint, true);
      {
        for (int j = 0; j < nGP; ++j) {
          basis.f(data->intPoints[j].pt[0], data->intPoints[j].pt[1], 0, val);
          for (int i = 0; i < szSpace; ++i) {
            M2(i, j) = val[i] * data->intPoints[j].weight;
          }
        }
        for (int i = 0; i < nConstraint; ++i) {
          M2(szSpace+i, nGP+i) = 1;
        }
      }

      fullMatrix<double> M1(szSpace+nConstraint, szSpace+nConstraint, true);
      {
        basis.integralfSquared(val);
        for (int k = 0; k < szSpace; ++k)
          M1(k, k) = val[k];

        for (int i = 0; i < nConstraint; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for (int k = 0; k < szSpace; ++k) {
            M1(szSpace+i, k) = M1(k, szSpace+i) = val[k];
          }
        }
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(szSpace, szSpace, true);
      {
        for (int i = 0; i < szSpace; ++i) {
          basis.f(refNodes(i, 0), refNodes(i, 1), 0, val);
          for (int j = 0; j < szSpace; ++j) {
            Leg2Lag(i, j) = val[j];
          }
        }
      }

      delete val;

      fullMatrix<double> tmp(szSpace+nConstraint, nGP+nConstraint, false);
      invM1.mult(M2, tmp);
      fullMatrix<double> tmp2(szSpace, nGP+nConstraint, false);
      tmp2.copy(tmp, 0, szSpace, 0, nGP+nConstraint, 0, 0);

      data->invA.resize(szSpace, nGP+nConstraint, false);
      Leg2Lag.mult(tmp2, data->invA);
      return data;
    }
  }

  LeastSquareData* getLeastSquareData(int typeElement, int order,
                                      int orderGauss)
  {
    TupleLeastSquareData typeOrder(typeElement, std::make_pair(order, orderGauss));
    std::map<TupleLeastSquareData, LeastSquareData*>::iterator it;
    it = leastSquareData.find(typeOrder);

    if (it != leastSquareData.end()) return it->second;

    LeastSquareData *data = constructLeastSquareData(typeElement, order,
                                                     orderGauss);
    leastSquareData[typeOrder] = data;
    return data;
  }

  TFIData* constructTFIData(int typeElement, int order)
  {
    TFIData *data = new TFIData;
    int nbDof = order+1;

    fullMatrix<double> Mh; // lag coeff p n -> lag coeff p (n+1)
    fullMatrix<double> M0; // lag coeff p (n+1) c -> (1-xi) * c
    fullMatrix<double> M1; // lag coeff p (n+1) c ->    xi  * c
    fullMatrix<double> Ml; // lag coeff p (n+1) -> leg coeff p n
    fullMatrix<double> Me; // leg coeff p n -> lag coeff p n

    if (typeElement == TYPE_LIN) {
      int tagLine = ElementType::getTag(TYPE_LIN, order);
      const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
      const fullMatrix<double> &refNodes = fs->getReferenceNodes();
      int tagLineh = ElementType::getTag(TYPE_LIN, order+1);
      // FIXME replace with BasisFactory::getNodalBasis(funcSpaceData);
      const nodalBasis *fsh = BasisFactory::getNodalBasis(tagLineh);
      const fullMatrix<double> &refNodesh = fsh->getReferenceNodes();

      int nbDofh = refNodesh.size1();

//      refNodesh.print("refNodesh");

      Mh.resize(nbDofh, nbDof);
      for (int i = 0; i < nbDofh; ++i) {
        double sf[100];
        fs->f(refNodesh(i, 0), refNodesh(i, 1), refNodesh(i, 2), sf);
        for (int j = 0; j < nbDof; ++j) {
          Mh(i, j) = sf[j];
        }
      }
//      Mh.print("Mh");

      M0.resize(nbDofh, nbDofh, true);
      M1.resize(nbDofh, nbDofh, true);
      for (int i = 0; i < nbDofh; ++i) {
        M0(i, i) = .5 - refNodesh(i, 0) / 2;
        M1(i, i) = .5 + refNodesh(i, 0) / 2;
      }
//      M0.print("M0");
//      M1.print("M1");

      Ml.resize(nbDof, nbDofh);
      {
        fullMatrix<double> vandermonde(nbDofh, nbDofh);

        double *val = new double[nbDofh];
        for (int i = 0; i < nbDofh; ++i) {
          LegendrePolynomials::fc(order+1, refNodesh(i,0), val);
          for (int j = 0; j < nbDofh; ++j) {
            vandermonde(i, j) = val[j];
          }
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
        for (int i = 0; i < nbDof; ++i) {
          LegendrePolynomials::fc(order, refNodes(i, 0), val);
          for (int j = 0; j < nbDof; ++j) {
            Me(i, j) = val[j];
          }
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

  TFIData* getTFIData(int typeElement, int order)
  {
    std::pair<int, int> typeOrder(typeElement, order);
    std::map<std::pair<int, int>, TFIData*>::iterator it;
    it = tfiData.find(typeOrder);

    if (it != tfiData.end()) return it->second;

    TFIData *data = constructTFIData(typeElement, order);

    tfiData[typeOrder] = data;
    return data;
  }

  void computeExtremityCoefficients(const std::vector<MVertex*> &baseVert,
                                    const std::vector<MVertex*> &damped,
                                    const std::vector<MVertex*> &topVert,
                                    Parameters2DCurve &parameters,
                                    SVector3 w)
  {
    int tagLine = ElementType::getTag(TYPE_LIN, baseVert.size() - 1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
    double sf[100][3];

    SVector3 t, n, h;
    {
      double dx = 0, dy = 0, dz = 0;
      fs->df(-1, 0, 0, sf);
      for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
        const MVertex *v = damped[j];
        dx += sf[j][0] * v->x();
        dy += sf[j][0] * v->y();
        dz += sf[j][0] * v->z();
      }

      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);
      h = SVector3(topVert[0]->x() - baseVert[0]->x(),
                   topVert[0]->y() - baseVert[0]->y(),
                   topVert[0]->z() - baseVert[0]->z());
    }
    parameters.thickness[0] = dot(h, n);
    parameters.coeffb[0] = dot(h, t);

    {
      double dx = 0, dy = 0, dz = 0;
      fs->df(1, 0, 0, sf);
      for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
        const MVertex *v = damped[j];
        dx += sf[j][0] * v->x();
        dy += sf[j][0] * v->y();
        dz += sf[j][0] * v->z();
      }

      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);
      h = SVector3(topVert[1]->x() - baseVert[1]->x(),
                   topVert[1]->y() - baseVert[1]->y(),
                   topVert[1]->z() - baseVert[1]->z());
    }
    parameters.thickness[1] = dot(h, n);
    parameters.coeffb[1] = dot(h, t);
  }

  void idealPositionEdge(const std::vector<MVertex *> &baseVert,
                         const std::vector<MVertex *> &damped,
                         Parameters2DCurve &parameters, SVector3 w,
                         int nbPoints, const IntPt *points,
                         fullMatrix<double> &xyz, GEntity *bndEnt,
                         int triDirection = 0)
  {
    int tagLine = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

//    drawIdealCurve(baseVert, parameters, w, bndEnt);

    for (int i = 0; i < nbPoints; ++i) {
      double xi = points[i].pt[0];
      double xc = 0, yc = 0, zc = 0;
      double dx = 0, dy = 0, dz = 0;
      {
        double f[100];
        double sf[100][3];
        fs->f(xi, 0, 0, f);
        fs->df(xi, 0, 0, sf);
        for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
          const MVertex *v = baseVert[j];
          const MVertex *vDamped = damped[j];
          xc += f[j] * v->x();
          yc += f[j] * v->y();
          zc += f[j] * v->z();
          dx += sf[j][0] * vDamped->x();
          dy += sf[j][0] * vDamped->y();
          dz += sf[j][0] * vDamped->z();
        }
      }
      SVector3 t, n, h;
      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);
      int &d = triDirection;
      h = parameters.thicknessAtPoint(xi, d) * n
          + parameters.coeffbAtPoint(xi, d) * t;
      xyz(i, 0) = xc + h.x();
      xyz(i, 1) = yc + h.y();
      xyz(i, 2) = zc + h.z();
    }
  }

  double computeDampingDirections(const fullMatrix<double> &controlPoints,
                                  fullMatrix<double> &directions)
  {
    const int nVert = controlPoints.size1();

    std::vector<int> idx(nVert);
    idx[0] = 0;
    for (int i = 1; i < nVert-1; ++i) idx[i] = i+1;
    idx[nVert-1] = 1;

    directions(idx[0], 0) = 0;
    directions(idx[0], 1) = 0;
    directions(idx[0], 2) = 0;
    directions(idx[nVert-1], 0) = 0;
    directions(idx[nVert-1], 1) = 0;
    directions(idx[nVert-1], 2) = 0;
    for (int k = 1; k < nVert-1; ++k) {
      for (int j = 0; j < 3; ++j)
        directions(idx[k], j) = .25 * controlPoints(idx[k-1], j) +
                                .25 * controlPoints(idx[k+1], j) -
                                .5 * controlPoints(idx[k], j);
    }

    double maxDisplacement = 0;
    bool subdivide = true;
    bool subdivide2 = true;
    if (subdivide) {
      const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);
      fullMatrix<double> allSubs(2*nVert, 3);
      fs->subdivideBezCoeff(directions, allSubs);
      if (subdivide2) {
        fullMatrix<double> sub(nVert, 3);
        sub.copy(allSubs, 0, nVert, 0, 3, 0, 0);
        fullMatrix<double> allSubs2(2*nVert, 3);
        fs->subdivideBezCoeff(sub, allSubs2);
        for (int i = 0; i < allSubs2.size1(); ++i) {
          double displacement = std::sqrt(allSubs2(i, 0) * allSubs2(i, 0) +
                                          allSubs2(i, 1) * allSubs2(i, 1) +
                                          allSubs2(i, 2) * allSubs2(i, 2));
          maxDisplacement = std::max(maxDisplacement, displacement);
        }
        sub.copy(allSubs, nVert, nVert, 0, 3, 0, 0);
        fs->subdivideBezCoeff(sub, allSubs2);
        for (int i = 0; i < allSubs2.size1(); ++i) {
          double displacement = std::sqrt(allSubs2(i, 0) * allSubs2(i, 0) +
                                          allSubs2(i, 1) * allSubs2(i, 1) +
                                          allSubs2(i, 2) * allSubs2(i, 2));
          maxDisplacement = std::max(maxDisplacement, displacement);
        }
      }
      else {
        for (int i = 0; i < allSubs.size1(); ++i) {
          double displacement = std::sqrt(allSubs(i, 0) * allSubs(i, 0) +
                                          allSubs(i, 1) * allSubs(i, 1) +
                                          allSubs(i, 2) * allSubs(i, 2));
          maxDisplacement = std::max(maxDisplacement, displacement);
        }
      }

      double maxDisplacementNoSub = 0;
      for (int i = 2; i < nVert; ++i) {
        double displacement = std::sqrt(directions(i, 0) * directions(i, 0) +
                                        directions(i, 1) * directions(i, 1) +
                                        directions(i, 2) * directions(i, 2));
        maxDisplacementNoSub = std::max(maxDisplacementNoSub, displacement);
      }
//      std::cout << "max disp: " << maxDisplacementNoSub << " " << maxDisplacement << std::endl;
    }
    else {
      for (int i = 2; i < nVert; ++i) {
        double displacement = std::sqrt(directions(i, 0) * directions(i, 0) +
                                        directions(i, 1) * directions(i, 1) +
                                        directions(i, 2) * directions(i, 2));
        maxDisplacement = std::max(maxDisplacement, displacement);
      }
    }
    return maxDisplacement;
  }

  double computeLinearDirections(const fullMatrix<double> &controlPoints,
                                 fullMatrix<double> &directions)
  {
    const int nVert = controlPoints.size1();

    std::vector<double> xi(nVert);
    xi[0] = 0;
    xi[1] = 1;
    for (int i = 2; i < nVert; ++i) xi[i] = (double)(i-1) / (nVert-1);

    for (int i = 2; i < nVert; ++i) {
      for (int j = 0; j < 3; ++j)
        directions(i, j) = (1-xi[i]) * controlPoints(0, j) +
                              xi[i]  * controlPoints(1, j) -
                                       controlPoints(i, j);
    }

    double maxDisplacement = 0;
    for (int i = 2; i < nVert; ++i) {
      double displacement = std::sqrt(directions(i, 0) * directions(i, 0) +
                                      directions(i, 1) * directions(i, 1) +
                                      directions(i, 2) * directions(i, 2));
      maxDisplacement = std::max(maxDisplacement, displacement);
    }
    return maxDisplacement;
  }

  double dampingBezierControlPoints(fullMatrix<double> &controlPoints, double limit)
  {
    const int nVert = controlPoints.size1();
    fullMatrix<double> dCtrlPnts(nVert, 3);
    double maxDisplacement = computeDampingDirections(controlPoints, dCtrlPnts);

    if (maxDisplacement > limit)
      dCtrlPnts.scale(limit / maxDisplacement);
    // TODO go to linear in other case??

    controlPoints.add(dCtrlPnts);
    return maxDisplacement > limit ? limit : maxDisplacement;
  }

  void bezierOffset(const std::vector<MVertex *> &baseVert,
                    fullMatrix<double> &controlPts,
                    Parameters2DCurve &parameters, SVector3 &w,
                    GEntity *bndEnt,
                    int triDirection = 0)
  {
    int tagLine = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

    int nbPoints = (int)baseVert.size();

    fullMatrix<double> dn(nbPoints, 3), dt(nbPoints, 3);
    Msg::Info(" ");
    for (int i = 0; i < nbPoints; ++i) {
      double xi = 2 * (double)(i-1) / (nbPoints - 1) - 1;
      if (i == 0) xi = -1;
      if (i == 1) xi = 1;
      double dx = 0, dy = 0, dz = 0;
      {
        double sf[100][3];
        fs->df(xi, 0, 0, sf);
        for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
          const MVertex *v = baseVert[j];
          dx += sf[j][0] * v->x();
          dy += sf[j][0] * v->y();
          dz += sf[j][0] * v->z();
        }
      }
      SVector3 t, n, h, nn, tt;
      t = SVector3(dx, dy, dz).unit();
      n = crossprod(w, t);
      int &d = triDirection;
//      h = parameters.thicknessAtPoint(xi, d) * n
//          + parameters.coeffbAtPoint(xi, d) * t;
      nn = parameters.thicknessAtPoint(xi, d) * n;
      tt = parameters.coeffbAtPoint(xi, d) * t;
      dn(i, 0) = nn.x(); dn(i, 1) = nn.y(); dn(i, 2) = nn.z();
      dt(i, 0) = tt.x(); dt(i, 1) = tt.y(); dt(i, 2) = tt.z();
//      controlPts(i, 0) += h.x();
//      controlPts(i, 1) += h.y();
//      controlPts(i, 2) += h.z();
    }
    if (true) {
      for (int i = 0; i < nbPoints; ++i) {
        controlPts(i, 0) += dn(i, 0) + dt(i, 0);
        controlPts(i, 1) += dn(i, 1) + dt(i, 1);
        controlPts(i, 2) += dn(i, 2) + dt(i, 2);
      }
    }
    else {
      dn.print("dn");
      dt.print("dt");
      static double x = 0;
      static double prevmaxdxn = 0;
      static double prevmaxdxt = 0;
      double maxdyn = 0;
      double maxdyt = 0;
      double maxdxn = 0;
      double maxdxt = 0;
      for (int i = 0; i < nbPoints; ++i) {
        maxdyn = std::max(maxdyn, -dn(i, 1));
        maxdyt = std::max(maxdyt, dt(i, 1));
        maxdxn = std::max(maxdxn, -dn(i, 0));
        maxdxt = std::max(maxdxt, -dt(i, 0));
      }
      x += 1.5 * std::max(prevmaxdxn, prevmaxdxt);
      drawBezierOffsets(dn, (GEdge*)bndEnt, SPoint3(x, -5, 0));
      double dy = - 1.5*(maxdyn+maxdyt);
      dy = -.05;
      drawBezierOffsets(dt, (GEdge*)bndEnt, SPoint3(x, -5 + dy, 0));

      std::cout << "limit:" << parameters.characteristicThickness() << std::endl;
      double dep = 0;
      dep = dampingBezierControlPoints(dt, .1*parameters.characteristicThickness());
      std::cout << "dep:" << dep/parameters.characteristicThickness() << std::endl;
      dep = dampingBezierControlPoints(dt, .1*parameters.characteristicThickness());
      std::cout << "dep:" << dep/parameters.characteristicThickness() << std::endl;
      dep = dampingBezierControlPoints(dt, .1*parameters.characteristicThickness());
      std::cout << "dep:" << dep/parameters.characteristicThickness() << std::endl;
      dep = dampingBezierControlPoints(dt, .1*parameters.characteristicThickness());
      std::cout << "dep:" << dep/parameters.characteristicThickness() << std::endl;
      dep = dampingBezierControlPoints(dt, .1*parameters.characteristicThickness());
      std::cout << "dep:" << dep/parameters.characteristicThickness() << std::endl;
      for (int i = 0; i < nbPoints; ++i) {
        controlPts(i, 0) += dn(i, 0) + dt(i, 0);
        controlPts(i, 1) += dn(i, 1) + dt(i, 1);
        controlPts(i, 2) += dn(i, 2) + dt(i, 2);
      }
      drawBezierOffsets(dt, (GEdge*)bndEnt, SPoint3(x, -5 + dy, 0));

      x += 1.5 * std::max(maxdxn, maxdxt);
      prevmaxdxn = 0;
      prevmaxdxt = 0;
      for (int i = 0; i < nbPoints; ++i) {
        prevmaxdxn = std::max(maxdxn, dn(i, 0));
        prevmaxdxt = std::max(maxdxt, dt(i, 0));
      }

      static double prevMaxNormn = 0;
      static double prevMaxNormt = 0;
      double maxNormn = 0;
      double maxNormt = 0;
      for (int i = 0; i < nbPoints; ++i) {
        maxNormn = std::max(maxNormn, 1.);
      }
    }
  }

  void damping(std::vector<MVertex *> &vertices, double limit, GEntity *ent)
  {
    drawBezierControlPolygon(vertices, ent);
    const int nVert = (int)vertices.size();
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);

    fullMatrix<double> xyz(nVert, 3);
    for (int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }
    fullMatrix<double> controlPoints(nVert, 3);
    fs->lag2Bez(xyz, controlPoints);

    fullMatrix<double> dCtrlPnts(nVert, 3);
    double maxDisplacement = computeDampingDirections(controlPoints, dCtrlPnts);

    if (maxDisplacement > limit)
      dCtrlPnts.scale(limit / maxDisplacement);
    controlPoints.add(dCtrlPnts);

    fs->matrixBez2Lag.mult(controlPoints, xyz);
    for (int i = 0; i < nVert; ++i) {
      vertices[i]->x() = xyz(i, 0);
      vertices[i]->y() = xyz(i, 1);
      vertices[i]->z() = xyz(i, 2);
    }
    drawBezierControlPolygon(vertices, ent);
  }

  void damping2(std::vector<MVertex *> &vertices, double fact, GEntity *ent, bool draw = true)
  {
    const int nVert = (int)vertices.size();
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);

    fullMatrix<double> xyz(nVert, 3);
    for (int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }
    fullMatrix<double> controlPoints(nVert, 3);
    fs->lag2Bez(xyz, controlPoints);

    fullMatrix<double> dCtrlPnts(nVert, 3);
    computeDampingDirections(controlPoints, dCtrlPnts);

    dCtrlPnts.scale(fact);
    controlPoints.add(dCtrlPnts);

    fs->matrixBez2Lag.mult(controlPoints, xyz);
    for (int i = 0; i < nVert; ++i) {
      vertices[i]->x() = xyz(i, 0);
      vertices[i]->y() = xyz(i, 1);
      vertices[i]->z() = xyz(i, 2);
    }
    if (draw) drawBezierControlPolygon(vertices, ent);
  }

  double damping3(std::vector<MVertex *> &vertices, double maxFact,
                  double limit, GEntity *ent, bool draw = true)
  {
    const int nVert = (int)vertices.size();
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);

    fullMatrix<double> xyz(nVert, 3);
    for (int i = 0; i < nVert; ++i) {
      xyz(i, 0) = vertices[i]->x();
      xyz(i, 1) = vertices[i]->y();
      xyz(i, 2) = vertices[i]->z();
    }
    fullMatrix<double> controlPoints(nVert, 3);
    fs->lag2Bez(xyz, controlPoints);

    fullMatrix<double> dCtrlPnts(nVert, 3);
    double maxDisplacement = computeDampingDirections(controlPoints, dCtrlPnts);

    dCtrlPnts.scale(maxFact);
    maxDisplacement *= maxFact;

    if (maxDisplacement > limit) {
      dCtrlPnts.scale(limit / maxDisplacement);
      maxDisplacement = limit;
    }
    controlPoints.add(dCtrlPnts);

    fs->matrixBez2Lag.mult(controlPoints, xyz);
    for (int i = 0; i < nVert; ++i) {
      vertices[i]->x() = xyz(i, 0);
      vertices[i]->y() = xyz(i, 1);
      vertices[i]->z() = xyz(i, 2);
    }

    if (draw) drawBezierControlPolygon(vertices, ent);
    return maxDisplacement;
  }

  void regularizeExtremities(double targetAngle0, double targetAngle1,
                             SVector3 linear, SVector3 &w,
                             fullMatrix<double> &controlPoints, double limit,
                             double expansionFactor, double previousLenght0,
                             double previousLenght1)
  {
    targetAngle0 = std::abs(targetAngle0);
    targetAngle1 = std::abs(targetAngle1);
    int nVert = controlPoints.size1();
    SVector3 vTop0(controlPoints(2, 0) - controlPoints(0, 0),
                   controlPoints(2, 1) - controlPoints(0, 1),
                   controlPoints(2, 2) - controlPoints(0, 2));
    SVector3 vTop1(controlPoints(1, 0) - controlPoints(nVert-1, 0),
                   controlPoints(1, 1) - controlPoints(nVert-1, 1),
                   controlPoints(1, 2) - controlPoints(nVert-1, 2));

    double angle0 = signedAngle(linear, vTop0, w);
    double angle1 = signedAngle(linear, vTop1, w);

    fullMatrix<double> dCtrlPnts(nVert, 3);
    double displacement = 0;

    bool canImprove0 = true, canImprove1 = true;
    bool canImproveL0 = true, canImproveL1 = true;
    bool improve0 = std::abs(angle0) > targetAngle0 + 1e-12;
    bool improve1 = std::abs(angle1) > targetAngle1 + 1e-12;
    bool canImprove = (improve0 && canImprove0) || (improve1 && canImprove1);

    bool improved = true;

    while (improved && displacement < limit)
    {
      double maxDisplacement = computeDampingDirections(controlPoints, dCtrlPnts);
//      if (maxDisplacement < .05 * limit)
//        maxDisplacement = computeLinearDirections(controlPoints, dCtrlPnts);

      const int k = nVert-1;
      SVector3 dir0(dCtrlPnts(2, 0), dCtrlPnts(2, 1), dCtrlPnts(2, 2));
      SVector3 dir1(dCtrlPnts(k, 0), dCtrlPnts(k, 1), dCtrlPnts(k, 2));

      double maxFact = 0;
      {
        double alpha = angle0 - gmsh_sign(angle0) * targetAngle0;

        double length;
        canImprove0 = solveASDtriangle(-alpha, vTop0, dir0, length, w);
        if (improve0 && canImprove0)
          maxFact = std::max(maxFact, length / dir0.norm());
      }

      if (maxFact < 1) {
        double alpha = angle1 - gmsh_sign(angle1) * targetAngle1;

        double length;
        canImprove1 = solveASDtriangle(-alpha, -vTop1, dir1, length, w);
        if (improve1 && canImprove1)
          maxFact = std::max(maxFact, length / dir1.norm());
      }

//      double totalLength = linear.norm();
//      double limitLength = .5 * totalLength / (nVert-1);
      double length0 = vTop0.norm();
      double length1 = vTop1.norm();

      if (maxFact < 1 && expansionFactor > 1 && length0 < previousLenght0) {
        double length;
        bool canImprove = solveLSDtriangle(previousLenght0, vTop0, dir0, length, w);
        if (canImprove) maxFact = std::max(maxFact, length / dir0.norm());
      }

      if (maxFact < 1 && expansionFactor > 1 && length1 < previousLenght1) {
        double length;
        bool canImprove = solveLSDtriangle(previousLenght1, -vTop1, dir1, length, w);
        if (canImprove) maxFact = std::max(maxFact, length / dir1.norm());
      }

      double factDisp = (limit-displacement) / maxDisplacement;
      double fact = std::min(1., std::min(factDisp, maxFact));
//      std::cout << "fact: " << fact << " (" << fact0 << ", " << fact1 << ")" << std::endl;
//      fact = std::max(fact0, fact1);
      if (fact < 1e-12) fact = 0;

      dCtrlPnts.scale(fact);
      controlPoints.add(dCtrlPnts);

      vTop0 = SVector3(controlPoints(2, 0) - controlPoints(0, 0),
                       controlPoints(2, 1) - controlPoints(0, 1),
                       controlPoints(2, 2) - controlPoints(0, 2));
      vTop1 = SVector3(controlPoints(1, 0) - controlPoints(nVert-1, 0),
                       controlPoints(1, 1) - controlPoints(nVert-1, 1),
                       controlPoints(1, 2) - controlPoints(nVert-1, 2));

      angle0 = signedAngle(linear, vTop0, w);
      angle1 = signedAngle(linear, vTop1, w);
      displacement += fact * maxDisplacement;
      bool aa = std::abs(angle0) > targetAngle0;
      bool bb = std::abs(angle1) > targetAngle1;

      improve0 = std::abs(angle0) > targetAngle0 + 1e-12;
      improve1 = std::abs(angle1) > targetAngle1 + 1e-12;
      canImprove = (improve0 && canImprove0) || (improve1 && canImprove1);
      improved = fact > 0;
    }
  }

  void regularizeExtremities(const std::vector<MVertex *> &baseVert,
                             std::vector<MVertex *> &topVert,
                             Parameters2DCurve &parameters, SVector3 &w)
  {

    int nVert = baseVert.size();
    fullMatrix<double> xyzBase(nVert, 3);
    fullMatrix<double> xyzTop(nVert, 3);
    for (int i = 0; i < nVert; ++i) {
      xyzBase(i, 0) = baseVert[i]->x();
      xyzBase(i, 1) = baseVert[i]->y();
      xyzBase(i, 2) = baseVert[i]->z();
      xyzTop(i, 0) = topVert[i]->x();
      xyzTop(i, 1) = topVert[i]->y();
      xyzTop(i, 2) = topVert[i]->z();
    }
    const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);

    fullMatrix<double> controlPointsBase(nVert, 3);
    fs->lag2Bez(xyzBase, controlPointsBase);
    SVector3 vBase0(controlPointsBase(2, 0) - controlPointsBase(0, 0),
                    controlPointsBase(2, 1) - controlPointsBase(0, 1),
                    controlPointsBase(2, 2) - controlPointsBase(0, 2));
    SVector3 vBase1(controlPointsBase(1, 0) - controlPointsBase(nVert-1, 0),
                    controlPointsBase(1, 1) - controlPointsBase(nVert-1, 1),
                    controlPointsBase(1, 2) - controlPointsBase(nVert-1, 2));

    fullMatrix<double> controlPointsTop(nVert, 3);
    fs->lag2Bez(xyzTop, controlPointsTop);
    SVector3 vTop0(controlPointsTop(2, 0) - controlPointsTop(0, 0),
                   controlPointsTop(2, 1) - controlPointsTop(0, 1),
                   controlPointsTop(2, 2) - controlPointsTop(0, 2));
    SVector3 vTop1(controlPointsTop(1, 0) - controlPointsTop(nVert-1, 0),
                   controlPointsTop(1, 1) - controlPointsTop(nVert-1, 1),
                   controlPointsTop(1, 2) - controlPointsTop(nVert-1, 2));

    SVector3 vLinBase = baseVert[1]->point() - baseVert[0]->point();
    SVector3 vLinTop = topVert[1]->point() - topVert[0]->point();

    double a = signedAngle(vLinBase, vBase0, w);
    double b = signedAngle(vLinBase, vBase1, w);
    double c = signedAngle(vLinTop, vTop0, w);
    double d = signedAngle(vLinTop, vTop1, w);
    std::cout << "angles: " << a*180*M_1_PI << " -> " << c*180*M_1_PI << " (*" << c/a << ")  "
              << b*180*M_1_PI << " -> " << d*180*M_1_PI << " (*" << d/b << ")" << std::endl;

    double limit = .5 * parameters.characteristicThickness();

    double expansionFactor = vLinTop.norm() / vLinBase.norm();
    regularizeExtremities(a, b, vLinTop, w, controlPointsTop, limit,
                          expansionFactor, vBase0.norm(), vBase1.norm());

    fs->matrixBez2Lag.mult(controlPointsTop, xyzTop);
    for (int i = 0; i < nVert; ++i) {
      topVert[i]->x() = xyzTop(i, 0);
      topVert[i]->y() = xyzTop(i, 1);
      topVert[i]->z() = xyzTop(i, 2);
    }
  }

  void computePositionEdgeVert(const std::vector<MVertex *> &baseVert,
                               const std::vector<MVertex *> &damped,
                               std::vector<MVertex *> &topVert,
                               Parameters2DCurve &parameters, SVector3 w,
                               double factorDamping, GEntity *bndEnt,
                               int nLayer, bool last = false, int direction = 0)
  {
    // Let (t, n, e3) be the local reference frame
    // We seek for each component the polynomial function that fit the best
    //   x1(xi) = x0(xi) + h(xi) * n(xi) + b(xi) * t(xi)
    // in the least square sense.
    // where x0(xi) is the position of the base edge
    //       n(xi) is the unit normal of the base edge
    //       h(xi) is the linear thickness
    //       t(xi) is the unit tangent of the base edge
    //       b(xi) is the linear coefficient

    if (nLayer == 0) {
//      drawAmplifiedDiffWithLin(baseVert, bndEnt, 20);
//      drawBezierControlPolygon(baseVert, bndEnt);
    }

    const int orderCurve = (int)baseVert.size() - 1;
    const int orderGauss = orderCurve * 2;
    const int sizeSystem = getNGQLPts(orderGauss);
    const IntPt *gaussPnts = getGQLPts(orderGauss);

    if (true) { // Least square projection
      fullMatrix<double> xyz(sizeSystem + 2, 3);
      idealPositionEdge(baseVert, damped, parameters, w, sizeSystem, gaussPnts, xyz,
                        bndEnt, direction);
      for (int i = 0; i < 2; ++i) {
        xyz(sizeSystem+i, 0) = topVert[i]->x();
        xyz(sizeSystem+i, 1) = topVert[i]->y();
        xyz(sizeSystem+i, 2) = topVert[i]->z();
      }

      LeastSquareData *data = getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);
      fullMatrix<double> newxyz(orderCurve + 1, 3);
      data->invA.mult(xyz, newxyz);

      for (int i = 2; i < topVert.size(); ++i) {
        topVert[i]->x() = newxyz(i, 0);
        topVert[i]->y() = newxyz(i, 1);
        topVert[i]->z() = newxyz(i, 2);
      }
    }
    else { // Bézier
      int nVert = (int)baseVert.size();
      fullMatrix<double> xyz(nVert, 3);
      for (int i = 0; i < nVert; ++i) {
        xyz(i, 0) = baseVert[i]->x();
        xyz(i, 1) = baseVert[i]->y();
        xyz(i, 2) = baseVert[i]->z();
      }

      const bezierBasis *fs = BasisFactory::getBezierBasis(TYPE_LIN, nVert - 1);
      fullMatrix<double> controlPoints(nVert, 3);
      fs->lag2Bez(xyz, controlPoints);
      bezierOffset(baseVert, controlPoints, parameters, w, bndEnt, direction);

      fs->matrixBez2Lag.mult(controlPoints, xyz);
      for (int i = 0; i < nVert; ++i) {
        topVert[i]->x() = xyz(i, 0);
        topVert[i]->y() = xyz(i, 1);
        topVert[i]->z() = xyz(i, 2);
      }
    }

//    damping(topVert, factorDamping * parameters.characteristicThickness());

//    regularizeExtremities(baseVert, topVert, parameters, w);


//    if (nLayer == 0)
//      drawBezierControlPolygon(topVert, bndEnt);
//    drawAmplifiedDiffWithLin(topVert, bndEnt, 2);
//    drawBezierControlPolygon(topVert, bndEnt);
    if (last) {
//      drawAmplifiedDiffWithLin(topVert, bndEnt, 2);
//      drawBezierControlPolygon(topVert, bndEnt);
    }
  }

  double computeMeanSquareError(const std::vector<MVertex *> &verticesCurve1,
                                const std::vector<MVertex *> &verticesCurve2)
  {
    const int orderCurve = (int)verticesCurve1.size() - 1;
    const int orderGauss = orderCurve * 2;
    int nPts = getNGQLPts(orderGauss);
    IntPt *gPts = getGQLPts(orderGauss);

    double mse = 0;

    for (int i = 0; i < nPts; ++i) {
      const double xi = gPts[i].pt[0];

      int tagLine = ElementType::getTag(TYPE_LIN, orderCurve);
      const nodalBasis* fs = BasisFactory::getNodalBasis(tagLine);
      double sf[100];
      fs->f(xi, 0, 0, sf);

      double x1 = 0., y1 = 0., z1 = 0.;
      double x2 = 0., y2 = 0., z2 = 0.;
      for (int j = 0; j < orderCurve+1; j++) {
        const MVertex *v1 = verticesCurve1[i];
        const MVertex *v2 = verticesCurve2[i];
        x1 += sf[j] * v1->x();
        y1 += sf[j] * v1->y();
        z1 += sf[j] * v1->z();
        x2 += sf[j] * v2->x();
        y2 += sf[j] * v2->y();
        z2 += sf[j] * v2->z();
      }

      mse += (x1-x2) * (x1-x2) * gPts[i].weight;
      mse += (y1-y2) * (y1-y2) * gPts[i].weight;
      mse += (z1-z2) * (z1-z2) * gPts[i].weight;

      const double w = gPts[i].weight;
    }
    return mse;
  }

  double objectiveFunction(const std::vector<MVertex *> &baseVert,
                           const std::vector<MVertex *> &topVert,
                           std::vector<MVertex *> &bottomVertFromTop, SVector3 w,
                           GEntity *bndEnt)
  {
    Parameters2DCurve parameters;
    computeExtremityCoefficients(topVert, topVert, bottomVertFromTop, parameters, w);
    computePositionEdgeVert(topVert, topVert,
                            bottomVertFromTop, parameters, w,
                            0, bndEnt, -1);
    return computeMeanSquareError(baseVert, bottomVertFromTop);
  }

  double computeGradientsOptimization(std::vector<std::vector<double> > &gradients,
                                      const std::vector<MVertex *> &baseVert,
                                      const std::vector<MVertex *> &topVert,
                                      std::vector<MVertex *> &bottomVertFromTop,
                                      SVector3 w, GEntity *bndEnt)
  {
    if (gradients[0].empty()) {
      for (int i = 0; i < (int)gradients.size(); ++i) {
        gradients[i].resize(3);
      }
    }
    gradients[0][0] = 0;
    gradients[0][1] = 0;
    gradients[0][2] = 0;
    gradients[1][0] = 0;
    gradients[1][1] = 0;
    gradients[1][2] = 0;

//    double F = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
    const double step = 1e-6;
    double Fp, Fm;

    for (int i = 2; i < baseVert.size(); ++i) {
      const double x = topVert[i]->x();
      topVert[i]->x() += step;
      Fp = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
      topVert[i]->x() -= 2*step;
      Fm = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
      topVert[i]->x() = x;
      gradients[i][0] = (Fp-Fm)/2/step;

      const double y = topVert[i]->y();
      topVert[i]->y() += step;
      Fp = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
      topVert[i]->y() -= 2*step;
      Fm = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
      topVert[i]->y() = y;
      gradients[i][1] = (Fp-Fm)/2/step;

      const double z = topVert[i]->z();
      topVert[i]->z() += step;
      Fp = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
      topVert[i]->z() -= 2*step;
      Fm = objectiveFunction(baseVert, topVert, bottomVertFromTop, w, bndEnt);
      topVert[i]->z() = z;
      gradients[i][2] = (Fp-Fm)/2/step;
    }
  }

  void moveTopVerticesOptimization(const std::vector<MVertex *> &topVert,
                                   std::vector<MVertex *> &topVertCopy,
                                   const std::vector<std::vector<double> > &gradients,
                                   double a)
  {
    for (int i = 0; i < topVert.size(); ++i) {
      MVertex *v0 = topVert[i];
      MVertex *v1 = topVertCopy[i];
      v1->x() = v0->x() - a * gradients[i][0];
      v1->y() = v0->y() - a * gradients[i][1];
      v1->z() = v0->z() - a * gradients[i][2];
    }
  }

  void optimizePositionEdgeVert(const std::vector<MVertex *> &baseVert,
                                std::vector<MVertex *> &topVert, SVector3 w,
                                GEntity *bndEnt)
  {
    std::vector<MVertex *> baseVertCopy;
    std::vector<MVertex *> topVertCopy;
    for (int i = 0; i < baseVert.size(); ++i) {
      const MVertex *v = baseVert[i];
      const MVertex *v2 = topVert[i];
      baseVertCopy.push_back(new MVertex(v->x(),v->y(),v->z()));
      topVertCopy.push_back(new MVertex(v2->x(),v2->y(),v2->z()));
    }
    double obj = objectiveFunction(baseVert, topVert, baseVertCopy, w, bndEnt);
    double dxFirstGuess = 1e-4;

    damping3(topVertCopy, .1, 1e100, bndEnt, false);
    double objDamp = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);
    while (objDamp < obj) {
      obj = objDamp;
      for (int i = 2; i < topVert.size(); ++i) {
        topVert[i]->x() = topVertCopy[i]->x();
        topVert[i]->y() = topVertCopy[i]->y();
        topVert[i]->z() = topVertCopy[i]->z();
      }
      damping3(topVertCopy, .1, 1e100, bndEnt, false);
      objDamp = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);
    }

    for (int i = 2; i < topVert.size(); ++i) {
      const double xi = (i-1)/((double)topVert.size()-1);
      topVertCopy[i]->x() = (1-xi) * topVert[0]->x() + xi * topVert[1]->x();
      topVertCopy[i]->y() = (1-xi) * topVert[0]->y() + xi * topVert[1]->y();
      topVertCopy[i]->z() = (1-xi) * topVert[0]->z() + xi * topVert[1]->z();
    }
    double objLin = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);

    if (objLin < obj) {
      obj = objLin;
      for (int i = 2; i < topVert.size(); ++i) {
        topVert[i]->x() = topVertCopy[i]->x();
        topVert[i]->y() = topVertCopy[i]->y();
        topVert[i]->z() = topVertCopy[i]->z();
      }
    }

    int maxIteration = 10000, iter = 0;
    while (obj > 1e-6 && ++iter < maxIteration) {
      std::vector<std::vector<double> > gradients(baseVert.size());
      computeGradientsOptimization(gradients, baseVert, topVert,
                                   baseVertCopy, w, bndEnt);
      double maxGradient = 0;
      for (int i = 0; i < (int)baseVert.size(); ++i) {
        maxGradient = std::max(maxGradient,  gradients[i][0]*gradients[i][0]
                                           + gradients[i][1]*gradients[i][1]
                                           + gradients[i][2]*gradients[i][2]);
      }
      maxGradient = std::sqrt(maxGradient);

      double a = dxFirstGuess / maxGradient;
      moveTopVerticesOptimization(topVert, topVertCopy, gradients, a);
      double newobj = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);
      if (newobj > obj) {
        obj = newobj;
        a /= 2;
        moveTopVerticesOptimization(topVert, topVertCopy, gradients, a);
        newobj = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);
        while (newobj < obj) {
          a /= 2;
          obj = newobj;
          moveTopVerticesOptimization(topVert, topVertCopy, gradients, a);
          newobj = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);
        }
        a *= 2;
      }
      else {
        while (newobj < obj) {
          a *= 2;
          obj = newobj;
          moveTopVerticesOptimization(topVert, topVertCopy, gradients, a);
          newobj = objectiveFunction(baseVert, topVertCopy, baseVertCopy, w, bndEnt);
        }
        a /= 2;
      }

      // Test
      moveTopVerticesOptimization(topVert, topVert, gradients, a);

//      obj = objectiveFunction(baseVert, topVert, baseVertCopy, w, bndEnt);
    }

    std::cout << "obj: " << obj << " " << baseVert[2]->getNum() << std::endl;
  }

  InteriorPlacementData* constructInteriorPlacementData(int tag)
  {
    const int order = ElementType::OrderFromTag(tag);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tag);
    InteriorPlacementData *data = new InteriorPlacementData;

    int type = ElementType::ParentTypeFromTag(tag);

    switch (type) {
      case TYPE_TRI:
      case TYPE_QUA: {
        std::map<std::pair<int, int>, int> coordinate2num;
        std::vector<std::pair<int, int> > num2coordinate;
        int x, y;
        for (int i = 0; i < fs->points.size1(); ++i) {
          if (type == TYPE_TRI) {
            x = static_cast<int>(fs->points(i, 0) * order + .5);
            y = static_cast<int>(fs->points(i, 1) * order + .5);
          }
          else {
            x = static_cast<int>((fs->points(i, 0) + 1) / 2. * order + .5);
            y = static_cast<int>((fs->points(i, 1) + 1) / 2. * order + .5);
          }
          coordinate2num[std::make_pair(x, y)] = i;
          num2coordinate.push_back(std::make_pair(x, y));
        }

        for (int i = 0; i < fs->points.size1(); ++i) {
          const std::pair<int, int> coordinates(num2coordinate[i]);
          const int &x = coordinates.first;
          const int &y = coordinates.second;
          int y1;
          if (type == TYPE_TRI) {
            y1 = order - x;
            if (y == 0 || y == y1 || x == 0) continue;
          }
          else {
            y1 = order;
            if (y == 0 || y == y1 || x == 0 || x == order) continue;
          }
          const std::pair<int, int> coordinates0(x, 0);
          const std::pair<int, int> coordinates1(x, y1);
          data->iToMove.push_back(i);
          data->factor.push_back(1 - y / (double) y1);
          data->i0.push_back(coordinate2num[coordinates0]);
          data->i1.push_back(coordinate2num[coordinates1]);
        }
        break;
      }
      default:
        Msg::Error("Need to implement constructInteriorPlacementData for other type");
    }

    return data;
  }

  void repositionInteriorNodes(MElement *el)
  {
    int tag = el->getTypeForMSH();
    InteriorPlacementData *data;

    std::map<int, InteriorPlacementData*>::iterator it;
    it = interiorPlacementData.find(tag);
    if (it != interiorPlacementData.end()) data = it->second;
    else {
      data = constructInteriorPlacementData(tag);
      interiorPlacementData[tag] = data;
    }

    for (int i = 0; i < data->iToMove.size(); ++i) {
      MVertex *v = el->getVertex(data->iToMove[i]);
      MVertex *v0 = el->getVertex(data->i0[i]);
      MVertex *v1 = el->getVertex(data->i1[i]);
      v->x() = data->factor[i] * v0->x() + (1 - data->factor[i]) * v1->x();
      v->y() = data->factor[i] * v0->y() + (1 - data->factor[i]) * v1->y();
      v->z() = data->factor[i] * v0->z() + (1 - data->factor[i]) * v1->z();
    }
  }

  MEdge commonEdge(MTriangle *t0, MTriangle *t1)
  {
    MVertex *v[3] = {NULL};
    int k = 0;
    for (int i = 0; i < 3; ++i) {
      if (t0->getVertex(i) == t1->getVertex(0) ||
          t0->getVertex(i) == t1->getVertex(1) ||
          t0->getVertex(i) == t1->getVertex(2)) v[k++] = t0->getVertex(i);
    }
    if (k == 3) Msg::Error("Multiple common edges!");
    if (k > 1) return MEdge(v[0], v[1]);
    Msg::Error("no common edge!!!");
    return MEdge();
  }

  MEdge commonEdge(MTriangle *t, MElement *el)
  {
    MEdge theEdge;
    for (int i = 0; i < el->getNumEdges(); ++i) {
      MEdge e = el->getEdge(i);
      int cntVertInT = 0;
      for (int j = 0; j < 3; ++j) {
        if (e.getVertex(0) == t->getVertex(j) ||
            e.getVertex(1) == t->getVertex(j)) ++cntVertInT;
      }
      if (cntVertInT == 2) {
        if (theEdge.getVertex(0) || theEdge.getVertex(1)) {
          Msg::Error("Multiple common edges or error in default creation!");
        }
        theEdge = e;
      }
    }
    if (theEdge.getVertex(0) && theEdge.getVertex(1)) return theEdge;
    Msg::Error("no common edge!!!");
    return MEdge();
  }

  bool curve2DTriColumn(MElement *bottomEdge, MElement *extElem,
                        std::vector<MElement *> &column,
                        SVector3 &w, double dampingFactor, GEntity *bndEnt)
  {
    MEdge bottom(bottomEdge->getVertex(0), bottomEdge->getVertex(1));
    std::vector<MVertex *> bottomVertices, topVertices, midVertices;

    for (int i = 0; i < column.size(); i += 2) {
      MTriangle *tri0 = dynamic_cast<MTriangle *>(column[i]);
      MTriangle *tri1 = dynamic_cast<MTriangle *>(column[i+1]);
      MEdge common = commonEdge(tri0, tri1);
      MEdge top;
      if (i == column.size() - 2)
        top = commonEdge(tri1, extElem);
      else
        top = commonEdge(tri1, dynamic_cast<MTriangle *>(column[i+2]));

      // Reorient if needed (makes function repositionInteriorNodes() simpler)
      int iBottom, iTop, sign;
      tri0->getEdgeInfo(bottom, iBottom, sign);
      tri0->getEdgeInfo(common, iTop, sign);
      if (iBottom != 0 && iTop != 0) tri0->reorient(1, false);
      else if (iBottom != 1 && iTop != 1) tri0->reorient(2, false);
      tri1->getEdgeInfo(common, iBottom, sign);
      tri1->getEdgeInfo(top, iTop, sign);
      if (iBottom != 0 && iTop != 0) tri1->reorient(1, false);
      else if (iBottom != 1 && iTop != 1) tri1->reorient(2, false);

      // Get vertices
      tri0->getEdgeInfo(bottom, iBottom, sign);
      tri0->getEdgeVertices(iBottom, bottomVertices);
      tri0->getEdgeVertices(1-iBottom, midVertices);
      std::reverse(midVertices.begin(), midVertices.begin() + 2);
      std::reverse(midVertices.begin() + 2, midVertices.end());

      common = MEdge(midVertices[0], midVertices[1]);
      tri1->getEdgeInfo(common, iBottom, sign);
      tri1->getEdgeVertices(1-iBottom, topVertices);
      if (sign > 0) {
        std::reverse(topVertices.begin(), topVertices.begin() + 2);
        std::reverse(topVertices.begin() + 2, topVertices.end());
      }

      //
      int direction = 1;
      if (bottomVertices[1] == midVertices[1]) direction = -1;
      Parameters2DCurve parameters;
      computeExtremityCoefficients(bottomVertices, bottomVertices, topVertices, parameters, w);
      computePositionEdgeVert(bottomVertices, bottomVertices, midVertices, parameters, w,
                              dampingFactor, bndEnt, i/2, i == column.size()-2,
                              direction);
      computePositionEdgeVert(bottomVertices, bottomVertices, topVertices, parameters, w,
                              dampingFactor, bndEnt, i/2, i == column.size()-2);
      repositionInteriorNodes(tri0);
      repositionInteriorNodes(tri1);
      bottom = MEdge(topVertices[0], topVertices[1]);

      // Check validity of first and last layer:
      if ((i == 0 || i == column.size()-2) &&
          (tri0->getValidity() != 1 || tri1->getValidity() != 1)) return false;
    }
    return true;
  }

  bool curve2DQuadColumn(MElement *bottomEdge, std::vector<MElement *> &column,
                         SVector3 &w, double dampingFactor, GEntity *bndEnt)
  {
    opt_general_default_filename(0, GMSH_SET, "layer");
    MEdge bottom(bottomEdge->getVertex(0), bottomEdge->getVertex(1));
    std::vector<MVertex *> bottomVertices, topVertices;

    for (int i = 0; i < column.size(); ++i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      int iBottom, sign;
      quad->getEdgeInfo(bottom, iBottom, sign);
      // Reorientation makes function repositionInteriorNodes() simpler
      if (iBottom != 0) quad->reorient(4 - iBottom, false);
      quad->getEdgeVertices(0, bottomVertices);
      quad->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());

      Parameters2DCurve parameters;
      computeExtremityCoefficients(bottomVertices, bottomVertices, topVertices, parameters, w);
//      std::vector<MVertex *> dampedBottomVertices(bottomVertices.size());
//      for (int i = 0; i < bottomVertices.size(); ++i) {
//        MVertex *v = bottomVertices[i];
//        dampedBottomVertices[i] = new MVertex(v->x(), v->y(), v->z());
//      }
//      damping(dampedBottomVertices, .00 * bottomVertices[0]->distance(bottomVertices[1]));
//      computeExtremityCoefficients(bottomVertices, dampedBottomVertices, topVertices, parameters, w);
//      computePositionEdgeVert(bottomVertices, dampedBottomVertices, topVertices, parameters, w,
//                              dampingFactor, bndEnt, i, -i == column.size()-1);
      computePositionEdgeVert(bottomVertices, bottomVertices, topVertices, parameters, w,
                              dampingFactor, bndEnt, i, -i == column.size()-1);
      //optimizePositionEdgeVert(bottomVertices, topVertices, w, bndEnt);
      repositionInteriorNodes(quad);
      bottom = MEdge(topVertices[0], topVertices[1]);

      // Check validity of first and last layer:
      if ((i == 0 || i == column.size()-1) && quad->getValidity() != 1) return false;
      // debug
      if (quad->getValidity() != 1) {

        for (int j = i+1; j < column.size(); ++j) {
          column[j]->setVisibility(false);
        }
        return false;
      }

//      if (false && i < 16) {
//        double fact = 10;
//        for (int j = 1; j < 7; ++j) {
//          drawBezierDerivative(bottomVertices, bndEnt, SPoint3(fact*j, -10, 0), &j, .01);
//          drawBezierControlPolygon(bottomVertices, bndEnt);
//          if (i == column.size()-1) {
//            drawBezierDerivative(topVertices, bndEnt, SPoint3(fact*(j), -10, 0), &j, .01);
//            drawBezierControlPolygon(topVertices, bndEnt);
//          }
//        }
//      }
    }
    return true;
  }

  void linearTFI(std::vector<MElement *> &column,
                 std::vector<MVertex *> &globalBottomVertices,
                 std::vector<MVertex *> &globalTopVertices)
  {
    // Here, we assume that "thickness" is identical on the left and on the
    // right part of the column => identical eta_i
    MVertex *vbot = globalBottomVertices[0];
    MVertex *vtop = globalTopVertices[0];
    double dX = vtop->x() - vbot->x();
    double dY = vtop->y() - vbot->y();
    bool lookAtX = std::abs(dX) > std::abs(dY);

    // Go trough the whole column and compute TFI position of topVertices
    std::vector<MVertex *> bottomVertices;
    for (int i = (int)column.size() - 1; i >= 0; --i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      quad->getEdgeVertices(0, bottomVertices);
      MVertex *v = bottomVertices[0];
      double factor;
      if (lookAtX) factor = (v->x() - vbot->x()) / dX;
      else factor = (v->y() - vbot->y()) / dY;
      for (int j = 2; j < bottomVertices.size(); ++j) {
        MVertex *vbot = globalBottomVertices[j];
        MVertex *vtop = globalTopVertices[j];
        MVertex *v = bottomVertices[j];
        v->x() = (1 - factor) * vbot->x() + factor * vtop->x();
        v->y() = (1 - factor) * vbot->y() + factor * vtop->y();
        v->z() = (1 - factor) * vbot->z() + factor * vtop->z();
      }
      repositionInteriorNodes(quad);
    }
  }

  void linearTFI(const fullMatrix<double> &x, fullMatrix<double> &lin)
  {
    int n = x.size1();
    lin.copy(x, 0, 2, 0, 3, 0, 0);
    for (int i = 2; i < n; ++i) {
      double fact = ((double)i-1)/(n-1);
      for (int j = 0; j < 3; ++j)
        lin(i, j) = (1-fact) * x(0, j) + fact * x(1, j);
    }
  }

  void hermiteTFI(std::vector<std::vector<MVertex *> > &layerVertices)
  {
    // General definition

    // First, compute eta_i^k, k=0,1
    std::vector<std::pair<double, double> > eta(layerVertices.size());
    eta[0] = std::make_pair(0, 0);
    MVertex *vb0 = layerVertices[0][0];
    MVertex *vb1 = layerVertices[0][1];
    for (int i = 1; i < layerVertices.size(); ++i) {
      MVertex *vt0 = layerVertices[i][0];
      MVertex *vt1 = layerVertices[i][1];
      eta[i].first = eta[i-1].first + vb0->distance(vt0);
      eta[i].second = eta[i-1].second + vb1->distance(vt1);
      vb0 = vt0;
      vb1 = vt1;
    }

    for (int i = 1; i < eta.size(); ++i) {
      eta[i].first /= eta.back().first;
      eta[i].second /= eta.back().second;
    }

    // Precompute Delta(x_k), k=0,1,n
    int numVerticesToCompute = (int)layerVertices[0].size();
    double eta1 = .5 * (eta[1].first + eta[1].second);
    fullMatrix<double> delta0(numVerticesToCompute, 3);
    fullMatrix<double> delta1(numVerticesToCompute, 3);
    fullMatrix<double> deltan(numVerticesToCompute, 3);
    for (int i = 0; i < delta0.size1(); ++i) {
      delta0(i, 0) = layerVertices[0][i]->x();
      delta0(i, 1) = layerVertices[0][i]->y();
      delta0(i, 2) = layerVertices[0][i]->z();
      delta1(i, 0) = layerVertices[1][i]->x();
      delta1(i, 1) = layerVertices[1][i]->y();
      delta1(i, 2) = layerVertices[1][i]->z();
      deltan(i, 0) = layerVertices.back()[i]->x();
      deltan(i, 1) = layerVertices.back()[i]->y();
      deltan(i, 2) = layerVertices.back()[i]->z();
    }
    {
      fullMatrix<double> dummy(numVerticesToCompute, 3);
      linearTFI(delta0, dummy);
      delta0.add(dummy, -1);
      linearTFI(delta1, dummy);
      delta1.add(dummy, -1);
      linearTFI(deltan, dummy);
      deltan.add(dummy, -1);

      delta1.add(delta0, -1);
      delta1.scale(1 / eta1);
      deltan.add(delta0, -1);
    }

    // Go through each layer
    TFIData *tfiData = getTFIData(TYPE_LIN, (int)layerVertices[0].size()-1);

    fullMatrix<double> term0(numVerticesToCompute, 3);
    fullMatrix<double> term10(numVerticesToCompute, 3);
    fullMatrix<double> term11(numVerticesToCompute, 3);
    fullMatrix<double> term20(numVerticesToCompute, 3);
    fullMatrix<double> term21(numVerticesToCompute, 3);
    fullMatrix<double> term22(numVerticesToCompute, 3);
    term0.copy(delta0);
    tfiData->T0.mult(delta1, term10);
    tfiData->T1.mult(delta1, term11);
    fullMatrix<double> diff(numVerticesToCompute, 3);
    fullMatrix<double> dum0(numVerticesToCompute, 3);
    fullMatrix<double> dum1(numVerticesToCompute, 3);
    diff.copy(deltan);
    diff.add(delta1, -1);
    tfiData->T0.mult(diff, dum0);
    tfiData->T1.mult(diff, dum1);
    tfiData->T0.mult(dum0, term20);
    tfiData->T1.mult(dum0, term21);
    tfiData->T1.mult(dum1, term22);

    for (int i = 2; i < layerVertices.size()-1; ++i) {
      fullMatrix<double> x(numVerticesToCompute, 3);
      for (int j = 0; j < delta0.size1(); ++j) {
        x(j, 0) = layerVertices[i][j]->x();
        x(j, 1) = layerVertices[i][j]->y();
        x(j, 2) = layerVertices[i][j]->z();
      }
      linearTFI(x, x);

      x.axpy(term0);
      x.axpy(term10, eta[i].first);
      x.axpy(term11, eta[i].second);
      x.axpy(term20, eta[i].first * eta[i].first);
      x.axpy(term21, 2*eta[i].first * eta[i].second);
      x.axpy(term22, eta[i].second * eta[i].second);
      for (int j = 0; j < delta0.size1(); ++j) {
        layerVertices[i][j]->x() = x(j, 0);
        layerVertices[i][j]->y() = x(j, 1);
        layerVertices[i][j]->z() = x(j, 2);
      }
    }


  }

  double getDistDamping(int num)
  {
    return 0;
    switch (num) {
      case 1157: return .05;
      case 1156: return .10;
      case 1150: return .12;
      case 1102: return .45;
      case 1079: return .15;
      default: return .10;
    }
  }

  bool curve2DQuadColumnTFI(MElement *bottomEdge, std::vector<MElement *> &column,
                            SVector3 &w, double dampingFactor, GEntity *bndEnt,
                            bool linear)
  {
    if (linear)
      opt_general_default_filename(0, GMSH_SET, "tfiLinear");
    else
      opt_general_default_filename(0, GMSH_SET, "tfiHermite");

    // First, go through the whole column, reorient and save last curve
    MEdge bottom(bottomEdge->getVertex(0), bottomEdge->getVertex(1));
    std::vector<MVertex *> bottomVertices, topVertices;
    std::vector<MVertex *> globalBottomVertices, globalTopVertices;
    std::vector<std::vector<MVertex *> > allLayerVertices; // for general TFI

    double lengthFirst = bottom.length();
    double distDamping = getDistDamping(bottomEdge->getNum()) * lengthFirst;

    for (int i = 0; i < column.size(); ++i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      int iBottom, sign;
      quad->getEdgeInfo(bottom, iBottom, sign);
      // Reorientation makes function repositionInteriorNodes() simpler
      if (iBottom != 0) quad->reorient(4 - iBottom, false);
      quad->getEdgeVertices(0, bottomVertices);
      quad->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());

      if (i == 0) {
        globalBottomVertices = bottomVertices;
        allLayerVertices.push_back(bottomVertices);
      }
      allLayerVertices.push_back(topVertices);
      if (i == column.size() - 1) globalTopVertices = topVertices;

      bottom = MEdge(topVertices[0], topVertices[1]);
    }

//    drawAngleChange(globalBottomVertices, bndEnt, w, 1e-2);

    /*
//    int deriv = 5;
//    double scale = 1, dx = 2; // Strange
//    double scale = 1, dx = 8; // Good
    int deriv = 6;
    double scale = 10, dx = 2; // Strange
//    double scale = 1, dx = 2; // Good
    drawBezierControlPolygon(globalBottomVertices, bndEnt);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(0, -10, 0), &deriv, scale);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(-dx, -10, 0), &deriv, scale);
    damping3(globalBottomVertices, .3, 10000, bndEnt, true);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(dx, -10, 0), &deriv, scale);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(-dx, -10, 0), &deriv, scale);
    damping3(globalBottomVertices, .3, 10000, bndEnt, true);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(2*dx, -10, 0), &deriv, scale);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(-dx, -10, 0), &deriv, scale);
    damping3(globalBottomVertices, .3, 10000, bndEnt, true);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(3*dx, -10, 0), &deriv, scale);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(-dx, -10, 0), &deriv, scale);
    damping3(globalBottomVertices, .3, 10000, bndEnt, true);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(4*dx, -10, 0), &deriv, scale);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(-dx, -10, 0), &deriv, scale);
    damping3(globalBottomVertices, .3, 10000, bndEnt, true);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(5*dx, -10, 0), &deriv, scale);
    drawBezierDerivative(globalBottomVertices, bndEnt, SPoint3(-dx, -10, 0), &deriv, scale);
     */

    // Curve last layer
    Parameters2DCurve parameters;
    computeExtremityCoefficients(globalBottomVertices, globalBottomVertices,
                                 globalTopVertices, parameters, w);
    computePositionEdgeVert(globalBottomVertices, globalBottomVertices,
                            globalTopVertices, parameters, w,
                            dampingFactor, bndEnt, -1, true);

//    Parameters2DCurve parameters2;
//    computeExtremityCoefficients(globalTopVertices, globalTopVertices,
//                                 globalBottomVertices, parameters2, w);
//    drawIdealCurve(globalTopVertices, parameters2, w, bndEnt);
//    optimizePositionEdgeVert(globalBottomVertices, globalTopVertices, w, bndEnt);
//    computeExtremityCoefficients(globalTopVertices, globalTopVertices,
//                                 globalBottomVertices, parameters2, w);
//    drawIdealCurve(globalTopVertices, parameters2, w, bndEnt);

//    drawIdealCurve(globalBottomVertices, parameters, w, bndEnt, true, false, true);

    double remainingDamping = distDamping;
    double delta = 1;
//      std::cout << "remain:" << remainingDamping << std::endl;
    while (remainingDamping > 1e-12 && delta > 1e-4 * lengthFirst) {
      delta = damping3(globalTopVertices, .1, remainingDamping, bndEnt, false);
      remainingDamping -= delta;
    }

    // Choose between linear and hermite
    if (linear) {
      linearTFI(column, globalBottomVertices, globalTopVertices);
    }
    else {
      computeExtremityCoefficients(globalBottomVertices, globalBottomVertices,
                                   allLayerVertices[1], parameters, w);
      computePositionEdgeVert(globalBottomVertices, globalBottomVertices,
                              allLayerVertices[1], parameters, w,
                              dampingFactor, bndEnt, -1, true);
//      optimizePositionEdgeVert(globalBottomVertices, allLayerVertices[1], w, bndEnt);
//      int N = 0;
//      switch (bottomEdge->getNum()) {
//        case 1102: N = 0; break;
//      }
//      for (int i = 0; i < N; ++i) {
//        damping2(allLayerVertices[1], .1, bndEnt);
//      }

      hermiteTFI(allLayerVertices);
      for (int i = 0; i < (int)column.size(); ++i)
        repositionInteriorNodes(column[i]);
    }

    return true;
  }

  bool curve2DQuadColumnFirst(MElement *bottomEdge, std::vector<MElement *> &column,
                              SVector3 &w, double dampingFactor, GEntity *bndEnt)
  {
    opt_general_default_filename(0, GMSH_SET, "first");
    // First, go through the whole column, reorient and save last curve
    MEdge bottom(bottomEdge->getVertex(0), bottomEdge->getVertex(1));
    std::vector<MVertex *> bottomVertices, topVertices;
    std::vector<MVertex *> globalBottomVertices, globalTopVertices;

    double lengthFirst = bottom.length();
    double distDamping = getDistDamping(bottomEdge->getNum()) * lengthFirst;

    for (int i = 0; i < column.size(); ++i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      int iBottom, sign;
      quad->getEdgeInfo(bottom, iBottom, sign);
      // Reorientation makes function repositionInteriorNodes() simpler
      if (iBottom != 0) quad->reorient(4 - iBottom, false);
      quad->getEdgeVertices(0, bottomVertices);
      quad->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());

      if (i == 0) globalBottomVertices = bottomVertices;
      if (i == column.size() - 1) globalTopVertices = topVertices;

      bottom = MEdge(topVertices[0], topVertices[1]);
    }

    //
    MVertex *vbot = globalBottomVertices[0];
    MVertex *vtop = globalTopVertices[0];
    double dX = vtop->x() - vbot->x();
    double dY = vtop->y() - vbot->y();
    bool lookAtX = std::abs(dX) > std::abs(dY);

    bottom = MEdge(bottomEdge->getVertex(0), bottomEdge->getVertex(1));

    for (int i = 0; i < column.size(); ++i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      int iBottom, sign;
      quad->getEdgeInfo(bottom, iBottom, sign);
      // Reorientation makes function repositionInteriorNodes() simpler
      if (iBottom != 0) quad->reorient(4 - iBottom, false);
      quad->getEdgeVertices(0, bottomVertices);
      quad->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());
      if (i == 0) globalBottomVertices = bottomVertices;

      Parameters2DCurve parameters;
      computeExtremityCoefficients(globalBottomVertices, globalBottomVertices, topVertices, parameters, w);
      computePositionEdgeVert(globalBottomVertices, globalBottomVertices, topVertices, parameters, w,
                              dampingFactor, bndEnt, i, -i == column.size()-1);

      double factor;
      {
        MVertex *v = topVertices[0];
        if (lookAtX) factor = (v->x() - vbot->x()) / dX;
        else factor = (v->y() - vbot->y()) / dY;
      }

      double remainingDamping = distDamping * factor * (i+1) / column.size();
//      double remainingDamping = distDamping * factor;
      double delta = lengthFirst;
//      std::cout << "remain:" << remainingDamping << std::endl;
      while (remainingDamping > 1e-12 && delta > 1e-4 * lengthFirst) {
        delta = damping3(topVertices, .1, remainingDamping, bndEnt, false);
        remainingDamping -= delta;
      }
//      drawBezierControlPolygon(topVertices, bndEnt);

      repositionInteriorNodes(quad);
      bottom = MEdge(topVertices[0], topVertices[1]);

      // Check validity of first and last layer:
      if ((i == 0 || i == column.size()-1) && quad->getValidity() != 1) return false;
    }
    return true;
  }

  double feedbackMeasure(const std::vector<MVertex *> &baseVert,
                         const std::vector<MVertex *> &topVert,
                         std::vector<MVertex *> &baseVertCopy,
                         SVector3 &w, GEntity *bndEnt)
  {
    Parameters2DCurve parameters;
    computeExtremityCoefficients(topVert, topVert, baseVertCopy, parameters, w);
    computePositionEdgeVert(topVert, topVert, baseVertCopy, parameters, w, 0, bndEnt, -1, false);

    return computeMeanSquareError(baseVert, baseVertCopy);
  }

  void computeTopFeedback(const std::vector<MVertex *> &baseVert,
                          std::vector<MVertex *> &topVert,
                          SVector3 &w, GEntity *bndEnt)
  {
    std::vector<MVertex *> baseNormal0, baseNormal1, basePosition0, basePosition1;
    std::vector<MVertex *> dummy;
    for (int i = 0; i < baseVert.size(); ++i) {
      const MVertex *v = baseVert[i];
      baseNormal0.push_back(new MVertex(v->x(),v->y(),v->z()));
      baseNormal1.push_back(new MVertex(v->x(),v->y(),v->z()));
      basePosition0.push_back(new MVertex(v->x(),v->y(),v->z()));
      basePosition1.push_back(new MVertex(v->x(),v->y(),v->z()));
      dummy.push_back(new MVertex(v->x(),v->y(),v->z()));
    }
    Parameters2DCurve parameters;
    computeExtremityCoefficients(basePosition0, baseNormal0, topVert, parameters, w);
    computePositionEdgeVert(basePosition0, baseNormal0, topVert, parameters, w,
                            0, bndEnt, -1, false);
    double error = feedbackMeasure(baseVert, topVert, dummy, w, bndEnt);

    double maxFact = .001;
    double limit = 1e10;
    damping3(baseNormal1, maxFact, limit, bndEnt, false);
    damping3(basePosition1, maxFact, limit, bndEnt, false);

    computeExtremityCoefficients(basePosition0, baseNormal1, topVert, parameters, w);
    computePositionEdgeVert(basePosition0, baseNormal1, topVert, parameters, w,
                            0, bndEnt, -1, false);
    double errorNormal = feedbackMeasure(baseVert, topVert, dummy, w, bndEnt);

    computeExtremityCoefficients(basePosition1, baseNormal0, topVert, parameters, w);
    computePositionEdgeVert(basePosition1, baseNormal0, topVert, parameters, w,
                            0, bndEnt, -1, false);
    double errorPosition = feedbackMeasure(baseVert, topVert, dummy, w, bndEnt);

    while (errorPosition < error || errorNormal < error) {
      if (errorPosition < errorNormal) {
        error = errorPosition;
        damping3(basePosition0, maxFact, limit, bndEnt, false);
        damping3(basePosition1, maxFact, limit, bndEnt, false);
      }
      else {
        error = errorNormal;
        damping3(baseNormal0, maxFact, limit, bndEnt, false);
        damping3(baseNormal1, maxFact, limit, bndEnt, false);
      }

      computeExtremityCoefficients(basePosition0, baseNormal1, topVert, parameters, w);
      computePositionEdgeVert(basePosition0, baseNormal1, topVert, parameters, w,
                              0, bndEnt, -1, false);
      errorNormal = feedbackMeasure(baseVert, topVert, dummy, w, bndEnt);

      computeExtremityCoefficients(basePosition1, baseNormal0, topVert, parameters, w);
      computePositionEdgeVert(basePosition1, baseNormal0, topVert, parameters, w,
                              0, bndEnt, -1, false);
      errorPosition = feedbackMeasure(baseVert, topVert, dummy, w, bndEnt);
    }
    computeExtremityCoefficients(basePosition0, baseNormal0, topVert, parameters, w);
    computePositionEdgeVert(basePosition0, baseNormal0, topVert, parameters, w,
                            0, bndEnt, -1, false);

    std::vector<MVertex *> &topVertCopy = baseNormal0;
    for (int i = 0; i < topVert.size(); ++i) {
      MVertex *v = topVertCopy[i];
      MVertex *v2 = topVert[i];
      v->x() = v2->x();
      v->y() = v2->y();
      v->z() = v2->z();
    }

    damping3(topVertCopy, maxFact, limit, bndEnt, false);
    double errorDamping = feedbackMeasure(baseVert, topVertCopy, dummy, w, bndEnt);
    while (errorDamping < error) {
      error = errorDamping;
      damping3(topVertCopy, maxFact, limit, bndEnt, false);
      damping3(topVert, maxFact, limit, bndEnt, false);
      errorDamping = feedbackMeasure(baseVert, topVertCopy, dummy, w, bndEnt);
    }
  }

  bool curve2DQuadColumnFeedback(MElement *bottomEdge, std::vector<MElement *> &column,
                                 SVector3 &w, GEntity *bndEnt)
  {
    opt_general_default_filename(0, GMSH_SET, "feedback");
    MEdge bottom(bottomEdge->getVertex(0), bottomEdge->getVertex(1));
    std::vector<MVertex *> bottomVertices, topVertices;

    for (int i = 0; i < column.size(); ++i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      int iBottom, sign;
      quad->getEdgeInfo(bottom, iBottom, sign);
      // Reorientation makes function repositionInteriorNodes() simpler
      if (iBottom != 0) quad->reorient(4 - iBottom, false);
      quad->getEdgeVertices(0, bottomVertices);
      quad->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());

      computeTopFeedback(bottomVertices, topVertices, w, bndEnt);
      repositionInteriorNodes(quad);
      bottom = MEdge(topVertices[0], topVertices[1]);
    }
    return true;
  }

  void computeThicknessQuality(std::vector<MVertex *> &bottomVertices,
                               std::vector<MVertex *> &topVertices,
                               std::vector<double> &thickness,
                               SVector3 &w)
  {
    int nVertices = (int)bottomVertices.size();
    int tagLine = ElementType::getTag(TYPE_LIN, nVertices-1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

    for (int i = 0; i < nVertices; ++i) {
      const MVertex *v0 = bottomVertices[i];
      const MVertex *v1 = topVertices[i];
      SVector3 t, n, h;
      h = SVector3(v1->x()-v0->x(), v1->y()-v0->y(), v1->z()-v0->z());

      double xi = fs->points(i, 0);
      double xc = 0, yc = 0, zc = 0;
      double dx = 0, dy = 0, dz = 0;
      {
        double f[100];
        double sf[100][3];
        fs->f(xi, 0, 0, f);
        fs->df(xi, 0, 0, sf);
        for (int j = 0; j < fs->getNumShapeFunctions(); j++) {
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
    for (int j = 2; j < nVertices; ++j) {
      double fact = ((double)j-1)/(nVertices-1);
      double idealThickness = (1-fact) * t0 + fact * t1;
      int sign = gmsh_sign(idealThickness);
      if (sign * thickness[j] < 0)
        thickness[j] = 0;
      else if (sign*thickness[j] < sign*idealThickness)
        thickness[j] = thickness[j] / idealThickness;
      else
        thickness[j] = idealThickness / thickness[j];
    }
  }

  void computeThicknessPView(MElement *el, SVector3 &w,
                             std::map<int, std::vector<double> > &data)
  {
    if (el->getType() == TYPE_QUA) {
      std::vector<MVertex *> bottomVertices, topVertices;

      el->getEdgeVertices(0, bottomVertices);
      el->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());

      std::vector<double> thickness[2];
      computeThicknessQuality(bottomVertices, topVertices, thickness[0], w);
      computeThicknessQuality(topVertices, bottomVertices, thickness[1], w);

      std::map<int, double> v2q;
      v2q[0] = thickness[0][0];
      v2q[1] = thickness[0][1];
      v2q[2] = thickness[1][1];
      v2q[3] = thickness[1][0];
      int nEdgeVertex = (int)topVertices.size()-2;
      for (int i = 2; i < (int)thickness[0].size(); ++i) {
        v2q[4+i-2] = thickness[0][i];
        v2q[3+3*nEdgeVertex-i+2] = thickness[1][i];
      }

      double q00 = v2q[0];
      double q10 = v2q[1];
      double q11 = v2q[2];
      double q01 = v2q[3];
      for (int i = 0; i < nEdgeVertex; ++i) {
        double fact = ((double)i+1)/(nEdgeVertex+1);
        v2q[4+nEdgeVertex+i]   = (1-fact) * q10 + fact * q11;
        v2q[4+3*nEdgeVertex+i] = (1-fact) * q01 + fact * q00;
      }

      int tag = el->getTypeForMSH();
      InteriorPlacementData *pData;
      std::map<int, InteriorPlacementData*>::iterator it;
      it = interiorPlacementData.find(tag);
      if (it != interiorPlacementData.end()) pData = it->second;
      else {
        pData = constructInteriorPlacementData(tag);
        interiorPlacementData[tag] = pData;
      }
      for (int i = 0; i < pData->iToMove.size(); ++i) {
        int idx = pData->iToMove[i];
        double q0 = v2q[pData->i0[i]];
        double q1 = v2q[pData->i1[i]];
        v2q[idx] = pData->factor[i] * q0 + (1-pData->factor[i]) * q1;
      }

      std::vector<double> &vData = data[el->getNum()];
      std::map<int, double>::iterator it2;
      for (it2 = v2q.begin(); it2 != v2q.end(); ++it2) {
        vData.push_back(it2->second);
      }
    }
  }

}


void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column,
                          std::vector<MElement*> aboveElements,
                          SVector3 n, GEntity *bndEnt)
{
#ifdef _OPENMP
#pragma omp for
#endif
  std::map<int, std::vector<double> > data;


  for (int i = 0; i < bndEl2column.size(); ++i) {
    MElement *bottomEdge = bndEl2column[i].first;
//    if (bottomEdge->getNum() != 1079) continue; // Good
//    if (bottomEdge->getNum() != 1078) continue; // Next to good
    if (bottomEdge->getNum() != 1102) continue; // Bad HO
//    if (bottomEdge->getNum() != 1136) continue; // Bad linear
//    if (bottomEdge->getNum() != 1150) continue; // concave
//    if (bottomEdge->getNum() != 1151) continue; // symetric of concave
//    if (bottomEdge->getNum() != 1156) continue; // Strange
//    if (bottomEdge->getNum() != 1157) continue; // next to Strange
    std::vector<MElement*> &column = bndEl2column[i].second;
//    std::cout << bottomEdge->getNum();
    double dampingFactor = 0;
    bool success = false;
    if (!success && dampingFactor < 1000) {
      if (column[0]->getType() == TYPE_TRI)
        success = BoundaryLayerCurver::curve2DTriColumn(bottomEdge,
                                                        aboveElements[i],
                                                        column, n,
                                                        dampingFactor, bndEnt);
      else
//        success = BoundaryLayerCurver::curve2DQuadColumn(bottomEdge, column,
//                                                         n, dampingFactor,
//                                                         bndEnt);
//        success = BoundaryLayerCurver::curve2DQuadColumnFirst(bottomEdge, column,
//                                                              n, dampingFactor,
//                                                              bndEnt);
//        success = BoundaryLayerCurver::curve2DQuadColumnTFI(bottomEdge, column,
//                                                            n, dampingFactor,
//                                                            bndEnt, true);
      success = BoundaryLayerCurver::curve2DQuadColumnFeedback(bottomEdge, column,
                                                               n, bndEnt);
      if (dampingFactor == 0) dampingFactor = .01;
      else dampingFactor *= 2;
    }
    if (success) {
//      for (int j = 0; j < column.size(); ++j) {
//        column[j]->setVisibility(false);
//      }
    }
    for (int j = 0; j < column.size(); ++j) {
      BoundaryLayerCurver::computeThicknessPView(column[j], n, data);
    }
  }

#if defined(HAVE_POST)
//  new PView("Thickness quality", "ElementNodeData", GModel::current(), data, 0, 1);
  std::map<int, std::vector<double> > data2;
  std::map<int, std::vector<double> >::iterator it;
  for (it = data.begin(); it != data.end(); ++it) {
    double min = 1;
    for (int i = 0; i < (int)it->second.size(); ++i) {
      min = std::min(min, it->second[i]);
    }
    data2[it->first].push_back(min);
  }
//  new PView("Thickness quality", "ElementData", GModel::current(), data2, 0, 1);
//  static int aaa = 0;
//  if (++aaa == 7) GMSH_AnalyseCurvedMeshPlugin().execute(NULL);
#if defined(HAVE_FLTK)
  FlGui::instance()->updateViews(true, true);
#endif
#endif
}
