// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
};

template<class T> struct dofTraits<fullVector<T> >
{
  typedef fullVector<T> VecType;
  typedef fullMatrix<T> MatType;
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
  //   dataMat * DofVec = \sum_i dataMat_i * DofVec_i + dataVec
  std::map<std::pair<Dof, dataMat>, DofAffineConstraint<dataVec> > constraints;
    
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
    if(fixed.find(key) != fixed.end()) return;
    // if (constraints.find(key) != constraints.end()) return;
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
    Vals.reserve(Vals.size()+ndofs);
    for (int i=0;i<ndofs;++i) Vals.push_back(getDofValue(keys[i]));
  }

  inline dataVec getDofValue(Dof key) const
  {
    {
      typename std::map<Dof, dataVec>::const_iterator it = fixed.find(key);
      if (it != fixed.end()) return it->second;
    }
    {
      std::map<Dof, int>::const_iterator it = unknown.find(key);
      if (it != unknown.end())
        return _current->getFromSolution(it->second);
    }
    return dataVec(0.0);
  }

  inline dataVec getDofValue(int ent, int type) const
  {
    Dof key(ent, type);
    {
      typename std::map<Dof, dataVec>::const_iterator it = fixed.find(key);
      if (it != fixed.end()) return it->second;
    }
    {
      std::map<Dof, int>::const_iterator it = unknown.find(key);
      if (it != unknown.end())
        return _current->getFromSolution(it->second);
    }
    return dataVec(0.0);
  }
  inline dataVec getDofValue(MVertex *v, int iComp, int iField) const
  {
    return getDofValue(v->getNum(), Dof::createTypeWithTwoInts(iComp, iField));
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
        if (itFixed != fixed.end()){
          _current->addToRightHandSide(itR->second, -value * itFixed->second);
        }
      }
    }
  }
  inline void assemble(std::vector<Dof> &R, std::vector<Dof> &C, fullMatrix<dataMat> &m)
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
              _current->addToRightHandSide(NR[i], -m(i,j) * itFixed->second);
            }
          }
        }
      }
    }
  }

  inline void assemble(std::vector<Dof> &R, fullVector<dataMat> &m) // for linear forms
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
    }
  }


  inline void assemble(std::vector<Dof> &R, fullMatrix<dataMat> &m)
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
              _current->addToRightHandSide(NR[i], -m(i, j) * itFixed->second);
            }
          }
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
  linearSystem<dataMat> *getLinearSystem(std::string &name)
  {
    typename std::map<const std::string, linearSystem<dataMat>*>::iterator it =
      _linearSystems.find(name);
    if(it != _linearSystems.end())
      return it->second;
    else
      return 0;
  }
};

#endif
