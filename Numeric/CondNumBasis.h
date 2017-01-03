// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _CONDNUMBASIS_H_
#define _CONDNUMBASIS_H_

#include <map>
#include <vector>
#include "fullMatrix.h"
#include "JacobianBasis.h"

class CondNumBasis {
 private:
  const GradientBasis *_gradBasis;

  const int _tag, _dim, _condNumOrder;

  fullVector<double> primGradShapeBarycenterX, primGradShapeBarycenterY,
                     primGradShapeBarycenterZ;

  int _nCondNumNodes;
  int _nMapNodes, _nPrimMapNodes;

 public :
  CondNumBasis(int tag, int cnOrder = -1);

  // Get methods
  inline int getCondNumOrder() const { return _condNumOrder; }
  inline int getNumCondNumNodes() const { return _nCondNumNodes; }
  inline int getNumMapNodes() const { return _nMapNodes; }
  inline int getNumPrimMapNodes() const { return _nPrimMapNodes; }

  // Order calculation
  static int condNumOrder(int tag);
  static int condNumOrder(int parentType, int order);

  // Condition number evaluation methods
  inline void getInvCondNum(const fullMatrix<double> &nodesXYZ,
                            fullVector<double> &invCond) const {
    getInvCondNumGeneral(_nCondNumNodes,
                         _gradBasis->gradShapeIdealMatX,
                         _gradBasis->gradShapeIdealMatY,
                         _gradBasis->gradShapeIdealMatZ,
                         nodesXYZ, invCond);
  }
  inline void getSignedInvCondNum(const fullMatrix<double> &nodesXYZ,
                                  const fullMatrix<double> &normals,
                                  fullVector<double> &invCond) const {
    getSignedInvCondNumGeneral(_nCondNumNodes,
                               _gradBasis->gradShapeIdealMatX,
                               _gradBasis->gradShapeIdealMatY,
                               _gradBasis->gradShapeIdealMatZ,
                               nodesXYZ, normals, invCond);
  }
  inline void getInvCondNumAndGradients(const fullMatrix<double> &nodesXYZ,
                                        fullMatrix<double> &IDI) const {
    getInvCondNumAndGradientsGeneral(_nCondNumNodes,
                                     _gradBasis->gradShapeIdealMatX,
                                     _gradBasis->gradShapeIdealMatY,
                                     _gradBasis->gradShapeIdealMatZ,
                                     nodesXYZ, IDI);
  }
  inline void getSignedInvCondNumAndGradients(const fullMatrix<double> &nodesXYZ,
                                              const fullMatrix<double> &normals,
                                              fullMatrix<double> &IDI) const {
    getSignedInvCondNumAndGradientsGeneral(_nCondNumNodes,
                                           _gradBasis->gradShapeIdealMatX,
                                           _gradBasis->gradShapeIdealMatY,
                                           _gradBasis->gradShapeIdealMatZ,
                                           nodesXYZ, normals, IDI);
  }


 private :
  template<bool sign>
  void getInvCondNumGeneral(int nCondNumNodes,
                            const fullMatrix<double> &gSMatX,
                            const fullMatrix<double> &gSMatY,
                            const fullMatrix<double> &gSMatZ,
                            const fullMatrix<double> &nodesXYZ,
                            const fullMatrix<double> &normals,
                            fullVector<double> &invCond) const;
  void getInvCondNumGeneral(int nCondNumNodes,
                            const fullMatrix<double> &gSMatX,
                            const fullMatrix<double> &gSMatY,
                            const fullMatrix<double> &gSMatZ,
                            const fullMatrix<double> &nodesXYZ,
                            fullVector<double> &invCond) const;
  void getSignedInvCondNumGeneral(int nCondNumNodes,
                                  const fullMatrix<double> &gSMatX,
                                  const fullMatrix<double> &gSMatY,
                                  const fullMatrix<double> &gSMatZ,
                                  const fullMatrix<double> &nodesXYZ,
                                  const fullMatrix<double> &normals,
                                  fullVector<double> &invCond) const;

  template<bool sign>
  void getInvCondNumAndGradientsGeneral(int nCondNumNodes,
                                        const fullMatrix<double> &gSMatX,
                                        const fullMatrix<double> &gSMatY,
                                        const fullMatrix<double> &gSMatZ,
                                        const fullMatrix<double> &nodesXYZ,
                                        const fullMatrix<double> &normals,
                                        fullMatrix<double> &IDI) const;
  void getInvCondNumAndGradientsGeneral(int nCondNumNodes,                          // No normal given -> unsigned measure
                                        const fullMatrix<double> &gSMatX,
                                        const fullMatrix<double> &gSMatY,
                                        const fullMatrix<double> &gSMatZ,
                                        const fullMatrix<double> &nodesXYZ,
                                        fullMatrix<double> &IDI) const;
  void getSignedInvCondNumAndGradientsGeneral(int nCondNumNodes,                    // Normals given -> signed measure
                                              const fullMatrix<double> &gSMatX,
                                              const fullMatrix<double> &gSMatY,
                                              const fullMatrix<double> &gSMatZ,
                                              const fullMatrix<double> &nodesXYZ,
                                              const fullMatrix<double> &normals,
                                              fullMatrix<double> &IDI) const;


};

#endif
