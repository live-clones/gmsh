#ifndef _LOCALFUNCTIONSPACEVECTOR_H_
#define _LOCALFUNCTIONSPACEVECTOR_H_

#include "fullMatrix.h"
#include "LocalFunctionSpace.h"

/**
   @class LocalFunctionSpaceVector
   @brief Vectorial Local Function Spaces
   
   A Local Function Space build on a @em Vectorial Basis.
 */

class LocalFunctionSpaceVector: public LocalFunctionSpace{
 public:
  //! Deletes this LocalFunctionSpaceVector
  //!
  virtual ~LocalFunctionSpaceVector(void);

  //! Performs an Interpolation
  //! @param coef The coefficients to use for the
  //! Interpolation
  //! @param x,y,z The coordinate of the Interpolation 
  //! @return Returns the value of the Interpolation
  virtual fullVector<double> interpolate(const fullVector<double>& coef, 
					 double x, double y, double z) const = 0;

 protected:
  //! Instantiate a new LocalFunctionSpacaeVector 
  //! @warning Users can't instantiate a LocalFunctionSpaceVector
  LocalFunctionSpaceVector(void);
};

#endif
