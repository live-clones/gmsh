// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "JacobianBasis.h"

#include "GmshDefines.h"
#include "GmshMessage.h"

#include <vector>
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "Numeric.h"

namespace {

// Compute the determinant of a 3x3 matrix
inline double calcDet3D(double M11, double M12, double M13,
                        double M21, double M22, double M23,
                        double M31, double M32, double M33)
{
  return M11 * (M22*M33 - M23*M32)
       - M12 * (M21*M33 - M23*M31)
       + M13 * (M21*M32 - M22*M31);
}

// Compute the squared Frobenius norm a matrix
inline double calcFrobNormSq3D(double M11, double M12, double M13,
                               double M21, double M22, double M23,
                               double M31, double M32, double M33)
{
  return M11*M11 + M12*M12 + M13*M13
       + M21*M21 + M22*M22 + M23*M23
       + M31*M31 + M32*M32 + M33*M33;
}

// Compute the squared Frobenius norm of the inverse of a matrix
inline double calcFrobNormSqInv3D(double M11, double M12, double M13,
                                  double M21, double M22, double M23,
                                  double M31, double M32, double M33)
{
  const double invD = 1./calcDet3D(M11, M12, M13, M21, M22, M23, M31, M32, M33);
  const double I11 = M22*M33-M23*M32, I12 = M13*M32-M12*M33, I13 = M12*M23-M13*M22,
               I21 = M23*M31-M21*M33, I22 = M11*M33-M13*M31, I23 = M13*M21-M11*M23,
               I31 = M21*M32-M22*M31, I32 = M12*M31-M11*M32, I33 = M11*M22-M12*M21;
  return (I11*I11 + I12*I12 + I13*I13
        + I21*I21 + I22*I22 + I23*I23
        + I31*I31 + I32*I32 + I33*I33)*invD*invD;
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

// Compute inverse condition number and its gradients
// w.r.t. node positions, at one location in a 1D element
inline void calcIDI1D(double dxdX, double dxdY, double dxdZ,
                      double dydX, double dydY, double dydZ,
                      double dzdX, double dzdY, double dzdZ,
                      int i, int numMapNodes,
                      const fullMatrix<double> &gSMatX,
                      const fullMatrix<double> &JDJ,
                      fullMatrix<double> &IDI)
{
  const double &J = JDJ(i, 3*numMapNodes), JSq = J*J, JQuadInv = 1./(JSq*JSq);
  const double A1 = dydY*dzdZ - dydZ*dzdY, A2 = dydX*dzdZ - dydZ*dzdX,
               A3 = dxdY*dzdZ - dxdZ*dzdY, A4 = dxdX*dzdZ - dxdZ*dzdX,
               A5 = dydX*dzdY - dydY*dzdX, A6 = dxdX*dzdY - dxdY*dzdX,
               A7 = dxdY*dydZ - dxdZ*dydY, A8 = dxdX*dydZ - dxdZ*dydX,
               A9 = dxdX*dydY - dxdY*dydX;
  const double A = A1*A1 + A2*A2 + A3*A3 + A4*A4 + A5*A5 + A6*A6 + A7*A7 + A8*A8 + A9*A9;
  const double nInvJSq = A/JSq;
  const double nJSq = dxdX*dxdX + dxdY*dxdY + dxdZ*dxdZ
                    + dydX*dydX + dydY*dydY + dydZ*dydZ
                    + dzdX*dzdX + dzdY*dzdY + dzdZ*dzdZ;
  const double invProd = 1./(nJSq*nInvJSq), sqrtInvProd = sqrt(invProd);
  IDI(i, 3*numMapNodes) = 3.*sqrtInvProd;
  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dJdxj = JDJ(i, j), &dJdyj = JDJ(i, j+numMapNodes),
                 &dJdzj = JDJ(i, j+2*numMapNodes);
    const double dAdxj = 2.*(dPhidX*dzdZ * A4 + dPhidX*dzdY * A6
                           + dPhidX*dydZ * A8 + dPhidX*dydY * A9);
    const double dnInvJSqdxj = (dAdxj*JSq-2.*dJdxj*J*A)*JQuadInv;
    const double dnJSqdxj = 2.*dPhidX*dxdX;
    IDI(i, j) = -1.5 * (dnJSqdxj*nInvJSq+nJSq*dnInvJSqdxj)*invProd*sqrtInvProd;
    const double dAdyj = 2.*(dPhidX*dzdZ * A2 + dPhidX*dzdY * A5
                           - dxdZ*dPhidX * A8 - dxdY*dPhidX * A9);
    const double dnInvJSqdyj = (dAdyj*JSq-2.*dJdyj*J*A)*JQuadInv;
    const double dnJSqdyj = 2.*dPhidX*dydX;
    IDI(i, j+numMapNodes) = -1.5 * (dnJSqdyj*nInvJSq+nJSq*dnInvJSqdyj)*invProd*sqrtInvProd;
    const double dAdzj = 2.*(-dydZ*dPhidX * A2 - dxdZ*dPhidX * A4
                           - dydY*dPhidX * A5 - dxdY*dPhidX * A6);
    const double dnInvJSqdzj = (dAdzj*JSq-2.*dJdzj*J*A)*JQuadInv;
    const double dnJSqdzj = 2.*dPhidX*dzdX;
    IDI(i, j+2*numMapNodes) = -1.5 * (dnJSqdzj*nInvJSq + nJSq*dnInvJSqdzj) * invProd*sqrtInvProd;
  }
}

// Compute inverse condition number and its gradients
// w.r.t. node positions, at one location in a 2D element
// FIXME: Precision issues?
inline void calcIDI2D(double dxdX, double dxdY, double dxdZ,
                      double dydX, double dydY, double dydZ,
                      double dzdX, double dzdY, double dzdZ,
                      int i, int numMapNodes,
                      const fullMatrix<double> &gSMatX,
                      const fullMatrix<double> &gSMatY,
                      const fullMatrix<double> &JDJ,
                      fullMatrix<double> &IDI)
{
  const double &J = JDJ(i, 3*numMapNodes), JSq = J*J, JQuadInv = 1./(JSq*JSq);
  const double A1 = dydY*dzdZ - dydZ*dzdY, A2 = dydX*dzdZ - dydZ*dzdX,
               A3 = dxdY*dzdZ - dxdZ*dzdY, A4 = dxdX*dzdZ - dxdZ*dzdX,
               A5 = dydX*dzdY - dydY*dzdX, A6 = dxdX*dzdY - dxdY*dzdX,
               A7 = dxdY*dydZ - dxdZ*dydY, A8 = dxdX*dydZ - dxdZ*dydX,
               A9 = dxdX*dydY - dxdY*dydX;
  const double A = A1*A1 + A2*A2 + A3*A3 + A4*A4 + A5*A5 + A6*A6 + A7*A7 + A8*A8 + A9*A9;
  const double nInvJSq = A/JSq;
  const double nJSq = dxdX*dxdX + dxdY*dxdY + dxdZ*dxdZ
                    + dydX*dydX + dydY*dydY + dydZ*dydZ
                    + dzdX*dzdX + dzdY*dzdY + dzdZ*dzdZ;
  const double invProd = 1./(nJSq*nInvJSq), sqrtInvProd = sqrt(invProd);
  IDI(i, 3*numMapNodes) = 3.*sqrtInvProd;
  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dPhidY = gSMatY(i, j);
    const double &dJdxj = JDJ(i, j), &dJdyj = JDJ(i, j+numMapNodes),
                 &dJdzj = JDJ(i, j+2*numMapNodes);
    const double dAdxj = 2.*(dPhidY*dzdZ * A3 + dPhidX*dzdZ * A4
                           + (dPhidX*dzdY - dPhidY*dzdX) * A6 + dPhidY*dydZ * A7
                           + dPhidX*dydZ * A8 + (dPhidX*dydY - dPhidY*dydX) * A9);
    const double dnInvJSqdxj = (dAdxj*JSq-2.*dJdxj*J*A)*JQuadInv;
    const double dnJSqdxj = 2.*(dPhidX*dxdX + dPhidY*dxdY);
    IDI(i, j) = -1.5 * (dnJSqdxj*nInvJSq+nJSq*dnInvJSqdxj)*invProd*sqrtInvProd;
    const double dAdyj = 2.*(dPhidY*dzdZ * A1 + dPhidX*dzdZ * A2
                           + (dPhidX*dzdY - dPhidY*dzdX) * A5 - dxdZ*dPhidY * A7
                           - dxdZ*dPhidX * A8 + (dxdX*dPhidY - dxdY*dPhidX) * A9);
    const double dnInvJSqdyj = (dAdyj*JSq-2.*dJdyj*J*A)*JQuadInv;
    const double dnJSqdyj = 2.*(dPhidX*dydX + dPhidY*dydY);
    IDI(i, j+numMapNodes) = -1.5 * (dnJSqdyj*nInvJSq+nJSq*dnInvJSqdyj)*invProd*sqrtInvProd;
    const double dAdzj = 2.*(-dydZ*dPhidY * A1 - dydZ*dPhidX * A2
                           - dxdZ*dPhidY * A3 - dxdZ*dPhidX * A4
                           + (dydX*dPhidY - dydY*dPhidX) * A5 + (dxdX*dPhidY - dxdY*dPhidX) * A6);
    const double dnInvJSqdzj = (dAdzj*JSq-2.*dJdzj*J*A)*JQuadInv;
    const double dnJSqdzj = 2.*(dPhidX*dzdX + dPhidY*dzdY);
    IDI(i, j+2*numMapNodes) = -1.5 * (dnJSqdzj*nInvJSq + nJSq*dnInvJSqdzj) * invProd*sqrtInvProd;
  }
}

// Compute inverse condition number and its gradients
// w.r.t. node positions, at one location in a 3D element
inline void calcIDI3D(double dxdX, double dxdY, double dxdZ,
                      double dydX, double dydY, double dydZ,
                      double dzdX, double dzdY, double dzdZ,
                      int i, int numMapNodes,
                      const fullMatrix<double> &gSMatX,
                      const fullMatrix<double> &gSMatY,
                      const fullMatrix<double> &gSMatZ,
                      const fullMatrix<double> &JDJ,
                      fullMatrix<double> &IDI)
{
  const double &J = JDJ(i, 3*numMapNodes), JSq = J*J, JQuadInv = 1./(JSq*JSq);
  const double A1 = dydY*dzdZ - dydZ*dzdY, A2 = dydX*dzdZ - dydZ*dzdX,
               A3 = dxdY*dzdZ - dxdZ*dzdY, A4 = dxdX*dzdZ - dxdZ*dzdX,
               A5 = dydX*dzdY - dydY*dzdX, A6 = dxdX*dzdY - dxdY*dzdX,
               A7 = dxdY*dydZ - dxdZ*dydY, A8 = dxdX*dydZ - dxdZ*dydX,
               A9 = dxdX*dydY - dxdY*dydX;
  const double A = A1*A1 + A2*A2 + A3*A3 + A4*A4 + A5*A5 + A6*A6 + A7*A7 + A8*A8 + A9*A9;
  const double nInvJSq = A/JSq;
  const double nJSq = dxdX*dxdX + dxdY*dxdY + dxdZ*dxdZ
                    + dydX*dydX + dydY*dydY + dydZ*dydZ
                    + dzdX*dzdX + dzdY*dzdY + dzdZ*dzdZ;
  const double invProd = 1./(nJSq*nInvJSq), sqrtInvProd = sqrt(invProd);
  IDI(i, 3*numMapNodes) = 3.*sqrtInvProd;
  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dPhidY = gSMatY(i, j);
    const double &dPhidZ = gSMatZ(i, j);
    const double &dJdxj = JDJ(i, j), &dJdyj = JDJ(i, j+numMapNodes),
                 &dJdzj = JDJ(i, j+2*numMapNodes);
    const double dAdxj = 2.*((dPhidY*dzdZ - dPhidZ*dzdY) * A3 + (dPhidX*dzdZ - dPhidZ*dzdX) * A4
                           + (dPhidX*dzdY - dPhidY*dzdX) * A6 + (dPhidY*dydZ - dPhidZ*dydY) * A7
                           + (dPhidX*dydZ - dPhidZ*dydX) * A8 + (dPhidX*dydY - dPhidY*dydX) * A9);
    const double dnInvJSqdxj = (dAdxj*JSq-2.*dJdxj*J*A)*JQuadInv;
    const double dnJSqdxj = 2.*(dPhidX*dxdX + dPhidY*dxdY + dPhidZ*dxdZ);
    IDI(i, j) = -1.5*(dnJSqdxj*nInvJSq+nJSq*dnInvJSqdxj)*invProd*sqrtInvProd;
    const double dAdyj = 2.*((dPhidY*dzdZ - dPhidZ*dzdY) * A1 + (dPhidX*dzdZ - dPhidZ*dzdX) * A2
                           + (dPhidX*dzdY - dPhidY*dzdX) * A5 + (dxdY*dPhidZ - dxdZ*dPhidY) * A7
                           + (dxdX*dPhidZ - dxdZ*dPhidX) * A8 + (dxdX*dPhidY - dxdY*dPhidX) * A9);
    const double dnInvJSqdyj = (dAdyj*JSq-2.*dJdyj*J*A)*JQuadInv;
    const double dnJSqdyj = 2.*(dPhidX*dydX + dPhidY*dydY + dPhidZ*dydZ);
    IDI(i, j+numMapNodes) = -1.5*(dnJSqdyj*nInvJSq+nJSq*dnInvJSqdyj)*invProd*sqrtInvProd;
    const double dAdzj = 2.*((dydY*dPhidZ - dydZ*dPhidY) * A1 + (dydX*dPhidZ - dydZ*dPhidX) * A2
                           + (dxdY*dPhidZ - dxdZ*dPhidY) * A3 + (dxdX*dPhidZ - dxdZ*dPhidX) * A4
                           + (dydX*dPhidY - dydY*dPhidX) * A5 + (dxdX*dPhidY - dxdY*dPhidX) * A6);
    const double dnInvJSqdzj = (dAdzj*JSq-2.*dJdzj*J*A)*JQuadInv;
    const double dnJSqdzj = 2.*(dPhidX*dzdX + dPhidY*dzdY + dPhidZ*dzdZ);
    IDI(i, j+2*numMapNodes) = -1.5 * (dnJSqdzj*nInvJSq + nJSq*dnInvJSqdzj) * invProd*sqrtInvProd;
  }
}

}

GradientBasis::GradientBasis(int tag, int order) :
    _type(ElementType::ParentTypeFromTag(tag)),
    _idealDifferent(_type == TYPE_TRI || _type == TYPE_PRI ||
                    _type == TYPE_TET || _type == TYPE_PYR)
{
  const int type = ElementType::ParentTypeFromTag(tag);

  fullMatrix<double> samplingPoints;

  switch (type) {
    case TYPE_PNT :
      samplingPoints = gmshGeneratePointsLine(0);
      break;
    case TYPE_LIN :
      samplingPoints = gmshGeneratePointsLine(order);
      break;
    case TYPE_TRI :
      samplingPoints = gmshGeneratePointsTriangle(order,false);
      break;
    case TYPE_QUA :
      samplingPoints = gmshGeneratePointsQuadrangle(order,false);
      break;
    case TYPE_TET :
      samplingPoints = gmshGeneratePointsTetrahedron(order,false);
      break;
    case TYPE_PRI :
      samplingPoints = gmshGeneratePointsPrism(order,false);
      break;
    case TYPE_HEX :
      samplingPoints = gmshGeneratePointsHexahedron(order,false);
      break;
    case TYPE_PYR :
      samplingPoints = gmshGeneratePointsPyramidGeneral(false, order+2, order);
      break;
    default :
      Msg::Error("Unknown Jacobian function space for element tag %d", tag);
      return;
  }
  const int numSampPnts = samplingPoints.size1();

  // Store shape function gradients of mapping at Jacobian nodes
  fullMatrix<double> allDPsi;
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(tag);
  mapBasis->df(samplingPoints, allDPsi);
  const int numMapNodes = allDPsi.size1();

  gradShapeMatX.resize(numSampPnts, numMapNodes);
  gradShapeMatY.resize(numSampPnts, numMapNodes);
  gradShapeMatZ.resize(numSampPnts, numMapNodes);
  for (int i=0; i<numSampPnts; i++) {
    for (int j=0; j<numMapNodes; j++) {
      gradShapeMatX(i, j) = allDPsi(j, 3*i);
      gradShapeMatY(i, j) = allDPsi(j, 3*i+1);
      gradShapeMatZ(i, j) = allDPsi(j, 3*i+2);
    }
  }
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

void GradientBasis::mapFromIdealElement(fullMatrix<double> *dxyzdX,
                                        fullMatrix<double> *dxyzdY,
                                        fullMatrix<double> *dxyzdZ) const
{
  if (_idealDifferent) {
    if (_type == TYPE_PYR) {
      dxyzdZ->scale(.5);
      return;
    }

    static const double cTri[2] = {-1./std::sqrt(3), 2./std::sqrt(3)};
    dxyzdY->scale(cTri[1]);
    dxyzdY->axpy(*dxyzdX, cTri[0]);

    switch(_type) {
    case TYPE_TRI:
      return;

    case TYPE_PRI:
      dxyzdZ->scale(2);
      return;

    case TYPE_TET:
    {
      static const double cTet[3] = {-1.5/sqrt(6), -0.75/sqrt(2), 3./sqrt(6)};
      dxyzdZ->scale(cTet[2]);
      dxyzdZ->axpy(*dxyzdX, cTet[0]);
      dxyzdZ->axpy(*dxyzdY, cTet[1]);
    }
    }
  }
}

// Given Jac. det. from reference element, compute Jac. det. from ideal element
void GradientBasis::detJacFromIdealElement(double &dJ) const
{
  static const double TriFact = 2./sqrt(3.), TetFact = sqrt(2.);
  if (_idealDifferent) {
    switch(_type) {
    case TYPE_TRI: dJ *= TriFact; return;
    case TYPE_PRI: dJ *= 0.5; return;
    case TYPE_TET: dJ *= TetFact; return;
    case TYPE_PYR: dJ *= 2.; return;
    }
  }
}

JacobianBasis::JacobianBasis(int tag, int jacOrder) :
    _bezier(NULL), _tag(tag), _dim(ElementType::DimensionFromTag(tag)),
    _jacOrder(jacOrder >= 0 ? jacOrder : jacobianOrder(tag))
{
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int primJacobianOrder = jacobianOrder(parentType, 1);

  fullMatrix<double> lagPoints;                                  // Sampling points

  switch (parentType) {
    case TYPE_PNT :
      lagPoints = gmshGeneratePointsLine(0);
      break;
    case TYPE_LIN :
      lagPoints = gmshGeneratePointsLine(_jacOrder);
      break;
    case TYPE_TRI :
      lagPoints = gmshGeneratePointsTriangle(_jacOrder,false);
      break;
    case TYPE_QUA :
      lagPoints = gmshGeneratePointsQuadrangle(_jacOrder,false);
      break;
    case TYPE_TET :
      lagPoints = gmshGeneratePointsTetrahedron(_jacOrder,false);
      break;
    case TYPE_PRI :
      lagPoints = gmshGeneratePointsPrism(_jacOrder,false);
      break;
    case TYPE_HEX :
      lagPoints = gmshGeneratePointsHexahedron(_jacOrder,false);
      break;
    case TYPE_PYR :
      lagPoints = gmshGeneratePointsPyramidGeneral(false, _jacOrder+2, _jacOrder);
      break;
    default :
      Msg::Error("Unknown Jacobian function space for element tag %d", tag);
      return;
  }
  numJacNodes = lagPoints.size1();

  // Store shape function gradients of mapping at Jacobian nodes
  _gradBasis = BasisFactory::getGradientBasis(tag, _jacOrder);

  // Compute matrix for lifting from primary Jacobian basis to Jacobian basis
  int primJacType = ElementType::getTag(parentType, primJacobianOrder, false);
  const nodalBasis *primJacBasis = BasisFactory::getNodalBasis(primJacType);
  numPrimJacNodes = primJacBasis->getNumShapeFunctions();

  matrixPrimJac2Jac.resize(numJacNodes,numPrimJacNodes);
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

  primGradShapeBarycenterX.resize(numPrimMapNodes);
  primGradShapeBarycenterY.resize(numPrimMapNodes);
  primGradShapeBarycenterZ.resize(numPrimMapNodes);
  for (int j=0; j<numPrimMapNodes; j++) {
    primGradShapeBarycenterX(j) = barDPsi[j][0];
    primGradShapeBarycenterY(j) = barDPsi[j][1];
    primGradShapeBarycenterZ(j) = barDPsi[j][2];
  }

  delete[] barDPsi;

  // Compute "fast" Jacobian evaluation matrices (at 1st order nodes + barycenter)
  numJacNodesFast = numPrimMapNodes+1;
  fullMatrix<double> lagPointsFast(numJacNodesFast,3);                                  // Sampling points
  lagPointsFast.copy(primMapBasis->points,0,numPrimMapNodes,
                     0,primMapBasis->points.size2(),0,0);                               // 1st order nodes
  lagPointsFast(numPrimMapNodes,0) = barycenter[0];                                     // Last point = barycenter
  lagPointsFast(numPrimMapNodes,1) = barycenter[1];
  lagPointsFast(numPrimMapNodes,2) = barycenter[2];

  fullMatrix<double> allDPsiFast;
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(tag);
  mapBasis->df(lagPointsFast, allDPsiFast);
  numMapNodes = mapBasis->getNumShapeFunctions();

  gradShapeMatXFast.resize(numJacNodesFast, numMapNodes);
  gradShapeMatYFast.resize(numJacNodesFast, numMapNodes);
  gradShapeMatZFast.resize(numJacNodesFast, numMapNodes);
  for (int i=0; i<numJacNodesFast; i++) {
    for (int j=0; j<numMapNodes; j++) {
      gradShapeMatXFast(i, j) = allDPsiFast(j, 3*i);
      gradShapeMatYFast(i, j) = allDPsiFast(j, 3*i+1);
      gradShapeMatZFast(i, j) = allDPsiFast(j, 3*i+2);
    }
  }
}

const bezierBasis* JacobianBasis::getBezier() const {
  if (_bezier) return _bezier;
  const int parentType = ElementType::ParentTypeFromTag(_tag);
  const_cast<JacobianBasis*>(this)->_bezier =
      BasisFactory::getBezierBasis(parentType, _jacOrder);
  return _bezier;
}

// Computes (unit) normals to straight line element at barycenter (with norm of gradient as return value)
double JacobianBasis::getPrimNormals1D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const
{

  fullVector<double> dxyzdXbar(3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBarycenterX(j)*nodesXYZ(j,0);
    dxyzdXbar(1) += primGradShapeBarycenterX(j)*nodesXYZ(j,1);
    dxyzdXbar(2) += primGradShapeBarycenterX(j)*nodesXYZ(j,2);
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
double JacobianBasis::getPrimNormal2D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result, bool ideal) const
{
  fullVector<double> dxyzdXbar(3), dxyzdYbar(3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBarycenterX(j)*nodesXYZ(j,0);
    dxyzdXbar(1) += primGradShapeBarycenterX(j)*nodesXYZ(j,1);
    dxyzdXbar(2) += primGradShapeBarycenterX(j)*nodesXYZ(j,2);
    dxyzdYbar(0) += primGradShapeBarycenterY(j)*nodesXYZ(j,0);
    dxyzdYbar(1) += primGradShapeBarycenterY(j)*nodesXYZ(j,1);
    dxyzdYbar(2) += primGradShapeBarycenterY(j)*nodesXYZ(j,2);
  }

  result(0,2) = dxyzdXbar(0) * dxyzdYbar(1) - dxyzdXbar(1) * dxyzdYbar(0);
  result(0,1) = -dxyzdXbar(0) * dxyzdYbar(2) + dxyzdXbar(2) * dxyzdYbar(0);
  result(0,0) = dxyzdXbar(1) * dxyzdYbar(2) - dxyzdXbar(2) * dxyzdYbar(1);
  double norm0 = sqrt(result(0,0)*result(0,0)+result(0,1)*result(0,1)+result(0,2)*result(0,2));
  const double invNorm0 = 1./norm0;
  result(0,0) *= invNorm0; result(0,1) *= invNorm0; result(0,2) *= invNorm0;

  if (ideal) _gradBasis->detJacFromIdealElement(norm0);
  return norm0;
}

// Returns absolute value of Jacobian of straight volume element at barycenter
double JacobianBasis::getPrimJac3D(const fullMatrix<double> &nodesXYZ, bool ideal) const
{
  double dxdX = 0, dydX = 0, dzdX = 0, dxdY = 0, dydY = 0, dzdY = 0, dxdZ = 0, dydZ = 0, dzdZ = 0;
  for (int j=0; j<numPrimMapNodes; j++) {
    dxdX += primGradShapeBarycenterX(j)*nodesXYZ(j,0);
    dydX += primGradShapeBarycenterX(j)*nodesXYZ(j,1);
    dzdX += primGradShapeBarycenterX(j)*nodesXYZ(j,2);
    dxdY += primGradShapeBarycenterY(j)*nodesXYZ(j,0);
    dydY += primGradShapeBarycenterY(j)*nodesXYZ(j,1);
    dzdY += primGradShapeBarycenterY(j)*nodesXYZ(j,2);
    dxdZ += primGradShapeBarycenterZ(j)*nodesXYZ(j,0);
    dydZ += primGradShapeBarycenterZ(j)*nodesXYZ(j,1);
    dzdZ += primGradShapeBarycenterZ(j)*nodesXYZ(j,2);
  }

  double dJ = fabs(calcDet3D(dxdX, dxdY, dxdZ,
                             dydX, dydY, dydZ,
                             dzdX, dzdY, dzdZ));
  if (ideal) _gradBasis->detJacFromIdealElement(dJ);
  return dJ;
}

// Calculate (signed, possibly scaled) Jacobian for one element, with normal vectors to straight element
// for regularization. Evaluation points depend on the given matrices for shape function gradients.
template<bool scaling, bool ideal>
inline void JacobianBasis::getJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                              const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                              const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const
{
  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nJacNodes; i++) jacobian(i) = 1.;
      break;
    }

    case 1 : {
      fullMatrix<double> normals(2,3);
      const double invScale = getPrimNormals1D(nodesXYZ,normals);
      if (scaling) {
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
      const double invScale = getPrimNormal2D(nodesXYZ,normal);
      if (scaling) {
        const double scale = 1./invScale;
        normal(0,0) *= scale; normal(0,1) *= scale; normal(0,2) *= scale;               // Faster to scale normal than afterwards
      }
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, NULL);
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
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, &dxyzdZ);
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

// Calculate signed Jacobian for one element, with normal vectors to straight element for
// regularization. Evaluation points depend on the given matrices for shape function gradients.
void JacobianBasis::getSignedJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                             const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                             const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const
{
  getJacobianGeneral<false, false>(nJacNodes, gSMatX,  gSMatY, gSMatZ, nodesXYZ, jacobian);
}

// Calculate (signed) scaled Jacobian for one element, with normal vectors to straight element
// for regularization. Evaluation points depend on the given matrices for shape function gradients.
void JacobianBasis::getScaledJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                             const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                             const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const
{
  getJacobianGeneral<true, false>(nJacNodes, gSMatX,  gSMatY, gSMatZ, nodesXYZ, jacobian);
}

// Calculate (signed, possibly scaled) Jacobian for several elements, with normal vectors to straight
// elements for regularization. Evaluation points depend on the given matrices for shape function gradients.
// TODO: Optimize and test 1D & 2D
template<bool scaling, bool ideal>
inline void JacobianBasis::getJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                              const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                              const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                              const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const
{
  switch (_dim) {

    case 0 : {
      const int numEl = nodesX.size2();
      for (int iEl = 0; iEl < numEl; iEl++)
        for (int i = 0; i < nJacNodes; i++) jacobian(i,iEl) = 1.;
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
        if (scaling) {
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
      if (ideal) {
        _gradBasis->mapFromIdealElement(&dxdX, &dxdY, NULL);
        _gradBasis->mapFromIdealElement(&dydX, &dydY, NULL);
        _gradBasis->mapFromIdealElement(&dzdX, &dzdY, NULL);
      }
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimMapNodes,3);
        for (int i = 0; i < numPrimMapNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normal(1,3);
        const double invScale = getPrimNormal2D(nodesXYZ,normal);
        if (scaling) {
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
      if (ideal) {
        _gradBasis->mapFromIdealElement(&dxdX, &dxdY, &dxdZ);
        _gradBasis->mapFromIdealElement(&dydX, &dydY, &dydZ);
        _gradBasis->mapFromIdealElement(&dzdX, &dzdY, &dzdZ);
      }
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

// Calculate signed Jacobian for several elements, with normal vectors to straight elements for
// regularization. Evaluation points depend on the given matrices for shape function gradients.
void JacobianBasis::getSignedJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                             const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                             const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                             const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const
{
  getJacobianGeneral<false, false>(nJacNodes, gSMatX,  gSMatY, gSMatZ, nodesX, nodesY, nodesZ, jacobian);
}

// Calculate (signed) scaled Jacobian for several elements, with normal vectors to straight elements
// for regularization. Evaluation points depend on the given matrices for shape function gradients.
void JacobianBasis::getScaledJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                             const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                             const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                             const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const
{
  getJacobianGeneral<true, false>(nJacNodes, gSMatX,  gSMatY, gSMatZ, nodesX, nodesY, nodesZ, jacobian);
}

// Calculate (signed) Jacobian and its gradients for one element, with normal vectors to straight element
// for regularization. Evaluation points depend on the given matrices for shape function gradients.
template<bool ideal>
inline void JacobianBasis::getSignedJacAndGradientsGeneral(int nJacNodes,
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
          JDJ (i,j) = 0.;
          JDJ (i,j+1*numMapNodes) = 0.;
          JDJ (i,j+2*numMapNodes) = 0.;
        }
        JDJ(i,3*numMapNodes) = 1.;
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
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, NULL);
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
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, &dxyzdZ);
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

// Calculate the inverse condition number in Frobenius norm for one element, with normal vectors to straight
// element for regularization. Evaluation points depend on the given matrices for shape function gradients.
template<bool ideal>
inline void JacobianBasis::getInvCondGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                            const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                            const fullMatrix<double> &nodesXYZ, fullVector<double> &invCond) const
{
  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nJacNodes; i++) invCond(i) = 1.;
      break;
    }

    case 1 : {
      fullMatrix<double> normals(2,3);
      getPrimNormals1D(nodesXYZ,normals);
      fullMatrix<double> dxyzdX(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        const double nJSq = calcFrobNormSq3D(dxdX, dxdY, dxdZ,
                                             dydX, dydY, dydZ,
                                             dzdX, dzdY, dzdZ);
        const double nInvJSq = calcFrobNormSqInv3D(dxdX, dxdY, dxdZ,
                                                   dydX, dydY, dydZ,
                                                   dzdX, dzdY, dzdZ);
        invCond(i) = 3./sqrt(nJSq*nInvJSq);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> normal(1,3);
      const double scaleSq = getPrimNormal2D(nodesXYZ, normal, ideal), scale = sqrt(scaleSq);
      normal(0, 0) *= scale; normal(0, 1) *= scale; normal(0, 2) *= scale;
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, NULL);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normal(0,0), &dydZ = normal(0,1), &dzdZ = normal(0,2);
        const double nJSq = calcFrobNormSq3D(dxdX, dxdY, dxdZ,
                                             dydX, dydY, dydZ,
                                             dzdX, dzdY, dzdZ);
        const double nInvJSq = calcFrobNormSqInv3D(dxdX, dxdY, dxdZ,
                                                   dydX, dydY, dydZ,
                                                   dzdX, dzdY, dzdZ);
        invCond(i) = 3./sqrt(nJSq*nInvJSq);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dum;
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3), dxyzdZ(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      gSMatZ.mult(nodesXYZ, dxyzdZ);
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, &dxyzdZ);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        const double nJSq = calcFrobNormSq3D(dxdX, dxdY, dxdZ,
                                             dydX, dydY, dydZ,
                                             dzdX, dzdY, dzdZ);
        const double nInvJSq = calcFrobNormSqInv3D(dxdX, dxdY, dxdZ,
                                                   dydX, dydY, dydZ,
                                                   dzdX, dzdY, dzdZ);
        invCond(i) = 3./sqrt(nJSq*nInvJSq);
     }
      break;
    }
  }
}

void JacobianBasis::getInvCondGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                      const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                      const fullMatrix<double> &nodesXYZ, fullVector<double> &invCond) const
{
  getInvCondGeneral<true>(nJacNodes, gSMatX,  gSMatY,  gSMatZ, nodesXYZ, invCond);
}

// Calculate the inverse condition number in Frobenius norm and its gradients w.r.t. node position,
// with normal vectors to straight element  for regularization. Evaluation points depend on the
// given matrices for shape function gradients.
template<bool ideal>
inline void JacobianBasis::getInvCondAndGradientsGeneral(int nJacNodes,
                                                         const fullMatrix<double> &gSMatX,
                                                         const fullMatrix<double> &gSMatY,
                                                         const fullMatrix<double> &gSMatZ,
                                                         const fullMatrix<double> &nodesXYZ,
                                                         const fullMatrix<double> &normals,
                                                         fullMatrix<double> &IDI) const
{
  fullMatrix<double> JDJ(nJacNodes, 3*numMapNodes+1);

  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nJacNodes; i++) {
        for (int j = 0; j < numMapNodes; j++) {
          IDI(i,j) = 0.;
          IDI(i,j+1*numMapNodes) = 0.;
          IDI(i,j+2*numMapNodes) = 0.;
        }
        IDI(i,3*numMapNodes) = 1.;
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
        calcIDI1D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, JDJ, IDI);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, NULL);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normals(0,0), &dydZ = normals(0,1), &dzdZ = normals(0,2);
        calcJDJ2D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, gSMatY, JDJ);
        calcIDI2D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, gSMatY, JDJ, IDI);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(nJacNodes,3), dxyzdY(nJacNodes,3), dxyzdZ(nJacNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      gSMatZ.mult(nodesXYZ, dxyzdZ);
      if (ideal) _gradBasis->mapFromIdealElement(&dxyzdX, &dxyzdY, &dxyzdZ);
      for (int i = 0; i < nJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        calcJDJ3D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, gSMatY, gSMatZ, JDJ);
        calcIDI3D(dxdX, dxdY, dxdZ,
                  dydX, dydY, dydZ,
                  dzdX, dzdY, dzdZ,
                  i, numMapNodes,
                  gSMatX, gSMatY, gSMatZ, JDJ, IDI);
      }
      break;
    }
  }
}

void JacobianBasis::getInvCondAndGradientsGeneral(int nJacNodes,
                                                  const fullMatrix<double> &gSMatX,
                                                  const fullMatrix<double> &gSMatY,
                                                  const fullMatrix<double> &gSMatZ,
                                                  const fullMatrix<double> &nodesXYZ,
                                                  const fullMatrix<double> &normals,
                                                  fullMatrix<double> &IDI) const
{
  getInvCondAndGradientsGeneral<true>(nJacNodes, gSMatX, gSMatY, gSMatZ, nodesXYZ, normals, IDI);
}

void JacobianBasis::getSignedJacAndGradientsGeneral(int nJacNodes,
                                                           const fullMatrix<double> &gSMatX,
                                                           const fullMatrix<double> &gSMatY,
                                                           const fullMatrix<double> &gSMatZ,
                                                           const fullMatrix<double> &nodesXYZ,
                                                           const fullMatrix<double> &normals,
                                                           fullMatrix<double> &JDJ) const
{
  getSignedJacAndGradientsGeneral<false>(nJacNodes, gSMatX, gSMatY, gSMatZ, nodesXYZ, normals, JDJ);
}


void JacobianBasis::getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                             const fullMatrix<double> &nodesXYZStraight,
                                             fullVector<double> &lambdaJ, fullMatrix<double> &gradLambdaJ) const
{

  // jacobian of the straight elements (only triangles for now)
  SPoint3 v0(nodesXYZ(0,0),nodesXYZ(0,1),nodesXYZ(0,2));
  SPoint3 v1(nodesXYZ(1,0),nodesXYZ(1,1),nodesXYZ(1,2));
  SPoint3 v2(nodesXYZ(2,0),nodesXYZ(2,1),nodesXYZ(2,2));
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
      const double &dPhidX = _gradBasis->gradShapeMatX(l,i);
      const double &dPhidY = _gradBasis->gradShapeMatY(l,i);
      const double dpsidx = dPhidX * invJaci[0][0] + dPhidY * invJaci[1][0];
      const double dpsidy = dPhidX * invJaci[0][1] + dPhidY * invJaci[1][1];
      jac[0][0] += nodesXYZ(i,0) * dpsidx;
      jac[0][1] += nodesXYZ(i,0) * dpsidy;
      jac[1][0] += nodesXYZ(i,1) * dpsidx;
      jac[1][1] += nodesXYZ(i,1) * dpsidy;
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
      const double &dPhidX = _gradBasis->gradShapeMatX(l,i);
      const double &dPhidY = _gradBasis->gradShapeMatY(l,i);
      gradLambdaJ(l, i + 0 * numMapNodes) = axixi * dPhidX + axieta * dPhidY;
      gradLambdaJ(l, i + 1 * numMapNodes) = aetaxi * dPhidX + aetaeta * dPhidY;
    }
  }
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


