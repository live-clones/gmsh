//
// C++ Interface: terms
//
// Description: Define material law
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef _MLAW_H_
#define _MLAW_H_
#ifndef SWIG
#include "ipstate.h"
#include "MElement.h"
#endif
class materialLaw{
 public :
  enum matname{linearElasticPlaneStress, linearElasticPlaneStressWithDamage, linearElasticOrthotropicPlaneStress, cohesiveLaw, fracture};
 protected :
  int _num; // number of law (must be unique !)
  bool _initialized; // to initialize law
#ifndef SWIG
 public:
  // constructor
  materialLaw(const int num, const bool init=true);
  ~materialLaw(){}
  materialLaw(const materialLaw &source);
  materialLaw& operator=(const materialLaw &source);
  virtual int getNum() const{return _num;}
  virtual matname getType() const=0;
  virtual void createIPState(IPStateBase* &ips,const bool* state_=NULL,const MElement *ele=NULL, const int nbFF_=0) const=0;
  virtual void initLaws(const std::map<int,materialLaw*> &maplaw)=0;
  virtual const bool isInitialized() {return _initialized;}
  // for explicit scheme it must return sqrt(E/rho) adapted to your case
  virtual double soundSpeed() const=0;
#endif
};
#ifndef SWIG
class materialLaw2LawsInitializer{
 public:
  materialLaw2LawsInitializer(){}
  ~materialLaw2LawsInitializer(){}
  materialLaw2LawsInitializer(const materialLaw2LawsInitializer &source){}
//  virtual materialLaw::matname getType() const{return materialLaw::fracture;}
  virtual void initialBroken(IPStateBase *ips) const=0;
};

// If you used two laws your class has to be derived from this one
template<class Tbulk, class Tfrac>class fractureBy2Laws : public materialLaw2LawsInitializer{
 protected:
  const int _nbulk;
  const int _nfrac;
  Tbulk *_mbulk;
  Tfrac *_mfrac;
 public:
  fractureBy2Laws(const int num, const int nbulk, const int nfrac) : materialLaw2LawsInitializer(),
                                                                       _nbulk(nbulk), _nfrac(nfrac),
                                                                       _mbulk(NULL), _mfrac(NULL){}
  fractureBy2Laws(const fractureBy2Laws &source) : materialLaw2LawsInitializer(source), _nbulk(source._nbulk),
                                                    _nfrac(source._nfrac),
                                                    _mbulk(source._mbulk), _mfrac(source._mfrac){}
  ~fractureBy2Laws(){};
  virtual const int bulkLawNumber() const{return _nbulk;}
  virtual const int fractureLawNumber() const{return _nfrac;}
  virtual const Tbulk* getBulkLaw() const{return _mbulk;}
  virtual Tbulk* getBulkLaw(){return _mbulk;}
  virtual const Tfrac* getFractureLaw() const{return _mfrac;}
  virtual void initLaws(const std::map<int,materialLaw*> &maplaw)
  {
    bool findb=false;
    bool findc=false;
    for(std::map<int,materialLaw*>::const_iterator it = maplaw.begin(); it != maplaw.end(); ++it)
    {
      int num = it->first;
      if(num == _nbulk){
        findb=true;
        it->second->initLaws(maplaw);
        _mbulk = dynamic_cast<Tbulk*>(it->second);
      }
      if(num == _nfrac){
        findc=true;
        it->second->initLaws(maplaw);
        _mfrac = dynamic_cast<Tfrac*>(it->second);
      }
    }
    if(!findb) Msg::Error("The bulk law is not initialize for shellFractureByCohesiveLaw number %d",_nbulk);
    if(!findc) Msg::Error("The cohesive law is not initialize for shellFractureByCohesiveLaw number %d",_nfrac);
  }
  virtual void initialBroken(IPStateBase *ips) const=0;
};
#endif // SWIG
#endif //MLAW_H_
