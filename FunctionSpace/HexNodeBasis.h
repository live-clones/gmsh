#ifndef _HEXNODEBASIS_H_
#define _HEXNODEBASIS_H_

#include "BasisScalar.h"

/**
   @class HexNodeBasis
   @brief A Node Basis for Hexahedra
 
   This class can instantiate a Node-Based Basis 
   (high or low order) for Hexahedra.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 */

class HexNodeBasis: public BasisScalar{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Node-Basis for Hexahedra of the given order
  HexNodeBasis(const int order);

  //! @return Deletes this Basis
  //!
  virtual ~HexNodeBasis(void);
};

#endif
