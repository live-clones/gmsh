#ifndef _LINENODEBASIS_H_
#define _LINENODEBASIS_H_

#include "BasisHierarchicalScalar.h"

/**
   @class LineNodeBasis
   @brief A Node Basis for Lines
 
   This class can instantiate a Node-Based Basis 
   (high or low order) for Lines.@n
   
   It uses an @em adaptation of
   <a href="http://www.hpfem.jku.at/publications/szthesis.pdf">Zaglmayr's</a>  
   Basis for @em high @em order Polynomial%s generation.@n

   This Basis is a restriction of a Quad Basis to @f$y = 0@f$.@n
   
   It also uses the following mapping: @f$x = \frac{u + 1}{2}@f$.
 */

class LineNodeBasis: public BasisHierarchicalScalar{
 public:
  //! @param order The order of the Basis
  //!
  //! Returns a new Node-Basis for Lines of the given order
  LineNodeBasis(unsigned int order);
  
  //! Deletes this Basis
  //!
  virtual ~LineNodeBasis(void);
};

#endif
