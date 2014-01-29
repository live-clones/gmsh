#include "ReferenceSpaceManager.h"
#include "BasisLagrange.h"
#include "Exception.h"

using namespace std;

BasisLagrange::BasisLagrange(void){
  scalar = true;
  form   = 0;

  preEvaluated     = false;
  preEvaluatedGrad = false;

  preEvaluatedFunction     = NULL;
  preEvaluatedGradFunction = NULL;
}

BasisLagrange::~BasisLagrange(void){
  if(preEvaluated)
    delete preEvaluatedFunction;

  if(preEvaluatedGrad)
    delete preEvaluatedGradFunction;
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

  // Permute retValues, accordingly to ReferenceSpace
  permutation(ReferenceSpaceManager::getOrientation(element), retValues);
}

void BasisLagrange::
getFunctions(fullMatrix<double>& retValues,
             size_t orientation,
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

  // Permute retValues, accordingly to ReferenceSpace
  permutation(orientation, retValues);
}

void BasisLagrange::getDerivative(fullMatrix<double>& retValues,
                                  const MElement& element,
                                  double u, double v, double w) const{
  throw Exception("Not Implemented");
}

void BasisLagrange::preEvaluateFunctions(const fullMatrix<double>& point) const{
  // Delete if older //
  if(preEvaluated)
    delete preEvaluatedFunction;

  // Fill Matrix //
  fullMatrix<double> tmp;
  lBasis->f(point, tmp);

  // Transpose 'tmp': otherwise not coherent with df !!
  preEvaluatedFunction = new fullMatrix<double>(tmp.transpose());

  // PreEvaluated //
  preEvaluated = true;
}

void BasisLagrange::
preEvaluateDerivatives(const fullMatrix<double>& point) const{
  // Delete if older //
  if(preEvaluatedGrad)
    delete preEvaluatedGradFunction;

  // Alloc //
  preEvaluatedGradFunction = new fullMatrix<double>;

  // Fill Matrix //
  lBasis->df(point, *preEvaluatedGradFunction);

  // PreEvaluated //
  preEvaluatedGrad = true;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedFunctions(const MElement& element) const{
  return *preEvaluatedFunction;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedDerivatives(const MElement& element) const{
  return *preEvaluatedGradFunction;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedFunctions(size_t orientation) const{
  return *preEvaluatedFunction;
}

const fullMatrix<double>&
BasisLagrange::getPreEvaluatedDerivatives(size_t orientation) const{
  return *preEvaluatedGradFunction;
}

vector<double> BasisLagrange::
project(const MElement& element,
        const std::vector<double>& coef,
        const FunctionSpaceScalar& fSpace){

  // Init New Coefs //
  const size_t size = lPoint->size1();
  const size_t dim  = lPoint->size2();

  vector<double> newCoef(size);

  // Interpolation at Lagrange Points //
  for(size_t i = 0; i < size; i++){
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

std::vector<double> BasisLagrange::
project(const MElement& element,
        const std::vector<double>& coef,
        const FunctionSpaceVector& fSpace){

  // Init New Coefs //
  const size_t size = lPoint->size1();
  const size_t dim  = lPoint->size2();

  vector<double>     newCoef(size * 3);
  fullVector<double> tmp(3);

  // Interpolation at Lagrange Points //
  for(size_t i = 0; i < size; i++){
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

    tmp = fSpace.interpolateInRefSpace(element,
                                       coef,
                                       uvw);
    newCoef[i * 3 + 0] = tmp(0);
    newCoef[i * 3 + 1] = tmp(1);
    newCoef[i * 3 + 2] = tmp(2);
  }

  // Return ;
  return newCoef;
}

void BasisLagrange::permutation(size_t orientation,
                                fullMatrix<double>& function) const{
}

std::string BasisLagrange::toString(void) const{
  return std::string("BasisLagrange::toString() not Implemented");
}
