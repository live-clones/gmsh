#ifndef _FUNCTIONSPACEVECTOR_H_
#define _FUNCTIONSPACEVECTOR_H_

#include "fullMatrix.h"
#include "BasisVector.h"
#include "CurlBasis.h"
#include "DivBasis.h"
#include "FunctionSpace.h"

/**
    @interface FunctionSpaceVector
    @brief Common Interface of all Vectorial FunctionSpaces
    
    This is the @em common @em interface of
    all @em Vectorial FunctionSpaces.@n

    A FunctionSpaceVector can be @em interpolated.

    @note
    A VectorFunctionSpace is an @em interface, so it
    can't be instantiated.
*/


class FunctionSpaceVector : public FunctionSpace{
 protected:
  const BasisVector* basisVector;

  mutable bool       hasCurl;
  mutable CurlBasis* curlBasis;

  mutable bool       hasDiv;
  mutable DivBasis*  divBasis;

 public:
  virtual ~FunctionSpaceVector(void);

  virtual fullVector<double> 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;

  const std::vector<const std::vector<Polynomial>*>
    getLocalFunctions(const MElement& element) const;

  const std::vector<const std::vector<Polynomial>*>
    getCurlLocalFunctions(const MElement& element) const;

  const std::vector<const Polynomial*> 
    getDivLocalFunctions(const MElement& element) const;

 protected:
  FunctionSpaceVector(void);
};


/**
   @fn FunctionSpaceVector::~FunctionSpaceVector
   Deletes this FunctionSpaceVector
   **

   @fn FunctionSpaceVector::interpolate
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param xyz The coordinate 
   (of point @em inside the given @c element)
   of the interpolation

   @return Returns the (vectorial) interpolated value

   @warning
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   
   @todo
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   ---> check
   **

   @fn FunctionSpaceVector::getLocalFunctions
   @param element A MElement
   @return Returns the basis functions associated
   to the given element (with correct @em closure)
*/

//////////////////////
// Inline Functions //
//////////////////////

inline const std::vector<const std::vector<Polynomial>*> 
FunctionSpaceVector::getLocalFunctions(const MElement& element) const{
  return locBasis(element, *basisVector);
}

inline const std::vector<const std::vector<Polynomial>*>
FunctionSpaceVector::getCurlLocalFunctions(const MElement& element) const{

  // Got Curl Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasCurl){
    curlBasis = new CurlBasis(*basisVector);
    hasCurl   = true;
  }

  return locBasis(element, *curlBasis);
}

inline const std::vector<const Polynomial*> 
FunctionSpaceVector::getDivLocalFunctions(const MElement& element) const{

  // Got Div Basis ? //
  // --> mutable data 
  //  --> Just a 'cache memory' 
  if(!hasDiv){
    divBasis = new DivBasis(*basisVector);
    hasDiv   = true;
  }

  return locBasis(element, *divBasis);
}

#endif
