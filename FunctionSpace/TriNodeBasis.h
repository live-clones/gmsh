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
  TriNodeBasis(const int order);
  virtual ~TriNodeBasis(void);
};

/**
   @fn TriNodeBasis::TriNodeBasis(const int order)
   @param order The order of the Basis
   @return Returns a new Node-Basis for Triangles of the given order

   @fn TriNodeBasis::~TriNodeBasis(void)
   @return Deletes this Basis
*/

#endif
