#include "TriEdgeBasis.h"
#include "Legendre.h"

TriEdgeBasis::TriEdgeBasis(const int order){
  // Set Basis Type //
  this->order = order;
 
  type    = 1;
  size    = (order + 1) * (order + 2);
  nodeNbr = 3;
  dim     = 2;

  // Alloc Temporary Space //
  const int orderPlus     = order + 1;
  const int orderMinus    = order - 1;

  Polynomial* legendre    = new Polynomial[orderPlus];
  Polynomial* intLegendre = new Polynomial[orderPlus];
  
  Polynomial* lagrange    = new Polynomial[3];
  Polynomial* lagrangeSub = new Polynomial[3];
  Polynomial* lagrangeSum = new Polynomial[3];

  Polynomial* u           = new Polynomial[orderPlus];
  Polynomial* v           = new Polynomial[orderPlus];

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

  // Lagrange Sub //
  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3)
    lagrangeSub[i] = lagrange[i] - lagrange[j];


  // Basis //
  basis = new std::vector<Polynomial>[size];

  for(int i = 0; i < size; i++)
    basis[i].resize(3);


  // Edge Based (Nedelec) //
  int i = 0;

  for(int j = 1; i < 3; j = (j + 1) % 3){
    std::vector<Polynomial> tmp = lagrange[j].gradient();
    tmp[0].mul(lagrange[i]);
    tmp[1].mul(lagrange[i]);
    tmp[2].mul(lagrange[i]);

    basis[i] = lagrange[i].gradient();

    basis[i][0].mul(lagrange[j]);
    basis[i][1].mul(lagrange[j]);
    basis[i][2].mul(lagrange[j]);      

    basis[i][0].sub(tmp[0]);
    basis[i][1].sub(tmp[1]);
    basis[i][2].sub(tmp[2]);

    i++;
  }

  // Edge Based (High Order) //
  for(int l = 1; l < orderPlus; l++){
    for(int e = 0; e < 3; e++){
      basis[i] = 
	(intLegendre[l].compose(lagrangeSub[e], lagrangeSum[e])).gradient();

      i++;
    }
  }

  // Cell Based (Preliminary) //
  Polynomial p = lagrange[2] * 2 - Polynomial(1, 0, 0, 0);
  
  for(int l = 0; l < orderPlus; l++){
    u[l] = intLegendre[l].compose(lagrangeSub[0] * -1, lagrangeSum[0]);
    v[l] = legendre[l].compose(p);
    v[l].mul(lagrange[2]);
  }

  // Cell Based (Type 1) //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinus; l2++){
      std::vector<Polynomial> tmp = v[l2].gradient();
      tmp[0].mul(u[l1]);
      tmp[1].mul(u[l1]);
      tmp[2].mul(u[l1]);

      basis[i] = u[l1].gradient();
      
      basis[i][0].mul(v[l2]);
      basis[i][1].mul(v[l2]);
      basis[i][2].mul(v[l2]);

      basis[i][0].add(tmp[0]);
      basis[i][1].add(tmp[1]);
      basis[i][2].add(tmp[2]);
      
      i++;
    }
  }

  // Cell Based (Type 2) //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinus; l2++){
      std::vector<Polynomial> tmp = v[l2].gradient();
      tmp[0].mul(u[l1]);
      tmp[1].mul(u[l1]);
      tmp[2].mul(u[l1]);

      basis[i] = u[l1].gradient();

      basis[i][0].mul(v[l2]);
      basis[i][1].mul(v[l2]);
      basis[i][2].mul(v[l2]);

      basis[i][0].sub(tmp[0]);
      basis[i][1].sub(tmp[1]);
      basis[i][2].sub(tmp[2]);
 
      i++;
    }
  }

  // Cell Based (Type 3) //
  for(int l = 0; l < orderMinus; l++){
    basis[i] = basis[0];

    basis[i][0].mul(v[l]);
    basis[i][1].mul(v[l]);
    basis[i][2].mul(v[l]);
    
    i++;
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] intLegendre;
  delete[] lagrange;
  delete[] lagrangeSub;
  delete[] lagrangeSum;
  delete[] u;
  delete[] v;
}

TriEdgeBasis::~TriEdgeBasis(void){
  delete[] basis;
}

/*
#include <cstdio>
int main(void){
  const int P = 6;
  const double d = 0.05;
  const char x[2] = {'X', 'Y'};

  TriEdgeBasis b(P);
  
  const std::vector<Polynomial>* basis = b.getBasis();
  
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
  
  printf("function [rx ry] = p(i, x, y)\n");
  printf("p = zeros(%d, 2);\n", b.getSize());
  printf("\n");
  
  for(int i = 0; i < b.getSize(); i++){
    //printf("p(%d) = %s;\n", i + 1, basis[i].toString().c_str());
    printf("p(%d, 1) = %s;\n", i + 1, basis[i][0].toString().c_str());
    printf("p(%d, 2) = %s;\n", i + 1, basis[i][1].toString().c_str());
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
  printf("for j = 1:ly - i + 1\n");
  printf("\n");

  for(int i = 0; i < b.getSize(); i++)
    printf("[p%dX(j, i), p%dY(j, i)] = p(%d, x(i), y(j));\n", i + 1, i + 1, i + 1);
  
  printf("end\n");
  printf("end\n");

  printf("\n");
  printf("SizeOfBasis = %lu\n", sizeof(b) + sizeof(basis) * b.getSize()); 
  printf("\n");

  printf("\n");
  for(int i = b.getSize() - 1; i >= 0; i--)
    printf("figure;\nquiver(x, y, p%dX, p%dY);\n", i + 1, i + 1);
  
  printf("\n");
  
  return 0;
}
*/
