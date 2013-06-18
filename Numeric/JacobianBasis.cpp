// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshDefines.h"
#include "GmshMessage.h"

#include <vector>
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "Numeric.h"


JacobianBasis::JacobianBasis(int tag)
{
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int order = ElementType::OrderFromTag(tag);

  int jacType = 0, primJacType = 0;

  /*if (parentType == TYPE_PYR) {
    switch (tag) {
    case MSH_PYR_5 : jacType = MSH_PYR_14; primJacType = MSH_PYR_14; break;   // TODO: Order 1, Jac. "order" 2, check this
    case MSH_PYR_14 : jacType = MSH_PYR_91; primJacType = MSH_PYR_14; break;  // TODO: Order 2, Jac. "order" 5, check this
    case MSH_PYR_30 : jacType = MSH_PYR_285; primJacType = MSH_PYR_14; break; // TODO: Order 3, Jac. "order" 8, check this
    default :
      Msg::Error("Unknown Jacobian function space for element type %d", tag);
      break;
    }
  }
  else {*/
    int jacobianOrder, primJacobianOrder;
    switch (parentType) {
      case TYPE_PNT : jacobianOrder = 0; primJacobianOrder = 0; break;
      case TYPE_LIN : jacobianOrder = order - 1; primJacobianOrder = 0; break;
      case TYPE_TRI : jacobianOrder = 2 * (order - 1); primJacobianOrder = 0; break;
      case TYPE_QUA : jacobianOrder = 2 * order - 1; primJacobianOrder = 1; break;
      case TYPE_TET : jacobianOrder = 3 * (order - 1); primJacobianOrder = 0; break;
      case TYPE_PRI : jacobianOrder = 3 * order - 1; primJacobianOrder = 2; break;
      case TYPE_HEX : jacobianOrder = 3 * order - 1; primJacobianOrder = 2; break;
      default :
        Msg::Error("Unknown Jacobian function space for element type %d", tag);
        jacobianOrder = 0;
        break;
    }
    jacType = ElementType::getTag(parentType, jacobianOrder, false);
    primJacType = ElementType::getTag(parentType, primJacobianOrder, false);
  //}

  // Store Bezier basis
  bezier = BasisFactory::getBezierBasis(jacType);

  // Store shape function gradients of mapping at Jacobian nodes
  const nodalBasis *mapBasis = BasisFactory::getNodalBasis(tag);
  fullMatrix<double> allDPsi;
  mapBasis->df(getPoints(), allDPsi);
  numJacNodes = getPoints().size1();
  numMapNodes = allDPsi.size1();
  gradShapeMatX.resize(numJacNodes,numMapNodes);
  gradShapeMatY.resize(numJacNodes,numMapNodes);
  gradShapeMatZ.resize(numJacNodes,numMapNodes);
  for (int i=0; i<numJacNodes; i++)
    for (int j=0; j<numMapNodes; j++) {
      gradShapeMatX(i,j) = allDPsi(j,3*i);
      gradShapeMatY(i,j) = allDPsi(j,3*i+1);
      gradShapeMatZ(i,j) = allDPsi(j,3*i+2);
    }

  // Compute matrix for lifting from primary Jacobian basis to Jacobian basis
  const nodalBasis *primJacBasis = BasisFactory::getNodalBasis(primJacType);
  numPrimJacNodes = primJacBasis->getNumShapeFunctions();
  matrixPrimJac2Jac.resize(numJacNodes,numPrimJacNodes);
  primJacBasis->f(getPoints(),matrixPrimJac2Jac);

  // Compute shape function gradients of primary mapping at barycenter,
  // in order to compute normal to straight element
  const int primMapType = ElementType::getTag(parentType, 1, false);
  const nodalBasis *primMapBasis = BasisFactory::getNodalBasis(primMapType);
  numPrimMapNodes = primMapBasis->getNumShapeFunctions();
  double xBar = 0., yBar = 0., zBar = 0.;
  for (int i=0; i<numPrimMapNodes; i++) {
    xBar += primMapBasis->points(i,0);
    yBar += primMapBasis->points(i,1);
    if (primMapBasis->points.size2() > 2)
      zBar +=  primMapBasis->points(i,2);
  }
  xBar /= numPrimMapNodes;
  yBar /= numPrimMapNodes;
  zBar /= numPrimMapNodes;
  double (*barDPsi)[3] = new double[numPrimMapNodes][3];
  primMapBasis->df(xBar, yBar, zBar, barDPsi);
  primGradShapeBarX.resize(numPrimMapNodes);
  primGradShapeBarY.resize(numPrimMapNodes);
  primGradShapeBarZ.resize(numPrimMapNodes);
  for (int j=0; j<numPrimMapNodes; j++) {
    primGradShapeBarX(j) = barDPsi[j][0];
    primGradShapeBarY(j) = barDPsi[j][1];
    primGradShapeBarZ(j) = barDPsi[j][2];
  }
  delete[] barDPsi;

}

// Computes (unit) normals to straight line element at barycenter (with norm of gradient as return value)
double JacobianBasis::getPrimNormals1D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const
{

  fullVector<double> dxyzdXbar(3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBarX(j)*nodesXYZ(j,0);
    dxyzdXbar(1) += primGradShapeBarX(j)*nodesXYZ(j,1);
    dxyzdXbar(2) += primGradShapeBarX(j)*nodesXYZ(j,2);
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
double JacobianBasis::getPrimNormal2D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const
{

  fullVector<double> dxyzdXbar(3), dxyzdYbar(3);
  for (int j=0; j<numPrimMapNodes; j++) {
    dxyzdXbar(0) += primGradShapeBarX(j)*nodesXYZ(j,0);
    dxyzdXbar(1) += primGradShapeBarX(j)*nodesXYZ(j,1);
    dxyzdXbar(2) += primGradShapeBarX(j)*nodesXYZ(j,2);
    dxyzdYbar(0) += primGradShapeBarY(j)*nodesXYZ(j,0);
    dxyzdYbar(1) += primGradShapeBarY(j)*nodesXYZ(j,1);
    dxyzdYbar(2) += primGradShapeBarY(j)*nodesXYZ(j,2);
  }

  result(0,2) = dxyzdXbar(0) * dxyzdYbar(1) - dxyzdXbar(1) * dxyzdYbar(0);
  result(0,1) = -dxyzdXbar(0) * dxyzdYbar(2) + dxyzdXbar(2) * dxyzdYbar(0);
  result(0,0) = dxyzdXbar(1) * dxyzdYbar(2) - dxyzdXbar(2) * dxyzdYbar(1);
  const double norm0 = sqrt(result(0,0)*result(0,0)+result(0,1)*result(0,1)+result(0,2)*result(0,2));
  result(0,0) /= norm0; result(0,1) /= norm0; result(0,2) /= norm0;

  return norm0;

}

static inline double calcDet3D(double dxdX, double dydX, double dzdX,
                               double dxdY, double dydY, double dzdY,
                               double dxdZ, double dydZ, double dzdZ)
{
  return dxdX*dydY*dzdZ + dxdY*dydZ*dzdX + dydX*dzdY*dxdZ
       - dxdZ*dydY*dzdX - dxdY*dydX*dzdZ - dydZ*dzdY*dxdX;
}

// Returns absolute value of Jacobian of straight volume element at barycenter
double JacobianBasis::getPrimJac3D(const fullMatrix<double> &nodesXYZ) const
{

  double dxdX = 0, dydX = 0, dzdX = 0, dxdY = 0, dydY = 0, dzdY = 0, dxdZ = 0, dydZ = 0, dzdZ = 0;
  for (int j=0; j<numPrimMapNodes; j++) {
    dxdX += primGradShapeBarX(j)*nodesXYZ(j,0);
    dydX += primGradShapeBarX(j)*nodesXYZ(j,1);
    dzdX += primGradShapeBarX(j)*nodesXYZ(j,2);
    dxdY += primGradShapeBarY(j)*nodesXYZ(j,0);
    dydY += primGradShapeBarY(j)*nodesXYZ(j,1);
    dzdY += primGradShapeBarY(j)*nodesXYZ(j,2);
    dxdZ += primGradShapeBarZ(j)*nodesXYZ(j,0);
    dydZ += primGradShapeBarZ(j)*nodesXYZ(j,1);
    dzdZ += primGradShapeBarZ(j)*nodesXYZ(j,2);
  }

  return fabs(calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ));

}

// Calculate (signed) Jacobian at mapping's nodes for one element, with normal vectors to
// straight element for regularization
void JacobianBasis::getSignedJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const
{

  switch (bezier->dim) {

    case 1 : {
      fullMatrix<double> normals(2,3);
      getPrimNormals1D(nodesXYZ,normals);
      getSignedJacobian(nodesXYZ,normals,jacobian);
      break;
    }

    case 2 : {
      fullMatrix<double> normal(1,3);
      getPrimNormal2D(nodesXYZ,normal);
      getSignedJacobian(nodesXYZ,normal,jacobian);
      break;
    }

    case 0 :
    case 3 : {
      fullMatrix<double> dum;
      getSignedJacobian(nodesXYZ,dum,jacobian);
      break;
    }

  }

}

// Calculate scaled (signed) Jacobian at mapping's nodes for one element, with normal vectors to
// straight element for regularization and scaling
void JacobianBasis::getScaledJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const
{

  switch (bezier->dim) {

    case 1 : {
      fullMatrix<double> normals(2,3);
      const double scale = 1./getPrimNormals1D(nodesXYZ,normals);
      normals(0,0) *= scale; normals(0,1) *= scale; normals(0,2) *= scale;  // Faster to scale 1 normal than afterwards
      getSignedJacobian(nodesXYZ,normals,jacobian);
      break;
    }

    case 2 : {
      fullMatrix<double> normal(1,3);
      const double scale = 1./getPrimNormal2D(nodesXYZ,normal);
      normal(0,0) *= scale; normal(0,1) *= scale; normal(0,2) *= scale;     // Faster to scale normal than afterwards
      getSignedJacobian(nodesXYZ,normal,jacobian);
      break;
    }

    case 0 :
    case 3 : {
      fullMatrix<double> dum;
      const double scale = 1./getPrimJac3D(nodesXYZ);
      getSignedJacobian(nodesXYZ,dum,jacobian);
      jacobian.scale(scale);
      break;
    }

  }

}

// Calculate (signed) Jacobian at mapping's nodes for one element, given vectors for regularization
// of line and surface Jacobians in 3D
void JacobianBasis::getSignedJacobian(const fullMatrix<double> &nodesXYZ,
                                      const fullMatrix<double> &normals, fullVector<double> &jacobian) const
{

  switch (bezier->dim) {

    case 0 : {
      for (int i = 0; i < numJacNodes; i++) jacobian(i) = 1.;
      break;
    }

    case 1 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        jacobian(i) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normals(0,0), &dydZ = normals(0,1), &dzdZ = normals(0,2);
        jacobian(i) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3), dxyzdZ(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      gradShapeMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        jacobian(i) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

  }

}

// Calculate (signed) Jacobian at mapping's nodes for one element, given vectors for regularization
// of line and surface Jacobians in 3D
void JacobianBasis::getSignedJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                             const fullMatrix<double> &normals,
                                             fullMatrix<double> &JDJ) const
{

  switch (bezier->dim) {

    case 0 : {
      for (int i = 0; i < numJacNodes; i++) {
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
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        for (int j = 0; j < numMapNodes; j++) {
          const double &dPhidX = gradShapeMatX(i,j);
          JDJ (i,j) = dPhidX * dydY * dzdZ + dPhidX * dzdY * dydZ;
          JDJ (i,j+1*numMapNodes) = dPhidX * dzdY * dxdZ - dPhidX * dxdY * dzdZ;
          JDJ (i,j+2*numMapNodes) = dPhidX * dxdY * dydZ - dPhidX * dydY * dxdZ;
        }
        JDJ(i,3*numMapNodes) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = normals(0,0), &dydZ = normals(0,1), &dzdZ = normals(0,2);
        for (int j = 0; j < numMapNodes; j++) {
          const double &dPhidX = gradShapeMatX(i,j);
          const double &dPhidY = gradShapeMatY(i,j);
          JDJ (i,j) =
            dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
            dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
          JDJ (i,j+1*numMapNodes) =
            dxdX * dPhidY * dzdZ +
            dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ
                                 - dPhidX * dxdY * dzdZ;
          JDJ (i,j+2*numMapNodes) =
                                   dPhidX * dxdY * dydZ +
            dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
            dxdX * dPhidY * dydZ;
        }
        JDJ(i,3*numMapNodes) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(numJacNodes,3), dxyzdY(numJacNodes,3), dxyzdZ(numJacNodes,3);
      gradShapeMatX.mult(nodesXYZ, dxyzdX);
      gradShapeMatY.mult(nodesXYZ, dxyzdY);
      gradShapeMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < numJacNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        for (int j = 0; j < numMapNodes; j++) {
          const double &dPhidX = gradShapeMatX(i,j);
          const double &dPhidY = gradShapeMatY(i,j);
          const double &dPhidZ = gradShapeMatZ(i,j);
          JDJ (i,j) =
            dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
            dydX * dzdY * dPhidZ - dzdX * dydY * dPhidZ -
            dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
          JDJ (i,j+1*numMapNodes) =
            dxdX * dPhidY * dzdZ + dzdX * dxdY * dPhidZ +
            dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ -
            dxdX * dzdY * dPhidZ - dPhidX * dxdY * dzdZ;
          JDJ (i,j+2*numMapNodes) =
            dxdX * dydY * dPhidZ + dPhidX * dxdY * dydZ +
            dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
            dxdX * dPhidY * dydZ - dydX * dxdY * dPhidZ;
        }
        JDJ(i,3*numMapNodes) = calcDet3D(dxdX,dydX,dzdX,dxdY,dydY,dzdY,dxdZ,dydZ,dzdZ);
      }
      break;
    }

  }

}

void JacobianBasis::getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                             const fullMatrix<double> &nodesXYZStraight,
                                             fullVector<double> &lambdaJ , fullMatrix<double> &gradLambdaJ) const
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
      const double &dPhidX = gradShapeMatX(l,i);
      const double &dPhidY = gradShapeMatY(l,i);
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
      const double &dPhidX = gradShapeMatX(l,i);
      const double &dPhidY = gradShapeMatY(l,i);
      gradLambdaJ(l, i + 0 * numMapNodes) = axixi * dPhidX + axieta * dPhidY;
      gradLambdaJ(l, i + 1 * numMapNodes) = aetaxi * dPhidX + aetaeta * dPhidY;
    }
  }

}

// Calculate (signed) Jacobian at mapping's nodes for several elements
// TODO: Optimize and test 1D & 2D
void JacobianBasis::getSignedJacobian(const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                      const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const
{

  switch (bezier->dim) {

    case 0 : {
      const int numEl = nodesX.size2();
      for (int iEl = 0; iEl < numEl; iEl++)
        for (int i = 0; i < numJacNodes; i++) jacobian(i,iEl) = 1.;
      break;
    }

    case 1 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(numJacNodes,numEl), dydX(numJacNodes,numEl), dzdX(numJacNodes,numEl);
      gradShapeMatX.mult(nodesX, dxdX); gradShapeMatX.mult(nodesY, dydX); gradShapeMatX.mult(nodesZ, dzdX);
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimJacNodes,3);
        for (int i = 0; i < numPrimJacNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normals(2,3);
        getPrimNormals1D(nodesXYZ,normals);
        const double &dxdY = normals(0,0), &dydY = normals(0,1), &dzdY = normals(0,2);
        const double &dxdZ = normals(1,0), &dydZ = normals(1,1), &dzdZ = normals(1,2);
        for (int i = 0; i < numJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl),dydX(i,iEl),dzdX(i,iEl),
                                      dxdY,dydY,dzdY,
                                      dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 2 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(numJacNodes,numEl), dydX(numJacNodes,numEl), dzdX(numJacNodes,numEl);
      fullMatrix<double> dxdY(numJacNodes,numEl), dydY(numJacNodes,numEl), dzdY(numJacNodes,numEl);
      gradShapeMatX.mult(nodesX, dxdX); gradShapeMatX.mult(nodesY, dydX); gradShapeMatX.mult(nodesZ, dzdX);
      gradShapeMatY.mult(nodesX, dxdY); gradShapeMatY.mult(nodesY, dydY); gradShapeMatY.mult(nodesZ, dzdY);
      for (int iEl = 0; iEl < numEl; iEl++) {
        fullMatrix<double> nodesXYZ(numPrimJacNodes,3);
        for (int i = 0; i < numPrimJacNodes; i++) {
          nodesXYZ(i,0) = nodesX(i,iEl);
          nodesXYZ(i,1) = nodesY(i,iEl);
          nodesXYZ(i,2) = nodesZ(i,iEl);
        }
        fullMatrix<double> normal(1,3);
        getPrimNormal2D(nodesXYZ,normal);
        const double &dxdZ = normal(0,0), &dydZ = normal(0,1), &dzdZ = normal(0,2);
        for (int i = 0; i < numJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl),dydX(i,iEl),dzdX(i,iEl),
                                      dxdY(i,iEl),dydY(i,iEl),dzdY(i,iEl),
                                      dxdZ,dydZ,dzdZ);
      }
      break;
    }

    case 3 : {
      const int numEl = nodesX.size2();
      fullMatrix<double> dxdX(numJacNodes,numEl), dydX(numJacNodes,numEl), dzdX(numJacNodes,numEl);
      fullMatrix<double> dxdY(numJacNodes,numEl), dydY(numJacNodes,numEl), dzdY(numJacNodes,numEl);
      fullMatrix<double> dxdZ(numJacNodes,numEl), dydZ(numJacNodes,numEl), dzdZ(numJacNodes,numEl);
      gradShapeMatX.mult(nodesX, dxdX); gradShapeMatX.mult(nodesY, dydX); gradShapeMatX.mult(nodesZ, dzdX);
      gradShapeMatY.mult(nodesX, dxdY); gradShapeMatY.mult(nodesY, dydY); gradShapeMatY.mult(nodesZ, dzdY);
      gradShapeMatZ.mult(nodesX, dxdZ); gradShapeMatZ.mult(nodesY, dydZ); gradShapeMatZ.mult(nodesZ, dzdZ);
      for (int iEl = 0; iEl < numEl; iEl++)
        for (int i = 0; i < numJacNodes; i++)
          jacobian(i,iEl) = calcDet3D(dxdX(i,iEl),dydX(i,iEl),dzdX(i,iEl),
                                      dxdY(i,iEl),dydY(i,iEl),dzdY(i,iEl),
                                      dxdZ(i,iEl),dydZ(i,iEl),dzdZ(i,iEl));
      break;
    }

  }

}
