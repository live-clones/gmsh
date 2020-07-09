// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "winslowTerm.h"
#include "Numeric.h"

// The SElement (Solver element) that has been sent to the function
// contains 2 enrichments, that can enrich both shape and test functions

void winslowTerm::createData(MElement *e) const
{
  if(_data.find(e->getTypeForMSH()) != _data.end()) return;
  winslowDataAtGaussPoint d;
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

void winslowTerm::elementMatrix(SElement *se, fullMatrix<double> &m) const
{
  MElement *e = se->getMeshElement();
  createData(e);

  int nbSF = (int)e->getNumShapeFunctions();
  winslowDataAtGaussPoint &d = _data[e->getTypeForMSH()];
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

void winslowTerm::elementVector(SElement *se, fullVector<double> &m) const
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
