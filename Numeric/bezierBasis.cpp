// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.


#include "GmshDefines.h"
#include "GmshMessage.h"
#include <vector>
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "Numeric.h"
#include <sstream>


namespace {
// Sub Control Points
std::vector< fullMatrix<double> > generateSubPointsLine(int order)
{
  std::vector< fullMatrix<double> > subPoints(2);

  subPoints[0] = gmshGenerateMonomialsLine(order);
  subPoints[0].scale(.5/order);

  subPoints[1].copy(subPoints[0]);
  subPoints[1].add(.5);

  return subPoints;
}

std::vector< fullMatrix<double> > generateSubPointsTriangle(int order)
{
  std::vector< fullMatrix<double> > subPoints(4);
  fullMatrix<double> prox;

  subPoints[0] = gmshGenerateMonomialsTriangle(order);
  subPoints[0].scale(.5/order);

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

std::vector< fullMatrix<double> > generateSubPointsQuad(int order)
{
  std::vector< fullMatrix<double> > subPoints(4);
  fullMatrix<double> prox;

  subPoints[0] = gmshGenerateMonomialsQuadrangle(order);
  subPoints[0].scale(.5/order);

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

std::vector< fullMatrix<double> > generateSubPointsTetrahedron(int order)
{
  std::vector< fullMatrix<double> > subPoints(8);
  fullMatrix<double> prox1;
  fullMatrix<double> prox2;

  subPoints[0] = gmshGenerateMonomialsTetrahedron(order);
  subPoints[0].scale(.5/order);

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

std::vector< fullMatrix<double> > generateSubPointsPrism(int order)
{
  std::vector< fullMatrix<double> > subPoints(8);
  fullMatrix<double> prox;

  subPoints[0] = gmshGenerateMonomialsPrism(order);
  subPoints[0].scale(.5/order);

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

std::vector< fullMatrix<double> > generateSubPointsHex(int order)
{
  std::vector< fullMatrix<double> > subPoints(8);
  fullMatrix<double> prox;

  subPoints[0] = gmshGenerateMonomialsHexahedron(order);
  subPoints[0].scale(.5/order);

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

std::vector< fullMatrix<double> > generateSubPointsPyr(int nij, int nk)
{
  if (nk == 0) {
    std::vector< fullMatrix<double> > subPoints(4);
    fullMatrix<double> prox;

    subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, nij, nk);
    subPoints[0].scale(.5/nij);

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
  else {
    std::vector< fullMatrix<double> > subPoints(8);
    fullMatrix<double> ref, prox;

    subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, nij, nk);
    prox.setAsProxy(subPoints[0], 2, 1);
    prox.scale(-1);
    prox.add(nk);
    subPoints[0].scale(.5/std::max(nij,nk));

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

    for (int i = 0; i < 8; ++i) {
      prox.setAsProxy(subPoints[i], 2, 1);
      prox.scale(-1);
      prox.add(1);
    }

    return subPoints;
  }
}

// Matrices generation
int nChoosek(int n, int k)
{
  if (n < k || k < 0) {
    Msg::Error("Wrong argument for combination. (%d, %d)", n, k);
    return 1;
  }

  if (k > n/2) k = n-k;
  if (k == 1)
    return n;
  if (k == 0)
    return 1;

  int c = 1;
  for (int i = 1; i <= k; i++, n--) (c *= n) /= i;
  return c;
}

fullMatrix<double> generateBez2LagMatrix
  (const fullMatrix<double> &exponent, const fullMatrix<double> &point,
   int order, int dimSimplex)
{
  if(exponent.size1() != point.size1() || exponent.size2() != point.size2()){
    Msg::Fatal("Wrong sizes for bez2lag matrix generation %d %d -- %d %d",
      exponent.size1(),point.size1(),
      exponent.size2(),point.size2());
    return fullMatrix<double>(1, 1);
  }

  int ndofs = exponent.size1();
  int dim = exponent.size2();

  fullMatrix<double> bez2Lag(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double dd = 1.;

      {
        double pointCompl = 1.;
        int exponentCompl = order;
        for (int k = 0; k < dimSimplex; k++) {
          dd *= nChoosek(exponentCompl, (int) exponent(i, k))
            * pow(point(j, k), exponent(i, k));
          pointCompl -= point(j, k);
          exponentCompl -= (int) exponent(i, k);
        }
        dd *= pow(pointCompl, exponentCompl);
      }

      for (int k = dimSimplex; k < dim; k++)
        dd *= nChoosek(order, (int) exponent(i, k))
            * pow(point(j, k), exponent(i, k))
            * pow(1. - point(j, k), order - exponent(i, k));

      bez2Lag(j, i) = dd;
    }
  }
  return bez2Lag;
}

fullMatrix<double> generateBez2LagMatrixPyramid
  (const fullMatrix<double> &exponent, const fullMatrix<double> &point,
   bool pyr, int nij, int nk)
{
  if(exponent.size1() != point.size1() || exponent.size2() != point.size2() ||
      exponent.size2() != 3){
    Msg::Fatal("Wrong sizes for pyramid's bez2lag matrix generation %d %d -- %d %d",
      exponent.size1(), point.size1(),
      exponent.size2(), point.size2());
    return fullMatrix<double>(1, 1);
  }

  const int ndofs = exponent.size1();

  int n01 = nij;
  fullMatrix<double> bez2Lag(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      if (pyr) n01 = exponent(j, 2) + nij;
      bez2Lag(i, j) =
            nChoosek(n01, exponent(j, 0))
          * nChoosek(n01, exponent(j, 1))
          * nChoosek(nk , exponent(j, 2))
          * pow_int(point(i, 0), exponent(j, 0))
          * pow_int(point(i, 1), exponent(j, 1))
          * pow_int(point(i, 2), exponent(j, 2))
          * pow_int(1. - point(i, 0), n01 - exponent(j, 0))
          * pow_int(1. - point(i, 1), n01 - exponent(j, 1))
          * pow_int(1. - point(i, 2), nk  - exponent(j, 2));
    }
  }
  return bez2Lag;
}

fullMatrix<double> generateSubDivisor
  (const fullMatrix<double> &exponents, const std::vector< fullMatrix<double> > &subPoints,
   const fullMatrix<double> &lag2Bez, int order, int dimSimplex)
{
  if (exponents.size1() != lag2Bez.size1() || exponents.size1() != lag2Bez.size2()){
    Msg::Fatal("Wrong sizes for Bezier Divisor %d %d -- %d %d",
      exponents.size1(), lag2Bez.size1(),
      exponents.size1(), lag2Bez.size2());
    return fullMatrix<double>(1, 1);
  }

  int nbPts = lag2Bez.size1();
  int nbSubPts = nbPts * subPoints.size();

  fullMatrix<double> intermediate2(nbPts, nbPts);
  fullMatrix<double> subDivisor(nbSubPts, nbPts);

  for (unsigned int i = 0; i < subPoints.size(); i++) {
    fullMatrix<double> intermediate1 =
      generateBez2LagMatrix(exponents, subPoints[i], order, dimSimplex);
    lag2Bez.mult(intermediate1, intermediate2);
    subDivisor.copy(intermediate2, 0, nbPts, 0, nbPts, i*nbPts, 0);
  }
  return subDivisor;
}

fullMatrix<double> generateSubDivisorPyramid
  (const fullMatrix<double> &exponents, const std::vector< fullMatrix<double> > &subPoints,
   const fullMatrix<double> &lag2Bez, bool pyr, int nij, int nk)
{
  if (exponents.size1() != lag2Bez.size1() || exponents.size1() != lag2Bez.size2()){
    Msg::Fatal("Wrong sizes for Bezier Divisor %d %d -- %d %d",
      exponents.size1(), lag2Bez.size1(),
      exponents.size1(), lag2Bez.size2());
    return fullMatrix<double>(1, 1);
  }

  int nbPts = lag2Bez.size1();
  int nbSubPts = nbPts * subPoints.size();

  fullMatrix<double> intermediate2(nbPts, nbPts);
  fullMatrix<double> subDivisor(nbSubPts, nbPts);

  for (unsigned int i = 0; i < subPoints.size(); i++) {
    fullMatrix<double> intermediate1 =
      generateBez2LagMatrixPyramid(exponents, subPoints[i],
                                   pyr, nij, nk);
    lag2Bez.mult(intermediate1, intermediate2);
    subDivisor.copy(intermediate2, 0, nbPts, 0, nbPts, i*nbPts, 0);
  }
  return subDivisor;
}
}

void bezierBasis::generateBezierPoints(fullMatrix<double> &points) const
{
  gmshGenerateMonomials(_data, points);
  points.scale(1./_data.spaceOrder());

  if (_data.elementType() == TYPE_PYR && _data.nk() < _data.spaceOrder()) {
    fullMatrix<double> prox;
    prox.setAsProxy(points, 2, 1);
    prox.add(1-static_cast<double>(_data.nk())/_data.spaceOrder());
  }
}

void bezierBasis::_FEpoints2BezPoints(fullMatrix<double> &points) const
{
  switch (_data.elementType()) {
  case TYPE_TRI:
  case TYPE_TET:
    break;

  case TYPE_QUA:
  case TYPE_HEX:
    points.add(1);
    points.scale(.5);
    break;

  case TYPE_PRI:
    {
      fullMatrix<double> tmp;
      tmp.setAsProxy(points, 2, 1);
      tmp.add(1);
      tmp.scale(.5);
    }
    break;

  case TYPE_PYR:
    for (int i = 0; i < points.size1(); ++i) {
      points(i, 2) = 1. - points(i, 2);
      points(i, 0) = .5 * (1 + points(i, 0) / points(i, 2));
      points(i, 1) = .5 * (1 + points(i, 1) / points(i, 2));
    }
    break;

  default:
    Msg::Error("_FEpoints2BezPoints not implemented for "
               "type of element %d", _data.elementType());
    return;
  }
}

void bezierBasis::interpolate(const fullMatrix<double> &coeffs,
                              const fullMatrix<double> &uvw,
                              fullMatrix<double> &result,
                              bool bezCoord) const
{
  if (result.size1() != uvw.size1() || result.size2() != coeffs.size2())
    result.resize(uvw.size1(), coeffs.size2());

  fullMatrix<double> bezuvw = uvw;
  if (!bezCoord) _FEpoints2BezPoints(bezuvw);

  const int numCoeff = _exponents.size1();
  const int dim = _exponents.size2();
  int order[3];

  for (int m = 0; m < uvw.size1(); ++m) {
    for (int n = 0; n < coeffs.size2(); ++n) result(m, n) = 0;
    for (int i = 0; i < numCoeff; i++) {
      _data.getOrderForBezier(order, _exponents(i, dim-1));
      double dd = 1;
      double pointCompl = 1.;
      int exponentCompl = order[0];
      for (int k = 0; k < _dimSimplex; k++) {
        dd *= nChoosek(exponentCompl, (int) _exponents(i, k))
          * pow(bezuvw(m, k), _exponents(i, k));
        pointCompl -= bezuvw(m, k);
        exponentCompl -= (int) _exponents(i, k);
      }
      dd *= pow_int(pointCompl, exponentCompl);

      for (int k = _dimSimplex; k < dim; k++) {
        dd *= nChoosek(order[k], (int) _exponents(i, k))
            * pow_int(bezuvw(m, k), _exponents(i, k))
            * pow_int(1. - bezuvw(m, k), order[k] - _exponents(i, k));
      }
      for (int n = 0; n < coeffs.size2(); ++n)
        result(m, n) += coeffs(i, n) * dd;
    }
  }
}

void bezierBasis::lag2Bez(const fullMatrix<double> &lag,
                          fullMatrix<double> &bez) const
{
  if (lag.size1() != matrixLag2Bez.size1()) {
    Msg::Error("matrix not the right size in lag2Bez function %d vs %d",
        lag.size1(), matrixLag2Bez.size1());
  }
  if (bez.size1() != lag.size1() || bez.size2() != lag.size2()) {
    bez.resize(lag.size1(), lag.size2());
  }
  matrixLag2Bez.mult(lag, bez);
}

void bezierBasis::subdivideBezCoeff(const fullMatrix<double> &coeff,
                                    fullMatrix<double> &subCoeff) const
{
  if (subCoeff.size1() != subDivisor.size1()
      || subCoeff.size2() != coeff.size2()  ) {
    subCoeff.resize(subDivisor.size1(), coeff.size2());
  }
  subDivisor.mult(coeff, subCoeff);
}

void bezierBasis::subdivideBezCoeff(const fullVector<double> &coeff,
                                    fullVector<double> &subCoeff) const
{
  if (subCoeff.size() != subDivisor.size1()) {
    subCoeff.resize(subDivisor.size1());
  }
  subDivisor.mult(coeff, subCoeff);
}

void bezierBasis::_construct()
{
  if (_data.elementType() == TYPE_PYR) {
    Msg::Fatal("This bezierBasis constructor is not for pyramids !");
  }

  std::vector< fullMatrix<double> > subPoints;
  int order = _data.spaceOrder();

  switch (_data.elementType()) {
    case TYPE_PNT :
      _numLagCoeff = 1;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsLine(0);
      subPoints.push_back(gmshGeneratePointsLine(0));
      break;
    case TYPE_LIN : {
      _numLagCoeff = order ? 2 : 1;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsLine(order);
      subPoints = generateSubPointsLine(order);
      break;
    }
    case TYPE_TRI : {
      _numLagCoeff = order ? 3 : 1;
      _dimSimplex = 2;
      _exponents = gmshGenerateMonomialsTriangle(order);
      subPoints = generateSubPointsTriangle(order);
      break;
    }
    case TYPE_QUA : {
      _numLagCoeff = order ? 4 : 1;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsQuadrangle(order);
      subPoints = generateSubPointsQuad(order);
      break;
    }
    case TYPE_TET : {
      _numLagCoeff = order ? 4 : 1;
      _dimSimplex = 3;
      _exponents = gmshGenerateMonomialsTetrahedron(order);
      subPoints = generateSubPointsTetrahedron(order);
      break;
    }
    case TYPE_PRI : {
      _numLagCoeff = order ? 6 : 1;
      _dimSimplex = 2;
      _exponents = gmshGenerateMonomialsPrism(order);
      subPoints = generateSubPointsPrism(order);
      break;
    }
    case TYPE_HEX : {
      _numLagCoeff = order ? 8 : 1;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsHexahedron(order);
      subPoints = generateSubPointsHex(order);
      break;
    }
    default : {
      Msg::Fatal("Unknown function space for parentType %d", _data.elementType());
      return;
    }
  }
  _numDivisions = static_cast<int>(subPoints.size());

  fullMatrix<double> bezierPoints = _exponents;
  if (order) bezierPoints.scale(1./order);

  matrixBez2Lag = generateBez2LagMatrix(_exponents, bezierPoints, order, _dimSimplex);
  matrixBez2Lag.invert(matrixLag2Bez);
  subDivisor = generateSubDivisor(_exponents, subPoints, matrixLag2Bez, order, _dimSimplex);
}

void bezierBasis::_constructPyr()
{
  if (_data.elementType() != TYPE_PYR) {
    Msg::Fatal("This bezierBasis constructor is for pyramids !");
  }

  const bool pyr = _data.isPyramidalSpace();
  const int nij = _data.nij(), nk = _data.nk();

  _numLagCoeff = nk == 0 ? 4 : 8;
  _dimSimplex = 0;
  gmshGenerateMonomials(_data, _exponents);

  fullMatrix<double> bezierPoints;
  generateBezierPoints(bezierPoints);
  matrixBez2Lag = generateBez2LagMatrixPyramid(_exponents, bezierPoints,
                                               pyr, nij, nk);
  matrixBez2Lag.invert(matrixLag2Bez);
  if (pyr) {
    _numDivisions = 0;
  }
  else {
    std::vector< fullMatrix<double> > subPoints;
    subPoints = generateSubPointsPyr(nij, nk);
    _numDivisions = static_cast<int>(subPoints.size());
    subDivisor = generateSubDivisorPyramid(_exponents, subPoints, matrixLag2Bez,
                                           pyr, nij, nk);
  }
  return;
}
