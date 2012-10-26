// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef LEGENDREPOLYNOMIALS_H
#define LEGENDREPOLYNOMIALS_H

#include "fullMatrix.h"

class LegendrePolynomials {

 public:
  LegendrePolynomials() {};
  LegendrePolynomials(int o);
  ~LegendrePolynomials();

  void f(double u, double *val) const;

  void df(double u, double *val) const;

 private:
  int n;
};


#endif
