//
// C++ Interface: field
//
// Description: 
//
//
// Author:  <Eric Bechet>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//


#ifndef _SOLVERFIELD_H_
#define _SOLVERFIELD_H_

#include <vector>
#include <iostream>
#include "MElement.h"
#include "dofManager.h"
#include "functionSpace.h"

template<class T>
class SolverField : public FunctionSpace<T> // being able to use it instead of a real function space is interesting (nbkeys=1, dofs undefined (or could be defined by element-wise )
{
 public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
 private:
  dofManager<double> *dm;
  FunctionSpace<T> *fs;
 public:
  SolverField(dofManager<double> *dm_,  FunctionSpace<T> *fs_) : dm(dm_),fs(fs_) {}
  virtual int getNumKeys(MVertex *ver) { return 1;}
  virtual int getNumKeys(MElement *ele) { return 1;}
 private:
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) { Msg::Error("getKeys for SolverField should'nt be called");}
  virtual void getKeys(MVertex *ver, std::vector<Dof> &keys) {Msg::Error("getKeys for SolverField should'nt be called");}
 public:

  virtual void f(MVertex *ver, std::vector<ValType> &vals)
  {
    ValType val;
    f(ver,val);
    vals.push_back(val);
  }

  virtual void f(MVertex *ver, ValType &val)
  {
    std::vector<Dof> D;
    std::vector<ValType> SFVals;
    std::vector<double> DMVals;
    fs->getKeys(ver,D);
    dm->getDofValue(D,DMVals);
    fs->f(ver,SFVals);
    val=ValType();
    for (int i=0;i<D.size();++i)
      val+=SFVals[i]*DMVals[i];
  }

  virtual void f(MElement *ele, double u, double v, double w, ValType &val)
  {
    std::vector<Dof> D;
    std::vector<ValType> SFVals;
    std::vector<double> DMVals;
    fs->getKeys(ele,D);
    dm->getDofValue(D,DMVals);
    fs->f(ele,u,v,w,SFVals);
    val=ValType();
    for (int i=0;i<D.size();++i)
      val+=SFVals[i]*DMVals[i];
  }

  virtual void f(MElement *ele, double u, double v, double w, std::vector<ValType> &vals)
  {
    ValType val;
    f(ele,u,v,w,val);
    vals.push_back(val);
  }

  virtual void gradf(MElement *ele, double u, double v, double w,GradType &grad)
  {
    std::vector<Dof> D;
    std::vector<GradType> SFGrads;
    std::vector<double> DMVals;
    fs->getKeys(ele,D);
    dm->getDofValue(D,DMVals);
    fs->gradf(ele,u,v,w,SFGrads);
    grad=GradType();
    for (int i=0;i<D.size();++i)
      grad+= SFGrads[i] * DMVals[i];
  }

  virtual void gradf(MElement *ele, double u, double v, double w,std::vector<GradType> &grads)
  {
    GradType grad;
    gradf(ele,u,v,w,grad);
    grads.push_back(grad);
  }
};




/*

class Formulation
{
  std::vector<FunctionSpace<double>* > scalarfs;
  std::vector<FunctionSpace<SVector3>* > vectorfs;
  std::vector<groupOfElements* > groups;
  std::vector<std::pair<MElement*,std::vector<groupOfElements&> > > links;
  dofManager<double> *dm; // 

};
*/

#endif //_SOLVERFIELD_H_
