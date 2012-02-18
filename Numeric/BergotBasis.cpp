// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "BergotBasis.h"

BergotBasis::BergotBasis(int p): order(p)
{
  // allocate function information and fill

  iOrder = new int[size()];
  jOrder = new int[size()];
  kOrder = new int[size()];

  legendre = new LegendrePolynomials(order);

  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      int mIJ = std::max(i,j);
      for (int k=0;k<= (int) (order - mIJ);k++,index++) {

        iOrder[index] = i;
        jOrder[index] = j;
        kOrder[index] = k;

        if (jacobi.find(mIJ) == jacobi.end()) {
          jacobi[mIJ] = new JacobiPolynomials(2*mIJ+2,0,order);
        }
      }
    }
  }
}

BergotBasis::~BergotBasis()
{
  delete [] iOrder;
  delete [] jOrder;
  delete [] kOrder;

  delete legendre;
  std::map<int,JacobiPolynomials*>::iterator jIter = jacobi.begin();
  for (;jIter!=jacobi.end();++jIter) delete jIter->second;
}

int BergotBasis::size() const
{
  return (2*order*order*order + 9*order*order + 13*order + 6)/6;
}

void BergotBasis::f(double u, double v, double w, double* val) const
{
  double uhat = (w == 1.) ? 1 : u/(1.-w);

  std::vector<double> uFcts(order+1);
  legendre->f(uhat,&(uFcts[0]));

  double vhat = (w == 1.) ? 1 : v/(1.-w);
  std::vector<double> vFcts(order+1);
  legendre->f(vhat,&(vFcts[0]));

  double what = 2.*w - 1.;
  std::map<int,double* > wFcts;
  std::map<int,JacobiPolynomials*>::const_iterator jIter=jacobi.begin();

  for (;jIter!=jacobi.end();jIter++) {
    int a = jIter->first;
    wFcts[a] = new double[order + 1];
    double* wf = wFcts[a];
    jIter->second->f(what,wf);
  }

  // recombine to find shape function values

  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {
      int mIJ = std::max(i,j);
      double fact = pow_int(1-w,(int) mIJ);
      double* wf = (wFcts.find(mIJ))->second;
      for (int k=0;k<=(int) (order - mIJ);k++,index++) {
        val[index] = uFcts[i] * vFcts[j] * wf[k] * fact;
      }
    }
  }

  jIter=jacobi.begin();

  for (;jIter!=jacobi.end();jIter++) {
    int a = jIter->first;
    delete [] wFcts[a];
  }
}

void BergotBasis::df(double u, double v, double w, double grads[][3]) const
{
  std::vector<double> uFcts(order+1);
  legendre->f(u,&(uFcts[0]));

  std::vector<double> uGrads(order+1);
  legendre->df(u,&(uGrads[0]));

  std::vector<double> vFcts(order+1);
  legendre->f(v,&(vFcts[0]));

 std::vector<double> vGrads(order+1);
  legendre->df(v,&(vGrads[0]));


  std::map<int,double* > wFcts;
  std::map<int,double* > wGrads;
  std::map<int,JacobiPolynomials*>::const_iterator jIter=jacobi.begin();

  for (;jIter!=jacobi.end();jIter++) {
    int a = jIter->first;
    wFcts[a] = new double[order+1];
    double* wf = wFcts[a];
    jIter->second->f(w,wf);
    wGrads[a] = new double[order+1];
    double* wg = wGrads[a];
    jIter->second->df(w,wg);
  }

  // now recombine to find the shape function gradients

  int index = 0;
  for (int i=0;i<=order;i++) {
    for (int j=0;j<=order;j++) {

      int mIJ = std::max(i,j);

      double* wf = (wFcts .find(mIJ))->second;
      double* wg = (wGrads.find(mIJ))->second;

      double wPowM2 = pow_int(1.-w,((int) mIJ) - 2);
      double wPowM1 = wPowM2*(1.-w);
      double wPowM0 = wPowM1*(1.-w);

      for (int k=0;k<= (int) (order - mIJ);k++,index++) {

        grads[index][0] = uGrads[i] * vFcts[j]  * wf[k] * wPowM1;

        grads[index][1] = uFcts[i]  * vGrads[j] * wf[k] * wPowM1;

        grads[index][2]  = 0;
        grads[index][2] += u   * uGrads[i] * vFcts[j]  * wf[k] * wPowM2;
        grads[index][2] += v   * uFcts[i]  * vGrads[j] * wf[k] * wPowM2;
        grads[index][2] -= mIJ * uFcts[i]  * vFcts[j]  * wf[k] * wPowM1;
        grads[index][2] +=   2 * uFcts[i]  * vFcts[j]  * wg[k] * wPowM0;


      }
    }
  }
  jIter=jacobi.begin();

  for (;jIter!=jacobi.end();jIter++) {
    int a = jIter->first;
    delete [] wFcts[a];
    delete [] wGrads[a];
  }

}
