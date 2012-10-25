#include "QuadEdgeBasis.h"
#include "Legendre.h"

using namespace std;

QuadEdgeBasis::QuadEdgeBasis(int order){
  // Set Basis Type //
  this->order = order;
  
  type = 1;
  dim  = 2;

  nVertex = 0;
  nEdge   = 4 * (order + 1);
  nFace   = 0;
  nCell   = 2 * (order + 1) * order;

  nEdgeClosure = 2;
  nFaceClosure = 0;

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const int  orderPlus = order + 1;

  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  Polynomial* iLegendreX  = new Polynomial[orderPlus];
  Polynomial* iLegendreY  = new Polynomial[orderPlus];
  Polynomial* legendreX   = new Polynomial[orderPlus];
  Polynomial* legendreY   = new Polynomial[orderPlus];

  Polynomial  lagrange[4];
  Polynomial  lifting[4];
  Polynomial  lagrangeSum[4];
  Polynomial  liftingSub[2][4];

  // Legendre Polynomial //
  Legendre::integrated(intLegendre, orderPlus);
  Legendre::legendre(legendre, order);

  // Vertices definig Edges & Permutations //
  const int edgeV[2][4][2] = 
    {
      { {0, 1}, {1, 2}, {2, 3}, {3, 0} },
      { {1, 0}, {2, 1}, {3, 2}, {0, 3} }
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
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0));

  lagrange[1] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0));

  lagrange[2] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0));

  lagrange[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0));

  // Lagrange Sum //
  for(int e = 0; e < 4; e++)
    lagrangeSum[e] = 
      lagrange[edgeV[0][e][0]] + 
      lagrange[edgeV[0][e][1]];
    
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


  // Edge Based (Nedelec) // 
  Polynomial oneHalf(0.5, 0, 0, 0);

  for(int c = 0; c < 2; c++){
    for(int e = 0; e < 4; e++){
      (*(*edge)[c])[e] = 
	new vector<Polynomial>(liftingSub[c][e].gradient());
    
      (*(*edge)[c])[e]->at(0).mul(lagrangeSum[e]);
      (*(*edge)[c])[e]->at(1).mul(lagrangeSum[e]);
      (*(*edge)[c])[e]->at(2).mul(lagrangeSum[e]);
  
      (*(*edge)[c])[e]->at(0).mul(oneHalf);
      (*(*edge)[c])[e]->at(1).mul(oneHalf);
      (*(*edge)[c])[e]->at(2).mul(oneHalf);
    }
  }


  // Edge Based (High Order) //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;
    
    for(int l = 1; l < orderPlus; l++){
      for(int e = 0; e < 4; e++){
	(*(*edge)[c])[i + 4] = 
	  new vector<Polynomial>((intLegendre[l].compose(liftingSub[c][e]) * 
				  lagrangeSum[e]).gradient());
	
	i++;
      }
    }
  }

  
  // Cell Based (Preliminary) //
  Polynomial px   = Polynomial(2, 1, 0, 0);
  Polynomial py   = Polynomial(2, 0, 1, 0);
  Polynomial zero = Polynomial(0, 0, 0, 0);

  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);

  unsigned int i = 0;

  for(int l = 0; l < orderPlus; l++){
    iLegendreX[l] = intLegendre[l].compose(px);
    iLegendreY[l] = intLegendre[l].compose(py);
     legendreX[l] =    legendre[l].compose(px);
     legendreY[l] =    legendre[l].compose(py);
  }

  // Cell Based (Type 1) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      (*cell)[i] = 
	new vector<Polynomial>((iLegendreX[l1] * iLegendreY[l2]).gradient());

      i++;
    }
  }
  
  // Cell Based (Type 2) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      (*cell)[i] = new vector<Polynomial>(3);

      (*cell)[i]->at(0) =  legendreX[l1] * iLegendreY[l2];
      (*cell)[i]->at(1) = iLegendreX[l1] *  legendreY[l2] * -1;
      (*cell)[i]->at(2) = zero;

      i++;
    }
  }

  // Cell Based (Type 3) //
  for(int l = 1, iPlus = i + order; l < orderPlus; l++, iPlus++){
    (*cell)[i]     = new vector<Polynomial>(3);
    (*cell)[iPlus] = new vector<Polynomial>(3);

    (*cell)[i]->at(0) = iLegendreY[l];
    (*cell)[i]->at(1) = zero;
    (*cell)[i]->at(2) = zero;

    (*cell)[iPlus]->at(0) = zero;
    (*cell)[iPlus]->at(1) = iLegendreX[l];
    (*cell)[iPlus]->at(2) = zero;

    i++;
  }


  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;

  delete[] iLegendreX;
  delete[] iLegendreY;
  delete[] legendreX;
  delete[] legendreY;
}

QuadEdgeBasis::~QuadEdgeBasis(void){
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
