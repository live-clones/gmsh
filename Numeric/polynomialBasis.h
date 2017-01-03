// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _POLYNOMIAL_BASIS_H_
#define _POLYNOMIAL_BASIS_H_

#include <math.h>
#include <map>
#include <vector>
#include "fullMatrix.h"
#include "nodalBasis.h"
#include <iostream>


inline double pow_int(const double &a, const int &n)
{
  switch (n) {
  case 0 : return 1.0;
  case 1 : return a;
  case 2 : return a*a;
  case 3 : return a*a*a;
  case 4 :
    {
      const double a2 = a*a;
      return a2*a2;
    }
  case 5 :
    {
      const double a2 = a*a;
      return a2*a2*a;
    }
  case 6 :
    {
      const double a3 = a*a*a;
      return a3*a3;
    }
  case 7 :
    {
      const double a3 = a*a*a;
      return a3*a3*a;
    }
  case 8 :
    {
      const double a2 = a*a;
      const double a4 = a2*a2;
      return a4*a4;
    }
  case 9 :
    {
      const double a3 = a*a*a;
      return a3*a3*a3;
    }
  case 10 :
    {
      const double a2 = a*a;
      const double a4 = a2*a2;
      return a4*a4*a2;
    }
  default :
    return pow_int(a, n-9) * pow_int(a, 9);
  }
}

inline double pow_int(const double &a, const double &d)
{
  // Round double !
  int n = static_cast<int>(d + .5);
  return pow_int(a, n);
}

class polynomialBasis : public nodalBasis
{
 public:
  // for now the only implemented polynomial basis are nodal poly
  // basis, we use the type of the corresponding gmsh element as type
  fullMatrix<double> monomials;
  fullMatrix<double> coefficients;

  polynomialBasis() {};
  polynomialBasis(int tag);
  ~polynomialBasis();

  virtual inline int getNumShapeFunctions() const {return coefficients.size1();}

  virtual void f(double u, double v, double w, double *sf) const;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const;
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void ddf(double u, double v, double w, double hess[][3][3]) const;
  virtual void dddf(double u, double v, double w, double third[][3][3][3]) const;

  void evaluateMonomials(double u, double v, double w, double p[]) const;
};


#endif
