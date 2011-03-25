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

class rigidContactSpaceBase : public ContactSpaceBase<double>{
 protected:
  const MVertex *_gc; // Node of gravity center
 public:
  rigidContactSpaceBase(const int id, FunctionSpace<double> *sp, MVertex *ver) : ContactSpaceBase<double>(id,sp), _gc(ver){}
  rigidContactSpaceBase(const int id, FunctionSpace<double> *sp, MVertex *ver, const int comp1,
                   const int comp2 = -1, const int comp3 =-1) : ContactSpaceBase<double>(id,sp,comp1,comp2,comp3){}
  virtual void getKeys(MElement *ele,std::vector<Dof> &keys)=0;
  virtual int getNumKeys(MElement *ele)=0;
  virtual void getKeysOfGravityCenter(std::vector<Dof> &keys)=0;
  virtual int getNumKeysOfGravityCenter()=0;
  virtual void getKeys(MElement *ele, const int ind, std::vector<Dof> &keys)=0;
  virtual int getNumKeys(MElement *ele, int ind)=0; // number key in one component + number of key of GC
};
#endif // CONTACTSPACE_H_

