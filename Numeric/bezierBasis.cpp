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

namespace {

  // Sub Control Points
  std::vector<fullMatrix<double> > generateSubPointsLine(int order)
  {
    std::vector<fullMatrix<double> > subPoints(2);
    subPoints[0] = gmshGenerateMonomialsLine(order);
    subPoints[0].scale(.5 / order);

    subPoints[1].copy(subPoints[0]);
    subPoints[1].add(.5);
    return subPoints;
  }

  std::vector<fullMatrix<double> > generateSubPointsTriangle(int order)
  {
    std::vector<fullMatrix<double> > subPoints(4);
    fullMatrix<double> prox;
    subPoints[0] = gmshGenerateMonomialsTriangle(order);
    subPoints[0].scale(.5 / order);

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
    subPoints[0] = gmshGenerateMonomialsQuadrangle(order);
    subPoints[0].scale(.5 / order);

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
    subPoints[0] = gmshGenerateMonomialsTetrahedron(order);
    subPoints[0].scale(.5 / order);

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

    subPoints[0] = gmshGenerateMonomialsPrism(order);
    subPoints[0].scale(.5 / order);

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

    subPoints[0] = gmshGenerateMonomialsHexahedron(order);
    subPoints[0].scale(.5 / order);

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
    if(nk == 0) {
      std::vector<fullMatrix<double> > subPoints(4);
      fullMatrix<double> prox;

      subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, nij, nk);
      subPoints[0].scale(.5 / nij);

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
      std::vector<fullMatrix<double> > subPoints(8);
      fullMatrix<double> ref, prox;

      subPoints[0] = gmshGenerateMonomialsPyramidGeneral(false, nij, nk);
      prox.setAsProxy(subPoints[0], 2, 1);
      prox.scale(-1);
      prox.add(nk);
      subPoints[0].scale(.5 / std::max(nij, nk));

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

      for(int i = 0; i < 8; ++i) {
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
          nChoosek(n01, exponent(j, 0)) * nChoosek(n01, exponent(j, 1)) *
          nChoosek(nk, exponent(j, 2)) * pow_int(point(i, 0), exponent(j, 0)) *
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

} // namespace

bezierBasis::bezierBasis(FuncSpaceData data) : _data(data), _raiser(NULL)
{
  if(_data.elementType() == TYPE_PYR)
    _constructPyr();
  else
    _construct();
}

bezierBasis::~bezierBasis() { delete _raiser; }

void bezierBasis::f(double u, double v, double w, double *sf) const
{
  const int tag = ElementType::getType(_data.elementType(), _data.spaceOrder());
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

void bezierBasis::generateBezierPoints(fullMatrix<double> &points) const
{
  gmshGenerateMonomials(_data, points);
  points.scale(1. / _data.spaceOrder());
  if(_data.elementType() == TYPE_PYR && _data.nk() < _data.spaceOrder()) {
    fullMatrix<double> prox;
    prox.setAsProxy(points, 2, 1);
    prox.add(1 - static_cast<double>(_data.nk()) / _data.spaceOrder());
  }
}

void bezierBasis::_fePoints2BezPoints(fullMatrix<double> &points) const
{
  fullMatrix<double> tmp;
  switch(_data.elementType()) {
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
    Msg::Error("_fePoints2BezPoints not implemented for "
               "type of element %d",
               _data.elementType());
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
  if(_data.elementType() == TYPE_PYR) {
    Msg::Error("This bezierBasis constructor is not for pyramids!");
    return;
  }

  std::vector<fullMatrix<double> > subPoints;
  int order = _data.spaceOrder();

  switch(_data.elementType()) {
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
    Msg::Error("Unknown function space for parentType %d", _data.elementType());
    return;
  }
  _numDivisions = static_cast<int>(subPoints.size());

  fullMatrix<double> bezierPoints = _exponents;
  if(order) bezierPoints.scale(1. / order);

  matrixBez2Lag =
    generateBez2LagMatrix(_exponents, bezierPoints, order, _dimSimplex);
  matrixBez2Lag.invert(matrixLag2Bez);
  subDivisor = generateSubDivisor(_exponents, subPoints, matrixLag2Bez, order,
                                  _dimSimplex);
}

void bezierBasis::_constructPyr()
{
  if(_data.elementType() != TYPE_PYR) {
    Msg::Error("This bezierBasis constructor is for pyramids!");
  }

  const bool pyr = _data.isPyramidalSpace();
  const int nij = _data.nij(), nk = _data.nk();

  _numLagCoeff = nk == 0 ? 4 : 8;
  _dimSimplex = 0;
  gmshGenerateMonomials(_data, _exponents);

  fullMatrix<double> bezierPoints;
  generateBezierPoints(bezierPoints);
  matrixBez2Lag =
    generateBez2LagMatrixPyramid(_exponents, bezierPoints, pyr, nij, nk);
  matrixBez2Lag.invert(matrixLag2Bez);
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

// const bezierBasis* bezierBasisRaiser::getRaisedBezierBasis(int raised) const
//{
//  if(raised != 2 && raised != 3){
//    Msg::Error("Why would you want other than 2 or 3?");
//    return NULL;
//  }
//  if(_bfs->_data.elementType() != TYPE_PYR)
//    return BasisFactory::getBezierBasis(
//        FuncSpaceData(_bfs->_data, _bfs->_data.spaceOrder()*raised));
//  else
//    return BasisFactory::getBezierBasis(
//        FuncSpaceData(_bfs->_data,
//                      _bfs->_data.nij()*raised,
//                      _bfs->_data.nk()*raised));
//}

void bezierBasisRaiser::_fillRaiserData()
{
  if(_bfs->getType() == TYPE_PYR) {
    _fillRaiserDataPyr();
    return;
  }

  fullMatrix<int> exp;
  {
    const fullMatrix<double> &expD = _bfs->_exponents;
    double2int(expD, exp);
  }
  int order = _bfs->getOrder();
  int ncoeff = exp.size1();
  int dim = _bfs->getDim();
  int dimSimplex = _bfs->getDimSimplex();

  // Speedup: Since the coefficients (num/den) are invariant from a permutation
  // of the indices (i, j) or (i, j, k), we fill only the raiser data for
  // i <= j <= k (and adapt the value to take into account the multiplicity).

  // Construction of raiser 2
  fullMatrix<int> exp2;
  {
    fullMatrix<double> expD2;
    FuncSpaceData dataRaiser2(_bfs->_data, 2 * order);
    gmshGenerateMonomials(dataRaiser2, expD2);
    double2int(expD2, exp2);
    _raiser2.resize(exp2.size1());
  }

  std::map<int, int> hashToInd2;
  for(int i = 0; i < exp2.size1(); ++i) {
    int hash = 0;
    for(int l = 0; l < dim; l++) {
      hash += exp2(i, l) * pow_int(2 * order + 1, l);
    }
    hashToInd2[hash] = i;
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

      // taking into account the multiplicity (reminder: i <= j)
      if(i < j) num *= 2;

      int hash = 0;
      for(int l = 0; l < dim; l++) {
        hash += (exp(i, l) + exp(j, l)) * pow_int(2 * order + 1, l);
      }
      _raiser2[hashToInd2[hash]].push_back(_data(num / den, i, j));
    }
  }

  // Construction of raiser 3
  fullMatrix<int> exp3;
  {
    fullMatrix<double> expD3;
    FuncSpaceData dataRaiser3(_bfs->_data, 3 * order);
    gmshGenerateMonomials(dataRaiser3, expD3);
    double2int(expD3, exp3);
    _raiser3.resize(exp3.size1());
  }

  std::map<int, int> hashToInd3;
  for(int i = 0; i < exp3.size1(); ++i) {
    int hash = 0;
    for(int l = 0; l < dim; l++) {
      hash += exp3(i, l) * pow_int(3 * order + 1, l);
    }
    hashToInd3[hash] = i;
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

        // taking into account the multiplicity (Reminder: i <= j <= k)
        if(i < j && j < k)
          num *= 6;
        else if(i < j || j < k)
          num *= 3;

        int hash = 0;
        for(int l = 0; l < dim; l++) {
          hash +=
            (exp(i, l) + exp(j, l) + exp(k, l)) * pow_int(3 * order + 1, l);
        }
        _raiser3[hashToInd3[hash]].push_back(_data(num / den, i, j, k));
      }
    }
  }
}

void bezierBasisRaiser::_fillRaiserDataPyr()
{
  FuncSpaceData fsdata = _bfs->getFuncSpaceData();
  if(fsdata.elementType() != TYPE_PYR) {
    _fillRaiserData();
    return;
  }
  if(fsdata.isPyramidalSpace()) {
    Msg::Error("Bezier raiser not implemented for pyramidal space");
    return;
  }

  fullMatrix<int> exp;
  {
    const fullMatrix<double> &expD = _bfs->_exponents;
    double2int(expD, exp);
  }
  int ncoeff = exp.size1();
  int order[3] = {fsdata.nij(), fsdata.nij(), fsdata.nk()};
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
                                     fullVector<double> &coeffSquare)
{
  coeffSquare.resize(_raiser2.size(), true);

  if(&coeffA == &coeffB) {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        _data &d = _raiser2[ind][l];
        coeffSquare(ind) += d.val * coeffA(d.i) * coeffB(d.j);
      }
    }
  }
  else {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        _data &d = _raiser2[ind][l];
        coeffSquare(ind) +=
          d.val / 2 * (coeffA(d.i) * coeffB(d.j) + coeffA(d.j) * coeffB(d.i));
      }
    }
  }
}

void bezierBasisRaiser::computeCoeff(const fullVector<double> &coeffA,
                                     const fullVector<double> &coeffB,
                                     const fullVector<double> &coeffC,
                                     fullVector<double> &coeffCubic)
{
  coeffCubic.resize(_raiser3.size(), true);

  if(&coeffA == &coeffB && &coeffB == &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        _data &d = _raiser3[ind][l];
        coeffCubic(ind) += d.val * coeffA(d.i) * coeffB(d.j) * coeffC(d.k);
      }
    }
  }
  else if(&coeffA != &coeffB && &coeffB != &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        _data &d = _raiser3[ind][l];
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
                                     fullMatrix<double> &coeffSquare)
{
  coeffSquare.resize(_raiser2.size(), coeffA.size2(), true);

  if(&coeffA == &coeffB) {
    for(std::size_t ind = 0; ind < _raiser2.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser2[ind].size(); ++l) {
        _data &d = _raiser2[ind][l];
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
        _data &d = _raiser2[ind][l];
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
                                     fullMatrix<double> &coeffCubic)
{
  coeffCubic.resize(_raiser3.size(), coeffB.size2(), true);

  if(&coeffB == &coeffC) {
    for(std::size_t ind = 0; ind < _raiser3.size(); ++ind) {
      for(std::size_t l = 0; l < _raiser3[ind].size(); ++l) {
        _data &d = _raiser3[ind][l];
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
        _data &d = _raiser3[ind][l];
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

bezierCoeff::bezierCoeff(FuncSpaceData data, fullMatrix<double> &lagCoeff,
                         int num)
    : _numPool(num), _funcSpaceData(data),
      _basis(BasisFactory::getBezierBasis(data))
{
  _r = lagCoeff.size1();
  _c = lagCoeff.size2();
  _own_data = false;
  if (num == 0 && _pool0)
    _data = _pool0->giveBlock(this);
  else if (num == 1 && _pool1)
    _data = _pool1->giveBlock(this);
  else {
    _own_data = true;
    _data = new double[_r * _c];
  }

  fullMatrix<double> prox(_data, _r, _c);
  _basis->matrixLag2Bez2.mult(lagCoeff, prox);
}

bezierCoeff::bezierCoeff(FuncSpaceData data, fullVector<double> &lagCoeff,
                         int num)
    : _numPool(num), _funcSpaceData(data), _basis(BasisFactory::getBezierBasis(data))
{
  _r = lagCoeff.size();
  _c = 1;
  _own_data = false;
  if (num == 0 && _pool0)
    _data = _pool0->giveBlock(this);
  else if (num == 1 && _pool1)
    _data = _pool1->giveBlock(this);
  else {
    _own_data = true;
    _data = new double[_r * _c];
  }

  fullVector<double> prox(_data, _r);
  _basis->matrixLag2Bez2.mult(lagCoeff, prox);
}

bezierCoeff::bezierCoeff(const bezierCoeff &other, bool swap)
{
  _numPool = other._numPool;
  _funcSpaceData = other._funcSpaceData;
  _basis = other._basis;
  _r = other._r;
  _c = other._c;
  if (swap) {
    _own_data = other._own_data;
    _data = other._data;
    const_cast<bezierCoeff&>(other)._own_data = false;
    const_cast<bezierCoeff&>(other)._numPool = -1;
  }
  else {
    _own_data = false;
    if (_numPool == 0 && _pool0)
      _data = _pool0->giveBlock(this);
    else if (_numPool == 1 && _pool1)
      _data = _pool1->giveBlock(this);
    else {
      _own_data = true;
      _data = new double[_r * _c];
    }
  }
}

bezierCoeff::~bezierCoeff()
{
  if (_own_data)
    delete[] _data;
  else {
    if (_numPool == -1)
      return;
    if (_numPool == 0 && _pool0)
      _pool0->releaseBlock(_data, this);
    else if (_numPool == 1 && _pool1)
      _pool1->releaseBlock(_data, this);
    else
      Msg::Error("Not supposed to be here. destructor bezierCoeff");
  }
}

void bezierCoeff::usePools(int size0, int size1)
{
  if (size0) {
    if (!_pool0) _pool0 = new bezierMemoryPool();
    _pool0->setSizeBlocks(size0);
  }
  if (size1) {
    if (!_pool1) _pool1 = new bezierMemoryPool();
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
  if (_own_data)
    Msg::Error("I own data, cannot do that");
  else
    _data += diff;
}

void bezierCoeff::subdivide(std::vector<bezierCoeff> &subCoeff) const
{
  int n = _funcSpaceData.spaceOrder()+1;

  switch(_funcSpaceData.elementType()) {
    case TYPE_TRI:
      subCoeff.resize(4, *this);
      _subdivideTriangle(*this, n, 0, subCoeff);
      return;
    case TYPE_QUA:
      subCoeff.resize(4, *this);
      _subdivideQuadrangle(*this, n, subCoeff);
  }
  // size all subcoeff (- coeff identical)
  // simplicial: same size and copy before subdividing
  // non simplicial: 2x size, subdivide then copy
  // prism: faire d'abord tri puis lignes
}

void bezierCoeff::_subdivide(fullMatrix<double> &coeff, int n, int start)
{
  // One-dimensional De Casteljau algorithm if consecutive data
  const int dim = coeff.size2();
  for (int iter = 1; iter < n; ++iter) {
    for (int I = start + iter; I < start+2*n-iter; I += 2) {
      for (int K = 0; K < dim; ++K) {
        coeff(I, K) = .5 * (coeff(I-1, K) + coeff(I+1, K));
      }
    }
  }
}

void bezierCoeff::_subdivide(fullMatrix<double> &coeff, int n, int start,
                             int inc)
{
  // One-dimensional De Casteljau algorithm if non-consecutive data
  const int dim = coeff.size2();
  for (int iter = 1; iter < n; ++iter) {
    for (int i = iter; i < 2*n-iter; i += 2) {
      int I = start + i * inc;
      for (int K = 0; K < dim; ++K) {
        coeff(I, K) = .5 * (coeff(I-inc, K) + coeff(I+inc, K));
      }
    }
  }
}

void bezierCoeff::_subdivideTriangle(const bezierCoeff &coeff, int n,
                                     int start,
                                     std::vector<bezierCoeff> &vSubCoeff)
{
  const int dim = coeff._c;

  // copy into first subdomain
  bezierCoeff &sub = vSubCoeff[0];
  _copy(coeff, start, (n + 1) * n / 2, sub);

  // Subdivide in u direction
  // TODO: consider precompute vector<pair<int, int>> for this
  for (int iter = 1; iter < n; ++iter) {
    for (int j = 0; j < n-iter; ++j) {
      for (int i = n-1-j; i >= iter; --i) {
        const int I = start + _ij2Index(i, j, n);
        const int Im = start + _ij2Index(i - 1, j, n);
        for (int K = 0; K < dim; ++K) {
          sub(I, K) = .5 * (sub(Im, K) + sub(I, K));
        }
      }
    }
  }
  // Subdivide in v direction
  for (int iter = 1; iter < n; ++iter) {
    for (int j = n-1; j >= iter; --j) {
      for (int i = 0; i < n-j; ++i) {
        const int I = start + _ij2Index(i, j, n);
        const int Im = start + _ij2Index(i, j - 1, n);
        for (int K = 0; K < dim; ++K) {
          sub(I, K) = .5 * (sub(Im, K) + sub(I, K));
        }
      }
    }
  }

  bezierCoeff &sub2 = vSubCoeff[1];
  _copy(sub, start, (n + 1) * n / 2, sub2);
  //
  // TODO: consider precompute vector<tuple<int, int, int>> for this
  for (int iter = 1; iter < n; ++iter) {
    for (int j = 0; j < n-iter; ++j) {
      for (int i = 0; i < n-1-j; ++i) {
        const int I = start  + _ij2Index(  i,   j, n);
        const int Ia = start + _ij2Index(i+1,   j, n);
        const int Ib = start + _ij2Index(  i, j+1, n);
        for (int K = 0; K < dim; ++K) {
          sub(I, K) = sub(Ia, K) + sub(Ib, K) - sub(I, K);
        }
      }
    }
  }

  bezierCoeff &sub3 = vSubCoeff[2];
  _copy(sub3, start, (n + 1) * n / 2, sub2);
  for (int iter = 1; iter < n; ++iter) {
    for (int j = 0; j < n-iter; ++j) {
      for (int i = n-1-j; i >= iter; --i) {
        const int I = start  + _ij2Index(  i,   j, n);
        const int Ia = start + _ij2Index(i-1,   j, n);
        const int Ib = start + _ij2Index(i-1, j+1, n);
        for (int K = 0; K < dim; ++K) {
          sub(I, K) = sub(Ia, K) + sub(Ib, K) - sub(I, K);
        }
      }
    }
  }

  bezierCoeff &sub4 = vSubCoeff[3];
  _copy(sub4, start, (n + 1) * n / 2, sub2); // copy 2, not 3
  for (int iter = 1; iter < n; ++iter) {
    for (int j = n-1; j >= iter; --j) {
      for (int i = 0; i < n-j; ++i) {
        const int I = start  + _ij2Index(  i,   j, n);
        const int Ia = start + _ij2Index(  i, j-1, n);
        const int Ib = start + _ij2Index(i+1, j-1, n);
        for (int K = 0; K < dim; ++K) {
          sub(I, K) = sub(Ia, K) + sub(Ib, K) - sub(I, K);
        }
      }
    }
  }
}

void bezierCoeff::_subdivideQuadrangle(const bezierCoeff &coeff, int n,
                                       std::vector<bezierCoeff> &subCoeff)
{
  const int N = 2 * n - 1;
  const int dim = coeff._c;
  _sub.resize(N*N, 1, false);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      const int I1 = i + j*n;
      const int I2 = (2*i) + (2*j)*N;
      for (int k = 0; k < dim; ++k) {
        _sub(I2, k) = coeff(I1, k);
      }
    }
  }
  for (int i = 0; i < N; i += 2) {
    _subdivide(_sub, n, i, N);
  }
  for (int j = 0; j < N; ++j) {
    _subdivide(_sub, n, j*N);
  }
  _copyQuad(_sub,   0,   0, n, subCoeff[0]);
  _copyQuad(_sub, n-1,   0, n, subCoeff[1]);
  _copyQuad(_sub, n-1, n-1, n, subCoeff[2]);
  _copyQuad(_sub,   0, n-1, n, subCoeff[3]);
  return;
}

void bezierCoeff::_copy(const bezierCoeff &from, int start, int num,
                        bezierCoeff &to)
{
  const int dim = from._c;
  for (int i = start; i < start + num; ++i) {
    for (int j = 0; j < dim; ++j) {
      to(i, j) = from(i, j);
    }
  }
}

void
bezierCoeff::_copyQuad(const fullMatrix<double> &allSub, int starti, int startj,
                       int n, bezierCoeff &sub)
{
  const int dim = allSub.size2();
  const int N = 2*n-1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      const int I1 = i + j*n;
      const int I2 = (starti+i) + (startj+j) * N;
      for (int K = 0; K < dim; ++K) {
        sub(I1, K) = allSub(I2, K);
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
  if (_numUsedBlocks) {
    Msg::Error("Cannot change size of blocks if blocks are still being used!");
    return;
  }
  _sizeBlocks = size;
  _endOfSearch = 0;
}

double* bezierMemoryPool::giveBlock(bezierCoeff *bez)
{
  _checkEnoughMemory();

  if (_numUsedBlocks == _endOfSearch) {
    int idx = _endOfSearch;
    if (_bezierCoeff.size() == idx)
      _bezierCoeff.push_back(bez);
    else if (_bezierCoeff[idx]) {
      Msg::Error("this block is being used!?");
      return NULL;
    }
    else
      _bezierCoeff[idx] = bez;
    ++_numUsedBlocks;
    ++_endOfSearch;
    return &_memory.front() + _sizeBlocks * idx;
  }

  for (int i = 0; i < _endOfSearch; ++i) {
    int idx = _currentIndexOfSearch;
    ++_currentIndexOfSearch;
    if (_currentIndexOfSearch == _endOfSearch)
      _currentIndexOfSearch = 0;
    if (!_bezierCoeff[idx]) {
      _bezierCoeff[idx] = bez;
      ++_numUsedBlocks;
      return &_memory.front() + _sizeBlocks * idx;
    }
  }

  // We must never be here. If yes, this means that
  // _numUsedBlocks < _endOfSearch
  // and _bezierCoeff[i] for i < _endOfSearch are all different from
  // NULL which should never happens.
  Msg::Error("Wrong state of bezierMemoryPool. "
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
  if (idx == _endOfSearch-1) {
    do {--_endOfSearch;}
    while (_endOfSearch && !_bezierCoeff[_endOfSearch-1]);
    if (_currentIndexOfSearch >= _endOfSearch)
      _currentIndexOfSearch = 0;
  }
  --_numUsedBlocks;
}

void bezierMemoryPool::freeMemory()
{
  if (_numUsedBlocks) {
    Msg::Error("I cannot free memory if some is still in use!");
    return;
  }
  // force deallocation:
  std::vector<double> dummy;
  _memory.swap(dummy);
}

void bezierMemoryPool::_checkEnoughMemory()
{
  if (_numUsedBlocks < _memory.size() / _sizeBlocks) return;

  double *pointer = &_memory.front();
  _memory.resize(_memory.size() + _sizeBlocks);

  if (pointer == &_memory.front()) return;

  // If a reallocation has been performed at a different place of the memory,
  // then we need to update pointers

  long diff = &_memory.front() - pointer;
  for (unsigned int i = 0; i < _bezierCoeff.size(); ++i) {
    if (_bezierCoeff[i]) _bezierCoeff[i]->updateDataPtr(diff);
  }
}
