#include "QuadNodeBasis.h"
#include "Legendre.h"

QuadNodeBasis::QuadNodeBasis(const int order){
  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 2;

  nVertex = 4                            ;
  nEdge   = 4 * (order - 1)              ;
  nFace   = 0                            ;
  nCell   =     (order - 1) * (order - 1);

  size = (order + 1) * (order + 1);

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
  basis = new std::vector<const Polynomial*>(size);

  // Vertex Based (Lagrange) // 
  (*basis)[0] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)));

  (*basis)[1] = 
    new Polynomial((Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 0, 0) - Polynomial(1, 0, 1, 0)));

  (*basis)[2] = 
    new Polynomial((Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0)));

  (*basis)[3] = 
    new Polynomial((Polynomial(1, 0, 0, 0) - Polynomial(1, 1, 0, 0)) *
		   (Polynomial(1, 0, 1, 0)));
  
  // Edge Based //
  int i = 4;

  for(int l = 1; l < order; l++){
    for(int e1 = 0, e2 = 1; e1 < 4; e1++, e2 = (e2 + 1) % 4){
      (*basis)[i] = 
	new Polynomial(legendre[l].compose(lifting[e2] - lifting[e1]) * 
		       (*(*basis)[e1] + *(*basis)[e2]));
            
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
      (*basis)[i] = 
	new Polynomial(legendre[l1].compose(px) * legendre[l2].compose(py));

      i++;
    }
  }

  // Free Temporary Sapce //
  delete[] legendre;
  delete[] lifting;
}

QuadNodeBasis::~QuadNodeBasis(void){
  for(int i = 0; i < size; i++)
    delete (*basis)[i];

  delete basis;
}
