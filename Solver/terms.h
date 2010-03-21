//
// C++ Interface: terms
//
// Description:
//
//
// Author:  <Eric Bechet>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _TERMS_H_
#define _TERMS_H_

#include "SVector3.h"
#include <vector>
#include <iterator>
#include "Numeric.h"
#include "functionSpace.h"
#include "groupOfElements.h"
#include "materialLaw.h"
#include "../contrib/cm3/MInterfaceElement.h"
class  BilinearTermBase
{
 public :
  virtual ~BilinearTermBase() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m) = 0 ;
  virtual void getInter(MInterfaceElement *iele,int npts,IntPt *GP,fullMatrix<double> &m){} ;
  virtual void getInterForce(MInterfaceElement *iele,int npts,IntPt *GP,const fullMatrix<double> &disp,fullMatrix<double> &m){} ;
  virtual void getForce(MElement *ele,int npts,IntPt *GP,const fullMatrix<double> &disp, fullMatrix<double> &m){}
  virtual void getInterOnBoundary(MInterfaceElement *iele,int npts,IntPt *GP,fullMatrix<double> &m){}
  virtual void getInterForceOnBoundary(MInterfaceElement *iele,int npts,IntPt *GP,const fullMatrix<double> &disp,fullMatrix<double> &m){} ;
};

template<class T1,class T2> class BilinearTerm : public BilinearTermBase
{
 protected :
  FunctionSpace<T1>& space1;
  FunctionSpace<T2>& space2;
 public :
  BilinearTerm(FunctionSpace<T1>& space1_,FunctionSpace<T1>& space2_) : space1(space1_),space2(space2_) {}
  virtual ~BilinearTerm() {}
};

class  LinearTermBase
{
  public:
  virtual ~LinearTermBase() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullVector<double> &v) =0;
};

template<class T1> class LinearTerm : public LinearTermBase
{
 protected :
  FunctionSpace<T1>& space1;
 public :
  LinearTerm(FunctionSpace<T1>& space1_) : space1(space1_) {}
  virtual ~LinearTerm() {}
};

class  ScalarTermBase
{
 public :
  virtual ~ScalarTermBase() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,double &val) =0;
};

class ScalarTerm : public ScalarTermBase
{
 public :
  virtual ~ScalarTerm() {}
};


template<class T1,class T2> class BilinearTermToScalarTerm : public ScalarTerm
{
  BilinearTerm<T1,T2> &bilterm;
  public :
  BilinearTermToScalarTerm(BilinearTerm<T1,T2> &bilterm_): bilterm(bilterm_){}
  virtual ~BilinearTermToScalarTerm() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,double &val)
  {
    fullMatrix<double> localMatrix;
    bilterm.get(ele,npts,GP,localMatrix);
    val=localMatrix(0,0);
  }
};


class ScalarTermConstant : public ScalarTerm
{
  double val;
 public :
  ScalarTermConstant(double val_=1.0): val(val_) {}
  virtual ~ScalarTermConstant() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,double &val)
  {
    double jac[3][3];
    val=0;
    for (int i = 0; i < npts; i++)
    {
      const double u = GP[i].pt[0];const double v = GP[i].pt[1];const double w = GP[i].pt[2];
      const double weight = GP[i].weight;const double detJ = ele->getJacobian(u, v, w, jac);
      val+=weight*detJ;
    }
  }
  virtual void get(MVertex *ver,double &val)
  {
      val=1;
  }
};



template<class T1,class T2> class LaplaceTerm : public BilinearTerm<T1,T2>
{
 public :
  LaplaceTerm(FunctionSpace<T1>& space1_,FunctionSpace<T2>& space2_) : BilinearTerm<T1,T2>(space1_,space2_)
  {}
  virtual ~LaplaceTerm() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m)
  {
    Msg::Error("LaplaceTerm<S1,S2> w/ S1!=S2 not implemented");
  }
  virtual void get(MVertex *ver,fullMatrix<double> &m)
  {
    Msg::Error("LaplaceTerm<S1,S2> w/ S1!=S2 not implemented");
  }
}; // class



template<class T1> class LaplaceTerm<T1,T1> : public BilinearTerm<T1,T1> // symmetric
{
 public :
  LaplaceTerm(FunctionSpace<T1>& space1_) : BilinearTerm<T1,T1>(space1_,space1_)
  {}
  virtual ~LaplaceTerm() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m)
  {
    int nbFF = BilinearTerm<T1,T1>::space1.getNumKeys(ele);
    double jac[3][3];
    m.resize(nbFF, nbFF);
    m.setAll(0.);
    for (int i = 0; i < npts; i++)
    {
      const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
      const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
      std::vector<typename TensorialTraits<T1>::GradType> Grads;
      BilinearTerm<T1,T1>::space1.gradf(ele,u, v, w, Grads);
      for (int j = 0; j < nbFF; j++)
      {
        for (int k = j; k < nbFF; k++)
        {
          double contrib=weight * detJ * dot(Grads[j],Grads[k]);
          m(j,k)+=contrib;
          if (j!=k) m(k,j)+=contrib;
        }
      }
    }
//    m.print("");
//    exit(0);
  }
}; // class




class IsotropicElasticTerm : public BilinearTerm<SVector3,SVector3>
{
 protected :
  double E,nu;
  bool sym;
  fullMatrix<double> H;/* =
    { {C11, C12, C12,    0,   0,   0},
      {C12, C11, C12,    0,   0,   0},
      {C12, C12, C11,    0,   0,   0},
      {  0,   0,   0,  C44,   0,   0},
      {  0,   0,   0,    0, C44,   0},
      {  0,   0,   0,    0,   0, C44} };*/

 public :
  IsotropicElasticTerm(FunctionSpace<SVector3>& space1_,FunctionSpace<SVector3>& space2_,double E_,double nu_) : BilinearTerm<SVector3,SVector3>(space1_,space2_),E(E_),nu(nu_),H(6,6)
  {
    double FACT = E / (1 + nu);
    double C11 = FACT * (1 - nu) / (1 - 2 * nu);
    double C12 = FACT * nu / (1 - 2 * nu);
    double C44 = (C11 - C12) / 2;
    H.scale(0.);
    for (int i=0;i<3;++i) {H(i,i)=C11;H(i+3,i+3)=C44;}
    H(1,0)=H(0,1)=H(2,0)=H(0,2)=H(1,2)=H(2,1)=C12;
    sym=(&space1_==&space2_);
  }
  IsotropicElasticTerm(FunctionSpace<SVector3>& space1_,double E_,double nu_) : BilinearTerm<SVector3,SVector3>(space1_,space1_),E(E_),nu(nu_),H(6,6)
  {
    double FACT = E / (1 + nu);
    double C11 = FACT * (1 - nu) / (1 - 2 * nu);
    double C12 = FACT * nu / (1 - 2 * nu);
    double C44 = (C11 - C12) / 2;
    H.scale(0.);
    for (int i=0;i<3;++i) {H(i,i)=C11;H(i+3,i+3)=C44;}
    H(1,0)=H(0,1)=H(2,0)=H(0,2)=H(1,2)=H(2,1)=C12;
    sym=true;
  }
  virtual ~IsotropicElasticTerm() {}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<double> &m)
  {
    if (sym)
    {
      int nbFF = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(ele);
      double jac[3][3];
      fullMatrix<double> B(6, nbFF);
      fullMatrix<double> BTH(nbFF, 6);
      fullMatrix<double> BT(nbFF, 6);
      printf("npts : %d\n",npts);
      m.resize(nbFF, nbFF);
      m.setAll(0.);
      std::cout << m.size1() << "  " << m.size2() << std::endl;
      for (int i = 0; i < npts; i++)
      {
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        if (ele->getParent()) ele=ele->getParent();
        const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
        std::vector<TensorialTraits<SVector3>::GradType> Grads;
        BilinearTerm<SVector3,SVector3>::space1.gradf(ele,u, v, w, Grads); // a optimiser ??
        for (int j = 0; j < nbFF; j++)
        {
          BT(j, 0) = B(0, j) = Grads[j](0,0);
          BT(j, 1) = B(1, j) = Grads[j](1,1);
          BT(j, 2) = B(2, j) = Grads[j](2,2);
          BT(j, 3) = B(3, j) = Grads[j](0,1)+Grads[j](1,0);
          BT(j, 4) = B(4, j) = Grads[j](1,2)+Grads[j](2,1);
          BT(j, 5) = B(5, j) = Grads[j](0,2)+Grads[j](2,0);
        }
        BTH.setAll(0.);
        BTH.gemm(BT, H);
        m.gemm(BTH, B, weight * detJ, 1.);
      }
    }
    else
    {
      int nbFF1 = BilinearTerm<SVector3,SVector3>::space1.getNumKeys(ele);
      int nbFF2 = BilinearTerm<SVector3,SVector3>::space2.getNumKeys(ele);
      double jac[3][3];
      fullMatrix<double> B(6, nbFF2);
      fullMatrix<double> BTH(nbFF2, 6);
      fullMatrix<double> BT(nbFF1, 6);
      m.resize(nbFF1, nbFF2);
      m.setAll(0.);
      // Sum on Gauss Points i
      for (int i = 0; i < npts; i++)
      {
        const double u = GP[i].pt[0]; const double v = GP[i].pt[1]; const double w = GP[i].pt[2];
        const double weight = GP[i].weight; const double detJ = ele->getJacobian(u, v, w, jac);
        std::vector<TensorialTraits<SVector3>::GradType> Grads;// tableau de matrices...
        std::vector<TensorialTraits<SVector3>::GradType> GradsT;// tableau de matrices...
        BilinearTerm<SVector3,SVector3>::space1.gradf(ele,u, v, w, Grads);
        BilinearTerm<SVector3,SVector3>::space2.gradf(ele,u, v, w, GradsT);
        for (int j = 0; j < nbFF1; j++)
        {
          BT(j, 0) = Grads[j](0,0);
          BT(j, 1) = Grads[j](1,1);
          BT(j, 2) = Grads[j](2,2);
          BT(j, 3) = Grads[j](0,1)+Grads[j](1,0);
          BT(j, 4) = Grads[j](1,2)+Grads[j](2,1);
          BT(j, 5) = Grads[j](0,2)+Grads[j](2,0);
        }
        for (int j = 0; j < nbFF2; j++)
        {
          B(0, j) = GradsT[j](0,0);
          B(1, j) = GradsT[j](1,1);
          B(2, j) = GradsT[j](2,2);
          B(3, j) = GradsT[j](0,1)+GradsT[j](1,0);
          B(4, j) = GradsT[j](1,2)+GradsT[j](2,1);
          B(5, j) = GradsT[j](0,2)+GradsT[j](2,0);
        }
        BTH.setAll(0.);
        BTH.gemm(BT, H);
        // gemm add the product to m so there is a sum on gauss' points here
        m.gemm(BTH, B, weight * detJ, 1.);
      }
    }
  }
}; // class

inline double dot(const double &a, const double &b)
{ return a*b; }


template<class T1> class LoadTerm : public LinearTerm<T1>
{
  simpleFunction<typename TensorialTraits<T1>::ValType> &Load;
 public :
  LoadTerm(FunctionSpace<T1>& space1_,simpleFunction<typename TensorialTraits<T1>::ValType> &Load_) :LinearTerm<T1>(space1_),Load(Load_) {}
  virtual ~LoadTerm() {}

  virtual void get(MElement *ele,int npts,IntPt *GP,fullVector<double> &m)
  {
    double nbFF=LinearTerm<T1>::space1.getNumKeys(ele);
    double jac[3][3];
    m.resize(nbFF);
    m.scale(0.);
    for (int i = 0; i < npts; i++)
    {
      const double u = GP[i].pt[0];const double v = GP[i].pt[1];const double w = GP[i].pt[2];
      const double weight = GP[i].weight;const double detJ = ele->getJacobian(u, v, w, jac);
      std::vector<typename TensorialTraits<T1>::ValType> Vals;
      LinearTerm<T1>::space1.f(ele,u, v, w, Vals);
      SPoint3 p;
      ele->pnt(u, v, w, p);
      typename TensorialTraits<T1>::ValType load=Load(p.x(),p.y(),p.z());
      for (int j = 0; j < nbFF ; ++j)
      {
        m(j)+=dot(Vals[j],load)*weight*detJ;
      }
    }
  }
};




#endif// _TERMS_H_
