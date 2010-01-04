#include "dgConservationLaw.h"
#include "function.h"
class dgBoundaryConditionOutsideValue : public dgBoundaryCondition {
  dgConservationLaw &_claw;
  std::string _outsideValueFunctionName;
  class term : public dataCacheDouble {
    dataCacheMap cacheMapRight; // new cacheMap to  pass to the Riemann solver
    dataCacheDouble &solutionRight;
    dataCacheDouble &outsideValue;
    dataCacheDouble *riemannSolver;
    dgConservationLaw &_claw;
    public:
    term(dgConservationLaw &claw, dataCacheMap &cacheMapLeft,const std::string outsideValueFunctionName):
      dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),claw.nbFields()),
      cacheMapRight(cacheMapLeft.getNbEvaluationPoints()),
      solutionRight(cacheMapRight.provideData("Solution")),
      outsideValue(cacheMapLeft.get(outsideValueFunctionName,this)),
      _claw(claw)
    {
      riemannSolver=_claw.newRiemannSolver(cacheMapLeft,cacheMapRight);
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
  dgBoundaryConditionOutsideValue(dgConservationLaw &claw,const std::string outsideValueFunctionName): _claw(claw),
    _outsideValueFunctionName(outsideValueFunctionName)
  { }
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft,_outsideValueFunctionName);
  }
};

class dgBoundarySymmetry : public dgBoundaryCondition {
  dgConservationLaw &_claw;
  class term : public dataCacheDouble {
    dataCacheDouble *riemannSolver;
    dgConservationLaw &_claw;
    public:
    term(dgConservationLaw &claw, dataCacheMap &cacheMapLeft):
      dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),claw.nbFields()), _claw(claw)
    {
      riemannSolver=_claw.newRiemannSolver(cacheMapLeft,cacheMapLeft);
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
  dgBoundarySymmetry(dgConservationLaw &claw): _claw(claw) {}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft);
  }
};

class dgBoundaryCondition0Flux : public dgBoundaryCondition {
  dgConservationLaw &_claw;
  class term : public dataCacheDouble {
    public:
    term(dgConservationLaw &claw,dataCacheMap &cacheMapLeft):
    dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),claw.nbFields()) {}
    void _eval() {
    }
  };
  public:
  dgBoundaryCondition0Flux(dgConservationLaw &claw): _claw(claw) {}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft);
  }
};

dgBoundaryCondition *dgConservationLaw::newSymmetryBoundary() {
  return new dgBoundarySymmetry(*this);
}
dgBoundaryCondition *dgConservationLaw::newOutsideValueBoundary(const std::string outsideValueFunctionName) {
  return new dgBoundaryConditionOutsideValue(*this,outsideValueFunctionName);
}
dgBoundaryCondition *dgConservationLaw::new0FluxBoundary() {
  return new dgBoundaryCondition0Flux(*this);
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
