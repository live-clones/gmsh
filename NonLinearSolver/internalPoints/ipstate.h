//
// C++ Interface: terms
//
// Description: Class to store internal variables at gauss point
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef IPSTATE_H_
#define IPSTATE_H_
#include "GModel.h"
#include "ipvariable.h"
// enum to access to component of stress and deformation GLOBAL ??
struct component{
 enum enumcomp{xx,yy,zz,xy,xz,yz};
};
class partDomain;
class dgPartDomain;
class materialLaw;
class IPStateBase{
 public:
  IPStateBase(){}
  IPStateBase(const IPStateBase &source){}
  virtual IPStateBase& operator=(const IPStateBase &source){return *this;}
  enum whichState{initial, previous, current}; // keep previous OVERLOAD enum in daughter class ???
  virtual IPVariable* getState(const whichState wst=IPStateBase::current) const=0;
};

class IP3State : public IPStateBase{
 protected :
  IPVariable *_initial;     // initial state t=0
  IPVariable *_step1;    // previous step if _st = true and current step otherwise
  IPVariable *_step2;     // current step if _st = true and previous step otherwise
  const bool *_st; // pointer on a bool value to choice what vector is current and what vector is previous
 public :
  IP3State(bool *st) : IPStateBase(),_st(st), _initial(NULL), _step1(NULL), _step2(NULL){}
  IP3State(const bool *st,IPVariable *init,
           IPVariable *st1, IPVariable *st2): _st(st), _initial(init), _step1(st1), _step2(st2){}
  ~IP3State();
  IP3State(const IP3State &source);
  virtual IP3State & operator = (const IPStateBase &source);
  IPVariable* getState(const whichState wst=IPStateBase::current) const;
};

// Class to access to the IPState of all gauss point
class AllIPState{
 public:
  typedef std::map<long int, std::vector<IPStateBase*> > ipstateContainer;
  typedef std::pair<long int, std::vector<IPStateBase*> > ipstatePairType;
  typedef std::vector<IPStateBase*> ipstateElementContainer;
 protected:
  ipstateContainer _mapall;
  bool state; // flag to switch previous and current (change the pointer in place of copy all variables)
 public :
  AllIPState(GModel *pModel, std::vector<partDomain*> &vdom);
  ~AllIPState();
  ipstateElementContainer* getIPstate(const long int num);
  ipstateElementContainer* operator[](const long int num);
  void nextStep() {state ? state=false : state=true;} // change boolvalue
  void copy(const IPStateBase::whichState ws1, const IPStateBase::whichState ws2){
    for(ipstateContainer::iterator it=_mapall.begin(); it!=_mapall.end();++it){
      std::vector<IPStateBase*> *vips = &((*it).second);
      for(int i=0;i<vips->size();i++){
        IPVariable *ipv1= (*vips)[i]->getState(ws1);
        IPVariable *ipv2= (*vips)[i]->getState(ws2);
        *ipv2 =*ipv1;
      }
    }
  }
};
#endif // IPSTATE_H_
