// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "MetricBasis.h"
//#include "GmshDefines.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"
#include <cmath>

MetricCoefficient::MetricCoefficient(MElement *el) : _element(el)
{
  const int tag = el->getTypeForMSH();
  const int type = ElementType::ParentTypeFromTag(tag);
  const int metricOrder = MetricCoefficient::metricOrder(tag);
  _jacobian = BasisFactory::getJacobianBasis(tag);
  _gradients = BasisFactory::getGradientBasis(tag, metricOrder);
  _bezier = BasisFactory::getBezierBasis(type, metricOrder);

  int nSampPnts = _gradients->getNumSamplingPoints();
  int nMapping = _gradients->getNumMapNodes();
  fullMatrix<double> nodesXYZ(nMapping, 3);
  el->getNodesCoord(nodesXYZ);

  switch (el->getDim()) {
  case 0 :
    return;

  case 1 :
  {
    Msg::Fatal("not implemented");
  }
  break;

  case 2 :
  {
    Msg::Fatal("not implemented");
  }
  break;

  case 3 :
  {
    fullMatrix<double> dxyzdX(nSampPnts,3), dxyzdY(nSampPnts,3), dxyzdZ(nSampPnts,3);
    _gradients->getGradientsFromNodes(nodesXYZ, &dxyzdX, &dxyzdY, &dxyzdZ);

    _coefficientsLag.resize(nSampPnts, 7);
    for (int i = 0; i < nSampPnts; i++) {
      const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
      const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
      const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
      const double dvxdX = dxdX*dxdX + dydX*dydX + dzdX*dzdX;
      const double dvxdY = dxdY*dxdY + dydY*dydY + dzdY*dzdY;
      const double dvxdZ = dxdZ*dxdZ + dydZ*dydZ + dzdZ*dzdZ;
      _coefficientsLag(i, 0) = (dvxdX + dvxdY + dvxdZ) / 3;
      _coefficientsLag(i, 1) = dvxdX - _coefficientsLag(i, 0);
      _coefficientsLag(i, 2) = dvxdY - _coefficientsLag(i, 0);
      _coefficientsLag(i, 3) = dvxdZ - _coefficientsLag(i, 0);
      _coefficientsLag(i, 4) = dxdX*dxdY + dydX*dydY + dzdX*dzdY;
      _coefficientsLag(i, 5) = dxdZ*dxdY + dydZ*dydY + dzdZ*dzdY;
      _coefficientsLag(i, 6) = dxdX*dxdZ + dydX*dydZ + dzdX*dzdZ;
    }
  }
  break;
  }
}

void MetricCoefficient::getCoefficients(fullMatrix<double> &coeff, bool bezier)
{
  fullMatrix<double> *ref;
  switch (_coefficientsLag.size2()) {
  case 1:
    if (!bezier) coeff = _coefficientsLag;
    else {
      if (_coefficientsBez.size2() != 1) _computeBezCoeff();
      coeff = _coefficientsBez;
    }
    break;

  case 3:
    if (!bezier) ref = &_coefficientsLag;
    else {
      if (_coefficientsBez.size2() != 3) _computeBezCoeff();
      ref = &_coefficientsBez;
    }
    coeff.resize(ref->size1(), 2);
    for (int i = 0; i < ref->size1(); ++i) {
      double tmp = pow((*ref)(i, 1), 2);
      tmp += pow((*ref)(i, 2), 2);
      tmp = std::sqrt(tmp);
      coeff(i, 0) = (*ref)(i, 0) - tmp;
      coeff(i, 1) = (*ref)(i, 0) + tmp;
    }
    break;

  case 7:
    if (!bezier) ref = &_coefficientsLag;
    else {
      if (_coefficientsBez.size2() != 7) _computeBezCoeff();
      ref = &_coefficientsBez;
    }
    coeff.resize(ref->size1(), 2);
    for (int i = 0; i < ref->size1(); ++i) {
      double tmp = pow((*ref)(i, 1), 2);
      tmp += pow((*ref)(i, 2), 2);
      tmp += pow((*ref)(i, 3), 2);
      tmp += 2 * pow((*ref)(i, 4), 2);
      tmp += 2 * pow((*ref)(i, 5), 2);
      tmp += 2 * pow((*ref)(i, 6), 2);
      tmp = std::sqrt(tmp);
      double factor = std::sqrt(6)/3;
      coeff(i, 0) = (*ref)(i, 0) - factor * tmp;
      coeff(i, 1) = (*ref)(i, 0) + factor * tmp;
    }
    break;

  default:
    Msg::Error("Wrong number of functions for metric: %d",
               _coefficientsLag.size2());
  }
}

static int nChoosek(int n, int k)
{
  if (n < k || k < 0) {
    Msg::Error("Wrong argument for combination.");
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

void MetricCoefficient::interpolate(const double *uvw, double *minmaxQ)
{
  if (minmaxQ == NULL) {
    Msg::Error("Cannot write solution of interpolation");
    return;
  }

  int order = _bezier->getOrder();

  int dimSimplex;
  fullMatrix<double> exponents;
  double bezuvw[3];
  switch (_element->getType()) {
  case TYPE_PYR:
    bezuvw[0] = .5 * (1 + uvw[0]);
    bezuvw[1] = .5 * (1 + uvw[1]);
    bezuvw[2] = uvw[2];
    _interpolateBezierPyramid(uvw, minmaxQ);
    return;

  case TYPE_HEX:
    bezuvw[0] = .5 * (1 + uvw[0]);
    bezuvw[1] = .5 * (1 + uvw[1]);
    bezuvw[2] = .5 * (1 + uvw[2]);
    dimSimplex = 0;
    exponents = gmshGenerateMonomialsHexahedron(order);
    break;

  case TYPE_TET:
    bezuvw[0] = uvw[0];
    bezuvw[1] = uvw[1];
    bezuvw[2] = uvw[2];
    dimSimplex = 3;
    exponents = gmshGenerateMonomialsTetrahedron(order);
    break;

  case TYPE_PRI:
    bezuvw[0] = uvw[0];
    bezuvw[1] = uvw[1];
    bezuvw[2] = .5 * (1 + uvw[2]);
    dimSimplex = 2;
    exponents = gmshGenerateMonomialsPrism(order);
    break;
  }

  int numCoeff = exponents.size1();
  int dim = exponents.size2();

  if (_coefficientsBez.size2() == 0) _computeBezCoeff();

  double *terms = new double[_coefficientsBez.size2()];
  for (int t = 0; t < _coefficientsBez.size2(); ++t) {
    terms[t] = 0;
    for (int i = 0; i < numCoeff; i++) {
      double dd = 1;
      double pointCompl = 1.;
      int exponentCompl = order;
      for (int k = 0; k < dimSimplex; k++) {
        dd *= nChoosek(exponentCompl, (int) exponents(i, k))
          * pow(bezuvw[k], exponents(i, k));
        pointCompl -= bezuvw[k];
        exponentCompl -= (int) exponents(i, k);
      }
      dd *= pow(pointCompl, exponentCompl);

      for (int k = dimSimplex; k < dim; k++)
        dd *= nChoosek(order, (int) exponents(i, k))
            * pow(bezuvw[k], exponents(i, k))
            * pow(1. - bezuvw[k], order - exponents(i, k));
      terms[t] += _coefficientsBez(i, t) * dd;
    }
  }

  switch (_coefficientsBez.size2()) {
  case 1:
    minmaxQ[0] = terms[0];
    minmaxQ[1] = terms[0];
    break;

  case 3:
  {
    double tmp = pow(terms[1], 2);
    tmp += pow(terms[2], 2);
    tmp = std::sqrt(tmp);
    minmaxQ[0] = terms[0] - tmp;
    minmaxQ[1] = terms[0] + tmp;
  }
    break;

  case 7:
  {
    double tmp = pow(terms[1], 2);
    tmp += pow(terms[2], 2);
    tmp += pow(terms[3], 2);
    tmp += 2 * pow(terms[4], 2);
    tmp += 2 * pow(terms[5], 2);
    tmp += 2 * pow(terms[6], 2);
    tmp = std::sqrt(tmp);
    double factor = std::sqrt(6)/3;
    if (tmp < 1e-3*terms[0]) {
      static int aa = 0;
      Msg::Info("%d", ++aa);
      minmaxQ[0] = terms[0] - factor * tmp;
      minmaxQ[1] = terms[0] + factor * tmp;
    }
    else {
      double phi;
      {
        fullMatrix<double> nodes(_element->getNumShapeFunctions(),3);
        _element->getNodesCoord(nodes);
        fullVector<double> jac(_jacobian->getNumJacNodes());
        _jacobian->getSignedJacobian(nodes, jac);

        nodes.resize(1, 3);
        nodes(0, 0) = uvw[0];
        nodes(0, 1) = uvw[1];
        nodes(0, 2) = uvw[2];

        fullMatrix<double> result;
        _jacobian->interpolate(jac, nodes, result);
        phi = result(0, 0)*result(0, 0);
      }
      phi -= terms[0]*terms[0]*terms[0];
      phi += .5*terms[0]*tmp*tmp;
      phi /= tmp*tmp*tmp;
      phi *= 3*std::sqrt(6);
      if (phi >  1) phi =  1;
      if (phi < -1) phi = -1;
      phi = std::acos(phi)/3;
      minmaxQ[0] = terms[0] + factor * tmp * std::cos(phi + 2*M_PI/3);
      minmaxQ[1] = terms[0] + factor * tmp * std::cos(phi);
    }
  }
    break;

  default:
    Msg::Error("Wrong number of functions for metric: %d",
               _coefficientsLag.size2());
  }
}

double MetricCoefficient::getBoundRmin(double tol)
{
  fullMatrix<double> nodes(_element->getNumShapeFunctions(),3);
  fullVector<double> jac(_jacobian->getNumJacNodes());
  _element->getNodesCoord(nodes);
  _jacobian->getSignedJacobian(nodes, jac);

  if(jac.size() != _coefficientsBez.size1())
    Msg::Fatal("not same size, jac %d, coeff %d", jac.size(), _coefficientsBez.size1());

  // compute RminLag
  double RminLag = 1.;
  const double factor1 = std::sqrt(6) / 3;
  const double factor2 = std::sqrt(6) * 3;

  for (int i = 0; i < _bezier->getNumLagCoeff(); ++i) {
    double q = _coefficientsBez(i, 0);
    double tmp = pow_int(_coefficientsBez(i, 1), 2);
    tmp += pow_int(_coefficientsBez(i, 2), 2);
    tmp += pow_int(_coefficientsBez(i, 3), 2);
    tmp += 2 * pow_int(_coefficientsBez(i, 4), 2);
    tmp += 2 * pow_int(_coefficientsBez(i, 5), 2);
    tmp += 2 * pow_int(_coefficientsBez(i, 6), 2);
    tmp = tmp*factor1;
    if (tmp < 1e-3 * q) {
      tmp = (q - tmp) / (q + tmp);
      RminLag = std::min(RminLag, tmp);
    }
    else {
      double phi = jac(i)*jac(i);
      phi -= q * q * q;
      phi += .5 * q * tmp * tmp;
      phi /= tmp * tmp * tmp;
      phi *= factor2;
      if (phi >  1.1 || phi < -1.1) Msg::Warning("phi %g", phi);
      if (phi >  1) phi =  1;
      if (phi < -1) phi = -1;
      phi = std::acos(phi)/3;
      tmp = (q + tmp * std::cos(phi + 2*M_PI/3)) / (q + tmp * std::cos(phi));
      RminLag = std::min(RminLag, tmp);
    }
  }

  // compute RminBez
  /*double RminBez = 1.;
  double minq = minq();
  double minp = minp();
  double maxq = maxq();
  double maxp = maxp();
  if (minq < 1e-3 * maxp) {
    double tmp = (minq - maxp) / (minq + maxp);
    RminLag = std::min(RminBez, tmp);
  }
  else {

  }*/


  /*compute RminBez
  if RminLag-RminBez < tol : return RminBez
  return subdivide*/
  return RminLag;
}

int MetricCoefficient::metricOrder(int tag)
{
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int order = ElementType::OrderFromTag(tag);

  switch (parentType) {
    case TYPE_PNT : return 0;
    case TYPE_LIN : return order;
    case TYPE_TRI :
    case TYPE_TET : return 2*order-2;
    case TYPE_QUA :
    case TYPE_PRI :
    case TYPE_HEX :
    case TYPE_PYR : return 2*order;
    default :
      Msg::Error("Unknown element type %d, return order 0", parentType);
      return 0;
  }
}

void MetricCoefficient::_interpolateBezierPyramid(const double *uvw, double *minmaxQ)
{
  int order = _jacobian->bezier->getOrder();

  fullMatrix<double> exponents = JacobianBasis::generateJacMonomialsPyramid(order);
  int numCoeff = exponents.size1();

  if (_coefficientsBez.size2() == 0) _computeBezCoeff();

  static int aa = 0;
  if (++aa == 1) {
    fullMatrix<double> val;
    getCoefficients(val, true);
    for (int i = 0; i < val.size2(); ++i) {
      Msg::Info("--------- column %d", i);
      for (int j = 0; j < val.size1(); ++j) {
        Msg::Info("%.2e", val(j, i));
      }
    }
  }
  double terms[7];
  for (int t = 0; t < _coefficientsBez.size2(); ++t) {
    terms[t] = 0;
    for (int j = 0; j < numCoeff; j++) {
      double dd =
          nChoosek(order, exponents(j, 2))
          * pow(uvw[2], exponents(j, 2))
          * pow(1. - uvw[2], order - exponents(j, 2));

      double p = order + 2 - exponents(j, 2);
      double denom = 1. - uvw[2];
      dd *= nChoosek(p, exponents(j, 0))
          * nChoosek(p, exponents(j, 1))
          * pow(uvw[0] / denom, exponents(j, 0))
          * pow(uvw[1] / denom, exponents(j, 1))
          * pow(1. - uvw[0] / denom, p - exponents(j, 0))
          * pow(1. - uvw[1] / denom, p - exponents(j, 1));
      terms[t] += _coefficientsBez(j, t) * dd;
    }
  }

  double tmp = pow(terms[1], 2);
  tmp += pow(terms[2], 2);
  tmp += pow(terms[3], 2);
  tmp += 2 * pow(terms[4], 2);
  tmp += 2 * pow(terms[5], 2);
  tmp += 2 * pow(terms[6], 2);
  tmp = std::sqrt(tmp);
  double factor = std::sqrt(6)/3;
  minmaxQ[0] = terms[0] - factor * tmp;
  minmaxQ[1] = terms[0] + factor * tmp;
}

void MetricCoefficient::_computeBezCoeff()
{
  _coefficientsBez.resize(_coefficientsLag.size1(),
                          _coefficientsLag.size2());
  _bezier->matrixLag2Bez.mult(_coefficientsLag, _coefficientsBez);
}
