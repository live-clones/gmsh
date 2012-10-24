#ifndef _QUADNODEBASIS_H_
#define _QUADNODEBASIS_H_

#include "BasisScalar.h"

/**
   @class QuadNodeBasis
   @brief A Node Basis for Quads
 
   This class can instantiate a Node-Based Basis 
   (high or low order) for Quads.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 */

class QuadNodeBasis: public BasisScalar{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Node-Basis for Quads of the given order
  QuadNodeBasis(int order);

  //! @return Deletes this Basis
  //!
  virtual ~QuadNodeBasis(void);
};

#endif
