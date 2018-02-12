// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef INCOMPLETE_BASIS_H
#define INCOMPLETE_BASIS_H

//#include <math.h>
//#include <map>
//#include <vector>
//#include "fullMatrix.h"
#include "nodalBasis.h"
//#include <iostream>


class incompleteBasis : public nodalBasis
{
private:
  nodalBasis *completeBasis;
  polynomialBasis *polyBasis;
  fullMatrix<double> coefficients;

public:

  incompleteBasis() {};
  incompleteBasis(int tag);
  ~incompleteBasis();

  virtual inline int getNumShapeFunctions() const {return points.size1();}

  virtual void f(double u, double v, double w, double *sf) const;
  virtual void f(const fullMatrix<double> &coord, fullMatrix<double> &sf) const;
  virtual void df(const fullMatrix<double> &coord, fullMatrix<double> &dfm) const;
  virtual void df(double u, double v, double w, double grads[][3]) const;
  virtual void ddf(double u, double v, double w, double hess[][3][3]) const;
  virtual void dddf(double u, double v, double w, double third[][3][3][3]) const;

  void evaluateMonomials(double u, double v, double w, double p[]) const;
};


#endif
