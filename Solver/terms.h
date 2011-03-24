//
// C++ Interface: terms
//
// Description:
//
//
// Author:  <Eric Bechet>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _TERMS_H_
#define _TERMS_H_

#include "SVector3.h"
#include "STensor3.h"
#include "STensor43.h"
#include "Numeric.h"
#include "functionSpace.h"
#include "groupOfElements.h"
#include "materialLaw.h"
#include <vector>
#include <iterator>

template<class T2> class ScalarTermBase;

template<class T2> class LinearTermBase;
template<class T2> class  PlusTerm;

class  BilinearTermBase;

inline double dot(const double &a, const double &b)
{
  return a * b;
}

inline int delta(int i,int j) {if (i==j) return 1; else return 0;}




template<class T2=double> class  ScalarTermBase
{
public :
  virtual ~ScalarTermBase() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, T2 &val) const = 0 ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<T2> &vval) const = 0 ;
  virtual ScalarTermBase<T2>* clone () const =0;
};

template<class T2=double> class ScalarTerm : public ScalarTermBase<T2>
{
public :
  virtual ~ScalarTerm() {}
};


template<class T2=double> class ScalarTermConstant : public ScalarTerm<T2>
{
protected:
  T2 cst;
public :
  ScalarTermConstant(T2 val_ = T2()) : cst(val_) {}
  virtual ~ScalarTermConstant() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, T2 &val) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<T2> &vval) const;
  virtual void get(MVertex *ver, T2 &val) const;
  virtual ScalarTermBase<T2>* clone () const {return new ScalarTermConstant<T2>(cst);}
};

class BilinearTermToScalarTerm : public ScalarTerm<double>
{
protected:
  BilinearTermBase &bilterm;
public :
  BilinearTermToScalarTerm(BilinearTermBase &bilterm_): bilterm(bilterm_){}
  virtual ~BilinearTermToScalarTerm() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, double &val) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<double> &vval) const {};
  virtual ScalarTermBase<double>* clone () const {return new BilinearTermToScalarTerm(bilterm);}
};



class  BilinearTermBase
{
public :
  virtual ~BilinearTermBase() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const  ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const = 0  ;
  virtual BilinearTermBase* clone () const =0;
};


template<class T2> class BilinearTermContract : public BilinearTermBase
{
protected:
  const LinearTermBase<T2> *a;
  const LinearTermBase<T2> *b;
public:
  BilinearTermContract(const LinearTermBase<T2> &a_,const LinearTermBase<T2> &b_) : a(a_.clone()),b(b_.clone()) {}
  virtual ~BilinearTermContract() {delete a;delete b;}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const {};
  virtual BilinearTermBase* clone () const {return new BilinearTermContract<T2>(*a,*b);}
};

template<class T2> class BilinearTermContractWithLaw : public  BilinearTermContract<T2>
{
public:
protected:
  const ScalarTermBase< typename TensorialTraits<T2>::TensProdType > *c;
public:
  BilinearTermContractWithLaw(const LinearTermBase<T2> &a_,const ScalarTermBase<typename TensorialTraits<T2>::TensProdType> &c_, const LinearTermBase<T2> &b_) : BilinearTermContract<T2>(a_,b_), c(c_.clone()) {}
  virtual ~BilinearTermContractWithLaw() {delete c;}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const ;
  virtual BilinearTermBase* clone () const {return new BilinearTermContractWithLaw<T2>(*BilinearTermContract<T2>::a,*c,*BilinearTermContract<T2>::b);}
};

template<class T2> BilinearTermContract<T2> operator |(const LinearTermBase<T2>& L1,const LinearTermBase<T2>& L2);


template<class T1,class T2> class BilinearTerm : public BilinearTermBase
{
protected :
  FunctionSpace<T1>& space1;
  FunctionSpace<T2>& space2;
public :
  BilinearTerm(FunctionSpace<T1>& space1_, FunctionSpace<T2>& space2_) : space1(space1_), space2(space2_) {}
  virtual ~BilinearTerm() {}
};

template<class T2=double> class  LinearTermBase
{
public:
  virtual ~LinearTermBase() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<T2> &v) const ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<T2> > &vv) const =0;
  virtual LinearTermBase<T2>* clone () const = 0;
  PlusTerm<T2> operator +(const LinearTermBase<T2>& other);
};


template<class T2> class  PlusTerm:public LinearTermBase<T2>
{
  const LinearTermBase<T2> *a;
  const LinearTermBase<T2> *b;
public:
  PlusTerm(const LinearTermBase<T2> &a_,const LinearTermBase<T2> &b_) : a(a_.clone()),b(b_.clone()) {}
  virtual ~PlusTerm() {delete a;delete b;}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<T2> &v) const ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<T2> > &vv) const {};
  virtual LinearTermBase<T2>* clone () const { return new PlusTerm<T2>(*a,*b);}
};


template<class T1, class T2=double> class LinearTerm : public LinearTermBase<T2>
{
protected :
  FunctionSpace<T1>& space1;
public :
  LinearTerm(FunctionSpace<T1>& space1_) : space1(space1_) {}
  virtual ~LinearTerm() {}
};



template<class T1> class GradTerm : public LinearTerm<T1, typename TensorialTraits<T1>::GradType >
{
public :
  GradTerm(FunctionSpace<T1>& space1_) : LinearTerm<T1,typename TensorialTraits<T1>::GradType >(space1_) {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<typename TensorialTraits<T1>::GradType > &vec) const {LinearTermBase<typename TensorialTraits<T1>::GradType>::get(ele,npts,GP,vec);}
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<typename TensorialTraits<T1>::GradType > > &vvec) const;
  virtual LinearTermBase<typename TensorialTraits<T1>::GradType>* clone () const { return new GradTerm<T1>(LinearTerm<T1,typename TensorialTraits<T1>::GradType>::space1);}
  virtual ~GradTerm() {}
};


template<class T1, class T2> class LaplaceTerm : public BilinearTerm<T1, T2>
{
public :
  LaplaceTerm(FunctionSpace<T1>& space1_, FunctionSpace<T2>& space2_) : BilinearTerm<T1, T2>(space1_, space2_)
  {}
  virtual ~LaplaceTerm() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const
  {
    Msg::Error("LaplaceTerm<S1, S2> w/ S1 != S2 not implemented");
  }
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector< fullMatrix<double> > &vm) const
  {
    Msg::Error("LaplaceTerm<S1, S2> w/ S1 != S2 not implemented");
  }
  virtual void get(MVertex *ver, fullMatrix<double> &m)
  {
    Msg::Error("LaplaceTerm<S1, S2> w/ S1 != S2 not implemented");
  }
  virtual BilinearTermBase* clone () const {return new LaplaceTerm< T1, T2 >(BilinearTerm<T1, T2>::space1,BilinearTerm<T1, T2>::space2);}
}; // class

template<class T1> class LaplaceTerm<T1, T1> : public BilinearTerm<T1, T1> // symmetric
{
protected:
  double diffusivity;
public :
  LaplaceTerm(FunctionSpace<T1>& space1_, double diff = 1) :
    BilinearTerm<T1, T1>(space1_, space1_), diffusivity(diff) {}
  virtual ~LaplaceTerm() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector< fullMatrix<double> > &vm) const{};
  virtual BilinearTermBase* clone () const {return new LaplaceTerm< T1, T1 >(BilinearTerm<T1, T1>::space1,diffusivity);}
}; // class

class IsotropicElasticTerm : public BilinearTerm<SVector3,SVector3>
{
protected :
  double E, nu;
  bool sym;
  fullMatrix<double> H;/* =
    { {C11, C12, C12,    0,   0,   0},
      {C12, C11, C12,    0,   0,   0},
      {C12, C12, C11,    0,   0,   0},
      {  0,   0,   0,  C44,   0,   0},
      {  0,   0,   0,    0, C44,   0},
      {  0,   0,   0,    0,   0, C44} };*/
public :
  IsotropicElasticTerm(FunctionSpace<SVector3>& space1_, FunctionSpace<SVector3>& space2_, double E_, double nu_);
  IsotropicElasticTerm(FunctionSpace<SVector3>& space1_, double E_, double nu_);
  virtual ~IsotropicElasticTerm() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector< fullMatrix<double> > &vm) const{};
  virtual BilinearTermBase* clone () const {return new IsotropicElasticTerm(BilinearTerm<SVector3, SVector3>::space1,BilinearTerm<SVector3, SVector3>::space2,E,nu);}
}; // class


template<class T1> class LoadTerm : public LinearTerm<T1>
{
protected:
  simpleFunction<typename TensorialTraits<T1>::ValType> &Load;
public :
  LoadTerm(FunctionSpace<T1>& space1_, simpleFunction<typename TensorialTraits<T1>::ValType> &Load_) :
      LinearTerm<T1>(space1_), Load(Load_) {}
  virtual ~LoadTerm() {}
  virtual LinearTermBase<double>* clone () const { return new LoadTerm<T1>(LinearTerm<T1>::space1,Load);}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<double> &m) const ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<double> > &vv) const {};
};

class LagrangeMultiplierTerm : public BilinearTerm<SVector3, double>
{
  SVector3 _d;
public :
  LagrangeMultiplierTerm(FunctionSpace<SVector3>& space1_, FunctionSpace<double>& space2_, const SVector3 &d) :
      BilinearTerm<SVector3, double>(space1_, space2_)
  {
    for (int i = 0; i < 3; i++) _d(i) = d(i);
  }
  virtual ~LagrangeMultiplierTerm() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector< fullMatrix<double> > &vm) const{};
  virtual BilinearTermBase* clone () const {return new LagrangeMultiplierTerm(BilinearTerm<SVector3, double>::space1,BilinearTerm<SVector3, double>::space2,_d);}
};

class LagMultTerm : public BilinearTerm<SVector3, SVector3>
{
private :
  double _eqfac;
public :
  LagMultTerm(FunctionSpace<SVector3>& space1_, FunctionSpace<SVector3>& space2_, double eqfac = 1.0) :
      BilinearTerm<SVector3, SVector3>(space1_, space2_), _eqfac(eqfac) {}
  virtual ~LagMultTerm() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector< fullMatrix<double> > &vm) const{};
  virtual BilinearTermBase* clone () const {return new LagMultTerm(BilinearTerm<SVector3, SVector3>::space1,BilinearTerm<SVector3, SVector3>::space2,_eqfac);}
};

template<class T1> class LoadTermOnBorder : public LinearTerm<T1>
{
private :
  double _eqfac;
  simpleFunction<typename TensorialTraits<T1>::ValType> &Load;
public :
  LoadTermOnBorder(FunctionSpace<T1>& space1_, simpleFunction<typename TensorialTraits<T1>::ValType> &Load_, double eqfac = 1.0) :
      LinearTerm<T1>(space1_), _eqfac(eqfac), Load(Load_) {}
  virtual ~LoadTermOnBorder() {}
  virtual LinearTermBase<double>* clone () const { return new LoadTermOnBorder<T1>(LinearTerm<T1>::space1,Load,_eqfac);}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<double> &m) const ;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<double> > &vv) const {};
};

#include "terms.hpp"

#endif// _TERMS_H_
