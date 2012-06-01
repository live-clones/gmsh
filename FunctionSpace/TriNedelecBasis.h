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
  TriNedelecBasis(void);
  virtual ~TriNedelecBasis(void);
};


/**
   @fn TriNedelecBasis::TriNedelecBasis
   @return Returns a new Nedelec Basis for Triangles

   @fn TriNedelecBasis::~TriNedelecBasis(void)
   @return Deletes this Basis
*/

#endif
