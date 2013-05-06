#ifndef _TETLAGRANGEBASIS_H_
#define _TETLAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class TetLagrangeBasis
   @brief Lagrange Basis for Tetrahedra

   This class can instantiate a @em Lagrange @em Basis
   for a Tetrahedron and for a given Order.@n

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class TetLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new TetLagrangeBasis
  //! of the given Order
  TetLagrangeBasis(unsigned int order);

  //! Deletes this Basis
  //!
  virtual ~TetLagrangeBasis(void);

 private:
  //! @param order A natural number
  //! @return Returns the @em tag of a @em Tetrahedron of
  //! the given order
  static unsigned int getTag(unsigned int order);
};

#endif
