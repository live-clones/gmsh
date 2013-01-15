#include "BasisLagrange.h"

BasisLagrange::BasisLagrange(void){
}

BasisLagrange::~BasisLagrange(void){
}

fullMatrix<double>* BasisLagrange::
getFunctions(const MElement& element, 
	     double u, double v, double w) const{
  return new fullMatrix<double>(nFunction, 1);
}

fullMatrix<double>* BasisLagrange::getFunctions(unsigned int permutation, 
						double u, double v, double w) const{

  // Alloc Memory //
  fullMatrix<double>  tmp(nFunction, 1);
  fullMatrix<double>* values = new fullMatrix<double>(nFunction, 1);

  // Fill Matrix //
  fullMatrix<double> point(1, 3);
  point(0, 0) = u;
  point(0, 1) = v;
  point(0, 2) = w;

  lBasis->f(point, tmp);
  
  *values = tmp.transpose(); // Otherwise not coherent with df !!
  
  // Return //
  return values;
}

void BasisLagrange::preEvaluateFunctions(const fullMatrix<double>& point) const{
}

void BasisLagrange::preEvaluateGradFunctions(const fullMatrix<double>& point) const{
}

const fullMatrix<double>& 
BasisLagrange::getPreEvaluatedFunctions(const MElement& element) const{
  return fullMatrix<double>(nFunction, 1);
}
 
const fullMatrix<double>& 
BasisLagrange::getPreEvaluatedGradFunctions(const MElement& element) const{
  return fullMatrix<double>(nFunction, 1);
}

std::vector<double> BasisLagrange::
project(const MElement& element,
	const std::vector<double>& coef,
	const FunctionSpaceScalar& fSpace){
  
  // Init New Coefs //
  const unsigned int size = lPoint->size1();
  std::vector<double> newCoef(size);
  
  // Interpolation at Lagrange Points //
  for(unsigned int i = 0; i < size; i++){
    fullVector<double> uvw(3);
    uvw(0) = (*lPoint)(i, 0);
    uvw(1) = (*lPoint)(i, 1);
    uvw(2) = (*lPoint)(i, 2);
    
    newCoef[i] = fSpace.interpolateInRefSpace(element, 
					      coef, 
					      uvw);
  }
  
  // Return ;
  return newCoef;
}

std::vector<fullVector<double> > BasisLagrange::
project(const MElement& element,
	const std::vector<double>& coef,
	const FunctionSpaceVector& fSpace){
  
  // Init New Coefs //
  const unsigned int size = lPoint->size1();
  std::vector<fullVector<double> > newCoef(size);
  
  // Interpolation at Lagrange Points //
  for(unsigned int i = 0; i < size; i++){
    fullVector<double> uvw(3);
    uvw(0) = (*lPoint)(i, 0);
    uvw(1) = (*lPoint)(i, 1);
    uvw(2) = (*lPoint)(i, 2);
    
    newCoef[i] = fSpace.interpolateInRefSpace(element, 
					      coef, 
					      uvw);
  }
  
  // Return ;
  return newCoef;
}
