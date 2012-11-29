// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _JACOBIAN_BASIS_H_
#define _JACOBIAN_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"

class MElement;

class bezierBasis {
 private :
  static std::map<int, bezierBasis> _bbs;
 public :
  int order;
  int numLagPts;
  int numDivisions;
  // the 'numLagPts' first exponents are related to 'Lagrangian' values
  fullMatrix<double> exponents; // exponents of Bezier FF
  fullMatrix<double> points; // sampling point
  fullMatrix<double> matrixLag2Bez, matrixBez2Lag;
  fullMatrix<double> subDivisor;
  static const bezierBasis *find(int);
};

class JacobianBasis {
 private:
  static std::map<int, JacobianBasis> _fs;
 public :
  const bezierBasis *bezier;
  fullMatrix<double> gradShapeMatX, gradShapeMatY, gradShapeMatZ;
  fullMatrix<double> primJac2Jac;                                   // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.
  static const JacobianBasis *find(int);
  void getSignedJacobian(MElement *el, fullVector<double> &jacobian) const;
};

#endif
