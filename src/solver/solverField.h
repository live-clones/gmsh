// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Eric Bechet
//

#ifndef SOLVERFIELD_H
#define SOLVERFIELD_H

#include <vector>
#include <iostream>
#include "MElement.h"
#include "dofManager.h"
#include "functionSpace.h"

template <class T>
class SolverField
  : public FunctionSpace<T> // being able to use it instead of a real function
                            // space is interesting (nbkeys=1, explicit
                            // keys/dofs undefined (or could be defined
                            // element-wise )
{
public:
  typedef typename TensorialTraits<T>::ValType ValType;
  typedef typename TensorialTraits<T>::GradType GradType;
  typedef typename TensorialTraits<T>::HessType HessType;

private:
  dofManager<double> *dm;
  FunctionSpace<T> *fs;

public:
  SolverField(dofManager<double> *dm_, FunctionSpace<T> *fs_) : dm(dm_), fs(fs_)
  {
  }
  virtual int getNumKeys(MVertex *ver) const { return 1; }
  virtual int getNumKeys(MElement *ele) const { return 1; }

private:
  virtual void getKeys(MElement *ele, std::vector<Dof> &keys) const
  {
    Msg::Error("getKeys for SolverField shouldn't be called");
  }
  virtual void getKeys(MVertex *ver, std::vector<Dof> &keys) const
  {
    Msg::Error("getKeys for SolverField shouldn't be called");
  }

public:
  virtual void f(MElement *ele, double u, double v, double w,
                 ValType &val) const
  {
    std::vector<Dof> D;
    std::vector<ValType> SFVals;
    std::vector<double> DMVals;
    fs->getKeys(ele, D);
    dm->getDofValue(D, DMVals);
    fs->f(ele, u, v, w, SFVals);
    val = ValType();
    for(std::size_t i = 0; i < D.size(); ++i) val += SFVals[i] * DMVals[i];
  }

  virtual void f(MElement *ele, double u, double v, double w,
                 std::vector<ValType> &vals) const
  {
    ValType val;
    f(ele, u, v, w, val);
    vals.push_back(val);
  }

  virtual void gradf(MElement *ele, double u, double v, double w,
                     GradType &grad) const
  {
    std::vector<Dof> D;
    std::vector<GradType> SFGrads;
    std::vector<double> DMVals;
    fs->getKeys(ele, D);
    dm->getDofValue(D, DMVals);
    fs->gradf(ele, u, v, w, SFGrads);
    grad = GradType();
    for(std::size_t i = 0; i < D.size(); ++i) grad += SFGrads[i] * DMVals[i];
  }

  // A quoi sert cette fonction ?? (Evalue le hessien au noeuds
  /*  virtual void hessf(MElement *ele, double u, double v, double w, HessType
  &hess)
    {
      // Pas besoin des dof etc
  //    std::vector<Dof> D;
      std::vector<HessType> SFHess;
  //    std::vector<double> DMVals;
  //    fs->getKeys(ele, D);
  //    dm->getDofValue(D, DMVals);
      fs->hessf(ele, u, v, w, SFHess);

  //    hess = HessType;
  //    for (int i = 0; i < D.size(); ++i)
  //      hess += SFHess[i] * DMVals[i];
    }*/

  virtual void gradf(MElement *ele, double u, double v, double w,
                     std::vector<GradType> &grads) const
  {
    GradType grad;
    gradf(ele, u, v, w, grad);
    grads.push_back(grad);
  }
  virtual void hessfuvw(MElement *ele, double u, double v, double w,
                        std::vector<HessType> &hess) const
  {
    // HessType hes;
    fs->hessfuvw(ele, u, v, w, hess);
  }
};

/*

class Formulation
{
  std::vector<FunctionSpace<double>* > scalarfs;
  std::vector<FunctionSpace<SVector3>* > vectorfs;
  std::vector<groupOfElements* > groups;
  std::vector<std::pair<MElement*, std::vector<groupOfElements&> > > links;
  dofManager<double> *dm; //

};
*/

#endif //_SOLVERFIELD_H_
