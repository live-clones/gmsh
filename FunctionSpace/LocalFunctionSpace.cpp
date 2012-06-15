#include "LocalFunctionSpace.h"
#include "Exception.h"

LocalFunctionSpace::LocalFunctionSpace(void){
  
}

LocalFunctionSpace::~LocalFunctionSpace(void){
  
}

void LocalFunctionSpace::selectTransform(int form){
  switch(form){
  case 0:
    transform = LocalFunctionSpace::form0;
    break;

  case 1:
    transform = LocalFunctionSpace::form1;
    break;

  case 2:
    throw Exception("Mapping of 2-form not implemented");
    break;

  case 3:
    throw Exception("Mapping of 3-form not implemented");
    break;
 
  default:
    throw Exception ("Unknow %d-form", form);
    break;
  }
}
