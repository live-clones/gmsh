#include "TriNodeBasis.h"
#include "Legendre.h"

TriNodeBasis::TriNodeBasis(const int order){
  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 2;

  nVertex = 3;
  nEdge   = 3 * (order - 1);
  nFace   = 0;
  nCell   =     (order - 1) * (order - 2) / 2;

  size    = (order + 1) * (order + 2) / 2;

  // Alloc Temporary Space //
  Polynomial* legendre     = new Polynomial[order];
  Polynomial* intLegendre  = new Polynomial[order];

  Polynomial  lagrangeSum[3];
  Polynomial  lagrangeSub[3];
  Polynomial rLagrangeSub[3];

  // Classical and Intrated-Scaled Legendre Polynomial //
  const int orderMinus = order - 1;

  Legendre::legendre(legendre, orderMinus);
  Legendre::intScaled(intLegendre, order);
 

  // Basis (& revert) //
     basis = new std::vector<const Polynomial*>(size);
  revBasis = new std::vector<const Polynomial*>(size);

  // Vertex Based (Lagrange) // 
  (*basis)[0] = 
    new Polynomial(Polynomial(1, 0, 0, 0) - 
		   Polynomial(1, 1, 0, 0) - 
		   Polynomial(1, 0, 1, 0));

  (*basis)[1] = 
    new Polynomial(Polynomial(1, 1, 0, 0));

  (*basis)[2] = 
    new Polynomial(Polynomial(1, 0, 1, 0));

  // Vertex Based (revert) //
  for(int i = 0; i < 3; i++)
    (*revBasis)[i] = (*basis)[i];  

  // Lagrange Sum (& revert) //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3)
     lagrangeSum[i] = *(*basis)[i] + *(*basis)[j];

  // Lagrange Sub (& revert) //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3){
     lagrangeSub[i] = *(*basis)[j] - *(*basis)[i];
    rLagrangeSub[i] = *(*basis)[i] - *(*basis)[j];
  }

  
  // Edge Based //
  int i = 3;

  for(int l = 1; l < order; l++){
    for(int e = 0; e < 3; e++){
      (*basis)[i] = new Polynomial(
	intLegendre[l].compose(lagrangeSub[e], lagrangeSum[e]));

      (*revBasis)[i] = new Polynomial(
	intLegendre[l].compose(rLagrangeSub[e], lagrangeSum[e]));
      
      i++;
    }
  }

  // Cell Based //
  Polynomial p             = *(*basis)[2] * 2 - Polynomial(1, 0, 0, 0);
  const int  orderMinusTwo = order - 2;
  
  for(int l1 = 1; l1 < orderMinus; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinusTwo; l2++){
      (*basis)[i] = new Polynomial(
	intLegendre[l1].compose(lagrangeSub[0], lagrangeSum[0]) * 
	legendre[l2].compose(p) * *(*basis)[2]);
      
      (*revBasis)[i] = (*basis)[i];
      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
}

TriNodeBasis::~TriNodeBasis(void){
  for(int i = 0; i < size; i++){
    delete (*basis)[i];
    
    if(i >= nVertex && i < nVertex + nEdge)
      delete (*revBasis)[i];
  }

  delete basis;
  delete revBasis;
}
