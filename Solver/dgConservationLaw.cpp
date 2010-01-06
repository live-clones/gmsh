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
      dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),claw->nbFields()),
      cacheMapRight(cacheMapLeft.getNbEvaluationPoints()),
      solutionRight(cacheMapRight.provideData("Solution")),
      outsideValue(cacheMapLeft.get(outsideValueFunctionName,this)),
      _claw(claw)
    {
      riemannSolver=_claw->newRiemannSolver(cacheMapLeft,cacheMapRight);
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
  public:
  dgBoundaryConditionOutsideValue(dgConservationLaw *claw,const std::string outsideValueFunctionName): dgBoundaryCondition(claw),
    _outsideValueFunctionName(outsideValueFunctionName)
  { }
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft,_outsideValueFunctionName);
  }
};

class dgBoundarySymmetry : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble *riemannSolver;
    dgConservationLaw *_claw;
  public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft):
      dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),claw->nbFields()), _claw(claw)
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
      dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),claw->nbFields()) {}
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
dgBoundaryCondition *dgConservationLaw::new0FluxBoundary() {
  return new dgBoundaryCondition0Flux(this);
}


class dgBoundaryCondition::dirichlet_ : public dataCacheDouble {
  dataCacheDouble &sol;
public:
  dirichlet_(dataCacheMap &cacheMap):
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
  ~neumann_ () {if (diffusiveFlux)delete diffusiveFlux;}
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
  cb->addMethod("addBoundaryCondition",&dgConservationLaw::addBoundaryCondition);
  cb->addMethod("new0FluxBoundary",&dgConservationLaw::new0FluxBoundary);
  cb->addMethod("newSymmetryBoundary",&dgConservationLaw::newSymmetryBoundary);
  cb->addMethod("newOutsideValueBoundary",&dgConservationLaw::newOutsideValueBoundary);
}

void dgBoundaryCondition::registerBindings(binding *b){
  classBinding *cb = b->addClass<dgBoundaryCondition>("dgBoundaryCondition");
}
