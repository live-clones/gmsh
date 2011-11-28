#ifndef LEGENDREPOLYNOMIALS_H
#define LEGENDREPOLYNOMIALS_H

#include "fullMatrix.h"

class LegendrePolynomials {

 public:
  LegendrePolynomials(int o);
  ~LegendrePolynomials();

  void f(double u, double *val) const;

  void df(double u, double *val) const;

 private:
  int n;
};


#endif
