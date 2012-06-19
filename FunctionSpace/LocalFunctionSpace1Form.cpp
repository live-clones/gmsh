#include "LocalFunctionSpace1Form.h"
#include "BasisVector.h"
#include "fullMatrix.h"
#include "Exception.h"

LocalFunctionSpace1Form::LocalFunctionSpace1Form(const Basis& basis, 
						 const Element& elem){
  
  if(basis.isScalar()) 
    throw Exception("Can't Create a Vector Function Space with a Scalar Basis"); 
  
  const BasisVector& b = static_cast<const BasisVector&>(basis); 

  this->size  = b.getSize(); 
  this->type  = b.getType();  
  this->basis = &(b.getBasis());

  jac    = &(elem.getJacobian());
  orient = &(elem.getAllOrientations());
}


LocalFunctionSpace1Form::~LocalFunctionSpace1Form(void){
  // LocalFunctionSpace1From is *NOT* responsible 
  // for deleting 'basis' 
  // It's the Basis job 
}


fullVector<double> LocalFunctionSpace1Form::
interpolate(const fullVector<double>& coef, 
	    double x, double y, double z) const{

  fullVector<double> res(3);
  res(0) = 0;
  res(1) = 0;
  res(2) = 0;
  
  fullVector<double> uv = jac->invMap(x, y);
  
  for(int i = 0; i < size; i++){
    res(0) += (*basis)[i][0].at(uv(0), uv(1), 0.0) * (*orient)[i];
    res(1) += (*basis)[i][1].at(uv(0), uv(1), 0.0) * (*orient)[i];
  }

  fullVector<double> gradRes = jac->grad(res(0), res(1));
  
  res(0) = gradRes(0);
  res(1) = gradRes(1);

  return res;

}
