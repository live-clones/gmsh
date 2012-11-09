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
