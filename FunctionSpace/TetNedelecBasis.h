#ifndef _TETNEDELECBASIS_H_
#define _TETNEDELECBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class TetNedelecBasis
   @brief A Nedelec Basis for Tetrahedra

   This class can instantiate a Nedelec Basis for Tetrahedra.
*/

class TetNedelecBasis: public BasisHierarchical1Form{
 public:
  //! Returns a new Nedelec Basis for Tetrahedra
  //!
  TetNedelecBasis(void);

  //! Deletes this Basis
  //!
  virtual ~TetNedelecBasis(void);
};

#endif
