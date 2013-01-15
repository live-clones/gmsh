#ifndef _TRILAGRANGEBASIS_H_
#define _TRILAGRANGEBASIS_H_

#include "BasisLagrange.h"

/**
   @class TriLagrangeBasis
   @brief Lagrange Basis for Triangles
 
   This class can instantiate a @em Lagrange @em Basis 
   for a Triangle and for a given Order.@n
   
   It uses 
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.
 */

class TriLagrangeBasis: public BasisLagrange{
 public:
  //! @param order A natural number
  //!
  //! Returns a new TriLagrangeBasis 
  //! of the given Order
  TriLagrangeBasis(unsigned int order);
  
  //! Deletes this Basis
  //!
  virtual ~TriLagrangeBasis(void);

 private:  
  //! @param order A natural number
  //! @return Returns the @em tag of a @em Triangle of 
  //! the given order 
  static unsigned int getTag(unsigned int order);

  //! @param order A natural number 
  //! @return Returns Lagrangian Points on a Triangle
  //! for the given Order
  static fullMatrix<double> triPoint(unsigned int order);
};

#endif
