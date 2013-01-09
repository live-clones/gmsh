// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _JACOBIAN_BASIS_H_
#define _JACOBIAN_BASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"

class MElement;

class bezierBasis {
 private :
  static std::map<int, bezierBasis> _bbs;
 public :
  int dim, order;
  int numLagPts;
  int numDivisions;
  // the 'numLagPts' first exponents are related to 'Lagrangian' values
  fullMatrix<double> exponents; // exponents of Bezier FF
  fullMatrix<double> bezierPoints, lagPoints; // sampling point
  fullMatrix<double> matrixLag2Bez, matrixBez2Lag;
  fullMatrix<double> subDivisor;
  static const bezierBasis *find(int);
};

class JacobianBasis {
 private:
  static std::map<int, JacobianBasis*> _fs;
  const bezierBasis *bezier;
  fullMatrix<double> gradShapeMatX, gradShapeMatY, gradShapeMatZ;
  fullVector<double> primGradShapeBarX, primGradShapeBarY, primGradShapeBarZ;
  fullMatrix<double> matrixPrimJac2Jac;                                   // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.
  int numJacNodes, numMapNodes, numPrimJacNodes, numPrimMapNodes;
  inline const fullMatrix<double> &getPoints() const { return bezier->lagPoints; }
 public :
  static const JacobianBasis *find(int);
  JacobianBasis(int tag);
  inline int getNumJacNodes() const { return numJacNodes; }
  inline int getNumMapNodes() const { return numMapNodes; }
  inline int getNumPrimJacNodes() const { return numPrimJacNodes; }
  inline int getNumPrimMapNodes() const { return numPrimMapNodes; }
  inline int getNumDivisions() const { return bezier->numDivisions; }
  inline int getNumSubNodes() const { return bezier->subDivisor.size1(); }
  inline int getNumLagPts() const { return bezier->numLagPts; }
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
};

#endif
