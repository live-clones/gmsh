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
  std::vector<std::vector<const Polynomial*>*>* basis;

 public:
  //! Deletes this BasisScalar
  //!
  virtual ~BasisScalar(void);

  //! @param refSpace A natural number
  //! @param i A natural number
  //! @return Returns the @c i%th @em 
  //! Basis Function of the @c refSpace%th ReferenceSpace
  const Polynomial&
    getFunction(unsigned int refSpace, unsigned int i) const;

  //! @param refSpace A natural number
  //! @return Returns the @em all
  //! Basis Function of the @c refSpace%th ReferenceSpace
  const std::vector<const Polynomial*>&
    getFunction(unsigned int refSpace) const;

  //! @param element An Element
  //! @return Returns the @em all
  //! Basis Function in the @c given element
  //! @em ReferenceSpace
  const std::vector<const Polynomial*>&
    getFunction(const MElement& element) const;  

  virtual std::string toString(void) const;

 protected:
  //! @internal
  //! Instantiates a new BasisScalar
  //!
  //! @endinternal
  BasisScalar(void);
};

//////////////////////
// Inline Function //
//////////////////////

inline  
const Polynomial& 
BasisScalar::getFunction(unsigned int refSpace, unsigned int i) const{
  return *(*(*basis)[refSpace])[i];
}

inline  
const std::vector<const Polynomial*>&
BasisScalar::getFunction(unsigned int refSpace) const{
  return *(*basis)[refSpace];
}

inline  
const std::vector<const Polynomial*>&
BasisScalar::getFunction(const MElement& element) const{
  return *(*basis)[refSpace->getReferenceSpace(element)];
}

#endif
