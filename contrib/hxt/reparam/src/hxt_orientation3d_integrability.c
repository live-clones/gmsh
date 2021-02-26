// #include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_orientation3d_tools.h"  
#include <math.h>

HXTStatus getEulerConfig(double euler[3], double newEulerConfig[3], int idConfig[4]){ //dbg fct
  for(int i=0;i<3;i++)
    newEulerConfig[i]=euler[i];
  if(idConfig[3]==1){
    newEulerConfig[0]=newEulerConfig[0]-M_PI;
    newEulerConfig[1]=-newEulerConfig[1];
    newEulerConfig[2]=newEulerConfig[2]-M_PI;
  }
  else if(idConfig[3]!=0){
    printf("pb in getEulerConfig\n");
    exit(0);
  }
  for(int i=0;i<3;i++){
    if(idConfig[i]==0)
      newEulerConfig[i]=newEulerConfig[i]-2*M_PI;
    else if(idConfig[i]==1)
      newEulerConfig[i]=newEulerConfig[i];
    else if(idConfig[i]==2)
      newEulerConfig[i]=newEulerConfig[i]+2*M_PI;
    else{
      printf("pb in getEulerConfig\n");
      exit(0);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus computeEulerElem3(double dirElem[9*4],double eulerElem[3*4], const double dLdX[4][3], int *flagLoc){ //dbg fct
  *flagLoc=0;
  double flagNotUnique[4]={0.0};
  double *dir=dirElem;
      
  for(int k=0;k<4;k++){
    double euler[3]={0.0};  
    dir=dirElem+9*k;
    hxtOr3DdirectionsToEuler(dir,flagNotUnique+k,euler);
    for(int j=0;j<3;j++)
      eulerElem[3*k+j]=euler[j];
  }

  /* int indRef=0; */
  int elemNoNutation[4]={1,1,1,1};
  for(int k=0;k<4;k++)
    if(fabs(flagNotUnique[k])<1e-5){
      elemNoNutation[k]=0;
      /* indRef=k; */
    }
  /* //ICI */
  /* printf("-----------------********************--------------------\n"); */
  /* printf("eulemNoNutation :\n"); */
  /* printf("%i %i %i %i\n",elemNoNutation[0],elemNoNutation[1],elemNoNutation[2],elemNoNutation[3]); */
  /* printf("indRef : %i\n",indRef); */
  /* printf("u : %g %g %g\n",dirElem[0],dirElem[1],dirElem[2]); */
  /* printf("v : %g %g %g\n",dirElem[3],dirElem[4],dirElem[5]); */
  /* printf("w : %g %g %g\n",dirElem[6],dirElem[7],dirElem[8]); */
  /* printf("-----------------********************--------------------\n"); */
  /* printf("eulerRef :\n"); */
  /* printf("%g %g %g\n",eulerElem[0],eulerElem[1],eulerElem[2]); */
  for(int k=0;k<4;k++)
    if(elemNoNutation[k]){
      *flagLoc=1;
      printf("elem with no nutation, computeEulerElem3\n");
      return HXT_STATUS_OK;
      /* exit(0); */
    }

  double normInit=0.0;
  double gradInit[3][3]={{0.0}};
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<4;k++){
	gradInit[i][j]+=dLdX[k][j]*eulerElem[3*k+i];
      }
    }
  }

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      normInit+=gradInit[i][j]*gradInit[i][j];

  double normMin=normInit;
  double eulerElemFinal[4*3]={0.0};
  for(int a=0;a<4;a++)
    for(int b=0;b<3;b++)
      eulerElemFinal[3*a+b]=eulerElem[3*a+b];
  
  int idConfig[4][4]={{0}};
  for(int i=1;i<2;i++){
    for(int j=1;j<2;j++){
      for(int k=1;k<2;k++){
	for(int l=0;l<3;l++){
	  for(int m=0;m<3;m++){
	    for(int n=0;n<3;n++){
	      for(int o=0;o<3;o++){
		for(int p=0;p<3;p++){
		  for(int q=0;q<3;q++){
		    for(int r=0;r<3;r++){
		      for(int s=0;s<3;s++){
			for(int t=0;t<3;t++){
			  for(int u=0;u<1;u++){
			    for(int v=0;v<2;v++){
			      for(int w=0;w<2;w++){
				for(int x=0;x<2;x++){
				  idConfig[0][0]=i;
				  idConfig[0][1]=j;
				  idConfig[0][2]=k;
				  idConfig[0][3]=u;
				  idConfig[1][0]=l;
				  idConfig[1][1]=m;
				  idConfig[1][2]=n;
				  idConfig[1][3]=v;
				  idConfig[2][0]=o;
				  idConfig[2][1]=p;
				  idConfig[2][2]=q;
				  idConfig[2][3]=w;
				  idConfig[3][0]=r;
				  idConfig[3][1]=s;
				  idConfig[3][2]=t;
				  idConfig[3][3]=x;
				  double eulerElemTry[3*4]={0.0};
				  for(int a=0;a<4;a++)
				    for(int b=0;b<3;b++)
				      eulerElemTry[3*a+b]=eulerElem[3*a+b];
				  for(int a=0;a<4;a++){
				    int configNode[4]={0};
				    for(int b=0;b<4;b++)
				      configNode[b]=idConfig[a][b];
				    getEulerConfig(eulerElem+3*a, eulerElemTry+3*a, configNode);
				  }
				  //ICI
				  double normTry=0.0;
				  double gradTry[3][3]={{0.0}};
				  /* printf("+++++++++++++++++++++++++++++++++++++\n"); */
				  /* printf("eulerRef Final:\n"); */
				  /* printf("%g %g %g\n",eulerRef[0],eulerRef[1],eulerRef[2]); */
				  for(int i=0;i<3;i++){
				    for(int j=0;j<3;j++){
				      for(int k=0;k<4;k++){
					gradTry[i][j]+=dLdX[k][j]*eulerElemTry[3*k+i];
				      }
				    }
				  }
				  for(int i=0;i<3;i++)
				    for(int j=0;j<3;j++)
				      normTry+=gradTry[i][j]*gradTry[i][j];
				  if(normTry<normMin){
				    normMin=normTry;
				    for(int a=0;a<4;a++)
				      for(int b=0;b<3;b++)
					eulerElemFinal[3*a+b]=eulerElemTry[3*a+b];
				  }
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  for(int a=0;a<4;a++)
    for(int b=0;b<3;b++)
      eulerElem[3*a+b]=eulerElemFinal[3*a+b];
  
  /* indRef=0; */
  /* for(int k=0;k<4;k++){ */
  /*   if(!(k==indRef)){ */
  /*     double *euler=eulerElem+3*k; */
  /*     printf("euler %i :\n",k); */
  /*     printf("%g %g %g\n",euler[0],euler[1],euler[2]); */
  /*   } */
  /* } */
  /* if(fabs(normMin)>fabs(normInit)+1e-8){ */
  /*   printf("normInit : %g\n",normInit); */
  /*   printf("normFinal : %g\n",normMin); */
  /*   printf("Houston we have a pb\n"); */
  /*   /\* exit(0); *\/ */
  /* } */
  /* printf("-----------------********************--------------------\n"); */

  return HXT_STATUS_OK;
}

void getBuildingVectors(const double euler[3], double u[3], double v[3], double w[3], double uOrth[3], double vOrth[3], double wOrth[3], double uXY[3], double vXY[3], double wXY[3], double wPi2[3], double u1[3]){
  double psi=euler[0];
  double theta=euler[1];
  double phi=euler[2];
  double cPsi = cos(psi);
  double sPsi = sin(psi);
  double cTheta = cos(theta);
  double sTheta = sin(theta);
  double cPhi = cos(phi);
  double sPhi = sin(phi);
  
  u[0]=-sPhi*sPsi*cTheta+cPhi*cPsi; u[1]=sPhi*cPsi*cTheta+sPsi*cPhi; u[2]=sPhi*sTheta;
  v[0]=-sPhi*cPsi-sPsi*cPhi*cTheta; v[1]=-sPhi*sPsi+cPhi*cPsi*cTheta; v[2]=sTheta*cPhi;
  w[0]=sPsi*sTheta; w[1]=-sTheta*cPsi; w[2]=cTheta;

  uOrth[0]=-u[1]; uOrth[1]=u[0]; uOrth[2]=0.0;
  vOrth[0]=-v[1]; vOrth[1]=v[0]; vOrth[2]=0.0;
  wOrth[0]=-w[1]; wOrth[1]=w[0]; wOrth[2]=0.0;

  uXY[0]=u[0]; uXY[1]=u[1]; uXY[2]=0.0;
  vXY[0]=v[0]; vXY[1]=v[1]; vXY[2]=0.0;
  wXY[0]=w[0]; wXY[1]=w[1]; wXY[2]=0.0;

  wPi2[0]=sPsi*cTheta; wPi2[1]=-cPsi*cTheta; wPi2[2]=-sTheta;
  u1[0]=cPsi; u1[1]=sPsi; u1[2]=0.0;
  return;
}

double computeKnotchEnergy(const double dirG[9], const double eulerG[3], const double gradPsi[3], const double gradTheta[3], const double gradPhi[3]){ 
  const double *u = dirG;
  const double *v = dirG+3;
  const double *w = dirG+6;
  double theta = eulerG[1];
  double phi = eulerG[2];
  
  double valEner=0.0;
  double valW=0.0;
  for(int k=0;k<3;k++){
    valW+=(-cos(phi)*u[k]+sin(phi)*v[k])*gradTheta[k] - sin(theta)*(sin(phi)*u[k]+cos(phi)*v[k])*gradPsi[k];
  }

  double valV=0.0;
  for(int k=0;k<3;k++){
    valV+=cos(phi)*u[k]*gradTheta[k] + w[k]*gradPhi[k] + (cos(theta)*w[k] + sin(theta)*sin(phi)*u[k])*gradPsi[k];
  }

  double valU=0.0;
  for(int k=0;k<3;k++){
    valU+=sin(phi)*v[k]*gradTheta[k] - w[k]*gradPhi[k] - (cos(theta)*w[k] + sin(theta)*cos(phi)*v[k])*gradPsi[k];
  }

  valEner=valW*valW+valV*valV+valU*valU;
  return valEner;
}

static inline void getIntegrabilityCostFctRoot(const double dirG[9], const double eulerG[3], const double gradPsi[3], const double gradTheta[3], const double gradPhi[3], double L[3]){
  const double *u = dirG;
  const double *v = dirG+3;
  const double *w = dirG+6;
  double theta = eulerG[1];
  double phi = eulerG[2];
  
  double valW=0.0;
  for(int k=0;k<3;k++){
    valW+=(-cos(phi)*u[k]+sin(phi)*v[k])*gradTheta[k] - sin(theta)*(sin(phi)*u[k]+cos(phi)*v[k])*gradPsi[k];
  }

  double valV=0.0;
  for(int k=0;k<3;k++){
    valV+=cos(phi)*u[k]*gradTheta[k] + w[k]*gradPhi[k] + (cos(theta)*w[k] + sin(theta)*sin(phi)*u[k])*gradPsi[k];
  }

  double valU=0.0;
  for(int k=0;k<3;k++){
    valU+=sin(phi)*v[k]*gradTheta[k] - w[k]*gradPhi[k] - (cos(theta)*w[k] + sin(theta)*cos(phi)*v[k])*gradPsi[k];
  }
  L[0]=valW;
  L[1]=valV;
  L[2]=valU;
  return;
}

static inline void getConstScalCostFctRoot(const double eulerG[3], const double gradPsi[3], const double gradTheta[3], const double gradPhi[3], double L[3][3]){
  // fctID, dimV
  /* Le[3][3];   */
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
  /* double theta = eulerG[1]; */
  double phi = eulerG[2];
  double cPhi=cos(phi);
  double sPhi=sin(phi);
  
  double LeW[3]={0.0};
  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      LeW[i]+=(w[i]*(sPhi*v[k]-cPhi*u[k]))*gradTheta[k] + (u[i]*u[k]+v[i]*v[k])*gradPhi[k] + (uOrth[i]*v[k]-vOrth[i]*u[k])*gradPsi[k];
    }
  }
    
  double LeV[3]={0.0};
  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      LeV[i]+=(sPhi*w[i]*w[k]-wPi2[i]*u[k])*gradTheta[k] + (v[i]*w[k])*gradPhi[k] + (uOrth[i]*w[k]-wOrth[i]*u[k])*gradPsi[k];
    }
  }
  double LeU[3]={0.0};
  for(int i=0;i<3;i++){
    for(int k=0;k<3;k++){
      LeU[i]+=(cPhi*w[i]*w[k]-wPi2[i]*v[k])*gradTheta[k] + (-u[i]*w[k])*gradPhi[k] + (vOrth[i]*w[k]-wOrth[i]*v[k])*gradPsi[k];
    }
  }

  for(int i=0;i<3;i++){
    L[0][i]=LeW[i];
    L[1][i]=LeV[i];
    L[2][i]=LeU[i];
  }
  return;
}

HXTStatus computeMeshEnergyKnotch(HXTMesh *mesh, const double *directions, double *energyKnotchPerTet){
  int nVert = mesh->vertices.num;
  int nTet = mesh->tetrahedra.num;

  double *minusGrad;
  HXT_CHECK(hxtMalloc(&minusGrad, 9*nVert*sizeof(double)));
  for(int i=0;i<9*nVert;i++)
    minusGrad[i]=0.0;
  
  for(int ieT=0;ieT<nTet;ieT++){
    // printf("--- elem %i / %i\n",ieT,nTet);
    uint32_t *tet = mesh->tetrahedra.node+ieT*4;
    //Frames at tet nodes
    double framesElem[9*4]={0.0};
    for(int k=0;k<4;k++){
      for(int l=0;l<9;l++){
	framesElem[9*k+l]=directions[9*tet[k]+l];
      }
    }
    //Computing derivation operator
    double x[4][3]={{0.0}};
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 3; j++)
	x[i][j] = mesh->vertices.coord[4*tet[i]+j];

    double dxdxi[3][3];
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
	dxdxi[j][i] = x[i+1][j] - x[0][j];
    double dxidx[3][3];
    double detj;
    HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
    detj=fabs(detj);
    const double dLdX[4][3] = {
      {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
      {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
      {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
      {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
    };
    double wG = 1./6.;

    //Evaluate energy value
    double dirG[9]={0.0};
    double eulerElem[4*3]={0.0};
    double eulerG[3]={0.0};
    double gradPsi[3]={0.0};
    double gradTheta[3]={0.0};
    double gradPhi[3]={0.0};
    hxtOr3DframesToEulerDataTet(framesElem, dLdX, eulerElem, gradPsi, gradTheta, gradPhi);
    for (int i = 0; i < 3; i++)
      for (int k = 0; k < 4; k++)
	eulerG[i]+=0.25*eulerElem[3*k+i];
    hxtOr3DeulerToBasis(eulerG, dirG);
    double energyRef = computeKnotchEnergy(dirG,eulerG,gradPsi,gradTheta,gradPhi)*detj*wG;
    /* energyKnotchPerTet[ieT]=energyRef/(detj*wG); */
    energyKnotchPerTet[ieT]=sqrt(energyRef/(detj*wG));
    /* energyKnotchPerTet[ieT]=energyRef; */
  }
  
  HXT_CHECK(hxtFree(&minusGrad));
  return HXT_STATUS_OK;
}

HXTStatus getConstScalGradOp(double *eulerG, const double *gradPsi, const double *gradTheta, const double *gradPhi, double LdEuler[3][3][3], double LDEuler[3][3][3][3]){
  //Ldeuler
  //fctID, dimV, euler
  //LDeuler
  //fctID, dimV, euler, dimX
  double theta = eulerG[1];
  double phi = eulerG[2];  
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
  double cTheta = cos(theta);
  /* double sTheta = sin(theta); */
  double cPhi = cos(phi);
  double sPhi = sin(phi);
  //Init
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++){
	LdEuler[i][j][k]=0.0;
	for(int l=0;l<3;l++)
	  LDEuler[i][j][k][l]=0.0;;
      }
  //eq1: ind 0
  // //Psi
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[0][iV][0]+=(wOrth[iV]*(sPhi*v[k]-cPhi*u[k])+w[iV]*(sPhi*vOrth[k]-cPhi*uOrth[k]))*gradTheta[k] + (uOrth[iV]*u[k]+u[iV]*uOrth[k]+vOrth[iV]*v[k]+v[iV]*vOrth[k])*gradPhi[k] + (-uXY[iV]*v[k]+uOrth[iV]*vOrth[k]+vXY[iV]*u[k]-vOrth[iV]*uOrth[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[0][iV][0][jX]+=uOrth[iV]*v[jX]-vOrth[iV]*u[jX];
  // //Theta
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[0][iV][1]+=(wPi2[iV]*(sPhi*v[k]-cPhi*u[k]))*gradTheta[k] + (sPhi*(w[iV]*u[k]+u[iV]*w[k])+cPhi*(w[iV]*v[k]+v[iV]*w[k]))*gradPhi[k] + (sPhi*(wOrth[iV]*v[k]-vOrth[iV]*w[k])+cPhi*(uOrth[iV]*w[k]-wOrth[iV]*u[k]))*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[0][iV][1][jX]+=w[iV]*(sPhi*v[jX]-cPhi*u[jX]);
  // //Phi
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[0][iV][2]+=0.0;
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
  LDEuler[0][iV][2][jX]+=u[iV]*u[jX]+v[iV]*v[jX];
  //eq2: ind 1
  // //Psi
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[1][iV][0]+=(sPhi*(wOrth[iV]*w[k]+w[iV]*wOrth[k])-cTheta*u1[iV]*u[k]-wPi2[iV]*uOrth[k])*gradTheta[k] + (vOrth[iV]*w[k]+v[iV]*wOrth[k])*gradPhi[k] + (-uXY[iV]*w[k]+uOrth[iV]*wOrth[k]+wXY[iV]*u[k]-wOrth[iV]*uOrth[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[1][iV][0][jX]+=uOrth[iV]*w[jX]-wOrth[iV]*u[jX];
  // //Theta
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[1][iV][1]+=(sPhi*w[iV]*wPi2[k]+w[iV]*u[k])*gradTheta[k] + (cPhi*w[iV]*w[k]+v[iV]*wPi2[k])*gradPhi[k] + (uOrth[iV]*wPi2[k]-cTheta*u1[iV]*u[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[1][iV][1][jX]+=sPhi*w[iV]*w[jX]-wPi2[iV]*u[jX];
  // //Phi
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[1][iV][2]+=(cPhi*w[iV]*w[k]-wPi2[iV]*v[k])*gradTheta[k] + (-u[iV]*w[k])*gradPhi[k] + (vOrth[iV]*w[k]-wOrth[iV]*v[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[1][iV][2][jX]+=v[iV]*w[jX];
  //eq3: ind 2
  // //Psi
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[2][iV][0]+=(cPhi*(wOrth[iV]*w[k]+w[iV]*wOrth[k])-cTheta*u1[iV]*v[k]-wPi2[iV]*vOrth[k])*gradTheta[k] + (-uOrth[iV]*w[k]-u[iV]*wOrth[k])*gradPhi[k] + (-vXY[iV]*w[k]+vOrth[iV]*wOrth[k]+wXY[iV]*v[k]-wOrth[iV]*vOrth[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[2][iV][0][jX]+=vOrth[iV]*w[jX]-wOrth[iV]*v[jX];
  // //Theta
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[2][iV][1]+=(cPhi*w[iV]*wPi2[k]+w[iV]*v[k])*gradTheta[k] + (-sPhi*w[iV]*w[k]-u[iV]*wPi2[k])*gradPhi[k] + (vOrth[iV]*wPi2[k]-cTheta*u1[iV]*v[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[2][iV][1][jX]+=cPhi*w[iV]*w[jX]-wPi2[iV]*v[jX];
  // //Phi
  for(int iV=0;iV<3;iV++)
    for(int k=0;k<3;k++)
      LdEuler[2][iV][2]+=(-sPhi*w[iV]*w[k]+wPi2[iV]*u[k])*gradTheta[k] + (-v[iV]*w[k])*gradPhi[k] + (-uOrth[iV]*w[k]+wOrth[iV]*u[k])*gradPsi[k];
  for(int iV=0;iV<3;iV++)
    for(int jX=0;jX<3;jX++)
      LDEuler[2][iV][2][jX]+=-u[iV]*w[jX];
  
  return HXT_STATUS_OK;
}

HXTStatus getIntegrabilityGradOp(double *eulerG, double *gradPsi, double *gradTheta, double *gradPhi, double LdPsi[3], double LDPsi[3][3], double LdTheta[3], double LDTheta[3][3], double LdPhi[3], double LDPhi[3][3],double Lddeuler[3][3][3],double LdDeuler[3][3][3][3],double LDdeuler[3][3][3][3]){
  double theta = eulerG[1];
  double phi = eulerG[2];
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
  double cTheta = cos(theta);
  double sTheta = sin(theta);
  double cPhi = cos(phi);
  double sPhi = sin(phi);
  //eq1: ind 0
  LdPsi[0] = 0.0;
  LdTheta[0] = 0.0;
  LdPhi[0] = 0.0;
  LDPsi[0][0] = LDPsi[0][1] = LDPsi[0][2] = 0.0;
  LDTheta[0][0] = LDTheta[0][1] = LDTheta[0][2] = 0.0;
  LDPhi[0][0] = LDPhi[0][1] = LDPhi[0][2] = 0.0;
  for(int i=0;i<3;i++){
    LdPsi[0]+= - (cPhi*uOrth[i]-sPhi*vOrth[i])*gradTheta[i]
               - sTheta*(sPhi*uOrth[i]+cPhi*vOrth[i])*gradPsi[i];
    LdTheta[0]+= (-1.0*cTheta*(sPhi*u[i]+cPhi*v[i])-sTheta*w[i])*gradPsi[i];
    LdPhi[0]+=0.0;
    LDPsi[0][i]=-1.0*sTheta*(sPhi*u[i]+cPhi*v[i]);
    LDTheta[0][i]=-(cPhi*u[i]-sPhi*v[i]);
    LDPhi[0][i]=0.0;
  }
  //eq2: ind 1
  LdPsi[1] = 0.0;
  LdTheta[1] = 0.0;
  LdPhi[1] = 0.0;
  LDPsi[1][0] = LDPsi[1][1] = LDPsi[1][2] = 0.0;
  LDTheta[1][0] = LDTheta[1][1] = LDTheta[1][2] = 0.0;
  LDPhi[1][0] = LDPhi[1][1] = LDPhi[1][2] = 0.0;
  for(int i=0;i<3;i++){
    LdPsi[1]+=cPhi*uOrth[i]*gradTheta[i]+wOrth[i]*gradPhi[i]+(cTheta*wOrth[i]+sPhi*sTheta*uOrth[i])*gradPsi[i];
    LdTheta[1]+=cPhi*sPhi*w[i]*gradTheta[i]+wPi2[i]*gradPhi[i]+(-sTheta*cPhi*cPhi*w[i]+cTheta*wPi2[i]+cTheta*sPhi*u[i])*gradPsi[i];
    LdPhi[1]+=(-sPhi*u[i]+cPhi*v[i])*gradTheta[i] + sTheta*(cPhi*u[i]+sPhi*v[i])*gradPsi[i];
    LDPsi[1][i]=cTheta*w[i]+sPhi*sTheta*u[i];
    /* LDTheta[1][i]=cTheta*u[i]; */
    LDTheta[1][i]=cPhi*u[i];
    LDPhi[1][i]=w[i];
  }
  //eq3: ind 2
  LdPsi[2] = 0.0;
  LdTheta[2] = 0.0;
  LdPhi[2] = 0.0;
  LDPsi[2][0] = LDPsi[2][1] = LDPsi[2][2] = 0.0;
  LDTheta[2][0] = LDTheta[2][1] = LDTheta[2][2] = 0.0;
  LDPhi[2][0] = LDPhi[2][1] = LDPhi[2][2] = 0.0;
  for(int i=0;i<3;i++){
    LdPsi[2]+=sPhi*vOrth[i]*gradTheta[i]-wOrth[i]*gradPhi[i]+(-cTheta*wOrth[i]-sTheta*cPhi*vOrth[i])*gradPsi[i];
    LdTheta[2]+=sPhi*cPhi*w[i]*gradTheta[i]-wPi2[i]*gradPhi[i]+(sTheta*sPhi*sPhi*w[i]-cTheta*wPi2[i]-cTheta*cPhi*v[i])*gradPsi[i];
    LdPhi[2]+=(cPhi*v[i]-sPhi*u[i])*gradTheta[i]+sTheta*(cPhi*u[i]+sPhi*v[i])*gradPsi[i];
    LDPsi[2][i]=-cTheta*w[i]-sTheta*cPhi*v[i];
    LDTheta[2][i]=sPhi*v[i];
    LDPhi[2][i]=-w[i];
  }

  //Lddeuler
  //fctID, eulerTilde, euler
  //LdDeuler
  //fctID, eulerTilde, euler, dim
  //LDdeuler
  //fctID, eulerTilde, euler, dim
  
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
	Lddeuler[i][j][k]=0.0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
	for(int l=0;l<3;l++){
	  LdDeuler[i][j][k][l]=0.0;
	  LDdeuler[i][j][k][l]=0.0;
	}
  //psiTilde, psi
  for(int i=0;i<3;i++)
    Lddeuler[0][0][0]+=-(-cPhi*uXY[i]+sPhi*vXY[i])*gradTheta[i]+sTheta*(sPhi*uXY[i]+cPhi*vXY[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[0][0][0][i]=-sTheta*(sPhi*uOrth[i]+cPhi*vOrth[i]);
    LDdeuler[0][0][0][i]=-sTheta*(sPhi*uOrth[i]+cPhi*vOrth[i]);
  }
  for(int i=0;i<3;i++)
    Lddeuler[1][0][0]+=-cPhi*uXY[i]*gradTheta[i]-wXY[i]*gradPhi[i]-(cTheta*wXY[i]+sPhi*sTheta*uXY[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[1][0][0][i]=cTheta*wOrth[i]+sPhi*sTheta*uOrth[i];
    LDdeuler[1][0][0][i]=cTheta*wOrth[i]+sPhi*sTheta*uOrth[i];
  }
  for(int i=0;i<3;i++)
    Lddeuler[2][0][0]+=-sPhi*vXY[i]*gradTheta[i]+wXY[i]*gradPhi[i]+(cTheta*wXY[i]+sTheta*cPhi*vXY[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[2][0][0][i]=-cTheta*wOrth[i]-sTheta*cPhi*vOrth[i];
    LDdeuler[2][0][0][i]=-cTheta*wOrth[i]-sTheta*cPhi*vOrth[i];
  }
  //psiTilde, theta
  for(int i=0;i<3;i++)
    Lddeuler[0][0][1]+=(-cTheta*(sPhi*uOrth[i]+cPhi*vOrth[i])-sTheta*wOrth[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[0][0][1][i]=-(cPhi*uOrth[i]-sPhi*vOrth[i]);
    LDdeuler[0][0][1][i]=-cTheta*(sPhi*u[i]+cPhi*v[i])-sTheta*w[i];
  }
  for(int i=0;i<3;i++)
    Lddeuler[1][0][1]+=cPhi*sPhi*wOrth[i]*gradTheta[i]+cTheta*u1[i]*gradPhi[i]+(-cPhi*cPhi*sTheta*wOrth[i]+cTheta*cTheta*u1[i]+sPhi*cTheta*uOrth[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[1][0][1][i]=cPhi*uOrth[i];
    LDdeuler[1][0][1][i]=-sTheta*cPhi*cPhi*w[i]+cTheta*wPi2[i]+sPhi*cTheta*u[i];
  }
  for(int i=0;i<3;i++)
    Lddeuler[2][0][1]+=sPhi*cPhi*wOrth[i]*gradTheta[i]-cTheta*u1[i]*gradPhi[i]+(sTheta*sPhi*sPhi*wOrth[i]-cTheta*cTheta*u1[i]-cTheta*cPhi*vOrth[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[2][0][1][i]=sPhi*vOrth[i];
    LDdeuler[2][0][1][i]=sTheta*sPhi*sPhi*w[i]-cTheta*wPi2[i]-cTheta*cPhi*v[i];
  }
  //psiTilde, phi
  Lddeuler[0][0][2]=0.0;
  for(int i=0;i<3;i++){
    LdDeuler[0][0][2][i]=0.0;
    LDdeuler[0][0][2][i]=0.0;
  }
  for(int i=0;i<3;i++)
    Lddeuler[1][0][2]+=(-sPhi*uOrth[i]+cPhi*vOrth[i])*gradTheta[i]+sTheta*(cPhi*uOrth[i]+sPhi*vOrth[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[1][0][2][i]=wOrth[i];
    LDdeuler[1][0][2][i]=sTheta*(cPhi*u[i]+sPhi*v[i]);
  }
  for(int i=0;i<3;i++)
    Lddeuler[2][0][2]+=(cPhi*vOrth[i]-sPhi*uOrth[i])*gradTheta[i]+sTheta*(cPhi*uOrth[i]+sPhi*vOrth[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[2][0][2][i]=-wOrth[i];
    LDdeuler[2][0][2][i]=sTheta*(cPhi*u[i]+sPhi*v[i]);
  }
  //thetaTilde, phi
  Lddeuler[0][1][2]=0.0;
  for(int i=0;i<3;i++){
    LdDeuler[0][1][2][i]=0.0;
    LDdeuler[0][1][2][i]=0.0;
  }
  for(int i=0;i<3;i++)
    Lddeuler[1][1][2]+=cos(2*phi)*w[i]*gradTheta[i]+(sTheta*sin(2*phi)*w[i]+cTheta*cPhi*u[i]+cTheta*sPhi*v[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[1][1][2][i]=wPi2[i];
    /* LDdeuler[1][1][2][i]=cTheta*v[i]; */
    LDdeuler[1][1][2][i]=-sPhi*u[i]+cPhi*v[i];
  }
  for(int i=0;i<3;i++)
    Lddeuler[2][1][2]+=cos(2*phi)*w[i]*gradTheta[i]+(sTheta*sin(2*phi)*w[i]+cTheta*cPhi*u[i]+cTheta*sPhi*v[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[2][1][2][i]=-wPi2[i];
    LDdeuler[2][1][2][i]=cPhi*v[i]-sPhi*u[i];
  }
  //thetaTilde, theta
  for(int i=0;i<3;i++)
    Lddeuler[0][1][1]=-2*(sTheta*wPi2[i]+cTheta*w[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[0][1][1][i]=0.0;
    LDdeuler[0][1][1][i]=0.0;
  }
  for(int i=0;i<3;i++)
    Lddeuler[1][1][1]+=cPhi*sPhi*wPi2[i]*gradTheta[i]-w[i]*gradPhi[i]+(-2*cTheta*cPhi*cPhi*w[i]-sTheta*(1+cPhi*cPhi)*wPi2[i]-sTheta*sPhi*u[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[1][1][1][i]=cPhi*sPhi*w[i];
    /* LDdeuler[1][1][1][i]=-sTheta*u[i]+cTheta*sPhi*w[i]; */
    LDdeuler[1][1][1][i]=cPhi*sPhi*w[i];
  }
  for(int i=0;i<3;i++)
    Lddeuler[2][1][1]+=sPhi*cPhi*wPi2[i]*gradTheta[i]+w[i]*gradPhi[i]+(2*cTheta*sPhi*sPhi*w[i]+sTheta*(1+sPhi*sPhi)*wPi2[i]+sTheta*cPhi*v[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[2][1][1][i]=sPhi*cPhi*w[i];
    LDdeuler[2][1][1][i]=sPhi*cPhi*w[i];
  }
  //phiTilde, phi
  Lddeuler[0][2][2]=0.0;
  for(int i=0;i<3;i++){
    LdDeuler[0][2][2][i]=0.0;
    LDdeuler[0][2][2][i]=0.0;
  }
  for(int i=0;i<3;i++)
    Lddeuler[1][2][2]+=-2*(cPhi*u[i]+sPhi*v[i])*gradTheta[i]+2*sTheta*(-sPhi*u[i]+cPhi*v[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[1][2][2][i]=0.0;
    LDdeuler[1][2][2][i]=0.0;
  }
  for(int i=0;i<3;i++)
    Lddeuler[2][2][2]+=-2*(cPhi*u[i]+sPhi*v[i])*gradTheta[i]+2*sTheta*(-sPhi*u[i]+cPhi*v[i])*gradPsi[i];
  for(int i=0;i<3;i++){
    LdDeuler[2][2][2][i]=0.0;
    LDdeuler[2][2][2][i]=0.0;
  }
  //Dealing with symmetries
  for(int k=0;k<3;k++)
    for(int i=0;i<3;i++)
      for(int j=i+1;j<3;j++)
	Lddeuler[k][j][i]=Lddeuler[k][i][j];
  for(int k=0;k<3;k++)
    for(int i=0;i<3;i++)
      for(int j=i+1;j<3;j++)
	for(int l=0;l<3;l++){
	  LdDeuler[k][j][i][l]=LDdeuler[k][i][j][l];
	  LDdeuler[k][j][i][l]=LdDeuler[k][i][j][l];
	}
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpIntegrabilityB(HXTMesh *mesh, uint32_t *tetNodes, double framesElem[9*4], double epsilon, double grad[9*4], double Hess[9*4*9*4]){
  /* epsilon=sqrt(epsilon); */
  epsilon=1.0;
  //convert framesElem to eulerElem
  for(int j=0;j<9*4;j++)
    grad[j]=0.0;
  if(Hess!=NULL)
    for(int j=0;j<9*4;j++)
      for(int k=0;k<9*4;k++)
	Hess[j*9*4+k]=0.0;
  //Computing derivation operator
  double x[4][3]={{0.0}};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      x[i][j] = mesh->vertices.coord[4*tetNodes[i]+j];

  double dxdxi[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      dxdxi[j][i] = x[i+1][j] - x[0][j];
  double dxidx[3][3];
  double detj;
  HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
  detj=fabs(detj);
  const double dLdX[4][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  double wG = 1./6.;

  //Evaluate energy value
  double euler[3*4]={0.0};
  double dirG[9]={0.0};
  double eulerG[3]={0.0};
  double gradPsi[3]={0.0};
  double gradTheta[3]={0.0};
  double gradPhi[3]={0.0};
  hxtOr3DframesToEulerDataTet(framesElem, dLdX, euler, gradPsi, gradTheta, gradPhi);
  for (int i = 0; i < 3; i++)
    for (int k = 0; k < 4; k++)
      eulerG[i]+=euler[3*k+i];
  hxtOr3DeulerToBasis(eulerG, dirG);

  //compute dBdEuler pseudo inverse and its grad
  //dEulerdB computed at gauss point
  double dBdEulerG[9][3]={{0.0}};
  hxtOr3DdBdEuler(eulerG, dBdEulerG);
  double dEulerdBG[3][9]={{0.0}};
  hxtOr3DpseudoInv9x3(dBdEulerG, dEulerdBG);

  //Checking if pseudo inverse is ok
  double p1[9][3]={{0.0}};
  double p2[3][9]={{0.0}};
  double p3[9][9]={{0.0}};
  double p4[3][3]={{0.0}};

  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<3;k++)
	for(int l=0;l<9;l++)
	  p1[i][j]+=dBdEulerG[i][k]*dEulerdBG[k][l]*dBdEulerG[l][j];	  
  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++)
      p1[i][j]-=dBdEulerG[i][j];
  for(int i=0;i<3;i++)
    for(int j=0;j<9;j++)
      for(int k=0;k<9;k++)
	for(int l=0;l<3;l++)
	  p2[i][j]+=dEulerdBG[i][k]*dBdEulerG[k][l]*dEulerdBG[l][j];
  for(int i=0;i<3;i++)
    for(int j=0;j<9;j++)
      p2[i][j]-=dEulerdBG[i][j];
  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++)
      for(int k=0;k<9;k++)
	p3[i][k]+=dBdEulerG[i][j]*dEulerdBG[j][k];
  for(int i=0;i<9;i++)
    for(int j=i;j<9;j++){
      double temp=p3[i][j];
      p3[i][j]-=p3[j][i];
      if(i!=j)
	p3[j][i]-=temp;
    }
  for(int i=0;i<3;i++)
    for(int j=0;j<9;j++)
      for(int k=0;k<3;k++)
	p4[i][k]+=dEulerdBG[i][j]*dBdEulerG[j][k];
  for(int i=0;i<3;i++)
    for(int k=i;k<3;k++){
      double temp=p4[i][k];
      p4[i][k]-=p4[k][i];
      if(i!=k)
	p4[k][i]-=temp;
    }

  double valP1=0.0;
  double valP2=0.0;
  double valP3=0.0;
  double valP4=0.0;
  for(int i=0;i<9;i++)
    for(int j=0;j<3;j++){
      valP1+=p1[i][j]*p1[i][j];
      valP2+=p2[j][i]*p2[j][i];
    }
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++){
      valP3+=p3[i][j]*p3[i][j];
    }
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      valP4+=p4[i][j]*p4[i][j];
    }

  double tolPInv=1e-3;
  if(sqrt(valP1)>tolPInv||sqrt(valP2)>tolPInv||sqrt(valP3)>tolPInv||sqrt(valP4)>tolPInv){
    int baseVect[3];
    int rank=0;
    hxtOr3DgetRankMat9x3(dBdEulerG,baseVect,&rank);
    printf("pb with pseudo inverse\n");
    printf("rank : %i\n",rank);
    printf("dBdEuler\n");
    for(int i=0;i<9;i++)
      printf("%g // %g // %g\n",dBdEulerG[i][0],dBdEulerG[i][1],dBdEulerG[i][2]);
    printf("---------------\n");
    printf("dEulerdB\n");
    for(int i=0;i<3;i++)
      printf("%g // %g // %g // %g // %g // %g // %g // %g // %g\n",dEulerdBG[i][0],dEulerdBG[i][1],dEulerdBG[i][2],dEulerdBG[i][3],dEulerdBG[i][4],dEulerdBG[i][5],dEulerdBG[i][6],dEulerdBG[i][7],dEulerdBG[i][8]);
    printf("values chec pInv\n");
    printf("first  : %g // %g // %g // %g\n",sqrt(valP1),sqrt(valP2),sqrt(valP3),sqrt(valP4));
    exit(0);
  }
  //
    
  //dEulerdB computed at elem nodes to compute its grad
  //node, euler, b
  double dEulerdBElem[4][3][9]={{{0.0}}};
  for(int iN=0;iN<4;iN++){
    double eulerNode[3]={euler[3*iN+0],euler[3*iN+1],euler[3*iN+2]};
    double dBdEulerN[9][3]={{0.0}};
    hxtOr3DdBdEuler(eulerNode, dBdEulerN);
    double dEulerdBN[3][9]={{0.0}};
    hxtOr3DpseudoInv9x3(dBdEulerN, dEulerdBN);
    for(int i=0;i<3;i++)
      for(int j=0;j<9;j++)
	dEulerdBElem[iN][i][j]=dEulerdBN[i][j];
  }
  double gradXdEulerdB[3][9][3]={{{0.0}}}; //euler, B, X
  //ICI
  for(int iX=0;iX<3;iX++)
    for(int kN=0;kN<4;kN++)
      for(int jEul=0;jEul<3;jEul++)
	for(int lB=0;lB<9;lB++)
	  gradXdEulerdB[jEul][lB][iX]+=dLdX[kN][iX]*dEulerdBElem[kN][jEul][lB];
  
  //compute integrability operators (euler)
  // fctID
  double Le[3]={0.0};
  double LdPsi[3]={0.0};
  double LdTheta[3]={0.0};
  double LdPhi[3]={0.0};
  // fctID,dim
  double LDPsi[3][3]={{0.0}};
  double LDTheta[3][3]={{0.0}};
  double LDPhi[3][3]={{0.0}};
  // fctID, eulerTilde, euler
  double Lddeuler[3][3][3]={{{0.0}}};
  // fctID, eulerTilde, euler, dim
  double LdDeuler[3][3][3][3]={{{{0.0}}}};
  double LDdeuler[3][3][3][3]={{{{0.0}}}};
  
  getIntegrabilityCostFctRoot(dirG, eulerG, gradPsi, gradTheta, gradPhi, Le);
  getIntegrabilityGradOp(eulerG,gradPsi,gradTheta,gradPhi,LdPsi,LDPsi,LdTheta,LDTheta,LdPhi,LDPhi,Lddeuler,LdDeuler,LDdeuler); //ICI: To check!!

  //compute integrability operators (b)
  double LdB[3][9]={{0.0}}; //eq (3) , bi (9)
  double LDB[3][3][9]={{{0.0}}}; //eq (3) , X (3), bi (9)
  
  for(int iEq=0;iEq<3;iEq++)
    for(int jB=0;jB<9;jB++)
      LdB[iEq][jB]+= dEulerdBG[0][jB]*LdPsi[iEq] + dEulerdBG[1][jB]*LdTheta[iEq] + dEulerdBG[2][jB]*LdPhi[iEq];
  
  for(int iEq=0;iEq<3;iEq++)
    for(int jB=0;jB<9;jB++)
      for(int kX=0;kX<3;kX++){
	LDB[iEq][kX][jB]+=dEulerdBG[0][jB]*LDPsi[iEq][kX] + dEulerdBG[1][jB]*LDTheta[iEq][kX] + dEulerdBG[2][jB]*LDPhi[iEq][kX];
	LdB[iEq][jB]+=gradXdEulerdB[0][jB][kX]*LDPsi[iEq][kX] + gradXdEulerdB[1][jB][kX]*LDTheta[iEq][kX] + gradXdEulerdB[2][jB][kX]*LDPhi[iEq][kX];
      }
  
  //assembling localRhs and hess
  double L[4]={1./4.,1./4.,1./4.,1./4.};
  for(int j=0;j<9*4;j++)
    grad[j]=0.0;

  //Rhs
  for(int jB=0;jB<9;jB++)
    for(int kN=0;kN<4;kN++){
      grad[jB*4+kN] += L[kN]*(LdB[0][jB]*Le[0]+LdB[1][jB]*Le[1]+LdB[2][jB]*Le[2])*detj*wG*(1./epsilon) ;
      for(int lX=0;lX<3;lX++)
	grad[jB*4+kN] += dLdX[kN][lX]*(LDB[0][lX][jB]*Le[0]+LDB[1][lX][jB]*Le[1]+LDB[2][lX][jB]*Le[2])*detj*wG*(1./epsilon);
    }

  if(Hess!=NULL){
    //Hess
    //Prepare op
    //fctID, euler
    double Ldeuler[3][3]={{0.0}};
    for(int iF=0;iF<3;iF++){
      Ldeuler[iF][0]=LdPsi[iF];
      Ldeuler[iF][1]=LdTheta[iF];
      Ldeuler[iF][2]=LdPhi[iF];
    }
    //fctID, euler, dim
    double LDeuler[3][3][3]={{{0.0}}};
    for(int iF=0;iF<3;iF++){
      for(int jX=0;jX<3;jX++){
	LDeuler[iF][0][jX]=LDPsi[iF][jX];
	LDeuler[iF][1][jX]=LDTheta[iF][jX];
	LDeuler[iF][2][jX]=LDPhi[iF][jX];
      }
    }
    //alphaTilde, beta
    double fullLddEuler[3][3]={{0.0}};
    for(int iTilde=0;iTilde<3;iTilde++)
      for(int j=0;j<3;j++)
	for(int kEq=0;kEq<3;kEq++)
	  fullLddEuler[iTilde][j]+=Lddeuler[kEq][iTilde][j]*Le[kEq]+Ldeuler[kEq][iTilde]*Ldeuler[kEq][j];
    //alphaTilde, beta, dim
    double fullLdDEuler[3][3][3]={{{0.0}}};
    for(int iTilde=0;iTilde<3;iTilde++)
      for(int j=0;j<3;j++)
	for(int kEq=0;kEq<3;kEq++)
	  for(int lX=0;lX<3;lX++)
	    fullLdDEuler[iTilde][j][lX]+=LdDeuler[kEq][iTilde][j][lX]*Le[kEq]+Ldeuler[kEq][iTilde]*LDeuler[kEq][j][lX];
    //alphaTilde, beta, dimTilde
    double fullLDdEuler[3][3][3]={{{0.0}}};
    for(int iTilde=0;iTilde<3;iTilde++)
      for(int j=0;j<3;j++)
	for(int kEq=0;kEq<3;kEq++)
	  for(int lX=0;lX<3;lX++)
	    fullLDdEuler[iTilde][j][lX]+=LDdeuler[kEq][iTilde][j][lX]*Le[kEq]+LDeuler[kEq][iTilde][lX]*Ldeuler[kEq][j];
    //alphaTilde, beta, dimTilde, dim
    double fullLDDEuler[3][3][3][3]={{{{0.0}}}};
    for(int iTilde=0;iTilde<3;iTilde++)
      for(int j=0;j<3;j++)
	for(int kEq=0;kEq<3;kEq++)
	  for(int lXTilde=0;lXTilde<3;lXTilde++)
	    for(int mX=0;mX<3;mX++)
	      fullLDDEuler[iTilde][j][lXTilde][mX]+=LDeuler[kEq][iTilde][lXTilde]*LDeuler[kEq][j][mX];

    //convert op from euler to B
    //aTilde, b
    double fullLddB[9][9]={{0.0}};
    //aTilde, b, dim
    double fullLdDB[9][9][3]={{{0.0}}};
    //aTilde, b, dimTilde
    double fullLDdB[9][9][3]={{{0.0}}};
    //aTilde, b, dimTilde, dim
    double fullLDDB[9][9][3][3]={{{{0.0}}}};
    //
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    fullLddB[aTilde][b]+=dEulerdBG[iTilde][aTilde]*fullLddEuler[iTilde][j]*dEulerdBG[j][b];
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int lX=0;lX<3;lX++)
	      fullLddB[aTilde][b]+=dEulerdBG[iTilde][aTilde]*fullLdDEuler[iTilde][j][lX]*gradXdEulerdB[j][b][lX];
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int mXTilde=0;mXTilde<3;mXTilde++)
	      fullLddB[aTilde][b]+=gradXdEulerdB[iTilde][aTilde][mXTilde]*fullLDdEuler[iTilde][j][mXTilde]*dEulerdBG[j][b];
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int lX=0;lX<3;lX++)
	      for(int mXTilde=0;mXTilde<3;mXTilde++)
		fullLddB[aTilde][b]+=gradXdEulerdB[iTilde][aTilde][mXTilde]*fullLDDEuler[iTilde][j][mXTilde][lX]*gradXdEulerdB[j][b][lX];
    //
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int lX=0;lX<3;lX++)
	      fullLdDB[aTilde][b][lX]+=dEulerdBG[iTilde][aTilde]*fullLdDEuler[iTilde][j][lX]*dEulerdBG[j][b] ;
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int lX=0;lX<3;lX++)
	      for(int mXTilde=0;mXTilde<3;mXTilde++)
		fullLdDB[aTilde][b][lX]+=gradXdEulerdB[iTilde][aTilde][mXTilde]*fullLDDEuler[iTilde][j][mXTilde][lX]*dEulerdBG[j][b];
    //
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int mXTilde=0;mXTilde<3;mXTilde++)
	      fullLDdB[aTilde][b][mXTilde]+=dEulerdBG[iTilde][aTilde]*fullLDdEuler[iTilde][j][mXTilde]*dEulerdBG[j][b] ;
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int mXTilde=0;mXTilde<3;mXTilde++)
	      for(int lX=0;lX<3;lX++)
		fullLDdB[aTilde][b][mXTilde]+=dEulerdBG[iTilde][aTilde]*fullLDDEuler[iTilde][j][mXTilde][lX]*gradXdEulerdB[j][b][lX] ;
    //
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int iTilde=0;iTilde<3;iTilde++)
	  for(int j=0;j<3;j++)
	    for(int mXTilde=0;mXTilde<3;mXTilde++)
	      for(int lX=0;lX<3;lX++)
		fullLDDB[aTilde][b][mXTilde][lX]+=dEulerdBG[iTilde][aTilde]*fullLDDEuler[iTilde][j][mXTilde][lX]*dEulerdBG[j][b];

    //Building local Hessian matrix
    for(int j=0;j<9*4;j++)
      for(int k=0;k<9*4;k++)
	Hess[j*9*4+k]=0.0;

    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int kTilde=0;kTilde<4;kTilde++)
	  for(int l=0;l<4;l++)
	    Hess[(aTilde*4+kTilde)*36+b*4+l] += L[kTilde]*fullLddB[aTilde][b]*L[l]*(1/epsilon)*detj*wG;

    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int kTilde=0;kTilde<4;kTilde++)
	  for(int l=0;l<4;l++)
	    for(int nX=0;nX<3;nX++)
	      Hess[(aTilde*4+kTilde)*36+b*4+l] += L[kTilde]*fullLdDB[aTilde][b][nX]*dLdX[l][nX]*(1/epsilon)*detj*wG;
    
    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int kTilde=0;kTilde<4;kTilde++)
	  for(int l=0;l<4;l++)
	    for(int mXTilde=0;mXTilde<3;mXTilde++)
	      Hess[(aTilde*4+kTilde)*36+b*4+l] += dLdX[kTilde][mXTilde]*fullLDdB[aTilde][b][mXTilde]*L[l]*(1/epsilon)*detj*wG;

    for(int aTilde=0;aTilde<9;aTilde++)
      for(int b=0;b<9;b++)
	for(int kTilde=0;kTilde<4;kTilde++)
	  for(int l=0;l<4;l++)
	    for(int mXTilde=0;mXTilde<3;mXTilde++)
	      for(int nX=0;nX<3;nX++)
		Hess[(aTilde*4+kTilde)*36+b*4+l] += dLdX[kTilde][mXTilde]*fullLDDB[aTilde][b][mXTilde][nX]*dLdX[l][nX]*(1/epsilon)*detj*wG;
  }

  return HXT_STATUS_OK;
}

HXTStatus getGradFDEulerInt(HXTMesh *mesh, uint32_t *tetNodes, double framesElem[9*4], double grad[3*4]){ // dbg fct
  double x[4][3]={{0.0}};
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      x[i][j] = mesh->vertices.coord[4*tetNodes[i]+j];

  double dxdxi[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      dxdxi[j][i] = x[i+1][j] - x[0][j];
  double dxidx[3][3];
  double detj;
  HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
  detj=fabs(detj);
  const double dLdX[4][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  double wG = 1./6.;

  //Evaluate energy value
  double euler[3*4]={0.0};
  double dirG[9]={0.0};
  double eulerG[3]={0.0};
  double gradPsi[3]={0.0};
  double gradTheta[3]={0.0};
  double gradPhi[3]={0.0};
  hxtOr3DframesToEulerDataTet(framesElem, dLdX, euler, gradPsi, gradTheta, gradPhi);
  for (int i = 0; i < 3; i++)
    for (int k = 0; k < 4; k++)
      eulerG[i]+=0.25*euler[3*k+i];
  hxtOr3DeulerToBasis(eulerG, dirG);
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
  double dirGTest[9]={u[0],u[1],u[2],v[0],v[1],v[2],w[0],w[1],w[2]};
  double Le[3]={0.0};  
  getIntegrabilityCostFctRoot(dirGTest, eulerG, gradPsi, gradTheta, gradPhi, Le);
  /* getIntegrabilityCostFctRoot(dirG, eulerG, gradPsi, gradTheta, gradPhi, Le); */
  
  double L[4]={1./4.,1./4.,1./4.,1./4.};
  for(int j=0;j<3*4;j++)
    grad[j]=0.0;
  //

  for(int iEul=0;iEul<3;iEul++){
    for(int kN=0;kN<4;kN++){
      double eulerDelta[3*4]={0.0};
      for(int l=0;l<4*3;l++)
	eulerDelta[l]=euler[l];
      double deltaVal=0.0;
      deltaVal=1e-10;
      /* if(fabs(eulerDelta[kN*3+iEul])<1e-8) */
      /* 	deltaVal=1e-8; */
      /* else */
      /* 	deltaVal=1e-8*fabs(eulerDelta[kN*3+iEul]); */

      /* printf("deltaval euler : %g\n",deltaVal); */
      /* printf("val euler : %g\n",eulerDelta[kN*3+iEul]); */
      eulerDelta[kN*3+iEul]+=deltaVal;
      /* double framesElemDelta[9*4]={0.0}; */
      /* for(int k=0;k<4;k++) */
      /* 	hxtOr3DeulerToFrame(framesElemDelta+9*k, eulerDelta+3*k); */
      double eulerGDelta[3]={eulerG[0],eulerG[1],eulerG[2]};
      eulerGDelta[iEul]+=0.25*deltaVal;

      double gradPsiDelta[3]={0.0};
      double gradThetaDelta[3]={0.0};
      double gradPhiDelta[3]={0.0};
      for (int j = 0; j < 3; ++j){
	for (int k = 0; k < 4; ++k){
	  gradPsiDelta[j]+=dLdX[k][j]*eulerDelta[3*k+0];
	  gradThetaDelta[j]+=dLdX[k][j]*eulerDelta[3*k+1];
	  gradPhiDelta[j]+=dLdX[k][j]*eulerDelta[3*k+2];
	}
      }

      /* double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3]; */
      getBuildingVectors(eulerGDelta,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      double dirGDelta[9]={u[0],u[1],u[2],v[0],v[1],v[2],w[0],w[1],w[2]};
      
      double LeDelta[3]={0.0};
      getIntegrabilityCostFctRoot(dirGDelta, eulerGDelta, gradPsiDelta, gradThetaDelta, gradPhiDelta, LeDelta);
      for(int iEq=0;iEq<3;iEq++)
      	/* grad[iEul*4+kN] += L[kN]*0.5*(LeDelta[iEq]*LeDelta[iEq]-Le[iEq]*Le[iEq])*detj*wG; */
      	grad[iEul*4+kN] += L[kN]*2*(LeDelta[iEq]*LeDelta[iEq]-Le[iEq]*Le[iEq])*detj*wG/deltaVal;
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus getGradConstScal(HXTMesh *mesh, uint32_t *tetNodes, double framesElem[9*4], double grad[3*4]){
  //convert framesElem to eulerElem
  int isTetSing=0;
  for (int i = 0; i < 4; i++){
    double qual=0.0;
    hxtOr3DcomputeQuality(framesElem+9*i, &qual);
    if(qual>10)
      isTetSing=1;
  }
  for(int j=0;j<3*4;j++)
    grad[j]=0.0;
  if(!isTetSing){
    //Computing derivation operator
    double x[4][3]={{0.0}};
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 3; j++)
	x[i][j] = mesh->vertices.coord[4*tetNodes[i]+j];

    double dxdxi[3][3];
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
	dxdxi[j][i] = x[i+1][j] - x[0][j];
    double dxidx[3][3];
    double detj;
    HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
    detj=fabs(detj);
    const double dLdX[4][3] = {
      {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
      {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
      {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
      {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
    };
    double wG = 1./6.;

    double euler[3*4]={0.0};
    double dirG[9]={0.0};
    double eulerG[3]={0.0};
    double gradPsi[3]={0.0};
    double gradTheta[3]={0.0};
    double gradPhi[3]={0.0};
    hxtOr3DframesToEulerDataTet(framesElem, dLdX, euler, gradPsi, gradTheta, gradPhi);
    for (int i = 0; i < 3; i++)
      for (int k = 0; k < 4; k++)
	eulerG[i]+=0.25*euler[3*k+i];
    hxtOr3DeulerToBasis(eulerG, dirG);
  
    //compute integrability operators (euler)
    // fctID, dimV
    double Le[3][3]={{0.0}};
    //fctID, dimV, euler
    double LdEuler[3][3][3]={{{0.0}}};
    //fctID, dimV, euler, dimX
    double LDEuler[3][3][3][3]={{{{0.0}}}};
    
    getConstScalCostFctRoot(eulerG, gradPsi, gradTheta, gradPhi, Le);
    getConstScalGradOp(eulerG, gradPsi, gradTheta, gradPhi, LdEuler, LDEuler);
  
    double L[4]={1./4.,1./4.,1./4.,1./4.};
    for(int j=0;j<3*4;j++)
      grad[j]=0.0;

    //Rhs
    for(int iEul=0;iEul<3;iEul++){
      for(int iEq=0;iEq<3;iEq++){
	for(int kN=0;kN<4;kN++){
	  for(int jV=0;jV<3;jV++){
	    grad[iEul*4+kN] += L[kN]*(LdEuler[iEq][jV][iEul]*Le[iEq][jV])*detj*wG;
	    for(int lX=0;lX<3;lX++){
	      grad[iEul*4+kN] += dLdX[kN][lX]*(LDEuler[iEq][jV][iEul][lX]*Le[iEq][jV])*detj*wG;
	    }
	  }
	}
      }
    }
    
    /* //Rhs */
    /* for(int iEq=0;iEq<3;iEq++){ */
    /*   for(int kN=0;kN<4;kN++){ */
    /* 	grad[0*4+kN] += L[kN]*(LdPsi[iEq]*Le[iEq])*detj*wG; */
    /* 	grad[1*4+kN] += L[kN]*(LdTheta[iEq]*Le[iEq])*detj*wG; */
    /* 	grad[2*4+kN] += L[kN]*(LdPhi[iEq]*Le[iEq])*detj*wG; */
    /* 	for(int lX=0;lX<3;lX++){ */
    /* 	  grad[0*4+kN] += dLdX[kN][lX]*(LDPsi[iEq][lX]*Le[iEq])*detj*wG; */
    /* 	  grad[1*4+kN] += dLdX[kN][lX]*(LDTheta[iEq][lX]*Le[iEq])*detj*wG; */
    /* 	  grad[2*4+kN] += dLdX[kN][lX]*(LDPhi[iEq][lX]*Le[iEq])*detj*wG; */
    /* 	} */
    /*   } */
    /* } */

  }
  return HXT_STATUS_OK;
}

HXTStatus getGradEulerInt(HXTMesh *mesh, uint32_t *tetNodes, double framesElem[9*4], double grad[3*4]){ //dbg fct
  //convert framesElem to eulerElem
  int isTetSing=0;
  for (int i = 0; i < 4; i++){
    double qual=0.0;
    hxtOr3DcomputeQuality(framesElem+9*i, &qual);
    if(qual>10)
      isTetSing=1;
  }
  for(int j=0;j<3*4;j++)
    grad[j]=0.0;
  if(!isTetSing){
    //Computing derivation operator
    double x[4][3]={{0.0}};
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 3; j++)
	x[i][j] = mesh->vertices.coord[4*tetNodes[i]+j];

    double dxdxi[3][3];
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
	dxdxi[j][i] = x[i+1][j] - x[0][j];
    double dxidx[3][3];
    double detj;
    HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
    detj=fabs(detj);
    const double dLdX[4][3] = {
      {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
      {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
      {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
      {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
    };
    double wG = 1./6.;

    //Evaluate energy value
    double euler[3*4]={0.0};
    double dirG[9]={0.0};
    double eulerG[3]={0.0};
    double gradPsi[3]={0.0};
    double gradTheta[3]={0.0};
    double gradPhi[3]={0.0};
    hxtOr3DframesToEulerDataTet(framesElem, dLdX, euler, gradPsi, gradTheta, gradPhi);
    for (int i = 0; i < 3; i++)
      for (int k = 0; k < 4; k++)
	eulerG[i]+=0.25*euler[3*k+i];
    hxtOr3DeulerToBasis(eulerG, dirG);
    /* //ICI */
    /* for (int j = 0; j < 3; ++j){ */
    /*   gradPsi[j]=0.0; */
    /*   gradTheta[j]=0.0; */
    /*   gradPhi[j]=0.0; */
    /* } */
    /* for (int j = 0; j < 3; ++j){ */
    /*   for (int k = 0; k < 4; ++k){ */
    /* 	gradPsi[j]+=dLdX[k][j]*euler[3*k+0]; */
    /* 	gradTheta[j]+=dLdX[k][j]*euler[3*k+1]; */
    /* 	gradPhi[j]+=dLdX[k][j]*euler[3*k+2]; */
    /*   } */
    /* } */
    /* double uu[3],vv[3],ww[3],uOrthu[3],vOrthv[3],wOrthw[3],uXYu[3],vXYv[3],wXYw[3],wPi2w[3],u1u[3]; */
    /* getBuildingVectors(eulerG,uu,vv,ww,uOrthu,vOrthv,wOrthw,uXYu,vXYv,wXYw,wPi2w,u1u); */
    /* for (int j = 0; j < 3; ++j){ */
    /*   dirG[j]=uu[j]; */
    /*   dirG[3+j]=vv[j]; */
    /*   dirG[6+j]=ww[j]; */
    /* } */

    /* //compute dBdEuler pseudo inverse and its grad */
    /* //dEulerdB computed at gauss point */
    /* double dBdEulerG[9][3]={{0.0}}; */
    /* hxtOr3DdBdEuler(eulerG, dBdEulerG); */
    /* double dEulerdBG[3][9]={{0.0}}; */
    /* pseudoInv9x3(dBdEulerG, dEulerdBG); */

    /* //Checking if pseudo inverse is ok */
    /* double p1[9][3]={{0.0}}; */
    /* double p2[3][9]={{0.0}}; */
    /* double p3[9][9]={{0.0}}; */
    /* double p4[3][3]={{0.0}}; */

    /* for(int i=0;i<9;i++) */
    /*   for(int j=0;j<3;j++) */
    /* 	for(int k=0;k<3;k++) */
    /* 	  for(int l=0;l<9;l++) */
    /* 	    p1[i][j]+=dBdEulerG[i][k]*dEulerdBG[k][l]*dBdEulerG[l][j];	   */
    /* for(int i=0;i<9;i++) */
    /*   for(int j=0;j<3;j++) */
    /* 	p1[i][j]-=dBdEulerG[i][j]; */
    /* for(int i=0;i<3;i++) */
    /*   for(int j=0;j<9;j++) */
    /* 	for(int k=0;k<9;k++) */
    /* 	  for(int l=0;l<3;l++) */
    /* 	    p2[i][j]+=dEulerdBG[i][k]*dBdEulerG[k][l]*dEulerdBG[l][j]; */
    /* for(int i=0;i<3;i++) */
    /*   for(int j=0;j<9;j++) */
    /* 	p2[i][j]-=dEulerdBG[i][j]; */
    /* for(int i=0;i<9;i++) */
    /*   for(int j=0;j<3;j++) */
    /* 	for(int k=0;k<9;k++) */
    /* 	  p3[i][k]+=dBdEulerG[i][j]*dEulerdBG[j][k]; */
    /* for(int i=0;i<9;i++) */
    /*   for(int j=i;j<9;j++){ */
    /* 	double temp=p3[i][j]; */
    /* 	p3[i][j]-=p3[j][i]; */
    /* 	if(i!=j) */
    /* 	  p3[j][i]-=temp; */
    /*   } */
    /* for(int i=0;i<3;i++) */
    /*   for(int j=0;j<9;j++) */
    /* 	for(int k=0;k<3;k++) */
    /* 	  p4[i][k]+=dEulerdBG[i][j]*dBdEulerG[j][k]; */
    /* for(int i=0;i<3;i++) */
    /*   for(int k=i;k<3;k++){ */
    /* 	double temp=p4[i][k]; */
    /* 	p4[i][k]-=p4[k][i]; */
    /* 	if(i!=k) */
    /* 	  p4[k][i]-=temp; */
    /*   } */

    /* double valP1=0.0; */
    /* double valP2=0.0; */
    /* double valP3=0.0; */
    /* double valP4=0.0; */
    /* for(int i=0;i<9;i++) */
    /*   for(int j=0;j<3;j++){ */
    /* 	valP1+=p1[i][j]*p1[i][j]; */
    /* 	valP2+=p2[j][i]*p2[j][i]; */
    /*   } */
    /* for(int i=0;i<9;i++) */
    /*   for(int j=0;j<9;j++){ */
    /* 	valP3+=p3[i][j]*p3[i][j]; */
    /*   } */
    /* for(int i=0;i<3;i++) */
    /*   for(int j=0;j<3;j++){ */
    /* 	valP4+=p4[i][j]*p4[i][j]; */
    /*   } */

    /* double tolPInv=1e-7; */
    /* if(sqrt(valP1)>tolPInv||sqrt(valP2)>tolPInv||sqrt(valP3)>tolPInv||sqrt(valP4)>tolPInv){ */
    /*   int baseVect[3]; */
    /*   int rank = getRankMat9x3(dBdEulerG,baseVect); */
    /*   printf("pb with pseudo inverse\n"); */
    /*   printf("rank : %i\n",rank); */
    /*   printf("dBdEuler\n"); */
    /*   for(int i=0;i<9;i++) */
    /* 	printf("%g // %g // %g\n",dBdEulerG[i][0],dBdEulerG[i][1],dBdEulerG[i][2]); */
    /*   printf("---------------\n"); */
    /*   printf("dEulerdB\n"); */
    /*   for(int i=0;i<3;i++) */
    /* 	printf("%g // %g // %g // %g // %g // %g // %g // %g // %g\n",dEulerdBG[i][0],dEulerdBG[i][1],dEulerdBG[i][2],dEulerdBG[i][3],dEulerdBG[i][4],dEulerdBG[i][5],dEulerdBG[i][6],dEulerdBG[i][7],dEulerdBG[i][8]); */
    /*   printf("values chec pInv\n"); */
    /*   printf("first  : %g // %g // %g // %g\n",sqrt(valP1),sqrt(valP2),sqrt(valP3),sqrt(valP4)); */
    /*   exit(0); */
    /* } */
    /* // */
    
    /* //dEulerdB computed at elem nodes to compute its grad */
    /* //node, euler, b */
    /* double dEulerdBElem[4][3][9]={{0.0}}; */
    /* for(int iN=0;iN<4;iN++){ */
    /*   double eulerNode[3]={euler[3*iN+0],euler[3*iN+1],euler[3*iN+2]}; */
    /*   double dBdEulerN[9][3]={{0.0}}; */
    /*   hxtOr3DdBdEuler(eulerNode, dBdEulerN); */
    /*   double dEulerdBN[3][9]={{0.0}}; */
    /*   pseudoInv9x3(dBdEulerN, dEulerdBN); */
    /*   for(int i=0;i<3;i++) */
    /* 	for(int j=0;j<9;j++) */
    /* 	  dEulerdBElem[iN][i][j]=dEulerdBN[i][j]; */
    /* } */
    /* double gradXdEulerdB[3][9][3]={{0.0}}; //euler, B, X */
    /* //ICI */
    /* for(int iX=0;iX<3;iX++) */
    /*   for(int kN=0;kN<4;kN++) */
    /* 	for(int jEul=0;jEul<3;jEul++) */
    /* 	  for(int lB=0;lB<9;lB++) */
    /* 	    gradXdEulerdB[jEul][lB][iX]+=dLdX[kN][iX]*dEulerdBElem[kN][jEul][lB]; */
  
    //compute integrability operators (euler)
    // fctID
    double Le[3]={0.0};
    double LdPsi[3]={0.0};
    double LdTheta[3]={0.0};
    double LdPhi[3]={0.0};
    // fctID,dim
    double LDPsi[3][3]={{0.0}};
    double LDTheta[3][3]={{0.0}};
    double LDPhi[3][3]={{0.0}};
    // fctID, eulerTilde, euler
    double Lddeuler[3][3][3]={{{0.0}}};
    // fctID, eulerTilde, euler, dim
    double LdDeuler[3][3][3][3]={{{{0.0}}}};
    double LDdeuler[3][3][3][3]={{{{0.0}}}};
  
    getIntegrabilityCostFctRoot(dirG, eulerG, gradPsi, gradTheta, gradPhi, Le);
    getIntegrabilityGradOp(eulerG,gradPsi,gradTheta,gradPhi,LdPsi,LDPsi,LdTheta,LDTheta,LdPhi,LDPhi,Lddeuler,LdDeuler,LDdeuler);

    /* //compute integrability operators (b) */
    /* double LdB[3][9]={0.0}; //eq (3) , bi (9) */
    /* double LDB[3][3][9]={{{0.0}}}; //eq (3) , X (3), bi (9) */
  
    /* for(int iEq=0;iEq<3;iEq++) */
    /*   for(int jB=0;jB<9;jB++) */
    /* 	LdB[iEq][jB]+= dEulerdBG[0][jB]*LdPsi[iEq] + dEulerdBG[1][jB]*LdTheta[iEq] + dEulerdBG[2][jB]*LdPhi[iEq]; */
  
    /* for(int iEq=0;iEq<3;iEq++) */
    /*   for(int jB=0;jB<9;jB++) */
    /* 	for(int kX=0;kX<3;kX++){ */
    /* 	  LDB[iEq][kX][jB]+=dEulerdBG[0][jB]*LDPsi[iEq][kX] + dEulerdBG[1][jB]*LDTheta[iEq][kX] + dEulerdBG[2][jB]*LDPhi[iEq][kX]; */
    /* 	  LdB[iEq][jB]+=gradXdEulerdB[0][jB][kX]*LDPsi[iEq][kX] + gradXdEulerdB[1][jB][kX]*LDTheta[iEq][kX] + gradXdEulerdB[2][jB][kX]*LDPhi[iEq][kX]; */
    /* 	} */
  
    double L[4]={1./4.,1./4.,1./4.,1./4.};
    for(int j=0;j<3*4;j++)
      grad[j]=0.0;

    /* //Rhs */
    /* for(int jB=0;jB<9;jB++){ */
    /*   for(int kN=0;kN<4;kN++){ */
    /* 	grad[jB*4+kN] += L[kN]*(LdB[0][jB]*Le[0]+LdB[1][jB]*Le[1]+LdB[2][jB]*Le[2])*detj*wG*(1./epsilon) ; */
    /* 	for(int lX=0;lX<3;lX++) */
    /* 	  grad[jB*4+kN] += dLdX[kN][lX]*(LDB[0][lX][jB]*Le[0]+LDB[1][lX][jB]*Le[1]+LDB[2][lX][jB]*Le[2])*detj*wG*(1./epsilon); */
    /*   } */
    /* } */
    
    //Rhs
    for(int iEq=0;iEq<3;iEq++){
      for(int kN=0;kN<4;kN++){
	grad[0*4+kN] += L[kN]*(LdPsi[iEq]*Le[iEq])*detj*wG;
	grad[1*4+kN] += L[kN]*(LdTheta[iEq]*Le[iEq])*detj*wG;
	grad[2*4+kN] += L[kN]*(LdPhi[iEq]*Le[iEq])*detj*wG;
	for(int lX=0;lX<3;lX++){
	  grad[0*4+kN] += dLdX[kN][lX]*(LDPsi[iEq][lX]*Le[iEq])*detj*wG;
	  grad[1*4+kN] += dLdX[kN][lX]*(LDTheta[iEq][lX]*Le[iEq])*detj*wG;
	  grad[2*4+kN] += dLdX[kN][lX]*(LDPhi[iEq][lX]*Le[iEq])*detj*wG;
	}
      }
    }

  }
  return HXT_STATUS_OK;
}

HXTStatus testGradValue(HXTMesh *mesh, int *invSortedVertices, double *directionsSorted)
{ //dbg fct
  int nVert=mesh->vertices.num;

  for (uint64_t ieT=0; ieT < mesh->tetrahedra.num; ++ieT){
    double framesElemNew[9*4];
    uint32_t *tet = &mesh->tetrahedra.node[ieT*4];
    uint32_t tetSorted[4];
    for(int k=0;k<4;k++)
      tetSorted[k]=invSortedVertices[tet[k]];
    for(int k=0;k<4;k++)
      for(int j=0;j<9;j++)
	framesElemNew[9*k+j] = directionsSorted[nVert*j+tetSorted[k]];

    double grad[3*4]={0.0};
    getGradEulerInt(mesh, tet, framesElemNew, grad);
    double normGrad=0.0;
    hxtNorm2V(grad, 12, &normGrad);
    double gradFD[3*4]={0.0};
    getGradFDEulerInt(mesh, tet, framesElemNew, gradFD);
    double normFD=0.0;
    hxtNorm2V(gradFD, 12, &normFD);
    double diffGrad[3*4]={0.0};
    for(int j=0;j<12;j++)
      diffGrad[j]=grad[j]-gradFD[j];
    double normDiff=0.0;
    hxtNorm2V(diffGrad, 12, &normDiff);
    printf("normGrad : %g // normGradFD : %g\n",normGrad,normFD);
    if(normGrad>1e-10&&normDiff/normGrad>0.05){
      printf("                    val norm diff test grad : ** -- %g -- **\n",normDiff/normGrad*100);
      printf("grad :\n");
      printf("a:%g / b:%g / c:%g / d:%g / e:%g / f:%g / g:%g / h:%g / i:%g / j:%g / k:%g / l:%g\n",grad[0],grad[1],grad[2],grad[3],grad[4],grad[5],grad[6],grad[7],grad[8],grad[9],grad[10],grad[11]);
      printf("gradFD :\n");
      printf("a:%g / b:%g / c:%g / d:%g / e:%g / f:%g / g:%g / h:%g / i:%g / j:%g / k:%g / l:%g\n",gradFD[0],gradFD[1],gradFD[2],gradFD[3],gradFD[4],gradFD[5],gradFD[6],gradFD[7],gradFD[8],gradFD[9],gradFD[10],gradFD[11]);
      if(normDiff/normGrad>0.05)
	exit(0);
    }
  }
  
  return HXT_STATUS_OK;
}
