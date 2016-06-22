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
MElement *_CoeffDataAnisotropy::currentElement = NULL;
_CoeffDataAnisotropy *_CoeffDataAnisotropy::current = NULL;
std::fstream _CoeffDataAnisotropy::file;
std::vector<double> _CoeffDataAnisotropy::mytimes;
std::vector<int> _CoeffDataAnisotropy::mynumbers;
double _CoeffDataScaledJac::cTri = 2/std::sqrt(3);
double _CoeffDataScaledJac::cTet = std::sqrt(2);
double _CoeffDataScaledJac::cPyr = std::sqrt(2)*4;

void minMaxJacobianDeterminant(MElement *el, double &min, double &max)
{
  _CoeffDataAnisotropy::currentElement = el;
  const JacobianBasis *jfs = el->getJacobianFuncSpace();
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el->getTypeForMSH());
    min = 99;
    max = -99;
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

double minScaledJacobian(MElement *el, bool knownValid, bool reversedOk)
{
  bool isReversed = false;
  if (!knownValid) {
    double jmin, jmax;
    minMaxJacobianDeterminant(el, jmin, jmax);
    if (jmax < 0) {
      if (!reversedOk) return 0;
      isReversed = true;
    }
    else if (jmin <= 0) return 0;
  }
  // Computation of the minimum (or maximum) of the scaled Jacobian should never
  // be performed to invalid elements (for which the measure is 0).

  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const JacobianBasis *jacBasis;
  const GradientBasis *gradBasis;

  const int type = el->getType();
  const int order = el->getPolynomialOrder();
  const int jacOrder = order * el->getDim();
  const bool serendipFalse = false;

  FuncSpaceData jacMatSpace, jacDetSpace;

  switch(type) {
  case TYPE_TRI:
    jacMatSpace = FuncSpaceData(el, order-1, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, jacOrder-2, &serendipFalse);
    break;
  case TYPE_TET:
    jacMatSpace = FuncSpaceData(el, order-1, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, jacOrder-3, &serendipFalse);
    break;
  case TYPE_QUA:
  case TYPE_HEX:
  case TYPE_PRI:
    jacMatSpace = FuncSpaceData(el, order, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, jacOrder, &serendipFalse);
    break;
  case TYPE_PYR:
    jacMatSpace = FuncSpaceData(el, false, order, order-1, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, false, jacOrder, jacOrder-3, &serendipFalse);
    break;
  default:
    Msg::Error("Scaled Jacobian not implemented for type of element %d", el->getType());
    return -1;
  }
  gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
  jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

  fullVector<double> coeffDetBez;
  {
    fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
    jacBasis->getSignedJacobian(nodesXYZ, coeffDetLag);

    coeffDetBez.resize(jacBasis->getNumJacNodes());
    jacBasis->lag2Bez(coeffDetLag, coeffDetBez);

    if (isReversed) coeffDetBez.scale(-1);
  }

  fullMatrix<double> coeffMatBez;
  {
    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->getAllGradientsFromNodes(nodesXYZ, coeffMatLag);

    coeffMatBez.resize(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->lag2Bez(coeffMatLag, coeffMatBez);
    if (el->getDim() == 2) coeffMatBez.resize(coeffMatBez.size1(), 6, false);
  }

  std::vector<_CoeffData*> domains;
  domains.push_back(
      new _CoeffDataScaledJac(coeffDetBez, coeffMatBez, jacBasis->getBezier(),
                              gradBasis->getBezier(), 0, el->getType())
  );

  _subdivideDomains(domains);

//  Msg::Info("element %d, type %d, numSub %d", el->getNum(), el->getType(),
//      domains.size()/7);
  if (domains.size()/7 > 500) {//fordebug
    Msg::Info("S too much subdivision: %d (el %d, type %d, tag %d)",
        domains.size()/7, el->getNum(), el->getType(), el->getTypeForMSH());
  }

  double min = domains[0]->minB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    delete domains[i];
  }
  return min;
}

double minAnisotropyMeasure(MElement *el,
                            bool knownValid,
                            bool reversedOk,
                            int n)
{
  if (!knownValid) {
    double jmin, jmax;
    minMaxJacobianDeterminant(el, jmin, jmax);
    if (jmin <= 0 && jmax >= 0) return 0;
    if (!reversedOk && jmax < 0) return 0;
  }
  // Computation of the minimum of the anisotropy measure should never
  // be performed to invalid elements (for which the measure is 0).

  if (_CoeffDataAnisotropy::noMoreComputationPlease()) {
    Msg::Info("Sorry, no more computation");
    return -9; //fordebug
  }

//  double minSampled = minSampledAnisotropyMeasure(el, n); //fordebug

  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const GradientBasis *gradBasis;
  const JacobianBasis *jacBasis = NULL;

  const int type = el->getType();
  const bool serendipFalse = false;
  const int metricOrder = _CoeffDataAnisotropy::metricOrder(el);
  const int jacDetOrder = 3*metricOrder/2;
  if (metricOrder == -1) {
    Msg::Error("Anisotropy measure not implemented for type of element %d", el->getType());
    return -1;
  }

  FuncSpaceData metricSpace, jacDetSpace;

  switch(type) {
  case TYPE_TET:
  case TYPE_HEX:
  case TYPE_PRI:
    jacDetSpace = FuncSpaceData(el, jacDetOrder, &serendipFalse);
    jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);
    //no break
  case TYPE_TRI:
  case TYPE_QUA:
    metricSpace = FuncSpaceData(el, metricOrder, &serendipFalse);
    break;
  case TYPE_PYR:
    metricSpace = FuncSpaceData(el, false, metricOrder+2, metricOrder, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, false, jacDetOrder+3, jacDetOrder, &serendipFalse);
    jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);
    break;
  }
  gradBasis = BasisFactory::getGradientBasis(metricSpace);

  // Metric Coefficients
  fullMatrix<double> coeffMetricBez;
  {
    fullMatrix<double> coeffMetricLag;
    _CoeffDataAnisotropy::fillMetricCoeff(gradBasis, nodesXYZ, coeffMetricLag,
                                          el->getDim(), true);

    coeffMetricBez.resize(coeffMetricLag.size1(), coeffMetricLag.size2());
    gradBasis->lag2Bez(coeffMetricLag, coeffMetricBez);
  }

  // Jacobian determinant coefficients
  fullVector<double> coeffJacDetBez;
  if (jacBasis) {
    fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
    jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

    coeffJacDetBez.resize(jacBasis->getNumJacNodes());
    jacBasis->lag2Bez(coeffDetLag, coeffJacDetBez);
  }

  std::vector<_CoeffData*> domains;
  domains.push_back(
      new _CoeffDataAnisotropy(coeffJacDetBez, coeffMetricBez,
                               jacBasis ? jacBasis->getBezier() : NULL,
                               gradBasis->getBezier(), 0, el)
  );

  _subdivideDomains(domains);
  if (domains.size()/7 > 500) {//fordebug
    Msg::Info("A too much subdivision: %d (el %d, type %d)", domains.size()/7, el->getNum(), el->getType());
  }

  double min = domains[0]->minB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    delete domains[i];
  }

//  if (min - minSampled > 1e-13) {//fordebug
//    Msg::Error("no, works no el %d (%g vs %g, diff %g)", el->getNum(), min, minSampled, min-minSampled);
//  }

  return min;
}

double minIsotropyMeasure(MElement *el,
                          bool knownValid,
                          bool reversedOk)
{
  bool isReversed = false;
  if (!knownValid) {
    double jmin, jmax;
    minMaxJacobianDeterminant(el, jmin, jmax);
    if (jmax < 0) {
      if (!reversedOk) return 0;
      isReversed = true;
    }
    else if (jmin <= 0) return 0;
  }
  // Computation of the minimum (or maximum) of the scaled Jacobian should never
  // be performed to invalid elements (for which the measure is 0).

  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const JacobianBasis *jacBasis;
  const GradientBasis *gradBasis;

  const int type = el->getType();
  const int order = el->getPolynomialOrder();
  const int jacOrder = order * el->getDim();
  const bool serendipFalse = false;

  FuncSpaceData jacMatSpace, jacDetSpace;

  switch(type) {
  case TYPE_TRI:
    jacMatSpace = FuncSpaceData(el, order-1, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, jacOrder-2, &serendipFalse);
    break;
  case TYPE_TET:
    jacMatSpace = FuncSpaceData(el, order-1, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, jacOrder-3, &serendipFalse);
    break;
  case TYPE_QUA:
  case TYPE_HEX:
  case TYPE_PRI:
    jacMatSpace = FuncSpaceData(el, order, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, jacOrder, &serendipFalse);
    break;
  case TYPE_PYR:
    jacMatSpace = FuncSpaceData(el, false, order, order-1, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, false, jacOrder, jacOrder-3, &serendipFalse);
    break;
  default:
    Msg::Error("Isotropy not implemented for type of element %d", el->getType());
    return -1;
  }
  gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
  jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

  fullVector<double> coeffDetBez;
  {
    fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
    jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

    coeffDetBez.resize(jacBasis->getNumJacNodes());
    jacBasis->lag2Bez(coeffDetLag, coeffDetBez);

    if (isReversed) coeffDetBez.scale(-1);
  }

  fullMatrix<double> coeffMatBez;
  {
    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);

    coeffMatBez.resize(gradBasis->getNumSamplingPoints(), 9);
    gradBasis->lag2Bez(coeffMatLag, coeffMatBez);
    if (el->getDim() == 2) coeffMatBez.resize(coeffMatBez.size1(), 6, false);
  }

  std::vector<_CoeffData*> domains;
  domains.push_back(
      new _CoeffDataIsotropy(coeffDetBez, coeffMatBez, jacBasis->getBezier(),
                             gradBasis->getBezier(), 0)
  );

  _subdivideDomains(domains);
  if (domains.size()/7 > 500) {//fordebug
    Msg::Info("I too much subdivision: %d (el %d, type %d, tag %d)",
               domains.size()/7, el->getNum(), el->getType(), el->getTypeForMSH());
  }


  double min = domains[0]->minB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    delete domains[i];
  }
  return min;
}

//double minSampledAnisotropyMeasure(MElement *el, int deg, bool writeInFile)//fordebug
//{
//  fullMatrix<double> samplingPoints;
//  bool serendip = false;
//  gmshGeneratePoints(FuncSpaceData(el, deg, &serendip), samplingPoints);
//
//  double values[3];
//  double min = std::numeric_limits<double>::infinity();
//  for (int i = 0; i < samplingPoints.size1(); ++i) {
//    min = std::min(min, el->getEigenvaluesMetric(samplingPoints(i, 0),
//                                                 samplingPoints(i, 1),
//                                                 samplingPoints(i, 2),
//                                                 values));
//  }
//
//  return min;
//}

double minSampledIsotropyMeasure(MElement *el, int deg, bool writeInFile)//fordebug
{
  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const JacobianBasis *jacBasis;
  const GradientBasis *gradBasis;

  const int type = el->getType();
//  const int order = el->getPolynomialOrder();
//  const int jacOrder = order * el->getDim();
  const bool serendipFalse = false;

  FuncSpaceData jacMatSpace, jacDetSpace;

  switch(type) {
  case TYPE_TRI:
  case TYPE_TET:
  case TYPE_QUA:
  case TYPE_HEX:
  case TYPE_PRI:
    jacMatSpace = FuncSpaceData(el, deg, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, deg, &serendipFalse);
    break;
  case TYPE_PYR:
//    jacMatSpace = FuncSpaceData(el, false, order, order-1, &serendipFalse);
//    jacDetSpace = FuncSpaceData(el, false, jacOrder, jacOrder-3, &serendipFalse);
    break;
  default:
    Msg::Error("Isotropy not implemented for type of element %d", el->getType());
    return -1;
  }
  gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
  jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

  fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
  jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

  fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
  gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);

  double min = std::numeric_limits<double>::infinity();
  for (int i = 0; i < coeffDetLag.size(); ++i) {
    double frobNorm = 0;
    if (el->getDim() == 2) {
      for (int k = 0; k < 6; ++k)
        frobNorm += coeffMatLag(i, k) * coeffMatLag(i, k);
      min = std::min(min, 2*coeffDetLag(i)/frobNorm);
    }
    else if (el->getDim() == 3) {
      for (int k = 0; k < 9; ++k)
        frobNorm += coeffMatLag(i, k) * coeffMatLag(i, k);
      min = std::min(min, 3*std::pow(coeffDetLag(i), 2/3.)/frobNorm);
    }
  }

  return min;
}

double minSampledScaledJacobian(MElement *el, int deg, bool writeInFile)//fordebug
{
  fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
  el->getNodesCoord(nodesXYZ);

  const JacobianBasis *jacBasis;
  const GradientBasis *gradBasis;

  const int type = el->getType();
//  const int order = el->getPolynomialOrder();
//  const int jacOrder = order * el->getDim();
  const bool serendipFalse = false;

  FuncSpaceData jacMatSpace, jacDetSpace;

  switch(type) {
  case TYPE_TRI:
  case TYPE_TET:
  case TYPE_QUA:
  case TYPE_HEX:
  case TYPE_PRI:
    jacMatSpace = FuncSpaceData(el, deg, &serendipFalse);
    jacDetSpace = FuncSpaceData(el, deg, &serendipFalse);
    break;
  case TYPE_PYR:
//    jacMatSpace = FuncSpaceData(el, false, order, order-1, &serendipFalse);
//    jacDetSpace = FuncSpaceData(el, false, jacOrder, jacOrder-3, &serendipFalse);
    break;
  default:
    Msg::Error("Isotropy not implemented for type of element %d", el->getType());
    return -1;
  }
  gradBasis = BasisFactory::getGradientBasis(jacMatSpace);
  jacBasis = BasisFactory::getJacobianBasis(jacDetSpace);

  fullVector<double> coeffDetLag(jacBasis->getNumJacNodes());
  jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag);

  fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
  gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);

  double min = std::numeric_limits<double>::infinity();
  for (int i = 0; i < coeffDetLag.size(); ++i) {
    if (el->getDim() == 2) {
      double v[2] = {0, 0};
      for (int k = 0; k < 2; ++k) {
        for (int l = k*3; l < k*3+3; ++l)
          v[k] += coeffMatLag(i, l) * coeffMatLag(i, l);
      }
      min = std::min(min, coeffDetLag(i)/v[0]/v[1]);
    }
    else if (el->getDim() == 3) {
      double v[3] = {0, 0, 0};
      for (int k = 0; k < 3; ++k) {
        for (int l = k*3; l < k*3+3; ++l)
          v[k] += coeffMatLag(i, l) * coeffMatLag(i, l);
      }
      min = std::min(min, coeffDetLag(i)/std::sqrt(v[0]*v[1]*v[2]));
    }
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
                                         int depth, int type)
: _CoeffData(depth), _coeffsJacDet(det.getDataPtr(), det.size()),
  _coeffsJacMat(mat.getDataPtr(), mat.size1(), mat.size2()),
  _bfsDet(bfsDet), _bfsMat(bfsMat), _type(type)
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
//  Msg::Info("%g %g %g", _minB, _minL, _maxL);//fordebug
//  _coeffsJacDet.print("_coeffsJacDet");
//  _coeffsJacMat.print("_coeffsJacMat");
  // computation of _maxB not implemented for now
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
    newData = new _CoeffDataScaledJac(coeffD, coeffM, _bfsDet, _bfsMat,
                                      _depth+1, _type);
    v.push_back(newData);
  }
}

void _CoeffDataScaledJac::_computeAtCorner(double &min, double &max) const
{
  min = std::numeric_limits<double>::infinity();
  max = -min;

  fullMatrix<double> v;
  _getCoeffLengthVectors(v, true);

  for (int i = 0; i < _bfsDet->getNumLagCoeff(); i++) {
    double sJ;
    switch(_type) {
    case TYPE_QUA:
      sJ =  _coeffsJacDet(i)/v(i, 0)/v(i,1);
      break;
    case TYPE_HEX:
      sJ = _coeffsJacDet(i)/v(i,0)/v(i,1)/v(i,2);
      break;
    case TYPE_TRI:
      sJ = cTri * _coeffsJacDet(i) * (1/v(i,0)/v(i,1) +
                                      1/v(i,0)/v(i,2) +
                                      1/v(i,1)/v(i,2)) / 3;
      break;
    case TYPE_TET:
      sJ = cTet * _coeffsJacDet(i) * (1/v(i,0)/v(i,1)/v(i,2) +
                                      1/v(i,0)/v(i,3)/v(i,4) +
                                      1/v(i,1)/v(i,3)/v(i,5) +
                                      1/v(i,2)/v(i,4)/v(i,5)) / 4;
      break;
    case TYPE_PRI:
      sJ = cTri * _coeffsJacDet(i) * (1/v(i,0)/v(i,1)/v(i,2) +
                                      1/v(i,0)/v(i,3)/v(i,2) +
                                      1/v(i,1)/v(i,3)/v(i,2)) / 3;
      break;
    case TYPE_PYR:
      sJ = cPyr * _coeffsJacDet(i) * (1/v(i,0)/v(i,1)/v(i,2) +
                                      1/v(i,0)/v(i,1)/v(i,3) +
                                      1/v(i,0)/v(i,1)/v(i,4) +
                                      1/v(i,0)/v(i,1)/v(i,5) +
                                      1/v(i,2)/v(i,3)/v(i,4) +
                                      1/v(i,2)/v(i,3)/v(i,5) +
                                      1/v(i,2)/v(i,4)/v(i,5) +
                                      1/v(i,3)/v(i,4)/v(i,5)  ) / 8;
      break;
    default:
      Msg::Error("Unkown type for scaled jac computation");
      return;
    }
    min = std::min(min, sJ);
    max = std::max(max, sJ);
  }
}

double _CoeffDataScaledJac::_computeLowerBound() const
{
  // Speedup: If one coeff _coeffsJacDet is negative, without bounding
  // J^2/(a^2+b^2), we would get with certainty a negative lower bound.
  // For now, returning 0.
  for (int i = 0; i < _coeffsJacDet.size(); ++i) {
    if (_coeffsJacDet(i) < 0) {
      return 0;
    }
  }

  fullMatrix<double> v;
  _getCoeffLengthVectors(v, false);

  fullVector<double> prox[6];
  for (int i = 0; i < v.size2(); ++i) {
    prox[i].setAsProxy(v, i);
  }

  bezierBasisRaiser *raiser = _bfsMat->getRaiser();
  fullVector<double> coeffDenominator;
  double result = 0;

  switch (_type) {
  case TYPE_QUA:
    raiser->computeCoeff(prox[0], prox[1], coeffDenominator);
    return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

  case TYPE_TRI:
    raiser->computeCoeff(prox[0], prox[1], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[0], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[1], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    return cTri*result/3;

  case TYPE_HEX:
    raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
    return _computeBoundRational(_coeffsJacDet, coeffDenominator, true);

  case TYPE_PRI:
    raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[0], prox[3], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[1], prox[3], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    return cTri*result/3;

  case TYPE_TET:
    raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[0], prox[3], prox[4], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[1], prox[3], prox[5], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[2], prox[4], prox[5], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    return cTet*result/4;

  case TYPE_PYR:
    raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[0], prox[1], prox[3], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[0], prox[1], prox[4], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[0], prox[1], prox[5], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[2], prox[4], prox[5], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[2], prox[3], prox[4], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[2], prox[3], prox[5], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    raiser->computeCoeff(prox[3], prox[4], prox[5], coeffDenominator);
    result += _computeBoundRational(_coeffsJacDet, coeffDenominator, true);
    return cPyr*result/8;

  default:
    Msg::Info("Unknown type for scaled Jacobian (%d)", _type);
    return -1;
  }
}

void _CoeffDataScaledJac::_getCoeffLengthVectors(fullMatrix<double> &coeff,
                                                 bool corners) const
{
  int sz1 = corners ? _bfsDet->getNumLagCoeff() : _coeffsJacMat.size1();

  switch (_type) {
    case TYPE_QUA: coeff.resize(sz1, 2); break;
    case TYPE_TRI: coeff.resize(sz1, 3); break;
    case TYPE_HEX: coeff.resize(sz1, 3); break;
    case TYPE_PRI: coeff.resize(sz1, 4); break;
    case TYPE_TET: coeff.resize(sz1, 6); break;
    case TYPE_PYR: coeff.resize(sz1, 6); break;
    default:
      Msg::Error("Unkown type for scaled jac computation");
      coeff.resize(0, 0);
      return;
  }

  const fullMatrix<double> &mat = _coeffsJacMat;

  if (_type != TYPE_PYR) {
    for (int i = 0; i < sz1; i++) {
      coeff(i, 0) = std::sqrt(pow_int(mat(i, 0), 2) +
                              pow_int(mat(i, 1), 2) +
                              pow_int(mat(i, 2), 2)  );
      coeff(i, 1) = std::sqrt(pow_int(mat(i, 3), 2) +
                              pow_int(mat(i, 4), 2) +
                              pow_int(mat(i, 5), 2)  );
    }
    if (mat.size2() > 6) {
      for (int i = 0; i < sz1; i++) {
        coeff(i, 2) = std::sqrt(pow_int(mat(i, 6), 2) +
                                pow_int(mat(i, 7), 2) +
                                pow_int(mat(i, 8), 2)  );
      }
    }
    else if (_type == TYPE_TRI) {
      for (int i = 0; i < sz1; i++) {
        coeff(i, 2) = std::sqrt(pow_int(mat(i, 3) - mat(i, 0), 2) +
                                pow_int(mat(i, 4) - mat(i, 1), 2) +
                                pow_int(mat(i, 5) - mat(i, 2), 2)  );
      }
    }
    switch (_type) {
    case TYPE_TET:
    case TYPE_PRI:
      for (int i = 0; i < sz1; i++) {
        coeff(i, 3) = std::sqrt(pow_int(mat(i, 3) - mat(i, 0), 2) +
                                pow_int(mat(i, 4) - mat(i, 1), 2) +
                                pow_int(mat(i, 5) - mat(i, 2), 2)  );
      }
    }
    if (_type == TYPE_TET) {
      for (int i = 0; i < sz1; i++) {
        coeff(i, 4) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0), 2) +
                                pow_int(mat(i, 7) - mat(i, 1), 2) +
                                pow_int(mat(i, 8) - mat(i, 2), 2)  );
        coeff(i, 5) = std::sqrt(pow_int(mat(i, 6) - mat(i, 3), 2) +
                                pow_int(mat(i, 7) - mat(i, 4), 2) +
                                pow_int(mat(i, 8) - mat(i, 5), 2)  );
      }
    }
  }
  else {
    for (int i = 0; i < sz1; i++) {
      coeff(i, 0) = std::sqrt(pow_int(2*mat(i, 0), 2) +
                              pow_int(2*mat(i, 1), 2) +
                              pow_int(2*mat(i, 2), 2)  );
      coeff(i, 1) = std::sqrt(pow_int(2*mat(i, 3), 2) +
                              pow_int(2*mat(i, 4), 2) +
                              pow_int(2*mat(i, 5), 2)  );
      coeff(i, 2) = std::sqrt(pow_int(mat(i, 6) + mat(i, 0) + mat(i, 3), 2) +
                              pow_int(mat(i, 7) + mat(i, 1) + mat(i, 4), 2) +
                              pow_int(mat(i, 8) + mat(i, 2) + mat(i, 5), 2)  );
      coeff(i, 3) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0) + mat(i, 3), 2) +
                              pow_int(mat(i, 7) - mat(i, 1) + mat(i, 4), 2) +
                              pow_int(mat(i, 8) - mat(i, 2) + mat(i, 5), 2)  );
      coeff(i, 4) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0) - mat(i, 3), 2) +
                              pow_int(mat(i, 7) - mat(i, 1) - mat(i, 4), 2) +
                              pow_int(mat(i, 8) - mat(i, 2) - mat(i, 5), 2)  );
      coeff(i, 5) = std::sqrt(pow_int(mat(i, 6) + mat(i, 0) - mat(i, 3), 2) +
                              pow_int(mat(i, 7) + mat(i, 1) - mat(i, 4), 2) +
                              pow_int(mat(i, 8) + mat(i, 2) - mat(i, 5), 2)  );
    }
  }
}

// Isotropy measure
_CoeffDataIsotropy::_CoeffDataIsotropy(fullVector<double> &det,
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
  // _coeffsJacDet and _coeffsMetric reuse data, this avoid to allocate new
  // arrays and to copy data that are not used outside of this object.
  // It remains to swap ownerships:
  det.setOwnData(false);
  mat.setOwnData(false);
  const_cast<fullVector<double>&>(_coeffsJacDet).setOwnData(true);
  const_cast<fullMatrix<double>&>(_coeffsJacMat).setOwnData(true);

  _computeAtCorner(_minL, _maxL);

  _minB = 0;
  if (boundsOk(_minL, _maxL)) return;
  else _minB = _computeLowerBound();
//  Msg::Info("%g %g %g ", _minB, _minL, _maxL);
//  _coeffsJacDet.print("_coeffsJacDet");
//  _coeffsJacMat.print("_coeffsJacMat");

  // _maxB not used for now
}

bool _CoeffDataIsotropy::boundsOk(double minL, double maxL) const
{
  static double tol = 1e-3;
  return minL < tol*1e-3 || (_minB > minL-tol && _minB > minL*(1-100*tol));
}

void _CoeffDataIsotropy::getSubCoeff(std::vector<_CoeffData*> &v) const
{
  v.clear();
  v.reserve(_bfsMat->getNumDivision());
  fullMatrix<double> subCoeffM;
  fullVector<double> subCoeffD;
  _bfsMat->subdivideBezCoeff(_coeffsJacMat, subCoeffM);
  _bfsDet->subdivideBezCoeff(_coeffsJacDet, subCoeffD);

  int szD = _coeffsJacDet.size();
  int szM1 = _coeffsJacMat.size1();
  int szM2 = _coeffsJacMat.size2();
  for (int i = 0; i < _bfsMat->getNumDivision(); i++) {
    fullVector<double> coeffD(szD);
    fullMatrix<double> coeffM(szM1, szM2);
    coeffD.copy(subCoeffD, i * szD, szD, 0);
    coeffM.copy(subCoeffM, i * szM1, szM1, 0, szM2, 0, 0);
    _CoeffDataIsotropy *newData
        = new _CoeffDataIsotropy(coeffD, coeffM, _bfsDet, _bfsMat, _depth+1);
    v.push_back(newData);
  }
}

void _CoeffDataIsotropy::_computeAtCorner(double &min, double &max) const
{
  min = std::numeric_limits<double>::infinity();
  max = -min;

  for (int i = 0; i < _bfsMat->getNumLagCoeff(); i++) {
    double p = 0;
    for (int k = 0; k < _coeffsJacMat.size2(); ++k) {
      p += pow_int(_coeffsJacMat(i, k), 2);
    }
    double qual;
    if (_coeffsJacMat.size2() == 6)
      qual = 2 * _coeffsJacDet(i) / p;
    else
      qual = 3 * std::pow(_coeffsJacDet(i), 2/3.) / p;
    min = std::min(min, qual);
    max = std::max(max, qual);
  }
}

double _CoeffDataIsotropy::_computeLowerBound() const
{
  // Speedup: If one coeff _coeffsJacDet is negative, we would get
  // a negative lower bound. For now, returning 0.
  for (int i = 0; i < _coeffsJacDet.size(); ++i) {
    if (_coeffsJacDet(i) < 0) {
      return 0;
    }
  }

  // 2D element
  if (_coeffsJacMat.size2() == 6) {
    fullVector<double> coeffDenominator;
    {
      bezierBasisRaiser *raiser = _bfsMat->getRaiser();
      fullVector<double> prox;
      for (int k = 0; k < _coeffsJacMat.size2(); ++k) {
        prox.setAsProxy(_coeffsJacMat, k);
        fullVector<double> tmp;
        raiser->computeCoeff(prox, prox, tmp);
        if (k == 0) coeffDenominator.resize(tmp.size());
        coeffDenominator.axpy(tmp, 1);
      }
    }
    return 2*_computeBoundRational(_coeffsJacDet, coeffDenominator, true);
  }

  // 3D element NEW
  fullVector<double> coeffDenominator;
  {
    // P: coefficients of function that bound from above the Frobenius norm of J
    // element of P are automatically set to 0
    fullVector<double> P(_coeffsJacMat.size1());
    for (int i = 0; i < _coeffsJacMat.size1(); ++i) {
      for (int k = 0; k < _coeffsJacMat.size2(); ++k) {
        P(i) += _coeffsJacMat(i, k) * _coeffsJacMat(i, k);
      }
      P(i) = std::sqrt(P(i));
    }
    _bfsMat->getRaiser()->computeCoeff(P, P, P, coeffDenominator);
  }

  return 3*std::pow(_computeBoundRational(_coeffsJacDet,
                                          coeffDenominator, true), 2/3.);

//  // 3D element OLD
//  fullVector<double> coeffNumerator;
//  _bfsDet->getRaiser()->computeCoeff(_coeffsJacDet, _coeffsJacDet, coeffNumerator);
//
//  fullVector<double> coeffDenominator;
//  {
//    fullVector<double> coeffDenCbrt;
//    bezierBasisRaiser *raiser = _bfsMat->getRaiser();
//
//    fullVector<double> prox;
//    for (int k = 0; k < _coeffsJacMat.size2(); ++k) {
//      prox.setAsProxy(_coeffsJacMat, k);
//      fullVector<double> tmp;
//      raiser->computeCoeff(prox, prox, tmp);
//      if (k == 0) coeffDenCbrt.resize(tmp.size());
//      coeffDenCbrt.axpy(tmp, 1);
//    }
//
//    bezierBasisRaiser *raiser2 = raiser->getRaisedBezierBasis(2)->getRaiser();
//    raiser2->computeCoeff(coeffDenCbrt, coeffDenCbrt, coeffDenCbrt, coeffDenominator);
//  }
//
//  return 3*std::pow(_computeBoundRational(coeffNumerator,
//                                          coeffDenominator, true), 1/3.);
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
  _CoeffDataAnisotropy::current = this;
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

  _computeAtCorner(_minL, _maxL);

  _minB = 0;
  if (boundsOk(_minL, _maxL)) return;
  else _minB = _computeLowerBound();

  // computation of _maxB not implemented for now
  //statsForMatlab(_elForDebug, _numForDebug);//fordebug
}

void _CoeffDataAnisotropy::_computeAtCorner(double &min, double &max) const
{
  min = std::numeric_limits<double>::infinity();
  max = -min;

  for (int i = 0; i < _bfsMet->getNumLagCoeff(); i++) {
    const double &q = _coeffsMetric(i, 0);
    double p = 0;
    for (int k = 1; k < _coeffsMetric.size2(); ++k) {
      p += pow_int(_coeffsMetric(i, k), 2);
    }
    p = std::sqrt(p);
    double qualSqrd;
    if (_coeffsMetric.size2() == 3)
      qualSqrd = _R2Dsafe(q, p);
    else
      qualSqrd = _R3Dsafe(q, p, _coeffsJacDet(i));
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
  double mina = _computeLowerBoundA();
  double minK = _computeLowerBoundK();

  _moveInsideDomain(mina, minK, true);

  double p_dRda, p_dRdK;
  _computePseudoDerivatives(mina, minK, p_dRda, p_dRdK);

  if (p_dRda < 0) {
    // cases 1 & 2 => compute a lower bounding curve K = beta * a^3 + c * a
    // with c such that the curve that passes through (minK, mina) has the
    // slope equal to -dRda/dRdK
    double slope = -p_dRda/p_dRdK;
    double gamma = .5*(3*minK/mina - slope);
    double beta;
    _computeBoundingCurve(beta, gamma, true);
    /*{//fordebug
      double beta = (minK/mina-c)/mina/mina;
      if (std::abs(p_dRda + p_dRdK * (3*beta*mina*mina+c)) > 1e-12) {
        Msg::Error("Derivative along curve not zero %g", p_dRda + p_dRdK * (3*beta*mina*mina+c));
      }
    }*/

    double a_int = mina, K_int = minK;
    int where = _intersectionCurveLeftCorner(beta, gamma, a_int, K_int);
    if (where == 1) {
      // the minimum is on the curve, long to compute, we return this for now:
      return std::sqrt(_R3Dsafe(mina, minK));
    }
    //Msg::Info("int (%g, %g) (beta %g, gamma %g)", a_int, K_int, beta, gamma);//fordebug

    // Let a0 be the point at which R(a, minK) takes its minimum. If there is
    // an intersection and if a_int < a0, the minimum is at (a_int, minK),
    // otherwise it is at (a0, minK).
    bool minIsAta0;
    if (where == -1 || _moveInsideDomain(a_int, K_int, false)) {
      minIsAta0 = true;
    }
    else {
      double p_dRda, p_dRdK;
      _computePseudoDerivatives(a_int, K_int, p_dRda, p_dRdK);
      /*if (p_dRda + p_dRdK * (3*beta*a_int*a_int+c) < -1e-5) {//fordebug
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
      return std::sqrt(_R3Dsafe(a_int, minK));
    }
  }
  else if (p_dRdK < 0) {
    // cases 4 & 5 => compute an upper bounding curve K = beta * a^3 + c * a
    // with c such that the curve that passes through (minK, mina) has the
    // slope equal to -dRda/dRdK
    double slope = -p_dRda/p_dRdK;
    double gamma = .5*(3*minK/mina - slope);
    double beta;
    _computeBoundingCurve(beta, gamma, false);

    double a_int = mina, K_int = minK;
    int where = _intersectionCurveLeftCorner(beta, gamma, a_int, K_int);
    if (where == 0) {
      // the minimum is on the curve, long to compute, we return this for now:
      return std::sqrt(_R3Dsafe(mina, minK));
    }

    // Let K0 be the point at which R(mina, K) takes its minimum. If there is
    // an intersection and if K_int < K0, the minimum is at (mina, K_int),
    // otherwise it is at (mina, K0).
    double K0 = 2*std::cos(3*std::acos(-1/mina)-M_PI) + (mina*mina-3) * mina;
    if (where == -1)
      return std::sqrt(_R3Dsafe(mina, K0));
    else
      return std::sqrt(_R3Dsafe(mina, std::min(K0, K_int)));
  }
  else {
    return std::sqrt(_R3Dsafe(mina, minK));
  }
}

double _CoeffDataAnisotropy::_computeLowerBoundA() const
{
  fullVector<double> coeffNumerator;
  {
    fullVector<double> coeffq;
    coeffq.setAsProxy(_coeffsMetric, 0);
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
  // compute a lower/upper bounding curve K = beta * a^3 + gamma * a
  // with gamma fixed.

  fullVector<double> J2;
  _bfsDet->getRaiser()->computeCoeff(_coeffsJacDet, _coeffsJacDet, J2);

  fullVector<double> q(_coeffsMetric.size1());
  for (int i = 0; i < q.size(); ++i) {
    q(i) = _coeffsMetric(i, 0);
  }

  fullVector<double> qp2;
  {
    fullMatrix<double> terms_p, terms_qp2;
    terms_p.setAsProxy(_coeffsMetric, 1, _coeffsMetric.size2()-1);
    _bfsMet->getRaiser()->computeCoeff(q, terms_p, terms_p, terms_qp2);
    qp2.resize(terms_qp2.size1(), true);
    for (int i = 0; i < terms_qp2.size1(); ++i) {
      for (int j = 0; j < terms_qp2.size2(); ++j) {
        qp2(i) += terms_qp2(i, j);
      }
    }
  }

  fullVector<double> &coeffNumerator = J2;
  coeffNumerator.axpy(qp2, -gamma);

  fullVector<double> coeffDenominator;
  _bfsMet->getRaiser()->computeCoeff(q, q, q, coeffDenominator);

  beta = _computeBoundRational(coeffNumerator, coeffDenominator, compLowBound);
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

  if (bottomleftCorner) {
    K = std::max(K, .0);
    a = std::max(a, 1.);
  }

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

int _CoeffDataAnisotropy::_intersectionCurveLeftCorner(double beta, double gamma,
                                                       double &a, double &K)
{
  // curve K = beta * a^3 + gamma * a
  // on input, a and K are the bottom left corner
  // on output, a and K are the intersection
  //            return 0 if the intersection is on the horizontal
  //                   1 if the intersection is on the vertical
  //                  -1 if there is no intersection

//  if (beta < 0) {
//    Msg::Warning("Negative curvature, there are 2 or 0 intersections... Is it "
//                 "normal? Anyway, I will compute the left one if it exists.");
////    Msg::Info("%g %g | %g %g", beta, gamma, a, K);
//  }

  const double minK = K;
  K = (beta*a*a + gamma)*a;
  if (K >= minK) return 1;

  // Find the root by Newton-Raphson.
  K = minK;
  if (beta < 0) {
    // When beta < 0, check if the intersection exists:
    double aMaximum = std::sqrt(-gamma/3/beta);
    double KMaximum = (beta * aMaximum*aMaximum + gamma) * aMaximum;
    if (gamma < 0 || aMaximum < a || KMaximum < K) {
//      Msg::Warning("Sorry but there is no intersection");
      return -1;
    }
  }
  else if (beta > 0) {
    // When beta > 0 and aMin > 'a', we must move 'a' to the right of aMin,
    // otherwise we would compute a wrong intersection:
    double aMinimum = std::sqrt(-gamma/3/beta);
    if (aMinimum > a) a += 2*(aMinimum - a);
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
  return 0;
}

double _CoeffDataAnisotropy::_computeAbscissaMinR(double aStart, double K)
{
  // If K == 0, then R == 0. Note, there are less numerical problems when
  // computing R(2, 0) than R(1, 0), so return 2:
  if (K == 0) return 2;

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
    a += da;
  }
  return a;
}

bool _CoeffDataAnisotropy::boundsOk(double minL, double maxL) const
{
  static double tol = 1e-3;
  return minL < tol*1e-3 || (_minB > minL-tol && _minB > minL*(1-100*tol));
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
  if (p < 0 || p == std::numeric_limits<double>::infinity() || J != J) {
    Msg::Error("Wrong argument for 3d Raniso (%g, %g, %g)", q, p, J);
    return -1;
  }

  if (q == 0) return 0;
  if (q > 0 && p == 0) return 1;
  if (q == std::numeric_limits<double>::infinity()) {
    Msg::Warning("q had infinite value in computation of 3D Raniso");
    return 1;
  }

  const double a = q/p;
  const double K = J*J/p/p/p;
  return _R3Dsafe(a, K);
}

double _CoeffDataAnisotropy::_R3Dsafe(double a, double K)
{
  if (a < 1 || K < 0) {
    if (K >= 0 && a > 1-1e-6 && K < 1e-12) {
      return 0;
    }
    Msg::Error("Wrong argument for 3d Raniso (%g, %g)", a, K);
    _CoeffDataAnisotropy::youReceivedAnError();
    return -1;
  }

  if (a == std::numeric_limits<double>::infinity() ||
      K == std::numeric_limits<double>::infinity()) {
    Msg::Warning("a and/or K had infinite value in computation of 3D Raniso");
    return 1;
  }

  const double w = _wSafe(a, K);

  const double phi = std::acos(w) / 3;
  const double R = (a + 2*std::cos(phi + 2*M_PI/3)) / (a + 2*std::cos(phi));
  return std::max(.0, std::min(1., R));
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
      if (w < 1+1e-5 || w < 1+K*1e-14) return 1;
      else {
        Msg::Error("outside the domain w(%g, %g) = %g", a, K, w);
        hasError = true;
      }
    }
    else if (w < -1) {
      if (w > -1-1e-5 || w > -1-K*1e-14) return -1;
      else {
        Msg::Error("outside the domain w(%g, %g) = %g", a, K, w);
        hasError = true;
      }
    }
    return w;
  }
  else {
    youReceivedAnError();
    Msg::Error("Wrong argument for w (%g, %g)", a, K);
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
      Msg::Error("Unknown element type %d, returning -1", el->getType());
      return -1;
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
      _CoeffDataAnisotropy::file << "mina minKfast minKsharp cmin beta_m beta_M beta c_m a_int K_int pdRda pdRdK a0" << std::endl;
      double mina, minKs, minKf, gamma, beta_m, beta_M, beta, c_m;
      double a_int, K_int, p_dRda, p_dRdK, a0;

      mina = _computeLowerBoundA();

      if (el->getDim() == 3) {
        minKs = minKf = _computeLowerBoundK();
        double minK = minKf;
        _moveInsideDomain(mina, minK, true);
        _computePseudoDerivatives(mina, minK, p_dRda, p_dRdK);
        double slope = -p_dRda/p_dRdK;
        gamma = .5*(3*minK/mina - slope);
        _computeBoundingCurve(beta_m, gamma, true);
        _computeBoundingCurve(beta_M, gamma, false);
        beta = -p_dRda/(p_dRdK*3*mina*mina);
        c_m = -1;
        if (p_dRda < 0) {
          a_int = mina, K_int = minK;
          _intersectionCurveLeftCorner(beta_m, gamma, a_int, K_int);
        }
        else {
          a_int = mina, K_int = minK;
          _intersectionCurveLeftCorner(beta_M, gamma, a_int, K_int);
        }
        a0 = _computeAbscissaMinR(mina, minK);
      }
      else {
        minKs = minKf = gamma = beta_m = beta_M = beta = c_m = -1;
        a_int = K_int = p_dRda = p_dRdK = a0 = -1;
      }

      _CoeffDataAnisotropy::file << std::setprecision(15);
      _CoeffDataAnisotropy::file << mina << " " << minKf << " " << minKs << " " << std::endl;
      _CoeffDataAnisotropy::file << gamma << " " << beta_m << " " << beta_M << " " << std::endl;
      _CoeffDataAnisotropy::file << beta << " " << c_m << std::endl;
      _CoeffDataAnisotropy::file << a_int << " " << K_int << std::endl;
      _CoeffDataAnisotropy::file << p_dRda << " " << p_dRdK << std::endl;
      _CoeffDataAnisotropy::file << a0 << std::endl;
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
  int k = 0;
  while (!domains[0]->boundsOk(minL, maxL) && k++ < 1000) {
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
  if (k > 1000) {
    if (domains[0]->getNumMeasure() == 3)
      _CoeffDataAnisotropy::youReceivedAnError();
    Msg::Error("Max subdivision (1000) (size %d)", domains.size());
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
    Msg::Fatal("In order to compute a bound on a rational function, I need "
               "vectors of the same size! (%d vs %d)", numerator.size(),
               denominator.size());
    _CoeffDataAnisotropy::youReceivedAnError();
    return 0;
  }

  // upper and lower bound of the desired bound:
  const double inf = std::numeric_limits<double>::infinity();
  double upperBound = inf;
  double lowerBound = -inf;

  if (!positiveDenom) lower = !lower;

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
