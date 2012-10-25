#ifndef _DIVBASIS_H_
#define _DIVBASIS_H_

#include "BasisScalar.h"
#include "BasisVector.h"

/**
   @class DivBasis
   @brief The Divergence of an other Basis
 
   This class can instantiate a Divergence Basis.
 */

class DivBasis: public BasisScalar{
 public:
  //! @param other An Other Basis
  //!
  //! Returns a new Basis, which is the divergence of
  //! the given Basis
  DivBasis(const BasisVector& other);
  
  //! Deletes this Basis
  //!
  virtual ~DivBasis(void);
};

#endif
