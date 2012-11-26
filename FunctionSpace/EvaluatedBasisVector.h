#ifndef _EVALUATEDBASISVECTOR_H_
#define _EVALUATEDBASISVECTOR_H_

#include <vector>
#include "fullMatrix.h"
#include "BasisVector.h"
#include "EvaluatedBasis.h"

/**
   @class EvaluatedBasisVector
   @brief A @em Vectorial EvaluatedBasis 

   This class is a @em Vectorial EvaluatedBasis.@n
*/

class EvaluatedBasisVector: public EvaluatedBasis{
 protected:
  std::vector            <std::vector<fullVector<double> >*>*   node;
  std::vector<std::vector<std::vector<fullVector<double> >*>*>* edge;
  std::vector<std::vector<std::vector<fullVector<double> >*>*>* face;
  std::vector            <std::vector<fullVector<double> >*>*   cell;

 public:
  //! @param basis the Basis to Evaluate
  //! @param point the Evaluation Points
  //!
  //! Instanciates the requested EvaluatedBasisVector
  //!
  EvaluatedBasisVector(const BasisVector& basis, 
		       const fullMatrix<double>& point);

  //! Deletes this EvaluatedBasisVector
  //!
  virtual ~EvaluatedBasisVector(void);

  //! @param i A natural number
  //! @return Returns the evaluation of the @c i%th @em Vertex Based 
  //! Basis Function (at every evaluation Points)
  const std::vector<fullVector<double> >&
    getNodeEvaluation(unsigned int i) const;
  
  //! @param i A natural number
  //! @param closure A natural number
  //! @return Returns the evaluation of the @c i%th @em Edge Based 
  //! Basis Function (at every evaluation Points), with the @c closure%th Closure
  const std::vector<fullVector<double> >&
    getEdgeEvaluation(unsigned int closure, unsigned int i) const;
  
  //! @param i A natural number
  //! @param closure A natural number
  //! @return Returns the evaluation of the @c i%th @em Face Based 
  //! Basis Function (at every evaluation Points), with the @c closure%th Closure
  const std::vector<fullVector<double> >&
    getFaceEvaluation(unsigned int closure, unsigned int i) const;
 
  //! @param i A natural number
  //! @return Returns the evaluation of the @c i%th @em Cell Based 
  //! Basis Function (at every evaluation Points)
  const std::vector<fullVector<double> >&
    getCellEvaluation(unsigned int i) const;
};

//////////////////////
// Inline Function //
//////////////////////

inline
const std::vector<fullVector<double> >& 
EvaluatedBasisVector::getNodeEvaluation(unsigned int i) const{
  return *(*node)[i];
}

inline  
const std::vector<fullVector<double> >& 
EvaluatedBasisVector::getEdgeEvaluation(unsigned int closure, unsigned int i) const{
  return *(*(*edge)[closure])[i];
}

inline
const std::vector<fullVector<double> >& 
EvaluatedBasisVector::getFaceEvaluation(unsigned int closure, unsigned int i) const{
  return *(*(*face)[closure])[i];
}

inline
const std::vector<fullVector<double> >&
EvaluatedBasisVector::getCellEvaluation(unsigned int i) const{
  return *(*cell)[i];
}

#endif
