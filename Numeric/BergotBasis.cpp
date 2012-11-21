// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "BergotBasis.h"

/*BergotBasis::BergotBasis() {


}*/



BergotBasis::BergotBasis(int p): order(p)
{
}



BergotBasis::~BergotBasis()
{
}



void BergotBasis::f(double u, double v, double w, double* val) const
{

  LegendrePolynomials legendre(order);

  double uhat = (w == 1.) ? 1. : u/(1.-w);
  std::vector<double> uFcts(order+1);
  legendre.f(uhat,&(uFcts[0]));

  double vhat = (w == 1.) ? 1. : v/(1.-w);
  std::vector<double> vFcts(order+1);
  legendre.f(vhat,&(vFcts[0]));

  double what = 2.*w - 1.;
  std::vector<std::vector<double> > wFcts(order+1), wGrads(order+1);
  for (int mIJ=0; mIJ<=order; mIJ++) {
    int kMax = order-mIJ;
    std::vector<double> &wf = wFcts[mIJ];
    wf.resize(kMax+1);
    JacobiPolynomials jacobi(2.*mIJ+2.,0.,kMax);
    jacobi.f(what,&(wf[0]));
  }

  // recombine to find shape function values

  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      int mIJ = std::max(i,j);
      double fact = pow(1.-w, mIJ);
      std::vector<double> &wf = wFcts[mIJ];
      for (int k=0; k<=order-mIJ; k++,index++) {
        val[index] = uFcts[i] * vFcts[j] * wf[k] * fact;
      }
    }
  }

}



void BergotBasis::df(double u, double v, double w, double grads[][3]) const
{

  LegendrePolynomials legendre(order);

//  std::cout << "DBGTT: u = " << u << ", v = " << v << ", w = " << w << "\n";

  double uhat = (w == 1.) ? 1. : u/(1.-w);
  std::vector<double> uFcts(order+1), uGrads(order+1);
  legendre.f(uhat,&(uFcts[0]));
  legendre.df(uhat,&(uGrads[0]));

  double vhat = (w == 1.) ? 1. : v/(1.-w);
  std::vector<double> vFcts(order+1), vGrads(order+1);
  legendre.f(vhat,&(vFcts[0]));
  legendre.df(vhat,&(vGrads[0]));

  double what = 2.*w - 1.;
  std::vector<std::vector<double> > wFcts(order+1), wGrads(order+1);
  for (int mIJ=0; mIJ<=order; mIJ++) {
    int kMax = order-mIJ;
    std::vector<double> &wf = wFcts[mIJ], &wg = wGrads[mIJ];
    wf.resize(kMax+1);
    wg.resize(kMax+1);
    if (what == 1.) {
      const int alpha = 2*mIJ+2, fMax = std::max(kMax,1)+alpha;
      std::vector<double> fact(fMax);
      fact[0] = 1.;
      for (int i=1;i<=fMax;i++) fact[i] = i*fact[i-1];
      wf[0] = 1.; wg[0] = 0.;
      for (int k=1;k<=kMax;k++) {
//        std::cout << "DBGTT: calc. fMax = " << fMax << ", alpha = " << alpha << ", k = " << k << "\n";
        wf[k] = fact[k+alpha]/(fact[alpha]*fact[k]);
        wg[k] = 0.5*(k+alpha+2)*fact[k+alpha]/(fact[alpha+1]*fact[k-1]);
//        std::cout << "DBGTT:     -> wf[k] = " << wf[k] << ", wg[k] = " << wg[k] << "\n";
      }
    }
    else {
      JacobiPolynomials jacobi(2.*mIJ+2.,0.,kMax);
      jacobi.f(what,&(wf[0]));
      jacobi.df(what,&(wg[0]));
    }
//    for (int k=0; k<=order-mIJ; k++) std::cout << " -> mIJ = " << mIJ << ", k = " << k
//        << " -> wf[k] = " << wf[k] << ", wg[k] = " << wg[k] << "\n";
  }

  // now recombine to find the shape function gradients

  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      int mIJ = std::max(i,j);
      std::vector<double> &wf = wFcts[mIJ], &wg = wGrads[mIJ];
      double oMW = 1.-w;
      double powM2 = ((w == 1.) && (mIJ < 2)) ? 0. : pow(oMW, mIJ-2);
      double powM1 = powM2*oMW;
      for (int k=0; k<=order-mIJ; k++,index++) {
        if (mIJ == 0) {
          grads[index][0] = 0.;
          grads[index][1] = 0.;
          grads[index][2] = 2.*wg[k];
        }
        else if (mIJ == 1) {
          if (i == 0) {
            grads[index][0] = 0.;
            grads[index][1] = wf[k];
            grads[index][2] = 2.*v*wg[k];
          }
          else if (j == 0) {
            grads[index][0] = wf[k];
            grads[index][1] = 0.;
            grads[index][2] = 2.*u*wg[k];
          }
          else {
            grads[index][0] = vhat*wf[k];
            grads[index][1] = uhat*wf[k];
            grads[index][2] = uhat*vhat*wf[k]+2.*uhat*v*wg[k];
          }
        }
        else {
          grads[index][0] = uGrads[i] * vFcts[j]  * wf[k] * powM1;
          grads[index][1] = uFcts[i]  * vGrads[j] * wf[k] * powM1;
          grads[index][2] = wf[k]*powM2*(u*uGrads[i]*vFcts[j]+v*uFcts[i]*vGrads[j])
                            + uFcts[i]*vFcts[j]*powM1*(2.*oMW*wg[k]-mIJ*wf[k]);
        }
////        std::cout << " -> i = " << i << ", j = " << j << ", k = " << k << " -> grad = ("
////            << grads[index][0] << ", " << grads[index][1] << ", "<< grads[index][2] << ")\n";
//        std::cout << " -> i = " << i << ", j = " << j << ", k = " << k
//            << " -> wf[k] = " << wf[k] << ", wg[k] = " << wg[k] << "\n";
      }
    }
  }

}
