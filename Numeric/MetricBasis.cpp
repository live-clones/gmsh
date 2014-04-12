// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "MetricBasis.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"
#include <cmath>
#include <queue>
#include "OS.h"

namespace {
  double cubicCardanoRoot(double p, double q)
  {
    double A = q*q/4 + p*p*p/27;
    if (A > 0) {
      double sq = std::sqrt(A);
      return std::pow(-q/2+sq, 1/3.) + std::pow(-q/2-sq, 1/3.);
    }
    else {
      double module = std::sqrt(-p*p*p/27);
      double ang = std::acos(-q/2/module);
      return 2 * std::pow(module, 1/3.) * std::cos(ang/3);
    }
  }

  int nChoosek(int n, int k)
  {
    if (n < k || k < 0) {
      Msg::Error("Wrong argument for combination. n %d k %d", n, k);
      int a[2];
      int e = 0;
      for (int i = 0; i < 10000000; ++i) e+=a[i];
      Msg::Info("%d",e);
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
}

MetricCoefficient::MetricCoefficient(MElement *el) : _element(el)
{
  const int tag = el->getTypeForMSH();
  const int type = ElementType::ParentTypeFromTag(tag);
  const int metricOrder = MetricCoefficient::metricOrder(tag);
  if (type == TYPE_HEX || type == TYPE_PRI) {
    int order = ElementType::OrderFromTag(tag);
    _jacobian = new JacobianBasis(tag, 3*order);
  }
  else if (type == TYPE_TET)
    _jacobian = BasisFactory::getJacobianBasis(tag);
  else
    Msg::Fatal("metric not implemented for element tag %d", tag);
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
      const double fact = std::sqrt(2);
      _coefficientsLag(i, 4) = fact * (dxdX*dxdY + dydX*dydY + dzdX*dzdY);
      _coefficientsLag(i, 5) = fact * (dxdZ*dxdY + dydZ*dydY + dzdZ*dzdY);
      _coefficientsLag(i, 6) = fact * (dxdX*dxdZ + dydX*dydZ + dzdX*dzdZ);
    }
  }
  break;
  }

  _fillInequalities(metricOrder);
}

void MetricCoefficient::_fillInequalities(int metricOrder)
{
  int dimSimplex = _bezier->_dimSimplex;
  int dim = _bezier->getDim();
  fullMatrix<int> exp(_bezier->_exponents.size1(), _bezier->_exponents.size2());
  for (int i = 0; i < _bezier->_exponents.size1(); ++i) {
    for (int j = 0; j < _bezier->_exponents.size2(); ++j) {
      exp(i, j) = static_cast<int>(_bezier->_exponents(i, j) + .5);
    }
  }
  int ncoeff = _coefficientsLag.size1();

  int countP3 = 0, countJ2 = 0, countA = 0;
  double tol = .1;
  for (int i = 0; i < ncoeff; i++) {
    for (int j = i; j < ncoeff; j++) {
      double num = 1, den = 1;
      {
        int compl1 = metricOrder;
        int compl2 = metricOrder;
        int compltot = 2*metricOrder;
        for (int k = 0; k < dimSimplex; k++) {
          num *= nChoosek(compl1, exp(i, k))
               * nChoosek(compl2, exp(j, k));
          den *= nChoosek(compltot, exp(i, k) + exp(j, k));
          compl1 -= exp(i, k);
          compl2 -= exp(j, k);
          compltot -= exp(i, k) + exp(j, k);
        }
        for (int k = dimSimplex; k < dim; k++) {
          num *= nChoosek(metricOrder, exp(i, k))
               * nChoosek(metricOrder, exp(j, k));
          den *= nChoosek(2*metricOrder, exp(i, k) + exp(j, k));
        }
      }

      if (i != j) num *= 2;

      ++countA;
      int hash = 0;
      for (int l = 0; l < dim; l++) {
        hash += (exp(i, l)+exp(j, l)) * pow_int(2*metricOrder+1, l);
      }
      _ineqA[hash].push_back(IneqData(num/den, i, j));

      for (int k = j; k < ncoeff; ++k) {
        double num = 1, den = 1;
        {
          int compl1 = metricOrder;
          int compl2 = metricOrder;
          int compl3 = metricOrder;
          int compltot = 3*metricOrder;
          for (int l = 0; l < dimSimplex; l++) {
            num *= nChoosek(compl1, exp(i, l))
                 * nChoosek(compl2, exp(j, l))
                 * nChoosek(compl3, exp(k, l));
            den *= nChoosek(compltot, exp(i, l) + exp(j, l) + exp(k, l));
            compl1 -= exp(i, l);
            compl2 -= exp(j, l);
            compl3 -= exp(k, l);
            compltot -= exp(i, l) + exp(j, l) + exp(k, l);
          }
          for (int l = dimSimplex; l < dim; l++) {
            num *= nChoosek(metricOrder, exp(i, l))
                 * nChoosek(metricOrder, exp(j, l))
                 * nChoosek(metricOrder, exp(k, l));
            den *= nChoosek(3*metricOrder, exp(i, l) + exp(j, l) + exp(k, l));
          }
        }

        if (i == j) {
          if (j != k) num *= 3;
        }
        else {
          if (j == k || i == k) num *= 3;
          else num *= 6;
        }

        ++countP3;
        int hash = 0;
        for (int l = 0; l < dim; l++) {
          hash += (exp(i, l)+exp(j, l)+exp(k, l)) * pow_int(3*metricOrder+1, l);
        }
        _ineqP3[hash].push_back(IneqData(num/den, i, j, k));
      }
    }
  }

  exp.resize(_jacobian->bezier->_exponents.size1(),
             _jacobian->bezier->_exponents.size2());
  for (int i = 0; i < _jacobian->bezier->_exponents.size1(); ++i) {
    for (int j = 0; j < _jacobian->bezier->_exponents.size2(); ++j) {
      exp(i, j) = static_cast<int>(_jacobian->bezier->_exponents(i, j) + .5);
    }
  }
  int njac = _jacobian->getNumJacNodes();
  for (int i = 0; i < njac; i++) {
    for (int j = i; j < njac; j++) {
      int order = metricOrder/2*3;
      double num = 1, den = 1;
      {
        int compl1 = order;
        int compl2 = order;
        int compltot = 2*order;
        for (int k = 0; k < dimSimplex; k++) {
          num *= nChoosek(compl1, exp(i, k))
               * nChoosek(compl2, exp(j, k));
          den *= nChoosek(compltot, exp(i, k) + exp(j, k));
          compl1 -= exp(i, k);
          compl2 -= exp(j, k);
          compltot -= exp(i, k) + exp(j, k);
        }
      }
      for (int k = dimSimplex; k < dim; k++) {
        num *= nChoosek(order, exp(i, k))
             * nChoosek(order, exp(j, k));
        den *= nChoosek(2*order, exp(i, k) + exp(j, k));
      }

      if (i != j) num *= 2;

      ++countJ2;
      int hash = 0;
      for (int k = 0; k < dim; k++) {
        hash += (exp(i, k)+exp(j, k)) * pow_int(2*order+1, k);
      }
      _ineqJ2[hash].push_back(IneqData(num/den, i, j));
    }
  }

  _lightenInequalities(tol, countJ2, countP3, countA);

  Msg::Info("A : %d / %d", countA, ncoeff*(ncoeff+1)/2);
  Msg::Info("J2 : %d / %d", countJ2, njac*(njac+1)/2);
  Msg::Info("P3 : %d / %d", countP3, ncoeff*(ncoeff+1)*(ncoeff+2)/6);
}

void MetricCoefficient::_lightenInequalities(double tol, int &countj, int &countp, int &counta)
{
  std::map<int, std::vector<IneqData> >::iterator it, itbeg[3], itend[3];

  int cnt[3] = {0,0,0};
  itbeg[0] = _ineqJ2.begin();
  itbeg[1] = _ineqP3.begin();
  itbeg[2] = _ineqA.begin();
  itend[0] = _ineqJ2.end();
  itend[1] = _ineqP3.end();
  itend[2] = _ineqA.end();
  for (int k = 0; k < 3; ++k) {
    it = itbeg[k];
    while (it != itend[k]) {
      std::sort(it->second.begin(), it->second.end(), gterIneq());

      double rmved = .0;
      while (it->second.size() && rmved + it->second.back().val <= tol) {
        rmved += it->second.back().val;
        it->second.pop_back();
        ++cnt[k];
      }
      const double factor = 1-rmved;
      for (unsigned int i = 0; i < it->second.size(); ++i) {
        it->second[i].val /= factor;
      }
      ++it;
    }
  }
  countj -= cnt[0];
  countp -= cnt[1];
  counta -= cnt[2];
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
      double tmp = 0;
      for (int j = 1; j < 7; ++j) {
        tmp += pow((*ref)(i, j), 2);
      }
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
    tmp += pow(terms[4], 2);
    tmp += pow(terms[5], 2);
    tmp += pow(terms[6], 2);
    tmp = std::sqrt(tmp);
    double factor = std::sqrt(6)/3;
    if (tmp < 1e-3*terms[0]) {
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

  delete [] terms;
}

double MetricCoefficient::getBoundRmin(double tol, int which)
{
  if (_coefficientsBez.size2() == 0) _computeBezCoeff();

  fullMatrix<double> nodes(_element->getNumShapeFunctions(),3);
  fullVector<double> jac(_jacobian->getNumJacNodes());
  _element->getNodesCoord(nodes);
  _jacobian->getSignedJacobian(nodes, jac);

  double RminLag, RminBez;
  if (which == 1)
    _computeRmin1(_coefficientsBez, jac, RminLag, RminBez, 0);
  else
    _computeRmin2(_coefficientsBez, jac, RminLag, RminBez, 0, which);

  if (RminLag-RminBez < tol) {
    Msg::Info("RETURNING %g", RminBez);
    return RminBez;
  }
  else {
    fullMatrix<double> *copycoeff = new fullMatrix<double>(_coefficientsBez);
    fullVector<double> *copyjac = new fullVector<double>(jac);
    MetricData *md = new MetricData(copycoeff, copyjac, RminBez, 0);
    __numSubdivision = 0;
    __numSub.resize(20);
    for (unsigned int i = 0; i < __numSub.size(); ++i) __numSub[i] = 0;
    __maxdepth = 0;
    double time = Cpu();
    double tt = _subdivideForRmin(md, RminLag, tol, which);
    Msg::Info("> computation time %g", Cpu() - time);
    Msg::Info("> maxDepth %d", __maxdepth);
    Msg::Info("> numSubdivision %d", __numSubdivision);
    int last = __numSub.size();
    while (--last > 0 && __numSub[last] == 0);
    for (unsigned int i = 0; i < last+1; ++i) {
      Msg::Info("> depth %d: %d", i, __numSub[i]);
    }
    Msg::Info("RETURNING %g after subdivision", tt);
    return tt;
  }
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
  double terms[7] = {0,0,0,0,0,0,0};
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

void MetricCoefficient::_computeRmin1(
    fullMatrix<double> &coeff, fullVector<double> &jac,
    double &RminLag, double &RminBez, int depth) const
{
  RminLag = 1.;
  static const double factor1 = std::sqrt(6) / 3;
  static const double factor2 = std::sqrt(6) * 3;

  for (int i = 0; i < _bezier->getNumLagCoeff(); ++i) {
    double q = coeff(i, 0);
    double p = pow_int(coeff(i, 1), 2);
    p += pow_int(coeff(i, 2), 2);
    p += pow_int(coeff(i, 3), 2);
    p += pow_int(coeff(i, 4), 2);
    p += pow_int(coeff(i, 5), 2);
    p += pow_int(coeff(i, 6), 2);
    p = std::sqrt(p);
    if (p < 1e-3 * q) {
      p *= factor1;
      RminLag = std::min(RminLag, std::sqrt((q - p) / (q + p)));
    }
    else {
      double phi = q/p;
      phi = .5 * phi - pow_int(phi,3);
      phi += jac(i)/p/p*jac(i)/p;
      phi *= factor2;
      if (phi >  1.1 || phi < -1.1) {
        if (!depth) {
          Msg::Warning("+ phi %g (jac %g, q %g, p %g)", phi, jac(i), q, p);
          Msg::Info("%g + %g - %g = %g", jac(i)*jac(i)/p/p/p, .5 * q/p, q*q*q/p/p/p, (jac(i)*jac(i)+.5 * q*p*p-q*q*q)/p/p/p);
        }
        else if (depth == 1)
          Msg::Warning("- phi %g @ %d(%d) (jac %g, q %g, p %g)", phi, depth, i, jac(i), q, p);
      }

      if (phi >  1) phi =  1;
      if (phi < -1) phi = -1;
      phi = std::acos(phi)/3;
      p *= factor1;
      double tmp = (q + p * std::cos(phi + 2*M_PI/3)) / (q + p * std::cos(phi));
      if (tmp < 0) Msg::Fatal("1 s normal ? %g", tmp);
      RminLag = std::min(RminLag, std::sqrt(tmp));
    }
  }

  double minq = _minq(coeff);
  double maxp = _maxp(coeff);
  if (maxp < 1e-3 * minq) {
    maxp *= factor1;
    double tmp = (minq - maxp) / (minq + maxp);
    RminBez = std::sqrt(tmp);
  }
  else {
    double minp = _minp(coeff);
    double maxq = _maxq(coeff);

    double minJ2;
    double maxJ2;
    _minMaxJacobianSqr(jac, minJ2, maxJ2);

    double minphi = minJ2/pow_int(maxp, 3);
    minphi -= pow_int(maxq/minp, 3);
    minphi += .5 * minq/maxp;
    minphi *= factor2;
    if (minphi < -1) minphi = -1;
    if (minphi >  1) minphi = 1;
    minphi = std::acos(minphi) / 3 + 2*M_PI/3;

    double maxphi = maxJ2/pow_int(minp, 3);
    maxphi -= pow_int(minq/maxp, 3);
    maxphi += .5 * maxq/minp;
    maxphi *= factor2;
    if (maxphi < -1.) maxphi = -1.;
    if (maxphi >  1.) maxphi = 1.;
    maxphi = std::acos(maxphi) / 3;

    double tmp = minq + factor1 * maxp * std::cos(minphi);
    tmp /= maxq + factor1 * maxp * std::cos(maxphi);
    if (tmp < 0) RminBez = 0;
    else RminBez = std::sqrt(tmp);
  }
}

void MetricCoefficient::_computeRmin2(
    fullMatrix<double> &coeff, fullVector<double> &jac,
    double &RminLag, double &RminBez, int depth, int which) const
{
  RminLag = 1.;
  static const double factor1 = std::sqrt(6) / 3;
  static const double factor2 = std::sqrt(6) * 3;

  for (int i = 0; i < _bezier->getNumLagCoeff(); ++i) {
    double q = coeff(i, 0);
    double p = pow_int(coeff(i, 1), 2);
    p += pow_int(coeff(i, 2), 2);
    p += pow_int(coeff(i, 3), 2);
    p += pow_int(coeff(i, 4), 2);
    p += pow_int(coeff(i, 5), 2);
    p += pow_int(coeff(i, 6), 2);
    p = std::sqrt(p);
    if (p < 1e-3 * q) {
      p *= factor1;
      RminLag = std::min(RminLag, std::sqrt((q - p) / (q + p)));
    }
    else {
      double phi = q/p;
      phi = .5 * phi - pow_int(phi,3);
      phi += jac(i)/p/p*jac(i)/p;
      phi *= factor2;
      if (phi >  1.1 || phi < -1.1) {
        if (!depth) {
          Msg::Warning("+ phi %g (jac %g, q %g, p %g)", phi, jac(i), q, p);
          Msg::Info("%g + %g - %g = %g", jac(i)*jac(i)/p/p/p, .5 * q/p, q*q*q/p/p/p, (jac(i)*jac(i)+.5 * q*p*p-q*q*q)/p/p/p);
        }
        else if (depth == 1)
          Msg::Warning("- phi %g @ %d(%d) (jac %g, q %g, p %g)", phi, depth, i, jac(i), q, p);
      }

      if (phi >  1) phi =  1;
      if (phi < -1) phi = -1;
      phi = std::acos(phi)/3;
      p *= factor1;
      double tmp = (q + p * std::cos(phi + 2*M_PI/3)) / (q + p * std::cos(phi));
      if (tmp < 0) Msg::Fatal("2 s normal ? %g", tmp);
      RminLag = std::min(RminLag, std::sqrt(tmp));
    }
  }

  double minq = _minq(coeff);
  double maxp = _maxp(coeff);
  //Msg::Info("1: %g", maxp/minq);
  if (maxp < 1e-3 * minq) {
    maxp *= factor1;
    double tmp = (minq - maxp) / (minq + maxp); //TODO il y a mieux !
    RminBez = std::sqrt(tmp);
    /*if (RminBez > .6 || isnan(RminBez)) Msg::Info("minq %g maxp %g => %g", minq, maxp, RminBez);*/
  }
  else {
    double minJ;
    if (which == 2 || which == 4) {
      double maxJ;
      _minMaxJacobianSqr(jac, minJ, maxJ);
      minJ /= maxp*maxp*maxp;
    }
    else if (which == 3 || which == 5) {
      _minJ2P3(coeff, jac, minJ);
    }
    else {
      Msg::Fatal("don't know what to do %d", which);
      return;
    }

    double a1, a0;
    {
      double p = -1./2;
      double q = -minJ-1/factor2;
      a1 = cubicCardanoRoot(p, q); //plus grand => -1
      q = -minJ+1/factor2;
      a0 = cubicCardanoRoot(p, q); //plus petit => 1
    }

    double mina;
    double maxa;
    if (which == 2 || which == 5) {
      mina = minq/maxp;
      double minp = _minp(coeff);
      if (minp > 0.)
        maxa = _maxq(coeff)/minp;
      else
        maxa = a1;
    }
    else if (which == 3 || which == 4) {
      _minMaxA2(coeff, mina, maxa);
    }
    else {
      Msg::Fatal("don't know what to do %d", which);
      return;
    }

    double phimin = std::acos(-factor1/2/mina) - M_PI/3;
    if (mina > a1) {
      RminBez = (mina+factor1*std::cos(phimin+2*M_PI/3))/(mina+factor1*std::cos(phimin)); //*
      RminBez = std::sqrt(RminBez);
      return;
    }

    double phim = std::acos(-factor1/2/a1) - M_PI/3;
    double am;
    {
      double p = -1./2;
      double q = -minJ+std::cos(3*phim)/factor2;
      am = cubicCardanoRoot(p, q); //milieu
    }

    if (maxa < am) {
      double phi = std::acos(factor2*(minJ-maxa*maxa*maxa+maxa/2))/3;
      RminBez = (maxa+factor1*std::cos(phi+2*M_PI/3))/(maxa+factor1*std::cos(phi));
      RminBez = std::sqrt(RminBez);
      return;
    }

    if (mina > am) {
      RminBez = (mina+factor1*std::cos(phimin+2*M_PI/3))/(mina+factor1*std::cos(phimin)); //same as *
      RminBez = std::sqrt(RminBez);
      return;
    }
    else {
      RminBez = (a1+factor1*std::cos(phim+2*M_PI/3))/(a1+factor1*std::cos(phim));
      RminBez = std::sqrt(RminBez);
      return;
    }
  }
}

double MetricCoefficient::_subdivideForRmin(
    MetricData *md, double RminLag, double tol, int which) const
{
  std::priority_queue<MetricData*, std::vector<MetricData*>, lessMinB> subdomains;
  std::vector<MetricData*> vect;
  const int numCoeff = md->_metcoeffs->size2();
  const int numMetPnts = md->_metcoeffs->size1();
  const int numJacPnts = md->_jaccoeffs->size();
  const int numSub = _jacobian->getNumDivisions();
  subdomains.push(md);

  std::vector<fullVector<double>*> trash;

  while (RminLag - subdomains.top()->_RminBez > tol && subdomains.size() < pow_int(8,8)) {
    fullMatrix<double> *subcoeffs, *coeff;
    fullVector<double> *subjac, *jac;

    MetricData *current = subdomains.top();
    subcoeffs = new fullMatrix<double>(numSub*numMetPnts, numCoeff);
    subjac = new fullVector<double>(numSub*numJacPnts);
    _bezier->subDivisor.mult(*current->_metcoeffs, *subcoeffs);
    _jacobian->subdivideBezierCoeff(*current->_jaccoeffs, *subjac);
    int depth = current->_depth;
      //Msg::Info("d %d RminBez %g / %g", depth, current->_RminBez, RminLag);
    delete current;
    subdomains.pop();

    ++((MetricCoefficient*)this)->__numSubdivision;
    ++((MetricCoefficient*)this)->__numSub[depth];
    ((MetricCoefficient*)this)->__maxdepth = std::max(__maxdepth, depth+1);

    for (int i = 0; i < numSub; ++i) {
      coeff = new fullMatrix<double>(numMetPnts, numCoeff);
      coeff->copy(*subcoeffs, i * numMetPnts, numMetPnts, 0, numCoeff, 0, 0);
      jac = new fullVector<double>;
      jac->setAsProxy(*subjac, i * numJacPnts, numJacPnts);
      double minLag, minBez;
      if (which == 1)
        _computeRmin1(*coeff, *jac, minLag, minBez, depth+1);
      else
        _computeRmin2(*coeff, *jac, minLag, minBez, depth+1, which);
      //Msg::Info("new RminBez %g", minBez);
      RminLag = std::min(RminLag, minLag);
      MetricData *metData = new MetricData(coeff, jac, minBez, depth+1);
      subdomains.push(metData);
      vect.push_back(metData);
    }
    trash.push_back(subjac);
    delete subcoeffs;

    /*for (unsigned int i = 0; i < vect.size(); ++i) {
      Msg::Info("v %g", vect[i]->_RminBez);
    }
    Msg::Info("top %g (RminLag %g)", subdomains.top()->_RminBez, RminLag);
    return 0;*/
    //Msg::Info("RminLag %g - RminBez %g  @ %d", RminLag, subdomains.top()->_RminBez, subdomains.top()->_depth);
  }

  md = subdomains.top();
  double ans = md->_RminBez;

  while (subdomains.size()) {
    md = subdomains.top();
    subdomains.pop();
    delete md;
  }
  for (unsigned int i = 0; i < trash.size(); ++i) {
    delete trash[i];
  }

  return ans;
}

double MetricCoefficient::_minp(const fullMatrix<double> &coeff) const
{
  fullMatrix<double> minmaxCoeff(2, 6);
  for (int j = 0; j < 6; ++j) {
    minmaxCoeff(0, j) = coeff(0, j+1);
    minmaxCoeff(1, j) = coeff(0, j+1);
  }

  for (int i = 1; i < coeff.size1(); ++i) {
    for (int j = 0; j < 6; ++j) {
      if (minmaxCoeff(0, j) > coeff(i, j+1)) {
        minmaxCoeff(0, j) = coeff(i, j+1);
      }
      if (minmaxCoeff(1, j) < coeff(i, j+1)) {
        minmaxCoeff(1, j) = coeff(i, j+1);
      }
    }
  }

  double ans = 0;
  for (int j = 0; j < 6; ++j) {
    if (minmaxCoeff(0, j) * minmaxCoeff(1, j) > 0) {
      ans += minmaxCoeff(0, j) > 0 ?
          pow_int(minmaxCoeff(0, j), 2) :
          pow_int(minmaxCoeff(1, j), 2);
    }
  }
  return std::sqrt(ans);
}

double MetricCoefficient::_minq(const fullMatrix<double> &coeff) const
{
  double ans = coeff(0, 0);
  for (int i = 1; i < coeff.size1(); ++i) {
    if (ans > coeff(i, 0)) ans = coeff(i, 0);
  }
  return ans;
}

double MetricCoefficient::_maxp(const fullMatrix<double> &coeff) const
{
  double ans = 0;
  for (int i = 0; i < coeff.size1(); ++i) {
    double tmp = pow_int(coeff(i, 1), 2);
    tmp += pow_int(coeff(i, 2), 2);
    tmp += pow_int(coeff(i, 3), 2);
    tmp += pow_int(coeff(i, 4), 2);
    tmp += pow_int(coeff(i, 5), 2);
    tmp += pow_int(coeff(i, 6), 2);
    if (ans < tmp) ans = tmp;
  }
  return std::sqrt(ans);
}

double MetricCoefficient::_maxq(const fullMatrix<double> &coeff) const
{
  double ans = coeff(0, 0);
  for (int i = 1; i < coeff.size1(); ++i) {
    if (ans < coeff(i, 0)) ans = coeff(i, 0);
  }
  return ans;
}

void MetricCoefficient::_minMaxA2(
    const fullMatrix<double> &coeff, double &min, double &max) const
{
  min = 1e10;
  max = 0;
  std::map<int, std::vector<IneqData> >::const_iterator it = _ineqA.begin();
  while (it != _ineqA.end()) {
    double num = 0;
    double den = 0;
    for (unsigned int k = 0; k < it->second.size(); ++k) {
      const int i = it->second[k].i;
      const int j = it->second[k].j;
      double tmp = 0;
      for (int l = 1; l < 7; ++l) {
        tmp += coeff(i, l) * coeff(j, l);
      }
      den += it->second[k].val * tmp;
      num += it->second[k].val * coeff(i, 0) * coeff(j, 0);
      double val = num/den;
      min = std::min(val, min);
      max = std::max(val, max);
    }
    ++it;
  }

  if (min < 0)
    Msg::Fatal("minA ne devrait pas etre negatif");

  min = std::sqrt(min);
  max = std::sqrt(max);
}

void MetricCoefficient::_minMaxJacobianSqr(
    const fullVector<double> &jac, double &min, double &max) const
{
  static int a = 1;
  if (++a == 1) {
    for (int i = 1; i < jac.size(); ++i) {
      Msg::Info("<%g>", jac(i));
    }
  }
  min = max = jac(0);
  for (int i = 1; i < jac.size(); ++i) {
    if (min > jac(i)) min = jac(i);
    if (max < jac(i)) max = jac(i);
  }

  if (a == 1) {
      Msg::Info("%g %g", min, max);
  }

  if (min*max < 0) {
    max = max > -min ? max*max : min*min;
    min = 0;
  }
  else {
    if (max > 0) {
      max = max*max;
      min = min*min;
    }
    else {
      double tmp = max;
      max = min*min;
      min = tmp*tmp;
    }
  }
}

void MetricCoefficient::_minJ2P3(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double &min) const
{
  fullVector<double> r(coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    r(i) = 0;
    for (int l = 1; l < 7; ++l) {
      r(i) += coeff(i, l) * coeff(i, l);
    }
    r(i) = std::sqrt(r(i));
  }

  min = 1e10;
  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  //Msg::Warning("sizes %d %d", _ineqJ2.size(), _ineqP3.size());
  int count = 0;
  while (itJ != _ineqJ2.end() && itP != _ineqP3.end()) {
    if (count >= _ineqJ2.size()) Msg::Fatal("aaargh");
    if (itJ->first != itP->first) Msg::Fatal("not same hash %d %d", itJ->first, itP->first);

    double num = 0;
    //Msg::Info("sizej %d", itJ->second.size());
    for (int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num += itJ->second[l].val * jac(i) * jac(j);
    }

    double den = 0;
    //Msg::Info("sizep %d", itP->second.size());
    for (int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      //Msg::Info("i%d j%d k%d", i, j, k);
      if (l>=itP->second.size()) Msg::Error("l %d/%d", l, itP->second.size());
      if (i>=r.size() || j>=r.size()||k>=r.size() ) Msg::Fatal("i%d j%d k%d /%d (%dl%d)", i, j, k, r.size(), count, l);
      den += itP->second[l].val * r(i) * r(j) * r(k);
    }
    //Msg::Info("%g/%g = %g", num, den, num/den);
    min = std::min(min, num/den);
    ++itJ;
    ++itP;
    ++count;
  }
}
