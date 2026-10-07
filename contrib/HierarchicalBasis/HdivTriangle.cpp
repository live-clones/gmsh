// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Nawfel BENATIA (2025), based on Ismail Badia's contribution
// (2019).
//
// Reference : Solin, P., Segeth, K., & Dolezel, I. (2003).
//             Higher-Order Finite Element Methods (1st ed.).
//             Chapman and Hall/CRC. https://doi.org/10.1201/9780203488041

#include <iostream>
#include "HdivTriangle.h"

HdivTriangle::HdivTriangle(int order)
{
  _pf = order;
  _pOrderEdge = {order, order, order};
  _numVertex = 3;
  _numEdge = 3;
  _numTriFace = 1;
  _numQuadFace = 0;
  _numVertexFunction = 0;
  _numEdgeFunction = 3 * order + 3;
  _numQuadFaceFunction = 0;
  _numTriFaceFunction =
    ((order == 0) ? 0 : 3 * (order - 1) + (order - 1) * (order - 2));
  _numBubbleFunction = 0;
}

double HdivTriangle::dotProduct(const std::vector<double> &u,
                                const std::vector<double> &v)
{ return u[0] * v[0] + u[1] * v[1]; }

double HdivTriangle::_affineCoordinate(int j, double u, double v)
{
  switch(j) {
  case(1): return 0.5 * (1 + v);
  case(2): return -0.5 * (u + v);
  case(3): return 0.5 * (1 + u);
  default: return 0.; // not reached
  }
}

void HdivTriangle::generateHdivBasis(
  double u, double v, double w, std::vector<std::vector<double>> &edgeBasis,
  std::vector<std::vector<double>> &faceBasis,
  std::vector<std::vector<double>> &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double jacob = 2;
  //*****
  double lambda1 = _affineCoordinate(1, uc, vc);
  double lambda2 = _affineCoordinate(2, uc, vc);
  double lambda3 = _affineCoordinate(3, uc, vc);

  const std::vector<double> t1{1.0, 0.0, 0.0};
  const std::vector<double> t2{-1.0, 1.0, 0.0}; //!!!!!
  const std::vector<double> t3{0.0, -1.0, 0.0};

  const std::vector<double> n1{0.0, 1.0, 0.0};
  // normal of the same length as the edge, for the normal component to be
  // continuous across elements once mapped with the contravariant Piola map
  const std::vector<double> n2{-1.0, -1.0, 0.0};
  const std::vector<double> n3{1.0, 0.0, 0.0};

  // Whitney functions
  std::vector<std::vector<double>> gamma_0(3, std::vector<double>(3, 0));
  std::vector<std::vector<double>> gamma_1(3, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    gamma_0[0][i] = lambda3 * t2[i] / dotProduct(t2, n1) +
                    lambda2 * t3[i] / dotProduct(t3, n1);
    gamma_0[1][i] = lambda1 * t3[i] / dotProduct(t3, n2) +
                    lambda3 * t1[i] / dotProduct(t1, n2);
    gamma_0[2][i] = lambda2 * t1[i] / dotProduct(t1, n3) +
                    lambda1 * t2[i] / dotProduct(t2, n3);

    gamma_1[0][i] = lambda3 * t2[i] / dotProduct(t2, n1) -
                    lambda2 * t3[i] / dotProduct(t3, n1);
    gamma_1[1][i] = lambda1 * t3[i] / dotProduct(t3, n2) -
                    lambda3 * t1[i] / dotProduct(t1, n2);
    gamma_1[2][i] = lambda2 * t1[i] / dotProduct(t1, n3) -
                    lambda1 * t2[i] / dotProduct(t2, n3);
  }

  double subl3l2 = lambda3 - lambda2;
  double subl1l3 = lambda1 - lambda3;
  double subl2l1 = lambda2 - lambda1;
  std::vector<std::vector<double>> legendreVector(3);

  legendreVector[0] =
    std::vector<double>(std::max(std::max(_pOrderEdge[0], _pf - 1), 0));
  legendreVector[1] =
    std::vector<double>(std::max(std::max(_pOrderEdge[1], _pf - 1), 0));
  legendreVector[2] =
    std::vector<double>(std::max(std::max(_pOrderEdge[2], _pf - 1), 0));

  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, subl3l2);
  }

  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, subl1l3);
  }

  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, subl2l1);
  }

  int edgeIt = 0;
  int faceIt = 0;
  for(int i = 0; i < _numEdge; i++) {
    for(int j = 0; j < 3; j++) { edgeBasis[edgeIt][j] = jacob * gamma_0[i][j]; }
    edgeIt++;
    if(_pOrderEdge[i] >= 1) {
      for(int j = 0; j < 3; j++) {
        edgeBasis[edgeIt][j] = jacob * gamma_1[i][j];
      }
      edgeIt++;

      for(int iedge = 2; iedge <= _pOrderEdge[i]; iedge++) {
        for(int j = 0; j < 3; j++) {
          edgeBasis[edgeIt][j] =
            jacob * ((2 * double(iedge) - 1) / double(iedge) *
                       legendreVector[i][iedge - 1] * gamma_1[i][j] -
                     (double(iedge) - 1) / double(iedge) *
                       legendreVector[i][iedge - 2] * gamma_0[i][j]);
        }
        edgeIt++;
      }
    }
    double product = 0;
    std::vector<double> tD(3, 0); //!!!!!!!!!!!!!
    switch(i) {
    case(0):
      product = lambda3 * lambda2;
      tD[0] = 0.5;
      break;
    case(1):
      product = lambda1 * lambda3;
      tD[0] = -0.5;
      tD[1] = 0.5;
      break;
    case(2):
      product = lambda1 * lambda2;
      tD[1] = -0.5;
      break;
    }
    for(int i1 = 2; i1 <= _pf; i1++) {
      for(int j = 0; j < 3; j++) {
        faceBasis[faceIt][j] =
          jacob * product * legendreVector[i][i1 - 2] * tD[j];
      }
      faceIt++;
    }
  }
  double product = lambda1 * lambda2 * lambda3;
  int faceIt2 = faceIt;
  for(int n1 = 0; n1 < _pf - 2; n1++) {
    for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
      faceBasis[faceIt][0] =
        0.5 * jacob * (product * legendreVector[0][n1] * legendreVector[2][n2]);
      faceBasis[faceIt][1] = 0;
      faceBasis[faceIt][2] = 0;
      faceIt++;
    }
  }
  for(int n1 = 0; n1 < _pf - 2; n1++) {
    for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
      faceBasis[faceIt][0] = 0;
      faceBasis[faceIt][1] = faceBasis[faceIt2][0];
      faceBasis[faceIt][2] = 0;
      faceIt++;
      faceIt2++;
    }
  }
}

void HdivTriangle::generateDivBasis(double u, double v, double w,
                                    std::vector<double> &edgeBasis,
                                    std::vector<double> &faceBasis,
                                    std::vector<double> &bubbleBasis)
{
  //***
  // to map onto the reference domain of gmsh:
  double uc = 2 * u - 1;
  double vc = 2 * v - 1;
  double det = 4;
  //*****
  double lambda1 = _affineCoordinate(1, uc, vc);
  double lambda2 = _affineCoordinate(2, uc, vc);
  double lambda3 = _affineCoordinate(3, uc, vc);

  const std::vector<double> t1{1.0, 0.0, 0.0};
  const std::vector<double> t2{-1.0, 1.0, 0.0};
  const std::vector<double> t3{0.0, -1.0, 0.0};

  const std::vector<double> n1{0.0, 1.0, 0.0};
  // normal of the same length as the edge, for the normal component to be
  // continuous across elements once mapped with the contravariant Piola map
  const std::vector<double> n2{-1.0, -1.0, 0.0};
  const std::vector<double> n3{1.0, 0.0, 0.0};

  // Whitney functions
  std::vector<std::vector<double>> gamma_0(3, std::vector<double>(3, 0));
  std::vector<std::vector<double>> gamma_1(3, std::vector<double>(3, 0));
  for(int i = 0; i < 3; i++) {
    gamma_0[0][i] = lambda3 * t2[i] / dotProduct(t2, n1) +
                    lambda2 * t3[i] / dotProduct(t3, n1);
    gamma_0[1][i] = lambda1 * t3[i] / dotProduct(t3, n2) +
                    lambda3 * t1[i] / dotProduct(t1, n2);
    gamma_0[2][i] = lambda2 * t1[i] / dotProduct(t1, n3) +
                    lambda1 * t2[i] / dotProduct(t2, n3);

    gamma_1[0][i] = lambda3 * t2[i] / dotProduct(t2, n1) -
                    lambda2 * t3[i] / dotProduct(t3, n1);
    gamma_1[1][i] = lambda1 * t3[i] / dotProduct(t3, n2) -
                    lambda3 * t1[i] / dotProduct(t1, n2);
    gamma_1[2][i] = lambda2 * t1[i] / dotProduct(t1, n3) -
                    lambda1 * t2[i] / dotProduct(t2, n3);
  }
  std::vector<double> divgamma_0(3);
  std::vector<double> divgamma_1(3);
  divgamma_0[0] = -1;
  divgamma_0[1] = -1;
  divgamma_0[2] = -1;
  divgamma_1[0] = 0;
  divgamma_1[1] = 0;
  divgamma_1[2] = 0;
  std::vector<double> subtraction(3, 0);
  subtraction[0] = lambda3 - lambda2;
  subtraction[1] = lambda1 - lambda3;
  subtraction[2] = lambda2 - lambda1;

  std::vector<std::vector<double>> dsubtraction(3, std::vector<double>(2, 0));
  dsubtraction[0][0] = 1;
  dsubtraction[0][1] = 0.5;
  dsubtraction[1][0] = -0.5;
  dsubtraction[1][1] = 0.5;
  dsubtraction[2][0] = -0.5;
  dsubtraction[2][1] = -1;

  std::vector<std::vector<double>> legendreVector(3);
  legendreVector[0] =
    std::vector<double>(std::max(std::max(_pOrderEdge[0], _pf - 1), 0));
  legendreVector[1] =
    std::vector<double>(std::max(std::max(_pOrderEdge[1], _pf - 1), 0));
  legendreVector[2] =
    std::vector<double>(std::max(std::max(_pOrderEdge[2], _pf - 1), 0));

  std::vector<std::vector<double>> dlegendreVector(3);
  dlegendreVector[0] =
    std::vector<double>(std::max(std::max(_pOrderEdge[0], _pf - 1), 0));
  dlegendreVector[1] =
    std::vector<double>(std::max(std::max(_pOrderEdge[1], _pf - 1), 0));
  dlegendreVector[2] =
    std::vector<double>(std::max(std::max(_pOrderEdge[2], _pf - 1), 0));

  for(unsigned int k = 0; k < legendreVector[0].size(); k++) {
    legendreVector[0][k] = OrthogonalPoly::EvalLegendre(k, subtraction[0]);
    dlegendreVector[0][k] = OrthogonalPoly::EvalDLegendre(k, subtraction[0]);
  }
  for(unsigned int k = 0; k < legendreVector[1].size(); k++) {
    legendreVector[1][k] = OrthogonalPoly::EvalLegendre(k, subtraction[1]);
    dlegendreVector[1][k] = OrthogonalPoly::EvalDLegendre(k, subtraction[1]);
  }
  for(unsigned int k = 0; k < legendreVector[2].size(); k++) {
    legendreVector[2][k] = OrthogonalPoly::EvalLegendre(k, subtraction[2]);
    dlegendreVector[2][k] = OrthogonalPoly::EvalDLegendre(k, subtraction[2]);
  }
  int edgeIt = 0;

  for(int i = 0; i < _numEdge; i++) {
    edgeBasis[edgeIt] = det * divgamma_0[i];
    edgeIt++;
    if(_pOrderEdge[i] >= 1) {
      edgeBasis[edgeIt] = det * divgamma_1[i];
      edgeIt++;
      for(int iedge = 2; iedge <= _pOrderEdge[i]; iedge++) {
        edgeBasis[edgeIt] =
          det * ((2 * double(iedge) - 1) / double(iedge) *
                   (dsubtraction[i][0] * dlegendreVector[i][iedge - 1] *
                      gamma_1[i][0] +
                    dsubtraction[i][1] * dlegendreVector[i][iedge - 1] *
                      gamma_1[i][1]) -
                 (double(iedge) - 1) / double(iedge) *
                   (dsubtraction[i][0] * dlegendreVector[i][iedge - 2] *
                      gamma_0[i][0] +
                    dsubtraction[i][1] * dlegendreVector[i][iedge - 2] *
                      gamma_0[i][1] +
                    divgamma_0[i] * legendreVector[i][iedge - 2]));
        edgeIt++;
      }
    }
  }
  int faceIt = 0;
  double dlambda23 = 0.5 * (lambda2 - lambda3);
  double prod32 = lambda3 * lambda2;
  for(int n1 = 2; n1 <= _pf; n1++) {
    faceBasis[faceIt] =
      0.5 * det *
      (dlambda23 * legendreVector[0][n1 - 2] +
       prod32 * dsubtraction[0][0] * dlegendreVector[0][n1 - 2]);

    faceIt++;
  }
  double dlambda13U = 0.5 * (lambda1);
  double dlambda13V = 0.5 * (lambda3);
  double prod13 = lambda3 * lambda1;
  for(int n1 = 2; n1 <= _pf; n1++) {
    faceBasis[faceIt] =
      -0.5 * det *
      (dlambda13U * legendreVector[1][n1 - 2] +
       prod13 * dsubtraction[1][0] * dlegendreVector[1][n1 - 2] -
       (dlambda13V * legendreVector[1][n1 - 2] +
        prod13 * dsubtraction[1][1] * dlegendreVector[1][n1 - 2]));
    faceIt++;
  }
  double dlambda12 = 0.5 * (lambda2 - lambda1);
  double prod12 = lambda2 * lambda1;
  for(int n1 = 2; n1 <= _pf; n1++) {
    faceBasis[faceIt] =
      -0.5 * det *
      (dlambda12 * legendreVector[2][n1 - 2] +
       prod12 * dsubtraction[2][1] * dlegendreVector[2][n1 - 2]);
    faceIt++;
  }
  double prod123 = lambda1 * lambda2 * lambda3;
  double dlambda123U = 0.5 * lambda1 * (lambda2 - lambda3);
  double dlambda123V = 0.5 * lambda3 * (lambda2 - lambda1);
  for(int n1 = 0; n1 < _pf - 2; n1++) {
    for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
      faceBasis[faceIt] =
        0.5 * det *
        (dlambda123U * legendreVector[0][n1] * legendreVector[2][n2] +
         prod123 * dsubtraction[0][0] * dlegendreVector[0][n1] *
           legendreVector[2][n2] +
         prod123 * dsubtraction[2][0] * legendreVector[0][n1] *
           dlegendreVector[2][n2]);

      faceIt++;
    }
  }
  for(int n1 = 0; n1 < _pf - 2; n1++) {
    for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
      faceBasis[faceIt] =
        0.5 * det *
        (dlambda123V * legendreVector[0][n1] * legendreVector[2][n2] +
         prod123 * dsubtraction[0][1] * dlegendreVector[0][n1] *
           legendreVector[2][n2] +
         prod123 * dsubtraction[2][1] * legendreVector[0][n1] *
           dlegendreVector[2][n2]);
      faceIt++;
    }
  }
}

void HdivTriangle::orientOneFace(
  double u, double v, double w, int flag1, int flag2, int flag3, int faceNumber,
  std::vector<std::vector<double>> &faceFunctions)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    if(_space == HDIV) {
      // to map onto the reference domain of gmsh:
      double uc = 2 * u - 1;
      double vc = 2 * v - 1;
      double jacob = 2;
      //*****

      int faceIt = 0;
      std::vector<double> lambda(3, 0);
      lambda[0] = _affineCoordinate(2, uc, vc);
      lambda[1] = _affineCoordinate(3, uc, vc);
      lambda[2] = _affineCoordinate(1, uc, vc);
      std::vector<std::vector<double>> dlambda(3, std::vector<double>(2, 0));
      dlambda[0][0] = -0.5;
      dlambda[0][1] = -0.5;
      dlambda[1][0] = 0.5;
      dlambda[2][1] = 0.5;
      double product = lambda[0] * lambda[1] * lambda[2];
      if(flag1 == 1 && flag2 == -1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 0 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 2 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[0];
        lambda[0] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[0];
        dlambda[0] = dcopy;
      }
      else if(flag1 == 1 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = lambda[2];
        lambda[2] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dlambda[2];
        dlambda[2] = dcopy;
      }
      else if(flag1 == 2 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      std::vector<double> sub(3);
      sub[0] = lambda[1] - lambda[0];
      sub[1] = lambda[2] - lambda[1];
      sub[2] = lambda[0] - lambda[2];
      std::vector<double> t1 = std::vector<double>(2, 0);
      t1[0] = dlambda[2][1];
      t1[1] = -dlambda[2][0];
      std::vector<double> t2 = std::vector<double>(2, 0);
      t2[0] = dlambda[0][1];
      t2[1] = -dlambda[0][0];
      std::vector<double> t3 = std::vector<double>(2, 0);
      t3[0] = dlambda[1][1];
      t3[1] = -dlambda[1][0];
      // edge-based face functions
      for(int i = 0; i < 3; i++) {
        double product2 = 0;
        std::vector<double> *tangent(nullptr);
        switch(i) {
        case(0):
          product2 = lambda[1] * lambda[0];
          tangent = &t1;
          break;
        case(1):
          product2 = lambda[1] * lambda[2];
          tangent = &t2;
          break;
        case(2):
          product2 = lambda[2] * lambda[0];
          tangent = &t3;
          break;
        }
        for(int i1 = 2; i1 <= _pf; i1++) {
          for(int j = 0; j < 2; j++) {
            faceFunctions[faceIt][j] =
              jacob * product2 * OrthogonalPoly::EvalLegendre(i1 - 2, sub[i]) *
              (*tangent)[j];
          }
          faceFunctions[faceIt][2] = 0;
          faceIt++;
        }
      }
      double sub1 = sub[0];
      double sub2 = sub[2];
      std::vector<double> LSub2(_pf - 2);
      for(int it = 0; it < _pf - 2; it++) {
        LSub2[it] = OrthogonalPoly::EvalLegendre(it, sub2);
      }
      for(int n1 = 0; n1 < _pf - 2; n1++) {
        double LSub1 = OrthogonalPoly::EvalLegendre(n1, sub1);
        for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
          faceFunctions[faceIt][0] =
            jacob * product * LSub1 * LSub2[n2] * dlambda[1][0];
          faceFunctions[faceIt][1] =
            jacob * product * LSub1 * LSub2[n2] * dlambda[1][1];
          faceIt++;
        }
      }
      // int faceIt2 = 3 * (_pf - 1);
      for(int n1 = 0; n1 < _pf - 2; n1++) {
        double LSub1 = OrthogonalPoly::EvalLegendre(n1, sub1);
        for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
          faceFunctions[faceIt][0] =
            jacob * product * LSub1 * LSub2[n2] * dlambda[2][0];
          faceFunctions[faceIt][1] =
            jacob * product * LSub1 * LSub2[n2] * dlambda[2][1];
          faceIt++;
          // faceIt2++;
        }
      }
    }
  }
}

void HdivTriangle::orientOneFace(double u, double v, double w, int flag1,
                                 int flag2, int flag3, int faceNumber,
                                 std::vector<double> &faceFunctions)
{
  if(!(flag1 == 0 && flag2 == 1)) {
    if(_space == DIV_HDIV) {
      // to map onto the reference domain of gmsh:
      double uc = 2 * u - 1;
      double vc = 2 * v - 1;
      double det = 4;
      //*****
      int faceIt = 0;
      std::vector<double> lambda(3);
      std::vector<std::vector<double>> dlambda(3, std::vector<double>(2, 0));
      std::vector<double> dProduct(2); // grad(lambdaA*lambdaB*lambdaC)
      lambda[0] = _affineCoordinate(2, uc, vc);
      lambda[1] = _affineCoordinate(3, uc, vc);
      lambda[2] = _affineCoordinate(1, uc, vc);
      dlambda[0][0] = -0.5;
      dlambda[0][1] = -0.5;
      dlambda[1][0] = 0.5;
      dlambda[2][1] = 0.5;
      dProduct[0] = 0.5 * lambda[2] * (lambda[0] - lambda[1]);
      dProduct[1] = 0.5 * lambda[1] * (lambda[0] - lambda[2]);
      double product = lambda[0] * lambda[1] * lambda[2];
      if(flag1 == 1 && flag2 == -1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 0 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      else if(flag1 == 2 && flag2 == -1) {
        double copy = lambda[2];
        lambda[2] = lambda[0];
        lambda[0] = copy;
        std::vector<double> dcopy = dlambda[2];
        dlambda[2] = dlambda[0];
        dlambda[0] = dcopy;
      }
      else if(flag1 == 1 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[1];
        lambda[1] = lambda[2];
        lambda[2] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[1];
        dlambda[1] = dlambda[2];
        dlambda[2] = dcopy;
      }
      else if(flag1 == 2 && flag2 == 1) {
        double copy = lambda[0];
        lambda[0] = lambda[2];
        lambda[2] = lambda[1];
        lambda[1] = copy;
        std::vector<double> dcopy = dlambda[0];
        dlambda[0] = dlambda[2];
        dlambda[2] = dlambda[1];
        dlambda[1] = dcopy;
      }
      std::vector<double> sub(3);
      sub[0] = lambda[1] - lambda[0];
      sub[1] = lambda[2] - lambda[1];
      sub[2] = lambda[0] - lambda[2];
      std::vector<double> t1 = std::vector<double>(2, 0);
      t1[0] = dlambda[2][1];
      t1[1] = -dlambda[2][0];
      std::vector<double> t2 = std::vector<double>(2, 0);
      t2[0] = dlambda[0][1];
      t2[1] = -dlambda[0][0];
      std::vector<double> t3 = std::vector<double>(2, 0);
      t3[0] = dlambda[1][1];
      t3[1] = -dlambda[1][0];
      std::vector<std::vector<double>> dsub(3, std::vector<double>(2, 0));
      for(int p = 0; p < 2; p++) {
        dsub[0][p] = dlambda[1][p] - dlambda[0][p];
        dsub[1][p] = dlambda[2][p] - dlambda[1][p];
        dsub[2][p] = dlambda[0][p] - dlambda[2][p];
      }
      // edge-based face functions
      double dlambda23U = dlambda[0][0] * lambda[1] + dlambda[1][0] * lambda[0];
      double dlambda23V = dlambda[0][1] * lambda[1] + dlambda[1][1] * lambda[0];
      double prod32 = lambda[0] * lambda[1];
      for(int i1 = 2; i1 <= _pf; i1++) {
        double dphiU =
          dlambda23U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
          prod32 * dsub[0][0] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0]);
        double dphiV =
          dlambda23V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[0]) +
          prod32 * dsub[0][1] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[0]);
        faceFunctions[faceIt] = det * (t1[0] * dphiU + t1[1] * dphiV);
        faceIt++;
      }
      double dlambda13U = dlambda[2][0] * lambda[1] + dlambda[1][0] * lambda[2];
      double dlambda13V = dlambda[2][1] * lambda[1] + dlambda[1][1] * lambda[2];
      double prod13 = lambda[2] * lambda[1];
      for(int i1 = 2; i1 <= _pf; i1++) {
        double dphiU =
          dlambda13U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
          prod13 * dsub[1][0] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1]);
        double dphiV =
          dlambda13V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[1]) +
          prod13 * dsub[1][1] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[1]);
        faceFunctions[faceIt] = det * (t2[0] * dphiU + t2[1] * dphiV);
        faceIt++;
      }
      double dlambda12U = dlambda[2][0] * lambda[0] + dlambda[0][0] * lambda[2];
      double dlambda12V = dlambda[2][1] * lambda[0] + dlambda[0][1] * lambda[2];
      double prod12 = lambda[0] * lambda[2];
      for(int i1 = 2; i1 <= _pf; i1++) {
        double dphiU =
          dlambda12U * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
          prod12 * dsub[2][0] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2]);
        double dphiV =
          dlambda12V * OrthogonalPoly::EvalLegendre(i1 - 2, sub[2]) +
          prod12 * dsub[2][1] * OrthogonalPoly::EvalDLegendre(i1 - 2, sub[2]);
        faceFunctions[faceIt] = det * (t3[0] * dphiU + t3[1] * dphiV);
        faceIt++;
      }
      // Genuine face function
      double subBA = sub[0];
      double subAC = sub[2];
      std::vector<double> dsubBA(2);
      std::vector<double> dsubAC(2);
      for(int i = 0; i < 2; i++) {
        dsubBA[i] = dsub[0][i];
        dsubAC[i] = dsub[2][i];
      }
      std::vector<double> LSubAC(_pf - 2);
      std::vector<double> dLSubAC(_pf - 2);
      for(int it = 0; it < _pf - 2; it++) {
        LSubAC[it] = OrthogonalPoly::EvalLegendre(it, subAC);
        dLSubAC[it] = OrthogonalPoly::EvalDLegendre(it, subAC);
      }
      std::vector<double> LSubBA(_pf - 2);
      std::vector<double> dLSubBA(_pf - 2);
      for(int it = 0; it < _pf - 2; it++) {
        LSubBA[it] = OrthogonalPoly::EvalLegendre(it, subBA);
        dLSubBA[it] = OrthogonalPoly::EvalDLegendre(it, subBA);
      }

      for(int n1 = 0; n1 < _pf - 2; n1++) {
        for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
          faceFunctions[faceIt] =
            det * ((dProduct[0] * LSubAC[n2] * LSubBA[n1] +
                    product * dsubBA[0] * LSubAC[n2] * dLSubBA[n1] +
                    product * dsubAC[0] * dLSubAC[n2] * LSubBA[n1]) *
                     dlambda[1][0] +
                   (dProduct[1] * LSubAC[n2] * LSubBA[n1] +
                    product * dsubBA[1] * LSubAC[n2] * dLSubBA[n1] +
                    product * dsubAC[1] * dLSubAC[n2] * LSubBA[n1]) *
                     dlambda[1][1]);
          faceIt++;
        }
      }
      for(int n1 = 0; n1 < _pf - 2; n1++) {
        for(int n2 = 0; n2 < _pf - 2 - n1; n2++) {
          faceFunctions[faceIt] =
            det * ((dProduct[0] * LSubAC[n2] * LSubBA[n1] +
                    product * dsubBA[0] * LSubAC[n2] * dLSubBA[n1] +
                    product * dsubAC[0] * dLSubAC[n2] * LSubBA[n1]) *
                     dlambda[2][0] +
                   (dProduct[1] * LSubAC[n2] * LSubBA[n1] +
                    product * dsubBA[1] * LSubAC[n2] * dLSubBA[n1] +
                    product * dsubAC[1] * dLSubAC[n2] * LSubBA[n1]) *
                     dlambda[2][1]);
          faceIt++;
        }
      }
    }
  }
}

void HdivTriangle::getKeysInfo(std::vector<int> &functionTypeInfo,
                               std::vector<int> &orderInfo)
{
  int it = 0;
  for(int numEdge = 0; numEdge < 3; numEdge++) {
    for(int i = 0; i <= _pOrderEdge[numEdge]; i++) {
      functionTypeInfo[it] = 1;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int numEdge = 0; numEdge < 3; numEdge++) {
    for(int i = 2; i <= _pf; i++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = i;
      it++;
    }
  }
  for(int n1 = 1; n1 < _pf - 1; n1++) {
    for(int n2 = 1; n2 <= _pf - 1 - n1; n2++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = n1 + n2 + 1;
      it++;
    }
  }
  for(int n1 = 1; n1 < _pf - 1; n1++) {
    for(int n2 = 1; n2 <= _pf - 1 - n1; n2++) {
      functionTypeInfo[it] = 2;
      orderInfo[it] = n1 + n2 + 1;
      it++;
    }
  }
}
