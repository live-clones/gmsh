// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).

#ifndef HIERARCHICAL_BASIS_H
#define HIERARCHICAL_BASIS_H

#include <vector>
#include "OrthogonalPoly.h"

class HierarchicalBasis {
protected:
  int _nvertex;
  int _nedge;
  int _nfaceQuad; // number of quadrilateral faces
  int _nfaceTri; // number of triangular faces
  int _nVertexFunction;
  int _nEdgeFunction;
  int _nQuadFaceFunction;
  int _nTriFaceFunction;
  int _nBubbleFunction;

public:
  virtual ~HierarchicalBasis() = 0;
  int getnVertexFunction() const;
  int getnEdgeFunction() const;
  int getnTriFaceFunction() const;
  int getnQuadFaceFunction() const;
  int getnBubbleFunction() const;
  int getNumTriFace() const;
  int getNumQuadFace() const;
  int getNumEdge() const;
  virtual void generateBasis(double const &u, double const &v, double const &w,
                             std::vector<double> &vertexBasis,
                             std::vector<double> &edgeBasis,
                             std::vector<double> &faceBasis,
                             std::vector<double> &bubbleBasis) = 0;

  virtual void generateBasis(
    double const &u, double const &v, double const &w,
    std::vector<std::vector<double> > &vertexBasis,
    std::vector<std::vector<double> > &edgeBasis,
    std::vector<std::vector<double> > &faceBasis,
    std::vector<std::vector<double> > &bubbleBasis,
    std::string typeFunction) = 0; // typeFunction =GradH1Legendre ,
                                   // HcurlLegendre,curlHcurlLegendre

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<std::vector<double> > &edgeBasis) = 0;

  virtual void
  orientFace(double const &u, double const &v, double const &w,
             int const &flag1, int const &flag2, int const &flag3,
             int const &faceNumber,
             std::vector<std::vector<double> > &faceBasis,
             std::string typeFunction) = 0; // typeFunction =GradH1Legendre ,
                                            // HcurlLegendre,curlHcurlLegendre

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<double> &edgeFunctions) = 0;
  virtual void orientFace(double const &u, double const &v, double const &w,
                          int const &flag1, int const &flag2, int const &flag3,
                          int const &faceNumber,
                          std::vector<double> &faceFunctions) = 0;

  // Get information about the `keys' defined in GMSH API for one  element
  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo) = 0;
};

#endif
