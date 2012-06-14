#include "LocalFunctionSpaceScalar.h"
#include "BasisScalar.h"
#include "Exception.h"

LocalFunctionSpaceScalar::LocalFunctionSpaceScalar(const Basis& basis){
  if(!basis.isScalar())
    throw Exception("Can't Create a Scalar Function Space with a Vectorial Basis");

  const BasisScalar& b = static_cast<const BasisScalar&>(basis);

  this->scalar = true;
  this->size   = b.getSize();
  this->basis  = &(b.getBasis());
}

LocalFunctionSpaceScalar::~LocalFunctionSpaceScalar(void){
  // LocalFunctionSpaceScalar is *NOT* responsible
  // for deleting 'basis'
  // It's the Basis job
}
