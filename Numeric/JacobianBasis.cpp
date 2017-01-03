// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "JacobianBasis.h"
#include "pointsGenerators.h"
#include "nodalBasis.h"
#include "bezierBasis.h"
#include "BasisFactory.h"
#include "Numeric.h"
#include <cmath>

namespace {

template<class T>
void calcMapFromIdealElement(int type, T &gSMatX, T &gSMatY, T &gSMatZ)
{
  // 2D scaling
  switch(type) {
    case TYPE_QUA:                                             // Quad, hex, pyramid -> square with side of length 1
    case TYPE_HEX:
    case TYPE_PYR: {
      gSMatX.scale(2.);
      gSMatY.scale(2.);
      break;
    }
    default: {                                                // Tri, tet, prism: equilateral tri with side of length 1
      static const double cTri[2] = {-1./std::sqrt(3.), 2./std::sqrt(3.)};
      gSMatY.scale(cTri[1]);
      gSMatY.axpy(gSMatX, cTri[0]);
      break;
    }
  }

  // 3D scaling
  switch(type) {
    case TYPE_HEX:                                            // Hex, prism -> side of length 1 in z
    case TYPE_PRI: {
      gSMatZ.scale(2.);
      break;
    }
    case TYPE_PYR: {                                          // Pyramid -> height sqrt(2.)/2
      static const double cPyr = sqrt(2.);
      gSMatZ.scale(cPyr);
      break;
    }
    case TYPE_TET:                                            // Tet: take into account (x, y) scaling to obtain regular tet
    {
      static const double cTet[3] = {-3./2/std::sqrt(6.),
                                     -1./2/std::sqrt(2.),
                                     std::sqrt(1.5)};
      gSMatZ.scale(cTet[2]);
      gSMatZ.axpy(gSMatX, cTet[0]);
      gSMatZ.axpy(gSMatY, cTet[1]);
      break;
    }
  }
}

// Compute the determinant of a 3x3 matrix
inline double calcDet3D(double M11, double M12, double M13,
                        double M21, double M22, double M23,
                        double M31, double M32, double M33)
{
  return M11 * (M22*M33 - M23*M32)
       - M12 * (M21*M33 - M23*M31)
       + M13 * (M21*M32 - M22*M31);
}

// Compute signed Jacobian and its gradients w.r.t.
// node positions, at one location in a 1D element
inline void calcJDJ1D(double dxdX, double dxdY, double dxdZ,
                      double dydX, double dydY, double dydZ,
                      double dzdX, double dzdY, double dzdZ,
                      int i, int numMapNodes,
                      const fullMatrix<double> &gSMatX,
                      fullMatrix<double> &JDJ)
{
  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    JDJ(i, j) = dPhidX * dydY * dzdZ + dPhidX * dzdY * dydZ;
    JDJ(i, j+numMapNodes) = dPhidX * dzdY * dxdZ - dPhidX * dxdY * dzdZ;
    JDJ(i, j+2*numMapNodes) = dPhidX * dxdY * dydZ - dPhidX * dydY * dxdZ;
  }
  JDJ(i, 3*numMapNodes) = calcDet3D(dxdX, dxdY, dxdZ,
                                    dydX, dydY, dydZ,
                                    dzdX, dzdY, dzdZ);
}

// Compute signed Jacobian and its gradients w.r.t.
// node positions, at one location in a 2D element
inline void calcJDJ2D(double dxdX, double dxdY, double dxdZ,
                      double dydX, double dydY, double dydZ,
                      double dzdX, double dzdY, double dzdZ,
                      int i, int numMapNodes,
                      const fullMatrix<double> &gSMatX,
                      const fullMatrix<double> &gSMatY,
                      fullMatrix<double> &JDJ)
{
  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dPhidY = gSMatY(i, j);
    JDJ(i, j) =
      dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
      dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
    JDJ(i, j+numMapNodes) =
      dxdX * dPhidY * dzdZ +
      dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ
                           - dPhidX * dxdY * dzdZ;
    JDJ(i, j+2*numMapNodes) =
                             dPhidX * dxdY * dydZ +
      dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
      dxdX * dPhidY * dydZ;
  }
  JDJ(i, 3*numMapNodes) = calcDet3D(dxdX, dxdY, dxdZ,
                                    dydX, dydY, dydZ,
                                    dzdX, dzdY, dzdZ);
}

// Compute signed Jacobian and its gradients w.r.t.
// node positions, at one location in a 3D element
inline void calcJDJ3D(double dxdX, double dxdY, double dxdZ,
                      double dydX, double dydY, double dydZ,
                      double dzdX, double dzdY, double dzdZ,
                      int i, int numMapNodes,
                      const fullMatrix<double> &gSMatX,
                      const fullMatrix<double> &gSMatY,
                      const fullMatrix<double> &gSMatZ,
                      fullMatrix<double> &JDJ)
{
  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dPhidY = gSMatY(i, j);
    const double &dPhidZ = gSMatZ(i, j);
    JDJ(i, j) =
      dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
      dydX * dzdY * dPhidZ - dzdX * dydY * dPhidZ -
      dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
    JDJ(i, j+numMapNodes) =
      dxdX * dPhidY * dzdZ + dzdX * dxdY * dPhidZ +
      dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ -
      dxdX * dzdY * dPhidZ - dPhidX * dxdY * dzdZ;
    JDJ(i, j+2*numMapNodes) =
      dxdX * dydY * dPhidZ + dPhidX * dxdY * dydZ +
      dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
      dxdX * dPhidY * dydZ - dydX * dxdY * dPhidZ;
  }
  JDJ(i, 3*numMapNodes) = calcDet3D(dxdX, dxdY, dxdZ,
                                    dydX, dydY, dydZ,
                                    dzdX, dzdY, dzdZ);
}

} //namespace

GradientBasis::GradientBasis(FuncSpaceData data)
    : _data(data)
{
  fullMatrix<double> samplingPoints;
  gmshGeneratePoints(data, samplingPoints);
  const int numSampPnts = samplingPoints.size1();

  // Store shape function gradients of mapping at Jacobian nodes
  fullMatrix<double> allDPsi;
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(_data.elementTag());
  mapBasis->df(samplingPoints, allDPsi);
  const int numMapNodes = allDPsi.size1();

  gradShapeMatX.resize(numSampPnts, numMapNodes);
  gradShapeMatY.resize(numSampPnts, numMapNodes);
  gradShapeMatZ.resize(numSampPnts, numMapNodes);
  for (int i = 0; i < numSampPnts; i++) {
    for (int j = 0; j < numMapNodes; j++) {
      gradShapeMatX(i, j) = allDPsi(j, 3*i);
      gradShapeMatY(i, j) = allDPsi(j, 3*i+1);
      gradShapeMatZ(i, j) = allDPsi(j, 3*i+2);
    }
  }

  gradShapeIdealMatX = gradShapeMatX;
  gradShapeIdealMatY = gradShapeMatY;
  gradShapeIdealMatZ = gradShapeMatZ;
  mapFromIdealElement(_data.elementType(), gradShapeIdealMatX,
                      gradShapeIdealMatY, gradShapeIdealMatZ);
}

const bezierBasis* GradientBasis::getBezier() const
{
  return BasisFactory::getBezierBasis(_data);
}

void GradientBasis::getGradientsFromNodes(const fullMatrix<double> &nodes,
                                          fullMatrix<double> *dxyzdX,
                                          fullMatrix<double> *dxyzdY,
                                          fullMatrix<double> *dxyzdZ) const
{
  if (dxyzdX) gradShapeMatX.mult(nodes, *dxyzdX);
  if (dxyzdY) gradShapeMatY.mult(nodes, *dxyzdY);
  if (dxyzdZ) gradShapeMatZ.mult(nodes, *dxyzdZ);
}

void GradientBasis::getAllGradientsFromNodes(const fullMatrix<double> &nodes,
                                             fullMatrix<double> &dxyzdXYZ) const
{
  fullMatrix<double> prox;
  prox.setAsProxy(dxyzdXYZ, 0, 3);
  gradShapeMatX.mult(nodes, prox);

  prox.setAsProxy(dxyzdXYZ, 3, 3);
  gradShapeMatY.mult(nodes, prox);

  prox.setAsProxy(dxyzdXYZ, 6, 3);
  gradShapeMatZ.mult(nodes, prox);
}

void GradientBasis::
    getAllIdealGradientsFromNodes(const fullMatrix<double> &nodes,
                                  fullMatrix<double> &dxyzdXYZ) const
{
  fullMatrix<double> prox;
  prox.setAsProxy(dxyzdXYZ, 0, 3);
  gradShapeIdealMatX.mult(nodes, prox);

  prox.setAsProxy(dxyzdXYZ, 3, 3);
  gradShapeIdealMatY.mult(nodes, prox);

  prox.setAsProxy(dxyzdXYZ, 6, 3);
  gradShapeIdealMatZ.mult(nodes, prox);
}

void GradientBasis::getIdealGradientsFromNodes(const fullMatrix<double> &nodes,
                                               fullMatrix<double> *dxyzdX,
                                               fullMatrix<double> *dxyzdY,
                                               fullMatrix<double> *dxyzdZ) const
{
  if (dxyzdX) gradShapeIdealMatX.mult(nodes, *dxyzdX);
  if (dxyzdY) gradShapeIdealMatY.mult(nodes, *dxyzdY);
  if (dxyzdZ) gradShapeIdealMatZ.mult(nodes, *dxyzdZ);
}

void GradientBasis::mapFromIdealElement(int type,
                                        fullMatrix<double> &gSMatX,
                                        fullMatrix<double> &gSMatY,
                                        fullMatrix<double> &gSMatZ)
{
  calcMapFromIdealElement(type, gSMatX, gSMatY, gSMatZ);
}

void GradientBasis::mapFromIdealElement(int type,
                                        fullVector<double> &gSVecX,
                                        fullVector<double> &gSVecY,
                                        fullVector<double> &gSVecZ)
{
  calcMapFromIdealElement(type, gSVecX, gSVecY, gSVecZ);
}

void GradientBasis::mapFromIdealElement(int type, double jac[3][3])
{
  fullMatrix<double> dxyzdX(jac[0], 1, 3), dxyzdY(jac[1], 1, 3), dxyzdZ(jac[2], 1, 3);
  mapFromIdealElement(type, dxyzdX, dxyzdY, dxyzdZ);
}

void GradientBasis::lag2Bez(const fullMatrix<double> &lag,
                            fullMatrix<double> &bez) const
{
  getBezier()->matrixLag2Bez.mult(lag,bez);
}

JacobianBasis::JacobianBasis(FuncSpaceData data)
    : _data(data), _dim(data.dimension())
{
  const int parentType = data.elementType();
  const int primJacobianOrder = jacobianOrder(parentType, 1);

  fullMatrix<double> lagPoints;                               // Sampling points
  gmshGeneratePoints(data, lagPoints);
  numJacNodes = lagPoints.size1();

  // Store shape function gradients of mapping at Jacobian nodes
  _gradBasis = BasisFactory::getGradientBasis(data);

  // Compute matrix for lifting from primary Jacobian basis to Jacobian basis
  int primJacType = ElementType::getTag(parentType, primJacobianOrder, false);
  const nodalBasis *primJacBasis = BasisFactory::getNodalBasis(primJacType);
  numPrimJacNodes = primJacBasis->getNumShapeFunctions();

  matrixPrimJac2Jac.resize(numJacNodes, numPrimJacNodes);
  primJacBasis->f(lagPoints, matrixPrimJac2Jac);

  // Compute shape function gradients of primary mapping at barycenter,
  // in order to compute normal to straight element
  const int primMapType = ElementType::getTag(parentType, 1, false);
  const nodalBasis *primMapBasis = BasisFactory::getNodalBasis(primMapType);
  numPrimMapNodes = primMapBasis->getNumShapeFunctions();

  double xBar = 0., yBar = 0., zBar = 0.;
  double barycenter[3] = {0., 0., 0.};
  for (int i = 0; i < numPrimMapNodes; i++) {
    for (int j = 0; j < primMapBasis->points.size2(); ++j) {
      barycenter[j] += primMapBasis->points(i, j);
    }
  }
  barycenter[0] /= numPrimMapNodes;
  barycenter[1] /= numPrimMapNodes;
  barycenter[2] /= numPrimMapNodes;

  double (*barDPsi)[3] = new double[numPrimMapNodes][3];
  primMapBasis->df(xBar, yBar, zBar, barDPsi);

  primGradShapeBaryX.resize(numPrimMapNodes);
  primGradShapeBaryY.resize(numPrimMapNodes);
  primGradShapeBaryZ.resize(numPrimMapNodes);
  for (int j = 0; j < numPrimMapNodes; j++) {
    primGradShapeBaryX(j) = barDPsi[j][0];
    primGradShapeBaryY(j) = barDPsi[j][1];
    primGradShapeBaryZ(j) = barDPsi[j][2];
  }

  primIdealGradShapeBaryX = primGradShapeBaryX;
  primIdealGradShapeBaryY = primGradShapeBaryY;
  primIdealGradShapeBaryZ = primGradShapeBaryZ;
  _gradBasis->mapFromIdealElement(primIdealGradShapeBaryX, primIdealGradShapeBaryY,
                                  primIdealGradShapeBaryZ);

  delete[] barDPsi;

  // Compute "fast" Jacobian evaluation matrices (at 1st order nodes + barycenter)
  numJacNodesFast = numPrimMapNodes + 1;
  fullMatrix<double> lagPointsFast(numJacNodesFast, 3);           // Sampling points
  lagPointsFast.copy(primMapBasis->points, 0, numPrimMapNodes,
                     0, primMapBasis->points.size2(), 0, 0);      // 1st order nodes
  lagPointsFast(numPrimMapNodes, 0) = barycenter[0];              // Last point = barycenter
  lagPointsFast(numPrimMapNodes, 1) = barycenter[1];
  lagPointsFast(numPrimMapNodes, 2) = barycenter[2];

  fullMatrix<double> allDPsiFast;
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(data.elementTag());
  mapBasis->df(lagPointsFast, allDPsiFast);
  numMapNodes = mapBasis->getNumShapeFunctions();

  gradShapeMatXFast.resize(numJacNodesFast, numMapNodes);
  gradShapeMatYFast.resize(numJacNodesFast, numMapNodes);
  gradShapeMatZFast.resize(numJacNodesFast, numMapNodes);
  for (int i = 0; i < numJacNodesFast; i++) {
    for (int j = 0; j < numMapNodes; j++) {
      gradShapeMatXFast(i, j) = allDPsiFast(j, 3*i);
      gradShapeMatYFast(i, j) = allDPsiFast(j, 3*i+1);
      gradShapeMatZFast(i, j) = allDPsiFast(j, 3*i+2);
    }
  }
}

const bezierBasis* JacobianBasis::getBezier() const
{
  return BasisFactory::getBezierBasis(_data);
}

// Computes (unit) normals to straight line element at barycenter (with norm of gradient as return value)
double JacobianBasis::getPrimNormals1D(const fullMatrix<double> &nodesXYZ,
                                       fullMatrix<double> &result) const
{

  fullVector<double> dxyzdXbar(3);
  for (int j = 0; j < numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBaryX(j) * nodesXYZ(j, 0);
    dxyzdXbar(1) += primGradShapeBaryX(j) * nodesXYZ(j, 1);
    dxyzdXbar(2) += primGradShapeBaryX(j) * nodesXYZ(j, 2);
  }

  if((fabs(dxyzdXbar(0)) >= fabs(dxyzdXbar(1)) && fabs(dxyzdXbar(0)) >= fabs(dxyzdXbar(2))) ||
     (fabs(dxyzdXbar(1)) >= fabs(dxyzdXbar(0)) && fabs(dxyzdXbar(1)) >= fabs(dxyzdXbar(2)))) {
    result(0,0) = dxyzdXbar(1); result(0,1) = -dxyzdXbar(0); result(0,2) = 0.;
  }
  else {
    result(0,0) = 0.; result(0,1) = dxyzdXbar(2); result(0,2) = -dxyzdXbar(1);
  }
  const double norm0 = sqrt(result(0,0)*result(0,0)+result(0,1)*result(0,1)+result(0,2)*result(0,2));
  result(0,0) /= norm0; result(0,1) /= norm0; result(0,2) /= norm0;

  result(1,2) = dxyzdXbar(0) * result(0,1) - dxyzdXbar(1) * result(0,0);
  result(1,1) = -dxyzdXbar(0) * result(0,2) + dxyzdXbar(2) * result(0,0);
  result(1,0) = dxyzdXbar(1) * result(0,2) - dxyzdXbar(2) * result(0,1);
  const double norm1 = sqrt(result(1,0)*result(1,0)+result(1,1)*result(1,1)+result(1,2)*result(1,2));
  result(1,0) /= norm1; result(1,1) /= norm1; result(1,2) /= norm1;

  return sqrt(dxyzdXbar(0)*dxyzdXbar(0)+dxyzdXbar(1)*dxyzdXbar(1)+dxyzdXbar(2)*dxyzdXbar(2));

}

// Computes (unit) normal to straight surface element at barycenter (with norm as return value)
double JacobianBasis::getPrimNormal2D(const fullMatrix<double> &nodesXYZ,
                                      fullMatrix<double> &result, bool ideal) const
{
  const fullVector<double> &gSX = ideal ? primIdealGradShapeBaryX : primGradShapeBaryX,
                           &gSY = ideal ? primIdealGradShapeBaryY : primGradShapeBaryY;
  fullMatrix<double> dxyzdX(1, 3), dxyzdY(1, 3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdX(0, 0) += gSX(j)*nodesXYZ(j,0);
    dxyzdX(0, 1) += gSX(j)*nodesXYZ(j,1);
    dxyzdX(0, 2) += gSX(j)*nodesXYZ(j,2);
    dxyzdY(0, 0) += gSY(j)*nodesXYZ(j,0);
    dxyzdY(0, 1) += gSY(j)*nodesXYZ(j,1);
    dxyzdY(0, 2) += gSY(j)*nodesXYZ(j,2);
  }

  result(0, 2) = dxyzdX(0, 0) * dxyzdY(0, 1) - dxyzdX(0, 1) * dxyzdY(0, 0);
  result(0, 1) = -dxyzdX(0, 0) * dxyzdY(0, 2) + dxyzdX(0, 2) * dxyzdY(0, 0);
  result(0, 0) = dxyzdX(0, 1) * dxyzdY(0, 2) - dxyzdX(0, 2) * dxyzdY(0, 1);
  double norm0 = sqrt(result(0, 0)*result(0, 0)+result(0, 1)*result(0, 1)+result(0, 2)*result(0, 2));
  const double invNorm0 = 1./norm0;
  result(0, 0) *= invNorm0; result(0, 1) *= invNorm0; result(0, 2) *= invNorm0;

  return norm0;
}

// Returns absolute value of Jacobian of straight volume element at barycenter
double JacobianBasis::getPrimJac3D(const fullMatrix<double> &nodesXYZ, bool ideal) const
{
  const fullVector<double> &gSX = ideal ? primIdealGradShapeBaryX : primGradShapeBaryX,
                           &gSY = ideal ? primIdealGradShapeBaryY : primGradShapeBaryY,
                           &gSZ = ideal ? primIdealGradShapeBaryZ : primGradShapeBaryZ;
  fullMatrix<double> dxyzdX(1, 3), dxyzdY(1, 3), dxyzdZ(1, 3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdX(0, 0) += gSX(j)*nodesXYZ(j,0);
    dxyzdX(0, 1) += gSX(j)*nodesXYZ(j,1);
    dxyzdX(0, 2) += gSX(j)*nodesXYZ(j,2);
    dxyzdY(0, 0) += gSY(j)*nodesXYZ(j,0);
    dxyzdY(0, 1) += gSY(j)*nodesXYZ(j,1);
    dxyzdY(0, 2) += gSY(j)*nodesXYZ(j,2);
    dxyzdZ(0, 0) += gSZ(j)*nodesXYZ(j,0);
    dxyzdZ(0, 1) += gSZ(j)*nodesXYZ(j,1);
    dxyzdZ(0, 2) += gSZ(j)*nodesXYZ(j,2);
  }

  double dJ = fabs(calcDet3D(dxyzdX(0, 0), dxyzdY(0, 0), dxyzdZ(0, 0),
                             dxyzdX(0, 1), dxyzdY(0, 1), dxyzdZ(0, 1),
                             dxyzdX(0, 2), dxyzdY(0, 2), dxyzdZ(0, 2)));
  return dJ;
}

// Calculate (signed, possibly scaled) Jacobian for one element, with normal vectors to straight element
// for regularization. Evaluation points depend on the given matrices for shape function gradients.
void JacobianBasis::getJacobianGeneral(int nJacNodes,
                                       const fullMatrix<double> &gSMatX,
                                       const fullMatrix<double> &gSMatY,
                                       const fullMatrix<double> &gSMatZ,
                                       const fullMatrix<double> &nodesXYZ,
                                       bool idealNorm, bool scaling,
                                       fullVector<double> &jacobian,
                                       const fullMatrix<double> *geomNormals) const
{
  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nJacNodes; i++) jacobian(i) = 1.;
      break;
    }

    case 1 : {
      fullMatrix<double> normals(2,3);
      const double invScale = getPrimNormals1D(nodesXYZ,normals);
      if (geomNormals)
        normals.setAll(*geomNormals);
      if (scaling) {
        if (invScale == 0) {
          for (int i = 0; i < nJacNodes; i++) jacobian(i) = 0;
          return;
        }
        const double scale = 1./invScale;
        normals(0,0) *= scale; normals(0,1) *= scale; normals(0,2) *= scale;            // Faster to scale 1 normal than afterwards
      }
      fullMatrix<double> dxyzdX(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        jacobian(i) = calcDet3D(dxdX, dxdY, dxdZ,
                                dydX, dydY, dydZ,
                                dzdX, dzdY, dzdZ);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> normal(1,3);
      const double invScale = getPrimNormal2D(nodesXYZ, normal, idealNorm);
      if (geomNormals)
        normal.setAll(*geomNormals);
      if (scaling) {
        if (invScale == 0) {
          for (int i = 0; i < nJacNodes; i++) jacobian(i) = 0;
          return;
        }
        const double scale = 1./invScale;
        normal(0,0) *= scale; normal(0,1) *= scale; normal(0,2) *= scale;               // Faster to scale normal than afterwards
      }
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normal(0,0), &dydZ = normal(0,1), &dzdZ = normal(0,2);
        jacobian(i) = calcDet3D(dxdX, dxdY, dxdZ,
                                dydX, dydY, dydZ,
                                dzdX, dzdY, dzdZ);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dum;
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3), dxyzdZ(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      gSMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        jacobian(i) = calcDet3D(dxdX, dxdY, dxdZ,
                                dydX, dydY, dydZ,
                                dzdX, dzdY, dzdZ);
      }
      if (scaling) {
        const double scale = 1./getPrimJac3D(nodesXYZ);
        jacobian.scale(scale);
      }
      break;

    }

  }

}

// Calculate (signed, possibly scaled) Jacobian for several elements, with normal vectors to straight
// elements for regularization. Evaluation points depend on the given matrices for shape function gradients.
// TODO: Optimize and test 1D & 2D
void JacobianBasis::getJacobianGeneral(int nJacNodes,
                                       const fullMatrix<double> &gSMatX,
                                       const fullMatrix<double> &gSMatY,
                                       const fullMatrix<double> &gSMatZ,
                                       const fullMatrix<double> &nodesX,
                                       const fullMatrix<double> &nodesY,
                                       const fullMatrix<double> &nodesZ,
                                       bool idealNorm, bool scaling,
                                       fullMatrix<double> &jacobian,
                                       const fullMatrix<double> *geomNormals) const
{
  switch (_dim) {

    case 0 : {
      const int numEl = nodesX.size2();
      for (int iEl = 0; iEl < numEl; iEl++)
        for (int i = 0; i < nJacNodes; i++) jacobian(i, iEl) = 1.;
      break;
    }

    case 1 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(nJacNodes,numEl), dydX(nJacNodes,numEl), dzdX(nJacNodes,numEl);
      gSMatX.mult(nodesX, dxdX); gSMatX.mult(nodesY, dydX); gSMatX.mult(nodesZ, dzdX);
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimMapNodes,3);
        for (int i = 0; i < numPrimMapNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normals(2,3);
        const double invScale = getPrimNormals1D(nodesXYZ,normals);
        if (geomNormals)
          normals.setAll(*geomNormals);
        if (scaling) {
          if (invScale == 0) {
            for (int i = 0; i < nJacNodes; i++) jacobian(i,iEl) = 0;
            continue;
          }
          const double scale = 1./invScale;
          normals(0,0) *= scale; normals(0,1) *= scale; normals(0,2) *= scale;                // Faster to scale 1 normal than afterwards
        }
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        for (int i = 0; i < nJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl), dxdY, dxdZ,
                                      dydX(i,iEl), dydY, dydZ,
                                      dzdX(i,iEl), dzdY, dzdZ);
      }
      break;
    }

    case 2 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(nJacNodes,numEl), dydX(nJacNodes,numEl), dzdX(nJacNodes,numEl);
      fullMatrix<double> dxdY(nJacNodes,numEl), dydY(nJacNodes,numEl), dzdY(nJacNodes,numEl);
      gSMatX.mult(nodesX, dxdX); gSMatX.mult(nodesY, dydX); gSMatX.mult(nodesZ, dzdX);
      gSMatY.mult(nodesX, dxdY); gSMatY.mult(nodesY, dydY); gSMatY.mult(nodesZ, dzdY);
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimMapNodes,3);
        for (int i = 0; i < numPrimMapNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normal(1,3);
        const double invScale = getPrimNormal2D(nodesXYZ, normal, idealNorm);
        if (geomNormals)
          normal.setAll(*geomNormals);
        if (scaling) {
          if (invScale == 0) {
            for (int i = 0; i < nJacNodes; i++) jacobian(i,iEl) = 0;
            continue;
          }
          const double scale = 1./invScale;
          normal(0,0) *= scale; normal(0,1) *= scale; normal(0,2) *= scale;                   // Faster to scale normal than afterwards
        }
        const double &dxdZ = normal(0,0), &dydZ = normal(0,1), &dzdZ = normal(0,2);
        for (int i = 0; i < nJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl), dxdY(i,iEl), dxdZ,
                                      dydX(i,iEl), dydY(i,iEl), dydZ,
                                      dzdX(i,iEl), dzdY(i,iEl), dzdZ);
      }
      break;
    }

    case 3 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(nJacNodes,numEl), dydX(nJacNodes,numEl), dzdX(nJacNodes,numEl);
      fullMatrix<double> dxdY(nJacNodes,numEl), dydY(nJacNodes,numEl), dzdY(nJacNodes,numEl);
      fullMatrix<double> dxdZ(nJacNodes,numEl), dydZ(nJacNodes,numEl), dzdZ(nJacNodes,numEl);
      gSMatX.mult(nodesX, dxdX); gSMatX.mult(nodesY, dydX); gSMatX.mult(nodesZ, dzdX);
      gSMatY.mult(nodesX, dxdY); gSMatY.mult(nodesY, dydY); gSMatY.mult(nodesZ, dzdY);
      gSMatZ.mult(nodesX, dxdZ); gSMatZ.mult(nodesY, dydZ); gSMatZ.mult(nodesZ, dzdZ);
      for (int iEl = 0; iEl < numEl; iEl++) {
        for (int i = 0; i < nJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl), dxdY(i,iEl), dxdZ(i,iEl),
                                      dydX(i,iEl), dydY(i,iEl), dydZ(i,iEl),
                                      dzdX(i,iEl), dzdY(i,iEl), dzdZ(i,iEl));
        if (scaling) {
          fullMatrix<double> nodesXYZ(numPrimMapNodes,3);
          for (int i = 0; i < numPrimMapNodes; i++) {
            nodesXYZ(i,0) = nodesX(i,iEl);
            nodesXYZ(i,1) = nodesY(i,iEl);
            nodesXYZ(i,2) = nodesZ(i,iEl);
          }
          const double scale = 1./getPrimJac3D(nodesXYZ);
          for (int i = 0; i < nJacNodes; i++) jacobian(i,iEl) *= scale;
        }
      }
      break;
    }

  }

}

// Calculate (signed) Jacobian and its gradients for one element, with normal vectors to straight element
// for regularization. Evaluation points depend on the given matrices for shape function gradients.
void JacobianBasis::getSignedJacAndGradientsGeneral(int nJacNodes,
                                                           const fullMatrix<double> &gSMatX,
                                                           const fullMatrix<double> &gSMatY,
                                                           const fullMatrix<double> &gSMatZ,
                                                           const fullMatrix<double> &nodesXYZ,
                                                           const fullMatrix<double> &normals,
                                                           fullMatrix<double> &JDJ) const
{
  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nJacNodes; i++) {
        for (int j = 0; j < numMapNodes; j++) {
          JDJ(i, j) = 0.;
          JDJ(i, j+1*numMapNodes) = 0.;
          JDJ(i, j+2*numMapNodes) = 0.;
        }
        JDJ(i, 3*numMapNodes) = 1.;
      }
      break;
    }

    case 1 : {
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        calcJDJ1D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, JDJ);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normals(0,0), &dydZ = normals(0,1), &dzdZ = normals(0,2);
        calcJDJ2D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, gSMatY, JDJ);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3), dxyzdZ(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      gSMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        calcJDJ3D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, gSMatY, gSMatZ, JDJ);
      }
      break;
    }

  }

}

void JacobianBasis::getSignedIdealJacAndGradientsGeneral(int nJacNodes,
                                                         const fullMatrix<double> &gSMatX,
                                                         const fullMatrix<double> &gSMatY,
                                                         const fullMatrix<double> &gSMatZ,
                                                         const fullMatrix<double> &nodesXYZ,
                                                         const fullMatrix<double> &normals,
                                                         fullMatrix<double> &JDJ) const
{
  getSignedJacAndGradientsGeneral(nJacNodes, gSMatX, gSMatY, gSMatZ, nodesXYZ, normals, JDJ);
}


void JacobianBasis::getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                             const fullMatrix<double> &nodesXYZStraight,
                                             fullVector<double> &lambdaJ, fullMatrix<double> &gradLambdaJ) const
{

  // jacobian of the straight elements (only triangles for now)
  SPoint3 v0(nodesXYZ(0, 0), nodesXYZ(0, 1), nodesXYZ(0, 2));
  SPoint3 v1(nodesXYZ(1, 0), nodesXYZ(1, 1), nodesXYZ(1, 2));
  SPoint3 v2(nodesXYZ(2, 0), nodesXYZ(2, 1), nodesXYZ(2, 2));
  SPoint3 *IXYZ[3] = {&v0, &v1, &v2};
  double jaci[2][2] = {
    {IXYZ[1]->x() - IXYZ[0]->x(), IXYZ[2]->x() - IXYZ[0]->x()},
    {IXYZ[1]->y() - IXYZ[0]->y(), IXYZ[2]->y() - IXYZ[0]->y()}
  };
  double invJaci[2][2];
  inv2x2(jaci, invJaci);

  for (int l = 0; l < numJacNodes; l++) {
    double jac[2][2] = {{0., 0.}, {0., 0.}};
    for (int i = 0; i < numMapNodes; i++) {
      const double &dPhidX = _gradBasis->gradShapeMatX(l, i);
      const double &dPhidY = _gradBasis->gradShapeMatY(l, i);
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
    const double osqr = sqr > 1e-8 ? 1/sqr : 0;
    lambdaJ(l) = 0.5 * (dxdx + dydy - sqr);
    const double axx = (1 - (dxdx - dydy) * osqr) * jac[0][0] - 2 * dxdy * osqr * jac[1][0];
    const double axy = (1 - (dxdx - dydy) * osqr) * jac[0][1] - 2 * dxdy * osqr * jac[1][1];
    const double ayx = -2 * dxdy * osqr * jac[0][0] + (1 - (dydy - dxdx) * osqr) * jac[1][0];
    const double ayy = -2 * dxdy * osqr * jac[0][1] + (1 - (dydy - dxdx) * osqr) * jac[1][1];
    const double axixi   = axx * invJaci[0][0] + axy * invJaci[0][1];
    const double aetaeta = ayx * invJaci[1][0] + ayy * invJaci[1][1];
    const double aetaxi  = ayx * invJaci[0][0] + ayy * invJaci[0][1];
    const double axieta  = axx * invJaci[1][0] + axy * invJaci[1][1];
    for (int i = 0; i < numMapNodes; i++) {
      const double &dPhidX = _gradBasis->gradShapeMatX(l, i);
      const double &dPhidY = _gradBasis->gradShapeMatY(l, i);
      gradLambdaJ(l, i + 0 * numMapNodes) = axixi * dPhidX + axieta * dPhidY;
      gradLambdaJ(l, i + 1 * numMapNodes) = aetaxi * dPhidX + aetaeta * dPhidY;
    }
  }
}

void JacobianBasis::lag2Bez(const fullVector<double> &lag,
                                   fullVector<double> &bez) const
{
  getBezier()->matrixLag2Bez.mult(lag, bez);
}

void JacobianBasis::lag2Bez(const fullMatrix<double> &lag,
                                   fullMatrix<double> &bez) const
{
  getBezier()->matrixLag2Bez.mult(lag, bez);
}

// Research purpose (to be removed ?)
void JacobianBasis::interpolate(const fullVector<double> &jacobian,
                                const fullMatrix<double> &uvw,
                                fullMatrix<double> &result,
                                bool areBezier) const
{
  fullMatrix<double> bezM(jacobian.size(), 1);
  fullVector<double> bez;
  bez.setAsProxy(bezM, 0);

  if (areBezier)
    bez.setAll(jacobian);
  else
    lag2Bez(jacobian, bez);

  getBezier()->interpolate(bezM, uvw, result);
}

int JacobianBasis::jacobianOrder(int tag)
{
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int order = ElementType::OrderFromTag(tag);
  return jacobianOrder(parentType, order);
}

int JacobianBasis::jacobianOrder(int parentType, int order)
{
  switch (parentType) {
    case TYPE_PNT : return 0;
    case TYPE_LIN : return order - 1;
    case TYPE_TRI : return 2*order - 2;
    case TYPE_QUA : return 2*order - 1;
    case TYPE_TET : return 3*order - 3;
    case TYPE_PRI : return 3*order - 1;
    case TYPE_HEX : return 3*order - 1;
    case TYPE_PYR : return 3*order - 3;
    // note : for the pyramid, the jacobian space is
    // different from the space of the mapping
    default :
      Msg::Error("Unknown element type %d, return order 0", parentType);
      return 0;
  }
}

FuncSpaceData JacobianBasis::jacobianMatrixSpace(int type, int order)
{
  if (type == TYPE_PYR) {
    Msg::Fatal("jacobianMatrixSpace not yet implemented for pyramids");
    return FuncSpaceData(false, type, false, 1, 0);
  }
  int jacOrder = -1;
  switch (type) {
    case TYPE_PNT :
      jacOrder = 0;
      break;

    case TYPE_LIN :
    case TYPE_TRI :
    case TYPE_TET :
      jacOrder = order - 1;
      break;

    case TYPE_QUA :
    case TYPE_PRI :
    case TYPE_HEX :
      jacOrder = order;
      break;

    default :
      Msg::Error("Unknown element type %d, return order 0", type);
      return 0;
  }

  return FuncSpaceData(true, ElementType::getTag(type, order), jacOrder);
}
