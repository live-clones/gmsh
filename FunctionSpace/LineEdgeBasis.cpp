#include "LineEdgeBasis.h"
#include "Legendre.h"

using namespace std;

LineEdgeBasis::LineEdgeBasis(int order){
  // Set Basis Type //
  this->order = order;
  
  type = 1;
  dim  = 1;

  nVertex = 0;
  nEdge   = (order + 1);
  nFace   = 0;
  nCell   = 0;

  nEdgeClosure = 2;
  nFaceClosure = 0;

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const int   orderPlus   = order + 1;
  Polynomial* intLegendre = new Polynomial[orderPlus];

  const Polynomial plusOneHalf(+0.5, 0, 0, 0);
  const Polynomial minusOneHalf(-0.5, 0, 0, 0);
  const Polynomial zero(0, 0, 0, 0);

  const Polynomial x[2] = {
    Polynomial(+1, 1, 0, 0),
    Polynomial(-1, 1, 0, 0)
  };

  // Legendre Polynomial //
  Legendre::integrated(intLegendre, orderPlus);

  // Permutations //
  const int permutation[2] = {0, 1};

  // Basis //
  node = new vector<vector<Polynomial>*>(nVertex);
  edge = new vector<vector<vector<Polynomial>*>*>(nEdgeClosure);
  face = new vector<vector<vector<Polynomial>*>*>(nFaceClosure);
  cell = new vector<vector<Polynomial>*>(nCell);
  
  (*edge)[0] = new vector<vector<Polynomial>*>(nEdge);
  (*edge)[1] = new vector<vector<Polynomial>*>(nEdge);


  // Edge Based (Nedelec) // 
  (*(*edge)[0])[0]        = new vector<Polynomial>(3);
  (*(*edge)[0])[0]->at(0) = plusOneHalf; 
  (*(*edge)[0])[0]->at(1) = zero; 
  (*(*edge)[0])[0]->at(2) = zero; 

  (*(*edge)[1])[0]        = new vector<Polynomial>(3);
  (*(*edge)[1])[0]->at(0) = minusOneHalf; 
  (*(*edge)[1])[0]->at(1) = zero; 
  (*(*edge)[1])[0]->at(2) = zero; 


  // Edge Based (High Order) //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;
    
    for(int l = 1; l < orderPlus; l++){
      (*(*edge)[c])[i + 1] = 
	new vector<Polynomial>((intLegendre[l].compose(x[permutation[c]])).gradient());
      
      i++;
    }
  }


  // Free Temporary Space //
  delete[] intLegendre;
}

LineEdgeBasis::~LineEdgeBasis(void){
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
