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
            _value(i,j) = (*riemannSolver)(i,j*2);
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

dgBoundaryCondition *dgBoundaryCondition::newOutsideValueCondition(dgConservationLaw &claw,const std::string outsideValueFunctionName) {
  return new dgBoundaryConditionOutsideValue(claw,outsideValueFunctionName);
}
dgBoundaryCondition *dgBoundaryCondition::new0FluxCondition(dgConservationLaw &claw) {
  return new dgBoundaryCondition0Flux(claw);
}

