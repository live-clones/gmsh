// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef POLYNOMIAL_BASIS_H
#define POLYNOMIAL_BASIS_H

#include <math.h>
#include <iostream>
#include <map>
#include <vector>
#include "fullMatrix.h"
#include "nodalBasis.h"

class polynomialBasis : public nodalBasis {
public:
  // for now the only implemented polynomial basis are nodal poly basis, we use
  // the type of the corresponding gmsh element as type
  fullMatrix<double> monomials;
  fullMatrix<double> coefficients;

  polynomialBasis(){};
  polynomialBasis(int tag);
  ~polynomialBasis();

  virtual inline int getNumShapeFunctions() const
  {
    return coefficients.size1();
  }

  virtual void f(double u, double v, double w, double *sf) const;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void f(double u, double v, double w, int i, double *sf) const;
  virtual void df(const fullMatrix<double> &coord,
                  fullMatrix<double> &dfm) const;
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void df(double u, double v, double w, int i, double grad[3]) const;
  virtual void ddf(double u, double v, double w, double hess[][3][3]) const;
  virtual void dddf(double u, double v, double w,
                    double third[][3][3][3]) const;

  void evaluateMonomials(double u, double v, double w, double p[]) const;
};

#endif
