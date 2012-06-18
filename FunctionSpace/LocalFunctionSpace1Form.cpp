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

  //double res = 0;
  
  for(int i = 0; i < size; i++){
    //fullVector<double> uv = jac->invMap(x, y);

    //res += (*basis)[i].at(uv(0), uv(1), 0.0);
  }

  //return res;

}
