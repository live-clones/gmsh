#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "ReferenceSpaceManager.h"
#include "FunctionSpace.h"

/**
   @class FunctionSpaceScalar
   @brief A Scalar FunctionSpaces

   This class is a @em Scalar FunctionSpaces.@n

   A FunctionSpaceScalar can be @em interpolated.
*/


class FunctionSpaceScalar : public FunctionSpace{
 public:
  FunctionSpaceScalar(GroupOfElement& goe, size_t order);
  FunctionSpaceScalar(GroupOfElement& goe, size_t order, std::string family);

  virtual ~FunctionSpaceScalar(void);

  double
    interpolate(const MElement& element,
                const std::vector<double>& coef,
                const fullVector<double>& xyz) const;

  double
    interpolateInRefSpace(const MElement& element,
                          const std::vector<double>& coef,
                          const fullVector<double>& uvw) const;

  fullVector<double>
    interpolateDerivative(const MElement& element,
                          const std::vector<double>& coef,
                          const fullVector<double>& xyz) const;

 private:
  double interpolateInABC(const MElement& element,
                          const std::vector<double>& coef,
                          double abc[3]) const;
  fullVector<double>
    interpolateDerivativeInABC(const MElement& element,
                               const std::vector<double>& coef,
                               double abc[3]) const;
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


//////////////////////
// Inline Functions //
//////////////////////

inline double FunctionSpaceScalar::
interpolate(const MElement& element,
            const std::vector<double>& coef,
            const fullVector<double>& xyz) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromXYZtoABC(element, xyz(0), xyz(1), xyz(2), abc);

  // Interpolate in ABC //
  return interpolateInABC(element, coef, abc);
}

inline double FunctionSpaceScalar::
interpolateInRefSpace(const MElement& element,
                      const std::vector<double>& coef,
                      const fullVector<double>& uvw) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromUVWtoABC(element, uvw(0), uvw(1), uvw(2), abc);

  // Interpolate in ABC //
  return interpolateInABC(element, coef, abc);
}

inline fullVector<double> FunctionSpaceScalar::
interpolateDerivative(const MElement& element,
                      const std::vector<double>& coef,
                      const fullVector<double>& xyz) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromXYZtoABC(element, xyz(0), xyz(1), xyz(2), abc);

  // Interpolate in ABC //
  return interpolateDerivativeInABC(element, coef, abc);
}

#endif
