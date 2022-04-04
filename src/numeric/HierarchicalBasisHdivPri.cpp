// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Reference :  "Higher-Order Finite Element  Methods"; Pavel Solin, Karel
// Segeth ,
//                 Ivo Dolezel , Chapman and Hall/CRC; Edition : Har/Cdr (2003).
#include "HierarchicalBasisHdivPri.h"

HierarchicalBasisHdivPri::HierarchicalBasisHdivPri(int order)
{
  _nvertex = 6;
  _nedge = 9;
  _nfaceTri = 2;
  _nfaceQuad = 3;
  _nVertexFunction = 0;
  _nEdgeFunction = 0;
  _nQuadFaceFunction = 3 * (order + 1) * (order + 1);
  _nTriFaceFunction = (order + 1) * (order + 2);
  _nBubbleFunction = (order * (order + 1) * order) / 2;
  if(order >= 2) {
    _nBubbleFunction += (3 * (order - 1) + (order - 1) * (order - 2)) * (order + 1);
  }
  _pb1 = order;
  _pb2 = order;
  for(int i = 0; i < 3; i++) {
    _pOrderQuadFace1[i] = order;
    _pOrderQuadFace2[i] = order;
  }
  for(int i = 0; i < 2; i++) { _pOrderTriFace[i] = order; }
}

HierarchicalBasisHdivPri::~HierarchicalBasisHdivPri() {}

unsigned int HierarchicalBasisHdivPri::getNumberOfOrientations() const
{
  return 720; // factorial 6
}

double HierarchicalBasisHdivPri::_affineCoordinate(const int &j,
                                                      const double &u,
                                                      const double &v,
                                                      const double &w)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (u + v);
  case(3): return 0.5 * (1 + u);
  case(4): return 0.5 * (1 + w);
  case(5): return 0.5 * (1 - w);
  default: throw std::string("j must be : 1<=j<=5");
  }
}

static double dotProduct(const std::vector<double> &u1,
                                const std::vector<double> &u2) // in 2D
{
  return u1[0] * u2[0] + u1[1] * u2[1];
}

static void matrixVectorProductForMapping(
  const double &a, const std::vector<double> &u, std::vector<double> &result)
{
  result[0] = a * 2 * u[0];
  result[1] = a * 2 * u[1];
  result[2] = a * u[2];
}

void HierarchicalBasisHdivPri::generateHdivBasis(
  double const &u, double const &v, double const &w,
  std::vector<std::vector<double> > &faceBasis,
  std::vector<std::vector<double> > &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double wc = w;
  //*****
  // compute all needed terms
  double lambda1 = _affineCoordinate(1, uc, vc, wc);
  double lambda2 = _affineCoordinate(2, uc, vc, wc);
  double lambda3 = _affineCoordinate(3, uc, vc, wc);
  double lambda4 = _affineCoordinate(4, uc, vc, wc);
  double lambda5 = _affineCoordinate(5, uc, vc, wc);
  std::vector<double> t1 = std::vector<double>(3, 0);
  t1[0] = 1;
  std::vector<double> t2 = std::vector<double>(3, 0);
  t2[0] = -1;
  t2[1] = 1;
  std::vector<double> t3 = std::vector<double>(3, 0);
  t3[1] = 1;
  std::vector<double> n1 = std::vector<double>(3, 0);
  n1[1] = 1;
  std::vector<double> n2 = std::vector<double>(3, 0);
  n2[0] = -sqrt(0.5);
  n2[1] = -sqrt(0.5);
  std::vector<double> n3 = std::vector<double>(3, 0);
  n3[0] = 1;
  // Whitney functions
  std::vector<std::vector<double> > gammae_0(3, std::vector<double>(3, 0));
  std::vector<std::vector<double> > gammae_1(3, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    gammae_0[0][i] = lambda3 * t2[i] / dotProduct(t2, n1) +
                     lambda2 * t3[i] / dotProduct(t3, n1);
    gammae_0[1][i] = lambda1 * t3[i] / dotProduct(t3, n2) +
                     lambda3 * t1[i] / dotProduct(t1, n2);
    gammae_0[2][i] = lambda2 * t1[i] / dotProduct(t1, n3) +
                     lambda1 * t2[i] / dotProduct(t2, n3);

    gammae_1[0][i] = lambda3 * t2[i] / dotProduct(t2, n1) -
                     lambda2 * t3[i] / dotProduct(t3, n1);
    gammae_1[1][i] = lambda1 * t3[i] / dotProduct(t3, n2) -
                     lambda3 * t1[i] / dotProduct(t1, n2);
    gammae_1[2][i] = -lambda2 * t1[i] / dotProduct(t1, n3) +
                     lambda1 * t2[i] / dotProduct(t2, n3); // edge oriented: {0;2}
  }
  double subl3l2 = lambda3 - lambda2;
  double subl1l3 = lambda1 - lambda3;
  double subl1l2 = lambda1 - lambda2;
  double subl2l1 = lambda2 - lambda1;
  std::vector<double> sub(4, 0);
  sub[0] = subl3l2, sub[1] = subl1l3, sub[2] = subl1l2, sub[3] = subl2l1;
  std::vector<std::vector<double> > legendreVector(4);
  unsigned int maxQuadFace1Order = std::max( std::max(_pOrderQuadFace1[0], std::max(_pOrderQuadFace1[1], _pOrderQuadFace1[2]) ), 1 );
  legendreVector[0] = std::vector<double>(maxQuadFace1Order - 1, 0);
  legendreVector[1] = std::vector<double>(maxQuadFace1Order - 1, 0);
  legendreVector[2] = std::vector<double>(maxQuadFace1Order - 1, 0);
  legendreVector[3] = std::vector<double>(maxQuadFace1Order - 1, 0);
  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, subl3l2);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, subl1l3);
  }
  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, subl1l2);
  }
  for(unsigned int k = 0; k < legendreVector[3].size(); k++) {
    legendreVector[3][k] = OrthogonalPoly::EvalLegendre(k, subl2l1);
  }

  std::vector<double> legendreW(
    std::max(std::max(std::max(_pOrderQuadFace2[0] + 1,
                               _pOrderQuadFace2[1] + 1),
                      _pOrderQuadFace2[2] + 1),
             _pb2 + 1),
    0);
  std::vector<double> lobattoW(2, 0);
  for(unsigned int k = 0; k < legendreW.size(); k++) {
    legendreW[k] = OrthogonalPoly::EvalLegendre(k, wc);
  }
  for(unsigned int k = 0; k < lobattoW.size(); k++) {
    lobattoW[k] = OrthogonalPoly::EvalLobatto(k, wc);
  }
  // quad face
  int faceIt = 0;
  for(int iFace = 0; iFace < _nfaceQuad; iFace++) {
    int index = 0;
    switch(iFace) {
    case(0):
      index = 0;
      break;
    case(1):
      index = 2;
      break;
    case(2):
      index = 1;
      break;
    }
    for(int n1 = 0; n1 <= _pOrderQuadFace1[iFace]; n1++) {
      std::vector<double> faceGamma(3, 0);
      if(n1 == 0) {
        faceGamma[0] = gammae_0[index][0];
        faceGamma[1] = gammae_0[index][1];
        faceGamma[2] = gammae_0[index][2];
      }
      else if(n1 == 1) {
        faceGamma[0] = gammae_1[index][0];
        faceGamma[1] = gammae_1[index][1];
        faceGamma[2] = gammae_1[index][2];
      }
      else {
        for(int j = 0; j < 3; j++) {
          faceGamma[j] = (2 * float(n1) - 1) / float(n1) *
                           legendreVector[index][n1 - 1] * gammae_1[index][j] -
                         (float(n1) - 1) / float(n1) *
                           legendreVector[index][n1 - 2] * gammae_0[index][j];
        }
      }
      
      for(int n2 = 0; n2 <= _pOrderQuadFace2[iFace]; n2++) {
        matrixVectorProductForMapping(legendreW[n2], faceGamma, faceBasis[faceIt]);
        faceIt++;
      }
    }
  }
  // tri face
  for(int iFace = 0; iFace < _nfaceTri; iFace++) {
    double lambda = 0;
    if(iFace == 0) {
      lambda = lambda5;
    }
    else {
      lambda = lambda4;
    }
    if(_pOrderTriFace[iFace] >= 0) {
      faceBasis[faceIt][0] = 0.;
      faceBasis[faceIt][1] = 0.;
      faceBasis[faceIt][2] = 1.;
      matrixVectorProductForMapping(lambda, faceBasis[faceIt], faceBasis[faceIt]);
      faceIt++;
    }
    if(_pOrderTriFace[iFace] >= 1) {
      faceBasis[faceIt][0] = 0.;
      faceBasis[faceIt][1] = 0.;
      faceBasis[faceIt][2] = 1.;
      matrixVectorProductForMapping(lambda * (lambda3 - lambda2), faceBasis[faceIt], faceBasis[faceIt]);
      faceIt++;
      
      faceBasis[faceIt][0] = 0.;
      faceBasis[faceIt][1] = 0.;
      faceBasis[faceIt][2] = 1.;
      matrixVectorProductForMapping(lambda * (lambda2 - lambda1), faceBasis[faceIt], faceBasis[faceIt]);
      faceIt++;
    }
    if(_pOrderTriFace[iFace] >= 2) {
      for(int i = 0; i < 3; i++) {
        double prod = 0;
        int index = 0;
        switch(i) {
        case 0:
          prod = lambda2 * lambda3;
          index = 0;
          break;
        case 1:
          prod = lambda1 * lambda3;
          index = 1;
          break;
        case 2:
          prod = lambda1 * lambda2;
          index = 3;
          break;
        }
        for(int k = 2; k <= _pOrderTriFace[iFace]; ++k) {
          faceBasis[faceIt][0] = 0.;
          faceBasis[faceIt][1] = 0.;
          faceBasis[faceIt][2] = prod * OrthogonalPoly::EvalKernelFunction(k - 2, sub[index]);
          matrixVectorProductForMapping(lambda, faceBasis[faceIt], faceBasis[faceIt]);
          faceIt++;
        }
      }
    }
  }
  int bubbleIt = 0;
  // horizontal bubble
  if(_pb1 >= 2) {
    // based on interior edge BFs of K_div^tri
    std::vector< std::vector< double > > triEgdeBF(3, std::vector< double >(3, 0.));
    for(int n1 = 0; n1 < _pb1 - 2; n1++) {
      for(int iEdge = 0; iEdge < 3; ++iEdge) {
        double prod = 0.;
        int index = 0;
        double t0 = 0., t1 = 0.;
        switch(iEdge) {
        case 0:
          prod = lambda2 * lambda3;
          index = 0;
          t0 = 1.;
          t1 = 0.;
          break;
        case 1:
          {
            prod = lambda1 * lambda3;
            index = 1;
            const double invSqrt2 = sqrt(0.5);
            t0 = - invSqrt2;
            t1 = invSqrt2;
          }
          break;
        case 2:
          prod = lambda1 * lambda2;
          index = 3;
          t0 = 0.;
          t1 = 1.;
          break;
        }
        triEgdeBF[iEdge][0] = t0 * prod * legendreVector[index][n1];
        triEgdeBF[iEdge][1] = t1 * prod * legendreVector[index][n1];
      }
    }
    for(int n1 = 0; n1 < _pb1 - 2; n1++) {
      for(int n3 = 0; n3 <= _pb2; n3++) {
        for(int iEdge = 0; iEdge < 3; ++iEdge) {
          matrixVectorProductForMapping(legendreW[n3], triEgdeBF[iEdge], faceBasis[faceIt]);
        }
        bubbleIt++;
      }
    }
    // based on genuine bubble BFs of K_div^tri
    double product = lambda1 * lambda2 * lambda3;
    for(int n1 = 0; n1 < _pb1 - 2; n1++) {
      for(int n2 = 0; n2 < _pb1 - 2 - n1; n2++) {
        std::vector<double> term(3, 0);
        term[0] = product * legendreVector[0][n1] * legendreVector[3][n2];
        for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
          matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
          bubbleIt++;
        }
        term[0] = 0.;
        term[1] = product * legendreVector[0][n1] * legendreVector[3][n2];
        for(int n3 = 2; n3 <= _pb2 + 1; n3++) {
          matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
          bubbleIt++;
        }
      }
    }
  }
  // vertical bubble
  if(_pb2 >= 1) {
    std::vector<double> term(3, 0);
    // lowest-order
    if(_pb1 >= 1) {
      term[0] = 1. * lobattoW[0] * lobattoW[1];
      for(int n3 = 0; n3 < _pb2 - 2; ++n3) {
        matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
    // linear
    if(_pb1 >= 2) {
      term[0] = lambda3 * lobattoW[0] * lobattoW[1];
      for(int n3 = 0; n3 < _pb2 - 2; ++n3) {
        matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
      term[0] = lambda1 * lobattoW[0] * lobattoW[1];
      for(int n3 = 0; n3 < _pb2 - 2; ++n3) {
        matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
        bubbleIt++;
      }
    }
    // high-order edge
    if(_pb1 >= 3) {
      for(int iEdge = 0; iEdge < 3; iEdge++) {
        double prod = 0.;
        int subIndex = 0;
        std::vector< double > triEgdeBF(_pb1 - 2, 0.);
        switch(iEdge) {
        case 0:
          prod = lambda2 * lambda3;
          subIndex = 0;
          break;
        case 1:
          prod = lambda1 * lambda3;
          subIndex = 1;
          break;
        case 2:
          prod = lambda1 * lambda2;
          subIndex = 3;
          break;
        }
        for(int k = 0; k <= _pb1 - 3; k++) {
          triEgdeBF[k] = prod * OrthogonalPoly::EvalKernelFunction(k, sub[subIndex]);
        }
        for(int k = 0; k <= _pb1 - 3; k++) {
          term[0] = triEgdeBF[k] * lobattoW[0] * lobattoW[1];
          for(int n3 = 0; n3 < _pb2 - 2; ++n3) {
            matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
            bubbleIt++;
          }
        }
      }
    }
    // high-order bubble
    if(_pb1 >= 4) {
      for(int n1 = 0; n1 < _pb1 - 4; n1++) {
        const double prod = lambda1 * lambda2 * lambda3 * OrthogonalPoly::EvalKernelFunction(n1, subl3l2);
        for(int n2 = 0; n2 < _pb1 - 4 - n1; n2++) {
          term[0] = prod * OrthogonalPoly::EvalKernelFunction(n2, subl2l1);
          for(int n3 = 0; n3 <= _pb2 - 2; n2++) {
            matrixVectorProductForMapping(lobattoW[n3], term, bubbleBasis[bubbleIt]);
            bubbleIt++;
          }
        }
      }
    }
  }
}

void HierarchicalBasisHdivPri::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector< double > &faceFunctions)
{
}

void HierarchicalBasisHdivPri::orientOneFace(
  double const &u, double const &v, double const &w, int const &flag1,
  int const &flag2, int const &flag3, int const &faceNumber,
  std::vector<std::vector<double> > &faceFunctions, std::string typeFunction)
{
  if(faceNumber < 3) {
    if(!(flag1 == 1 && flag2 == 1 && flag3 == 1)) {
      int iterator = 0;
      for(int k = 0; k < faceNumber; k++) {
        iterator = iterator +
          (_pOrderQuadFace1[k] + 1) * (_pOrderQuadFace2[k] + 1);
      }
      if(flag3 == 1) {
        for(int it1 = 0; it1 <= _pOrderQuadFace1[faceNumber] + 1; it1++) {
          for(int it2 = 2; it2 <= _pOrderQuadFace2[faceNumber] + 1; it2++) {
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
        for(int it1 = 2; it1 <= _pOrderQuadFace1[faceNumber] + 1; it1++) {
          for(int it2 = 0; it2 <= _pOrderQuadFace2[faceNumber] + 1; it2++) {
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
      }
    }
  }
  else {
  
  }
}

void HierarchicalBasisHdivPri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector< double > &quadFaceFunctionsAllOrientation,
  const std::vector< double > &triFaceFunctionsAllOrientation,
  std::vector< double > &fTableCopy)
{
  if(faceNumber < 3) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderQuadFace1[i] + 1) * (_pOrderQuadFace2[i] + 1);
    }
    int numFaceFunctions =
      (_pOrderQuadFace1[faceNumber] + 1) * (_pOrderQuadFace2[faceNumber] + 1);
    int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
    int offset = iOrientation * _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i] = quadFaceFunctionsAllOrientation[i + offset];
    }
  }
  else {
    int iterator = _nQuadFaceFunction;
    int numface = faceNumber - 3;
    for(int i = 0; i < numface; i++) {
      iterator += (_pOrderTriFace[i] + 1) * (_pOrderTriFace[i] + 2) / 2;
    }
    int numFaceFunctions =
      (_pOrderTriFace[numface] + 1) * (_pOrderTriFace[numface] + 2) / 2;
    int iOrientation = numberOrientationTriFace(flag1, flag2);
    int offset = iOrientation * _nTriFaceFunction - _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i] = triFaceFunctionsAllOrientation[i + offset];
    }
  }
}

void HierarchicalBasisHdivPri::orientFace(
  int const &flag1, int const &flag2, int const &flag3, int const &faceNumber,
  const std::vector<std::vector<double> > &quadFaceFunctionsAllOrientation,
  const std::vector<std::vector<double> > &triFaceFunctionsAllOrientation,
  std::vector<std::vector<double> > &fTableCopy)
{
  if(faceNumber < 3) {
    int iterator = 0;
    for(int i = 0; i < faceNumber; i++) {
      iterator += (_pOrderQuadFace1[i] + 1) * (_pOrderQuadFace2[i] + 1);
    }
    int numFaceFunctions =
      (_pOrderQuadFace1[faceNumber] + 1) * (_pOrderQuadFace2[faceNumber] + 1);
    int iOrientation = numberOrientationQuadFace(flag1, flag2, flag3);
    int offset = iOrientation * _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i][0] = quadFaceFunctionsAllOrientation[i + offset][0];
      fTableCopy[i][1] = quadFaceFunctionsAllOrientation[i + offset][1];
      fTableCopy[i][2] = quadFaceFunctionsAllOrientation[i + offset][2];
    }
  }
  else {
    int iterator = _nQuadFaceFunction;
    int numface = faceNumber - 3;
    for(int i = 0; i < numface; i++) {
      iterator += (_pOrderTriFace[i] + 1) * (_pOrderTriFace[i] + 2) / 2;
    }
    int numFaceFunctions =
      (_pOrderTriFace[numface] + 1) * (_pOrderTriFace[numface] + 2) / 2;
    int iOrientation = numberOrientationTriFace(flag1, flag2);
    int offset = iOrientation * _nTriFaceFunction - _nQuadFaceFunction;
    int offset2 = iterator + numFaceFunctions;
    for(int i = iterator; i < offset2; i++) {
      fTableCopy[i][0] = triFaceFunctionsAllOrientation[i + offset][0];
      fTableCopy[i][1] = triFaceFunctionsAllOrientation[i + offset][1];
      fTableCopy[i][2] = triFaceFunctionsAllOrientation[i + offset][2];
    }
  }
}

void HierarchicalBasisHdivPri::generateDivBasis(
  double const &u, double const &v, double const &w,
  std::vector< double > &faceBasis,
  std::vector< double > &bubbleBasis)
{

}

void HierarchicalBasisHdivPri::getKeysInfo(
  std::vector<int> &functionTypeInfo, std::vector<int> &orderInfo)
{

}
