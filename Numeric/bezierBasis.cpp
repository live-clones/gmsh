// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <map>
#include <algorithm>
#include "bezierBasis.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "Numeric.h"
#include "JacobianBasis.h" //FIXMEDEBUG

namespace {

  // Exponents:
  void generateExponents(FuncSpaceData data, fullMatrix<double> &exp)
  {
    gmshGenerateOrderedMonomials(data, exp);
  }
  void generateBezierPoints(FuncSpaceData data, fullMatrix<double> &points)
  {
    // FIXME: to be removed with JACOBIAN_ORDERED
    gmshGenerateMonomials(data, points);
//    points.print("monomials");
    if (data.getType() != TYPE_PYR)
      points.scale(1. / data.getSpaceOrder());
    else {
      // For pyramids, the space is tensorial (like the hex). The bezier
      // points are on a grid (like the hex).
      fullMatrix<double> prox;
      prox.setAsProxy(points, 2, 1);
      prox.scale(-1);
      prox.add(data.getNk());
      points.scale(1. / data.getSpaceOrder());
    }
  }

  // Sub Control Points
  std::vector<fullMatrix<double> > generateSubPointsLine(int order)
  {
    std::vector<fullMatrix<double> > subPoints(2);

#if defined(JACOBIAN_ORDERED)
    FuncSpaceData data(TYPE_LIN, order, false);
    gmshGenerateOrderedPoints(data, subPoints[0], true);
    subPoints[0].scale(.5);
#else
    subPoints[0] = gmshGenerateMonomialsLine(order);
    subPoints[0].scale(.5 / order);
#endif

    subPoints[1].copy(subPoints[0]);
    subPoints[1].add(.5);
    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsTriangle(int order)
  {
    std::vector<fullMatrix<double> > subPoints(4);
    fullMatrix<double> prox;

#if defined(JACOBIAN_ORDERED)
    FuncSpaceData data(TYPE_TRI, order, false);
    gmshGenerateOrderedPoints(data, subPoints[0], true);
    subPoints[0].scale(.5);
#else
    subPoints[0] = gmshGenerateMonomialsTriangle(order);
    subPoints[0].scale(.5 / order);
#endif

    subPoints[1].copy(subPoints[0]);
    prox.setAsProxy(subPoints[1], 0, 1);
    prox.add(.5);

    subPoints[2].copy(subPoints[0]);
    prox.setAsProxy(subPoints[2], 1, 1);
    prox.add(.5);

    subPoints[3].copy(subPoints[0]);
    subPoints[3].scale(-1.);
    subPoints[3].add(.5);
    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsQuad(int order)
  {
    std::vector<fullMatrix<double> > subPoints(4);
    fullMatrix<double> prox;

#if defined(JACOBIAN_ORDERED)
    FuncSpaceData data(TYPE_QUA, order, false);
    gmshGenerateOrderedPoints(data, subPoints[0], true);
    subPoints[0].scale(.5);
#else
    subPoints[0] = gmshGenerateMonomialsQuadrangle(order);
    subPoints[0].scale(.5 / order);
#endif

    subPoints[1].copy(subPoints[0]);
    prox.setAsProxy(subPoints[1], 0, 1);
    prox.add(.5);

    subPoints[2].copy(subPoints[0]);
    prox.setAsProxy(subPoints[2], 1, 1);
    prox.add(.5);

    subPoints[3].copy(subPoints[1]);
    prox.setAsProxy(subPoints[3], 1, 1);
    prox.add(.5);
    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsTetrahedron(int order)
  {
    std::vector<fullMatrix<double> > subPoints(8);
    fullMatrix<double> prox1;
    fullMatrix<double> prox2;

#if defined(JACOBIAN_ORDERED)
    FuncSpaceData data(TYPE_TET, order, false);
    gmshGenerateOrderedPoints(data, subPoints[0], true);
    subPoints[0].scale(.5);
#else
    subPoints[0] = gmshGenerateMonomialsTetrahedron(order);
    subPoints[0].scale(.5 / order);
#endif

    subPoints[1].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[1], 0, 1);
    prox1.add(.5);

    subPoints[2].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[2], 1, 1);
    prox1.add(.5);

    subPoints[3].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[3], 2, 1);
    prox1.add(.5);

    // u := .5-u-w
    // v := .5-v-w
    // w := w
    subPoints[4].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[4], 0, 2);
    prox1.scale(-1.);
    prox1.add(.5);
    prox1.setAsProxy(subPoints[4], 0, 1);
    prox2.setAsProxy(subPoints[4], 2, 1);
    prox1.add(prox2, -1.);
    prox1.setAsProxy(subPoints[4], 1, 1);
    prox1.add(prox2, -1.);

    // u := u
    // v := .5-v
    // w := w+v
    subPoints[5].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[5], 2, 1);
    prox2.setAsProxy(subPoints[5], 1, 1);
    prox1.add(prox2);
    prox2.scale(-1.);
    prox2.add(.5);

    // u := .5-u
    // v := v
    // w := w+u
    subPoints[6].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[6], 2, 1);
    prox2.setAsProxy(subPoints[6], 0, 1);
    prox1.add(prox2);
    prox2.scale(-1.);
    prox2.add(.5);

    // u := u+w
    // v := v+w
    // w := .5-w
    subPoints[7].copy(subPoints[0]);
    prox1.setAsProxy(subPoints[7], 0, 1);
    prox2.setAsProxy(subPoints[7], 2, 1);
    prox1.add(prox2);
    prox1.setAsProxy(subPoints[7], 1, 1);
    prox1.add(prox2);
    prox2.scale(-1.);
    prox2.add(.5);

    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsPrism(int order)
  {
    std::vector<fullMatrix<double> > subPoints(8);
    fullMatrix<double> prox;

#if defined(JACOBIAN_ORDERED)
    FuncSpaceData data(TYPE_PRI, order, false);
    gmshGenerateOrderedPoints(data, subPoints[0], true);
    subPoints[0].scale(.5);
#else
    subPoints[0] = gmshGenerateMonomialsPrism(order);
    subPoints[0].scale(.5 / order);
#endif

    subPoints[1].copy(subPoints[0]);
    prox.setAsProxy(subPoints[1], 0, 1);
    prox.add(.5);

    subPoints[2].copy(subPoints[0]);
    prox.setAsProxy(subPoints[2], 1, 1);
    prox.add(.5);

    subPoints[3].copy(subPoints[0]);
    prox.setAsProxy(subPoints[3], 0, 2);
    prox.scale(-1.);
    prox.add(.5);

    subPoints[4].copy(subPoints[0]);
    prox.setAsProxy(subPoints[4], 2, 1);
    prox.add(.5);

    subPoints[5].copy(subPoints[1]);
    prox.setAsProxy(subPoints[5], 2, 1);
    prox.add(.5);

    subPoints[6].copy(subPoints[2]);
    prox.setAsProxy(subPoints[6], 2, 1);
    prox.add(.5);

    subPoints[7].copy(subPoints[3]);
    prox.setAsProxy(subPoints[7], 2, 1);
    prox.add(.5);

    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsHex(int order)
  {
    std::vector<fullMatrix<double> > subPoints(8);
    fullMatrix<double> prox;

#if defined(JACOBIAN_ORDERED)
    FuncSpaceData data(TYPE_HEX, order, false);
    gmshGenerateOrderedPoints(data, subPoints[0], true);
    subPoints[0].scale(.5);
#else
    subPoints[0] = gmshGenerateMonomialsHexahedron(order);
    subPoints[0].scale(.5 / order);
#endif

    subPoints[1].copy(subPoints[0]);
    prox.setAsProxy(subPoints[1], 0, 1);
    prox.add(.5);

    subPoints[2].copy(subPoints[0]);
    prox.setAsProxy(subPoints[2], 1, 1);
    prox.add(.5);

    subPoints[3].copy(subPoints[1]);
    prox.setAsProxy(subPoints[3], 1, 1);
    prox.add(.5);

    subPoints[4].copy(subPoints[0]);
    prox.setAsProxy(subPoints[4], 2, 1);
    prox.add(.5);

    subPoints[5].copy(subPoints[1]);
    prox.setAsProxy(subPoints[5], 2, 1);
    prox.add(.5);

    subPoints[6].copy(subPoints[2]);
    prox.setAsProxy(subPoints[6], 2, 1);
    prox.add(.5);

    subPoints[7].copy(subPoints[3]);
    prox.setAsProxy(subPoints[7], 2, 1);
    prox.add(.5);

    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsPyr(int nij, int nk)
  {
    // Note: We suppose that the space is hex-like because  subpoint is for
    // subdivision and pyramidal space is not subdivable.
    if(nk == 0) { // quad-like space
      std::vector<fullMatrix<double> > subPoints(4);
      fullMatrix<double> prox;

#if defined(JACOBIAN_ORDERED)
      FuncSpaceData data(TYPE_PYR, false, nij, nk, false);
      gmshGenerateOrderedPoints(data, subPoints[0], true);
      subPoints[0].scale(.5);
#else
      subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, nij, nk);
      subPoints[0].scale(.5 / nij);
#endif

      subPoints[1].copy(subPoints[0]);
      prox.setAsProxy(subPoints[1], 0, 1);
      prox.add(.5);

      subPoints[2].copy(subPoints[0]);
      prox.setAsProxy(subPoints[2], 1, 1);
      prox.add(.5);

      subPoints[3].copy(subPoints[1]);
      prox.setAsProxy(subPoints[3], 1, 1);
      prox.add(.5);

      return subPoints;
    }
    else { // hex-like space
      std::vector<fullMatrix<double> > subPoints(8);
      fullMatrix<double> prox;

#if defined(JACOBIAN_ORDERED)
      FuncSpaceData data(TYPE_PYR, false, nij, nk, false);
      gmshGenerateOrderedPoints(data, subPoints[0], true);
      subPoints[0].scale(.5);
#else
      subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, nij, nk);
      prox.setAsProxy(subPoints[0], 2, 1);
      prox.scale(-1);
      prox.add(nk);
      subPoints[0].scale(.5 / std::max(nij, nk));
#endif

      subPoints[1].copy(subPoints[0]);
      prox.setAsProxy(subPoints[1], 0, 1);
      prox.add(.5);

      subPoints[2].copy(subPoints[0]);
      prox.setAsProxy(subPoints[2], 1, 1);
      prox.add(.5);

      subPoints[3].copy(subPoints[1]);
      prox.setAsProxy(subPoints[3], 1, 1);
      prox.add(.5);

      subPoints[4].copy(subPoints[0]);
      prox.setAsProxy(subPoints[4], 2, 1);
      prox.add(.5);

      subPoints[5].copy(subPoints[1]);
      prox.setAsProxy(subPoints[5], 2, 1);
      prox.add(.5);

      subPoints[6].copy(subPoints[2]);
      prox.setAsProxy(subPoints[6], 2, 1);
      prox.add(.5);

      subPoints[7].copy(subPoints[3]);
      prox.setAsProxy(subPoints[7], 2, 1);
      prox.add(.5);

#if defined(JACOBIAN_ORDERED)
      // Nothing to do
#else
      for(int i = 0; i < 8; ++i) {
        prox.setAsProxy(subPoints[i], 2, 1);
        prox.scale(-1);
        prox.add(1);
      }
#endif

      return subPoints;
    }
  }

  // Matrices generation
  int nChoosek(int n, int k)
  {
    if(n < k || k < 0) {
      Msg::Error("Wrong argument for combination. (%d, %d)", n, k);
      return 1;
    }

    if(k > n / 2) k = n - k;
    if(k == 1) return n;
    if(k == 0) return 1;

    int c = 1;
    for(int i = 1; i <= k; i++, n--) (c *= n) /= i;
    return c;
  }

  fullMatrix<double> generateBez2LagMatrix(const fullMatrix<double> &exponent,
                                           const fullMatrix<double> &point,
                                           int order, int dimSimplex)
  {
    if(exponent.size1() != point.size1() || exponent.size2() != point.size2()) {
      Msg::Error("Wrong sizes for bez2lag matrix generation %d %d -- %d %d",
                 exponent.size1(), point.size1(), exponent.size2(),
                 point.size2());
      return fullMatrix<double>(1, 1);
    }

    int ndofs = exponent.size1();
    int dim = exponent.size2();

    fullMatrix<double> bez2Lag(ndofs, ndofs);
    for(int i = 0; i < ndofs; i++) {
      for(int j = 0; j < ndofs; j++) {
        double dd = 1.;
        {
          double pointCompl = 1.;
          int exponentCompl = order;
          for(int k = 0; k < dimSimplex; k++) {
            dd *= nChoosek(exponentCompl, (int)exponent(i, k)) *
                  pow(point(j, k), exponent(i, k));
            pointCompl -= point(j, k);
            exponentCompl -= (int)exponent(i, k);
          }
          dd *= pow(pointCompl, exponentCompl);
        }

        for(int k = dimSimplex; k < dim; k++)
          dd *= nChoosek(order, (int)exponent(i, k)) *
                pow(point(j, k), exponent(i, k)) *
                pow(1. - point(j, k), order - exponent(i, k));

        bez2Lag(j, i) = dd;
      }
    }
    return bez2Lag;
  }

  fullMatrix<double>
  generateBez2LagMatrixPyramid(const fullMatrix<double> &exponent,
                               const fullMatrix<double> &point, bool pyr,
                               int nij, int nk)
  {
    // For pyramids, the space is hex-like and thus tensorial.
    // 'point' is the list of points on a grid.
    if(exponent.size1() != point.size1() || exponent.size2() != point.size2() ||
       exponent.size2() != 3) {
      Msg::Error(
        "Wrong sizes for pyramid's bez2lag matrix generation %d %d -- %d %d",
        exponent.size1(), point.size1(), exponent.size2(), point.size2());
      return fullMatrix<double>(1, 1);
    }

    const int ndofs = exponent.size1();

    int n01 = nij;
    fullMatrix<double> bez2Lag(ndofs, ndofs);
    for(int i = 0; i < ndofs; i++) {
      for(int j = 0; j < ndofs; j++) {
        if(pyr) n01 = exponent(j, 2) + nij;
        bez2Lag(i, j) =
          nChoosek(n01, exponent(j, 0)) *
          nChoosek(n01, exponent(j, 1)) *
          nChoosek(nk, exponent(j, 2)) *
          pow_int(point(i, 0), exponent(j, 0)) *
          pow_int(point(i, 1), exponent(j, 1)) *
          pow_int(point(i, 2), exponent(j, 2)) *
          pow_int(1. - point(i, 0), n01 - exponent(j, 0)) *
          pow_int(1. - point(i, 1), n01 - exponent(j, 1)) *
          pow_int(1. - point(i, 2), nk - exponent(j, 2));
      }
    }
    return bez2Lag;
  }

  fullMatrix<double>
  generateSubDivisor(const fullMatrix<double> &exponents,
                     const std::vector<fullMatrix<double> > &subPoints,
                     const fullMatrix<double> &lag2Bez, int order,
                     int dimSimplex)
  {
    if(exponents.size1() != lag2Bez.size1() ||
       exponents.size1() != lag2Bez.size2()) {
      Msg::Error("Wrong sizes for Bezier Divisor %d %d -- %d %d",
                 exponents.size1(), lag2Bez.size1(), exponents.size1(),
                 lag2Bez.size2());
      return fullMatrix<double>(1, 1);
    }

    int nbPts = lag2Bez.size1();
    int nbSubPts = nbPts * subPoints.size();

    fullMatrix<double> intermediate2(nbPts, nbPts);
    fullMatrix<double> subDivisor(nbSubPts, nbPts);

    for(std::size_t i = 0; i < subPoints.size(); i++) {
      fullMatrix<double> intermediate1 =
        generateBez2LagMatrix(exponents, subPoints[i], order, dimSimplex);
      lag2Bez.mult(intermediate1, intermediate2);
      subDivisor.copy(intermediate2, 0, nbPts, 0, nbPts, i * nbPts, 0);
    }
    return subDivisor;
  }

  fullMatrix<double>
  generateSubDivisorPyramid(const fullMatrix<double> &exponents,
                            const std::vector<fullMatrix<double> > &subPoints,
                            const fullMatrix<double> &lag2Bez, bool pyr,
                            int nij, int nk)
  {
    if(exponents.size1() != lag2Bez.size1() ||
       exponents.size1() != lag2Bez.size2()) {
      Msg::Error("Wrong sizes for Bezier Divisor %d %d -- %d %d",
                 exponents.size1(), lag2Bez.size1(), exponents.size1(),
                 lag2Bez.size2());
      return fullMatrix<double>(1, 1);
    }

    int nbPts = lag2Bez.size1();
    int nbSubPts = nbPts * subPoints.size();

    fullMatrix<double> intermediate2(nbPts, nbPts);
    fullMatrix<double> subDivisor(nbSubPts, nbPts);

    for(std::size_t i = 0; i < subPoints.size(); i++) {
      fullMatrix<double> intermediate1 =
        generateBez2LagMatrixPyramid(exponents, subPoints[i], pyr, nij, nk);
      lag2Bez.mult(intermediate1, intermediate2);
      subDivisor.copy(intermediate2, 0, nbPts, 0, nbPts, i * nbPts, 0);
    }
    return subDivisor;
  }

  void double2int(const fullMatrix<double> &matDouble, fullMatrix<int> &matInt)
  {
    matInt.resize(matDouble.size1(), matDouble.size2());
    for(int i = 0; i < matDouble.size1(); ++i) {
      for(int j = 0; j < matDouble.size2(); ++j) {
        matInt(i, j) = static_cast<int>(matDouble(i, j) + .5);
      }
    }
  }

  void generateOneDMatrixLag2Bez(int order, fullMatrix<double> &c)
  {
    c.resize(order + 1, order + 1, true);

    fullVector<double> x(order + 1);
    for(int i = 0; i <= order; ++i) {
      int ii = i == 0 ? 0 : i == 1 ? order : i - 1;
      x(i) = static_cast<double>(ii) / order;
    }
    fullVector<double> w(order + 1);
    fullVector<double> f(order + 1);

    for(int i = 0; i <= order; ++i) {
      f.setAll(0);
      f(i) = 1;
      w.setAll(0);
      w(0) = 1;
      c(0, i) = f(0);
      for(int s = 1; s <= order; ++s) {
        for(int k = order; k >= s; --k) {
          f(k) = (f(k) - f(k - 1)) / (x(k) - x(k - s));
        }
        for(int k = s; k >= 1; --k) {
          const double kk = static_cast<double>(k);
          w(k) =
            kk / s * w(k - 1) * (1 - x(s - 1)) - (1 - kk / s) * w(k) * x(s - 1);
          c(k, i) = kk / s * c(k - 1, i) + (1 - kk / s) * c(k, i) + f(s) * w(k);
        }
        w(0) = -w(0) * x(s - 1);
        c(0, i) = c(0, i) + f(s) * w(0);
      }
    }
  }

  template <typename D>
  void convertLag2Bez(const fullMatrix<double> &lag, int order, int start,
                      int inc, const fullVector<D> &x, fullMatrix<double> &bez)
  {
    // Algorithm to compute Bézier coefficients of f(x), x in [0, 1].
    // f is given by the Lagrange expansion: the coefficients are 'lag'
    // and the corresponding Lagrange basis polynomials are constructed with
    // nodes 'x'. Those nodes should be in [0, 1] if we aim at expanding the
    // "same" function in Bézier interpolation.
    // See this paper for the details:
    // "Computing the Bézier control points of the Lagrangian interpolant in
    // arbitrary dimension" by M. Ainsworth and M. A. Sánchez
    const int nColumns = lag.size2();
    fullMatrix<D> f(order + 1, nColumns);
    for(int i = start, n = 0; n <= order; i += inc, ++n) {
      for(int j = 0; j < nColumns; ++j) {
        f(n, j) = lag(i, j);
      }
    }
    fullVector<D> w(order + 1);
    w.setAll(0);
    w(0) = 1;
    fullMatrix<D> c(order + 1, nColumns);
    for(int j = 0; j < nColumns; ++j) {
      c(0, j) = f(0, j);
    }
    for(int s = 1; s <= order; ++s) {
      for(int k = order; k >= s; --k) {
        for(int j = 0; j < nColumns; ++j) {
          f(k, j) = (f(k, j) - f(k - 1, j)) / (x(k) - x(k - s));
        }
      }
      for(int k = s; k >= 1; --k) {
        const D kk = static_cast<D>(k);
        w(k) =
          kk / s * w(k - 1) * (1 - x(s - 1)) - (1 - kk / s) * w(k) * x(s - 1);
        for(int j = 0; j < nColumns; ++j) {
          c(k, j) =
            kk / s * c(k - 1, j) + (1 - kk / s) * c(k, j) + f(s, j) * w(k);
        }
      }
      w(0) = -w(0) * x(s - 1);
      for(int j = 0; j < nColumns; ++j) {
        c(0, j) = c(0, j) + f(s, j) * w(0);
      }
    }
    for(int i = start, n = 0; n <= order; i += inc, ++n) {
      for(int j = 0; j < nColumns; ++j) {
        bez(i, j) = static_cast<double>(c(n, j));
      }
    }
  }

  void convertLag2Bez(const fullMatrix<double> &lag, int order,
                      const fullVector<double> &x, fullMatrix<double> &bez,
                      int start = -1, int inc = -1)
  {
    if (start < 0) start = 0;
    if (inc < 1) inc = 1;
    convertLag2Bez<double>(lag, order, start, inc, x, bez);
  }

  void lejaOrder(fullVector<double> &x, fullVector<int> &permutation)
  {
    int n = x.size();
    permutation.resize(n);
    for(int i = 0; i < n; ++i) {
      permutation(i) = i;
    }

    int I = 0;
    double m = x(0);
    for(int i = 1; i < n; ++i) {
      if(std::abs(x(i)) > m) {
        I = i;
        m = std::abs(x(i));
      }
    }
    if(I != 0) {
      double temp1 = x(0);
      x(0) = x(I);
      x(I) = temp1;
      int temp2 = permutation(0);
      permutation(0) = permutation(I);
      permutation(I) = temp2;
    }

    fullVector<double> p(n);
    p.setAll(1);
    for(int k = 1; k < n - 1; ++k) {
      for(int i = k; i < n; ++i) {
        p(i) = p(i) * (x(i) - x(k - 1));
      }
      int II = k;
      double mm = p(k);
      for(int i = k + 1; i < n; ++i) {
        if(std::abs(p(i)) > mm) {
          II = i;
          mm = std::abs(p(i));
        }
      }
      if(II != k) {
        double temp1 = x(k);
        x(k) = x(II);
        x(II) = temp1;
        int temp2 = permutation(k);
        permutation(k) = permutation(II);
        permutation(II) = temp2;
        double temp3 = p(k);
        p(k) = p(II);
        p(II) = temp3;
      }
    }
  }

} // namespace

bezierBasis::bezierBasis(FuncSpaceData data) : _data(data), _raiser(NULL)
{
  if(_data.getType() == TYPE_PYR)
    _constructPyr();
  else
    _construct();
}

bezierBasis::~bezierBasis() { delete _raiser; }

void bezierBasis::f(double u, double v, double w, double *sf) const
{
  const int tag = ElementType::getType(_data.getType(), _data.getSpaceOrder());
  const nodalBasis *fs = BasisFactory::getNodalBasis(tag);
  double p[1256];
  // TODO Amaury: change (u,v,w)
  fs->f(u, v, w, p);

  for(int i = 0; i < matrixBez2Lag.size1(); i++) {
    sf[i] = 0.0;
    for(int j = 0; j < matrixBez2Lag.size2(); j++) {
      sf[i] += matrixBez2Lag(j, i) * p[j];
    }
  }
}

void bezierBasis::_fePoints2BezPoints(fullMatrix<double> &points) const
{
  fullMatrix<double> tmp;
  switch(_data.getType()) {
  case TYPE_TRI:
  case TYPE_TET: break;

  case TYPE_LIN:
    tmp.setAsProxy(points, 0, 1);
    tmp.add(1);
    tmp.scale(.5);
    break;

  case TYPE_QUA:
    tmp.setAsProxy(points, 0, 2);
    tmp.add(1);
    tmp.scale(.5);
    break;

  case TYPE_HEX:
    points.add(1);
    points.scale(.5);
    break;

  case TYPE_PRI:
    tmp.setAsProxy(points, 2, 1);
    tmp.add(1);
    tmp.scale(.5);
    break;

  case TYPE_PYR:
    for(int i = 0; i < points.size1(); ++i) {
      points(i, 2) = 1. - points(i, 2);
      points(i, 0) = .5 * (1 + points(i, 0) / points(i, 2));
      points(i, 1) = .5 * (1 + points(i, 1) / points(i, 2));
    }
    break;

  default:
    Msg::Error("_fepoints2BezPoints not implemented for "
               "type of element %d",
               _data.getType());
    return;
  }
}

void bezierBasis::interpolate(const fullMatrix<double> &coeffs,
                              const fullMatrix<double> &uvw,
                              fullMatrix<double> &result, bool bezCoord) const
{
  if(result.size1() != uvw.size1() || result.size2() != coeffs.size2())
    result.resize(uvw.size1(), coeffs.size2());

  fullMatrix<double> bezuvw = uvw;
  if(!bezCoord) _fePoints2BezPoints(bezuvw);

  const int numCoeff = _exponents.size1();
  const int dim = _exponents.size2();
  int order[3];

  for(int m = 0; m < uvw.size1(); ++m) {
    for(int n = 0; n < coeffs.size2(); ++n) result(m, n) = 0;
    for(int i = 0; i < numCoeff; i++) {
      _data.getOrderForBezier(order, _exponents(i, dim - 1));
      double dd = 1;
      double pointCompl = 1.;
      int exponentCompl = order[0];
      for(int k = 0; k < _dimSimplex; k++) {
        dd *= nChoosek(exponentCompl, (int)_exponents(i, k)) *
              pow(bezuvw(m, k), _exponents(i, k));
        pointCompl -= bezuvw(m, k);
        exponentCompl -= (int)_exponents(i, k);
      }
      dd *= pow_int(pointCompl, exponentCompl);

      for(int k = _dimSimplex; k < dim; k++) {
        dd *= nChoosek(order[k], (int)_exponents(i, k)) *
              pow_int(bezuvw(m, k), _exponents(i, k)) *
              pow_int(1. - bezuvw(m, k), order[k] - _exponents(i, k));
      }
      for(int n = 0; n < coeffs.size2(); ++n) result(m, n) += coeffs(i, n) * dd;
    }
  }
}

void bezierBasis::lag2Bez(const fullMatrix<double> &lag,
                          fullMatrix<double> &bez) const
{
  if(lag.size1() != matrixLag2Bez.size1()) {
    Msg::Error("matrix not the right size in lag2Bez function %d vs %d",
               lag.size1(), matrixLag2Bez.size1());
  }
  if(bez.size1() != lag.size1() || bez.size2() != lag.size2()) {
    bez.resize(lag.size1(), lag.size2());
  }
  matrixLag2Bez.mult(lag, bez);
}

void bezierBasis::subdivideBezCoeff(const fullMatrix<double> &coeff,
                                    fullMatrix<double> &subCoeff) const
{
  if(subCoeff.size1() != subDivisor.size1() ||
     subCoeff.size2() != coeff.size2()) {
    subCoeff.resize(subDivisor.size1(), coeff.size2());
  }
  subDivisor.mult(coeff, subCoeff);
}

void bezierBasis::subdivideBezCoeff(const fullVector<double> &coeff,
                                    fullVector<double> &subCoeff) const
{
  if(subCoeff.size() != subDivisor.size1()) {
    subCoeff.resize(subDivisor.size1());
  }
  subDivisor.mult(coeff, subCoeff);
}

void bezierBasis::_construct()
{
  if(_data.getType() == TYPE_PYR) {
    Msg::Error("This bezierBasis constructor is not for pyramids!");
    return;
  }

  std::vector<fullMatrix<double> > subPoints;
  int order = _data.getSpaceOrder();

  switch(_data.getType()) {
  case TYPE_PNT:
    _numLagCoeff = 1;
    _dimSimplex = 0;
    _exponents = gmshGenerateMonomialsLine(0);
    subPoints.push_back(gmshGeneratePointsLine(0));
    break;
  case TYPE_LIN:
    _numLagCoeff = order ? 2 : 1;
    _dimSimplex = 0;
    _exponents = gmshGenerateMonomialsLine(order);
    subPoints = generateSubPointsLine(order);
    break;
  case TYPE_TRI:
    _numLagCoeff = order ? 3 : 1;
    _dimSimplex = 2;
    _exponents = gmshGenerateMonomialsTriangle(order);
    subPoints = generateSubPointsTriangle(order);
    break;
  case TYPE_QUA:
    _numLagCoeff = order ? 4 : 1;
    _dimSimplex = 0;
    _exponents = gmshGenerateMonomialsQuadrangle(order);
    subPoints = generateSubPointsQuad(order);
    break;
  case TYPE_TET:
    _numLagCoeff = order ? 4 : 1;
    _dimSimplex = 3;
    _exponents = gmshGenerateMonomialsTetrahedron(order);
    subPoints = generateSubPointsTetrahedron(order);
    break;
  case TYPE_PRI:
    _numLagCoeff = order ? 6 : 1;
    _dimSimplex = 2;
    _exponents = gmshGenerateMonomialsPrism(order);
    subPoints = generateSubPointsPrism(order);
    break;
  case TYPE_HEX:
    _numLagCoeff = order ? 8 : 1;
    _dimSimplex = 0;
    _exponents = gmshGenerateMonomialsHexahedron(order);
    subPoints = generateSubPointsHex(order);
    break;
  default:
    Msg::Error("Unknown function space for parentType %d", _data.getType());
    return;
  }
  _numDivisions = static_cast<int>(subPoints.size());

  fullMatrix<double> bezSamplingPoints;
#if defined(JACOBIAN_ORDERED)
  gmshGenerateOrderedPoints(_data, bezSamplingPoints, true);
#else
  generateBezierPoints(_data, bezierPoints);
#endif
  generateExponents(_data, _exponents2);

  matrixBez2Lag =
    generateBez2LagMatrix(_exponents, bezSamplingPoints, order, _dimSimplex);
  matrixBez2Lag.invert(matrixLag2Bez);
  matrixBez2Lag2 =
    generateBez2LagMatrix(_exponents2, bezSamplingPoints, order, _dimSimplex);
  matrixBez2Lag2.invert(matrixLag2Bez2);
  subDivisor = generateSubDivisor(_exponents, subPoints, matrixLag2Bez, order,
                                  _dimSimplex);

  if(_data.getType() == TYPE_QUA) {
    fullMatrix<double> oneDPoints = gmshGenerateMonomialsLine(order);
    if(order) oneDPoints.scale(1. / order);
    fullMatrix<double> oneDExponents;
    generateExponents(FuncSpaceData(TYPE_LIN, order, false), oneDExponents);
    fullMatrix<double> oneDMatrixBez2Lag =
      generateBez2LagMatrix(oneDExponents, oneDPoints, order, 0);
    fullMatrix<double> oneDMatrixLag2Bez;
    oneDMatrixBez2Lag.invert(oneDMatrixLag2Bez);
//    fullMatrix<double> b(oneDMatrixLag2Bez);
//    b.reshape(1, oneDMatrixLag2Bez.size1() * oneDMatrixLag2Bez.size2());
//    b.print("oneDMatrixLag2Bez");
    matrixLag2Bez3.resize(matrixLag2Bez2.size1(), matrixLag2Bez2.size2());
    matrixLag2Bez4.resize(matrixLag2Bez2.size1(), matrixLag2Bez2.size2());

    fullMatrix<double> oneDMatrixLag2Bez4;
    generateOneDMatrixLag2Bez(order, oneDMatrixLag2Bez4);

    for(int i = 0; i <= order; ++i) {
      for(int j = 0; j <= order; ++j) {
        int I = i + (order + 1) * j;
        //        std::cout << std::endl;
        for(int k = 0; k <= order; ++k) {
          for(int l = 0; l <= order; ++l) {
            int K = 0;
            while(K < _exponents.size1() &&
                  (_exponents(K, 0) - .5 >= k || _exponents(K, 0) + .5 <= k ||
                   _exponents(K, 1) - .5 >= l || _exponents(K, 1) + .5 <= l))
              ++K;
            if(K == _exponents.size1()) {
              Msg::Error("ARRAGRGRAG");
            }
            int kk = k;
            if(kk == order)
              kk = 1;
            else if(kk != 0)
              ++kk;
            int ll = l;
            if(ll == order)
              ll = 1;
            else if(ll != 0)
              ++ll;
            matrixLag2Bez3(I, K) =
              oneDMatrixLag2Bez(i, kk) * oneDMatrixLag2Bez(j, ll);
            matrixLag2Bez4(I, K) =
              oneDMatrixLag2Bez4(i, kk) * oneDMatrixLag2Bez4(j, ll);
          }
        }
      }
    }
  }

  //  matrixBez2Lag.print("matrixBez2Lag");
  //  matrixBez2Lag2.print("matrixBez2Lag2");
  //  matrixLag2Bez.print("matrixLag2Bez");
  //  matrixLag2Bez2.print("matrixLag2Bez2");

  gmshGenerateOrderedPointsLine(order, ordered1dBezPoints);
}

void bezierBasis::_constructPyr()
{
  if(_data.getType() != TYPE_PYR) {
    Msg::Error("This bezierBasis constructor is for pyramids!");
  }

  const bool pyr = _data.getPyramidalSpace();
  const int nij = _data.getNij(), nk = _data.getNk();

  _numLagCoeff = nk == 0 ? 4 : 8;
  _dimSimplex = 0;
  gmshGenerateMonomials(_data, _exponents);

  // Note that the sampling points for the Jacobian determinant of pyramids are
  // for z in [0, a] with a < 1. The third coordinate of Bezier points should
  // also be in [0, a]. The same for subpoints.
  fullMatrix<double> bezierPoints;
#if defined(JACOBIAN_ORDERED)
  gmshGenerateOrderedPoints(_data, bezierPoints, true);
#else
  generateBezierPoints(_data, bezierPoints);
#endif
  generateExponents(_data, _exponents2);
  matrixBez2Lag =
    generateBez2LagMatrixPyramid(_exponents, bezierPoints, pyr, nij, nk);
  matrixBez2Lag.invert(matrixLag2Bez);
  matrixBez2Lag2 =
    generateBez2LagMatrixPyramid(_exponents2, bezierPoints, pyr, nij, nk);
  matrixBez2Lag2.invert(matrixLag2Bez2);
  if(pyr) {
    _numDivisions = 0;
  }
  else {
    std::vector<fullMatrix<double> > subPoints;
    subPoints = generateSubPointsPyr(nij, nk);
    _numDivisions = static_cast<int>(subPoints.size());
    subDivisor = generateSubDivisorPyramid(_exponents, subPoints, matrixLag2Bez,
                                           pyr, nij, nk);
  }
}

bezierBasisRaiser *bezierBasis::getRaiser() const
{
  if(!_raiser) {
    const_cast<bezierBasis *>(this)->_raiser = new bezierBasisRaiser(this);
  }
  return _raiser;
}

void bezierBasisRaiser::_fillRaiserData()
{
  if(_bfs->getType() == TYPE_PYR) {
    _fillRaiserDataPyr();
    return;
  }

  fullMatrix<int> exp;
  fullMatrix<int> expNew;
  {
    const fullMatrix<double> &expD = _bfs->_exponents;
    const fullMatrix<double> &expDNew = _bfs->_exponents2;
    double2int(expD, exp);
    double2int(expDNew, expNew);
  }
  int order = _bfs->getOrder();
  int ncoeff = exp.size1();
  int dim = _bfs->getDim();
  int dimSimplex = _bfs->getDimSimplex();

  // Speedup: Since the coefficients (num/den) are invariant from a permutation
  // of the indices (i, j) or (i, j, k), we fill only the raiser data for
  // i <= j <= k (and adapt the value to take into account the multiplicity).

  std::map<int, int> hashToInd2;
  std::map<int, int> hashToInd2New;
  {
    // Construction of raiser 2
    fullMatrix<int> exp2;
    fullMatrix<int> exp2New; // FIXME: delete one of them
    {
      fullMatrix<double> expD2;
      FuncSpaceData dataRaiser2(_bfs->_data, 2 * order);
      gmshGenerateMonomials(dataRaiser2, expD2);
      double2int(expD2, exp2);
      _raiser2.resize(exp2.size1());
      fullMatrix<double> expD2New;
      FuncSpaceData data(_bfs->_data, 2 * order);
      generateExponents(data, expD2New);
      double2int(expD2New, exp2New);
      _raiser2New.resize(exp2New.size1());
    }

    //    std::map<int, int> hashToInd2;
    for(int i = 0; i < exp2.size1(); ++i) {
      int hash = 0;
      for(int l = 0; l < dim; l++) {
        hash += static_cast<int>(exp2(i, l) * pow_int(2 * order + 1, l));
      }
      hashToInd2[hash] = i;
    }
    //    std::map<int, int> hashToInd2New;
    for(int i = 0; i < exp2New.size1(); ++i) {
      int hash = 0;
      for(int l = 0; l < dim; l++) {
        hash += static_cast<int>(exp2New(i, l) * pow_int(2 * order + 1, l));
      }
      hashToInd2New[hash] = i;
    }
  }

  for(int i = 0; i < ncoeff; i++) {
    for(int j = i; j < ncoeff; j++) {
      double num = 1, den = 1;
      {
        int compl1 = order;
        int compl2 = order;
        int compltot = 2 * order;
        for(int l = 0; l < dimSimplex; l++) {
          num *= nChoosek(compl1, exp(i, l)) * nChoosek(compl2, exp(j, l));
          den *= nChoosek(compltot, exp(i, l) + exp(j, l));
          compl1 -= exp(i, l);
          compl2 -= exp(j, l);
          compltot -= exp(i, l) + exp(j, l);
        }
        for(int l = dimSimplex; l < dim; l++) {
          num *= nChoosek(order, exp(i, l)) * nChoosek(order, exp(j, l));
          den *= nChoosek(2 * order, exp(i, l) + exp(j, l));
        }
      }
      double numNew = 1, denNew = 1;
      {
        int compl1 = order;
        int compl2 = order;
        int compltot = 2 * order;
        for(int l = 0; l < dimSimplex; l++) {
          numNew *=
            nChoosek(compl1, expNew(i, l)) * nChoosek(compl2, expNew(j, l));
          denNew *= nChoosek(compltot, expNew(i, l) + expNew(j, l));
          compl1 -= expNew(i, l);
          compl2 -= expNew(j, l);
          compltot -= expNew(i, l) + expNew(j, l);
        }
        for(int l = dimSimplex; l < dim; l++) {
          numNew *=
            nChoosek(order, expNew(i, l)) * nChoosek(order, expNew(j, l));
          denNew *= nChoosek(2 * order, expNew(i, l) + expNew(j, l));
        }
      }

      // taking into account the multiplicity (reminder: i <= j)
      if(i < j) num *= 2;
      if(i < j) numNew *= 2;

      int hash = 0;
      for(int l = 0; l < dim; l++) {
        hash +=
          static_cast<int>((exp(i, l) + exp(j, l)) * pow_int(2 * order + 1, l));
      }
      _raiser2[hashToInd2[hash]].push_back(_data(num / den, i, j));

      int hashNew = 0;
      for(int l = 0; l < dim; l++) {
        hashNew += static_cast<int>((expNew(i, l) + expNew(j, l)) *
                                    pow_int(2 * order + 1, l));
      }
      _raiser2New[hashToInd2New[hashNew]].push_back(
        _data(numNew / denNew, i, j));
    }
  }

  // Construction of raiser 3
  std::map<int, int> hashToInd3;
  std::map<int, int> hashToInd3New;
  {
    fullMatrix<int> exp3;
    fullMatrix<int> exp3New; // FIXME: delete one of them
    {
      fullMatrix<double> expD3;
      FuncSpaceData dataRaiser3(_bfs->_data, 3 * order);
      gmshGenerateMonomials(dataRaiser3, expD3);
      double2int(expD3, exp3);
      _raiser3.resize(exp3.size1());
      fullMatrix<double> expD3New;
      FuncSpaceData data(_bfs->_data, 3 * order);
      generateExponents(data, expD3New);
      double2int(expD3New, exp3New);
      _raiser3New.resize(exp3New.size1());
    }

    //    std::map<int, int> hashToInd3;
    for(int i = 0; i < exp3.size1(); ++i) {
      int hash = 0;
      for(int l = 0; l < dim; l++) {
        hash += static_cast<int>(exp3(i, l) * pow_int(3 * order + 1, l));
      }
      hashToInd3[hash] = i;
    }
    //    std::map<int, int> hashToInd3New;
    for(int i = 0; i < exp3New.size1(); ++i) {
      int hash = 0;
      for(int l = 0; l < dim; l++) {
        hash += static_cast<int>(exp3New(i, l) * pow_int(3 * order + 1, l));
      }
      hashToInd3New[hash] = i;
    }
  }

  for(int i = 0; i < ncoeff; i++) {
    for(int j = i; j < ncoeff; j++) {
      for(int k = j; k < ncoeff; ++k) {
        double num = 1, den = 1;
        {
          int compl1 = order;
          int compl2 = order;
          int compl3 = order;
          int compltot = 3 * order;
          for(int l = 0; l < dimSimplex; l++) {
            num *= nChoosek(compl1, exp(i, l)) * nChoosek(compl2, exp(j, l)) *
                   nChoosek(compl3, exp(k, l));
            den *= nChoosek(compltot, exp(i, l) + exp(j, l) + exp(k, l));
            compl1 -= exp(i, l);
            compl2 -= exp(j, l);
            compl3 -= exp(k, l);
            compltot -= exp(i, l) + exp(j, l) + exp(k, l);
          }
          for(int l = dimSimplex; l < dim; l++) {
            num *= nChoosek(order, exp(i, l)) * nChoosek(order, exp(j, l)) *
                   nChoosek(order, exp(k, l));
            den *= nChoosek(3 * order, exp(i, l) + exp(j, l) + exp(k, l));
          }
        }

        double numNew = 1, denNew = 1;
        {
          int compl1 = order;
          int compl2 = order;
          int compl3 = order;
          int compltot = 3 * order;
          for(int l = 0; l < dimSimplex; l++) {
            numNew *= nChoosek(compl1, expNew(i, l)) *
                      nChoosek(compl2, expNew(j, l)) *
                      nChoosek(compl3, expNew(k, l));
            denNew *=
              nChoosek(compltot, expNew(i, l) + expNew(j, l) + expNew(k, l));
            compl1 -= expNew(i, l);
            compl2 -= expNew(j, l);
            compl3 -= expNew(k, l);
            compltot -= expNew(i, l) + expNew(j, l) + expNew(k, l);
          }
          for(int l = dimSimplex; l < dim; l++) {
            numNew *= nChoosek(order, expNew(i, l)) *
                      nChoosek(order, expNew(j, l)) *
                      nChoosek(order, expNew(k, l));
            denNew *=
              nChoosek(3 * order, expNew(i, l) + expNew(j, l) + expNew(k, l));
          }
        }

        // taking into account the multiplicity (Reminder: i <= j <= k)
        if(i < j && j < k)
          num *= 6;
        else if(i < j || j < k)
          num *= 3;
        if(i < j && j < k)
          numNew *= 6;
        else if(i < j || j < k)
          numNew *= 3;

        int hash = 0;
        for(int l = 0; l < dim; l++) {
          hash += static_cast<int>((exp(i, l) + exp(j, l) + exp(k, l)) *
                                   pow_int(3 * order + 1, l));
        }
        _raiser3[hashToInd3[hash]].push_back(_data(num / den, i, j, k));
        int hashNew = 0;
        for(int l = 0; l < dim; l++) {
          hashNew +=
            static_cast<int>((expNew(i, l) + expNew(j, l) + expNew(k, l)) *
                             pow_int(3 * order + 1, l));
        }
        _raiser3New[hashToInd3New[hashNew]].push_back(
          _data(numNew / denNew, i, j, k));
      }
    }
  }
}

void bezierBasisRaiser::_fillRaiserDataPyr()
{
  FuncSpaceData fsdata = _bfs->getFuncSpaceData();
  if(fsdata.getType() != TYPE_PYR) {
    _fillRaiserData();
    return;
  }
  if(fsdata.getPyramidalSpace()) {
    Msg::Error("Bezier raiser not implemented for pyramidal space");
    return;
  }

  fullMatrix<int> exp;
  {
    const fullMatrix<double> &expD = _bfs->_exponents;
    double2int(expD, exp);
  }
  int ncoeff = exp.size1();
  int order[3] = {fsdata.getNij(), fsdata.getNij(), fsdata.getNk()};
  int orderHash = std::max(order[0], order[1]);

  // Speedup: Since the coefficients (num/den) are invariant from a permutation
  // of the indices (i, j) or (i, j, k), we fill only the raiser data for i <= j
  // <= k (and adapt the value to take into account the multiplicity).

  // Construction of raiser 2
  fullMatrix<int> exp2;
  {
    fullMatrix<double> expD2;
    FuncSpaceData dataRaiser2(_bfs->_data, 2 * order[0], 2 * order[2]);
    gmshGenerateMonomials(dataRaiser2, expD2);
    double2int(expD2, exp2);
    _raiser2.resize(exp2.size1());
  }

  std::map<int, int> hashToInd2;
  for(int i = 0; i < exp2.size1(); ++i) {
    int hash = 0;
    for(int l = 0; l < 3; l++) {
      hash += exp2(i, l) * pow_int(2 * orderHash + 1, l);
    }
    hashToInd2[hash] = i;
  }

  for(int i = 0; i < ncoeff; i++) {
    for(int j = i; j < ncoeff; j++) {
      double num = 1, den = 1;
      for(int l = 0; l < 3; l++) {
        num *= nChoosek(order[l], exp(i, l)) * nChoosek(order[l], exp(j, l));
        den *= nChoosek(2 * order[l], exp(i, l) + exp(j, l));
      }

      // taking into account the multiplicity (reminder: i <= j)
      if(i < j) num *= 2;

      int hash = 0;
      for(int l = 0; l < 3; l++) {
        hash += (exp(i, l) + exp(j, l)) * pow_int(2 * orderHash + 1, l);
      }
      _raiser2[hashToInd2[hash]].push_back(_data(num / den, i, j));
    }
  }

  // Construction of raiser 3
  fullMatrix<int> exp3;
  {
    fullMatrix<double> expD3;
    FuncSpaceData dataRaiser3(_bfs->_data, 3 * order[0], 3 * order[2]);
    gmshGenerateMonomials(dataRaiser3, expD3);
    double2int(expD3, exp3);
    _raiser3.resize(exp3.size1());
  }

  std::map<int, int> hashToInd3;
  for(int i = 0; i < exp3.size1(); ++i) {
    int hash = 0;
    for(int l = 0; l < 3; l++) {
      hash += exp3(i, l) * pow_int(3 * orderHash + 1, l);
    }
    hashToInd3[hash] = i;
  }

  for(int i = 0; i < ncoeff; i++) {
    for(int j = i; j < ncoeff; j++) {
      for(int k = j; k < ncoeff; ++k) {
        double num = 1, den = 1;
        for(int l = 0; l < 3; l++) {
          num *= nChoosek(order[l], exp(i, l)) * nChoosek(order[l], exp(j, l)) *
                 nChoosek(order[l], exp(k, l));
          den *= nChoosek(3 * order[l], exp(i, l) + exp(j, l) + exp(k, l));
        }

        // taking into account the multiplicity (Reminder: i <= j <= k)
        if(i < j && j < k)
          num *= 6;
        else if(i < j || j < k)
          num *= 3;

        int hash = 0;
        for(int l = 0; l < 3; l++) {
          hash +=
            (exp(i, l) + exp(j, l) + exp(k, l)) * pow_int(3 * orderHash + 1, l);
        }
        _raiser3[hashToInd3[hash]].push_back(_data(num / den, i, j, k));
      }
    }
  }
}

void bezierBasisRaiser::computeCoeff(const fullVector<double> &coeffA,
                                     const fullVector<double> &coeffB,
                                     fullVector<double> &coeffSquare) const
{
  coeffSquare.resize(_raiser2.size(), true);

  if(&coeffA == &coeffB) {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        const _data &d = _raiser2[ind][l];
        coeffSquare(ind) += d.val * coeffA(d.i) * coeffB(d.j);
      }
    }
  }
  else {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        const _data &d = _raiser2[ind][l];
        coeffSquare(ind) +=
          d.val / 2 * (coeffA(d.i) * coeffB(d.j) + coeffA(d.j) * coeffB(d.i));
      }
    }
  }
}

void bezierBasisRaiser::computeCoeff2(const fullVector<double> &coeffA,
                                      const fullVector<double> &coeffB,
                                      fullVector<double> &coeffSquare) const
{
  coeffSquare.resize(_raiser2New.size(), true);

  if(&coeffA == &coeffB) {
    for(std::size_t ind = 0; ind < _raiser2New.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2New[ind].size(); ++l) {
        const _data &d = _raiser2New[ind][l];
        coeffSquare(ind) += d.val * coeffA(d.i) * coeffB(d.j);
      }
    }
  }
  else {
    for(std::size_t ind = 0; ind < _raiser2New.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2New[ind].size(); ++l) {
        const _data &d = _raiser2New[ind][l];
        coeffSquare(ind) +=
          d.val / 2 * (coeffA(d.i) * coeffB(d.j) + coeffA(d.j) * coeffB(d.i));
      }
    }
  }
}

void bezierBasisRaiser::computeCoeff(const fullVector<double> &coeffA,
                                     const fullVector<double> &coeffB,
                                     const fullVector<double> &coeffC,
                                     fullVector<double> &coeffCubic) const
{
  coeffCubic.resize(_raiser3.size(), true);

  if(&coeffA == &coeffB && &coeffB == &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        const _data &d = _raiser3[ind][l];
        coeffCubic(ind) += d.val * coeffA(d.i) * coeffB(d.j) * coeffC(d.k);
      }
    }
  }
  else if(&coeffA != &coeffB && &coeffB != &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        const _data &d = _raiser3[ind][l];
        coeffCubic(ind) += d.val / 6 *
                           (coeffA(d.i) * coeffB(d.j) * coeffC(d.k) +
                            coeffA(d.i) * coeffB(d.k) * coeffC(d.j) +
                            coeffA(d.j) * coeffB(d.i) * coeffC(d.k) +
                            coeffA(d.j) * coeffB(d.k) * coeffC(d.i) +
                            coeffA(d.k) * coeffB(d.i) * coeffC(d.j) +
                            coeffA(d.k) * coeffB(d.j) * coeffC(d.i));
      }
    }
  }
  else
    Msg::Error(
      "bezierBasisRaiser::computeCoeff not implemented for A == B != C "
      "or A != B == C");
}

void bezierBasisRaiser::computeCoeff2(const fullVector<double> &coeffA,
                                      const fullVector<double> &coeffB,
                                      const fullVector<double> &coeffC,
                                      fullVector<double> &coeffCubic) const
{
  coeffCubic.resize(_raiser3New.size(), true);

  if(&coeffA == &coeffB && &coeffB == &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3New.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3New[ind].size(); ++l) {
        const _data &d = _raiser3New[ind][l];
        coeffCubic(ind) += d.val * coeffA(d.i) * coeffB(d.j) * coeffC(d.k);
      }
    }
  }
  else if(&coeffA != &coeffB && &coeffB != &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3New.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3New[ind].size(); ++l) {
        const _data &d = _raiser3New[ind][l];
        coeffCubic(ind) += d.val / 6 *
                           (coeffA(d.i) * coeffB(d.j) * coeffC(d.k) +
                            coeffA(d.i) * coeffB(d.k) * coeffC(d.j) +
                            coeffA(d.j) * coeffB(d.i) * coeffC(d.k) +
                            coeffA(d.j) * coeffB(d.k) * coeffC(d.i) +
                            coeffA(d.k) * coeffB(d.i) * coeffC(d.j) +
                            coeffA(d.k) * coeffB(d.j) * coeffC(d.i));
      }
    }
  }
  else
    Msg::Error(
      "bezierBasisRaiser::computeCoeff not implemented for A == B != C "
      "or A != B == C");
}

void bezierBasisRaiser::computeCoeff(const fullMatrix<double> &coeffA,
                                     const fullMatrix<double> &coeffB,
                                     fullMatrix<double> &coeffSquare) const
{
  coeffSquare.resize(_raiser2.size(), coeffA.size2(), true);

  if(&coeffA == &coeffB) {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        const _data &d = _raiser2[ind][l];
        for(int ind2 = 0; ind2 < coeffA.size2(); ++ind2) {
          coeffSquare(ind, ind2) +=
            d.val * coeffA(d.i, ind2) * coeffB(d.j, ind2);
        }
      }
    }
  }
  else {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        const _data &d = _raiser2[ind][l];
        double val = d.val / 2;
        for(int ind2 = 0; ind2 < coeffA.size2(); ++ind2) {
          coeffSquare(ind, ind2) +=
            val * (coeffA(d.i, ind2) * coeffB(d.j, ind2) +
                   coeffA(d.j, ind2) * coeffB(d.i, ind2));
        }
      }
    }
  }
}

void bezierBasisRaiser::computeCoeff(const fullVector<double> &coeffA,
                                     const fullMatrix<double> &coeffB,
                                     const fullMatrix<double> &coeffC,
                                     fullMatrix<double> &coeffCubic) const
{
  coeffCubic.resize(_raiser3.size(), coeffB.size2(), true);

  if(&coeffB == &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        const _data &d = _raiser3[ind][l];
        double val = d.val / 3;
        for(int ind2 = 0; ind2 < coeffB.size2(); ++ind2) {
          coeffCubic(ind, ind2) +=
            val * (coeffA(d.i) * coeffB(d.j, ind2) * coeffC(d.k, ind2) +
                   coeffA(d.j) * coeffB(d.i, ind2) * coeffC(d.k, ind2) +
                   coeffA(d.k) * coeffB(d.i, ind2) * coeffC(d.j, ind2));
        }
      }
    }
  }
  else {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        const _data &d = _raiser3[ind][l];
        double val = d.val / 6;
        for(int ind2 = 0; ind2 < coeffB.size2(); ++ind2) {
          coeffCubic(ind, ind2) +=
            val * (coeffA(d.i) * coeffB(d.j, ind2) * coeffC(d.k, ind2) +
                   coeffA(d.i) * coeffB(d.k, ind2) * coeffC(d.j, ind2) +
                   coeffA(d.j) * coeffB(d.i, ind2) * coeffC(d.k, ind2) +
                   coeffA(d.j) * coeffB(d.k, ind2) * coeffC(d.i, ind2) +
                   coeffA(d.k) * coeffB(d.i, ind2) * coeffC(d.j, ind2) +
                   coeffA(d.k) * coeffB(d.j, ind2) * coeffC(d.i, ind2));
        }
      }
    }
  }
}

bezierMemoryPool *bezierCoeff::_pool0 = NULL;
bezierMemoryPool *bezierCoeff::_pool1 = NULL;
fullMatrix<double> bezierCoeff::_sub = fullMatrix<double>();

bezierCoeff::bezierCoeff(FuncSpaceData data, const fullMatrix<double> &lagCoeff,
                         int num)
  : _numPool(num), _funcSpaceData(data),
    _basis(BasisFactory::getBezierBasis(data))
{
  _r = lagCoeff.size1();
  _c = lagCoeff.size2();
  _own_data = false;
  if(num == 0 && _pool0)
    _data = _pool0->giveBlock(this);
  else if(num == 1 && _pool1)
    _data = _pool1->giveBlock(this);
  else {
    _own_data = true;
    _data = new double[_r * _c];
  }

  _computeCoefficients(lagCoeff.getDataPtr());
}

bezierCoeff::bezierCoeff(FuncSpaceData data, const fullVector<double> &lagCoeff,
                         int num)
  : _numPool(num), _funcSpaceData(data),
    _basis(BasisFactory::getBezierBasis(data))
{
  _r = lagCoeff.size();
  _c = 1;
  _own_data = false;
  if(num == 0 && _pool0)
    _data = _pool0->giveBlock(this);
  else if(num == 1 && _pool1)
    _data = _pool1->giveBlock(this);
  else {
    _own_data = true;
    _data = new double[_r * _c];
  }

  _computeCoefficients(lagCoeff.getDataPtr());
}

bezierCoeff::bezierCoeff(const bezierCoeff &other, bool swap)
{
  _numPool = other._numPool;
  _funcSpaceData = other._funcSpaceData;
  _basis = other._basis;
  _r = other._r;
  _c = other._c;
  if(swap) {
    _own_data = other._own_data;
    _data = other._data;
    const_cast<bezierCoeff &>(other)._own_data = false;
    const_cast<bezierCoeff &>(other)._numPool = -1;
  }
  else {
    _own_data = false;
    if(_numPool == 0 && _pool0)
      _data = _pool0->giveBlock(this);
    else if(_numPool == 1 && _pool1)
      _data = _pool1->giveBlock(this);
    else {
      _own_data = true;
      _data = new double[_r * _c];
    }
  }
}

bezierCoeff::~bezierCoeff()
{
  if(_own_data)
    delete[] _data;
  else {
    if(_numPool == -1) return;
    if(_numPool == 0 && _pool0)
      _pool0->releaseBlock(_data, this);
    else if(_numPool == 1 && _pool1)
      _pool1->releaseBlock(_data, this);
    else
      Msg::Error("Not supposed to be here. destructor bezierCoeff");
  }
}

void bezierCoeff::_computeCoefficients(const double *lagCoeffData)
{
  // FIXME: Use Leja order? (if yes, change gmshGenerateOrderedPoints)
  const int type = _funcSpaceData.getType();
  const int order = _funcSpaceData.getSpaceOrder();
  const int npt = order + 1;
  const fullMatrix<double> lag(const_cast<double*>(lagCoeffData), _r, _c);
  const fullVector<double> &x = _basis->ordered1dBezPoints;
  fullMatrix<double> bez(_data, _r, _c);

  // For simplicial elements, do as before for now
  // FIXME: for prisms, we should do a mix of triangle + convertLag2Bez()

  switch(type) {
  case TYPE_TRI:
  case TYPE_TET:
  case TYPE_PRI:
    // Note: For simplices, less significant errors in matrixLag2Bez2 but
    // an algorithm exists (see same paper than algo convertLag2Bez), yet
    // it is complex. It may be implemented it in the future if it is necessary.
    _basis->matrixLag2Bez2.mult(lag, bez);
    return;
  case TYPE_LIN:
    convertLag2Bez(lag, order, x, bez);
    return;
  case TYPE_QUA:
    for(int i = 0; i < npt; ++i) convertLag2Bez(lag, order, x, bez, i, npt);
    for(int j = 0; j < npt; ++j) convertLag2Bez(bez, order, x, bez, j * npt, 1);
    return;
  case TYPE_HEX:
    for(int ij = 0; ij < npt * npt; ++ij) {
      convertLag2Bez(lag, order, x, bez, ij, npt * npt);
    }
    for(int i = 0; i < npt; ++i) {
      for(int k = 0; k < npt; ++k) {
        convertLag2Bez(bez, order, x, bez, i + k * npt * npt, npt);
      }
    }
    for(int jk = 0; jk < npt * npt; ++jk) {
      convertLag2Bez(bez, order, x, bez, jk * npt, 1);
    }
    return;
  case TYPE_PYR:
  {
    // Pyramids space is tensorial like the hex
    const int nbij = _funcSpaceData.getNij() + 1;
    const int nbk = _funcSpaceData.getNk() + 1;
    fullVector<double> xij, xk;
    gmshGenerateOrderedPointsLine(nbij - 1, xij);
    gmshGenerateOrderedPointsLine(nbk - 1, xk);
    for(int ij = 0; ij < nbij * nbij; ++ij) {
      convertLag2Bez(lag, nbk - 1, xk, bez, ij, nbij * nbij);
    }
    for(int i = 0; i < nbij; ++i) {
      for(int k = 0; k < nbk; ++k) {
        convertLag2Bez(bez, nbij - 1, xij, bez, i + k * nbij * nbij, nbij);
      }
    }
    for(int jk = 0; jk < nbij * nbk; ++jk) {
      convertLag2Bez(bez, nbij - 1, xij, bez, jk * nbij, 1);
    }
    return;
  }
  }
}

void bezierCoeff::usePools(int size0, int size1)
{
  if(size0) {
    if(!_pool0) _pool0 = new bezierMemoryPool();
    _pool0->setSizeBlocks(size0);
  }
  if(size1) {
    if(!_pool1) _pool1 = new bezierMemoryPool();
    _pool1->setSizeBlocks(size1);
  }
}

void bezierCoeff::releasePools()
{
  delete _pool0;
  delete _pool1;
  _pool0 = NULL;
  _pool1 = NULL;
}

void bezierCoeff::updateDataPtr(long diff)
{
  if(_own_data)
    Msg::Error("I own data, cannot do that");
  else
    _data += diff;
}

int bezierCoeff::getIdxCornerCoeff(int i) const
{
  const int order = _funcSpaceData.getSpaceOrder();
  switch(_funcSpaceData.getType()) {
  case TYPE_TRI:
    switch(i) {
    case 0: return 0;
    case 1: return order;
    case 2: return _r - 1;
    }
  case TYPE_QUA:
    switch(i) {
    case 0: return 0;
    case 1: return order;
    case 2: return _r - 1;
    case 3: return _r - 1 - order;
    }
  case TYPE_TET:
    switch(i) {
    case 0: return 0;
    case 1: return order;
    case 2: return (order + 2) * (order + 1) / 2 - 1;
    case 3: return _r - 1;
    }
  case TYPE_HEX:
    switch(i) {
    case 0: return 0;
    case 1: return order;
    case 2: return (order + 1) * (order + 1) - 1;
    case 3: return (order + 1) * order;
    case 4: return (order + 1) * (order + 1) * order;
    case 5: return (order + 1) * (order + 1) * order + order;
    case 6: return _r - 1;
    case 7: return (order + 2) * (order + 1) * order;
    }
  case TYPE_PRI:
    switch(i) {
    case 0: return 0;
    case 1: return order;
    case 2: return (order + 2) * (order + 1) / 2 - 1;
    case 3: return (order + 2) * (order + 1) / 2 * order;
    case 4: return (order + 2) * (order + 1) / 2 * order + order;
    case 5: return _r - 1;
    }
  case TYPE_PYR:
    if (_funcSpaceData.getPyramidalSpace()) {
      switch(i) {
      case 0: return 0;
      case 1: return order;
      case 2: return (order + 1) * (order + 1) - 1;
      case 3: return (order + 1) * order;
      case 4: return _r - 1;
      }
    }
    else {
      const int nij = _funcSpaceData.getNij();
      const int nk = _funcSpaceData.getNk();
      switch(i) {
      case 0: return 0;
      case 1: return nij;
      case 2: return (nij + 1) * (nij + 1) - 1;
      case 3: return (nij + 1) * nij;
      case 4: return (nij + 1) * (nij + 1) * nk;
      case 5: return (nij + 1) * (nij + 1) * nk + nij;
      case 6: return _r - 1;
      case 7: return (nij + 1) * (nij + 1) * nk + (nij + 1) * nij;
      }
    }
  default:
    Msg::Error("type %d not implemented in getIdxCornerCoeff",
               _funcSpaceData.getType());
    return 0;
  }
}

void bezierCoeff::getCornerCoeffs(fullVector<double> &v) const
{
  const int n = getNumCornerCoeff();
  v.resize(n);
  for(int i = 0; i < n; ++i) {
    v(i) = getCornerCoeff(i);
  }
}

void bezierCoeff::getCornerCoeffs(fullMatrix<double> &m) const
{
  const int n = getNumCornerCoeff();
  m.resize(n, _c);
  for(int i = 0; i < n; ++i) {
    const int k = getIdxCornerCoeff(i);
    for(int j = 0; j < _c; ++j) {
      m(i, j) = _data[k + _r * j];
    }
  }
}

void bezierCoeff::subdivide(std::vector<bezierCoeff *> &subCoeff) const
{
  if(subCoeff.size()) {
    Msg::Warning("expected empty vector of bezierCoeff");
    subCoeff.clear();
  }

  // TODO: other types
  switch(_funcSpaceData.getType()) {
  case TYPE_TRI:
    for(int i = 0; i < 4; ++i) subCoeff.push_back(new bezierCoeff(*this));
    _subdivideTriangle(*this, 0, subCoeff);
    return;
  case TYPE_QUA:
    for(int i = 0; i < 4; ++i) subCoeff.push_back(new bezierCoeff(*this));
    _subdivideQuadrangle(*this, subCoeff);
    return;
  case TYPE_TET:
    for(int i = 0; i < 8; ++i) subCoeff.push_back(new bezierCoeff(*this));
    _subdivideTetrahedron(*this, subCoeff);
    return;
  case TYPE_HEX:
    for(int i = 0; i < 8; ++i) subCoeff.push_back(new bezierCoeff(*this));
    _subdivideHexahedron(*this, subCoeff);
    return;
  case TYPE_PRI:
    for(int i = 0; i < 8; ++i) subCoeff.push_back(new bezierCoeff(*this));
    _subdividePrism(*this, subCoeff);
    return;
  case TYPE_PYR:
    for(int i = 0; i < 8; ++i) subCoeff.push_back(new bezierCoeff(*this));
    _subdividePyramid(*this, subCoeff);
    return;
  }
}

void bezierCoeff::_subdivide(fullMatrix<double> &coeff, int npts, int start)
{
  // One-dimensional De Casteljau algorithm if consecutive data
  const int dim = coeff.size2();
  for(int iter = 1; iter < npts; ++iter) {
    for(int I = start + iter; I < start + 2 * npts - iter; I += 2) {
      for(int K = 0; K < dim; ++K) {
        coeff(I, K) = .5 * (coeff(I - 1, K) + coeff(I + 1, K));
      }
    }
  }
}

void bezierCoeff::_subdivide(fullMatrix<double> &coeff, int npts, int start,
                             int inc)
{
  // One-dimensional De Casteljau algorithm if non-consecutive data
  const int dim = coeff.size2();
  for(int iter = 1; iter < npts; ++iter) {
    for(int i = iter; i < 2 * npts - iter; i += 2) {
      int I = start + i * inc;
      for(int K = 0; K < dim; ++K) {
        coeff(I, K) = .5 * (coeff(I - inc, K) + coeff(I + inc, K));
      }
    }
  }
}

void bezierCoeff::_subdivideTriangle(const bezierCoeff &coeff, int start,
                                     std::vector<bezierCoeff *> &vSubCoeff)
{
  const int n = coeff.getPolynomialOrder() + 1;
  const int dim = coeff._c;

  bezierCoeff &sub1 = *vSubCoeff[0];
  bezierCoeff &sub2 = *vSubCoeff[1];
  bezierCoeff &sub3 = *vSubCoeff[2];
  bezierCoeff &sub4 = *vSubCoeff[3];

  // copy into first subdomain
  _copy(coeff, start, (n + 1) * n / 2, sub1);

  // Subdivide in u direction
  // TODO: consider precompute vector<pair<int, int>> for this
  for(int iter = 1; iter < n; ++iter) {
    for(int j = 0; j < n - iter; ++j) {
      for(int i = n - 1 - j; i >= iter; --i) {
        const int I = start + _ij2Index(i, j, n);
        const int Im = start + _ij2Index(i - 1, j, n);
        for(int K = 0; K < dim; ++K) {
          sub1(I, K) = .5 * (sub1(Im, K) + sub1(I, K));
        }
      }
    }
  }
  // Subdivide in v direction
  for(int iter = 1; iter < n; ++iter) {
    for(int j = n - 1; j >= iter; --j) {
      for(int i = 0; i < n - j; ++i) {
        const int I = start + _ij2Index(i, j, n);
        const int Im = start + _ij2Index(i, j - 1, n);
        for(int K = 0; K < dim; ++K) {
          sub1(I, K) = .5 * (sub1(Im, K) + sub1(I, K));
        }
      }
    }
  }

  _copy(sub1, start, (n + 1) * n / 2, sub2);
  //
  // TODO: consider precompute vector<tuple<int, int, int>> for this
  for(int iter = 1; iter < n; ++iter) {
    for(int j = 0; j < n - iter; ++j) {
      for(int i = 0; i < n - iter - j; ++i) {
        const int I = start + _ij2Index(i, j, n);
        const int Ia = start + _ij2Index(i + 1, j, n);
        const int Ib = start + _ij2Index(i, j + 1, n);
        for(int K = 0; K < dim; ++K) {
          sub2(I, K) = sub2(Ia, K) + sub2(Ib, K) - sub2(I, K);
        }
      }
    }
  }

  _copy(sub2, start, (n + 1) * n / 2, sub3);
  for(int iter = 1; iter < n; ++iter) {
    for(int j = 0; j < n - iter; ++j) {
      for(int i = n - 1 - j; i >= iter; --i) {
        const int I = start + _ij2Index(i, j, n);
        const int Ia = start + _ij2Index(i - 1, j, n);
        const int Ib = start + _ij2Index(i - 1, j + 1, n);
        for(int K = 0; K < dim; ++K) {
          sub3(I, K) = sub3(Ia, K) + sub3(Ib, K) - sub3(I, K);
        }
      }
    }
  }

  _copy(sub2, start, (n + 1) * n / 2, sub4); // copy 2, not 3
  for(int iter = 1; iter < n; ++iter) {
    for(int j = n - 1; j >= iter; --j) {
      for(int i = 0; i < n - j; ++i) {
        const int I = start + _ij2Index(i, j, n);
        const int Ia = start + _ij2Index(i, j - 1, n);
        const int Ib = start + _ij2Index(i + 1, j - 1, n);
        for(int K = 0; K < dim; ++K) {
          sub4(I, K) = sub4(Ia, K) + sub4(Ib, K) - sub4(I, K);
        }
      }
    }
  }
}

void bezierCoeff::_subdivideTet(_SubdivisionTet which, int n,
                                bezierCoeff &coeff)
{
  // TODO: consider precompute vector<pair<int, int>> for subdiv
  //       consider precompute vector<pair<int, int, int>> for n_crosse_e

  const int dim = coeff.getNumColumns();
  switch (which) {
  case subdivU:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = 0; k < n - iter; ++k) {
        for(int j = 0; j < n - iter - k; ++j) {
          for(int i = n - 1 - j - k; i >= iter; --i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Im = _ijk2Index(i - 1, j, k, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = .5 * (coeff(Im, K) + coeff(I, K));
            }
          }
        }
      }
    }
    return;
  case subdivV:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = 0; k < n - iter; ++k) {
        for(int j = n - 1 - k; j >= iter; --j) {
          for(int i = 0; i < n - j - k; ++i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Im = _ijk2Index(i, j - 1, k, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = .5 * (coeff(Im, K) + coeff(I, K));
            }
          }
        }
      }
    }
    return;
  case subdivW:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = n - 1; k >= iter; --k) {
        for(int j = 0; j < n - k; ++j) {
          for(int i = 0; i < n - j - k; ++i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Im = _ijk2Index(i, j, k - 1, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = .5 * (coeff(Im, K) + coeff(I, K));
            }
          }
        }
      }
    }
    return;
    // TODO: consider precompute vector<tuple<int, int, int>> for this
  case node0CrossEdge12:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = 0; k < n - iter; ++k) {
        for(int j = 0; j < n - iter - k; ++j) {
          for(int i = 0; i < n - iter - j - k; ++i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Ia = _ijk2Index(i + 1, j, k, n);
            const int Ib = _ijk2Index(i, j + 1, k, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = coeff(Ia, K) + coeff(Ib, K) - coeff(I, K);
            }
          }
        }
      }
    }
    return;
  case node3CrossEdge12:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = n - 1; k >= iter; --k) {
        for(int j = 0; j < n - k; ++j) {
          for(int i = 0; i < n - j - k; ++i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Ia = _ijk2Index(i + 1, j, k - 1, n);
            const int Ib = _ijk2Index(i, j + 1, k - 1, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = coeff(Ia, K) + coeff(Ib, K) - coeff(I, K);
            }
          }
        }
      }
    }
    return;
  case node1CrossEdge03:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = 0; k < n - iter; ++k) {
        for(int j = 0; j < n - iter - k; ++j) {
          for(int i = n - 1 - j - k; i >= iter; --i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Ia = _ijk2Index(i - 1, j, k, n);
            const int Ib = _ijk2Index(i - 1, j, k + 1, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = coeff(Ia, K) + coeff(Ib, K) - coeff(I, K);
            }
          }
        }
      }
    }
    return;
  case node2CrossEdge03:
    for(int iter = 1; iter < n; ++iter) {
      for(int k = 0; k < n - iter; ++k) {
        for(int j = n - 1 - k; j >= iter; --j) {
          for(int i = 0; i < n - j - k; ++i) {
            const int I = _ijk2Index(i, j, k, n);
            const int Ia = _ijk2Index(i, j - 1, k, n);
            const int Ib = _ijk2Index(i, j - 1, k + 1, n);
            for(int K = 0; K < dim; ++K) {
              coeff(I, K) = coeff(Ia, K) + coeff(Ib, K) - coeff(I, K);
            }
          }
        }
      }
    }
  }
}

void bezierCoeff::_subdivideTetrahedron(const bezierCoeff &coeff,
                                        std::vector<bezierCoeff *> &vSubCoeff)
{
  const int n = coeff.getPolynomialOrder() + 1;
  const int N = (n + 2) * (n + 1) * n / 6;

  bezierCoeff &sub1 = *vSubCoeff[0];
  bezierCoeff &sub2 = *vSubCoeff[1];
  bezierCoeff &sub3 = *vSubCoeff[2];
  bezierCoeff &sub4 = *vSubCoeff[3];
  bezierCoeff &sub5 = *vSubCoeff[4];
  bezierCoeff &sub6 = *vSubCoeff[5];
  bezierCoeff &sub7 = *vSubCoeff[6];
  bezierCoeff &sub8 = *vSubCoeff[7];

  // Corner (0,0,0)
  _copy(coeff, 0, N, sub1);
  _subdivideTet(subdivU, n, sub1);
  _subdivideTet(subdivV, n, sub1);
  _subdivideTet(subdivW, n, sub1);

  // Compute 4 middle ones
  _copy(sub1, 0, N, sub2);
  _subdivideTet(node0CrossEdge12, n, sub2);

  _copy(sub2, 0, N, sub3);
  _copy(sub2, 0, N, sub4);
  _subdivideTet(node1CrossEdge03, n, sub3);
  _subdivideTet(node2CrossEdge03, n, sub4);

  _copy(sub4, 0, N, sub5);
  _subdivideTet(node1CrossEdge03, n, sub5);

  // 3 remaining corners
  _copy(sub3, 0, N, sub6);
  _copy(sub4, 0, N, sub7);
  _copy(sub5, 0, N, sub8);
  _subdivideTet(node3CrossEdge12, n, sub6);
  _subdivideTet(node3CrossEdge12, n, sub7);
  _subdivideTet(node0CrossEdge12, n, sub8);
  // node 3 cross edge 1-2
}

void bezierCoeff::_subdivideQuadrangle(const bezierCoeff &coeff,
                                       std::vector<bezierCoeff *> &subCoeff)
{
  const int n = coeff.getPolynomialOrder() + 1;
  const int N = 2 * n - 1;
  const int dim = coeff._c;
  _sub.resize(N * N, dim, false);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      const int I1 = i + j * n;
      const int I2 = (2 * i) + (2 * j) * N;
      for(int k = 0; k < dim; ++k) {
        _sub(I2, k) = coeff(I1, k);
      }
    }
  }
  for(int i = 0; i < N; i += 2) {
    _subdivide(_sub, n, i, N);
  }
  for(int j = 0; j < N; ++j) {
    _subdivide(_sub, n, j * N);
  }
  _copyQuad(_sub, n, 0, 0, *subCoeff[0]);
  _copyQuad(_sub, n, n - 1, 0, *subCoeff[1]);
  _copyQuad(_sub, n, 0, n - 1, *subCoeff[2]);
  _copyQuad(_sub, n, n - 1, n - 1, *subCoeff[3]);
  return;
}

void bezierCoeff::_subdivideHexahedron(const bezierCoeff &coeff,
                                       std::vector<bezierCoeff *> &subCoeff)
{
  const int n = coeff.getPolynomialOrder() + 1;
  const int N = 2 * n - 1;
  const int dim = coeff._c;
  _sub.resize(N * N * N, dim, false);
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int k = 0; k < n; ++k) {
        const int I1 = i + j * n + k * n * n;
        const int I2 = (2 * i) + (2 * j) * N + (2 * k) * N * N;
        for(int k = 0; k < dim; ++k) {
          _sub(I2, k) = coeff(I1, k);
        }
      }
    }
  }
  for(int i = 0; i < N; i += 2) {
    for(int j = 0; j < N; j += 2) {
      _subdivide(_sub, n, i + j * N, N * N);
    }
  }
  for(int i = 0; i < N; i += 2) {
    for(int k = 0; k < N; ++k) {
      _subdivide(_sub, n, i + k * N * N, N);
    }
  }
  for(int j = 0; j < N; ++j) {
    for(int k = 0; k < N; ++k) {
      _subdivide(_sub, n, j * N + k * N * N);
    }
  }
  _copyHex(_sub, n, 0, 0, 0, *subCoeff[0]);
  _copyHex(_sub, n, n - 1, 0, 0, *subCoeff[1]);
  _copyHex(_sub, n, 0, n - 1, 0, *subCoeff[2]);
  _copyHex(_sub, n, n - 1, n - 1, 0, *subCoeff[3]);
  _copyHex(_sub, n, 0, 0, n - 1, *subCoeff[4]);
  _copyHex(_sub, n, n - 1, 0, n - 1, *subCoeff[5]);
  _copyHex(_sub, n, 0, n - 1, n - 1, *subCoeff[6]);
  _copyHex(_sub, n, n - 1, n - 1, n - 1, *subCoeff[7]);
  return;
}

void bezierCoeff::_subdividePrism(const bezierCoeff &coeff,
                                  std::vector<bezierCoeff *> &subCoeff)
{
  const int n = coeff.getPolynomialOrder() + 1;
  const int ntri = (n + 1) * n / 2;
  const int N = 2 * n - 1;
  const int dim = coeff._c;
  _sub.resize(N * ntri, dim, false);
  for(int k = 0; k < n; ++k) {
    for(int i = 0; i < ntri; ++i) {
      const int I1 = i + k * ntri;
      const int I2 = i + (2 * k) * ntri;
      for(int l = 0; l < dim; ++l) {
        _sub(I2, l) = coeff(I1, l);
      }
    }
  }
  for(int i = 0; i < ntri; ++i) {
    _subdivide(_sub, n, i, ntri);
  }

  std::vector<bezierCoeff *> subCoeff2;
  subCoeff2.push_back(subCoeff[4]);
  subCoeff2.push_back(subCoeff[5]);
  subCoeff2.push_back(subCoeff[6]);
  subCoeff2.push_back(subCoeff[7]);
  _copyLine(_sub, n * ntri, 0, *subCoeff[0]);
  _copyLine(_sub, n * ntri, (n - 1) * ntri, *subCoeff2[0]);
  for(int k = 0; k < n; ++k) {
    _subdivideTriangle(*subCoeff[0], k*ntri, subCoeff);
    _subdivideTriangle(*subCoeff2[0], k*ntri, subCoeff2);
  }
  return;
}

void bezierCoeff::_subdividePyramid(const bezierCoeff &coeff,
                                    std::vector<bezierCoeff *> &subCoeff)
{
  const int nij = coeff._funcSpaceData.getNij();
  const int nk = coeff._funcSpaceData.getNk();
  const int Nij = 2 * nij - 1;
  const int Nk = 2 * nk - 1;
  const int dim = coeff._c;

  _sub.resize(Nij * Nij * Nk, dim, false);
  for(int i = 0; i < nij; ++i) {
    for(int j = 0; j < nij; ++j) {
      for(int k = 0; k < nk; ++k) {
        const int I1 = i + j * nij + k * nij * nij;
        const int I2 = (2 * i) + (2 * j) * Nij + (2 * k) * Nij * Nij;
        for(int k = 0; k < dim; ++k) {
          _sub(I2, k) = coeff(I1, k);
        }
      }
    }
  }
  for(int i = 0; i < Nij; i += 2) {
    for(int j = 0; j < Nij; j += 2) {
      _subdivide(_sub, nk, i + j * Nij, Nij * Nij);
    }
  }
  for(int i = 0; i < Nij; i += 2) {
    for(int k = 0; k < Nk; ++k) {
      _subdivide(_sub, nij, i + k * Nij * Nij, Nij);
    }
  }
  for(int j = 0; j < Nij; ++j) {
    for(int k = 0; k < Nk; ++k) {
      _subdivide(_sub, nij, j * Nij + k * Nij * Nij);
    }
  }
  _copyPyr(_sub, nij, nk, 0, 0, 0, *subCoeff[0]);
  _copyPyr(_sub, nij, nk, nij - 1, 0, 0, *subCoeff[1]);
  _copyPyr(_sub, nij, nk, 0, nij - 1, 0, *subCoeff[2]);
  _copyPyr(_sub, nij, nk, nij - 1, nij - 1, 0, *subCoeff[3]);
  _copyPyr(_sub, nij, nk, 0, 0, nk - 1, *subCoeff[4]);
  _copyPyr(_sub, nij, nk, nij - 1, 0, nk - 1, *subCoeff[5]);
  _copyPyr(_sub, nij, nk, 0, nij - 1, nk - 1, *subCoeff[6]);
  _copyPyr(_sub, nij, nk, nij - 1, nij - 1, nk - 1, *subCoeff[7]);
  return;
}

void bezierCoeff::_copy(const bezierCoeff &from, int start, int num,
                        bezierCoeff &to)
{
  const int dim = from._c;
  for(int i = start; i < start + num; ++i) {
    for(int j = 0; j < dim; ++j) {
      to(i, j) = from(i, j);
    }
  }
}

void
bezierCoeff::_copyLine(const fullMatrix<double> &allSub, int n, int start,
                       bezierCoeff &sub)
{
  const int dim = allSub.size2();
  for(int i = 0; i < n; ++i) {
    for(int K = 0; K < dim; ++K) {
      sub(i, K) = allSub(start + i, K);
    }
  }
}

void
bezierCoeff::_copyQuad(const fullMatrix<double> &allSub, int n, int starti, int startj,
                       bezierCoeff &sub)
{
  const int dim = allSub.size2();
  const int N = 2 * n - 1;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      const int I1 = i + j * n;
      const int I2 = (starti + i) + (startj + j) * N;
      for(int K = 0; K < dim; ++K) {
        sub(I1, K) = allSub(I2, K);
      }
    }
  }
}

void
bezierCoeff::_copyHex(const fullMatrix<double> &allSub, int n, int starti, int startj,
                      int startk, bezierCoeff &sub)
{
  const int dim = allSub.size2();
  const int N = 2 * n - 1;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      for(int k = 0; k < n; ++k) {
        const int I1 = i + j * n + k * n * n;
        const int I2 = (starti + i) + (startj + j) * N + (startk + k) * N * N;
        for(int K = 0; K < dim; ++K) {
          sub(I1, K) = allSub(I2, K);
        }
      }
    }
  }
}

void
bezierCoeff::_copyPyr(const fullMatrix<double> &allSub, int nij, int nk,
                      int starti, int startj, int startk, bezierCoeff &sub)
{
  const int dim = allSub.size2();
  const int Nij = 2 * nij - 1;
  for(int i = 0; i < nij; ++i) {
    for(int j = 0; j < nij; ++j) {
      for(int k = 0; k < nk; ++k) {
        const int I1 = i + j * nij + k * nij * nij;
        const int I2 = (starti + i) + (startj + j) * Nij + (startk + k) * Nij * Nij;
        for(int K = 0; K < dim; ++K) {
          sub(I1, K) = allSub(I2, K);
        }
      }
    }
  }
}

bezierMemoryPool::bezierMemoryPool()
{
  _sizeBlocks = 0;
  _numUsedBlocks = 0;
  _currentIndexOfSearch = 0;
  _endOfSearch = 0;
}

void bezierMemoryPool::setSizeBlocks(int size)
{
  if(_numUsedBlocks) {
    Msg::Error("Cannot change size of blocks if blocks are still being used!");
    return;
  }
  _currentIndexOfSearch = 0;
  _sizeBlocks = size;
  _endOfSearch = 0;
}

double *bezierMemoryPool::giveBlock(bezierCoeff *bez)
{
  _checkEnoughMemory();

  if(_numUsedBlocks == _endOfSearch) {
    int idx = _endOfSearch;
    if(_bezierCoeff.size() == idx)
      _bezierCoeff.push_back(bez);
    else if(_bezierCoeff[idx]) {
      Msg::Error("this block is being used!?");
      return NULL;
    }
    else
      _bezierCoeff[idx] = bez;
    ++_numUsedBlocks;
    ++_endOfSearch;
    return &_memory.front() + _sizeBlocks * idx;
  }

  for(int i = 0; i < _endOfSearch; ++i) {
    int idx = _currentIndexOfSearch;
    ++_currentIndexOfSearch;
    if(_currentIndexOfSearch == _endOfSearch) _currentIndexOfSearch = 0;
    if(!_bezierCoeff[idx]) {
      _bezierCoeff[idx] = bez;
      ++_numUsedBlocks;
      return &_memory.front() + _sizeBlocks * idx;
    }
  }

  // We must never be here. If yes, this means that
  // _numUsedBlocks < _endOfSearch
  // and _bezierCoeff[i] for i < _endOfSearch are all different from
  // NULL which should never happens.
  Msg::Error("Wrong state of bezierMemoryPool."
             "_bezierCoeff[i] not correct?");
  return NULL;
}

void bezierMemoryPool::releaseBlock(double *block, bezierCoeff *bez)
{
  long diff = block - &_memory.front();
  int idx = diff / _sizeBlocks;
  //  if (_bezierCoeff[idx] == bez)
  //    Msg::Info("It's a good guess!");
  //  else
  //    Msg::Info("Did not work :'( ");
  _bezierCoeff[idx] = NULL;
  if(idx == _endOfSearch - 1) {
    do {
      --_endOfSearch;
    } while(_endOfSearch && !_bezierCoeff[_endOfSearch - 1]);
    _bezierCoeff.resize(_endOfSearch);
    if(_currentIndexOfSearch >= _endOfSearch) _currentIndexOfSearch = 0;
  }
  --_numUsedBlocks;
}

void bezierMemoryPool::freeMemory()
{
  if(_numUsedBlocks) {
    Msg::Error("I cannot free memory if some is still in use!");
    return;
  }
  // force deallocation:
  std::vector<double> dummy;
  _memory.swap(dummy);
}

void bezierMemoryPool::_checkEnoughMemory()
{
  if(_numUsedBlocks < _memory.size() / _sizeBlocks) return;

  double *pointer = &_memory.front();
  _memory.resize(_memory.size() + _sizeBlocks);

  if(pointer == &_memory.front()) return;

  // If a reallocation has been performed at a different place of the memory,
  // then we need to update pointers

  long diff = &_memory.front() - pointer;
  for(std::size_t i = 0; i < _bezierCoeff.size(); ++i) {
    if(_bezierCoeff[i]) _bezierCoeff[i]->updateDataPtr(diff);
  }
}
