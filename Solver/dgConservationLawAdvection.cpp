#include "dgConservationLaw.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"
#include "SPoint3.h"
#include "MElement.h"
#include "function.h"
#include "dgConservationLawAdvection.h"

class dgConservationLawAdvection::advection : public dataCacheDouble {
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
class dgConservationLawAdvection::riemann : public dataCacheDouble {
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
class dgConservationLawAdvection::diffusion : public dataCacheDouble {
  dataCacheDouble &solgrad, &nu;
  public:
  diffusion(std::string nuFunctionName, dataCacheMap &cacheMap):
    solgrad(cacheMap.get("SolutionGradient",this)),
    nu(cacheMap.get(nuFunctionName,this))
  {};
  void _eval () { 
    if(_value.size1() != solgrad().size1()/3)
      _value=fullMatrix<double>(solgrad().size1()/3,3);
    for(int i=0; i< solgrad().size1()/3; i++) {
      _value(i,0) = -solgrad(i*3,0)*nu(i,0);
      _value(i,1) = -solgrad(i*3+1,0)*nu(i,0);
      _value(i,2) = -solgrad(i*3+2,0)*nu(i,0);
    }
  }
};
dataCacheDouble *dgConservationLawAdvection::newConvectiveFlux( dataCacheMap &cacheMap) const {
  if( !_vFunctionName.empty())
    return new advection(_vFunctionName,cacheMap);
  else
    return NULL;
}
dataCacheDouble *dgConservationLawAdvection::newMaximumDiffusivity( dataCacheMap &cacheMap) const {
  if( !_nuFunctionName.empty())
    return &cacheMap.get(_nuFunctionName);
  else
    return NULL;
}
dataCacheDouble *dgConservationLawAdvection::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  if( !_vFunctionName.empty())
    return new riemann(_vFunctionName,cacheMapLeft, cacheMapRight);
  else
    return NULL;
}
dataCacheDouble *dgConservationLawAdvection::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  if( !_nuFunctionName.empty())
    return new diffusion(_nuFunctionName,cacheMap);
  else
    return NULL;
}
dgConservationLawAdvection::dgConservationLawAdvection(std::string vFunctionName, std::string nuFunctionName) 
{
  _vFunctionName = vFunctionName;
  _nuFunctionName = nuFunctionName;
  _nbf = 1;
}

#include "Bindings.h"
void dgConservationLawAdvectionRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawAdvection>("dgConservationLawAdvection");
  cb->setConstructor<dgConservationLawAdvection,std::string,std::string>();
  cb->setParentClass<dgConservationLaw>();
}
