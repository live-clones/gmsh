#include "LocalFunctionSpaceVector.h"
#include "BasisVector.h"
#include "Exception.h"

LocalFunctionSpaceVector::LocalFunctionSpaceVector(const Basis& basis){
  if(basis.isScalar())
    throw Exception("Can't Create a Vector Function Space with a Scalar Basis");

  const BasisVector& b = static_cast<const BasisVector&>(basis);

  this->scalar = false;
  this->size   = b.getSize();
  this->basis  = &(b.getBasis());
}

LocalFunctionSpaceVector::~LocalFunctionSpaceVector(void){
  // LocalFunctionSpaceVector is *NOT* responsible
  // for deleting 'basis'
  // It's the Basis job
}
