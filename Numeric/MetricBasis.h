// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _METRIC_BASIS_H_
#define _METRIC_BASIS_H_

#include "MElement.h"
#include "JacobianBasis.h"
#include "fullMatrix.h"

class MetricCoefficient {
 private:
  MElement *_element;
  const JacobianBasis *_jacobian;
  fullMatrix<double> _coefficientsLag, _coefficientsBez;

 public:
  MetricCoefficient(MElement*);
  void getCoefficients(fullMatrix<double>&, bool bezier = true);
  void interpolate(const double *uvw, double *minmaxQ);
  void getBound(double tol);

 private:
  void _computeBezCoeff();
  void _interpolateBezierPyramid(const double *uvw, double *minmaxQ);
};

#endif
