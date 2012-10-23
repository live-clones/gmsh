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
  std::vector            <std::vector<Polynomial>*>*   node;
  std::vector<std::vector<std::vector<Polynomial>*>*>* edge;
  std::vector<std::vector<std::vector<Polynomial>*>*>* face;
  std::vector            <std::vector<Polynomial>*>*   cell;

  std::vector<const std::vector<Polynomial>*>* basis;
  std::vector<const std::vector<Polynomial>*>* revBasis;

 public:
  //! Deletes this BasisVector
  //!
  virtual ~BasisVector(void);

  const std::vector<Polynomial>&
    getNodeFunction(unsigned int i) const;
  
  const std::vector<Polynomial>&
    getEdgeFunction(unsigned int closure, unsigned int i) const;
  
  const std::vector<Polynomial>&
    getFaceFunction(unsigned int closure, unsigned int i) const;
 
  const std::vector<Polynomial>&
    getCellFunction(unsigned int i) const;

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
BasisVector::getNodeFunction(unsigned int i) const{
  return *(*node)[i];
}

inline  
const std::vector<Polynomial>& 
BasisVector::getEdgeFunction(unsigned int closure, unsigned int i) const{
  return *(*(*edge)[closure])[i];
}

inline
const std::vector<Polynomial>& 
BasisVector::getFaceFunction(unsigned int closure, unsigned int i) const{
  return *(*(*face)[closure])[i];
}

inline
const std::vector<Polynomial>& 
BasisVector::getCellFunction(unsigned int i) const{
  return *(*cell)[i];
}

#endif
