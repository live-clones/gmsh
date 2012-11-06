#ifndef _LAGRANGEBASIS_H_
#define _LAGRANGEBASIS_H_

#include <vector>

#include "polynomialBasis.h"
#include "BasisScalar.h"

/**
   @interface LagrangeBasis
   @brief Interoface for Lagrange Basis
 
   This is an interface for Lagrange Basis.@n
 
   These Scalar Basis allow a @em Coefficient Matrix,
   and a Monomial Matrix, to be consulted.@n

   A vector from an Other Basis (set of Functions)
   can also be projected into a Lagrange Basis.@n

   @todo
   Add a method to erase polynomialBasis in polynomialBasis@n
   Add a method to get lagrange Point in polynomialBasis
 */

class LagrangeBasis: public BasisScalar{
 protected:
  fullMatrix<double>* point;
  const polynomialBasis* l;

 public:
  //! Deletes this Basis
  //!
  virtual ~LagrangeBasis(void);

  //! @return Returns the Coefficient Matrix
  const fullMatrix<double>& getCoefficient(void) const;

  //! @return Returns the Monomial Matrix
  const fullMatrix<double>& getMonomial(void) const;

  //! @param coef A vector of Real numbers
  //! @param basis A vector of Polynomials 
  //! in a @em Reference Space
  //! @return Projects the given Coefficients in this LagrangeBasis@n
  fullVector<double> project(const fullVector<double>& coef,
			     const std::vector<const Polynomial*>& basis);

 protected:
  //! Returns a new LagrangeBasis
  //!
  LagrangeBasis(void);
};


//////////////////////
// Inline Functions //
//////////////////////

inline const fullMatrix<double>& LagrangeBasis::
getCoefficient(void) const{
  return l->coefficients;
}

inline const fullMatrix<double>& LagrangeBasis::
getMonomial(void) const{
  return l->monomials;
}

#endif
