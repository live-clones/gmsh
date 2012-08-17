#ifndef _BASISVECTOR_H_
#define _BASISVECTOR_H_

#include <vector>
#include "Basis.h"
#include "Polynomial.h"

/**
   @interface BasisVector
   @brief Common Interface for all 
   @em Vectorial Basis

   This class is the @em common @em interface for all 
   @em vectorial Basis.@n

   @note
   A BasisVector is an @em interface, 
   so it @em can't be instanciated
*/

class BasisVector: public Basis{
 protected:
  std::vector<std::vector<Polynomial> >* basis;

 public:
  //! Deletes this BasisVector
  //!
  virtual ~BasisVector(void);

  //! @return Returns the set of @em Polynomial%s
  //! defining this (vectorial) Basis
  const std::vector<std::vector<Polynomial> >& getFunctions(void) const;

 protected:
  //! @internal
  //! Instantiate a new BasisVector
  //!
  //! @endinternal
  BasisVector(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline 
const std::vector<std::vector<Polynomial> >& BasisVector::
getFunctions(void) const{

  return *basis;
}

#endif
