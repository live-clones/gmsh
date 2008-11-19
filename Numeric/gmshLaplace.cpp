// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "gmshLaplace.h"

extern double inv3x3 (double a[3][3], double b[3][3]);

void gmshLaplaceTerm::elementMatrix(MElement *e, Double_Matrix & m) const
{
  int nbNodes = e->getNumVertices();
  int integrationOrder = 2*(e->getPolynomialOrder()-1);
  int npts;
  IntPt *GP;
  double jac    [3][3];
  double invjac [3][3];
  double Grads[256][3],grads[256][3];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  
  m.set_all(0.0);

  for (int i=0;i<npts;i++){
    const double u      = GP[i].pt[0];
    const double v      = GP[i].pt[1];
    const double w      = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian (u,v,w,jac);   
    inv3x3 ( jac, invjac) ;
    e->getGradShapeFunctions (u,v,w,grads);
    for (int j=0;j<nbNodes;j++){
      Grads[j][0] = invjac[0][0] * grads[j][0] + invjac[0][1] * grads[j][1] + invjac[0][2] * grads[j][2];
      Grads[j][1] = invjac[1][0] * grads[j][0] + invjac[1][1] * grads[j][1] + invjac[1][2] * grads[j][2];
      Grads[j][2] = invjac[2][0] * grads[j][0] + invjac[2][1] * grads[j][1] + invjac[2][2] * grads[j][2];
    }
    for (int j=0;j<nbNodes;j++){
      for (int k=0;k<=j;k++){
	m(j,k) += (Grads[j][0]*Grads[k][0]+
		   Grads[j][1]*Grads[k][1]+
		   Grads[j][2]*Grads[k][2]) * weight * detJ * _diffusivity*0.5;
      }
    }
  }

  for (int j=0;j<nbNodes;j++)
    for (int k=0;k<j;k++)
	m(k,j) = m(j,k);

} 

