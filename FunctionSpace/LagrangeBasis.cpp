#include "Exception.h"
#include "LagrangeBasis.h"

using namespace std;

LagrangeBasis::LagrangeBasis(void){
}

LagrangeBasis::~LagrangeBasis(void){
}

vector<double> LagrangeBasis::
project(const MElement& element,
	const vector<double>& coef,
	const FunctionSpaceScalar& fSpace){

  // Init New Coefs //
  const unsigned int size = point->size1();
  vector<double> newCoef(size);

  // Interpolation at Lagrange Points //
  for(unsigned int i = 0; i < size; i++){
    fullVector<double> uvw(3);
    uvw(0) = (*point)(i, 0);
    uvw(1) = (*point)(i, 1);
    uvw(2) = (*point)(i, 2);

    newCoef[i] = fSpace.interpolateInRefSpace(element, 
					      coef, 
					      uvw);
  }
    
  // Return ;
  return newCoef;
}

vector<fullVector<double> > LagrangeBasis::
project(const MElement& element,
	const vector<double>& coef,
	const FunctionSpaceVector& fSpace){
  
  // Init New Coefs //
  const unsigned int size = point->size1();
  vector<fullVector<double> > newCoef(size);

  // Interpolation at Lagrange Points //
  for(unsigned int i = 0; i < size; i++){
    fullVector<double> uvw(3);
    uvw(0) = (*point)(i, 0);
    uvw(1) = (*point)(i, 1);
    uvw(2) = (*point)(i, 2);
    
    newCoef[i] = fSpace.interpolateInRefSpace(element, 
					      coef, 
					      uvw);
  }
    
  // Return ;
  return newCoef;
}

unsigned int** LagrangeBasis::triEdgeOrder(int order){
  // Check //
  if(order <= 1)
    return NULL;

  // Number of Edge Based Basis //
  const unsigned int orderMinus = order - 1;
  const unsigned int size       = 3 * orderMinus;
  
  // Alloc //
  unsigned int i;
  unsigned int** edgeOrder = new unsigned int*[2];
  edgeOrder[0]             = new unsigned int[size];
  edgeOrder[1]             = new unsigned int[size];

  // Direct Numeration //
  i = 0;

  for(unsigned int j = 0; j < orderMinus; j++){
    for(unsigned int k = 0; k < size; k += orderMinus){
      edgeOrder[0][i] = k + j;
      i++;
    }
  }

  // Invert Numeration //
  i = 0;

 for(unsigned int j = 0; j < orderMinus; j++){
    for(unsigned int k = 0; k < size; k += orderMinus){
      edgeOrder[1][i] = k + orderMinus - 1 - j;
      i++;
    }
  }

  // Retrun //
  return edgeOrder;
}
