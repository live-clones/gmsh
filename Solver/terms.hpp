//
// C++ Template Implementations: terms
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

template<class T2> void LinearTermBase<T2>::get(MElement *ele, int npts, IntPt *GP, fullVector<T2> &vec) const
{
  std::vector<fullVector<T2> > vv;
  vv.resize(npts);
  get(ele,npts,GP,vv);
  int nbFF=vv[0].size();
  vec.resize(nbFF);
  vec.setAll(T2());
  double jac[3][3];
  for(int i = 0; i < npts; i++)
  {
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    for(int j = 0; j < nbFF; j++)
    {
      double contrib = weight * detJ;
      vec(j) += contrib*vv[i](j);
    }
  }
}

template<class T2> void PlusTerm<T2>::get(MElement *ele, int npts, IntPt *GP, fullVector<T2> &v) const 
{
  fullVector<T2> v2;
  a->get(ele,npts,GP,v);
  b->get(ele,npts,GP,v2);
  for (int i=0;i<v2.size();++i) v(i)+=v2(i);
}

template<class T2> void ScalarTermConstant<T2>::get(MElement *ele, int npts, IntPt *GP, T2 &val) const
{
  double jac[3][3];
  double eval = 0;
  for(int i = 0; i < npts; i++)
  {
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    eval += weight * detJ;
  }
  val=cst * eval;
}

template<class T2> void ScalarTermConstant<T2>::get(MElement *ele, int npts, IntPt *GP, std::vector<T2> &vval) const
{
  for(int i = 0; i < npts; i++)
  {
    vval[i] = cst;
  }
}

template<class T2> void ScalarTermConstant<T2>::get(MVertex *ver, T2 &val) const
{
    val = cst;
}

template<class T1> void LaplaceTerm<T1, T1>::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const
{
  int nbFF = BilinearTerm<T1, T1>::space1.getNumKeys(ele);
  double jac[3][3];
  m.resize(nbFF, nbFF);
  m.setAll(0.);
  for(int i = 0; i < npts; i++){
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    std::vector<typename TensorialTraits<T1>::GradType> Grads;
    BilinearTerm<T1, T1>::space1.gradf(ele, u, v, w, Grads);
    for(int j = 0; j < nbFF; j++)
    {
      for(int k = j; k < nbFF; k++)
      {
        double contrib = weight * detJ * dot(Grads[j], Grads[k]) * diffusivity;
        m(j, k) += contrib;
        if(j != k) m(k, j) += contrib;
      }
    }
  }
}

template<class T1> void LoadTerm<T1>::get(MElement *ele, int npts, IntPt *GP, fullVector<double> &m) const 
{
  if(ele->getParent()) ele = ele->getParent();
  int nbFF = LinearTerm<T1>::space1.getNumKeys(ele);
  double jac[3][3];
  m.resize(nbFF);
  m.scale(0.);
  for(int i = 0; i < npts; i++){
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    std::vector<typename TensorialTraits<T1>::ValType> Vals;
    LinearTerm<T1>::space1.f(ele, u, v, w, Vals);
    SPoint3 p;
    ele->pnt(u, v, w, p);
    typename TensorialTraits<T1>::ValType load = Load(p.x(), p.y(), p.z());
    for(int j = 0; j < nbFF ; ++j)
    {
      m(j) += dot(Vals[j], load) * weight * detJ;
    }
  }
}

template<class T2> BilinearTermContract<T2> operator |(const LinearTermBase<T2>& L1,const LinearTermBase<T2>& L2)
{
  return BilinearTermContract<T2>(L1,L2);
}

template<class T2> void BilinearTermContract<T2>::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const 
{
  fullVector<T2> va;
  fullVector<T2> vb;
  a->get(ele,npts,GP,va);
  b->get(ele,npts,GP,vb);
  m.resize(va.size(), vb.size());
  m.setAll(0.);
  for (int i=0;i<va.size();++i)
    for (int j=0;j<vb.size();++j)
      m(i,j)=dot(va(i),vb(j));
}


template<class T2> void BilinearTermContractWithLaw<T2>::get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const 
{
  BilinearTermBase::get(ele,npts,GP,m);
}
  
template<class T2> void BilinearTermContractWithLaw<T2>::get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const 
{
  std::vector<fullVector<T2> > va(npts);
  std::vector<fullVector<T2> > vb(npts);
  std::vector<typename TensorialTraits<T2>::TensProdType> tens(npts);
  BilinearTermContract<T2>::a->get(ele,npts,GP,va);
  BilinearTermContract<T2>::b->get(ele,npts,GP,vb);
  c->get(ele,npts,GP,tens);
  for (int k=0;k<npts;k++)
  {
    mv[k].resize(va[k].size(), vb[k].size());
    for (int i=0;i<va[k].size();++i)
      for (int j=0;j<vb[k].size();++j)
        mv[k](i,j)=dot(va[k](i),tens[k]*vb[k](j));
  }
}

template<class T2> PlusTerm<T2> LinearTermBase<T2>::operator +(const LinearTermBase<T2>& other)
{
  return PlusTerm<T2>(*this,other);
}
/*
template<class T1> void GradTerm<T1>::get(MElement *ele, int npts, IntPt *GP, fullVector<typename TensorialTraits<T1>::GradType > &vec) const 
{
  int nbFF = LinearTerm<T1,typename TensorialTraits<T1>::GradType>::space1.getNumKeys(ele);
  double jac[3][3];
  vec.resize(nbFF);
  vec.setAll(typename TensorialTraits<T1>::GradType());
  for(int i = 0; i < npts; i++)
  {
    std::vector<typename TensorialTraits<T1>::GradType> Grads;
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    LinearTerm<T1,typename TensorialTraits<T1>::GradType>::space1.gradf(ele, u, v, w, Grads);
    for(int j = 0; j < nbFF; j++)
    {
      double contrib = weight * detJ;
      vec(j) += contrib*Grads[j];
    }
  }
}
*/
template<class T1> void GradTerm<T1>::get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<typename TensorialTraits<T1>::GradType > > &vvec) const 
{
  int nbFF = LinearTerm<T1,typename TensorialTraits<T1>::GradType>::space1.getNumKeys(ele);
  for(int i = 0; i < npts; i++)
  {
    vvec[i].resize(nbFF);
    std::vector<typename TensorialTraits<T1>::GradType> Grads;
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    LinearTerm<T1,typename TensorialTraits<T1>::GradType>::space1.gradf(ele, u, v, w, Grads);
    for(int j = 0; j < nbFF; j++)
    {
      vvec[i](j) = Grads[j];
    }
  }
}



template<class T1> void LoadTermOnBorder<T1>::get(MElement *ele, int npts, IntPt *GP, fullVector<double> &m) const 
{
  MElement *elep;
  if (ele->getParent()) elep = ele->getParent();
  int nbFF = LinearTerm<T1>::space1.getNumKeys(ele);
  double jac[3][3];
  m.resize(nbFF);
  m.scale(0.);
  for(int i = 0; i < npts; i++)
  {
    const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
    const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
    std::vector<typename TensorialTraits<T1>::ValType> Vals;
    LinearTerm<T1>::space1.f(ele, u, v, w, Vals);
    SPoint3 p;
    ele->pnt(u, v, w, p);
    typename TensorialTraits<T1>::ValType load = Load(p.x(), p.y(), p.z());
    for(int j = 0; j < nbFF ; ++j){
      m(j) += _eqfac * dot(Vals[j], load) * weight * detJ;
    }
  }
}
