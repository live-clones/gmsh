// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Ismail Badia.

#include <algorithm>
#include "HierarchicalBasisHcurlBrick.h"

HierarchicalBasisHcurlBrick::HierarchicalBasisHcurlBrick(int order)
{
  _pb1 = order;
  _pb2 = order;
  _pb3 = order;
  for(int i = 0; i < 12; i++) { _pOrderEdge[i] = order; }
  for(int j = 0; j < 6; j++) {
    _pOrderFace1[j] = order;
    _pOrderFace2[j] = order;
  }
  _nvertex = 8;
  _nedge = 12;
  _nfaceQuad = 6;
  _nfaceTri = 0;
  _nVertexFunction = 0;
  _nEdgeFunction = 12 * order + 12;
  _nQuadFaceFunction = 12 * order * (order + 1);
  _nTriFaceFunction = 0;
  _nBubbleFunction = 3 * order * order * (order + 1);
}

HierarchicalBasisHcurlBrick::~HierarchicalBasisHcurlBrick() {}

unsigned int HierarchicalBasisHcurlBrick::getNumberOfOrientations() const
{
  return 40320; // factorial 8
}

double HierarchicalBasisHcurlBrick::_affineCoordinate(const int &j,
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

void HierarchicalBasisHcurlBrick::generateHcurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
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
  std::vector<double> product(12, 0);
  product[0] = lambda[3] * lambda[5];
  product[1] = lambda[1] * lambda[5];
  product[2] = lambda[1] * lambda[3];
  product[3] = lambda[0] * lambda[5];
  product[4] = lambda[3] * lambda[0];
  product[5] = lambda[2] * lambda[5];
  product[6] = lambda[2] * lambda[0];
  product[7] = lambda[2] * lambda[1];
  product[8] = lambda[3] * lambda[4];
  product[9] = lambda[4] * lambda[1];
  product[10] = lambda[4] * lambda[0];
  product[11] = lambda[4] * lambda[2];
  int indexEdgeBasis = 0;
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    int uvw = 0;
    std::vector<double> direction(3, 0);
    switch(iEdge) {
    case(0):
    case(5):
    case(8):
    case(11):
      uvw = 0;
      direction[0] = 1;
      break;
    case(1):
    case(3):
    case(9):
    case(10):
      uvw = 1;
      direction[1] = 1;
      break;
    case(2):
    case(4):
    case(6):;
    case(7):
      uvw = 2;
      direction[2] = 1;
      break;
    }
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] + 1;
        indexEdgeFunc++) {
      for(int j = 0; j < 3; j++) {
        edgeBasis[indexEdgeBasis][j] =
          direction[j] * legendreVector[uvw][indexEdgeFunc] * product[iEdge];
      }
      indexEdgeBasis++;
    }
  }

  // face  functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int indexLambda = 0;
    std::vector<double> direction1(3, 0);
    std::vector<double> direction2(3, 0);
    int uvw1 = 0;
    int uvw2 = 0;
    switch(iFace) {
    case(0):
      indexLambda = 5;
      uvw1 = 0;
      uvw2 = 1;
      direction1[0] = 1;
      direction2[1] = 1;
      break;
    case(1):
      indexLambda = 3;
      uvw1 = 0;
      uvw2 = 2;
      direction1[0] = 1;
      direction2[2] = 1;
      break;
    case(2):
      indexLambda = 1;
      uvw1 = 1;
      uvw2 = 2;
      direction1[1] = 1;
      direction2[2] = 1;
      break;
    case(3):
      indexLambda = 0;
      uvw1 = 1;
      uvw2 = 2;
      direction1[1] = 1;
      direction2[2] = 1;
      break;
    case(4):
      indexLambda = 2;
      uvw1 = 0;
      uvw2 = 2;
      direction1[0] = 1;
      direction2[2] = 1;
      break;
    case(5):
      indexLambda = 4;
      uvw1 = 0;
      uvw2 = 1;
      direction1[0] = 1;
      direction2[1] = 1;
      break;
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace] + 1; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace]; index2++) {
        for(int j = 0; j < 3; j++) {
          faceBasis[indexFaceFunction][j] =
            lambda[indexLambda] * legendreVector[uvw1][index1] *
            lobattoVector[uvw2][index2] * direction1[j];
        }

        indexFaceFunction++;
      }
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace]; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace] + 1; index2++) {
        for(int j = 0; j < 3; j++) {
          faceBasis[indexFaceFunction][j] =
            lambda[indexLambda] * lobattoVector[uvw1][index1] *
            legendreVector[uvw2][index2] * direction2[j];
        }

        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = legendreVector[0][ipb1] *
                                           lobattoVector[1][ipb2] *
                                           lobattoVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][1] = 0;
        bubbleBasis[indexBubbleBasis][2] = 0;
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = 0;
        bubbleBasis[indexBubbleBasis][1] = lobattoVector[0][ipb1] *
                                           legendreVector[1][ipb2] *
                                           lobattoVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][2] = 0;
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = 0;
        bubbleBasis[indexBubbleBasis][1] = 0;
        bubbleBasis[indexBubbleBasis][2] = lobattoVector[0][ipb1] *
                                           lobattoVector[1][ipb2] *
                                           legendreVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisHcurlBrick::orientEdge(
  int const &flagOrientation, int const &edgeNumber,
  std::vector<std::vector<double> > &edgeFunctions,
  const std::vector<std::vector<double> > &eTablePositiveFlag,
  const std::vector<std::vector<double> > &eTableNegativeFlag)
{
  if(flagOrientation == -1) {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] + 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber];
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k][0] = eTableNegativeFlag[k][0];
      edgeFunctions[k][1] = eTableNegativeFlag[k][1];
      edgeFunctions[k][2] = eTableNegativeFlag[k][2];
    }
  }
  else {
    int constant1 = 0;
    int constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] + 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber];
    for(int k = constant1; k <= constant2; k++) {
      edgeFunctions[k][0] = eTablePositiveFlag[k][0];
      edgeFunctions[k][1] = eTablePositiveFlag[k][1];
      edgeFunctions[k][2] = eTablePositiveFlag[k][2];
    }
  }
}
void HierarchicalBasisHcurlBrick::orientEdgeFunctionsForNegativeFlag(
  std::vector<std::vector<double> > &edgeFunctions)
{
  int constant1 = 0;
  int constant2 = 0;
  for(int edgeNumber = 0; edgeNumber < _nedge; edgeNumber++) {
    constant2 = 0;
    constant2 = 0;
    for(int i = 0; i <= edgeNumber; i++) { constant2 += _pOrderEdge[i] + 1; }
    constant2 = constant2 - 1;
    constant1 = constant2 - _pOrderEdge[edgeNumber];
    for(int k = constant1; k <= constant2; k++) {
      if((k - constant1) % 2 == 0) {
        edgeFunctions[k][0] = edgeFunctions[k][0] * (-1);
        edgeFunctions[k][1] = edgeFunctions[k][1] * (-1);
        edgeFunctions[k][2] = edgeFunctions[k][2] * (-1);
      }
    }
  }
}
void HierarchicalBasisHcurlBrick::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{
  if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderFace1[i] + 1) * _pOrderFace2[i] +
                  (_pOrderFace2[i] + 1) * _pOrderFace1[i];
    }
    if(flag3 == 1) {
      for(int it1 = 0; it1 < _pOrderFace1[faceNumber] + 1; it1++) {
        for(int it2 = 0; it2 < _pOrderFace2[faceNumber]; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
          if(flag2 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
          faceFunctions[iterator][0] =
            faceFunctions[iterator][0] * impactFlag1 * impactFlag2;
          faceFunctions[iterator][1] =
            faceFunctions[iterator][1] * impactFlag1 * impactFlag2;
          faceFunctions[iterator][2] =
            faceFunctions[iterator][2] * impactFlag1 * impactFlag2;
          iterator++;
        }
      }
      for(int it1 = 0; it1 < _pOrderFace1[faceNumber]; it1++) {
        for(int it2 = 0; it2 < _pOrderFace2[faceNumber] + 1; it2++) {
          int impactFlag1 = 1;
          int impactFlag2 = 1;
          if(flag1 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
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
      if(typeFunction == "HcurlLegendre") {
        std::vector<double> uvw(3);
        uvw[0] = u;
        uvw[1] = v;
        uvw[2] = w;
        double lambda = 0;
        int var1 = 0;
        int var2 = 0;
        switch(faceNumber) {
        case(0):
          lambda = _affineCoordinate(6, u, v, w);
          var1 = 0;
          var2 = 1;
          break;
        case(1):
          lambda = _affineCoordinate(4, u, v, w);
          var1 = 0;
          var2 = 2;
          break;
        case(2):
          lambda = _affineCoordinate(2, u, v, w);
          var1 = 1;
          var2 = 2;
          break;
        case(3):
          lambda = _affineCoordinate(1, u, v, w);
          var1 = 1;
          var2 = 2;
          break;
        case(4):
          lambda = _affineCoordinate(3, u, v, w);
          var1 = 0;
          var2 = 2;
          break;
        case(5):
          lambda = _affineCoordinate(5, u, v, w);
          var1 = 0;
          var2 = 1;
          break;
        }
        std::vector<double> lkVector1(_pOrderFace2[faceNumber]);
        std::vector<double> lkVector2(_pOrderFace1[faceNumber]);
        std::vector<double> legendreVector1(_pOrderFace1[faceNumber] + 1);
        std::vector<double> legendreVector2(_pOrderFace2[faceNumber] + 1);
        for(int it = 2; it <= _pOrderFace2[faceNumber] + 1; it++) {
          lkVector1[it - 2] = OrthogonalPoly::EvalLobatto(it, uvw[var2]);
        }
        for(int it = 2; it <= _pOrderFace1[faceNumber] + 1; it++) {
          lkVector2[it - 2] = OrthogonalPoly::EvalLobatto(it, uvw[var1]);
        }
        for(int it = 0; it <= _pOrderFace1[faceNumber]; it++) {
          legendreVector1[it] = OrthogonalPoly::EvalLegendre(it, uvw[var1]);
        }
        for(int it = 0; it <= _pOrderFace2[faceNumber]; it++) {
          legendreVector2[it] = OrthogonalPoly::EvalLegendre(it, uvw[var2]);
        }
        std::vector<double> direction1(3, 0);
        direction1[var1] = 1;
        std::vector<double> direction2(3, 0);
        direction2[var2] = 1;
        for(int it1 = 0; it1 < _pOrderFace2[faceNumber] + 1; it1++) {
          for(int it2 = 0; it2 < _pOrderFace1[faceNumber]; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag2 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
            if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
            for(int itVector = 0; itVector < 3; itVector++) {
              faceFunctions[iterator][itVector] =
                lambda * legendreVector2[it1] * lkVector2[it2] * impactFlag1 *
                impactFlag2 * direction2[itVector];
            }
            iterator++;
          }
        }
        for(int it1 = 0; it1 < _pOrderFace2[faceNumber]; it1++) {
          for(int it2 = 0; it2 < _pOrderFace1[faceNumber] + 1; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag1 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
            for(int itVector = 0; itVector < 3; itVector++) {
              faceFunctions[iterator][itVector] =
                lambda * legendreVector1[it2] * lkVector1[it1] * impactFlag1 *
                impactFlag2 * direction1[itVector];
            }
            iterator++;
          }
        }
      }
      else if(typeFunction == "CurlHcurlLegendre") {
        std::vector<double> vec1(3, 0);
        std::vector<double> vec2(3, 0);
        std::vector<double> uvw(3);
        uvw[0] = u;
        uvw[1] = v;
        uvw[2] = w;
        int uvw1 = 0;
        int uvw2 = 0;
        int il1 = 0;
        int jl1 = 0;
        int il2 = 0;
        int jl2 = 0;
        switch(faceNumber) {
        case(0):
          uvw1 = 0;
          uvw2 = 1;
          vec1[1] = -0.5;
          vec1[2] = -_affineCoordinate(6, u, v, w);
          il1 = 2;
          jl1 = 1;
          vec2[0] = 0.5;
          vec2[2] = _affineCoordinate(6, u, v, w);
          il2 = 2;
          jl2 = 0;
          break;
        case(1):
          uvw1 = 0;
          uvw2 = 2;
          vec1[1] = _affineCoordinate(4, u, v, w);
          vec1[2] = 0.5;
          il1 = 1;
          jl1 = 2;
          vec2[0] = -0.5;
          vec2[1] = -_affineCoordinate(4, u, v, w);
          il2 = 1;
          jl2 = 0;
          break;
        case(2):
          uvw1 = 1;
          uvw2 = 2;
          vec1[0] = -_affineCoordinate(2, u, v, w);
          vec1[2] = -0.5;
          il1 = 0;
          jl1 = 2;
          vec2[0] = _affineCoordinate(2, u, v, w);
          vec2[1] = 0.5;
          il2 = 0;
          jl2 = 1;
          break;
        case(3):
          uvw1 = 1;
          uvw2 = 2;
          vec1[0] = -_affineCoordinate(1, u, v, w);
          vec1[2] = 0.5;
          il1 = 0;
          jl1 = 2;
          vec2[0] = _affineCoordinate(1, u, v, w);
          vec2[1] = -0.5;
          il2 = 0;
          jl2 = 1;
          break;
        case(4):
          uvw1 = 0;
          uvw2 = 2;
          vec1[1] = _affineCoordinate(3, u, v, w);
          vec1[2] = -0.5;
          il1 = 1;
          jl1 = 2;
          vec2[0] = 0.5;
          vec2[1] = -_affineCoordinate(3, u, v, w);
          il2 = 1;
          jl2 = 0;
          break;
        case(5):
          uvw1 = 0;
          uvw2 = 1;
          vec1[1] = 0.5;
          vec1[2] = -_affineCoordinate(5, u, v, w);
          il1 = 2;
          jl1 = 1;
          vec2[0] = -0.5;
          vec2[2] = _affineCoordinate(5, u, v, w);
          il2 = 2;
          jl2 = 0;
          break;
        }
        std::vector<double> lkVector1(_pOrderFace2[faceNumber]);
        std::vector<double> lkVector2(_pOrderFace1[faceNumber]);
        std::vector<double> dlkVector1(_pOrderFace2[faceNumber]);
        std::vector<double> dlkVector2(_pOrderFace1[faceNumber]);
        std::vector<double> legendreVector1(_pOrderFace1[faceNumber] + 1);
        std::vector<double> legendreVector2(_pOrderFace2[faceNumber] + 1);
        for(int it = 2; it <= _pOrderFace2[faceNumber] + 1; it++) {
          lkVector1[it - 2] = OrthogonalPoly::EvalLobatto(it, uvw[uvw2]);
          dlkVector1[it - 2] = OrthogonalPoly::EvalDLobatto(it, uvw[uvw2]);
        }
        for(int it = 2; it <= _pOrderFace1[faceNumber] + 1; it++) {
          lkVector2[it - 2] = OrthogonalPoly::EvalLobatto(it, uvw[uvw1]);
          dlkVector2[it - 2] = OrthogonalPoly::EvalDLobatto(it, uvw[uvw1]);
        }
        for(int it = 0; it <= _pOrderFace1[faceNumber]; it++) {
          legendreVector1[it] = OrthogonalPoly::EvalLegendre(it, uvw[uvw1]);
        }
        for(int it = 0; it <= _pOrderFace2[faceNumber]; it++) {
          legendreVector2[it] = OrthogonalPoly::EvalLegendre(it, uvw[uvw2]);
        }
        for(int it1 = 0; it1 < _pOrderFace2[faceNumber] + 1; it1++) {
          for(int it2 = 0; it2 < _pOrderFace1[faceNumber]; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag2 == -1 && it1 % 2 == 0) { impactFlag1 = -1; }
            if(flag1 == -1 && it2 % 2 != 0) { impactFlag2 = -1; }
            for(int j = 0; j < 3; j++) {
              if(j == jl2) {
                faceFunctions[iterator][j] = vec2[j] * lkVector2[it2] *
                                             legendreVector2[it1] *
                                             impactFlag1 * impactFlag2;
              }
              else if(j == il2) {
                faceFunctions[iterator][j] = vec2[j] * dlkVector2[it2] *
                                             legendreVector2[it1] *
                                             impactFlag1 * impactFlag2;
              }
              else {
                faceFunctions[iterator][j] = 0;
              }
            }
            iterator++;
          }
        }
        for(int it1 = 0; it1 < _pOrderFace2[faceNumber]; it1++) {
          for(int it2 = 0; it2 < _pOrderFace1[faceNumber] + 1; it2++) {
            int impactFlag1 = 1;
            int impactFlag2 = 1;
            if(flag2 == -1 && it1 % 2 != 0) { impactFlag1 = -1; }
            if(flag1 == -1 && it2 % 2 == 0) { impactFlag2 = -1; }
            for(int j = 0; j < 3; j++) {
              if(j == jl1) {
                faceFunctions[iterator][j] = vec1[j] * legendreVector1[it2] *
                                             lkVector1[it1] * impactFlag1 *
                                             impactFlag2;
              }

              else if(j == il1) {
                faceFunctions[iterator][j] = vec1[j] * legendreVector1[it2] *
                                             dlkVector1[it1] * impactFlag1 *
                                             impactFlag2;
              }
              else {
                faceFunctions[iterator][j] = 0;
              }
            }
            iterator++;
          }
        }
      }
      else {
        throw std::string("unknown typeFunction");
      }
    }
  }
}
void HierarchicalBasisHcurlBrick::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  int iterator = 0;
  for(int i = 0; i < faceNumber; i++) {
    iterator += (_pOrderFace1[i] + 1) * _pOrderFace2[i] +
                (_pOrderFace2[i] + 1) * _pOrderFace1[i];
  }
  int numFaceFunctions =
    (_pOrderFace1[faceNumber] + 1) * _pOrderFace2[faceNumber] +
    (_pOrderFace2[faceNumber] + 1) * _pOrderFace1[faceNumber];
  int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
  int offset = iOrientation * _nQuadFaceFunction;
  int offset2 = iterator + numFaceFunctions;
  for(int i = iterator; i < offset2; i++) {
    fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
    fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
    fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
  }
}

void HierarchicalBasisHcurlBrick::generateCurlBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &edgeBasis,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
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
  std::vector<std::vector<double> > curlProduct(12, std::vector<double>(3, 0));
  curlProduct[0][1] = lambda[3] * dlambda[5];
  curlProduct[0][2] = -dlambda[3] * lambda[5];
  curlProduct[5][1] = lambda[2] * dlambda[5];
  curlProduct[5][2] = -dlambda[2] * lambda[5];
  curlProduct[8][1] = lambda[3] * dlambda[4];
  curlProduct[8][2] = -dlambda[3] * lambda[4];
  curlProduct[11][1] = lambda[2] * dlambda[4];
  curlProduct[11][2] = -dlambda[2] * lambda[4];

  curlProduct[1][0] = -lambda[1] * dlambda[5];
  curlProduct[1][2] = dlambda[1] * lambda[5];
  curlProduct[3][0] = -lambda[0] * dlambda[5];
  curlProduct[3][2] = dlambda[0] * lambda[5];
  curlProduct[9][0] = -lambda[1] * dlambda[4];
  curlProduct[9][2] = dlambda[1] * lambda[4];
  curlProduct[10][0] = -lambda[0] * dlambda[4];
  curlProduct[10][2] = dlambda[0] * lambda[4];

  curlProduct[2][0] = lambda[1] * dlambda[3];
  curlProduct[2][1] = -dlambda[1] * lambda[3];
  curlProduct[4][0] = lambda[0] * dlambda[3];
  curlProduct[4][1] = -dlambda[0] * lambda[3];
  curlProduct[6][0] = lambda[0] * dlambda[2];
  curlProduct[6][1] = -dlambda[0] * lambda[2];
  curlProduct[7][0] = lambda[1] * dlambda[2];
  curlProduct[7][1] = -dlambda[1] * lambda[2];

  int indexEdgeBasis = 0;
  for(int iEdge = 0; iEdge < _nedge; iEdge++) {
    int uvw = 0;
    switch(iEdge) {
    case(0):
    case(5):
    case(8):
    case(11): uvw = 0; break;
    case(1):
    case(3):
    case(9):
    case(10): uvw = 1; break;
    case(2):
    case(4):
    case(6):;
    case(7): uvw = 2; break;
    }
    for(int indexEdgeFunc = 0; indexEdgeFunc < _pOrderEdge[iEdge] + 1;
        indexEdgeFunc++) {
      for(int j = 0; j < 3; j++) {
        edgeBasis[indexEdgeBasis][j] =
          curlProduct[iEdge][j] * legendreVector[uvw][indexEdgeFunc];
      }
      indexEdgeBasis++;
    }
  }
  // face  functions:
  int indexFaceFunction = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    std::vector<double> vec1(3, 0);
    std::vector<double> vec2(3, 0);
    int uvw1 = 0;
    int uvw2 = 0;
    int il1 = 0;
    int jl1 = 0;
    int il2 = 0;
    int jl2 = 0;
    switch(iFace) {
    case(0):
      uvw1 = 0;
      uvw2 = 1;
      vec1[1] = dlambda[5];
      vec1[2] = -lambda[5];
      il1 = 2;
      jl1 = 1;
      vec2[0] = -dlambda[5];
      vec2[2] = lambda[5];
      il2 = 2;
      jl2 = 0;
      break;
    case(1):
      uvw1 = 0;
      uvw2 = 2;
      vec1[1] = lambda[3];
      vec1[2] = -dlambda[3];
      il1 = 1;
      jl1 = 2;
      vec2[0] = dlambda[3];
      vec2[1] = -lambda[3];
      il2 = 1;
      jl2 = 0;
      break;
    case(2):
      uvw1 = 1;
      uvw2 = 2;
      vec1[0] = -lambda[1];
      vec1[2] = dlambda[1];
      il1 = 0;
      jl1 = 2;
      vec2[0] = lambda[1];
      vec2[1] = -dlambda[1];
      il2 = 0;
      jl2 = 1;
      break;
    case(3):
      uvw1 = 1;
      uvw2 = 2;
      vec1[0] = -lambda[0];
      vec1[2] = dlambda[0];
      il1 = 0;
      jl1 = 2;
      vec2[0] = lambda[0];
      vec2[1] = -dlambda[0];
      il2 = 0;
      jl2 = 1;
      break;
    case(4):
      uvw1 = 0;
      uvw2 = 2;
      vec1[1] = lambda[2];
      vec1[2] = -dlambda[2];
      il1 = 1;
      jl1 = 2;
      vec2[0] = dlambda[2];
      vec2[1] = -lambda[2];
      il2 = 1;
      jl2 = 0;
      break;
    case(5):
      uvw1 = 0;
      uvw2 = 1;
      vec1[1] = dlambda[4];
      vec1[2] = -lambda[4];
      il1 = 2;
      jl1 = 1;
      vec2[0] = -dlambda[4];
      vec2[2] = lambda[4];
      il2 = 2;
      jl2 = 0;
      break;
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace] + 1; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace]; index2++) {
        for(int j = 0; j < 3; j++) {
          if(j == jl1) {
            faceBasis[indexFaceFunction][j] = vec1[j] *
                                              legendreVector[uvw1][index1] *
                                              lobattoVector[uvw2][index2];
          }
          else if(j == il1) {
            faceBasis[indexFaceFunction][j] = vec1[j] *
                                              legendreVector[uvw1][index1] *
                                              dlobattoVector[uvw2][index2];
          }
          else {
            faceBasis[indexFaceFunction][j] = 0;
          }
        }
        indexFaceFunction++;
      }
    }
    for(int index1 = 0; index1 < _pOrderFace1[iFace]; index1++) {
      for(int index2 = 0; index2 < _pOrderFace2[iFace] + 1; index2++) {
        for(int j = 0; j < 3; j++) {
          if(j == jl2) {
            faceBasis[indexFaceFunction][j] = vec2[j] *
                                              lobattoVector[uvw1][index1] *
                                              legendreVector[uvw2][index2];
          }
          else if(j == il2) {
            faceBasis[indexFaceFunction][j] = vec2[j] *
                                              dlobattoVector[uvw1][index1] *
                                              legendreVector[uvw2][index2];
          }
          else {
            faceBasis[indexFaceFunction][j] = 0;
          }
        }
        indexFaceFunction++;
      }
    }
  }
  // bubble shape functions:
  int indexBubbleBasis = 0;
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = 0;
        bubbleBasis[indexBubbleBasis][1] = legendreVector[0][ipb1] *
                                           lobattoVector[1][ipb2] *
                                           dlobattoVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][2] = -legendreVector[0][ipb1] *
                                           dlobattoVector[1][ipb2] *
                                           lobattoVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = -lobattoVector[0][ipb1] *
                                           legendreVector[1][ipb2] *
                                           dlobattoVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][1] = 0;
        bubbleBasis[indexBubbleBasis][2] = dlobattoVector[0][ipb1] *
                                           legendreVector[1][ipb2] *
                                           lobattoVector[2][ipb3];
        indexBubbleBasis++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        bubbleBasis[indexBubbleBasis][0] = lobattoVector[0][ipb1] *
                                           dlobattoVector[1][ipb2] *
                                           legendreVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][1] = -dlobattoVector[0][ipb1] *
                                           lobattoVector[1][ipb2] *
                                           legendreVector[2][ipb3];
        bubbleBasis[indexBubbleBasis][2] = 0;

        indexBubbleBasis++;
      }
    }
  }
}

void HierarchicalBasisHcurlBrick::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{
  int it = 0;
  for(int numEdge = 0; numEdge < 12; numEdge++) {
    for(int i = 0; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    for(int index1 = 0; index1 <= _pOrderFace1[iFace]; index1++) {
      for(int index2 = 2; index2 <= _pOrderFace2[iFace] + 1; index2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(index1, index2);
        it++;
      }
    }
    for(int index1 = 2; index1 <= _pOrderFace1[iFace] + 1; index1++) {
      for(int index2 = 0; index2 <= _pOrderFace2[iFace]; index2++) {
        functionTypeInfo[it] = 2;
        orderInfo[it] = std::max(index1, index2);
        it++;
      }
    }
  }
  for(int ipb1 = 0; ipb1 < _pb1 + 1; ipb1++) {
    for(int ipb2 = 2; ipb2 <= _pb2 + 1; ipb2++) {
      for(int ipb3 = 2; ipb3 <= _pb3 + 1; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
  for(int ipb1 = 2; ipb1 <= _pb1 + 1; ipb1++) {
    for(int ipb2 = 0; ipb2 < _pb2 + 1; ipb2++) {
      for(int ipb3 = 2; ipb3 <= _pb3 + 1; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
  for(int ipb1 = 2; ipb1 <= _pb1 + 1; ipb1++) {
    for(int ipb2 = 2; ipb2 <= _pb2 + 1; ipb2++) {
      for(int ipb3 = 0; ipb3 < _pb3 + 1; ipb3++) {
        functionTypeInfo[it] = 3;
        orderInfo[it] = std::max(std::max(ipb1, ipb2), ipb3);
        it++;
      }
    }
  }
}
