#ifndef _QUADNODEBASIS_H_
#define _QUADNODEBASIS_H_

#include "BasisHierarchical0Form.h"

/**
   @class QuadNodeBasis
   @brief A Node Basis for Quads

   This class can instantiate a Node-Based Basis (high or low order) for Quads.

   It uses a variation of
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.@n

   The following mapping has been applied to Zaglmayr's Basis for Quads:
   @li @f$x = \frac{u + 1}{2}@f$
   @li @f$y = \frac{v + 1}{2}@f$
*/

class QuadNodeBasis: public BasisHierarchical0Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Node-Basis for Quads of the given order
  QuadNodeBasis(size_t order);

  //! @return Deletes this Basis
  //!
  virtual ~QuadNodeBasis(void);
};

#endif
