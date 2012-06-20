#include "FunctionSpace.h"

using namespace std;

FunctionSpace::FunctionSpace(void){
  ebLookUp = new map<Element*, Basis*, ElementComparator>;
}

FunctionSpace::~FunctionSpace(void){
  delete ebLookUp;
}

