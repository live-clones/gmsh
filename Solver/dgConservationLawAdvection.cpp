#include "dgConservationLaw.h"
#include "fullMatrix.h"
#include "dgGroupOfElements.h"
#include "SPoint3.h"
#include "MElement.h"
#include "function.h"
#include "dgConservationLawAdvection.h"

class dgConservationLawAdvectionDiffusion::advection : public dataCacheDouble {
  dataCacheDouble &sol, &v;
  public:
  advection(const function *vFunction, dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap,1,3),
    sol(cacheMap.get(function::getSolution(),this)),
    v(cacheMap.get(vFunction,this))
  {};
  void _eval () { 
    for(int i=0; i< sol().size1(); i++) {
      _value(i,0) = sol(i,0)*v(i,0);
      _value(i,1) = sol(i,0)*v(i,1);
      _value(i,2) = sol(i,0)*v(i,2);
    }
  }
};

class dgConservationLawAdvectionDiffusion::maxConvectiveSpeed : public dataCacheDouble {
  dataCacheDouble &v;
  public:
  maxConvectiveSpeed(const function *vFunction,dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap,1,1),
    v(cacheMap.get(vFunction,this))
  {
  };
  void _eval () {
    int nQP = v().size1();
    for(int i=0; i< nQP; i++) {
      _value(i,0) = hypot(v(i,0),v(i,1));
    }
  }
};

class dgConservationLawAdvectionDiffusion::riemann : public dataCacheDouble {
  dataCacheDouble &normals, &solLeft, &solRight,&v;
  public:
  riemann(const function *vFunction, dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight):
    dataCacheDouble(cacheMapLeft,1,2),
    normals(cacheMapLeft.get(function::getNormals(), this)),
    solLeft(cacheMapLeft.get(function::getSolution(), this)),
    solRight(cacheMapRight.get(function::getSolution(), this)),
    v(cacheMapLeft.get(vFunction,this))
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

class dgConservationLawAdvectionDiffusion::diffusion : public dataCacheDouble {
  dataCacheDouble &solgrad, &nu;
  public:
  diffusion(const function * nuFunction, dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap,1,3),
    solgrad(cacheMap.get(function::getSolutionGradient(), this)),
    nu(cacheMap.get(nuFunction,this))
  {};
  void _eval () { 
    for(int i=0; i< solgrad().size1(); i++) {
      _value(i,0) = -solgrad(i,0)*nu(i,0);
      _value(i,1) = -solgrad(i,1)*nu(i,0);
      _value(i,2) = -solgrad(i,2)*nu(i,0);
    }
  }
};

dataCacheDouble *dgConservationLawAdvectionDiffusion::newConvectiveFlux( dataCacheMap &cacheMap) const {
  return _vFunction ? new advection(_vFunction,cacheMap) : NULL;
}
dataCacheDouble *dgConservationLawAdvectionDiffusion::newMaxConvectiveSpeed( dataCacheMap &cacheMap) const {
  return _vFunction ? new maxConvectiveSpeed(_vFunction,cacheMap) : NULL ;

}
dataCacheDouble *dgConservationLawAdvectionDiffusion::newMaximumDiffusivity( dataCacheMap &cacheMap) const {
  return _nuFunction ? &cacheMap.get(_nuFunction) : NULL;
}
dataCacheDouble *dgConservationLawAdvectionDiffusion::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  return _vFunction ? new riemann(_vFunction,cacheMapLeft, cacheMapRight) : NULL;
}
dataCacheDouble *dgConservationLawAdvectionDiffusion::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  return _nuFunction ? new diffusion(_nuFunction,cacheMap) : NULL;
}

dgConservationLawAdvectionDiffusion *dgConservationLawAdvectionDiffusion::diffusionLaw(const function *nu) {
  return new dgConservationLawAdvectionDiffusion(NULL, nu);
}
dgConservationLawAdvectionDiffusion *dgConservationLawAdvectionDiffusion::advectionLaw(const function *v) {
  return new dgConservationLawAdvectionDiffusion(v,NULL);
}

dgConservationLawAdvectionDiffusion::dgConservationLawAdvectionDiffusion(const function *vFunction, const function *nuFunction) 
{
  _vFunction = vFunction;
  _nuFunction = nuFunction;
  _nbf = 1;
}
#include "Bindings.h"
void dgConservationLawAdvectionDiffusionRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawAdvectionDiffusion>("dgConservationLawAdvectionDiffusion");
  methodBinding *cm;
  cm = cb->setConstructor<dgConservationLawAdvectionDiffusion,const function *, const function*>();
  cm->setArgNames("v","nu",NULL);
  cm->setDescription("A new advection-diffusion law. The advection speed is given by 'v' vector function and the (scalar) diffusivity is given by the function 'nu'.");
  cm = cb->addMethod("diffusionLaw",dgConservationLawAdvectionDiffusion::diffusionLaw);
  cm->setDescription("static method to create an instance with diffusion only.");
  cm->setArgNames("nu",NULL);
  cm = cb->addMethod("advectionLaw",dgConservationLawAdvectionDiffusion::advectionLaw);
  cm->setDescription("static method to create an instance with advection only.");
  cm->setArgNames("v",NULL);
  cb->setParentClass<dgConservationLaw>();
  cb->setDescription("Advection and diffusion of a scalar, the advection and diffusion are provided by functions.");
}
