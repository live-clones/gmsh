// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "approximationError.h"
#include "MElement.h"

double approximationError (simpleFunction<double> &f, MElement *e)
{
  std::vector<double> VALS(e->getNumVertices());
  for (int i=0;i<e->getNumVertices();i++){
    MVertex *v = e->getVertex(i);
    VALS[i] = f(v->x(),v->y(),v->z());
  }
  int npts; IntPt *pts;
  e->getIntegrationPoints (2*e->getPolynomialOrder() + 2 , &npts, &pts);
  double errSqr = 0.0;
  for (int k=0;k<npts;k++){
    const double u = pts[k].pt[0];
    const double v = pts[k].pt[1];
    const double w = pts[k].pt[2];
    SPoint3 p; e->pnt(u, v, w, p);
    const double Jac = e->getJacobianDeterminant(u,v,w);
    const double C = e->interpolate(&VALS[0],u,v,w);
    const double F = f(p.x(),p.y(),p.z());
    const double DIFF = C-F;
    errSqr += pts[k].weight * Jac * (DIFF*DIFF);
  }
  return sqrt(errSqr);
}

