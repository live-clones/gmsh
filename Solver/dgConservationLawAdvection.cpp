#include "dgConservationLaw.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"
#include "SPoint3.h"
#include "MElement.h"
#include "function.h"

class dgConservationLawAdvection : public dgConservationLaw {
  std::string _vFunctionName;
  class advection : public dataCacheDouble {
    dataCacheDouble &sol, &v;
    public:
    advection(std::string vFunctionName, dataCacheMap &cacheMap):
      dataCacheDouble(cacheMap.getNbEvaluationPoints(),3),
      sol(cacheMap.get("Solution",this)),
      v(cacheMap.get(vFunctionName,this))
      {};
    void _eval () { 
      for(int i=0; i< sol().size1(); i++) {
        _value(i,0) = sol(i,0)*v(i,0);
        _value(i,1) = sol(i,0)*v(i,1);
        _value(i,2) = sol(i,0)*v(i,2);
      }
    }
  };
  class riemann : public dataCacheDouble {
    dataCacheDouble &normals, &solLeft, &solRight,&v;
    public:
    riemann(std::string vFunctionName, dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight):
      dataCacheDouble(cacheMapLeft.getNbEvaluationPoints(),2),
      normals(cacheMapLeft.get("Normals", this)),
      solLeft(cacheMapLeft.get("Solution", this)),
      solRight(cacheMapRight.get("Solution", this)),
      v(cacheMapLeft.get(vFunctionName,this))
      {};
    void _eval () { 
      for(int i=0; i< _value.size1(); i++) {
        double un=v(i,0)*normals(0,i)+v(i,1)*normals(1,i)+v(i,2)*normals(2,i);
        if(un>0){
          _value(i,0) = -solLeft(i,0)*un;
          _value(i,1) = solLeft(i,0)*un;
        }else{
          _value(i,0) = -solRight(i,0)*un;
          _value(i,1) = solRight(i,0)*un;
        }
      }
    }
  };
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const {
    return new advection(_vFunctionName,cacheMap);
  }
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
    return new riemann(_vFunctionName,cacheMapLeft, cacheMapRight);
  }
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const {
    return 0;
  }
  dgConservationLawAdvection(std::string vFunctionName) 
  {
    _vFunctionName = vFunctionName;
    _nbf = 1;
  }
};

dgConservationLaw *dgNewConservationLawAdvection(std::string vFunctionName) {
  return new dgConservationLawAdvection(vFunctionName);
}
