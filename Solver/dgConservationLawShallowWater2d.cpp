#include "dgConservationLawShallowWater2d.h"
#include "function.h"
static double g = 9.81;

class dgConservationLawShallowWater2d : public dgConservationLaw {
  class advection;
  class source;
  class riemann;
  class clipToPhysics;
  class boundaryWall;
  class maxConvectiveSpeed;
  const function *_linearDissipation, *_quadraticDissipation, *_source, *_coriolisFactor, *_bathymetry;
  mutable function *_advection, *_riemann;
  public:
  dataCacheDouble *newConvectiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const;
  dataCacheDouble *newDiffusiveFlux( dataCacheMap &cacheMap) const;
  dataCacheDouble *newSourceTerm (dataCacheMap &cacheMap) const;
  dataCacheDouble *newMaxConvectiveSpeed (dataCacheMap &cacheMap) const;
  dataCacheDouble *newClipToPhysics (dataCacheMap &cacheMap) const;
  inline void setCoriolisFactor(const function *coriolisFactor){ _coriolisFactor = coriolisFactor;}
  inline void setLinearDissipation(const function *linearDissipation){ _linearDissipation = linearDissipation;}
  inline void setQuadraticDissipation(const function *quadraticDissipation){ _quadraticDissipation = quadraticDissipation;}
  inline void setSource(const function *source){ _source = source;}
  inline void setBathymetry(const function *bathymetry) { _bathymetry = bathymetry;}
  dgConservationLawShallowWater2d();
  dgBoundaryCondition *newBoundaryWall();
};

class dgConservationLawShallowWater2d::advection: public function {
  public:
  advection(const function *bathymetry, const function *solution):function(9)
  {
    addArgument(bathymetry);
    addArgument(solution);
  }
  void call (dataCacheMap *m, const fullMatrix<double> &bathymetry, const fullMatrix<double> &sol, fullMatrix<double> &value) { 
    int nQP = value.size1();
    for(int i=0; i< nQP; i++) {
      double h = bathymetry(i,0);
      double eta = sol(i,0);
      double u = sol(i,1);
      double v = sol(i,2);
      // flux_x
      value(i,0) = (h+eta)*u;
      value(i,1) = g*eta+u*u;
      value(i,2) = u*v;
      // flux_y
      value(i,3) = (h+eta)*v;
      value(i,4) = v*u;
      value(i,5) = g*eta+v*v;
      // flux_z
      value(i,6) = 0;
      value(i,7) = 0;
      value(i,8) = 0;
    }
  }
};

class dgConservationLawShallowWater2d::clipToPhysics : public dataCacheDouble {
  dataCacheDouble &sol, &_bathymetry;
  double _hMin;
public:
  clipToPhysics(dataCacheMap &cacheMap, const function *bathymetry, double hMin):
    dataCacheDouble(cacheMap,1,3),
    sol(cacheMap.get(function::getSolution(), this)),
    _bathymetry(cacheMap.get(bathymetry,this))
  {
    _hMin=hMin;
  };
  void _eval () { 
    const int nQP = _value.size1();
    for (size_t k = 0 ; k < nQP; k++ ){
      double h = _bathymetry(k,0);
      _value(k,0) = sol(k,0);
      _value(k,1) = sol(k,1);
      _value(k,2) = sol(k,2);
      double H = sol(k,0)+h;
      if (H < _hMin){
        _value(k,0) = _hMin;
      }
    }
  }
};

class dgConservationLawShallowWater2d::maxConvectiveSpeed: public dataCacheDouble {
  dataCacheDouble &sol, &_bathymetry;
  public:
  maxConvectiveSpeed(dataCacheMap &cacheMap, const function *bathymetry):
    dataCacheDouble(cacheMap,1,1),
    sol(cacheMap.get(function::getSolution(), this)),
    _bathymetry(cacheMap.get(bathymetry,this))
  {};
  void _eval () { 
    int nQP = _value.size1();
    for(int i=0; i< nQP; i++) {
      double h = _bathymetry(i,0);
      double eta = sol(i,0);
      double u = sol(i,1);
      double v = sol(i,2);
      _value(i,0) = sqrt((h+eta)*g)+hypot(u,v);
    }
  }
};


/*class dgConservationLawShallowWater2d::advection: public dataCacheDouble {
  dataCacheDouble &sol, &_bathymetry;
  public:
  advection(dataCacheMap &cacheMap, const function *bathymetry):
    dataCacheDouble(cacheMap,1,9),
    sol(cacheMap.get(function::getSolution(), this)),
    _bathymetry(cacheMap.get(bathymetry,this))
  {};
  void _eval () { 
    int nQP = _value.size1();
    for(int i=0; i< nQP; i++) {
      double h = _bathymetry(i,0);
      double eta = sol(i,0);
      double u = sol(i,1);
      double v = sol(i,2);
      // flux_x
      _value(i,0) = (h+eta)*u;
      _value(i,1) = g*eta+u*u;
      _value(i,2) = u*v;
      // flux_y
      _value(i,3) = (h+eta)*v;
      _value(i,4) = v*u;
      _value(i,5) = g*eta+v*v;
      // flux_z
      _value(i,6) = 0;
      _value(i,7) = 0;
      _value(i,8) = 0;
    }
  }
};*/

class dgConservationLawShallowWater2d::source: public dataCacheDouble {
  dataCacheDouble &solution,&solutionGradient;
  dataCacheDouble &_coriolisFactor, &_source, &_linearDissipation, &_quadraticDissipation;
  public :
  source(dataCacheMap &cacheMap, const function *linearDissipation, const function *quadraticDissipation, const function *coriolisFactor, const function *source) : 
    dataCacheDouble(cacheMap,1,3),
    _coriolisFactor(cacheMap.get(coriolisFactor,this)),
    _source(cacheMap.get(source,this)),
    _linearDissipation(cacheMap.get(linearDissipation,this)),
    _quadraticDissipation(cacheMap.get(quadraticDissipation,this)),
    solution(cacheMap.get(function::getSolution(), this)),
    solutionGradient(cacheMap.get(function::getSolutionGradient(), this))
  {
  }
  void _eval () {
    int nQP =_value.size1();
    for (int i=0; i<nQP; i++) {
      double eta = solution(i,0);
      double u = solution(i,1);
      double v = solution(i,2);
      double normu = hypot(u,v);
      double dudx = solutionGradient(i,3);
      double dvdx = solutionGradient(i,6);
      double dudy = solutionGradient(i,4);
      double dvdy = solutionGradient(i,7);
      _value (i,0) = 0;
      _value (i,1) = _coriolisFactor(i,0)*v  - (_linearDissipation(i,0)+_quadraticDissipation(i,0)*normu)*u + _source(i,0) + u*(dudx+dvdy);
      _value (i,2) = -_coriolisFactor(i,0)*u - (_linearDissipation(i,0)+_quadraticDissipation(i,0)*normu)*v + _source(i,1) + v*(dudx+dvdy);
    }
  }
};

#if 0
class dgConservationLawShallowWater2d::riemann:public function {
  public:
  riemann (const function *bathymetry): function(6)
  {
    addArgument (function::getNormals(), 0);
    addArgument (function::getSolution(), 0);
    addArgument (function::getSolution(), 1);
    addArgument (bathymetry, 0);
  };
  void call  (dataCacheMap *m, const fullMatrix<double> &normals, const fullMatrix<double> &solL, const fullMatrix<double> &solR, const fullMatrix<double> &_bathymetry, fullMatrix<double> &value) { 
    int nQP = solL.size1();
    for(int i=0; i< nQP; i++) {
      double h = _bathymetry(i,0);
      double nx = normals(0,i);
      double ny = normals(1,i);
      double HR = solR(i,0) + h, HL = solL(i,0) + h;
      double uL = nx*solL(i,1) + ny*solL(i,2), uR = nx*solR(i,1) + ny*solR(i,2);
      double vL = -ny*solL(i,1) + nx*solL(i,2), vR = - ny*solR(i,1) + nx*solR(i,2);
      double HuL = uL*HL, HuR = uR*HR;
      double HvL = vL*HL, HvR = vR*HR;
      double HM = (HL+HR)/2, HJ = (HL-HR)/2;
      double HuM = (HuL+HuR)/2, HuJ = (HuL-HuR)/2;
      double HvM = (HvL+HvR)/2, HvJ = (HvL-HvR)/2;
      double sqHL = sqrt(HL), sqHR = sqrt(HR);
      double u_roe = (sqHL*uL + sqHR*uR) / (sqHL + sqHR);
      double v_roe = (sqHL*vL + sqHR*vR) / (sqHL + sqHR);
      double c_roe = sqrt(g*HM);
      double H = HM + (HuJ - u_roe *HJ) / c_roe;
      double Hu = HuM + (c_roe - u_roe*u_roe/c_roe) *HJ + u_roe/c_roe *HuJ;
      double Hv = -v_roe*u_roe/c_roe*HJ + v_roe/c_roe*HuJ + (u_roe>0 ? -v_roe*HJ+HvL : v_roe*HJ+HvR);
      double u = Hu / H;
      double v = Hv / H;
      double eta  = H-h;

      /*double u = (uL+uR)/2; // 
      double v = (vL+vR)/2;
      double eta = (HL+HR)/2-h;
      double c = hypot(u,v)+sqrt(g*(h+eta));
      double Fun = -g*eta - u*u - (uL-uR)/2 * c;
      double Fut = -u*( u>0 ? vL:vR);
      double Feta = -(h+eta)*u - (HL-HR)/2 * c;*/

      double Fun = -g*eta - u*u;
      double Fut = -u*v;
      double Feta = -(h+eta)*u;

      /* //linear equations 
      double unL = nx*solL(i,1) + ny*solL(i,2);
      double unR = nx*solR(i,1) + ny*solR(i,2);
      double etaR = solR(i,0);
      double etaL = solL(i,0);
      double sq_g_h = sqrt(g/h);
      double etaRiemann = (etaL+etaR + (unL-unR)/sq_g_h)/2;
      double unRiemann = (unL+unR + (etaL-etaR)*sq_g_h)/2;
      double Fun = -g*etaRiemann;
      double Fut = 0;
      double Feta = -h*unRiemann;
      */

      value(i,0) = Feta;
      value(i,1) = Fun*nx - Fut*ny;
      value(i,2) = Fun*ny + Fut*nx;
      value(i,3) = -value(i,0);
      value(i,4) = -value(i,1);
      value(i,5) = -value(i,2);
    }
  }
};
#endif

#if 1
class dgConservationLawShallowWater2d::riemann:public dataCacheDouble {
  dataCacheDouble &normals, &solL, &solR, &_bathymetry;
  public:
  riemann(dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight, const function *bathymetry):
    dataCacheDouble(cacheMapLeft,1,6),
    normals(cacheMapLeft.get(function::getNormals(), this)),
    solL(cacheMapLeft.get(function::getSolution(), this)),
    solR(cacheMapRight.get(function::getSolution(), this)),
    _bathymetry(cacheMapLeft.get(bathymetry, this))
  {};
  void _eval () { 
    int nQP = solL().size1();
    for(int i=0; i< nQP; i++) {
      double h = _bathymetry(i,0);
      double nx = normals(0,i);
      double ny = normals(1,i);
      double HR = solR(i,0) + h, HL = solL(i,0) + h;
      double uL = nx*solL(i,1) + ny*solL(i,2), uR = nx*solR(i,1) + ny*solR(i,2);
      double vL = -ny*solL(i,1) + nx*solL(i,2), vR = - ny*solR(i,1) + nx*solR(i,2);
      double HuL = uL*HL, HuR = uR*HR;
      double HvL = vL*HL, HvR = vR*HR;
      double HM = (HL+HR)/2, HJ = (HL-HR)/2;
      double HuM = (HuL+HuR)/2, HuJ = (HuL-HuR)/2;
      double HvM = (HvL+HvR)/2, HvJ = (HvL-HvR)/2;
      double sqHL = sqrt(HL), sqHR = sqrt(HR);
      double u_roe = (sqHL*uL + sqHR*uR) / (sqHL + sqHR);
      double v_roe = (sqHL*vL + sqHR*vR) / (sqHL + sqHR);
      double c_roe = sqrt(g*HM);
      double H = HM + (HuJ - u_roe *HJ) / c_roe;
      double Hu = HuM + (c_roe - u_roe*u_roe/c_roe) *HJ + u_roe/c_roe *HuJ;
      double Hv = -v_roe*u_roe/c_roe*HJ + v_roe/c_roe*HuJ + (u_roe>0 ? -v_roe*HJ+HvL : v_roe*HJ+HvR);
      double u = Hu / H;
      double v = Hv / H;
      double eta  = H-h;

      /*double u = (uL+uR)/2; // 
      double v = (vL+vR)/2;
      double eta = (HL+HR)/2-h;
      double c = hypot(u,v)+sqrt(g*(h+eta));
      double Fun = -g*eta - u*u - (uL-uR)/2 * c;
      double Fut = -u*( u>0 ? vL:vR);
      double Feta = -(h+eta)*u - (HL-HR)/2 * c;*/

      double Fun = -g*eta - u*u;
      double Fut = -u*v;
      double Feta = -(h+eta)*u;

      /* //linear equations 
      double unL = nx*solL(i,1) + ny*solL(i,2);
      double unR = nx*solR(i,1) + ny*solR(i,2);
      double etaR = solR(i,0);
      double etaL = solL(i,0);
      double sq_g_h = sqrt(g/h);
      double etaRiemann = (etaL+etaR + (unL-unR)/sq_g_h)/2;
      double unRiemann = (unL+unR + (etaL-etaR)*sq_g_h)/2;
      double Fun = -g*etaRiemann;
      double Fut = 0;
      double Feta = -h*unRiemann;
      */

      _value(i,0) = Feta;
      _value(i,1) = Fun*nx - Fut*ny;
      _value(i,2) = Fun*ny + Fut*nx;
      _value(i,3) = -_value(i,0);
      _value(i,4) = -_value(i,1);
      _value(i,5) = -_value(i,2);
    }
  }
};
#endif

class dgConservationLawShallowWater2d::boundaryWall : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals;
    public:
    term(dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap,1,3),
    sol(cacheMap.get(function::getSolution(), this)),
    normals(cacheMap.get(function::getNormals(), this)){}
    void _eval () { 
      int nQP = sol().size1();
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
  boundaryWall(dgConservationLaw *claw) : dgBoundaryCondition(claw){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft);
  }
};

dataCacheDouble *dgConservationLawShallowWater2d::newConvectiveFlux( dataCacheMap &cacheMap) const {
  if(_advection==NULL)
    _advection = new advection(_bathymetry, function::getSolution());
  return &cacheMap.get(_advection, NULL);
}

dataCacheDouble *dgConservationLawShallowWater2d::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  //if(_riemann==NULL)
    //_riemann = new riemann(_bathymetry);
  //return &cacheMapLeft.get(_riemann, NULL);
  return new riemann(cacheMapLeft, cacheMapRight, _bathymetry);
}
dataCacheDouble *dgConservationLawShallowWater2d::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  return 0;
}
dataCacheDouble *dgConservationLawShallowWater2d::newMaxConvectiveSpeed( dataCacheMap &cacheMap) const {
  return new maxConvectiveSpeed(cacheMap, _bathymetry);
}
dataCacheDouble *dgConservationLawShallowWater2d::newSourceTerm (dataCacheMap &cacheMap) const {
  return new source(cacheMap, _linearDissipation, _quadraticDissipation, _coriolisFactor, _source);
}

dgBoundaryCondition *dgConservationLawShallowWater2d::newBoundaryWall(){
  return new boundaryWall(this);
}

dataCacheDouble *dgConservationLawShallowWater2d::newClipToPhysics( dataCacheMap &cacheMap) const {
  return new clipToPhysics(cacheMap, _bathymetry, 1e-5);
}
dgConservationLawShallowWater2d::dgConservationLawShallowWater2d()
{
  _nbf = 3; // eta u v
  function *fzero = functionConstantNew(0.);
  _bathymetry = fzero;
  _linearDissipation = fzero;
  _coriolisFactor = fzero;
  _quadraticDissipation = fzero;
  _source = fzero;
  _advection = NULL;
}

#include "Bindings.h"
void dgConservationLawShallowWater2dRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawShallowWater2d>("dgConservationLawShallowWater2d");
  cb->setDescription("The non-conservative shallow water conservation law. (eta, u, v)");
  methodBinding *cm;
  cm = cb->addMethod("newBoundaryWall",&dgConservationLawShallowWater2d::newBoundaryWall);
  cm->setDescription("slip wall boundary");
  cm = cb->setConstructor<dgConservationLawShallowWater2d>();
  cm->setDescription("A new shallow water conservation law.");
  cb->setParentClass<dgConservationLaw>();
  cm = cb->addMethod("setCoriolisFactor", &dgConservationLawShallowWater2d::setCoriolisFactor);
  cm->setDescription("set the function to evaluate the coriolis factor du/dt = -f v ; dv/dt = f u");
  cm->setArgNames("f",NULL);
  cm = cb->addMethod("setLinearDissipation", &dgConservationLawShallowWater2d::setLinearDissipation);
  cm->setDescription("set the function to evaluate the linear dissipation du/dt = -gamma u; dv/dt = -gamma v");
  cm->setArgNames("gamma",NULL);
  cm = cb->addMethod("setQuadraticDissipation", &dgConservationLawShallowWater2d::setQuadraticDissipation);
  cm->setDescription("set the function to evaluate the quadratic dissipation du/dt = -c_d u||u||; dv/dt = -c_d v");
  cm->setArgNames("gamma",NULL);
  cm = cb->addMethod("setSource", &dgConservationLawShallowWater2d::setSource);
  cm->setDescription("set the function to evaluate the source term du/dt = s(0); dv/dt = s(1)");
  cm->setArgNames("s",NULL);
  cm = cb->addMethod("setBathymetry", &dgConservationLawShallowWater2d::setBathymetry);
  cm->setDescription("set the function to evaluate the bathymetry h (H = h+eta)");
  cm->setArgNames("h",NULL);
}
