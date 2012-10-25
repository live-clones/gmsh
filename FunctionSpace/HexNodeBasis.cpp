#include "HexNodeBasis.h"
#include "Legendre.h"

using namespace std;

HexNodeBasis::HexNodeBasis(int order){
  /*
  // Set Basis Type //
  this->order = order;

  type = 0;
  dim  = 3;

  nVertex =  8;
  nEdge   = 12 * (order - 1);
  nFace   =  6 * (order - 1) * (order - 1);
  nCell   =      (order - 1) * (order - 1) * (order - 1);

  nEdgeClosure = 2;
  nFaceClosure = 8;

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  Polynomial* legendre = new Polynomial[order];
  Polynomial* lifting  = new Polynomial[8];

  Polynomial* xi       = new Polynomial[6];
  Polynomial* eta      = new Polynomial[6];
  Polynomial* lambda   = new Polynomial[6];

  // Legendre Polynomial //
  Legendre::integrated(legendre, order);

  // Vertices definig Edges & Permutations //
  const int edgeV[2][12][2] = 
    {
      { {0, 1}, {0, 3}, {0, 4}, {1, 2}, {1, 5}, {2, 3}, 
	{2, 6},	{3, 7}, {4, 5}, {4, 7}, {5, 6}, {6, 7} },

      { {1, 0}, {3, 0}, {4, 0}, {2, 1}, {5, 1}, {3, 2}, 
	{6, 2},	{7, 3}, {5, 4}, {7, 4}, {6, 5}, {7, 6} },
    };

  const int faceV[6][4] = 
    {
      {0, 3, 2, 1},
      {0, 1, 5, 4},
      {0, 4, 7, 3},
      {1, 2, 6, 5},
      {2, 3, 7, 6},
      {4, 5, 6, 7}
    };

  
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
  const int edge1[12] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3};
  const int edge2[12] = {1, 2, 3, 0, 5, 6, 7, 4, 4, 5, 6, 7};

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
  const int face1[6] = {0, 3, 2, 1, 5, 4};
  const int face2[6] = {1, 7, 6, 0, 6, 7};
  const int face3[6] = {2, 6, 5, 4, 7, 3};
  const int face4[6] = {3, 2, 1, 5, 4, 0};

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
*/
}

HexNodeBasis::~HexNodeBasis(void){
  /*
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
  for(int c = 0; c < 6; c++){
    for(int i = 0; i < nFace; i++)
      delete (*(*face)[c])[i];
    
    delete (*face)[c];
  }

  delete face;


  // Cell Based //
  for(int i = 0; i < nCell; i++)
    delete (*cell)[i];

  delete cell;
  */
}
