#include "Mapper.h"
#include "FunctionSpaceVector.h"

FunctionSpaceVector::FunctionSpaceVector(const GroupOfElement& goe,
                                         const Basis& basis){
  scalar = false;
  build(goe, basis);
}

FunctionSpaceVector::~FunctionSpaceVector(void){
  // Done by FunctionSpace
}

fullVector<double> FunctionSpaceVector::
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

  // Get Jacobian //
  fullMatrix<double>  invJac(3, 3);
  eelement.getJacobian(uvw[0], uvw[1], uvw[2], invJac);
  invJac.invertInPlace();

  // Get Basis Functions //
  fullMatrix<double>* fun =
    (*basis)[0]->getFunctions(element, uvw[0], uvw[1], uvw[2]);

  const unsigned int nFun = fun->size1();

  // Interpolate (in Reference Place) //
  fullVector<double> val(3);
  val(0) = 0;
  val(1) = 0;
  val(2) = 0;

  for(unsigned int i = 0; i < nFun; i++){
    val(0) += (*fun)(i, 0) * coef[i];
    val(1) += (*fun)(i, 1) * coef[i];
    val(2) += (*fun)(i, 2) * coef[i];
  }

  // Return Interpolated Value //
  delete fun;
  return Mapper::grad(val, invJac);
}

fullVector<double> FunctionSpaceVector::
interpolateInRefSpace(const MElement& element,
		      const std::vector<double>& coef,
		      const fullVector<double>& uvw) const{

  // Const Cast For MElement //
  MElement& eelement =
    const_cast<MElement&>(element);

  // Get Jacobian //
  fullMatrix<double>  invJac(3, 3);
  eelement.getJacobian(uvw(0), uvw(1), uvw(2), invJac);
  invJac.invertInPlace();

  // Get Basis Functions //
  fullMatrix<double>* fun =
    (*basis)[0]->getFunctions(element, uvw(0), uvw(1), uvw(2));

  const unsigned int nFun = fun->size1();


  // Interpolate (in Reference Place) //
  fullVector<double> val(3);
  val(0) = 0;
  val(1) = 0;
  val(2) = 0;

  for(unsigned int i = 0; i < nFun; i++){
    val(0) += (*fun)(i, 0) * coef[i];
    val(1) += (*fun)(i, 1) * coef[i];
    val(2) += (*fun)(i, 2) * coef[i];
  }

  // Return Interpolated Value //
  delete fun;
  return Mapper::grad(val, invJac);
}
