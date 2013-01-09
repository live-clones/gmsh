#ifndef _EVALUATEDBASIS_H_
#define _EVALUATEDBASIS_H_

#include <vector>
#include "fullMatrix.h"
#include "BasisScalar.h"
#include "BasisVector.h"
#include "MElement.h"
#include "ReferenceSpace.h"

/**
   @class EvaluatedBasis
   @brief A Basis that has been Evaluated

   This class is A basis that has been Evaluated at
   some given points.@n
 */

class EvaluatedBasis{
 private:
  const ReferenceSpace* refSpace;
  unsigned int nRefSpace;
  bool         scalar;

  unsigned int nFunction;
  unsigned int nPoint;

  std::vector<fullMatrix<double>*>* eBasis;

 public:
  //! @param basis the Basis to Evaluate
  //! @param point the Evaluation Points
  //!
  //! Instanciates the requested EvaluatedBasisScalar
  //!
  EvaluatedBasis(const BasisScalar& basis, 
		 const fullMatrix<double>& point);

  //! @param basis the Basis to Evaluate
  //! @param point the Evaluation Points
  //!
  //! Instanciates the requested EvaluatedBasisVector
  //!
  EvaluatedBasis(const BasisVector& basis, 
		 const fullMatrix<double>& point);

  //! Deletes this EvaluatedBasis
  //!
  ~EvaluatedBasis(void);

  //! @return Returns:
  //! @li @c true, if the evaluated
  //! values are @em scalar  
  //! @li @c false, otherwise  
  bool isScalar(void) const;

  //! @return Returns the number of 
  //! evaluated @em Functions
  unsigned int getNFunction(void) const;

  //! @return Returns the number of 
  //! evaluation @em Points
  unsigned int getNPoint(void) const;

  //! @param refSpace A natural number
  //! @return Returns the evaluation of all Basis Functions
  //! (at every evaluation Points)
  //! for the @c refSpace%th @em ReferenceSpace
  const fullMatrix<double>&
    getEvaluation(unsigned int refSpace) const;

  //! @param element A MElement
  //! @return Returns the evaluation of all Basis Functions
  //! (at every evaluation Points)
  //! in the ReferenceSpace of the given element
  const fullMatrix<double>&
    getEvaluation(const MElement& element) const;
};

//////////////////////
// Inline Function //
//////////////////////

inline bool EvaluatedBasis::isScalar(void) const{
  return scalar;
}

inline unsigned int EvaluatedBasis::getNFunction(void) const{
  return nFunction;
}

inline unsigned int EvaluatedBasis::getNPoint(void) const{
  return nPoint;
}

inline const fullMatrix<double>& 
EvaluatedBasis::getEvaluation(unsigned int refSpace) const{
  return *(*eBasis)[refSpace];
}

inline const fullMatrix<double>& 
EvaluatedBasis::getEvaluation(const MElement& element) const{
  return *(*eBasis)[refSpace->getPermutation(element)];
}

#endif
