#ifndef _BASISVECTOR_H_
#define _BASISVECTOR_H_

#include "Basis.h"
#include "MElement.h"
#include "fullMatrix.h"

/**
   @interface BasisVector
   @brief Common Interface for all 
   @em Vectorial Basis

   This class is the @em common @em interface for all 
   @em vectorial Basis.@n
*/

class BasisVector: public Basis{
 public:
  //! Deletes this BasisVector
  //!
  virtual ~BasisVector(void);

  virtual fullMatrix<double>* getFunctions(const MElement& element, 
					   double u, double v, double w) const = 0;

  virtual fullMatrix<double>* getFunctions(unsigned int permutation, 
					   double u, double v, double w) const = 0;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateCurlFunctions(const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateDivFunctions (const fullMatrix<double>& point) const = 0;
  
  virtual const fullMatrix<double>& 
    getPreEvaluatedFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>& 
    getPreEvaluatedCurlFunctions(const MElement& element) const = 0;

  virtual const fullMatrix<double>& 
    getPreEvaluatedDivFunctions(const MElement& element) const = 0;

 protected:
  //! @internal
  //! Instantiates a new BasisVector
  //!
  //! @endinternal
  BasisVector(void);
};

#endif
