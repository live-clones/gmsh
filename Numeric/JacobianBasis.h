// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef JACOBIAN_BASIS_H
#define JACOBIAN_BASIS_H

#include "fullMatrix.h"
#include "FuncSpaceData.h"

class GradientBasis {
public:
  fullMatrix<double> gradShapeMatX, gradShapeMatY, gradShapeMatZ;
  fullMatrix<double> gradShapeIdealMatX, gradShapeIdealMatY, gradShapeIdealMatZ;

private:
  const int _elementTag;
  const FuncSpaceData _data;

public:
  GradientBasis(int elementTag, FuncSpaceData);

  inline int getPolynomialOrder() const { return _data.getSpaceOrder(); }
  int getNumSamplingPoints() const { return gradShapeMatX.size1(); }
  int getNumMapNodes() const { return gradShapeMatX.size2(); }
  void getGradientsFromNodes(const fullMatrix<double> &nodes,
                             fullMatrix<double> *dxyzdX,
                             fullMatrix<double> *dxyzdY,
                             fullMatrix<double> *dxyzdZ) const;
  void getAllGradientsFromNodes(const fullMatrix<double> &nodes,
                                fullMatrix<double> &dxyzdXYZ) const;
  void getIdealGradientsFromNodes(const fullMatrix<double> &nodes,
                                  fullMatrix<double> *dxyzdX,
                                  fullMatrix<double> *dxyzdY,
                                  fullMatrix<double> *dxyzdZ) const;
  void getAllIdealGradientsFromNodes(const fullMatrix<double> &nodes,
                                     fullMatrix<double> &dxyzdXYZ) const;
  void mapFromIdealElement(fullMatrix<double> &dxyzdX,
                           fullMatrix<double> &dxyzdY,
                           fullMatrix<double> &dxyzdZ) const
  {
    GradientBasis::mapFromIdealElement(_data.getType(), dxyzdX, dxyzdY, dxyzdZ);
  }
  void mapFromIdealElement(fullVector<double> &dxyzdX,
                           fullVector<double> &dxyzdY,
                           fullVector<double> &dxyzdZ) const
  {
    GradientBasis::mapFromIdealElement(_data.getType(), dxyzdX, dxyzdY, dxyzdZ);
  }
  static void mapFromIdealElement(int type, fullMatrix<double> &gSMatX,
                                  fullMatrix<double> &gSMatY,
                                  fullMatrix<double> &gSMatZ);
  static void mapFromIdealElement(int type, fullVector<double> &gSVecX,
                                  fullVector<double> &gSVecY,
                                  fullVector<double> &gSVecZ);
  static void mapFromIdealElement(int type, double jac[3][3]);
};

class JacobianBasis {
private:
  const GradientBasis *_gradBasis;
  const int _elementTag;
  const FuncSpaceData _data;
  const int _dim;
  fullMatrix<double> gradShapeMatXFast, gradShapeMatYFast, gradShapeMatZFast;
  fullVector<double> primGradShapeBaryX, primGradShapeBaryY, primGradShapeBaryZ;
  fullVector<double> primIdealGradShapeBaryX, primIdealGradShapeBaryY;
  fullVector<double> primIdealGradShapeBaryZ;
  // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.
  fullMatrix<double> matrixPrimJac2Jac;
  int numJacNodes, numPrimJacNodes;
  int numMapNodes, numPrimMapNodes;
  int numJacNodesFast;

public:
  JacobianBasis(int elementTag, FuncSpaceData);

  // Get methods
  inline int getJacOrder() const { return _data.getSpaceOrder(); }
  inline int getNumJacNodes() const { return numJacNodes; }
  inline int getNumJacNodesFast() const { return numJacNodesFast; }
  inline int getNumMapNodes() const { return numMapNodes; }
  inline int getNumPrimJacNodes() const { return numPrimJacNodes; }
  inline int getNumPrimMapNodes() const { return numPrimMapNodes; }
  inline FuncSpaceData getFuncSpaceData() const { return _data; }

  // Jacobian evaluation methods
  double getPrimNormals1D(const fullMatrix<double> &nodesXYZ,
                          fullMatrix<double> &result) const;
  double getPrimNormal2D(const fullMatrix<double> &nodesXYZ,
                         fullMatrix<double> &result, bool ideal = false) const;
  double getPrimJac3D(const fullMatrix<double> &nodesXYZ,
                      bool ideal = false) const;
  inline void getSignedJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                       const fullMatrix<double> &normals,
                                       fullMatrix<double> &JDJ) const
  {
    getSignedJacAndGradientsGeneral(
      numJacNodes, _gradBasis->gradShapeMatX, _gradBasis->gradShapeMatY,
      _gradBasis->gradShapeMatZ, nodesXYZ, normals, JDJ);
  }
  inline void getSignedJacAndGradientsFast(const fullMatrix<double> &nodesXYZ,
                                           const fullMatrix<double> &normals,
                                           fullMatrix<double> &JDJ) const
  {
    getSignedJacAndGradientsGeneral(numJacNodesFast, gradShapeMatXFast,
                                    gradShapeMatYFast, gradShapeMatZFast,
                                    nodesXYZ, normals, JDJ);
  }
  inline void getSignedIdealJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                            const fullMatrix<double> &normals,
                                            fullMatrix<double> &JDJ) const
  {
    getSignedJacAndGradientsGeneral(numJacNodes, _gradBasis->gradShapeIdealMatX,
                                    _gradBasis->gradShapeIdealMatY,
                                    _gradBasis->gradShapeIdealMatZ, nodesXYZ,
                                    normals, JDJ);
  }
  void getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                const fullMatrix<double> &nodesXYZStraight,
                                fullVector<double> &lambdaJ,
                                fullMatrix<double> &gradLambdaJ) const;
  inline void getSignedJacobian(const fullMatrix<double> &nodesXYZ,
                                fullVector<double> &jacobian,
                                const fullMatrix<double> *normals = NULL) const
  {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY, _gradBasis->gradShapeMatZ,
                       nodesXYZ, false, false, jacobian, normals);
  }
  inline void getSignedJacobian(const fullMatrix<double> &nodesX,
                                const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ,
                                fullMatrix<double> &jacobian,
                                const fullMatrix<double> *normals = NULL) const
  {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY, _gradBasis->gradShapeMatZ,
                       nodesX, nodesY, nodesZ, false, false, jacobian, normals);
  }
  inline void
  getSignedIdealJacobian(const fullMatrix<double> &nodesXYZ,
                         fullVector<double> &jacobian,
                         const fullMatrix<double> *normals = NULL) const
  {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeIdealMatX,
                       _gradBasis->gradShapeIdealMatY,
                       _gradBasis->gradShapeIdealMatZ, nodesXYZ, true, false,
                       jacobian, normals);
  }
  inline void getSignedIdealJacobian(
    const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
    const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian,
    const fullMatrix<double> *normals = NULL) const
  {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeIdealMatX,
                       _gradBasis->gradShapeIdealMatY,
                       _gradBasis->gradShapeIdealMatZ, nodesX, nodesY, nodesZ,
                       true, false, jacobian, normals);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesXYZ,
                                fullVector<double> &jacobian) const
  {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY, _gradBasis->gradShapeMatZ,
                       nodesXYZ, false, true, jacobian, NULL);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesX,
                                const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ,
                                fullMatrix<double> &jacobian) const
  {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY, _gradBasis->gradShapeMatZ,
                       nodesX, nodesY, nodesZ, false, true, jacobian, NULL);
  }
  inline void
  getSignedJacobianFast(const fullMatrix<double> &nodesXYZ,
                        fullVector<double> &jacobian,
                        const fullMatrix<double> *normals = NULL) const
  {
    getJacobianGeneral(numJacNodesFast, gradShapeMatXFast, gradShapeMatYFast,
                       gradShapeMatZFast, nodesXYZ, false, false, jacobian,
                       normals);
  }
  inline void
  getScaledJacobianFast(const fullMatrix<double> &nodesXYZ,
                        fullVector<double> &jacobian,
                        const fullMatrix<double> *normals = NULL) const
  {
    getJacobianGeneral(numJacNodesFast, gradShapeMatXFast, gradShapeMatYFast,
                       gradShapeMatZFast, nodesXYZ, false, true, jacobian,
                       normals);
  }

  inline void primJac2Jac(const fullVector<double> &primJac,
                          fullVector<double> &jac) const
  {
    matrixPrimJac2Jac.mult(primJac, jac);
  }

  static int jacobianOrder(int tag);
  static int jacobianOrder(int parentType, int order);
  static FuncSpaceData jacobianMatrixSpace(int type, int order);

private:
  void getJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                          const fullMatrix<double> &gSMatY,
                          const fullMatrix<double> &gSMatZ,
                          const fullMatrix<double> &nodesXYZ, bool idealNorm,
                          bool scaling, fullVector<double> &jacobian,
                          const fullMatrix<double> *normals) const;
  void getJacobianGeneral(int nJacNodes, const fullMatrix<double> &gSMatX,
                          const fullMatrix<double> &gSMatY,
                          const fullMatrix<double> &gSMatZ,
                          const fullMatrix<double> &nodesX,
                          const fullMatrix<double> &nodesY,
                          const fullMatrix<double> &nodesZ, bool idealNorm,
                          bool scaling, fullMatrix<double> &jacobian,
                          const fullMatrix<double> *normals) const;
  void getSignedJacAndGradientsGeneral(int nJacNodes,
                                       const fullMatrix<double> &gSMatX,
                                       const fullMatrix<double> &gSMatY,
                                       const fullMatrix<double> &gSMatZ,
                                       const fullMatrix<double> &nodesXYZ,
                                       const fullMatrix<double> &normals,
                                       fullMatrix<double> &JDJ) const;
  void getSignedIdealJacAndGradientsGeneral(int nJacNodes,
                                            const fullMatrix<double> &gSMatX,
                                            const fullMatrix<double> &gSMatY,
                                            const fullMatrix<double> &gSMatZ,
                                            const fullMatrix<double> &nodesXYZ,
                                            const fullMatrix<double> &normals,
                                            fullMatrix<double> &JDJ) const;
};

#endif
