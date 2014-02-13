#ifndef _HEXEDGEBASIS_H_
#define _HEXEDGEBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class HexEdgeBasis
   @brief An Edge Basis for Hexahedra

   This class can instantiate an Edge-Based Basis
   (high or low order) for Hexahedra.

   It uses
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>
   Basis for high order Polynomial%s generation.
 */

class HexEdgeBasis: public BasisHierarchical1Form{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Edge-Basis for Hexahedra of the given order
  HexEdgeBasis(size_t order);

  //! Deletes this Basis
  //!
  virtual ~HexEdgeBasis(void);
};

#endif
