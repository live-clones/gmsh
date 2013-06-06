// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _BEZIER_BASIS_H_
#define _BEZIER_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"

class bezierBasis {
 private :
 public :
  int dim, order;
  int numLagPts;
  int numDivisions;
  // the 'numLagPts' first exponents are related to 'Lagrangian' values
  bezierBasis() {Msg::Fatal("Should not be created this way");};
  bezierBasis(int tag);
  fullMatrix<double> exponents; // exponents of Bezier FF
  fullMatrix<double> bezierPoints, lagPoints; // sampling point
  fullMatrix<double> matrixLag2Bez, matrixBez2Lag;
  fullMatrix<double> subDivisor;
};

#endif


