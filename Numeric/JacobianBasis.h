// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
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
  const bezierBasis *bezier;

  fullMatrix<double> lagPoints; // sampling point
  fullMatrix<double> gradShapeMatX, gradShapeMatY, gradShapeMatZ;
  fullVector<double> primGradShapeBarycenterX, primGradShapeBarycenterY, primGradShapeBarycenterZ;
  fullMatrix<double> matrixPrimJac2Jac;                                   // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.

  int numJacNodes, numPrimJacNodes;
  int numMapNodes, numPrimMapNodes;

 public :
  JacobianBasis(int tag);

  // get methods
  inline int getNumJacNodes() const { return numJacNodes; }
  inline int getNumMapNodes() const { return numMapNodes; }
  inline int getNumPrimJacNodes() const { return numPrimJacNodes; }
  inline int getNumPrimMapNodes() const { return numPrimMapNodes; }
  inline int getNumDivisions() const { return bezier->getNumDivision(); }
  inline int getNumSubNodes() const { return bezier->subDivisor.size1(); }
  inline int getNumLagCoeff() const { return bezier->getNumLagCoeff(); }

  //
  double getPrimNormals1D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const;
  double getPrimNormal2D(const fullMatrix<double> &nodesXYZ, fullMatrix<double> &result) const;
  double getPrimJac3D(const fullMatrix<double> &nodesXYZ) const;
  void getSignedJacobian(const fullMatrix<double> &nodesXYZ,
                         const fullMatrix<double> &normals, fullVector<double> &jacobian) const;
  void getSignedJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                const fullMatrix<double> &normals, fullMatrix<double> &JDJ) const;
  void getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                const fullMatrix<double> &nodesXYZStraight,
                                fullVector<double> &lambdaJ , fullMatrix<double> &gradLambdaJ) const;
  void getSignedJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const;
  void getSignedJacobian(const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
                         const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian) const;
  void getScaledJacobian(const fullMatrix<double> &nodesXYZ, fullVector<double> &jacobian) const;

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
  inline void subDivisor(const fullVector<double> &bez, fullVector<double> &result) const {
    bezier->subDivisor.mult(bez,result);
  }

  //
  static fullMatrix<double> generateJacMonomialsPyramid(int order);
  static inline fullMatrix<double> generateJacPointsPyramid(int order) {
    fullMatrix<double> points = generateJacMonomialsPyramid(order);

    if (order == 0) return points;

    points.scale(1. / (order+2.));
    return points;
  }
};

#endif
