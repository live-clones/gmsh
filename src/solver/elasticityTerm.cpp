// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "elasticityTerm.h"
#include "Numeric.h"

// The SElement (Solver element) that has been sent to the function
// contains 2 enrichments, that can enrich both shape and test functions

void elasticityTerm::createData(MElement *e) const
{
  if(_data.find(e->getTypeForMSH()) != _data.end()) return;
  elasticityDataAtGaussPoint d;
  int nbSF = (int)e->getNumShapeFunctions();
  int integrationOrder = 2 * (e->getPolynomialOrder() - 1);
  int npts;
  IntPt *GP;
  double gs[100][3];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);
  for(int i = 0; i < npts; i++) {
    fullMatrix<double> a(nbSF, 3);
    const double u = GP[i].pt[0];
    const double v = GP[i].pt[1];
    const double w = GP[i].pt[2];
    const double weight = GP[i].weight;
    e->getGradShapeFunctions(u, v, w, gs);
    for(int j = 0; j < nbSF; j++) {
      a(j, 0) = gs[j][0];
      a(j, 1) = gs[j][1];
      a(j, 2) = gs[j][2];
    }
    d.gradSF.push_back(a);
    d.u.push_back(u);
    d.v.push_back(v);
    d.w.push_back(w);
    d.weight.push_back(weight);
  }
  _data[e->getTypeForMSH()] = d;
}

void elasticityTerm::elementMatrix(SElement *se, fullMatrix<double> &m) const
{
  MElement *e = se->getMeshElement();
  createData(e);

  int nbSF = (int)e->getNumShapeFunctions();
  elasticityDataAtGaussPoint &d = _data[e->getTypeForMSH()];
  int npts = d.u.size();
  m.setAll(0.);

  double FACT = _e / (1 + _nu);
  double C11 = FACT * (1 - _nu) / (1 - 2 * _nu);
  double C12 = FACT * _nu / (1 - 2 * _nu);
  double C44 = (C11 - C12) / 2;
  const double C[6][6] = {{C11, C12, C12, 0, 0, 0}, {C12, C11, C12, 0, 0, 0},
                          {C12, C12, C11, 0, 0, 0}, {0, 0, 0, C44, 0, 0},
                          {0, 0, 0, 0, C44, 0},     {0, 0, 0, 0, 0, C44}};

  fullMatrix<double> H(6, 6);
  fullMatrix<double> B(6, 3 * nbSF);
  fullMatrix<double> BTH(3 * nbSF, 6);
  fullMatrix<double> BT(3 * nbSF, 6);
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++) H(i, j) = C[i][j];

  double jac[3][3], invjac[3][3], Grads[100][3];
  for(int i = 0; i < npts; i++) {
    const double weight = d.weight[i];
    const fullMatrix<double> &grads = d.gradSF[i];
    const double detJ = e->getJacobian(grads, jac);
    inv3x3(jac, invjac);

    for(int j = 0; j < nbSF; j++) {
      Grads[j][0] = invjac[0][0] * grads(j, 0) + invjac[0][1] * grads(j, 1) +
                    invjac[0][2] * grads(j, 2);
      Grads[j][1] = invjac[1][0] * grads(j, 0) + invjac[1][1] * grads(j, 1) +
                    invjac[1][2] * grads(j, 2);
      Grads[j][2] = invjac[2][0] * grads(j, 0) + invjac[2][1] * grads(j, 1) +
                    invjac[2][2] * grads(j, 2);
    }

    B.setAll(0.);
    BT.setAll(0.);

    if(se->getShapeEnrichement() == se->getTestEnrichement()) {
      for(int j = 0; j < nbSF; j++) {
        BT(j, 0) = B(0, j) = Grads[j][0];
        BT(j, 3) = B(3, j) = Grads[j][1];
        BT(j, 5) = B(5, j) = Grads[j][2];

        BT(j + nbSF, 1) = B(1, j + nbSF) = Grads[j][1];
        BT(j + nbSF, 3) = B(3, j + nbSF) = Grads[j][0];
        BT(j + nbSF, 4) = B(4, j + nbSF) = Grads[j][2];

        BT(j + 2 * nbSF, 2) = B(2, j + 2 * nbSF) = Grads[j][2];
        BT(j + 2 * nbSF, 4) = B(4, j + 2 * nbSF) = Grads[j][1];
        BT(j + 2 * nbSF, 5) = B(5, j + 2 * nbSF) = Grads[j][0];
      }
    }
    else {
      /*
      se->gradNodalTestFunctions (u, v, w, invjac,GradsT);
      for (int j = 0; j < nbSF; j++){
        BT(j, 0) = Grads[j][0]; B(0, j) = GradsT[j][0];
        BT(j, 3) = Grads[j][1]; B(3, j) = GradsT[j][1];
        BT(j, 5) = Grads[j][2]; B(5, j) = GradsT[j][2];

        BT(j + nbSF, 1) = Grads[j][1]; B(1, j + nbSF) = GradsT[j][1];
        BT(j + nbSF, 3) = Grads[j][0]; B(3, j + nbSF) = GradsT[j][0];
        BT(j + nbSF, 4) = Grads[j][2]; B(4, j + nbSF) = GradsT[j][2];

        BT(j + 2 * nbSF, 2) = Grads[j][2]; B(2, j + 2 * nbSF) = GradsT[j][2];
        BT(j + 2 * nbSF, 4) = Grads[j][1]; B(4, j + 2 * nbSF) = GradsT[j][1];
        BT(j + 2 * nbSF, 5) = Grads[j][0]; B(5, j + 2 * nbSF) = GradsT[j][0];
      }
      */
    }

    BTH.setAll(0.);
    BTH.gemm(BT, H);
    m.gemm(BTH, B, weight * detJ, 1.);
  }
}

void elasticityTerm::elementVector(SElement *se, fullVector<double> &m) const
{
  MElement *e = se->getMeshElement();
  int nbSF = (int)e->getNumShapeFunctions();
  int integrationOrder = 2 * e->getPolynomialOrder();
  int npts;
  IntPt *GP;
  double jac[3][3];
  double ff[256];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);

  m.scale(0.);

  for(int i = 0; i < npts; i++) {
    const double u = GP[i].pt[0];
    const double v = GP[i].pt[1];
    const double w = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian(u, v, w, jac);
    se->nodalTestFunctions(u, v, w, ff);
    for(int j = 0; j < nbSF; j++) {
      m(j) += _volumeForce.x() * ff[j] * weight * detJ * .5;
      m(j + nbSF) += _volumeForce.y() * ff[j] * weight * detJ * .5;
      m(j + 2 * nbSF) += _volumeForce.z() * ff[j] * weight * detJ * .5;
    }
  }
}

/*

B_d is the deviatoric part of the FE strains

K_{uu} = \int_\Omega B^T_d H B_d dv

*/

void elasticityMixedTerm::elementMatrix(SElement *se,
                                        fullMatrix<double> &m) const
{
  setPolynomialBasis(se);
  MElement *e = se->getMeshElement();
  int integrationOrder = 4 * (e->getPolynomialOrder()) + 2;
  int npts;
  IntPt *GP;
  double jac[3][3];
  double invjac[3][3];
  double Grads[100][3];
  double SF[100];
  e->getIntegrationPoints(integrationOrder, &npts, &GP);

  m.setAll(0.);
  fullMatrix<double> KUU(3 * _sizeN, 3 * _sizeN);
  fullMatrix<double> KUP(3 * _sizeN, _sizeM);
  fullMatrix<double> KUG(3 * _sizeN, _sizeM);
  fullMatrix<double> KPG(_sizeM, _sizeM);
  fullMatrix<double> KGG(_sizeM, _sizeM);
  fullMatrix<double> KPP(_sizeM, _sizeM); // stabilization

  double FACT = _e / ((1 + _nu) * (1. - 2 * _nu));
  double C11 = FACT * (1 - _nu);
  double C12 = FACT * _nu;
  double C44 = FACT * (1 - 2. * _nu) * .5;
  // double _k = 3*_e / (1 - 2 * _nu);
  // FIXME : PLANE STRESS !!!
  //  FACT = _e / (1-_nu*_nu);
  //  C11  = FACT;
  //  C12  = _nu * FACT;
  //  C44 = (1.-_nu)*.5*FACT;

  const double C[6][6] = {{C11, C12, C12, 0, 0, 0}, {C12, C11, C12, 0, 0, 0},
                          {C12, C12, C11, 0, 0, 0}, {0, 0, 0, C44, 0, 0},
                          {0, 0, 0, 0, C44, 0},     {0, 0, 0, 0, 0, C44}};

  fullMatrix<double> H(6, 6);
  fullMatrix<double> B(6, 3 * _sizeN);
  fullMatrix<double> BDEV(6, 3 * _sizeN);
  fullMatrix<double> BDIL(1, 3 * _sizeN);
  fullMatrix<double> BDILT(3 * _sizeN, 1);
  fullMatrix<double> BTH(3 * _sizeN, 6);
  fullMatrix<double> BT(3 * _sizeN, 6);
  fullMatrix<double> trBTH(3 * _sizeN, 1);
  fullMatrix<double> MT(_sizeM, 1);
  fullMatrix<double> M(1, _sizeM);
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++) H(i, j) = C[i][j];

  double _dimension = 2.0;

  for(int i = 0; i < npts; i++) {
    const double u = GP[i].pt[0];
    const double v = GP[i].pt[1];
    const double w = GP[i].pt[2];
    const double weight = GP[i].weight;
    const double detJ = e->getJacobian(u, v, w, jac);
    inv3x3(jac, invjac);
    se->gradNodalShapeFunctions(u, v, w, invjac, Grads);
    e->getShapeFunctions(u, v, w, SF, _polyOrderM);

    B.setAll(0.);
    BT.setAll(0.);

    const double K =
      .0000002 * weight * detJ *
      pow(detJ, 2 / _dimension); // the second detJ is for stabilization

    for(int j = 0; j < _sizeM; j++) {
      for(int k = 0; k < _sizeM; k++) {
        KPP(j, k) += (Grads[j][0] * Grads[k][0] + Grads[j][1] * Grads[k][1] +
                      Grads[j][2] * Grads[k][2]) *
                     K;
      }
    }

    const double K2 = weight * detJ;

    for(int j = 0; j < _sizeN; j++) {
      for(int k = 0; k < _sizeM; k++) {
        KUP(j + 0 * _sizeN, k) += Grads[j][0] * SF[k] * K2;
        KUP(j + 1 * _sizeN, k) += Grads[j][1] * SF[k] * K2;
        KUP(j + 2 * _sizeN, k) += Grads[j][2] * SF[k] * K2;
      }
    }

    /*
    const double K3 = weight * detJ * _e/(2*(1+_nu));
    for (int j = 0; j < _sizeN; j++){
      for (int k = 0; k < _sizeN; k++){
    const double fa = (Grads[j][0] * Grads[k][0] +
               Grads[j][1] * Grads[k][1] +
               Grads[j][2] * Grads[k][2]) * K3;
    KUU(j+0*_sizeN, k+0*_sizeN) += fa;
    KUU(j+1*_sizeN, k+1*_sizeN) += fa;
    KUU(j+2*_sizeN, k+2*_sizeN) += fa;
      }
    }
    */

    for(int j = 0; j < _sizeN; j++) {
      //      printf("%g %g %g\n",Grads[j][0],Grads[j][1],Grads[j][2]);

      BDILT(j, 0) = BDIL(0, j) = Grads[j][0] / _dimension;

      BT(j, 0) = B(0, j) = Grads[j][0]; //-Grads[j][0]/_dimension;
      //      BT(j, 1) = B(1, j) =            -Grads[j][1]/_dimension;
      //      BT(j, 2) = B(2, j) =            -Grads[j][2]/_dimension;

      BT(j, 3) = B(3, j) = Grads[j][1];
      BT(j, 4) = B(4, j) = Grads[j][2];

      BDILT(j + _sizeN, 0) = BDIL(0, j + _sizeN) = Grads[j][1] / _dimension;

      //      BT(j + _sizeN, 0) = B(0, j + _sizeN) = -Grads[j][0]/_dimension;
      BT(j + _sizeN, 1) = B(1, j + _sizeN) =
        Grads[j][1]; //-Grads[j][1]/_dimension;
      //      BT(j + _sizeN, 2) = B(2, j + _sizeN) = -Grads[j][2]/_dimension;

      BT(j + _sizeN, 3) = B(3, j + _sizeN) = Grads[j][0];
      BT(j + _sizeN, 5) = B(5, j + _sizeN) = Grads[j][2];

      BDILT(j + 2 * _sizeN, 0) = BDIL(0, j + 2 * _sizeN) =
        Grads[j][2] / _dimension;

      //      BT(j + 2 * _sizeN, 0) = B(0, j + 2 * _sizeN) =
      //      -Grads[j][0]/_dimension; BT(j + 2 * _sizeN, 1) = B(1, j + 2 *
      //      _sizeN) =            -Grads[j][1]/_dimension;
      BT(j + 2 * _sizeN, 2) = B(2, j + 2 * _sizeN) =
        Grads[j][2]; //-Grads[j][2]/_dimension;

      BT(j + 2 * _sizeN, 4) = B(4, j + 2 * _sizeN) = Grads[j][1];
      BT(j + 2 * _sizeN, 5) = B(5, j + 2 * _sizeN) = Grads[j][0];
    }

    for(int j = 0; j < _sizeM; j++) {
      MT(j, 0) = M(0, j) = SF[j];
    }

    // printf("BT (%d %d) x H (%d,%d) = BTH(%d,%d)\n",BT.size1(),BT.size2(),
    // H.size1(),H.size2(),BTH.size1(),BTH.size2());

    BTH.setAll(0.);
    BTH.gemm(BT, H);

    for(int j = 0; j < 3 * _sizeN; j++) {
      trBTH(j, 0) = BTH(j, 0) + BTH(j, 1) + BTH(j, 2);
    }

    KUU.gemm(BTH, B, weight * detJ);
    // KUP.gemm(BDILT, M, weight * detJ);
    // KPG.gemm(MT, M, -weight * detJ);
    // KUG.gemm(trBTH, M, weight * detJ/_dimension);
    // KGG.gemm(MT, M, weight * detJ * (_k)/(_dimension*_dimension));
  }
  /*
          3*_sizeN  _sizeM _sizeM

          KUU     KUP     KUG
    m  =  KUP^t   KPP      KPG
          KUG^T    KPG^t  KGG

   */

  for(int i = 0; i < 3 * _sizeN; i++) {
    for(int j = 0; j < 3 * _sizeN; j++) m(i, j) = KUU(i, j); // assemble KUU

    for(int j = 0; j < _sizeM; j++) {
      m(i, j + 3 * _sizeN) = KUP(i, j); // assemble KUP
      m(j + 3 * _sizeN, i) = KUP(i, j); // assemble KUP^T
    }

    for(int j = 0; j < _sizeM; j++) {
      m(i, j + 3 * _sizeN + _sizeM) = KUG(i, j); // assemble KUG
      m(j + 3 * _sizeN + _sizeM, i) = KUG(i, j); // assemble KUG^t
    }
  }
  for(int i = 0; i < _sizeM; i++) {
    for(int j = 0; j < _sizeM; j++) {
      m(i + 3 * _sizeN, j + 3 * _sizeN + _sizeM) = KPG(i, j); // assemble KPG
      m(j + 3 * _sizeN + _sizeM, i + 3 * _sizeN) = KPG(i, j); // assemble KPG^t

      m(i + 3 * _sizeN + _sizeM, j + 3 * _sizeN + _sizeM) =
        KGG(i, j); // assemble KGG

      m(i + 3 * _sizeN, j + 3 * _sizeN) = KPP(i, j); // assemble KPP
    }
  }
  //    m.print("Mixed");
  return;
}
