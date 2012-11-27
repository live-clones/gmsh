#include "FunctionSpaceScalar.h"

using namespace std;

FunctionSpaceScalar::FunctionSpaceScalar(void){
  hasGrad   = false;
  gradBasis = NULL;
  
  locPreEvaluated  = false;
  gradPreEvaluated = false;  
  evalLoc          = NULL;
  evalGrad         = NULL;
}

FunctionSpaceScalar::~FunctionSpaceScalar(void){
  if(hasGrad)
    delete gradBasis;
  
  if(locPreEvaluated)
    delete evalLoc;

  if(gradPreEvaluated)
    delete evalGrad;
}

void FunctionSpaceScalar::
preEvaluateLocalFunctions(fullMatrix<double>& points){
  // Delete Old Struct (if any) //
  if(locPreEvaluated)
    delete evalLoc;

  // New Struct //
  evalLoc = new EvaluatedBasisScalar(*basisScalar, points);

  // PreEvaluated //
  locPreEvaluated = true;
}

void FunctionSpaceScalar::
preEvaluateGradLocalFunctions(fullMatrix<double>& points){
  // Got Grad Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasGrad){
    gradBasis = new GradBasis(*basisScalar);
    hasGrad   = true;
  }

  // Delete Old Struct (if any) //
  if(gradPreEvaluated)
    delete evalGrad;

  // New Struct //
  evalGrad = new EvaluatedBasisVector(*gradBasis, points);

  // PreEvaluated //
  gradPreEvaluated = true;
}
