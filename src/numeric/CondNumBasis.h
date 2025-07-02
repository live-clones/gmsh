// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CONDNUMBASIS_H
#define CONDNUMBASIS_H

#include <map>
#include <vector>
#include "JacobianBasis.h"
#include "fullMatrix.h"

class CondNumBasis {
private:
  const GradientBasis *_gradBasis;

  const int _tag, _dim, _condNumOrder;

  fullVector<double> dPrimBaryShape_dX, dPrimBaryShape_dY, dPrimBaryShape_dZ;

  int _nCondNumNodes;
  int _nMapNodes, _nPrimMapNodes;

public:
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
                            fullVector<double> &invCond) const
  {
    getInvCondNumGeneral(_nCondNumNodes, _gradBasis->dShapeIdealMat_dX,
                         _gradBasis->dShapeIdealMat_dY,
                         _gradBasis->dShapeIdealMat_dZ, nodesXYZ, invCond);
  }
  inline void getSignedInvCondNum(const fullMatrix<double> &nodesXYZ,
                                  const fullMatrix<double> &normals,
                                  fullVector<double> &invCond) const
  {
    getSignedInvCondNumGeneral(_nCondNumNodes, _gradBasis->dShapeIdealMat_dX,
                               _gradBasis->dShapeIdealMat_dY,
                               _gradBasis->dShapeIdealMat_dZ, nodesXYZ, normals,
                               invCond);
  }
  inline void getInvCondNumAndGradients(const fullMatrix<double> &nodesXYZ,
                                        fullMatrix<double> &IDI) const
  {
    getInvCondNumAndGradientsGeneral(
      _nCondNumNodes, _gradBasis->dShapeIdealMat_dX,
      _gradBasis->dShapeIdealMat_dY, _gradBasis->dShapeIdealMat_dZ, nodesXYZ,
      IDI);
  }
  inline void
  getSignedInvCondNumAndGradients(const fullMatrix<double> &nodesXYZ,
                                  const fullMatrix<double> &normals,
                                  fullMatrix<double> &IDI) const
  {
    getSignedInvCondNumAndGradientsGeneral(
      _nCondNumNodes, _gradBasis->dShapeIdealMat_dX,
      _gradBasis->dShapeIdealMat_dY, _gradBasis->dShapeIdealMat_dZ, nodesXYZ,
      normals, IDI);
  }

private:
  template <bool sign>
  void getInvCondNumGeneral(int nCondNumNodes,
                            const fullMatrix<double> &dSMat_dX,
                            const fullMatrix<double> &dSMat_dY,
                            const fullMatrix<double> &dSMat_dZ,
                            const fullMatrix<double> &nodesXYZ,
                            const fullMatrix<double> &normals,
                            fullVector<double> &invCond) const;
  void getInvCondNumGeneral(int nCondNumNodes,
                            const fullMatrix<double> &dSMat_dX,
                            const fullMatrix<double> &dSMat_dY,
                            const fullMatrix<double> &dSMat_dZ,
                            const fullMatrix<double> &nodesXYZ,
                            fullVector<double> &invCond) const;
  void getSignedInvCondNumGeneral(int nCondNumNodes,
                                  const fullMatrix<double> &dSMat_dX,
                                  const fullMatrix<double> &dSMat_dY,
                                  const fullMatrix<double> &dSMat_dZ,
                                  const fullMatrix<double> &nodesXYZ,
                                  const fullMatrix<double> &normals,
                                  fullVector<double> &invCond) const;

  template <bool sign>
  void getInvCondNumAndGradientsGeneral(int nCondNumNodes,
                                        const fullMatrix<double> &dSMat_dX,
                                        const fullMatrix<double> &dSMat_dY,
                                        const fullMatrix<double> &dSMat_dZ,
                                        const fullMatrix<double> &nodesXYZ,
                                        const fullMatrix<double> &normals,
                                        fullMatrix<double> &IDI) const;
  void getInvCondNumAndGradientsGeneral(
    int nCondNumNodes, // No normal given -> unsigned measure
    const fullMatrix<double> &dSMat_dX, const fullMatrix<double> &dSMat_dY,
    const fullMatrix<double> &dSMat_dZ, const fullMatrix<double> &nodesXYZ,
    fullMatrix<double> &IDI) const;
  void getSignedInvCondNumAndGradientsGeneral(
    int nCondNumNodes, // Normals given -> signed measure
    const fullMatrix<double> &dSMat_dX, const fullMatrix<double> &dSMat_dY,
    const fullMatrix<double> &dSMat_dZ, const fullMatrix<double> &nodesXYZ,
    const fullMatrix<double> &normals, fullMatrix<double> &IDI) const;
};

#endif
