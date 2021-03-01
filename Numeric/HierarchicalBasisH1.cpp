// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

#include "HierarchicalBasisH1.h"
HierarchicalBasisH1::~HierarchicalBasisH1() {}

void HierarchicalBasisH1::addAllOrientedFaceFunctions(
  double const &u, double const &v, double const &w,
  const std::vector<double> &faceFunctions,
  std::vector<double> &quadFaceFunctionsAllOrientations,
  std::vector<double> &triFaceFunctionsAllOrientations)
{
  int it = 0;
  // quadrilateral faces
  if(_nQuadFaceFunction > 0) {
    for(int iOrientation = 0; iOrientation < 8; iOrientation++) {
      int flag1 = 1;
      int flag2 = 1;
      int flag3 = 1;
      std::vector<double> orientedFaceFunction(_nQuadFaceFunction +
                                               _nTriFaceFunction);
      for(int r = 0; r < _nQuadFaceFunction + _nTriFaceFunction; r++) {
        orientedFaceFunction[r] = faceFunctions[r];
      }
      switch(iOrientation) {
      case(0): // case 111
        flag1 = 1, flag2 = 1, flag3 = 1;
        break;
      case(1): // case -111
        flag1 = -1, flag2 = 1, flag3 = 1;
        break;
      case(2): // case 1-11
        flag1 = 1, flag2 = -1, flag3 = 1;
        break;
      case(3): // case -1-11
        flag1 = -1, flag2 = -1, flag3 = 1;
        break;
      case(4): // case 11-1
        flag1 = 1, flag2 = 1, flag3 = -1;
        break;
      case(5): // case -11-1
        flag1 = -1, flag2 = 1, flag3 = -1;
        break;
      case(6): // case 1-1-1
        flag1 = 1, flag2 = -1, flag3 = -1;
        break;
      case(7): // case -1-1-1
        flag1 = -1, flag2 = -1, flag3 = -1;
        break;
      }
      for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
        orientOneFace(u, v, w, flag1, flag2, flag3, iFace,
                      orientedFaceFunction);
      }
      for(int r = 0; r < _nQuadFaceFunction; r++) {
        quadFaceFunctionsAllOrientations[it] = orientedFaceFunction[r];
        it++;
      }
    }
  }
  // Triangular faces
  it = 0;
  if(_nTriFaceFunction > 0) {
    for(int iOrientation = 0; iOrientation < 6; iOrientation++) {
      std::vector<double> orientedFaceFunction(_nQuadFaceFunction +
                                               _nTriFaceFunction);
      for(int r = 0; r < _nQuadFaceFunction + _nTriFaceFunction; r++) {
        orientedFaceFunction[r] = faceFunctions[r];
      }
      int flag1 = 0;
      int flag2 = 1;
      int flag3 = 1;
      switch(iOrientation) {
      case(0): // case 01
        flag1 = 0, flag2 = 1;
        break;
      case(1): // case 11
        flag1 = 1, flag2 = 1;
        break;
      case(2): // case 21
        flag1 = 2, flag2 = 1;
        break;
      case(3): // case 0-1
        flag1 = 0, flag2 = -1;
        break;
      case(4): // case 1-1
        flag1 = 1, flag2 = -1;
        break;
      case(5): // case 2-1
        flag1 = 2, flag2 = -1;
        break;
      }
      for(int iFace = _nfaceQuad; iFace < _nfaceQuad + _nfaceTri; iFace++) {
        orientOneFace(u, v, w, flag1, flag2, flag3, iFace,
                      orientedFaceFunction);
      }
      for(int r = 0; r < _nTriFaceFunction; r++) {
        triFaceFunctionsAllOrientations[it] =
          orientedFaceFunction[r + _nQuadFaceFunction];
        it++;
      }
    }
  }
}
void HierarchicalBasisH1::addAllOrientedFaceFunctions(
  double const &u, double const &v, double const &w,
  const std::vector<std::vector<double> > &faceFunctions,
  std::vector<std::vector<double> > &quadFaceFunctionsAllOrientations,
  std::vector<std::vector<double> > &triFaceFunctionsAllOrientations,
  std::string typeFunction)
{
  int it = 0;
  // quadrilateral faces
  if(_nQuadFaceFunction > 0) {
    for(int iOrientation = 0; iOrientation < 8; iOrientation++) {
      int flag1 = 1;
      int flag2 = 1;
      int flag3 = 1;
      std::vector<std::vector<double> > orientedFaceFunction(
        _nQuadFaceFunction + _nTriFaceFunction, std::vector<double>(3, 0));
      for(int r = 0; r < _nQuadFaceFunction + _nTriFaceFunction; r++) {
        orientedFaceFunction[r][0] = faceFunctions[r][0];
        orientedFaceFunction[r][1] = faceFunctions[r][1];
        orientedFaceFunction[r][2] = faceFunctions[r][2];
      }
      switch(iOrientation) {
      case(0): // case 111
        flag1 = 1, flag2 = 1, flag3 = 1;
        break;
      case(1): // case -111
        flag1 = -1, flag2 = 1, flag3 = 1;
        break;
      case(2): // case 1-11
        flag1 = 1, flag2 = -1, flag3 = 1;
        break;
      case(3): // case -1-11
        flag1 = -1, flag2 = -1, flag3 = 1;
        break;
      case(4): // case 11-1
        flag1 = 1, flag2 = 1, flag3 = -1;
        break;
      case(5): // case -11-1
        flag1 = -1, flag2 = 1, flag3 = -1;
        break;
      case(6): // case 1-1-1
        flag1 = 1, flag2 = -1, flag3 = -1;
        break;
      case(7): // case -1-1-1
        flag1 = -1, flag2 = -1, flag3 = -1;
        break;
      }
      for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
        orientOneFace(u, v, w, flag1, flag2, flag3, iFace,
                      orientedFaceFunction);
      }
      for(int r = 0; r < _nQuadFaceFunction; r++) {
        quadFaceFunctionsAllOrientations[it][0] = orientedFaceFunction[r][0];
        quadFaceFunctionsAllOrientations[it][1] = orientedFaceFunction[r][1];
        quadFaceFunctionsAllOrientations[it][2] = orientedFaceFunction[r][2];
        it++;
      }
    }
  }
  // Triangular faces
  it = 0;
  if(_nTriFaceFunction > 0) {
    for(int iOrientation = 0; iOrientation < 6; iOrientation++) {
      std::vector<std::vector<double> > orientedFaceFunction(
        _nQuadFaceFunction + _nTriFaceFunction, std::vector<double>(3, 0));
      for(int r = 0; r < _nQuadFaceFunction + _nTriFaceFunction; r++) {
        orientedFaceFunction[r] = faceFunctions[r];
      }
      int flag1 = 0;
      int flag2 = 1;
      int flag3 = 1;
      switch(iOrientation) {
      case(0): // case 01
        flag1 = 0, flag2 = 1;
        break;
      case(1): // case 11
        flag1 = 1, flag2 = 1;
        break;
      case(2): // case 21
        flag1 = 2, flag2 = 1;
        break;
      case(3): // case 0-1
        flag1 = 0, flag2 = -1;
        break;
      case(4): // case 1-1
        flag1 = 1, flag2 = -1;
        break;
      case(5): // case 2-1
        flag1 = 2, flag2 = -1;
        break;
      }
      for(int iFace = _nfaceQuad; iFace < _nfaceQuad + _nfaceTri; iFace++) {
        orientOneFace(u, v, w, flag1, flag2, flag3, iFace,
                      orientedFaceFunction);
      }
      for(int r = 0; r < _nTriFaceFunction; r++) {
        triFaceFunctionsAllOrientations[it][0] =
          orientedFaceFunction[r + _nQuadFaceFunction][0];
        triFaceFunctionsAllOrientations[it][1] =
          orientedFaceFunction[r + _nQuadFaceFunction][1];
        triFaceFunctionsAllOrientations[it][2] =
          orientedFaceFunction[r + _nQuadFaceFunction][2];
        it++;
      }
    }
  }
}
