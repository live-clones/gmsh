#include "Mapper.h"
#include "Exception.h"
#include "FunctionSpaceScalar.h"

FunctionSpaceScalar::FunctionSpaceScalar(const GroupOfElement& goe,
                                         size_t order){
  if(order == 0)
    throw Exception("%s: %s",
                    "FunctionSpaceScalar",
                    "Cannot have a order 0 scalar function space");

  this->scalar = true;
  this->form   = 0;
  this->order  = order;

  build(goe, "hierarchical");
}

FunctionSpaceScalar::FunctionSpaceScalar(const GroupOfElement& goe,
                                         size_t order, std::string family){
  if(order == 0)
    throw Exception("%s: %s",
                    "FunctionSpaceScalar",
                    "Cannot have a order 0 scalar function space");
  this->scalar = true;
  this->form   = 0;
  this->order  = order;

  build(goe, family);
}

FunctionSpaceScalar::~FunctionSpaceScalar(void){
  // Done by FunctionSpace
}

double FunctionSpaceScalar::interpolateInABC(const MElement& element,
                                             const std::vector<double>& coef,
                                             double abc[3]) const{
  // Get Basis Functions //
  const Basis& basis = getBasis(element);
  const size_t nFun  = basis.getNFunction();
  fullMatrix<double> fun(nFun, 1);

  basis.getFunctions(fun, element, abc[0], abc[1], abc[2]);

  // Interpolate (in Reference Place) //
  double val = 0;

  for(size_t i = 0; i < nFun; i++)
    val += fun(i, 0) * coef[i];

  // Return Interpolated Value //
  return val;
}

fullVector<double> FunctionSpaceScalar::
interpolateDerivativeInABC(const MElement& element,
                           const std::vector<double>& coef,
                           double abc[3]) const{
  // Get Jacobian //
  fullMatrix<double> invJac(3, 3);
  ReferenceSpaceManager::getJacobian(element, abc[0], abc[1], abc[2], invJac);
  invJac.invertInPlace();

  // Get Basis Functions //
  const Basis& basis = getBasis(element);
  const size_t nFun  = basis.getNFunction();
  fullMatrix<double> fun(nFun, 3);

  basis.getDerivative(fun, element, abc[0], abc[1], abc[2]);

  // Interpolate (in Reference Place) //
  fullMatrix<double> val(1, 3);
  val(0, 0) = 0;
  val(0, 1) = 0;
  val(0, 2) = 0;

  for(size_t i = 0; i < nFun; i++){
    val(0, 0) += fun(i, 0) * coef[i];
    val(0, 1) += fun(i, 1) * coef[i];
    val(0, 2) += fun(i, 2) * coef[i];
  }

  // Return Interpolated Value //
  fullVector<double> map(3);
  Mapper::hCurl(val, 0, 0, invJac, map);
  return map;
}
