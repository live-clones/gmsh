#include "FunctionSpaceVector.h"

using namespace std;

FunctionSpaceVector::FunctionSpaceVector(void){
  hasCurl   = false;
  curlBasis = NULL;

  hasDiv   = false;
  divBasis = NULL;

  locPreEvaluated  = false;
  curlPreEvaluated = false;  
  divPreEvaluated  = false;  
  evalLoc          = NULL;
  evalCurl         = NULL;
  evalDiv          = NULL;
}

FunctionSpaceVector::~FunctionSpaceVector(void){
  if(hasCurl)
    delete curlBasis;

  if(hasDiv)
    delete divBasis;

  if(locPreEvaluated)
    delete evalLoc;

  if(curlPreEvaluated)
    delete evalCurl;

  if(divPreEvaluated)
    delete evalDiv;
}

void FunctionSpaceVector::
preEvaluateLocalFunctions(fullMatrix<double>& points){
  // Delete Old Struct (if any) //
  if(locPreEvaluated)
    delete evalLoc;

  // New Struct //
  evalLoc = new EvaluatedBasisVector(*basisVector, points);

  // PreEvaluated //
  locPreEvaluated = true;
}

void FunctionSpaceVector::
preEvaluateCurlLocalFunctions(fullMatrix<double>& points){
  // Got Curl Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasCurl){
    curlBasis = new CurlBasis(*basisVector);
    hasCurl   = true;
  }

  // Delete Old Struct (if any) //
  if(curlPreEvaluated)
    delete evalCurl;

  // New Struct //
  evalCurl = new EvaluatedBasisVector(*curlBasis, points);

  // PreEvaluated //
  curlPreEvaluated = true;
}

void FunctionSpaceVector::
preEvaluateDivLocalFunctions(fullMatrix<double>& points){
  // Got Div Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasDiv){
    divBasis = new DivBasis(*basisVector);
    hasDiv   = true;
  }

  // Delete Old Struct (if any) //
  if(divPreEvaluated)
    delete evalDiv;

  // New Struct //
  evalDiv = new EvaluatedBasisScalar(*divBasis, points);

  // PreEvaluated //
  divPreEvaluated = true;
}
