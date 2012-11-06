#include "Exception.h"
#include "LagrangeBasis.h"

using namespace std;

LagrangeBasis::LagrangeBasis(void){
}

LagrangeBasis::~LagrangeBasis(void){
}

fullVector<double> LagrangeBasis::
project(const fullVector<double>& coef,
	const std::vector<const Polynomial*>& basis){

  // Init New Coefs //
  const unsigned int size = point->size1();
  fullVector<double> newCoef(size);

  // Interpolation at Lagrange Points //
  const unsigned int nCoef = coef.size();
 
  for(unsigned int i = 0; i < size; i++){
    newCoef(i) = 0;
    
    for(unsigned int j = 0; j < nCoef; j++)
      newCoef(i) += coef(j) * basis[j]->at((*point)(i, 0),
					   (*point)(i, 1),
					   (*point)(i, 2));
  }
    
  // Return ;
  return newCoef;
}
