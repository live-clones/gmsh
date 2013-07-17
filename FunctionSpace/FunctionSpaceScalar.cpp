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
interpolate(const MElement& element,
            const std::vector<double>& coef,
            const fullVector<double>& xyz) const{

  // Get ABC Space coordinate //
  double abc[3];
  (*basis)[0]->getReferenceSpace().mapFromXYZtoABC(element, xyz, abc);

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

double FunctionSpaceScalar::
interpolateInRefSpace(const MElement& element,
                      const std::vector<double>& coef,
                      const fullVector<double>& uvw) const{

  // Get ABC Space coordinate //
  double abc[3];
  (*basis)[0]->getReferenceSpace().mapFromUVWtoABC(element, uvw, abc);

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
