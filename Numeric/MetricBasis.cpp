// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "MElement.h"
#include "AnalyseCurvedMesh.h"
#include "MetricBasis.h"
#include "BasisFactory.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "OS.h"
#include <queue>
#include <sstream>
#include <limits>

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

  double symRand(double f = 1)
  {
    return f * (rand()%2001 - 1000) / 1000.;
  }
}

MetricBasis::MetricBasis(int tag) : _type(ElementType::ParentTypeFromTag(tag)),
    _dim(ElementType::DimensionFromTag(tag))
{
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
  if (_type == TYPE_TRI || _type == TYPE_QUA) {
    jacSpace = NULL;
  }
  else if (_type == TYPE_TET || _type == TYPE_HEX || _type == TYPE_PRI) {
    jacSpace = new FuncSpaceData(true, tag, jacOrder, &serendip);
  }
  else if (_type == TYPE_PYR) {
    jacSpace = new FuncSpaceData(true, tag, false, jacOrder+3,
                                 jacOrder, &serendip);
  }
  else
    Msg::Fatal("metric not implemented for element tag %d", tag);

  if (jacSpace) {
    _jacobian = BasisFactory::getJacobianBasis(*jacSpace);
    delete jacSpace;
  }
  else
    _jacobian = NULL;

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

double MetricBasis::minSampledR(MElement *el, int order)
{
  MetricBasis *metric = (MetricBasis*)BasisFactory::getMetricBasis(el->getTypeForMSH());
  return metric->getMinSampledR(el, order);
}

double MetricBasis::getMinSampledR(MElement *el, int deg) const
{
  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);

  MetricData *md;
  _getMetricData(el, md);

  fullMatrix<double> R;
  interpolate(el, md, samplingPoints, R);

  if (R.size1() < 1) return -1;

  double min = R(0, 1);
  for (int i = 1; i < R.size1(); ++i)
    min = std::min(min, R(i, 1));

  return min;
}

double MetricBasis::minSampledRnew(MElement *el, int deg)
{
  int dim = el->getDim();
  if (dim < 2) return 1;

  fullMatrix<double> nodes(el->getNumVertices(), 3);
  el->getNodesCoord(nodes);

  // if deg is small: sample at every point
  // otherwise: compute Bezier coefficients and interpolate
  //const bool BezierInterp = deg > 100;

  FuncSpaceData jacMatSpace;
  /*if (BezierInterp) {
    jacMatSpace =
        JacobianBasis::jacobianMatrixSpace(el->getType(), el->getPolynomialOrder());
  }
  else {*/
    const bool serendip = false;
    jacMatSpace = FuncSpaceData(el, deg, &serendip);
  //}

  const GradientBasis *gb = BasisFactory::getGradientBasis(jacMatSpace);
  fullMatrix<double> coeffJacMat(gb->getNumSamplingPoints(), 3*dim);
  fullMatrix<double> dxyzdX(coeffJacMat, 0, 3);
  fullMatrix<double> dxyzdY(coeffJacMat, 3, 3);
  if (dim == 2)
    gb->getIdealGradientsFromNodes(nodes, &dxyzdX, &dxyzdY, NULL);
  else {
    fullMatrix<double> dxyzdZ(coeffJacMat, 6, 3);
    gb->getIdealGradientsFromNodes(nodes, &dxyzdX, &dxyzdY, &dxyzdZ);
  }

  /*if (BezierInterp) {
    const bezierBasis *bb = BasisFactory::getBezierBasis(jacMatSpace);
    fullMatrix<double> points;
    const bool serendip = false;
    gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), points);

    fullMatrix<double> bezCoeffJacMat;
    bb->lag2Bez(coeffJacMat, bezCoeffJacMat);
    bb->interpolate(bezCoeffJacMat, points, coeffJacMat);
  }*/

  double minR = 1;
  for (int k = 0; k < coeffJacMat.size1(); ++k) {
    fullMatrix<double> metric(dim, dim);
    for (int i = 0; i < dim; ++i) {
      for (int j = i; j < dim; ++j) {
        for (int n = 0; n < 3; ++n)
          metric(i, j) += coeffJacMat(k, 3*i+n) * coeffJacMat(k, 3*j+n);
      }
    }
    metric(1, 0) = metric(0, 1);
    if (dim == 3) {
      metric(2, 0) = metric(0, 2);
      metric(2, 1) = metric(1, 2);
    }
    fullVector<double> valReal(dim), valImag(dim);
    fullMatrix<double> vecLeft(dim, dim), vecRight(dim, dim);
    metric.eig(valReal, valImag, vecLeft, vecRight, true);
    minR = std::min(minR, std::sqrt(valReal(0) / valReal(dim-1)));
  }

  return minR;
}

double MetricBasis::getBoundMinR(MElement *el) const
{
  int nSampPnts = _gradients->getNumSamplingPoints();
  int nMapping = _gradients->getNumMapNodes();

  // Nodes
  fullMatrix<double> nodes(nMapping, 3);
  el->getNodesCoord(nodes);

  // Jacobian coefficients
  fullVector<double> jacLag(_jacobian->getNumJacNodes());
  fullVector<double> *jac = new fullVector<double>(_jacobian->getNumJacNodes());
  _jacobian->getSignedIdealJacobian(nodes, jacLag);
  _jacobian->lag2Bez(jacLag, *jac);

  // Metric coefficients
  fullMatrix<double> metCoeffLag;
  _fillCoeff<true>(el->getDim(), _gradients, nodes, metCoeffLag);
  fullMatrix<double> *metCoeff;
  metCoeff = new fullMatrix<double>(nSampPnts, metCoeffLag.size2());
  _bezier->matrixLag2Bez.mult(metCoeffLag, *metCoeff);

  // Compute min(R, _tol)
  double RminLag, RminBez;
  _computeRmin(*metCoeff, *jac, RminLag, RminBez);

  if (RminLag-RminBez < MetricBasis::_tol) {
    delete jac;
    delete metCoeff;
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
        if (j == k && j != i)
          _ineqP3[hash].push_back(IneqData(num/den, k, j, i));
        else
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
        if (j == k && j != i)
          _ineqP3[hash].push_back(IneqData(num/den, k, j, i));
        else
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
  Msg::Info("Testing Bezier interpolation and subdivision "
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

      const MetricBasis *metricBasis = BasisFactory::getMetricBasis(tag);

      // compare the two metric

      fullMatrix<double> metric_Bez(numSampPnt, 2);
      fullVector<int> isub(numSubdiv);
      fullMatrix<double> uvw(numSampPnt, 3);
      metricBasis->interpolateAfterNSubdivisions(el, numSubdiv, numSampPnt,
                                                 isub, uvw, metric_Bez);

      /*{
        static int deg = 2;
        MetricBasis::minSampledR(el, deg);
        MetricBasis::minSampledRnew(el, deg);

        double time = Cpu();
        double minR1;
        for (int cn = 0; cn < 100; ++cn)
          minR1 = MetricBasis::minSampledR(el, deg);
        double tm1 = Cpu()-time;

        time = Cpu();
        double minR2;
        for (int cn = 0; cn < 100; ++cn)
          minR2 = MetricBasis::minSampledRnew(el, deg);
        double tm2 = Cpu()-time;

        if (std::abs(minR1-minR2) < 1e-14)
          Msg::Info("ok deg %d, times %g %g speedup %g", deg, tm1, tm2, tm1/tm2);
        else
          Msg::Error("not ok deg %d: %g vs %g, times %g %g speedup %g", deg, minR1, minR2, tm1, tm2, tm1/tm2);
        //++deg;
      }*/

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
        ++numError;
        Msg::Error("Too much errors "
            "even when computing by metric tensor (max %g)", maxBadMatchTensor);
      }
      else if (numBadMatch > .5*numSampPnt) {
        ++numError;
        Msg::Error("Too much errors (max %g)", maxBadMatch);
      }
    }
  }

  if (numError) Msg::Error("Validation of Bezier terminated with %d errors!", numError);
  else Msg::Info("Validation of Bezier terminated without errors");
  return numError;
}

void MetricBasis::interpolate(const MElement *el,
                              const MetricData *md,
                              const fullMatrix<double> &nodes,
                              fullMatrix<double> &R) const
{
  fullMatrix<double> &metcoeffs = *md->_metcoeffs, *metric = new fullMatrix<double>;
  fullVector<double> &jaccoeffs = *md->_jaccoeffs, *jac = new fullVector<double>;

  _bezier->interpolate(metcoeffs, nodes, *metric);

  R.resize(nodes.size1(), 2);

  switch (metcoeffs.size2()) {
  case 1:
    for (int i = 0; i < R.size1(); ++i)
      R(i, 0) = R(i, 1) = 1;
    break;

  case 3:
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
      }
    break;

  case 7:
    _jacobian->getBezier()->interpolate(jaccoeffs, nodes, *jac);
    for (int i = 0; i < R.size1(); ++i) {
      // Compute from q, p, J
      double p = 0;
      for (int k = 1; k < 7; ++k) p += pow((*metric)(i, k), 2);
      p = std::sqrt(p);
      R(i, 0) = std::sqrt(_R3Dsafe((*metric)(i, 0), p, (*jac)(i)));
      // Comppute from tensor
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
  const int numJacPnts = md->_jaccoeffs ? md->_jaccoeffs->size() : 0;
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
    sin = std::sqrt(3.) / 2;
    sqrt = 0;
  }
  else if (x0 < -1) {
    K = -2 + a*a*a - 3*a;

    x0 = -1;
    phip = 2 * M_PI / 3;
    term1 = 1 - .5 * a;
    sin = std::sqrt(3.) / 2;
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
        double dzdX, dzdY;
        if (nodes.size2() > 2) {
          dzdX = dxydX(i,2);
          dzdY = dxydY(i,2);
        }
        else {
          dzdX = 0;
          dzdY = 0;
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

      const double q = coeff(i, 0);
      double p = 0;
      for (int k = 1; k < 7; ++k) {
        p += pow_int(coeff(i, k), 2);
      }
      p = std::sqrt(p);
      const double a = q/p;
      if (a > 1e4) { // TODO: from _tol ?
        Rmin = std::min(Rmin, std::sqrt((a - std::sqrt(3.)) / (a + std::sqrt(3.))));
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

      const double &q = coeff(i, 0);
      const double p = pow_int(coeff(i, 1), 2) + pow_int(coeff(i, 2), 2);
      const double tmpR = _R2Dsafe(q, std::sqrt(p));
      Rmin = std::min(Rmin, std::sqrt(tmpR));
    }
    return Rmin;

  default:
    Msg::Error("coeff have not right number of column");
    return -1;
  }
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
    r(i) = std::sqrt(r(i));
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
    P(i) = std::sqrt(P(i));
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
    P(i) = std::sqrt(P(i));
    for (int j = 0; j < coeff.size1(); ++j) {
      Q(i, j) = 0;
      for (int l = 1; l < 7; ++l) {
        Q(i, j) += coeff(i, l) * coeff(j, l);
      }
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
    r(i) = std::sqrt(r(i));
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
    P(i) = std::sqrt(P(i));
    for (int j = 0; j < coeff.size1(); ++j) {
      Q(i, j) = 0;
      for (int l = 1; l < 7; ++l) {
        Q(i, j) += coeff(i, l) * coeff(j, l);
      }
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

double MetricBasis::_R3Dsafe(double q, double p, double J)
{
  if (q > 1e5*p) {
    const double m = p*std::sqrt(3.)/q;
    return (1-m) / (1+m);
  }
  const double a = q/p;
  const double K = J*J/p/p/p;
  return _R3Dsafe(a, K);
}

double MetricBasis::_R3Dsafe(double a, double K)
{
  const double x = .5 * (K + (3 - a*a)*a);
  if (x > 1+1e-7 || x < -1-1e-7) {
    Msg::Warning("x = %g (a,K) = (%g,%g)", x, a, K);
  }

  double ans;
  if (x >= 1)       ans = (a - 1) / (a + 2);
  else if (x <= -1) ans = (a - 2) / (a + 1);
  else {
    const double phi = std::acos(x) / 3;
    ans = (a + 2*std::cos(phi + 2*M_PI/3)) / (a + 2*std::cos(phi));
  }

  if (ans < 0 || ans > 1) {
    if (ans < 0) return 0;
    else return 1;
  }
  return ans;
}

double MetricBasis::_R2Dsafe(double q, double p)
{
  if (q < 0 || p < 0 || p > q)
    Msg::Error("wrong argument for 2d metric (%g, %g)", q, p);
  return (q-p) / (q+p);
}

double MetricBasis::_R2Dsafe(double a)
{
  if (a < 1
#if !defined(_MSC_VER)
      || !std::isfinite(a)
#endif
      )
    Msg::Error("wrong argument for 2d metric (%g)", a);
  return (a - 1) / (a + 1);
}
