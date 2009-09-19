// THIS FILE WILL BE REMOVED AS SOON AS THE NEW SOLVER INTERFACE IS READY

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "gmshProjection.h"
#include "Numeric.h"

void gmshProjectionTerm::elementMatrix(MElement *e, fullMatrix<double> &m) const
{
  int nbNodes = e->getNumVertices();
  int integrationOrder = 2 * e->getPolynomialOrder();
  int npts;
  IntPt *GP;
  double jac[3][3];
  double sf[256];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  m.set_all(0.);
  for (int i = 0; i < npts; i++){
    const double u = GP[i].pt[0];
    const double v = GP[i].pt[1];
    const double w = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian(u, v, w, jac);   
    SPoint3 p; e->pnt(u, v, w, p);
    e->getShapeFunctions(u, v, w, sf);
    for (int j = 0; j < nbNodes; j++){
      for (int k = 0; k < nbNodes; k++){
        m(j, k) += sf[j] * sf[k] * weight * detJ;
      }
    }
  }
} 
