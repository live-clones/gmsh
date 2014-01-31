#include "Mapper.h"
#include "FunctionSpaceVector.h"

FunctionSpaceVector::FunctionSpaceVector(const GroupOfElement& goe,
                                         size_t order){
  this->scalar = false;
  this->form   = 1;
  this->order  = order;

  build(goe, "hierarchical");
}

FunctionSpaceVector::FunctionSpaceVector(const GroupOfElement& goe,
                                         size_t order, std::string family){
  this->scalar = false;
  this->form   = 1;
  this->order  = order;

  build(goe, family);
}

FunctionSpaceVector::~FunctionSpaceVector(void){
  // Done by FunctionSpace
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
