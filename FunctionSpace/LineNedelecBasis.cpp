#include "LineNedelecBasis.h"
#include "Legendre.h"

using namespace std;

LineNedelecBasis::LineNedelecBasis(void){
  // Set Basis Type //
  order = 1;
  
  type = 1;
  dim  = 1;

  nVertex = 0;
  nEdge   = 1;
  nFace   = 0;
  nCell   = 0;

  nEdgeClosure = 2;
  nFaceClosure = 0;

  size = 1;

  // Alloc Temporary Space //
  const Polynomial plusOneHalf(+0.5, 0, 0, 0);
  const Polynomial minusOneHalf(-0.5, 0, 0, 0);
  const Polynomial zero(0, 0, 0, 0);

  // Basis //
  node = new vector<vector<Polynomial>*>(nVertex);
  edge = new vector<vector<vector<Polynomial>*>*>(nEdgeClosure);
  face = new vector<vector<vector<Polynomial>*>*>(nFaceClosure);
  cell = new vector<vector<Polynomial>*>(nCell);
  
  (*edge)[0] = new vector<vector<Polynomial>*>(nEdge);
  (*edge)[1] = new vector<vector<Polynomial>*>(nEdge);


  // Nedelec // 
  (*(*edge)[0])[0]        = new vector<Polynomial>(3);
  (*(*edge)[0])[0]->at(0) = plusOneHalf; 
  (*(*edge)[0])[0]->at(1) = zero; 
  (*(*edge)[0])[0]->at(2) = zero; 

  (*(*edge)[1])[0]        = new vector<Polynomial>(3);
  (*(*edge)[1])[0]->at(0) = minusOneHalf; 
  (*(*edge)[1])[0]->at(1) = zero; 
  (*(*edge)[1])[0]->at(2) = zero; 
}

LineNedelecBasis::~LineNedelecBasis(void){
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
