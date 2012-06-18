#include "LocalFunctionSpace0Form.h"
#include "BasisScalar.h"
#include "fullMatrix.h"
#include "Exception.h"

LocalFunctionSpace0Form::LocalFunctionSpace0Form(const Basis& basis, 
						 const Element& elem){
  if(!basis.isScalar())
    throw Exception("Can't Create a Scalar Function Space with a Vectorial Basis"); 

  const BasisScalar& b = static_cast<const BasisScalar&>(basis); 

  this->size  = b.getSize(); 
  this->type  = b.getType();  
  this->basis = &(b.getBasis());

  jac = &(elem.getJacobian());
}


LocalFunctionSpace0Form::~LocalFunctionSpace0Form(void){
  // LocalFunctionSpace0From is *NOT* responsible 
  // for deleting 'basis' 
  // It's the Basis job 
}


double LocalFunctionSpace0Form::interpolate(const fullVector<double>& coef, 
					    double x, double y, double z) const{
  double res = 0;

  for(int i = 0; i < size; i++){
    fullVector<double> uv = jac->invMap(x, y);

    res += (*basis)[i].at(uv(0), uv(1), 0.0);
  }

  return res;
}
