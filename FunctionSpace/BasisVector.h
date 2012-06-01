#ifndef _BASISVECTOR_H_
#define _BASISVECTOR_H_

#include "Basis.h"
#include "Polynomial.h"
#include "Vector.h"

/**
   @class BasisVector
   @brief Mother class of all 
   @em vectorial Basis

   This class is the @em mother (by @em inheritence) 
   of all @em vectorial Basis.@n
*/

class BasisVector: public Basis{
 protected:
  Vector<Polynomial>* basis;

 public:
  virtual ~BasisVector(void);

  Vector<Polynomial>* getBasis(void) const;

 protected:
  BasisVector(void);
};

/**
   @fn BasisVector::~BasisVector
   @return Deletes this Basis

   @fn BasisVector::getBasis
   @return Returns the set of 
   @em Vector%s @em of @em Polynomial%s
   that defines this Basis
*/

//////////////////////
// Inline Functions //
//////////////////////

inline Vector<Polynomial>* BasisVector::getBasis(void) const{
  return basis;
}

#endif
