//
// C++ Interface: ipvariable
//
// Description: Base class for ipvariable
//
//
// Author:  <Gauthier BECKER>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
// class with the variables of IP (stress, deformation and localBasis)

#ifndef IPVARIABLE_H_
#define IPVARIABLE_H_
#include <stdlib.h>
#include <stdio.h>

class IPVariable
{
 public :
  IPVariable(){}
  virtual ~IPVariable(){}
  // copie constructor
  IPVariable(const IPVariable &source){};
  virtual IPVariable &operator=(const IPVariable &source){return *this;};
};

class IPVariableMechanics : public IPVariable{
 public:
  IPVariableMechanics(): IPVariable(){}
  IPVariableMechanics(const IPVariableMechanics &source) : IPVariable(source){};
  virtual IPVariableMechanics &operator=(const IPVariable &source){
    IPVariable::operator=(source);
    return *this;
  }
  virtual double defoEnergy() const{return 0;}
  virtual double stressComp(const int i) const{return 0;}
};

template<class Tbulk,class Tfrac> class IPVariable2ForFracture : virtual public IPVariableMechanics{
 protected:
  Tbulk *_ipvbulk;
  Tfrac *_ipvfrac;
  bool _broken; // To know which law to use
 public:
  IPVariable2ForFracture() : IPVariableMechanics(), _ipvbulk(NULL), _ipvfrac(NULL), _broken(false){}
  IPVariable2ForFracture(const IPVariable2ForFracture &source) : IPVariableMechanics(source), _broken(source._broken)
  {
    (*_ipvbulk) = (*(dynamic_cast<const IPVariable*>(source._ipvbulk)));
    if(source._ipvfrac != NULL)
      if(_ipvfrac == NULL) _ipvfrac = new Tfrac(*(source._ipvfrac));
      else  (*_ipvfrac) = (*(dynamic_cast<const IPVariable*>(source._ipvfrac)));
  }
  IPVariable2ForFracture& operator=(const IPVariable &source)
  {
    IPVariableMechanics::operator=(source);
    const IPVariable2ForFracture *ipvf =dynamic_cast<const IPVariable2ForFracture *> (&source);
    _broken = ipvf->_broken;
    (*_ipvbulk) = (*(dynamic_cast<const IPVariableMechanics*>(ipvf->_ipvbulk)));
    if(ipvf->_ipvfrac != NULL){
      if(_ipvfrac == NULL) _ipvfrac = new Tfrac(*(ipvf->_ipvfrac));
      else (*_ipvfrac) = (*(dynamic_cast<IPVariableMechanics*>(ipvf->_ipvfrac)));
    }
    else{
      if(_ipvfrac != NULL) delete _ipvfrac;
      _ipvfrac =NULL;
    }
    return *this;
  }
  ~IPVariable2ForFracture()
  {
    if(_ipvbulk != NULL){
      delete _ipvbulk;
    }
    if(_ipvfrac != NULL){
      delete _ipvfrac;
    }
  }
  const bool broken() const{return _broken;}
  bool isbroken(){return _broken;}
  void broken(){_broken=true;}
  void nobroken(){_broken=false;}
  Tbulk* getIPvBulk(){return _ipvbulk;}
  const Tbulk* getIPvBulk() const{return _ipvbulk;}
  Tfrac* getIPvFrac(){return _ipvfrac;}
  const Tfrac* getIPvFrac() const {return _ipvfrac;}
  void setIPvBulk(IPVariable *ipv){ _ipvbulk = dynamic_cast<Tbulk*>(ipv);}
  void setIPvFrac(IPVariable *ipv){ _ipvfrac = dynamic_cast<Tfrac*>(ipv);}
};

#endif //IPVARIABLE_H_

