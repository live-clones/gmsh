#ifndef _QUADLAGRANGEBASIS_H_
#define _QUADLAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class QuadLagrangeBasis
   @brief Lagrange Basis for Quadrangles

   This class can instantiate a @em Lagrange @em Basis
   for a Quadrangle and for a given Order.@n

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class QuadLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new QuadLagrangeBasis
  //! of the given Order
  QuadLagrangeBasis(unsigned int order);

  //! Deletes this Basis
  //!
  virtual ~QuadLagrangeBasis(void);

 private:
  //! @param order A natural number
  //! @return Returns the @em tag of a @em Quadrangle of
  //! the given order
  static unsigned int getTag(unsigned int order);
};

#endif
