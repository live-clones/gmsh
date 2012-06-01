#include "TriNodeBasis.h"
#include "Legendre.h"

TriNodeBasis::TriNodeBasis(const int order){
  // Set Basis Type //
  this->order = order;
  
  type    = 0;
  size    = (order + 1) * (order + 2) / 2;
  nodeNbr = 3;
  dim     = 2;

  // Alloc Temporary Space //
  Polynomial* legendre    = new Polynomial[order];
  Polynomial* intLegendre = new Polynomial[order];
  Polynomial* lagrangeSub = new Polynomial[3];
  Polynomial* lagrangeSum = new Polynomial[3];

  // Classical and Intrated-Scaled Legendre Polynomial //
  const int orderMinus = order - 1;

  Legendre::legendre(legendre, orderMinus);
  Legendre::intScaled(intLegendre, order);
 

  // Basis //
  basis = new Polynomial[size];

  // Vertex Based (Lagrange) // 
  basis[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  basis[1] = 
    Polynomial(1, 1, 0, 0);

  basis[2] = 
    Polynomial(1, 0, 1, 0);

  
  // Lagrange Sum //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3)
    lagrangeSum[i] = basis[i] + basis[j];

  // Lagrange Sub //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3)
    lagrangeSub[i] = basis[j] - basis[i];

  
  // Edge Based //
  int i = 3;

  for(int l = 1; l < order; l++){
    for(int e = 0; e < 3; e++){
      basis[i] = 
	intLegendre[l].compose(lagrangeSub[e], lagrangeSum[e]);
            
      i++;
    }
  }

  // Cell Based //
  Polynomial p             = basis[2] * 2 - Polynomial(1, 0, 0, 0);
  const int  orderMinusTwo = order - 2;
  
  for(int l1 = 1; l1 < orderMinus; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinusTwo; l2++){
      basis[i] = 
	intLegendre[l1].compose(lagrangeSub[0], lagrangeSum[0]) * 
	   legendre[l2].compose(p) * basis[2];
      
      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
  delete[] lagrangeSub;
  delete[] lagrangeSum;
}

TriNodeBasis::~TriNodeBasis(void){
  delete[] basis;
}

/*
#include <cstdio>
int main(void){
  const int P = 5;
  const double d = 0.01;

  TriNodeBasis b(P);
  
  const Polynomial* basis = b.getBasis();
  
  printf("\n");
  printf("clear all;\n");
  printf("\n");

  printf("\n");
  printf("Order      = %d\n", b.getOrder());
  printf("Type       = %d\n", b.getType());
  printf("Size       = %d\n", b.getSize());
  printf("NodeNumber = %d\n", b.getNodeNbr());
  printf("Dimension  = %d\n", b.getDim());
  printf("\n");

  printf("function r = p(i, x, y)\n");
  printf("p = zeros(%d, 1);\n", b.getSize());
  printf("\n");
  
  for(int i = 0; i < b.getSize(); i++)
    printf("p(%d) = %s;\n", i + 1, basis[i].toString().c_str());
  
  printf("\n");
  printf("r = p(i, 1);\n");
  printf("end\n");
  printf("\n");
  
  printf("d = %lf;\nx = [0:d:1];\ny = x;\n\nlx = length(x);\nly = length(y);\n\n", d);
  
  for(int i = 0; i < b.getSize(); i++)
    printf("p%d = zeros(lx, ly);\n", i + 1);

  printf("\n");
  printf("for i = 1:lx\n");
  printf("for j = 1:ly - i + 1\n");
  printf("\n");

  for(int i = 0; i < b.getSize(); i++)
    printf("p%d(j, i) = p(%d, x(i), y(j));\n", i + 1, i + 1, i + 1);
  
  printf("end\n");
  printf("end\n");

  printf("\n");
  printf("SizeOfBasis = %lu\n", sizeof(b) + sizeof(basis) * b.getSize()); 
  printf("\n");

  printf("\n");
  for(int i = 0; i < b.getSize(); i++)
    printf("figure;\ncontourf(x, y, p%d);\ncolorbar;\n", i + 1, i + 1);
  
  printf("\n");
  
  return 0;
}
*/
