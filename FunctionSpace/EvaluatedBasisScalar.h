#ifndef _EVALUATEDBASISSCALAR_H_
#define _EVALUATEDBASISSCALAR_H_

#include <vector>
#include "fullMatrix.h"
#include "BasisScalar.h"
#include "EvaluatedBasis.h"

/**
   @class EvaluatedBasisScalar
   @brief A @em Scalar EvaluatedBasis 

   This class is a @em Scalar EvaluatedBasis.@n
*/

class EvaluatedBasisScalar: public EvaluatedBasis{
 protected:
  std::vector            <std::vector<double>*>*   node;
  std::vector<std::vector<std::vector<double>*>*>* edge;
  std::vector<std::vector<std::vector<double>*>*>* face;
  std::vector            <std::vector<double>*>*   cell;

 public:
  //! @param basis the Basis to Evaluate
  //! @param point the Evaluation Points
  //!
  //! Instanciates the requested EvaluatedBasisScalar
  //!
  EvaluatedBasisScalar(const BasisScalar& basis, 
		       const fullMatrix<double>& point);

  //! Deletes this EvaluatedBasisScalar
  //!
  virtual ~EvaluatedBasisScalar(void);

  //! @param i A natural number
  //! @return Returns the evaluation of the @c i%th @em Vertex Based 
  //! Basis Function (at every evaluation Points)
  const std::vector<double>&
    getNodeEvaluation(unsigned int i) const;
  
  //! @param i A natural number
  //! @param closure A natural number
  //! @return Returns the evaluation of the @c i%th @em Edge Based 
  //! Basis Function (at every evaluation Points), with the @c closure%th Closure
  const std::vector<double>&
    getEdgeEvaluation(unsigned int closure, unsigned int i) const;
  
  //! @param i A natural number
  //! @param closure A natural number
  //! @return Returns the evaluation of the @c i%th @em Face Based 
  //! Basis Function (at every evaluation Points), with the @c closure%th Closure
  const std::vector<double>&
    getFaceEvaluation(unsigned int closure, unsigned int i) const;
 
  //! @param i A natural number
  //! @return Returns the evaluation of the @c i%th @em Cell Based 
  //! Basis Function (at every evaluation Points)
  const std::vector<double>&
    getCellEvaluation(unsigned int i) const;
};

//////////////////////
// Inline Function //
//////////////////////

inline
const std::vector<double>& 
EvaluatedBasisScalar::getNodeEvaluation(unsigned int i) const{
  return *(*node)[i];
}

inline  
const std::vector<double>& 
EvaluatedBasisScalar::getEdgeEvaluation(unsigned int closure, unsigned int i) const{
  return *(*(*edge)[closure])[i];
}

inline
const std::vector<double>& 
EvaluatedBasisScalar::getFaceEvaluation(unsigned int closure, unsigned int i) const{
  return *(*(*face)[closure])[i];
}

inline
const std::vector<double>&
EvaluatedBasisScalar::getCellEvaluation(unsigned int i) const{
  return *(*cell)[i];
}

#endif
