#include "FunctionSpaceScalar.h"

using namespace std;

FunctionSpaceScalar::FunctionSpaceScalar(void){
  hasGrad   = false;
  gradBasis = NULL;
}

FunctionSpaceScalar::~FunctionSpaceScalar(void){
  if(hasGrad)
    delete gradBasis;
}
