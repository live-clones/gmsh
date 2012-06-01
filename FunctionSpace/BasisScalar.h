#ifndef _BASISSCALAR_H_
#define _BASISSCALAR_H_

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
  Polynomial* basis;

 public:
  virtual ~BasisScalar(void);

  Polynomial* getBasis(void) const;

 protected:
  BasisScalar(void);
};

/**
   @fn BasisScalar::~BasisScalar
   @return Deletes this Basis

   @fn BasisScalar::getBasis
   @return Returns the set of 
   @em Polynomial%s
   that defines this Basis
*/

//////////////////////
// Inline Functions //
//////////////////////

inline Polynomial* BasisScalar::getBasis(void) const{
  return basis;
}

#endif
