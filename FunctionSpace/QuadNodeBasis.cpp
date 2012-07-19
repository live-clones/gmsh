#include "QuadNodeBasis.h"
#include "Legendre.h"

QuadNodeBasis::QuadNodeBasis(const int order){
  // Set Basis Type //
  this->order = order;

  type    = 0;
  size    = (order + 1) * (order + 1);
  nodeNbr = 4;
  dim     = 2;

  nVertex = 4                            ;
  nEdge   = 4 * (order - 1)              ;
  nFace   = 0                            ;
  nCell   =     (order - 1) * (order - 1);

  // Alloc Temporary Space //
  Polynomial* legendre = new Polynomial[order];
  Polynomial* lifting  = new Polynomial[4];

  // Legendre Polynomial //
  Legendre::integrated(legendre, order);
  
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



  // Basis //
  basis = new std::vector<Polynomial>(size);

  // Vertex Based (Lagrange) // 
  (*basis)[0] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0));

  (*basis)[1] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0));

  (*basis)[2] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0));

  (*basis)[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0));
  
  // Edge Based //
  int i = 4;

  for(int l = 1; l < order; l++){
    for(int e1 = 0, e2 = 1; e1 < 4; e1++, e2 = (e2 + 1) % 4){
      (*basis)[i] = 
	legendre[l].compose(lifting[e2] - lifting[e1]) * ((*basis)[e1] + (*basis)[e2]);
            
      i++;
    }
  }

  // Cell Based //
  Polynomial px = Polynomial(2, 1, 0, 0);
  Polynomial py = Polynomial(2, 0, 1, 0);

  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);

  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      (*basis)[i] = legendre[l1].compose(px) * legendre[l2].compose(py);

      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] lifting;
}

QuadNodeBasis::~QuadNodeBasis(void){
  delete basis;
}

/*
#include <cstdio>
int main(void){
  const int P = 8;
  const double d = 0.05;

  QuadNodeBasis b(P);

  printf("%d = %d + %d + %d + %d = %d\n",
	 b.getSize(), 
	 b.getNVertex(), b.getNEdge(), b.getNFace(), b.getNCell(),
	 b.getNVertex() + b.getNEdge() + b.getNFace() + b.getNCell());
  
  const std::vector<Polynomial>& basis = b.getBasis();
  
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
  printf("for j = 1:ly\n");
  printf("\n");

  for(int i = 0; i < b.getSize(); i++)
    printf("p%d(j, i) = p(%d, x(i), y(j));\n", i + 1, i + 1);
  
  printf("end\n");
  printf("end\n");

  printf("\n");
  printf("SizeOfBasis = %lu\n", sizeof(b) + sizeof(basis) * b.getSize()); 
  printf("\n");

  printf("\n");
  for(int i = b.getSize(); i > 0; i--)
    printf("figure;\ncontourf(x, y, p%d);\ncolorbar;\n", i);
  
  printf("\n");

  return 0;
}
*/
