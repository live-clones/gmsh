#include "Exception.h"
#include "BasisLagrange.h"

using namespace std;

BasisLagrange::BasisLagrange(void){
  scalar = true;
}

BasisLagrange::~BasisLagrange(void){
}

unsigned int BasisLagrange::
getNOrientation(void) const{
  return 1;
}

unsigned int BasisLagrange::
getOrientation(const MElement& element) const{
  return 0;
}

void BasisLagrange::
getFunctionPermutation(const MElement& element,
                       unsigned int* indexPermutation) const{
}

void BasisLagrange::
getFunctions(fullMatrix<double>& retValues,
             const MElement& element,
             double u, double v, double w) const{

  // Fill Matrix //
  fullMatrix<double> tmp;
  fullMatrix<double> point(1, 3);
  point(0, 0) = u;
  point(0, 1) = v;
  point(0, 2) = w;

  lBasis->f(point, tmp);

  // Transpose 'tmp': otherwise not coherent with df !!
  retValues = tmp.transpose();
}

void BasisLagrange::
getFunctions(fullMatrix<double>& retValues,
             unsigned int orientation,
             double u, double v, double w) const{

  // Fill Matrix //
  fullMatrix<double> tmp;
  fullMatrix<double> point(1, 3);
  point(0, 0) = u;
  point(0, 1) = v;
  point(0, 2) = w;

  lBasis->f(point, tmp);

  // Transpose 'tmp': otherwise not coherent with df !!
  retValues = tmp.transpose();
}

void BasisLagrange::preEvaluateFunctions(const fullMatrix<double>& point) const{
  throw Exception("BasisLagrange::Not Implemented");
}

void BasisLagrange::
preEvaluateDerivatives(const fullMatrix<double>& point) const{
  throw Exception("BasisLagrange::Not Implemented");
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedFunctions(const MElement& element) const{
  throw Exception("BasisLagrange::Not Implemented");
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedDerivatives(const MElement& element) const{
  throw Exception("BasisLagrange::Not Implemented");
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedFunctions(unsigned int orientation) const{
  throw Exception("BasisLagrange::Not Implemented");
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedDerivatives(unsigned int orientation) const{
  throw Exception("BasisLagrange::Not Implemented");
}

vector<double> BasisLagrange::
project(const MElement& element,
        const vector<double>& coef,
        const FunctionSpaceScalar& fSpace){

  // Init New Coefs //
  const unsigned int size = lPoint->size1();
  const unsigned int dim  = lPoint->size2();

  vector<double> newCoef(size);

  // Interpolation at Lagrange Points //
  for(unsigned int i = 0; i < size; i++){
    fullVector<double> uvw(3);

    if(dim > 0)
      uvw(0) = (*lPoint)(i, 0);
    else
      uvw(0) = 0;

    if(dim > 1)
      uvw(1) = (*lPoint)(i, 1);
    else
      uvw(1) = 0;

    if(dim > 2)
      uvw(2) = (*lPoint)(i, 2);
    else
      uvw(2) = 0;

    newCoef[i] = fSpace.interpolateInRefSpace(element,
                                              coef,
                                              uvw);
  }

  // Return ;
  return newCoef;
}

vector<fullVector<double> > BasisLagrange::
project(const MElement& element,
        const vector<double>& coef,
        const FunctionSpaceVector& fSpace){

  // Init New Coefs //
  const unsigned int size = lPoint->size1();
  vector<fullVector<double> > newCoef(size);

  // Interpolation at Lagrange Points //
  for(unsigned int i = 0; i < size; i++){
    fullVector<double> uvw(3);

    if(dim > 0)
      uvw(0) = (*lPoint)(i, 0);
    else
      uvw(0) = 0;

    if(dim > 1)
      uvw(1) = (*lPoint)(i, 1);
    else
      uvw(1) = 0;

    if(dim > 2)
      uvw(2) = (*lPoint)(i, 2);
    else
      uvw(2) = 0;

    newCoef[i] = fSpace.interpolateInRefSpace(element,
                                              coef,
                                              uvw);
  }

  // Return ;
  return newCoef;
}
