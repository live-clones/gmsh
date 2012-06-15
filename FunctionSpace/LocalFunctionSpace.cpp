#include "LocalFunctionSpace.h"
#include "Exception.h"

LocalFunctionSpace::LocalFunctionSpace(void){
  
}

LocalFunctionSpace::~LocalFunctionSpace(void){
  
}

void LocalFunctionSpace::selectTransform(int form){
  switch(form){
  case 0:
    transform = jac::map;
    break;

  case 1:
    transform = jac::grad;
    break;

  case 2:
    throw Exception("Mapping of 2-form not implemented");
    break;

  case 3:
    throw Exception("Mapping of 3-form not implemented");
    break;
 
  default:
    throw Exception ("Unknow %d-form", from);
    break;
  }
}
