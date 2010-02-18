#include "dgConservationLaw.h"
#include "function.h"
class dgBoundaryConditionOutsideValue : public dgBoundaryCondition {
  std::string _outsideValueFunctionName;
  class term : public dataCacheDouble {
    dataCacheMap cacheMapRight; // new cacheMap to  pass to the Riemann solver
    dataCacheDouble &solutionRight;
    dataCacheDouble &outsideValue;
    dataCacheDouble *riemannSolver;
    dgConservationLaw *_claw;
    public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft,const std::string outsideValueFunctionName):
      dataCacheDouble(cacheMapLeft, cacheMapLeft.getNbEvaluationPoints(),claw->getNbFields()),
      cacheMapRight(cacheMapLeft.getNbEvaluationPoints()),
      solutionRight(cacheMapRight.provideData("Solution")),
      outsideValue(cacheMapLeft.get(outsideValueFunctionName,this)),
      _claw(claw)
    {
      riemannSolver=_claw->newRiemannSolver(cacheMapLeft,cacheMapRight);
      if(riemannSolver)
        riemannSolver->addMeAsDependencyOf(this);
    }

    void _eval() {
      solutionRight.set(outsideValue());
      if(riemannSolver){
        for(int i=0;i<_value.size1(); i++)
          for(int j=0;j<_value.size2(); j++)
            _value(i,j) = (*riemannSolver)(i,j);
      }
    }
  };
  class dirichlet : public dataCacheDouble {
    dataCacheDouble &outsideValue;
    public:
    dirichlet(dgConservationLaw *claw, dataCacheMap &cacheMap,const std::string outsideValueFunctionName):
      dataCacheDouble(cacheMap, cacheMap.getNbEvaluationPoints(),claw->getNbFields()),
      outsideValue(cacheMap.get(outsideValueFunctionName,this)){}
    void _eval () { 
      for(int i=0;i<_value.size1();i++)
        for(int j=0;j<_value.size2();j++)
          _value(i,j)=outsideValue(i,j);
    }
  };
  class maximumDiffusivity : public dataCacheDouble {
    dataCacheMap cacheMapRight; // new cacheMap to  pass to the Riemann solver
    dataCacheDouble &solutionRight;
    dataCacheDouble &outsideValue;
    dataCacheDouble *maxDif;
    dgConservationLaw *_claw;
    public:
    maximumDiffusivity(dgConservationLaw *claw, dataCacheMap &cacheMapLeft,const std::string outsideValueFunctionName):
      dataCacheDouble(cacheMapLeft, cacheMapLeft.getNbEvaluationPoints(),claw->getNbFields()),
      cacheMapRight(cacheMapLeft.getNbEvaluationPoints()),
      solutionRight(cacheMapRight.provideData("Solution")),
      outsideValue(cacheMapLeft.get(outsideValueFunctionName,this)),
      _claw(claw)
    {
      maxDif = _claw->newMaximumDiffusivity(cacheMapRight);
      if(maxDif)
        maxDif->addMeAsDependencyOf(this);
    }
    void _eval() {
      if(maxDif){
        solutionRight.set(outsideValue());
        for(int i=0;i<_value.size1(); i++)
          for(int j=0;j<_value.size2(); j++)
            _value(i,j) = (*maxDif)(i,j);
      }
    }
  };
  public:
  dgBoundaryConditionOutsideValue(dgConservationLaw *claw,const std::string outsideValueFunctionName): dgBoundaryCondition(claw),
    _outsideValueFunctionName(outsideValueFunctionName)
  { }
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft,_outsideValueFunctionName);
  }
  dataCacheDouble *newDiffusiveDirichletBC(dataCacheMap &cacheMapLeft) const {
    return new dirichlet(_claw,cacheMapLeft,_outsideValueFunctionName);
  }
  dataCacheDouble *newMaximumDiffusivity(dataCacheMap &cacheMapLeft) const {
    return new maximumDiffusivity(_claw,cacheMapLeft,_outsideValueFunctionName); 
  }
};
class dgBoundaryConditionNeumann : public dgBoundaryCondition {
  std::string _fluxFunctionName;
  class term : public dataCacheDouble {
    dataCacheDouble &flux;
    public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft,const std::string fluxFunctionName):
      dataCacheDouble(cacheMapLeft, cacheMapLeft.getNbEvaluationPoints(),claw->getNbFields()),
      flux(cacheMapLeft.get(fluxFunctionName,this))
    {}
    void _eval() {
      for(int i=0;i<_value.size1(); i++)
        for(int j=0;j<_value.size2(); j++)
          _value(i,j) = (flux)(i,j);
    }
  };
  public:
  dgBoundaryConditionNeumann(dgConservationLaw *claw,const std::string fluxFunctionName): dgBoundaryCondition(claw),
    _fluxFunctionName(fluxFunctionName)
  { }
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft,_fluxFunctionName);
  }
};

class dgBoundarySymmetry : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble *riemannSolver;
    dgConservationLaw *_claw;
  public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft):
      dataCacheDouble(cacheMapLeft, cacheMapLeft.getNbEvaluationPoints(),claw->getNbFields()), _claw(claw)
    {
      riemannSolver=_claw->newRiemannSolver(cacheMapLeft,cacheMapLeft);
      riemannSolver->addMeAsDependencyOf(this);
    }
    
    void _eval() {
      if(riemannSolver){
        for(int i=0;i<_value.size1(); i++)
          for(int j=0;j<_value.size2(); j++)
            _value(i,j) = (*riemannSolver)(i,j);
      }
    }
  };
public:
  dgBoundarySymmetry(dgConservationLaw *claw): dgBoundaryCondition(claw) {}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft);
  }
};

class dgBoundaryCondition0Flux : public dgBoundaryCondition {
  class term : public dataCacheDouble {
  public:
    term(dgConservationLaw *claw,dataCacheMap &cacheMapLeft):
      dataCacheDouble(cacheMapLeft,cacheMapLeft.getNbEvaluationPoints(),claw->getNbFields()) {}
    void _eval() {
    }
  };
public:
  dgBoundaryCondition0Flux(dgConservationLaw *claw): dgBoundaryCondition(claw) {}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft);
  }
};

dgBoundaryCondition *dgConservationLaw::newSymmetryBoundary() {
  return new dgBoundarySymmetry(this);
}
dgBoundaryCondition *dgConservationLaw::newOutsideValueBoundary(const std::string outsideValueFunctionName) {
  return new dgBoundaryConditionOutsideValue(this,outsideValueFunctionName);
}
dgBoundaryCondition *dgConservationLaw::newNeumannBoundary(const std::string fluxFunctionName) {
  return new dgBoundaryConditionNeumann(this,fluxFunctionName);
}
dgBoundaryCondition *dgConservationLaw::new0FluxBoundary() {
  return new dgBoundaryCondition0Flux(this);
}


class dgBoundaryCondition::dirichlet_ : public dataCacheDouble {
  dataCacheDouble &sol;
public:
  dirichlet_(dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap),
    sol(cacheMap.get("Solution",this)){}
  void _eval () { 
    int nQP = sol().size1();
    if(_value.size1() != nQP)
      _value = fullMatrix<double>(nQP,sol().size2());
    for(int i=0; i< nQP; i++) 
      for (int k=0;k<sol().size2();k++) 
	_value(i,k) = sol(i,k);
  }
};

class dgBoundaryCondition::neumann_ : public dataCacheDouble {
  dgConservationLaw *_claw;
  dataCacheDouble &sol,&normals;
  dataCacheDouble *diffusiveFlux;
public:
  neumann_(dataCacheMap &cacheMap, dgConservationLaw *claw):
    dataCacheDouble(cacheMap),
    _claw (claw),
    sol(cacheMap.get("Solution",this)),
    normals(cacheMap.get("Normals",this)){
    diffusiveFlux=_claw->newDiffusiveFlux(cacheMap);
    if (diffusiveFlux)diffusiveFlux->addMeAsDependencyOf(this);
  }
  void _eval () { 
    int nQP = sol().size1();
    if(_value.size1() != nQP)
      _value = fullMatrix<double>(nQP,sol().size2());
    
    const fullMatrix<double> &dfl = (*diffusiveFlux)();
    
    for(int i=0; i< nQP; i++) {
      for (int k=0;k<sol().size2();k++) { 
	_value(i,k) = 
	  dfl(i,k+sol().size2()*0) *normals(0,i) +
	  dfl(i,k+sol().size2()*1) *normals(1,i) +
	  dfl(i,k+sol().size2()*2) *normals(2,i);
      }
    }
  }
  ~neumann_ () {}
};

dataCacheDouble *dgBoundaryCondition::newDiffusiveDirichletBC(dataCacheMap &cacheMapLeft) const {
  return new dirichlet_(cacheMapLeft);
}
dataCacheDouble *dgBoundaryCondition::newDiffusiveNeumannBC(dataCacheMap &cacheMapLeft) const {
  return new dgBoundaryCondition::neumann_(cacheMapLeft, _claw);
}


#include "Bindings.h"

void dgConservationLaw::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgConservationLaw>("dgConservationLaw");
  cb->setDescription("A conservation law is defined a convective flux (f), a diffusive flux(g), a source term(r) and a set of boundary conditions.\n\\partial_t L(u) =   \\nabla \\cdot (\\vec{f}(u,forcings)) + \\nabla \\cdot (\\vec{g}(u,\\nabla u,forcings) + r(u,forcings).");
  methodBinding *cm;
  cm = cb->addMethod("addBoundaryCondition",&dgConservationLaw::addBoundaryCondition);
  cm->setDescription("Use the boundary condition 'bc' for interface tagged with 'tag',");
  cm->setArgNames("tag","bc",NULL);
  cm = cb->addMethod("new0FluxBoundary",&dgConservationLaw::new0FluxBoundary);
  cm->setDescription("Create a new boundary condition which set to 0 all the fluxes through the interfaces.");
  cm = cb->addMethod("newSymmetryBoundary",&dgConservationLaw::newSymmetryBoundary);
  cm->setDescription("Create a new boundary condition using the values computed inside the domain as boundary values. (In practice, the fluxes are computed with the Riemann solver of this equation using the internal values as internal AND external values.)");
  cm = cb->addMethod("newOutsideValueBoundary",&dgConservationLaw::newOutsideValueBoundary);
  cm->setDescription("Create a new boundary condition which compute the fluxes using the Riemann solver using the 'outsideFunction' function to compute external values.");
  cm->setArgNames("outsideFunction",NULL);
  cm = cb->addMethod("newNeumannBoundary",&dgConservationLaw::newNeumannBoundary);
  cm->setDescription("Create a new boundary condition with a given flux (no other fluxes will be computed, nor with the rieman solver nor the IP diffusive term");
  cm->setArgNames("flux",NULL);
  cm = cb->addMethod("getNbFields",&dgConservationLaw::getNbFields);
  cm->setDescription("Return the number of fields composing the unknowns of this conservation law. For vectorial fields, each components is counted as one field.");
}

void dgBoundaryCondition::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgBoundaryCondition>("dgBoundaryCondition");
  cb->setDescription("A boundary condition of a conservation law. Boundary conditions should be associated with tag using dgConservationLaw::addBoundaryCondition.");
}
