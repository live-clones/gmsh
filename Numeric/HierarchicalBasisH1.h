// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H1_H
#define HIERARCHICAL_BASIS_H1_H

#include <vector>
#include "OrthogonalPoly.h"

class HierarchicalBasisH1 {
protected:
  int _nvertex;
  int _nedge;
  int _nface;
  int _nVertexFunction;
  int _nEdgeFunction;
  int _nFaceFunction;
  int _nBubbleFunction;

public:
  virtual ~HierarchicalBasisH1() = 0;
  int getnVertexFunction() const;
  int getnEdgeFunction() const;
  int getnFaceFunction() const;
  int getnBubbleFunction() const;
  int getNumFace() const;
  int getNumEdge() const;
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis) = 0;
  virtual void
  generateGradientBasis(double const &u, double const &v, double const &w,
                        std::vector<std::vector<double> > &gradientVertex,
                        std::vector<std::vector<double> > &gradientEdge,
                        std::vector<std::vector<double> > &gradientFace,
                        std::vector<std::vector<double> > &gradientBubble) = 0;
  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                             std::vector<double> &edgeBasis) = 0;
  virtual void
  orientEdgeGrad(int const &flagOrientation, int const &edgeNumber,
                    std::vector<std::vector<double> > &gradientEdge) = 0;

  virtual void orientFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceBasis) = 0;

  virtual void
  orientFaceGrad(double const &u, double const &v, double const &w,
                    int const &flag1, int const &flag2, int const &flag3,
                    int const &faceNumber,
                    std::vector<std::vector<double> > &gradientFace) = 0;
};

#endif
