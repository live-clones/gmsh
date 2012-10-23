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
  std::vector            <Polynomial*>*   node;
  std::vector<std::vector<Polynomial*>*>* edge;
  std::vector<std::vector<Polynomial*>*>* face;
  std::vector            <Polynomial*>*   cell;

  std::vector<const Polynomial*>* basis;
  std::vector<const Polynomial*>* revBasis;

 public:
  //! Deletes this BasisScalar
  //!
  virtual ~BasisScalar(void);
  
  const Polynomial&
    getNodeFunction(unsigned int i) const;
  
  const Polynomial&
    getEdgeFunction(unsigned int closure, unsigned int i) const;
  
  const Polynomial&
    getFaceFunction(unsigned int closure, unsigned int i) const;
 
  const Polynomial&
    getCellFunction(unsigned int i) const;

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
BasisScalar::getNodeFunction(unsigned int i) const{
  return *(*node)[i];
}

inline  
const Polynomial& 
BasisScalar::getEdgeFunction(unsigned int closure, unsigned int i) const{
  return *(*(*edge)[closure])[i];
}

inline
const Polynomial& 
BasisScalar::getFaceFunction(unsigned int closure, unsigned int i) const{
  return *(*(*face)[closure])[i];
}

inline
const Polynomial&
BasisScalar::getCellFunction(unsigned int i) const{
  return *(*cell)[i];
}

#endif
