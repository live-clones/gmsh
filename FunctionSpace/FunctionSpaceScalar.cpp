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

  // Const Cast For MElement //
  MElement& eelement =
    const_cast<MElement&>(element);

  // Get Reference coordinate //
  double phys[3] = {xyz(0), xyz(1), xyz(2)};
  double uvw[3];

  eelement.xyz2uvw(phys, uvw);

  // Get Basis Functions //
  fullMatrix<double>* fun =
    (*basis)[0]->getFunctions(element, uvw[0], uvw[1], uvw[2]);

  const unsigned int nFun = fun->size1();

  // Interpolate (in Reference Place) //
  double val = 0;

  for(unsigned int i = 0; i < nFun; i++)
    val += (*fun)(i, 0) * coef[i];

  // Return Interpolated Value //
  delete fun;
  return val;
}

double FunctionSpaceScalar::
interpolateInRefSpace(const MElement& element,
		      const std::vector<double>& coef,
		      const fullVector<double>& uvw) const{

  // Get Basis Functions //
  fullMatrix<double>* fun =
    (*basis)[0]->getFunctions(element, uvw(0), uvw(1), uvw(2));

  const unsigned int nFun = fun->size1();

  // Interpolate (in Reference Place) //
  double val = 0;

  for(unsigned int i = 0; i < nFun; i++)
    val += (*fun)(i, 0) * coef[i];

  // Return Interpolated Value //
  delete fun;
  return val;
}
