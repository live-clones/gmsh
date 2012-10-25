#include "DivBasis.h"

using namespace std;

DivBasis::DivBasis(const BasisVector& other){
  // Set Basis Type //
  order = other.getOrder();
  
  type = other.getType();
  dim  = other.getDim();
  
  nVertex = other.getNVertexBased();
  nEdge   = other.getNEdgeBased();
  nFace   = other.getNFaceBased();
  nCell   = other.getNCellBased();
  
  nEdgeClosure = other.getNEdgeClosure();
  nFaceClosure = other.getNFaceClosure();

  size = other.getSize();

  // Alloc Basis //
  node = new vector<Polynomial*>(nVertex);
  edge = new vector<vector<Polynomial*>*>(2);
  face = new vector<vector<Polynomial*>*>(6);
  cell = new vector<Polynomial*>(nCell);

  for(int i = 0; i < nEdgeClosure; i++)
    (*edge)[i] = new vector<Polynomial*>(nEdge);

  for(int i = 0; i < nFaceClosure; i++)
    (*face)[i] = new vector<Polynomial*>(nFace);  

  // Node Based //
  for(int i = 0; i < nVertex; i++)
    (*node)[i] = 
      new Polynomial
      (Polynomial::divergence(other.getNodeFunction(i)));
  
  // Edge Based //
  for(int i = 0; i < nEdgeClosure; i++)
    for(int j = 0; j < nEdge; j++)
      (*(*edge)[i])[j] = 
	new Polynomial
	(Polynomial::divergence(other.getEdgeFunction(i, j)));

  // Face Based //
  for(int i = 0; i < nFaceClosure; i++)
    for(int j = 0; j < nFace; j++)
      (*(*face)[i])[j] = 
	new Polynomial
	(Polynomial::divergence(other.getFaceFunction(i, j)));

  // Cell Based //
  for(int i = 0; i < nCell; i++)
    (*cell)[i] = 
      new Polynomial
      (Polynomial::divergence(other.getCellFunction(i)));
}

DivBasis::~DivBasis(void){
  // Vertex Based //
  for(int i = 0; i < nVertex; i++)
    delete (*node)[i];
  
  delete node;


  // Edge Based //
  for(int c = 0; c < nEdgeClosure; c++){
    for(int i = 0; i < nEdge; i++)
      delete (*(*edge)[c])[i];
    
    delete (*edge)[c];
  }
  
  delete edge;


  // Face Based //
  for(int c = 0; c < nFaceClosure; c++){
    for(int i = 0; i < nFace; i++)
      delete (*(*face)[c])[i];
    
    delete (*face)[c];
  }

  delete face;


  // Cell Based //
  for(int i = 0; i < nCell; i++)
    delete (*cell)[i];
  
  delete cell;
}
