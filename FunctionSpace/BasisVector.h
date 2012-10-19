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
  std::vector            <const std::vector<Polynomial>*>*   node;
  std::vector<std::vector<const std::vector<Polynomial>*>*>* edge;
  std::vector<std::vector<const std::vector<Polynomial>*>*>* face;
  std::vector            <const std::vector<Polynomial>*>*   cell;

  std::vector<const std::vector<Polynomial>*>* basis;
  std::vector<const std::vector<Polynomial>*>* revBasis;

 public:
  //! Deletes this BasisVector
  //!
  virtual ~BasisVector(void);

  //! @param closure A natural number
  //! @return Returns the set of @em Polynomial%s
  //! defining this (scalar) Basis, for the given closure
  const std::vector<const std::vector<Polynomial>*>& 
    getFunctions(unsigned int closure) const;

  const std::vector<const std::vector<Polynomial>*>&
    getNodeFunctions(void) const;
  
  const std::vector<std::vector<const std::vector<Polynomial>*>*>&
    getEdgeFunctions(void) const;
  
  const std::vector<std::vector<const std::vector<Polynomial>*>*>&
    getFaceFunctions(void) const;
 
  const std::vector<const std::vector<Polynomial>*>&
    getCellFunctions(void) const;

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
const std::vector<const std::vector<Polynomial>*>& BasisVector::
getFunctions(unsigned int closure) const{
  if(!closure)
    return *basis;

  else
    return *revBasis;
}

inline
const std::vector<const std::vector<Polynomial>*>& 
BasisVector::getNodeFunctions(void) const{
  return *node;
}

inline  
const std::vector<std::vector<const std::vector<Polynomial>*>*>& 
BasisVector::getEdgeFunctions(void) const{
  return *edge;
}

inline
const std::vector<std::vector<const std::vector<Polynomial>*>*>& 
BasisVector::getFaceFunctions(void) const{
  return *face;
}

inline
const std::vector<const std::vector<Polynomial>*>& 
BasisVector::getCellFunctions(void) const{
  return *cell;
}

#endif
