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

  size = 3;

  // Lagrange //
  Polynomial lagrange[3];

  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);


  // Basis //
  node = new vector<vector<Polynomial>*>(nVertex);
  edge = new vector<vector<vector<Polynomial>*>*>(2);
  face = new vector<vector<vector<Polynomial>*>*>(0);
  cell = new vector<vector<Polynomial>*>(nCell);
  
  (*edge)[0] = new vector<vector<Polynomial>*>(nEdge);
  (*edge)[1] = new vector<vector<Polynomial>*>(nEdge);

  
  // Nedelec //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3){
    // Temp
    vector<Polynomial> tmp = lagrange[j].gradient();
    
    // Edge[0]
    tmp[0].mul(lagrange[i]);
    tmp[1].mul(lagrange[i]);
    tmp[2].mul(lagrange[i]);
    
    (*(*edge)[0])[i] = new vector<Polynomial>(lagrange[i].gradient());
    
    (*(*edge)[0])[i]->at(0).mul(lagrange[j]);
    (*(*edge)[0])[i]->at(1).mul(lagrange[j]);
    (*(*edge)[0])[i]->at(2).mul(lagrange[j]);      
    
    (*(*edge)[0])[i]->at(0).sub(tmp[0]);
    (*(*edge)[0])[i]->at(1).sub(tmp[1]);
    (*(*edge)[0])[i]->at(2).sub(tmp[2]);
    
    //Edge[1]
    tmp = lagrange[i].gradient();
    
    tmp[0].mul(lagrange[j]);
    tmp[1].mul(lagrange[j]);
    tmp[2].mul(lagrange[j]);
    
    (*(*edge)[1])[i] = new vector<Polynomial>(lagrange[j].gradient());
    
    (*(*edge)[1])[i]->at(0).mul(lagrange[i]);
    (*(*edge)[1])[i]->at(1).mul(lagrange[i]);
    (*(*edge)[1])[i]->at(2).mul(lagrange[i]);
    
    (*(*edge)[1])[i]->at(0).sub(tmp[0]);
    (*(*edge)[1])[i]->at(1).sub(tmp[1]);
    (*(*edge)[1])[i]->at(2).sub(tmp[2]);
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
