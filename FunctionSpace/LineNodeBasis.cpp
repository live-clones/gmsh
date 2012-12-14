#include "LineNodeBasis.h"
#include "LineReferenceSpace.h"
#include "Legendre.h"

using namespace std;

LineNodeBasis::LineNodeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new LineReferenceSpace;
  nRefSpace = refSpace->getNReferenceSpace();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 1;

  nVertex   = 2;
  nEdge     = (order - 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  Polynomial* intLegendre = new Polynomial[order];

  const Polynomial x[2] = {
    Polynomial(+1, 1, 0, 0),
    Polynomial(-1, 1, 0, 0)
  };

  // Legendre Polynomial //
  Legendre::integrated(intLegendre, order);

  // Basis //
  basis = new vector<vector<const Polynomial*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const Polynomial*>(nFunction);

  // Vertex Based (Lagrange) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    (*(*basis)[s])[0] = 
      new Polynomial(Polynomial(0.5, 0, 0, 0) - 
		     Polynomial(0.5, 1, 0, 0));
    
    (*(*basis)[s])[1] = 
      new Polynomial(Polynomial(0.5, 0, 0, 0) + 
		     Polynomial(0.5, 1, 0, 0));
  }

  // Edge Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nVertex;
    
    for(unsigned int l = 1; l < order; l++){
      (*(*basis)[s])[i] = 
	new Polynomial(intLegendre[l].compose(x[(*(*edgeV[s])[0])[0]]));
      
      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] intLegendre;
}

LineNodeBasis::~LineNodeBasis(void){
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete (*(*basis)[i])[j];

    delete (*basis)[i];
  }

  delete basis;
}
