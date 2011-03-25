//
// contact Domain
//
// Description: Domain to solve contact problem
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef CONTACTDOMAIN_H_
#define CONTACTDOMAIN_H_
#ifndef SWIG
#include "groupOfElements.h"
#include "partDomain.h"
#include "contactTerms.h"
#include "rigidCylinderContactTerms.h"
#include "MVertex.h"
#include "MElement.h"
template<class T2> class contactBilinearTermBase;
template<class T2> class contactLinearTermBase;
#endif
class contactDomain{
 public:
  enum contact{rigidCylinder, rigidSphere};
 protected:
  int _phys;
  int _physSlave;
  int _tag;
  double _penalty;
  BilinearTermBase* _bterm;
  BilinearTermBase* _massterm;
  LinearTermBase<double>* _lterm;
  partDomain *_dom;
  contact _contype;
  bool _rigid;
  FunctionSpaceBase *_space;
  QuadratureBase *_integ;
 public:
  groupOfElements *gMaster;
  groupOfElements *gSlave;
#ifndef SWIG
  contactDomain() : gMaster(0), gSlave(0), _phys(0), _physSlave(0), _tag(0), _contype(rigidCylinder), _dom(0), _penalty(0.), _rigid(true){}
  contactDomain(const int tag, const int phys, const int physSlave, double pe,
                contact conty,const bool rigid=false) : _tag(tag), _phys(phys), _physSlave(physSlave),
                                                          _penalty(pe), _contype(conty),
                                                          _rigid(rigid), _space(NULL){}
  contactDomain(const contactDomain &source);
  ~contactDomain(){}

  virtual void setTag(const int t){ _tag =t;}
  virtual void setPhys(const int p){_phys =p;}
  virtual void setPenalty(const double pe){_penalty=pe;}
  virtual void setContactType(const int ct);
  virtual void setContactType(const contact ct){_contype =ct;}
  virtual int getTag() const{return _tag;}
  virtual int getPhys() const{return _phys;}
  virtual int getPhysSlave() const{return _physSlave;}
  virtual double getPenalty() const{return _penalty;}
  virtual contact getContactType() const{return _contype;}
  virtual partDomain* getDomain() const {return _dom;}
  virtual MElement * getFirstElement() const;
  virtual bool isRigid() const {return _rigid;}
  virtual BilinearTermBase* getMassTerm(){return _massterm;}
  virtual BilinearTermBase* getStiffnessTerm(){return _bterm;}
  virtual LinearTermBase<double>* getForceTerm(){return _lterm;}
  virtual FunctionSpaceBase* getSpace() {return _space;}
  virtual const FunctionSpaceBase* getSpace() const {return _space;}
  virtual QuadratureBase* getGaussIntegration() const{return _integ;}
  virtual void setDomainAndFunctionSpace(partDomain *dom)=0;
  virtual void initializeTerms(const unknownField *ufield)=0;
//  static void registerBindings(binding *b);
#endif
};

class rigidCylinderContactDomain : public contactDomain{
 protected:
  double _length; // length of cylinder;
  double _radius; // outer radius of cylinder;
  double _thick;  // thickness of cylinder;
  double _thickContact; // use for shell (contact with neutral axis of external fiber is !=0)
  double _density; // density of cylinder Not a material law for now
  MVertex *_vergc;  // vertex of gravity center
  SVector3 *_axisDirector; // normalized vector director of cylinder's axis
#ifndef SWIG
 public:
  rigidCylinderContactDomain() : contactDomain(), _length(0.), _radius(0.), _thick(0.){
    _contype = rigidCylinder;
    _rigid = true;
    _integ = new QuadratureVoid();
  }
  rigidCylinderContactDomain(const int tag, const int physMaster, const int physSlave, const int physpt1,
                       const int physpt2,const double penalty,const double h,const double rho);
  ~rigidCylinderContactDomain(){delete _axisDirector;}
  virtual void initializeTerms(const unknownField *ufield);
  SVector3* getAxisDirector() const{return _axisDirector;}
  virtual void setDomainAndFunctionSpace(partDomain *dom)=0;
  virtual MVertex* getGC() const{return _vergc;}
  double getDensity() const{return _density;}
  double getLength() const{return _length;}
  double getRadius() const{return _radius;}
  double getThickness() const{return _thick;}
#endif
};
#endif // CONTACTDOMAIN_H_
