// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _BEZIER_BASIS_H_
#define _BEZIER_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"
#include "ElementType.h"

class MElement;

class bezierBasis {
 public:
 //private :
  // the 'numLagPts' first exponents are related to 'Lagrangian' values
  int dim, order;
  int numLagPts;
  int numDivisions;
  fullMatrix<double> subDivisor;

 public :
  fullMatrix<double> lagPoints; // sampling point
  fullMatrix<double> matrixLag2Bez, matrixBez2Lag;

  inline bezierBasis(int tag) {
    _construct(ElementType::ParentTypeFromTag(tag), ElementType::OrderFromTag(tag));
  }
  inline bezierBasis(int parendtType, int order) {
    _construct(parendtType, order);
  }

  // get methods
  inline int getDim() {return dim;}
  inline int getOrder() {return order;}
  inline int getNumLagPts() {return numLagPts;}
  inline int getNumDivision() {return numDivisions;}

 private :
  void _construct(int parendtType, int order);
};

#endif


