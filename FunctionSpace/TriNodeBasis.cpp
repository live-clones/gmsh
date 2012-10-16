#include "TriNodeBasis.h"
#include "Legendre.h"

using namespace std;

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
  Polynomial  lagrangeSub[2][3];

  // Classical and Intrated-Scaled Legendre Polynomial //
  const int orderMinus = order - 1;

  Legendre::legendre(legendre, orderMinus);
  Legendre::intScaled(intLegendre, order);
 

  // Basis //
  node = new vector<const Polynomial*>(nVertex);
  edge = new vector<vector<const Polynomial*>*>(2);
  face = new vector<vector<const Polynomial*>*>(0);
  cell = new vector<const Polynomial*>(nCell);

  (*edge)[0] = new vector<const Polynomial*>(nEdge);
  (*edge)[1] = new vector<const Polynomial*>(nEdge);


  // Vertex Based (Lagrange) //
  (*node)[0] = 
    new Polynomial(Polynomial(1, 0, 0, 0) - 
		   Polynomial(1, 1, 0, 0) - 
		   Polynomial(1, 0, 1, 0));

  (*node)[1] = 
    new Polynomial(Polynomial(1, 1, 0, 0));

  (*node)[2] = 
    new Polynomial(Polynomial(1, 0, 1, 0));
 

  // Lagrange Sum //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3)
     lagrangeSum[i] = *(*node)[i] + *(*node)[j];

  // Lagrange Sub //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3){
    lagrangeSub[0][i] = *(*node)[j] - *(*node)[i];
    lagrangeSub[1][i] = *(*node)[i] - *(*node)[j];
  }

 
  // Edge Based //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;

    for(int l = 1; l < order; l++){
      for(int e = 0; e < 3; e++){
	(*(*edge)[c])[i] = 
	  new Polynomial(intLegendre[l].compose(lagrangeSub[c][e], lagrangeSum[e]));
	
	i++;
      }
    }
  }


  // Cell Based //
  Polynomial p             = *(*node)[2] * 2 - Polynomial(1, 0, 0, 0);
  const int  orderMinusTwo = order - 2;

  unsigned int i = 0;
  
  for(int l1 = 1; l1 < orderMinus; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinusTwo; l2++){
      (*cell)[i] = 
	new Polynomial(intLegendre[l1].compose(lagrangeSub[0][0], lagrangeSum[0]) * 
		       legendre[l2].compose(p) * *(*node)[2]);

      i++;
    }
  }
  
  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
}

TriNodeBasis::~TriNodeBasis(void){
  // Vertex Based //
  for(int i = 0; i < nVertex; i++)
    delete (*node)[i];
  
  delete node;


  // Edge Based //
  for(int c = 0; c < 2; c++){
    for(int i = 0; i < nEdge; i++)
      delete (*(*edge)[c])[i];
    
    delete (*edge)[c];
  }
  
  delete edge;


  // Face Based //
  delete face;


  // Cell Based //
  for(int i = 0; i < nCell; i++)
    delete (*cell)[i];

  delete cell;
}
