#ifndef _LOCALFUNCTIONSPACESCALAR_H_
#define _LOCALFUNCTIONSPACESCALAR_H_

#include <vector>
#include "Polynomial.h"
#include "Basis.h"
#include "LocalFunctionSpace.h"

/**
   @class LocalFunctionSpaceScalar
   @brief Scalar Local Function Spaces
   
   A Local Function Space build on a @em Scalar Basis.
 */

class LocalFunctionSpaceScalar: LocalFunctionSpace{
 protected:
  const std::vector<Polynomial>* basis;

 public:
  //! Instantiate a new LocalFunctionSpaceScalar
  //! @param basis The Basis used to build 
  //! this Function Space
  LocalFunctionSpaceScalar(const Basis& basis);
  
  //! Deletes this LocalFunctionSpaceScalar
  //!
  virtual ~LocalFunctionSpaceScalar(void);

  //! Performs an Interpolation
  //! @param coef The coefficients to use for the
  //! Interpolation
  //! @param x,y,z The coordinate of the Interpolation 
  //! @return Returns the value of the Interpolation
  double interpolate(const fullVector<double>& coef, 
		     double x, double y, double z) const;
};

#endif
