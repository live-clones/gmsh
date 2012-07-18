#include "FunctionSpace.h"

using namespace std;

FunctionSpace::FunctionSpace(void){
  ebLookUp = new map<MElement*, Basis*, ElementComparator>;
}

FunctionSpace::~FunctionSpace(void){
  delete ebLookUp;
}

