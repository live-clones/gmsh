#ifndef _TRIEDGEBASIS_H_
#define _TRIEDGEBASIS_H_

#include "BasisVector.h"

/**
   @class TriEdgeBasis
   @brief An Edge-Basis for Triangles
 
   This class can instantiate an Edge-Based Basis 
   (high or low order) for Triangles.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
*/

class TriEdgeBasis: public BasisVector{
 public:
  //! Returns a new Edge-Basis for Triangles of the given order
  //! @param order The order of the Basis
  TriEdgeBasis(const int order);
  
  //! Deletes this Basis
  //!
  virtual ~TriEdgeBasis(void);
};

#endif
