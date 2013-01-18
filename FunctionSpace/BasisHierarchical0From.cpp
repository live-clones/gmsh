#include <sstream>
#include "Exception.h"
#include "BasisHierarchical0From.h"

using namespace std;

BasisHierarchical0From::BasisHierarchical0From(void){
  // Scalar Basis ? //
  scalar = true;

  // Grad Basis //
  hasGrad = false;
  grad    = NULL;

  // PreEvaluation //
  preEvaluated     = false;
  preEvaluatedGrad = false;

  preEvaluatedFunction     = NULL;
  preEvaluatedGradFunction = NULL;
}

BasisHierarchical0From::~BasisHierarchical0From(void){
  // Grad Basis //
  if(hasGrad){
    for(unsigned int i = 0; i < nRefSpace; i++){
      for(unsigned int j = 0; j < nFunction; j++)
	delete grad[i][j];

      delete[] grad[i];
    }

    delete[] grad;
  }

  // PreEvaluation //
  if(preEvaluated){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedFunction[i];

    delete[] preEvaluatedFunction;
  }

  if(preEvaluatedGrad){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedGradFunction[i];

    delete[] preEvaluatedGradFunction;
  }
}

unsigned int BasisHierarchical0From::
getNOrientation(void) const{
  return refSpace->getNPermutation();
}

unsigned int BasisHierarchical0From::
getOrientation(const MElement& element) const{
  return refSpace->getPermutation(element);
}

fullMatrix<double>* BasisHierarchical0From::
getFunctions(const MElement& element,
	     double u, double v, double w) const{

  // Alloc Memory //
  fullMatrix<double>* values = new fullMatrix<double>(nFunction, 1);

  // Define Orientation //
  unsigned int orientation = refSpace->getPermutation(element);

  // Fill Matrix //
  for(unsigned int i = 0; i < nFunction; i++)
    (*values)(i, 0) = basis[orientation][i]->at(u, v, w);

  // Return //
  return values;
}

fullMatrix<double>* BasisHierarchical0From::
getFunctions(unsigned int orientation,
	     double u, double v, double w) const{

  // Alloc Memory //
  fullMatrix<double>* values = new fullMatrix<double>(nFunction, 1);

  // Fill Matrix //
  for(unsigned int i = 0; i < nFunction; i++)
    (*values)(i, 0) = basis[orientation][i]->at(u, v, w);

  // Return //
  return values;
}

void BasisHierarchical0From::
preEvaluateFunctions(const fullMatrix<double>& point) const{
  // Delete if older //
  if(preEvaluated){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedFunction[i];

    delete[] preEvaluatedFunction;
  }

  // Alloc //
  const unsigned int nPoint = point.size1();
  preEvaluatedFunction      = new fullMatrix<double>*[nRefSpace];

  for(unsigned int i = 0; i < nRefSpace; i++)
    preEvaluatedFunction[i] =
      new fullMatrix<double>(nFunction, nPoint);

  // Fill Matrix //
  for(unsigned int i = 0; i < nRefSpace; i++)
    for(unsigned int j = 0; j < nFunction; j++)
      for(unsigned int k = 0; k < nPoint; k++)
	(*preEvaluatedFunction[i])(j, k) =
	  basis[i][j]->at(point(k, 0),
			  point(k, 1),
			  point(k, 2));

  // PreEvaluated //
  preEvaluated = true;
}

void BasisHierarchical0From::
preEvaluateDerivatives(const fullMatrix<double>& point) const{
  // Build Grad //
  if(!hasGrad)
    getGrad();

  // Delete if older //
  if(preEvaluatedGrad){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedGradFunction[i];

    delete[] preEvaluatedGradFunction;
  }

  // Alloc //
  const unsigned int nPoint  = point.size1();
  const unsigned int nPoint3 = nPoint * 3;
  preEvaluatedGradFunction   = new fullMatrix<double>*[nRefSpace];

  for(unsigned int i = 0; i < nRefSpace; i++)
    preEvaluatedGradFunction[i] =
      new fullMatrix<double>(nFunction, nPoint3);

  // Fill Matrix //
  fullVector<double> tmp(3);

  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++){
      for(unsigned int k = 0; k < nPoint; k++){
	tmp = Polynomial::at(*grad[i][j],
			     point(k, 0),
			     point(k, 1),
			     point(k, 2));

	(*preEvaluatedGradFunction[i])(j, 3 * k)     = tmp(0);
	(*preEvaluatedGradFunction[i])(j, 3 * k + 1) = tmp(1);
	(*preEvaluatedGradFunction[i])(j, 3 * k + 2) = tmp(2);
      }
    }
  }

  // PreEvaluated //
  preEvaluatedGrad = true;
}

const fullMatrix<double>& BasisHierarchical0From::
getPreEvaluatedFunctions(const MElement& element) const{
  return getPreEvaluatedFunctions(refSpace->getPermutation(element));
}

const fullMatrix<double>& BasisHierarchical0From::
getPreEvaluatedDerivatives(const MElement& element) const{
  return getPreEvaluatedDerivatives(refSpace->getPermutation(element));
}

const fullMatrix<double>& BasisHierarchical0From::
getPreEvaluatedFunctions(unsigned int orientation) const{
  if(!preEvaluated)
    throw Exception("getPreEvaluatedFunction: function has not been preEvaluated");

  return *preEvaluatedFunction[orientation];
}

const fullMatrix<double>& BasisHierarchical0From::
getPreEvaluatedDerivatives(unsigned int orientation) const{
  if(!preEvaluatedGrad)
    throw Exception("getPreEvaluatedDerivative: gradient has not been preEvaluated");

  return *preEvaluatedGradFunction[orientation];
}

void BasisHierarchical0From::getGrad(void) const{
  // Alloc //
  grad = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    grad[s] = new vector<Polynomial>*[nFunction];

  // Grad //
  for(unsigned int s = 0; s < nRefSpace; s++)
    for(unsigned int f = 0 ; f < nFunction; f++)
      grad[s][f] =
	new vector<Polynomial>(basis[s][f]->gradient());

  // Has Grad //
  hasGrad = true;
}

string BasisHierarchical0From::toString(void) const{
  stringstream stream;
  unsigned int i = 0;
  const unsigned int refSpace = 0;

  stream << "Vertex Based:" << endl;
  for(; i < nVertex; i++)
    stream << "f("  << i + 1                 << ") = "
	   << basis[refSpace][i]->toString() << endl;

  stream << "Edge Based:"   << endl;
  for(; i < nVertex + nEdge; i++)
    stream << "f(" << i + 1                  << ") = "
	   << basis[refSpace][i]->toString() << endl;

  stream << "Face Based:"   << endl;
  for(; i < nVertex + nEdge + nFace; i++)
    stream << "f(" << i + 1                  << ") = "
	   << basis[refSpace][i]->toString() << endl;

  stream << "Cell Based:"   << endl;
  for(; i < nVertex + nEdge + nFace + nCell; i++)
    stream << "f("  << i + 1                 << ") = "
	   << basis[refSpace][i]->toString() << endl;

  return stream.str();
}
