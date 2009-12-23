#include "dgConservationLawShallowWater2d.h"
#include "function.h"
static double g = 9.81;
static double h = 1000;

class dgConservationLawShallowWater2d::advection: public dataCacheDouble {
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
      double eta = sol(i,0);
      double u = sol(i,1);
      double v = sol(i,2);
      // flux_x
      _value(i,0) = h*u;
      _value(i,1) = g*eta;
      _value(i,2) = 0;
      // flux_y
      _value(i,3) = h*v;
      _value(i,4) = 0;
      _value(i,5) = g*eta;
      // flux_z
      _value(i,6) = 0;
      _value(i,7) = 0;
      _value(i,8) = 0;
    }
  }
};

class dgConservationLawShallowWater2d::source: public dataCacheDouble {
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
      double eta = solution(i,0);
      double u = solution(i,1);
      double v = solution(i,2);
      double wind = 0.1*sin(xyz(i,1)/1e6*M_PI)/1000/h;
      double f = 1e-4+xyz(i,1)*2e-11;
      double gamma = 1e-6;
      _value (i,0) = 0;
      _value (i,1) = f*v + - gamma*u + wind;
      _value (i,2) = -f*u - gamma*v ;
    }
  }
};
class dgConservationLawShallowWater2d::riemann:public dataCacheDouble {
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
      double utL = ny*solL(i,1) - nx*solL(i,2);
      double utR = ny*solR(i,1) - nx*solR(i,2);
      double etaR = solR(i,0);
      double etaL = solL(i,0);
      double sq_g_h = sqrt(g/h);
      double etaRiemann = (etaL+etaR + (unL-unR)/sq_g_h)/2;
      double unRiemann = (unL+unR + (etaL-etaR)*sq_g_h)/2;
      double Fun = -g*etaRiemann;
      double Feta = -h*unRiemann;
      _value(i,0) = Feta;
      _value(i,1) = Fun*nx;
      _value(i,2) = Fun*ny;

      _value(i,3) = -_value(i,0);
      _value(i,4) = -_value(i,1);
      _value(i,5) = -_value(i,2);
    }
  }
};

class dgConservationLawShallowWater2d::boundaryWall : public dgBoundaryCondition {
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
        double eta = sol(i,0);

        _value(i,0) = 0;
        _value(i,1) = -g*eta*nx;
        _value(i,2) = -g*eta*ny;
      }
    }
  };
  public:
  boundaryWall(){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft);
  }
};

dataCacheDouble *dgConservationLawShallowWater2d::newConvectiveFlux( dataCacheMap &cacheMap) const {
  return new advection(cacheMap);
}
dataCacheDouble *dgConservationLawShallowWater2d::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  return new riemann(cacheMapLeft, cacheMapRight);
}
dataCacheDouble *dgConservationLawShallowWater2d::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  return 0;
}
dataCacheDouble *dgConservationLawShallowWater2d::newSourceTerm (dataCacheMap &cacheMap) const {
  return new source(cacheMap);
}

dgBoundaryCondition *dgConservationLawShallowWater2d::newBoundaryWall(){
  return new boundaryWall();
}

#include "Bindings.h"
void dgConservationLawShallowWater2dRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawShallowWater2d>("dgConservationLawShallowWater2d");
  methodBinding *cm;
  cb->addMethod("newBoundaryWall",&dgConservationLawShallowWater2d::newBoundaryWall);
  cb->setConstructor<dgConservationLawShallowWater2d>();
  cb->setParentClass<dgConservationLaw>();
}
