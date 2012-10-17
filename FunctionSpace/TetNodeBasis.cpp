#include "TetNodeBasis.h"
#include "Legendre.h"

using namespace std;

TetNodeBasis::TetNodeBasis(unsigned int order){
  // Set Basis Type //
  this->order = order;
  
  type = 0;
  dim  = 3;

  nVertex = 4;
  nEdge   = 6 * (order - 1);
  nFace   = 2 * (order - 1) * (order - 2);
  nCell   =     (order - 1) * (order - 2) * (order - 3) / 6;

  size    = nVertex + nEdge + nFace + nCell;

  // Alloc Temporary Space //
  Polynomial* legendre     = new Polynomial[order];
  Polynomial* sclLegendre  = new Polynomial[order];
  Polynomial* intLegendre  = new Polynomial[order];

  // Classical, Scaled and Intrated-Scaled Legendre Polynomial //
  const unsigned int orderMinus      = order - 1;
  const unsigned int orderMinusTwo   = order - 2;
  const unsigned int orderMinusThree = order - 3;

  Legendre::legendre(legendre, orderMinus);
  Legendre::scaled(sclLegendre, orderMinus);
  Legendre::intScaled(intLegendre, order);

  // Points definig Edges //
  const unsigned int edge0[6] = {0, 1, 2, 2, 3, 3};
  const unsigned int edge1[6] = {1, 2, 0, 3, 0, 1};

  // Points definig Faces //
  const unsigned int face0[4] = {0, 0, 0, 1};
  const unsigned int face1[4] = {1, 1, 2, 2};
  const unsigned int face2[4] = {3, 2, 3, 3};

  // Counter //
  unsigned int i;

  // Basis //
  node = new vector<const Polynomial*>(nVertex);
  edge = new vector<vector<const Polynomial*>*>(2);
  face = new vector<vector<const Polynomial*>*>(6);
  cell = new vector<const Polynomial*>(nCell);

  (*edge)[0] = new vector<const Polynomial*>(nEdge);
  (*edge)[1] = new vector<const Polynomial*>(nEdge);

  (*face)[0] = new vector<const Polynomial*>(nFace);
  (*face)[1] = new vector<const Polynomial*>(nFace);
  (*face)[2] = new vector<const Polynomial*>(nFace);
  (*face)[3] = new vector<const Polynomial*>(nFace);
  (*face)[4] = new vector<const Polynomial*>(nFace);
  (*face)[5] = new vector<const Polynomial*>(nFace);


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
  i = 0;

  for(unsigned int l = 1; l < order; l++){
    for(unsigned int e = 0; e < 6; e++){
      (*(*edge)[0])[i] = 
	new Polynomial(intLegendre[l].compose
		       (*(*node)[edge0[e]] - *(*node)[edge1[e]], 
			*(*node)[edge0[e]] + *(*node)[edge1[e]]));

      (*(*edge)[1])[i] = 
	new Polynomial(intLegendre[l].compose
		       (*(*node)[edge1[e]] - *(*node)[edge0[e]], 
			*(*node)[edge1[e]] + *(*node)[edge0[e]]));      
      
      i++;
    }
  }


  // Face Based //
  i = 0;

  for(unsigned int l1 = 1; l1 < orderMinus; l1++){
    for(unsigned int l2 = 0; l1 + l2 - 1 < orderMinusTwo; l2++){
      for(unsigned int m = 0; m < 4; m++){
	Polynomial sum = 
	  *(*node)[face0[m]] + 
	  *(*node)[face1[m]] + 
	  *(*node)[face2[m]];	  

	(*(*face)[0])[i] = 
	  new Polynomial(intLegendre[l1].compose
			 (*(*node)[face0[m]] - *(*node)[face1[m]], 
			  *(*node)[face0[m]] + *(*node)[face1[m]]) * 
			 
			 *(*node)[face2[m]] * 
			 
			 sclLegendre[l2].compose
			 (*(*node)[face2[m]] * 2 - sum, sum));

	(*(*face)[1])[i] = 
	  new Polynomial(intLegendre[l1].compose
			 (*(*node)[face1[m]] - *(*node)[face0[m]], 
			  *(*node)[face1[m]] + *(*node)[face0[m]]) * 
			 
			 *(*node)[face2[m]] * 
			 
			 sclLegendre[l2].compose
			 (*(*node)[face2[m]] * 2 - sum, sum));

	(*(*face)[2])[i] = 
	  new Polynomial(intLegendre[l1].compose
			 (*(*node)[face1[m]] - *(*node)[face2[m]], 
			  *(*node)[face1[m]] + *(*node)[face2[m]]) * 
			 
			 *(*node)[face0[m]] * 
			 
			 sclLegendre[l2].compose
			 (*(*node)[face0[m]] * 2 - sum, sum));

	(*(*face)[3])[i] = 
	  new Polynomial(intLegendre[l1].compose
			 (*(*node)[face2[m]] - *(*node)[face1[m]], 
			  *(*node)[face2[m]] + *(*node)[face1[m]]) * 
			 
			 *(*node)[face0[m]] * 
			 
			 sclLegendre[l2].compose
			 (*(*node)[face0[m]] * 2 - sum, sum));

	(*(*face)[4])[i] = 
	  new Polynomial(intLegendre[l1].compose
			 (*(*node)[face2[m]] - *(*node)[face0[m]], 
			  *(*node)[face2[m]] + *(*node)[face0[m]]) * 
			 
			 *(*node)[face1[m]] * 
			 
			 sclLegendre[l2].compose
			 (*(*node)[face1[m]] * 2 - sum, sum));

	(*(*face)[5])[i] = 
	  new Polynomial(intLegendre[l1].compose
			 (*(*node)[face0[m]] - *(*node)[face2[m]], 
			  *(*node)[face0[m]] + *(*node)[face2[m]]) * 
			 
			 *(*node)[face1[m]] * 
			 
			 sclLegendre[l2].compose
			 (*(*node)[face1[m]] * 2 - sum, sum));

	i++;
      }
    }
  }
  

  // Cell Based //
  Polynomial oneMinusFour         = Polynomial(1, 0, 0, 0) - *(*node)[3];
  Polynomial twoThreeOneMinusFour = *(*node)[2] * 2 - oneMinusFour;
  Polynomial twoFourMinusOne      = *(*node)[3] * 2 - Polynomial(1, 0, 0, 0);

  Polynomial sub = *(*node)[0] - *(*node)[1];
  Polynomial add = *(*node)[0] + *(*node)[1];

  i = 0;
  
  for(unsigned int l1 = 1; l1 < orderMinusTwo; l1++){
    for(unsigned int l2 = 0; l2 + l1 - 1 < orderMinusThree; l2++){
      for(unsigned int l3 = 0; l3 + l2 + l1 - 1 < orderMinusThree; l3++){
	
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
