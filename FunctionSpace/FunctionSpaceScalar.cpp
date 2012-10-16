#include "FunctionSpaceScalar.h"
#include "Exception.h"

using namespace std;

FunctionSpaceScalar::~FunctionSpaceScalar(void){
}

const vector<const Polynomial*> FunctionSpaceScalar::
getLocalFunctions(const MElement& element) const{

  // Get Closure //
  map<const MElement*, vector<bool>*>::iterator it = 
    edgeClosure->find(&element);

  if(it == edgeClosure->end())
    throw Exception("Element not found for closure");

  vector<bool>* closure   = it->second;

  // Get Basis //
  const vector       <const Polynomial*>&   node = getBasis(element).getNodeFunctions();
  const vector<vector<const Polynomial*>*>& edge = getBasis(element).getEdgeFunctions();
  const vector       <const Polynomial*>&   cell = getBasis(element).getCellFunctions();

  // Get Functions //
  unsigned int i           = 0;
  const unsigned int nNode = node.size();
  const unsigned int nEdge = edge[0]->size();
  const unsigned int nCell = cell.size();

  vector<const Polynomial*> fun(getBasis(element).getSize());
  
  // Vertex Based //
  for(unsigned int j = 0; j < nNode; j++){
    fun[i] = node[j];
    i++;
  }

  // Edge Based //
  for(unsigned int j = 0; j < nEdge; j++){
    if((*closure)[i])
      fun[i] = (*edge[0])[j];

    else
      fun[i] = (*edge[1])[j];

    i++;
  }

  // Vertex Based //
  for(unsigned int j = 0; j < nCell; j++){
    fun[i] = cell[j];
    i++;
  }

  // Return 
  return fun;
}
