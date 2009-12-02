#include "dgConservationLaw.h"
#include "function.h"
// dp/dt - rho*c^2  div(u,v) = 0
// du/dt + 1/rho  dp/dx = 0
// dv/dt + 1/rho  dp/dy = 0
static double c=1;
static double rho=1;
class dgConservationLawWaveEquation : public dgConservationLaw {
  class hyperbolicFlux : public dataCacheDouble {
    dataCacheDouble &sol;
    public:
    hyperbolicFlux(dataCacheMap &cacheMap):
      sol(cacheMap.get("Solution",this))
      {};
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
        _value=fullMatrix<double>(nQP,9);
      for(int i=0; i< nQP; i++) {
        double p = sol(i,0);
        double u = sol(i,1);
        double v = sol(i,2);
        // flux_x
        _value(i,0) = c*c*rho*u;
        _value(i,1) = p/rho; 
        _value(i,2) = 0;
        // flux_y
        _value(i,3) = c*c*rho*v;
        _value(i,4) = 0;
        _value(i,5) = p/rho;
        // flux_z
        _value(i,6) = 0;
        _value(i,7) = 0;
        _value(i,8) = 0;
      }
    }
  };
  class riemann : public dataCacheDouble {
    dataCacheDouble &normals, &solL, &solR;
    public:
    riemann(dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight):
      normals(cacheMapLeft.get("Normals", this)),
      solL(cacheMapLeft.get("Solution", this)),
      solR(cacheMapRight.get("Solution", this))
      {};
    void _eval () { 
      int nQP = solL().size1();
      if(_value.size1() != nQP)
        _value = fullMatrix<double>(nQP,6);
      for(int i=0; i< nQP; i++) {
        double nx = normals(0,i);
        double ny = normals(1,i);
        double unL = nx*solL(i,1) + ny*solL(i,2);
        double unR = nx*solR(i,1) + ny*solR(i,2);
        double pR = solR(i,0);
        double pL = solL(i,0);

        double pRiemann =  0.5 * (pL+pR + (unL-unR)*(rho*c));
        double unRiemann =  0.5 * (unL+unR + (pL-pR)/(rho*c));

        double Fp = -rho*c*c*unRiemann;
        double Fun = -pRiemann/rho;

        _value(i,0) = Fp;
        _value(i,1) = Fun*nx;
        _value(i,2) = Fun*ny;

        _value(i,3) = -_value(i,0);
        _value(i,4) = -_value(i,1);
        _value(i,5) = -_value(i,2);
      }
    }
  };
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const {
    return new hyperbolicFlux(cacheMap);
  }
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
    return new riemann(cacheMapLeft, cacheMapRight);
  }
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const {
    return 0;
  }
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const {
    return 0;
  }
  dgConservationLawWaveEquation() 
  {
    _nbf = 3; // H U(=Hu) V(=Hv)
  }
};

class dgBoundaryConditionWaveEquationWall : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals;
    public:
    term(dataCacheMap &cacheMap):
    sol(cacheMap.get("Solution",this)),
    normals(cacheMap.get("Normals",this)){}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
        _value = fullMatrix<double>(nQP,3);
      for(int i=0; i< nQP; i++) {
        double nx = normals(0,i);
        double ny = normals(1,i);
        double p = sol(i,0);

        _value(i,0) = 0;
        _value(i,1) = -p/rho*nx;
        _value(i,2) = -p/rho*ny;
      }
    }
  };
  public:
  dgBoundaryConditionWaveEquationWall(){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft);
  }
};

dgConservationLaw *dgNewConservationLawWaveEquation() {
  return new dgConservationLawWaveEquation();
}
dgBoundaryCondition *dgNewBoundaryConditionWaveEquationWall() {
  return new dgBoundaryConditionWaveEquationWall();
}
