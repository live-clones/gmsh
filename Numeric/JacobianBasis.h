// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _JACOBIAN_BASIS_H_
#define _JACOBIAN_BASIS_H_

#include <map>
#include <vector>
#include "bezierBasis.h"
#include "fullMatrix.h"


class JacobianBasis {
 private:
  fullMatrix<double> gradShapeMatX, gradShapeMatY, gradShapeMatZ;
  fullMatrix<double> gradShapeMatXFast, gradShapeMatYFast, gradShapeMatZFast;
  fullVector<double> primGradShapeBarycenterX, primGradShapeBarycenterY, primGradShapeBarycenterZ;
  fullMatrix<double> matrixPrimJac2Jac;                                   // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.

  int numJacNodes, numPrimJacNodes;
  int numMapNodes, numPrimMapNodes;
  int numJacNodesFast;

  void getSignedJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const;
  void getSignedJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const;
  void getScaledJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const;
  void getSignedJacAndGradientsGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                                       const fullMatrix<double> &gSMatY, const fullMatrix<double> &gSMatZ,
                                       const fullMatrix<double> &nodesXYZ, const fullMatrix<double> &normals,
                                       fullMatrix<double> &JDJ) const;

 public :
  const bezierBasis *bezier;

  JacobianBasis(int tag);

  // Get methods
  inline int getNumJacNodes() const { return numJacNodes; }
  inline int getNumJacNodesFast() const { return numJacNodesFast; }
  inline int getNumMapNodes() const { return numMapNodes; }
  inline int getNumPrimJacNodes() const { return numPrimJacNodes; }
  inline int getNumPrimMapNodes() const { return numPrimMapNodes; }
  inline int getNumDivisions() const { return bezier->getNumDivision(); }
  inline int getNumSubNodes() const { return bezier->subDivisor.size1(); }
  inline int getNumLagCoeff() const { return bezier->getNumLagCoeff(); }

  // Jacobian evaluation methods
  double getPrimNormals1D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const;
  double getPrimNormal2D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const;
  double getPrimJac3D(const fullMatrix<double> &nodesXYZ) const;
  inline void getSignedJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                       const fullMatrix<double> &normals, fullMatrix<double> &JDJ) const {
    getSignedJacAndGradientsGeneral(numJacNodes,gradShapeMatX,gradShapeMatY,gradShapeMatZ,nodesXYZ,normals,JDJ);
  }
  inline void getSignedJacAndGradientsFast(const fullMatrix<double> &nodesXYZ,
                                           const fullMatrix<double> &normals, fullMatrix<double> &JDJ) const {
    getSignedJacAndGradientsGeneral(numJacNodesFast,gradShapeMatXFast,gradShapeMatYFast,
                                    gradShapeMatZFast,nodesXYZ,normals,JDJ);
  }
  void getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                const fullMatrix<double> &nodesXYZStraight,
                                fullVector<double> &lambdaJ , fullMatrix<double> &gradLambdaJ) const;
  inline void getSignedJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const {
    getSignedJacobianGeneral(numJacNodes,gradShapeMatX,gradShapeMatY,gradShapeMatZ,nodesXYZ,jacobian);
  }
  inline void getSignedJacobian(const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const {
    getSignedJacobianGeneral(numJacNodes,gradShapeMatX,gradShapeMatY,
                             gradShapeMatZ,nodesX,nodesY,nodesZ,jacobian);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const {
    getScaledJacobianGeneral(numJacNodes,gradShapeMatX,gradShapeMatY,gradShapeMatZ,nodesXYZ,jacobian);
  }
  inline void getSignedJacobianFast(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const {
    getSignedJacobianGeneral(numJacNodesFast,gradShapeMatXFast,gradShapeMatYFast,gradShapeMatZFast,nodesXYZ,jacobian);
  }
  inline void getSignedJacobianFast(const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                                    const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const {
    getSignedJacobianGeneral(numJacNodesFast,gradShapeMatXFast,gradShapeMatYFast,
                             gradShapeMatZFast,nodesX,nodesY,nodesZ,jacobian);
  }
  inline void getScaledJacobianFast(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const {
    getScaledJacobianGeneral(numJacNodesFast,gradShapeMatXFast,gradShapeMatYFast,gradShapeMatZFast,nodesXYZ,jacobian);
  }
  //
  inline void lag2Bez(const fullVector<double> &jac, fullVector<double> &bez) const {
    bezier->matrixLag2Bez.mult(jac,bez);
  }
  inline void lag2Bez(const fullMatrix<double> &jac, fullMatrix<double> &bez) const {
    bezier->matrixLag2Bez.mult(jac,bez);
  }
  inline void primJac2Jac(const fullVector<double> &primJac, fullVector<double> &jac) const {
    matrixPrimJac2Jac.mult(primJac,jac);
  }
  inline void subdivideBezierCoeff(const fullVector<double> &bez, fullVector<double> &result) const {
    bezier->subDivisor.mult(bez,result);
  }
  //
  void interpolate(const fullVector<double> &jacobian,
                   const fullMatrix<double> &uvw,
                   fullMatrix<double> &result) const;

  // Jacobian basis order and pyramidal basis
  void getGradientsFromNodes(const fullMatrix<double> &nodes,
                             fullMatrix<double> *dxyzdX,
                             fullMatrix<double> *dxyzdY,
                             fullMatrix<double> *dxyzdZ) const;

  //
  static int jacobianOrder(int parentType, int order);
  static fullMatrix<double> generateJacMonomialsPyramid(int order);
  static fullMatrix<double> generateJacPointsPyramid(int order);
};

#endif
