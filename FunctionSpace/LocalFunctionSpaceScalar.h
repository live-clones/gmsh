#ifndef _LOCALFUNCTIONSPACESCALAR_H_
#define _LOCALFUNCTIONSPACESCALAR_H_

#include <vector>
#include "Polynomial.h"
#include "LocalFunctionSpace.h"

/**
   @class LocalFunctionSpaceScalar
   @brief Scalar Local Function Spaces
   
   A Local Function Space build on a @em Scalar Basis.
 */

class LocalFunctionSpaceScalar: public LocalFunctionSpace{
 public:  
  //! Deletes this LocalFunctionSpaceScalar
  //!
  virtual ~LocalFunctionSpaceScalar(void);

  //! Performs an Interpolation
  //! @param coef The coefficients to use for the
  //! Interpolation
  //! @param x,y,z The coordinate of the Interpolation 
  //! @return Returns the value of the Interpolation
  virtual double interpolate(const fullVector<double>& coef, 
			     double x, double y, double z) const = 0;

 protected:
  //! Instantiate a new LocalFunctionSpaceScalar
  //! @warning Users can't instantiate a LocalFunctionSpaceScalar
  LocalFunctionSpaceScalar(void);
};

#endif
