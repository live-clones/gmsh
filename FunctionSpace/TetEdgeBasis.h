#ifndef _TETEDGEBASIS_H_
#define _TETEDGEBASIS_H_

#include "BasisVector.h"

/**
   @class TetEdgeBasis
   @brief An Edge Basis for Tetrahedra
 
   This class can instantiate an Edge-Based Basis 
   (high or low order) for Tetrahedra.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
*/

class TetEdgeBasis: public BasisVector{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Tetrahedra of the given order
  TetEdgeBasis(int order);
  
  //! Deletes this Basis
  //!
  virtual ~TetEdgeBasis(void);
};

#endif
