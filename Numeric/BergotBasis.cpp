// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <cmath>
#include "BergotBasis.h"
#include "MElement.h"



BergotBasis::BergotBasis(int p): order(p)
{
}



BergotBasis::~BergotBasis()
{
}



// Values of Bergot basis functions for coordinates (u,v,w) in the unit pyramid:
// f = L_i(uhat)*L_j(vhat)*(1-w)^max(i,j)*P_k^{2*max(i,j)+2,0}(what)
// with i,j = 0...order and k = 0...order-max(i,j)
// and (uhat,vhat,what) = (u/(1-w),v/(1-w),2*w-1) reduced coordinates in the unit cube [-1,1]^3
void BergotBasis::f(double u, double v, double w, double* val) const
{

  LegendrePolynomials legendre(order);

  // Compute Legendre polynomials at uhat
  double uhat = (w == 1.) ? 0. : u/(1.-w);
  std::vector<double> uFcts(order+1);
  legendre.f(uhat,&(uFcts[0]));

  // Compute Legendre polynomials at vhat
  double vhat = (w == 1.) ? 0. : v/(1.-w);
  std::vector<double> vFcts(order+1);
  legendre.f(vhat,&(vFcts[0]));

  // Compute Jacobi polynomials at what
  double what = 2.*w - 1.;
  std::vector<std::vector<double> > wFcts(order+1), wGrads(order+1);
  for (int mIJ=0; mIJ<=order; mIJ++) {
    int kMax = order-mIJ;
    std::vector<double> &wf = wFcts[mIJ];
    wf.resize(kMax+1);
    JacobiPolynomials jacobi(2.*mIJ+2.,0.,kMax);
    jacobi.f(what,&(wf[0]));
  }

  // Recombine to find shape function values
  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      int mIJ = std::max(i,j);
      double fact = pow(1.-w, mIJ);
      std::vector<double> &wf = wFcts[mIJ];
      for (int k=0; k<=order-mIJ; k++,index++) val[index] = uFcts[i] * vFcts[j] * wf[k] * fact;
    }
  }

}



// Derivatives of Bergot basis functions for coordinates (u,v,w) in the unit pyramid:
// dfdu = L'_i(uhat)*L_j(vhat)*(1-w)^(max(i,j)-1)*P_k^{2*max(i,j)+2,0}(what)
// dfdv = L_i(uhat)*L'_j(vhat)*(1-w)^(max(i,j)-1)*P_k^{2*max(i,j)+2,0}(what)
// dfdw = (1-w)^(max(i,j)-2)*P_k^{2*max(i,j)+2,0}(what)*(u*L'_i(uhat)*L_j(vhat)+v*L_i(uhat)*L'_j(vhat))
//        + u*v*(1-w)^(max(i,j)-1)*(2*(1-w)*P'_k^{2*max(i,j)+2,0}(what)-max(i,j)*P_k^{2*max(i,j)+2,0}(what))
// with i,j = 0...order and k = 0...order-max(i,j)
// and (uhat,vhat,what) = (u/(1-w),v/(1-w),2*w-1) reduced coordinates in the unit cube [-1,1]^3
void BergotBasis::df(double u, double v, double w, double grads[][3]) const
{

  LegendrePolynomials legendre(order);

  // Compute Legendre polynomials and derivatives at uhat
  double uhat = (w == 1.) ? 0. : u/(1.-w);
  std::vector<double> uFcts(order+1), uGrads(order+1);
  legendre.f(uhat,&(uFcts[0]));
  legendre.df(uhat,&(uGrads[0]));

  // Compute Legendre polynomials and derivatives at vhat
  double vhat = (w == 1.) ? 0. : v/(1.-w);
  std::vector<double> vFcts(order+1), vGrads(order+1);
  legendre.f(vhat,&(vFcts[0]));
  legendre.df(vhat,&(vGrads[0]));

  // Compute Jacobi polynomials and derivatives at what
  double what = 2.*w - 1.;
  std::vector<std::vector<double> > wFcts(order+1), wGrads(order+1);
  for (int mIJ=0; mIJ<=order; mIJ++) {
    int kMax = order-mIJ;
    std::vector<double> &wf = wFcts[mIJ], &wg = wGrads[mIJ];
    wf.resize(kMax+1);
    wg.resize(kMax+1);
    JacobiPolynomials jacobi(2.*mIJ+2.,0.,kMax);
    jacobi.f(what,&(wf[0]));
    jacobi.df(what,&(wg[0]));
  }

  // Recombine to find the shape function gradients
  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      int mIJ = std::max(i,j);
      std::vector<double> &wf = wFcts[mIJ], &wg = wGrads[mIJ];
      if (mIJ == 0) {                                                     // Indeterminate form for mIJ = 0
        for (int k=0; k<=order-mIJ; k++,index++) {
          grads[index][0] = 0.;
          grads[index][1] = 0.;
          grads[index][2] = 2.*wg[k];
        }
      }
      else if (mIJ == 1) {                                                // Indeterminate form for mIJ = 1
        if (i == 0) {
          for (int k=0; k<=order-mIJ; k++,index++) {
            grads[index][0] = 0.;
            grads[index][1] = wf[k];
            grads[index][2] = 2.*v*wg[k];
          }
        }
        else if (j == 0) {
          for (int k=0; k<=order-mIJ; k++,index++) {
            grads[index][0] = wf[k];
            grads[index][1] = 0.;
            grads[index][2] = 2.*u*wg[k];
          }
        }
        else {
          for (int k=0; k<=order-mIJ; k++,index++) {
            grads[index][0] = vhat*wf[k];
            grads[index][1] = uhat*wf[k];
            grads[index][2] = uhat*vhat*wf[k]+2.*uhat*v*wg[k];
          }
        }
      }
      else {                                                              // General formula
        double oMW = 1.-w;
        double powM2 = pow(oMW, mIJ-2);
        double powM1 = powM2*oMW;
        for (int k=0; k<=order-mIJ; k++,index++) {
          grads[index][0] = uGrads[i] * vFcts[j]  * wf[k] * powM1;
          grads[index][1] = uFcts[i]  * vGrads[j] * wf[k] * powM1;
          grads[index][2] = wf[k]*powM2*(u*uGrads[i]*vFcts[j]+v*uFcts[i]*vGrads[j])
                                    + uFcts[i]*vFcts[j]*powM1*(2.*oMW*wg[k]-mIJ*wf[k]);
        }
      }
    }
  }

}
