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
  std::vector<const Polynomial*>* basis;
  std::vector<const Polynomial*>* revBasis;

 public:
  //! Deletes this BasisScalar
  //!
  virtual ~BasisScalar(void);
  
  //! @return Returns the set of @em Polynomial%s
  //! defining this (scalar) Basis
  const std::vector<const Polynomial*>& getFunctions(void) const;

  //! @param closure A natural number
  //! @return Returns the set of @em Polynomial%s
  //! defining this (scalar) Basis, for the given closure
  const std::vector<const Polynomial*>& getFunctions(unsigned int closure) const;

  virtual std::string toString(void) const;

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
const std::vector<const Polynomial*>& BasisScalar::
getFunctions(unsigned int closure) const{
  if(!closure)
    return *basis;

  else
    return *revBasis;
}


#endif
