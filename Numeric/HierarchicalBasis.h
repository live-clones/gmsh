// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
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
#include <algorithm>

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
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<double> &faceFunctions) = 0;
  virtual void orientOneFace(double const &u, double const &v, double const &w,
                             int const &flag1, int const &flag2,
                             int const &flag3, int const &faceNumber,
                             std::vector<std::vector<double> > &faceFunctions,
                             std::string typeFunction) = 0;

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
  virtual unsigned int getNumberOfOrientations() const = 0;
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

  virtual void
  orientEdge(int const &flagOrientation, int const &edgeNumber,
             std::vector<std::vector<double> > &edgeBasis,
             const std::vector<std::vector<double> > &eTablePositiveFlag,
             const std::vector<std::vector<double> > &eTableNegativeFlag) = 0;

  virtual void
  orientEdgeFunctionsForNegativeFlag(std::vector<double> &edgeFunctions) = 0;
  virtual void orientEdgeFunctionsForNegativeFlag(
    std::vector<std::vector<double> > &edgeFunctions) = 0;

  virtual void addAllOrientedFaceFunctions(
    double const &u, double const &v, double const &w,
    const std::vector<double> &faceFunctions,
    std::vector<double> &quadFaceFunctionsAllOrientation,
    std::vector<double> &triFaceFunctionsAllOrientation) = 0;

  virtual void addAllOrientedFaceFunctions(
    double const &u, double const &v, double const &w,
    const std::vector<std::vector<double> > &faceFunctions,
    std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
    std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
    std::string typeFunction) = 0; // typeFunction =GradH1Legendre ,
                                   // HcurlLegendre,curlHcurlLegendre
  virtual void
  orientFace(int const &flag1, int const &flag2, int const &flag3,
             int const &faceNumber,
             const std::vector<double> &quadFaceFunctionsAllOrientation,
             const std::vector<double> &triFaceFunctionsAllOrientation,
             std::vector<double> &fTableCopy) = 0;
  virtual void orientFace(
    int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
    const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
    const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
    std::vector<std::vector<double> > &fTableCopy) = 0;

  virtual void orientEdge(int const &flagOrientation, int const &edgeNumber,
                          std::vector<double> &edgeFunctions,
                          const std::vector<double> &eTablePositiveFlag,
                          const std::vector<double> &eTableNegativeFlag) = 0;
  inline int numberOrientationQuadFace(int const &flag1, int const &flag2,
                                       int const &flag3)
  {
    if(flag1 == 1 && flag2 == 1 && flag3 == 1) { return 0; }
    else if(flag1 == -1 && flag2 == 1 && flag3 == 1) {
      return 1;
    }
    else if(flag1 == 1 && flag2 == -1 && flag3 == 1) {
      return 2;
    }
    else if(flag1 == -1 && flag2 == -1 && flag3 == 1) {
      return 3;
    }
    else if(flag1 == 1 && flag2 == 1 && flag3 == -1) {
      return 4;
    }
    else if(flag1 == -1 && flag2 == 1 && flag3 == -1) {
      return 5;
    }
    else if(flag1 == 1 && flag2 == -1 && flag3 == -1) {
      return 6;
    }
    else {
      return 7;
    }
  }
  inline int numberOrientationTriFace(int const &flag1, int const &flag2)
  {
    if(flag1 == 0 && flag2 == 1) { return 0; }
    else if(flag1 == 1 && flag2 == 1) {
      return 1;
    }
    else if(flag1 == 2 && flag2 == 1) {
      return 2;
    }
    else if(flag1 == 0 && flag2 == -1) {
      return 3;
    }
    else if(flag1 == 1 && flag2 == -1) {
      return 4;
    }
    else {
      return 5;
    }
  }

  // Get information about the `keys' defined in GMSH API for one  element
  virtual void getKeysInfo(std::vector<int> &functionTypeInfo,
                           std::vector<int> &orderInfo) = 0;
};

#endif
