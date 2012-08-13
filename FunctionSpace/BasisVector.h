#ifndef _BASISVECTOR_H_
#define _BASISVECTOR_H_

#include <vector>
#include "Basis.h"
#include "Polynomial.h"

/**
   @class BasisVector
   @brief Mother class of all 
   @em vectorial Basis

   This class is the @em mother (by @em inheritence) 
   of all @em vectorial Basis.@n
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
  //! Instantiate a new BasisVector
  //! @warning Users can't instantiate a BasisVector
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
