// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MEANVALUE_BASIS_H
#define MEANVALUE_BASIS_H

#include <math.h>
#include "fullMatrix.h"
#include "nodalBasis.h"
#include "MElement.h"

class meanValueBasis : public nodalBasis {
public:
  fullMatrix<double> coordinates;

  meanValueBasis() {};
  ~meanValueBasis() {};

  virtual inline int getNumShapeFunctions() const { return 0; }

  virtual void f(double x, double y, double z, double *sf) const;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void f(double x, double y, double z, int i, double *sf) const;
  virtual void df(const fullMatrix<double> &coord,
                  fullMatrix<double> &dfm) const;
  virtual void df(double x, double y, double z, double grads[][3]) const;
  virtual void df(double x, double y, double z, int i, double grad[3]) const;
  virtual void ddf(double x, double y, double z, double hess[][3][3]) const;
  virtual void dddf(double x, double y, double z,
                    double third[][3][3][3]) const;

  void evaluateCoordinates(MElement *e, double x, double y, double z,
                           std::vector<double> c) const;
};

#endif
