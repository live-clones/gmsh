#ifndef _TRILAGRANGEBASIS_H_
#define _TRILAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class TriLagrangeBasis
   @brief Lagrange Basis for Triangles

   This class can instantiate a Lagrange Basis
   for a Triangle and for a given order.

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class TriLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new TriLagrangeBasis of the given order
  TriLagrangeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~TriLagrangeBasis(void);
};

#endif
