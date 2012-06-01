#include "TriNedelecBasis.h"

TriNedelecBasis::TriNedelecBasis(void){
  // Set Basis Type //
  order   = 1;
  type    = 1;
  size    = 3;
  nodeNbr = 3;
  dim     = 2;

  // Lagrange //
  Polynomial* lagrange    = new Polynomial[3];

  lagrange[0] = 
    Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0) - Polynomial(1, 0, 1, 0);

  lagrange[1] = 
    Polynomial(1, 1, 0, 0);

  lagrange[2] = 
    Polynomial(1, 0, 1, 0);

  // Basis //
  basis = new Vector<Polynomial>[size];

  for(int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3){
    Vector<Polynomial> tmp = lagrange[j].gradient();
    tmp.mul(lagrange[i]);

    basis[i] = lagrange[i].gradient();
    basis[i].mul(lagrange[j]);
   
    basis[i].sub(tmp);
  }

  // Free Temporary Sapce //
  delete[] lagrange;
}

TriNedelecBasis::~TriNedelecBasis(void){
  delete[] basis;
}

/*
#include <cstdio>
int main(void){
  const int P = 1;
  const double d = 0.05;
  const char x[2] = {'X', 'Y'};

  TriNedelec b;
  
  const Vector<Polynomial>* basis = b.getBasis();
  
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
    printf("p(%d, 1) = %s;\n", i + 1, basis[i](0).toString().c_str());
    printf("p(%d, 2) = %s;\n", i + 1, basis[i](1).toString().c_str());
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
