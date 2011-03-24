// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _DGC0SHELL_SOLVER_H_
#define _DGC0SHELL_SOLVER_H_
#ifndef SWIG
#include <map>
#include <string>
#include "SVector3.h"
#include "dofManager.h"
#include "simpleFunction.h"
#include "functionSpace.h"
#include "MInterfaceElement.h"
#include "groupOfElements.h"
#include "partDomain.h"
#include "explicitHulbertChung.h"
#include "contactDomain.h"


class PView;
class groupOfElements;
class binding;
class unknownField;
class unknownDynamicField;
class IPField;
template<class T1,class T2> class DgC0BilinearTerm;
template<class T1> class DgC0LinearTerm;

struct archiveForce{
  int numphys;
  int dim;
  int comp;
  archiveForce() : numphys(0), dim(0), comp(0){}
  archiveForce(const archiveForce &source){
    numphys = source.numphys;
    dim = source.dim;
    comp = source.comp;
  }
  archiveForce(int np, int d, int c) : numphys(np), dim(d), comp(c){}
  ~archiveForce(){}
};

struct archiveRigidContactDisp{
  int _physmaster;
  int _comp;
  FilterDof *_fdof;
  initialCondition::whichCondition _wc;
  archiveRigidContactDisp() : _physmaster(0), _comp(0), _wc(initialCondition::position), _fdof(NULL){}
  archiveRigidContactDisp(const int nphys, const int cmp,
                          initialCondition::whichCondition wc, partDomain *dom) : _physmaster(nphys), _comp(cmp), _wc(wc)
  {
    // change this HOW
    _fdof = dom->createFilterDof(cmp);
  }
  archiveRigidContactDisp(const archiveRigidContactDisp &source){
    _physmaster = source._physmaster;
    _comp = source._comp;
    _wc = source._wc;
    _fdof = source._fdof;
  }
  ~archiveRigidContactDisp(){}
};

struct archiveIPVariable{
  int numphys; // physical number of the node
  int ipval;   // num of the component to archive // must be defined for each ipvariable
  archiveIPVariable() : numphys(0), ipval(0){}
  archiveIPVariable(const archiveIPVariable &source){
    numphys = source.numphys;
    ipval = source.ipval;
  }
  archiveIPVariable(const int numphys_, const int ipval_) : numphys(numphys_), ipval(ipval_){}
  ~archiveIPVariable(){}
};

struct fextPrescribedDisp{
  Dof D;
  double val;
  fextPrescribedDisp(Dof D_) : D(D_), val(0.){}
  fextPrescribedDisp(const fextPrescribedDisp &source) : D(source.D){
    val = source.val;
  }
};
#endif
class nonLinearMechSolver
{
 public:
  typedef std::set<contactDomain*> contactContainer;
 protected:
  GModel *pModel;
  int _dim, _tag;
  dofManager<double> *pAssembler;
//  dgGroupCollection _groups;
  std::vector<partDomain*> domainVector;
  contactContainer _allContact;
  // contact

  // neumann BC
  std::vector<nonLinearNeumannBC> allNeumann;
  // dirichlet BC
  std::vector<nonLinearDirichletBC> allDirichlet;

  // initial BC
  std::vector<initialCondition> allinitial;

  // neumann BC theta (weak enforcement of rotation) regroup this with allNeumann
  std::vector<nonLinearNeumannBC> allTheta;

  // dirichlet BC on rigid surface (prescribed the motion of gravity center)
  std::vector<rigidContactBC> allContactBC;

  // set with virtual interfaceElements used to prescribed BC put this in an other place ??
  std::map<int,groupOfElements> mapvinter;

  // vector with material law
  std::map<int,materialLaw*> maplaw;
  // physical entities that are initialy broken
  std::vector<int> initbrokeninter;

  // map to archive force
  std::map<int,std::vector<Dof> > aef;
  std::map<int,double> aefvalue;
  std::vector<fextPrescribedDisp> _allaef;
  // std vector to archive a node displacement
  std::vector<std::pair<Dof,initialCondition::whichCondition> > anoded;
  // std::vector to archive a force (info musy be store before creation because functionSpace are not initialize)
  std::vector<archiveForce> vaf;
  // std vector to archive ipvariable
  std::vector<archiveIPVariable> vaip;
  // std vector to archive rigid contact disp
  std::vector<archiveRigidContactDisp> varcd;

  // specific data
  int numstep; // Number of step not used for StaticLinearScheme and number of step between time step evaluation for Explicit Scheme
  double endtime; // final time not used for StaticLinearScheme but it is not necesary to derive class because (small useless data)
  double _tol; // relative tolerance for iteration not used for StaticLinearScheme but it is not necesary to derive class because (small useless data)
  int nsba; // number of step between 2 archiving (=1 by default)

  // specific data for explicit scheme
  double _beta, _gamma, _alpham, _gammas, _rhoinfty;

  // File name for restart or initial value
  std::string initOrResartfname;
  bool _restart;

  // Function to initiate the solver before solve
  // (create interfaceElement and link the materialLaw and dgLinearShellDomain)
#ifndef SWIG
  void init();
  void initTerms(unknownField *ufield, IPField *ipf);

  // Split Boundary Condition Between the different partDomain
  void splitBoundaryConditions();

  // Function used by non linear solver
  void NewtonRaphson(linearSystem<double> *lsys, dofManager<double> *pAssembler, unknownField *ufield,
                     IPField *ipf,const double time);

  double computeNorm0(linearSystem<double> *lsys, dofManager<double> *pAssembler, unknownField *ufield,
                      IPField *ipf);

  double computeRightHandSide(linearSystem<double> *lsys, dofManager<double> *pAssembler, unknownField *ufield,
                                    IPField *ipf);

  void computeStiffMatrix(const unknownField *ufield);
  void computeExternalForces(IPField *ipf, const unknownField *ufield);
  void computeContactForces();
  void computeInternalForces(unknownField *ufield);
  void fixNodalDofs();
  void numberDofs(linearSystem<double> *lsys);
  void insertTheta(const int numphys, groupOfElements *goe);
  double criticalExplicitTimeStep(unknownField *ufield);
  void setInitialCondition();
  void setTimeForBC(double time);
  void initArchiveForce();
  void initContactInteraction();
#endif
 public : //protected with lua ??
  enum solver{ Gmm=0,Taucs=1,Petsc=2};
  enum scheme{StaticLinear=0, StaticNonLinear=1, Explicit=2};
  solver whatSolver; //  Solver used to solve
  scheme whatScheme; // scheme used to solve equation
 public:
  nonLinearMechSolver(int tag) : _tag(tag), pAssembler(0), numstep(1), endtime(1.), _tol(1.e-6), nsba(1),
                             whatSolver(nonLinearMechSolver::Gmm), whatScheme(nonLinearMechSolver::StaticLinear),
                             _beta(0.), _gamma(0.5), _alpham(0.), _rhoinfty(1.), initOrResartfname(""), _restart(false)
  {} // default Gmm and static linear scheme

  virtual ~nonLinearMechSolver()
  {
    if (pAssembler) delete pAssembler;
//    for(std::map<int,materialLaw*>::iterator it = maplaw.begin(); it!=maplaw.end();++it){ delete it->second;}
    // I can't delete or problem at the end since swig.
//    for(std::vector<partDomain*>::iterator it = domainVector.begin(); it!=domainVector.end(); ++it){delete *it;}
  }
#ifndef SWIG
  int getStepBetweenArchiving() const{return nsba;}
  int getNumStep() const{return numstep;}
  double getEndTime() const{return endtime;}
  scheme getScheme() const{return whatScheme;}
  virtual void solveStaticLinar();
  virtual void solveSNL();
  virtual void solveExplicit();
  virtual void createInterfaceElement();
  virtual materialLaw* getMaterialLaw(const int num);
  // create interfaceelement with dgGoupOfElement from dg project doesn't work (segmentation fault)
  virtual void createInterfaceElement_2();
#endif
  // functions for lua interaction
  void loadModel(const std::string meshFileName);
  virtual void solve();
//  virtual void addDgLinearElasticShellDomain(dgLinearShellDomain* dom);
//  virtual void addInterShellDomain(interDomainBetweenShell *dom);
  virtual void addDomain(partDomain *dom);
//  virtual void addDomain(dgLinearShellDomain* dom);
  virtual void addMaterialLaw(materialLaw *mlaw);
//  virtual void addLinearElasticShellLaw(linearElasticShellLaw *mlaw);
//  virtual void addShellLinearCohesiveLaw(shellLinearCohesiveLaw *mlaw);
//  virtual void addLinearElasticOrthotropicShellLaw(linearElasticOrthotropicShellLaw *mlaw);
//  virtual void addshellFractureByCohesiveLaw(shellFractureByCohesiveLaw *mlaw);
  void Solver(const int s){whatSolver= (solver)s;}
  void Scheme(const int s){whatScheme=(scheme)s;}
  void snlData(const int ns, const double et, const double reltol);
  void explicitData(const double ftime, const double gams=0.666667, const double beta=0, const double gamma=0.5, const double alpham=0.);
  void explicitSpectralRadius(const double ftime,const double gams=0.666667,const double rho=1.);
  void explicitTimeStepEvaluation(const int nst);
  void stepBetweenArchiving(const int n){nsba = n;}
  virtual void thetaBC(const int numphys);
  virtual void displacementBC(std::string onwhat, const int numphys, const int comp, const double value);
  virtual void displacementRigidContactBC(const int numphys, const int comp,const double value);
  virtual void initialBC(std::string onwhat, std::string whichC, const int numphys, const int comp, const double value);
  virtual void forceBC(std::string onwhat, const int numphys, const int comp, const double val);
  virtual void independentDisplacementBC(std::string onwhat, const int numphys, const int comp, const double value);
  virtual void independentForceBC(std::string onwhat, const int numphys, const int comp, const double val);
  virtual void blastPressureBC(const int numphys,const double p0,const double p1, const double plexp, const double t0, const double t1);
  virtual void pressureOnPhysicalGroupBC(const int numphys, const double press, const double p0);
  virtual void archivingForceOnPhysicalGroup(const std::string onwhat, const int numphys, const int comp);
  virtual void archivingNodeDisplacement(const int num, const int comp);
  virtual void archivingNodeVelocity(const int num, const int comp);
  virtual void archivingNodeAcceleration(const int num, const int comp);
  virtual void archivingNode(const int num, const int comp, initialCondition::whichCondition);
  virtual void archivingNodeIP(const int numphys, const int ipval);
  virtual void physInitBroken(const int phys);
  virtual void setInitOrRestartFileName(const std::string fname);
  virtual void restart(unknownField *ufield);
  virtual void contactInteraction(contactDomain *cdom);
  virtual void archivingRigidContact(const int numphys, const int comp, const int wc=0);
};


#endif // nonLinearMechSolver

