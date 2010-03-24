
#include "dgConservationLaw.h"
#include "dgConservationLawWaveEquation.h"
#include "function.h"

static double c=1;
static double rho=1;

class dgConservationLawWaveEquation::hyperbolicFlux : public dataCacheDouble {
  dataCacheDouble &sol;
  const int _DIM,_nbf;    
  public:
  hyperbolicFlux(dataCacheMap &cacheMap,int DIM):
    dataCacheDouble(cacheMap,1,3*(DIM+1)),
    sol(cacheMap.get(function::getSolution(), this)),_DIM(DIM),_nbf(DIM+1)
  {};
  void _eval () {
    int nQP = sol().size1();
    _value.scale(0.);
    for(int i=0; i< nQP; i++) {
      const double p = sol(i,0);        
      for (int j=0;j<_DIM;j++){
        _value(i,0  +j*_nbf) = c*c*rho*sol(i,j+1);
        _value(i,j+1+j*_nbf) = p/rho;
      }
    }
  }
};

class dgConservationLawWaveEquation::maxConvectiveSpeed : public dataCacheDouble {
  dataCacheDouble &sol;
  public:
  maxConvectiveSpeed(dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap,1,1),
    sol(cacheMap.get(function::getSolution(), this))
  {
  };
  void _eval () {
    _value.setAll(c);
  }
};

class dgConservationLawWaveEquation::riemann : public dataCacheDouble {
  dataCacheDouble &normals, &solL, &solR;
  const int _DIM,_nbf;
  public:
  riemann(dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight, int DIM):
    dataCacheDouble(cacheMapLeft,1,2*(DIM+1)),
    normals(cacheMapLeft.get(function::getNormals(), this)),
    solL(cacheMapLeft.get(function::getSolution(), this)),
    solR(cacheMapRight.get(function::getSolution(), this)),
    _DIM(DIM),_nbf(DIM+1)
  {};
  void _eval () { 
    int nQP = solL().size1();
    for(int i=0; i< nQP; i++) {
      const double n[3] = {normals(0,i),normals(1,i),normals(2,i)};
      double unL=0,unR=0;
      for (int j=0;j<_DIM;j++){   
        unL += n[j]*solL(i,j+1);
        unR += n[j]*solR(i,j+1);
      }
      double pR = solR(i,0);
      double pL = solL(i,0);

      double pRiemann  =  0.5 * (pL+pR + (unL-unR)*(rho*c));
      double unRiemann =  0.5 * (unL+unR + (pL-pR)/(rho*c));

      double Fp = -rho*c*c*unRiemann;
      double Fun = -pRiemann/rho;

      _value(i,0) = Fp;
      for (int j=0;j<_DIM;j++)
        _value(i,j+1) = Fun*n[j];
      for (int j=0;j<_nbf;j++)
        _value(i,j+_nbf) = -_value(i,j);        
    }
  }
};
dataCacheDouble *dgConservationLawWaveEquation::newConvectiveFlux( dataCacheMap &cacheMap) const {
  return new hyperbolicFlux(cacheMap,_DIM);
}
dataCacheDouble *dgConservationLawWaveEquation::newMaxConvectiveSpeed( dataCacheMap &cacheMap) const {
  return new maxConvectiveSpeed(cacheMap);
}
dataCacheDouble *dgConservationLawWaveEquation::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  return new riemann(cacheMapLeft, cacheMapRight,_DIM);
}
dataCacheDouble *dgConservationLawWaveEquation::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  return 0;
}
dataCacheDouble *dgConservationLawWaveEquation::newSourceTerm (dataCacheMap &cacheMap) const {
  return 0;
}
dgConservationLawWaveEquation::dgConservationLawWaveEquation(int DIM) : _DIM(DIM)
{
  _nbf = 1 + _DIM; // H U(=Hu) V(=Hv)
}

class dgBoundaryConditionWaveEquationWall : public dgBoundaryCondition {
  int _DIM;
  class term : public dataCacheDouble {
    int _DIM;
    dataCacheDouble &sol,&normals;    
    public:
    term(dataCacheMap &cacheMap, int DIM):
      dataCacheDouble(cacheMap,1,DIM+1),
      sol(cacheMap.get(function::getSolution(), this)),
      normals(cacheMap.get(function::getNormals(), this)),
      _DIM(DIM){}
    void _eval () { 
      int nQP = sol().size1();
      for(int i=0; i< nQP; i++) {
        const double n[3] = {normals(0,i),normals(1,i),normals(2,i)};
        double p = sol(i,0);    
        _value(i,0) = 0;
        for (int j=0;j<_DIM;j++)
          _value(i,j+1) = -p/rho*n[j];
      }
    }
  };
  public:
  dgBoundaryConditionWaveEquationWall(int DIM, dgConservationLaw *claw):_DIM(DIM),dgBoundaryCondition(claw){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft,_DIM);
  }
};
dgBoundaryCondition *dgConservationLawWaveEquation::newBoundaryWall(){
  return new dgBoundaryConditionWaveEquationWall(_DIM, this);
}

#include "Bindings.h"
void dgConservationLawWaveEquationRegisterBindings(binding *b){
  classBinding *cb = b->addClass<dgConservationLawWaveEquation> ("dgConservationLawWaveEquation");
  cb->setDescription("Solve the wave equation in dimension 1, 2 or 3.)");
  methodBinding *cm;
  cm = cb->addMethod("newBoundaryWall",&dgConservationLawWaveEquation::newBoundaryWall);
  cm->setDescription("wall boundary");
  cm = cb->setConstructor<dgConservationLawWaveEquation,int>();
  cm->setArgNames("d",NULL);
  cm->setDescription("New wave equation of dimension 'd'");

  cb->setParentClass<dgConservationLaw>();
}
