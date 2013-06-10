// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "MLine.h"
#include "nodalBasis.h"
#include "BasisFactory.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"

const nodalBasis* MLine::getFunctionSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;
  
  switch (order) {
  case 0: return BasisFactory::getNodalBasis(MSH_LIN_1);
  case 1: return BasisFactory::getNodalBasis(MSH_LIN_2);
  case 2: return BasisFactory::getNodalBasis(MSH_LIN_3);
  case 3: return BasisFactory::getNodalBasis(MSH_LIN_4);
  case 4: return BasisFactory::getNodalBasis(MSH_LIN_5);
  case 5: return BasisFactory::getNodalBasis(MSH_LIN_6);
  case 6: return BasisFactory::getNodalBasis(MSH_LIN_7);
  case 7: return BasisFactory::getNodalBasis(MSH_LIN_8);
  case 8: return BasisFactory::getNodalBasis(MSH_LIN_9);
  case 9: return BasisFactory::getNodalBasis(MSH_LIN_10);
  case 10: return BasisFactory::getNodalBasis(MSH_LIN_11);
  default: Msg::Error("Order %d line function space not implemented", order);
  }
  return 0;
}

const JacobianBasis* MLine::getJacobianFuncSpace(int o) const
{
  int order = (o == -1) ? getPolynomialOrder() : o;
  
  switch (order) {
  case 1: return BasisFactory::getJacobianBasis(MSH_LIN_2);
  case 2: return BasisFactory::getJacobianBasis(MSH_LIN_3);
  case 3: return BasisFactory::getJacobianBasis(MSH_LIN_4);
  case 4: return BasisFactory::getJacobianBasis(MSH_LIN_5);
  case 5: return BasisFactory::getJacobianBasis(MSH_LIN_6);
  case 6: return BasisFactory::getJacobianBasis(MSH_LIN_7);
  case 7: return BasisFactory::getJacobianBasis(MSH_LIN_8);
  case 8: return BasisFactory::getJacobianBasis(MSH_LIN_9);
  case 9: return BasisFactory::getJacobianBasis(MSH_LIN_10);
  case 10: return BasisFactory::getJacobianBasis(MSH_LIN_11);
  default: Msg::Error("Order %d line function space not implemented", order);
  }
  return 0;
}

void MLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts = getNGQLPts(pOrder);
  *pts = getGQLPts(pOrder);
}

double MLine::getInnerRadius()
{
  return _v[0]->distance(_v[1]) * .5;
}

double MLine::getLength()
{
  return _v[0]->distance(_v[1]);
}

double MLine::getVolume()
{
  return getLength();
}

int MLine3::getNumEdgesRep() 
{
  return  CTX::instance()->mesh.numSubEdges;
}

void MLine3::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  int numSubEdges = CTX::instance()->mesh.numSubEdges;
  SPoint3 pnt1, pnt2;
  pnt(-1. + 2 * (double)num / numSubEdges, 0., 0., pnt1);
  pnt(-1. + 2 * (double)(num + 1) / numSubEdges, 0., 0, pnt2);
  x[0] = pnt1.x(); x[1] = pnt2.x();
  y[0] = pnt1.y(); y[1] = pnt2.y();
  z[0] = pnt1.z(); z[1] = pnt2.z();
  n[0] = n[1] = MEdge(_v[0], _v[1]).normal();
}

int MLineN::getNumEdgesRep() 
{
  return  CTX::instance()->mesh.numSubEdges;
}

void MLineN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  int numSubEdges = CTX::instance()->mesh.numSubEdges;
  SPoint3 pnt1, pnt2;
  pnt(-1. + 2 * (double)num / numSubEdges, 0., 0., pnt1);
  pnt(-1. + 2 * (double)(num + 1) / numSubEdges, 0., 0, pnt2);
  x[0] = pnt1.x(); x[1] = pnt2.x();
  y[0] = pnt1.y(); y[1] = pnt2.y();
  z[0] = pnt1.z(); z[1] = pnt2.z();
  n[0] = n[1] = MEdge(_v[0], _v[1]).normal();
}
