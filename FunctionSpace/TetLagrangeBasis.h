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

  //! @param order A natural number
  //! @return Returns Lagrangian Points on a Tetrahedron
  //! for the given Order
  static fullMatrix<double> tetPoint(unsigned int order);

  //! Unknown gmsh function
  static unsigned int nbdoftriangle(unsigned int order);

  //! Unknown gmsh function
  static void nodepositionface0(unsigned int order,
                                double *u, double *v, double *w);

  //! Unknown gmsh function
  static void nodepositionface1(unsigned int order,
                                double *u, double *v, double *w);

  //! Unknown gmsh function
  static void nodepositionface2(unsigned int order,
                                double *u, double *v, double *w);

  //! Unknown gmsh function
  static void nodepositionface3(unsigned int order,
                                double *u, double *v, double *w);
};

#endif
