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

double _CoeffDataScaledJac::cTri = 2/std::sqrt(3);
double _CoeffDataScaledJac::cTet = std::sqrt(2);
double _CoeffDataScaledJac::cPyr = std::sqrt(2);

void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                               const fullMatrix<double> *normals)
{
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
  jfs->getSignedJacobian(nodesXYZ, coeffLag, normals);
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
      sJ = cTet * _coeffsJacDet(i) * (1/v(i,0)/v(i,5)/v(i,1) +
                                      1/v(i,0)/v(i,5)/v(i,2) +
                                      1/v(i,0)/v(i,5)/v(i,3) +
                                      1/v(i,0)/v(i,5)/v(i,4) +
                                      1/v(i,1)/v(i,4)/v(i,0) +
                                      1/v(i,1)/v(i,4)/v(i,2) +
                                      1/v(i,1)/v(i,4)/v(i,3) +
                                      1/v(i,1)/v(i,4)/v(i,5) +
                                      1/v(i,2)/v(i,3)/v(i,0) +
                                      1/v(i,2)/v(i,3)/v(i,1) +
                                      1/v(i,2)/v(i,3)/v(i,4) +
                                      1/v(i,2)/v(i,3)/v(i,5)) / 12;
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
                                      1/v(i,4)/v(i,5)/v(i,2) +
                                      1/v(i,4)/v(i,5)/v(i,3)  ) / 8;
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
  {
    fullVector<double> thirdTerm, coeffNum1, tmp;
    thirdTerm = prox[1];
    thirdTerm.axpy(prox[2]);
    thirdTerm.axpy(prox[3]);
    thirdTerm.axpy(prox[4]);
    raiser->computeCoeff(prox[0], prox[5], thirdTerm, coeffNum1);
    thirdTerm = prox[0];
    thirdTerm.axpy(prox[2]);
    thirdTerm.axpy(prox[3]);
    thirdTerm.axpy(prox[5]);
    raiser->computeCoeff(prox[1], prox[4], thirdTerm, tmp);
    coeffNum1.axpy(tmp);
    thirdTerm = prox[0];
    thirdTerm.axpy(prox[1]);
    thirdTerm.axpy(prox[4]);
    thirdTerm.axpy(prox[5]);
    raiser->computeCoeff(prox[2], prox[3], thirdTerm, tmp);
    coeffNum1.axpy(tmp);

    fullVector<double> coeffDen1, coeffDen2;
    raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDen1);
    raiser->computeCoeff(prox[3], prox[4], prox[5], coeffDen2);

    fullVector<double> &coeffNumerator = tmp;
    bezierBasisRaiser *raiserBis;
    raiserBis = raiser->getRaisedBezierBasis(3)->getRaiser();
    raiserBis->computeCoeff(coeffNum1, _coeffsJacDet, coeffNumerator);
    raiserBis->computeCoeff(coeffDen1, coeffDen2, coeffDenominator);

    result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
    return cTet*result/12;
  }

  case TYPE_PYR:
  {
    fullVector<double> thirdTerm, coeffNum1, tmp;
    thirdTerm = prox[2];
    thirdTerm.axpy(prox[3]);
    thirdTerm.axpy(prox[4]);
    thirdTerm.axpy(prox[5]);
    raiser->computeCoeff(prox[0], prox[1], thirdTerm, coeffNum1);
    thirdTerm = prox[4];
    thirdTerm.axpy(prox[5]);
    raiser->computeCoeff(prox[2], prox[3], thirdTerm, tmp);
    coeffNum1.axpy(tmp);
    thirdTerm = prox[2];
    thirdTerm.axpy(prox[3]);
    raiser->computeCoeff(prox[4], prox[5], thirdTerm, tmp);
    coeffNum1.axpy(tmp);

    fullVector<double> coeffDen1, coeffDen2;
    raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDen1);
    raiser->computeCoeff(prox[3], prox[4], prox[5], coeffDen2);

    fullVector<double> &coeffNumerator = tmp;
    bezierBasisRaiser *raiserBis;
    raiserBis = raiser->getRaisedBezierBasis(3)->getRaiser();
    raiserBis->computeCoeff(coeffNum1, _coeffsJacDet, coeffNumerator);
    raiserBis->computeCoeff(coeffDen1, coeffDen2, coeffDenominator);

    result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
    return cPyr*result/8;
  }

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
