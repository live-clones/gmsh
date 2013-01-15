#ifndef _BASISSCALAR_H_
#define _BASISSCALAR_H_

#include "Basis.h"
#include "MElement.h"
#include "fullMatrix.h"

/**
   @interface BasisScalar
   @brief Common Interface for all 
   @em Scalar Basis

   This class is the @em common @em interface for all 
   @em scalar Basis.@n
*/

class BasisScalar: public Basis{
 public:
  //! Deletes this BasisScalar
  //!
  virtual ~BasisScalar(void);

  virtual fullMatrix<double>* getFunctions(const MElement& element, 
					   double u, double v, double w) const = 0;

  virtual fullMatrix<double>* getFunctions(unsigned int permutation, 
					   double u, double v, double w) const = 0;

  virtual void preEvaluateFunctions    (const fullMatrix<double>& point) const = 0;
  virtual void preEvaluateGradFunctions(const fullMatrix<double>& point) const = 0;

  virtual const fullMatrix<double>& 
    getPreEvaluatedFunctions(const MElement& element) const = 0;
 
  virtual const fullMatrix<double>& 
    getPreEvaluatedGradFunctions(const MElement& element) const = 0;

 protected:
  //! @internal
  //! Instantiates a new BasisScalar
  //!
  //! @endinternal
  BasisScalar(void);
};

#endif
