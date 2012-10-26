// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef JACOBIPOLYNOMIALS_H
#define JACOBIPOLYNOMIALS_H

#include "fullMatrix.h"

class JacobiPolynomials {

 public:
  JacobiPolynomials() {};
  JacobiPolynomials(double a, double b, int o);
  ~JacobiPolynomials();

  void f(double u, double *val) const;

  void df(double u, double *val) const;

 private:
  double alpha;
  double beta;
  int n;

  double alphaPlusBeta;
  double a2MinusB2;

};


#endif
