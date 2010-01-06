#include "dgConservationLawPerfectGas.h"
#include "function.h"

/*
\rho \left(\frac{\partial \mathbf{v}}{\partial t} + \mathbf{v} \cdot \nabla \mathbf{v}\right) = -\nabla p + \mu \nabla^2 \mathbf{v} + \left( \tfrac13 \mu + \mu^v) \nabla (\nabla \cdot \mathbf{v} \right) + \rho \mathbf{f} 
*/

const double GAMMA = 1.4;
static inline void _ROE2D (const double &_GAMMA,
			   const double &nx,  
			   const double &ny,  
			   const double *solL,
			   const double *solR,
			   double *FLUX){

  const double gamma = _GAMMA;
  const double GM1 = gamma - 1.;
  
  double uL[4], uR[4];
  const double overRhoL = 1./solL[0];	
  uL[0] = solL[0];
  uL[1] = solL[1]*overRhoL; 
  uL[2] = solL[2]*overRhoL;
  uL[3] = GM1*(solL[3] - 0.5* (solL[1]*solL[1]+solL[2]*solL[2])*overRhoL); 
  
  const double overRhoR = 1./solR[0];	
  uR[0] = solR[0];
  uR[1] = solR[1]*overRhoR; 
  uR[2] = solR[2]*overRhoR;
  uR[3] = GM1*(solR[3] - 0.5* (solR[1]*solR[1]+solR[2]*solR[2])*overRhoR); 
  // central contributions 
  
  double halfrhoun;                           
  
  /* --- left contributions ---*/
  halfrhoun = 0.5*(uL[0]*(uL[1]*nx + uL[2]*ny));
  double HL        = gamma/GM1* uL[3]/uL[0]+0.5*(uL[1]*uL[1]+
						 uL[2]*uL[2]);
  
  FLUX[0] = halfrhoun;
  FLUX[1] = halfrhoun*uL[1] + .5*uL[3]*nx;
  FLUX[2] = halfrhoun*uL[2] + .5*uL[3]*ny;
  FLUX[3] = halfrhoun*HL; 
  
  /* --- right contributions ---*/
  
  halfrhoun = 0.5*(uR[0]*(uR[1]*nx+uR[2]*ny));
  double HR        = gamma/GM1* uR[3]/uR[0]+0.5*(uR[1]*uR[1]+uR[2]*uR[2]);
  
  FLUX[0] += halfrhoun;
  FLUX[1] += halfrhoun*uR[1] + .5*uR[3]*nx;
  FLUX[2] += halfrhoun*uR[2] + .5*uR[3]*ny;
  FLUX[3] += halfrhoun*HR; 

  /* --- add dissipation ---*/       	
  
  double sqr_rhoL = sqrt(uL[0]);					
  double sqr_rhoR = sqrt(uR[0]);					
  
  double invz1  = 1./ (sqr_rhoL + sqr_rhoR);
  
  // double rho  =   sqr_rhoL * sqr_rhoR;					  
  double u    = ( sqr_rhoL* uL[1] + sqr_rhoR * uR[1] ) * invz1;	  
  double v    = ( sqr_rhoL* uL[2] + sqr_rhoR * uR[2] ) * invz1;	  
  double H    = ( sqr_rhoL* HL    + sqr_rhoR * HR    ) * invz1;	  
  
  double dU[4];
  for (int k=0;k<4;k++) dU[k] = solR[k] - solL[k];
  
  double un   = u*nx + v*ny ; 
  double tet  = ny*u - nx*v;
  
  double u2 = u*u + v*v;						  
  double c2 = GM1 * ( H - 0.5 * u2);
  double c = sqrt(c2);
  
  double g1  = gamma - 1.;
  double oC  = 1./c;
  double oC2 = oC*oC;
  
  double g1OnC2 = g1*oC2;
  double TtOnT     = (1.0 - u2*g1OnC2);
  
  // matrix of left eigenvectors
  
  double L[16] = {
    nx*TtOnT       ,nx*u*g1OnC2      ,nx*v*g1OnC2 , -nx*g1OnC2, // L1
    - tet          , ny              ,-nx         , 0,          // L3
    g1*u2 - c*un   , c*nx - g1*u     , c*ny - g1*v, g1,         // L3
    g1*u2 + c*un   ,-c*nx - g1*u     ,-c*ny - g1*v, g1};        // L4
  
  
  // characteristic decomposition of differences  
  
  double dW[4] = {0,0,0,0};
  int idx = 0;
  for (int i=0;i<4;i++)
    for (int j=0;j<4;j++)
      dW[i] += L[idx++]*dU[j];
  
  // matrix of right eigenvectors
  
  double R[16] = {
    //R1 //R2   //R3                //R4              
    nx   ,0     ,0.5*oC2            ,0.5*oC2,
    u*nx ,ny    ,0.5*(nx*oC + u*oC2),0.5*(-nx*oC + u*oC2),
    v*nx ,- nx  ,0.5*(ny*oC + v*oC2),0.5*(-ny*oC + v*oC2),
    u2*nx,tet   ,0.5*(un*oC + H*oC2),0.5*(-un*oC + H*oC2)};
  
  
  // eigenvalues
  // KH : shouldn't we take into account an entropy correction ?
    // absorb half the surface : scaling wrt central term
  
  
  const double A = 0.5;
  double eps = 1.e-6;
  double absUn = (fabs(un) + eps*c)*A;
  double lA[4] = {absUn,
		  absUn,
		  fabs(un + c)*A,
		  (fabs(un - c)+eps*c)*A};
  
  // add wave contributions to flux
  int index = 0;
  
  for (int k=0;k<4;k++) {
    double lflux = FLUX[k];
    for (int j=0;j<4;j++)
      lflux -= lA[j]*dW[j]*R[index++];
    FLUX[k] = -lflux;
  }
} 
// perfect gas law, GAMMA is the only parameter

class dgPerfectGasLaw2d::advection : public dataCacheDouble {
  dataCacheDouble &sol;
  public:
  advection(dataCacheMap &cacheMap):
    sol(cacheMap.get("Solution",this))
  {};
  void _eval () { 
    const int nQP = sol().size1();      
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,8);
    const double GM1 = GAMMA - 1.0;
    for (size_t k = 0 ; k < nQP; k++ ){
      //	printf("%d %g %g %g %g\n",k,sol(k,0),sol(k,1),sol(k,2),sol(k,3));
      const double invrho = 1./sol(k,0);

      const double q12 = sol(k,1)*sol(k,2)*invrho;
      const double q11 = sol(k,1)*sol(k,1)*invrho;
      const double q22 = sol(k,2)*sol(k,2)*invrho;

      const double p = GM1*sol(k,3) - 0.5*GM1*(q11+q22);
      const double qq = invrho*(sol(k,3)+p);

      _value(k,0)   = sol(k,1);
      _value(k,1) = q11+p;
      _value(k,2) = q12;
      _value(k,3) = sol(k,1)*qq;

      _value(k,0+4) = sol(k,2);
      _value(k,1+4) = q12;
      _value(k,2+4) = q22+p;
      _value(k,3+4) = sol(k,2)*qq;

      /*	_value(k,8) = 0;
          _value(k,9) = 0;
          _value(k,10) = 0;
          _value(k,11) = 0;*/
    }
  }
};

class dgPerfectGasLaw2d::diffusion : public dataCacheDouble {
  dataCacheDouble &sol,&grad,&mu,&kappa;
  public:
  diffusion(dataCacheMap &cacheMap, 
	    const std::string &muFunctionName,
	    const std::string &kappaFunctionName ):
    sol(cacheMap.get("Solution",this)),
    grad(cacheMap.get("SolutionGradient",this)),
    mu(cacheMap.get(muFunctionName,this)),
    kappa(cacheMap.get(kappaFunctionName,this))
  {};
  void _eval () { 
    const int nQP = sol().size1();      
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,12);

    for (size_t k = 0 ; k < nQP; k++ ){
      const double muk    = mu(k,0);
      const double kappak = kappa(k,0);      
      //      printf("%g %g grad rho (%g %g)\n",muk,kappak,grad(k*3+0,0),grad(k*3+1,0));
    // find gradients of primitive variables    
      const double overRho = 1./sol(k,0);
      const double u = sol(k,1) * overRho;
      const double v = sol(k,2) * overRho;
      // grad v    
      const double dudx = (grad(k*3+0,1) - grad(k*3+0,0) * u) * overRho;
      const double dudy = (grad(k*3+1,1) - grad(k*3+1,0) * u) * overRho;
      const double dvdx = (grad(k*3+0,2) - grad(k*3+0,0) * v) * overRho;
      const double dvdy = (grad(k*3+1,2) - grad(k*3+1,0) * v) * overRho;    
      // shear stress tensor - Newtonian fluid without bulk viscosity
      
      const double tauxx = muk * (dudx - dvdy);
      const double tauxy = muk * (dudy + dvdx);
      const double tauyy = - tauxx;
    
      _value(k,1) = -tauxx;
      _value(k,2) = -tauxy;
    
      _value(k,1+4) = -tauxy;
      _value(k,2+4) = -tauyy;    
      // heat flux
    
      const double kOverRhoCv = kappak * overRho; 
      const double Ek = u * u + v * v;
      const double eMinus= sol(k,3) * overRho - Ek;
    
      // k grad T
      
      _value(k,3)      = -kOverRhoCv*(grad(k*3+0,3) - eMinus*grad(k*3+0,0) - (grad(k*3+0,1)*u + grad(k*3+0,2)*v));
      _value(k,3+4)    = -kOverRhoCv*(grad(k*3+1,3) - eMinus*grad(k*3+1,0) - (grad(k*3+1,1)*u + grad(k*3+1,2)*v));
      
      // v . tau - momentum dissipation
      
      _value(k,3)      -= (u * tauxx + v * tauxy);
      _value(k,3+4)    -= (u * tauxy + v * tauyy);         
      
      //      printf("%g %g %g %g %g %g %g %g \n",_value(k,0),_value(k,1),_value(k,2),_value(k,3),_value(k,4),_value(k,5),_value(k,6),_value(k,7));
      
    }
  }
};

class dgPerfectGasLaw2d::source : public dataCacheDouble {
  dataCacheDouble &sol,&s;
public:
  source(dataCacheMap &cacheMap, const std::string &sourceFunctionName):
    sol(cacheMap.get("Solution",this)),
    s(cacheMap.get(sourceFunctionName,this))
  {};
  void _eval () { 
    const int nQP = sol().size1();      
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,4);
    for (size_t k = 0 ; k < nQP; k++ ){
      _value(k,0) = sol(k,0)*s(0,0);
      _value(k,1) = sol(k,0)*s(0,1);
      _value(k,2) = sol(k,0)*s(0,2);
      _value(k,3) = sol(k,0)*s(0,3);
    }
  }
};


class dgPerfectGasLaw2d::riemann : public dataCacheDouble {
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
      _value = fullMatrix<double>(nQP,12);

    for(int i=0; i< nQP; i++) {
      const double solLeft [4] = {solL(i,0),solL(i,1),solL(i,2),solL(i,3)};
      const double solRight[4] = {solR(i,0),solR(i,1),solR(i,2),solR(i,3)};
      double FLUX[4] ;
      const double nx = normals(0,i);
      const double ny = normals(1,i);
      _ROE2D (GAMMA,nx,ny,solLeft,solRight,FLUX);

      _value(i,0) = FLUX[0];
      _value(i,1) = FLUX[1];
      _value(i,2) = FLUX[2];
      _value(i,3) = FLUX[3];
      _value(i,4) = -_value(i,0);
      _value(i,5) = -_value(i,1);
      _value(i,6) = -_value(i,2);
      _value(i,7) = -_value(i,3);
    }
  }
};

class dgPerfectGasLaw2d::maxConvectiveSpeed : public dataCacheDouble {
  dataCacheDouble &sol;
  public:
  maxConvectiveSpeed(dataCacheMap &cacheMap):
    sol(cacheMap.get("Solution",this))
  {
  };
  void _eval () {
    int nQP = sol().size1();
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,1);
    for(int i=0; i< nQP; i++) {
      const double rhov2 = (sol(i,1)*sol(i,1) + sol(i,2)*sol(i,2))/sol(i,0);
      const double p = (GAMMA-1.0)*(sol(i,3) - 0.5 * rhov2);
      //      printf("p = %g %g %g %g %g\n",p,_value(i,0),_value(i,1),_value(i,2),_value(i,3));
      const double c = sqrt(GAMMA*p/sol(i,0));
      _value(i,0) = c+sqrt(rhov2/sol(i,0));
    }
  }
};

class dgPerfectGasLaw2d::maxDiffusivity : public dataCacheDouble {
  dataCacheDouble &sol,&mu,&kappa;
  public:
  maxDiffusivity(dataCacheMap &cacheMap, const std::string &muFunctionName, const std::string &kappaFunctionName ):
    sol(cacheMap.get("Solution",this)),
    mu(cacheMap.get(muFunctionName,this)),
    kappa(cacheMap.get(kappaFunctionName,this))
  {
  };
  void _eval () {
    int nQP = sol().size1();
    if(_value.size1() != nQP)
      _value=fullMatrix<double>(nQP,1);
    for(int i=0; i< nQP; i++) {
      _value(i,0) = std::max(mu(i,0),kappa(i,0));
    }
  }
};


dataCacheDouble *dgPerfectGasLaw2d::newMaximumDiffusivity( dataCacheMap &cacheMap) const {
  return _muFunctionName.empty() ? NULL : new maxDiffusivity(cacheMap,_muFunctionName,_kappaFunctionName);
}

dataCacheDouble *dgPerfectGasLaw2d::newMaxConvectiveSpeed( dataCacheMap &cacheMap) const {
  return new maxConvectiveSpeed(cacheMap);
}
dataCacheDouble *dgPerfectGasLaw2d::newConvectiveFlux( dataCacheMap &cacheMap) const {
  return new advection(cacheMap);
}
dataCacheDouble *dgPerfectGasLaw2d::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  return new riemann(cacheMapLeft, cacheMapRight);
}
dataCacheDouble *dgPerfectGasLaw2d::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  if (_muFunctionName.empty() || _kappaFunctionName.empty())
    return 0;
  else
    return new diffusion(cacheMap,_muFunctionName,_kappaFunctionName);
}
dataCacheDouble *dgPerfectGasLaw2d::newSourceTerm (dataCacheMap &cacheMap) const {
  if (_sourceFunctionName.empty())
    return 0;
  else
    return new source(cacheMap,_sourceFunctionName);    
}

dgPerfectGasLaw2d::dgPerfectGasLaw2d() 
{
  _nbf = 4; // \rho \rho u \rho v \rho e
}

//-------------------------------------------------------------------------------
// A class for slip and non slip walls
// could easily add moving walls ...
//-------------------------------------------------------------------------------
class dgBoundaryConditionPerfectGasLaw2dWall : public dgBoundaryCondition {
  int _type;
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals;
  public:
//-------------------------------------------------------------------------------
// NON VISCOUS BOUNDARY FLUX
//-------------------------------------------------------------------------------
    term(dataCacheMap &cacheMap):
      sol(cacheMap.get("Solution",this)),
      normals(cacheMap.get("Normals",this)){}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
	_value = fullMatrix<double>(nQP,4);
      
      for(int i=0; i< nQP; i++) {
	const double nx = normals(0,i);
	const double ny = normals(1,i);
	const double solLeft [4] = {sol(i,0),sol(i,1),sol(i,2),sol(i,3)};
	const double vn = (solLeft [1] * nx +  solLeft [2] * ny);
	const double solRight[4] = {sol(i,0),
				    sol(i,1) - 2 * vn  * nx,
				    sol(i,2) - 2 * vn  * ny,
				    sol(i,3)};
	double FLUX[4] ;
	_ROE2D (GAMMA,nx,ny,solLeft,solRight,FLUX);
	_value(i,0) = FLUX[0];
	_value(i,1) = FLUX[1];
	_value(i,2) = FLUX[2];
	_value(i,3) = FLUX[3];
	/*
	const double q11 = sol(i,1)*sol(i,1)/sol(i,0);
	const double q22 = sol(i,2)*sol(i,2)/sol(i,0);
	const double p = (GAMMA-1)*sol(i,3) - 0.5*(GAMMA-1)*(q11+q22);
	_value(i,0) = 0;//FLUX[0];
	_value(i,1) = -p*nx;//FLUX[1];
	_value(i,2) = -p*ny;//FLUX[2];
	_value(i,3) = 0.0;//FLUX[3];
	*/
      }
    }
  };

//-------------------------------------------------------------------------------
// Non Slip Dirichlet BC --
// What to put on the right side of the IP (no velocity, same density) 
// Assume Adiabatic Wall --> no heat transfer -> \partial_n T = 0
// So, we use the same temperature as inside
//-------------------------------------------------------------------------------
  class dirichletNonSlip : public dataCacheDouble {
    dataCacheDouble &sol;
    public:
    dirichletNonSlip(dataCacheMap &cacheMap):
    sol(cacheMap.get("Solution",this)){}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
	_value = fullMatrix<double>(nQP,4);
      
      for(int i=0; i< nQP; i++) {
	_value(i,0) = sol(i,0);
	_value(i,1) = 0.0;
	_value(i,2) = 0.0;
	_value(i,3) = sol(i,3) - 0.5 * (sol(i,1) * sol(i,1) + sol(i,2) * sol(i,2))/sol(i,0);
      }
    }
  };

//-------------------------------------------------------------------------------
// Non Slip Neumann BC --
// Compute normal diffusive fluxes at the boundary
// Assume Adiabatic Wall --> no heat transfer -> no flux for component 3 (in 2D)
//-------------------------------------------------------------------------------

  class neumannNonSlip : public dataCacheDouble {
    dgConservationLaw *_claw;
    dataCacheDouble &sol,&normals;
    dataCacheDouble *diffusiveFlux;
  public:
    neumannNonSlip(dataCacheMap &cacheMap, dgConservationLaw *claw):
      _claw (claw),
      sol(cacheMap.get("Solution",this)),
      normals(cacheMap.get("Normals",this)){
      diffusiveFlux=_claw->newDiffusiveFlux(cacheMap);
      if (diffusiveFlux)diffusiveFlux->addMeAsDependencyOf(this);
    }
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
	_value = fullMatrix<double>(nQP,4);

      const fullMatrix<double> &dfl = (*diffusiveFlux)();

      for(int i=0; i< nQP; i++) {
	for (int k=0;k<3;k++) { 
          _value(i,k) = 
	    dfl(i,k+4*0) *normals(0,i) +
	    dfl(i,k+4*1) *normals(1,i) +
	    dfl(i,k+4*2) *normals(2,i);
	}
	_value(i,3) = 0.0; 
      }
    }
    ~neumannNonSlip () {if (diffusiveFlux)delete diffusiveFlux;}
  };

//-------------------------------------------------------------------------------
// Slip Wall Dirichlet BC --
// Assume zero derivatives of all variables --> put the same as inside 
//-------------------------------------------------------------------------------

  class dirichletSlip : public dataCacheDouble {
    dataCacheDouble &sol;
    public:
    dirichletSlip(dataCacheMap &cacheMap):
    sol(cacheMap.get("Solution",this)){}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
	_value = fullMatrix<double>(nQP,sol().size2());
      
      for(int i=0; i< nQP; i++) {
	for(int k=0; k< sol().size2(); k++) {
	  _value(i,k) = sol(i,k);
	}
      }
    }
  };

//-------------------------------------------------------------------------------
// Slip Wall or Symmetry Neumann BC -- assume NO FLUXES AT ALL
//-------------------------------------------------------------------------------

  class neumannSlip : public dataCacheDouble {
    dgConservationLaw *_claw;
    dataCacheDouble &sol,&normals;
  public:
    neumannSlip(dataCacheMap &cacheMap, dgConservationLaw *claw):
      _claw (claw),
      sol(cacheMap.get("Solution",this)),
      normals(cacheMap.get("Normals",this)){
    }
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
	_value = fullMatrix<double>(nQP,4);
      _value.setAll(0.0);
    }
  };

  public:
    dgBoundaryConditionPerfectGasLaw2dWall(int type, dgPerfectGasLaw2d *claw):_type(type), dgBoundaryCondition(claw){}
    dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
      return new term(cacheMapLeft);
    }
    dataCacheDouble *newDiffusiveDirichletBC(dataCacheMap &cacheMapLeft) const {
      switch(_type){
      case 1 : return new dirichletSlip(cacheMapLeft);
      case 2 : return new dirichletNonSlip(cacheMapLeft);
      }
    }
    dataCacheDouble *newDiffusiveNeumannBC(dataCacheMap &cacheMapLeft) const {
      switch(_type){
      case 1 : return new neumannSlip(cacheMapLeft,_claw);
      case 2 : return new neumannNonSlip(cacheMapLeft,_claw);
      }
    }
};

dgBoundaryCondition *dgPerfectGasLaw2d::newWallBoundary()  {
  return new dgBoundaryConditionPerfectGasLaw2dWall(2, this);
}
dgBoundaryCondition *dgPerfectGasLaw2d::newSlipWallBoundary()  {
  return new dgBoundaryConditionPerfectGasLaw2dWall(1, this);
}

#include "Bindings.h"
void dgPerfectGasLaw2dRegisterBindings (binding *b){
  classBinding *cb = b->addClass<dgPerfectGasLaw2d>("dgPerfectGasLaw2d");
  methodBinding *cm;
  cb->addMethod("newWallBoundary",&dgPerfectGasLaw2d::newWallBoundary);
  cb->addMethod("newNonSlipWallBoundary",&dgPerfectGasLaw2d::newWallBoundary);
  cb->addMethod("newSlipWallBoundary",&dgPerfectGasLaw2d::newSlipWallBoundary);
  cb->addMethod("setSource",&dgPerfectGasLaw2d::setSource);
  cb->addMethod("setViscosityAndThermalConductivity",&dgPerfectGasLaw2d::setViscosityAndThermalConductivity);
  cb->setConstructor<dgPerfectGasLaw2d>();
  cb->setParentClass<dgConservationLaw>();
}
