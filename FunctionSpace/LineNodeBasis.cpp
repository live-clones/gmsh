#include "LineNodeBasis.h"
#include "Legendre.h"

using namespace std;

LineNodeBasis::LineNodeBasis(int order){
  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 1;

  nVertex = 2;
  nEdge   = (order - 1);
  nFace   = 0;
  nCell   = 0;

  nEdgeClosure = 2;
  nFaceClosure = 0;

  size = nVertex + nEdge + nFace + nCell;

  // Legendre Polynomial //
  Polynomial* intLegendre = new Polynomial[order];
  Legendre::integrated(intLegendre, order);

  // Basis //
  node = new vector<Polynomial*>(nVertex);
  edge = new vector<vector<Polynomial*>*>(nEdgeClosure);
  face = new vector<vector<Polynomial*>*>(nFaceClosure);
  cell = new vector<Polynomial*>(nCell);

  (*edge)[0] = new vector<Polynomial*>(nEdge);
  (*edge)[1] = new vector<Polynomial*>(nEdge);


  // Vertex Based (Lagrange) //
  (*node)[0] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - 
		    Polynomial(1, 1, 0, 0)) *
		   0.5);
  
  (*node)[1] = 
    new Polynomial((Polynomial(1, 0, 0, 0) + 
		    Polynomial(1, 1, 0, 0)) *
		   0.5);
  
  
  // Edge Based //
  const int permutation[2] = {0, 1};
  const Polynomial    x[2] = {
    Polynomial(+1, 1, 0, 0),
    Polynomial(-1, 1, 0, 0)
  };
  
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;
    
    for(int l = 1; l < order; l++){
      (*(*edge)[c])[i] = 
	new Polynomial(intLegendre[l].compose(x[permutation[c]]));
      
      i++;
    }
  }


  // Free Temporary Sapce //
  delete[] intLegendre;
}

LineNodeBasis::~LineNodeBasis(void){
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
  delete cell;
}
