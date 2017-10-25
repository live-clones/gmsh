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
//#include "MElement.h"
#include "MQuadrangle.h"
#include "BasisFactory.h"
//#include "MLine.h"
//#include "GmshDefines.h"
#include "legendrePolynomials.h"

namespace BoundaryLayerCurver
{
  static std::map<std::tuple<int, int, int>, LeastSquareData*> leastSquareData;

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
    LeastSquareData *data = new LeastSquareData;
    if (typeElement == TYPE_LIN) {
      data->nbPoints = getNGQLPts(orderGauss);
      data->intPoints = getGQLPts(orderGauss);
      LegendrePolynomials legendre(order);

      int sz1 = order + 1;
      int sz2 = data->nbPoints;
      fullMatrix<double> M2(sz1+2, sz2+2, true);
      {
        double *val = new double[sz1];
        for (int j = 0; j < sz2; ++j) {
          legendre.f(data->intPoints[j].pt[0], val);
          for (int i = 0; i < sz1; ++i) {
            M2(i, j) = 2 * val[i] * data->intPoints[j].weight;
          }
        }
        M2(sz1, sz2) = M2(sz1+1, sz2+1) = 1;
        delete val;
      }

      fullMatrix<double> M1(sz1+2, sz1+2, true);
      for (int k = 0; k < sz1; ++k) {
        const int sign = k % 2 == 0 ? 1 : -1;
        M1(sz1, k) = M1(k, sz1) = sign;
        M1(sz1+1, k) = M1(k, sz1+1) = 1;
        M1(k, k) = 4 / (1 + 2*k);
      }
      fullMatrix<double> invM1;
      M1.invert(invM1);

      fullMatrix<double> Leg2Lag(sz1+2, sz1+2, true);
      {
        int tagLine = ElementType::getTag(TYPE_LIN, order);
        const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);
        const fullMatrix<double> &refNodes = fs->getReferenceNodes();
        double *val = new double[sz1];
        for (int i = 0; i < sz1; ++i) {
          legendre.f(refNodes(i, 0), val);
          for (int j = 0; j < sz1; ++j) {
            Leg2Lag(i, j) = val[j];
          }
        }
        Leg2Lag(sz1, sz1) = Leg2Lag(sz1+1, sz1+1) = 1;
      }

      fullMatrix<double> &tmp = M1;
      tmp.resize(sz1+2, sz2+2, false);
      invM1.mult(M2, tmp);

      fullMatrix<double> &tmp2 = M2;
      tmp2.resize(sz1+2, sz2+2, false);
      Leg2Lag.mult(tmp, tmp2);

      data->invA.resize(sz1, sz2+2, false);
      data->invA.copy(tmp2, 0, sz1, 0, sz2+2, 0, 0);
    }
    else if (typeElement == TYPE_QUA) {
      Msg::Error("Implement data for quad");
    }
    else if (typeElement == TYPE_TRI) {
      Msg::Error("Implement data for tri");
    }
  }

  LeastSquareData* getLeastSquareData(int typeElement, int order,
                                      int orderGauss)
  {
    std::tuple<int, int, int> typeOrder(typeElement, order, orderGauss);
    auto it = leastSquareData.find(typeOrder);

    if (it != leastSquareData.end()) return it->second;

    LeastSquareData *data = constructLeastSquareData(typeElement, order,
                                                     orderGauss);
    leastSquareData[typeOrder] = data;
    return data;
  }

  void computeExtremityCoefficients(const std::vector<MVertex*> &baseVert,
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
        const MVertex *v = baseVert[j];
        dx += sf[j][0] * v->x();
        dy += sf[j][0] * v->y();
        dz += sf[j][0] * v->z();
      }

      t = SVector3(dx, dy, dz).normalize();
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
        const MVertex *v = baseVert[j];
        dx += sf[j][0] * v->x();
        dy += sf[j][0] * v->y();
        dz += sf[j][0] * v->z();
      }

      t = SVector3(dx, dy, dz).normalize();
      n = crossprod(w, t);
      h = SVector3(topVert[1]->x() - baseVert[1]->x(),
                   topVert[1]->y() - baseVert[1]->y(),
                   topVert[1]->z() - baseVert[1]->z());
    }
    parameters.thickness[1] = dot(h, n);
    parameters.coeffb[1] = dot(h, t);
  }

  void idealPositionTopEdge(const std::vector<MVertex *> &baseVert,
                            Parameters2DCurve &parameters, SVector3 w,
                            int nbPoints, const IntPt *points,
//                            double *x, double *y, double *z)
                            fullMatrix<double> xyz)
  {
    int tagLine = ElementType::getTag(TYPE_LIN, baseVert.size()-1);
    const nodalBasis *fs = BasisFactory::getNodalBasis(tagLine);

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
          xc += f[j] * v->x();
          yc += f[j] * v->y();
          zc += f[j] * v->z();
          dx += sf[j][0] * v->x();
          dy += sf[j][0] * v->y();
          dz += sf[j][0] * v->z();
        }
      }
      SVector3 t, n, h;
      t = SVector3(dx, dy, dz).normalize();
      n = crossprod(w, t);
      h = parameters.thicknessAtPoint(xi) * n + parameters.coeffbAtPoint(xi) * t;
      xyz(i, 0) = xc + h.x();
      xyz(i, 1) = yc + h.y();
      xyz(i, 2) = zc + h.z();
    }
  }

  void computePositionTopVert(const std::vector<MVertex*> &baseVert,
                              std::vector<MVertex*> &topVert,
                              Parameters2DCurve &parameters,
                              SVector3 e3)
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

    const int orderCurve = baseVert.size() - 1;
    const int orderGauss = orderCurve * 2;
    const int sizeSystem = getNGQLPts(orderGauss);
    const IntPt *gaussPnts = getGQLPts(orderGauss);

    fullMatrix<double> xyz(sizeSystem + 2, 3);
    idealPositionTopEdge(baseVert, parameters, e3, sizeSystem, gaussPnts, xyz);
    xyz(sizeSystem, 0) = topVert[0]->x();
    xyz(sizeSystem, 1) = topVert[0]->y();
    xyz(sizeSystem, 2) = topVert[0]->z();
    xyz(sizeSystem+1, 0) = topVert[1]->x();
    xyz(sizeSystem+1, 1) = topVert[1]->y();
    xyz(sizeSystem+1, 2) = topVert[1]->z();
//    double *x = new double[sizeSystem];
//    double *y = new double[sizeSystem];
//    double *z = new double[sizeSystem];
//    idealPositionTopEdge(baseVert, parameters, e3, sizeSystem, gaussPnts, x, y, z);

//    // Project into a global reference frame {e1, e2, e3}
//    SVector3 e1(0, 0, 0), e2;
//    double *u = new double[sizeSystem];
//    double *v = new double[sizeSystem];
//    {
//      int k = 0;
//      if (std::abs(e3(1)) > std::abs(e3(k))) k = 1;
//      if (std::abs(e3(2)) > std::abs(e3(k))) k = 2;
//      e1((k + 1) % 3) = 1;
//      e2 = crossprod(e3, e1).normalize();
//      e1 = crossprod(e2, e3);
//
//      for (int i = 0; i < sizeSystem; ++i) {
//        SVector3 h(x[i], y[i], z[i]);
//        u[i] = dot(h, e1);
//        v[i] = dot(h, e2);
//      }
//    }

    LeastSquareData *data = getLeastSquareData(TYPE_LIN, orderCurve, orderGauss);

    fullMatrix<double> newxyz(orderCurve + 1, 3);
    data->invA.mult(xyz, newxyz);

    std::cout << newxyz(0, 0) - topVert[0]->x() << " "
              << newxyz(0, 1) - topVert[0]->y() << " "
              << newxyz(0, 2) - topVert[0]->z() << " "
              << newxyz(1, 0) - topVert[1]->x() << " "
              << newxyz(1, 1) - topVert[1]->y() << " "
              << newxyz(1, 2) - topVert[1]->z() << std::endl;

    for (int i = 2; i < topVert.size(); ++i) {
      topVert[i]->x() = newxyz(i, 0);
      topVert[i]->y() = newxyz(i, 1);
      topVert[i]->z() = newxyz(i, 2);
    }

//    for (int i = 0; i < sizeSystem; ++i) {
//      x[i] =
//    }

//    delete x;
//    delete y;
//    delete z;
//    delete u;
//    delete v;
  }

  void curve2DTriColumn(MElement *bottomEdge, std::vector<MElement *> &column,
                        SVector3 w)
  {
    for (int i = 0; i < column.size(); i += 2) {
      MElement *tri0 = column[i];
      MElement *tri1 = column[i + 1];
    }
  }

  void curve2DQuadColumn(MElement *bottomEdge, std::vector<MElement *> &column,
                         SVector3 w)
  {
    MEdge bottom(bottomEdge->getVertex(0), bottomEdge->getVertex(1));
    std::vector<MVertex *> bottomVertices, topVertices;
    for (int i = 0; i < column.size(); ++i) {
      MQuadrangle *quad = dynamic_cast<MQuadrangle *>(column[i]);
      int iBottom, sign;
      quad->getEdgeInfo(bottom, iBottom, sign);
      if (iBottom != 0) {
        quad->reorient(4 - iBottom, false);
      }
      quad->getEdgeVertices(0, bottomVertices);
      quad->getEdgeVertices(2, topVertices);
      std::reverse(topVertices.begin(), topVertices.begin() + 2);
      std::reverse(topVertices.begin() + 2, topVertices.end());

//      Parameters2DCurve parameters;
//      computeExtremityCoefficients(bottomVertices, topVertices, parameters, w);
    }
  }

}


void curve2DBoundaryLayer(VecPairMElemVecMElem &bndEl2column, SVector3 n)
{
//  // Compute reference frame (handle general planar 2D BL)
//  int k = 0;
//  if (std::abs(n(1)) > std::abs(n(k))) k = 1;
//  if (std::abs(n(2)) > std::abs(n(k))) k = 2;
//  SVector3 u(0, 0, 0);
//  u((k+1) % 3) = 1;
//  SVector3 v = crossprod(n, u).normalize();
//  u = crossprod(v, n);

#ifdef _OPENMP
#pragma omp for
#endif
  for (int i = 0; i < bndEl2column.size(); ++i) {
    MElement *bottomEdge = bndEl2column[i].first;
    std::vector<MElement*> &column = bndEl2column[i].second;
    if (column[0]->getType() == TYPE_TRI)
      BoundaryLayerCurver::curve2DTriColumn(bottomEdge, column, n);
    else
      BoundaryLayerCurver::curve2DQuadColumn(bottomEdge, column, n);
  }
}

void curve3DBoundaryLayer(VecPairMElemVecMElem &bndEl2column)
{

}
