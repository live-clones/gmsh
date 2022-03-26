// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//

#include <algorithm>
#include "HierarchicalBasisHdivBrick.h"

HierarchicalBasisHdivBrick::HierarchicalBasisHdivBrick(int order)
{
  _pb1 = order;
  _pb2 = order;
  _pb3 = order;
  for(int j = 0; j < 6; j++) {
    _pOrderFace1[j] = order;
    _pOrderFace2[j] = order;
  }
  _nvertex = 8;
  _nedge = 12;
  _nfaceQuad = 6;
  _nfaceTri = 0;
  _nVertexFunction = 0;
  _nEdgeFunction = 0;
  _nQuadFaceFunction = 6 * (order + 1) * (order + 1);
  _nTriFaceFunction = 0;
  _nBubbleFunction = 3 * order * (order + 1) * (order + 1);
}

HierarchicalBasisHdivBrick::~HierarchicalBasisHdivBrick() {}

unsigned int HierarchicalBasisHdivBrick::getNumberOfOrientations() const
{
  return 40320; // factorial 8
}

double HierarchicalBasisHdivBrick::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v,
                                                      const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + u);
  case(2): return 0.5 * (1 - u);
  case(3): return 0.5 * (1 + v);
  case(4): return 0.5 * (1 - v);
  case(5): return 0.5 * (1 + w);
  case(6): return 0.5 * (1 - w);
  default: throw std::string("j must be : 1<=j<=6");
  }
}

void HierarchicalBasisHdivBrick::generateHdivBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  std::vector<std::vector<double> > lobattoVector(3);
  lobattoVector[0] = std::vector<double>(_pb1);
  lobattoVector[1] = std::vector<double>(_pb2);
  lobattoVector[2] = std::vector<double>(_pb3);
  for(int it = 2; it <= _pb1 + 1; it++) {
    lobattoVector[0][it - 2] = OrthogonalPoly::EvalLobatto(it, u);
  }
  for(int it = 2; it <= _pb2 + 1; it++) {
    lobattoVector[1][it - 2] = OrthogonalPoly::EvalLobatto(it, v);
  }
  for(int it = 2; it <= _pb3 + 1; it++) {
    lobattoVector[2][it - 2] = OrthogonalPoly::EvalLobatto(it, w);
  }
  std::vector<std::vector<double> > legendreVector(3);
  legendreVector[0] = std::vector<double>(_pb1 + 1);
  legendreVector[1] = std::vector<double>(_pb2 + 1);
  legendreVector[2] = std::vector<double>(_pb3 + 1);
  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, u);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, v);
  }
  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, w);
  }
  std::vector<double> lambda(6, 0);
  lambda[0] = _affineCoordinate(1, u, v, w);
  lambda[1] = _affineCoordinate(2, u, v, w);
  lambda[2] = _affineCoordinate(3, u, v, w);
  lambda[3] = _affineCoordinate(4, u, v, w);
  lambda[4] = _affineCoordinate(5, u, v, w);
  lambda[5] = _affineCoordinate(6, u, v, w);

  // face  functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int indexLambda = 0;
    std::vector<double> direction(3, 0);
    int uvw1 = 0;
    int uvw2 = 0;
    switch(iFace) {
    case(0):
      indexLambda = 5;
      uvw1 = 0;
      uvw2 = 1;
      direction[2] = 1;
      break;
    case(1):
      indexLambda = 3;
      uvw1 = 0;
      uvw2 = 2;
      direction[1] = 1;
      break;
    case(2):
      indexLambda = 1;
      uvw1 = 1;
      uvw2 = 2;
      direction[0] = 1;
      break;
    case(3):
      indexLambda = 0;
      uvw1 = 1;
      uvw2 = 2;
      direction[0] = 1;
      break;
    case(4):
      indexLambda = 2;
      uvw1 = 0;
      uvw2 = 2;
      direction[1] = 1;
      break;
    case(5):
      indexLambda = 4;
      uvw1 = 0;
      uvw2 = 1;
      direction[2] = 1;
      break;
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace] + 1; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace] + 1; index2++) {
        for(int j = 0; j < 3; j++) {
          faceBasis[indexFaceFunction][j] =
            lambda[indexLambda] * legendreVector[uvw1][index1] *
            legendreVector[uvw2][index2] * direction[j];
        }

        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = lobattoVector[0][ipb1] *
                                           legendreVector[1][ipb2] *
                                           legendreVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][1] = 0;
        bubbleBasis[indexBubbleBasis][2] = 0;
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = 0;
        bubbleBasis[indexBubbleBasis][1] = legendreVector[0][ipb1] *
                                           lobattoVector[1][ipb2] *
                                           legendreVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][2] = 0;
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = 0;
        bubbleBasis[indexBubbleBasis][1] = 0;
        bubbleBasis[indexBubbleBasis][2] = legendreVector[0][ipb1] *
                                           legendreVector[1][ipb2] *
                                           lobattoVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisHdivBrick::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< double > &faceFunctions)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderFace1[i] + 1) * (_pOrderFace2[i] + 1);
    }
    if(flag3 == 1) {
      for(int it1 = 0; it1 < _pOrderFace1[faceNumber] + 1; it1++) {
        for(int it2 = 0; it2 < _pOrderFace2[faceNumber] + 1; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
          if(flag2 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
          faceFunctions[iterator] =
            faceFunctions[iterator] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
    else {
      std::vector<double> uvw(3);
      uvw[0] = u;
      uvw[1] = v;
      uvw[2] = w;
      double dlambda = 0.;
      int var1 = 0;
      int var2 = 0;
      std::vector<double> direction(3, 0);
      std::vector<double> legendreVector1(_pOrderFace1[faceNumber] + 1);
      std::vector<double> legendreVector2(_pOrderFace2[faceNumber] + 1);
      switch(faceNumber) {
      case(0):
        dlambda = -0.5;
        var1 = 0;
        var2 = 1;
        direction[2] = 1;
        break;
      case(1):
        dlambda = -0.5;
        var1 = 0;
        var2 = 2;
        direction[1] = 1;
        break;
      case(2):
        dlambda = -0.5;
        var1 = 1;
        var2 = 2;
        direction[0] = 1;
        break;
      case(3):
        dlambda = 0.5;
        var1 = 1;
        var2 = 2;
        direction[0] = 1;
        break;
      case(4):
        dlambda = 0.5;
        var1 = 0;
        var2 = 2;
        direction[1] = 1;
        break;
      case(5):
        dlambda = 0.5;
        var1 = 0;
        var2 = 1;
        direction[2] = 1;
        break;
      }
      for(int it = 0; it <= _pOrderFace1[faceNumber]; it++) {
        legendreVector1[it] = OrthogonalPoly::EvalLegendre(it, uvw[var1]);
      }
      for(int it = 0; it <= _pOrderFace2[faceNumber]; it++) {
        legendreVector2[it] = OrthogonalPoly::EvalLegendre(it, uvw[var2]);
      }
      for(int index1 = 0; index1 < _pOrderFace2[faceNumber] + 1; index1++) {
        for(int index2 = 0; index2 < _pOrderFace1[faceNumber] + 1; index2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && index1 % 2 == 0) { impactFlag1 = -1; }
          if(flag2 == -1 && index2 % 2 == 0) { impactFlag2 = -1; }
          for(int j = 0; j < 3; j++) {
            faceFunctions[iterator] +=
              dlambda * legendreVector1[index2] * legendreVector2[index1]
                * direction[j] * impactFlag1 * impactFlag2;
          }
          iterator++;
        }
      }
    }
  }
}

void HierarchicalBasisHdivBrick::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< std::vector< double > > &faceFunctions, std::string typeFunction)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderFace1[i] + 1) * (_pOrderFace2[i] + 1);
    }
    if(flag3 == 1) {
      for(int it1 = 0; it1 < _pOrderFace1[faceNumber] + 1; it1++) {
        for(int it2 = 0; it2 < _pOrderFace2[faceNumber] + 1; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
          if(flag2 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
          faceFunctions[iterator][0] =
            faceFunctions[iterator][0] * impactFlag1 * impactFlag2;
          faceFunctions[iterator][1] =
            faceFunctions[iterator][1] * impactFlag1 * impactFlag2;
          faceFunctions[iterator][2] =
            faceFunctions[iterator][2] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
    }
    else {
      std::vector<double> uvw(3);
      uvw[0] = u;
      uvw[1] = v;
      uvw[2] = w;
      double lambda = 0.;
      int var1 = 0;
      int var2 = 0;
      std::vector<double> direction(3, 0);
      std::vector<double> legendreVector1(_pOrderFace1[faceNumber] + 1);
      std::vector<double> legendreVector2(_pOrderFace2[faceNumber] + 1);
      switch(faceNumber) {
      case(0):
        lambda = _affineCoordinate(6, u, v, w);
        var1 = 0;
        var2 = 1;
        direction[2] = 1;
        break;
      case(1):
        lambda = _affineCoordinate(4, u, v, w);
        var1 = 0;
        var2 = 2;
        direction[1] = 1;
        break;
      case(2):
        lambda = _affineCoordinate(2, u, v, w);
        var1 = 1;
        var2 = 2;
        direction[0] = 1;
        break;
      case(3):
        lambda = _affineCoordinate(1, u, v, w);
        var1 = 1;
        var2 = 2;
        direction[0] = 1;
        break;
      case(4):
        lambda = _affineCoordinate(3, u, v, w);
        var1 = 0;
        var2 = 2;
        direction[1] = 1;
        break;
      case(5):
        lambda = _affineCoordinate(5, u, v, w);
        var1 = 0;
        var2 = 1;
        direction[2] = 1;
        break;
      }
      for(int it = 0; it <= _pOrderFace1[faceNumber]; it++) {
        legendreVector1[it] = OrthogonalPoly::EvalLegendre(it, uvw[var1]);
      }
      for(int it = 0; it <= _pOrderFace2[faceNumber]; it++) {
        legendreVector2[it] = OrthogonalPoly::EvalLegendre(it, uvw[var2]);
      }
      for(int index1 = 0; index1 < _pOrderFace2[faceNumber] + 1; index1++) {
        for(int index2 = 0; index2 < _pOrderFace1[faceNumber] + 1; index2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && index1 % 2 == 0) { impactFlag1 = -1; }
          if(flag2 == -1 && index2 % 2 == 0) { impactFlag2 = -1; }
          for(int j = 0; j < 3; j++) {
            faceFunctions[iterator][j] =
              lambda * legendreVector1[index2] * legendreVector2[index1]
                * direction[j] * impactFlag1 * impactFlag2;
          }
          iterator++;
        }
      }
    }
  }
}

void HierarchicalBasisHdivBrick::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector< double > &quadFaceFunctionsAllOrientation,
  const std::vector< double > &triFaceFunctionsAllOrientation,
  std::vector< double > &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += (_pOrderFace1[i] + 1) * (_pOrderFace2[i] + 1);
  }
  int numFaceFunctions =
    (_pOrderFace1[faceNumber] + 1) * (_pOrderFace2[faceNumber] + 1);
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i] = quadFaceFunctionsAllOrientation[i + offset];
  }
}

void HierarchicalBasisHdivBrick::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += (_pOrderFace1[i] + 1) * (_pOrderFace2[i] + 1);
  }
  int numFaceFunctions =
    (_pOrderFace1[faceNumber] + 1) * (_pOrderFace2[faceNumber] + 1);
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisHdivBrick::generateDivBasis(
  double const &u, double const &v, double const &w,
  std::vector< double > &faceBasis,
  std::vector< double > &bubbleBasis)
{
  std::vector<std::vector<double> > lobattoVector(3);
  lobattoVector[0] = std::vector<double>(_pb1);
  lobattoVector[1] = std::vector<double>(_pb2);
  lobattoVector[2] = std::vector<double>(_pb3);
  std::vector<std::vector<double> > dlobattoVector(3);
  dlobattoVector[0] = std::vector<double>(_pb1);
  dlobattoVector[1] = std::vector<double>(_pb2);
  dlobattoVector[2] = std::vector<double>(_pb3);
  for(int it = 2; it <= _pb1 + 1; it++) {
    lobattoVector[0][it - 2] = OrthogonalPoly::EvalLobatto(it, u);
    dlobattoVector[0][it - 2] = OrthogonalPoly::EvalDLobatto(it, u);
  }
  for(int it = 2; it <= _pb2 + 1; it++) {
    lobattoVector[1][it - 2] = OrthogonalPoly::EvalLobatto(it, v);
    dlobattoVector[1][it - 2] = OrthogonalPoly::EvalDLobatto(it, v);
  }
  for(int it = 2; it <= _pb3 + 1; it++) {
    lobattoVector[2][it - 2] = OrthogonalPoly::EvalLobatto(it, w);
    dlobattoVector[2][it - 2] = OrthogonalPoly::EvalDLobatto(it, w);
  }

  std::vector<std::vector<double> > legendreVector(3);
  legendreVector[0] = std::vector<double>(_pb1 + 1);
  legendreVector[1] = std::vector<double>(_pb2 + 1);
  legendreVector[2] = std::vector<double>(_pb3 + 1);
  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, u);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, v);
  }
  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, w);
  }
  std::vector<double> lambda(6, 0);
  lambda[0] = _affineCoordinate(1, u, v, w);
  lambda[1] = _affineCoordinate(2, u, v, w);
  lambda[2] = _affineCoordinate(3, u, v, w);
  lambda[3] = _affineCoordinate(4, u, v, w);
  lambda[4] = _affineCoordinate(5, u, v, w);
  lambda[5] = _affineCoordinate(6, u, v, w);

  std::vector<double> dlambda(6, 0);
  dlambda[0] = 0.5;
  dlambda[1] = -0.5;
  dlambda[2] = 0.5;
  dlambda[3] = -0.5;
  dlambda[4] = 0.5;
  dlambda[5] = -0.5;

  // face  functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int indexLambda = 0;
    std::vector<double> direction(3, 0);
    int uvw1 = 0;
    int uvw2 = 0;
    switch(iFace) {
    case(0):
      indexLambda = 5;
      uvw1 = 0;
      uvw2 = 1;
      direction[2] = 1;
      break;
    case(1):
      indexLambda = 3;
      uvw1 = 0;
      uvw2 = 2;
      direction[1] = 1;
      break;
    case(2):
      indexLambda = 1;
      uvw1 = 1;
      uvw2 = 2;
      direction[0] = 1;
      break;
    case(3):
      indexLambda = 0;
      uvw1 = 1;
      uvw2 = 2;
      direction[0] = 1;
      break;
    case(4):
      indexLambda = 2;
      uvw1 = 0;
      uvw2 = 2;
      direction[1] = 1;
      break;
    case(5):
      indexLambda = 4;
      uvw1 = 0;
      uvw2 = 1;
      direction[2] = 1;
      break;
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace] + 1; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace] + 1; index2++) {
        faceBasis[indexFaceFunction] = 0.f;
        for(int j = 0; j < 3; j++) {
          faceBasis[indexFaceFunction] +=
            dlambda[indexLambda] * legendreVector[uvw1][index1] *
            legendreVector[uvw2][index2] * direction[j];
        }

        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        bubbleBasis[indexBubbleBasis] = dlobattoVector[0][ipb1] *
                                        legendreVector[1][ipb2] *
                                        legendreVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        bubbleBasis[indexBubbleBasis] = legendreVector[0][ipb1] *
                                        dlobattoVector[1][ipb2] *
                                        legendreVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        bubbleBasis[indexBubbleBasis] = legendreVector[0][ipb1] *
                                        legendreVector[1][ipb2] *
                                        dlobattoVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisHdivBrick::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{
  int it = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    for(int index1 = 0; index1 <= _pOrderFace1[iFace] + 1; index1++) {
      for(int index2 = 0; index2 <= _pOrderFace2[iFace] + 1; index2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(index1, index2);
        it++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
}
