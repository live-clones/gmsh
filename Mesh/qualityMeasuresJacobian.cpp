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


namespace jacobianBasedQuality {

bool _lessMinB::operator()(_CoeffData *cd1, _CoeffData *cd2) const
{
  return cd1->minB() > cd2->minB();
}

bool _lessMaxB::operator()(_CoeffData *cd1, _CoeffData *cd2) const
{
  return cd1->maxB() < cd2->maxB();
}

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
  ((fullVector<double>)_coeffs).setOwnData(true);

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
  const fullVector<double> *p1 = &_coeffsJacDet;
  const fullMatrix<double> *p2 = &_coeffsJacMat;
  ((fullVector<double>*)p1)->setOwnData(true);
  ((fullMatrix<double>*)p2)->setOwnData(true);

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
  fullVector<double> coeffNumerator;
  _bfsDet->getRaiser()->reorder(_coeffsJacDet, coeffNumerator);

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

  return _computeBoundRational(coeffNumerator, coeffDenominator, true);
}

bool _CoeffDataScaledJac::boundsOk(double minL, double maxL) const
{
  double tol = 1e-3;
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

void minMaxJacobianDeterminant(MElement *el, double &min, double &max)
{
  const JacobianBasis *jfs = el->getJacobianFuncSpace();
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el->getTypeForMSH());
    return;
  }

  fullMatrix<double> nodesXYZ(jfs->getNumMapNodes(), 3);
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

void minScaledJacobian(MElement *el, double &min)
{
  const int jacOrder = el->getPolynomialOrder() * el->getDim();
  const JacobianBasis *jfs = el->getJacobianFuncSpace(jacOrder);
  if (!jfs) {
    Msg::Error("Jacobian function space not implemented for type of element %d", el->getTypeForMSH());
    return;
  }

  fullMatrix<double> nodesXYZ(jfs->getNumMapNodes(), 3);
  el->getNodesCoord(nodesXYZ);

  fullVector<double> coeffDetLag(jfs->getNumJacNodes());
  fullVector<double> coeffDetBez(jfs->getNumJacNodes());
  jfs->getSignedJacobian(nodesXYZ, coeffDetLag);
  jfs->lag2Bez(coeffDetLag, coeffDetBez);

  const GradientBasis *gfs = BasisFactory::getGradientBasis(el->getTypeForMSH());

  fullMatrix<double> coeffMatLag(gfs->getNumSamplingPoints(), 9);
  fullMatrix<double> coeffMatBez(gfs->getNumSamplingPoints(), 9);
  gfs->getAllGradientsFromNodes(nodesXYZ, coeffMatLag);
  gfs->lag2Bez(coeffMatLag, coeffMatBez);

  if (el->getDim() == 2) coeffMatBez.resize(coeffMatBez.size1(), 6);

  std::vector<_CoeffData*> domains;
  domains.push_back(
      new _CoeffDataScaledJac(coeffDetBez, coeffMatBez, jfs->getBezier(),
                             gfs->getBezier(), 0)
  );

  _subdivideDomains(domains);

  min = domains[0]->minB();
  delete domains[0];
  for (unsigned int i = 1; i < domains.size(); ++i) {
    min = std::min(min, domains[i]->minB());
    delete domains[i];
  }

  Msg::Info("=====================================================min %g", min);
}

double minScaledJacobian(MElement *el)
{
  double min;
  minScaledJacobian(el, min);
  return min;
}

double _computeBoundRational(const fullVector<double> &numerator,
                             const fullVector<double> &denominator,
                             bool lower, bool positiveDenom)
{
  //sleep(1);
  //numerator.print("numerator");
  //denominator.print("denominator");
  if (numerator.size() != denominator.size()) {
    Msg::Error("In order to compute a bound on a rational function, I need "
               "vectors of the same size!");
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
