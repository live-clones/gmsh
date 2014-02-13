#ifndef _QUADEDGEBASIS_H_
#define _QUADEDGEBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class QuadEdgeBasis
   @brief An Edge Basis for Quads

   This class can instantiate an Edge-Based Basis (high or low order) for Quads.

   It uses a variation of
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.@n

   The following mapping has been applied to Zaglmayr's Basis for Quads:
   @li @f$x = \frac{u + 1}{2}@f$
   @li @f$y = \frac{v + 1}{2}@f$
*/

class QuadEdgeBasis: public BasisHierarchical1Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Quads of the given order
  QuadEdgeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~QuadEdgeBasis(void);
};

#endif
