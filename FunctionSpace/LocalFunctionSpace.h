#ifndef _LOCALFUNCTIONSPACE_H_
#define _LOCALFUNCTIONSPACE_H_

/**
   @class LocalFunctionSpace
   @brief Mother class for Local Function Spaces
   
   This class is the @em mother (by @em inheritence) of all
   Local Function Spaces.@n

   A Local Function Space is a Basis on which we can interpolate on.@n
   In order to interpolate, a Local Function Space shall colaborate
   with an Element.
 */

#include "Jacobian.h"

class LocalFunctionSpace{
 protected:
  bool      scalar;
  int       size;
  int       type;

  Jacobian* jac;

 public:
  //! Deletes this LocalFunctionSpace
  //!
  virtual ~LocalFunctionSpace(void);

  //! @return Returns:
  //! @li @c true, if a  
  //! @em scalar Basis is used 
  //! @li @c false, if a
  //! @em vectorial Basis is used
  //! @see LocalFunctionSpaceScalar
  //! @see LocalFunctionSpaceVector
  bool isScalar(void) const;

  //! @return Returns the size of the Basis used
  int  getSize(void) const;

  //! @return Returns the type of the Basis used
  //! @li 0 for 0-form
  //! @li 1 for 1-form
  //! @li 2 for 2-form
  //! @li 3 for 3-form
  //! @todo Check if the 'form numbering' is good
  int  getType(void) const;

 protected:
  //! Instantiate a new LocalFunctionSpace
  //! @warning Users can't instantiate a LocalFunctionSpace
  LocalFunctionSpace(void);
};

//////////////////////
// Inline Functions //
//////////////////////

inline bool LocalFunctionSpace::isScalar(void) const{
  return scalar;
}

inline int LocalFunctionSpace::getSize(void) const{
  return size;
}

inline int LocalFunctionSpace::getType(void) const{
  return type;
}

#endif
