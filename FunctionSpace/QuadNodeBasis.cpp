#include "QuadNodeBasis.h"
#include "Legendre.h"

using namespace std;

QuadNodeBasis::QuadNodeBasis(const int order){
  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2;

  nVertex = 4;
  nEdge   = 4 * (order - 1);
  nFace   = 0;
  nCell   =     (order - 1) * (order - 1);

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  Polynomial* legendre = new Polynomial[order];
  Polynomial  lifting[4];
  Polynomial  liftingSub[2][4];

  // Legendre Polynomial //
  Legendre::integrated(legendre, order);
  
  // Vertices definig Edges & Permutations //
  const int edgeV[2][4][2] = 
    {
      { {0, 1}, {1, 2}, {2, 3}, {3, 0} },
      { {1, 0}, {2, 1}, {3, 2}, {0, 3} }
    }; 

  // Basis //
  node = new vector<Polynomial*>(nVertex);
  edge = new vector<vector<Polynomial*>*>(2);
  face = new vector<vector<Polynomial*>*>(0);
  cell = new vector<Polynomial*>(nCell);

  (*edge)[0] = new vector<Polynomial*>(nEdge);
  (*edge)[1] = new vector<Polynomial*>(nEdge);


  // Lifting //
  lifting[0] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0));

  lifting[1] = 
    (Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0));

  lifting[2] = 
    (Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0));

  lifting[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0));

  // Lifting Sub //
  for(int e = 0; e < 4; e++){
    liftingSub[0][e] = 
      lifting[edgeV[0][e][0]] - 
      lifting[edgeV[0][e][1]];
    
    liftingSub[1][e] = 
      lifting[edgeV[1][e][0]] - 
      lifting[edgeV[1][e][1]];
  }


  // Vertex Based (Lagrange) // 
  (*node)[0] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)));

  (*node)[1] = 
    new Polynomial((Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)));

  (*node)[2] = 
    new Polynomial((Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0)));

  (*node)[3] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0)));


  // Edge Based //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;

    for(int l = 1; l < order; l++){
      for(int e = 0; e < 4; e++){
	(*(*edge)[c])[i] = 
	  new Polynomial(legendre[l].compose(liftingSub[c][e]) * 
			 (*(*node)[edgeV[c][e][0]] + *(*node)[edgeV[c][e][1]]));

	i++;
      }
    }
  }


  // Cell Based //
  Polynomial px = Polynomial(2, 1, 0, 0);
  Polynomial py = Polynomial(2, 0, 1, 0);

  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);

  unsigned int i = 0;

  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      (*cell)[i] = 
	new Polynomial(legendre[l1].compose(px) * legendre[l2].compose(py));

      i++;
    }
  }


  // Free Temporary Sapce //
  delete[] legendre;
}

QuadNodeBasis::~QuadNodeBasis(void){
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
