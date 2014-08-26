// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "AnalyseCurvedMesh.h"
#include "MetricBasis.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include <queue>
#include "OS.h"
#include <sstream>

double MetricBasis::_tol = 1e-3;

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

MetricBasis::MetricBasis(int tag)
{
  const int type = ElementType::ParentTypeFromTag(tag);
  const int metOrder = metricOrder(tag);
  if (type == TYPE_HEX || type == TYPE_PRI) {
    int order = ElementType::OrderFromTag(tag);
    _jacobian = BasisFactory::getJacobianBasis(tag, 3*order);
  }
  else if (type == TYPE_TET || type == TYPE_TRI || type == TYPE_QUA)
    _jacobian = BasisFactory::getJacobianBasis(tag);
  else
    Msg::Fatal("metric not implemented for element tag %d", tag);
  _gradients = BasisFactory::getGradientBasis(tag, metOrder);
  _bezier = BasisFactory::getBezierBasis(type, metOrder);

  _fillInequalities(metOrder);
}

double MetricBasis::boundMinR(MElement *el)
{
  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  return metric->getBoundMinR(el);
}

double MetricBasis::minRCorner(MElement *el)
{
  int tag = el->getTypeForMSH();
  int order = 1;
  if (el->getType() == TYPE_TRI || el->getType() == TYPE_TET) order = 0;

  const GradientBasis *gradients = BasisFactory::getGradientBasis(tag, order);
  const JacobianBasis *jacobian = BasisFactory::getJacobianBasis(tag, order);

  int nSampPnts = jacobian->getNumJacNodes();
  if (el->getType() == TYPE_PYR) nSampPnts = 4;
  int nMapping = gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);
  fullMatrix<double> nodesMetric;
  switch (el->getDim()) {
  case 1:
    return -1;

  case 2:
    if (_paramOnPlane(nodes, nodesMetric)) return -1;
    break;

  case 3:
    nodesMetric.setAsProxy(nodes);
    break;

  default:
    Msg::Error("no metric for element of dimension %d (tag=%d)",
        el->getDim(), el->getTypeForMSH());
  }

  // Jacobian coefficients
  fullVector<double> jacLag(jacobian->getNumJacNodes());
  jacobian->getSignedJacobian(nodes, jacLag);

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff(gradients, nodesMetric, metCoeffLag);

  // Compute min_corner(R)
  return _computeMinlagR(jacLag, metCoeffLag, nSampPnts);
}

double MetricBasis::minSampledR(MElement *el, int order)
{
  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  return metric->getMinSampledR(el, order);
}

double MetricBasis::getMinSampledR(MElement *el, int deg) const
{
  fullMatrix<double> samplingPoints;

  switch (el->getType()) {
    case TYPE_PNT :
      samplingPoints = gmshGeneratePointsLine(0);
      break;
    case TYPE_LIN :
      samplingPoints = gmshGeneratePointsLine(deg);
      break;
    case TYPE_TRI :
      samplingPoints = gmshGeneratePointsTriangle(deg,false);
      break;
    case TYPE_QUA :
      samplingPoints = gmshGeneratePointsQuadrangle(deg,false);
      break;
    case TYPE_TET :
      samplingPoints = gmshGeneratePointsTetrahedron(deg,false);
      break;
    case TYPE_PRI :
      samplingPoints = gmshGeneratePointsPrism(deg,false);
      break;
    case TYPE_HEX :
      samplingPoints = gmshGeneratePointsHexahedron(deg,false);
      break;
    case TYPE_PYR :
      samplingPoints = JacobianBasis::generateJacPointsPyramid(deg);
      break;
    default :
      Msg::Error("Unknown Jacobian function space for element type %d", el->getType());
      return -1;
  }

  MetricData *md;
  _getMetricData(el, md);

  double uvw[3];
  double minmaxQ[2];
  uvw[0] = samplingPoints(0, 0);
  uvw[1] = samplingPoints(0, 1);
  uvw[2] = samplingPoints(0, 2);

  interpolate(el, md, uvw, minmaxQ);
  double min, max = min = std::sqrt(minmaxQ[0]/minmaxQ[1]);
  for (int i = 1; i < samplingPoints.size1(); ++i) {
    uvw[0] = samplingPoints(i, 0);
    uvw[1] = samplingPoints(i, 1);
    uvw[2] = samplingPoints(i, 2);
    interpolate(el, md, uvw, minmaxQ);
    double tmp = std::sqrt(minmaxQ[0]/minmaxQ[1]);
    min = std::min(min, tmp);
    max = std::max(max, tmp);
  }
  return min;
}

double MetricBasis::getBoundMinR(MElement *el)
{
  int nSampPnts = _gradients->getNumSamplingPoints();
  int nMapping = _gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);
  fullMatrix<double> nodesMetric;
  switch (el->getDim()) {
  case 1:
    return -1;

  case 2:
    if (_paramOnPlane(nodes, nodesMetric)) return -1;
    break;

  case 3:
    nodesMetric.setAsProxy(nodes);
    break;

  default:
    Msg::Error("no metric for element of dimension %d (tag=%d)",
        el->getDim(), el->getTypeForMSH());
  }

  // Jacobian coefficients
  fullVector<double> jacLag(_jacobian->getNumJacNodes());
  fullVector<double> *jac = new fullVector<double>(_jacobian->getNumJacNodes());
  _jacobian->getSignedJacobian(nodes, jacLag);
  _jacobian->lag2Bez(jacLag, *jac);

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff(_gradients, nodesMetric, metCoeffLag);
  fullMatrix<double> *metCoeff;
  metCoeff = new fullMatrix<double>(nSampPnts, metCoeffLag.size2());
  _bezier->matrixLag2Bez.mult(metCoeffLag, *metCoeff);

  // Compute min(R, _tol)
  double RminLag, RminBez;
  _computeRmin(*metCoeff, *jac, RminLag, RminBez);

  if (RminLag-RminBez < MetricBasis::_tol) {
    return RminBez;
  }
  else {
    MetricData *md2 = new MetricData(metCoeff, jac, RminBez, 0, 0);
    double tt = _subdivideForRmin(md2, RminLag, MetricBasis::_tol);
    return tt;
  }
}

void MetricBasis::_fillInequalities(int metricOrder)
{
  int dimSimplex = _bezier->getDimSimplex();
  int dim = _bezier->getDim();
  fullMatrix<int> exp(_bezier->_exponents.size1(), _bezier->_exponents.size2());
  for (int i = 0; i < _bezier->_exponents.size1(); ++i) {
    for (int j = 0; j < _bezier->_exponents.size2(); ++j) {
      exp(i, j) = static_cast<int>(_bezier->_exponents(i, j) + .5);
    }
  }
  int ncoeff = _gradients->getNumSamplingPoints();

  int countP3 = 0, countJ2 = 0, countA = 0;
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
          if (j == k || i == k) {
            num *= 3;
          }
          else num *= 6;
        }

        ++countP3;
        int hash = 0;
        for (int l = 0; l < dim; l++) {
          hash += (exp(i, l)+exp(j, l)+exp(k, l)) * pow_int(3*metricOrder+1, l);
        }
        if (j == k && j != i)
          _ineqP3[hash].push_back(IneqData(num/den, k, j, i));
        else
          _ineqP3[hash].push_back(IneqData(num/den, i, j, k));
      }
    }
  }

  if (_jacobian) {
    exp.resize(_jacobian->getBezier()->_exponents.size1(),
               _jacobian->getBezier()->_exponents.size2());
    for (int i = 0; i < _jacobian->getBezier()->_exponents.size1(); ++i) {
      for (int j = 0; j < _jacobian->getBezier()->_exponents.size2(); ++j) {
        exp(i, j) = static_cast<int>(_jacobian->getBezier()->_exponents(i, j) + .5);
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
  }

  _lightenInequalities(countJ2, countP3, countA);
}

void MetricBasis::_lightenInequalities(int &countj, int &countp, int &counta)
{
  double tol = .0;
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

void MetricBasis::interpolate(const MElement *el, const MetricData *md, const double *uvw, double *minmaxQ) const
{
  if (minmaxQ == NULL) {
    Msg::Error("Cannot write solution of interpolation");
    return;
  }

  int order = _bezier->getOrder();

  int dimSimplex = 0;
  fullMatrix<double> exponents;
  double bezuvw[3];
  switch (el->getType()) {
  case TYPE_PYR:
    bezuvw[0] = .5 * (1 + uvw[0]);
    bezuvw[1] = .5 * (1 + uvw[1]);
    bezuvw[2] = uvw[2];
    //_interpolateBezierPyramid(uvw, minmaxQ);
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

  fullMatrix<double> metcoeffs = *md->_metcoeffs;
  fullVector<double> jaccoeffs = *md->_jaccoeffs;

  double *terms = new double[metcoeffs.size2()];
  for (int t = 0; t < metcoeffs.size2(); ++t) {
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
      terms[t] += metcoeffs(i, t) * dd;
    }
  }

  switch (metcoeffs.size2()) {
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
      //{
        fullMatrix<double> nodes(1, 3);
        nodes(0, 0) = uvw[0];
        nodes(0, 1) = uvw[1];
        nodes(0, 2) = uvw[2];

        fullMatrix<double> result;
        _jacobian->interpolate(jaccoeffs, nodes, result, true);
        phi = result(0, 0)*result(0, 0);
      //}
      phi -= terms[0]*terms[0]*terms[0];
      phi += .5*terms[0]*tmp*tmp;
      phi /= tmp*tmp*tmp;
      phi *= 3*std::sqrt(6);
      if (phi >  1) phi =  1;
      if (phi < -1) phi = -1;
      phi = std::acos(phi)/3;
      minmaxQ[0] = terms[0] + factor * tmp * std::cos(phi + 2*M_PI/3);
      minmaxQ[1] = terms[0] + factor * tmp * std::cos(phi);
      ((MetricBasis*)this)->file << terms[0] << " " << tmp/std::sqrt(6) << " " << result(0, 0) << std::endl;
    }
  }
  break;

  default:
    Msg::Error("Wrong number of functions for metric: %d",
               metcoeffs.size2());
  }

  delete[] terms;
}

int MetricBasis::metricOrder(int tag)
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

void MetricBasis::_computeRmin(
    const fullMatrix<double> &coeff, const fullVector<double> &jac,
    double &RminLag, double &RminBez) const
{
  RminLag = _computeMinlagR(jac, coeff, _bezier->getNumLagCoeff());
  if (RminLag == 0) {
    RminBez = 0;
    return;
  }

  if (coeff.size2() == 3) { // 2d element
    double mina, dummy;
    _minMaxA(coeff, mina, dummy);
    RminBez = std::sqrt(_R2Dsafe(mina));
    return;
  }

  double minK;
  _minK(coeff, jac, minK);
  if (minK < 1e-10) {
    RminBez = 0;
    return;
  }

  double mina, dummy;
  _minMaxA(coeff, mina, dummy);

  double term1, dRda, phip;
  _computeTermBeta(mina, minK, dRda, term1, phip);

  if (dRda < 0) {
    // TODO : better am ?
    double amApprox, da;
    {
      const double p = -3;
      double q = -minK - 2;
      const double a1 = cubicCardanoRoot(p, q);
      const double phim = std::acos(-1/a1) - M_PI/3;
      q = -minK + 2*std::cos(3*phim);
      amApprox = cubicCardanoRoot(p, q);
      if (minK < 10)
        da = -.3;
      else if (minK < 20)
        da = -.25;
      else if (minK < 35)
        da = -.2;
      else if (minK < 70)
        da = -.15;
      else if (minK < 175)
        da = -.1;
      else
        da = -.05;
    }

    double beta = -3 * mina*mina * term1 / dRda / 6;
    double maxa;
    if (beta*minK-mina*mina*mina < 0)
      _maxAstKneg(coeff, jac, minK, beta, maxa);
    else {
      _maxAstKpos(coeff, jac, minK, beta, maxa);
      if (maxa < amApprox && beta*minK-maxa*maxa*maxa < 0)
        _maxAstKneg(coeff, jac, minK, beta, maxa);
    }

    maxa = std::max(mina, maxa);
    if (amApprox*amApprox*amApprox+da < maxa*maxa*maxa) {
      // compute better am
      //
      double am0 = std::pow(amApprox*amApprox*amApprox+da, 1/3.);
      double am1 = std::pow(amApprox*amApprox*amApprox+da+.05, 1/3.);
      //double am0S = am0, am1S = am1;
      double am = (am0 + am1)/2;
      double R0 = _R3Dsafe(am0, minK);
      double R1 = _R3Dsafe(am1, minK);
      double Rnew = _R3Dsafe(am, minK);

      int cnt = 0;
      while (std::abs(R0-Rnew) > _tol*.01 || std::abs(R1-Rnew) > _tol*.01) {
        ++cnt;
        if (R0 > R1) {
          am0 = am;
          R0 = Rnew;
        }
        else {
          am1 = am;
          R1 = Rnew;
        }
        am = (am0 + am1)/2;
        Rnew = _R3Dsafe(am, minK);
      }

      if (am < maxa) {
        RminBez = _R3Dsafe(am, minK);
        RminBez = std::sqrt(RminBez);
        return;
      }
    }

    RminBez = _R3Dsafe(maxa, minK);
    RminBez = std::sqrt(RminBez);
    return;
  }
  else if (term1 < 0) {
    double maxK;
    double beta = -3 * mina*mina * term1 / dRda / 6;
    if (beta*minK-mina*mina*mina > 0) Msg::Fatal("Arf pas prevu");
    //_maxKstAsharp(coeff, jac, mina, beta, maxK);
    _maxKstAfast(coeff, jac, mina, beta, maxK);
    const double x = .5*(maxK-mina*mina*mina+3*mina);
    const double phimin = std::acos(-1/mina) - M_PI/3;
    double myphi;
    if (std::abs(x) > 1) {
      myphi = phimin;
    }
    else {
      const double phimaxK = std::acos(x)/3;
      myphi = std::max(phimin, phimaxK);
    }
    RminBez = (mina+2*std::cos(myphi+2*M_PI/3))/(mina+2*std::cos(myphi));
    RminBez = std::sqrt(RminBez);
    return;
  }
  else {
    RminBez = (mina+2*std::cos(phip+M_PI/3))/(mina+2*std::cos(phip-M_PI/3));
    RminBez = std::sqrt(RminBez);
    return;
  }
}

void MetricBasis::_computeRmax(
    const fullMatrix<double> &coeff, const fullVector<double> &jac,
    double &RmaxLag) const
{
  RmaxLag = 0.;

  for (int i = 0; i < _bezier->getNumLagCoeff(); ++i) {
    double q = coeff(i, 0);
    double p = 0;
    for (int k = 1; k < 7; ++k) {
      p += pow_int(coeff(i, k), 2);
    }
    p = std::sqrt(p/6);
    const double a = q/p;
    if (a > 1e4) {
      RmaxLag = std::max(RmaxLag, std::sqrt((a - std::sqrt(3)) / (a + std::sqrt(3))));
    }
    else {
      const double tmpR = _R3Dsafe(a, jac(i)/p/p*jac(i)/p);
      RmaxLag = std::max(RmaxLag, std::sqrt(tmpR));
    }
  }
}

double MetricBasis::_subdivideForRmin(MetricData *md, double RminLag, double tol) const
{
  std::priority_queue<MetricData*, std::vector<MetricData*>, lessMinB> subdomains;
  const int numCoeff = md->_metcoeffs->size2();
  const int numMetPnts = md->_metcoeffs->size1();
  const int numJacPnts = md->_jaccoeffs->size();
  const int numSub = _bezier->getNumDivision();
  subdomains.push(md);

  std::vector<fullVector<double>*> trash;

  while (RminLag - subdomains.top()->_RminBez > tol && subdomains.size() < 25000) {
    fullMatrix<double> *subcoeffs, *coeff;
    fullVector<double> *subjac, *jac;

    MetricData *current = subdomains.top();
    subcoeffs = new fullMatrix<double>(numSub*numMetPnts, numCoeff);
    subjac = new fullVector<double>(numSub*numJacPnts);
    _bezier->subDivisor.mult(*current->_metcoeffs, *subcoeffs);
    _jacobian->getBezier()->subDivisor.mult(*current->_jaccoeffs, *subjac);
    int depth = current->_depth;
    int num = current->_num;
    delete current;
    subdomains.pop();

    for (int i = 0; i < numSub; ++i) {
      coeff = new fullMatrix<double>(numMetPnts, numCoeff);
      coeff->copy(*subcoeffs, i * numMetPnts, numMetPnts, 0, numCoeff, 0, 0);
      jac = new fullVector<double>;
      jac->setAsProxy(*subjac, i * numJacPnts, numJacPnts);
      double minLag, minBez;
      _computeRmin(*coeff, *jac, minLag, minBez);
      RminLag = std::min(RminLag, minLag);
      int newNum = num + (i+1) * pow_int(10, depth);
      MetricData *metData = new MetricData(coeff, jac, minBez, depth+1, newNum);
      subdomains.push(metData);
    }
    trash.push_back(subjac);
    delete subcoeffs;
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

void MetricBasis::_computeTermBeta(double &a, double &K,
                                   double &dRda, double &term1,
                                   double &phip) const
{
  double x0 = .5 * (K - a*a*a + 3*a);
  double sin, sqrt;
  if (x0 > 1) {
    const double p = -3;
    double q = -K + 2;
    a = cubicCardanoRoot(p, q);

    x0 = 1;
    phip = M_PI / 3;
    term1 = 1 + .5 * a;
    sin = std::sqrt(3) / 2;
    sqrt = 0;
  }
  else if (x0 < -1) {
    K = -2 + a*a*a - 3*a;

    x0 = -1;
    phip = 2 * M_PI / 3;
    term1 = 1 - .5 * a;
    sin = std::sqrt(3) / 2;
    sqrt = 0;
  }
  else {
    phip = (std::acos(x0) + M_PI) / 3;
    term1 = 1 + a * std::cos(phip);
    sin = std::sin(phip);
    sqrt = std::sqrt(1-x0*x0);
  }
  dRda = sin * sqrt + .5 * term1 * (1-a*a);
}

void MetricBasis::_getMetricData(MElement *el, MetricData *&md) const
{
  int nSampPnts = _gradients->getNumSamplingPoints();
  int nMapping = _gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);
  fullMatrix<double> nodesMetric;
  switch (el->getDim()) {
  case 1:
    md = NULL;
    return;

  case 2:
    if (_paramOnPlane(nodes, nodesMetric)) {
      md = NULL;
      return;
    }
    break;

  case 3:
    nodesMetric.setAsProxy(nodes);
    break;

  default:
    Msg::Error("no metric for element of dimension %d (tag=%d)",
        el->getDim(), el->getTypeForMSH());
  }

  // Jacobian coefficients
  fullVector<double> jacLag(_jacobian->getNumJacNodes());
  fullVector<double> *jac = new fullVector<double>(_jacobian->getNumJacNodes());
  _jacobian->getSignedJacobian(nodes, jacLag);
  _jacobian->lag2Bez(jacLag, *jac);

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff(_gradients, nodesMetric, metCoeffLag);
  fullMatrix<double> *metCoeff;
  metCoeff = new fullMatrix<double>(nSampPnts, metCoeffLag.size2());
  _bezier->matrixLag2Bez.mult(metCoeffLag, *metCoeff);

  md = new MetricData(metCoeff, jac, -1, 0, 0);
}

void MetricBasis::_fillCoeff(const GradientBasis *gradients,
    fullMatrix<double> &nodes, fullMatrix<double> &coeff)
{
  const int nSampPnts = gradients->getNumSamplingPoints();

  switch (nodes.size2()) {
  case 0 :
    return;
  case 1 :
    Msg::Fatal("not implemented");
    break;

  case 2 :
    {
      fullMatrix<double> dxydX(nSampPnts,2), dxydY(nSampPnts,2);
      gradients->getGradientsFromNodes(nodes, &dxydX, &dxydY, NULL);

      coeff.resize(nSampPnts, 3);
      for (int i = 0; i < nSampPnts; i++) {
        const double &dxdX = dxydX(i,0), &dydX = dxydX(i,1);
        const double &dxdY = dxydY(i,0), &dydY = dxydY(i,1);
        const double dvxdX = dxdX*dxdX + dydX*dydX;
        const double dvxdY = dxdY*dxdY + dydY*dydY;
        coeff(i, 0) = (dvxdX + dvxdY) / 2;
        coeff(i, 1) = dvxdX - coeff(i, 0);
        coeff(i, 2) = (dxdX*dxdY + dydX*dydY);
      }
    }
    break;

  case 3 :
    {
      fullMatrix<double> dxyzdX(nSampPnts,3), dxyzdY(nSampPnts,3), dxyzdZ(nSampPnts,3);
      gradients->getGradientsFromNodes(nodes, &dxyzdX, &dxyzdY, &dxyzdZ);

      coeff.resize(nSampPnts, 7);
      for (int i = 0; i < nSampPnts; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        const double dvxdX = dxdX*dxdX + dydX*dydX + dzdX*dzdX;
        const double dvxdY = dxdY*dxdY + dydY*dydY + dzdY*dzdY;
        const double dvxdZ = dxdZ*dxdZ + dydZ*dydZ + dzdZ*dzdZ;
        coeff(i, 0) = (dvxdX + dvxdY + dvxdZ) / 3;
        coeff(i, 1) = dvxdX - coeff(i, 0);
        coeff(i, 2) = dvxdY - coeff(i, 0);
        coeff(i, 3) = dvxdZ - coeff(i, 0);
        const double fact = std::sqrt(2);
        coeff(i, 4) = fact * (dxdX*dxdY + dydX*dydY + dzdX*dzdY);
        coeff(i, 5) = fact * (dxdZ*dxdY + dydZ*dydY + dzdZ*dzdY);
        coeff(i, 6) = fact * (dxdX*dxdZ + dydX*dydZ + dzdX*dzdZ);
      }
    }
    break;
  }
}

double MetricBasis::_computeMinlagR(const fullVector<double> &jac,
                                    const fullMatrix<double> &coeff, int num)
{
  double Rmin = 1.;

  switch (coeff.size2()) {
  case 7:
    for (int i = 0; i < num; ++i) {
      if (jac(i) <= 0.) return 0;

      const double q = coeff(i, 0);
      double p = 0;
      for (int k = 1; k < 7; ++k) {
        p += pow_int(coeff(i, k), 2);
      }
      p = std::sqrt(p/6);
      const double a = q/p;
      if (a > 1e4) { // TODO: from _tol ?
        Rmin = std::min(Rmin, std::sqrt((a - std::sqrt(3)) / (a + std::sqrt(3))));
      }
      else {
        const double tmpR = _R3Dsafe(a, jac(i)/p/p*jac(i)/p);
        Rmin = std::min(Rmin, std::sqrt(tmpR));
      }
    }
    return Rmin;

  case 3:
    for (int i = 0; i < num; ++i) {
      if (jac(i) <= 0.) return 0;

      const double q = coeff(i, 0);
      const double p = pow_int(coeff(i, 1), 2) + pow_int(coeff(i, 2), 2);
      const double a = q/std::sqrt(p);
      const double tmpR = _R2Dsafe(a);
      Rmin = std::min(Rmin, std::sqrt(tmpR));
    }
    return Rmin;

  default:
    Msg::Error("coeff have not right number of column");
    return -1;
  }
}

int MetricBasis::_paramOnPlane(const fullMatrix<double> &nodes3d,
                               fullMatrix<double> &nodes2d)
{
  // check if in xy-plane
  int i = 0;
  while (i < nodes3d.size1() && nodes3d(i,2) == 0) ++i;
  if (i == nodes3d.size1()) {
    nodes2d.setAsProxy(const_cast<double*>(nodes3d.getDataPtr()),
                       nodes3d.size1(), 2);
    Msg::Info("Was on xy-plane");
    return 0;
  }

  // check if coplanar and reparameterize
  SVector3 vx(nodes3d(1, 0) - nodes3d(0, 0),
              nodes3d(1, 1) - nodes3d(0, 1),
              nodes3d(1, 2) - nodes3d(0, 2));
  SVector3 vy(nodes3d(2, 0) - nodes3d(0, 0),
              nodes3d(2, 1) - nodes3d(0, 1),
              nodes3d(2, 2) - nodes3d(0, 2));

  double lx = vx.norm(), L = vy.norm() + lx;
  if (norm(crossprod(vx, vy)) / L < 1e-10) {
    nodes2d.resize(nodes3d.size1(), 2, true);
    return 0;
  }

  nodes2d.resize(nodes3d.size1(), 2, false);
  nodes2d(0, 0) = 0;
  nodes2d(0, 1) = 0;

  SVector3 ux = vx;
  ux *= 1/lx;
  nodes2d(1, 0) = lx;
  nodes2d(1, 1) = 0;

  double p_vy_x = dot(vy, ux);
  SVector3 uy = ux;
  uy *= -p_vy_x;
  uy += vy;
  double n = uy.norm();
  uy.normalize();
  nodes2d(2, 0) = p_vy_x;
  nodes2d(2, 1) = n;

  for (int i = 3; i < nodes3d.size1(); ++i) {
    SVector3 v(nodes3d(i, 0) - nodes3d(0, 0),
               nodes3d(i, 1) - nodes3d(0, 1),
               nodes3d(i, 2) - nodes3d(0, 2));
    double p_v_x = dot(v, ux);
    double p_v_y = dot(v, uy);
    SVector3 px = ux, py = uy;
    px *= -p_v_x;
    py *= -p_v_y;
    v -= px;
    v -= py;
    if (norm(v) / L < 1e-10) {
      //Msg::Info("%g / %g = %g <= 1e-10", norm(v), L, norm(v)/L);
      return 1;
    }
    nodes2d(i, 0) = p_v_x;
    nodes2d(i, 1) = p_v_y;
  }

  return 0;
}

void MetricBasis::_minMaxA(
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
      for (int l = 1; l < coeff.size2(); ++l) {
        tmp += coeff(i, l) * coeff(j, l);
      }
      den += it->second[k].val * tmp;
      num += it->second[k].val * coeff(i, 0) * coeff(j, 0);
    }
    double val = num/den;
    min = std::min(val, min);
    max = std::max(val, max);
    ++it;
  }
  if (coeff.size2() == 7) {
    min *= 6;
    max *= 6;
  }

  min = min > 1 ? std::sqrt(min) : 1;
  max = std::sqrt(max);
}

void MetricBasis::_minK(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double &min) const
{
  fullVector<double> r(coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    r(i) = 0;
    for (int l = 1; l < 7; ++l) {
      r(i) += coeff(i, l) * coeff(i, l);
    }
    r(i) = std::sqrt(r(i)/6);
  }

  min = 1e10;
  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  if (_ineqP3.size() != _ineqJ2.size()) Msg::Fatal("sizes P3 %d, J2 %d", _ineqP3.size(), _ineqJ2.size());
  //Msg::Warning("sizes %d %d", _ineqJ2.size(), _ineqP3.size());
  int count = 0;
  while (itJ != _ineqJ2.end() && itP != _ineqP3.end()) {
    if (count >= (int)_ineqJ2.size()) Msg::Fatal("aaargh");
    if (itJ->first != itP->first) Msg::Fatal("not same hash %d %d", itJ->first, itP->first);

    double num = 0;
    //Msg::Info("sizej %d", itJ->second.size());
    for (unsigned int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num += itJ->second[l].val * jac(i) * jac(j);
    }

    double den = 0;
    //Msg::Info("sizep %d", itP->second.size());
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
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
  min = std::max(min, 0.);
}

void MetricBasis::_maxAstKpos(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double minK, double beta, double &maxa) const
{
  fullVector<double> P(coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    P(i) = 0;
    for (int l = 1; l < 7; ++l) {
      P(i) += coeff(i, l) * coeff(i, l);
    }
    P(i) = std::sqrt(P(i)/6);
  }

  double min = 1e10;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  while (itJ != _ineqJ2.end() && itP != _ineqP3.end()) {
    double num = 0, den = 0;
    for (unsigned int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num += itJ->second[l].val * jac(i) * jac(j);
    }
    num *= beta;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      num -= itP->second[l].val * coeff(i, 0) * coeff(j, 0) * coeff(k, 0);
      den += itP->second[l].val * P(i) * P(j) * P(k);
    }
    min = std::min(min, num/den);
    ++itJ;
    ++itP;
  }

  maxa = std::pow(beta*minK-min, 1/3.);
}

void MetricBasis::_maxAstKneg(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double minK, double beta, double &maxa) const
{
  fullVector<double> P(coeff.size1());
  fullMatrix<double> Q(coeff.size1(), coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    P(i) = 0;
    for (int l = 1; l < 7; ++l) {
      P(i) += coeff(i, l) * coeff(i, l);
    }
    P(i) = std::sqrt(P(i)/6);
    for (int j = 0; j < coeff.size1(); ++j) {
      Q(i, j) = 0;
      for (int l = 1; l < 7; ++l) {
        Q(i, j) += coeff(i, l) * coeff(j, l);
      }
      Q(i, j) /= 6;
    }
  }

  double min = 1e10;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  while (itJ != _ineqJ2.end() && itP != _ineqP3.end()) {
    double num = 0, den = 0;
    for (unsigned int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num += itJ->second[l].val * jac(i) * jac(j);
    }
    num *= beta;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      num -= itP->second[l].val * coeff(i, 0) * coeff(j, 0) * coeff(k, 0);
      double tmp = P(i) * Q(j, k);
      tmp = std::min(tmp, P(j) * Q(i, k));
      tmp = std::min(tmp, P(k) * Q(i, j));
      den += itP->second[l].val * tmp;
    }
    min = std::min(min, num/den);
    ++itJ;
    ++itP;
  }

  maxa = std::pow(beta*minK-min, 1/3.);
}

void MetricBasis::_maxKstAfast(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double mina, double beta, double &maxK) const
{
  fullVector<double> r(coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    r(i) = 0;
    for (int l = 1; l < 7; ++l) {
      r(i) += coeff(i, l) * coeff(i, l);
    }
    r(i) = std::sqrt(r(i)/6);
  }

  double min = 1e10;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  while (itJ != _ineqJ2.end() && itP != _ineqP3.end()) {
    double num = 0, den = 0;
    for (unsigned int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num -= itJ->second[l].val * jac(i) * jac(j);
    }
    num *= beta;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      num += itP->second[l].val * coeff(i, 0) * coeff(j, 0) * coeff(k, 0);
      den += itP->second[l].val * r(i) * r(j) * r(k);
    }
    min = std::min(min, num/den);
    ++itJ;
    ++itP;
  }

  maxK = 1/beta*(mina*mina*mina-min);
}

void MetricBasis::_maxKstAsharp(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double mina, double beta, double &maxK) const
{
  fullVector<double> P(coeff.size1());
  fullMatrix<double> Q(coeff.size1(), coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    P(i) = 0;
    for (int l = 1; l < 7; ++l) {
      P(i) += coeff(i, l) * coeff(i, l);
    }
    P(i) = std::sqrt(P(i)/6);
    for (int j = 0; j < coeff.size1(); ++j) {
      Q(i, j) = 0;
      for (int l = 1; l < 7; ++l) {
        Q(i, j) += coeff(i, l) * coeff(j, l);
      }
      Q(i, j) /= 6;
    }
  }

  double min = 1e10;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  while (itJ != _ineqJ2.end() && itP != _ineqP3.end()) {
    double num = 0, den = 0;
    for (unsigned int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num -= itJ->second[l].val * jac(i) * jac(j);
    }
    num *= beta;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      num += itP->second[l].val * coeff(i, 0) * coeff(j, 0) * coeff(k, 0);
      if (j == k)
        den += itP->second[l].val * Q(i,i) * P(i);
      else
        den += itP->second[l].val * 1/3*(Q(i,j)*P(k)+Q(i,k)*P(j)+Q(k,j)*P(i));
    }
    min = std::min(min, num/den);
    ++itJ;
    ++itP;
  }

  maxK = 1/beta*(mina*mina*mina-min);
}
