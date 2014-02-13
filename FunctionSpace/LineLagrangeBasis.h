#ifndef _LINELAGRANGEBASIS_H_
#define _LINELAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class LineLagrangeBasis
   @brief Lagrange Basis for Lines

   This class can instantiate a Lagrange Basis
   for a Line and for a given order.

   It uses
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class LineLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new LineLagrangeBasis of the given order
  LineLagrangeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~LineLagrangeBasis(void);
};

#endif
