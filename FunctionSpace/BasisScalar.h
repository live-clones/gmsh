#ifndef _BASISSCALAR_H_
#define _BASISSCALAR_H_

#include <vector>
#include "Basis.h"
#include "Polynomial.h"

/**
   @interface BasisScalar
   @brief Common Interface for all 
   @em Scalar Basis

   This class is the @em common @em interface for all 
   @em scalar Basis.@n

   @note
   A BasisScalar is an @em interface, 
   so it @em can't be instanciated
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
  const std::vector<Polynomial>& getFunctions(void) const;

 protected:
  //! @internal
  //! Instantiates a new BasisScalar
  //!
  //! @endinternal
  BasisScalar(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline 
const std::vector<Polynomial>& BasisScalar::
getFunctions(void) const{

  return *basis;
}

#endif
