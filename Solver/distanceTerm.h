// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DISTANCE_TERM_H_
#define _DISTANCE_TERM_H_

#include "helmholtzTerm.h"

class distanceTerm : public helmholtzTerm<double> {
 public:
  distanceTerm(GModel *gm, int iField, simpleFunction<double> *k,
               simpleFunction<double> *a)
    : helmholtzTerm<double>(gm, iField, iField, k, a) {}
  void elementVector(SElement *se, fullVector<double> &m) const
  {
    MElement *e = se->getMeshElement();
    int integrationOrder = 2 * e->getPolynomialOrder();
    int npts;
    IntPt *GP;
    double jac[3][3];
    double ff[256];
    e->getIntegrationPoints(integrationOrder, &npts, &GP);
    m.scale(0.); 
    for (int i = 0; i < npts; i++){
      const double u = GP[i].pt[0];
      const double v = GP[i].pt[1];
      const double w = GP[i].pt[2];
      const double weight = GP[i].weight;
      const double detJ = e->getJacobian(u, v, w, jac);
      e->getShapeFunctions(u, v, w, ff);
      for (int j = 0; j < e->getNumShapeFunctions(); j++){
        m(j)  += ff[j] * weight * detJ;
      }
    }
  }
};

#endif
