// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <limits>
#include "qualityMeasuresJacobian.h"
#include "FuncSpaceData.h"
#include "MElement.h"
#include "BasisFactory.h"
#include "bezierBasis.h"
#include "JacobianBasis.h"
#include "Numeric.h"
#include "fullMatrix.h"

// For regression tests:
#include "GModel.h"

static const double cTri = 2 / std::sqrt(3);
static const double cTet = std::sqrt(2);
static const double cPyr = 4 * std::sqrt(2);

static void _computeCoeffLengthVectors(const fullMatrix<double> &mat,
                                       fullMatrix<double> &coeff, int type,
                                       int numCoeff = -1)
{
  int sz1 = numCoeff > -1 ? numCoeff : mat.size1();

  switch(type) {
  case TYPE_QUA: coeff.resize(sz1, 2); break;
  case TYPE_TRI: coeff.resize(sz1, 3); break;
  case TYPE_HEX: coeff.resize(sz1, 3); break;
  case TYPE_PRI: coeff.resize(sz1, 4); break;
  case TYPE_TET: coeff.resize(sz1, 6); break;
  case TYPE_PYR: coeff.resize(sz1, 6); break;
  default:
    Msg::Warning("Unknown element type %d for quality computation", type);
    coeff.resize(0, 0);
    return;
  }

  if(type != TYPE_PYR) {
    for(int i = 0; i < sz1; i++) {
      coeff(i, 0) = std::sqrt(pow_int(mat(i, 0), 2) + pow_int(mat(i, 1), 2) +
                              pow_int(mat(i, 2), 2));
      coeff(i, 1) = std::sqrt(pow_int(mat(i, 3), 2) + pow_int(mat(i, 4), 2) +
                              pow_int(mat(i, 5), 2));
    }
    if(type == TYPE_TRI) {
      for(int i = 0; i < sz1; i++) {
        coeff(i, 2) = std::sqrt(pow_int(mat(i, 3) - mat(i, 0), 2) +
                                pow_int(mat(i, 4) - mat(i, 1), 2) +
                                pow_int(mat(i, 5) - mat(i, 2), 2));
      }
    }
    else if(type != TYPE_QUA) { // if 3D
      for(int i = 0; i < sz1; i++) {
        coeff(i, 2) = std::sqrt(pow_int(mat(i, 6), 2) + pow_int(mat(i, 7), 2) +
                                pow_int(mat(i, 8), 2));
      }
    }
    if(type == TYPE_TET || type == TYPE_PRI) {
      for(int i = 0; i < sz1; i++) {
        coeff(i, 3) = std::sqrt(pow_int(mat(i, 3) - mat(i, 0), 2) +
                                pow_int(mat(i, 4) - mat(i, 1), 2) +
                                pow_int(mat(i, 5) - mat(i, 2), 2));
      }
    }
    if(type == TYPE_TET) {
      for(int i = 0; i < sz1; i++) {
        coeff(i, 4) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0), 2) +
                                pow_int(mat(i, 7) - mat(i, 1), 2) +
                                pow_int(mat(i, 8) - mat(i, 2), 2));
        coeff(i, 5) = std::sqrt(pow_int(mat(i, 6) - mat(i, 3), 2) +
                                pow_int(mat(i, 7) - mat(i, 4), 2) +
                                pow_int(mat(i, 8) - mat(i, 5), 2));
      }
    }
  }
  else {
    for(int i = 0; i < sz1; i++) {
      coeff(i, 0) =
        std::sqrt(pow_int(2 * mat(i, 0), 2) + pow_int(2 * mat(i, 1), 2) +
                  pow_int(2 * mat(i, 2), 2));
      coeff(i, 1) =
        std::sqrt(pow_int(2 * mat(i, 3), 2) + pow_int(2 * mat(i, 4), 2) +
                  pow_int(2 * mat(i, 5), 2));
      coeff(i, 2) = std::sqrt(pow_int(mat(i, 6) + mat(i, 0) + mat(i, 3), 2) +
                              pow_int(mat(i, 7) + mat(i, 1) + mat(i, 4), 2) +
                              pow_int(mat(i, 8) + mat(i, 2) + mat(i, 5), 2));
      coeff(i, 3) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0) + mat(i, 3), 2) +
                              pow_int(mat(i, 7) - mat(i, 1) + mat(i, 4), 2) +
                              pow_int(mat(i, 8) - mat(i, 2) + mat(i, 5), 2));
      coeff(i, 4) = std::sqrt(pow_int(mat(i, 6) - mat(i, 0) - mat(i, 3), 2) +
                              pow_int(mat(i, 7) - mat(i, 1) - mat(i, 4), 2) +
                              pow_int(mat(i, 8) - mat(i, 2) - mat(i, 5), 2));
      coeff(i, 5) = std::sqrt(pow_int(mat(i, 6) + mat(i, 0) - mat(i, 3), 2) +
                              pow_int(mat(i, 7) + mat(i, 1) - mat(i, 4), 2) +
                              pow_int(mat(i, 8) + mat(i, 2) - mat(i, 5), 2));
    }
  }
}

static void _computeIGE(const fullVector<double> &det,
                        const fullMatrix<double> &v, fullVector<double> &ige,
                        int type)
{
  int sz = std::min(det.size(), v.size1());
  ige.resize(sz);

  switch(type) {
  case TYPE_QUA:
    for(int i = 0; i < sz; i++) { ige(i) = det(i) / v(i, 0) / v(i, 1); }
    break;
  case TYPE_HEX:
    for(int i = 0; i < sz; i++) {
      ige(i) = det(i) / v(i, 0) / v(i, 1) / v(i, 2);
    }
    break;
  case TYPE_TRI:
    for(int i = 0; i < sz; i++) {
      ige(i) = cTri * det(i) *
               (1 / v(i, 0) / v(i, 1) + 1 / v(i, 0) / v(i, 2) +
                1 / v(i, 1) / v(i, 2)) /
               3;
    }
    break;
  case TYPE_PRI:
    for(int i = 0; i < sz; i++) {
      ige(i) =
        cTri * det(i) *
        (1 / v(i, 0) / v(i, 1) / v(i, 2) + 1 / v(i, 0) / v(i, 3) / v(i, 2) +
         1 / v(i, 1) / v(i, 3) / v(i, 2)) /
        3;
    }
    break;
  case TYPE_TET:
    for(int i = 0; i < sz; i++) {
      ige(i) =
        cTet * det(i) *
        (1 / v(i, 0) / v(i, 5) / v(i, 1) + 1 / v(i, 0) / v(i, 5) / v(i, 2) +
         1 / v(i, 0) / v(i, 5) / v(i, 3) + 1 / v(i, 0) / v(i, 5) / v(i, 4) +
         1 / v(i, 1) / v(i, 4) / v(i, 0) + 1 / v(i, 1) / v(i, 4) / v(i, 2) +
         1 / v(i, 1) / v(i, 4) / v(i, 3) + 1 / v(i, 1) / v(i, 4) / v(i, 5) +
         1 / v(i, 2) / v(i, 3) / v(i, 0) + 1 / v(i, 2) / v(i, 3) / v(i, 1) +
         1 / v(i, 2) / v(i, 3) / v(i, 4) + 1 / v(i, 2) / v(i, 3) / v(i, 5)) /
        12;
    }
    break;
  case TYPE_PYR:
    for(int i = 0; i < sz; i++) {
      ige(i) =
        cPyr * det(i) *
        (1 / v(i, 0) / v(i, 1) / v(i, 2) + 1 / v(i, 0) / v(i, 1) / v(i, 3) +
         1 / v(i, 0) / v(i, 1) / v(i, 4) + 1 / v(i, 0) / v(i, 1) / v(i, 5) +
         1 / v(i, 2) / v(i, 3) / v(i, 4) + 1 / v(i, 2) / v(i, 3) / v(i, 5) +
         1 / v(i, 4) / v(i, 5) / v(i, 2) + 1 / v(i, 4) / v(i, 5) / v(i, 3)) /
        8;
    }
    break;
  }
}

static void _computeICN(const fullVector<double> &det,
                        const fullMatrix<double> &grad, fullVector<double> &icn,
                        int dim)
{
  int sz = std::min(det.size(), grad.size1());
  icn.resize(sz);

  for(int i = 0; i < sz; i++) {
    double p = 0;
    for(int k = 0; k < grad.size2(); ++k) { p += pow_int(grad(i, k), 2); }
    if(dim == 2)
      icn(i) = 2 * det(i) / p;
    else // 3D
      icn(i) = 3 * std::pow(det(i), 2 / 3.) / p;
  }
}

static bool _getQualityFunctionSpace(MElement *el, FuncSpaceData &fsGrad,
                                     FuncSpaceData &fsDet,
                                     int orderSamplingPoints = 0)
{
  const int type = el->getType();

  if(orderSamplingPoints < 1) { // For computing bounds
    const int order = el->getPolynomialOrder();
    const int jacOrder = order * el->getDim();

    switch(type) {
    case TYPE_TRI:
      fsGrad = FuncSpaceData(el, order - 1, false);
      fsDet = FuncSpaceData(el, jacOrder - 2, false);
      break;
    case TYPE_TET:
      fsGrad = FuncSpaceData(el, order - 1, false);
      fsDet = FuncSpaceData(el, jacOrder - 3, false);
      break;
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      fsGrad = FuncSpaceData(el, order, false);
      fsDet = FuncSpaceData(el, jacOrder, false);
      break;
    case TYPE_PYR:
      fsGrad = FuncSpaceData(el, false, order, order - 1, false);
      fsDet = FuncSpaceData(el, false, jacOrder, jacOrder - 3, false);
      break;
    default:
      Msg::Info("Quality measure not implemented for %s",
                el->getName().c_str());
      return false;
    }
  }
  else {
    const int type = el->getType();
    switch(type) {
    case TYPE_TRI:
    case TYPE_TET:
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PRI:
      fsGrad = FuncSpaceData(el, orderSamplingPoints, false);
      fsDet = FuncSpaceData(el, orderSamplingPoints, false);
      break;
    case TYPE_PYR:
      fsGrad = FuncSpaceData(el, true, 1, orderSamplingPoints - 1, false);
      fsDet = FuncSpaceData(el, true, 1, orderSamplingPoints - 1, false);
      break;
    default:
      Msg::Info("Quality measure not implemented for %s",
                el->getName().c_str());
      return false;
    }
  }
  return true;
}

namespace jacobianBasedQuality {

  void minMaxJacobianDeterminant(MElement *el, double &min, double &max,
                                 const fullMatrix<double> *normals, bool debug)
  {
    // Get Jacobian basis
    const JacobianBasis *jfs = el->getJacobianFuncSpace();
    if(!jfs) {
      Msg::Warning("Jacobian function space not implemented for %s",
                   el->getName().c_str());
      min = 99;
      max = -99;
      return;
    }

    // Sample jacobian determinant
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    fullVector<double> coeffLag(jfs->getNumSamplingPnts());
    el->getNodesCoord(nodesXYZ);
    jfs->getSignedJacobian(nodesXYZ, coeffLag, normals);

    // Convert into Bezier coeff
    bezierCoeff::usePools(static_cast<std::size_t>(coeffLag.size()), 0);
    bezierCoeff *bez = new bezierCoeff(jfs->getFuncSpaceData(), coeffLag, 0);

    // Refine coefficients
    std::vector<_coeffData *> domains(1, new _coeffDataJac(bez));
    _subdivideDomains(domains, true, debug);

    // Get extrema
    min = std::numeric_limits<double>::max();
    max = -min;
    for(std::size_t i = 0; i < domains.size(); ++i) {
      min = std::min(min, domains[i]->minB());
      max = std::max(max, domains[i]->maxB());
      domains[i]->deleteBezierCoeff();
      delete domains[i];
    }
  }

  double minIGEMeasure(MElement *el, bool knownValid, bool reversedOk,
                       const fullMatrix<double> *normals, bool debug)
  {
    if(!knownValid) {
      // Computation of the measure should never be performed to invalid
      // elements (for which the measure is 0).
      double jmin, jmax;
      minMaxJacobianDeterminant(el, jmin, jmax, normals);
      if((jmin <= 0 && jmax >= 0) || (jmax < 0 && !reversedOk)) return 0;
    }

    // Get Jacobian and gradient bases
    const GradientBasis *gradBasis;
    const JacobianBasis *jacBasis;
    const int tag = el->getTypeForMSH();
    FuncSpaceData jacMatSpace, jacDetSpace;
    if(!_getQualityFunctionSpace(el, jacMatSpace, jacDetSpace)) return 0;
    gradBasis = BasisFactory::getGradientBasis(tag, jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(tag, jacDetSpace);

    // Sample gradients and jacobian determinant
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    fullVector<double> coeffDetLag(jacBasis->getNumSamplingPnts());
    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    el->getNodesCoord(nodesXYZ);
    jacBasis->getSignedJacobian(nodesXYZ, coeffDetLag, normals);
    gradBasis->getAllGradientsFromNodes(nodesXYZ, coeffMatLag);
    // NB: If coeffDetLag(0) is negative, then all coefficients are negative
    if(coeffDetLag(0) < 0) coeffDetLag.scale(-1);
    if(el->getDim() == 2) coeffMatLag.resize(coeffMatLag.size1(), 6, false);

    // Convert into Bezier coeff
    bezierCoeff::usePools(static_cast<std::size_t>(coeffDetLag.size()),
                          static_cast<std::size_t>(coeffMatLag.size1()) *
                            static_cast<std::size_t>(coeffMatLag.size2()));
    bezierCoeff *bezDet = new bezierCoeff(jacDetSpace, coeffDetLag, 0);
    bezierCoeff *bezMat = new bezierCoeff(jacMatSpace, coeffMatLag, 1);

    // Compute measure and refine
    std::vector<_coeffData *> domains;
    domains.push_back(new _coeffDataIGE(el->getType(), bezDet, bezMat));
    _subdivideDomains(domains, false, debug);

    return _getMinAndDeleteDomains(domains);
  }

  double minICNMeasure(MElement *el, bool knownValid, bool reversedOk,
                       const fullMatrix<double> *normals, bool debug)
  {
    if(!knownValid) {
      // Computation of the measure should never
      // be performed to invalid elements (for which the measure is 0).
      double jmin, jmax;
      minMaxJacobianDeterminant(el, jmin, jmax, normals);
      if((jmin <= 0 && jmax >= 0) || (jmax < 0 && !reversedOk)) return 0;
    }

    // Get Jacobian and gradient bases
    const GradientBasis *gradBasis;
    const JacobianBasis *jacBasis;
    const int tag = el->getTypeForMSH();
    FuncSpaceData jacMatSpace, jacDetSpace;
    if(!_getQualityFunctionSpace(el, jacMatSpace, jacDetSpace)) return 0;
    gradBasis = BasisFactory::getGradientBasis(tag, jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(tag, jacDetSpace);

    // Sample gradients and jacobian determinant
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    fullVector<double> coeffDetLag(jacBasis->getNumSamplingPnts());
    fullMatrix<double> coeffMatLag(gradBasis->getNumSamplingPoints(), 9);
    el->getNodesCoord(nodesXYZ);
    jacBasis->getSignedIdealJacobian(nodesXYZ, coeffDetLag, normals);
    gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, coeffMatLag);
    // NB: If coeffDetLag(0) is negative, then all coefficients are negative
    if(coeffDetLag(0) < 0) coeffDetLag.scale(-1);
    if(el->getDim() == 2) coeffMatLag.resize(coeffMatLag.size1(), 6, false);

    // Convert into Bezier coeff
    bezierCoeff::usePools(static_cast<std::size_t>(coeffDetLag.size()),
                          static_cast<std::size_t>(coeffMatLag.size1()) *
                            static_cast<std::size_t>(coeffMatLag.size2()));
    bezierCoeff *bezDet = new bezierCoeff(jacDetSpace, coeffDetLag, 0);
    bezierCoeff *bezMat = new bezierCoeff(jacMatSpace, coeffMatLag, 1);

    // Compute measure and refine
    std::vector<_coeffData *> domains;
    domains.push_back(new _coeffDataICN(el->getDim(), bezDet, bezMat));
    _subdivideDomains(domains, false, debug);

    return _getMinAndDeleteDomains(domains);
  }

  void sampleJacobianDeterminant(MElement *el, int deg, double &min,
                                 double &max, const fullMatrix<double> *normals)
  {
    fullVector<double> jac;
    sampleJacobianDeterminant(el, deg, jac, normals);

    min = std::numeric_limits<double>::max();
    max = -min;
    for(int i = 0; i < jac.size(); ++i) {
      min = std::min(min, jac(i));
      max = std::max(max, jac(i));
    }
  }

  void sampleIGEMeasure(MElement *el, int deg, double &min, double &max)
  {
    fullVector<double> ige;
    sampleIGEMeasure(el, deg, ige);

    min = std::numeric_limits<double>::max();
    max = -min;
    for(int i = 0; i < ige.size(); ++i) {
      min = std::min(min, ige(i));
      max = std::max(max, ige(i));
    }
  }

  void sampleICNMeasure(MElement *el, int deg, double &min, double &max)
  {
    fullVector<double> icn;
    sampleICNMeasure(el, deg, icn);

    min = std::numeric_limits<double>::max();
    max = -min;
    for(int i = 0; i < icn.size(); ++i) {
      min = std::min(min, icn(i));
      max = std::max(max, icn(i));
    }
  }

  void sampleJacobianDeterminant(MElement *el, int deg, fullVector<double> &jac,
                                 const fullMatrix<double> *normals)
  {
    // Get Jacobian basis
    const JacobianBasis *jacBasis;
    FuncSpaceData sampleSpace;
    if(el->getType() != TYPE_PYR)
      sampleSpace = FuncSpaceData(el, deg, false);
    else
      sampleSpace = FuncSpaceData(TYPE_PYR, true, 1, deg - 1, false);
    jacBasis = BasisFactory::getJacobianBasis(el->getTypeForMSH(), sampleSpace);

    // Sample jacobian determinant
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    el->getNodesCoord(nodesXYZ);
    jac.resize(jacBasis->getNumSamplingPnts());
    jacBasis->getSignedJacobian(nodesXYZ, jac, normals);
  }

  void sampleIGEMeasure(MElement *el, int deg, fullVector<double> &ige)
  {
    // Get Jacobian and gradient bases
    const GradientBasis *gradBasis;
    const JacobianBasis *jacBasis;
    const int tag = el->getTypeForMSH();
    FuncSpaceData jacMatSpace, jacDetSpace;
    if(!_getQualityFunctionSpace(el, jacMatSpace, jacDetSpace, deg)) return;
    gradBasis = BasisFactory::getGradientBasis(tag, jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(tag, jacDetSpace);

    // Sample gradients and jacobian determinant
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    fullVector<double> determinant(jacBasis->getNumSamplingPnts());
    fullMatrix<double> gradients(gradBasis->getNumSamplingPoints(), 9);
    el->getNodesCoord(nodesXYZ);
    jacBasis->getSignedJacobian(nodesXYZ, determinant);
    gradBasis->getAllGradientsFromNodes(nodesXYZ, gradients);
    if(el->getDim() == 2) gradients.resize(gradients.size1(), 6, false);

    // Compute measure
    fullMatrix<double> v;
    const int type = el->getType();
    _computeCoeffLengthVectors(gradients, v, type);
    _computeIGE(determinant, v, ige, type);
  }

  void sampleICNMeasure(MElement *el, int deg, fullVector<double> &icn)
  {
    // Get Jacobian and gradient bases
    const GradientBasis *gradBasis;
    const JacobianBasis *jacBasis;
    const int tag = el->getTypeForMSH();
    FuncSpaceData jacMatSpace, jacDetSpace;
    if(!_getQualityFunctionSpace(el, jacMatSpace, jacDetSpace, deg)) return;
    gradBasis = BasisFactory::getGradientBasis(tag, jacMatSpace);
    jacBasis = BasisFactory::getJacobianBasis(tag, jacDetSpace);

    // Sample gradients and jacobian determinant
    fullMatrix<double> nodesXYZ(el->getNumVertices(), 3);
    fullVector<double> determinant(jacBasis->getNumSamplingPnts());
    fullMatrix<double> gradients(gradBasis->getNumSamplingPoints(), 9);
    el->getNodesCoord(nodesXYZ);
    jacBasis->getSignedIdealJacobian(nodesXYZ, determinant);
    gradBasis->getAllIdealGradientsFromNodes(nodesXYZ, gradients);

    // Compute measure
    _computeICN(determinant, gradients, icn, el->getDim());
  }

  // Virtual class _coeffData
  bool _lessMinB::operator()(_coeffData *cd1, _coeffData *cd2) const
  {
    return cd1->minB() > cd2->minB();
  }

  bool _lessMaxB::operator()(_coeffData *cd1, _coeffData *cd2) const
  {
    return cd1->maxB() < cd2->maxB();
  }

  // Jacobian determinant (for validity of all elements)
  _coeffDataJac::_coeffDataJac(const bezierCoeff *coeffs)
    : _coeffData(), _coeffs(coeffs)
  {
    const bezierCoeff &coeff = (*_coeffs);

    _minL = _maxL = coeff.getCornerCoeff(0);
    for(int i = 1; i < coeff.getNumCornerCoeff(); i++) {
      _minL = std::min(_minL, coeff.getCornerCoeff(i));
      _maxL = std::max(_maxL, coeff.getCornerCoeff(i));
    }
    _minB = _maxB = coeff(0);
    for(int i = 1; i < coeff.getNumCoeff(); i++) {
      _minB = std::min(_minB, coeff(i));
      _maxB = std::max(_maxB, coeff(i));
    }
  }

  bool _coeffDataJac::boundsOk(double minL, double maxL) const
  {
    double tol = std::max(std::abs(minL), std::abs(maxL)) * 1e-3;
    return (minL <= 0 || _minB > 0) && (maxL >= 0 || _maxB < 0) &&
           minL - _minB < tol && _maxB - maxL < tol;
    // NB: First condition implies minL and minB both positive or both negative
  }

  void _coeffDataJac::getSubCoeff(std::vector<_coeffData *> &v) const
  {
    std::vector<bezierCoeff *> sub;
    _coeffs->subdivide(sub);

    v.clear();
    for(std::size_t i = 0; i < sub.size(); i++) {
      v.push_back(new _coeffDataJac(sub[i]));
    }
  }

  void _coeffDataJac::deleteBezierCoeff() { delete _coeffs; }

  // IGE measure (Inverse Gradient Error)
  _coeffDataIGE::_coeffDataIGE(int type, const bezierCoeff *det,
                               const bezierCoeff *mat)
    : _coeffData(), _coeffDet(det), _coeffMat(mat), _type(type)
  {
    _computeAtCorner(_minL, _maxL);

    _minB = 0;
    if(boundsOk(_minL, _maxL))
      return;
    else {
      _minB = _computeLowerBound();
    }
    // computation of _maxB not implemented for now
  }

  bool _coeffDataIGE::boundsOk(double minL, double maxL) const
  {
    static const double tolmin = 1e-3;
    static const double tolmax = 1e-2;
    const double tol = tolmin + (tolmax - tolmin) * std::max(_minB, .0);
    return minL - _minB < tol;
  }

  void _coeffDataIGE::getSubCoeff(std::vector<_coeffData *> &v) const
  {
    std::vector<bezierCoeff *> subD;
    std::vector<bezierCoeff *> subM;
    _coeffDet->subdivide(subD);
    _coeffMat->subdivide(subM);

    v.clear();
    for(std::size_t i = 0; i < subD.size(); i++) {
      v.push_back(new _coeffDataIGE(_type, subD[i], subM[i]));
    }
  }

  void _coeffDataIGE::deleteBezierCoeff()
  {
    delete _coeffDet;
    delete _coeffMat;
  }

  void _coeffDataIGE::_computeAtCorner(double &min, double &max) const
  {
    fullVector<double> det, ige;
    fullMatrix<double> mat;
    _coeffDet->getCornerCoeffs(det);
    _coeffMat->getCornerCoeffs(mat);

    fullMatrix<double> v;
    _computeCoeffLengthVectors(mat, v, _type);
    _computeIGE(det, v, ige, _type);

    min = std::numeric_limits<double>::max();
    max = -min;
    for(int i = 0; i < ige.size(); ++i) {
      min = std::min(min, ige(i));
      max = std::max(max, ige(i));
    }
  }

  double _coeffDataIGE::_computeLowerBound() const
  {
    fullVector<double> det;
    fullMatrix<double> mat;
    _coeffDet->setVectorAsProxy(det);
    _coeffMat->setMatrixAsProxy(mat);

    // Speedup: If one coeff _coeffDet is negative, without bounding
    // J^2/(a^2+b^2), we would get with certainty a negative lower bound.
    // Returning 0.
    for(int i = 0; i < det.size(); ++i) {
      if(det(i) < 0) { return 0; }
    }

    fullMatrix<double> v;
    _computeCoeffLengthVectors(mat, v, _type);

    fullVector<double> prox[6];
    for(int i = 0; i < v.size2(); ++i) { prox[i].setAsProxy(v, i); }

    const bezierBasisRaiser *raiser = _coeffMat->getBezierBasis()->getRaiser();
    fullVector<double> coeffDenominator;
    double result = 0;

    switch(_type) {
    case TYPE_QUA:
      raiser->computeCoeff(prox[0], prox[1], coeffDenominator);
      return _computeBoundRational(det, coeffDenominator, true);

    case TYPE_TRI:
      raiser->computeCoeff(prox[0], prox[1], coeffDenominator);
      result += _computeBoundRational(det, coeffDenominator, true);
      raiser->computeCoeff(prox[0], prox[2], coeffDenominator);
      result += _computeBoundRational(det, coeffDenominator, true);
      raiser->computeCoeff(prox[1], prox[2], coeffDenominator);
      result += _computeBoundRational(det, coeffDenominator, true);
      // The bound is not sharp, which can lead to a lot of subdivision. This
      // can be avoided by bounding the total function instead of bounding each
      // rational function and summing the three bounds. This is done for
      // TYPE_TET and TYPE_PYR. In order to do that for triangles, it is
      // needed to implement raising bezier coefficient from different spaces.
      // If computation of sharp bounds is implemented, change also function
      // _getMinAndDeleteDomains(..) so that it returns minB instead of some
      // combination of minB and minL.
      return cTri * result / 3;

    case TYPE_HEX:
      raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
      return _computeBoundRational(det, coeffDenominator, true);

    case TYPE_PRI:
      raiser->computeCoeff(prox[0], prox[1], prox[2], coeffDenominator);
      result += _computeBoundRational(det, coeffDenominator, true);
      raiser->computeCoeff(prox[0], prox[3], prox[2], coeffDenominator);
      result += _computeBoundRational(det, coeffDenominator, true);
      raiser->computeCoeff(prox[1], prox[3], prox[2], coeffDenominator);
      result += _computeBoundRational(det, coeffDenominator, true);
      // Same comment than for TYPE_TRI.
      return cTri * result / 3;

    case TYPE_TET: {
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
      const bezierBasisRaiser *raiserBis =
        _coeffDet->getBezierBasis()->getRaiser();
      raiserBis->computeCoeff(coeffNum1, det, coeffNumerator);
      raiserBis->computeCoeff(coeffDen1, coeffDen2, coeffDenominator);

      result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
      return cTet * result / 12;
    }

    case TYPE_PYR: {
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
      const bezierBasisRaiser *raiserBis =
        _coeffDet->getBezierBasis()->getRaiser();
      raiserBis->computeCoeff(coeffNum1, det, coeffNumerator);
      raiserBis->computeCoeff(coeffDen1, coeffDen2, coeffDenominator);

      result = _computeBoundRational(coeffNumerator, coeffDenominator, true);
      return cPyr * result / 8;
    }

    default: Msg::Info("Unknown element type %d for IGE", _type); return -1;
    }
  }

  // ICN measure (Inverse Condition Number)
  _coeffDataICN::_coeffDataICN(int dim, const bezierCoeff *det,
                               const bezierCoeff *mat)
    : _coeffData(), _coeffDet(det), _coeffMat(mat), _dim(dim)
  {
    _computeAtCorner(_minL, _maxL);

    _minB = 0;
    if(boundsOk(_minL, _maxL))
      return;
    else {
      _minB = _computeLowerBound();
    }
    // _maxB not used for now
  }

  bool _coeffDataICN::boundsOk(double minL, double maxL) const
  {
    static const double tolmin = 1e-3;
    static const double tolmax = 1e-2;
    const double tol = tolmin + (tolmax - tolmin) * std::max(_minB, .0);
    return minL - _minB < tol;
  }

  void _coeffDataICN::getSubCoeff(std::vector<_coeffData *> &v) const
  {
    std::vector<bezierCoeff *> subD;
    std::vector<bezierCoeff *> subM;
    _coeffDet->subdivide(subD);
    _coeffMat->subdivide(subM);

    v.clear();
    for(std::size_t i = 0; i < subD.size(); i++) {
      v.push_back(new _coeffDataICN(_dim, subD[i], subM[i]));
    }
  }

  void _coeffDataICN::deleteBezierCoeff()
  {
    delete _coeffDet;
    delete _coeffMat;
  }

  void _coeffDataICN::_computeAtCorner(double &min, double &max) const
  {
    fullVector<double> det, icn;
    fullMatrix<double> mat;
    _coeffDet->getCornerCoeffs(det);
    _coeffMat->getCornerCoeffs(mat);
    _computeICN(det, mat, icn, _dim);

    min = std::numeric_limits<double>::max();
    max = -min;
    for(int i = 0; i < icn.size(); i++) {
      min = std::min(min, icn(i));
      max = std::max(max, icn(i));
    }
  }

  double _coeffDataICN::_computeLowerBound() const
  {
    fullVector<double> det;
    fullMatrix<double> mat;
    _coeffDet->setVectorAsProxy(det);
    _coeffMat->setMatrixAsProxy(mat);

    // Speedup: If one coeff _coeffDet is negative, we would get
    // a negative lower bound. For now, returning 0.
    for(int i = 0; i < det.size(); ++i) {
      if(det(i) < 0) { return 0; }
    }

    const bezierBasisRaiser *raiser = _coeffMat->getBezierBasis()->getRaiser();
    if(_dim == 2) {
      fullVector<double> coeffDenominator;
      {
        fullVector<double> prox;
        for(int k = 0; k < mat.size2(); ++k) {
          prox.setAsProxy(mat, k);
          fullVector<double> tmp;
          raiser->computeCoeff(prox, prox, tmp);
          if(k == 0) coeffDenominator.resize(tmp.size());
          coeffDenominator.axpy(tmp, 1);
        }
      }
      return 2 * _computeBoundRational(det, coeffDenominator, true);
    }

    // 3D element
    fullVector<double> coeffDenominator;
    {
      // P: coefficients of function that bound from above the Frobenius norm of
      // J (elements of P are automatically set to 0)
      fullVector<double> P(mat.size1());
      for(int i = 0; i < mat.size1(); ++i) {
        for(int k = 0; k < mat.size2(); ++k) { P(i) += mat(i, k) * mat(i, k); }
        P(i) = std::sqrt(P(i));
      }
      raiser->computeCoeff(P, P, P, coeffDenominator);
    }

    const double boundFraction =
      _computeBoundRational(det, coeffDenominator, true);

    return 3 * std::pow(boundFraction * boundFraction, 1. / 3);
  }

  // Miscellaneous
  template <typename Comp>
  void _subdivideDomainsMinOrMax(std::vector<_coeffData *> &domains,
                                 double &minL, double &maxL, bool debug)
  {
    std::vector<_coeffData *> subs;
    make_heap(domains.begin(), domains.end(), Comp());
    int k = 0;
    const int max_subdivision = 1000;
    while(!domains[0]->boundsOk(minL, maxL) && k + 1 < max_subdivision) {
      _coeffData *cd = domains[0];
      pop_heap(domains.begin(), domains.end(), Comp());
      domains.pop_back();
      cd->getSubCoeff(subs);
      cd->deleteBezierCoeff();
      delete cd;

      for(std::size_t i = 0; i < subs.size(); i++) {
        minL = std::min(minL, subs[i]->minL());
        maxL = std::max(maxL, subs[i]->maxL());
        domains.push_back(subs[i]);
        push_heap(domains.begin(), domains.end(), Comp());
      }
      ++k;
    }
    if(debug) { std::cout << "Number of subdivisions: " << k << std::endl; }
    else if(k == max_subdivision) {
      Msg::Error("Max subdivision (%d) (size domains %d)", max_subdivision,
                 domains.size());
    }
  }

  void _subdivideDomains(std::vector<_coeffData *> &domains, bool alsoMax,
                         bool debug)
  {
    if(domains.empty()) {
      Msg::Warning("Empty vector in Bezier subdivision, nothing to do");
      return;
    }
    double minL = domains[0]->minL();
    double maxL = domains[0]->maxL();
    for(std::size_t i = 1; i < domains.size(); ++i) {
      minL = std::min(minL, domains[i]->minL());
      maxL = std::max(maxL, domains[i]->maxL());
    }

    _subdivideDomainsMinOrMax<_lessMinB>(domains, minL, maxL, debug);
    if(alsoMax)
      _subdivideDomainsMinOrMax<_lessMaxB>(domains, minL, maxL, debug);
  }

  double _getMinAndDeleteDomains(std::vector<_coeffData *> &domains)
  {
    double minB = domains[0]->minB();
    double minL = domains[0]->minL();
    domains[0]->deleteBezierCoeff();
    delete domains[0];
    for(std::size_t i = 1; i < domains.size(); ++i) {
      minB = std::min(minB, domains[i]->minB());
      minL = std::min(minL, domains[i]->minL());
      domains[i]->deleteBezierCoeff();
      delete domains[i];
    }
    double fact = .5 * (minB + minL);
    // This is done because, for triangles and prisms, currently, the
    // computation of bounds is not sharp. It can happen than the IGE measure
    // is very close to 1 everywhere but that the bound is close to 1 only
    // after a huge amount of subdivision. In this case, it is better to
    // return minL instead of minB. The best solution would be to implement
    // sharp bounds for triangles and prisms, see function
    // _coeffDataIGE::_computeLowerBound(..). If it is done, change this to
    // return minB.
    return fact * minL + (1 - fact) * minB;
  }

  double _computeBoundRational(const fullVector<double> &numerator,
                               const fullVector<double> &denominator,
                               bool lower, bool positiveDenom)
  {
    if(numerator.size() != denominator.size()) {
      Msg::Error("In order to compute a bound on a rational function, I need "
                 "vectors of the same size! (%d vs %d)",
                 numerator.size(), denominator.size());
      return 0;
    }

    // upper and lower bound of the desired bound:
    const double inf = std::numeric_limits<double>::max();
    double upperBound = inf;
    double lowerBound = -inf;

    if(!positiveDenom) lower = !lower;

    if(lower) {
      // if lower is true, we seek: bound * den <= num
      for(int i = 0; i < numerator.size(); ++i) {
        if(denominator(i) == 0) {
          if(numerator(i) < 0) return -inf;
        }
        else if(denominator(i) > 0) {
          upperBound = std::min(upperBound, numerator(i) / denominator(i));
        }
        else {
          lowerBound = std::max(lowerBound, numerator(i) / denominator(i));
        }
      }
      if(lowerBound > upperBound)
        return -inf;
      else
        return upperBound;
    }
    else {
      // otherwise, we seek: bound * den >= num
      for(int i = 0; i < numerator.size(); ++i) {
        if(denominator(i) == 0) {
          if(numerator(i) > 0) return inf;
        }
        else if(denominator(i) > 0) {
          lowerBound = std::max(lowerBound, numerator(i) / denominator(i));
        }
        else {
          upperBound = std::min(upperBound, numerator(i) / denominator(i));
        }
      }
      if(lowerBound > upperBound)
        return inf;
      else
        return lowerBound;
    }
  }

  void testAllMeasuresAllElements()
  {
    GModel *m = GModel::current();
    std::set<GEntity *, GEntityPtrFullLessThan> entities;
    for(auto it = m->firstRegion(); it != m->lastRegion(); it++)
      entities.insert(*it);
    for(auto it = m->firstFace(); it != m->lastFace(); it++)
      entities.insert(*it);
    for(auto it = m->firstEdge(); it != m->lastEdge(); it++)
      entities.insert(*it);

    for(auto it = entities.begin(); it != entities.end(); ++it) {
      unsigned num = (*it)->getNumMeshElements();
      for(unsigned i = 0; i < num; ++i) {
        MElement *el = (*it)->getMeshElement(i);
        testAllMeasures(el);
      }
    }
  }

  void testAllMeasures(MElement *el, const fullMatrix<double> *normals)
  {
    static int orderSampling = 50;
    static double tol = 1e-5;
    double minSampled, maxSampled, minAlgo, maxAlgo;
    std::cout << std::endl;
    std::cout << "Element #" << el->getNum() << " (type: " << el->getType();
    std::cout << ", " << el->getTypeForMSH() << ")" << std::endl;

    sampleJacobianDeterminant(el, orderSampling, minSampled, maxSampled,
                              normals);
    minMaxJacobianDeterminant(el, minAlgo, maxAlgo, normals, true);
    std::cout << "JAC sampled: " << minSampled << " " << maxSampled;
    std::cout << " v.s. computed: " << minAlgo << " " << maxAlgo << std::endl;
    if(minSampled < minAlgo * (1 - tol) || maxSampled > maxAlgo * (1 + tol)) {
      std::cout << "ERROR sampled measure outside the bounds" << std::endl;
      return;
    }

    if(minAlgo <= 0 && maxAlgo >= 0) {
      std::cout << "GOOD (Invalid)" << std::endl;
      return;
    }

    sampleIGEMeasure(el, orderSampling, minSampled, maxSampled);
    minAlgo = minIGEMeasure(el, true, true, normals, true);
    std::cout << "IGE sampled: " << minSampled << " " << maxSampled;
    std::cout << " v.s. computed: " << minAlgo << " -" << std::endl;
    if(minSampled < minAlgo * (1 - tol)) {
      std::cout << "ERROR sampled measure smaller than the bound" << std::endl;
      return;
    }

    sampleICNMeasure(el, orderSampling, minSampled, maxSampled);
    minAlgo = minICNMeasure(el, true, true, normals, true);
    std::cout << "ICN sampled: " << minSampled << " " << maxSampled;
    std::cout << " v.s. computed: " << minAlgo << " -" << std::endl;
    if(minSampled < minAlgo * (1 - tol)) {
      std::cout << "ERROR sampled measure smaller than the bound" << std::endl;
      return;
    }
    std::cout << "GOOD" << std::endl;
  }

} // end namespace jacobianBasedQuality
