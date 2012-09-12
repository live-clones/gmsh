#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "fullMatrix.h"
#include "BasisScalar.h"
#include "FunctionSpace.h"

/**
    @interface FunctionSpaceScalar
    @brief Common Interface of all Scalar FunctionSpaces
    
    This is the @em common @em interface of
    all @em Scalar FunctionSpaces.@n

    A FunctionSpaceScalar can be @em interpolated.

    @note
    A ScalarFunctionSpace is an @em interface, so it
    can't be instantiated.
*/


class FunctionSpaceScalar : public FunctionSpace{
 public:
  virtual ~FunctionSpaceScalar(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;
  
  const std::vector<const Polynomial*> 
    getLocalFunctions(const MElement& element) const;
  
  const BasisScalar& getBasis(const MElement& element) const;
};


/**
   @fn FunctionSpaceScalar::~FunctionSpaceScalar
   Deletes this FunctionSpaceScalar
   **

   @fn FunctionSpaceScalar::interpolate
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param xyz The coordinate 
   (of point @em inside the given @c element)
   of the interpolation

   @return Returns the (scalar) interpolated value

   @warning
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   
   @todo
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   ---> check
   **

   @fn FunctionSpaceScalar::getBasis
   @param element A MElement of the support 
   of this FunctionSpace
   @return Returns the Basis (BasisScalar) associated
   to the given MElement
 */


//////////////////////
// Inline Functions //
//////////////////////

inline const BasisScalar& FunctionSpaceScalar::
getBasis(const MElement& element) const{
  return static_cast<const BasisScalar&>(*basis);
}

#endif
