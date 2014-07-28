#include "Mapper.h"
#include "FunctionSpaceVector.h"

FunctionSpaceVector::
FunctionSpaceVector(const GroupOfElement& goe, size_t order){
  // Temp vector
  std::vector<const GroupOfElement*> tmp(1);
  tmp[0] = &goe;

  // Init
  init(tmp, order, "hierarchical");
}

FunctionSpaceVector::
FunctionSpaceVector(const std::vector<const GroupOfElement*>& goe,
                    size_t order){
  // Init
  init(goe, order, "hierarchical");
}

FunctionSpaceVector::
FunctionSpaceVector(const GroupOfElement& goe,
                    size_t order, std::string family){
  // Temp vector
  std::vector<const GroupOfElement*> tmp(1);
  tmp[0] = &goe;

  // Init
  init(tmp, order, family);
}

FunctionSpaceVector::
FunctionSpaceVector(const std::vector<const GroupOfElement*>& goe,
                    size_t order, std::string family){
  // Init
  init(goe, order, family);
}

FunctionSpaceVector::~FunctionSpaceVector(void){
  // Done by FunctionSpace
}

void FunctionSpaceVector::init(const std::vector<const GroupOfElement*>& goe,
                               size_t order, std::string family){
  // Init
  this->scalar = false;
  this->form   = 1;
  this->order  = order;

  // Build FunctionSpace
  const size_t nGoe = goe.size();
  for(size_t i = 0; i < nGoe; i++)
    build(*goe[i], family);

  // Next Offset for next FunctionSpace
  nxtOffset = findMaxType() + 1;
}

fullVector<double> FunctionSpaceVector::
interpolateInABC(const MElement& element,
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

  basis.getFunctions(fun, element, abc[0], abc[1], abc[2]);

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

fullVector<double> FunctionSpaceVector::
interpolateDerivativeInABC(const MElement& element,
                           const std::vector<double>& coef,
                           double abc[3]) const{
  // Get Jacobian //
  fullMatrix<double> jac(3, 3);
  double det =
    ReferenceSpaceManager::getJacobian(element, abc[0], abc[1], abc[2], jac);

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
  Mapper::hDiv(val, 0, 0, jac, det, map);
  return map;
}
