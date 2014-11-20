#ifndef _FUNCTIONSPACEVECTOR_H_
#define _FUNCTIONSPACEVECTOR_H_

#include "fullMatrix.h"
#include "FunctionSpaceScalar.h"
#include "FunctionSpace.h"

/**
   @class FunctionSpaceVector
   @brief A vectorial FunctionSpaces

   This class is a vectorial FunctionSpaces.

   A FunctionSpaceVector can be interpolated.
*/


class FunctionSpaceVector : public FunctionSpace{
 public:
  FunctionSpaceVector(const std::vector<const GroupOfElement*>& goe,
                      const std::vector<const GroupOfElement*>& exclude,
                      size_t order, std::string family = "hierarchical");

  FunctionSpaceVector(const std::vector<const GroupOfElement*>& goe,
                      size_t order, std::string family = "hierarchical");

  FunctionSpaceVector(const GroupOfElement& goe,
                      size_t order, std::string family = "hierarchical");

  virtual ~FunctionSpaceVector(void);

  fullVector<double>
    interpolate(const MElement& element,
                const std::vector<double>& coef,
                const fullVector<double>& xyz) const;

  fullVector<double>
    interpolateInRefSpace(const MElement& element,
                          const std::vector<double>& coef,
                          const fullVector<double>& uvw) const;

  fullVector<double>
    interpolateDerivative(const MElement& element,
                          const std::vector<double>& coef,
                          const fullVector<double>& xyz) const;

  fullVector<double>
    interpolateDerivativeInRefSpace(const MElement& element,
                                    const std::vector<double>& coef,
                                    const fullVector<double>& uvw) const;
 private:
  void init(const std::vector<const GroupOfElement*>& goe,
            const std::vector<const GroupOfElement*>& exclude,
            size_t order, std::string family);

  fullVector<double>
    interpolateInABC(const MElement& element,
                     const std::vector<double>& coef,
                     double abc[3]) const;

  fullVector<double>
    interpolateDerivativeInABC(const MElement& element,
                               const std::vector<double>& coef,
                               double abc[3]) const;
};


/**
   @fn FunctionSpaceVector::FunctionSpaceVector(const std::vector<const GroupOfElement*>&,const std::vector<const GroupOfElement*>&,size_t,std::string)
   @param goe A vector of GroupOfElement
   @param exclude An other of GroupOfElement
   @param order A natural number
   @param family A string (defaulted to 'hierarchical')

   Instanciates a new FunctionSpaceVector
   on the GroupOfElement%s of 'goe',
   with the exception of the GroupOfElement%s of 'exclude',
   and with the given order

   The instanciated FunctionSpace will use the requested Basis family:
   @li If family is equal to 'lagrange' a Lagrange Basis will be used
   @li If family is equal to 'hierarchical' a hierarchical Basis will be used

   @see See BasisGenerator::generate()
   **

   @fn FunctionSpaceVector::FunctionSpaceVector(const std::vector<const GroupOfElement*>&,size_t,std::string)
   @param goe A vector of GroupOfElement
   @param order A natural number
   @param family A string (defaulted to 'hierarchical')

   Same as FunctionSpaceVector::FunctionSpaceVector(goe, [], order, family)
   **

   @fn FunctionSpaceVector::FunctionSpaceVector(const GroupOfElement&,size_t,std::string)
   @param goe A GroupOfElement
   @param order A natural number
   @param family A string  (defaulted to 'hierarchical')

   Same as FunctionSpaceVector::FunctionSpaceVector([goe], [], order, family)
   **

   @fn FunctionSpaceVector::~FunctionSpaceVector
   Deletes this FunctionSpaceVector
   **

   @fn FunctionSpaceVector::interpolate
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param xyz The coordinate (of a point inside the given element)
   of the interpolation in the @em physical space

   @return Returns the (vectorial) interpolated value

   If the given coordinate are not in the given
   element @em Bad @em Things may happend
   **

   @fn FunctionSpaceVector::interpolateInRefSpace
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param uvw The coordinate (of a point inside the given element)
   of the interpolation in the @em reference space

   @return Returns the (vectorial) interpolated value

   If the given coordinate are not in the given
   element @em Bad @em Things may happend
   **

   @fn FunctionSpaceVector::interpolateDerivative
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param xyz The coordinate (of a point inside the given element)
   of the interpolation in the @em physical space

   Same as FunctionSpaceVector::interpolate(element, coef, xyz),
   but this method iterpolates the derivative.
   **

   @fn FunctionSpaceVector::interpolateDerivativeInRefSpace
   @param element The MElement to interpolate on
   @param coef The coefficients of the interpolation
   @param uvw The coordinate (of a point inside the given element)
   of the interpolation in the @em reference space

   Same as FunctionSpaceVector::interpolateInRefSpace(element, coef, uvw),
   but this method iterpolates the derivative.
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

inline fullVector<double> FunctionSpaceVector::
interpolateDerivative(const MElement& element,
                      const std::vector<double>& coef,
                      const fullVector<double>& xyz) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromXYZtoABC(element, xyz(0), xyz(1), xyz(2), abc);

  // Interpolate in ABC //
  return interpolateDerivativeInABC(element, coef, abc);
}

inline fullVector<double> FunctionSpaceVector::
interpolateDerivativeInRefSpace(const MElement& element,
                                const std::vector<double>& coef,
                                const fullVector<double>& uvw) const{

  // Get ABC Space coordinate //
  double abc[3];
  ReferenceSpaceManager::mapFromUVWtoABC(element, uvw(0), uvw(1), uvw(2), abc);

  // Interpolate in ABC //
  return interpolateDerivativeInABC(element, coef, abc);
}

#endif
