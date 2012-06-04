#include "QuadEdgeBasis.h"
#include "Legendre.h"

QuadEdgeBasis::QuadEdgeBasis(const int order){
  // Set Basis Type //
  this->order = order;
  
  type    = 1;
  size    = 2 * (order + 2) * (order + 1);
  nodeNbr = 4;
  dim     = 2;

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


  // Basis //
  basis = new std::vector<std::vector<Polynomial> >(size);

  for(int i = 0; i < size; i++)
    (*basis)[i].resize(3);


  // Edge Based (Nedelec) // 
  int i = 0;
  Polynomial oneHalf(0.5, 0, 0, 0);

  for(int e = 0; e < 4; e++){
    (*basis)[i] = 
      (liftingSub[e]).gradient();
    
    (*basis)[i][0].mul(lagrangeSum[e]);
    (*basis)[i][1].mul(lagrangeSum[e]);
    (*basis)[i][2].mul(lagrangeSum[e]);

    (*basis)[i][0].mul(oneHalf);
    (*basis)[i][1].mul(oneHalf);
    (*basis)[i][2].mul(oneHalf);

    i++;
  }

  // Edge Based (High Order) //
  for(int l = 1; l < orderPlus; l++){
    for(int e = 0; e < 4; e++){
      (*basis)[i] = 
	(intLegendre[l].compose(liftingSub[e]) * lagrangeSum[e]).gradient();
     
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
      (*basis)[i] = (iLegendreX[l1] * iLegendreY[l2]).gradient();

      i++;
    }
  }
  
  // Cell Based (Type 2) //
  for(int l1 = 1; l1 < orderPlus; l1++){
    for(int l2 = 1; l2 < orderPlus; l2++){
      (*basis)[i][0] =  legendreX[l1] * iLegendreY[l2];
      (*basis)[i][1] = iLegendreX[l1] *  legendreY[l2] * -1;
      (*basis)[i][2] = zero;

      i++;
    }
  }

  // Cell Based (Type 3) //
  for(int l = 1, iPlus = i + order; l < orderPlus; l++, iPlus++){
    (*basis)[i][0] = iLegendreY[l];
    (*basis)[i][1] = zero;
    (*basis)[i][2] = zero;

    (*basis)[iPlus][0] = zero;
    (*basis)[iPlus][1] = iLegendreX[l];
    (*basis)[iPlus][2] = zero;

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
}

QuadEdgeBasis::~QuadEdgeBasis(void){
  delete basis;
}

/*
#include <cstdio>
int main(void){
  const int P = 3;
  const double d = 0.05;
  const char x[2] = {'X', 'Y'};

  QuadEdgeBasis b(P);
  
  const std::vector<std::vector<Polynomial> >& basis = b.getBasis();
  
  printf("\n");
  printf("clear all;\n");
  printf("close all;\n");
  printf("\n");

  printf("\n");
  printf("Order      = %d\n", b.getOrder());
  printf("Type       = %d\n", b.getType());
  printf("Size       = %d\n", b.getSize());
  printf("NodeNumber = %d\n", b.getNodeNbr());
  printf("Dimension  = %d\n", b.getDim());
  printf("\n");

  printf("function [rx ry] = p(i, x, y)\n");
  printf("p = zeros(%d, 2);\n", b.getSize());
  printf("\n");

  for(int i = 0; i < b.getSize(); i++){
    for(int j = 0; j < 2; j++)
      printf("p(%d, %d) = %s;\n", i + 1, j + 1, basis[i][j].toString().c_str());
    //printf("p(%d) = %s", i, basis[i].toString().c_str());
    printf("\n");
  }

  printf("\n");
  printf("rx = p(i, 1);\n");
  printf("ry = p(i, 2);\n");
  printf("end\n");
  printf("\n");
  
  printf("d = %lf;\nx = [0:d:1];\ny = x;\n\nlx = length(x);\nly = length(y);\n\n", d);
  
  for(int i = 0; i < b.getSize(); i++)
    for(int j = 0; j < 2; j++)
      printf("p%d%c = zeros(lx, ly);\n", i + 1, x[j]);

  printf("\n");
  printf("for i = 1:lx\n");
  printf("for j = 1:ly\n");
  printf("\n");

  for(int i = 0; i < b.getSize(); i++)
    printf("[p%dX(j, i), p%dY(j, i)] = p(%d, x(i), y(j));\n", i + 1, i + 1, i + 1);

  printf("\n");
  printf("end\n");
  printf("end\n");

  printf("\n");
  printf("SizeOfBasis = %lu\n", sizeof(b) + sizeof(basis) * b.getSize()); 
  printf("\n");

  printf("\n");
  for(int i = 0; i < b.getSize(); i++)
    printf("figure;\nquiver(x, y, p%dX, p%dY);\n", i + 1, i + 1);
  
  printf("\n");

  return 0;
}
*/
