#ifndef _LOCALFUNCTIONSPACEVECTOR_H_
#define _LOCALFUNCTIONSPACEVECTOR_H_

#include <vector>
#include "Polynomial.h"
#include "Basis.h"
#include "fullMatrix.h"
#include "LocalFunctionSpace.h"

/**
   @class LocalFunctionSpaceVector
   @brief Vectorial Local Function Spaces
   
   A Local Function Space build on a @em Vectorial Basis.
 */

class LocalFunctionSpaceVector: LocalFunctionSpace{
 protected:
  const std::vector<std::vector<Polynomial> >* basis;

 public:
  //! Instantiate a new LocalFunctionSpaceVector
  //! @param basis The Basis used to build 
  //! this Function Space
  LocalFunctionSpaceVector(const Basis& basis);

  //! Deletes this LocalFunctionSpaceVector
  //!
  virtual ~LocalFunctionSpaceVector(void);

  //! Performs an Interpolation
  //! @param coef The coefficients to use for the
  //! Interpolation
  //! @param x,y,z The coordinate of the Interpolation 
  //! @return Returns the value of the Interpolation
  fullVector<double> interpolate(const fullVector<double>& coef, 
				 double x, double y, double z) const;
};

#endif
