#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

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
*/

#endif
