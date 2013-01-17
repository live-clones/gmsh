#include <sstream>
#include "Exception.h"
#include "BasisHierarchicalVector.h"

using namespace std;

BasisHierarchicalVector::BasisHierarchicalVector(void){
  // Scalar Basis ?//
  scalar = false;

  // Curl Basis //
  hasCurl = false;
  curl    = NULL;

  // PreEvaluation //
  preEvaluated     = false;
  preEvaluatedCurl = false;

  preEvaluatedFunction     = NULL;
  preEvaluatedCurlFunction = NULL;
}

BasisHierarchicalVector::~BasisHierarchicalVector(void){
  // Curl Basis //
  if(hasCurl){
    for(unsigned int i = 0; i < nRefSpace; i++){
      for(unsigned int j = 0; j < nFunction; j++)
	delete curl[i][j];

      delete[] curl[i];
    }

    delete[] curl;
  }

  // PreEvaluation //
  if(preEvaluated){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedFunction[i];

    delete[] preEvaluatedFunction;
  }

  if(preEvaluatedCurl){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedCurlFunction[i];

    delete[] preEvaluatedCurlFunction;
  }
}

unsigned int BasisHierarchicalVector::
getNOrientation(void) const{
  return refSpace->getNPermutation();
}

unsigned int BasisHierarchicalVector::
getOrientation(const MElement& element) const{
  return refSpace->getPermutation(element);
}

fullMatrix<double>* BasisHierarchicalVector::
getFunctions(const MElement& element,
	     double u, double v, double w) const{

  // Alloc Memory //
  fullMatrix<double>* values = new fullMatrix<double>(nFunction, 3);

  // Define Orientation //
  unsigned int orientation = refSpace->getPermutation(element);

  // Fill Vector //
  for(unsigned int i = 0; i < nFunction; i++){
    fullVector<double> eval =
      Polynomial::at(*basis[orientation][i], u, v, w);

    (*values)(i, 0) = eval(0);
    (*values)(i, 1) = eval(1);
    (*values)(i, 2) = eval(2);
  }

  // Return //
  return values;
}

fullMatrix<double>* BasisHierarchicalVector::
getFunctions(unsigned int orientation,
	     double u, double v, double w) const{

  // Alloc Memory //
  fullMatrix<double>* values = new fullMatrix<double>(nFunction, 3);

  // Fill Vector //
  for(unsigned int i = 0; i < nFunction; i++){
    fullVector<double> eval =
      Polynomial::at(*basis[orientation][i], u, v, w);

    (*values)(i, 0) = eval(0);
    (*values)(i, 1) = eval(1);
    (*values)(i, 2) = eval(2);
  }

  // Return //
  return values;
}

void BasisHierarchicalVector::
preEvaluateFunctions(const fullMatrix<double>& point) const{
  // Delete if older //
  if(preEvaluated){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedFunction[i];

    delete[] preEvaluatedFunction;
  }

  // Alloc //
  const unsigned int nPoint  = point.size1();
  const unsigned int nPoint3 = nPoint * 3;
  preEvaluatedFunction       = new fullMatrix<double>*[nRefSpace];

  for(unsigned int i = 0; i < nRefSpace; i++)
    preEvaluatedFunction[i] =
      new fullMatrix<double>(nFunction, nPoint3);

  // Fill Matrix //
  fullVector<double> tmp(3);

  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++){
      for(unsigned int k = 0; k < nPoint; k++){
	tmp = Polynomial::at(*basis[i][j],
			     point(k, 0),
			     point(k, 1),
			     point(k, 2));

	(*preEvaluatedFunction[i])(j, 3 * k)     = tmp(0);
	(*preEvaluatedFunction[i])(j, 3 * k + 1) = tmp(1);
	(*preEvaluatedFunction[i])(j, 3 * k + 2) = tmp(2);
      }
    }
  }

  // PreEvaluated //
  preEvaluated = true;
}

void BasisHierarchicalVector::
preEvaluateDerivatives(const fullMatrix<double>& point) const{
  // Build Curl //
  if(!hasCurl)
    getCurl();

  // Delete if older //
  if(preEvaluatedCurl){
    for(unsigned int i = 0; i < nRefSpace; i++)
      delete preEvaluatedCurlFunction[i];

    delete[] preEvaluatedCurlFunction;
  }

  // Alloc //
  const unsigned int nPoint  = point.size1();
  const unsigned int nPoint3 = nPoint * 3;
  preEvaluatedCurlFunction   = new fullMatrix<double>*[nRefSpace];

  for(unsigned int i = 0; i < nRefSpace; i++)
    preEvaluatedCurlFunction[i] =
      new fullMatrix<double>(nFunction, nPoint3);

  // Fill Matrix //
  fullVector<double> tmp(3);

  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++){
      for(unsigned int k = 0; k < nPoint; k++){
	tmp = Polynomial::at(*curl[i][j],
			     point(k, 0),
			     point(k, 1),
			     point(k, 2));

	(*preEvaluatedCurlFunction[i])(j, 3 * k)     = tmp(0);
	(*preEvaluatedCurlFunction[i])(j, 3 * k + 1) = tmp(1);
	(*preEvaluatedCurlFunction[i])(j, 3 * k + 2) = tmp(2);
      }
    }
  }

  // PreEvaluated //
  preEvaluatedCurl = true;
}

const fullMatrix<double>& BasisHierarchicalVector::
getPreEvaluatedFunctions(const MElement& element) const{
  return getPreEvaluatedFunctions(refSpace->getPermutation(element));
}

const fullMatrix<double>& BasisHierarchicalVector::
getPreEvaluatedDerivatives(const MElement& element) const{
  return getPreEvaluatedDerivatives(refSpace->getPermutation(element));
}

const fullMatrix<double>& BasisHierarchicalVector::
getPreEvaluatedFunctions(unsigned int orientation) const{
  if(!preEvaluated)
    throw Exception("getPreEvaluatedFunction: function has not been preEvaluated");

  return *preEvaluatedFunction[orientation];
}

const fullMatrix<double>& BasisHierarchicalVector::
getPreEvaluatedDerivatives(unsigned int orientation) const{
  if(!preEvaluatedCurl)
    throw Exception("getPreEvaluatedDerivative: curl has not been preEvaluated");

  return *preEvaluatedCurlFunction[orientation];
}

void BasisHierarchicalVector::getCurl(void) const{
  // Alloc //
  curl = new vector<Polynomial>**[nRefSpace];

  for(unsigned int s = 0; s < nRefSpace; s++)
    curl[s] = new vector<Polynomial>*[nFunction];

  // Curl //
  for(unsigned int s = 0; s < nRefSpace; s++)
    for(unsigned int f = 0 ; f < nFunction; f++)
      curl[s][f] =
	new vector<Polynomial>(Polynomial::curl(*basis[s][f]));

  // Has Curl //
  hasCurl = true;
}

string BasisHierarchicalVector::toString(void) const{
  stringstream stream;
  unsigned int i = 0;
  const unsigned int refSpace = 0;

  stream << "Vertex Based:" << endl;
  for(; i < nVertex; i++)
    stream << "f("   << i + 1                               << ") = " << endl
	   << "\t[ " << (*basis[refSpace][i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[2].toString() << " ]"   << endl;

  stream << "Edge Based:"   << endl;
  for(; i < nVertex + nEdge; i++)
    stream << " f("  << i + 1                               << ") = " << endl
	   << "\t[ " << (*basis[refSpace][i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[2].toString() << " ]"   << endl;

  stream << "Face Based:"   << endl;
  for(; i < nVertex + nEdge + nFace; i++)
    stream << " f("  << i + 1                               << ") = " << endl
	   << "\t[ " << (*basis[refSpace][i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[2].toString() << " ]"   << endl;

  stream << "Cell Based:"   << endl;
  for(; i < nVertex + nEdge + nFace + nCell; i++)
    stream << " f("  << i + 1                               << ") = " << endl
	   << "\t[ " << (*basis[refSpace][i])[0].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[1].toString() << " ]"   << endl
	   << "\t[ " << (*basis[refSpace][i])[2].toString() << " ]"   << endl;

  return stream.str();
}
