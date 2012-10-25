#include "FunctionSpaceVector.h"

using namespace std;

FunctionSpaceVector::FunctionSpaceVector(void){
  hasCurl   = false;
  curlBasis = NULL;

  hasDiv   = false;
  divBasis = NULL;
}

FunctionSpaceVector::~FunctionSpaceVector(void){
  if(hasCurl)
    delete curlBasis;

  if(hasDiv)
    delete divBasis;
}
