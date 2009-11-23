#include "dgConservationLaw.h"
#include "function.h"
class dgBoundaryCondition0Out : public dgBoundaryCondition {
  dgConservationLaw &_claw;
  class term : public dataCacheDouble {
    dataCacheMap cacheMapRight; // new cacheMap to  pass to the Riemann solver
    dataCacheDouble &solutionRight;
    dataCacheDouble &solutionLeft;
    dataCacheDouble *riemannSolver;
    dgConservationLaw &_claw;
    public:
    term(dgConservationLaw &claw, dataCacheMap &cacheMapLeft):
      solutionRight(cacheMapRight.provideData("Solution")),
      solutionLeft(cacheMapLeft.get("Solution",this)),
      _claw(claw)
    {
      riemannSolver=_claw.newRiemannSolver(cacheMapLeft,cacheMapRight);
    }

    void _eval() {
      if(_value.size1()!=solutionLeft().size1()){
        //adjust sizes
        solutionRight.set(fullMatrix<double>(solutionLeft().size1(),_claw.nbFields()));
        _value = fullMatrix<double>(solutionLeft().size1(),_claw.nbFields());
      }
      for(int i=0;i<_value.size1(); i++)
        for(int j=0;j<_value.size2(); j++)
          _value(i,j) = (*riemannSolver)(i,j*2);
    }
  };
  public:
  dgBoundaryCondition0Out(dgConservationLaw &claw): _claw(claw) {}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft);
  }
};

class dgBoundaryCondition0Flux : public dgBoundaryCondition {
  dgConservationLaw &_claw;
  class term : public dataCacheDouble {
    dataCacheDouble &UVW;
    dgConservationLaw &_claw;
    public:
    term(dgConservationLaw &claw,dataCacheMap &cacheMapLeft): UVW(cacheMapLeft.get("UVW",this)),_claw(claw) {}
    void _eval() {
      if(_value.size1()!=UVW().size1()){
        //adjust sizes
        _value = fullMatrix<double>(UVW().size1(),_claw.nbFields());
      }
    }
  };
  public:
  dgBoundaryCondition0Flux(dgConservationLaw &claw): _claw(claw) {}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft);
  }
};

dgBoundaryCondition *dgBoundaryCondition::new0OutCondition(dgConservationLaw &claw) {
  return new dgBoundaryCondition0Out(claw);
}
dgBoundaryCondition *dgBoundaryCondition::new0FluxCondition(dgConservationLaw &claw) {
  return new dgBoundaryCondition0Flux(claw);
}

