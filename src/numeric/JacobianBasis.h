// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef JACOBIAN_BASIS_H
#define JACOBIAN_BASIS_H

#include "fullMatrix.h"
#include "FuncSpaceData.h"

class GradientBasis {
public:
  fullMatrix<double> dShapeMat_dX, dShapeMat_dY, dShapeMat_dZ;
  fullMatrix<double> dShapeIdealMat_dX, dShapeIdealMat_dY, dShapeIdealMat_dZ;

private:
  const int _elementTag;
  const FuncSpaceData _data;

public:
  GradientBasis(int elementTag, FuncSpaceData);

  inline int getPolynomialOrder() const { return _data.getSpaceOrder(); }
  int getNumSamplingPoints() const { return dShapeMat_dX.size1(); }
  int getNumMapNodes() const { return dShapeMat_dX.size2(); }
  void getGradientsFromNodes(const fullMatrix<double> &nodesCoord,
                             fullMatrix<double> *dxyzdX,
                             fullMatrix<double> *dxyzdY,
                             fullMatrix<double> *dxyzdZ) const;
  void getAllGradientsFromNodes(const fullMatrix<double> &nodesCoord,
                                fullMatrix<double> &dxyzdXYZ) const;
  void getIdealGradientsFromNodes(const fullMatrix<double> &nodesCoord,
                                  fullMatrix<double> *dxyzdX,
                                  fullMatrix<double> *dxyzdY,
                                  fullMatrix<double> *dxyzdZ) const;
  void getAllIdealGradientsFromNodes(const fullMatrix<double> &nodesCoord,
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
  static void mapFromIdealElement(int type, fullMatrix<double> &dSMat_dX,
                                  fullMatrix<double> &dSMat_dY,
                                  fullMatrix<double> &dSMat_dZ);
  static void mapFromIdealElement(int type, fullVector<double> &dSVec_dX,
                                  fullVector<double> &dSVec_dY,
                                  fullVector<double> &dSVec_dZ);
  static void mapFromIdealElement(int type, double jac[3][3]);
};

class JacobianBasis {
private:
  const GradientBasis *_gradBasis;
  const int _elementTag;
  const FuncSpaceData _data;
  const int _dim;
  fullMatrix<double> dFastShapeMat_dX, dFastShapeMat_dY, dFastShapeMat_dZ;
  fullVector<double> dPrimBaryShape_dX, dPrimBaryShape_dY, dPrimBaryShape_dZ;
  fullVector<double> dPrimBaryIdealShape_dX, dPrimBaryIdealShape_dY;
  fullVector<double> dPrimBaryIdealShape_dZ;
  // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.
  fullMatrix<double> matrixPrimJac2Jac;
  int numSamplingPnts, numPrimSamplingPnts;
  int numMapNodes, numPrimMapNodes;
  int numSamplingPntsFast;

public:
  JacobianBasis(int elementTag, FuncSpaceData);

  // Get methods
  inline int getJacOrder() const { return _data.getSpaceOrder(); }
  inline int getNumSamplingPnts() const { return numSamplingPnts; }
  inline int getNumSamplingPntsFast() const { return numSamplingPntsFast; }
  inline int getNumMapNodes() const { return numMapNodes; }
  inline int getNumPrimSamplingPnts() const { return numPrimSamplingPnts; }
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
      numSamplingPnts, _gradBasis->dShapeMat_dX, _gradBasis->dShapeMat_dY,
      _gradBasis->dShapeMat_dZ, nodesXYZ, normals, JDJ);
  }
  inline void getSignedJacAndGradientsFast(const fullMatrix<double> &nodesXYZ,
                                           const fullMatrix<double> &normals,
                                           fullMatrix<double> &JDJ) const
  {
    getSignedJacAndGradientsGeneral(numSamplingPntsFast, dFastShapeMat_dX,
                                    dFastShapeMat_dY, dFastShapeMat_dZ,
                                    nodesXYZ, normals, JDJ);
  }
  inline void getSignedIdealJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                            const fullMatrix<double> &normals,
                                            fullMatrix<double> &JDJ) const
  {
    getSignedJacAndGradientsGeneral(
      numSamplingPnts, _gradBasis->dShapeIdealMat_dX,
      _gradBasis->dShapeIdealMat_dY, _gradBasis->dShapeIdealMat_dZ, nodesXYZ,
      normals, JDJ);
  }
  void getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                const fullMatrix<double> &nodesXYZStraight,
                                fullVector<double> &lambdaJ,
                                fullMatrix<double> &gradLambdaJ) const;
  inline void getSignedJacobian(const fullMatrix<double> &nodesXYZ,
                                fullVector<double> &jacobian,
                                const fullMatrix<double> *normals = nullptr) const
  {
    getJacobianGeneral(numSamplingPnts, _gradBasis->dShapeMat_dX,
                       _gradBasis->dShapeMat_dY, _gradBasis->dShapeMat_dZ,
                       nodesXYZ, false, false, jacobian, normals);
  }
  inline void getSignedJacobian(const fullMatrix<double> &nodesX,
                                const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ,
                                fullMatrix<double> &jacobian,
                                const fullMatrix<double> *normals = nullptr) const
  {
    getJacobianGeneral(numSamplingPnts, _gradBasis->dShapeMat_dX,
                       _gradBasis->dShapeMat_dY, _gradBasis->dShapeMat_dZ,
                       nodesX, nodesY, nodesZ, false, false, jacobian, normals);
  }
  inline void
  getSignedIdealJacobian(const fullMatrix<double> &nodesXYZ,
                         fullVector<double> &jacobian,
                         const fullMatrix<double> *normals = nullptr) const
  {
    getJacobianGeneral(numSamplingPnts, _gradBasis->dShapeIdealMat_dX,
                       _gradBasis->dShapeIdealMat_dY,
                       _gradBasis->dShapeIdealMat_dZ, nodesXYZ, true, false,
                       jacobian, normals);
  }
  inline void getSignedIdealJacobian(
    const fullMatrix<double> &nodesX, const fullMatrix<double> &nodesY,
    const fullMatrix<double> &nodesZ, fullMatrix<double> &jacobian,
    const fullMatrix<double> *normals = nullptr) const
  {
    getJacobianGeneral(numSamplingPnts, _gradBasis->dShapeIdealMat_dX,
                       _gradBasis->dShapeIdealMat_dY,
                       _gradBasis->dShapeIdealMat_dZ, nodesX, nodesY, nodesZ,
                       true, false, jacobian, normals);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesXYZ,
                                fullVector<double> &jacobian) const
  {
    getJacobianGeneral(numSamplingPnts, _gradBasis->dShapeMat_dX,
                       _gradBasis->dShapeMat_dY, _gradBasis->dShapeMat_dZ,
                       nodesXYZ, false, true, jacobian, nullptr);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesX,
                                const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ,
                                fullMatrix<double> &jacobian) const
  {
    getJacobianGeneral(numSamplingPnts, _gradBasis->dShapeMat_dX,
                       _gradBasis->dShapeMat_dY, _gradBasis->dShapeMat_dZ,
                       nodesX, nodesY, nodesZ, false, true, jacobian, nullptr);
  }
  inline void
  getSignedJacobianFast(const fullMatrix<double> &nodesXYZ,
                        fullVector<double> &jacobian,
                        const fullMatrix<double> *normals = nullptr) const
  {
    getJacobianGeneral(numSamplingPntsFast, dFastShapeMat_dX, dFastShapeMat_dY,
                       dFastShapeMat_dZ, nodesXYZ, false, false, jacobian,
                       normals);
  }
  inline void
  getScaledJacobianFast(const fullMatrix<double> &nodesXYZ,
                        fullVector<double> &jacobian,
                        const fullMatrix<double> *normals = nullptr) const
  {
    getJacobianGeneral(numSamplingPntsFast, dFastShapeMat_dX, dFastShapeMat_dY,
                       dFastShapeMat_dZ, nodesXYZ, false, true, jacobian,
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
  void getJacobianGeneral(int nSamplingPnts, const fullMatrix<double> &dSMat_dX,
                          const fullMatrix<double> &dSMat_dY,
                          const fullMatrix<double> &dSMat_dZ,
                          const fullMatrix<double> &nodesXYZ, bool idealNorm,
                          bool scaling, fullVector<double> &jacobian,
                          const fullMatrix<double> *normals) const;
  void getJacobianGeneral(int nSamplingPnts, const fullMatrix<double> &dSMat_dX,
                          const fullMatrix<double> &dSMat_dY,
                          const fullMatrix<double> &dSMat_dZ,
                          const fullMatrix<double> &nodesX,
                          const fullMatrix<double> &nodesY,
                          const fullMatrix<double> &nodesZ, bool idealNorm,
                          bool scaling, fullMatrix<double> &jacobian,
                          const fullMatrix<double> *normals) const;
  void getSignedJacAndGradientsGeneral(int nSamplingPnts,
                                       const fullMatrix<double> &dSMat_dX,
                                       const fullMatrix<double> &dSMat_dY,
                                       const fullMatrix<double> &dSMat_dZ,
                                       const fullMatrix<double> &nodesXYZ,
                                       const fullMatrix<double> &normals,
                                       fullMatrix<double> &JDJ) const;
  void getSignedIdealJacAndGradientsGeneral(int nSamplingPnts,
                                            const fullMatrix<double> &dSMat_dX,
                                            const fullMatrix<double> &dSMat_dY,
                                            const fullMatrix<double> &dSMat_dZ,
                                            const fullMatrix<double> &nodesXYZ,
                                            const fullMatrix<double> &normals,
                                            fullMatrix<double> &JDJ) const;
};

#endif
