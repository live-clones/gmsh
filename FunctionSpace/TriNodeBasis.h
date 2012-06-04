#ifndef _TRINODEBASIS_H_
#define _TRINODEBASIS_H_

#include "BasisScalar.h"

/**
   @class TriNodeBasis
   @brief A Node-Basis for Triangles
 
   This class can instantiate a Node-Based Basis 
   (high or low order) for Triangles.@n
   
   It uses 
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n
 */

class TriNodeBasis: public BasisScalar{
 public:
  //! Returns a new Node-Basis for Triangles of the given order
  //! @param order The order of the Basis
  TriNodeBasis(const int order);
  
  //! Deletes this Basis
  //!
  virtual ~TriNodeBasis(void);
};

#endif
