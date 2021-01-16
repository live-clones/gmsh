// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PYRAMIDALBASIS_H
#define PYRAMIDALBASIS_H

#include "fullMatrix.h"
#include "nodalBasis.h"
#include "BergotBasis.h"

class pyramidalBasis : public nodalBasis {
private:
  // Orthogonal basis for the pyramid
  BergotBasis *bergot;
  fullMatrix<double> bergotCoefficients;

public:
  fullMatrix<double> coefficients;
  fullMatrix<double> monomials;

public:
  pyramidalBasis(int tag);
  ~pyramidalBasis();
  virtual void f(double u, double v, double w, double *val) const;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void f(double u, double v, double w, int i, double *val) const;
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void df(const fullMatrix<double> &coord,
                  fullMatrix<double> &dfm) const;
  virtual void df(double u, double v, double w, int i, double grad[3]) const;
  virtual int getNumShapeFunctions() const;
};

#endif
