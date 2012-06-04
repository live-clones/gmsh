#ifndef _TRINEDELECBASIS_H_
#define _TRINEDELECBASIS_H_

#include "BasisVector.h"

/**
   @class TriNedelecBasis
   @brief Nedelec Basis for Triangles
 
   This class can instantiate a Nedelec Basis 
   for Triangles.@n
*/

class TriNedelecBasis: public BasisVector{
 public:
  //! Returns a new Nedelec Basis for Triangles
  //!
  TriNedelecBasis(void);
  
  //! Deletes this Basis
  //!
  virtual ~TriNedelecBasis(void);
};

#endif
