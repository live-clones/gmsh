// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "approximationError.h"
#include "MElement.h"

double approximationError(simpleFunction<double> &f, MElement *element)
{
  std::vector<double> VALS(element->getNumVertices());

  for(std::size_t i = 0; i < element->getNumVertices(); i++) {
    MVertex *v = element->getVertex(i);
    VALS[i] = f(v->x(), v->y(), v->z());
  }

  int npts;
  IntPt *pts;
  element->getIntegrationPoints(2 * element->getPolynomialOrder() + 2, &npts,
                                &pts);
  double errSqr = 0.0;
  for(int k = 0; k < npts; k++) {
    const double u = pts[k].pt[0];
    const double v = pts[k].pt[1];
    const double w = pts[k].pt[2];
    SPoint3 p;
    element->pnt(u, v, w, p);
    const double Jac = element->getJacobianDeterminant(u, v, w);
    const double C = element->interpolate(&VALS[0], u, v, w);
    const double F = f(p.x(), p.y(), p.z());
    errSqr += pts[k].weight * Jac * std::pow(C - F, 2);
  }
  return std::sqrt(errSqr);
}
