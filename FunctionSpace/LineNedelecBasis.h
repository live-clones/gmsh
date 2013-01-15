#ifndef _LINENEDELECBASIS_H_
#define _LINENEDELECBASIS_H_

#include "BasisHierarchicalVector.h"

/**
   @class LineNedelecBasis
   @brief Nedelec Basis for Lines
 
   This class can instantiate a Nedelec Basis 
   for Lines.@n
*/

class LineNedelecBasis: public BasisHierarchicalVector{
 public:
  //! Returns a new Nedelec Basis for Lines
  //!
  LineNedelecBasis(void);
  
  //! Deletes this Basis
  //!
  virtual ~LineNedelecBasis(void);
};

#endif
