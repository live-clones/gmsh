#include "TriNodeBasis.h"
#include "TriReferenceSpace.h"
#include "Legendre.h"

using namespace std;

TriNodeBasis::TriNodeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new TriReferenceSpace;
  nRefSpace = refSpace->getNPermutation();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  // Set BasisTwo Type //
  this->order = order;
  
  type = 0;
  dim  = 2;

  nVertex   = 3;
  nEdge     = 3 * (order - 1);
  nFace     = 0;
  nCell     =     (order - 1) * (order - 2) / 2;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Some Space //
  const int orderMinus = order - 1;

  Polynomial* legendre    = new Polynomial[order];
  Polynomial* intLegendre = new Polynomial[order];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Lagrange Polynomial //
  const Polynomial lagrange[3] = 
    {
      Polynomial(Polynomial(1, 0, 0, 0) - 
		 Polynomial(1, 1, 0, 0) - 
		 Polynomial(1, 0, 1, 0)),
 
      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0))
    };

  // Basis //
  basis = new Polynomial**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    basis[s] = new Polynomial*[nFunction];

  // Vertex Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    basis[s][0] = new Polynomial(lagrange[0]);
    basis[s][1] = new Polynomial(lagrange[1]);
    basis[s][2] = new Polynomial(lagrange[2]);
  }
  
  // Edge Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nVertex;

    for(int e = 0; e < 3; e++){
      for(unsigned int l = 1; l < order; l++){
	basis[s][i] = 
	  new Polynomial(intLegendre[l].compose(lagrange[(*(*edgeV[s])[e])[1]] -
						lagrange[(*(*edgeV[s])[e])[0]]
						, 
						lagrange[(*(*edgeV[s])[e])[0]] +
						lagrange[(*(*edgeV[s])[e])[1]]));
	i++;
      }
    }
  }
  
  // Cell Based //
  const Polynomial p = (lagrange[2] * 2) - Polynomial(1, 0, 0, 0);
  const int orderMinusTwo = order - 2;
  
  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nVertex + nEdge;
    
    for(int l1 = 1; l1 < orderMinus; l1++){
      for(int l2 = 0; l2 + l1 - 1 < orderMinusTwo; l2++){
	basis[s][i] = 
	  new Polynomial(intLegendre[l1].compose(lagrange[1] - lagrange[0], 
						 lagrange[1] + lagrange[0]) 
			 * 
			 legendre[l2].compose(p) * lagrange[2]);
	
	i++;
      }
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
}

TriNodeBasis::~TriNodeBasis(void){
  // ReferenceSpace //
  delete refSpace;

  // Basis //
  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++)
      delete basis[i][j];

    delete[] basis[i];
  }

  delete[] basis;
}
