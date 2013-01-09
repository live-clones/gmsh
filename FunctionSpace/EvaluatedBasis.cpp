#include "Polynomial.h"
#include "EvaluatedBasis.h"

using namespace std;

EvaluatedBasis::
EvaluatedBasis(const BasisScalar& basis, 
	       const fullMatrix<double>& point){
  // Data //
  refSpace  = &basis.getReferenceSpace(); 
  nRefSpace = refSpace->getNPermutation();
  scalar    = true;
  nFunction = basis.getNFunction();
  nPoint    = point.size1();

  // Alloc //
  eBasis = new vector<fullMatrix<double>*>(nRefSpace);
  
  for(unsigned int i = 0; i < nRefSpace; i++)
    (*eBasis)[i] = new fullMatrix<double>(nFunction, nPoint);

  // Evaluate //
  for(unsigned int i = 0; i < nRefSpace; i++)
    for(unsigned int j = 0; j < nFunction; j++)
      for(unsigned int k = 0; k < nPoint; k++)
	(*(*eBasis)[i])(j, k) = 
	  basis.getFunction(i, j).at(point(k, 0),
				     point(k, 1),
				     point(k, 2));
}

EvaluatedBasis::
EvaluatedBasis(const BasisVector& basis, 
	       const fullMatrix<double>& point){
  // Data //
  refSpace  = &basis.getReferenceSpace(); 
  nRefSpace = refSpace->getNPermutation();
  scalar    = false;
  nFunction = basis.getNFunction();  
  nPoint    = point.size1();
  
  // Alloc //
  eBasis = new vector<fullMatrix<double>*>(nRefSpace);
  
  // WARNING Each Evaluation Got *3* Component !
  const unsigned int nPointThree = nPoint * 3;
 
  for(unsigned int i = 0; i < nRefSpace; i++)
    (*eBasis)[i] = new fullMatrix<double>(nFunction, nPointThree);

  // Evaluate //
  fullVector<double> tmp(3);

  for(unsigned int i = 0; i < nRefSpace; i++){
    for(unsigned int j = 0; j < nFunction; j++){
      for(unsigned int k = 0; k < nPoint; k++){
	tmp = Polynomial::at(basis.getFunction(i, j),
			     point(k, 0),
			     point(k, 1),
			     point(k, 2));

	(*(*eBasis)[i])(j, 3 * k)     = tmp(0);
	(*(*eBasis)[i])(j, 3 * k + 1) = tmp(1);
	(*(*eBasis)[i])(j, 3 * k + 2) = tmp(2);
      }
    }
  }
}

EvaluatedBasis::~EvaluatedBasis(void){
  for(unsigned int i = 0; i < nRefSpace; i++)
    delete (*eBasis)[i];

  delete eBasis;
}
