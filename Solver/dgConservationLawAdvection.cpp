#include "dgConservationLaw.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"
#include "SPoint3.h"
#include "MElement.h"
#include "function.h"

class dgConservationLawAdvection : public dgConservationLaw {
  std::string _vFunctionName;
  class advection : public dataCacheDouble {
    dataCacheDouble &sol, &uvw, &v;
    public:
    advection(std::string vFunctionName, dataCacheMap &cacheMap):
      uvw(cacheMap.get("UVW",this)),
      sol(cacheMap.get("Solution",this)),
      v(cacheMap.get(vFunctionName,this))
      {};
    void _eval () { 
      if(_value.size1() !=sol().size1())
        _value=fullMatrix<double>(sol().size1(),3);
      for(int i=0; i< sol().size1(); i++) {
        _value(i,0) = sol(i,0)*v(i,0);
        _value(i,1) = sol(i,0)*v(i,1);
        _value(i,2) = sol(i,0)*v(i,2);
      }
    }
  };
  class riemann : public dataCacheDouble {
    dataCacheDouble &uvw, &normals, &solLeft, &solRight,&v;
    public:
    riemann(std::string vFunctionName, dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight):
      uvw(cacheMapLeft.get("UVW", this)),
      normals(cacheMapLeft.get("Normals", this)),
      solLeft(cacheMapLeft.get("Solution", this)),
      solRight(cacheMapRight.get("Solution", this)),
      v(cacheMapLeft.get(vFunctionName,this))
      {};
    void _eval () { 
      if(_value.size1() !=solLeft().size1())
        _value = fullMatrix<double>(solLeft().size1(),2);
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
