#ifndef _TETEDGEBASIS_H_
#define _TETEDGEBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class TetEdgeBasis
   @brief An Edge Basis for Tetrahedra

   This class can instantiate an Edge-Based Basis
   (high or low order) for Tetrahedra

   It uses
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.
*/

class TetEdgeBasis: public BasisHierarchical1Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Tetrahedra of the given order
  TetEdgeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~TetEdgeBasis(void);
};

#endif
