#include "dgConservationLaw.h"
#include "function.h"
static double g = 9.81;
class dgConservationLawShallowWater2d : public dgConservationLaw {
  class advection : public dataCacheDouble {
    dataCacheDouble &sol;
    public:
    advection(dataCacheMap &cacheMap):
      sol(cacheMap.get("Solution",this))
      {};
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
        _value=fullMatrix<double>(nQP,9);
      for(int i=0; i< nQP; i++) {
        double H = sol(i,0);
        double U = sol(i,1);
        double V = sol(i,2);
        // flux_x
        _value(i,0) = U;
        _value(i,1) = U*U/H + g*H*H/2;
        _value(i,2) = U*V/H;
        // flux_y
        _value(i,3) = V;
        _value(i,4) = V*U/H;
        _value(i,5) = V*V/H + g*H*H/2;
        // flux_z
        _value(i,6) = 0;
        _value(i,7) = 0;
        _value(i,8) = 0;
      }
      _value.scale(0);
    }
  };
  class source : public dataCacheDouble {
    dataCacheDouble &xyz, &solution;
    public :
    source(dataCacheMap &cacheMap) : 
      xyz(cacheMap.get("XYZ",this)),
      solution(cacheMap.get("Solution",this))
    {}
    void _eval () {
      int nQP = xyz().size1();
      if(_value.size1() != nQP)
        _value = fullMatrix<double>(nQP,3);
      for (int i=0; i<nQP; i++) {
        double H = solution(i,0);
        double U = solution(i,1);
        double V = solution(i,2);
        double wind = 0.1*sin(xyz(i,1)/1e6*M_PI)/H/1000;
        double f = 1e-4+xyz(i,1)*2e-11;
        double gamma = 1e-6;
        f=0;
        _value (i,0) = 0;
        _value (i,1) = -gamma*U - f*V + wind;
        _value (i,2) = -gamma*V + f*U;
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
        double UnL = nx*solL(i,1) + ny*solL(i,2);
        double UnR = nx*solR(i,1) + ny*solR(i,2);
        double UtL = ny*solL(i,1) - nx*solL(i,2);
        double UtR = ny*solR(i,1) - nx*solR(i,2);
        double HR = solR(i,0);
        double HL = solL(i,0);
        double c = sqrt(g*(HR+HL)/2);
        double FUn = -(UnL*UnL/HL + g*HL*HL/2 + UnR*UnR/HR + g*HR*HR/2)/2 + c*(UnL-UnR)/2;
        double FUt = -(UnL*UtL/HL + UnR*UtR/HR)/2 + c*(UtL-UtR)/2;
        double FH = -(UnL+UnR)/2 + c*(HL-HR)/2;
        _value(i,0) = FH;
        _value(i,1) = FUn*nx + FUt*ny;
        _value(i,2) = FUn*ny - FUt*nx;

      _value(i,1)=0;
      _value(i,2)=0;
        _value(i,3) = -_value(i,0);
        _value(i,4) = -_value(i,1);
        _value(i,5) = -_value(i,2);
      }
    }
  };
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const {
    return new advection(cacheMap);
  }
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
    return new riemann(cacheMapLeft, cacheMapRight);
  }
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const {
    return 0;
  }
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const {
    return new source(cacheMap);
  }
  dgConservationLawShallowWater2d() 
  {
    _nbf = 3; // H U(=Hu) V(=Hv)
  }
};

dgConservationLaw *dgNewConservationLawShallowWater2d() {
  return new dgConservationLawShallowWater2d();
}
