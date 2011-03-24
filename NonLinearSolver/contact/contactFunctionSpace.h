//
// functional space for contact
//
// Description:
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//

#ifndef CONTACTSPACE_H_
#define CONTACTSPACE_H_
#include "functionSpace.h"
#include "Dof3IntType.h"
template <class T1> class ContactSpaceBase : public FunctionSpaceBase{
 protected:
  FunctionSpace<T1> *_space; // functional space of domain where contact is computed
  const int _id;
  std::vector<int> _comp;
 public:
  ContactSpaceBase(const int id, FunctionSpace<double> *sp) : FunctionSpaceBase(), _id(id), _space(sp){
    _comp.push_back(0);
    _comp.push_back(1);
    _comp.push_back(2);
  }
  ContactSpaceBase(const int id, FunctionSpace<double> *sp, const int comp1,
                   const int comp2 = -1, const int comp3 =-1) : FunctionSpaceBase(), _id(id), _space(sp)
  {
    _comp.push_back(comp1);
    if(comp2 !=-1)
      _comp.push_back(comp2);
    if(comp3 != -1)
      _comp.push_back(comp3);
  }

  virtual void getKeys(MElement *ele,std::vector<Dof> &keys){
    _space->getKeys(ele,keys);
  }
  virtual int getNumKeys(MElement *ele){
    return _space->getNumKeys(ele);
  }
};

class rigidContactSpace : public ContactSpaceBase<double>{
 protected:
  const MVertex *_gc; // Node of gravity center
 public:
  rigidContactSpace(const int id, FunctionSpace<double> *sp, MVertex *ver) : ContactSpaceBase<double>(id,sp), _gc(ver){}
  rigidContactSpace(const int id, FunctionSpace<double> *sp, MVertex *ver, const int comp1,
                   const int comp2 = -1, const int comp3 =-1) : ContactSpaceBase<double>(id,sp,comp1,comp2,comp3){}
  virtual void getKeys(MElement *ele,std::vector<Dof> &keys){
    _space->getKeys(ele,keys);
    for(int i=0;i<_comp.size();i++){
      keys.push_back(Dof(_gc->getNum(),Dof3IntType::createTypeWithThreeInts(_comp[i],_id)));
    }
  }
  virtual int getNumKeys(MElement *ele){
    int nkeysele = _space->getNumKeys(ele);
    return nkeysele + _comp.size();
  }
  virtual void getKeysOfGravityCenter(std::vector<Dof> &keys){
    for(int i=0;i<_comp.size(); i++)
      keys.push_back(Dof(_gc->getNum(),Dof3IntType::createTypeWithThreeInts(_comp[i],_id)));
  }
  virtual int getNumKeysOfGravityCenter(){
    return _comp.size();
  }
  virtual void getKeys(MElement *ele, const int ind, std::vector<Dof> &keys){
    // generate keys of element and select the good ones after LAGRANGE OK ?? CHANGE THIS HOW TODO
    std::vector<Dof> tkeys;
    this->getKeys(ele,tkeys);
    int nkeys = this->getNumKeys(ele);
    int ncomp = _comp.size();
    int nbver = nkeys/ncomp-1; // because GC is in the nkeys
    for(int i=0;i<ncomp; i++)
      keys.push_back(tkeys[ind+i*nbver]);
    this->getKeysOfGravityCenter(keys);
  }
  virtual int getNumKeys(MElement *ele, int ind){
    return 2*_comp.size();
  }
};
#endif // CONTACTSPACE_H_

