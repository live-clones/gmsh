#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "fullMatrix.h"
#include "BasisScalar.h"
#include "GradBasis.h"
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
 protected:
  const BasisScalar* basisScalar;

  mutable bool       hasGrad;
  mutable GradBasis* gradBasis;

 public:
  virtual ~FunctionSpaceScalar(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;
  
  const std::vector<const Polynomial*> 
    getLocalFunctions(const MElement& element) const;

  const std::vector<const std::vector<Polynomial>*>
    getGradLocalFunctions(const MElement& element) const;

 protected:
  FunctionSpaceScalar(void);
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

   @fn FunctionSpaceScalar::getLocalFunctions
   @param element A MElement
   @return Returns the basis functions associated
   to the given element (with correct @em closure)
 */

//////////////////////
// Inline Functions //
//////////////////////

inline const std::vector<const Polynomial*> 
FunctionSpaceScalar::getLocalFunctions(const MElement& element) const{
  return locBasis(element, *basisScalar);
}

inline const std::vector<const std::vector<Polynomial>*>
FunctionSpaceScalar::getGradLocalFunctions(const MElement& element) const{

  // Got Grad Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasGrad){
    gradBasis = new GradBasis(*basisScalar);
    hasGrad   = true;
  }

  return locBasis(element, *gradBasis);
}

#endif
