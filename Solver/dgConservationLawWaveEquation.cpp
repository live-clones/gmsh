#include "dgConservationLaw.h"
#include "dgConservationLawWaveEquation.h"
#include "function.h"
// dp/dt - rho*c^2  div(u,v) = 0
// du/dt + 1/rho  dp/dx = 0
// dv/dt + 1/rho  dp/dy = 0
static double c=1;
static double rho=1;

class dgConservationLawWaveEquation::hyperbolicFlux : public dataCacheDouble {
  dataCacheDouble &sol;
  const int _DIM,_nbf;    
  public:
  hyperbolicFlux(dataCacheMap &cacheMap,int DIM):
    sol(cacheMap.get("Solution",this)),_DIM(DIM),_nbf(DIM+1)
  {};
  void _eval () {
    int nQP = sol().size1();
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,3*_nbf);
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
class dgConservationLawWaveEquation::riemann : public dataCacheDouble {
  dataCacheDouble &normals, &solL, &solR;
  const int _DIM,_nbf;
  public:
  riemann(dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight, int DIM):
    normals(cacheMapLeft.get("Normals", this)),
    solL(cacheMapLeft.get("Solution", this)),
    solR(cacheMapRight.get("Solution", this)),
    _DIM(DIM),_nbf(DIM+1)
  {};
  void _eval () { 
    int nQP = solL().size1();
    if(_value.size1() != nQP)
      _value = fullMatrix<double>(nQP,2*_nbf);
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
      sol(cacheMap.get("Solution",this)),
      normals(cacheMap.get("Normals",this)),
      _DIM(DIM){}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
        _value = fullMatrix<double>(nQP,_DIM+1);
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
  dgBoundaryConditionWaveEquationWall(int DIM):_DIM(DIM){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft,_DIM);
  }
};
dgBoundaryCondition *dgConservationLawWaveEquation::newBoundaryWall()const{
  return new dgBoundaryConditionWaveEquationWall(_DIM);
}

#include "Bindings.h"
const char *dgConservationLawWaveEquation::className = "ConservationLawWaveEquation";
const char *dgConservationLawWaveEquation::parentClassName = "ConservationLaw";
methodBinding *dgConservationLawWaveEquation::methods[] ={
  new methodBindingTemplate<const dgConservationLawWaveEquation,dgBoundaryCondition*>("newWallBoundary",&dgConservationLawWaveEquation::newBoundaryWall),
0};
constructorBinding *dgConservationLawWaveEquation::constructorMethod=new constructorBindingTemplate<dgConservationLawWaveEquation,int>();
