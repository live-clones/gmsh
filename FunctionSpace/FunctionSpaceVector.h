#ifndef _FUNCTIONSPACEVECTOR_H_
#define _FUNCTIONSPACEVECTOR_H_

#include "fullMatrix.h"
#include "FunctionSpaceScalar.h"
#include "FunctionSpace.h"

/**
   @class FunctionSpaceVector
   @brief A Vectorial FunctionSpaces

   This class is a @em Vectorial FunctionSpaces.@n

   A FunctionSpaceVector can be @em interpolated.
*/


class FunctionSpaceVector : public FunctionSpace{
 public:
  FunctionSpaceVector(GroupOfElement& goe, size_t order);
  FunctionSpaceVector(GroupOfElement& goe, size_t order, std::string family);

  virtual ~FunctionSpaceVector(void);

  fullVector<double>
    interpolate(const MElement& element,
                const std::vector<double>& coef,
                const fullVector<double>& xyz) const;

  fullVector<double>
    interpolateInRefSpace(const MElement& element,
                          const std::vector<double>& coef,
                          const fullVector<double>& uvw) const;

 private:
  fullVector<double>
    interpolateInABC(const MElement& element,
                     const std::vector<double>& coef,
                     double abc[3]) const;
};


/**
   @fn FunctionSpaceVector::FunctionSpaceVector
   @param goe A GroupOfElement
   @em of @em the @em same @em geomtrical @em type
   @param basis A Basis (with a meaning on @c goe)
   Instanciates a new FunctionSpaceVector with the
   given Basis on the given GroupOfElement
   **

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
*/


//////////////////////
// Inline Functions //
//////////////////////

inline fullVector<double> FunctionSpaceVector::
interpolate(const MElement& element,
            const std::vector<double>& coef,
            const fullVector<double>& xyz) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromXYZtoABC(element, xyz(0), xyz(1), xyz(2), abc);

  // Interpolate in ABC //
  return interpolateInABC(element, coef, abc);
}

inline fullVector<double> FunctionSpaceVector::
interpolateInRefSpace(const MElement& element,
                      const std::vector<double>& coef,
                      const fullVector<double>& uvw) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromUVWtoABC(element, uvw(0), uvw(1), uvw(2), abc);

  // Interpolate in ABC //
  return interpolateInABC(element, coef, abc);
}

#endif
