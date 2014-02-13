#ifndef _QUADNEDELECBASIS_H_
#define _QUADNEDELECBASIS_H_

#include "BasisHierarchical1Form.h"

/**
   @class QuadNedelecBasis
   @brief Nedelec Basis for Quads

   This class can instantiate a Nedelec Basis for Quadrangles.
*/

class QuadNedelecBasis: public BasisHierarchical1Form{
 public:
  //! Returns a new Nedelec Basis for Quadrangles
  //!
  QuadNedelecBasis(void);

  //! Deletes this Basis
  //!
  virtual ~QuadNedelecBasis(void);
};

#endif
