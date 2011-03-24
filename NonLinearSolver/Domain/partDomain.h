//
// C++ Interface: partDomain
//
// Description: Interface class to used solver. Your term ha to be store in a domain
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef PARTDOMAIN_H_
#define PARTDOMAIN_H_
#ifndef SWIG
#include "mlaw.h"
#include "SVector3.h"
#include "MInterfaceElement.h"
#include "groupOfElements.h"
#include "timeFunction.h"
#include "functionSpaceType.h"
#include "nonLinearBC.h"
#include "nlTerms.h"
#include "unknownField.h"
#include "InterfaceBuilder.h"
// class for a domain (pure virtual class)
#endif
class partDomain{
 public :
  typedef std::set<nonLinearDirichletBC*> diriContainer;
  typedef std::set<nonLinearNeumannBC*> neuContainer;
  typedef std::set<initialCondition*> initContainer;

 protected :
  int _tag; // tag for the dofManager
  int _phys; // physical of interface group I don't know how to retrieve it from *g
  bool _fullDg; // To know which formulation Cg/Dg or FullDg is used for this part
  functionSpaceType::whichSpace _wsp;
  BilinearTermBase* btermBulk;
  BilinearTermBase* massterm;
  LinearTermBase<double>* ltermBulk;
  QuadratureBase* integBulk;
  // for matrix by perturbation
  bool _bmbp;
  double _eps;
  virtual void setBulkMatrixByPerturbation(const int i, const double eps=1e-8);
  // To know if law is already set
  bool setmaterial;
  // BC are put in domain to be sure to use the good function space
  // neumann BC
  neuContainer allNeumann;
  // dirichlet BC
  diriContainer allDirichlet;
  // initial Condition
  initContainer allInitial;

 public :
  // Todo protect this variable
  groupOfElements *g; // support for this field

#ifndef SWIG
  // Constructors
  partDomain(const int tag, const int phys,
             const int ws = 0,const bool fdg=false) : g(0), _tag(tag), _phys(phys),
                                                         _bmbp(false), _eps(1e-8), _fullDg(fdg), setmaterial(false)
  {
    switch(ws){
     case 0:
      _wsp = functionSpaceType::Lagrange;
      break;
     case 10000: // Allow to set space later (used for interface domain)
      _wsp = functionSpaceType::Inter;
      break;
     default:
      Msg::Error("Function space type is unknown for partDomain %d. So Lagrange by default");
      _wsp = functionSpaceType::Lagrange;
    }
  }
  partDomain(const partDomain &source);
  partDomain& operator=(const partDomain &source);
//  ~partDomain(){delete btermBulk; delete ltermBulk; delete integBulk;}
  BilinearTermBase* getBilinearBulkTerm() const{return btermBulk;}
  BilinearTermBase* getBilinearMassTerm() const{return massterm;}
  LinearTermBase<double>* getLinearBulkTerm() const{return ltermBulk;}
  QuadratureBase* getBulkGaussIntegrationRule() const{return integBulk;}
  // Dimension of domain
  virtual int getDim() const=0;
  int getTag()const{return _tag;}
  int getPhysical() const{return _phys;}
  virtual void initializeTerms(unknownField *uf,IPField *ip)=0;
  // true is domain has interface terms
  virtual bool IsInterfaceTerms() const=0;
  functionSpaceType::whichSpace getFunctionSpaceType() const{return _wsp;}
  // can be return const FunctionSpaceBase if the function of this class are declarated const
  virtual FunctionSpaceBase* getFunctionSpace() const=0;
// some data of BC have to be set by domain
  virtual void addDirichletBC(nonLinearDirichletBC *diri)=0; // space and filterDof
  virtual void addNeumannBC(nonLinearNeumannBC *neu)=0; // space, integration rule and term
  virtual void addInitialCondition(initialCondition *initC)=0; // idem as dirichlet
  void setTimeBC(const double curtime){
    for(neuContainer::iterator it=neuBegin(); it!=neuEnd(); ++it){
      nonLinearNeumannBC *neu = *it;
      simpleFunctionTime<double> *ft = dynamic_cast<simpleFunctionTime<double>*>(neu->_f);
      ft->setTime(curtime);
    }

    for(diriContainer::iterator it=diriBegin(); it!=diriEnd(); ++it){
      nonLinearDirichletBC *diri = *it;
      diri->_f.setTime(curtime);
    }
  }
  diriContainer::iterator diriBegin(){return allDirichlet.begin();}
  diriContainer::iterator diriEnd(){return allDirichlet.end();}
  neuContainer::iterator neuBegin(){return allNeumann.begin();}
  neuContainer::iterator neuEnd(){return allNeumann.end();}
  initContainer::iterator initCBegin(){return allInitial.begin();}
  initContainer::iterator initCEnd(){return allInitial.end();}

//  static void registerBindings(binding *b);
  virtual void computeIPVariable(AllIPState *aips,const unknownField *ufield,const IPStateBase::whichState ws)=0;
  virtual void computeIpv(AllIPState *aips,MInterfaceElement *ie, IntPt *GP,const IPStateBase::whichState ws,
                           partDomain* efMinus, partDomain *efPlus,materialLaw *mlawminus,
                           materialLaw *mlawplus,fullVector<double> &dispm,
                           fullVector<double> &dispp,const bool virt,const bool checkfrac=true)=0;
  virtual void computeIpv(AllIPState *aips,MElement *e, IPStateBase::whichState ws,
                           materialLaw *mlaw,fullVector<double> &disp)=0;
  virtual void setGaussIntegrationRule()=0;
  virtual void inverseLinearTermSign()=0;
  virtual bool getFormulation() const{return _fullDg;}
  virtual void setMaterialLaw(const std::map<int,materialLaw*> maplaw)=0;
  // No materialLaw store here but the function to give the material law exist
  // The law has to be store in the derivated class
  virtual materialLaw* getMaterialLaw()=0;
  virtual const materialLaw* getMaterialLaw() const=0;
  virtual int getLawNum() const=0;
  // For dg formulation the stability parameters decrease the critical time step size
  // in explicit. So this function allows to scale the time step
  virtual double scaleTimeStep() const {return 1.;}
  // creation of interface. At least boundary to create interface domain
  // can be empty be not interdomain creation in this case
  virtual void createInterface(manageInterface &maninter)=0;
  //Iedge has to be change in IElement
  virtual MElement* createVirtualInterface(IElement *ie) const=0;
  virtual MElement* createInterface(IElement* ie1,IElement* ie2) const=0;
  // Add for BC
  virtual FilterDof* createFilterDof(const int comp) const=0;
#endif
};
// class for Dg part domain (pure virtual)
class dgPartDomain : public partDomain{
 protected :
  BilinearTermBase* btermBound;
  LinearTermBase<double>* ltermBound;
  BilinearTermBase* btermVirtBound;
  LinearTermBase<double>* ltermVirtBound;
  QuadratureBase* integBound;
  // For matrix by perturbation
  bool _interByPert;
  bool _virtByPert;

 public :
  // TODO protect these variables
  groupOfElements *gi; // support for the interfaceElement TODO cast to a groupOfElements
  groupOfElements *gib; // support for the interfaceElement TODO cast to a groupOfElements
  groupOfElements *giv; // support for the virtual interface element (used to set Neumann and Dirichlet BC)
#ifndef SWIG
  dgPartDomain(const int tag, const int phys, const int ws = 0,
               const bool fdg=false) : partDomain(tag,phys,ws,fdg), _interByPert(false), _virtByPert(false)
  {
    gi = new groupOfElements();
    gib = new groupOfElements();
    giv = new groupOfElements();
  }
  dgPartDomain(const dgPartDomain &source);
  dgPartDomain& operator=(dgPartDomain &source);
//  ~dgPartDomain(){delete btermBound; delete ltermBound; delete btermVirtBound; delete ltermVirtBound;
//                  delete integBound; delete gib; delete giv}
  BilinearTermBase* getBilinearInterfaceTerm(){return btermBound;}
  LinearTermBase<double>* getLinearInterfaceTerm()const{return ltermBound;}
  BilinearTermBase* getBilinearVirtualInterfaceTerm(){return btermVirtBound;}
  LinearTermBase<double>* getLinearVirtualInterfaceTerm(){return ltermVirtBound;}
  QuadratureBase* getInterfaceGaussIntegrationRule() const {return integBound;}
  virtual void computeIPVariable(AllIPState *aips,const unknownField *ufield,const IPStateBase::whichState ws)=0;
  virtual void computeIpv(AllIPState *aips,MInterfaceElement *ie, IntPt *GP,const IPStateBase::whichState ws,
                            partDomain* efMinus, partDomain *efPlus,materialLaw *mlawminus,
                            materialLaw *mlawplus,fullVector<double> &dispm,
                            fullVector<double> &dispp,const bool virt,const bool checkfrac=true)=0;
  virtual void computeIpv(AllIPState *aips,MElement *e, IPStateBase::whichState ws,
                            materialLaw *mlaw,fullVector<double> &disp)=0;
  virtual void addDirichletBC(nonLinearDirichletBC *diri)=0;
  virtual void addNeumannBC(nonLinearNeumannBC *neu)=0;
  virtual void addInitialCondition(initialCondition *initC)=0;
  virtual void setGaussIntegrationRule()=0;
  virtual int getDim() const=0;
  virtual bool IsInterfaceTerms() const{return true;}
  virtual FunctionSpaceBase* getFunctionSpace() const=0;
  virtual FunctionSpaceBase* getFunctionSpaceMinus() const=0;
  virtual FunctionSpaceBase* getFunctionSpacePlus() const=0;
  virtual void matrixByPerturbation(const int ibulk, const int iinter, const int ivirt,const double eps=1e-8)=0;
//  static void registerBindings(binding *b);
  virtual void setMaterialLaw(const std::map<int,materialLaw*> maplaw)=0;
  virtual materialLaw* getMaterialLaw(){Msg::Error("The law to retrieve is not given on a dgdom"); return NULL;}
  virtual const materialLaw* getMaterialLaw() const{Msg::Error("The law to retrieve is not given on a dgdom"); return NULL;}
  virtual materialLaw* getMaterialLawMinus()=0;
  virtual const materialLaw* getMaterialLawMinus() const=0;
  virtual materialLaw* getMaterialLawPlus()=0;
  virtual const materialLaw* getMaterialLawPlus() const=0;
  virtual int getLawNum() const=0;
  virtual int getMinusLawNum() const=0;
  virtual int getPlusLawNum() const=0;
  virtual const partDomain* getMinusDomain() const=0;
  virtual const partDomain* getPlusDomain() const=0;
  virtual partDomain* getMinusDomain()=0;
  virtual partDomain* getPlusDomain()=0;
  virtual void createInterface(manageInterface &maninter)=0;
  virtual MElement* createVirtualInterface(IElement *ie) const=0;
  virtual MElement* createInterface(IElement *ie1, IElement *ie2) const=0;
  // Add for BC
  virtual FilterDof* createFilterDof(const int comp) const=0;
#endif
};
#endif
