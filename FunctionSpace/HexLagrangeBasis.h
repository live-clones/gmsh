#ifndef _HEXLAGRANGEBASIS_H_
#define _HEXLAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class HexLagrangeBasis
   @brief Lagrange Basis for Hexahedra

   This class can instantiate a @em Lagrange @em Basis
   for a Hexahedron and for a given Order.@n

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class HexLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new HexLagrangeBasis
  //! of the given Order
  HexLagrangeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~HexLagrangeBasis(void);
};

#endif
