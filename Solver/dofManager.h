// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DOF_MANAGER_H_
#define _DOF_MANAGER_H_

#include <vector>
#include <string>
#include <complex>
#include <map>
#include "MVertex.h"
#include "linearSystem.h"
#include "fullMatrix.h"

#include <iostream>

class Dof{
 private:
  // v(x) = \sum_f \sum_i v_{fi} s^f_i(x)
  long int _entity; // "i": node, edge, group, etc.
  int _type; // "f": basis function type index, etc.
 public:
  Dof(long int entity, int type) : _entity(entity), _type(type) {}
  inline long int getEntity() const { return _entity; }
  inline int getType() const { return _type; }
  inline static int createTypeWithTwoInts(int i1, int i2)
  {
    return i1 + 10000 * i2;
  }
  inline static void getTwoIntsFromType(int t, int &i1, int &i2)
  {
    i1 = t % 10000;
    i2 = t / 10000;
  }
  bool operator < (const Dof &other) const
  {
    if(_entity < other._entity) return true;
    if(_entity > other._entity) return false;
    if(_type < other._type) return true;
    return false;
  }
  bool operator == (const Dof &other) const{
    return (_entity == other._entity && _type == other._type);
  }
};

template<class T> struct dofTraits
{
  typedef T VecType;
  typedef T MatType;
  inline static void gemm (VecType &r, const MatType &m, const VecType &v) { r += m*v;}
  inline static void neg (VecType &r) { r = -r;}
  inline static void setToZero (VecType &r) { r = 0;}
};

template<class T> struct dofTraits<fullMatrix<T> >
{
  typedef fullMatrix<T> VecType;
  typedef fullMatrix<T> MatType;
  inline static void gemm (VecType &r, const MatType &m, const VecType &v) { r.gemm(m, v);}
  inline static void neg (VecType &r) { r.scale(-1.);}
  inline static void setToZero (VecType &r) { r.scale(0);}
};
/*
template<> struct dofTraits<fullVector<std::complex<double> > >
{
  typedef fullVector<std::complex<double> > VecType;
  typedef fullMatrix<std::complex<double> > MatType;
};
*/
template<class T>
class DofAffineConstraint{
 public:
  std::vector<std::pair<Dof, typename dofTraits<T>::MatType> > linear;
  typename dofTraits<T>::VecType shift;
};

// A manager for degrees of freedoms, templated on the value of a dof
// (what the functional returns): float, double, complex<double>,
// fullVecor<double>, ...
template <class T>
class dofManager{
 public:
  typedef typename dofTraits<T>::VecType dataVec;
  typedef typename dofTraits<T>::MatType dataMat;
 private:
  // general affine constraint on sub-blocks, treated by adding
  // equations:

  //   Dof = \sum_i dataMat_i x Dof_i + dataVec
  std::map<Dof, DofAffineConstraint< dataVec > > constraints;

  // fixations on full blocks, treated by eliminating equations:
  //   DofVec = dataVec
  std::map<Dof, dataVec> fixed;

  // initial conditions
  std::map<Dof, std::vector<dataVec> > initial;

  // numbering of unknown dof blocks
  std::map<Dof, int> unknown;

  // associatations
  std::map<Dof, Dof> associatedWith;

  // linearSystems
  std::map<const std::string, linearSystem<dataMat>*> _linearSystems;
  linearSystem<dataMat> *_current;

 public:
 dofManager(linearSystem<dataMat> *l) : _current(l) { _linearSystems["A"] = l; }
 dofManager(linearSystem<dataMat> *l1, linearSystem<dataMat> *l2) : _current(l1) {
    _linearSystems.insert(std::make_pair("A", l1));
    _linearSystems.insert(std::make_pair("B", l2));
    //_linearSystems.["A"] = l1;
    //_linearSystems["B"] = l2;
  }
  inline void fixDof(Dof key, const dataVec &value)
  {
    fixed[key] = value;
  }
  inline void fixDof(long int ent, int type, const dataVec &value)
  {
    fixed[Dof(ent, type)] = value;
  }
  inline void fixVertex(MVertex*v, int iComp, int iField, const dataVec &value)
  {
    fixDof(v->getNum(), Dof::createTypeWithTwoInts(iComp, iField), value);
  }
  inline void numberDof(Dof key)
  {
    if(fixed.find(key) != fixed.end())
    {
      return;
    }
    // constraints
    if (constraints.find(key) != constraints.end()){
       return;
    }
    //
    std::map<Dof, int> :: iterator it = unknown.find(key);
    if (it == unknown.end()){
      unsigned int size = unknown.size();
      unknown[key] = size;
    }
  }
  inline void numberDof(long int ent, int type)
  {
    numberDof(Dof(ent, type));
  }
  inline void numberVertex(MVertex*v, int iComp, int iField)
  {
    numberDof(v->getNum(), Dof::createTypeWithTwoInts(iComp, iField));
  }

  inline void getDofValue(std::vector<Dof> &keys,std::vector<dataVec> &Vals)
  {
    int ndofs=keys.size();
    size_t originalSize = Vals.size();
    Vals.resize(originalSize+ndofs);
    for (int i=0;i<ndofs;++i) getDofValue(keys[i], Vals[originalSize+i]);
  }

  inline void getDofValue(Dof key,  dataVec &val) const
  {
    {
      typename std::map<Dof, dataVec>::const_iterator it = fixed.find(key);
      if (it != fixed.end()) {
        val =  it->second;
        return ;
      }
    }
    {
      std::map<Dof, int>::const_iterator it = unknown.find(key);
      if (it != unknown.end()) {
        _current->getFromSolution(it->second,val );
        return;
      }
    }
    {
      typename std::map<Dof, DofAffineConstraint< dataVec > >::const_iterator it = constraints.find(key);
      if (it != constraints.end())
      {
         dataVec tmp(val);
         dofTraits<T>::setToZero(val);
         for (int i=0;i<(it->second).linear.size();i++)
         {
            std::map<Dof, int>::const_iterator itu = unknown.find(((it->second).linear[i]).first);
            getDofValue(((it->second).linear[i]).first, tmp);
            dofTraits<T>::gemm(val,((it->second).linear[i]).second, tmp);
         }
         val += (it->second).shift;
         return ;
      }
    }
    dofTraits<T>::setToZero(val);
  }

  inline void getDofValue(int ent, int type, dataVec &v) const
  {
    Dof key(ent, type);
    {
      typename std::map<Dof, dataVec>::const_iterator it = fixed.find(key);
      if (it != fixed.end()){
        v = it->second;
        return;
      }
    }
    {
      std::map<Dof, int>::const_iterator it = unknown.find(key);
      if (it != unknown.end()){
        _current->getFromSolution(it->second, v);
        return;
      }
    }
     {
      typename std::map<Dof, DofAffineConstraint< dataVec > >::const_iterator it = constraints.find(key);
      if (it != constraints.end())
      {
         dofTraits<T>::setToZero(v);
         dataVec tmp(v);
         for (int i=0;i<(it->second).linear.size();i++)
         {
            std::map<Dof, int>::const_iterator itu = unknown.find(((it->second).linear[i]).first);
            getDofValue(((it->second).linear[i]).first, tmp);
            dofTraits<T>::gemm(v, ((it->second).linear[i]).second, tmp);
         }
         v += (it->second).shift;
         return ;
      }
    }

    dofTraits<T>::setToZero(v);
  }
  inline void getDofValue(MVertex *v, int iComp, int iField, dataVec &value) const
  {
    getDofValue(v->getNum(), Dof::createTypeWithTwoInts(iComp, iField), value);
  }

  inline void assemble(const Dof &R, const Dof &C, const dataMat &value)
  {
    if (!_current->isAllocated()) _current->allocate(unknown.size());
    std::map<Dof, int>::iterator itR = unknown.find(R);
    if (itR != unknown.end()){
      std::map<Dof, int>::iterator itC = unknown.find(C);
      if (itC != unknown.end()){
        _current->addToMatrix(itR->second, itC->second, value);
      }
      else{
        typename std::map<Dof,  dataVec>::iterator itFixed = fixed.find(C);
        if (itFixed != fixed.end()) {
          // tmp = -value * itFixed->second
          dataVec tmp(itFixed->second);
          dofTraits<T>::setToZero(tmp);
          dofTraits<T>::gemm(tmp , value, itFixed->second);
          dofTraits<T>::neg(tmp);
          _current->addToRightHandSide(itR->second, tmp);
        }else assembleLinConst(R, C, value);
      }
    }
    if (itR == unknown.end())
    {
      assembleLinConst(R, C, value);
    }
  }
  inline void assemble(std::vector<Dof> &R, std::vector<Dof> &C, const fullMatrix<dataMat> &m)
  {
    if (!_current->isAllocated()) _current->allocate(unknown.size());

    std::vector<int> NR(R.size()), NC(C.size());

    for (unsigned int i = 0; i < R.size(); i++){
      std::map<Dof, int>::iterator itR = unknown.find(R[i]);
      if (itR != unknown.end()) NR[i] = itR->second;
      else NR[i] = -1;
    }
    for (unsigned int i = 0; i < C.size(); i++){
      std::map<Dof, int>::iterator itC = unknown.find(C[i]);
      if (itC != unknown.end()) NC[i] = itC->second;
      else NC[i] = -1;
    }
    for (unsigned int i = 0; i < R.size(); i++){
      if (NR[i] != -1){
        for (unsigned int j = 0; j < C.size(); j++){
          if (NC[j] != -1){
            _current->addToMatrix(NR[i], NC[j], m(i, j));
          }
          else{
            typename std::map<Dof,  dataVec>::iterator itFixed = fixed.find(C[j]);
            if (itFixed != fixed.end()){
              // tmp = -m(i,j) * itFixed->second
              dataVec tmp(itFixed->second);
              dofTraits<T>::setToZero(tmp);
              dofTraits<T>::gemm(tmp , m(i,j), itFixed->second);
              dofTraits<T>::neg(tmp);
              _current->addToRightHandSide(NR[i], tmp);
            }else assembleLinConst(R[i], C[j], m(i,j));
          }
        }
      }
      else
      {
        for (unsigned int j = 0; j < C.size(); j++)
        {
            assembleLinConst(R[i], C[j], m(i, j));
        }
      }
    }
  }

  inline void assemble(std::vector<Dof> &R, const fullVector<dataMat> &m) // for linear forms
  {
    if (!_current->isAllocated()) _current->allocate(unknown.size());
    std::vector<int> NR(R.size());
    for (unsigned int i = 0; i < R.size(); i++)
    {
      std::map<Dof, int>::iterator itR = unknown.find(R[i]);
      if (itR != unknown.end()) NR[i] = itR->second;
      else NR[i] = -1;
    }
    for (unsigned int i = 0; i < R.size(); i++)
    {
      if (NR[i] != -1)
      {
        _current->addToRightHandSide(NR[i], m(i));
      }
      else
      {
        typename std::map<Dof,DofAffineConstraint<dataVec> >::iterator itConstraint;
        itConstraint = constraints.find(R[i]);
        if (itConstraint != constraints.end())
        {
          for (int i=0;i<(itConstraint->second).linear.size();i++)
          {
                  std::map<Dof, int>::iterator itC = unknown.find((itConstraint->second).linear[i].first); // lin dep in unknown ?!
                  _current->addToRightHandSide(itC->second, m(i)*(itConstraint->second).linear[i].second);
          }
        }
      }
    }
  }


  inline void assemble(std::vector<Dof> &R, const fullMatrix<dataMat> &m)
  {
    if (!_current->isAllocated()) _current->allocate(unknown.size());
    std::vector<int> NR(R.size());
    for (unsigned int i = 0; i < R.size(); i++)
    {
      std::map<Dof, int>::iterator itR = unknown.find(R[i]);
      if (itR != unknown.end()) NR[i] = itR->second;
      else NR[i] = -1;
    }
    for (unsigned int i = 0; i < R.size(); i++)
    {
      if (NR[i] != -1)
      {
        for (unsigned int j = 0; j < R.size(); j++)
        {
          if (NR[j] != -1)
          {
            _current->addToMatrix(NR[i], NR[j], m(i, j));
          }
          else
          {
            typename std::map<Dof,  dataVec>::iterator itFixed = fixed.find(R[j]);
            if (itFixed != fixed.end()){
              // tmp = -m(i,j) * itFixed->second
              dataVec tmp(itFixed->second);
              dofTraits<T>::setToZero(tmp);
              dofTraits<T>::gemm(tmp , m(i,j), itFixed->second);
              dofTraits<T>::neg(tmp);
              _current->addToRightHandSide(NR[i], tmp);
            } else assembleLinConst(R[i],R[j],m(i,j));
          }
        }
      }
      else
      {
        for (unsigned int j = 0; j < R.size(); j++){
        assembleLinConst(R[i],R[j],m(i,j));
        }
      }
    }
  }

  inline void assemble(int entR, int typeR, int entC, int typeC, const dataMat &value)
  {
    assemble(Dof(entR, typeR), Dof(entC, typeC), value);
  }
  inline void assemble(MVertex *vR, int iCompR, int iFieldR,
                       MVertex *vC, int iCompC, int iFieldC,
                       const dataMat &value)
  {
    assemble(vR->getNum(), Dof::createTypeWithTwoInts(iCompR, iFieldR),
             vC->getNum(), Dof::createTypeWithTwoInts(iCompC, iFieldC),
             value);
  }
  inline void assemble(const Dof &R, const dataMat &value)
  {
    if(!_current->isAllocated()) _current->allocate(unknown.size());
    std::map<Dof, int>::iterator itR = unknown.find(R);
    if(itR != unknown.end()){
      _current->addToRightHandSide(itR->second, value);
    }
  }
  inline void assemble(int entR, int typeR, const dataMat &value)
  {
    assemble(Dof(entR, typeR), value);
  }
  inline void assemble(MVertex *vR, int iCompR, int iFieldR,
                        const dataMat &value)
  {
    assemble(vR->getNum(), Dof::createTypeWithTwoInts(iCompR, iFieldR), value);
  }
  int sizeOfR() const { return unknown.size(); }
  int sizeOfF() const { return fixed.size(); }
  void systemSolve(){ _current->systemSolve(); }
  void systemClear()
  {
    _current->zeroMatrix();
    _current->zeroRightHandSide();
  }
  inline void setCurrentMatrix(std::string name){
    typename std::map<const std::string, linearSystem<dataMat>*>::iterator it =  _linearSystems.find(name);
     if(it != _linearSystems.end())
       _current = it->second;
     else{
       Msg::Error("Current matrix %s not found ",  name.c_str());
       throw;
     }
  }
  linearSystem<dataMat> *getLinearSystem(std::string &name)
  {
    typename std::map<const std::string, linearSystem<dataMat>*>::iterator it =
      _linearSystems.find(name);
    if(it != _linearSystems.end())
      return it->second;
    else
      return 0;
  }

  inline void setLinearConstraint (Dof key, DofAffineConstraint<dataVec> &affineconstraint)
  {
      constraints.insert(std::make_pair(key,affineconstraint));
  }

  inline void assembleLinConst(const Dof &R, const Dof &C, const dataMat &value)
  {
    std::map<Dof, int>::iterator itR = unknown.find(R);
    if (itR != unknown.end())
    {
      typename std::map<Dof,DofAffineConstraint<dataVec> >::iterator itConstraint;
      itConstraint = constraints.find(C);
      if (itConstraint != constraints.end())
      {
        dataMat tmp(value);
        for (int i=0;i<(itConstraint->second).linear.size();i++)
        {
          dofTraits<T>::setToZero(tmp);
          dofTraits<T>::gemm(tmp,(itConstraint->second).linear[i].second,value);
          assemble(R,(itConstraint->second).linear[i].first,tmp);
        }
        dataMat tmp2(value);
        dofTraits<T>::setToZero(tmp2);
        dofTraits<T>::gemm(tmp2, value, itConstraint->second.shift);
        dofTraits<T>::neg(tmp2);
        _current->addToRightHandSide(itR->second, tmp2);
      }
    }
    else  // test function ; (no shift ?)
    {
      typename std::map<Dof,DofAffineConstraint<dataVec> >::iterator itConstraint;
      itConstraint = constraints.find(R);
      if (itConstraint != constraints.end())
      {
        dataMat tmp(value);
        for (int i=0;i<(itConstraint->second).linear.size();i++)
        {
          dofTraits<T>::setToZero(tmp);
          dofTraits<T>::gemm(tmp,itConstraint->second.linear[i].second,value);
          assemble((itConstraint->second).linear[i].first,C,tmp);
        }
      }
    }
  }

};
#endif
