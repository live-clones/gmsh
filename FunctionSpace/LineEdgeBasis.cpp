#include "LineEdgeBasis.h"
#include "LineReferenceSpace.h"
#include "Legendre.h"

using namespace std;

LineEdgeBasis::LineEdgeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new LineReferenceSpace;
  nRefSpace = refSpace->getNReferenceSpace();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  // Set Basis Type //
  this->order = order;
  
  type = 1;
  dim  = 1;

  nVertex   = 0;
  nEdge     = (order + 1);
  nFace     = 0;
  nCell     = 0;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const unsigned int orderPlus = order + 1;
  Polynomial* intLegendre = new Polynomial[orderPlus];

  vector<Polynomial> first(3);
  first[0] = Polynomial(+0.5, 0, 0, 0);
  first[1] = Polynomial( 0  , 0, 0, 0);
  first[2] = Polynomial( 0  , 0, 0, 0);

  vector<Polynomial> second(3);
  second[0] = Polynomial(-0.5, 0, 0, 0);
  second[1] = Polynomial( 0  , 0, 0, 0);
  second[2] = Polynomial( 0  , 0, 0, 0);

  const Polynomial x[2] = {
    Polynomial(+1, 1, 0, 0),
    Polynomial(-1, 1, 0, 0)
  };

  // Legendre Polynomial //
  Legendre::integrated(intLegendre, orderPlus);

  // Basis //
  basis = new vector<vector<const vector<Polynomial>*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const vector<Polynomial>*>(nFunction);

  // Edge Based (Nedelec) // 
  (*(*basis)[0])[0] = new vector<Polynomial>(first);
  (*(*basis)[1])[0] = new vector<Polynomial>(second);

  // Edge Based (High Order) //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = 1;
    
    for(unsigned int l = 1; l < orderPlus; l++){
      (*(*basis)[s])[i] = 
	new vector<Polynomial>((intLegendre[l].compose
				(x[(*(*edgeV[s])[0])[0]])).gradient());
      
      i++;
    }
  }

  // Free Temporary Space //
  delete[] intLegendre;
}

LineEdgeBasis::~LineEdgeBasis(void){
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
