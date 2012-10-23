#include "TriEdgeBasis.h"
#include "Legendre.h"

using namespace std;

TriEdgeBasis::TriEdgeBasis(int order){
  // Set Basis Type //
  this->order = order;
 
  type = 1;
  dim  = 2;

  nVertex = 0;
  nEdge   = 3 * (order + 1);
  nFace   = 0;
  nCell   = ((order - 1) * order + order - 1);

  size = (order + 1) * (order + 2);

  // Alloc Temporary Space //
  const int orderPlus     = order + 1;
  const int orderMinus    = order - 1;

  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];
  Polynomial* u           = new Polynomial[orderPlus];
  Polynomial* v           = new Polynomial[orderPlus];

  Polynomial lagrange    [3];
  Polynomial lagrangeSum [3];
  Polynomial lagrangeSub [2][3];

  // Classical and Intrated-Scaled Legendre Polynomial //
  Legendre::legendre(legendre, order);
  Legendre::intScaled(intLegendre, orderPlus);

  // Lagrange //
  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);

  // Lagrange Sum //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3)
    lagrangeSum[i] = lagrange[j] + lagrange[i];

  // Lagrange Sub (& revert) //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3){
    lagrangeSub[0][i] = lagrange[i] - lagrange[j];
    lagrangeSub[1][i] = lagrange[j] - lagrange[i];
  }


  // Basis //
  node = new vector<vector<Polynomial>*>(nVertex);
  edge = new vector<vector<vector<Polynomial>*>*>(2);
  face = new vector<vector<vector<Polynomial>*>*>(0);
  cell = new vector<vector<Polynomial>*>(nCell);
  
  (*edge)[0] = new vector<vector<Polynomial>*>(nEdge);
  (*edge)[1] = new vector<vector<Polynomial>*>(nEdge);
  
  // Counter 
  unsigned int i = 0;

  
  // Edge Based (Nedelec) //
  for(int j = 1; i < 3; j = (j + 1) % 3){
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

    // Next
    i++;
  }
  
  // Edge Based (High Order) //
  for(int l = 1; l < orderPlus; l++){
    for(int e = 0; e < 3; e++){
      (*(*edge)[0])[i] = 
	new vector<Polynomial>((intLegendre[l].compose(lagrangeSub[0][e],  
						       lagrangeSum[e])).gradient());

      (*(*edge)[1])[i] = 
	new vector<Polynomial>((intLegendre[l].compose(lagrangeSub[1][e], 
						       lagrangeSum[e])).gradient());
      i++;
    }
  }
  
  // Cell Based (Preliminary) //
  Polynomial p = lagrange[2] * 2 - Polynomial(1, 0, 0, 0);
  
  for(int l = 0; l < orderPlus; l++){
    u[l] = intLegendre[l].compose(lagrangeSub[0][0] * -1, lagrangeSum[0]);
    v[l] = legendre[l].compose(p);
    v[l].mul(lagrange[2]);
  }

  i = 0;
  
  // Cell Based (Type 1) //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinus; l2++){
      vector<Polynomial> tmp = v[l2].gradient();
      tmp[0].mul(u[l1]);
      tmp[1].mul(u[l1]);
      tmp[2].mul(u[l1]);

      (*cell)[i] = new vector<Polynomial>(u[l1].gradient());
      
      (*cell)[i]->at(0).mul(v[l2]);
      (*cell)[i]->at(1).mul(v[l2]);
      (*cell)[i]->at(2).mul(v[l2]);

      (*cell)[i]->at(0).add(tmp[0]);
      (*cell)[i]->at(1).add(tmp[1]);
      (*cell)[i]->at(2).add(tmp[2]);
     
      i++;
    }
  }
  
  // Cell Based (Type 2) //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinus; l2++){
      vector<Polynomial> tmp = v[l2].gradient();
      tmp[0].mul(u[l1]);
      tmp[1].mul(u[l1]);
      tmp[2].mul(u[l1]);

      (*cell)[i] = new vector<Polynomial>(u[l1].gradient());

      (*cell)[i]->at(0).mul(v[l2]);
      (*cell)[i]->at(1).mul(v[l2]);
      (*cell)[i]->at(2).mul(v[l2]);

      (*cell)[i]->at(0).sub(tmp[0]);
      (*cell)[i]->at(1).sub(tmp[1]);
      (*cell)[i]->at(2).sub(tmp[2]);
 
      i++;
    }
  }

  // Cell Based (Type 3) //
  for(int l = 0; l < orderMinus; l++){
    (*cell)[i] = new vector<Polynomial>(*(*cell)[0]);

    (*cell)[i]->at(0).mul(v[l]);
    (*cell)[i]->at(1).mul(v[l]);
    (*cell)[i]->at(2).mul(v[l]);
    
    i++;
  }
  
  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
  delete[] u;
  delete[] v;
}

TriEdgeBasis::~TriEdgeBasis(void){
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
