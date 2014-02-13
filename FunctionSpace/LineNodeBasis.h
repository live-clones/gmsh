#ifndef _LINENODEBASIS_H_
#define _LINENODEBASIS_H_

#include "BasisHierarchical0Form.h"

/**
   @class LineNodeBasis
   @brief A Node Basis for Lines

   This class can instantiate a Node-Based Basis (high or low order) for Lines.

   It uses an adaptation of
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.

   This Basis is a restriction of a Quad Basis to @f$y = 0@f$.

   It also uses the following mapping: @f$x = \frac{u + 1}{2}@f$.
 */

class LineNodeBasis: public BasisHierarchical0Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Node-Basis for Lines of the given order
  LineNodeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~LineNodeBasis(void);
};

#endif
