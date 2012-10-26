// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef BASIS_H
#define BASIS_H

#include "fullMatrix.h"

class nodalBasis {

 public:
  int type, parentType, order, dimension, numFaces;
  bool serendip;
  fullMatrix<double> points;

  virtual void initialize() {};

  // Basis functions evaluation
  inline virtual void f(double u, double v, double w, double *sf) const {};
  inline void f(fullMatrix<double> &coord, fullMatrix<double> &sf) const;

  // Basis functions gradients evaluation
  inline virtual void df(double u, double v, double w, double grads[][3]) const {};
  inline void df(fullMatrix<double> &coord, fullMatrix<double> &dfm) const;
  
  inline void ddf(double u, double v, double w, double grads[][3][3]) const {};
  inline void dddf(double u, double v, double w, double grads[][3][3][3]) const {};

};
#endif