#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "fullMatrix.h"
#include "Exception.h"
#include "BasisScalar.h"
#include "GradBasis.h"
#include "EvaluatedBasis.h"
#include "FunctionSpace.h"

/**
    @interface FunctionSpaceScalar
    @brief Common Interface of all Scalar FunctionSpaces
    
    This is the @em common @em interface of
    all @em Scalar FunctionSpaces.@n

    A FunctionSpaceScalar can be @em interpolated,
    and can return a @em Local Basis associated
    to an Element of the Support.

    @note
    A ScalarFunctionSpace is an @em interface, so it
    can't be instantiated.
*/


class FunctionSpaceScalar : public FunctionSpace{
 protected:
  const BasisScalar* basisScalar;

  mutable bool       hasGrad;
  mutable GradBasis* gradBasis;

  bool locPreEvaluated;
  bool gradPreEvaluated;
  
  EvaluatedBasis* evalLoc;
  EvaluatedBasis* evalGrad;

 public:
  virtual ~FunctionSpaceScalar(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;

  virtual double 
    interpolateInRefSpace(const MElement& element, 
			  const std::vector<double>& coef,
			  const fullVector<double>& uvw) const = 0;
  
  const std::vector<const Polynomial*>&
    getLocalFunctions(const MElement& element) const;

  const std::vector<const std::vector<Polynomial>*>&
    getGradLocalFunctions(const MElement& element) const;

  void preEvaluateLocalFunctions(fullMatrix<double>& points);
  void preEvaluateGradLocalFunctions(fullMatrix<double>& points);

  const fullMatrix<double>&
    getEvaluatedLocalFunctions(const MElement& element) const;

  const fullMatrix<double>&
    getEvaluatedGradLocalFunctions(const MElement& element) const;
  
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
   of the interpolation in the @em Physical Space

   @return Returns the (scalar) interpolated value

   @warning
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   
   @todo
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   ---> check
   **

   @fn FunctionSpaceScalar::interpolateInRefSpace
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param uvw The coordinate 
   (of point @em inside the given @c element)
   of the interpolation in the @em Reference Space

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
   **

   @fn FunctionSpaceScalar::getGradLocalFunctions
   @param element A MElement
   @return Returns the @em gradient 
   of the basis functions associated
   to the given element (with correct @em closure)
   **

   @fn FunctionSpaceScalar::preEvaluateLocalFunctions
   @param points A set of @c 3D Points

   Precomputes the Local Functions of this FunctionSpace
   at the given Points.

   @note Each row of @c point is a new Point,
   and each column is a coordinate (for a total of
   3 columns)
   **

   @fn FunctionSpaceScalar::preEvaluateGradLocalFunctions
   @param points A set of @c 3D Points

   Precomputes the @em Gradient of the Local Functions 
   of this FunctionSpace at the given Points.

   @note Each row of @c point is a new Point,
   and each column is a coordinate (for a total of
   3 columns)
   **

   @fn FunctionSpaceScalar::getEvaluatedLocalFunctions
   @param element A MElement
   @return Returns the @em values of the @em precomputed 
   Basis Functions associated
   to the given element (with correct @em closure)
   
   @note
   The returned values @em must be computed by
   FunctionSpaceScalar::preEvaluateLocalFunctions(), 
   if not an Exception will be thrown
   **

   @fn FunctionSpaceScalar::getEvaluatedGradLocalFunctions
   @param element A MElement
   @return Returns the @em values of the @em precomputed 
   @em Gradients of the Basis Functions associated
   to the given element (with correct @em closure)
   
   @note
   The returned values @em must be computed by
   FunctionSpaceScalar::preEvaluateGradLocalFunctions(), 
   if not an Exception will be thrown
 */

//////////////////////
// Inline Functions //
//////////////////////

inline const std::vector<const Polynomial*>&
FunctionSpaceScalar::getLocalFunctions(const MElement& element) const{
  return locBasis(element, *basisScalar);
}

inline const std::vector<const std::vector<Polynomial>*>&
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

inline const fullMatrix<double>&
FunctionSpaceScalar::getEvaluatedLocalFunctions(const MElement& element) const{
  if(!locPreEvaluated)
    throw Exception("Local Basis Functions not PreEvaluated");

  return locEvalBasis(element, *evalLoc);
}

inline const fullMatrix<double>&
FunctionSpaceScalar::getEvaluatedGradLocalFunctions(const MElement& element) const{
  if(!gradPreEvaluated)
    throw Exception("Gradients of Local Basis Functions not PreEvaluated");

  return locEvalBasis(element, *evalGrad);
}

#endif
