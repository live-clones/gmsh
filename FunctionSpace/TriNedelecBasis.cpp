#include "TriNedelecBasis.h"

using namespace std;

TriNedelecBasis::TriNedelecBasis(void){
  // Set Basis Type //
  order = 1;

  type = 1;
  dim  = 2;

  nVertex = 0;
  nEdge   = 3;
  nFace   = 0;
  nCell   = 0;

  nEdgeClosure = 2;
  nFaceClosure = 0;

  size = 3;

  // Vertices definig Edges & Permutations //
  const int edgeV[2][3][2] = 
    {
      { {0, 1}, {1, 2}, {2, 0} },
      { {1, 0}, {2, 1}, {0, 2} }
    }; 

  // Basis //
  node = new vector<vector<Polynomial>*>(nVertex);
  edge = new vector<vector<vector<Polynomial>*>*>(2);
  face = new vector<vector<vector<Polynomial>*>*>(0);
  cell = new vector<vector<Polynomial>*>(nCell);
  
  (*edge)[0] = new vector<vector<Polynomial>*>(nEdge);
  (*edge)[1] = new vector<vector<Polynomial>*>(nEdge);


  // Lagrange //
  Polynomial lagrange[3];

  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);


  // Nedelec //
  for(int c = 0; c < 2; c++){
    for(int e = 0; e < 3; e++){
      vector<Polynomial> tmp = lagrange[edgeV[c][e][1]].gradient();
 
      tmp[0].mul(lagrange[edgeV[c][e][0]]);
      tmp[1].mul(lagrange[edgeV[c][e][0]]);
      tmp[2].mul(lagrange[edgeV[c][e][0]]);
      
      (*(*edge)[c])[e] = 
	new vector<Polynomial>(lagrange[edgeV[c][e][0]].gradient());

      (*(*edge)[c])[e]->at(0).mul(lagrange[edgeV[c][e][1]]);
      (*(*edge)[c])[e]->at(1).mul(lagrange[edgeV[c][e][1]]);
      (*(*edge)[c])[e]->at(2).mul(lagrange[edgeV[c][e][1]]);      
      
      (*(*edge)[c])[e]->at(0).sub(tmp[0]);
      (*(*edge)[c])[e]->at(1).sub(tmp[1]);
      (*(*edge)[c])[e]->at(2).sub(tmp[2]);
    }
  }  
}

TriNedelecBasis::~TriNedelecBasis(void){
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
