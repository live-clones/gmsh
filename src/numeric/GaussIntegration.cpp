// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshDefines.h"
#include "GaussIntegration.h"
#include "fullMatrix.h"

static void pts2fullMatrix(int npts, IntPt *pts, fullMatrix<double> &pMatrix,
                           fullVector<double> &wMatrix)
{
  pMatrix.resize(npts, 3);
  wMatrix.resize(npts, 1);
  for(int i = 0; i < npts; i++) {
    pMatrix(i, 0) = pts[i].pt[0];
    pMatrix(i, 1) = pts[i].pt[1];
    pMatrix(i, 2) = pts[i].pt[2];
    wMatrix(i) = pts[i].weight;
  }
}

void gaussIntegration::getTriangle(int order, fullMatrix<double> &pts,
                                   fullVector<double> &weights)
{
  pts2fullMatrix(getNGQTPts(order), getGQTPts(order), pts, weights);
}

void gaussIntegration::getLine(int order, fullMatrix<double> &pts,
                               fullVector<double> &weights)
{
  pts2fullMatrix(getNGQLPts(order), getGQLPts(order), pts, weights);
}

void gaussIntegration::getQuad(int order, fullMatrix<double> &pts,
                               fullVector<double> &weights)
{
  pts2fullMatrix(getNGQQPts(order), getGQQPts(order), pts, weights);
}

void gaussIntegration::getTetrahedron(int order, fullMatrix<double> &pts,
                                      fullVector<double> &weights)
{
  pts2fullMatrix(getNGQTetPts(order), getGQTetPts(order), pts, weights);
}

void gaussIntegration::getHexahedron(int order, fullMatrix<double> &pts,
                                     fullVector<double> &weights)
{
  pts2fullMatrix(getNGQHPts(order), getGQHPts(order), pts, weights);
}

void gaussIntegration::getPrism(int order, fullMatrix<double> &pts,
                                fullVector<double> &weights)
{
  pts2fullMatrix(getNGQPriPts(order), getGQPriPts(order), pts, weights);
}

void gaussIntegration::getPyramid(int order, fullMatrix<double> &pts,
                                  fullVector<double> &weights)
{
  pts2fullMatrix(getNGQPyrPts(order), getGQPyrPts(order), pts, weights);
}

void gaussIntegration::get(int elementType, int order, fullMatrix<double> &pts,
                           fullVector<double> &weights, bool forceTensorRule)
{
  switch(elementType) {
  case TYPE_TRI:
    pts2fullMatrix(getNGQTPts(order, forceTensorRule),
                   getGQTPts(order, forceTensorRule), pts, weights);
    break;
  case TYPE_LIN:
    pts2fullMatrix(getNGQLPts(order), getGQLPts(order), pts, weights);
    break;
  case TYPE_QUA:
    pts2fullMatrix(getNGQQPts(order, forceTensorRule),
                   getGQQPts(order, forceTensorRule), pts, weights);
    break;
  case TYPE_TET:
    pts2fullMatrix(getNGQTetPts(order, forceTensorRule),
                   getGQTetPts(order, forceTensorRule), pts, weights);
    break;
  case TYPE_HEX:
    pts2fullMatrix(getNGQHPts(order, forceTensorRule),
                   getGQHPts(order, forceTensorRule), pts, weights);
    break;
  case TYPE_PRI:
    pts2fullMatrix(getNGQPriPts(order, forceTensorRule),
                   getGQPriPts(order, forceTensorRule), pts, weights);
    break;
  case TYPE_PYR:
    pts2fullMatrix(getNGQPyrPts(order),
                   getGQPyrPts(order), pts, weights);
    break;
  case TYPE_PNT:
    weights.resize(1, 1);
    weights(0) = 1.;
    pts.resize(1, 3);
    break;
  default: Msg::Error("No integration rules defined for type %i", elementType);
  }
}
