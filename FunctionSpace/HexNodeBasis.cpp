#include "HexNodeBasis.h"
#include "Legendre.h"

HexNodeBasis::HexNodeBasis(const int order){
  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 3;

  nVertex =  8;
  nEdge   = 12 * (order - 1);
  nFace   =  6 * (order - 1) * (order - 1);
  nCell   =      (order - 1) * (order - 1) * (order - 1);

  size = (order + 1) * (order + 1) * (order + 1);

  // Alloc Temporary Space //
  Polynomial* legendre = new Polynomial[order];
  Polynomial* lifting  = new Polynomial[8];

  Polynomial* xi       = new Polynomial[6];
  Polynomial* eta      = new Polynomial[6];
  Polynomial* lambda   = new Polynomial[6];

  // Legendre Polynomial //
  Legendre::integrated(legendre, order);
  
  // Lifting //
  lifting[0] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[1] = 
    (Polynomial(1, 1, 0, 0))                          +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[2] = 
    (Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0))                          +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  lifting[4] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
     Polynomial(1, 0, 0, 1);

  lifting[5] = 
    (Polynomial(1, 1, 0, 0))                          +
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) +
     Polynomial(1, 0, 0, 1);

  lifting[6] = 
    (Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0)) +
     Polynomial(1, 0, 0, 1);

  lifting[7] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) +
    (Polynomial(1, 0, 1, 0))                          +
     Polynomial(1, 0, 0, 1);


  // Basis //
  basis = new std::vector<Polynomial>(size);


  // Vertex Based (Lagrange) // 
  (*basis)[0] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  (*basis)[1] = 
    (Polynomial(1, 1, 0, 0))                          *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  (*basis)[2] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  (*basis)[3] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0))                          *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1));

  (*basis)[4] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
     Polynomial(1, 0, 0, 1);

  (*basis)[5] = 
    (Polynomial(1, 1, 0, 0))                          *
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
     Polynomial(1, 0, 0, 1);

  (*basis)[6] = 
    (Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0)) *
     Polynomial(1, 0, 0, 1);

  (*basis)[7] = 
    (Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
    (Polynomial(1, 0, 1, 0))                          *
     Polynomial(1, 0, 0, 1);

  
  // Edge Based //
  // Keep counting
  int i = 8;

  // Points definig Edges
  int edge1[12] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3};
  int edge2[12] = {1, 2, 3, 0, 5, 6, 7, 4, 4, 5, 6, 7};

  for(int l = 1; l < order; l++){
    for(int e = 0; e < 12; e++){
      (*basis)[i] = 
	legendre[l].compose(lifting[edge1[e]] - lifting[edge2[e]]) * 
	((*basis)[edge1[e]] + (*basis)[edge2[e]]);
            
      i++;
    }
  }

  
  // Face Based (Preliminary) //
  // Points definig Faces
  int face1[6] = {0, 3, 2, 1, 5, 4};
  int face2[6] = {1, 7, 6, 0, 6, 7};
  int face3[6] = {2, 6, 5, 4, 7, 3};
  int face4[6] = {3, 2, 1, 5, 4, 0};

  // 'Xi' Functions
  for(int f = 0; f < 6; f++)
    xi[f]  = lifting[face1[f]] - lifting[face2[f]];

  // 'Eta' Functions
  for(int f = 0; f < 6; f++)
    eta[f] = lifting[face1[f]] - lifting[face4[f]];

  // 'Lambda' Functions
  for(int f = 0; f < 6; f++)
    lambda[f] = 
      (*basis)[face1[f]] +
      (*basis)[face2[f]] +
      (*basis)[face3[f]] +
      (*basis)[face4[f]];


  // Face Based //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      for(int f = 0; f < 6; f++){	
	(*basis)[i] = 
	  legendre[l1].compose(xi[f])  *
	  legendre[l2].compose(eta[f]) *
	  lambda[f];
	  
	i++;
      }
    }
  }
 
  
  // Cell Based //
  Polynomial px = Polynomial(2, 1, 0, 0);
  Polynomial py = Polynomial(2, 0, 1, 0);
  Polynomial pz = Polynomial(2, 0, 0, 1);

  px = px - Polynomial(1, 0, 0, 0);
  py = py - Polynomial(1, 0, 0, 0);
  pz = pz - Polynomial(1, 0, 0, 0);

  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      for(int l3 = 1; l3 < order; l3++){
	(*basis)[i] = 
	  legendre[l1].compose(px) * 
	  legendre[l2].compose(py) *
	  legendre[l3].compose(pz);
	
	i++;
      }
    }
  }


  // Free Temporary Sapce //
  delete[] legendre;
  delete[] lifting;

  delete[] xi;
  delete[] eta;
  delete[] lambda;
}

HexNodeBasis::~HexNodeBasis(void){
  delete basis;
}

/*
#include <cstdio>
int main(void){

  const int P = 8;
  const double d = 0.05;

  HexNodeBasis b(P);
  
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

  printf("function r = p(i, x, y, z)\n");
  printf("p = zeros(%d, 1);\n", b.getSize());
  printf("\n");

  for(int i = 0; i < b.getSize(); i++)
    printf("p(%d) = %s;\n", i + 1, basis[i].toString().c_str());

  printf("\n");
  printf("r = p(i, 1);\n");
  printf("end\n");
  printf("\n");
  
  printf("d = %f;\nx = [0:d:1];\ny = x;\nz = x;\n\nlx = length(x);\nly = length(y);\nlz = length(z);\n\n", d);
  
  for(int i = 0; i < b.getSize(); i++)
    printf("p%d = zeros(lx, ly, lz);\n", i + 1);

  printf("\n");
  printf("for i = 1:lx\n");
  printf("for j = 1:ly\n");
  printf("for k = 1:lz\n");
  printf("\n");

  for(int i = 0; i < b.getSize(); i++)
    printf("p%d(j, i, k) = p(%d, x(i), y(j), z(k));\n", i + 1, i + 1);
  
  printf("\nend\n");
  printf("end\n");
  printf("end\n");

  printf("\n");
  printf("SizeOfBasis = %lu\n", sizeof(b) + sizeof(basis) * b.getSize()); 
  printf("\n");
  
  printf("\n");
  for(int i = b.getSize(); i > 0; i--){
    printf("figure;\n");

    printf("subplot(3, 2, 1);\n");
    printf("contourf(x, y, squeeze(p%d(:, :, 1)));\n", i);
    printf("colorbar;\n");
    printf("title('z = 0');\n");
    printf("ylabel('x');\n");
    printf("xlabel('y');\n\n");

    printf("subplot(3, 2, 2);\n");
    printf("contourf(x, y, squeeze(p%d(:, :, end)));\n", i);
    printf("colorbar;\n");
    printf("title('z = 1');\n");
    printf("ylabel('x');\n");
    printf("xlabel('y');\n\n");

    printf("subplot(3, 2, 3);\n");
    printf("contourf(x, z, squeeze(p%d(:, 1, :)));\n", i);
    printf("colorbar;\n");
    printf("title('y = 0');\n");
    printf("ylabel('x');\n");
    printf("xlabel('z');\n\n");

    printf("subplot(3, 2, 4);\n");
    printf("contourf(x, z, squeeze(p%d(:, end, :)));\n", i);
    printf("colorbar;\n");
    printf("title('y = 1');\n");
    printf("ylabel('x');\n");
    printf("xlabel('z');\n\n");

    printf("subplot(3, 2, 5);\n");
    printf("contourf(y, z, squeeze(p%d(1, :, :)));\n", i);
    printf("colorbar;\n");
    printf("title('x = 0');\n");
    printf("ylabel('y');\n");
    printf("xlabel('z');\n\n");

    printf("subplot(3, 2, 6);\n");
    printf("contourf(y, z, squeeze(p%d(end, :, :)));\n", i);
    printf("colorbar;\n");
    printf("title('x = 1');\n");  
    printf("ylabel('y');\n");
    printf("xlabel('z');\n\n\n");
}
  
  printf("\n");
    
  return 0;
}
*/
