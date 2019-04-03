// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H1_LINE_H
#define HIERARCHICAL_BASIS_H1_LINE_H

#include <algorithm>
#include <vector>

#include "HierarchicalBasisH1.h"
/*
 *
 *
 *
 *
 *   0          +1
 * --+-----------+---> u
 *
 *
 *
 *
 *
 *
 *
 */
class HierarchicalBasisH1Line : public HierarchicalBasisH1 {
public:
  HierarchicalBasisH1Line(int pe);
  virtual ~HierarchicalBasisH1Line();
  // vertexBasis=[v0,v1]
  // edgeBasis=[phie_{2},...,phie_{pe}]
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis);
  virtual void
  generateGradientBasis(double const &u, double const &v, double const &w,
                        std::vector<std::vector<double> > &gradientVertex,
                        std::vector<std::vector<double> > &gradientEdge,
                        std::vector<std::vector<double> > &gradientFace,
                        std::vector<std::vector<double> > &gradientBubble);

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                             std::vector<double> &edgeBasis){};
  virtual void
  orientEdgeGrad(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &gradientEdge){};

  virtual void orientFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis){};

  virtual void
  orientFaceGrad(double const &u, double const &v, double const &w,
                    int const &flag1, int const &flag2, int const &flag3,
                    int const &faceNumber,
                    std::vector<std::vector<double> > &gradientFace){};

private:
  int _pe; //  edge function order in  direction u
  static double
  _affineCoordinate(int j,
                    double u); // affine coordinate lambdaj j={1,2}
  double _getDetJacobian(); // for transformation [-1;1] -> [0,1]
};

#endif
