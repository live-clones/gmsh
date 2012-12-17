#include "TetNodeBasis.h"
#include "TetReferenceSpace.h"
#include "Legendre.h"

using namespace std;

TetNodeBasis::TetNodeBasis(unsigned int order){
  // Reference Space //
  refSpace  = new TetReferenceSpace;
  nRefSpace = refSpace->getNReferenceSpace();

  const vector<const vector<const vector<unsigned int>*>*>&
    edgeV = refSpace->getAllEdge();

  const vector<const vector<const vector<unsigned int>*>*>&
    faceV = refSpace->getAllFace();

  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 3;

  nVertex   = 4;
  nEdge     = 6 * (order - 1);
  nFace     = 2 * (order - 1) * (order - 2);
  nCell     =     (order - 1) * (order - 2) * (order - 3) / 6;
  nFunction = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const unsigned int orderMinus      = order - 1;
  const unsigned int orderMinusTwo   = order - 2;
  const unsigned int orderMinusThree = order - 3;

  Polynomial* legendre     = new Polynomial[order];
  Polynomial* sclLegendre  = new Polynomial[order];
  Polynomial* intLegendre  = new Polynomial[order];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinus);
  Legendre::scaled(sclLegendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Lagrange Polynomial //
  const Polynomial lagrange[4] = 
    {
      Polynomial(Polynomial(1, 0, 0, 0) - 
		 Polynomial(1, 1, 0, 0) - 
		 Polynomial(1, 0, 1, 0) - 
		 Polynomial(1, 0, 0, 1)),
 
      Polynomial(Polynomial(1, 1, 0, 0)),

      Polynomial(Polynomial(1, 0, 1, 0)),
      
      Polynomial(Polynomial(1, 0, 0, 1))
    };


  // Basis //
  basis = new vector<vector<const Polynomial*>*>(nRefSpace);

  for(unsigned int s = 0; s < nRefSpace; s++)
    (*basis)[s] = new vector<const Polynomial*>(nFunction);

  // Vertex Based //
  for(unsigned int s = 0; s < nRefSpace; s++){
    (*(*basis)[s])[0] = new Polynomial(lagrange[0]);
    (*(*basis)[s])[1] = new Polynomial(lagrange[1]);
    (*(*basis)[s])[2] = new Polynomial(lagrange[2]);
    (*(*basis)[s])[3] = new Polynomial(lagrange[3]);
  }

  // Edge Based //
  for(unsigned int s = 0; s < 2; s++){
    unsigned int i = nVertex;

    for(unsigned int l = 1; l < order; l++){
      for(unsigned int e = 0; e < 6; e++){
	(*(*basis)[s])[i] = 
	  new Polynomial(intLegendre[l].compose
			 (lagrange[(*(*edgeV[s])[e])[0]] - 
			  lagrange[(*(*edgeV[s])[e])[1]]
			  , 
			  lagrange[(*(*edgeV[s])[e])[0]] + 
			  lagrange[(*(*edgeV[s])[e])[1]]));
	
	i++;
      }
    }
  }

  // Face Based //
  for(unsigned int s = 0; s < 6; s++){
    unsigned int i = nVertex + nEdge;

    for(unsigned int l1 = 1; l1 < orderMinus; l1++){
      for(unsigned int l2 = 0; l1 + l2 - 1 < orderMinusTwo; l2++){
	for(unsigned int f = 0; f < 4; f++){
	  Polynomial sum = 
	    lagrange[(*(*faceV[s])[f])[0]] + 
	    lagrange[(*(*faceV[s])[f])[1]] + 
	    lagrange[(*(*faceV[s])[f])[2]];	  
	  
	  (*(*basis)[s])[i] = 
	    new Polynomial(intLegendre[l1].compose
			   (lagrange[(*(*faceV[s])[f])[0]] - 
			    lagrange[(*(*faceV[s])[f])[1]]
			    , 
			    lagrange[(*(*faceV[s])[f])[0]] + 
			    lagrange[(*(*faceV[s])[f])[1]]) 
			   
			   * 
			   
			   lagrange[(*(*faceV[s])[f])[2]] 
			   * 
			   sclLegendre[l2].compose
			   (lagrange[(*(*faceV[s])[f])[2]] * 2 - sum, sum));
	
	  i++;
	}
      }
    }
  }
  
  // Cell Based //
  const Polynomial oneMinusFour         = Polynomial(1, 0, 0, 0) - lagrange[3];
  const Polynomial twoThreeOneMinusFour = lagrange[2] * 2 - oneMinusFour;
  const Polynomial twoFourMinusOne      = lagrange[3] * 2 - Polynomial(1, 0, 0, 0);

  const Polynomial sub = lagrange[0] - lagrange[1];
  const Polynomial add = lagrange[0] + lagrange[1];

  for(unsigned int s = 0; s < nRefSpace; s++){
    unsigned int i = nVertex + nEdge + nFace;
  
    for(unsigned int l1 = 1; l1 < orderMinusTwo; l1++){
      for(unsigned int l2 = 0; l2 + l1 - 1 < orderMinusThree; l2++){
	for(unsigned int l3 = 0; l3 + l2 + l1 - 1 < orderMinusThree; l3++){
	  
	  (*(*basis)[s])[i] = 
	    new Polynomial(intLegendre[l1].compose(sub, add)             * 
			   lagrange[2]                                   * 		 
			   sclLegendre[l2].compose(twoThreeOneMinusFour, 
						   oneMinusFour)         *
			   lagrange[3]                                   *
			   legendre[l3].compose(twoFourMinusOne));
	
	  i++;
	}
      }
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] sclLegendre;
  delete[] intLegendre;
}

TetNodeBasis::~TetNodeBasis(void){
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
