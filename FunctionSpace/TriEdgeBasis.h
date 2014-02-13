#ifndef _TRIEDGEBASIS_H_
#define _TRIEDGEBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class TriEdgeBasis
   @brief An Edge Basis for Triangles

   This class can instantiate an Edge-Based Basis
   (high or low order) for Triangles.

   It uses
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.
*/

class TriEdgeBasis: public BasisHierarchical1Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Triangles of the given order
  TriEdgeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~TriEdgeBasis(void);
};

#endif
