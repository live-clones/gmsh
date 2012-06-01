#ifndef _QUADEDGEBASIS_H_
#define _QUADEDGEBASIS_H_

#include "BasisVector.h"

/**
   @class QuadEdgeBasis
   @brief An Edge-Basis for Quads
 
   This class can instantiate an Edge-Based Basis 
   (high or low order) for Quads.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 */

class QuadEdgeBasis: public BasisVector{
 public:
  QuadEdgeBasis(const int order);
  virtual ~QuadEdgeBasis(void);
};

/**
   @fn QuadEdgeBasis::QuadEdgeBasis(const int order)
   @param order The order of the Basis
   @return Returns a new Edge-Basis for Quads of the given order

   @fn QuadEdgeBasis::~QuadEdgeBasis(void)
   @return Deletes this Basis
*/

#endif
