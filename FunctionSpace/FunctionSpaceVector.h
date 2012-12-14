#ifndef _FUNCTIONSPACEVECTOR_H_
#define _FUNCTIONSPACEVECTOR_H_

#include "fullMatrix.h"
#include "Exception.h"
#include "BasisVector.h"
#include "CurlBasis.h"
#include "DivBasis.h"
#include "EvaluatedBasis.h"
#include "FunctionSpace.h"

/**
    @interface FunctionSpaceVector
    @brief Common Interface of all Vectorial FunctionSpaces
    
    This is the @em common @em interface of
    all @em Vectorial FunctionSpaces.@n

    A FunctionSpaceVector can be @em interpolated,
    and can return a @em Local Basis associated
    to an Element of the Support.

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

  bool locPreEvaluated;
  bool curlPreEvaluated;
  bool divPreEvaluated;
  
  EvaluatedBasis* evalLoc;
  EvaluatedBasis* evalCurl;
  EvaluatedBasis* evalDiv;

 public:
  virtual ~FunctionSpaceVector(void);

  virtual fullVector<double> 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;

  virtual fullVector<double> 
    interpolateInRefSpace(const MElement& element, 
			  const std::vector<double>& coef,
			  const fullVector<double>& uvw) const = 0;

  const std::vector<const std::vector<Polynomial>*>&
    getLocalFunctions(const MElement& element) const;

  const std::vector<const std::vector<Polynomial>*>&
    getCurlLocalFunctions(const MElement& element) const;

  const std::vector<const Polynomial*>&
    getDivLocalFunctions(const MElement& element) const;

  void preEvaluateLocalFunctions(fullMatrix<double>& points);
  void preEvaluateCurlLocalFunctions(fullMatrix<double>& points);
  void preEvaluateDivLocalFunctions(fullMatrix<double>& points);

  const fullMatrix<double>&
    getEvaluatedLocalFunctions(const MElement& element) const;

  const fullMatrix<double>&
    getEvaluatedCurlLocalFunctions(const MElement& element) const;

  const fullMatrix<double>&
    getEvaluatedDivLocalFunctions(const MElement& element) const;

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
   of the interpolation in the @em Physical Space

   @return Returns the (vectorial) interpolated value

   @warning
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   
   @todo
   If the given coordinate are not in the given
   @c element @em Bad @em Things may happend
   ---> check
   **

   @fn FunctionSpaceVector::interpolateInRefSpace
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param uvw The coordinate 
   (of point @em inside the given @c element)
   of the interpolation in the @em Reference Space

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
   **

   @fn FunctionSpaceVector::getCurlLocalFunctions
   @param element A MElement
   @return Returns the @em curl 
   of the basis functions associated
   to the given element (with correct @em closure)
   **

   @fn FunctionSpaceVector::getDivLocalFunctions
   @param element A MElement
   @return Returns the @em divergence
   of the basis functions associated
   to the given element (with correct @em closure)
   **

   @fn FunctionSpaceVector::preEvaluateLocalFunctions
   @param points A set of @c 3D Points

   Precomputes the Local Functions of this FunctionSpace
   at the given Points.

   @note Each row of @c point is a new Point,
   and each column is a coordinate (for a total of
   3 columns)
   **

   @fn FunctionSpaceVector::preEvaluateCurlLocalFunctions
   @param points A set of @c 3D Points

   Precomputes the @em Curl of the Local Functions 
   of this FunctionSpace at the given Points.

   @note Each row of @c point is a new Point,
   and each column is a coordinate (for a total of
   3 columns)
   **

   @fn FunctionSpaceVector::preEvaluateDivLocalFunctions
   @param points A set of @c 3D Points

   Precomputes the @em Divergence of the Local Functions 
   of this FunctionSpace at the given Points.

   @note Each row of @c point is a new Point,
   and each column is a coordinate (for a total of
   3 columns)
   **

   @fn FunctionSpaceVector::getEvaluatedLocalFunctions
   @param element A MElement
   @return Returns the @em values of the @em precomputed 
   Basis Functions associated
   to the given element (with correct @em closure)
   
   @note
   The returned values @em must be computed by
   FunctionSpaceVector::preEvaluateLocalFunctions(), 
   if not an Exception will be thrown
   **

   @fn FunctionSpaceVector::getEvaluatedCurlLocalFunctions
   @param element A MElement
   @return Returns the @em values of the @em precomputed 
   @em Curls of the Basis Functions associated
   to the given element (with correct @em closure)
   
   @note
   The returned values @em must be computed by
   FunctionSpaceVector::preEvaluateCurlLocalFunctions(), 
   if not an Exception will be thrown
   **

   @fn FunctionSpaceVector::getEvaluatedDivLocalFunctions
   @param element A MElement
   @return Returns the @em values of the @em precomputed 
   @em Divergences of the Basis Functions associated
   to the given element (with correct @em closure)
   
   @note
   The returned values @em must be computed by
   FunctionSpaceVector::preEvaluateDivLocalFunctions(), 
   if not an Exception will be thrown
*/

//////////////////////
// Inline Functions //
//////////////////////

inline const std::vector<const std::vector<Polynomial>*>&
FunctionSpaceVector::getLocalFunctions(const MElement& element) const{
  return locBasis(element, *basisVector);
}

inline const std::vector<const std::vector<Polynomial>*>&
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

inline const std::vector<const Polynomial*>&
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

inline const fullMatrix<double>&
FunctionSpaceVector::getEvaluatedLocalFunctions(const MElement& element) const{
  if(!locPreEvaluated)
    throw Exception("Local Basis Functions not PreEvaluated");

  return locEvalBasis(element, *evalLoc);
}

inline const fullMatrix<double>&
FunctionSpaceVector::getEvaluatedCurlLocalFunctions(const MElement& element) const{
  if(!curlPreEvaluated)
    throw Exception("Curls of Local Basis Functions not PreEvaluated");

  return locEvalBasis(element, *evalCurl);
}

inline const fullMatrix<double>&
FunctionSpaceVector::getEvaluatedDivLocalFunctions(const MElement& element) const{
  if(!divPreEvaluated)
    throw Exception("Divergences of Local Basis Functions not PreEvaluated");

  return locEvalBasis(element, *evalDiv);
}

#endif
