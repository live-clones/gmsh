#include "dgConservationLaw.h"
#include "dgConservationLawMaxwell.h"
#include "function.h"


class dgConservationLawMaxwell::advection : public dataCacheDouble {
  dataCacheDouble &sol, &mu_eps;
  public:
  advection(std::string mu_epsFunctionName,dataCacheMap &cacheMap):
    dataCacheDouble(cacheMap),
    sol(cacheMap.get("Solution",this)), 
    mu_eps(cacheMap.get(mu_epsFunctionName,this))
  {};
  void _eval () { 
    int nQP = sol().size1();
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,18);
    for(int i=0; i< nQP; i++) {
      double Ex = sol(i,0);
      double Ey = sol(i,1);
      double Ez = sol(i,2);

      double Hx = sol(i,3);
      double Hy = sol(i,4);
      double Hz = sol(i,5);
      // flux_x
      _value(i,0) = 0;
      _value(i,1) = -Hz*mu_eps(i,1);
      _value(i,2) = Hy*mu_eps(i,2);
      _value(i,3) = 0;
      _value(i,4) = Ez*mu_eps(i,4);
      _value(i,5) = -Ey*mu_eps(i,5);
      // flux_y
      _value(i,6) = Hz*mu_eps(i,0);
      _value(i,7) =0;
      _value(i,8) =-Hx*mu_eps(i,2);
      _value(i,9) =-Ez*mu_eps(i,3);
      _value(i,10) =0;
      _value(i,11) =Ex*mu_eps(i,5);
      // flux_z
      _value(i,12) =-Hy*mu_eps(i,0);
      _value(i,13) = Hx*mu_eps(i,1);
      _value(i,14) =0;
      _value(i,15) =Ey*mu_eps(i,3);
      _value(i,16) =-Ex*mu_eps(i,4);
      _value(i,17) = 0;
      
    }
  }
};


class dgConservationLawMaxwell::source: public dataCacheDouble {
  dataCacheDouble &xyz, &solution;
  public :
  source(dataCacheMap &cacheMap) : 
    dataCacheDouble(cacheMap),
    xyz(cacheMap.get("XYZ",this)),
    solution(cacheMap.get("Solution",this))
  {}
  void _eval () {
    int nQP = xyz().size1();
    if(_value.size1() != nQP)
      _value = fullMatrix<double>(nQP,6);
    for (int i=0; i<nQP; i++) {
    
      _value (i,0) = 0;
      _value (i,1) = 0;
      _value (i,2) = 0;
      _value (i,3) = 0;
      _value (i,4) = 0;
      _value (i,5) = 0;
    }
  }
};


class dgConservationLawMaxwell::riemann:public dataCacheDouble {
  dataCacheDouble &normals, &solL, &solR, &mu_eps;
  public:
  riemann(std::string mu_epsFunctionName,dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight):
    dataCacheDouble(cacheMapLeft),
    normals(cacheMapLeft.get("Normals", this)),
    solL(cacheMapLeft.get("Solution", this)),
    solR(cacheMapRight.get("Solution", this)),
    mu_eps(cacheMapLeft.get(mu_epsFunctionName,this))
  {};
  void _eval () { 
    int nQP = solL().size1();
    if(_value.size1() != nQP)
      _value = fullMatrix<double>(nQP,12);
    for(int i=0; i< nQP; i++) {

      double nx= normals(0,i);
      double ny= normals(1,i);
      double nz= normals(2,i);

      double ExL = solL(i,0);
      double EyL = solL(i,1);
      double EzL = solL(i,2);

      double HxL = solL(i,3);
      double HyL = solL(i,4);
      double HzL = solL(i,5);
     

      double ExR = solR(i,0);
      double EyR = solR(i,1);
      double EzR = solR(i,2);

      double HxR = solR(i,3);
      double HyR = solR(i,4);
      double HzR = solR(i,5);
     

      
      double FexL =  (HzL*ny -HyL*nz)*mu_eps(i,0);
      double FeyL = (-HzL*nx + HxL*nz)*mu_eps(i,1);
      double FezL = (HyL*nx -HxL*ny)*mu_eps(i,2);
      double FhxL = (-EzL*ny + EyL*nz)*mu_eps(i,3);
      double FhyL = (EzL*nx - ExL*nz)*mu_eps(i,4);
      double FhzL = ( -EyL*nx  + ExL*ny)*mu_eps(i,5);
      
      double FexR = (HzR*ny - HyR*nz)*mu_eps(i,0);
      double FeyR = (-HzR*nx + HxR*nz)*mu_eps(i,1);
      double FezR = ( HyR*nx - HxR*ny)*mu_eps(i,2);
      double FhxR = (-EzR*ny + EyR*nz)*mu_eps(i,3);
      double FhyR = (EzR*nx - ExR*nz)*mu_eps(i,4);
      double FhzR = (-EyR*nx + ExR*ny)*mu_eps(i,5);
      
      
      
      double Fwex = ((ny*(EzL-EzR) -(EyL-EyR)*nz))*mu_eps(i,0);
      double Fwey = ((nz*(ExL-ExR) - (EzL-EzR)*nx))*mu_eps(i,1);
      double Fwez = (((EyL-EyR)*nx -(ExL-ExR)*ny))*mu_eps(i,2);
      double Fwhx = ((ny*(HzL-HzR) -(HyL-HyR)*nz))*mu_eps(i,3);
      double Fwhy = ((nz*(HxL-HxR) - (HzL-HzR)*nx))*mu_eps(i,4);
      double Fwhz = (((HyL-HyR)*nx -(HxL-HxR)*ny))*mu_eps(i,5);
      
      
      _value(i,0) =-((FexL+FexR)/2-(ny*Fwez-nz*Fwey)/2);
      _value(i,1) =-((FeyL+FeyR)/2-(nz*Fwex-nx*Fwez)/2);
      _value(i,2) =-((FezL+FezR)/2-(nx*Fwey-ny*Fwex)/2);
      _value(i,3) =-((FhxL+FhxR)/2-(ny*Fwhz-nz*Fwhy)/2);
      _value(i,4) =-((FhyL+FhyR)/2-(nz*Fwhx-nx*Fwhz)/2);
      _value(i,5) =-((FhzL+FhzR)/2-(nx*Fwhy-ny*Fwhx)/2);  
     
         
      _value(i,6) =-_value(i,0);
      _value(i,7) =-_value(i,1);
      _value(i,8) =-_value(i,2);
      _value(i,9) =-_value(i,3);
      _value(i,10) =-_value(i,4);
      _value(i,11) =-_value(i,5); 
     
     
    }
  }
};


dataCacheDouble *dgConservationLawMaxwell::newConvectiveFlux( dataCacheMap &cacheMap) const {
  if( !_mu_epsFunctionName.empty())
    return new advection(_mu_epsFunctionName,cacheMap);
  else
    return NULL; 
}


dataCacheDouble *dgConservationLawMaxwell::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  if( !_mu_epsFunctionName.empty())
    return new riemann(_mu_epsFunctionName,cacheMapLeft, cacheMapRight);
  else
    return NULL;
}


dataCacheDouble *dgConservationLawMaxwell::newSourceTerm (dataCacheMap &cacheMap) const {
  return new source(cacheMap);
}

dgConservationLawMaxwell::dgConservationLawMaxwell(std::string mu_epsFunctionName)
{
   _mu_epsFunctionName = mu_epsFunctionName;
  _nbf = 6;
}


class dgBoundaryConditionMaxwellWall : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals;    
    public:
    term(dataCacheMap &cacheMap):
      dataCacheDouble(cacheMap),
      sol(cacheMap.get("Solution",this)),
      normals(cacheMap.get("Normals",this))
      {}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
        _value = fullMatrix<double>(nQP,6);
      for(int i=0; i< nQP; i++) {
        
      double nx= normals(0,i);
      double ny= normals(1,i);
      double nz= normals(2,i);

      double Ex = sol(i,0);
      double Ey = sol(i,1);
      double Ez = sol(i,2);

      double Hx = sol(i,3);
      double Hy = sol(i,4);
      double Hz = sol(i,5);
      
     
      _value(i,0) = (-Ez*ny+Ey*nz);
      _value(i,1) = (Ez*nx-Ex*nz);
      _value(i,2) = (-Ey*nx+Ex*ny);
      _value(i,3) = (Hz*ny-Hy*nz);
      _value(i,4) = (-Hz*nx+Hx*nz);
      _value(i,5) = (Hy*nx-Hx*ny);
      
      }
    }
  };
  public:
  dgBoundaryConditionMaxwellWall(dgConservationLaw *claw):dgBoundaryCondition(claw){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft);
  }
};
dgBoundaryCondition *dgConservationLawMaxwell::newBoundaryWall(){
  return new dgBoundaryConditionMaxwellWall(this);
}



#include "Bindings.h"
void dgConservationLawMaxwellRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgConservationLawMaxwell>("dgConservationLawMaxwell");
  cb->setDescription("The conservative law for Maxwell");
  methodBinding *cm;
   cm = cb->addMethod("newBoundaryWall",&dgConservationLawMaxwell::newBoundaryWall);
   cm->setDescription("wall boundary");
  cm = cb->setConstructor<dgConservationLawMaxwell, std::string>(); 
  cm->setArgNames("mu_eps",NULL);
  cm->setDescription("A new Maxwell conservation law.");
  cb->setParentClass<dgConservationLaw>();
 cb->setDescription("Advection for Maxwell equation.");
}
