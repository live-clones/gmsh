#ifndef _HEXEDGEBASIS_H_
#define _HEXEDGEBASIS_H_

#include "BasisVector.h"

/**
   @class HexEdgeBasis
   @brief An Edge Basis for Hexahedra
 
   This class can instantiate an Edge-Based Basis 
   (high or low order) for Hexahedra.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 */

class HexEdgeBasis: public BasisVector{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Hexahedra of the given order
  HexEdgeBasis(int order);
  
  //! Deletes this Basis
  //!
  virtual ~HexEdgeBasis(void);
};

#endif
