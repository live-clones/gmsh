#include "dgConservationLawShallowWater2d.h"
#include "function.h"
static double g = 9.81;
static double h = 1000.;
static double linearDissipation = 2e-7;

class dgConservationLawShallowWater2d::advection: public dataCacheDouble {
  dataCacheDouble &sol;
  public:
  advection(dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap,cacheMap.getNbEvaluationPoints(),9),
    sol(cacheMap.get("Solution",this))
  {};
  void _eval () { 
    int nQP = sol().size1();
    for(int i=0; i< nQP; i++) {
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
};

class dgConservationLawShallowWater2d::source: public dataCacheDouble {
  dataCacheDouble &xyz, &solution,&solutionGradient;
  public :
  source(dataCacheMap &cacheMap) : 
    dataCacheDouble(cacheMap,cacheMap.getNbEvaluationPoints(),3),
    xyz(cacheMap.get("XYZ",this)),
    solution(cacheMap.get("Solution",this)),
    solutionGradient(cacheMap.get("SolutionGradient",this))
  {}
  void _eval () {
    int nQP =_value.size1();
    for (int i=0; i<nQP; i++) {
      double eta = solution(i,0);
      double u = solution(i,1);
      double v = solution(i,2);
      double dudx = solutionGradient(i*3,1);
      double dvdx = solutionGradient(i*3,2);
      double dudy = solutionGradient(i*3+1,1);
      double dvdy = solutionGradient(i*3+1,2);
      double wind = 0.1*sin(xyz(i,1)/1e6*M_PI)/1000/h;
      double f = 1e-4+xyz(i,1)*2e-11;
      _value (i,0) = 0;
      _value (i,1) = f*v + - linearDissipation*u + wind + u*(dudx+dvdy);
      _value (i,2) = -f*u - linearDissipation*v         + v*(dudx+dvdy);
    }
  }
};
class dgConservationLawShallowWater2d::riemann:public dataCacheDouble {
  dataCacheDouble &normals, &solL, &solR;
  public:
  riemann(dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight):
    dataCacheDouble(cacheMapLeft,cacheMapLeft.getNbEvaluationPoints(),6),
    normals(cacheMapLeft.get("Normals", this)),
    solL(cacheMapLeft.get("Solution", this)),
    solR(cacheMapRight.get("Solution", this))
  {};
  void _eval () { 
    int nQP = solL().size1();
    for(int i=0; i< nQP; i++) {
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

class dgConservationLawShallowWater2d::boundaryWall : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals;
    public:
    term(dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap),
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
  boundaryWall(dgConservationLaw *claw) : dgBoundaryCondition(claw){}
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
  return new boundaryWall(this);
}

#include "Bindings.h"
void dgConservationLawShallowWater2dRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawShallowWater2d>("dgConservationLawShallowWater2d");
  cb->setDescription("The conservative sallow water conservation law. (H, Hu, Hv)");
  methodBinding *cm;
  cm = cb->addMethod("newBoundaryWall",&dgConservationLawShallowWater2d::newBoundaryWall);
  cm->setDescription("slip wall boundary");
  cm = cb->setConstructor<dgConservationLawShallowWater2d>();
  cm->setDescription("A new shallow water conservation law.");
  cb->setParentClass<dgConservationLaw>();
}
