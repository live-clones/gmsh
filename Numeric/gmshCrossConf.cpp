// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "gmshCrossConf.h"
#include "Numeric.h"

void gmshCrossConfTerm::elementMatrix(MElement *e, gmshMatrix<double> &m) const
{
  int nbNodes = e->getNumVertices();
  int integrationOrder = 2 * (e->getPolynomialOrder() - 1);
  int npts;
  IntPt *GP;
  double jac[3][3];
  double invjac[3][3];
  SVector3 Grads [256];
  double grads[256][3];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  
  m.set_all(0.);

  for (int i = 0; i < npts; i++){
    const double u = GP[i].pt[0];
    const double v = GP[i].pt[1];
    const double w = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian(u, v, w, jac);   
    SPoint3 p; e->pnt(u, v, w, p);
    const double _diff = (*_diffusivity)(p.x(), p.y(), p.z());
    inv3x3(jac, invjac) ; 
    e->getGradShapeFunctions(u, v, w, grads);
    for (int j = 0; j < nbNodes; j++){
      Grads[j] = SVector3(invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] + 
			  invjac[0][2] * grads[j][2],
			  invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] + 
			  invjac[1][2] * grads[j][2],
			  invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] +
			  invjac[2][2] * grads[j][2]);
    }

    SVector3 N (jac[2][0],jac[2][1],jac[2][2]);

    for (int j = 0; j < nbNodes; j++){
      for (int k = 0; k <= j; k++){
        m(j, k) += 1.0*dot(crossprod(Grads[j],Grads[k]),N) * weight * detJ * _diff;
      }
    }
  }

  for (int j = 0; j < nbNodes; j++)
    for (int k = 0; k < j; k++)
      m(k, j) = -1.0*m(j, k);
}

