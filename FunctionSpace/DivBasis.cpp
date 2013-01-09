#include "DivBasis.h"

using namespace std;

DivBasis::DivBasis(const BasisVector& other){
  // Reference Space //
  refSpace  = &other.getReferenceSpace();
  nRefSpace = other.getReferenceSpace().getNPermutation();

  // Set Basis Type //
  order = other.getOrder() - 1;
  
  type = other.getType();
  dim  = other.getDim();
  
  nVertex   = other.getNVertexBased();
  nEdge     = other.getNEdgeBased();
  nFace     = other.getNFaceBased();
  nCell     = other.getNCellBased();
  nFunction = other.getNFunction();
  
  // Basis //
  basis = new vector<vector<const Polynomial*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const Polynomial*>(nFunction);

  for(unsigned int s = 0; s < nRefSpace; s++)
    for(unsigned int i = 0; i < nFunction; i++)
      (*(*basis)[s])[i] = 
	new Polynomial
	(Polynomial::divergence(other.getFunction(s, i)));
}

DivBasis::~DivBasis(void){
  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete (*(*basis)[i])[j];
    
    delete (*basis)[i];
  }
  
  delete basis;
}
