#include "TriNodeBasis.h"
#include "Legendre.h"

using namespace std;

TriNodeBasis::TriNodeBasis(int order){
  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 2;

  nVertex = 3;
  nEdge   = 3 * (order - 1);
  nFace   = 0;
  nCell   =     (order - 1) * (order - 2) / 2;

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const int orderMinus = order - 1;

  Polynomial* legendre    = new Polynomial[order];
  Polynomial* intLegendre = new Polynomial[order];

  Polynomial lagrangeSum[3];
  Polynomial lagrangeSub[2][3];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Vertices definig Edges & Permutations //
  const int edgeV[2][3][2] = 
    {
      { {0, 1}, {1, 2}, {2, 0} },
      { {1, 0}, {2, 1}, {0, 2} }
    }; 

  // Basis //
  node = new vector<Polynomial*>(nVertex);
  edge = new vector<vector<Polynomial*>*>(2);
  face = new vector<vector<Polynomial*>*>(0);
  cell = new vector<Polynomial*>(nCell);

  (*edge)[0] = new vector<Polynomial*>(nEdge);
  (*edge)[1] = new vector<Polynomial*>(nEdge);


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
  for(int e = 0; e < 3; e++)
    lagrangeSum[e] = 
      *(*node)[edgeV[0][e][0]] + 
      *(*node)[edgeV[0][e][1]];

  // Lagrange Sub //
  for(int e = 0; e < 3; e++){
    lagrangeSub[0][e] = 
      *(*node)[edgeV[0][e][0]] - 
      *(*node)[edgeV[0][e][1]];
    
    lagrangeSub[1][e] = 
      *(*node)[edgeV[1][e][0]] - 
      *(*node)[edgeV[1][e][1]];
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
