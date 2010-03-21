#include "dgConservationLawShallowWater1d.h"
#include "function.h"

class dgConservationLawShallowWater1d : public dgConservationLaw {
  class advection;
  class source;
  class riemann;
  class boundaryWall;
  class clipToPhysics;
  class maxConvectiveSpeed;
  const function  *_bathymetry, *_linearDissipation, *_pressure, *_celerity;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaxConvectiveSpeed( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dataCacheDouble *newClipToPhysics (dataCacheMap &cacheMap) const;
  inline void setPressureFlux(const function *pressure) { _pressure = pressure;}
  inline void setCelerity(const function *celerity) { _celerity = celerity;}
  inline void setBathymetry(const function *bathymetry) { _bathymetry = bathymetry;}
  inline void setLinearDissipation(const function *linearDissipation){ _linearDissipation = linearDissipation;}
  inline const function* getPressureFlux() {return _pressure;};
  dgConservationLawShallowWater1d() 
  {
    _nbf = 2; // eta u
    fullMatrix<double> zero(1,1);
    zero(0,0) = 0.0;
    functionConstant *fzero = new functionConstant(&zero);
    _pressure = fzero;
    _celerity = fzero;
    _bathymetry = fzero;
    _linearDissipation = fzero;
  }
  dgBoundaryCondition *newBoundaryWall();
};

class dgConservationLawShallowWater1d::clipToPhysics : public dataCacheDouble {
  dataCacheDouble &sol, &_bathymetry;
  double _hMin;
public:
  clipToPhysics(dataCacheMap &cacheMap, const function *bathymetry, double hMin):
    dataCacheDouble(cacheMap,1,3),
    sol(cacheMap.getSolution(this)),
    _bathymetry(cacheMap.get(bathymetry,this))
  {
    _hMin=hMin;
  };
  void _eval () { 
    int nQP = _value.size1();
    for (size_t k = 0 ; k < nQP; k++ ){
      double h = _bathymetry(k,0);
      _value(k,0) = sol(k,0);
      _value(k,1) = sol(k,1);
      double H = sol(k,0)+h;
      if (H < _hMin){
        _value(k,0) = _hMin;
      }
    }
  }
};

class dgConservationLawShallowWater1d::maxConvectiveSpeed : public dataCacheDouble {
  dataCacheDouble &sol, &_celerity;
  public:
  maxConvectiveSpeed(dataCacheMap &cacheMap, const function *celerity):
    dataCacheDouble(cacheMap,1,1),
    sol(cacheMap.getSolution(this)),
    _celerity(cacheMap.get(celerity,this))
  {};
  void _eval () {
    int nQP = sol().size1();
    for(int i=0; i< nQP; i++) {
      _value(i,0) = sol(i,1) + _celerity(i,0);
    }
  }
};

class dgConservationLawShallowWater1d::advection: public dataCacheDouble {
  dataCacheDouble &sol, &_bathymetry, &_pressure;
  public:
  advection(dataCacheMap &cacheMap, const function *bathymetry, const function *pressure):
    dataCacheDouble(cacheMap,1,6),
    sol(cacheMap.getSolution(this)),
    _bathymetry(cacheMap.get(bathymetry,this)), 
    _pressure(cacheMap.get(pressure,this))
  {};
  void _eval () { 
    int nQP = _value.size1();
    for(int i=0; i< nQP; i++) {
      double h = _bathymetry(i,0);
      double p = _pressure(i,0);
      double eta = sol(i,0);
      double u = sol(i,1);
      // flux_x
      _value(i,0) = (h+eta)*u;
      _value(i,1) = .5*u*u + p;
      // flux_y
      _value(i,2) = 0;
      _value(i,3) = 0;
      // flux_z
      _value(i,4) = 0;
      _value(i,5) = 0;
    }
  }
};

class dgConservationLawShallowWater1d::source: public dataCacheDouble {
  dataCacheDouble  &solution;
  dataCacheDouble &_linearDissipation, &_bathymetry;
  public :
  source(dataCacheMap &cacheMap,  const function *linearDissipation, const function *bathymetry) : 
    dataCacheDouble(cacheMap,1,2),
    _linearDissipation(cacheMap.get(linearDissipation,this)),
    solution(cacheMap.getSolution(this)),
    _bathymetry(cacheMap.get(bathymetry,this))
  {}
  void _eval () {
    int nQP =_value.size1();
    for (int i=0; i<nQP; i++) {
      double h = _bathymetry(i,0);
      double eta = solution(i,0);
      double u = solution(i,1);
      _value (i,0) = 0;
      _value (i,1) = - _linearDissipation(i,0)*u/(h+eta) ;
    }
  }
};
class dgConservationLawShallowWater1d::riemann:public dataCacheDouble {
  dataCacheDouble &normals, &solL, &solR, &_bathymetryL, &_bathymetryR;
  dataCacheDouble &_pressureL, &_pressureR,  &_celerityL, &_celerityR;
  public:
  riemann(dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight, const function *bathymetry, 
          const function *pressure, const function *celerity):
    dataCacheDouble(cacheMapLeft,1,4),
    normals(cacheMapLeft.getNormals(this)),
    solL(cacheMapLeft.getSolution(this)),
    solR(cacheMapRight.getSolution(this)),
    _bathymetryL(cacheMapLeft.get(bathymetry, this)), 
    _bathymetryR(cacheMapRight.get(bathymetry, this)), 
    _pressureL(cacheMapLeft.get(pressure, this)), 
    _pressureR(cacheMapRight.get(pressure, this)),
    _celerityL(cacheMapLeft.get(celerity, this)), 
    _celerityR(cacheMapRight.get(celerity, this))
  {};
  void _eval () { 
    int nQP = solL().size1();
    for(int i=0; i< nQP; i++) {
      double hL = _bathymetryL(i,0);  double hR = _bathymetryR(i,0);
      double n0 = normals(0,i);
      double HL = solL(i,0) + hL, HR = solR(i,0) + hR;
      double uL = solL(i,1) , uR = solR(i,1) ;
      double sqHL = sqrt(HL), sqHR = sqrt(HR);
      double F1,F2;

//       //---------
//       //ROE 
//       //---------
//       double HuL = uL*HL, HuR = uR*HR;
//       double HM = (HL+HR)/2, HJ = (HL-HR)/2;
//       double HuM = (HuL+HuR)/2, HuJ = (HuL-HuR)/2;
//       double u_roe = (sqHL*uL + sqHR*uR) / (sqHL + sqHR);
//       double c_roe = sqrt(g*HM); //????
//       double H = HM + (HuJ - u_roe *HJ) / c_roe;
//       double Hu = HuM + (c_roe - u_roe*u_roe/c_roe) *HJ + u_roe/c_roe *HuJ;
//       double u = Hu / H;
//       double p = RHO*g*(H-h); //????
//       F1 = H*u*n0;
//       F2 = (.5*u*u + p/RHO)*n0;

//     //---------
//     //LAX 
//     //---------
      double pL = _pressureL(i,0);
      double pR = _pressureR(i,0);
      F1 = .5*( HL*uL + HR*uR )*n0;
      F2 = .5*( .5*uL*uL+pL  + .5*uR*uR+pR )*n0;       
      double maxlambdaL = uL + _celerityL(i,0); 
      double maxlambdaR = uR + _celerityR(i,0);  
      const double aMax = std::max(maxlambdaL,maxlambdaR);
      F1 += aMax*(HL-HR);
      F2 += aMax*(uL-uR);

//     //---------
//     //HLL 
//     //---------

//       double pL = _pressureL(i,0);
//       double pR = _pressureR(i,0);
//       double ustar = (sqHL*uL + sqHR*uR) / (sqHL + sqHR); 
//       double Hstar = (HL+HR)*.5;
//       double cstar =  sqrt(g*Hstar); //????   
//       double SL = std::min(uL - _celerityL(i,0), ustar - cstar);
//       double SR = std::min(uR + _celerityR(i,0),  ustar + cstar);
//       if (SL >= 0.){
//      F1 =  HL*uL*n0;  
//      F2 =  (.5*uL*uL + pL/RHO )*n0  ;
//       }
//       else if (SR <=0.){
//      F1 =  HR*uR*n0;  
//      F2 =  (.5*uR*uR + pR/RHO )*n0  ;
//       }
//       else{
//      F1 = (SR*HL*uL*n0-SL*HR*uR*n0 + SL*SR*(HR-HL))/(SR-SL);
//      F2 = (SR*(.5*uL*uL + pL/RHO )*n0-SL*(.5*uR*uR + pR/RHO )*n0  + SL*SR*(uR-uL))/(SR-SL);
//       }
      
    //-------------

      _value(i,0) = -F1;
      _value(i,1) = -F2;
      _value(i,2) = -_value(i,0);
      _value(i,3) = -_value(i,1);

    }

  }

};

class dgConservationLawShallowWater1d::boundaryWall : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals, &_pressure;
    public:
    term(dataCacheMap &cacheMap, const function *pressure):
    dataCacheDouble(cacheMap,1,2),
    sol(cacheMap.getSolution(this)),
    _pressure(cacheMap.get(pressure,this)),
    normals(cacheMap.getNormals(this))
    {}
    void _eval () { 
      int nQP = sol().size1();
      for(int i=0; i< nQP; i++) {
        double n0 = normals(0,i);
        double p = _pressure(i,0);
        _value(i,0) = 0;
        _value(i,1) = -p*n0;
      }
    }
  };
  public:
  dgConservationLawShallowWater1d *_claw; 
  boundaryWall(dgConservationLawShallowWater1d *claw) : dgBoundaryCondition(claw){_claw=claw;}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft, _claw->getPressureFlux());
  }
};


dataCacheDouble *dgConservationLawShallowWater1d::newMaxConvectiveSpeed( dataCacheMap &cacheMap) const {
  return new maxConvectiveSpeed(cacheMap, _celerity);
}
dataCacheDouble *dgConservationLawShallowWater1d::newConvectiveFlux( dataCacheMap &cacheMap) const {
  return new advection(cacheMap, _bathymetry, _pressure);
}
dataCacheDouble *dgConservationLawShallowWater1d::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  return new riemann(cacheMapLeft, cacheMapRight, _bathymetry, _pressure, _celerity);
}
dataCacheDouble *dgConservationLawShallowWater1d::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  return 0;
}
dataCacheDouble *dgConservationLawShallowWater1d::newSourceTerm (dataCacheMap &cacheMap) const {
  return new source(cacheMap, _linearDissipation, _bathymetry);
}

dgBoundaryCondition *dgConservationLawShallowWater1d::newBoundaryWall(){
  return new boundaryWall(this);
}

dataCacheDouble *dgConservationLawShallowWater1d::newClipToPhysics( dataCacheMap &cacheMap) const {
  return new clipToPhysics(cacheMap, _bathymetry, 1e-5);
}

#include "Bindings.h"
void dgConservationLawShallowWater1dRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawShallowWater1d>("dgConservationLawShallowWater1d");
  cb->setDescription("The non-conservative shallow water conservation law. (eta, u)");
  methodBinding *cm;
  cm = cb->addMethod("newBoundaryWall",&dgConservationLawShallowWater1d::newBoundaryWall);
  cm->setDescription("slip wall boundary");
  cm = cb->setConstructor<dgConservationLawShallowWater1d>();
  cm->setDescription("A new shallow water 1d conservation law.");
  cb->setParentClass<dgConservationLaw>();
  cm = cb->addMethod("setLinearDissipation", &dgConservationLawShallowWater1d::setLinearDissipation);
  cm->setDescription("set the function to evaluate the linear dissipation Kr u/A");
  cm->setArgNames("Kr",NULL);
  cm = cb->addMethod("setBathymetry", &dgConservationLawShallowWater1d::setBathymetry);
  cm->setDescription("set the function to evaluate the bathymetry h (H = h+eta)");
  cm->setArgNames("h",NULL);
  cm = cb->addMethod("setPressureFlux", &dgConservationLawShallowWater1d::setPressureFlux);
  cm->setDescription("set the function to evaluate the pressure flux");
  cm->setArgNames("pressureFlux",NULL);
  cm = cb->addMethod("setCelerity", &dgConservationLawShallowWater1d::setCelerity);
  cm->setDescription("set the function to the celerity of the waves");
  cm->setArgNames("celerity",NULL);
}
