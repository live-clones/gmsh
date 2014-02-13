#ifndef _TETLAGRANGEBASIS_H_
#define _TETLAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class TetLagrangeBasis
   @brief Lagrange Basis for Tetrahedra

   This class can instantiate a Lagrange Basis
   for a Tetrahedron and for a given order.

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class TetLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new TetLagrangeBasis of the given order
  TetLagrangeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~TetLagrangeBasis(void);
};

#endif
