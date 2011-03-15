//
// C++ Implementation: terms
//
// Description:
//
//
// Author:  <Eric Bechet>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "terms.h"


void BilinearTermToScalarTerm::get(MElement *ele, int npts, IntPt *GP, double &val) const
{
  fullMatrix<double> localMatrix;
  bilterm.get(ele, npts, GP, localMatrix);
  val = localMatrix(0, 0);
}

void BilinearTermBase::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const 
{
  std::vector<fullMatrix<double> > mv(npts);
  get(ele,npts,GP,mv);
  m.resize(mv[0].size1(), mv[0].size2());
  m.setAll(0.);
  double jac[3][3];
  for (int k=0;k<npts;k++)
  {
    const double u = GP[k].pt[0]; const double v = GP[k].pt[1]; const double w = GP[k].pt[2];
    const double weight = GP[k].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    const double coeff=weight*detJ;
    for (int i=0;i<mv[k].size1();++i)
      for (int j=0;j<mv[k].size2();++j)
        m(i,j)+=mv[k](i,j)*coeff;
  }
}

IsotropicElasticTerm::IsotropicElasticTerm(FunctionSpace<SVector3>& space1_, FunctionSpace<SVector3>& space2_, double E_, double nu_) :
    BilinearTerm<SVector3, SVector3>(space1_, space2_), E(E_), nu(nu_), H(6, 6)
{
  double FACT = E / (1 + nu);
  double C11 = FACT * (1 - nu) / (1 - 2 * nu);
  double C12 = FACT * nu / (1 - 2 * nu);
  double C44 = (C11 - C12) / 2;
  H.scale(0.);
  for(int i = 0; i < 3; ++i) { H(i, i) = C11; H(i + 3, i + 3) = C44; }
  H(1, 0) = H(0, 1) = H(2, 0) = H(0, 2) = H(1, 2) = H(2, 1) = C12;
  sym = (&space1_ == &space2_);
}
IsotropicElasticTerm::IsotropicElasticTerm(FunctionSpace<SVector3>& space1_, double E_, double nu_) :
    BilinearTerm<SVector3, SVector3>(space1_, space1_), E(E_), nu(nu_), H(6, 6)
{
  double FACT = E / (1 + nu);
  double C11 = FACT * (1 - nu) / (1 - 2 * nu);
  double C12 = FACT * nu / (1 - 2 * nu);
  double C44 = (C11 - C12) / 2;
/*  FACT = E / (1 - nu * nu); // plane stress (plates)
  C11  = FACT;
  C12  = nu * FACT; 
  C44 = (1. - nu) * .5 * FACT;*/
  H.scale(0.);
  for(int i = 0; i < 3; ++i) { H(i, i) = C11; H(i + 3, i + 3) = C44; }
  H(1, 0) = H(0, 1) = H(2, 0) = H(0, 2) = H(1, 2) = H(2, 1) = C12;
  sym = true;
}

void IsotropicElasticTerm::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const
{
  if(ele->getParent()) ele = ele->getParent();
  if(sym)
  {
    int nbFF = BilinearTerm<SVector3, SVector3>::space1.getNumKeys(ele);
    double jac[3][3];
    fullMatrix<double> B(6, nbFF);
    fullMatrix<double> BTH(nbFF, 6);
    fullMatrix<double> BT(nbFF, 6);
    m.resize(nbFF, nbFF);
    m.setAll(0.);
    //std::cout << m.size1() << "  " << m.size2() << std::endl;
    for(int i = 0; i < npts; i++)
    {
      const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
      const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
      std::vector<TensorialTraits<SVector3>::GradType> Grads;
      BilinearTerm<SVector3, SVector3>::space1.gradf(ele, u, v, w, Grads); // a optimiser ??
      for(int j = 0; j < nbFF; j++)
      {
        BT(j, 0) = B(0, j) = Grads[j](0, 0);
        BT(j, 1) = B(1, j) = Grads[j](1, 1);
        BT(j, 2) = B(2, j) = Grads[j](2, 2);
        BT(j, 3) = B(3, j) = Grads[j](0, 1) + Grads[j](1, 0);
        BT(j, 4) = B(4, j) = Grads[j](1, 2) + Grads[j](2, 1);
        BT(j, 5) = B(5, j) = Grads[j](0, 2) + Grads[j](2, 0);
      }
      BTH.setAll(0.);
      BTH.gemm(BT, H);
      m.gemm(BTH, B, weight * detJ, 1.);
    }
  }
  else
  {
    int nbFF1 = BilinearTerm<SVector3, SVector3>::space1.getNumKeys(ele);
    int nbFF2 = BilinearTerm<SVector3, SVector3>::space2.getNumKeys(ele);
    double jac[3][3];
    fullMatrix<double> B(6, nbFF2);
    fullMatrix<double> BTH(nbFF2, 6);
    fullMatrix<double> BT(nbFF1, 6);
    m.resize(nbFF1, nbFF2);
    m.setAll(0.);
    // Sum on Gauss Points i
    for(int i = 0; i < npts; i++)
    {
      const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
      const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
      std::vector<TensorialTraits<SVector3>::GradType> Grads;// tableau de matrices...
      std::vector<TensorialTraits<SVector3>::GradType> GradsT;// tableau de matrices...
      BilinearTerm<SVector3, SVector3>::space1.gradf(ele, u, v, w, Grads);
      BilinearTerm<SVector3, SVector3>::space2.gradf(ele, u, v, w, GradsT);
      for(int j = 0; j < nbFF1; j++)
      {
        BT(j, 0) = Grads[j](0, 0);
        BT(j, 1) = Grads[j](1, 1);
        BT(j, 2) = Grads[j](2, 2);
        BT(j, 3) = Grads[j](0, 1) + Grads[j](1, 0);
        BT(j, 4) = Grads[j](1, 2) + Grads[j](2, 1);
        BT(j, 5) = Grads[j](0, 2) + Grads[j](2, 0);
      }
      for(int j = 0; j < nbFF2; j++)
      {
        B(0, j) = GradsT[j](0, 0);
        B(1, j) = GradsT[j](1, 1);
        B(2, j) = GradsT[j](2, 2);
        B(3, j) = GradsT[j](0, 1) + GradsT[j](1, 0);
        B(4, j) = GradsT[j](1, 2) + GradsT[j](2, 1);
        B(5, j) = GradsT[j](0, 2) + GradsT[j](2, 0);
      }
      BTH.setAll(0.);
      BTH.gemm(BT, H);
      // gemm add the product to m so there is a sum on gauss' points here
      m.gemm(BTH, B, weight * detJ, 1.);
    }
  }
}

void LagrangeMultiplierTerm::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const
{
  int nbFF1 = BilinearTerm<SVector3, double>::space1.getNumKeys(ele); //nbVertices*nbcomp of parent
  int nbFF2 = BilinearTerm<SVector3, double>::space2.getNumKeys(ele); //nbVertices of boundary
  double jac[3][3];
  m.resize(nbFF1, nbFF2);
  m.setAll(0.);
  for(int i = 0; i < npts; i++)
  {
    double u = GP[i].pt[0]; double v = GP[i].pt[1]; double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    std::vector<TensorialTraits<SVector3>::ValType> Vals;
    std::vector<TensorialTraits<double>::ValType> ValsT;
    BilinearTerm<SVector3,double>::space1.f(ele, u, v, w, Vals);
    BilinearTerm<SVector3,double>::space2.f(ele, u, v, w, ValsT);
    for(int j = 0; j < nbFF1; j++)
    {
      for(int k = 0; k < nbFF2; k++)
      {
        m(j, k) += dot(Vals[j], _d) * ValsT[k] * weight * detJ;
      }
    }
  }
}

void LagMultTerm::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const
{
  int nbFF1 = BilinearTerm<SVector3, SVector3>::space1.getNumKeys(ele); //nbVertices*nbcomp of parent
  int nbFF2 = BilinearTerm<SVector3, SVector3>::space2.getNumKeys(ele); //nbVertices of boundary
  double jac[3][3];
  m.resize(nbFF1, nbFF2);
  m.setAll(0.);
  for(int i = 0; i < npts; i++) 
  {
    double u = GP[i].pt[0]; double v = GP[i].pt[1]; double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    std::vector<TensorialTraits<SVector3>::ValType> Vals;
    std::vector<TensorialTraits<SVector3>::ValType> ValsT;
    BilinearTerm<SVector3,SVector3>::space1.f(ele, u, v, w, Vals);
    BilinearTerm<SVector3,SVector3>::space2.f(ele, u, v, w, ValsT);
    for(int j = 0; j < nbFF1; j++)
    {
      for(int k = 0; k < nbFF2; k++)
      {
        m(j, k) += _eqfac * dot(Vals[j], ValsT[k]) * weight * detJ;
      }
    }
  }
}


