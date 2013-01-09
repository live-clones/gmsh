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
  std::vector<std::vector<const std::vector<Polynomial>*>*>* basis;

 public:
  //! Deletes this BasisVector
  //!
  virtual ~BasisVector(void);

  //! @param refSpace A natural number
  //! @param i A natural number
  //! @return Returns the @c i%th @em 
  //! Basis Function of the @c refSpace%th ReferenceSpace
  const std::vector<Polynomial>&
    getFunction(unsigned int refSpace, unsigned int i) const;

  //! @param refSpace A natural number
  //! @return Returns the @em all
  //! Basis Function of the @c refSpace%th ReferenceSpace
  const std::vector<const std::vector<Polynomial>*>&
    getFunction(unsigned int refSpace) const;

  //! @param element An Element
  //! @return Returns the @em all
  //! Basis Function in the @c given element
  //! @em ReferenceSpace
  const std::vector<const std::vector<Polynomial>*>&
    getFunction(const MElement& element) const;  

  virtual std::string toString(void) const;

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
const std::vector<Polynomial>& 
BasisVector::getFunction(unsigned int refSpace, unsigned int i) const{
  return *(*(*basis)[refSpace])[i];
}

inline  
const std::vector<const std::vector<Polynomial>*>&
BasisVector::getFunction(unsigned int refSpace) const{
  return *(*basis)[refSpace];
}

inline  
const std::vector<const std::vector<Polynomial>*>&
BasisVector::getFunction(const MElement& element) const{
  return *(*basis)[refSpace->getPermutation(element)];
}

#endif
