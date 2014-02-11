// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
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

const JacobianBasis* MLine::getJacobianFuncSpace(int order) const
{
  if (order == -1) return BasisFactory::getJacobianBasis(getTypeForMSH());

  int tag = ElementType::getTag(TYPE_LIN, order);
  return tag ? BasisFactory::getJacobianBasis(tag) : NULL;
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

int MLine3::getNumEdgesRep(bool curved)
{
  return curved ? CTX::instance()->mesh.numSubEdges : 1;
}

void MLine3::getEdgeRep(bool curved, int num, double *x, double *y, double *z, SVector3 *n)
{
  if (curved) {
    int numSubEdges = CTX::instance()->mesh.numSubEdges;
    SPoint3 pnt1, pnt2;
    pnt(-1. + 2 * (double)num / numSubEdges, 0., 0., pnt1);
    pnt(-1. + 2 * (double)(num + 1) / numSubEdges, 0., 0, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    n[0] = n[1] = MEdge(_v[0], _v[1]).normal();
  }
  else MLine::getEdgeRep(false, num, x, y, z, n);
}

int MLineN::getNumEdgesRep(bool curved)
{
  return curved ? CTX::instance()->mesh.numSubEdges : 1;
}

void MLineN::getEdgeRep(bool curved, int num, double *x, double *y, double *z, SVector3 *n)
{
  if (curved) {
    int numSubEdges = CTX::instance()->mesh.numSubEdges;
    SPoint3 pnt1, pnt2;
    pnt(-1. + 2 * (double)num / numSubEdges, 0., 0., pnt1);
    pnt(-1. + 2 * (double)(num + 1) / numSubEdges, 0., 0, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    n[0] = n[1] = MEdge(_v[0], _v[1]).normal();
  }
  else MLine::getEdgeRep(false, num, x, y, z, n);
}
