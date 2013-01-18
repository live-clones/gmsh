#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "FunctionSpace.h"

/**
   @class FunctionSpaceScalar
   @brief A Scalar FunctionSpaces

   This class is a @em Scalar FunctionSpaces.@n

   A FunctionSpaceScalar can be @em interpolated.

   @todo
   Allow interpolation with multiple basis
*/


class FunctionSpaceScalar : public FunctionSpace{
 public:
  FunctionSpaceScalar(const GroupOfElement& goe, const Basis& basis);
  virtual ~FunctionSpaceScalar(void);

  double
    interpolate(const MElement& element,
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const;

  double
    interpolateInRefSpace(const MElement& element,
			  const std::vector<double>& coef,
			  const fullVector<double>& uvw) const;
};


/**
   @fn FunctionSpaceScalar::FunctionSpaceScalar
   @param goe A GroupOfElement
   @em of @em the @em same @em geomtrical @em type
   @param basis A Basis (with a meaning on @c goe)
   Instanciates a new FunctionSpaceScalar with the
   given Basis on the given GroupOfElement
   **

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
