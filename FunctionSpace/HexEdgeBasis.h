#ifndef _HEXEDGEBASIS_H_
#define _HEXEDGEBASIS_H_

#include "BasisVector.h"

/**
   @class HexEdgeBasis
   @brief An Edge-Basis for Hexahedrons
 
   This class can instantiate an Edge-Based Basis 
   (high or low order) for Hexahedrons.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 */

class HexEdgeBasis: public BasisVector{
 public:
  //! Returns a new Edge-Basis for Hexahedrons of the given order
  //! @param order The order of the Basis
  HexEdgeBasis(const int order);
  
  //! Deletes this Basis
  //!
  virtual ~HexEdgeBasis(void);
};

#endif
