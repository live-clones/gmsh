#ifndef _LINELAGRANGEBASIS_H_
#define _LINELAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class LineLagrangeBasis
   @brief Lagrange Basis for Lines

   This class can instantiate a @em Lagrange @em Basis
   for a Line and for a given Order.@n

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class LineLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new LineLagrangeBasis
  //! of the given Order
  LineLagrangeBasis(unsigned int order);

  //! Deletes this Basis
  //!
  virtual ~LineLagrangeBasis(void);

 private:
  //! @param order A natural number
  //! @return Returns the @em tag of a @em Line of
  //! the given order
  static unsigned int getTag(unsigned int order);

  //! @param order A natural number
  //! @return Returns Lagrangian Points on a Line
  //! for the given Order
  static fullMatrix<double> linePoint(unsigned int order);
};

#endif
