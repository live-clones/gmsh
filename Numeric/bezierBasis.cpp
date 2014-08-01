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

std::vector< fullMatrix<double> > generateSubPointsPyr(int order)
{
  if (order == 0) {
    std::vector< fullMatrix<double> > subPoints(4);
    fullMatrix<double> prox;

    subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, 2, 0);
    subPoints[0].scale(.5/2);

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

    subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, order+2, order);
    prox.setAsProxy(subPoints[0], 2, 1);
    prox.scale(-1);
    prox.add(order);
    subPoints[0].scale(.5/(order+2));

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

    const int nPts = subPoints[0].size1();
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < nPts; ++j) {
        const double factor = (1. - subPoints[i](j, 2));
        subPoints[i](j, 0) = subPoints[i](j, 0) * factor;
        subPoints[i](j, 1) = subPoints[i](j, 1) * factor;
      }
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
   int order)
{
  if(exponent.size1() != point.size1() || exponent.size2() != point.size2() ||
      exponent.size2() != 3){
    Msg::Fatal("Wrong sizes for pyramid's bez2lag matrix generation %d %d -- %d %d",
      exponent.size1(),point.size1(),
      exponent.size2(),point.size2());
    return fullMatrix<double>(1, 1);
  }

  const int ndofs = exponent.size1();

  fullMatrix<double> bez2Lag(ndofs, ndofs);
  for (int i = 0; i < ndofs; i++) {
    for (int j = 0; j < ndofs; j++) {
      double denom = 1. - point(i, 2);
      bez2Lag(i, j) =
            nChoosek(order + 2, exponent(j, 0))
          * nChoosek(order + 2, exponent(j, 1))
          * nChoosek(order, exponent(j, 2))
          * pow_int(point(i, 0) / denom, exponent(j, 0))
          * pow_int(point(i, 1) / denom, exponent(j, 1))
          * pow_int(1. - point(i, 2)   , exponent(j, 2))
          * pow_int(1. - point(i, 0) / denom, order + 2 - exponent(j, 0))
          * pow_int(1. - point(i, 1) / denom, order + 2 - exponent(j, 1))
          * pow_int(point(i, 2)             , order     - exponent(j, 2));
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
   const fullMatrix<double> &lag2Bez, int order)
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
      generateBez2LagMatrixPyramid(exponents, subPoints[i], order);
    lag2Bez.mult(intermediate1, intermediate2);
    subDivisor.copy(intermediate2, 0, nbPts, 0, nbPts, i*nbPts, 0);
  }
  return subDivisor;
}
}

void bezierBasis::interpolate(const fullMatrix<double> &coeffs,
                              const fullMatrix<double> &uvw,
                              fullMatrix<double> &result,
                              bool bezCoord) const
{
  result.resize(uvw.size1(), coeffs.size2());
  int dimSimplex;
  fullMatrix<double> bezuvw = uvw;
  switch (_type) {
  case TYPE_HEX:
    if (!bezCoord) {
      bezuvw.add(1);
      bezuvw.scale(.5);
    }
    dimSimplex = 0;
    break;

  case TYPE_TET:
    dimSimplex = 3;
    break;

  case TYPE_PRI:
    if (!bezCoord) {
      fullMatrix<double> tmp;
      tmp.setAsProxy(bezuvw, 3, 1);
      tmp.add(1);
      tmp.scale(.5);
    }
    dimSimplex = 2;
    break;

  default:
  case TYPE_PYR:
    Msg::Error("Bezier interpolation not implemented for type of element %d", _type);
    /*bezuvw[0] = .5 * (1 + uvw[0]);
    bezuvw[1] = .5 * (1 + uvw[1]);
    bezuvw[2] = uvw[2];
    _interpolateBezierPyramid(uvw, minmaxQ);*/
    return;
  }

  int numCoeff = _exponents.size1();

  for (int m = 0; m < uvw.size1(); ++m) {
    for (int n = 0; n < coeffs.size2(); ++n) result(m, n) = 0;
    for (int i = 0; i < numCoeff; i++) {
      double dd = 1;
      double pointCompl = 1.;
      int exponentCompl = _order;
      for (int k = 0; k < dimSimplex; k++) {
        dd *= nChoosek(exponentCompl, (int) _exponents(i, k))
          * pow(bezuvw(m, k), _exponents(i, k));
        pointCompl -= bezuvw(m, k);
        exponentCompl -= (int) _exponents(i, k);
      }
      dd *= pow_int(pointCompl, exponentCompl);

      for (int k = dimSimplex; k < _exponents.size2(); k++) {
        dd *= nChoosek(_order, (int) _exponents(i, k))
            * pow_int(bezuvw(m, k), _exponents(i, k))
            * pow_int(1. - bezuvw(m, k), _order - _exponents(i, k));
      }
      for (int n = 0; n < coeffs.size2(); ++n)
        result(m, n) += coeffs(i, n) * dd;
    }
  }
}

void bezierBasis::_construct(int parentType, int p)
{
  _order = p;
  _type = parentType;
  std::vector< fullMatrix<double> > subPoints;

  if (parentType == TYPE_PYR) {
    _numLagCoeff = p == 0 ? 4 : 8;
    _exponents = gmshGenerateMonomialsPyramidGeneral(false, _order+2, _order);

    subPoints = generateSubPointsPyr(_order);
    _numDivisions = static_cast<int>(subPoints.size());

    fullMatrix<double> bezierPoints;
    bezierPoints.resize(_exponents.size1(), _exponents.size2());
    const double ord = _order + 2;
    for (int i = 0; i < bezierPoints.size1(); ++i) {
      bezierPoints(i, 2) = (_order - _exponents(i, 2)) / ord;
      const double scale = 1. - bezierPoints(i, 2);
      bezierPoints(i, 0) = _exponents(i, 0) / ord * scale;
      bezierPoints(i, 1) = _exponents(i, 1) / ord * scale;
    }

    matrixBez2Lag = generateBez2LagMatrixPyramid(_exponents, bezierPoints, _order);
    matrixBez2Lag.invert(matrixLag2Bez);
    subDivisor = generateSubDivisorPyramid(_exponents, subPoints, matrixLag2Bez, _order);
    return;
  }

  switch (parentType) {
    case TYPE_PNT :
      _numLagCoeff = 1;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsLine(0);
      subPoints.push_back(gmshGeneratePointsLine(0));
      break;
    case TYPE_LIN : {
      _numLagCoeff = _order == 0 ? 1 : 2;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsLine(_order);
      subPoints = generateSubPointsLine(_order);
      break;
    }
    case TYPE_TRI : {
      _numLagCoeff = _order == 0 ? 1 : 3;
      _dimSimplex = 2;
      _exponents = gmshGenerateMonomialsTriangle(_order);
      subPoints = generateSubPointsTriangle(_order);
      break;
    }
    case TYPE_QUA : {
      _numLagCoeff = _order == 0 ? 1 : 4;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsQuadrangle(_order);
      subPoints = generateSubPointsQuad(_order);
      break;
    }
    case TYPE_TET : {
      _numLagCoeff = _order == 0 ? 1 : 4;
      _dimSimplex = 3;
      _exponents = gmshGenerateMonomialsTetrahedron(_order);
      subPoints = generateSubPointsTetrahedron(_order);
      break;
    }
    case TYPE_PRI : {
      _numLagCoeff = _order == 0 ? 1 : 6;
      _dimSimplex = 2;
      _exponents = gmshGenerateMonomialsPrism(_order);
      subPoints = generateSubPointsPrism(_order);
      break;
    }
    case TYPE_HEX : {
      _numLagCoeff = _order == 0 ? 1 : 8;
      _dimSimplex = 0;
      _exponents = gmshGenerateMonomialsHexahedron(_order);
      subPoints = generateSubPointsHex(_order);
      break;
    }
    default : {
      Msg::Error("Unknown function space of parentType %d : "
          "reverting to TET_1", parentType);
      _order = 0;
      _numLagCoeff = 4;
      _dimSimplex = 3;
      _exponents = gmshGenerateMonomialsTetrahedron(_order);
      subPoints = generateSubPointsTetrahedron(_order);
      break;
    }
  }
  _numDivisions = static_cast<int>(subPoints.size());

  fullMatrix<double> bezierPoints = _exponents;
  bezierPoints.scale(1./_order);

  matrixBez2Lag = generateBez2LagMatrix(_exponents, bezierPoints, _order, _dimSimplex);
  matrixBez2Lag.invert(matrixLag2Bez);
  subDivisor = generateSubDivisor(_exponents, subPoints, matrixLag2Bez, _order, _dimSimplex);
}
