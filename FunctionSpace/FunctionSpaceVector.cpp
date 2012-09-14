#include "FunctionSpaceVector.h"
#include "Exception.h"

using namespace std;

FunctionSpaceVector::~FunctionSpaceVector(void){
}

  const vector<const vector<Polynomial>*> FunctionSpaceVector::
getLocalFunctions(const MElement& element) const{

  // Get Closure //
  map<const MElement*, vector<bool>*>::iterator it = 
    edgeClosure->find(&element);

  if(it == edgeClosure->end())
    throw Exception("Element not found for closure");

  vector<bool>* closure   = it->second;
  const unsigned int size = closure->size();

  // Get Basis //
  const vector<const vector<Polynomial>*>& basis = 
    getBasis(element).getFunctions(0);
  
  const vector<const vector<Polynomial>*>& revBasis = 
    getBasis(element).getFunctions(1);

  // Get Functions //
  vector<const vector<Polynomial>*> fun(size);
  
  for(unsigned int i = 0; i < size; i++)
    if((*closure)[i])
      fun[i] = basis[i];

    else
      fun[i] = revBasis[i];

  // Return 
  return fun;
}
