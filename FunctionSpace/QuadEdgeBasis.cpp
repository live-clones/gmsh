#include "QuadEdgeBasis.h"
#include "Legendre.h"

QuadEdgeBasis::QuadEdgeBasis(const int order){
  // Set Basis Type //
  this->order = order;
  
  type = 1;
  dim  = 2;

  nVertex = 0                      ;
  nEdge   = 4 * (order + 1)        ;
  nFace   = 0                      ;
  nCell   = 2 * (order + 1) * order;

  size = 2 * (order + 2) * (order + 1);

  // Alloc Temporary Space //
  const int  orderPlus = order + 1;
  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];

  Polynomial* iLegendreX  = new Polynomial[orderPlus];
  Polynomial* iLegendreY  = new Polynomial[orderPlus];
  Polynomial* legendreX   = new Polynomial[orderPlus];
  Polynomial* legendreY   = new Polynomial[orderPlus];

  Polynomial* lagrange    = new Polynomial[4];
  Polynomial* lagrangeSum = new Polynomial[4];

  Polynomial* lifting     = new Polynomial[4];
  Polynomial* liftingSub  = new Polynomial[4];

  // Integrated and classical Legendre Polynomial //
  Legendre::integrated(intLegendre, orderPlus);
  Legendre::legendre(legendre, order);

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
  for(int i = 0, j = 1; i < 4; i++, j = (j + 1) % 4)
    lagrangeSum[i] = lagrange[i] + lagrange[j];
    
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
  for(int i = 0, j = 1; i < 4; i++, j = (j + 1) % 4)
    liftingSub[i] = lifting[j] - lifting[i];


  // Basis (temporary --- *no* const) //
  std::vector<std::vector<Polynomial>*> basis(size);


  // Edge Based (Nedelec) // 
  int i = 0;
  Polynomial oneHalf(0.5, 0, 0, 0);

  for(int e = 0; e < 4; e++){
    basis[i] = new std::vector<Polynomial>(liftingSub[e].gradient());
    
    basis[i]->at(0).mul(lagrangeSum[e]);
    basis[i]->at(1).mul(lagrangeSum[e]);
    basis[i]->at(2).mul(lagrangeSum[e]);
  
    basis[i]->at(0).mul(oneHalf);
    basis[i]->at(1).mul(oneHalf);
    basis[i]->at(2).mul(oneHalf);

    i++;
  }

  // Edge Based (High Order) //
  for(int l = 1; l < orderPlus; l++){
    for(int e = 0; e < 4; e++){
      basis[i] = 
	new std::vector<Polynomial>((intLegendre[l].compose(liftingSub[e]) * lagrangeSum[e]).gradient());
     
      i++;
    }
  }

  
  // Cell Based (Preliminary) //
  Polynomial px   = Polynomial(2, 1, 0, 0);
  Polynomial py   = Polynomial(2, 0, 1, 0);
  Polynomial zero = Polynomial(0, 0, 0, 0);

  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);

  for(int l = 0; l < orderPlus; l++){
    iLegendreX[l] = intLegendre[l].compose(px);
    iLegendreY[l] = intLegendre[l].compose(py);
     legendreX[l] =    legendre[l].compose(px);
     legendreY[l] =    legendre[l].compose(py);
  }

  // Cell Based (Type 1) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      basis[i] = new std::vector<Polynomial>((iLegendreX[l1] * iLegendreY[l2]).gradient());

      i++;
    }
  }
  
  // Cell Based (Type 2) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      basis[i] = new std::vector<Polynomial>(3);

      basis[i]->at(0) =  legendreX[l1] * iLegendreY[l2];
      basis[i]->at(1) = iLegendreX[l1] *  legendreY[l2] * -1;
      basis[i]->at(2) = zero;

      i++;
    }
  }

  // Cell Based (Type 3) //
  for(int l = 1, iPlus = i + order; l < orderPlus; l++, iPlus++){
    basis[i]     = new std::vector<Polynomial>(3);
    basis[iPlus] = new std::vector<Polynomial>(3);

    basis[i]->at(0) = iLegendreY[l];
    basis[i]->at(1) = zero;
    basis[i]->at(2) = zero;

    basis[iPlus]->at(0) = zero;
    basis[iPlus]->at(1) = iLegendreX[l];
    basis[iPlus]->at(2) = zero;

    i++;
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;

  delete[] iLegendreX;
  delete[] iLegendreY;
  delete[] legendreX;
  delete[] legendreY;

  delete[] lagrange;
  delete[] lagrangeSum;

  delete[] lifting;
  delete[] liftingSub;


  // Set Basis //
  this->basis = new std::vector<const std::vector<Polynomial>*>
    (basis.begin(), basis.end());
}

QuadEdgeBasis::~QuadEdgeBasis(void){
  for(int i = 0; i < size; i++)
    delete (*basis)[i];

  delete basis;
}
