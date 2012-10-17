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
  basis = new std::vector<const Polynomial*>(size);


  // Vertex Based (Lagrange) // 
  (*basis)[0] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1)));

  (*basis)[1] = 
    new Polynomial((Polynomial(1, 1, 0, 0))                          *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1)));

  (*basis)[2] = 
    new Polynomial((Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1)));

  (*basis)[3] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0))                          *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 0, 1)));

  (*basis)[4] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
		   Polynomial(1, 0, 0, 1));

  (*basis)[5] = 
    new Polynomial((Polynomial(1, 1, 0, 0))                          *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)) *
		   Polynomial(1, 0, 0, 1));

  (*basis)[6] = 
    new Polynomial((Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0)) *
		   Polynomial(1, 0, 0, 1));

  (*basis)[7] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0))                          *
		   Polynomial(1, 0, 0, 1));

  
  // Edge Based //
  // Keep counting
  int i = 8;

  // Points definig Edges
  const unsigned int edge1[12] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3};
  const unsigned int edge2[12] = {1, 2, 3, 0, 5, 6, 7, 4, 4, 5, 6, 7};

  for(int l = 1; l < order; l++){
    for(int e = 0; e < 12; e++){
      (*basis)[i] = new Polynomial(
	legendre[l].compose(lifting[edge1[e]] - lifting[edge2[e]]) * 
	(*(*basis)[edge1[e]] + *(*basis)[edge2[e]]));
            
      i++;
    }
  }

  
  // Face Based (Preliminary) //
  // Points definig Faces
  const unsigned int face1[6] = {0, 3, 2, 1, 5, 4};
  const unsigned int face2[6] = {1, 7, 6, 0, 6, 7};
  const unsigned int face3[6] = {2, 6, 5, 4, 7, 3};
  const unsigned int face4[6] = {3, 2, 1, 5, 4, 0};

  // 'Xi' Functions
  for(int f = 0; f < 6; f++)
    xi[f]  = lifting[face1[f]] - lifting[face2[f]];

  // 'Eta' Functions
  for(int f = 0; f < 6; f++)
    eta[f] = lifting[face1[f]] - lifting[face4[f]];

  // 'Lambda' Functions
  for(int f = 0; f < 6; f++)
    lambda[f] = 
      *(*basis)[face1[f]] +
      *(*basis)[face2[f]] +
      *(*basis)[face3[f]] +
      *(*basis)[face4[f]];


  // Face Based //
  for(int l1 = 1; l1 < order; l1++){
    for(int l2 = 1; l2 < order; l2++){
      for(int f = 0; f < 6; f++){	
	(*basis)[i] = new Polynomial(
	  legendre[l1].compose(xi[f])  *
	  legendre[l2].compose(eta[f]) *
	  lambda[f]);
	  
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
	  new Polynomial(legendre[l1].compose(px) * 
			 legendre[l2].compose(py) *
			 legendre[l3].compose(pz));
	
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
  for(int i = 0; i < size; i++)
    delete (*basis)[i];

  delete basis;
}
