#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "ReferenceSpaceManager.h"
#include "FunctionSpace.h"

/**
   @class FunctionSpaceScalar
   @brief A scalar FunctionSpace

   This class is a scalar FunctionSpaces.

   A FunctionSpaceScalar can be interpolated.
*/


class FunctionSpaceScalar : public FunctionSpace{
 public:
  FunctionSpaceScalar(const GroupOfElement& goe, size_t order);
  FunctionSpaceScalar(const std::vector<const GroupOfElement*>& goe,
                      size_t order);

  FunctionSpaceScalar(const GroupOfElement& goe, size_t order,
                      std::string family);
  FunctionSpaceScalar(const std::vector<const GroupOfElement*>& goe,
                      size_t order, std::string family);

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
  void init(const std::vector<const GroupOfElement*>& goe,
            size_t order, std::string family);

  double interpolateInABC(const MElement& element,
                          const std::vector<double>& coef,
                          double abc[3]) const;
  fullVector<double>
    interpolateDerivativeInABC(const MElement& element,
                               const std::vector<double>& coef,
                               double abc[3]) const;
};


/**
   @fn FunctionSpaceScalar::FunctionSpaceScalar(const GroupOfElement&,size_t)
   @param goe A GroupOfElement
   @param order A natural number
   Instanciates a new FunctionSpaceScalar
   on the given GroupOfElement and with the given order

   The instanciated FunctionSpace will use a hierarchical Basis
   **

   @fn FunctionSpaceScalar::FunctionSpaceScalar(const std::vector<const GroupOfElement*>&,size_t)
   @param goe A vector of GroupOfElement
   @param order A natural number
   Instanciates a new FunctionSpaceScalar
   on the given GroupOfElement%s and with the given order

   The instanciated FunctionSpace will use a hierarchical Basis
   **

   @fn FunctionSpaceScalar::FunctionSpaceScalar(const GroupOfElement&,size_t,std::string)
   @param goe A GroupOfElement
   @param order A natural number
   @param family A stringr
   Instanciates a new FunctionSpaceScalar
   on the given GroupOfElement and with the given order

   The instanciated FunctionSpace will use the requested Basis family:
   @li If family is equal to 'lagrange' a Lagrange Basis will be used
   @li If family is equal to 'hierarchical' a hierarchical Basis will be used

   @see See BasisGenerator::generate()
   **

   @fn FunctionSpaceScalar::FunctionSpaceScalar(const std::vector<const GroupOfElement*>&,size_t,std::string)
   @param goe A vector of GroupOfElement
   @param order A natural number
   @param family A stringr
   Instanciates a new FunctionSpaceScalar
   on the given GroupOfElement%s and with the given order

   The instanciated FunctionSpace will use the requested Basis family:
   @li If family is equal to 'lagrange' a Lagrange Basis will be used
   @li If family is equal to 'hierarchical' a hierarchical Basis will be used

   @see See BasisGenerator::generate()
   **

   @fn FunctionSpaceScalar::~FunctionSpaceScalar
   Deletes this FunctionSpaceScalar
   **

   @fn FunctionSpaceScalar::interpolate
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param xyz The coordinate (of a point inside the given element)
   of the interpolation in the @em physical space

   @return Returns the (scalar) interpolated value

   If the given coordinate are not in the given
   element @em Bad @em Things may happend
   **

   @fn FunctionSpaceScalar::interpolateInRefSpace
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param uvw The coordinate (of a point inside the given element)
   of the interpolation in the @em reference space

   @return Returns the (scalar) interpolated value

   If the given coordinate are not in the given
   element @em Bad @em Things may happend
   **

   @fn FunctionSpaceScalar::interpolateDerivative
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param xyz The coordinate (of a point inside the given element)
   of the interpolation in the @em physical space

   Same as FunctionSpaceScalar::interpolate(element, coef, xyz),
   but this method iterpolates the derivative.
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
