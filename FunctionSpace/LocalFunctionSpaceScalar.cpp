#include "LocalFunctionSpaceScalar.h"
#include "BasisScalar.h"
#include "Exception.h"

LocalFunctionSpaceScalar::LocalFunctionSpaceScalar(const Basis& basis){
  if(!basis.isScalar())
    throw Exception("Can't Create a Scalar Function Space with a Vectorial Basis");

  const BasisScalar& b = static_cast<const BasisScalar&>(basis);

  this->scalar = true;
  this->size   = b.getSize();
  this->type   = b.getType(); 
  this->basis  = &(b.getBasis());

  selectTransform(type);
}

LocalFunctionSpaceScalar::~LocalFunctionSpaceScalar(void){
  // LocalFunctionSpaceScalar is *NOT* responsible
  // for deleting 'basis'
  // It's the Basis job
}

double LocalFunctionSpaceScalar::interpolate
(const fullVector<double>& coef,
 double x, double y, double z) const{
  
  if(coef.size() > size)
    throw Exception("To many coeficients for interpolation");

  if(coef.size() < size)
    throw Exception("Not enough coeficients for interpolation");


  fullVector<double> uvw = jac->invMap(x, y);
  double res             = 0;
  
  for(int i = 0; i < size; ++i){
    
    //transform(*jac, uvw(0), uvw(1), 0);
    //! @todo Interpolation rule ...
  }

  return res;
}
