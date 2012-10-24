#include "TetNodeBasis.h"
#include "Legendre.h"

using namespace std;

TetNodeBasis::TetNodeBasis(int order){
  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 3;

  nVertex = 4;
  nEdge   = 6 * (order - 1);
  nFace   = 2 * (order - 1) * (order - 2);
  nCell   =     (order - 1) * (order - 2) * (order - 3) / 6;

  size = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  const int orderMinus      = order - 1;
  const int orderMinusTwo   = order - 2;
  const int orderMinusThree = order - 3;

  Polynomial* legendre     = new Polynomial[order];
  Polynomial* sclLegendre  = new Polynomial[order];
  Polynomial* intLegendre  = new Polynomial[order];

  // Legendre Polynomial //
  Legendre::legendre(legendre, orderMinus);
  Legendre::scaled(sclLegendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Vertices definig Edges & Permutations //
  const int edgeV[2][6][2] = 
    {
      { {0, 1}, {1, 2}, {2, 0}, 
	{3, 0}, {3, 2}, {3, 1} },
      
      { {1, 0}, {2, 1}, {0, 2}, 
	{0, 3}, {2, 3}, {1, 3} }
    };

  // Vertices definig Faces & Permutations //
  const int faceV[6][4][3] = 
    {
      { {0, 2, 1}, {0, 1, 3}, {0, 3, 2}, {3, 1, 2} },
      { {2, 0, 1}, {1, 0, 3}, {3, 0, 2}, {1, 3, 2} },
      { {2, 1, 0}, {1, 3, 0}, {3, 2, 0}, {1, 2, 3} },
      { {1, 2, 0}, {3, 1, 0}, {2, 3, 0}, {2, 1, 3} },
      { {1, 0, 2}, {3, 0, 1}, {2, 0, 3}, {2, 3, 1} },
      { {0, 1, 2}, {0, 3, 1}, {0, 2, 3}, {3, 2, 1} },
    };

  // Basis //
  node = new vector<Polynomial*>(nVertex);
  edge = new vector<vector<Polynomial*>*>(2);
  face = new vector<vector<Polynomial*>*>(6);
  cell = new vector<Polynomial*>(nCell);

  (*edge)[0] = new vector<Polynomial*>(nEdge);
  (*edge)[1] = new vector<Polynomial*>(nEdge);

  (*face)[0] = new vector<Polynomial*>(nFace);
  (*face)[1] = new vector<Polynomial*>(nFace);
  (*face)[2] = new vector<Polynomial*>(nFace);
  (*face)[3] = new vector<Polynomial*>(nFace);
  (*face)[4] = new vector<Polynomial*>(nFace);
  (*face)[5] = new vector<Polynomial*>(nFace);


  // Vertex Based (Lagrange) //
  (*node)[0] = 
    new Polynomial(Polynomial(1, 0, 0, 0) - 
		   Polynomial(1, 1, 0, 0) - 
		   Polynomial(1, 0, 1, 0) - 
		   Polynomial(1, 0, 0, 1));

  (*node)[1] = 
    new Polynomial(Polynomial(1, 1, 0, 0));

  (*node)[2] = 
    new Polynomial(Polynomial(1, 0, 1, 0));

  (*node)[3] = 
    new Polynomial(Polynomial(1, 0, 0, 1));

 
  // Edge Based //
  for(int c = 0; c < 2; c++){
    unsigned int i = 0;

    for(int l = 1; l < order; l++){
      for(int e = 0; e < 6; e++){
	(*(*edge)[c])[i] = 
	  new Polynomial(intLegendre[l].compose
			 (*(*node)[edgeV[c][e][0]] - *(*node)[edgeV[c][e][1]], 
			  *(*node)[edgeV[c][e][0]] + *(*node)[edgeV[c][e][1]]));
	
	i++;
      }
    }
  }


  // Face Based //
  for(int c = 0; c < 6; c++){
    unsigned int i = 0;

    for(int l1 = 1; l1 < orderMinus; l1++){
      for(int l2 = 0; l1 + l2 - 1 < orderMinusTwo; l2++){
	for(int f = 0; f < 4; f++){
	  Polynomial sum = 
	    *(*node)[faceV[c][f][0]] + 
	    *(*node)[faceV[c][f][1]] + 
	    *(*node)[faceV[c][f][2]];	  
	  
	  (*(*face)[c])[i] = 
	    new Polynomial(intLegendre[l1].compose
			   (*(*node)[faceV[c][f][0]] - *(*node)[faceV[c][f][1]], 
			    *(*node)[faceV[c][f][0]] + *(*node)[faceV[c][f][1]]) * 
			 
			   *(*node)[faceV[c][f][2]] * 
			 
			   sclLegendre[l2].compose
			   (*(*node)[faceV[c][f][2]] * 2 - sum, sum));
	
	  i++;
	}
      }
    }
  }
  

  // Cell Based //
  Polynomial oneMinusFour         = Polynomial(1, 0, 0, 0) - *(*node)[3];
  Polynomial twoThreeOneMinusFour = *(*node)[2] * 2 - oneMinusFour;
  Polynomial twoFourMinusOne      = *(*node)[3] * 2 - Polynomial(1, 0, 0, 0);

  Polynomial sub = *(*node)[0] - *(*node)[1];
  Polynomial add = *(*node)[0] + *(*node)[1];

  unsigned int i = 0;
  
  for(int l1 = 1; l1 < orderMinusTwo; l1++){
    for(int l2 = 0; l2 + l1 - 1 < orderMinusThree; l2++){
      for(int l3 = 0; l3 + l2 + l1 - 1 < orderMinusThree; l3++){
	
	(*cell)[i] = 
	  new Polynomial(intLegendre[l1].compose(sub, add)             * 
			 *(*node)[2]                                   * 		 
			 sclLegendre[l2].compose(twoThreeOneMinusFour, 
						 oneMinusFour)         *
			 *(*node)[3]                                   *
			 legendre[l3].compose(twoFourMinusOne));
	
	i++;
      }
    }
  }
  
  // Free Temporary Sapce //
  delete[] legendre;
  delete[] sclLegendre;
  delete[] intLegendre;
}

TetNodeBasis::~TetNodeBasis(void){
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
}
