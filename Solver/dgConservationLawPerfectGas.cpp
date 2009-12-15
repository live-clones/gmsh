#include "dgConservationLawPerfectGas.h"
#include "function.h"

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
      _value = fullMatrix<double>(nQP,8);

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
dataCacheDouble *dgPerfectGasLaw2d::newConvectiveFlux( dataCacheMap &cacheMap) const {
  return new advection(cacheMap);
}
dataCacheDouble *dgPerfectGasLaw2d::newRiemannSolver( dataCacheMap &cacheMapLeft, dataCacheMap &cacheMapRight) const {
  return new riemann(cacheMapLeft, cacheMapRight);
}
dataCacheDouble *dgPerfectGasLaw2d::newDiffusiveFlux( dataCacheMap &cacheMap) const {
  return 0;
}
dataCacheDouble *dgPerfectGasLaw2d::newSourceTerm (dataCacheMap &cacheMap) const {
  return 0;
}
dgPerfectGasLaw2d::dgPerfectGasLaw2d() 
{
  _nbf = 4; // \rho \rho u \rho v \rho e
}


class dgBoundaryConditionPerfectGasLaw2dWall : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals;
    public:
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
	//	double FLUX[4] ;
	//	_ROE2D (GAMMA,nx,ny,solLeft,solRight,FLUX);
	const double q11 = sol(i,1)*sol(i,1)/sol(i,0);
	const double q22 = sol(i,2)*sol(i,2)/sol(i,0);
	const double p = (GAMMA-1)*sol(i,3) - 0.5*(GAMMA-1)*(q11+q22);
	_value(i,0) = 0;//FLUX[0];
	_value(i,1) = -p*nx;//FLUX[1];
	_value(i,2) = -p*ny;//FLUX[2];
	_value(i,3) = 0.0;//FLUX[3];
      }
    }
  };
  public:
  dgBoundaryConditionPerfectGasLaw2dWall(){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft);
  }
};
dgBoundaryCondition *dgPerfectGasLaw2d::newWallBoundary() const {
  return new dgBoundaryConditionPerfectGasLaw2dWall();
}

#if 0 // JF : I commented this out as I think this equivalent to the generic OutsideValue condition
can you confirm and remove it ?
class dgBoundaryConditionPerfectGasLaw2dFreeStream : public dgBoundaryCondition {
  class term : public dataCacheDouble {
    dataCacheDouble &sol,&normals,&freeStream;
    public:
    term(dataCacheMap &cacheMap, const std::string & freeStreamName):
    sol(cacheMap.get("Solution",this)),
    normals(cacheMap.get("Normals",this)),
    freeStream(cacheMap.get(freeStreamName,this)){}
    void _eval () { 
      int nQP = sol().size1();
      if(_value.size1() != nQP)
	_value = fullMatrix<double>(nQP,4);
      
      for(int i=0; i< nQP; i++) {
	const double nx = normals(0,i);
	const double ny = normals(1,i);
	const double solLeft [4] = {sol(i,0),sol(i,1),sol(i,2),sol(i,3)};
	const double solRight[4] = {freeStream(i,0),
				    freeStream(i,1),
				    freeStream(i,2),
				    freeStream(i,3)};
	double FLUX[4] ;
	_ROE2D (GAMMA,nx,ny,solLeft,solRight,FLUX);
	/*
	printf("SOLL %g %g %g %g\n",solLeft[0],solLeft[1],solLeft[2], solLeft[3]);
	printf("SOLR %g %g %g %g\n",solRight[0],solRight[1],solRight[2], solRight[3]);
	printf("N    %g %g\n",nx,ny);
	printf("FLUX %g %g %g %g\n",FLUX[0],FLUX[1],FLUX[2],FLUX[3]);
	*/
	_value(i,0) = FLUX[0];
	_value(i,1) = FLUX[1];
	_value(i,2) = FLUX[2];
	_value(i,3) = FLUX[3];
      }
    }
  };
  public:
  std::string _freeStreamName;
  dgBoundaryConditionPerfectGasLaw2dFreeStream(std::string & freeStreamName)
    : _freeStreamName(freeStreamName){}
  dataCacheDouble *newBoundaryTerm(dataCacheMap &cacheMapLeft) const {
    return new term(cacheMapLeft,_freeStreamName);
  }
};
#endif

#include "Bindings.h"
const char *dgPerfectGasLaw2d::className = "ConservationLawPerfectGas2d";
const char *dgPerfectGasLaw2d::parentClassName = "ConservationLaw";
methodBinding *dgPerfectGasLaw2d::methods[] ={
  new methodBindingTemplate<const dgPerfectGasLaw2d,dgBoundaryCondition*>("newWallBoundary",&dgPerfectGasLaw2d::newWallBoundary),
0};
constructorBinding *dgPerfectGasLaw2d::constructorMethod=new constructorBindingTemplate<dgPerfectGasLaw2d>();

