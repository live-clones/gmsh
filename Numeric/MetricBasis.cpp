// Gmsh - Copyright (C) 1997-2016 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "MElement.h"
#include "AnalyseCurvedMesh.h"
#include "MetricBasis.h"
#include "bezierBasis.h"
#include "JacobianBasis.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"
#include "MHexahedron.h"
#include "OS.h"
#include <queue>
#include <sstream>
#include <limits>
#include <iomanip>
#include <cmath>

double MetricBasis::_tol = 1e-3;

//TODO Renommer fonctions plus explicitement (minmaxA,...) et rendre statique certaines fonctions

namespace {
  /*
  double cubicCardanoRoot(double p, double q)
  {
    // solve the equation t^3 + p*t + q = 0
    double A = q*q/4 + p*p*p/27;
    if (A > 0) {
      double sq = std::sqrt(A);
      double t1 = -q/2+sq, t2 = -q/2-sq;;

      if (t1 < 0)
        t1 = -std::pow(-t1, 1/3.);
      else
        t1 = std::pow(t1, 1/3.);
      if (t2 < 0)
        t2 = -std::pow(-t2, 1/3.);
      else
        t2 = std::pow(t2, 1/3.);
      return t1 + t2;
    }
    else {
      double module = std::sqrt(-p*p*p/27);
      double ang = std::acos(-q/2/module);
      return 2 * std::pow(module, 1/3.) * std::cos(ang/3);
    }
  }
  */
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

  double symRand(double f = 1)
  {
    return f * (rand()%2001 - 1000) / 1000.;
  }
}

MetricBasis::MetricBasis(int tag) :
  _jacobian(NULL), _type(ElementType::ParentTypeFromTag(tag)),
  _dim(ElementType::DimensionFromTag(tag))
{
  //Msg::Fatal("Verifie si cette fonction est ok 1");
  const bool serendip = false;
  const int metOrder = metricOrder(tag);
  const int jacOrder = 3*metOrder/2;

  // get bezier and gradients for metric space
  FuncSpaceData *metricSpace = NULL;
  if (_type != TYPE_PYR)
    metricSpace = new FuncSpaceData(true, tag, metOrder, &serendip);
  else
    metricSpace = new FuncSpaceData(true, tag, false, metOrder+2,
                                    metOrder, &serendip);
  _gradients = BasisFactory::getGradientBasis(*metricSpace);
  _bezier = BasisFactory::getBezierBasis(*metricSpace);
  delete metricSpace;

  // get jacobian
  FuncSpaceData *jacSpace = NULL;
  if (_type == TYPE_TET || _type == TYPE_HEX || _type == TYPE_PRI) {
    jacSpace = new FuncSpaceData(true, tag, jacOrder, &serendip);
  }
  else if (_type == TYPE_PYR) {
    // The square of the jacobian must be in the same space than the cube of
    // the metric, so +3
    jacSpace = new FuncSpaceData(true, tag, false, jacOrder+3,
                                 jacOrder, &serendip);
  }
  else if (_type == TYPE_TRI || _type == TYPE_QUA) {
    // jacobian not needed
  }
  else
    Msg::Fatal("metric not implemented for element tag %d", tag);

  if (jacSpace) {
    _jacobian = BasisFactory::getJacobianBasis(*jacSpace);
    delete jacSpace;
  }

  _fillInequalities(metOrder);
}

double MetricBasis::getMinR(MElement *el)
{
  /*static int a = 0;
  if (++a == 1) {
    double pinf = 1/.0;
    double minf = -1/.0;
    double mynan = .0/.0;
    Msg::Info("pinf=%g minf=%g mynan=%g", pinf, minf, mynan);
    Msg::Info(". == . => %d %d %d", pinf == pinf, minf == minf, mynan == mynan);
    Msg::Info("./. => %g %g %g", pinf/pinf, minf/minf, mynan/mynan);
    Msg::Info("1. < . => %d %d %d", 1. < pinf, 1. < minf, 1. < mynan);
    Msg::Info("1. > . => %d %d %d", 1. > pinf, 1. > minf, 1. > mynan);
    Msg::Info("max => %g %g %g", std::max(1., pinf), std::max(1., minf), std::max(1., mynan));
    Msg::Info("min => %g %g %g", std::min(1., pinf), std::min(1., minf), std::min(1., mynan));
    Msg::Info("inv => %g %g %g", 1./pinf, 1./minf, 1./mynan);
    Msg::Info("pinf>. => %d %d %d", pinf > pinf, pinf > minf, pinf > mynan);
    Msg::Info(" ");
    double giant = std::numeric_limits<double>::max();
    double infinity = std::numeric_limits<double>::infinity();
    Msg::Info("giant=%g, giant*10=%g infinity=%g", giant, giant*10, infinity);
    Msg::Info("a=pinf, (a - 1) / (a + 1) => %g/%g => %g", pinf - 1, pinf + 1, (pinf - 1) / (pinf + 1));
    Msg::Info("a=giant, (a - 1) / (a + 1) => %g/%g => %g", giant - 1, giant + 1, (giant - 1) / (giant + 1));
    Msg::Info("giant*10 == infinity => %d", giant*10 == std::numeric_limits<double>::infinity());
    Msg::Info("sqrt(pinf) => %g", std::sqrt(pinf));
    Msg::Info("!(mynan >= 1) => %d, (mynan < 1) => %d", !(mynan >= 1), mynan < 1);
  }*/

  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  double m = metric->computeMinR(el);
  //Msg::Info("returning %g", m);
  return m;
}

double MetricBasis::computeMinR(MElement *el) const
{
  int nSampPnts = _gradients->getNumSamplingPoints();
  int nMapping = _gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);

  // Jacobian coefficients
  fullVector<double> *jac = NULL;
  if (_jacobian) {
    fullVector<double> jacLag(_jacobian->getNumJacNodes());
    jac = new fullVector<double>(_jacobian->getNumJacNodes());
    _jacobian->getSignedIdealJacobian(nodes, jacLag);
    _jacobian->lag2Bez(jacLag, *jac);
  }

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff<true>(el->getDim(), _gradients, nodes, metCoeffLag);
  fullMatrix<double> *metCoeff;
  metCoeff = new fullMatrix<double>(nSampPnts, metCoeffLag.size2());
  _bezier->matrixLag2Bez.mult(metCoeffLag, *metCoeff);

  /*static double inf = std::numeric_limits<double>::infinity();
  double minq = inf, maxq = -inf;
  for (int k = 0; k < nSampPnts; ++k) {
    minq = std::min(minq, (*metCoeff)(k, 0));
    maxq = std::max(maxq, (*metCoeff)(k, 0));
  }
  double minp = 0, maxp = 0;
  for (int i = 1; i < 7; ++i) {
    double min = inf, max = -inf;
    for (int k = 0; k < nSampPnts; ++k) {
      min = std::min(min, (*metCoeff)(k, i));
      max = std::max(max, (*metCoeff)(k, i));
    }
    if (min < 0 && max < 0) {
      double tmp = min;
      min = -max;
      max = -tmp;
    }
    minp += min*min;
    maxp += max*max;
  }
  minp = std::sqrt(minp);
  maxp = std::sqrt(maxp);
  double mina = minq/maxp;
  double maxa = maxq/minp;
  if (maxa-mina < _tol) {
    return getMinSampledR(el, 0);
  }*/

  // Compute min(R, _tol)
  double RminLag, RminBez;
  //Msg::Info("element %d", el->getNum());
  _computeBoundsRmin(*metCoeff, *jac, RminLag, RminBez);

  //statsForMatlab(el, 20, NULL);

  //Msg::Info("%.10g %.10g", RminBez, RminLag);

  if (RminLag-RminBez < _tol) {
    delete jac;
    delete metCoeff;
    return RminBez;
  }
  else {
    //Msg::Info("Subdivision (%g vs %g)", RminLag, RminBez);
    MetricData *md2 = new MetricData(metCoeff, jac, RminBez, 0, 0);
    double minBez = _subdivideForRmin(md2, RminLag, _tol, el);
    //Msg::Info("bez lag %.10g %.10g", minBez, RminLag);
    return minBez;
  }
}

double MetricBasis::getMinSampledR(MElement *el, int order)
{
  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  return metric->computeMinSampledR(el, order);
}

double MetricBasis::computeMinSampledR(MElement *el, int deg) const
{
  //Msg::Fatal("Verifie si cette fonction est ok b");
  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);

  MetricData *md;
  _getMetricData(el, md);

  fullMatrix<double> R;
  interpolate(el, md, samplingPoints, R);

  if (R.size1() < 1) {
    delete md;
    return -1;
  }

  double min = R(0, 1);
  for (int i = 1; i < R.size1(); ++i)
    min = std::min(min, R(i, 1));

  delete md;
  return min;
}

double MetricBasis::getMaxSampledR(MElement *el, int order)
{
  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  return metric->computeMaxSampledR(el, order);
}

double MetricBasis::computeMaxSampledR(MElement *el, int deg) const
{
  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);

  MetricData *md;
  _getMetricData(el, md);

  fullMatrix<double> R;
  interpolate(el, md, samplingPoints, R);

  if (R.size1() < 1) {
    delete md;
    return -1;
  }

  double max = R(0, 1);
  for (int i = 1; i < R.size1(); ++i)
    max = std::max(max, R(i, 1));

  delete md;
  return max;
}

void MetricBasis::lag2Bez(const fullMatrix<double> &metCoeffLag,
             fullMatrix<double> &metCoeffBez) const
{
  _bezier->matrixLag2Bez.mult(metCoeffLag, metCoeffBez);
}

double MetricBasis::getMinSampledGlobalRatio(MElement *el, int order)
{
  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  return metric->computeMinSampledGlobalRatio(el, order);
}

double MetricBasis::computeMinSampledGlobalRatio(MElement *el, int deg) const
{
  Msg::Fatal("Verifie si cette fonction est ok d");
  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);

  MetricData *md;
  _getMetricData(el, md);

  fullMatrix<double> R;
  interpolate(el, md, samplingPoints, R);

  double min = R(0, 2);
  double max = R(0, 3);
  for (int i = 1; i < R.size1(); ++i) {
    min = std::min(min, R(i, 2));
    max = std::max(max, R(i, 3));
  }

  //Msg::Info("%g %g", min, max);

  delete md;
  return std::sqrt(min/max);
}

double MetricBasis::getMinRCorner(MElement *el)
{
  Msg::Fatal("Verifie si cette fonction est ok e");
  int tag = el->getTypeForMSH();
  int order = 1;
  if (el->getType() == TYPE_TRI || el->getType() == TYPE_TET) order = 0;

  const GradientBasis *gradients;
  const JacobianBasis *jacobian;
  if (el->getType() != TYPE_PYR) {
    gradients = BasisFactory::getGradientBasis(tag, order);
    jacobian = BasisFactory::getJacobianBasis(tag, order);
  }
  else {
    const bool serendip = false;
    FuncSpaceData fsd(true, tag, false, 1, 0, &serendip);
    gradients = BasisFactory::getGradientBasis(fsd);
    jacobian = BasisFactory::getJacobianBasis(fsd);
  }

  int nSampPnts = jacobian->getNumJacNodes();
  if (el->getType() == TYPE_PYR) nSampPnts = 4;
  int nMapping = gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);

  // Jacobian coefficients
  fullVector<double> jacLag(jacobian->getNumJacNodes());
  jacobian->getSignedJacobian(nodes, jacLag);

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff<false>(el->getDim(), gradients, nodes, metCoeffLag);

  // Compute min_corner(R)
  return _computeMinlagR(jacLag, metCoeffLag, nSampPnts);
}

void MetricBasis::_fillInequalities(int metricOrder)
{
  //Msg::Fatal("Verifie si cette fonction est ok");
  if (_type == TYPE_PYR) {
    _fillInequalitiesPyr(metricOrder);
    return;
  }

  fullMatrix<int> exp(_bezier->_exponents.size1(), _bezier->_exponents.size2());
  for (int i = 0; i < _bezier->_exponents.size1(); ++i) {
    for (int j = 0; j < _bezier->_exponents.size2(); ++j) {
      exp(i, j) = static_cast<int>(_bezier->_exponents(i, j) + .5);
    }
  }

  int ncoeff = _gradients->getNumSamplingPoints();
  int dimSimplex = _bezier->getDimSimplex();
  int dim = _bezier->getDim();

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
        _ineqP3[hash].push_back(IneqData(num/den, i, j, k));
      }
    }
  }

  if (_dim == 2) {
    _lightenInequalities(countJ2, countP3, countA);
    return;
  }

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

  _lightenInequalities(countJ2, countP3, countA);
}

void MetricBasis::_fillInequalitiesPyr(int metricOrder)
{
  //Msg::Fatal("Verifie si cette fonction est ok");
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
      double num, den;
      num = nChoosek(metricOrder+2, exp(i, 0))
          * nChoosek(metricOrder+2, exp(i, 1))
          * nChoosek(metricOrder  , exp(i, 2))
          * nChoosek(metricOrder+2, exp(j, 0))
          * nChoosek(metricOrder+2, exp(j, 1))
          * nChoosek(metricOrder  , exp(j, 2));
      den = nChoosek(2*metricOrder+4, exp(i, 0) + exp(j, 0))
          * nChoosek(2*metricOrder+4, exp(i, 1) + exp(j, 1))
          * nChoosek(2*metricOrder  , exp(i, 2) + exp(j, 2));

      if (i != j) num *= 2;

      ++countA;
      int hash = 0;
      for (int l = 0; l < 3; l++) {
        hash += (exp(i, l)+exp(j, l)) * pow_int(2*metricOrder+1, l);
      }
      _ineqA[hash].push_back(IneqData(num/den, i, j));


      for (int k = j; k < ncoeff; ++k) {
        double num, den;
        num = nChoosek(metricOrder+2, exp(i, 0))
            * nChoosek(metricOrder+2, exp(i, 1))
            * nChoosek(metricOrder  , exp(i, 2))
            * nChoosek(metricOrder+2, exp(j, 0))
            * nChoosek(metricOrder+2, exp(j, 1))
            * nChoosek(metricOrder  , exp(j, 2))
            * nChoosek(metricOrder+2, exp(k, 0))
            * nChoosek(metricOrder+2, exp(k, 1))
            * nChoosek(metricOrder  , exp(k, 2));
        den = nChoosek(3*metricOrder+6, exp(i, 0) + exp(j, 0) + exp(k, 0))
            * nChoosek(3*metricOrder+6, exp(i, 1) + exp(j, 1) + exp(k, 1))
            * nChoosek(3*metricOrder  , exp(i, 2) + exp(j, 2) + exp(k, 2));

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
        for (int l = 0; l < 3; l++) {
          hash += (exp(i, l)+exp(j, l)+exp(k, l)) * pow_int(3*metricOrder+1, l);
        }
        _ineqP3[hash].push_back(IneqData(num/den, i, j, k));
      }
    }
  }

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

      double num, den;
      num = nChoosek(order+3, exp(i, 0))
          * nChoosek(order+3, exp(i, 1))
          * nChoosek(order  , exp(i, 2))
          * nChoosek(order+3, exp(j, 0))
          * nChoosek(order+3, exp(j, 1))
          * nChoosek(order  , exp(j, 2));
      den = nChoosek(2*order+6, exp(i, 0) + exp(j, 0))
          * nChoosek(2*order+6, exp(i, 1) + exp(j, 1))
          * nChoosek(2*order  , exp(i, 2) + exp(j, 2));

      if (i != j) num *= 2;

      ++countJ2;
      int hash = 0;
      for (int k = 0; k < 3; k++) {
        hash += (exp(i, k)+exp(j, k)) * pow_int(2*order+1, k);
      }
      _ineqJ2[hash].push_back(IneqData(num/den, i, j));
    }
  }

  _lightenInequalities(countJ2, countP3, countA);
}

void MetricBasis::_lightenInequalities(int &countj, int &countp, int &counta)
{
  //Msg::Fatal("Verifie si cette fonction est ok");
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

bool MetricBasis::validateBezierForMetricAndJacobian()
{
  Msg::Fatal("Verifie si cette fonction est ok f");
  Msg::Info("Testing Bezier interpolation and subdivision "
      "for jacobien and metric on all element types...");
  int numError = 0;

  // Parameters
  const int numElem = 10000000; ////////

  MElement **elements;
  elements = new MElement*[numElem];

  for (int tag = 1; tag <= MSH_NUM_TYPE; ++tag) {
    if (tag != 9) continue;   ////////
    const int numPrimNode = 3; ////////

    const int order = ElementType::OrderFromTag(tag);
    const int dim = ElementType::DimensionFromTag(tag);
    const int primTag = ElementType::getPrimaryTag(tag);

    Msg::Info("... testing element tag %d", tag);

    // Get reference nodes
    const nodalBasis *mapBasis = BasisFactory::getNodalBasis(tag);
    fullMatrix<double> nodes;
    mapBasis->getReferenceNodes(nodes);

    // Create 'numElem' elements more and more randomized
    for (int iel = 0; iel < numElem; ++iel) {
      //const double range = static_cast<double>(iel) / (numElem-1) / order;
      const double rangePrim = static_cast<double>(iel/2000) / ((numElem/2000)-1) / order; ////////
      const double rangeSub = static_cast<double>(iel%2000) / 1999 / order;                ////////
      if (!(iel%200)) Msg::Info("%g %g", rangePrim, rangeSub);
      std::vector<MVertex*> vertices(nodes.size1());
      for (int i = 0; i < numPrimNode; ++i) {
        vertices[i] = new MVertex(nodes(i, 0) + symRand(rangePrim),
                                  nodes(i, 1) + symRand(rangePrim),
                                  nodes(i, 2) + symRand(rangePrim));
      }
      MElement *primEl = MElement::createElement(primTag, vertices);

      for (int i = numPrimNode; i < nodes.size1(); ++i) {
        SPoint3 p;
        primEl->pnt(nodes(i, 0), nodes(i, 1), nodes(i, 2), p);
        vertices[i] = new MVertex(p.x() + symRand(rangeSub),
                                  p.y() + symRand(rangeSub),
                                  p.z() + symRand(rangeSub));
      }
      MElement *el = MElement::createElement(tag, vertices);
      if (!el) {
        Msg::Error("MElement was unable to create element for tag %d", tag);
        ++numError;
      }

      elements[iel] = el;
    }
#if defined(HAVE_PLUGINS)
    GMSH_AnalyseCurvedMeshPlugin plugin = GMSH_AnalyseCurvedMeshPlugin();
    plugin.test(elements, numElem, dim);
#endif
  }


  //=================
  return true; //987;
  //=================

  /*Msg::Info("Testing Bezier interpolation and subdivision "
      "for jacobien and metric on all element types...");
  int numError = 0;

  // Parameters
  const int numType = 6;
  const int acceptedTypes[numType] = {TYPE_TRI, TYPE_QUA, TYPE_TET,
                                      TYPE_PYR, TYPE_PRI, TYPE_HEX};
  const int maxOrder = 3; // at least 3 (so that serendip tet are tested)
  const int numElem = 5; // at least 2 (first is reference element)
  const int numSubdiv = 2; // at least 1
  const int numSampPnt = 10; // at least 1
  const double toleranceTensor = 1e-11; // at most 1e-5 (metric takes values in [0,1])
  double tolerance; // computed in function of tag

  //
  static const double epsilon = std::numeric_limits<double>::epsilon();

  for (int tag = 1; tag <= MSH_NUM_TYPE; ++tag) {
    if (tag > 66 && tag < 71) continue; //not conventional elements
    if (tag > 75 && tag < 79) continue; //no element tag 76, 77, 78...

    // Check if accepted type
    const int type = ElementType::ParentTypeFromTag(tag);
    bool knownType = false;
    for (int i = 0; i < numType; ++i) {
      knownType = (knownType || type == acceptedTypes[i]);
    }
    if (!knownType) continue;

    const int order = ElementType::OrderFromTag(tag);
    const int dim = ElementType::DimensionFromTag(tag);
    const bool serendip = ElementType::SerendipityFromTag(tag) > 1;

    // Skip p0 elements and elements for which order > 'maxOrder'
    // and skip for now serendipty pyramids (not implemented)
    if (order < 1 || order > maxOrder) continue;
    if (type == TYPE_PYR && serendip) continue;

    Msg::Info("... testing element tag %d", tag);

    // Compute tolerance
    tolerance = epsilon * pow_int(10, order*dim);
    if (type == TYPE_PYR) tolerance = std::max(tolerance, epsilon*1e9);

    // Get reference nodes
    const nodalBasis *mapBasis = BasisFactory::getNodalBasis(tag);
    fullMatrix<double> nodes;
    mapBasis->getReferenceNodes(nodes);

    // Create 'numElem' elements more and more randomized
    for (int iel = 0; iel < numElem; ++iel) {
      const double range = static_cast<double>(iel) / (numElem-1) / order;
      std::vector<MVertex*> vertices(nodes.size1());
      for (int i = 0; i < nodes.size1(); ++i) {
        vertices[i] = new MVertex(nodes(i, 0) + symRand(range),
                                  dim > 1 ? nodes(i, 1) + symRand(range) : 0,
                                  dim > 2 ? nodes(i, 2) + symRand(range) : 0);
      }
      MElement *el = MElement::createElement(tag, vertices);
      if (!el) {
        Msg::Error("MElement was unable to create element for tag %d", tag);
        ++numError;
      }

      numError += validateBezierForMetricAndJacobian(el, numSampPnt, numSubdiv,
                                                     toleranceTensor, tolerance);
    }
  }

  if (numError) Msg::Error("Validation of Bezier terminated with %d errors!", numError);
  else Msg::Info("Validation of Bezier terminated without errors");
  return numError;*/
}

int MetricBasis::validateBezierForMetricAndJacobian(MElement *el,
                                                    int numSampPnt,
                                                    int numSubdiv,
                                                    double toleranceTensor,
                                                    double tolerance)
{
  Msg::Fatal("Verifie si cette fonction est ok g");
  const int tag = el->getTypeForMSH();
  const MetricBasis *metricBasis = BasisFactory::getMetricBasis(tag);

  // compare the two metric
  fullMatrix<double> metric_Bez(numSampPnt, 2);
  fullVector<int> isub(numSubdiv);
  fullMatrix<double> uvw(numSampPnt, 3);
  metricBasis->interpolateAfterNSubdivisions(el, numSubdiv, numSampPnt,
                                             isub, uvw, metric_Bez);

  int numBadMatch = 0;
  int numBadMatchTensor = 0;
  double maxBadMatch = 0;
  double maxBadMatchTensor = 0;
  for (int isamp = 0; isamp < numSampPnt; ++isamp) {
    double dum[3];
    double &u = uvw(isamp, 0);
    double &v = uvw(isamp, 1);
    double &w = uvw(isamp, 2);
    double metric_Lag = el->getEigenvaluesMetric(u, v, w, dum);

    double diff = std::abs(metric_Lag - metric_Bez(isamp, 0));
    double diffTensor = std::abs(metric_Lag - metric_Bez(isamp, 1));

    if (diffTensor > toleranceTensor) {
      ++numBadMatchTensor;
      maxBadMatchTensor = std::max(maxBadMatchTensor, diffTensor);
    }
    else if (diff > tolerance) {
      ++numBadMatch;
      maxBadMatch = std::max(maxBadMatch, diff);
    }
  }

  if (numBadMatchTensor > .2*numSampPnt) {
    Msg::Error("Too much errors "
        "even when computing by metric tensor (max %g)", maxBadMatchTensor);
    return 1;
  }
  else if (numBadMatch > .5*numSampPnt) {
    Msg::Error("Too much errors (max %g)", maxBadMatch);
    return 1;
  }
  return 0;
}

void MetricBasis::interpolate(const MElement *el,
                              const MetricData *md,
                              const fullMatrix<double> &nodes,
                              fullMatrix<double> &R) const
{
  //Msg::Fatal("Verifie si cette fonction est ok h");
  fullMatrix<double> &metcoeffs = *md->_metcoeffs, *metric = new fullMatrix<double>;
  fullVector<double> &jaccoeffs = *md->_jaccoeffs, *jac = new fullVector<double>;

  _bezier->interpolate(metcoeffs, nodes, *metric);

  R.resize(nodes.size1(), 4);

  switch (metcoeffs.size2()) {
  case 1:
    for (int i = 0; i < R.size1(); ++i)
      R(i, 0) = R(i, 1) = 1;
    break;

  case 3:
    ((MetricBasis*)this)->file << "q p myR eigR" << std::endl;
    ((MetricBasis*)this)->file << _bezier->getNumLagCoeff() << std::endl;
    for (int i = 0; i < R.size1(); ++i) {
      // Compute from q, p
      double p = pow((*metric)(i, 1), 2);
      p += pow((*metric)(i, 2), 2);
      p = std::sqrt(p);
      R(i, 0) = std::sqrt(_R2Dsafe((*metric)(i, 0), p));
      // Comppute from tensor
      fullMatrix<double> metricTensor(2, 2);
      metricTensor(0, 0) = (*metric)(i, 0) + (*metric)(i, 1);
      metricTensor(1, 1) = (*metric)(i, 0) - (*metric)(i, 1);
      metricTensor(0, 1) = metricTensor(1, 0) = (*metric)(i, 2);
      fullVector<double> valReal(2), valImag(2);
      fullMatrix<double> vecLeft(2, 2), vecRight(2, 2);
      metricTensor.eig(valReal, valImag, vecLeft, vecRight, true);
      R(i, 1) = std::sqrt(valReal(0) / valReal(1));
      R(i, 2) = valReal(0);
      R(i, 3) = valReal(1);
      ((MetricBasis*)this)->file << (*metric)(i, 0) << " ";
      ((MetricBasis*)this)->file << p << " ";
      ((MetricBasis*)this)->file << R(i, 0) << " ";
      ((MetricBasis*)this)->file << R(i, 1) << std::endl;
      }
    break;

  case 7:
    ((MetricBasis*)this)->file << "a K myR eigR" << std::endl;
    ((MetricBasis*)this)->file << _bezier->getNumLagCoeff() << std::endl;
    _jacobian->getBezier()->interpolate(jaccoeffs, nodes, *jac);
    for (int i = 0; i < R.size1(); ++i) {
      // Compute from q, p, J
      double p = 0;
      for (int k = 1; k < 7; ++k) p += pow((*metric)(i, k), 2);
      p = std::sqrt(p);
      R(i, 0) = std::sqrt(_R3Dsafe((*metric)(i, 0), p, (*jac)(i)));
      // Compute from tensor
      fullMatrix<double> metricTensor(3, 3);
      for (int k = 0; k < 3; ++k) {
        static double fact1 = std::sqrt(6.);
        static double fact2 = std::sqrt(3.);
        const int ki = k%2;
        const int kj = std::min(k+1, 2);
        metricTensor(k, k) = (*metric)(i, k+1)*fact1 + (*metric)(i, 0);
        metricTensor(ki, kj) = metricTensor(kj, ki) = (*metric)(i, k+4)*fact2;
      }
      fullVector<double> valReal(3), valImag(3);
      fullMatrix<double> vecLeft(3, 3), vecRight(3, 3);
      metricTensor.eig(valReal, valImag, vecLeft, vecRight, true);
      R(i, 1) = std::sqrt(valReal(0) / valReal(2));
      R(i, 2) = valReal(0);
      R(i, 3) = valReal(2);
      ((MetricBasis*)this)->file << (*metric)(i, 0)/p << " ";
      ((MetricBasis*)this)->file << (*jac)(i)*(*jac)(i)/p/p/p << " ";
      ((MetricBasis*)this)->file << R(i, 0) << " ";
      ((MetricBasis*)this)->file << R(i, 1) << std::endl;
    }
    break;

  default:
    Msg::Error("Wrong number of functions for metric: %d",
               metcoeffs.size2());
  }

  delete jac;
  delete metric;
}

void MetricBasis::interpolateAfterNSubdivisions(
    const MElement *el, int numSubdiv, int numPnt,
    fullVector<int> &isub,
    fullMatrix<double> &uvw,
    fullMatrix<double> &metric) const
{
  Msg::Fatal("Verifie si cette fonction est ok i");
  // Interpolate metric after 'numSub' random subdivision at
  //   'numPnt' random points.
  // Return: isub, the subdomain tag of each subdivision,
  //         uvw, the reference points at which metric has been interpolated.
  //         metric, the interpolation.

  MetricData *md;
  _getMetricData(el, md);

  // Keep trace of subdomain to be able to compute uvw.
  // (Ensure to have the tag for the complete element):
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(el->getTypeForMSH());
  fullMatrix<double> nodes;
  mapBasis->getReferenceNodesForBezier(nodes);

  const int nSub = _bezier->getNumDivision();
  const int numCoeff = md->_metcoeffs->size2();
  const int numMetPnts = md->_metcoeffs->size1();
  const int numJacPnts = md->haveJac() ? md->_jaccoeffs->size() : 0;
  const int numNodPnts = nodes.size1();

  const bezierBasis *bezierMapping;
  if (el->getType() != TYPE_PYR)
    bezierMapping = BasisFactory::getBezierBasis(el->getTypeForMSH());
  else {
    FuncSpaceData data(true, el->getTypeForMSH(), false,
                       el->getPolynomialOrder(), el->getPolynomialOrder());
    bezierMapping = BasisFactory::getBezierBasis(data);
  }

  for (int k = 0; k < numSubdiv; ++k) {
    fullMatrix<double> subcoeffs, subnodes;
    fullVector<double> subjac;
    _bezier->subdivideBezCoeff(*md->_metcoeffs, subcoeffs);
    bezierMapping->subdivideBezCoeff(nodes, subnodes);

    if (_dim == 3)
      _jacobian->getBezier()->subdivideBezCoeff(*md->_jaccoeffs, subjac);
    delete md;

    isub(k) = std::rand() % nSub;

    fullMatrix<double> *coeff = new fullMatrix<double>(numMetPnts, numCoeff);
    coeff->copy(subcoeffs, isub(k) * numMetPnts, numMetPnts, 0, numCoeff, 0, 0);
    nodes.copy(subnodes, isub(k) * numNodPnts, numNodPnts, 0, _dim, 0, 0);
    fullVector<double> *jac = NULL;
    if (_dim == 3) {
      jac = new fullVector<double>(numJacPnts);
      jac->copy(subjac, isub(k) * numJacPnts, numJacPnts, 0);
    }

    md = new MetricData(coeff, jac);
  }

  // compute a random convex combination of reference nodes
  fullMatrix<double> subuvw(uvw.size1(), _dim);
  {
    int tagPrimary = ElementType::getTag(el->getType(), 1);
    const nodalBasis *primMapBasis = BasisFactory::getNodalBasis(tagPrimary);
    fullMatrix<double> refNodes;
    primMapBasis->getReferenceNodes(refNodes);
    double *c = new double[refNodes.size1()];

    for (int k = 0; k < uvw.size1(); ++k) {
      double sum = 0;
      int exp = 1 + std::rand() % 5;
      for (int i = 0; i < refNodes.size1(); ++i) {
        c[i] = pow_int((std::rand() % 1000) / 1000., exp);
        sum += c[i];
      }
      for (int i = 0; i < refNodes.size1(); ++i) {
        c[i] /= sum;
        subuvw(k, 0) += c[i] * refNodes(i, 0);
        if (_dim > 1) subuvw(k, 1) += c[i] * refNodes(i, 1);
        if (_dim > 2) subuvw(k, 2) += c[i] * refNodes(i, 2);
      }
    }

    delete[] c;
  }

  interpolate(el, md, subuvw, metric);
  bezierMapping->interpolate(nodes, subuvw, uvw, false);
  delete md;
}

void MetricBasis::statsForMatlab(MElement *el, int deg, MetricData *md) const
{
  //return;
  //Msg::Fatal("Verifie si cette fonction est ok h");
  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);

  if (!md) _getMetricData(el, md);

  static unsigned int aa = 0;
  if (md->_num < 100000 && ++aa < 1000) {
    std::stringstream name;
    name << "metricStat_" << el->getNum() << "_";
    name << (md->_num % 10);
    name << (md->_num % 100)/10;
    name << (md->_num % 1000)/100;
    name << (md->_num % 10000)/1000;
    name << (md->_num % 100000)/10000;
    name << ".txt";
    ((MetricBasis*)this)->file.open(name.str().c_str(), std::fstream::out);

    {
      ((MetricBasis*)this)->file << "mina minKfast minKsharp cmin beta_m beta_M beta c_m" << std::endl;
      double mina, maxa, minKs, minKf, c, beta_m, beta_M, beta, c_m;

      fullMatrix<double> *coeff = md->_metcoeffs;
      fullVector<double> *jac = md->_jaccoeffs;
      _minMaxA(*coeff, mina, maxa);

      if (el->getDim() == 3) {
        _minKfast(*coeff, *jac, minKf);
        _minKsharp(*coeff, *jac, minKs);
        double minK = minKf;
        _moveInsideDomain(mina, minK, true);
        double p_dRda, p_dRdK;
        _computePseudoDerivatives(mina, minK, p_dRda, p_dRdK);
        double slope = -p_dRda/p_dRdK;
        c = .5*(3*minK/mina - slope);
        _computeBoundingCurve(*coeff, *jac, beta_m, c, true);
        _computeBoundingCurve(*coeff, *jac, beta_M, c, false);
        beta = -p_dRda/(p_dRdK*3*mina*mina);
        if (beta < 0)
          _computeLowerBoundC(*coeff, *jac, beta, c_m);
        else
          c_m = -1;
      }
      else {
        minKs = minKf = c = beta_m = beta_M = beta = c_m = -1;
      }

      ((MetricBasis*)this)->file << std::setprecision(15);
      ((MetricBasis*)this)->file << mina << " " << minKf << " " << minKs << " ";
      ((MetricBasis*)this)->file << c << " " << beta_m << " " << beta_M << " ";
      ((MetricBasis*)this)->file << beta << " " << c_m << std::endl;
      ((MetricBasis*)this)->file << std::setprecision(8);
    }
  }

  fullMatrix<double> R;
  interpolate(el, md, samplingPoints, R);
  ((MetricBasis*)this)->file.close();

  return;

  if (R.size1() < 1) {
    ((MetricBasis*)this)->file << -1 << " ";
    ((MetricBasis*)this)->file.close();
    return;
  }

  double min = R(0, 1);
  for (int i = 1; i < R.size1(); ++i)
    min = std::min(min, R(i, 1));

  //((MetricBasis*)this)->file << min << " ";
  ((MetricBasis*)this)->file.close();
  return;
}

int MetricBasis::metricOrder(int tag)
{
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int order = ElementType::OrderFromTag(tag);

  switch (parentType) {
    case TYPE_PNT : return 0;

    case TYPE_LIN : return order;

    case TYPE_TRI :
    case TYPE_TET :
    case TYPE_PYR : return 2*order-2;

    case TYPE_QUA :
    case TYPE_PRI :
    case TYPE_HEX : return 2*order;

    default :
      Msg::Error("Unknown element type %d, return order 0", parentType);
      return 0;
  }
}

void MetricBasis::_computeBoundsRmin(
    const fullMatrix<double> &coeff, const fullVector<double> &jac,
    double &sqrtRminLag, double &sqrtRminBez) const
{
  sqrtRminLag = _computeMinlagR(jac, coeff, _bezier->getNumLagCoeff());
  if (sqrtRminLag <= _tol) {
    sqrtRminBez = .0;
    return;
  }

  if (coeff.size2() == 3) { // 2d element
    double mina, dummy;
    _minMaxA(coeff, mina, dummy);
    sqrtRminBez = std::sqrt(_R2Dsafe(mina));
    return;
  }

  double minK, mina, dummy;
  _minKfast(coeff, jac, minK);
  _minMaxA(coeff, mina, dummy);

  _moveInsideDomain(mina, minK, true);

  double p_dRda, p_dRdK;
  _computePseudoDerivatives(mina, minK, p_dRda, p_dRdK);

  if (p_dRda < 0) {
    //Msg::Info("case 1 & 2");
    // cases 1 & 2 => compute a lower bounding curve K = beta * a^3 + c * a
    // with c such that the curve that pass through (minK, mina) has the
    // slope equal to -dRda/dRdK
    double slope = -p_dRda/p_dRdK;
    double c = .5*(3*minK/mina - slope);
    double beta;
    _computeBoundingCurve(coeff, jac, beta, c, true);
    {
      double beta = (minK/mina-c)/mina/mina;
      if (std::abs(p_dRda + p_dRdK * (3*beta*mina*mina+c)) > 1e-12) {
        Msg::Error("Derivative along curve not zero %g", p_dRda + p_dRdK * (3*beta*mina*mina+c));
      }
    }

    double a_int = mina, K_int = minK;
    bool onVertical = _intersectionCurveLeftCorner(beta, c, a_int, K_int);
    if (onVertical) {
      // then the minimum is on the curve, we prefer to return this
      sqrtRminBez = std::sqrt(_R3Dsafe(mina, minK));
      //Msg::Info("onvertical");
      return;
    }
    /*if (a_int - mina < ???) {
      sqrtRminBez = std::sqrt(_R3Dsafe(a_int, minK));
      return;
    }*/

    bool haveToCompute_a0;
    if (_moveInsideDomain(a_int, K_int, true)) {
      haveToCompute_a0 = true;
    }
    else {
      double p_dRda, p_dRdK;
      _computePseudoDerivatives(a_int, K_int, p_dRda, p_dRdK);
      if (p_dRda + p_dRdK * (3*beta*a_int*a_int+c) < -1e-5) {
        Msg::Error("Derivative along curve not positive or zero %g", p_dRda + p_dRdK * (3*beta*a_int*a_int+c));
        Msg::Info("(%g, %g) vs (%g, %g), diff (%g, %g)", mina, minK, a_int, K_int, a_int-mina, K_int-minK);
        double beta2 = (minK/mina-c)/mina/mina;
        Msg::Info("beta %g - %g = %g", beta, beta2, beta-beta2);
      }
      haveToCompute_a0 = p_dRda > 0;
    }

    if (haveToCompute_a0) {
      double a0 = _computeAbscissaMinR(mina, minK);
      sqrtRminBez = std::sqrt(_R3Dsafe(a0, minK));
    }
    else {
      sqrtRminBez = std::sqrt(_R3Dsafe(a_int, K_int));
    }
    return;
  }
  else if (p_dRdK < 0) {
    //Msg::Info("case 4 & 5");
    double slope = -p_dRda/p_dRdK;
    double c = .5*(3*minK/mina - slope);
    double beta;
    _computeBoundingCurve(coeff, jac, beta, c, false);
    double a_int = mina, K_int = minK;

    if (_intersectionCurveLeftCorner(beta, c, a_int, K_int)) {
      /*if (std::abs(a_int - mina) < _tol / 100 &&
          std::abs(K_int - minK) < _tol / 100) {
        sqrtRminBez = std::sqrt(_R3Dsafe(mina, minK));
        return;
      }*/
      // We compute K0 and return _R3Dsafe(mina, min(K0,K_int))
      double K0 = 2*std::cos(3*std::acos(-1/mina)-M_PI) + (mina*mina-3) * mina;
      sqrtRminBez = std::sqrt(_R3Dsafe(mina, std::min(K0, K_int)));
    }
    else {
      if (_moveInsideDomain(a_int, K_int, false))
        sqrtRminBez = std::sqrt(_R3Dsafe(a_int, K_int));
      else
        sqrtRminBez = std::sqrt(_computeMinRAlongCurve(beta, c, a_int, -1));
    }
    return;
  }
  else {
    //Msg::Info("case 3");
    sqrtRminBez = std::sqrt(_R3Dsafe(mina, minK));
    return;
  }
}

void MetricBasis::_computeBoundsRmax(
    const fullMatrix<double> &coeff, const fullVector<double> &jac,
    double &RmaxLag) const
{
  Msg::Fatal("Verifie si cette fonction est ok k");
  RmaxLag = 0.;

  for (int i = 0; i < _bezier->getNumLagCoeff(); ++i) {
    double q = coeff(i, 0);
    double p = 0;
    for (int k = 1; k < 7; ++k) {
      p += pow_int(coeff(i, k), 2);
    }
    p = std::sqrt(p);
    const double a = q/p;
    if (a > 1e4) {
      RmaxLag = std::max(RmaxLag, std::sqrt((a - std::sqrt(3.)) / (a + std::sqrt(3.))));
    }
    else {
      const double tmpR = _R3Dsafe(a, jac(i)/p/p*jac(i)/p);
      RmaxLag = std::max(RmaxLag, std::sqrt(tmpR));
    }
  }
}

double MetricBasis::_subdivideForRmin(MetricData *md, double &RminLag, double tol, MElement *el) const
{
  //Msg::Fatal("Verifie si cette fonction est ok l");
  std::priority_queue<MetricData*, std::vector<MetricData*>, lessMinB> subdomains;
  const bool for3d = md->_jaccoeffs;
  const int numCoeff = md->_metcoeffs->size2();
  const int numMetPnts = md->_metcoeffs->size1();
  const int numJacPnts = for3d ? md->_jaccoeffs->size() : 0;
  const int numSub = _bezier->getNumDivision();
  subdomains.push(md);

  std::vector<fullVector<double>*> trash;

  int k = 0;
  while (RminLag - subdomains.top()->_RminBez > tol && subdomains.size() < 25000) {
    fullMatrix<double> *subcoeffs, *coeff;
    fullVector<double> *subjac, *jac = NULL;

    MetricData *current = subdomains.top();
    subcoeffs = new fullMatrix<double>(numSub*numMetPnts, numCoeff);
    _bezier->subDivisor.mult(*current->_metcoeffs, *subcoeffs);
    if (for3d) {
      subjac = new fullVector<double>(numSub*numJacPnts);
      _jacobian->getBezier()->subDivisor.mult(*current->_jaccoeffs, *subjac);
    }
    int depth = current->_depth;
    int num = current->_num;
    delete current;
    subdomains.pop();

    for (int i = 0; i < numSub; ++i) {
      coeff = new fullMatrix<double>(numMetPnts, numCoeff);
      coeff->copy(*subcoeffs, i * numMetPnts, numMetPnts, 0, numCoeff, 0, 0);
      if (for3d) {
        jac = new fullVector<double>;
        jac->setAsProxy(*subjac, i * numJacPnts, numJacPnts);
      }
      double minLag, minBez;
      _computeBoundsRmin(*coeff, *jac, minLag, minBez);
      RminLag = std::min(RminLag, minLag);
      int newNum = num + (i+1) * pow_int(10, depth);
      if (depth > 8) newNum = 999999999;
      MetricData *metData = new MetricData(coeff, jac, minBez, depth+1, newNum);
      //statsForMatlab(el, 15, metData);
      //if (el) statsForMatlab(el, 20, metData);
      subdomains.push(metData);
    }
    if (for3d) trash.push_back(subjac);
    delete subcoeffs;
    ++k;
  }

  //Msg::Info("num subdiv %d", k);

  double ans = subdomains.top()->_RminBez;
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

void MetricBasis::_getMetricData(const MElement *el, MetricData *&md) const
{
  int nSampPnts = _gradients->getNumSamplingPoints();
  int nMapping = _gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);

  // Jacobian coefficients
  fullVector<double> *jac = NULL;
  if (_dim == 3) {
    fullVector<double> jacLag(_jacobian->getNumJacNodes());
    jac = new fullVector<double>(_jacobian->getNumJacNodes());
    _jacobian->getSignedIdealJacobian(nodes, jacLag);
    _jacobian->lag2Bez(jacLag, *jac);
  }

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff<true>(el->getDim(), _gradients, nodes, metCoeffLag);
  fullMatrix<double> *metCoeff;
  metCoeff = new fullMatrix<double>(nSampPnts, metCoeffLag.size2());
  _bezier->matrixLag2Bez.mult(metCoeffLag, *metCoeff);

  md = new MetricData(metCoeff, jac, -1, 0, 0);
}

template<bool ideal>
void MetricBasis::_fillCoeff(int dim, const GradientBasis *gradients,
    const fullMatrix<double> &nodes, fullMatrix<double> &coeff)
{
  //Msg::Fatal("Verifie si cette fonction est ok o");
  const int nSampPnts = gradients->getNumSamplingPoints();

  switch (dim) {
  case 0 :
    return;
  case 1 :
    Msg::Fatal("Should not be here, metric for 1d not implemented");
    break;

  case 2 :
    {
      fullMatrix<double> dxydX(nSampPnts,3), dxydY(nSampPnts,3);
      if (ideal)
        gradients->getIdealGradientsFromNodes(nodes, &dxydX, &dxydY, NULL);
      else
        gradients->getGradientsFromNodes(nodes, &dxydX, &dxydY, NULL);

      coeff.resize(nSampPnts, 3);
      for (int i = 0; i < nSampPnts; i++) {
        const double &dxdX = dxydX(i,0), &dydX = dxydX(i,1);
        const double &dxdY = dxydY(i,0), &dydY = dxydY(i,1);
        double dzdX = 0, dzdY = 0;
        if (nodes.size2() > 2) {
          dzdX = dxydX(i,2);
          dzdY = dxydY(i,2);
        }
        const double dvxdX = dxdX*dxdX + dydX*dydX + dzdX*dzdX;
        const double dvxdY = dxdY*dxdY + dydY*dydY + dzdY*dzdY;
        coeff(i, 0) = (dvxdX + dvxdY) / 2;
        coeff(i, 1) = dvxdX - coeff(i, 0);
        coeff(i, 2) = (dxdX*dxdY + dydX*dydY + dzdX*dzdY);
      }
    }
    break;

  case 3 :
    {
      fullMatrix<double> dxyzdX(nSampPnts,3), dxyzdY(nSampPnts,3), dxyzdZ(nSampPnts,3);
      if (ideal)
        gradients->getIdealGradientsFromNodes(nodes, &dxyzdX, &dxyzdY, &dxyzdZ);
      else
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
        static double fact1 = 1./std::sqrt(6.);
        static double fact2 = 1./std::sqrt(3.);
        coeff(i, 1) = fact1 * (dvxdX - coeff(i, 0));
        coeff(i, 2) = fact1 * (dvxdY - coeff(i, 0));
        coeff(i, 3) = fact1 * (dvxdZ - coeff(i, 0));
        coeff(i, 4) = fact2 * (dxdX*dxdY + dydX*dydY + dzdX*dzdY);
        coeff(i, 5) = fact2 * (dxdZ*dxdY + dydZ*dydY + dzdZ*dzdY);
        coeff(i, 6) = fact2 * (dxdX*dxdZ + dydX*dydZ + dzdX*dzdZ);
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

      const double &q = coeff(i, 0);
      double p = 0;
      for (int k = 1; k < 7; ++k) {
        p += pow_int(coeff(i, k), 2);
      }
      p = std::sqrt(p);

      Rmin = std::min(Rmin, _R3Dsafe(q, p, jac(i)));
    }
    break;

  case 3:
    for (int i = 0; i < num; ++i) {
      const double &q = coeff(i, 0);
      double p = pow_int(coeff(i, 1), 2) + pow_int(coeff(i, 2), 2);
      p = std::sqrt(p);

      Rmin = std::min(Rmin, _R2Dsafe(q, p));
    }
    break;

  default:
    Msg::Error("coeff have not right number of column");
    return -1;
  }

  return std::sqrt(Rmin);
}

void MetricBasis::_minMaxA(const fullMatrix<double> &coeff,
                           double &mina, double &max) const
{
  // TODO calculer le max ?
  double upperBound = std::numeric_limits<double>::infinity();
  double lowerBound = -upperBound;
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

    // mina has to satisfy: mina^2 * den <= num
    if (den == 0) {
      if (num >= 0) {} // ok, nothing to do
      else {// impossible to satisfy.
        _minAfast(coeff, mina);
        return;
      }
    }
    else if (den > 0)
      upperBound = std::min(upperBound, num/den);
    else
      lowerBound = std::max(lowerBound, num/den);

    ++it;
  }

  if (lowerBound > upperBound)
    _minAfast(coeff, mina);
  else
    mina = upperBound > 1 ? std::sqrt(upperBound) : 1;
}

void MetricBasis::_minAfast(const fullMatrix<double> &coeff, double &mina) const
{
  double minq = coeff(0, 0);
  for (int i = 1; i < coeff.size1(); ++i)
    minq = std::min(minq, coeff(i, 0));

  double maxp = 0;
  for (int i = 0; i < coeff.size1(); ++i) {
    double tmp = 0;
    for (int j = 1; j < 7; ++j) {
      tmp += pow_int(coeff(i, j), 2);
    }
    maxp = std::max(maxp, tmp);
  }

  mina = std::max(1., minq/maxp); // accept +inf as answer
}

void MetricBasis::_minKfast(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double &minK) const
{
  fullVector<double> P(coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    P(i) = 0;
    for (int l = 1; l < 7; ++l) {
      P(i) += coeff(i, l) * coeff(i, l);
    }
    P(i) = std::sqrt(P(i));
  }

  double upperBound = std::numeric_limits<double>::infinity();
  double lowerBound = -upperBound;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  // _ineqJ2 and _ineqP3 have the same size
  while (itJ != _ineqJ2.end()) {
    //if (itJ->first != itP->first) Msg::Fatal("not same hash %d %d", itJ->first, itP->first);
    double num = 0;
    for (unsigned int k = 0; k < itJ->second.size(); ++k) {
      const int i = itJ->second[k].i;
      const int j = itJ->second[k].j;
      num += itJ->second[k].val * jac(i) * jac(j);
    }

    double den = 0;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      den += itP->second[l].val * P(i) * P(j) * P(k);
    }

    // minK has to satisfy: minK * den <= num
    if (den == 0) {
      if (num >= 0) {
        ++itJ;
        ++itP;
        continue;
      }
      // otherwise, it's impossible to satisfy.
      minK = 0;//TODO c'est mieux de retourner _minKfast(coeff, jac, minK); ?
      return;
    }
    else if (den > 0)
      upperBound = std::min(upperBound, num/den);
    else
      lowerBound = std::max(lowerBound, num/den);

    ++itJ;
    ++itP;
  }

  if (lowerBound > upperBound)
    minK = 0;//TODO c'est mieux de retourner _minKfast(coeff, jac, minK); ?
  else
    minK = std::max(.0, upperBound);
}

void MetricBasis::_minKsharp(const fullMatrix<double> &coeff,
    const fullVector<double> &jac, double &minK) const
{
  fullVector<double> P(coeff.size1());
  fullMatrix<double> Q(coeff.size1(), coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    P(i) = 0;
    for (int l = 1; l < 7; ++l) {
      P(i) += coeff(i, l) * coeff(i, l);
    }
    P(i) = std::sqrt(P(i));
    // fill only the half
    for (int j = i; j < coeff.size1(); ++j) {
      Q(i, j) = 0;
      for (int l = 1; l < 7; ++l) {
        Q(i, j) += coeff(i, l) * coeff(j, l);
      }
    }
  }

  double upperBound = std::numeric_limits<double>::infinity();
  double lowerBound = -upperBound;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  // _ineqJ2 and _ineqP3 have the same size
  while (itJ != _ineqJ2.end()) {
    double num = 0;
    for (unsigned int k = 0; k < itJ->second.size(); ++k) {
      const int i = itJ->second[k].i;
      const int j = itJ->second[k].j;
      num += itJ->second[k].val * jac(i) * jac(j);
    }

    double den = 0;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      den += itP->second[l].val * 1/3*(Q(i,j)*P(k)+Q(i,k)*P(j)+Q(j,k)*P(i));
    }

    // minK has to satisfy: minK * den <= num
    if (den == 0) {
      if (num >= 0) {
        ++itJ;
        ++itP;
        continue;
      }
      // otherwise, it's impossible to satisfy.
      minK = 0;//TODO c'est mieux de retourner _minKfast(coeff, jac, minK); ?
      return;
    }
    else if (den > 0)
      upperBound = std::min(upperBound, num/den);
    else
      lowerBound = std::max(lowerBound, num/den);

    ++itJ;
    ++itP;
  }

  if (lowerBound > upperBound)
     minK = 0;//TODO c'est mieux de retourner _minKfast(coeff, jac, minK); ?
  else
    minK = std::max(.0, upperBound);
}

void MetricBasis::_computeBoundingCurve(const fullMatrix<double> &coeff,
                                        const fullVector<double> &jac,
                                        double &beta, double c,
                                        bool compLowBound) const
{
  // compute a lower/upper bounding curve K = beta * a^3 + c * a
  // with c fixed.

  //Msg::Info("BEGINNING %g %g", std::numeric_limits<double>::min(), std::numeric_limits<double>::denorm_min());

  fullMatrix<double> Q(coeff.size1(), coeff.size1()); // (half filled!)
  for (int i = 0; i < coeff.size1(); ++i) {
    for (int j = i; j < coeff.size1(); ++j) {
      Q(i, j) = 0;
      for (int l = 1; l < 7; ++l)
        Q(i, j) += coeff(i, l) * coeff(j, l);
    }
  }

  double upperBound = std::numeric_limits<double>::infinity();
  double lowerBound = -upperBound;

  // values in case of a failure
  if (compLowBound) beta = upperBound;
  else              beta = lowerBound;

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  // _ineqJ2 and _ineqP3 have the same size
  //int kk = 0;
  while (itJ != _ineqJ2.end()) {// && kk++ < 2) {// FIXME making tests
    long double J2 = 0;
    for (unsigned int k = 0; k < itJ->second.size(); ++k) {
      const int i = itJ->second[k].i;
      const int j = itJ->second[k].j;
      J2 += itJ->second[k].val * jac(i) * jac(j);
      //Msg::Info("(%d, %d) = (%g | %g, %g) -> J2:%Lg", i, j, itJ->second[k].val, jac(i), jac(j), J2);
    }

    long double q3 = 0, qp2 = 0;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      q3 += itP->second[l].val * coeff(i, 0) * coeff(j, 0) * coeff(k, 0);
      qp2 += itP->second[l].val * 1/3*(coeff(i, 0) * Q(j, k) +
                                       coeff(j, 0) * Q(i, k) +
                                       coeff(k, 0) * Q(i, j));
      //Msg::Info("%d %d %d => %Lg %Lg", i, j, k, q3, qp2);
      //Msg::Info("(%d %d %d) -> q3:%Lg qp2:%Lg", i, j, k, q3, qp2);
    }

    //Msg::Info("a%Lg K%Lg  %Lg %Lg", std::sqrt(q3/qp2), std::sqrt(J2*J2*q3/qp2/qp2/qp2), std::sqrt(q3/qp2), std::sqrt(J2*J2*q3/qp2/qp2/qp2));

    const long double num = J2 - ((long double)c)*qp2;
    const long double den = q3;
    // beta has to satisfy beta * den <= num if compLowBound = true
    //                  or beta * den >= num if compLowBound = false

    if (den == 0) {
      if (compLowBound) {
        if (num >= 0) {} // ok, nothing to do
        else return;
        //TODO c'est mieux de retourner min(..)/max(..) ??
      }
      else {
        if (num <= 0) {} // ok, nothing to do
        else return;
        //TODO c'est mieux de retourner max(..)/min(..) ??
      }
    }
    else if (den > 0) {
      if (compLowBound)
        upperBound = std::min(upperBound, (double)(num/den));
      else
        lowerBound = std::max(lowerBound, (double)(num/den));
    }
    else {
      if (compLowBound)
        lowerBound = std::max(lowerBound, (double)(num/den));
      else
        upperBound = std::min(upperBound, (double)(num/den));
    }

    //Msg::Info("in [%.15g, %.15g]", lowerBound, upperBound);

    ++itJ;
    ++itP;
  }

  if (lowerBound <= upperBound) {
    if (compLowBound)
      beta = upperBound;
    else
      beta = lowerBound;
  }

  //Msg::Info("ENDING");
  //TODO sinon, c'est mieux de retourner m..(..)/m..(..) ??
}

void MetricBasis::_computeLowerBoundC(const fullMatrix<double> &coeff,
                                      const fullVector<double> &jac,
                                      double beta, double &c) const
{
  // compute a lower/upper bound of function C = K-beta*a^3

  double upperBound = std::numeric_limits<double>::infinity();
  double lowerBound = -upperBound;

  // value in case of a failure
  c = 0;

  fullVector<double> P(coeff.size1());
  for (int i = 0; i < coeff.size1(); ++i) {
    P(i) = 0;
    for (int l = 1; l < 7; ++l) {
      P(i) += coeff(i, l) * coeff(i, l);
    }
    P(i) = std::sqrt(P(i));
  }

  std::map<int, std::vector<IneqData> >::const_iterator itJ, itP;
  itJ = _ineqJ2.begin();
  itP = _ineqP3.begin();

  // _ineqJ2 and _ineqP3 have the same size
  while (itJ != _ineqJ2.end()) {
    double num = 0, den = 0;
    for (unsigned int l = 0; l < itP->second.size(); ++l) {
      const int i = itP->second[l].i;
      const int j = itP->second[l].j;
      const int k = itP->second[l].k;
      num -= itP->second[l].val * coeff(i, 0) * coeff(j, 0) * coeff(k, 0);
      den += itP->second[l].val * P(i) * P(j) * P(k);
    }

    num = num * beta;
    for (unsigned int l = 0; l < itJ->second.size(); ++l) {
      const int i = itJ->second[l].i;
      const int j = itJ->second[l].j;
      num += itJ->second[l].val * jac(i) * jac(j);
    }

    // c has to satisfy c * den <= num
    if (den == 0) {
      if (num >= 0) {
        ++itJ;
        ++itP;
        continue;
      }
      else return;
      //TODO c'est mieux de retourner min(J^2-beta q^3)/max(p^3) ?
    }
    if (den > 0)
      upperBound = std::min(upperBound, num/den);
    else {
      lowerBound = std::max(lowerBound, num/den);
    }

    ++itJ;
    ++itP;
  }

  if (lowerBound <= upperBound) {
    c = upperBound;
  }
  //TODO sinon, c'est mieux de retourner min(J^2-beta q^3)/max(p^3) ?
}

void MetricBasis::_computePseudoDerivatives(double a, double K,
                                            double &dRda, double &dRdK)
{
  // Return derivative without positive (but non-constant) coefficients
  // Useful when only the sign of dRda and dRdK or the ratio dRda/dRdK
  // are needed.

  double w = _wSafe(a, K);
  if (std::abs(w) > 1) {
    Msg::Error("Cannot compute pseudo derivatives of R "
               "outside the domain (w = %g)", w);
    return;
  }

  const double phip = (std::acos(w) + M_PI) / 3;
  const double C = 1 + a * std::cos(phip);

  dRdK = C / 3;
  dRda = 2 * std::sqrt(1-w*w) * std::sin(phip) + (1-a*a) * C;
}

void MetricBasis::_computeDerivatives(double a, double K,
                                      double &dRda, double &dRdK,
                                      double &dRdaa, double &dRdaK, double &dRdKK)
{
  const double w = _wSafe(a, K);
  if (std::abs(w) > 1) {
    Msg::Error("Cannot compute derivatives of R outside the domain");
    return;
  }

  const double phi = (std::acos(w)) / 3;
  const double phip = phi + M_PI / 3;
  const double S = 1./std::sqrt(1-w*w);
  const double A = (1-a*a)*S;
  const double sin = std::sin(phi);
  const double sinp = std::sin(phip);
  const double cosp = std::cos(phip);
  const double C = 1 + a*cosp;
  const double D = 1./(a+2*std::cos(phi));
  static const double sq3 = std::sqrt(3);
  const double coeff = sq3*D*D/18;

  dRdK = coeff*6    * (C*S);
  dRda = coeff*18   * (2*sinp + A*C);
  dRdKK = coeff*S*S * (a*sinp - 4*C*sin*D + 3*w*C*S);
  dRdaK = coeff*S*3 * (a*A*sinp + 3*w*A*C*S + 2*cosp - 4*C*(1+A*sin)*D);
  dRdaa = coeff*9   * (3*w*A*A*C*S - 4*a*C*S + a*A*A*sinp - 4*(1+A*sin)*D*(2*sinp + A*C));
}

bool MetricBasis::_moveInsideDomain(double &a, double &K, bool bottomleftCorner)
{
  // Note: For N-R (when moving 'a'), we compute the root of
  // f(a) = .5 * (K - a^3 + 3*a) - 'w' where 'w' is -1 or 1.

  double w = _w(a, K);
  if (w > 1.) {
    if (bottomleftCorner) {
      // make sure to compute the right root (a>1) and
      // avoid slopes that are too small:
      a = std::max(a, 1.1);

      const double tolerance = _tol/100;
      // Note: N-R approaches the root from the right, we
      while (w > 1 || w < 1-tolerance) {
        double df = w - 1;
        double slope = 1.5*(1-a*a);
        a -= df/slope;
        w = _w(a, K);
      }
    }
    else {
      K -= 2*w - 2;
    }
    return true;
  }
  else if (w < -1.) {
    if (bottomleftCorner) {
      K -= 2*w + 2;
    }
    else {
      a = std::max(a, 2.);

      const double tolerance = _tol/100;
      while (std::abs(w+1) > tolerance) {
        double df = w + 1;
        double slope = 1.5*(1-a*a);
        a -= df/slope;
        w = _w(a, K);
      }
    }
    return true;
  }
  return false;
}

double MetricBasis::_computeMinRAlongCurve(double beta, double c,
                                           double mina, double maxa)
{
  // Compute the minimum of R on the curve K = beta * a^3 + c
  // where beta can be zero.
  // 'mina' and 'maxa' stand for the limits of the curve. There must be at
  // least 1 limit. To indicate that 'mina' or 'maxa' is not a limit, it is
  // set to a negative value.

  bool towardsPositivea;
  double a, K, R;
  if (mina < 0) {
    a = maxa;
    K = (beta*a*a + c)*a;
    R = _R3Dsafe(a, K);
    towardsPositivea = false;
  }
  else if (maxa < 0) {
    a = mina;
    K = (beta*a*a + c)*a;
    R = _R3Dsafe(a, K);
    towardsPositivea = true;
  }
  else {
    // choose the more promising limit as starting point
    double K1 = beta*mina*mina*mina + c;
    double K2 = beta*maxa*maxa*maxa + c;
    double R1 = _R3Dsafe(mina, K1);
    double R2 = _R3Dsafe(maxa, K2);
    if (R1 < R2) {
      a = mina;
      K = K1;
      R = R1;
      towardsPositivea = true;
    }
    else {
      a = maxa;
      K = K2;
      R = R2;
      towardsPositivea = false;
    }
  }

  double da = 1, dK, dKK;
  double dRda, dRdK, dRdaa, dRdaK, dRdKK;
  double dRdC, dRdCC;

  _computeDerivatives(a, K, dRda, dRdK, dRdaa, dRdaK, dRdKK);
  dK = 3*beta*a*a+c;
  dKK = 6*beta*a;
  dRdC = dRda*da + dRdK*dK;
  dRdCC = dRdaa*da*da + 2*dRdaK*da*dK + dRdKK*dK*dK + dRdK*dKK;

  if ((towardsPositivea  && dRdC > 0) || (!towardsPositivea && dRdC < 0)) {
    Msg::Warning("Already the minimum");
    return R;
  }

  while (.25*dRdC*dRdC/dRdCC > .01*_toleranceOnR(R)) {
    a = a - dRdC / dRdCC;
    K = (beta*a*a + c)*a;
    R = _R3Dsafe(a, K);

    _computeDerivatives(a, K, dRda, dRdK, dRdaa, dRdaK, dRdKK);
    dK = 3*beta*a*a+c;
    dKK = 6*beta*a;
    dRdC = dRda*da + dRdK*dK;
    dRdCC = dRdaa*da*da + 2*dRdaK*da*dK + dRdKK*dK*dK + dRdK*dKK;
  }

  /*Msg::Warning("Checking Newton Raphson solution... (%g, %g)", a, K);
  double min = 1;
  for (double aa = std::max(1., .5*a); aa < 2*a; aa += .001*a) {
    double KK = (beta*aa*aa + c)*aa;
    double w = _wSafe(aa, KK);
    if (std::abs(w) <= 1) min = std::min(min, _R3Dsafe(aa, KK));
  }
  if (std::abs(min-R) < .01*_toleranceOnR(R))
    Msg::Info("... aaand, it is good!");
  else
    Msg::Error("... and, it's a fail! %g vs %g (tol %g => %g)", R, min, _toleranceOnR(R), R-.01*_toleranceOnR(R));*/

  return R;
}

bool MetricBasis::_intersectionCurveLeftCorner(double beta, double c,
                                               double &a, double &K)
{
  // on input, a and K are the bottom left corner
  // on output, a and K are the intersection
  //            return true if the intersection is on the vertical
  // We assume the intersection exists
  // (i.e. the bounding curve is sufficiently sharp)
  if (3*beta*a*a + c < 0) {
    Msg::Error("The slope is negative, cannot compute the intersection");
    return false;
  }

  const double minK = K;
  //const double mina = a; //TODO remove (not needed)

  K = (beta*a*a + c)*a;
  if (K >= minK) return true;

  // Find the root by Newton-Raphson
  double dK = K-minK;

  static double precision = std::numeric_limits<double>::epsilon() * 1e3;
  int n = 0;
  while (std::abs(dK) > minK * precision && ++n < 100) { //TODO meilleur approx
    const double slope = 3*beta*a*a + c;
    a -= dK / slope;
    dK = (beta*a*a + c)*a-minK;
  }
  K = minK;
  //Msg::Info("in %d it (%g, %g) -> (%g, %g) => diff(%g, %g)", k, mina, minK, a, K, a-mina, K-minK);
  return false;
}

double MetricBasis::_computeAbscissaMinR(double aStart, double K)
{
  double dRda, dRdK, dRdaa, dRdaK, dRdKK;
  _computeDerivatives(aStart, K, dRda, dRdK, dRdaa, dRdaK, dRdKK);
  double a = aStart;
  while (dRda > MetricBasis::_tol*1e-3) {
    double da = - dRda / dRdaa;
    a += da;
    _computeDerivatives(a, K, dRda, dRdK, dRdaa, dRdaK, dRdKK);
  }
  return a;
}

double MetricBasis::_R3Dsafe(double q, double p, double J)
{
  if (q >= p && p >= 0 && J == J &&
      p < std::numeric_limits<double>::infinity()) {
    if (q == 0) return 0;
    if (p == 0) return 1;
    if (q == std::numeric_limits<double>::infinity()) {
      Msg::Warning("q had infinite value in computation of 3D metric");
      return 1;
    }
    const double a = q/p;
    const double K = J*J/p/p/p;
    return _R3Dsafe(a, K);
  }
  else {
    Msg::Error("Wrong argument for 3d metric (%g, %g, %g)", q, p, J);
    return -1;
  }
}

double MetricBasis::_R3Dsafe(double a, double K)
{
  if (a >= 1 && K >= 0) {
    // TODO speedup in function of _tol ?
    // if (2/a < _tol) return 1.;
    // if (8/K < _tol*_tol*_tol) return 1.;

    if (a == std::numeric_limits<double>::infinity())
      return 1;

    const double w = _wSafe(a, K);
    if (std::abs(w) > 1-_tol/10) {
      if (w > 0) return (a - 1) / (a + 2);
      else        return (a - 2) / (a + 1);
    }

    const double phi = std::acos(w) / 3;
    const double R = (a + 2*std::cos(phi + 2*M_PI/3)) / (a + 2*std::cos(phi));
    return std::max(.0, std::min(1., R));
  }
  else {
    Msg::Error("Wrong argument for 3d metric (%g, %g)", a, K);
    return -1;
  }
}

double MetricBasis::_R2Dsafe(double q, double p)
{
  if (q >= p && p >= 0 && p < std::numeric_limits<double>::infinity()) {
    if (q == 0) return 0;
    if (q == std::numeric_limits<double>::infinity()) {
      Msg::Warning("q had infinite value in computation of 2D metric");
      return 1;
    }
    return (q-p) / (q+p);
  }
  else {
    Msg::Error("Wrong argument for 2d metric (%g, %g)", q, p);
    return -1;
  }
}

double MetricBasis::_R2Dsafe(double a)
{
  if (a >= 1) {
    if (a == std::numeric_limits<double>::infinity())
      return 1;
    return (a - 1) / (a + 1);
  }
  else {
    Msg::Error("Wrong argument for 2d metric (%g)", a);
    return -1;
  }
}

double MetricBasis::_toleranceOnR(double R)
{
  const double sqRmax = std::max(.0, std::sqrt(R) - _tol);
  return R - sqRmax*sqRmax;
}
