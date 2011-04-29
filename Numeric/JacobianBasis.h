// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _JACOBIAN_BASIS_H_
#define _JACOBIAN_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"
class bezierBasis {
 private :
  static std::map<int, bezierBasis> _bbs;
 public :
  int numLagPts;
  int numDivisions;
  fullMatrix<double> exposants; //exposants of Bezier FF
  fullMatrix<double> points; //sampling point
  fullMatrix<double> matrixLag2Bez, matrixBez2Lag;
  fullMatrix<double> divisor;
  static const bezierBasis *find(int);
};

class JacobianBasis {
 public :
  const bezierBasis *bezier;
  fullMatrix<double> gradShapeMatX;
  fullMatrix<double> gradShapeMatY;
  fullMatrix<double> gradShapeMatZ;
 private:
  static std::map<int, JacobianBasis> fs;
 public:
  static const JacobianBasis *find(int);
};

#endif
