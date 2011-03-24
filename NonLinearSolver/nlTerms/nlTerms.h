//
// C++ Interface: terms
//
// Description: Basic term for non linear solver
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef NONLINEARTERMS_H_
#define NONLINEARTERMS_H_
// lineartermBase and Bilinear term base are not be able
// to take easily into account a perturbation of the unknown field
// It leads to a very poorly efficient computation of matrix by perturbation
// I change the basis class for this reason ALL assemble functions have to be "duplicated"
#include "terms.h"
class unknownField;
class IPField;
class partDomain;
class  BiNonLinearTermBase : public BilinearTermBase
{
 public :
  virtual ~BiNonLinearTermBase() {}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m) = 0;
  virtual void set(const fullVector<double> *datafield) = 0 ;
  virtual const bool isData() const=0; // if true use this get function otherwise uses classical get
};

// Void term to avoid segmentation fault on domain for pure interface domain (Assemble on element)
class BilinearTermVoid : public BilinearTermBase
{
 public:
  virtual ~BilinearTermVoid(){}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullMatrix<double> &m){};
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const{}
  virtual BilinearTermBase* clone () const
  {
    return new BilinearTermVoid();
  }
};

template<class T2=double> class  nonLinearTermBase : public LinearTermBase<T2>
{
 protected:
  bool inverseSign; // has to be disappeared when solver is written with fext and fint
 public:
  nonLinearTermBase() : inverseSign(false){}
  virtual ~nonLinearTermBase(){}
//  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<T2> &v);
  virtual void set(const fullVector<double> *datafield) = 0;
  virtual const bool isData() const=0; // if true use this get function otherwise uses classical get
  void invSign(){inverseSign ? inverseSign = false : inverseSign = true;} // has to dissappear
};

// Void term to avoid segmentation fault on domain for pure interface domain (Assemble on element)
class LinearTermVoid : public LinearTermBase<double>
{
public:
  virtual ~LinearTermVoid(){}
  virtual void get(MElement *ele, int npts, IntPt *GP, fullVector<double> &v) const{};
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullVector<double> > &vv) const{}
  virtual LinearTermBase<double>* clone () const
  {
    return new LinearTermVoid();
  }
};

// BiNonLinear term by perturbation via nonLinearterm
template <class T2=double> class BilinearTermPerturbation : public BilinearTermBase{
 protected:
  nonLinearTermBase<T2> *_nlterm;
  FunctionSpaceBase &space1;
  FunctionSpaceBase &space2;
  unknownField *_ufield;
  partDomain *_dom;
  IPField *_ipf;
  const double _eps;
  const double _twoeps;
  const double _onedivtwoeps;
 private:
  mutable fullVector<double> dispm;
  mutable fullVector<double> dispp;
  mutable fullVector<double> disp;
  mutable fullVector<double> fm;
  mutable fullVector<double> fp;
 public:
  BilinearTermPerturbation(LinearTermBase<T2> *lterm, FunctionSpaceBase &sp1, FunctionSpaceBase &sp2,
                       unknownField *ufield, IPField *ipf, partDomain *dom,
                       const double pert=1e-8) : space1(sp1), space2(sp2), _nlterm(dynamic_cast<nonLinearTermBase<T2>*>(lterm)),
                                                   _ufield(ufield), _dom(dom),
                                                   _ipf(ipf), _eps(pert), _twoeps(pert+pert),
                                                   _onedivtwoeps(1./(pert+pert)){}
  ~BilinearTermPerturbation(){}
  virtual void get(MElement *ele,int npts,IntPt *GP,fullMatrix<T2> &m) const;
  virtual void get(MElement *ele, int npts, IntPt *GP, std::vector<fullMatrix<double> > &mv) const
  {
    Msg::Error("Define me ?? get without integration BilinearTermPerturbation");
  }
  virtual BilinearTermBase* clone () const
  {
    return new BilinearTermPerturbation<T2>(_nlterm,space1,space2,_ufield,_ipf,_dom,_eps);
  }
};

#endif // NONLINEARTERMS_H_

