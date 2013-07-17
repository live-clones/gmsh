#include "FunctionSpaceScalar.h"

FunctionSpaceScalar::FunctionSpaceScalar(GroupOfElement& goe,
                                         const Basis& basis){
  scalar = true;
  build(goe, basis);
}

FunctionSpaceScalar::~FunctionSpaceScalar(void){
  // Done by FunctionSpace
}

double FunctionSpaceScalar::
interpolateInABC(const MElement& element,
                 const std::vector<double>& coef,
                 double abc[3]) const{

  // Get Basis Functions //
  const unsigned int nFun = (*basis)[0]->getNFunction();
  fullMatrix<double>  fun(nFun, 1);

  (*basis)[0]->getFunctions(fun, element, abc[0], abc[1], abc[2]);

  // Interpolate (in Reference Place) //
  double val = 0;

  for(unsigned int i = 0; i < nFun; i++)
    val += fun(i, 0) * coef[i];

  // Return Interpolated Value //
  return val;
}
