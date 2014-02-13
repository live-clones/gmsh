#ifndef _TRINODEBASIS_H_
#define _TRINODEBASIS_H_

#include "BasisHierarchical0Form.h"

/**
   @class TriNodeBasis
   @brief A Node Basis for Triangles

   This class can instantiate a Node-Based Basis
   (high or low order) for Triangles.

   It uses
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.
 */

class TriNodeBasis: public BasisHierarchical0Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Node-Basis for Triangles of the given order
  TriNodeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~TriNodeBasis(void);
};

#endif
