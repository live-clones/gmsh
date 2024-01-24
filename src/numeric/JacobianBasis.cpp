// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "JacobianBasis.h"
#include "pointsGenerators.h"
#include "nodalBasis.h"
#include "BasisFactory.h"
#include "Numeric.h"
#include <cmath>

namespace {

  template <class T>
  void calcMapFromIdealElement(int type, T &dSVec_dX, T &dSVec_dY, T &dSVec_dZ)
  {
    // 2D scaling
    switch(type) {
    case TYPE_QUA:
    case TYPE_HEX:
    case TYPE_PYR: { // Quad, hex, pyramid -> square with side of length 1
      dSVec_dX.scale(2.);
      dSVec_dY.scale(2.);
      break;
    }
    default: { // Tri, tet, prism: equilateral tri with side of length 1
      static const double cTri[2] = {-1. / std::sqrt(3.), 2. / std::sqrt(3.)};
      dSVec_dY.scale(cTri[1]);
      dSVec_dY.axpy(dSVec_dX, cTri[0]);
      break;
    }
    }

    // 3D scaling
    switch(type) {
    case TYPE_HEX:
    case TYPE_PRI: { // Hex, prism -> side of length 1 in z
      dSVec_dZ.scale(2.);
      break;
    }
    case TYPE_PYR: { // Pyramid -> height sqrt(2.)/2
      static const double cPyr = sqrt(2.);
      dSVec_dZ.scale(cPyr);
      break;
    }
    case TYPE_TET: { // Tet: take into account (x, y) scaling to obtain regular
                     // tet
      static const double cTet[3] = {-3. / 2 / std::sqrt(6.),
                                     -1. / 2 / std::sqrt(2.), std::sqrt(1.5)};
      dSVec_dZ.scale(cTet[2]);
      dSVec_dZ.axpy(dSVec_dX, cTet[0]);
      dSVec_dZ.axpy(dSVec_dY, cTet[1]);
      break;
    }
    }
  }

  // Compute the determinant of a 3x3 matrix
  inline double calcDet3D(double M11, double M12, double M13, double M21,
                          double M22, double M23, double M31, double M32,
                          double M33)
  {
    return M11 * (M22 * M33 - M23 * M32) - M12 * (M21 * M33 - M23 * M31) +
           M13 * (M21 * M32 - M22 * M31);
  }

  // Compute (signed) Jacobian determinant, and its partial derivative w.r.t.
  // nodes coordinates, at sampling point 'i' of a 1D element (for which columns
  // 2 and 3 of the Jacobian matrix are constant).
  inline void calcJDJ1D(double dxdX, double dxdY, double dxdZ, double dydX,
                        double dydY, double dydZ, double dzdX, double dzdY,
                        double dzdZ, int i, int numMapNodes,
                        const fullMatrix<double> &dShapeMat_dX,
                        fullMatrix<double> &JDJ)
  {
    for(int j = 0; j < numMapNodes; j++) {
      const double &dPhidX = dShapeMat_dX(i, j);
      JDJ(i, j) = dPhidX * (dydY * dzdZ - dzdY * dydZ);
      JDJ(i, j + numMapNodes) = dPhidX * (dzdY * dxdZ - dxdY * dzdZ);
      JDJ(i, j + 2 * numMapNodes) = dPhidX * (dxdY * dydZ - dydY * dxdZ);
    }
    JDJ(i, 3 * numMapNodes) =
      calcDet3D(dxdX, dxdY, dxdZ, dydX, dydY, dydZ, dzdX, dzdY, dzdZ);
  }

  // Compute (signed) Jacobian determinant, and its partial derivative w.r.t.
  // nodes coordinates, at sampling point 'i' of a 2D element (for which column
  // 3 of the Jacobian matrix is constant).
  inline void calcJDJ2D(double dxdX, double dxdY, double dxdZ, double dydX,
                        double dydY, double dydZ, double dzdX, double dzdY,
                        double dzdZ, int i, int numMapNodes,
                        const fullMatrix<double> &dShapeMat_dX,
                        const fullMatrix<double> &dShapeMat_dY,
                        fullMatrix<double> &JDJ)
  {
    for(int j = 0; j < numMapNodes; j++) {
      const double &dPhidX = dShapeMat_dX(i, j);
      const double &dPhidY = dShapeMat_dY(i, j);
      JDJ(i, j) = dPhidX * (dydY * dzdZ - dzdY * dydZ) +
                  dPhidY * (dzdX * dydZ - dydX * dzdZ);
      JDJ(i, j + numMapNodes) = dPhidX * (dzdY * dxdZ - dxdY * dzdZ) +
                                dPhidY * (dxdX * dzdZ - dzdX * dxdZ);
      JDJ(i, j + 2 * numMapNodes) = dPhidX * (dxdY * dydZ - dydY * dxdZ) +
                                    dPhidY * (dydX * dxdZ - dxdX * dydZ);
    }
    JDJ(i, 3 * numMapNodes) =
      calcDet3D(dxdX, dxdY, dxdZ, dydX, dydY, dydZ, dzdX, dzdY, dzdZ);
  }

  // Compute (signed) Jacobian determinant, and its partial derivative w.r.t.
  // nodes coordinates, at sampling point 'i' of a 3D element
  inline void calcJDJ3D(double dxdX, double dxdY, double dxdZ, double dydX,
                        double dydY, double dydZ, double dzdX, double dzdY,
                        double dzdZ, int i, int numMapNodes,
                        const fullMatrix<double> &dShapeMat_dX,
                        const fullMatrix<double> &dShapeMat_dY,
                        const fullMatrix<double> &dShapeMat_dZ,
                        fullMatrix<double> &JDJ)
  {
    for(int j = 0; j < numMapNodes; j++) {
      const double &dPhidX = dShapeMat_dX(i, j);
      const double &dPhidY = dShapeMat_dY(i, j);
      const double &dPhidZ = dShapeMat_dZ(i, j);
      JDJ(i, j) = dPhidX * (dydY * dzdZ - dzdY * dydZ) +
                  dPhidY * (dzdX * dydZ - dydX * dzdZ) +
                  dPhidZ * (dydX * dzdY - dzdX * dydY);
      JDJ(i, j + numMapNodes) = dPhidX * (dzdY * dxdZ - dxdY * dzdZ) +
                                dPhidY * (dxdX * dzdZ - dzdX * dxdZ) +
                                dPhidZ * (dzdX * dxdY - dxdX * dzdY);
      JDJ(i, j + 2 * numMapNodes) = dPhidX * (dxdY * dydZ - dydY * dxdZ) +
                                    dPhidY * (dydX * dxdZ - dxdX * dydZ) +
                                    dPhidZ * (dxdX * dydY - dydX * dxdY);
    }
    JDJ(i, 3 * numMapNodes) =
      calcDet3D(dxdX, dxdY, dxdZ, dydX, dydY, dydZ, dzdX, dzdY, dzdZ);
  }

} // namespace

// GradientBasis contains the information for computing the partial
// derivatives of the mapping components w.r.t. to each reference coordinate
// for a given element type.
// Those partial derivatives are the components of the Jacobian matrix,
// and the gradients are the rows of the Jacobian matrix.
GradientBasis::GradientBasis(int elementTag, FuncSpaceData fsdata)
  : _elementTag(elementTag), _data(fsdata)
{
  // Matrix dShapeMat_dX, when multiplied by Lagrange coefficients
  // (i.e. node coordinates), gives the derivative of the mapping
  // w.r.t. the first reference coordinate at some sampling points.
  // Those sampling points is determined by 'fsdata'.
  // The ordering of the sampling points is "ordered" (see pointsGenerator.cpp)
  // and is thus different from the Gmsh ordering convention. This order is
  // useful for efficiently converting Lagrange to Bezier coefficients.
  fullMatrix<double> samplingPoints;
  gmshGenerateOrderedPoints(fsdata, samplingPoints);
  const int numSampPnts = samplingPoints.size1();

  // Store partial derivatives of shape functions at sampling points
  fullMatrix<double> allDPsi;
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(_elementTag);
  mapBasis->df(samplingPoints, allDPsi);
  const int numMapNodes = allDPsi.size2();

  dShapeMat_dX.resize(numSampPnts, numMapNodes);
  dShapeMat_dY.resize(numSampPnts, numMapNodes);
  dShapeMat_dZ.resize(numSampPnts, numMapNodes);
  for(int i = 0; i < numSampPnts; i++) {
    for(int j = 0; j < numMapNodes; j++) {
      dShapeMat_dX(i, j) = allDPsi(3 * i + 0, j);
      dShapeMat_dY(i, j) = allDPsi(3 * i + 1, j);
      dShapeMat_dZ(i, j) = allDPsi(3 * i + 2, j);
    }
  }

  dShapeIdealMat_dX = dShapeMat_dX;
  dShapeIdealMat_dY = dShapeMat_dY;
  dShapeIdealMat_dZ = dShapeMat_dZ;
  mapFromIdealElement(_data.getType(), dShapeIdealMat_dX, dShapeIdealMat_dY,
                      dShapeIdealMat_dZ);
}

void GradientBasis::getIdealGradientsFromNodes(
  const fullMatrix<double> &nodesCoord, fullMatrix<double> *dxyzdX,
  fullMatrix<double> *dxyzdY, fullMatrix<double> *dxyzdZ) const
{
  if(dxyzdX) dShapeIdealMat_dX.mult(nodesCoord, *dxyzdX);
  if(dxyzdY) dShapeIdealMat_dY.mult(nodesCoord, *dxyzdY);
  if(dxyzdZ) dShapeIdealMat_dZ.mult(nodesCoord, *dxyzdZ);
}

void GradientBasis::getGradientsFromNodes(const fullMatrix<double> &nodesCoord,
                                          fullMatrix<double> *dxyzdX,
                                          fullMatrix<double> *dxyzdY,
                                          fullMatrix<double> *dxyzdZ) const
{
  if(dxyzdX) dShapeMat_dX.mult(nodesCoord, *dxyzdX);
  if(dxyzdY) dShapeMat_dY.mult(nodesCoord, *dxyzdY);
  if(dxyzdZ) dShapeMat_dZ.mult(nodesCoord, *dxyzdZ);
}

void GradientBasis::getAllGradientsFromNodes(
  const fullMatrix<double> &nodesCoord, fullMatrix<double> &dxyzdXYZ) const
{
  fullMatrix<double> prox;
  prox.setAsProxy(dxyzdXYZ, 0, 3);
  dShapeMat_dX.mult(nodesCoord, prox);

  prox.setAsProxy(dxyzdXYZ, 3, 3);
  dShapeMat_dY.mult(nodesCoord, prox);

  prox.setAsProxy(dxyzdXYZ, 6, 3);
  dShapeMat_dZ.mult(nodesCoord, prox);
}

void GradientBasis::getAllIdealGradientsFromNodes(
  const fullMatrix<double> &nodesCoord, fullMatrix<double> &dxyzdXYZ) const
{
  fullMatrix<double> prox;
  prox.setAsProxy(dxyzdXYZ, 0, 3);
  dShapeIdealMat_dX.mult(nodesCoord, prox);

  prox.setAsProxy(dxyzdXYZ, 3, 3);
  dShapeIdealMat_dY.mult(nodesCoord, prox);

  prox.setAsProxy(dxyzdXYZ, 6, 3);
  dShapeIdealMat_dZ.mult(nodesCoord, prox);
}

void GradientBasis::mapFromIdealElement(int type, fullMatrix<double> &dSMat_dX,
                                        fullMatrix<double> &dSMat_dY,
                                        fullMatrix<double> &dSMat_dZ)
{
  calcMapFromIdealElement(type, dSMat_dX, dSMat_dY, dSMat_dZ);
}

void GradientBasis::mapFromIdealElement(int type, fullVector<double> &dSVec_dX,
                                        fullVector<double> &dSVec_dY,
                                        fullVector<double> &dSVec_dZ)
{
  calcMapFromIdealElement(type, dSVec_dX, dSVec_dY, dSVec_dZ);
}

void GradientBasis::mapFromIdealElement(int type, double jac[3][3])
{
  fullMatrix<double> dxyzdX(jac[0], 1, 3), dxyzdY(jac[1], 1, 3),
    dxyzdZ(jac[2], 1, 3);
  mapFromIdealElement(type, dxyzdX, dxyzdY, dxyzdZ);
}

JacobianBasis::JacobianBasis(int elementTag, FuncSpaceData data)
  : _elementTag(elementTag), _data(data), _dim(data.getDimension())
{
  const int parentType = data.getType();
  const int primJacobianOrder = jacobianOrder(parentType, 1);

  fullMatrix<double> samplingPoints;
  gmshGeneratePoints(data, samplingPoints);
  numSamplingPnts = samplingPoints.size1();

  // Store shape function gradients of mapping at Jacobian nodes
  _gradBasis = BasisFactory::getGradientBasis(elementTag, data);

  // Compute matrix for lifting from primary Jacobian basis to Jacobian basis
  int primJacType = ElementType::getType(parentType, primJacobianOrder, false);
  const nodalBasis *primJacBasis = BasisFactory::getNodalBasis(primJacType);
  numPrimSamplingPnts = primJacBasis->getNumShapeFunctions();

  matrixPrimJac2Jac.resize(numSamplingPnts, numPrimSamplingPnts);
  primJacBasis->f(samplingPoints, matrixPrimJac2Jac);

  // Compute shape function gradients of primary mapping at barycenter, in order
  // to compute normal to straight element
  const int primMapType = ElementType::getType(parentType, 1, false);
  const nodalBasis *primMapBasis = BasisFactory::getNodalBasis(primMapType);
  numPrimMapNodes = primMapBasis->getNumShapeFunctions();

  double xBar = 0., yBar = 0., zBar = 0.;
  double barycenter[3] = {0., 0., 0.};
  for(int i = 0; i < numPrimMapNodes; i++) {
    for(int j = 0; j < primMapBasis->points.size2(); ++j) {
      barycenter[j] += primMapBasis->points(i, j);
    }
  }
  barycenter[0] /= numPrimMapNodes;
  barycenter[1] /= numPrimMapNodes;
  barycenter[2] /= numPrimMapNodes;

  double(*barDPsi)[3] = new double[numPrimMapNodes][3];
  primMapBasis->df(xBar, yBar, zBar, barDPsi);

  dPrimBaryShape_dX.resize(numPrimMapNodes);
  dPrimBaryShape_dY.resize(numPrimMapNodes);
  dPrimBaryShape_dZ.resize(numPrimMapNodes);
  for(int j = 0; j < numPrimMapNodes; j++) {
    dPrimBaryShape_dX(j) = barDPsi[j][0];
    dPrimBaryShape_dY(j) = barDPsi[j][1];
    dPrimBaryShape_dZ(j) = barDPsi[j][2];
  }

  dPrimBaryIdealShape_dX = dPrimBaryShape_dX;
  dPrimBaryIdealShape_dY = dPrimBaryShape_dY;
  dPrimBaryIdealShape_dZ = dPrimBaryShape_dZ;
  _gradBasis->mapFromIdealElement(
    dPrimBaryIdealShape_dX, dPrimBaryIdealShape_dY, dPrimBaryIdealShape_dZ);

  delete[] barDPsi;

  // Compute "fast" Jacobian evaluation matrices (at 1st order nodes +
  // barycenter)
  numSamplingPntsFast = numPrimMapNodes + 1;
  fullMatrix<double> lagPointsFast(numSamplingPntsFast, 3); // Sampling points
  lagPointsFast.copy(primMapBasis->points, 0, numPrimMapNodes, 0,
                     primMapBasis->points.size2(), 0, 0); // 1st order nodes
  lagPointsFast(numPrimMapNodes, 0) = barycenter[0]; // Last point = barycenter
  lagPointsFast(numPrimMapNodes, 1) = barycenter[1];
  lagPointsFast(numPrimMapNodes, 2) = barycenter[2];

  fullMatrix<double> allDPsiFast;
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(_elementTag);
  mapBasis->df(lagPointsFast, allDPsiFast);
  numMapNodes = mapBasis->getNumShapeFunctions();

  dFastShapeMat_dX.resize(numSamplingPntsFast, numMapNodes);
  dFastShapeMat_dY.resize(numSamplingPntsFast, numMapNodes);
  dFastShapeMat_dZ.resize(numSamplingPntsFast, numMapNodes);
  for(int i = 0; i < numSamplingPntsFast; i++) {
    for(int j = 0; j < numMapNodes; j++) {
      dFastShapeMat_dX(i, j) = allDPsiFast(3 * i + 0, j);
      dFastShapeMat_dY(i, j) = allDPsiFast(3 * i + 1, j);
      dFastShapeMat_dZ(i, j) = allDPsiFast(3 * i + 2, j);
    }
  }
}

// Computes (unit) normals to straight line element at barycenter (with norm of
// gradient as return value)
double JacobianBasis::getPrimNormals1D(const fullMatrix<double> &nodesXYZ,
                                       fullMatrix<double> &result) const
{
  fullVector<double> dxyzdXbar(3);
  for(int j = 0; j < numPrimMapNodes; j++) {
    dxyzdXbar(0) += dPrimBaryShape_dX(j) * nodesXYZ(j, 0);
    dxyzdXbar(1) += dPrimBaryShape_dX(j) * nodesXYZ(j, 1);
    dxyzdXbar(2) += dPrimBaryShape_dX(j) * nodesXYZ(j, 2);
  }

  if((fabs(dxyzdXbar(0)) >= fabs(dxyzdXbar(1)) &&
      fabs(dxyzdXbar(0)) >= fabs(dxyzdXbar(2))) ||
     (fabs(dxyzdXbar(1)) >= fabs(dxyzdXbar(0)) &&
      fabs(dxyzdXbar(1)) >= fabs(dxyzdXbar(2)))) {
    result(0, 0) = dxyzdXbar(1);
    result(0, 1) = -dxyzdXbar(0);
    result(0, 2) = 0.;
  }
  else {
    result(0, 0) = 0.;
    result(0, 1) = dxyzdXbar(2);
    result(0, 2) = -dxyzdXbar(1);
  }
  const double norm0 =
    sqrt(result(0, 0) * result(0, 0) + result(0, 1) * result(0, 1) +
         result(0, 2) * result(0, 2));
  result(0, 0) /= norm0;
  result(0, 1) /= norm0;
  result(0, 2) /= norm0;

  result(1, 2) = dxyzdXbar(0) * result(0, 1) - dxyzdXbar(1) * result(0, 0);
  result(1, 1) = -dxyzdXbar(0) * result(0, 2) + dxyzdXbar(2) * result(0, 0);
  result(1, 0) = dxyzdXbar(1) * result(0, 2) - dxyzdXbar(2) * result(0, 1);
  const double norm1 =
    sqrt(result(1, 0) * result(1, 0) + result(1, 1) * result(1, 1) +
         result(1, 2) * result(1, 2));
  result(1, 0) /= norm1;
  result(1, 1) /= norm1;
  result(1, 2) /= norm1;

  return sqrt(dxyzdXbar(0) * dxyzdXbar(0) + dxyzdXbar(1) * dxyzdXbar(1) +
              dxyzdXbar(2) * dxyzdXbar(2));
}

// Computes (unit) normal to straight surface element at barycenter (with norm
// as return value)
double JacobianBasis::getPrimNormal2D(const fullMatrix<double> &nodesXYZ,
                                      fullMatrix<double> &result,
                                      bool ideal) const
{
  const fullVector<double> &gSX =
    ideal ? dPrimBaryIdealShape_dX : dPrimBaryShape_dX;
  const fullVector<double> &gSY =
    ideal ? dPrimBaryIdealShape_dY : dPrimBaryShape_dY;
  fullMatrix<double> dxyzdX(1, 3), dxyzdY(1, 3);
  for(int j = 0; j < numPrimMapNodes; j++) {
    dxyzdX(0, 0) += gSX(j) * nodesXYZ(j, 0);
    dxyzdX(0, 1) += gSX(j) * nodesXYZ(j, 1);
    dxyzdX(0, 2) += gSX(j) * nodesXYZ(j, 2);
    dxyzdY(0, 0) += gSY(j) * nodesXYZ(j, 0);
    dxyzdY(0, 1) += gSY(j) * nodesXYZ(j, 1);
    dxyzdY(0, 2) += gSY(j) * nodesXYZ(j, 2);
  }

  result(0, 2) = dxyzdX(0, 0) * dxyzdY(0, 1) - dxyzdX(0, 1) * dxyzdY(0, 0);
  result(0, 1) = -dxyzdX(0, 0) * dxyzdY(0, 2) + dxyzdX(0, 2) * dxyzdY(0, 0);
  result(0, 0) = dxyzdX(0, 1) * dxyzdY(0, 2) - dxyzdX(0, 2) * dxyzdY(0, 1);
  double norm0 =
    sqrt(result(0, 0) * result(0, 0) + result(0, 1) * result(0, 1) +
         result(0, 2) * result(0, 2));
  const double invNorm0 = 1. / norm0;
  result(0, 0) *= invNorm0;
  result(0, 1) *= invNorm0;
  result(0, 2) *= invNorm0;

  return norm0;
}

// Returns absolute value of Jacobian of straight volume element at barycenter
double JacobianBasis::getPrimJac3D(const fullMatrix<double> &nodesXYZ,
                                   bool ideal) const
{
  const fullVector<double> &gSX =
    ideal ? dPrimBaryIdealShape_dX : dPrimBaryShape_dX;
  const fullVector<double> &gSY =
    ideal ? dPrimBaryIdealShape_dY : dPrimBaryShape_dY;
  const fullVector<double> &gSZ =
    ideal ? dPrimBaryIdealShape_dZ : dPrimBaryShape_dZ;
  fullMatrix<double> dxyzdX(1, 3), dxyzdY(1, 3), dxyzdZ(1, 3);
  for(int j = 0; j < numPrimMapNodes; j++) {
    dxyzdX(0, 0) += gSX(j) * nodesXYZ(j, 0);
    dxyzdX(0, 1) += gSX(j) * nodesXYZ(j, 1);
    dxyzdX(0, 2) += gSX(j) * nodesXYZ(j, 2);
    dxyzdY(0, 0) += gSY(j) * nodesXYZ(j, 0);
    dxyzdY(0, 1) += gSY(j) * nodesXYZ(j, 1);
    dxyzdY(0, 2) += gSY(j) * nodesXYZ(j, 2);
    dxyzdZ(0, 0) += gSZ(j) * nodesXYZ(j, 0);
    dxyzdZ(0, 1) += gSZ(j) * nodesXYZ(j, 1);
    dxyzdZ(0, 2) += gSZ(j) * nodesXYZ(j, 2);
  }
  double dJ = fabs(calcDet3D(dxyzdX(0, 0), dxyzdY(0, 0), dxyzdZ(0, 0),
                             dxyzdX(0, 1), dxyzdY(0, 1), dxyzdZ(0, 1),
                             dxyzdX(0, 2), dxyzdY(0, 2), dxyzdZ(0, 2)));
  return dJ;
}

// Calculate (signed, possibly scaled) Jacobian for one element, with normal
// vectors to straight element for regularization. Evaluation points depend on
// the given matrices for shape function gradients.
void JacobianBasis::getJacobianGeneral(
  int nSamplingPnts, const fullMatrix<double> &dSMat_dX,
  const fullMatrix<double> &dSMat_dY, const fullMatrix<double> &dSMat_dZ,
  const fullMatrix<double> &nodesXYZ, bool idealNorm, bool scaling,
  fullVector<double> &jacobian, const fullMatrix<double> *geomNormals) const
{
  switch(_dim) {
  case 0: {
    for(int i = 0; i < nSamplingPnts; i++) jacobian(i) = 1.;
  } break;
  case 1: {
    fullMatrix<double> normals(2, 3);
    const double invScale = getPrimNormals1D(nodesXYZ, normals);
    if(geomNormals) normals.setAll(*geomNormals);
    if(scaling) {
      if(invScale == 0) {
        for(int i = 0; i < nSamplingPnts; i++) jacobian(i) = 0;
        return;
      }
      const double scale = 1. / invScale;
      // Faster to scale 1 normal than afterwards
      normals(0, 0) *= scale;
      normals(0, 1) *= scale;
      normals(0, 2) *= scale;
    }
    fullMatrix<double> dxyzdX(nSamplingPnts, 3);
    dSMat_dX.mult(nodesXYZ, dxyzdX);
    for(int i = 0; i < nSamplingPnts; i++) {
      const double &dxdX = dxyzdX(i, 0), &dydX = dxyzdX(i, 1),
                   &dzdX = dxyzdX(i, 2);
      const double &dxdY = normals(0, 0), &dydY = normals(0, 1),
                   &dzdY = normals(0, 2);
      const double &dxdZ = normals(1, 0), &dydZ = normals(1, 1),
                   &dzdZ = normals(1, 2);
      jacobian(i) =
        calcDet3D(dxdX, dxdY, dxdZ, dydX, dydY, dydZ, dzdX, dzdY, dzdZ);
    }
  } break;
  case 2: {
    fullMatrix<double> normal(1, 3);
    const double invScale = getPrimNormal2D(nodesXYZ, normal, idealNorm);
    if(geomNormals) normal.setAll(*geomNormals);
    if(scaling) {
      if(invScale == 0) {
        for(int i = 0; i < nSamplingPnts; i++) jacobian(i) = 0;
        return;
      }
      const double scale = 1. / invScale;
      // Faster to scale normal than afterwards
      normal(0, 0) *= scale;
      normal(0, 1) *= scale;
      normal(0, 2) *= scale;
    }
    fullMatrix<double> dxyzdX(nSamplingPnts, 3), dxyzdY(nSamplingPnts, 3);
    dSMat_dX.mult(nodesXYZ, dxyzdX);
    dSMat_dY.mult(nodesXYZ, dxyzdY);
    for(int i = 0; i < nSamplingPnts; i++) {
      const double &dxdX = dxyzdX(i, 0), &dydX = dxyzdX(i, 1),
                   &dzdX = dxyzdX(i, 2);
      const double &dxdY = dxyzdY(i, 0), &dydY = dxyzdY(i, 1),
                   &dzdY = dxyzdY(i, 2);
      const double &dxdZ = normal(0, 0), &dydZ = normal(0, 1),
                   &dzdZ = normal(0, 2);
      jacobian(i) =
        calcDet3D(dxdX, dxdY, dxdZ, dydX, dydY, dydZ, dzdX, dzdY, dzdZ);
    }
  } break;
  case 3: {
    fullMatrix<double> dum;
    fullMatrix<double> dxyzdX(nSamplingPnts, 3), dxyzdY(nSamplingPnts, 3),
      dxyzdZ(nSamplingPnts, 3);
    dSMat_dX.mult(nodesXYZ, dxyzdX);
    dSMat_dY.mult(nodesXYZ, dxyzdY);
    dSMat_dZ.mult(nodesXYZ, dxyzdZ);
    for(int i = 0; i < nSamplingPnts; i++) {
      const double &dxdX = dxyzdX(i, 0), &dydX = dxyzdX(i, 1),
                   &dzdX = dxyzdX(i, 2);
      const double &dxdY = dxyzdY(i, 0), &dydY = dxyzdY(i, 1),
                   &dzdY = dxyzdY(i, 2);
      const double &dxdZ = dxyzdZ(i, 0), &dydZ = dxyzdZ(i, 1),
                   &dzdZ = dxyzdZ(i, 2);
      jacobian(i) =
        calcDet3D(dxdX, dxdY, dxdZ, dydX, dydY, dydZ, dzdX, dzdY, dzdZ);
    }
    if(scaling) {
      const double scale = 1. / getPrimJac3D(nodesXYZ);
      jacobian.scale(scale);
    }
  } break;
  }
}

// Calculate (signed, possibly scaled) Jacobian for several elements, with
// normal vectors to straight elements for regularization. Evaluation points
// depend on the given matrices for shape function gradients.  TODO: Optimize
// and test 1D & 2D
void JacobianBasis::getJacobianGeneral(
  int nSamplingPnts, const fullMatrix<double> &dSMat_dX,
  const fullMatrix<double> &dSMat_dY, const fullMatrix<double> &dSMat_dZ,
  const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
  const fullMatrix<double> &nodesZ, bool idealNorm, bool scaling,
  fullMatrix<double> &jacobian, const fullMatrix<double> *geomNormals) const
{
  switch(_dim) {
  case 0: {
    const int numEl = nodesX.size2();
    for(int iEl = 0; iEl < numEl; iEl++)
      for(int i = 0; i < nSamplingPnts; i++) jacobian(i, iEl) = 1.;
  } break;
  case 1: {
    const int numEl = nodesX.size2();
    fullMatrix<double> dxdX(nSamplingPnts, numEl);
    fullMatrix<double> dydX(nSamplingPnts, numEl);
    fullMatrix<double> dzdX(nSamplingPnts, numEl);
    dSMat_dX.mult(nodesX, dxdX);
    dSMat_dX.mult(nodesY, dydX);
    dSMat_dX.mult(nodesZ, dzdX);
    for(int iEl = 0; iEl < numEl; iEl++) {
      fullMatrix<double> nodesXYZ(numPrimMapNodes, 3);
      for(int i = 0; i < numPrimMapNodes; i++) {
        nodesXYZ(i, 0) = nodesX(i, iEl);
        nodesXYZ(i, 1) = nodesY(i, iEl);
        nodesXYZ(i, 2) = nodesZ(i, iEl);
      }
      fullMatrix<double> normals(2, 3);
      const double invScale = getPrimNormals1D(nodesXYZ, normals);
      if(geomNormals) normals.setAll(*geomNormals);
      if(scaling) {
        if(invScale == 0) {
          for(int i = 0; i < nSamplingPnts; i++) jacobian(i, iEl) = 0;
          continue;
        }
        const double scale = 1. / invScale;
        // Faster to scale 1 normal than afterwards
        normals(0, 0) *= scale;
        normals(0, 1) *= scale;
        normals(0, 2) *= scale;
      }
      const double &dxdY = normals(0, 0), &dydY = normals(0, 1),
                   &dzdY = normals(0, 2);
      const double &dxdZ = normals(1, 0), &dydZ = normals(1, 1),
                   &dzdZ = normals(1, 2);
      for(int i = 0; i < nSamplingPnts; i++)
        jacobian(i, iEl) = calcDet3D(dxdX(i, iEl), dxdY, dxdZ, dydX(i, iEl),
                                     dydY, dydZ, dzdX(i, iEl), dzdY, dzdZ);
    }
  } break;
  case 2: {
    const int numEl = nodesX.size2();
    fullMatrix<double> dxdX(nSamplingPnts, numEl);
    fullMatrix<double> dydX(nSamplingPnts, numEl);
    fullMatrix<double> dzdX(nSamplingPnts, numEl);
    fullMatrix<double> dxdY(nSamplingPnts, numEl);
    fullMatrix<double> dydY(nSamplingPnts, numEl);
    fullMatrix<double> dzdY(nSamplingPnts, numEl);
    dSMat_dX.mult(nodesX, dxdX);
    dSMat_dX.mult(nodesY, dydX);
    dSMat_dX.mult(nodesZ, dzdX);
    dSMat_dY.mult(nodesX, dxdY);
    dSMat_dY.mult(nodesY, dydY);
    dSMat_dY.mult(nodesZ, dzdY);
    for(int iEl = 0; iEl < numEl; iEl++) {
      fullMatrix<double> nodesXYZ(numPrimMapNodes, 3);
      for(int i = 0; i < numPrimMapNodes; i++) {
        nodesXYZ(i, 0) = nodesX(i, iEl);
        nodesXYZ(i, 1) = nodesY(i, iEl);
        nodesXYZ(i, 2) = nodesZ(i, iEl);
      }
      fullMatrix<double> normal(1, 3);
      const double invScale = getPrimNormal2D(nodesXYZ, normal, idealNorm);
      if(geomNormals) normal.setAll(*geomNormals);
      if(scaling) {
        if(invScale == 0) {
          for(int i = 0; i < nSamplingPnts; i++) jacobian(i, iEl) = 0;
          continue;
        }
        const double scale = 1. / invScale;
        // Faster to scale normal than afterwards
        normal(0, 0) *= scale;
        normal(0, 1) *= scale;
        normal(0, 2) *= scale;
      }
      const double &dxdZ = normal(0, 0), &dydZ = normal(0, 1),
                   &dzdZ = normal(0, 2);
      for(int i = 0; i < nSamplingPnts; i++)
        jacobian(i, iEl) =
          calcDet3D(dxdX(i, iEl), dxdY(i, iEl), dxdZ, dydX(i, iEl),
                    dydY(i, iEl), dydZ, dzdX(i, iEl), dzdY(i, iEl), dzdZ);
    }
  } break;
  case 3: {
    const int numEl = nodesX.size2();
    fullMatrix<double> dxdX(nSamplingPnts, numEl);
    fullMatrix<double> dydX(nSamplingPnts, numEl);
    fullMatrix<double> dzdX(nSamplingPnts, numEl);
    fullMatrix<double> dxdY(nSamplingPnts, numEl);
    fullMatrix<double> dydY(nSamplingPnts, numEl);
    fullMatrix<double> dzdY(nSamplingPnts, numEl);
    fullMatrix<double> dxdZ(nSamplingPnts, numEl);
    fullMatrix<double> dydZ(nSamplingPnts, numEl);
    fullMatrix<double> dzdZ(nSamplingPnts, numEl);
    dSMat_dX.mult(nodesX, dxdX);
    dSMat_dX.mult(nodesY, dydX);
    dSMat_dX.mult(nodesZ, dzdX);
    dSMat_dY.mult(nodesX, dxdY);
    dSMat_dY.mult(nodesY, dydY);
    dSMat_dY.mult(nodesZ, dzdY);
    dSMat_dZ.mult(nodesX, dxdZ);
    dSMat_dZ.mult(nodesY, dydZ);
    dSMat_dZ.mult(nodesZ, dzdZ);
    for(int iEl = 0; iEl < numEl; iEl++) {
      for(int i = 0; i < nSamplingPnts; i++)
        jacobian(i, iEl) = calcDet3D(dxdX(i, iEl), dxdY(i, iEl), dxdZ(i, iEl),
                                     dydX(i, iEl), dydY(i, iEl), dydZ(i, iEl),
                                     dzdX(i, iEl), dzdY(i, iEl), dzdZ(i, iEl));
      if(scaling) {
        fullMatrix<double> nodesXYZ(numPrimMapNodes, 3);
        for(int i = 0; i < numPrimMapNodes; i++) {
          nodesXYZ(i, 0) = nodesX(i, iEl);
          nodesXYZ(i, 1) = nodesY(i, iEl);
          nodesXYZ(i, 2) = nodesZ(i, iEl);
        }
        const double scale = 1. / getPrimJac3D(nodesXYZ);
        for(int i = 0; i < nSamplingPnts; i++) jacobian(i, iEl) *= scale;
      }
    }
  } break;
  }
}

// Calculate the (signed) Jacobian determinant (in short, J) and its partial
// derivatives w.r.t. nodes coordinates for the element defined by
// the given node positions, with given normal vectors to straight element
// for regularization of 1D and 2D elements).
// Sampling points depend on the input matrices of shape function partial
// derivatives 'dSMat_d*', and only the 'nSamplingPnts' first of them
// are computed.
// The result is written in the matrix 'JDJ' which should be of size at
// least "nSamplingPnts x (3 * numMapNodes + 1)".
// For each sampling point, a row of 'JDJ' is filled with:
// - the partial derivatives of J w.r.t. the x component of the nodes
// - the partial derivatives of J w.r.t. the y component of the nodes
// - the partial derivatives of J w.r.t. the z component of the nodes
// - J
// NB: (x, y, z) are the physical coordinates and (X, Y, Z) are the reference
// coordinates
void JacobianBasis::getSignedJacAndGradientsGeneral(
  int nSamplingPnts, const fullMatrix<double> &dSMat_dX,
  const fullMatrix<double> &dSMat_dY, const fullMatrix<double> &dSMat_dZ,
  const fullMatrix<double> &nodesXYZ, const fullMatrix<double> &normals,
  fullMatrix<double> &JDJ) const
{
  switch(_dim) {
  case 0: {
    for(int i = 0; i < nSamplingPnts; i++) {
      for(int j = 0; j < numMapNodes; j++) {
        JDJ(i, j) = 0.;
        JDJ(i, j + 1 * numMapNodes) = 0.;
        JDJ(i, j + 2 * numMapNodes) = 0.;
      }
      JDJ(i, 3 * numMapNodes) = 1.;
    }
  } break;
  case 1: {
    fullMatrix<double> dxyzdX(nSamplingPnts, 3);
    dSMat_dX.mult(nodesXYZ, dxyzdX);
    for(int i = 0; i < nSamplingPnts; i++) {
      calcJDJ1D(dxyzdX(i, 0), normals(0, 0), normals(1, 0), dxyzdX(i, 1),
                normals(0, 1), normals(1, 1), dxyzdX(i, 2), normals(0, 2),
                normals(1, 2), i, numMapNodes, dSMat_dX, JDJ);
    }
  } break;
  case 2: {
    fullMatrix<double> dxyzdX(nSamplingPnts, 3);
    fullMatrix<double> dxyzdY(nSamplingPnts, 3);
    dSMat_dX.mult(nodesXYZ, dxyzdX);
    dSMat_dY.mult(nodesXYZ, dxyzdY);
    for(int i = 0; i < nSamplingPnts; i++) {
      calcJDJ2D(dxyzdX(i, 0), dxyzdY(i, 0), normals(0, 0), dxyzdX(i, 1),
                dxyzdY(i, 1), normals(0, 1), dxyzdX(i, 2), dxyzdY(i, 2),
                normals(0, 2), i, numMapNodes, dSMat_dX, dSMat_dY, JDJ);
    }
  } break;
  case 3: {
    fullMatrix<double> dxyzdX(nSamplingPnts, 3);
    fullMatrix<double> dxyzdY(nSamplingPnts, 3);
    fullMatrix<double> dxyzdZ(nSamplingPnts, 3);
    dSMat_dX.mult(nodesXYZ, dxyzdX);
    dSMat_dY.mult(nodesXYZ, dxyzdY);
    dSMat_dZ.mult(nodesXYZ, dxyzdZ);
    for(int i = 0; i < nSamplingPnts; i++) {
      calcJDJ3D(dxyzdX(i, 0), dxyzdY(i, 0), dxyzdZ(i, 0), dxyzdX(i, 1),
                dxyzdY(i, 1), dxyzdZ(i, 1), dxyzdX(i, 2), dxyzdY(i, 2),
                dxyzdZ(i, 2), i, numMapNodes, dSMat_dX, dSMat_dY, dSMat_dZ,
                JDJ);
    }
  } break;
  }
}

void JacobianBasis::getSignedIdealJacAndGradientsGeneral(
  int nSamplingPnts, const fullMatrix<double> &dSMat_dX,
  const fullMatrix<double> &dSMat_dY, const fullMatrix<double> &dSMat_dZ,
  const fullMatrix<double> &nodesXYZ, const fullMatrix<double> &normals,
  fullMatrix<double> &JDJ) const
{
  getSignedJacAndGradientsGeneral(nSamplingPnts, dSMat_dX, dSMat_dY, dSMat_dZ,
                                  nodesXYZ, normals, JDJ);
}

void JacobianBasis::getMetricMinAndGradients(
  const fullMatrix<double> &nodesXYZ,
  const fullMatrix<double> &nodesXYZStraight, fullVector<double> &lambdaJ,
  fullMatrix<double> &gradLambdaJ) const
{
  // jacobian of the straight elements (only triangles for now)
  SPoint3 v0(nodesXYZ(0, 0), nodesXYZ(0, 1), nodesXYZ(0, 2));
  SPoint3 v1(nodesXYZ(1, 0), nodesXYZ(1, 1), nodesXYZ(1, 2));
  SPoint3 v2(nodesXYZ(2, 0), nodesXYZ(2, 1), nodesXYZ(2, 2));
  SPoint3 *IXYZ[3] = {&v0, &v1, &v2};
  double jaci[2][2] = {
    {IXYZ[1]->x() - IXYZ[0]->x(), IXYZ[2]->x() - IXYZ[0]->x()},
    {IXYZ[1]->y() - IXYZ[0]->y(), IXYZ[2]->y() - IXYZ[0]->y()}};
  double invJaci[2][2];
  inv2x2(jaci, invJaci);

  for(int l = 0; l < numSamplingPnts; l++) {
    double jac[2][2] = {{0., 0.}, {0., 0.}};
    for(int i = 0; i < numMapNodes; i++) {
      const double &dPhidX = _gradBasis->dShapeMat_dX(l, i);
      const double &dPhidY = _gradBasis->dShapeMat_dY(l, i);
      const double dpsidx = dPhidX * invJaci[0][0] + dPhidY * invJaci[1][0];
      const double dpsidy = dPhidX * invJaci[0][1] + dPhidY * invJaci[1][1];
      jac[0][0] += nodesXYZ(i, 0) * dpsidx;
      jac[0][1] += nodesXYZ(i, 0) * dpsidy;
      jac[1][0] += nodesXYZ(i, 1) * dpsidx;
      jac[1][1] += nodesXYZ(i, 1) * dpsidy;
    }
    const double dxdx = jac[0][0] * jac[0][0] + jac[0][1] * jac[0][1];
    const double dydy = jac[1][0] * jac[1][0] + jac[1][1] * jac[1][1];
    const double dxdy = jac[0][0] * jac[1][0] + jac[0][1] * jac[1][1];
    const double sqr = sqrt((dxdx - dydy) * (dxdx - dydy) + 4 * dxdy * dxdy);
    const double osqr = sqr > 1e-8 ? 1 / sqr : 0;
    lambdaJ(l) = 0.5 * (dxdx + dydy - sqr);
    const double axx =
      (1 - (dxdx - dydy) * osqr) * jac[0][0] - 2 * dxdy * osqr * jac[1][0];
    const double axy =
      (1 - (dxdx - dydy) * osqr) * jac[0][1] - 2 * dxdy * osqr * jac[1][1];
    const double ayx =
      -2 * dxdy * osqr * jac[0][0] + (1 - (dydy - dxdx) * osqr) * jac[1][0];
    const double ayy =
      -2 * dxdy * osqr * jac[0][1] + (1 - (dydy - dxdx) * osqr) * jac[1][1];
    const double axixi = axx * invJaci[0][0] + axy * invJaci[0][1];
    const double aetaeta = ayx * invJaci[1][0] + ayy * invJaci[1][1];
    const double aetaxi = ayx * invJaci[0][0] + ayy * invJaci[0][1];
    const double axieta = axx * invJaci[1][0] + axy * invJaci[1][1];
    for(int i = 0; i < numMapNodes; i++) {
      const double &dPhidX = _gradBasis->dShapeMat_dX(l, i);
      const double &dPhidY = _gradBasis->dShapeMat_dY(l, i);
      gradLambdaJ(l, i + 0 * numMapNodes) = axixi * dPhidX + axieta * dPhidY;
      gradLambdaJ(l, i + 1 * numMapNodes) = aetaxi * dPhidX + aetaeta * dPhidY;
    }
  }
}

int JacobianBasis::jacobianOrder(int tag)
{
  const int parentType = ElementType::getParentType(tag);
  const int order = ElementType::getOrder(tag);
  return jacobianOrder(parentType, order);
}

int JacobianBasis::jacobianOrder(int parentType, int order)
{
  switch(parentType) {
  case TYPE_PNT: return 0;
  case TYPE_LIN: return order - 1;
  case TYPE_TRI: return 2 * order - 2;
  case TYPE_QUA: return 2 * order - 1;
  case TYPE_TET: return 3 * order - 3;
  case TYPE_PRI: return 3 * order - 1;
  case TYPE_HEX: return 3 * order - 1;
  case TYPE_PYR:
    return 3 * order - 3;
    // note : for the pyramid, the jacobian space is
    // different from the space of the mapping
  default:
    Msg::Error("Unknown element type %d, return order 0", parentType);
    return 0;
  }
}

FuncSpaceData JacobianBasis::jacobianMatrixSpace(int type, int order)
{
  if(type == TYPE_PYR) {
    Msg::Error("jacobianMatrixSpace not yet implemented for pyramids");
    return FuncSpaceData(type, false, 1, 0, false);
  }
  int jacOrder = -1;
  switch(type) {
  case TYPE_PNT: jacOrder = 0; break;
  case TYPE_LIN:
  case TYPE_TRI:
  case TYPE_TET: jacOrder = order - 1; break;
  case TYPE_QUA:
  case TYPE_PRI:
  case TYPE_HEX: jacOrder = order; break;
  default:
    Msg::Error("Unknown element type %d, return default space", type);
    return FuncSpaceData();
  }
  return FuncSpaceData(type, jacOrder, false);
}
