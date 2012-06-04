#ifndef _BASISSCALAR_H_
#define _BASISSCALAR_H_

#include <vector>
#include "Basis.h"
#include "Polynomial.h"

/**
   @class BasisScalar
   @brief Mother class of all 
   @em scalar Basis

   This class is the @em mother (by @em inheritence) 
   of all @em scalar Basis.@n
*/

class BasisScalar: public Basis{
 protected:
  std::vector<Polynomial>* basis;

 public:
  //! Deletes this BasisScalar
  //!
  virtual ~BasisScalar(void);
  
  //! @return Returns the set of @em Polynomial%s
  //! defining this (scalar) Basis
  const std::vector<Polynomial>& getBasis(void) const;

 protected:
  //! Instantiate a new BasisScalar
  //! @warning Users can't instantiate a BasisScalar
  BasisScalar(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline const std::vector<Polynomial>& BasisScalar::getBasis(void) const{
  return *basis;
}

#endif
