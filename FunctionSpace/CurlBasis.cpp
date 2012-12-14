#include "CurlBasis.h"

using namespace std;

CurlBasis::CurlBasis(const BasisVector& other){
  // Reference Space //
  refSpace  = &other.getReferenceSpace();
  nRefSpace = other.getReferenceSpace().getNReferenceSpace();

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
  basis = new vector<vector<const vector<Polynomial>*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const vector<Polynomial>*>(nFunction);

  for(unsigned int s = 0; s < nRefSpace; s++)
    for(unsigned int i = 0; i < nFunction; i++)
      (*(*basis)[s])[i] = 
	new vector<Polynomial>
	(Polynomial::curl(other.getFunction(s, i)));
}

CurlBasis::~CurlBasis(void){
  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete (*(*basis)[i])[j];

    delete (*basis)[i];
  }

  delete basis;
}
