// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include <limits>
#include "qualityMeasuresJacobian.h"
#include "MElement.h"
#include "BasisFactory.h"
#include "bezierBasis.h"
#include "JacobianBasis.h"

// For debugging
#include <sstream>
#include <iomanip>
#include "pointsGenerators.h"
#include "OS.h"
#define TMBEG(n, what) static int I##n = 0, IND##n = _CoeffDataAnisotropy::mytimes.size(); \
if (++I##n == 1) { \
  Msg::Info("Time%d = "#what, IND##n); \
  _CoeffDataAnisotropy::mytimes.push_back(0); \
  _CoeffDataAnisotropy::mynumbers.push_back(0); \
} \
_CoeffDataAnisotropy::mynumbers[IND##n] += 1; \
double TM##n = Cpu();
#define TMEND(n) _CoeffDataAnisotropy::mytimes[IND##n] += Cpu() - TM##n;

namespace jacobianBasedQuality {

bool _CoeffDataAnisotropy::hasError = false;
std::fstream _CoeffDataAnisotropy::file;
std::vector<double> _CoeffDataAnisotropy::mytimes;
std::vector<int> _CoeffDataAnisotropy::mynumbers;

void minMaxJacobianDeterminant(MElement *el, double &min, double &max)
{
  const JacobianBasis *jfs = el->getJacobianFuncSpace();
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el->getTypeForMSH());
    return;
  }

  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  fullVector<double> coeffLag(jfs->getNumJacNodes());
  fullVector<double> coeffBez(jfs->getNumJacNodes());
  jfs->getSignedJacobian(nodesXYZ, coeffLag);
  jfs->lag2Bez(coeffLag, coeffBez);

  std::vector<_CoeffData*> domains;
  domains.push_back(new _CoeffDataJac(coeffBez, jfs->getBezier(), 0));

  _subdivideDomains(domains);

  min = domains[0]->minB();
  max = domains[0]->maxB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    max = std::max(max, domains[i]->maxB());
    delete domains[i];
  }
}

double minScaledJacobian(MElement *el)
{
  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const JacobianBasis *jfs;
  const GradientBasis *gfs;

  fullVector<double> coeffDetBez;
  {
    const int jacOrder = el->getPolynomialOrder() * el->getDim();
    jfs = el->getJacobianFuncSpace(jacOrder);
    if (!jfs) {
      Msg::Error("Jacobian function space not implemented for type of element %d", el->getTypeForMSH());
      return -99;
    }
    coeffDetBez.resize(jfs->getNumJacNodes());
    fullVector<double> coeffDetLag(jfs->getNumJacNodes());

    jfs->getSignedJacobian(nodesXYZ, coeffDetLag);
    jfs->lag2Bez(coeffDetLag, coeffDetBez);
  }

  fullMatrix<double> coeffMatBez;
  {
    gfs = BasisFactory::getGradientBasis(el->getTypeForMSH());
    coeffMatBez.resize(gfs->getNumSamplingPoints(), 9);
    fullMatrix<double> coeffMatLag(gfs->getNumSamplingPoints(), 9);

    gfs->getAllGradientsFromNodes(nodesXYZ, coeffMatLag);
    gfs->lag2Bez(coeffMatLag, coeffMatBez);
    if (el->getDim() == 2) coeffMatBez.resize(coeffMatBez.size1(), 6);
  }

  std::vector<_CoeffData*> domains;
  domains.push_back(
      new _CoeffDataScaledJac(coeffDetBez, coeffMatBez, jfs->getBezier(),
                              gfs->getBezier(), 0)
  );

  _subdivideDomains(domains);

  double min = domains[0]->minB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    delete domains[i];
  }
  return min;
}

double minAnisotropyMeasure(MElement *el, int n)
{
  if (_CoeffDataAnisotropy::noMoreComputationPlease()) return -9;

//  double minSampled = minSampledAnisotropyMeasure(el, n);

//  double values[3];
//  Msg::Info("R %g", el->getEigenvaluesMetric(-1,-1,-1,values));
//  Msg::Info("R %g", el->getEigenvaluesMetric(-1,1,1,values));

  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const int type = el->getType();
  const bool serendipFalse = false;

  const GradientBasis *gradBasis;
  const JacobianBasis *jacBasis = NULL;

  // Metric Coefficients
  fullMatrix<double> coeffMetricBez;
  const int metricOrder = _CoeffDataAnisotropy::metricOrder(el);
  {
    FuncSpaceData *metricSpace = NULL;
    if (type != TYPE_PYR)
      metricSpace = new FuncSpaceData(el, metricOrder, &serendipFalse);
    else
      metricSpace = new FuncSpaceData(el, false, metricOrder+2,
                                      metricOrder, &serendipFalse);
    gradBasis = BasisFactory::getGradientBasis(*metricSpace);
    delete metricSpace;

    fullMatrix<double> coeffMetricLag;
    _CoeffDataAnisotropy::fillMetricCoeff(gradBasis, nodesXYZ, coeffMetricLag,
                                          el->getDim(), true);

    coeffMetricBez.resize(coeffMetricLag.size1(), coeffMetricLag.size2());
    gradBasis->lag2Bez(coeffMetricLag, coeffMetricBez);
  }

  // Jacobian determinant coefficients
  fullVector<double> coeffJacDetBez;
  {
    const int jacDetOrder = 3*metricOrder/2;
    FuncSpaceData *jacDetSpace = NULL;
    if (type == TYPE_TET || type == TYPE_HEX || type == TYPE_PRI)
      jacDetSpace = new FuncSpaceData(el, jacDetOrder, &serendipFalse);
    else if (type == TYPE_PYR)
      // The square of the jacobian space must be the same
      // space than the cube of the metric, so +3
      jacDetSpace = new FuncSpaceData(el, false, jacDetOrder+3,
                                      jacDetOrder, &serendipFalse);
    else if (type == TYPE_TRI || type == TYPE_QUA) {} //jacobian not needed
    else {
      Msg::Error("metric not implemented for element tag %d", el->getTypeForMSH());
      return -1;
    }
    if (jacDetSpace) {
      jacBasis = BasisFactory::getJacobianBasis(*jacDetSpace);
      delete jacDetSpace;

      fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
      jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

      coeffJacDetBez.resize(jacBasis->getNumJacNodes());
      jacBasis->lag2Bez(coeffDetLag, coeffJacDetBez);
    }
  }

  //
//  TMBEG(0, _CoeffDataAnisotropy)
  std::vector<_CoeffData*> domains;
  domains.push_back(
      new _CoeffDataAnisotropy(coeffJacDetBez, coeffMetricBez,
                               jacBasis ? jacBasis->getBezier() : NULL,
                               gradBasis->getBezier(), 0, el)
  );
//  TMEND(0)

  static int i = 0;
  ++i;
  _subdivideDomains(domains);
  if (domains.size()/7+1 > 20) {
    Msg::Info("%d: %d", el->getNum(), domains.size()/7+1);
  }

  double min = domains[0]->minB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    delete domains[i];
  }

//  if (min - minSampled > 1e-13) {
//    Msg::Error("no, works no el %d (%g vs %g, diff %g)", el->getNum(), min, minSampled, min-minSampled);
//  }

  return min;
}

double minSampledAnisotropyMeasure(MElement *el, int deg, bool writeInFile)
{
  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);

  double values[3];
  double min = std::numeric_limits<double>::infinity();
  for (int i = 0; i < samplingPoints.size1(); ++i) {
    min = std::min(min, el->getEigenvaluesMetric(samplingPoints(i, 0),
                                                 samplingPoints(i, 1),
                                                 samplingPoints(i, 2),
                                                 values));
  }

  return min;
}

// Virtual class _CoeffData
bool _lessMinB::operator()(_CoeffData *cd1, _CoeffData *cd2) const
{
  return cd1->minB() > cd2->minB();
}

bool _lessMaxB::operator()(_CoeffData *cd1, _CoeffData *cd2) const
{
  return cd1->maxB() < cd2->maxB();
}

// Jacobian determinant (for validity of all elements)
_CoeffDataJac::_CoeffDataJac(fullVector<double> &v,
                           const bezierBasis *bfs,
                           int depth)
: _CoeffData(depth), _coeffs(v.getDataPtr(), v.size()), _bfs(bfs)
{
  if (!v.getOwnData()) {
    Msg::Fatal("Cannot create an instance of _CoeffDataJac from a "
               "fullVector that does not own its data.");
  }
  // _coeffs reuses the data of v, this avoid to allocate a new array and to
  // copy data that are not used outside of this object.
  // It remains to swap ownership:
  v.setOwnData(false);
  const_cast<fullVector<double>&>(_coeffs).setOwnData(true);

  _minL = _maxL = v(0);
  int i = 1;
  for (; i < bfs->getNumLagCoeff(); i++) {
    _minL = std::min(_minL, v(i));
    _maxL = std::max(_maxL, v(i));
  }
  _minB = _minL;
  _maxB = _maxL;
  for (; i < v.size(); i++) {
    _minB = std::min(_minB, v(i));
    _maxB = std::max(_maxB, v(i));
  }
}

bool _CoeffDataJac::boundsOk(double minL, double maxL) const
{
  double tol = std::max(std::abs(minL), std::abs(maxL)) * 1e-3;
  return (minL <= 0 || _minB > 0) &&
         minL - _minB < tol &&
         _maxB - maxL < tol;
}

void _CoeffDataJac::getSubCoeff(std::vector<_CoeffData*> &v) const
{
  v.clear();
  v.reserve(_bfs->getNumDivision());
  fullVector<double> subCoeff;
  _bfs->subdivideBezCoeff(_coeffs, subCoeff);

  int sz = _coeffs.size();
  for (int i = 0; i < _bfs->getNumDivision(); i++) {
    fullVector<double> coeff(sz);
    coeff.copy(subCoeff, i * sz, sz, 0);
    _CoeffDataJac *newData = new _CoeffDataJac(coeff, _bfs, _depth+1);
    v.push_back(newData);
  }
}

// Scaled Jacobian (quality of quads and hexes)
_CoeffDataScaledJac::_CoeffDataScaledJac(fullVector<double> &det,
                                         fullMatrix<double> &mat,
                                         const bezierBasis *bfsDet,
                                         const bezierBasis *bfsMat,
                                         int depth)
: _CoeffData(depth), _coeffsJacDet(det.getDataPtr(), det.size()),
  _coeffsJacMat(mat.getDataPtr(), mat.size1(), mat.size2()),
  _bfsDet(bfsDet), _bfsMat(bfsMat)
{
  if (!det.getOwnData() || !mat.getOwnData()) {
    Msg::Fatal("Cannot create an instance of _CoeffDataScaledJac from a "
               "fullVector or a fullMatrix that does not own its data.");
  }
  // _coeffsJacDet and _coeffsJacMat reuse data, this avoid to allocate new
  // arrays and to copy data that are not used outside of this object.
  // It remains to swap ownerships:
  det.setOwnData(false);
  mat.setOwnData(false);
  const_cast<fullVector<double>&>(_coeffsJacDet).setOwnData(true);
  const_cast<fullMatrix<double>&>(_coeffsJacMat).setOwnData(true);

  _computeAtCorner(_minL, _maxL);
  _minB = _computeLowerBound();
  // computation of _maxB not implemented for now
}

void _CoeffDataScaledJac::_computeAtCorner(double &min, double &max) const
{
  min = std::numeric_limits<double>::infinity();
  max = -min;

  for (int i = 0; i < _bfsDet->getNumLagCoeff(); i++) {
    double den = 1;
    for (int j = 0; j < _coeffsJacMat.size2()/3; ++j) {
      den *= std::sqrt(_coeffsJacMat(0+3*j, i) * _coeffsJacMat(0+3*j, i)+
                       _coeffsJacMat(1+3*j, i) * _coeffsJacMat(1+3*j, i)+
                       _coeffsJacMat(2+3*j, i) * _coeffsJacMat(2+3*j, i));
    }
    min = std::min(min, _coeffsJacDet(i) / den);
    max = std::max(max, _coeffsJacDet(i) / den);
  }
}

double _CoeffDataScaledJac::_computeLowerBound() const
{
  fullVector<double> coeffDenominator;
  {
    fullVector<double> v[3];
    for (int i = 0; i < _coeffsJacMat.size2()/3; ++i) {
      v[i].resize(_coeffsJacMat.size1());
      for (int j = 0; j < _coeffsJacMat.size1(); ++j) {
        v[i](j) = std::sqrt(_coeffsJacMat(j, 0+3*i) * _coeffsJacMat(j, 0+3*i)+
                            _coeffsJacMat(j, 1+3*i) * _coeffsJacMat(j, 1+3*i)+
                            _coeffsJacMat(j, 2+3*i) * _coeffsJacMat(j, 2+3*i));
      }
    }
    if (_coeffsJacMat.size2()/3 == 3) {
      _bfsMat->getRaiser()->computeCoeff(v[0], v[1], v[2], coeffDenominator);
    }
    else {
      _bfsMat->getRaiser()->computeCoeff(v[0], v[1], coeffDenominator);
    }
  }

  return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
}

bool _CoeffDataScaledJac::boundsOk(double minL, double maxL) const
{
  static double tol = 1e-3;
  return minL - _minB < tol;
}

void _CoeffDataScaledJac::getSubCoeff(std::vector<_CoeffData*> &v) const
{
  v.clear();
  v.reserve(_bfsDet->getNumDivision());
  fullVector<double> subCoeffD;
  fullMatrix<double> subCoeffM;
  _bfsDet->subdivideBezCoeff(_coeffsJacDet, subCoeffD);
  _bfsMat->subdivideBezCoeff(_coeffsJacMat, subCoeffM);

  int szD = _coeffsJacDet.size();
  int szM1 = _coeffsJacMat.size1();
  int szM2 = _coeffsJacMat.size2();
  for (int i = 0; i < _bfsDet->getNumDivision(); i++) {
    fullVector<double> coeffD(szD);
    fullMatrix<double> coeffM(szM1, szM2);
    coeffD.copy(subCoeffD, i * szD, szD, 0);
    coeffM.copy(subCoeffM, i * szM1, szM1, 0, szM2, 0, 0);
    _CoeffDataScaledJac *newData;
    newData = new _CoeffDataScaledJac(coeffD, coeffM, _bfsDet, _bfsMat, _depth+1);
    v.push_back(newData);
  }
}

// Anisotropy measure
_CoeffDataAnisotropy::_CoeffDataAnisotropy(fullVector<double> &det,
                                           fullMatrix<double> &metric,
                                           const bezierBasis *bfsDet,
                                           const bezierBasis *bfsMet,
                                           int depth,
                                           MElement *el,
                                           int num)
: _CoeffData(depth), _coeffsJacDet(det.getDataPtr(), det.size()),
  _coeffsMetric(metric.getDataPtr(), metric.size1(), metric.size2()),
  _bfsDet(bfsDet), _bfsMet(bfsMet), _elForDebug(el), _numForDebug(num)
{
//  Msg::Info("new");
  if (!det.getOwnData() || !metric.getOwnData()) {
    Msg::Fatal("Cannot create an instance of _CoeffDataScaledJac from a "
               "fullVector or a fullMatrix that does not own its data.");
  }
  // _coeffsJacDet and _coeffsMetric reuse data, this avoid to allocate new
  // arrays and to copy data that are not used outside of this object.
  // It remains to swap ownerships:
  det.setOwnData(false);
  metric.setOwnData(false);
  const_cast<fullVector<double>&>(_coeffsJacDet).setOwnData(true);
  const_cast<fullMatrix<double>&>(_coeffsMetric).setOwnData(true);

  _computeAtCorner(_minL, _maxL);;

//  TMBEG(0, _computeLowerBound)
  if (_minL < 1e-3) _minB = 0;
  else _minB = _computeLowerBound();
//  TMEND(0)
  // computation of _maxB not implemented for now
  //statsForMatlab(_elForDebug, _numForDebug);
}

void _CoeffDataAnisotropy::_computeAtCorner(double &min, double &max) const
{
  min = std::numeric_limits<double>::infinity();
  max = -min;

  for (int i = 0; i < _bfsDet->getNumLagCoeff(); i++) {
    const double &q = _coeffsMetric(i, 0);
    double p = 0;
    for (int k = 1; k < _coeffsMetric.size2(); ++k) {
      p += pow_int(_coeffsMetric(i, k), 2);
    }
    p = std::sqrt(p);
    double qualSqrd;
//      Msg::Info("qpJ: (%g, %g, %g) => aK: (%g, %g)", q, p, _coeffsJacDet(i), q/p, _coeffsJacDet(i)*_coeffsJacDet(i)/p/p/p);
    if (_coeffsMetric.size2() == 3)
      qualSqrd = _R2Dsafe(q, p);
    else {
      qualSqrd = _R3Dsafe(q, p, _coeffsJacDet(i));
//      Msg::Info("qpJ:  (%g, %g, %g) => aK: (%g, %g) => R = %g", q, p, _coeffsJacDet(i), q/p, _coeffsJacDet(i)*_coeffsJacDet(i)/p/p/p, std::sqrt(_R3Dsafe(q, p, _coeffsJacDet(i))));
//      Msg::Info("(q^2, p^2) = (%g, %g)", q*q, p*p);
    }
    min = std::min(min, qualSqrd);
    max = std::max(max, qualSqrd);
  }
  min = std::sqrt(min);
  max = std::sqrt(max);
}

double _CoeffDataAnisotropy::_computeLowerBound() const
{
  // 2D element
  if (_coeffsMetric.size2() == 3) {
    double mina = _computeLowerBoundA();
    return std::sqrt(_R2Dsafe(mina));
  }

  // 3D element
//  TMBEG(0, _computeLowerBoundA)
  double mina = _computeLowerBoundA();
//  TMEND(0)
//  TMBEG(1, _computeLowerBoundK)
  double minK = _computeLowerBoundK();
//  TMEND(1)

//  TMBEG(2, _moveInsideDomain)
  _moveInsideDomain(mina, minK, true);
//  TMEND(2)

  double p_dRda, p_dRdK;
//  TMBEG(3, _computePseudoDerivatives)
  _computePseudoDerivatives(mina, minK, p_dRda, p_dRdK);
//  TMEND(3)

  if (p_dRda < 0) {
    // cases 1 & 2 => compute a lower bounding curve K = beta * a^3 + c * a
    // with c such that the curve that passes through (minK, mina) has the
    // slope equal to -dRda/dRdK
    double slope = -p_dRda/p_dRdK;
    double gamma = .5*(3*minK/mina - slope);
    double beta;

//    TMBEG(4, 12_computeBoundingCurve)
    _computeBoundingCurve(beta, gamma, true);
//    TMEND(4)
    /*{
      double beta = (minK/mina-c)/mina/mina;
      if (std::abs(p_dRda + p_dRdK * (3*beta*mina*mina+c)) > 1e-12) {
        Msg::Error("Derivative along curve not zero %g", p_dRda + p_dRdK * (3*beta*mina*mina+c));
      }
    }*/

    double a_int = mina, K_int = minK;
    if (_intersectionCurveLeftCorner(beta, gamma, a_int, K_int)) {
      // the minimum is on the curve, long to compute, we return this for now:
      return std::sqrt(_R3Dsafe(mina, minK));
    }

    // Let a0 be the point at which R(a, minK) takes its minimum. If a_int < a0,
    // the minimum is at (a_int, minK), otherwise it is at (a0, minK).
    bool minIsAta0;
    if (_moveInsideDomain(a_int, K_int, false)) {
      minIsAta0 = true;
    }
    else {
      double p_dRda, p_dRdK;
      _computePseudoDerivatives(a_int, K_int, p_dRda, p_dRdK);
      /*if (p_dRda + p_dRdK * (3*beta*a_int*a_int+c) < -1e-5) {
        Msg::Error("Derivative along curve not positive or zero %g", p_dRda + p_dRdK * (3*beta*a_int*a_int+c));
        Msg::Info("(%g, %g) vs (%g, %g), diff (%g, %g)", mina, minK, a_int, K_int, a_int-mina, K_int-minK);
        double beta2 = (minK/mina-c)/mina/mina;
        Msg::Info("beta %g - %g = %g", beta, beta2, beta-beta2);
      }*/
      minIsAta0 = p_dRda > 0;
    }

    if (minIsAta0) {
      double a0 = _computeAbscissaMinR(mina, minK);
      return std::sqrt(_R3Dsafe(a0, minK));
    }
    else {
      return std::sqrt(_R3Dsafe(a_int, K_int));
    }
  }
  else if (p_dRdK < 0) {
    // cases 4 & 5 => compute an upper bounding curve K = beta * a^3 + c * a
    // with c such that the curve that passes through (minK, mina) has the
    // slope equal to -dRda/dRdK
    double slope = -p_dRda/p_dRdK;
    double gamma = .5*(3*minK/mina - slope);
    double beta;
//    TMBEG(5, 45_computeBoundingCurve)
    _computeBoundingCurve(beta, gamma, false);
//    TMEND(5)

    double a_int = mina, K_int = minK;
    if (_intersectionCurveLeftCorner(beta, gamma, a_int, K_int)) {
      // Let K0 be the point at which R(mina, K) takes its minimum.
      // If K_int < K0, the minimum is at (mina, K_int),
      // otherwise it is at (mina, K0).
      double K0 = 2*std::cos(3*std::acos(-1/mina)-M_PI) + (mina*mina-3) * mina;
      return std::sqrt(_R3Dsafe(mina, std::min(K0, K_int)));
    }
    else {
      // the minimum is on the curve, long to compute, we return this for now:
      return std::sqrt(_R3Dsafe(mina, minK));
      /*if (_moveInsideDomain(a_int, K_int, false))
        return std::sqrt(_R3Dsafe(a_int, K_int));
      else
        // the minimum is on the curve, long to compute, we return this for now:
        return std::sqrt(_R3Dsafe(mina, minK));
        //return std::sqrt(_computeMinRAlongCurve(beta, c, a_int, -1));*/
    }
  }
  else {
    return std::sqrt(_R3Dsafe(mina, minK));
  }
}

double _CoeffDataAnisotropy::_computeLowerBoundA() const
{
  fullVector<double> coeffNumerator;
  {
    fullVector<double> coeffq(_coeffsMetric.size1());
    for (int i = 0; i < coeffq.size(); ++i) {
      coeffq(i) = _coeffsMetric(i, 0);
    }
    _bfsMet->getRaiser()->computeCoeff(coeffq, coeffq, coeffNumerator);
  }

  fullVector<double> coeffDenominator;
  {
    fullMatrix<double> prox, terms;
    prox.setAsProxy(_coeffsMetric, 1, _coeffsMetric.size2()-1);
    _bfsMet->getRaiser()->computeCoeff(prox, prox, terms);
    coeffDenominator.resize(terms.size1(), true);
    for (int i = 0; i < terms.size1(); ++i) {
      for (int j = 0; j < terms.size2(); ++j) {
        coeffDenominator(i) += terms(i, j);
      }
    }
  }

  double bound = _computeBoundRational(coeffNumerator, coeffDenominator, true);
  return bound > 1 ? std::sqrt(bound) : 1;
}

double _CoeffDataAnisotropy::_computeLowerBoundK() const
{
  fullVector<double> coeffNumerator;
  _bfsDet->getRaiser()->computeCoeff(_coeffsJacDet,
                                     _coeffsJacDet,
                                     coeffNumerator);

  fullVector<double> coeffDenominator;
  {
    fullVector<double> P(_coeffsMetric.size1());
    // element of P are automatically set to 0
    for (int i = 0; i < _coeffsMetric.size1(); ++i) {
      for (int l = 1; l < 7; ++l) {
        P(i) += _coeffsMetric(i, l) * _coeffsMetric(i, l);
      }
      P(i) = std::sqrt(P(i));
    }
    _bfsMet->getRaiser()->computeCoeff(P, P, P, coeffDenominator);
  }

  return _computeBoundRational(coeffNumerator, coeffDenominator, true);
}

void _CoeffDataAnisotropy::_computeBoundingCurve(double &beta, double gamma,
                                                 bool compLowBound) const
{
  // compute a lower/upper bounding curve K = beta * a^3 + c * a
  // with c fixed.

//  TMBEG(1, num)
//  TMBEG(11, J2)
  fullVector<double> J2;
  _bfsDet->getRaiser()->computeCoeff(_coeffsJacDet, _coeffsJacDet, J2);
//  TMEND(11)

//  TMBEG(12, q)
  fullVector<double> q(_coeffsMetric.size1());
  for (int i = 0; i < q.size(); ++i) {
    q(i) = _coeffsMetric(i, 0);
  }
//  TMEND(12)

//  TMBEG(13, qp2)
  fullVector<double> qp2;
  {
//    TMBEG(131, qp2A)
    fullMatrix<double> terms_p, terms_qp2;
    terms_p.setAsProxy(_coeffsMetric, 1, _coeffsMetric.size2()-1);
    _bfsMet->getRaiser()->computeCoeff(q, terms_p, terms_p, terms_qp2);
//    TMEND(131)
//    TMBEG(132, qp2B)
    qp2.resize(terms_qp2.size1(), true);
    for (int i = 0; i < terms_qp2.size1(); ++i) {
      for (int j = 0; j < terms_qp2.size2(); ++j) {
        qp2(i) += terms_qp2(i, j);
      }
    }
//    TMEND(132)
  }
//  TMEND(13)

//  TMBEG(14, J2-gqp2)
  fullVector<double> &coeffNumerator = J2;
  coeffNumerator.axpy(qp2, -gamma);
//  TMEND(14)
//  TMEND(1)

//  TMBEG(2, den)
  fullVector<double> coeffDenominator;
  _bfsMet->getRaiser()->computeCoeff(q, q, q, coeffDenominator);
//  TMEND(2)

//  TMBEG(3, _computeBoundRationalBoundingCurve)
  beta = _computeBoundRational(coeffNumerator, coeffDenominator, compLowBound);
//  TMEND(3)
}

void _CoeffDataAnisotropy::fillMetricCoeff(const GradientBasis *gradients,
                                           const fullMatrix<double> &nodes,
                                           fullMatrix<double> &coeff,
                                           int dim, bool ideal)
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
      fullMatrix<double> dxydX(nSampPnts,3);
      fullMatrix<double> dxydY(nSampPnts,3);
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
      fullMatrix<double> dxyzdX(nSampPnts,3);
      fullMatrix<double> dxyzdY(nSampPnts,3);
      fullMatrix<double> dxyzdZ(nSampPnts,3);
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

bool _CoeffDataAnisotropy::_moveInsideDomain(double &a,
                                             double &K,
                                             bool bottomleftCorner)
{
  // - bottomleftCorner: if false, then it is a top left or a bottom right corner
  //                     (it is the same treatment)
  // - Return true if the point has been moved, false otherwise

  // NB: When moving 'a', we use N-R to compute the root of
  // f(a) = .5 * (K - a^3 + 3*a) - 'w' where 'w' is -1 or 1.

  double w = _w(a, K);
  if (std::abs(w) <= 1) return false;

  const double tolerance = 1e-5;

  if (w > 1) {
    if (bottomleftCorner) {
      // make sure to compute the right root (a>1) and
      // avoid slopes that are too small:
      a = std::max(a, 1.1);

      // N-R approaches the root from the right, we can impose w > 1
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
  }
  else {
    if (bottomleftCorner) {
      K -= 2*w + 2;
    }
    else {
      // make sure to compute the right root (a>2)
      a = std::max(a, 2.);

      while (std::abs(w+1) > tolerance) {
        double df = w + 1;
        double slope = 1.5*(1-a*a);
        a -= df/slope;
        w = _w(a, K);
      }
    }
  }
  return true;
}

bool _CoeffDataAnisotropy::_computePseudoDerivatives(double a, double K,
                                                     double &dRda, double &dRdK)
{
  // Return derivative without the positive (but non-constant) coefficient
  // Useful when only the sign of dRda and dRdK or the ratio dRda/dRdK
  // are needed.

  double w = _wSafe(a, K);
  if (std::abs(w) > 1) {
    Msg::Error("Cannot compute pseudo derivatives of R "
               "outside the domain (w=%g)", w);
    return false;
  }

  const double phip = (std::acos(w) + M_PI) / 3;
  const double C = 1 + a * std::cos(phip);

  dRdK = C / 3;
  dRda = 2 * std::sqrt(1-w*w) * std::sin(phip) + (1-a*a) * C;
  return true;
}

bool _CoeffDataAnisotropy::_computeDerivatives(double a, double K,
                                               double &dRda, double &dRdK,
                                               double &dRdaa, double &dRdaK,
                                               double &dRdKK)
{
  const double w = _wSafe(a, K);
  if (std::abs(w) > 1) {
    Msg::Error("Cannot compute derivatives of R outside the domain (w=%g)", w);
    return false;
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
  return true;
}

bool _CoeffDataAnisotropy::_intersectionCurveLeftCorner(double beta, double gamma,
                                                        double &a, double &K)
{
  // curve K = beta * a^3 + c * a
  // on input, a and K are the bottom left corner
  // on output, a and K are the intersection
  //            return true if the intersection is on the vertical

//  if (beta < 0) {
//    Msg::Warning("Negative curvature, there are 2 or 0 intersections... Is it "
//                 "normal? Anyway, I will compute the left one if it exists.");
////    Msg::Info("%g %g | %g %g", beta, gamma, a, K);
//  }

  const double minK = K;
  K = (beta*a*a + gamma)*a;
  if (K >= minK) return true;

  // Find the root by Newton-Raphson.
  // When beta < 0, check if the intersection exists:
  K = minK;
  if (beta < 0) {
    double aMaximum = std::sqrt(-gamma/3/beta);
    double KMaximum = (beta * aMaximum*aMaximum + gamma) * aMaximum;
    if (aMaximum < a || KMaximum < K) {
      Msg::Error("Sorry but, there is no intersection");
      return -1;
    }
  }

  // Which precision? We know that w is in [-1, 1] with w = .5 * (K + (3-a*a)*a)
  // We thus seek a good precision on 'K' and '3*a - a^3'
  double a3 = (3-a*a)*a;
  double da3 = std::numeric_limits<double>::infinity();
  double dK = std::numeric_limits<double>::infinity();
  while (std::abs(da3) > 1e-5 || std::abs(dK) > 1e-4) {
    const double slope = 3*beta*a*a + gamma;
    dK = (beta*a*a + gamma)*a - minK;
    a -= dK / slope;
    da3 = a3;
    a3 = (3-a*a)*a;
    da3 -= a3;
  }
  return false;
}

double _CoeffDataAnisotropy::_computeAbscissaMinR(double aStart, double K)
{
//  Msg::Info("In _computeAbscissaMinR... (%g, %g)", aStart, K);
  double a = aStart;
  double a3 = (3-a*a)*a;
  double da3 = std::numeric_limits<double>::infinity();
  double dRda = da3, dRdK, dRdaa, dRdaK, dRdKK;
  while (std::abs(da3) > 1e-5 || std::abs(dRda) > 1e-5) {
    _computeDerivatives(a, K, dRda, dRdK, dRdaa, dRdaK, dRdKK);
    double da = - dRda / dRdaa;
    da3 = a3;
    double potentiala = a+da;
    a3 = (3-potentiala*potentiala)*potentiala;
    da3 -= a3;
    // Make sure we are not going outside the domain:
    while (std::abs(_w(a+da, K)) > 1) da /= 2;
//    Msg::Info("%g + %g = %g", a, da, a + da);
    a += da;
  }
  return a;
}

bool _CoeffDataAnisotropy::boundsOk(double minL, double maxL) const
{
  static double tol = 1e-3;
  return minL - _minB < tol;
}

void _CoeffDataAnisotropy::getSubCoeff(std::vector<_CoeffData*> &v) const
{
  v.clear();
  v.reserve(_bfsMet->getNumDivision());
  fullMatrix<double> subCoeffM;
  fullVector<double> subCoeffD;
  _bfsMet->subdivideBezCoeff(_coeffsMetric, subCoeffM);
  // in 2D, _bfsDet is NULL
  if (_bfsDet) _bfsDet->subdivideBezCoeff(_coeffsJacDet, subCoeffD);

  // in 2D, _coeffsJacDet is empty (szD == 0)
  int szD = _coeffsJacDet.size();
  int szM1 = _coeffsMetric.size1();
  int szM2 = _coeffsMetric.size2();
  for (int i = 0; i < _bfsMet->getNumDivision(); i++) {
    fullVector<double> coeffD(szD);
    fullMatrix<double> coeffM(szM1, szM2);
    coeffD.copy(subCoeffD, i * szD, szD, 0);
    coeffM.copy(subCoeffM, i * szM1, szM1, 0, szM2, 0, 0);
    int newNum = _numForDebug + (i+1) * pow_int(10, _depth);
    _CoeffDataAnisotropy *newData
        = new _CoeffDataAnisotropy(coeffD, coeffM, _bfsDet, _bfsMet, _depth+1, _elForDebug, newNum);
    v.push_back(newData);
  }
}

double _CoeffDataAnisotropy::_R2Dsafe(double q, double p)
{
  if (p <= q && p >= 0 && p < std::numeric_limits<double>::infinity()) {
    if (q == 0) return 0;
    if (q == std::numeric_limits<double>::infinity()) {
      Msg::Warning("q had infinite value in computation of 2D Raniso");
      return 1;
    }
    return (q-p) / (q+p);
  }
  else {
    Msg::Error("Wrong argument for 2d Raniso (%g, %g)", q, p);
    return -1;
  }
}

double _CoeffDataAnisotropy::_R2Dsafe(double a)
{
  if (a >= 1) {
    if (a == std::numeric_limits<double>::infinity())
      return 1;
    return (a - 1) / (a + 1);
  }
  else {
    Msg::Error("Wrong argument for 2d metRanisoric (%g)", a);
    return -1;
  }
}

double _CoeffDataAnisotropy::_R3Dsafe(double q, double p, double J)
{
  // J == J is false if J is nan
  if (p <= q && p >= 0 && J == J &&
      p < std::numeric_limits<double>::infinity()) {
    if (q == 0) return 0;
    if (p == 0) return 1;
    if (q == std::numeric_limits<double>::infinity()) {
      Msg::Warning("q had infinite value in computation of 3D Raniso");
      return 1;
    }
    const double a = q/p;
    const double K = J*J/p/p/p;
    return _R3Dsafe(a, K);
  }
  else {
    Msg::Error("Wrong argument for 3d Raniso (%g, %g, %g)", q, p, J);
    return -1;
  }
}

double _CoeffDataAnisotropy::_R3Dsafe(double a, double K)
{
  if (a >= 1 && K >= 0) {
    if (a == std::numeric_limits<double>::infinity() ||
        K == std::numeric_limits<double>::infinity()) {
      Msg::Warning("a and/or K had infinite value in computation of 3D Raniso");
      return 1;
    }

    const double w = _wSafe(a, K);
//    if (std::abs(w) > 1-1e-5) {
//      if (w > 0) return (a - 1) / (a + 2);
//      else       return (a - 2) / (a + 1);
//    }

    const double phi = std::acos(w) / 3;
    const double R = (a + 2*std::cos(phi + 2*M_PI/3)) / (a + 2*std::cos(phi));
    return std::max(.0, std::min(1., R));
  }
  else {
    Msg::Fatal("Wrong argument for 3d Raniso (%g, %g)", a, K);
    _CoeffDataAnisotropy::youReceivedAnError();
    return -1;
  }
}

double _CoeffDataAnisotropy::_wSafe(double a, double K) {
  if (a >= 1 && K >= 0) {
    if (a == std::numeric_limits<double>::infinity() ||
        K == std::numeric_limits<double>::infinity()) {
      Msg::Error("Cannot compute w with infinite numbers (%g, %g)", a, K);
      return 0;
    }
    const double w = _w(a, K);
    if (w > 1) {
      if (w < 1+1e-5) return 1;
      else {
        Msg::Error("outside the domain w(%g, %g) = %g", a, K, w);
        hasError = true;
      }
    }
    else if (w < -1) {
      if (w > -1-1e-5) return -1;
      else {
        Msg::Error("outside the domain w(%g, %g) = %g", a, K, w);
        hasError = true;
      }
    }
    return w;
  }
  else {
    Msg::Fatal("Wrong argument for w (%g, %g)", a, K);
    return -1;
  }
}

int _CoeffDataAnisotropy::metricOrder(MElement *el)
{
  const int order = el->getPolynomialOrder();

  switch (el->getType()) {
    case TYPE_PNT : return 0;

    case TYPE_LIN : return order;

    case TYPE_TRI :
    case TYPE_TET :
    case TYPE_PYR : return 2*order-2;

    case TYPE_QUA :
    case TYPE_PRI :
    case TYPE_HEX : return 2*order;

    default :
      Msg::Error("Unknown element type %d, returning order 0", el->getType());
      return 0;
  }
}

void _CoeffDataAnisotropy::interpolateForMatlab(const fullMatrix<double> &nodes) const
{
  fullVector<double> jac;
  fullMatrix<double> metric;
  _bfsMet->interpolate(_coeffsMetric, nodes, metric);

  switch (_coeffsMetric.size2()) {
  case 1:
    // nothing to do
    break;

  case 3:
    _CoeffDataAnisotropy::file << "q p myR eigR" << std::endl;
    _CoeffDataAnisotropy::file << _bfsMet->getNumLagCoeff();
    _CoeffDataAnisotropy::file << " " << metric.size1() << std::endl;
    for (int i = 0; i < metric.size1(); ++i) {
      // Compute from q, p
      double p = pow(metric(i, 1), 2);
      p += pow(metric(i, 2), 2);
      p = std::sqrt(p);
      double myR = std::sqrt(_R2Dsafe(metric(i, 0), p));
      // Comppute from tensor
      fullMatrix<double> metricTensor(2, 2);
      metricTensor(0, 0) = metric(i, 0) + metric(i, 1);
      metricTensor(1, 1) = metric(i, 0) - metric(i, 1);
      metricTensor(0, 1) = metricTensor(1, 0) = metric(i, 2);
      fullVector<double> valReal(2), valImag(2);
      fullMatrix<double> vecLeft(2, 2), vecRight(2, 2);
      metricTensor.eig(valReal, valImag, vecLeft, vecRight, true);
      double eigR = std::sqrt(valReal(0) / valReal(1));
      _CoeffDataAnisotropy::file << metric(i, 0) << " ";
      _CoeffDataAnisotropy::file << p << " ";
      _CoeffDataAnisotropy::file << myR << " ";
      _CoeffDataAnisotropy::file << eigR << std::endl;
      }
    break;

  case 7:
    _CoeffDataAnisotropy::file << "a K myR eigR" << std::endl;
    _CoeffDataAnisotropy::file << _bfsMet->getNumLagCoeff();
    _CoeffDataAnisotropy::file << " " << metric.size1() << std::endl;
    _bfsDet->interpolate(_coeffsJacDet, nodes, jac);
    for (int i = 0; i < metric.size1(); ++i) {
      // Compute from q, p, J
      double p = 0;
      for (int k = 1; k < 7; ++k) p += pow(metric(i, k), 2);
      p = std::sqrt(p);
      double myR = std::sqrt(_R3Dsafe(metric(i, 0), p, jac(i)));
      // Compute from tensor
      fullMatrix<double> metricTensor(3, 3);
      for (int k = 0; k < 3; ++k) {
        static double fact1 = std::sqrt(6.);
        static double fact2 = std::sqrt(3.);
        const int ki = k%2;
        const int kj = std::min(k+1, 2);
        metricTensor(k, k) = metric(i, k+1)*fact1 + metric(i, 0);
        metricTensor(ki, kj) = metricTensor(kj, ki) = metric(i, k+4)*fact2;
      }
      fullVector<double> valReal(3), valImag(3);
      fullMatrix<double> vecLeft(3, 3), vecRight(3, 3);
      metricTensor.eig(valReal, valImag, vecLeft, vecRight, true);
      double eigR = std::sqrt(valReal(0) / valReal(2));
      _CoeffDataAnisotropy::file << metric(i, 0)/p << " ";
      _CoeffDataAnisotropy::file << jac(i)*jac(i)/p/p/p << " ";
      _CoeffDataAnisotropy::file << myR << " ";
      _CoeffDataAnisotropy::file << eigR << std::endl;
    }
    break;

  default:
    Msg::Error("Wrong number of functions for metric: %d", _coeffsMetric.size2());
  }
}

void _CoeffDataAnisotropy::statsForMatlab(MElement *el, int num) const
{
  if (num > 1000000) return;
  static unsigned int aa = 0;
  if (++aa < 1000) {
    std::stringstream name;
    name << "metricStat_" << el->getNum() << "_";
    name << (num % 10);
    name << (num % 100)/10;
    name << (num % 1000)/100;
    name << (num % 10000)/1000;
    name << (num % 100000)/10000;
    name << ".txt";
    _CoeffDataAnisotropy::file.open(name.str().c_str(), std::fstream::out);

    {
      _CoeffDataAnisotropy::file << "mina minKfast minKsharp cmin beta_m beta_M beta c_m" << std::endl;
      double mina, minKs, minKf, gamma, beta_m, beta_M, beta, c_m;

      mina = _computeLowerBoundA();

      if (el->getDim() == 3) {
        minKs = minKf = _computeLowerBoundK();
        double minK = minKf;
        _moveInsideDomain(mina, minK, true);
        double p_dRda, p_dRdK;
        _computePseudoDerivatives(mina, minK, p_dRda, p_dRdK);
        double slope = -p_dRda/p_dRdK;
        gamma = .5*(3*minK/mina - slope);
        _computeBoundingCurve(beta_m, gamma, true);
        _computeBoundingCurve(beta_M, gamma, false);
        beta = -p_dRda/(p_dRdK*3*mina*mina);
        c_m = -1;
      }
      else {
        minKs = minKf = gamma = beta_m = beta_M = beta = c_m = -1;
      }

      _CoeffDataAnisotropy::file << std::setprecision(15);
      _CoeffDataAnisotropy::file << mina << " " << minKf << " " << minKs << " ";
      _CoeffDataAnisotropy::file << gamma << " " << beta_m << " " << beta_M << " ";
      _CoeffDataAnisotropy::file << beta << " " << c_m << std::endl;
      _CoeffDataAnisotropy::file << std::setprecision(8);
    }
  }

  fullMatrix<double> samplingPoints;
  bool serendip = false;
  gmshGeneratePoints(FuncSpaceData(el, 20, &serendip), samplingPoints);
  interpolateForMatlab(samplingPoints);
  _CoeffDataAnisotropy::file.close();
}

// Miscellaneous
template<typename Comp>
void _subdivideDomainsMinOrMax(std::vector<_CoeffData*> &domains,
                               double &minL,
                               double &maxL)
{
  std::vector<_CoeffData*> subs;
  make_heap(domains.begin(), domains.end(), Comp());
  while (!domains[0]->boundsOk(minL, maxL)) {
    _CoeffData *cd = domains[0];
    pop_heap(domains.begin(), domains.end(), Comp());
    domains.pop_back();
    cd->getSubCoeff(subs);
    delete cd;

    for (unsigned int i = 0; i < subs.size(); i++) {
      minL = std::min(minL, subs[i]->minL());
      maxL = std::max(maxL, subs[i]->maxL());
      domains.push_back(subs[i]);
      push_heap(domains.begin(), domains.end(), Comp());
    }
  }
}

void _subdivideDomains(std::vector<_CoeffData*> &domains)
{
  if (domains.empty()) {
    Msg::Warning("empty vector in Bezier subdivision, nothing to do");
    return;
  }
  double minL = domains[0]->minL();
  double maxL = domains[0]->maxL();
  for (unsigned int i = 1; i < domains.size(); ++i) {
    minL = std::min(minL, domains[i]->minL());
    maxL = std::max(maxL, domains[i]->maxL());
  }

  _subdivideDomainsMinOrMax<_lessMinB>(domains, minL, maxL);
  _subdivideDomainsMinOrMax<_lessMaxB>(domains, minL, maxL);
}

double _computeBoundRational(const fullVector<double> &numerator,
                             const fullVector<double> &denominator,
                             bool lower, bool positiveDenom)
{
  if (numerator.size() != denominator.size()) {
    Msg::Error("In order to compute a bound on a rational function, I need "
               "vectors of the same size! (%d vs %d)", numerator.size(),
               denominator.size());
    _CoeffDataAnisotropy::youReceivedAnError();
    return 0;
  }

  // upper and lower bound of the desired bound:
  const double inf = std::numeric_limits<double>::infinity();
  double upperBound = inf;
  double lowerBound = -inf;

  if (!positiveDenom) {
    lower = lower ? false : true;
  }

  if (lower) {
    // if lower is true, we seek: bound * den <= num
    for (int i = 0; i < numerator.size(); ++i) {
      if (denominator(i) == 0) {
        if (numerator(i) < 0) return -inf;
      }
      else if (denominator(i) > 0) {
        upperBound = std::min(upperBound, numerator(i)/denominator(i));
      }
      else {
        lowerBound = std::max(lowerBound, numerator(i)/denominator(i));
      }
    }
    if (lowerBound > upperBound)
      return -inf;
    else
      return upperBound;
  }
  else {
    // otherwise, we seek: bound * den >= num
    for (int i = 0; i < numerator.size(); ++i) {
      if (denominator(i) == 0) {
        if (numerator(i) > 0) return inf;
      }
      else if (denominator(i) > 0) {
        lowerBound = std::max(lowerBound, numerator(i)/denominator(i));
      }
      else {
        upperBound = std::min(upperBound, numerator(i)/denominator(i));
      }
    }
    if (lowerBound > upperBound)
      return inf;
    else
      return lowerBound;
  }
}

} // end namespace jacobianBasedQuality
