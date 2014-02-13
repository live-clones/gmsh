#ifndef _LINEEDGEBASIS_H_
#define _LINEEDGEBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class LineEdgeBasis
   @brief An Edge Basis for Lines

   This class can instantiate an Edge-Based Basis (high or low order) for Lines.

   It uses an adaptation of
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.@n

   This Basis is a restriction of a Quad Basis to @f$y = 0@f$.

   It also uses the following mapping: @f$x = \frac{u + 1}{2}@f$.
*/

class LineEdgeBasis: public BasisHierarchical1Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Lines of the given order
  LineEdgeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~LineEdgeBasis(void);
};

#endif
