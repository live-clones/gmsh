// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _JACOBIAN_BASIS_H_
#define _JACOBIAN_BASIS_H_

#include "fullMatrix.h"
#include "FuncSpaceData.h"

class bezierBasis;

class GradientBasis {
public:
  fullMatrix<double> gradShapeMatX, gradShapeMatY, gradShapeMatZ;
  fullMatrix<double> gradShapeIdealMatX, gradShapeIdealMatY, gradShapeIdealMatZ;

private:
  const FuncSpaceData _data;

public:
  GradientBasis(FuncSpaceData);

  int getNumSamplingPoints() const {return gradShapeMatX.size1();}
  int getNumMapNodes() const {return gradShapeMatX.size2();}
  const bezierBasis* getBezier() const;

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
                           fullMatrix<double> &dxyzdZ) const {
    GradientBasis::mapFromIdealElement(_data.elementType(), dxyzdX, dxyzdY, dxyzdZ);
  }
  void mapFromIdealElement(fullVector<double> &dxyzdX,
                           fullVector<double> &dxyzdY,
                           fullVector<double> &dxyzdZ) const {
    GradientBasis::mapFromIdealElement(_data.elementType(), dxyzdX, dxyzdY, dxyzdZ);
  }
  static void mapFromIdealElement(int type,
                                  fullMatrix<double> &gSMatX,
                                  fullMatrix<double> &gSMatY,
                                  fullMatrix<double> &gSMatZ);
  static void mapFromIdealElement(int type,
                                  fullVector<double> &gSVecX,
                                  fullVector<double> &gSVecY,
                                  fullVector<double> &gSVecZ);
  static void mapFromIdealElement(int type, double jac[3][3]);

  void lag2Bez(const fullMatrix<double> &lag, fullMatrix<double> &bez) const;
};

class JacobianBasis {
private:
  const GradientBasis *_gradBasis;
  const FuncSpaceData _data;
  const int _dim;

  fullMatrix<double> gradShapeMatXFast, gradShapeMatYFast, gradShapeMatZFast;
  fullVector<double> primGradShapeBaryX, primGradShapeBaryY, primGradShapeBaryZ;
  fullVector<double> primIdealGradShapeBaryX, primIdealGradShapeBaryY,
                     primIdealGradShapeBaryZ;
  fullMatrix<double> matrixPrimJac2Jac; // Lifts Lagrange basis of primary Jac. to Lagrange basis of Jac.

  int numJacNodes, numPrimJacNodes;
  int numMapNodes, numPrimMapNodes;
  int numJacNodesFast;

public:
  JacobianBasis(FuncSpaceData);

  // Get methods
  inline int getJacOrder() const {return _data.spaceOrder();}
  inline int getNumJacNodes() const {return numJacNodes;}
  inline int getNumJacNodesFast() const {return numJacNodesFast;}
  inline int getNumMapNodes() const {return numMapNodes;}
  inline int getNumPrimJacNodes() const {return numPrimJacNodes;}
  inline int getNumPrimMapNodes() const {return numPrimMapNodes;}
  const bezierBasis* getBezier() const;

  // Jacobian evaluation methods
  double getPrimNormals1D(const fullMatrix<double> &nodesXYZ,
                          fullMatrix<double> &result) const;
  double getPrimNormal2D(const fullMatrix<double> &nodesXYZ,
                         fullMatrix<double> &result, bool ideal=false) const;
  double getPrimJac3D(const fullMatrix<double> &nodesXYZ, bool ideal=false) const;
  inline void getSignedJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                       const fullMatrix<double> &normals,
                                       fullMatrix<double> &JDJ) const {
    getSignedJacAndGradientsGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                                    _gradBasis->gradShapeMatY,
                                    _gradBasis->gradShapeMatZ,
                                    nodesXYZ, normals, JDJ);
  }
  inline void getSignedJacAndGradientsFast(const fullMatrix<double> &nodesXYZ,
                                           const fullMatrix<double> &normals,
                                           fullMatrix<double> &JDJ) const {
    getSignedJacAndGradientsGeneral(numJacNodesFast, gradShapeMatXFast,
                                    gradShapeMatYFast, gradShapeMatZFast,
                                    nodesXYZ, normals, JDJ);
  }
  inline void getSignedIdealJacAndGradients(const fullMatrix<double> &nodesXYZ,
                                            const fullMatrix<double> &normals,
                                            fullMatrix<double> &JDJ) const {
    getSignedJacAndGradientsGeneral(numJacNodes, _gradBasis->gradShapeIdealMatX,
                                    _gradBasis->gradShapeIdealMatY,
                                    _gradBasis->gradShapeIdealMatZ,
                                    nodesXYZ, normals, JDJ);
  }
  void getMetricMinAndGradients(const fullMatrix<double> &nodesXYZ,
                                const fullMatrix<double> &nodesXYZStraight,
                                fullVector<double> &lambdaJ,
                                fullMatrix<double> &gradLambdaJ) const;
  inline void getSignedJacobian(const fullMatrix<double> &nodesXYZ,
                                fullVector<double> &jacobian,
                                const fullMatrix<double> *normals = NULL) const {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY,
                       _gradBasis->gradShapeMatZ,
                       nodesXYZ, false, false, jacobian, normals);
  }
  inline void getSignedJacobian(const fullMatrix<double> &nodesX,
                                const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ,
                                fullMatrix<double> &jacobian,
                                const fullMatrix<double> *normals = NULL) const {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY,
                       _gradBasis->gradShapeMatZ,
                       nodesX, nodesY, nodesZ, false, false, jacobian, normals);
  }
  inline void getSignedIdealJacobian(const fullMatrix<double> &nodesXYZ,
                                     fullVector<double> &jacobian,
                                     const fullMatrix<double> *normals = NULL) const {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeIdealMatX,
                       _gradBasis->gradShapeIdealMatY,
                       _gradBasis->gradShapeIdealMatZ,
                       nodesXYZ, true, false, jacobian, normals);
  }
  inline void getSignedIdealJacobian(const fullMatrix<double> &nodesX,
                                     const fullMatrix<double> &nodesY,
                                     const fullMatrix<double> &nodesZ,
                                     fullMatrix<double> &jacobian,
                                     const fullMatrix<double> *normals = NULL) const {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeIdealMatX,
                       _gradBasis->gradShapeIdealMatY,
                       _gradBasis->gradShapeIdealMatZ,
                       nodesX, nodesY, nodesZ, true, false, jacobian, normals);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesXYZ,
                                fullVector<double> &jacobian) const {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY,
                       _gradBasis->gradShapeMatZ,
                       nodesXYZ, false, true, jacobian, NULL);
  }
  inline void getScaledJacobian(const fullMatrix<double> &nodesX,
                                const fullMatrix<double> &nodesY,
                                const fullMatrix<double> &nodesZ,
                                fullMatrix<double> &jacobian) const {
    getJacobianGeneral(numJacNodes, _gradBasis->gradShapeMatX,
                       _gradBasis->gradShapeMatY,
                       _gradBasis->gradShapeMatZ,
                       nodesX, nodesY, nodesZ, false, true, jacobian, NULL);
  }
  inline void getSignedJacobianFast(const fullMatrix<double> &nodesXYZ,
                                    fullVector<double> &jacobian,
                                    const fullMatrix<double> *normals = NULL) const {
    getJacobianGeneral(numJacNodesFast, gradShapeMatXFast,
                       gradShapeMatYFast, gradShapeMatZFast,
                       nodesXYZ, false, false, jacobian, normals);
  }
  inline void getScaledJacobianFast(const fullMatrix<double> &nodesXYZ,
                                    fullVector<double> &jacobian,
                                    const fullMatrix<double> *normals = NULL) const {
    getJacobianGeneral(numJacNodesFast, gradShapeMatXFast,
                       gradShapeMatYFast, gradShapeMatZFast,
                       nodesXYZ, false, true, jacobian, normals);
  }

  void lag2Bez(const fullVector<double> &lag, fullVector<double> &bez) const;
  void lag2Bez(const fullMatrix<double> &lag, fullMatrix<double> &bez) const;
  inline void primJac2Jac(const fullVector<double> &primJac, fullVector<double> &jac) const {
    matrixPrimJac2Jac.mult(primJac,jac);
  }

  // Research purpose (to be removed ?)
  void interpolate(const fullVector<double> &jacobian,
                   const fullMatrix<double> &uvw,
                   fullMatrix<double> &result, bool areBezier = false) const;

  static int jacobianOrder(int tag);
  static int jacobianOrder(int parentType, int order);
  static FuncSpaceData jacobianMatrixSpace(int type, int order);


 private :
  void getJacobianGeneral(int nJacNodes,
                          const fullMatrix<double> &gSMatX,
                          const fullMatrix<double> &gSMatY,
                          const fullMatrix<double> &gSMatZ,
                          const fullMatrix<double> &nodesXYZ,
                          bool idealNorm, bool scaling,
                          fullVector<double> &jacobian,
                          const fullMatrix<double> *normals) const;
  void getJacobianGeneral(int nJacNodes,
                          const fullMatrix<double> &gSMatX,
                          const fullMatrix<double> &gSMatY,
                          const fullMatrix<double> &gSMatZ,
                          const fullMatrix<double> &nodesX,
                          const fullMatrix<double> &nodesY,
                          const fullMatrix<double> &nodesZ,
                          bool idealNorm, bool scaling,
                          fullMatrix<double> &jacobian,
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
