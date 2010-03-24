#include "dgConservationLaw.h"
#include "function.h"
class dgBoundaryConditionOutsideValue : public dgBoundaryCondition {
  const function *_outsideValueFunction;
  class term : public dataCacheDouble {
    dataCacheMap cacheMapRight; // new cacheMap to  pass to the Riemann solver
    dataCacheDouble &solutionRight;
    dataCacheDouble &outsideValue;
    dataCacheDouble *riemannSolver;
    dgConservationLaw *_claw;
    public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft,const function *outsideValueFunction):
      dataCacheDouble(cacheMapLeft, 1, claw->getNbFields()),
      solutionRight(cacheMapRight.provideSolution(claw->getNbFields())),
      outsideValue(cacheMapLeft.get(outsideValueFunction,this)),
      _claw(claw)
    {
      cacheMapRight.setNbEvaluationPoints(cacheMapLeft.getNbEvaluationPoints());
      riemannSolver=_claw->newRiemannSolver(cacheMapLeft,cacheMapRight);
      if(riemannSolver)
        riemannSolver->addMeAsDependencyOf(this);
    }

    void _eval() {
      solutionRight.set()=outsideValue();
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
    dirichlet(dgConservationLaw *claw, dataCacheMap &cacheMap,const function *outsideValueFunction):
      dataCacheDouble(cacheMap, 1, claw->getNbFields()),
      outsideValue(cacheMap.get(outsideValueFunction,this)){}
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
    maximumDiffusivity(dgConservationLaw *claw, dataCacheMap &cacheMapLeft,const function *outsideValueFunction):
      dataCacheDouble(cacheMapLeft, 1, claw->getNbFields()),
      solutionRight(cacheMapRight.provideSolution(claw->getNbFields())),
      outsideValue(cacheMapLeft.get(outsideValueFunction,this)),
      _claw(claw)
    {
      cacheMapRight.setNbEvaluationPoints(cacheMapLeft.getNbEvaluationPoints());
      maxDif = _claw->newMaximumDiffusivity(cacheMapRight);
      if(maxDif)
        maxDif->addMeAsDependencyOf(this);
    }
    void _eval() {
      if(maxDif){
        solutionRight.set()=outsideValue();
        for(int i=0;i<_value.size1(); i++)
          for(int j=0;j<_value.size2(); j++)
            _value(i,j) = (*maxDif)(i,j);
      }
    }
  };
  public:
  dgBoundaryConditionOutsideValue(dgConservationLaw *claw,const function *outsideValueFunction): dgBoundaryCondition(claw),
    _outsideValueFunction(outsideValueFunction)
  { }
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft,_outsideValueFunction);
  }
  dataCacheDouble *newDiffusiveDirichletBC(dataCacheMap &cacheMapLeft) const {
    return new dirichlet(_claw,cacheMapLeft,_outsideValueFunction);
  }
  dataCacheDouble *newMaximumDiffusivity(dataCacheMap &cacheMapLeft) const {
    return new maximumDiffusivity(_claw,cacheMapLeft,_outsideValueFunction); 
  }
};
class dgBoundaryConditionNeumann : public dgBoundaryCondition {
  const function *_fluxFunction;
  class term : public dataCacheDouble {
    dataCacheDouble &flux;
    public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft,const function *fluxFunction):
      dataCacheDouble(cacheMapLeft,1 ,claw->getNbFields()),
      flux(cacheMapLeft.get(fluxFunction,this))
    {}
    void _eval() {
      for(int i=0;i<_value.size1(); i++)
        for(int j=0;j<_value.size2(); j++)
          _value(i,j) = (flux)(i,j);
    }
  };
  public:
  dgBoundaryConditionNeumann(dgConservationLaw *claw,const function *fluxFunction): dgBoundaryCondition(claw),
    _fluxFunction(fluxFunction)
  { }
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(_claw,cacheMapLeft,_fluxFunction);
  }
};

class dgBoundarySymmetry : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble *riemannSolver;
    dgConservationLaw *_claw;
  public:
    term(dgConservationLaw *claw, dataCacheMap &cacheMapLeft):
      dataCacheDouble(cacheMapLeft, 1,claw->getNbFields()), _claw(claw)
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
      dataCacheDouble(cacheMapLeft,1,claw->getNbFields()) {}
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
dgBoundaryCondition *dgConservationLaw::newOutsideValueBoundary(const function *outsideValueFunction) {
  return new dgBoundaryConditionOutsideValue(this,outsideValueFunction);
}
dgBoundaryCondition *dgConservationLaw::newNeumannBoundary(const function *fluxFunction) {
  return new dgBoundaryConditionNeumann(this,fluxFunction);
}
dgBoundaryCondition *dgConservationLaw::new0FluxBoundary() {
  return new dgBoundaryCondition0Flux(this);
}

class dgBoundaryCondition::neumann_ : public dataCacheDouble {
  dataCacheDouble &normals;
  dataCacheDouble *diffusiveFlux;
public:
  neumann_(dataCacheMap &cacheMap, dgConservationLaw *claw):
    dataCacheDouble(cacheMap,1,claw->getNbFields()),
    normals(cacheMap.getNormals(this))
  {
    diffusiveFlux=claw->newDiffusiveFlux(cacheMap);
    if (diffusiveFlux)diffusiveFlux->addMeAsDependencyOf(this);
  }
  void _eval () { 
    int nbFields = _value.size2();
    const fullMatrix<double> &dfl = (*diffusiveFlux)();
    for(int i=0; i< _value.size1(); i++) {
      for (int k=0;k<_value.size2();k++) { 
        _value(i,k) = 
          dfl(i,k+nbFields*0) *(normals)(0,i) +
          dfl(i,k+nbFields*1) *(normals)(1,i) +
          dfl(i,k+nbFields*2) *(normals)(2,i);
      }
    }
  }
  ~neumann_ () {}
};

dataCacheDouble *dgBoundaryCondition::newDiffusiveDirichletBC(dataCacheMap &cacheMapLeft) const {
  return &cacheMapLeft.getSolution(NULL);
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
