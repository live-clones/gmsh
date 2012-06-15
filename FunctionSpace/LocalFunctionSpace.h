#ifndef _LOCALFUNCTIONSPACE_H_
#define _LOCALFUNCTIONSPACE_H_

/**
   @class LocalFunctionSpace
   @brief Mother class for Local Function Spaces
   
   This class is the @em mother (by @em inheritence) of all@n
   Local Function Spaces.@n

   A Local Function Space is a Basis on which we can interpolate on.@n
   In order to interpolate, a Local Function Space shall colaborate
   with a Jacobian.
 */

#include "Jacobian.h"

class LocalFunctionSpace{
 protected:
  typedef fullVector<double>(Jacobian::*JacMethod)
    (const fullVector<double>&) const;

  bool      scalar;
  int       size;
  int       type;

  Jacobian* jac;
  fullVector<double> (*transform)(const Jacobian&, 
				  double, 
				  double, 
				  double);

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

  //! Selects the right transorm method for the Jacobian
  //! @param form The @em type of the Basis used
  void selectTransform(int form);

  //! Mapping of 0-form
  //! @param jac The Jacobian to use
  //! @param u,v,w The @em reference coordinate to map
  //! @return Returns The mapped coordinate in the @em physical space
  static fullVector<double> form0(const Jacobian& jac, 
				  double u, 
				  double v, 
				  double w);

  //! Mapping of 1-form
  //! @param jac The Jacobian to use
  //! @param u,v,w The @em reference coordinate to map
  //! @return Returns The mapped coordinate in the @em physical space
  static fullVector<double> form1(const Jacobian& jac, 
				  double u, 
				  double v, 
				  double w);

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

inline fullVector<double> LocalFunctionSpace::form0(const Jacobian& jac,
						    double u,
						    double v,
						    double w){
  return jac.map(u, v);
}

inline fullVector<double> LocalFunctionSpace::form1(const Jacobian& jac,
						    double u,
						    double v,
						    double w){
  return jac.grad(u, v);
  //! @todo Missing Orientation !!
}

#endif
