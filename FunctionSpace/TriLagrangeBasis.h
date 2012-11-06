#ifndef _TRILAGRANGEBASIS_H_
#define _TRILAGRANGEBASIS_H_

#include "LagrangeBasis.h"

/**
   @class TriLagrangeBasis
   @brief Lagrange Basis for Triangles
 
   This class can instantiate a @em Lagrange @em Basis 
   for a Triangle and for a given Order.@n
   
   It uses 
   <a href="http://geuz.org/gmsh/">gmsh</a> Basis.@n

   @todo
   Add method to erase polynomialBasis in polynomialBasis
 */

class TriLagrangeBasis: public LagrangeBasis{
 public:
  //! @param odrer A natural number
  //!
  //! Returns a new  for TriLagrangeBasis 
  //! of the given Order
  TriLagrangeBasis(int order);
  
  //! Deletes this Basis
  //!
  virtual ~TriLagrangeBasis(void);

 private:  
  //! @param order A natural number 
  //! @return Returns Lagrangian Points on a Triangle
  //! for the given Order
  static fullMatrix<double> triPoint(unsigned int order);
};

#endif
