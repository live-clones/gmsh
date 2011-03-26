// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _JACOBIAN_BASIS_H_
#define _JACOBIAN_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"

class JacobianBasis
{
  public:
    int numLagPts;
    int numDivisions;
    fullMatrix<double> exposants; //exposants of Bezier FF
    fullMatrix<double> points; //sampling point
    fullMatrix<double> matrixLag2Bez;
    fullMatrix<double> gradShapeMatX;
    fullMatrix<double> gradShapeMatY;
    fullMatrix<double> gradShapeMatZ;
    fullMatrix<double> divisor;
};

class JacobianBases
{
 private:
  static std::map<int, JacobianBasis> fs;
 public:
  static const JacobianBasis *find(int);
};

#endif
