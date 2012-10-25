#ifndef _GRADBASIS_H_
#define _GRADBASIS_H_

#include "BasisVector.h"
#include "BasisScalar.h"

/**
   @class GradBasis
   @brief The Gradient of an other Basis
 
   This class can instantiate a Gradient Basis.
 */

class GradBasis: public BasisVector{
 public:
  //! @param other An Other Basis
  //!
  //! Returns a new Basis, which is the gradient of
  //! the given Basis
  GradBasis(const BasisScalar& other);
  
  //! Deletes this Basis
  //!
  virtual ~GradBasis(void);
};

#endif
