//
// C++ Interface: terms
//
// Description: Class of interface element used for DG
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
// Has to be merge with interface element defined in dg project HOW ??
#include "MInterfaceElement.h"
#include "quadratureRules.h"
#include "MLine.h"
double MInterfaceElement::characSize(MElement *e)
{
  // Compute the area of the element
  GaussQuadrature Integ_Bulk(GaussQuadrature::Grad); // which rule used for now not the same as the call function ??
  IntPt *GP;
  double perimeter = 0., Area = 0.;
  double jac[3][3];
  int npts=Integ_Bulk.getIntPoints(e,&GP);
  // Area
  for( int i = 0; i < npts; i++){
    // Coordonate of Gauss' point i
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = e->getJacobian(u, v, w, jac); // Or compute jacobian with crossprod(phi0[0],phi0[1]) ??
    Area += weight * detJ;
  }
  // perimeter
  int nside = e->getNumEdges();
  GaussQuadrature Integ_Bound(GaussQuadrature::ValVal);
  std::vector<MVertex*> vver;
  for(int i=0;i<nside;i++){
    IntPt *GPb;
    e->getEdgeVertices(i,vver);
    MLineN mlin = MLineN(vver);
    int npts = Integ_Bound.getIntPoints(&mlin,&GPb);
    for(int j=0;j<npts; j++){
      const double u = GPb[j].pt[0]; const double v = GPb[j].pt[1]; const double w = GPb[j].pt[2];
      const double weight = GPb[j].weight; const double detJ = mlin.getJacobian(u, v, w, jac);
      perimeter +=weight*detJ;
    }
    vver.clear();
  }

  return Area/perimeter;
}
