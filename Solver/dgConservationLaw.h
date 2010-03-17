#ifndef _DG_CONSERVATION_LAW_H_
#define _DG_CONSERVATION_LAW_H_

/*
  \partial_t L(u) =   \nabla \cdot (\vec{f}(u,forcings))  -> convective flux f
                    + \nabla \cdot (\vec{g}(u,\nabla u,forcings)  -> diffusive flux g
		    + r(u,forcings)                       -> source term r
*/
#include "fullMatrix.h"
class dataCacheDouble;
class dataCacheMap;
class function;

class dgConservationLaw;
class binding;

class dgBoundaryCondition {
  class neumann_;
  class dirichlet_;
 protected:
  dgConservationLaw *_claw;
 public:
  dgBoundaryCondition (dgConservationLaw *claw)  : _claw(claw){}
  virtual ~dgBoundaryCondition () {}
  virtual dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const = 0;
  virtual dataCacheDouble *newDiffusiveNeumannBC(dataCacheMap &cacheMapLeft) const;
  virtual dataCacheDouble *newDiffusiveDirichletBC(dataCacheMap &cacheMapLeft) const;
  virtual dataCacheDouble *newMaximumDiffusivity(dataCacheMap &cacheMapLeft)const {return NULL;}
  static void registerBindings(binding *b);
};

class dgConservationLaw {
  std::map<const std::string,dgBoundaryCondition*> _boundaryConditions;
 protected :
  int _nbf;
 public:
  virtual ~dgConservationLaw () {}

  int getNbFields() const {return _nbf;}

  virtual dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const {return NULL;} 
  virtual dataCacheDouble *newDiffusiveFlux (dataCacheMap &cacheMap) const {return NULL;} 
  virtual dataCacheDouble *newDiffusiveInterfaceTerm (dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {return NULL;} 
  virtual dataCacheDouble *newMaximumDiffusivity (dataCacheMap &cacheMap) const {return NULL;} 
  virtual dataCacheDouble *newConvectiveFlux (dataCacheMap &cacheMap) const {return NULL;}
  virtual dataCacheDouble *newMaxConvectiveSpeed (dataCacheMap &cacheMap) const {return NULL;}
  virtual dataCacheDouble *newRiemannSolver (dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {return NULL;}
  virtual dataCacheDouble *newBifurcationRiemannSolver (dataCacheMap &cacheMap0, dataCacheMap &cacheMap1, dataCacheMap &cacheMap2) const {return NULL;}
  virtual dataCacheDouble *newClipToPhysics (dataCacheMap &cacheMap) const {return NULL;}

  inline const dgBoundaryCondition *getBoundaryCondition(const std::string tag) const {
    std::map<const std::string,dgBoundaryCondition*>::const_iterator it = _boundaryConditions.find(tag);
    if(it==_boundaryConditions.end()) {
      Msg::Error("no boundary condition defined with tag '%s'", tag.c_str());
      throw;
    }
    return it->second;
  }

  void addBoundaryCondition(std::string tag, dgBoundaryCondition * condition) {
    if(_boundaryConditions.find(tag)!=_boundaryConditions.end())
      throw;
    _boundaryConditions[tag]=condition;
  }

  //a generic boundary condition using the Riemann solver of the conservation Law
  dgBoundaryCondition *newOutsideValueBoundary(const function *outsideValueFunction);
  dgBoundaryCondition *newNeumannBoundary(const function *fluxFunction);
  dgBoundaryCondition *new0FluxBoundary();
  dgBoundaryCondition *newSymmetryBoundary();

  static void registerBindings(binding *b);
};

dgConservationLaw *dgNewPerfectGasLaw2d();

dgBoundaryCondition *dgNewBoundaryConditionPerfectGasLaw2dWall();
dgBoundaryCondition *dgNewBoundaryConditionPerfectGasLaw2dFreeStream(std::string&);


#endif
