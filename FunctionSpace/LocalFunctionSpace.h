#ifndef _LOCALFUNCTIONSPACE_H_
#define _LOCALFUNCTIONSPACE_H_

/**
   @class LocalFunctionSpace
   @brief Mother class for Local Function Spaces
   
   This class is the @em mother (by @em inheritence) of all@n
   Local Function Spaces.@n

   A Local Function Space is a Basis on which we can interpolate on.
 */

class LocalFunctionSpace{
 protected:
  bool scalar;
  int  size;

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

#endif
