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

  basis->f(point, tmp);
  
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
