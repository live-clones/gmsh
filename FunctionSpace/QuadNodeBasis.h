#ifndef _QUADNODEBASIS_H_
#define _QUADNODEBASIS_H_

#include "BasisHierarchicalScalar.h"

/**
   @class QuadNodeBasis
   @brief A Node Basis for Quads
 
   This class can instantiate a Node-Based Basis 
   (high or low order) for Quads.@n
   
   It uses a variation of
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 
   The following mapping has been applied to Zaglmayr's Basis for Quads:
   @li @f$x = \frac{u + 1}{2}@f$
   @li @f$y = \frac{v + 1}{2}@f$
*/

class QuadNodeBasis: public BasisHierarchicalScalar{
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
