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

  size = nVertex + nEdge + nFace + nCell;

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

  // Legendre Polynomial //
  Legendre::legendre(legendre, order);
  Legendre::intScaled(intLegendre, orderPlus);

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
  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);

  // Lagrange Sum //
  for(int e = 0; e < 3; e++)
    lagrangeSum[e] = 
      lagrange[edgeV[0][e][0]] + 
      lagrange[edgeV[0][e][1]];

  // Lagrange Sub //
  for(int e = 0; e < 3; e++){
    lagrangeSub[0][e] = 
      lagrange[edgeV[0][e][0]] - 
      lagrange[edgeV[0][e][1]];
    
    lagrangeSub[1][e] = 
      lagrange[edgeV[1][e][0]] - 
      lagrange[edgeV[1][e][1]];
  }

    
  // Edge Based (Nedelec) //
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


  // Edge Based (High Order) //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;

    for(int l = 1; l < orderPlus; l++){
      for(int e = 0; e < 3; e++){
	(*(*edge)[c])[i + 3] = 
	  new vector<Polynomial>
	  ((intLegendre[l].compose(lagrangeSub[c][e],  
				   lagrangeSum[e])).gradient());

	i++;
      }
    }
  }


  // Cell Based (Preliminary) //
  Polynomial p = lagrange[2] * 2 - Polynomial(1, 0, 0, 0);
  
  for(int l = 0; l < orderPlus; l++){
    u[l] = intLegendre[l].compose(lagrangeSub[0][0] * -1, lagrangeSum[0]);
    v[l] = legendre[l].compose(p);
    v[l].mul(lagrange[2]);
  }

  unsigned int i = 0;
  
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
