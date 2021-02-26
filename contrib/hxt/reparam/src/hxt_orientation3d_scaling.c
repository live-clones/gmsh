// #include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_linear_system.h"
#include "hxt_orientation3d_tools.h"
#include "hxt_orientation3d_integrability.h"
#include "hxt_orientation3d_io.h"
#include "hxt_orientation3d_cleanMeshStruct.h"
#include <math.h>
#include <stdio.h>
#include <time.h>

typedef struct HXTOrientation3DScalStruct HXTOrientation3DScal;
/* typedef struct HXTOrientation3DCleanMeshStruct HXTOrientation3DCleanMesh; */

struct HXTOrientation3DScalStruct {
  HXTMesh *mesh;
  double *frames; // frame 9x1
  double *scaling;
  //global parameters

  
  //Element euler data
  double *eulerElem; //[3*4*iElem + 3*localNode + iEuler]
  double *branchMapElem; //[4*3*iElem + 3*localNode + iBranch]
  double *dLdXElem; //[3*4*iElem + 3*localNode + iDim]
  double *detj; //[iElem]
  double *localMatUU; //[4*4*iElem + 4*localNodeI + localNodeJ]
  double *localMatVV; //[4*4*iElem + 4*localNodeI + localNodeJ]
  double *localMatWW; //[4*4*iElem + 4*localNodeI + localNodeJ]
  double *localRhsU; //[4*iElem + localNodeI]
  double *localRhsV; //[4*iElem + localNodeI]
  double *localRhsW; //[4*iElem + localNodeI]
  double *localMatPenaltyUU; //[4*4*iElem + 4*localNodeI + localNodeJ]
  double *localMatPenaltyVV; //[4*4*iElem + 4*localNodeI + localNodeJ]
  double *localMatPenaltyWW; //[4*4*iElem + 4*localNodeI + localNodeJ]
  double *localRhsPenaltyU; //[4*iElem + localNodeI]
  double *localRhsPenaltyV; //[4*iElem + localNodeI]
  double *localRhsPenaltyW; //[4*iElem + localNodeI]
  double *squareTermErrorRhs; //[iElem]
  
};

/* struct HXTOrientation3DCleanMeshStruct { */
/*   HXTMesh *mesh; */
/*   uint8_t isMeshWithAloneVertices; */
/*   uint32_t nNodes; */
/*   //Vertices save */
/*   uint32_t verticesNumSave; */
/*   uint32_t verticesSizeSave; */
/*   double *verticesCoordSave; */
/*   //line save */
/*   uint32_t lineSizeSave; */
/*   uint32_t *lineNodeSave; */
/*   //triangle save */
/*   uint32_t triangleSizeSave; */
/*   uint32_t *triangleNodeSave; */
/*   //tetrahedra save */
/*   uint32_t tetrahedraSizeSave; */
/*   uint32_t *tetrahedraNodeSave; */
/*   //correspondance arrays */
/*   uint32_t *oldToNewNodes; */
/*   uint32_t *newToOldNodes; */
/* }; */

/* HXTStatus buildCleanMesh(HXTOrientation3DCleanMesh *cleanMeshObj, HXTMesh *mesh){ */
/*   cleanMeshObj->mesh=mesh; */
/*   cleanMeshObj->verticesCoordSave=NULL; */
/*   cleanMeshObj->lineNodeSave=NULL; */
/*   cleanMeshObj->triangleNodeSave=NULL; */
/*   cleanMeshObj->tetrahedraNodeSave=NULL; */
/*   cleanMeshObj->oldToNewNodes=NULL; */
/*   cleanMeshObj->newToOldNodes=NULL; */
/*   uint32_t *useNode; */
/*   HXT_CHECK(hxtMalloc(&useNode, sizeof(uint32_t)*mesh->vertices.num)); */
/*   for(uint32_t iN=0;iN<mesh->vertices.num;iN++){ */
/*     useNode[iN]=0; */
/*   } */
/*   for(uint32_t iL=0;iL<mesh->lines.num;iL++) */
/*     for(uint32_t k=0;k<2;k++) */
/*       useNode[mesh->lines.node[2*iL+k]]+=1; */
/*   for(uint32_t iT=0;iT<mesh->triangles.num;iT++) */
/*     for(uint32_t k=0;k<3;k++) */
/*       useNode[mesh->triangles.node[3*iT+k]]+=1; */
/*   for(uint32_t iT=0;iT<mesh->tetrahedra.num;iT++) */
/*     for(uint32_t k=0;k<4;k++) */
/*       useNode[mesh->tetrahedra.node[4*iT+k]]+=1; */
/*   cleanMeshObj->isMeshWithAloneVertices=0; */
/*   cleanMeshObj->nNodes=0; */
/*   for(uint32_t iN=0;iN<mesh->vertices.num;iN++){ */
/*     if(useNode[iN]>0){ */
/*       cleanMeshObj->nNodes++; */
/*     } */
/*   } */
/*   printf("nCleaned nodes : %i\n",cleanMeshObj->nNodes); */
/*   printf("nNodes in mesh : %i\n",mesh->vertices.num); */
/*   if(cleanMeshObj->nNodes<mesh->vertices.num) */
/*     cleanMeshObj->isMeshWithAloneVertices=1; */
/*   if(!(cleanMeshObj->isMeshWithAloneVertices)){ */
/*     hxtFree(&useNode); */
/*     return HXT_STATUS_OK; // No alone vertices. Return */
/*   } */
/*   HXT_CHECK(hxtMalloc(&(cleanMeshObj->oldToNewNodes), sizeof(uint32_t)*mesh->vertices.num)); */
/*   HXT_CHECK(hxtMalloc(&(cleanMeshObj->newToOldNodes), sizeof(uint32_t)*cleanMeshObj->nNodes)); */
/*   uint32_t currentInd=0; */
/*   for(uint32_t iN=0;iN<mesh->vertices.num;iN++){ */
/*     if(useNode[iN]>0){ */
/*       cleanMeshObj->oldToNewNodes[iN]=currentInd; */
/*       cleanMeshObj->newToOldNodes[currentInd]=iN; */
/*       currentInd++; */
/*     } */
/*   } */
/*   hxtFree(&useNode); */
/*   //vertices coord with new numerotation */
/*   double *newNodesCoord; */
/*   HXT_CHECK(hxtMalloc(&newNodesCoord, sizeof(double)*4*cleanMeshObj->nNodes)); */
/*   for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++){ */
/*     for(uint32_t k=0;k<4;k++) */
/*       newNodesCoord[4*iN+k]=mesh->vertices.coord[4*cleanMeshObj->newToOldNodes[iN]+k]; */
/*   } */
/*   //lines with new numerotation */
/*   uint32_t *newLinesNode; */
/*   HXT_CHECK(hxtMalloc(&newLinesNode, sizeof(uint32_t)*2*mesh->lines.num)); */
/*   for(uint32_t iL=0;iL<mesh->lines.num;iL++){ */
/*     for(uint32_t k=0;k<2;k++) */
/*       newLinesNode[2*iL+k]=cleanMeshObj->oldToNewNodes[mesh->lines.node[2*iL+k]]; */
/*   } */
/*   //triangles with new numerotation */
/*   uint32_t *newTriangleNode; */
/*   HXT_CHECK(hxtMalloc(&newTriangleNode, sizeof(uint32_t)*3*mesh->triangles.num)); */
/*   for(uint32_t iT=0;iT<mesh->triangles.num;iT++){ */
/*     for(uint32_t k=0;k<3;k++) */
/*       newTriangleNode[3*iT+k]=cleanMeshObj->oldToNewNodes[mesh->triangles.node[3*iT+k]]; */
/*   } */
/*   //tetrahedra with new numerotation */
/*   uint32_t *newTetrahedraNode; */
/*   HXT_CHECK(hxtMalloc(&newTetrahedraNode, sizeof(uint32_t)*4*mesh->tetrahedra.num)); */
/*   for(uint32_t iT=0;iT<mesh->tetrahedra.num;iT++){ */
/*     for(uint32_t k=0;k<4;k++) */
/*       newTetrahedraNode[4*iT+k]=cleanMeshObj->oldToNewNodes[mesh->tetrahedra.node[4*iT+k]]; */
/*   } */
/*   //saving current structures */
/*   cleanMeshObj->verticesNumSave=mesh->vertices.num; */
/*   cleanMeshObj->verticesSizeSave=mesh->vertices.size; */
/*   cleanMeshObj->verticesCoordSave=mesh->vertices.coord; */
/*   cleanMeshObj->lineSizeSave=mesh->lines.size; */
/*   cleanMeshObj->lineNodeSave=mesh->lines.node; */
/*   cleanMeshObj->triangleSizeSave=mesh->triangles.size; */
/*   cleanMeshObj->triangleNodeSave=mesh->triangles.node; */
/*   cleanMeshObj->tetrahedraSizeSave=mesh->tetrahedra.size; */
/*   cleanMeshObj->tetrahedraNodeSave=mesh->tetrahedra.node; */
/*   //new numerotation in mesh */
/*   mesh->vertices.num=cleanMeshObj->nNodes; */
/*   mesh->vertices.size=cleanMeshObj->nNodes; */
/*   mesh->vertices.coord=newNodesCoord; */
/*   mesh->lines.size=mesh->lines.num; */
/*   mesh->lines.node=newLinesNode; */
/*   mesh->triangles.size=mesh->triangles.num; */
/*   mesh->triangles.node=newTriangleNode; */
/*   mesh->tetrahedra.size=mesh->tetrahedra.num; */
/*   mesh->tetrahedra.node=newTetrahedraNode; */

/*   return HXT_STATUS_OK; */
/* } */

/* HXTStatus cleanMeshRestoreMesh(HXTOrientation3DCleanMesh *cleanMeshObj){ */
/*   HXTMesh *mesh = cleanMeshObj->mesh; */
/*   if(!(cleanMeshObj->isMeshWithAloneVertices)) */
/*     return HXT_STATUS_OK; */
/*   //restoring saved structures */
/*   if(cleanMeshObj->verticesCoordSave){ */
/*     mesh->vertices.num=cleanMeshObj->verticesNumSave; */
/*     mesh->vertices.size=cleanMeshObj->verticesSizeSave; */
/*     hxtFree(&(mesh->vertices.coord)); */
/*     mesh->vertices.coord=cleanMeshObj->verticesCoordSave; */
/*   } */
/*   if(cleanMeshObj->lineNodeSave){ */
/*     mesh->lines.size=cleanMeshObj->lineSizeSave; */
/*     hxtFree(&(mesh->lines.node)); */
/*     mesh->lines.node=cleanMeshObj->lineNodeSave; */
/*   } */
/*   if(cleanMeshObj->triangleNodeSave){ */
/*     mesh->triangles.size=cleanMeshObj->triangleSizeSave; */
/*     hxtFree(&(mesh->triangles.node)); */
/*     mesh->triangles.node=cleanMeshObj->triangleNodeSave; */
/*   } */
/*   if(cleanMeshObj->tetrahedraNodeSave){ */
/*     mesh->tetrahedra.size=cleanMeshObj->tetrahedraSizeSave; */
/*     hxtFree(&(mesh->tetrahedra.node)); */
/*     mesh->tetrahedra.node=cleanMeshObj->tetrahedraNodeSave; */
/*   } */
/*   return HXT_STATUS_OK; */
/* } */

/* HXTStatus cleanMeshRestoreSolution(HXTOrientation3DCleanMesh *cleanMeshObj, double *solution, uint32_t nFields){ */
/*   if(!(cleanMeshObj->isMeshWithAloneVertices)) */
/*     return HXT_STATUS_OK; */
/*   double *restoredSolution; */
/*   HXT_CHECK(hxtMalloc(&restoredSolution, sizeof(double)*nFields*cleanMeshObj->verticesNumSave)); */
/*   for(uint32_t iN=0;iN<cleanMeshObj->verticesNumSave;iN++) */
/*     for(uint32_t k=0;k<nFields;k++) */
/*       restoredSolution[nFields*iN+k]=0.0; */
/*   for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++){ */
/*     for(uint32_t k=0;k<nFields;k++) */
/*       restoredSolution[nFields*cleanMeshObj->newToOldNodes[iN]+k]=solution[nFields*iN+k]; */
/*   } */
/*   for(uint32_t iN=0;iN<cleanMeshObj->verticesNumSave;iN++) */
/*     for(uint32_t k=0;k<nFields;k++) */
/*       solution[nFields*iN+k]=restoredSolution[nFields*iN+k]; */
/*   hxtFree(&restoredSolution); */
/*   return HXT_STATUS_OK; */
/* } */

/* HXTStatus cleanMeshCleanSolution(HXTOrientation3DCleanMesh *cleanMeshObj, double *solution, uint32_t nFields){ */
/*   if(!(cleanMeshObj->isMeshWithAloneVertices)) */
/*     return HXT_STATUS_OK; */
/*   double *cleanedSolution; */
/*   HXT_CHECK(hxtMalloc(&cleanedSolution, sizeof(double)*nFields*cleanMeshObj->nNodes)); */
/*   for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++) */
/*     for(uint32_t k=0;k<nFields;k++) */
/*       cleanedSolution[nFields*iN+k]=0.0; */
/*   for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++){ */
/*     for(uint32_t k=0;k<nFields;k++) */
/*       cleanedSolution[nFields*iN+k]=solution[nFields*cleanMeshObj->newToOldNodes[iN]+k]; */
/*   } */
/*   for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++) */
/*     for(uint32_t k=0;k<nFields;k++) */
/*       solution[nFields*iN+k]=cleanedSolution[nFields*iN+k]; */
/*   hxtFree(&cleanedSolution); */
/*   return HXT_STATUS_OK; */
/* } */

/* HXTStatus cleanMeshDestroy(HXTOrientation3DCleanMesh *cleanMeshObj){ */
/*   if(cleanMeshObj->oldToNewNodes) */
/*     hxtFree(&(cleanMeshObj->oldToNewNodes)); */
/*   if(cleanMeshObj->newToOldNodes) */
/*     hxtFree(&(cleanMeshObj->newToOldNodes)); */
/*   return HXT_STATUS_OK; */
/* } */


HXTStatus computeLocalOpScaling(double AL[3][3], double AM[3][3], double Aphi[3][3], double Atheta[3][3], double Apsi[3][3], double BL[3][3], double BN[3][3], double Bphi[3][3], double Btheta[3][3], double Bpsi[3][3], double CM[3][3], double CN[3][3], double Cphi[3][3], double Ctheta[3][3], double Cpsi[3][3], const double eulerG[3], const double *dirG){ //keep
  double psi=eulerG[0];
  double theta=eulerG[1];
  double phi=eulerG[2];
  double u[3]={0.0};
  double v[3]={0.0};
  double w[3]={0.0};
  double minusU[3]={0.0};
  double minusV[3]={0.0};
  double sinPhiV[3]={0.0};
  double cosPhiW[3]={0.0};
  double sinPhiW[3]={0.0};
  double minusCosPhiU[3]={0.0};
  double wPiOver2[3]={sin(psi)*cos(theta),-cos(psi)*cos(theta),-sin(theta)};
  for(int i=0;i<3;i++){
    u[i]=dirG[i];
    v[i]=dirG[3+i];
    w[i]=dirG[6+i];
    minusU[i]=-u[i];
    minusV[i]=-v[i];
    sinPhiV[i]=sin(phi)*v[i];
    sinPhiW[i]=sin(phi)*w[i];
    cosPhiW[i]=cos(phi)*w[i];
    minusCosPhiU[i]=-cos(phi)*u[i];
  }
  double uOrth[3]={0.0};
  double vOrth[3]={0.0};
  double wOrth[3]={0.0};
  uOrth[0]=-u[1];
  uOrth[1]=u[0];
  vOrth[0]=-v[1];
  vOrth[1]=v[0];
  wOrth[0]=-w[1];
  wOrth[1]=w[0];

  //Operator u,v commutation
  hxtOr3DdyadicProd3(minusU, v, AL);
  hxtOr3DdyadicProd3(v, u, AM);
  double Aphi1[3][3]={{0.0}};
  double Aphi2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(u, u, Aphi1);
  hxtOr3DdyadicProd3(v, v, Aphi2);
  hxtOr3DsumMat3x3(Aphi1, Aphi2, Aphi);
  double Atheta1[3][3]={{0.0}};
  double Atheta2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(w, sinPhiV, Atheta1);
  hxtOr3DdyadicProd3(w, minusCosPhiU, Atheta2);
  hxtOr3DsumMat3x3(Atheta1, Atheta2, Atheta);
  double Apsi1[3][3]={{0.0}};
  double Apsi2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(uOrth, v, Apsi1);
  hxtOr3DdyadicProd3(vOrth, minusU, Apsi2);
  hxtOr3DsumMat3x3(Apsi1, Apsi2, Apsi);

  //Operator u,w commutation
  hxtOr3DdyadicProd3(minusU, w, BL);
  hxtOr3DdyadicProd3(w, u, BN);
  hxtOr3DdyadicProd3(v, w, Bphi);
  
  double Btheta1[3][3]={{0.0}};
  double Btheta2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(sinPhiW, w, Btheta1);
  hxtOr3DdyadicProd3(wPiOver2, minusU, Btheta2);
  hxtOr3DsumMat3x3(Btheta1, Btheta2, Btheta);

  double Bpsi1[3][3]={{0.0}};
  double Bpsi2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(uOrth, w, Bpsi1);
  hxtOr3DdyadicProd3(wOrth, minusU, Bpsi2);
  hxtOr3DsumMat3x3(Bpsi1, Bpsi2, Bpsi);

  //Operator v,w commutation
  hxtOr3DdyadicProd3(minusV, w, CM);
  hxtOr3DdyadicProd3(w, v, CN);
  hxtOr3DdyadicProd3(minusU, w, Cphi);

  double Ctheta1[3][3]={{0.0}};
  double Ctheta2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(cosPhiW, w, Ctheta1);
  hxtOr3DdyadicProd3(wPiOver2, minusV, Ctheta2);
  hxtOr3DsumMat3x3(Ctheta1, Ctheta2, Ctheta);

  double Cpsi1[3][3]={{0.0}};
  double Cpsi2[3][3]={{0.0}};
  hxtOr3DdyadicProd3(vOrth, w, Cpsi1);
  hxtOr3DdyadicProd3(wOrth, minusV, Cpsi2);
  hxtOr3DsumMat3x3(Cpsi1, Cpsi2, Cpsi);
  
  return HXT_STATUS_OK;
}

static inline double lagBasisTet(const int k, const double *xi){ //keep
  double value=0.0;
  switch (k){
  case 0:
    value = 1-xi[0]-xi[1]-xi[2];
    break;
  case 1:
    value = xi[0];
    break;
  case 2:
    value = xi[1];
    break;
  case 3:
    value = xi[2];
    break;
  default:
    printf("pb lag basis\n");
    exit(0);
    break;
  }
  return value;
}

HXTStatus getGauss(int nG, double *xG, double * wG){ //keep
  switch(nG)
    {
    case 1:
      {
	double xGref[3]={1.0/4.0, 1.0/4.0, 1.0/4.0};
	double wGref[1]={1.0/6.0};
	for(int i=0;i<nG;i++){
	  wG[i]=wGref[i];
	  for(int j=0;j<3;j++)
	    xG[3*i+j]=xGref[3*i+j];
	}
      }
      break;
    case 4:
      {
	double aG=(5-sqrt(5))/20.0;
	double bG=(5+3*sqrt(5))/20.0;
	double xGref[12]={aG,aG,aG,aG,aG,bG,aG,bG,aG,bG,aG,aG};
	double wGref[4]={1.0/24.0,1.0/24.0,1.0/24.0,1.0/24.0};
	for(int i=0;i<nG;i++){
	  wG[i]=wGref[i];
	  for(int j=0;j<3;j++)
	    xG[3*i+j]=xGref[3*i+j];
	}
      }
      break;
    case 5:
      {
	double a=0.25;
	double b=1.0/6.0;
	double c=0.5;
	double xGref[15]={a,a,a,b,b,b,b,b,c,b,c,b,c,b,b};
	double wGref[5]={-2.0/15.0,3.0/40.0,3.0/40.0,3.0/40.0,3.0/40.0};
	for(int i=0;i<nG;i++){
	  wG[i]=wGref[i];
	  for(int j=0;j<3;j++)
	    xG[3*i+j]=xGref[3*i+j];
	}
      }
      break;
    default:
      printf("pb gauss points\n");
      exit(0);
      break;
    }
  return HXT_STATUS_OK;
}

HXTStatus rotateDirElemTet(double dirElem[4*9]){ //keep
  for(int k=0;k<4;k++){
    double *dir=dirElem+9*k;
    double temp[3]={0.0};
    for(int j=0;j<3;j++)
      temp[j]=dir[3*2+j];
    for(int i=0;i<2;i++){
      for(int j=0;j<3;j++)
	dir[3*(2-i)+j]=dir[3*(2-i-1)+j];
    }
    for(int j=0;j<3;j++)
      dir[j]=temp[j];
  }
  return HXT_STATUS_OK;
}

HXTStatus getBranchMapElem(HXTMesh *mesh, double *dirElem, double *frames, int iel, int branchMapElem[4][3]){ //keep
  for(int k=0;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    for(int i=0;i<3;i++){
      double maxScalar=-1.0;
      double *branchToMap=dirElem+9*k+3*i;
      for(int lref=0;lref<3;lref++){
	double *branchRef=dirK+3*lref;
	double scalar=0.0;
	hxtOr3DdotProd(branchToMap,branchRef,3, &scalar);
	if(fabs(scalar)>maxScalar){
	  maxScalar=fabs(scalar);
	  branchMapElem[k][i]=lref;
	}
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus or3DGetEulerElemBranchMapElem(HXTOrientation3DScal *or3D){
  HXTMesh *mesh=or3D->mesh;
  double *frames=or3D->frames;
  for(uint32_t iel=0;iel<mesh->tetrahedra.num;iel++){
    double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frameElem, stableDir, refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    double eulerElem[3*4]={0.0};
    double dirElem[9*4]={0.0};
    for(int i=0;i<9;i++){
      dirElem[i]=refDir[i];
    }
    for(int k=1;k<4;k++){
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      hxtOr3DmakeOrientationDirect(dirK);
      hxtOr3DliftBasis(refDir,dirK);
      for(int i=0;i<9;i++){
	dirElem[9*k+i]=dirK[i];
      }
    }
    uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
    or3D->detj[iel]=detj;
    const double dphi[4][3] = {
      {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
      {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
      {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
      {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
    };
    
    int flagLoc=1;
    hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
    int nRot=0;
    while(flagLoc){
      nRot++;
      if(nRot>2){
	printf("ups to many rot needed\n");
	exit(0);
	break;
      }
      rotateDirElemTet(dirElem);
      hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
    }
    if(flagLoc){
      printf("hum, seem no way to do a rotation to remove no nutation\n");
      exit(0);
    }
    int branchMap[4][3];
    getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
    for(int k=0;k<4;k++){
      for(int j=0;j<3;j++){
	or3D->eulerElem[3*4*iel+3*k+j]=eulerElem[3*k+j];
	or3D->branchMapElem[3*4*iel+3*k+j]=branchMap[k][j];
	or3D->dLdXElem[3*4*iel+3*k+j]=dphi[k][j];
      }
    }
    int nG=1;
    double *xG;
    HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
    double *wG;
    HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
    getGauss(nG, xG, wG);
    double psiElem[4]={0.0};
    double thetaElem[4]={0.0};
    double phiElem[4]={0.0};    
    for(int k=0;k<4;k++){
      psiElem[k]=eulerElem[3*k+0];
      thetaElem[k]=eulerElem[3*k+1];
      phiElem[k]=eulerElem[3*k+2];
    }
    for(int iG=0;iG<nG;iG++){
      double AL[3][3]={{0.0}};
      double AM[3][3]={{0.0}};
      double Aphi[3][3]={{0.0}};
      double Atheta[3][3]={{0.0}};
      double Apsi[3][3]={{0.0}};
      double BL[3][3]={{0.0}};
      double BN[3][3]={{0.0}};
      double Bphi[3][3]={{0.0}};
      double Btheta[3][3]={{0.0}};
      double Bpsi[3][3]={{0.0}};
      double CM[3][3]={{0.0}};
      double CN[3][3]={{0.0}};
      double Cphi[3][3]={{0.0}};
      double Ctheta[3][3]={{0.0}};
      double Cpsi[3][3]={{0.0}};
      double eulerG[3]={0.0};
      double dirG[9]={0.0};
      for(int k=0;k<3;k++)
	for(int l=0;l<4;l++)
	  eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
      double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
      getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      for(int j=0;j<3;j++){
	dirG[j]=u[j];
	dirG[3+j]=v[j];
	dirG[6+j]=w[j];
      }
      computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
      double a[3]={0.0};
      double b[3]={0.0};
      double c[3]={0.0};
      for (int i = 0; i < 3; ++i){
	for (int j = 0; j < 3; ++j){
	  for (int k = 0; k < 4; ++k){
	    a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	    b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	    c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	  }
	}
      }
      double ua=0.0;
      double va=0.0;
      double ub=0.0;
      double wb=0.0;
      double vc=0.0;
      double wc=0.0;
      hxtOr3DdotProd(u,a,3, &ua);
      hxtOr3DdotProd(v,a,3, &va);
      hxtOr3DdotProd(u,b,3, &ub);
      hxtOr3DdotProd(w,b,3, &wb);
      hxtOr3DdotProd(v,c,3, &vc);
      hxtOr3DdotProd(w,c,3, &wc);
      double uAL[3]={0.0};
      double vAM[3]={0.0};
      double uBL[3]={0.0};
      double wBN[3]={0.0};
      double vCM[3]={0.0};
      double wCN[3]={0.0};
      for (int i = 0; i < 3; ++i){
	for (int k = 0; k < 3; ++k){
	  uAL[i]+=u[k]*AL[k][i];
	  vAM[i]+=v[k]*AM[k][i];
	  uBL[i]+=u[k]*BL[k][i];
	  wBN[i]+=w[k]*BN[k][i];
	  vCM[i]+=v[k]*CM[k][i];
	  wCN[i]+=w[k]*CN[k][i];
	}
      }
      
      double localMatUU[16]={0.0};
      double localMatVV[16]={0.0};
      double localMatWW[16]={0.0};
      double localMatPenaltyUU[16]={0.0};
      double localMatPenaltyVV[16]={0.0};
      double localMatPenaltyWW[16]={0.0};
      double localRhsU[4]={0.0};
      double localRhsV[4]={0.0};
      double localRhsW[4]={0.0};

      /* double gradL[3]={0.0}; */
      /* double gradM[3]={0.0}; */
      /* double gradN[3]={0.0}; */
      /* for (int j = 0; j < 4; ++j) */
      /* 	for (int k = 0; k < 3; ++k){ */
      /* 	  int globU=branchMap[j][0]; */
      /* 	  int globV=branchMap[j][1]; */
      /* 	  int globW=branchMap[j][2]; */
      /* 	  gradL[k]+=dphi[j][k]*or3D->scaling[3*tet[j]+globU]; */
      /* 	  gradM[k]+=dphi[j][k]*or3D->scaling[3*tet[j]+globV]; */
      /* 	  gradN[k]+=dphi[j][k]*or3D->scaling[3*tet[j]+globW]; */
      /* 	} */
      /* double gradLu=0.0; */
      /* double gradMv=0.0; */
      /* double gradNw=0.0; */
      /* for (int k = 0; k < 3; ++k){ */
      /* 	gradLu+=gradL[k]*u[k]; */
      /* 	gradMv+=gradM[k]*v[k]; */
      /* 	gradNw+=gradN[k]*w[k]; */
      /* } */
      
      int isTetSing=0;
      for (int k = 0; k < 4; k++){
	double qual=0.0;
	double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
	hxtOr3DcomputeQuality(frameK, &qual);
	if(qual>10)
	  isTetSing=1;
      }
      if(!isTetSing){
	for (int i = 0; i < 4; ++i)
	  for (int j = 0; j < 4; ++j)
	    for (int k = 0; k < 3; ++k){
	      for (int m = 0; m < 3; ++m){
		/* localMatUU[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m])*dphi[j][m]*detj*wG[iG]; */
		/* localMatVV[4*i+j]+= dphi[i][k]*(vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG]; */
		/* localMatWW[4*i+j]+= dphi[i][k]*(wBN[k]*wBN[m]+wCN[k]*wCN[m])*dphi[j][m]*detj*wG[iG]; */
		//regularization terms added
		localMatUU[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m])*dphi[j][m]*detj*wG[iG];
		localMatVV[4*i+j]+= dphi[i][k]*(vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG];
		localMatWW[4*i+j]+= dphi[i][k]*(wBN[k]*wBN[m]+wCN[k]*wCN[m])*dphi[j][m]*detj*wG[iG];

		localMatPenaltyUU[4*i+j]+=dphi[i][k]*(vAM[k]*vAM[m])*dphi[j][m]*detj*wG[iG];
		localMatPenaltyVV[4*i+j]+=dphi[i][k]*(uAL[k]*uAL[m])*dphi[j][m]*detj*wG[iG];
		localMatPenaltyWW[4*i+j]+=dphi[i][k]*(uBL[k]*uBL[m])*dphi[j][m]*detj*wG[iG];
	      }
	    }
	
	for (int j = 0; j < 4; ++j)
	  for (int k = 0; k < 3; ++k){
	    localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG];
	    localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG];
	    localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG];
	    /* //regularization term added */
	    /* localRhsU[j]+= dphi[j][k]*(vAM[k]*gradLu+uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	    /* localRhsV[j]+= dphi[j][k]*(-uAL[k]*gradMv+vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	    /* localRhsW[j]+= dphi[j][k]*(-uBL[k]*gradNw+wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	    /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb)*detj*wG[iG]; */
	    /* localRhsW[j]+= dphi[j][k]*(wCN[k]*wc)*detj*wG[iG]; */
	  }
      }
      or3D->squareTermErrorRhs[iel]=(ua*ua+ub*ub+va*va+vc*vc+wb*wb+wc*wc)*detj*wG[iG];
      for (int i = 0; i < 4; ++i){
	or3D->localRhsU[4*iel+i]=localRhsU[i];
	or3D->localRhsV[4*iel+i]=localRhsV[i];
	or3D->localRhsW[4*iel+i]=localRhsW[i];
	for (int j = 0; j < 4; ++j){
	  or3D->localMatUU[16*iel+4*i+j]=localMatUU[4*i+j];
	  or3D->localMatVV[16*iel+4*i+j]=localMatVV[4*i+j];
	  or3D->localMatWW[16*iel+4*i+j]=localMatWW[4*i+j];
	  or3D->localMatPenaltyUU[16*iel+4*i+j]=localMatPenaltyUU[4*i+j];
	  or3D->localMatPenaltyVV[16*iel+4*i+j]=localMatPenaltyVV[4*i+j];
	  or3D->localMatPenaltyWW[16*iel+4*i+j]=localMatPenaltyWW[4*i+j];
	}
      }
    }//end loop on gauss points
    hxtFree(&xG);
    hxtFree(&wG);
  }
  return HXT_STATUS_OK;
}

HXTStatus buildOr3DScal(HXTOrientation3DScal *or3D, HXTMesh *mesh, double *frames, double *scaling){
  or3D->mesh=mesh;
  or3D->frames=frames;
  or3D->scaling=scaling;
  HXT_CHECK(hxtMalloc(&(or3D->eulerElem), 3*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->branchMapElem), 3*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->dLdXElem), 3*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->detj), mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localMatUU), 4*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localMatVV), 4*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localMatWW), 4*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localRhsU), 4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localRhsV), 4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localRhsW), 4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localMatPenaltyUU), 4*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localMatPenaltyVV), 4*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localMatPenaltyWW), 4*4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localRhsPenaltyU), 4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localRhsPenaltyV), 4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->localRhsPenaltyW), 4*mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->squareTermErrorRhs), mesh->tetrahedra.num*sizeof(double)));
  for(uint64_t k=0;k<4*4*mesh->tetrahedra.num;k++){
    or3D->localMatUU[k]=0.0;
    or3D->localMatVV[k]=0.0;
    or3D->localMatWW[k]=0.0;
    or3D->localMatPenaltyUU[k]=0.0;
    or3D->localMatPenaltyVV[k]=0.0;
    or3D->localMatPenaltyWW[k]=0.0;
  }
  for(uint64_t k=0;k<4*mesh->tetrahedra.num;k++){
    or3D->localRhsU[k]=0.0;
    or3D->localRhsV[k]=0.0;
    or3D->localRhsW[k]=0.0;
    or3D->localRhsPenaltyU[k]=0.0;
    or3D->localRhsPenaltyV[k]=0.0;
    or3D->localRhsPenaltyW[k]=0.0;
  }
  for(uint64_t k=0;k<mesh->tetrahedra.num;k++){
    or3D->squareTermErrorRhs[k]=0.0;
  }
  or3DGetEulerElemBranchMapElem(or3D);
  
  return HXT_STATUS_OK;
}

HXTStatus destroyOr3DScal(HXTOrientation3DScal *or3D){
  HXT_CHECK(hxtFree(&(or3D->eulerElem)));
  HXT_CHECK(hxtFree(&(or3D->branchMapElem)));
  HXT_CHECK(hxtFree(&(or3D->dLdXElem)));
  HXT_CHECK(hxtFree(&(or3D->detj)));
  HXT_CHECK(hxtFree(&(or3D->localMatPenaltyUU)));
  HXT_CHECK(hxtFree(&(or3D->localMatPenaltyVV)));
  HXT_CHECK(hxtFree(&(or3D->localMatPenaltyWW)));
  HXT_CHECK(hxtFree(&(or3D->localMatUU)));
  HXT_CHECK(hxtFree(&(or3D->localMatVV)));
  HXT_CHECK(hxtFree(&(or3D->localMatWW)));
  HXT_CHECK(hxtFree(&(or3D->localRhsU)));
  HXT_CHECK(hxtFree(&(or3D->localRhsV)));
  HXT_CHECK(hxtFree(&(or3D->localRhsW)));
  HXT_CHECK(hxtFree(&(or3D->localRhsPenaltyU)));
  HXT_CHECK(hxtFree(&(or3D->localRhsPenaltyV)));
  HXT_CHECK(hxtFree(&(or3D->localRhsPenaltyW)));
  HXT_CHECK(hxtFree(&(or3D->squareTermErrorRhs)));
  return HXT_STATUS_OK;
}

HXTStatus computeBndNormalsScaling(HXTMesh *mesh, double *normals){
  int *numTriByNode;
  HXT_CHECK(hxtMalloc(&numTriByNode, sizeof(int)*mesh->vertices.num));
  int *isSharp;
  HXT_CHECK(hxtMalloc(&isSharp, sizeof(int)*mesh->vertices.num));
  int *isTooSharp;
  HXT_CHECK(hxtMalloc(&isTooSharp, sizeof(int)*mesh->vertices.num));
  int nEdgSharp=0;
  int nEdgTooSharp=0;
  int nBndEdges=0;
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) {
    normals[i*3+0] = 0;
    normals[i*3+1] = 0;
    normals[i*3+2] = 0;
    normals[(i+mesh->vertices.num)*3+0] = 0;
    normals[(i+mesh->vertices.num)*3+1] = 0;
    normals[(i+mesh->vertices.num)*3+2] = 0;
    numTriByNode[i] = 0;
    isSharp[i] = 0;
    isTooSharp[i] = 0;
  }
  for (uint64_t iel = 0; iel < mesh->triangles.num; ++iel) {
    uint32_t *tri = mesh->triangles.node + 3*iel;
    double *x[3] = {
      mesh->vertices.coord + 4*tri[0],
      mesh->vertices.coord + 4*tri[1],
      mesh->vertices.coord + 4*tri[2]
    };
    double dx[2][3] = {
      {x[1][0]-x[0][0], x[1][1]-x[0][1], x[1][2]-x[0][2]},
      {x[2][0]-x[0][0], x[2][1]-x[0][1], x[2][2]-x[0][2]}
    };
    double n[3] = {
      dx[0][1]*dx[1][2]-dx[0][2]*dx[1][1],
      dx[0][2]*dx[1][0]-dx[0][0]*dx[1][2],
      dx[0][0]*dx[1][1]-dx[0][1]*dx[1][0]
    };
    double norm = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
    n[0] /= norm;
    n[1] /= norm;
    n[2] /= norm;
    for (int i = 0; i < 3; ++i) {
      double *ni = normals + tri[i]*3;
      double *nj = normals + (mesh->vertices.num+tri[i])*3;
      if(sqrt(ni[0]*ni[0]+ni[1]*ni[1]+ni[2]*ni[2])>1e-6){
	double cosAngle = (ni[0]*n[0]+ni[1]*n[1]+ni[2]*n[2])/(sqrt(ni[0]*ni[0]+ni[1]*ni[1]+ni[2]*ni[2])*sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]));
	if(cosAngle<sqrt(2)/2){
	  if(!isSharp[tri[i]])
	     nEdgSharp++;
	  isSharp[tri[i]] = 1;
	  if(sqrt(nj[0]*nj[0]+nj[1]*nj[1]+nj[2]*nj[2])>1e-6){
	    double cosAngle2 = (nj[0]*n[0]+nj[1]*n[1]+nj[2]*n[2])/(sqrt(nj[0]*nj[0]+nj[1]*nj[1]+nj[2]*nj[2])*sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]));
	    if(cosAngle2<sqrt(2)/2){
	      if(!isTooSharp[tri[i]])
		 nEdgTooSharp++;
	      isTooSharp[tri[i]] = 1;
	    }
	    else{
	      nj[0] += n[0];
	      nj[1] += n[1];
	      nj[2] += n[2];
	    }
	  }
	  else{
	    nj[0] += n[0];
	    nj[1] += n[1];
	    nj[2] += n[2];
	  }
	}
	else{
	  ni[0] += n[0];
	  ni[1] += n[1];
	  ni[2] += n[2];
	}
      }
      else{
	ni[0] += n[0];
	ni[1] += n[1];
	ni[2] += n[2];
      }
      numTriByNode[tri[i]] += 1;
      if(numTriByNode[tri[i]]==1)
	 nBndEdges++;
    }
  }
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) {
    if (numTriByNode[i] == 0) continue;
    double *n = normals + i*3;
    n[0] /= numTriByNode[i];
    n[1] /= numTriByNode[i];
    n[2] /= numTriByNode[i];
    double norm = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
    n[0] /= norm;
    n[1] /= norm;
    n[2] /= norm;
    if(isSharp[i]){
      double *n2 = normals + (mesh->vertices.num+i)*3;
      double norm2 = sqrt(n2[0]*n2[0]+n2[1]*n2[1]+n2[2]*n2[2]);
      n2[0] /= norm2;
      n2[1] /= norm2;
      n2[2] /= norm2;
      if(isTooSharp[i]){
	n2[0] = 0;
	n2[1] = 0;
	n2[2] = 0;
      }
    }
    if(isTooSharp[i]){
      n[0] = 0;
      n[1] = 0;
      n[2] = 0;
    }
  }
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) {
    if (!isSharp[i]||isTooSharp[i]) continue;
    double *n = normals + i*3;
    double *n2 = normals + (mesh->vertices.num+i)*3;
    double cosTheta = n[0]*n2[0] + n[1]*n2[1] + n[2]*n2[2];
    double theta = acos(cosTheta);
    double thetaBarre = M_PI/2 - theta;
    double v[3];
    for(int k=0;k<3;k++)
      v[k] = n2[k] - cosTheta*n[k];
    double normV = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    for(int k=0;k<3;k++)
      v[k] /= normV;
    double newN2[3];
    for(int k=0;k<3;k++)
      newN2[k] = cos(thetaBarre/2 + theta)*n[k] + sin(thetaBarre/2 + theta)*v[k];
    double ps = n[0]*newN2[0] + n[1]*newN2[1] + n[2]*newN2[2];
    double newN[3];
    for(int k=0;k<3;k++)
      newN[k] = n[k]-ps*newN2[k];
    double normN = sqrt(newN[0]*newN[0] + newN[1]*newN[1] + newN[2]*newN[2]);
    for(int k=0;k<3;k++)
      newN[k] /= normN;
    for(int k=0;k<3;k++){
      n[k] = newN[k];
      n2[k] = newN2[k];
    }
  }
  /* // DBG disable BC on sharp edges */
  /* for (int i = 0; i < mesh->vertices.num; ++i) { */
  /*   if(isTooSharp[i]||isSharp[i]){ */
  /*     double *n = normals + i*3; */
  /*     n[0] = 0; */
  /*     n[1] = 0; */
  /*     n[2] = 0; */
  /*   } */
  /* } */
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) {
    if(isTooSharp[i]){
      double *n = normals + i*3;
      n[0] = 0;
      n[1] = 0;
      n[2] = 0;
    }
  }

  printf("numBndEdges : %i ; nBndSharpEdges : %i ; nBndTooSharpEdges : %i\n",nBndEdges,nEdgSharp,nEdgTooSharp);
  HXT_CHECK(hxtFree(&numTriByNode));
  HXT_CHECK(hxtFree(&isSharp));
  HXT_CHECK(hxtFree(&isTooSharp));
  return HXT_STATUS_OK;
}

HXTStatus moveNormalToLastDir(double *dir, const double *normal){ //keep
  
  double newDir[9]={0.0};
  // find closest to normal
  double maxDotProd=0.0;
  hxtOr3DdotProd(normal,dir,3, &maxDotProd);
  maxDotProd=fabs(maxDotProd);
  int indMax=0;
  double sign=0.0;
  for(int i=1;i<3;i++){
    double scalarProd=0.0;
    hxtOr3DdotProd(normal,dir+3*i,3, &scalarProd);
    if(fabs(scalarProd)>maxDotProd){
      indMax=i;
      maxDotProd=fabs(scalarProd);
    }
  }
  double scalarP=0.0;
  hxtOr3DdotProd(normal,dir+3*indMax,3, &scalarP);
  if(scalarP<0)
    sign=-1.0;
  else
    sign=1.0;
  for(int i=0;i<3;i++)
    newDir[2*3+i]=sign*dir[3*indMax+i];
  for(int i=0;i<3;i++)
    newDir[i]=sign*dir[3*((indMax+1)%3)+i];
  for(int i=0;i<3;i++)
    newDir[3+i]=dir[3*((indMax+2)%3)+i];
  for(int i=0;i<9;i++)
    dir[i]=newDir[i];
  return HXT_STATUS_OK;
}

HXTStatus orderForDBG3refDir(double *dirRef){ //keep
  int ind=0;
  int indDirPrincipale=2;
  double minValue=5.0;
  for(int i=0;i<3;i++){
    double *u=dirRef+3*i;
    if(fabs(fabs(u[indDirPrincipale])-1)<minValue){
      ind = i;
      minValue=fabs(fabs(u[indDirPrincipale])-1);
    }
  }
  double sign=1.0;
  if(dirRef[3*ind+indDirPrincipale]<0)
    sign=-1.0;
  
  double newDir[9]={0.0};
  for(int i=0;i<3;i++)
    newDir[6+i]=sign*dirRef[3*ind+i];
  for(int i=0;i<3;i++)
    newDir[i]=sign*dirRef[3*((ind+1)%3)+i];
  for(int i=0;i<3;i++)
    newDir[3+i]=dirRef[3*((ind+2)%3)+i];
  for(int i=0;i<9;i++)
    dirRef[i]=newDir[i];
  return HXT_STATUS_OK;
}

HXTStatus getBranchMapElemTri(HXTMesh *mesh, double *dirElem, double *frames, int iel, int branchMapElem[4][3]){ //keep
  for(int k=0;k<3;k++){
    double *frameK=frames+9*mesh->triangles.node[3*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    for(int i=0;i<3;i++){
      double maxScalar=-1.0;
      double *branchToMap=dirElem+9*k+3*i;
      for(int lref=0;lref<3;lref++){
	double *branchRef=dirK+3*lref;
	double scalar=0.0;
	hxtOr3DdotProd(branchToMap,branchRef,3, &scalar);
	if(fabs(scalar)>maxScalar){
	  maxScalar=fabs(scalar);
	  branchMapElem[k][i]=lref;
	}
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus assembleScalingSysAllFree(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *rhs){ //keep
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  for(uint32_t i=0;i<3*mesh->vertices.num;i++){
    rhs[i]=0.0;
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    double localMatrix[(4*3)*(4*3)]={0.0};
    double localRhs[4*3]={0.0};
    double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
    int nG=1;
    double *xG;
    HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
    double *wG;
    HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
    getGauss(nG, xG, wG);
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frameElem, stableDir, refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    hxtOr3DcheckIfBasisDirect(refDir);
    /* /\* //DBG HARD *\/ */
    double dirRadiale[3]={0.0,0.0,1.0};
    hxtNormalizeV(dirRadiale, 3);
    //
    orderForDBG3refDir(refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    hxtOr3DcheckIfBasisDirect(refDir);
    /* // */
    double eulerElem[3*4]={0.0};
    double dirElem[9*4]={0.0};
    for(int i=0;i<9;i++){
      dirElem[i]=refDir[i];
    }
    for(int k=1;k<4;k++){
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      hxtOr3DmakeOrientationDirect(dirK);
      hxtOr3DliftBasis(refDir,dirK);
      hxtOr3DcheckIfBasisDirect(dirK);
      for(int i=0;i<9;i++){
	dirElem[9*k+i]=dirK[i];
      }
    }
    
    uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
    const double dphi[4][3] = {
      {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
      {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
      {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
      {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
    };
    int flagLoc=1;
    hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
    /* int nRot=0; */
    /* while(flagLoc){ */
    /*   nRot++; */
    /*   if(nRot>2){ */
    /*   	printf("ups to many rot needed\n"); */
    /*   	exit(0); */
    /*   	break; */
    /*   } */
    /*   rotateDirElemTet(dirElem); */
    /*   hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc); */
    /* } */
    /* if(flagLoc){ */
    /*   printf("hum, seem no way to do a rotation to remove no nutation\n"); */
    /*   exit(0); */
    /* } */
    double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
    for(int k=0;k<4;k++){
      getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      double diffTest[3*3]={0.0};//ICI
      for(int j=0;j<3;j++){
    	diffTest[j]=dirElem[9*k+j]-u[j];
    	diffTest[3+j]=dirElem[9*k+3+j]-v[j];
    	diffTest[6+j]=dirElem[9*k+6+j]-w[j];
      }
      double normDiff=0.0;
      hxtNorm2V(diffTest, 9, &normDiff);
      if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
	/* printf("entertest\n"); */
	if(normDiff>1e-2){
	  printf("on node %i\n",k);
	  printf("normDiff : %g\n",normDiff);
	  printf("ok pb ici: normDiff = %g\n",normDiff);
	  printf("euler :\n");
	  printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
	  printf("u:\n");
	  printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
	  printf("uRebuilt:\n");
	  printf("%g %g %g\n",u[0],u[1],u[2]);
	  printf("uRef:\n");
	  printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
	  printf("v:\n");
	  printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
	  printf("vRebuilt:\n");
	  printf("%g %g %g\n",v[0],v[1],v[2]);
	  printf("vRef:\n");
	  printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
	  printf("w:\n");
	  printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
	  printf("wRebuilt:\n");
	  printf("%g %g %g\n",w[0],w[1],w[2]);
	  printf("wRef:\n");
	  printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
	  exit(0);
	}
      }
    }
    int branchMap[4][3];
    getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
    //ICI test branch map working properly
    for(int k=0;k<4;k++){
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      for(int i=0;i<3;i++){
    	double *branchLocKI=dirElem+9*k+3*i;
    	double *branchGlobKI = dirK+3*branchMap[k][i];
    	double diffTest[3]={0.0};
    	hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
    	double normDiff=0.0;
    	hxtNorm2V(diffTest, 3, &normDiff);
    	if(normDiff>1e-10){
    	  printf("pb branch map\n");
    	  printf("branch loc :\n");
    	  printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
    	  printf("branch glob :\n");
    	  printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
    	  exit(0);
    	}
      }
    }
    //
    
    double psiElem[4]={0.0};
    double thetaElem[4]={0.0};
    double phiElem[4]={0.0};    
    for(int k=0;k<4;k++){
      psiElem[k]=eulerElem[3*k+0];
      thetaElem[k]=eulerElem[3*k+1];
      phiElem[k]=eulerElem[3*k+2];
    }

    //Loop on gauss points
    for(int iG=0;iG<nG;iG++){
      double frameG[9]={0.0};
      for(int k=0;k<9;k++)
	for(int l=0;l<4;l++)
	  frameG[k]+=frames[9*mesh->tetrahedra.node[4*iel+l]+k]*lagBasisTet(l,xG+3*iG);
      double dirG[9]={0.0};
      double stableDirG[3]={0.0};
      hxtOr3DframeToDirections(frameG, stableDirG, dirG);
      hxtOr3DmakeOrientationDirect(dirG);
      hxtOr3DcheckIfBasisDirect(dirG);
      hxtOr3DliftBasis(refDir,dirG);
      hxtOr3DmakeOrientationDirect(dirG);
      hxtOr3DcheckIfBasisDirect(dirG);
      double AL[3][3]={{0.0}};
      double AM[3][3]={{0.0}};
      double Aphi[3][3]={{0.0}};
      double Atheta[3][3]={{0.0}};
      double Apsi[3][3]={{0.0}};
      double BL[3][3]={{0.0}};
      double BN[3][3]={{0.0}};
      double Bphi[3][3]={{0.0}};
      double Btheta[3][3]={{0.0}};
      double Bpsi[3][3]={{0.0}};
      double CM[3][3]={{0.0}};
      double CN[3][3]={{0.0}};
      double Cphi[3][3]={{0.0}};
      double Ctheta[3][3]={{0.0}};
      double Cpsi[3][3]={{0.0}};
      double eulerG[3]={0.0};
      for(int k=0;k<3;k++)
      	for(int l=0;l<4;l++)
      	  eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
      //ICI

      getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      for(int j=0;j<3;j++){
	dirG[j]=u[j];
	dirG[3+j]=v[j];
	dirG[6+j]=w[j];
      }
      computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
      double a[3]={0.0};
      double b[3]={0.0};
      double c[3]={0.0};
      for (int i = 0; i < 3; ++i){
	for (int j = 0; j < 3; ++j){
	  for (int k = 0; k < 4; ++k){
	    a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	    b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k]; //last one
	    /* b[i]+=0.0; //removed [u,w] */
	    c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k]; //last one
	    /* c[i]+=0.0; //removed [v,w] */
	  }
	}
      }
      double localMatLaplace[16]={0.0}; //DBGSmooth
      double localMatUU[16]={0.0};
      double localMatUV[16]={0.0};
      double localMatUW[16]={0.0};
      double localMatVU[16]={0.0};
      double localMatVV[16]={0.0};
      double localMatVW[16]={0.0};
      double localMatWU[16]={0.0};
      double localMatWV[16]={0.0};
      double localMatWW[16]={0.0};
      double localRhsU[4]={0.0};
      double localRhsV[4]={0.0};
      double localRhsW[4]={0.0};
      /* int isTetSing=0; */
      /* for (int k = 0; k < 4; k++){ */
      /* 	double qual=0.0; */
      /* 	double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k]; */
      /* 	hxtOr3DcomputeQuality(frameK, &qual); */
      /* 	if(qual>10) */
      /* 	  isTetSing=1; */
      /* } */
      
      if(0){
	printf("tetsing sysallfree\n");
	exit(0);
	  for (int i = 0; i < 4; ++i)
	    for (int j = 0; j < 4; ++j)
	      for (int k = 0; k < 3; ++k){
		localMatLaplace[4*i+j]+= dphi[i][k]*dphi[j][k]*detj*wG[iG]; //DBGSmooth
		for (int l = 0; l < 3; ++l)
		  for (int m = 0; m < 3; ++m){
		    /* localMatUU[4*i+j]+= dphi[i][k]*(AL[l][k]*AL[l][m]+BL[l][k]*BL[l][m])*dphi[j][m]*detj*wG[iG]; */
		    localMatUU[4*i+j]+= dphi[i][k]*((AL[l][k]+AM[l][k])*(AL[l][m]+AM[l][m])+BL[l][k]*BL[l][m])*dphi[j][m]*detj*wG[iG];//HARD DBG
		    /* localMatUV[4*i+j]+= dphi[i][k]*AL[l][k]*AM[l][m]*dphi[j][m]*detj*wG[iG]; */
		    localMatUW[4*i+j]+= dphi[i][k]*BL[l][k]*BN[l][m]*dphi[j][m]*detj*wG[iG];

		    /* localMatVU[4*i+j]+= dphi[i][k]*AM[l][k]*AL[l][m]*dphi[j][m]*detj*wG[iG]; */
		    /* localMatVV[4*i+j]+= dphi[i][k]*(AM[l][k]*AM[l][m]+CM[l][k]*CM[l][m])*dphi[j][m]*detj*wG[iG]; */
		    localMatVV[4*i+j]+= dphi[i][k]*((AL[l][k]+AM[l][k])*(AL[l][m]+AM[l][m])+CM[l][k]*CM[l][m])*dphi[j][m]*detj*wG[iG];//HARD DBG
		    localMatVW[4*i+j]+= dphi[i][k]*CM[l][k]*CN[l][m]*dphi[j][m]*detj*wG[iG];

		    localMatWU[4*i+j]+= dphi[i][k]*BN[l][k]*BL[l][m]*dphi[j][m]*detj*wG[iG];
		    localMatWV[4*i+j]+= dphi[i][k]*CN[l][k]*CM[l][m]*dphi[j][m]*detj*wG[iG];
		    localMatWW[4*i+j]+= dphi[i][k]*(BN[l][k]*BN[l][m]+CN[l][k]*CN[l][m])*dphi[j][m]*detj*wG[iG];
		  }
	      }
      
	for (int j = 0; j < 4; ++j)
	  for (int k = 0; k < 3; ++k)
	    for (int l = 0; l < 3; ++l){
	      localRhsU[j]+= dphi[j][k]*(AL[l][k]*a[l]+BL[l][k]*b[l])*detj*wG[iG];
	      localRhsV[j]+= dphi[j][k]*(AM[l][k]*a[l]+CM[l][k]*c[l])*detj*wG[iG];
	      localRhsW[j]+= dphi[j][k]*(BN[l][k]*b[l]+CN[l][k]*c[l])*detj*wG[iG];
	    }
      }
      else{
	for (int i = 0; i < 4; ++i)
	  for (int j = 0; j < 4; ++j)
	    for (int k = 0; k < 3; ++k){
	      localMatLaplace[4*i+j]+= dphi[i][k]*dphi[j][k]*detj*wG[iG]; //DBGSmooth
	      for (int l = 0; l < 3; ++l)
		for (int m = 0; m < 3; ++m){
		  localMatUU[4*i+j]+= dphi[i][k]*(AL[l][k]*AL[l][m]+BL[l][k]*BL[l][m])*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatUU[4*i+j]+= dphi[i][k]*(AL[l][k]*AL[l][m])*dphi[j][m]*detj*wG[iG]; //removed [u,w] */
		  localMatUV[4*i+j]+= dphi[i][k]*AL[l][k]*AM[l][m]*dphi[j][m]*detj*wG[iG];
		  localMatUW[4*i+j]+= dphi[i][k]*BL[l][k]*BN[l][m]*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatUW[4*i+j]+=0.0;//removed [u,w] */
		  
		  localMatVU[4*i+j]+= dphi[i][k]*AM[l][k]*AL[l][m]*dphi[j][m]*detj*wG[iG];
		  localMatVV[4*i+j]+= dphi[i][k]*(AM[l][k]*AM[l][m]+CM[l][k]*CM[l][m])*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatVV[4*i+j]+= dphi[i][k]*(AM[l][k]*AM[l][m])*dphi[j][m]*detj*wG[iG]; //removed [v,w] */
		  localMatVW[4*i+j]+= dphi[i][k]*CM[l][k]*CN[l][m]*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatVW[4*i+j]+= 0.0; //removed [v,w] */

		  localMatWU[4*i+j]+= dphi[i][k]*BN[l][k]*BL[l][m]*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatWU[4*i+j]+= 0.0; //removed [u,w] */
		  localMatWV[4*i+j]+= dphi[i][k]*CN[l][k]*CM[l][m]*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatWV[4*i+j]+= 0.0; //removed [v,w] */
		  localMatWW[4*i+j]+= dphi[i][k]*(BN[l][k]*BN[l][m]+CN[l][k]*CN[l][m])*dphi[j][m]*detj*wG[iG]; //last one
		  /* localMatWW[4*i+j]+= dphi[i][k]*(CN[l][k]*CN[l][m])*dphi[j][m]*detj*wG[iG]; //removed [u,w] */
		  /* localMatWW[4*i+j]+= dphi[i][k]*(BN[l][k]*BN[l][m])*dphi[j][m]*detj*wG[iG]; //removed [v,w] */
		  /* localMatWW[4*i+j]+= 0.0; //removed [u,w] and [v,w] */
		}
	    }
      
	for (int j = 0; j < 4; ++j)
	  for (int k = 0; k < 3; ++k)
	    for (int l = 0; l < 3; ++l){
	      localRhsU[j]+= dphi[j][k]*(AL[l][k]*a[l]+BL[l][k]*b[l])*detj*wG[iG];
	      localRhsV[j]+= dphi[j][k]*(AM[l][k]*a[l]+CM[l][k]*c[l])*detj*wG[iG];
	      localRhsW[j]+= dphi[j][k]*(BN[l][k]*b[l]+CN[l][k]*c[l])*detj*wG[iG];
	    }

      }
      
      /* double penality = 0.0; //DBGSmooth */
      for (int k = 0; k < 4; ++k){
	int iu=branchMap[k][0];
	int iv=branchMap[k][1];
	int iw=branchMap[k][2];
	localRhs[4*iu+k]+= localRhsU[k];
	localRhs[4*iv+k]+= localRhsV[k];
	localRhs[4*iw+k]+= localRhsW[k];

	for (int l = 0; l < 4; ++l){
	  int ju=branchMap[l][0];
	  int jv=branchMap[l][1];
	  int jw=branchMap[l][2];
	  /* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	  localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	  localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l];
	  localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l];
	  localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l];
	  localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	  localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l];
	  localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l];
	  localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l];
	  localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
	}
      }
      volume+=detj*wG[iG];
    }//end loop on gauss points
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
    hxtFree(&xG);
    hxtFree(&wG);
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalErrorScalingSmart(HXTMesh *mesh, double *frames, uint64_t iel, double *localScaling, double *errorElem, double *volumeElem){ //keep
  double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(frameElem, stableDir, refDir);
  /* printf("base before making it direct\n"); */
  /* hxtOr3DprintBase(refDir); */
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag -1\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* /\* /\\* //DBG HARD *\\/ *\/ */
  /* double dirRadiale[3]={0.0,0.0,1.0}; */
  /* hxtNormalizeV(dirRadiale, 3); */
  /* // */
  /* orderForDBG3refDir(refDir); */
  /* hxtOr3DmakeOrientationDirect(refDir); */
  /* /\* printf("flag 0\n"); *\/ */
  /* hxtOr3DcheckIfBasisDirect(refDir); */
  /* /\* // *\/ */
  double eulerElem[3*4]={0.0};
  double dirElem[9*4]={0.0};
  for(int i=0;i<9;i++){
    dirElem[i]=refDir[i];
  }
  for(int k=1;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    hxtOr3DmakeOrientationDirect(dirK);
    hxtOr3DliftBasis(refDir,dirK);
    /* printf("flag 1\n"); */
    hxtOr3DcheckIfBasisDirect(dirK);
    for(int i=0;i<9;i++){
      dirElem[9*k+i]=dirK[i];
    }
  }
    
  uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
  const double dphi[4][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  int flagLoc=1;
  hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  int nRot=0;
  while(flagLoc){
    nRot++;
    if(nRot>2){
      printf("ups to many rot needed\n");
      exit(0);
      break;
    }
    rotateDirElemTet(dirElem);
    hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  }
  if(flagLoc){
    printf("hum, seem no way to do a rotation to remove no nutation\n");
    exit(0);
  }
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  for(int k=0;k<4;k++){
    getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    double diffTest[3*3]={0.0};//ICI
    for(int j=0;j<3;j++){
      diffTest[j]=dirElem[9*k+j]-u[j];
      diffTest[3+j]=dirElem[9*k+3+j]-v[j];
      diffTest[6+j]=dirElem[9*k+6+j]-w[j];
    }
    double normDiff=0.0;
    hxtNorm2V(diffTest, 9, &normDiff);
    if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
      /* printf("entertest\n"); */
      if(normDiff>1e-2){
  	printf("on node %i\n",k);
  	printf("normDiff : %g\n",normDiff);
  	printf("ok pb ici: normDiff = %g\n",normDiff);
  	printf("euler :\n");
  	printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
  	printf("u:\n");
  	printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
  	printf("uRebuilt:\n");
  	printf("%g %g %g\n",u[0],u[1],u[2]);
  	printf("uRef:\n");
  	printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
  	printf("v:\n");
  	printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
  	printf("vRebuilt:\n");
  	printf("%g %g %g\n",v[0],v[1],v[2]);
  	printf("vRef:\n");
  	printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
  	printf("w:\n");
  	printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
  	printf("wRebuilt:\n");
  	printf("%g %g %g\n",w[0],w[1],w[2]);
  	printf("wRef:\n");
  	printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
  	exit(0);
      }
    }
  }
  int branchMap[4][3];
  getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
  //ICI test branch map working properly
  for(int k=0;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    for(int i=0;i<3;i++){
      double *branchLocKI=dirElem+9*k+3*i;
      double *branchGlobKI = dirK+3*branchMap[k][i];
      double diffTest[3]={0.0};
      hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
      double normDiff=0.0;
      hxtNorm2V(diffTest, 3, &normDiff);
      if(normDiff>1e-10){
  	printf("pb branch map\n");
  	printf("branch loc :\n");
  	printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
  	printf("branch glob :\n");
  	printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
  	exit(0);
      }
    }
  }
  //
    
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }

  /* //DBG check norm grad theta */
  /* double gradTheta[3]={0.0}; */
  /* for(int i=0;i<3;i++) */
  /*   for(int k=0;k<4;k++) */
  /* 	gradTheta[i]+=dphi[k][i]*phiElem[k]; */
  /* double normGradTheta=0.0; */
  /* hxtNorm2V(gradTheta+2, 1, &normGradTheta); */
  /* if(normGradTheta>1e-1){ */
  /*   printf("normGradTheta : %g\n",normGradTheta); */
  /*   printf("thetaElem: \n"); */
  /*   for(int k=0;k<4;k++) */
  /* 	printf(" %g /",phiElem[k]); */
  /*   printf("\n"); */
  /*   exit(0); */
  /* } */
  /* //DBG check sin(theta) */
  /* double maxSin=0.0; */
  /* for(int k=0;k<4;k++) */
  /*   if(fabs(sin(thetaElem[k]))>maxSin) */
  /* 	maxSin=fabs(sin(thetaElem[k])); */
  /* if(maxSin>1e-2){ */
  /*   printf("maxSin : %g\n",maxSin); */
  /*   exit(0); */
  /* } */
  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double frameG[9]={0.0};
    for(int k=0;k<9;k++)
      for(int l=0;l<4;l++)
  	frameG[k]+=frames[9*mesh->tetrahedra.node[4*iel+l]+k]*lagBasisTet(l,xG+3*iG);
    double dirG[9]={0.0};
    double stableDirG[3]={0.0};
    hxtOr3DframeToDirections(frameG, stableDirG, dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 2\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    hxtOr3DliftBasis(refDir,dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 3\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    double AL[3][3]={{0.0}};
    double AM[3][3]={{0.0}};
    double Aphi[3][3]={{0.0}};
    double Atheta[3][3]={{0.0}};
    double Apsi[3][3]={{0.0}};
    double BL[3][3]={{0.0}};
    double BN[3][3]={{0.0}};
    double Bphi[3][3]={{0.0}};
    double Btheta[3][3]={{0.0}};
    double Bpsi[3][3]={{0.0}};
    double CM[3][3]={{0.0}};
    double CN[3][3]={{0.0}};
    double Cphi[3][3]={{0.0}};
    double Ctheta[3][3]={{0.0}};
    double Cpsi[3][3]={{0.0}};
    double eulerG[3]={0.0};
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
  	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    //ICI

    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    for(int j=0;j<3;j++){
      dirG[j]=u[j];
      dirG[3+j]=v[j];
      dirG[6+j]=w[j];
    }
    computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
    double a[3]={0.0};
    double b[3]={0.0};
    double c[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
  	for (int k = 0; k < 4; ++k){
  	  a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
  	  b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
  	  c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
  	}
      }
    }
    double ua=0.0;
    double va=0.0;
    double ub=0.0;
    double wb=0.0;
    double vc=0.0;
    double wc=0.0;
    hxtOr3DdotProd(u,a,3, &ua);
    hxtOr3DdotProd(v,a,3, &va);
    hxtOr3DdotProd(u,b,3, &ub);
    hxtOr3DdotProd(w,b,3, &wb);
    hxtOr3DdotProd(v,c,3, &vc);
    hxtOr3DdotProd(w,c,3, &wc);
    double uAL[3]={0.0};
    double vAM[3]={0.0};
    double uBL[3]={0.0};
    double wBN[3]={0.0};
    double vCM[3]={0.0};
    double wCN[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int k = 0; k < 3; ++k){
  	uAL[i]+=u[k]*AL[k][i];
  	vAM[i]+=v[k]*AM[k][i];
  	uBL[i]+=u[k]*BL[k][i];
  	wBN[i]+=w[k]*BN[k][i];
  	vCM[i]+=v[k]*CM[k][i];
  	wCN[i]+=w[k]*CN[k][i];
      }
    }
      
    double localMatUU[16]={0.0};
    /* double localMatUV[16]={0.0}; */
    /* double localMatUW[16]={0.0}; */
    /* double localMatVU[16]={0.0}; */
    double localMatVV[16]={0.0};
    /* double localMatVW[16]={0.0}; */
    /* double localMatWU[16]={0.0}; */
    /* double localMatWV[16]={0.0}; */
    double localMatWW[16]={0.0};
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>10)
  	isTetSing=1;
    }
    if(!isTetSing){
      for (int i = 0; i < 4; ++i)
  	for (int j = 0; j < 4; ++j)
  	  for (int k = 0; k < 3; ++k){
  	    for (int m = 0; m < 3; ++m){
  	      localMatUU[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m])*dphi[j][m]*detj*wG[iG];
  	      localMatVV[4*i+j]+= dphi[i][k]*(vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG];
  	      localMatWW[4*i+j]+= dphi[i][k]*(wBN[k]*wBN[m]+wCN[k]*wCN[m])*dphi[j][m]*detj*wG[iG];
  	    }
  	  }
      
      for (int j = 0; j < 4; ++j)
  	for (int k = 0; k < 3; ++k){
  	  localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG];
  	  localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG];
  	  localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG];
  	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb)*detj*wG[iG]; */
  	  /* localRhsW[j]+= dphi[j][k]*(wCN[k]*wc)*detj*wG[iG]; */
  	}
    }
      
      
    double localMatrix[(4*3)*(4*3)]={0.0};
    double localRhs[4*3]={0.0};
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      localRhs[4*iu+k]+= localRhsU[k];
      localRhs[4*iv+k]+= localRhsV[k];
      localRhs[4*iw+k]+= localRhsW[k];

      for (int l = 0; l < 4; ++l){
	int ju=branchMap[l][0];
	int jv=branchMap[l][1];
	int jw=branchMap[l][2];
	/* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	/* localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l]; */
	/* localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l]; */
	/* localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l]; */
	localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	/* localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l]; */
	/* localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l]; */
	/* localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l]; */
	localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
      }
    }
    *errorElem=0.0;
    for (int k = 0; k < 4*3; ++k)
      for (int l = 0; l < 4*3; ++l)
	*errorElem+=localScaling[k]*localMatrix[12*k+l]*localScaling[l];
    for (int k = 0; k < 4*3; ++k)
      *errorElem-=2*localScaling[k]*localRhs[k];
    *errorElem+=(ua*ua+ub*ub+va*va+vc*vc+wb*wb+wc*wc)*detj*wG[iG];
    *errorElem=0.5*(*errorElem);
    *volumeElem=detj*wG[iG];
    /* volume+=detj*wG[iG]; */
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalErrorScalingSmart2(HXTOrientation3DScal *or3D, uint64_t iel, double *localScaling, double *errorElem, double *volumeElem){ //keep
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  for(int iG=0;iG<nG;iG++){
    int branchMap[4][3]={{0.0}};
    for(int k=0;k<4;k++)
      for(int j=0;j<3;j++)
	branchMap[k][j]=or3D->branchMapElem[4*3*iel+3*k+j];
    double detj=or3D->detj[iel];
    double localMatrix[(4*3)*(4*3)]={0.0};
    double localRhs[4*3]={0.0};
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      localRhs[4*iu+k]= or3D->localRhsU[4*iel+k];
      localRhs[4*iv+k]= or3D->localRhsV[4*iel+k];
      localRhs[4*iw+k]= or3D->localRhsW[4*iel+k];

      for (int l = 0; l < 4; ++l){
	int ju=branchMap[l][0];
	int jv=branchMap[l][1];
	int jw=branchMap[l][2];
	localMatrix[12*(k+4*iu)+l+4*ju] = or3D->localMatUU[4*4*iel+4*k+l];
	localMatrix[12*(k+4*iv)+l+4*jv] = or3D->localMatVV[4*4*iel+4*k+l];
	localMatrix[12*(k+4*iw)+l+4*jw] = or3D->localMatWW[4*4*iel+4*k+l];
      }
    }
    *errorElem=0.0;
    for (int k = 0; k < 4*3; ++k)
      for (int l = 0; l < 4*3; ++l)
	*errorElem+=localScaling[k]*localMatrix[12*k+l]*localScaling[l];
    for (int k = 0; k < 4*3; ++k)
      *errorElem-=2*localScaling[k]*localRhs[k];
    *errorElem+=or3D->squareTermErrorRhs[iel];
    *errorElem=0.5*(*errorElem);
    *volumeElem=detj*wG[iG];
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpDBG2DRect(HXTMesh *mesh, uint64_t iel, double gradXValTri, double *localMatrix, double *localRhs, double *volumeElem){
  uint32_t *tri = mesh->triangles.node+iel*3;
  double x[3][2]={{0.0}};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      x[i][j] = mesh->vertices.coord[4*tri[i]+j];

  double dxdxi[2][2];
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      dxdxi[j][i] = x[i+1][j] - x[0][j];
  double dxidx[2][2];
  double detj;
  HXT_CHECK(hxtInv2x2(dxdxi, dxidx, &detj));
  detj=fabs(detj);
  const double dphi[3][2] = {
    {-dxidx[0][0]-dxidx[1][0],-dxidx[0][1]-dxidx[1][1]},
    {dxidx[0][0],dxidx[0][1]},
    {dxidx[1][0],dxidx[1][1]}
  };
  double xG[2]={(x[0][0]+x[1][0]+x[2][0])/3.,(x[0][1]+x[1][1]+x[2][1])/3.};
  double l=1.0;
  double L=3.0;
  double gradMax=1.0;
  double gradMaxX=(xG[0]-L/3.)*(xG[0]-L/3.)*(-6*xG[0]/L+5.)*9.*gradMax/(L*L);
  /* double dXgradMaxX=2*(xG[0]-L/3.)*(-6*xG[0]/L+5.)*9.*gradMax/(L*L) + (xG[0]-L/3.)*(xG[0]-L/3.)*(-6./L)*9.*gradMax/(L*L); */
  /* double xa=0.0; */
  double ya=0.0;
  if(xG[0]<L/3.){
    /* xa=0.0; */
    ya=0.0;
  }
  else if((xG[0]>=L/3.)&&(xG[0]<2.*L/3.)){
    /* xa=-(xG[1]-l/2.)*(xG[1]-l/2.)*(1./l)*dXgradMaxX + (l*l/4.)*dXgradMaxX/3.; */
    ya=(l/2.-xG[1])*(2./l)*gradMaxX;
  }
  else if(xG[0]>=2.*L/3.){
    /* xa=0.0; */
    ya=(l/2.-xG[1])*(2./l)*gradMax;
  }
  else{
    printf("pb on splitting the domain properly\n");
    exit(0);
  }
      
  for (int j = 0; j < 3; ++j)
    for (int k = 0; k < 3; ++k)
      localMatrix[3*j+k]=0.0;

  double penalty = 1.0;
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      localMatrix[3*i+j]+= (penalty*dphi[i][0]*dphi[j][0]+dphi[i][1]*dphi[j][1])*detj*0.5;
      /* localMatrix[3*i+j]+= (dphi[i][1]*dphi[j][1])*detj*0.5; */

  for (int k = 0; k < 3; ++k)  
    localRhs[k] = 0.0;

  for (int j = 0; j < 3; ++j)
    localRhs[j]+= (dphi[j][0]*gradXValTri+dphi[j][1]*ya)*detj*0.5;
      /* localRhs[j]+= dphi[j][1]*ya*detj*0.5; */

  *volumeElem=detj*0.5;
  /* volume+=detj*wG[iG]; */
  //end loop on gauss points
  /* hxtFree(&xG); */
  /* hxtFree(&wG); */
  return HXT_STATUS_OK;
}

HXTStatus computeGradXTri(HXTMesh *mesh, double *scalarField, double *gradXTri){ //to remove
  for(uint32_t iel=0;iel<mesh->triangles.num;iel++){
    uint32_t *tri = mesh->triangles.node+iel*3;
    double x[3][2]={{0.0}};
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 2; j++)
	x[i][j] = mesh->vertices.coord[4*tri[i]+j];

    double dxdxi[2][2];
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
	dxdxi[j][i] = x[i+1][j] - x[0][j];
    double dxidx[2][2];
    double detj;
    HXT_CHECK(hxtInv2x2(dxdxi, dxidx, &detj));
    detj=fabs(detj);
    const double dphi[3][2] = {
      {-dxidx[0][0]-dxidx[1][0],-dxidx[0][1]-dxidx[1][1]},
      {dxidx[0][0],dxidx[0][1]},
      {dxidx[1][0],dxidx[1][1]}
    };
    gradXTri[iel]=0.0;
    for(int k = 0; k<3; k++)
      gradXTri[iel]+=dphi[k][0]*scalarField[tri[k]];
  }
  return HXT_STATUS_OK;
}

HXTStatus computeLocalErrorDBG2DRect(HXTMesh *mesh, uint64_t iel, double *localScaling, double *errorElem, double *volumeElem){
  uint32_t *tri = mesh->triangles.node+iel*3;
  double x[3][2]={{0.0}};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++)
      x[i][j] = mesh->vertices.coord[4*tri[i]+j];

  double dxdxi[2][2];
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      dxdxi[j][i] = x[i+1][j] - x[0][j];
  double dxidx[2][2];
  double detj;
  HXT_CHECK(hxtInv2x2(dxdxi, dxidx, &detj));
  detj=fabs(detj);
  const double dphi[3][2] = {
    {-dxidx[0][0]-dxidx[1][0],-dxidx[0][1]-dxidx[1][1]},
    {dxidx[0][0],dxidx[0][1]},
    {dxidx[1][0],dxidx[1][1]}
  };
  double xG[2]={(x[0][0]+x[1][0]+x[2][0])/3.,(x[0][1]+x[1][1]+x[2][1])/3.};
  double l=1.0;
  double L=3.0;
  double gradMax=1.0;
  double gradMaxX=(xG[0]-L/3.)*(xG[0]-L/3.)*(-6*xG[0]/L+5.)*9.*gradMax/(L*L);
  double ya=0.0;
  if(xG[0]<L/3.)
    ya=0.0;
  else if((xG[0]>=L/3.)&&(xG[0]<2.*L/3.))
    ya=(l/2.-xG[1])*(2./l)*gradMaxX;
  else if(xG[0]>=2.*L/3.)
    ya=(l/2.-xG[1])*(2./l)*gradMax;
  else{
    printf("pb on splitting the domain properly\n");
    exit(0);
  }
  double gradG[2]={0.0};
  for (int i = 0; i < 2; ++i)
    for (int k = 0; k < 3; ++k)
      gradG[i]+=dphi[k][i]*localScaling[k];
  *errorElem=0.5*(gradG[1]-ya)*(gradG[1]-ya)*detj*0.5;
  *volumeElem=detj*0.5;
  /* volume+=detj*wG[iG]; */
  //end loop on gauss points
  /* hxtFree(&xG); */
  /* hxtFree(&wG); */
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpScalingSmart(HXTMesh *mesh, double *frames, uint64_t iel, double *localMatrix, double *localRhs, double *volumeElem, int branchMap[4][3]){ //keep
  double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(frameElem, stableDir, refDir);
  /* printf("base before making it direct\n"); */
  /* hxtOr3DprintBase(refDir); */
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag -1\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* /\* //DBG HARD *\/ */
  double dirRadiale[3]={0.0,0.0,1.0};
  hxtNormalizeV(dirRadiale, 3);
  //
  orderForDBG3refDir(refDir);
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag 0\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* // */
  double eulerElem[3*4]={0.0};
  double dirElem[9*4]={0.0};
  for(int i=0;i<9;i++){
    dirElem[i]=refDir[i];
  }
  for(int k=1;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    hxtOr3DmakeOrientationDirect(dirK);
    hxtOr3DliftBasis(refDir,dirK);
    /* printf("flag 1\n"); */
    hxtOr3DcheckIfBasisDirect(dirK);
    for(int i=0;i<9;i++){
      dirElem[9*k+i]=dirK[i];
    }
  }
    
  uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
  const double dphi[4][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  int flagLoc=1;
  hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  int nRot=0;
  while(flagLoc){
    nRot++;
    if(nRot>2){
      printf("ups to many rot needed\n");
      exit(0);
      break;
    }
    rotateDirElemTet(dirElem);
    hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  }
  if(flagLoc){
    printf("hum, seem no way to do a rotation to remove no nutation\n");
    exit(0);
  }
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  for(int k=0;k<4;k++){
    getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    double diffTest[3*3]={0.0};//ICI
    for(int j=0;j<3;j++){
      diffTest[j]=dirElem[9*k+j]-u[j];
      diffTest[3+j]=dirElem[9*k+3+j]-v[j];
      diffTest[6+j]=dirElem[9*k+6+j]-w[j];
    }
    double normDiff=0.0;
    hxtNorm2V(diffTest, 9, &normDiff);
    if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
      /* printf("entertest\n"); */
      if(normDiff>1e-2){
	printf("on node %i\n",k);
	printf("normDiff : %g\n",normDiff);
	printf("ok pb ici: normDiff = %g\n",normDiff);
	printf("euler :\n");
	printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
	printf("u:\n");
	printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
	printf("uRebuilt:\n");
	printf("%g %g %g\n",u[0],u[1],u[2]);
	printf("uRef:\n");
	printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
	printf("v:\n");
	printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
	printf("vRebuilt:\n");
	printf("%g %g %g\n",v[0],v[1],v[2]);
	printf("vRef:\n");
	printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
	printf("w:\n");
	printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
	printf("wRebuilt:\n");
	printf("%g %g %g\n",w[0],w[1],w[2]);
	printf("wRef:\n");
	printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
	exit(0);
      }
    }
  }
  /* int branchMap[4][3]; */
  getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
  //ICI test branch map working properly
  for(int k=0;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    for(int i=0;i<3;i++){
      double *branchLocKI=dirElem+9*k+3*i;
      double *branchGlobKI = dirK+3*branchMap[k][i];
      double diffTest[3]={0.0};
      hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
      double normDiff=0.0;
      hxtNorm2V(diffTest, 3, &normDiff);
      if(normDiff>1e-10){
	printf("pb branch map\n");
	printf("branch loc :\n");
	printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
	printf("branch glob :\n");
	printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
	exit(0);
      }
    }
  }
  //
    
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};    
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }

  /* //DBG check norm grad theta */
  /* double gradTheta[3]={0.0}; */
  /* for(int i=0;i<3;i++) */
  /*   for(int k=0;k<4;k++) */
  /* 	gradTheta[i]+=dphi[k][i]*phiElem[k]; */
  /* double normGradTheta=0.0; */
  /* hxtNorm2V(gradTheta+2, 1, &normGradTheta); */
  /* if(normGradTheta>1e-1){ */
  /*   printf("normGradTheta : %g\n",normGradTheta); */
  /*   printf("thetaElem: \n"); */
  /*   for(int k=0;k<4;k++) */
  /* 	printf(" %g /",phiElem[k]); */
  /*   printf("\n"); */
  /*   exit(0); */
  /* } */
  /* //DBG check sin(theta) */
  /* double maxSin=0.0; */
  /* for(int k=0;k<4;k++) */
  /*   if(fabs(sin(thetaElem[k]))>maxSin) */
  /* 	maxSin=fabs(sin(thetaElem[k])); */
  /* if(maxSin>1e-2){ */
  /*   printf("maxSin : %g\n",maxSin); */
  /*   exit(0); */
  /* } */
  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double frameG[9]={0.0};
    for(int k=0;k<9;k++)
      for(int l=0;l<4;l++)
	frameG[k]+=frames[9*mesh->tetrahedra.node[4*iel+l]+k]*lagBasisTet(l,xG+3*iG);
    double dirG[9]={0.0};
    double stableDirG[3]={0.0};
    hxtOr3DframeToDirections(frameG, stableDirG, dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 2\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    hxtOr3DliftBasis(refDir,dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 3\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    double AL[3][3]={{0.0}};
    double AM[3][3]={{0.0}};
    double Aphi[3][3]={{0.0}};
    double Atheta[3][3]={{0.0}};
    double Apsi[3][3]={{0.0}};
    double BL[3][3]={{0.0}};
    double BN[3][3]={{0.0}};
    double Bphi[3][3]={{0.0}};
    double Btheta[3][3]={{0.0}};
    double Bpsi[3][3]={{0.0}};
    double CM[3][3]={{0.0}};
    double CN[3][3]={{0.0}};
    double Cphi[3][3]={{0.0}};
    double Ctheta[3][3]={{0.0}};
    double Cpsi[3][3]={{0.0}};
    double eulerG[3]={0.0};
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    //ICI

    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    for(int j=0;j<3;j++){
      dirG[j]=u[j];
      dirG[3+j]=v[j];
      dirG[6+j]=w[j];
    }
    computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
    double a[3]={0.0};
    double b[3]={0.0};
    double c[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
	for (int k = 0; k < 4; ++k){
	  a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	  b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	  c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	}
      }
    }
    double ua=0.0;
    double va=0.0;
    double ub=0.0;
    double wb=0.0;
    double vc=0.0;
    double wc=0.0;
    hxtOr3DdotProd(u,a,3, &ua);
    hxtOr3DdotProd(v,a,3, &va);
    hxtOr3DdotProd(u,b,3, &ub);
    hxtOr3DdotProd(w,b,3, &wb);
    hxtOr3DdotProd(v,c,3, &vc);
    hxtOr3DdotProd(w,c,3, &wc);
    double uAL[3]={0.0};
    double vAM[3]={0.0};
    double uBL[3]={0.0};
    double wBN[3]={0.0};
    double vCM[3]={0.0};
    double wCN[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int k = 0; k < 3; ++k){
	uAL[i]+=u[k]*AL[k][i];
	vAM[i]+=v[k]*AM[k][i];
	uBL[i]+=u[k]*BL[k][i];
	wBN[i]+=w[k]*BN[k][i];
	vCM[i]+=v[k]*CM[k][i];
	wCN[i]+=w[k]*CN[k][i];
      }
    }
      
    double localMatUU[16]={0.0};
    double localMatUV[16]={0.0};
    double localMatUW[16]={0.0};
    double localMatVU[16]={0.0};
    double localMatVV[16]={0.0};
    double localMatVW[16]={0.0};
    double localMatWU[16]={0.0};
    double localMatWV[16]={0.0};
    double localMatWW[16]={0.0};
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>10)
	isTetSing=1;
    }
    if(!isTetSing){
      for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	  for (int k = 0; k < 3; ++k){
	    for (int m = 0; m < 3; ++m){
	      localMatUU[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m])*dphi[j][m]*detj*wG[iG];
	      localMatVV[4*i+j]+= dphi[i][k]*(vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG];
	      localMatWW[4*i+j]+= dphi[i][k]*(wBN[k]*wBN[m]+wCN[k]*wCN[m])*dphi[j][m]*detj*wG[iG];
	    }
	  }
      
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG];
	  localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG];
	  localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG];
	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(wCN[k]*wc)*detj*wG[iG]; */
	}
    }
      
      
    /* double penality = 0.0; //DBGSmooth */
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      localRhs[4*iu+k]+= localRhsU[k];
      localRhs[4*iv+k]+= localRhsV[k];
      localRhs[4*iw+k]+= localRhsW[k];

      for (int l = 0; l < 4; ++l){
	int ju=branchMap[l][0];
	int jv=branchMap[l][1];
	int jw=branchMap[l][2];
	/* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l];
	localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l];
	localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l];
	localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l];
	localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l];
	localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l];
	localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
      }
    }
    *volumeElem=detj*wG[iG];
    /* volume+=detj*wG[iG]; */
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpScalingSmart2(HXTOrientation3DScal *or3D, double *scaling, uint64_t iel, double *localMatrix, double *localRhs, double *volumeElem, double *normGradEulerElem){ //keep
  HXTMesh *mesh=or3D->mesh;
  double *frames=or3D->frames;

  uint32_t *tet = mesh->tetrahedra.node+iel*4;
  double detj=or3D->detj[iel];
  double dphi[4][3]={{0.0}};
  for(int k=0;k<4;k++){
    for(int j=0;j<3;j++){
      dphi[k][j]=or3D->dLdXElem[3*4*iel+3*k+j];
    }
  }

  double *eulerElem=or3D->eulerElem + 4*3*iel;
  int branchMap[4][3]={{0.0}};
  for(int k=0;k<4;k++)
    for(int j=0;j<3;j++)
      branchMap[k][j]=or3D->branchMapElem[4*3*iel+3*k+j];
  
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};    
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }
  double gradPsi[3]={0.0};
  double gradTheta[3]={0.0};
  double gradPhi[3]={0.0};
  for(int k=0;k<4;k++){
    for(int j=0;j<3;j++){
      gradPsi[j]+=dphi[k][j]*psiElem[k];
      gradTheta[j]+=dphi[k][j]*thetaElem[k];
      gradPhi[j]+=dphi[k][j]*phiElem[k];
    }
  }
  *normGradEulerElem=0.0;
  for(int k=0;k<3;k++)
    *normGradEulerElem+=gradPsi[k]*gradPsi[k]+gradTheta[k]*gradTheta[k]+gradPhi[k]*gradPhi[k];
  *normGradEulerElem=sqrt(*normGradEulerElem);
  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double AL[3][3]={{0.0}};
    double AM[3][3]={{0.0}};
    double Aphi[3][3]={{0.0}};
    double Atheta[3][3]={{0.0}};
    double Apsi[3][3]={{0.0}};
    double BL[3][3]={{0.0}};
    double BN[3][3]={{0.0}};
    double Bphi[3][3]={{0.0}};
    double Btheta[3][3]={{0.0}};
    double Bpsi[3][3]={{0.0}};
    double CM[3][3]={{0.0}};
    double CN[3][3]={{0.0}};
    double Cphi[3][3]={{0.0}};
    double Ctheta[3][3]={{0.0}};
    double Cpsi[3][3]={{0.0}};
    double eulerG[3]={0.0};
    double dirG[9]={0.0};
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    for(int j=0;j<3;j++){
      dirG[j]=u[j];
      dirG[3+j]=v[j];
      dirG[6+j]=w[j];
    }
    computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
    double a[3]={0.0};
    double b[3]={0.0};
    double c[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
	for (int k = 0; k < 4; ++k){
	  a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	  b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	  c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	}
      }
    }
    double ua=0.0;
    double va=0.0;
    double ub=0.0;
    double wb=0.0;
    double vc=0.0;
    double wc=0.0;
    hxtOr3DdotProd(u,a,3, &ua);
    hxtOr3DdotProd(v,a,3, &va);
    hxtOr3DdotProd(u,b,3, &ub);
    hxtOr3DdotProd(w,b,3, &wb);
    hxtOr3DdotProd(v,c,3, &vc);
    hxtOr3DdotProd(w,c,3, &wc);
    double uAL[3]={0.0};
    double vAM[3]={0.0};
    double uBL[3]={0.0};
    double wBN[3]={0.0};
    double vCM[3]={0.0};
    double wCN[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int k = 0; k < 3; ++k){
	uAL[i]+=u[k]*AL[k][i];
	vAM[i]+=v[k]*AM[k][i];
	uBL[i]+=u[k]*BL[k][i];
	wBN[i]+=w[k]*BN[k][i];
	vCM[i]+=v[k]*CM[k][i];
	wCN[i]+=w[k]*CN[k][i];
      }
    }
      
    double localMatUU[16]={0.0};
    double localMatVV[16]={0.0};
    double localMatWW[16]={0.0};
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};
    for (int i = 0; i < 16; ++i){
      localMatUU[i]=or3D->localMatUU[16*iel+i]+or3D->localMatPenaltyUU[16*iel+i];
      localMatVV[i]=or3D->localMatVV[16*iel+i]+or3D->localMatPenaltyVV[16*iel+i];
      localMatWW[i]=or3D->localMatWW[16*iel+i]+or3D->localMatPenaltyWW[16*iel+i];
    }
    for (int i = 0; i < 4; ++i){
      localRhsU[i]=or3D->localRhsU[4*iel+i];
      localRhsV[i]=or3D->localRhsV[4*iel+i];
      localRhsW[i]=or3D->localRhsW[4*iel+i];
      or3D->localRhsPenaltyU[i]=0.0;
      or3D->localRhsPenaltyV[i]=0.0;
      or3D->localRhsPenaltyW[i]=0.0;
    }

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>10)
	isTetSing=1;
    }
    if(!isTetSing){
      double gradL[3]={0.0};
      double gradM[3]={0.0};
      double gradN[3]={0.0};
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  int globU=branchMap[j][0];
	  int globV=branchMap[j][1];
	  int globW=branchMap[j][2];
	  gradL[k]+=dphi[j][k]*scaling[3*tet[j]+globU];
	  gradM[k]+=dphi[j][k]*scaling[3*tet[j]+globV];
	  gradN[k]+=dphi[j][k]*scaling[3*tet[j]+globW];
	}
      double gradLu=0.0;
      double gradMv=0.0;
      double gradNw=0.0;
      for (int k = 0; k < 3; ++k){
	gradLu+=gradL[k]*u[k];
	gradMv+=gradM[k]*v[k];
	gradNw+=gradN[k]*w[k];
      }
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  /* localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	  /* localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	  /* //regularization term added */
	  /* localRhsU[j]+= dphi[j][k]*(vAM[k]*gradLu+uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	  /* localRhsV[j]+= dphi[j][k]*(-uAL[k]*gradMv+vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(-uBL[k]*gradNw+wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	  //regularization term added TEST
	  localRhsU[j]+= dphi[j][k]*(u[k]*gradLu)*detj*wG[iG];
	  localRhsV[j]+= dphi[j][k]*(v[k]*gradMv)*detj*wG[iG];
	  localRhsW[j]+= dphi[j][k]*(w[k]*gradNw)*detj*wG[iG];
	  or3D->localRhsPenaltyU[4*iel+j]+=dphi[j][k]*(u[k]*gradLu)*detj*wG[iG];
	  or3D->localRhsPenaltyV[4*iel+j]+=dphi[j][k]*(v[k]*gradMv)*detj*wG[iG];
	  or3D->localRhsPenaltyW[4*iel+j]+=dphi[j][k]*(w[k]*gradNw)*detj*wG[iG];
	}
    }
      
    /* double penality = 0.0; //DBGSmooth */
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      localRhs[4*iu+k]+= localRhsU[k];
      localRhs[4*iv+k]+= localRhsV[k];
      localRhs[4*iw+k]+= localRhsW[k];

      for (int l = 0; l < 4; ++l){
	int ju=branchMap[l][0];
	int jv=branchMap[l][1];
	int jw=branchMap[l][2];
	/* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	/* localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l]; */
	/* localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l]; */
	/* localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l]; */
	localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	/* localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l]; */
	/* localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l]; */
	/* localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l]; */
	localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
      }
    }
    *volumeElem=detj*wG[iG];
    /* volume+=detj*wG[iG]; */
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpScalingSmart3(HXTOrientation3DScal *or3D, double *scaling, uint64_t iel, double *localMatrix, double *localRhs, double *volumeElem, double *normGradEulerElem){ //keep
  HXTMesh *mesh=or3D->mesh;
  double *frames=or3D->frames;

  uint32_t *tet = mesh->tetrahedra.node+iel*4;
  double detj=or3D->detj[iel];
  double dphi[4][3]={{0.0}};
  for(int k=0;k<4;k++){
    for(int j=0;j<3;j++){
      dphi[k][j]=or3D->dLdXElem[3*4*iel+3*k+j];
    }
  }

  double *eulerElem=or3D->eulerElem + 4*3*iel;
  int branchMap[4][3]={{0.0}};
  for(int k=0;k<4;k++)
    for(int j=0;j<3;j++)
      branchMap[k][j]=or3D->branchMapElem[4*3*iel+3*k+j];
  
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};    
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }
  double gradPsi[3]={0.0};
  double gradTheta[3]={0.0};
  double gradPhi[3]={0.0};
  for(int k=0;k<4;k++){
    for(int j=0;j<3;j++){
      gradPsi[j]+=dphi[k][j]*psiElem[k];
      gradTheta[j]+=dphi[k][j]*thetaElem[k];
      gradPhi[j]+=dphi[k][j]*phiElem[k];
    }
  }
  *normGradEulerElem=0.0;
  for(int k=0;k<3;k++)
    *normGradEulerElem+=gradPsi[k]*gradPsi[k]+gradTheta[k]*gradTheta[k]+gradPhi[k]*gradPhi[k];
  *normGradEulerElem=sqrt(*normGradEulerElem);
  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double AL[3][3]={{0.0}};
    double AM[3][3]={{0.0}};
    double Aphi[3][3]={{0.0}};
    double Atheta[3][3]={{0.0}};
    double Apsi[3][3]={{0.0}};
    double BL[3][3]={{0.0}};
    double BN[3][3]={{0.0}};
    double Bphi[3][3]={{0.0}};
    double Btheta[3][3]={{0.0}};
    double Bpsi[3][3]={{0.0}};
    double CM[3][3]={{0.0}};
    double CN[3][3]={{0.0}};
    double Cphi[3][3]={{0.0}};
    double Ctheta[3][3]={{0.0}};
    double Cpsi[3][3]={{0.0}};
    double eulerG[3]={0.0};
    double dirG[9]={0.0};
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    for(int j=0;j<3;j++){
      dirG[j]=u[j];
      dirG[3+j]=v[j];
      dirG[6+j]=w[j];
    }
    computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
    double a[3]={0.0};
    double b[3]={0.0};
    double c[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
	for (int k = 0; k < 4; ++k){
	  a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	  b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	  c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	}
      }
    }
    double ua=0.0;
    double va=0.0;
    double ub=0.0;
    double wb=0.0;
    double vc=0.0;
    double wc=0.0;
    hxtOr3DdotProd(u,a,3, &ua);
    hxtOr3DdotProd(v,a,3, &va);
    hxtOr3DdotProd(u,b,3, &ub);
    hxtOr3DdotProd(w,b,3, &wb);
    hxtOr3DdotProd(v,c,3, &vc);
    hxtOr3DdotProd(w,c,3, &wc);
    double uAL[3]={0.0};
    double vAM[3]={0.0};
    double uBL[3]={0.0};
    double wBN[3]={0.0};
    double vCM[3]={0.0};
    double wCN[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int k = 0; k < 3; ++k){
	uAL[i]+=u[k]*AL[k][i];
	vAM[i]+=v[k]*AM[k][i];
	uBL[i]+=u[k]*BL[k][i];
	wBN[i]+=w[k]*BN[k][i];
	vCM[i]+=v[k]*CM[k][i];
	wCN[i]+=w[k]*CN[k][i];
      }
    }
      
    double localMatUU[16]={0.0};
    double localMatVV[16]={0.0};
    double localMatWW[16]={0.0};
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};
    for (int i = 0; i < 16; ++i){
      localMatUU[i]=or3D->localMatUU[16*iel+i];
      localMatVV[i]=or3D->localMatVV[16*iel+i];
      localMatWW[i]=or3D->localMatWW[16*iel+i];
    }
    for (int i = 0; i < 4; ++i){
      localRhsU[i]=or3D->localRhsU[4*iel+i];
      localRhsV[i]=or3D->localRhsV[4*iel+i];
      localRhsW[i]=or3D->localRhsW[4*iel+i];
      or3D->localRhsPenaltyU[i]=0.0;
      or3D->localRhsPenaltyV[i]=0.0;
      or3D->localRhsPenaltyW[i]=0.0;
    }

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>10)
	isTetSing=1;
    }
    if(!isTetSing){
      double gradL[3]={0.0};
      double gradM[3]={0.0};
      double gradN[3]={0.0};
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  int globU=branchMap[j][0];
	  int globV=branchMap[j][1];
	  int globW=branchMap[j][2];
	  gradL[k]+=dphi[j][k]*scaling[3*tet[j]+globU];
	  gradM[k]+=dphi[j][k]*scaling[3*tet[j]+globV];
	  gradN[k]+=dphi[j][k]*scaling[3*tet[j]+globW];
	}
      double gradLu=0.0;
      double gradMv=0.0;
      double gradNw=0.0;
      for (int k = 0; k < 3; ++k){
	gradLu+=gradL[k]*u[k];
	gradMv+=gradM[k]*v[k];
	gradNw+=gradN[k]*w[k];
      }
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  /* localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	  /* localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	  /* //regularization term added */
	  /* localRhsU[j]+= dphi[j][k]*(vAM[k]*gradLu+uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	  /* localRhsV[j]+= dphi[j][k]*(-uAL[k]*gradMv+vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(-uBL[k]*gradNw+wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	  //regularization term added TEST
	  localRhsU[j]+= dphi[j][k]*(u[k]*gradLu)*detj*wG[iG];
	  localRhsV[j]+= dphi[j][k]*(v[k]*gradMv)*detj*wG[iG];
	  localRhsW[j]+= dphi[j][k]*(w[k]*gradNw)*detj*wG[iG];
	  or3D->localRhsPenaltyU[4*iel+j]+=dphi[j][k]*(u[k]*gradLu)*detj*wG[iG];
	  or3D->localRhsPenaltyV[4*iel+j]+=dphi[j][k]*(v[k]*gradMv)*detj*wG[iG];
	  or3D->localRhsPenaltyW[4*iel+j]+=dphi[j][k]*(w[k]*gradNw)*detj*wG[iG];
	}
    }
      
    /* double penality = 0.0; //DBGSmooth */
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      localRhs[4*iu+k]+= localRhsU[k];
      localRhs[4*iv+k]+= localRhsV[k];
      localRhs[4*iw+k]+= localRhsW[k];

      for (int l = 0; l < 4; ++l){
	int ju=branchMap[l][0];
	int jv=branchMap[l][1];
	int jw=branchMap[l][2];
	/* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	/* localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l]; */
	/* localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l]; */
	/* localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l]; */
	localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	/* localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l]; */
	/* localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l]; */
	/* localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l]; */
	localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
      }
    }
    *volumeElem=detj*wG[iG];
    /* volume+=detj*wG[iG]; */
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus updateLocalRhsScalingSmart2(HXTOrientation3DScal *or3D, double *scaling, uint64_t iel, double *updateLocalRhs){ //keep
  HXTMesh *mesh=or3D->mesh;
  double *frames=or3D->frames;
  uint32_t *tet = mesh->tetrahedra.node+iel*4;
  
  double detj=or3D->detj[iel];
  double dphi[4][3]={{0.0}};
  for(int k=0;k<4;k++){
    for(int j=0;j<3;j++){
      dphi[k][j]=or3D->dLdXElem[3*4*iel+3*k+j];
    }
  }

  double *eulerElem=or3D->eulerElem + 4*3*iel;
  int branchMap[4][3]={{0.0}};
  for(int k=0;k<4;k++)
    for(int j=0;j<3;j++)
      branchMap[k][j]=or3D->branchMapElem[4*3*iel+3*k+j];
  
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);

  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double eulerG[3]={0.0};
    /* double dirG[9]={0.0}; */
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);      
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};
    for (int i = 0; i < 4; ++i){
      localRhsU[i]=or3D->localRhsU[4*iel+i];
      localRhsV[i]=or3D->localRhsV[4*iel+i];
      localRhsW[i]=or3D->localRhsW[4*iel+i];
    }
    /* for (int i = 0; i < 4; ++i){ */
    /*   localRhsU[i]-=or3D->localRhsPenaltyU[4*iel+i]; */
    /*   localRhsV[i]-=or3D->localRhsPenaltyV[4*iel+i]; */
    /*   localRhsW[i]-=or3D->localRhsPenaltyW[4*iel+i]; */
    /* } */

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>10)
	isTetSing=1;
    }
    if(!isTetSing){
      double gradL[3]={0.0};
      double gradM[3]={0.0};
      double gradN[3]={0.0};
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  int globU=branchMap[j][0];
	  int globV=branchMap[j][1];
	  int globW=branchMap[j][2];
	  gradL[k]+=dphi[j][k]*scaling[3*tet[j]+globU];
	  gradM[k]+=dphi[j][k]*scaling[3*tet[j]+globV];
	  gradN[k]+=dphi[j][k]*scaling[3*tet[j]+globW];
	}
      double gradLu=0.0;
      double gradMv=0.0;
      double gradNw=0.0;
      for (int k = 0; k < 3; ++k){
	gradLu+=gradL[k]*u[k];
	gradMv+=gradM[k]*v[k];
	gradNw+=gradN[k]*w[k];
      }
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  /* localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	  /* localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	  /* //regularization term added */
	  /* localRhsU[j]+= dphi[j][k]*(vAM[k]*gradLu+uAL[k]*ua+uBL[k]*ub)*detj*wG[iG]; */
	  /* localRhsV[j]+= dphi[j][k]*(-uAL[k]*gradMv+vAM[k]*va+vCM[k]*vc)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(-uBL[k]*gradNw+wBN[k]*wb+wCN[k]*wc)*detj*wG[iG]; */
	  //regularization term added TEST
	  localRhsU[j]+= dphi[j][k]*(u[k]*gradLu)*detj*wG[iG];
	  localRhsV[j]+= dphi[j][k]*(v[k]*gradMv)*detj*wG[iG];
	  localRhsW[j]+= dphi[j][k]*(w[k]*gradNw)*detj*wG[iG];
	}
    }
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      updateLocalRhs[4*iu+k]+= localRhsU[k];
      updateLocalRhs[4*iv+k]+= localRhsV[k];
      updateLocalRhs[4*iw+k]+= localRhsW[k];
    }
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpScalingSmartSing(HXTMesh *mesh, double *frames, uint64_t iel, double *localMatrix, double *localRhs, double *volumeElem, int branchMap[4][3]){ //keep
  for (int k = 0; k < 12*12; ++k)
    localMatrix[k]=0.0;
  for (int k = 0; k < 12; ++k)
    localRhs[k]=0.0;
  double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(frameElem, stableDir, refDir);
  /* printf("base before making it direct\n"); */
  /* hxtOr3DprintBase(refDir); */
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag -1\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* /\* //DBG HARD *\/ */
  double dirRadiale[3]={0.0,0.0,1.0};
  hxtNormalizeV(dirRadiale, 3);
  //
  orderForDBG3refDir(refDir);
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag 0\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* // */
  double eulerElem[3*4]={0.0};
  double dirElem[9*4]={0.0};
  for(int i=0;i<9;i++){
    dirElem[i]=refDir[i];
  }
  for(int k=1;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    hxtOr3DmakeOrientationDirect(dirK);
    hxtOr3DliftBasis(refDir,dirK);
    /* printf("flag 1\n"); */
    hxtOr3DcheckIfBasisDirect(dirK);
    for(int i=0;i<9;i++){
      dirElem[9*k+i]=dirK[i];
    }
  }
    
  uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
  const double dphi[4][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  int flagLoc=1;
  hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  int nRot=0;
  while(flagLoc){
    nRot++;
    if(nRot>2){
      printf("ups to many rot needed\n");
      exit(0);
      break;
    }
    rotateDirElemTet(dirElem);
    hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  }
  if(flagLoc){
    printf("hum, seem no way to do a rotation to remove no nutation\n");
    exit(0);
  }
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  for(int k=0;k<4;k++){
    getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    double diffTest[3*3]={0.0};//ICI
    for(int j=0;j<3;j++){
      diffTest[j]=dirElem[9*k+j]-u[j];
      diffTest[3+j]=dirElem[9*k+3+j]-v[j];
      diffTest[6+j]=dirElem[9*k+6+j]-w[j];
    }
    double normDiff=0.0;
    hxtNorm2V(diffTest, 9, &normDiff);
    if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
      /* printf("entertest\n"); */
      if(normDiff>1e-2){
	printf("on node %i\n",k);
	printf("normDiff : %g\n",normDiff);
	printf("ok pb ici: normDiff = %g\n",normDiff);
	printf("euler :\n");
	printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
	printf("u:\n");
	printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
	printf("uRebuilt:\n");
	printf("%g %g %g\n",u[0],u[1],u[2]);
	printf("uRef:\n");
	printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
	printf("v:\n");
	printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
	printf("vRebuilt:\n");
	printf("%g %g %g\n",v[0],v[1],v[2]);
	printf("vRef:\n");
	printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
	printf("w:\n");
	printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
	printf("wRebuilt:\n");
	printf("%g %g %g\n",w[0],w[1],w[2]);
	printf("wRef:\n");
	printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
	exit(0);
      }
    }
  }
  /* int branchMap[4][3]; */
  getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
  //ICI test branch map working properly
  for(int k=0;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    for(int i=0;i<3;i++){
      double *branchLocKI=dirElem+9*k+3*i;
      double *branchGlobKI = dirK+3*branchMap[k][i];
      double diffTest[3]={0.0};
      hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
      double normDiff=0.0;
      hxtNorm2V(diffTest, 3, &normDiff);
      if(normDiff>1e-10){
	printf("pb branch map\n");
	printf("branch loc :\n");
	printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
	printf("branch glob :\n");
	printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
	exit(0);
      }
    }
  }
  //
    
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};    
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }

  /* //DBG check norm grad theta */
  /* double gradTheta[3]={0.0}; */
  /* for(int i=0;i<3;i++) */
  /*   for(int k=0;k<4;k++) */
  /* 	gradTheta[i]+=dphi[k][i]*phiElem[k]; */
  /* double normGradTheta=0.0; */
  /* hxtNorm2V(gradTheta+2, 1, &normGradTheta); */
  /* if(normGradTheta>1e-1){ */
  /*   printf("normGradTheta : %g\n",normGradTheta); */
  /*   printf("thetaElem: \n"); */
  /*   for(int k=0;k<4;k++) */
  /* 	printf(" %g /",phiElem[k]); */
  /*   printf("\n"); */
  /*   exit(0); */
  /* } */
  /* //DBG check sin(theta) */
  /* double maxSin=0.0; */
  /* for(int k=0;k<4;k++) */
  /*   if(fabs(sin(thetaElem[k]))>maxSin) */
  /* 	maxSin=fabs(sin(thetaElem[k])); */
  /* if(maxSin>1e-2){ */
  /*   printf("maxSin : %g\n",maxSin); */
  /*   exit(0); */
  /* } */
  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double frameG[9]={0.0};
    for(int k=0;k<9;k++)
      for(int l=0;l<4;l++)
	frameG[k]+=frames[9*mesh->tetrahedra.node[4*iel+l]+k]*lagBasisTet(l,xG+3*iG);
    double dirG[9]={0.0};
    double stableDirG[3]={0.0};
    hxtOr3DframeToDirections(frameG, stableDirG, dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 2\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    hxtOr3DliftBasis(refDir,dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 3\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    double AL[3][3]={{0.0}};
    double AM[3][3]={{0.0}};
    double Aphi[3][3]={{0.0}};
    double Atheta[3][3]={{0.0}};
    double Apsi[3][3]={{0.0}};
    double BL[3][3]={{0.0}};
    double BN[3][3]={{0.0}};
    double Bphi[3][3]={{0.0}};
    double Btheta[3][3]={{0.0}};
    double Bpsi[3][3]={{0.0}};
    double CM[3][3]={{0.0}};
    double CN[3][3]={{0.0}};
    double Cphi[3][3]={{0.0}};
    double Ctheta[3][3]={{0.0}};
    double Cpsi[3][3]={{0.0}};
    double eulerG[3]={0.0};
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    //ICI

    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    for(int j=0;j<3;j++){
      dirG[j]=u[j];
      dirG[3+j]=v[j];
      dirG[6+j]=w[j];
    }
    computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
    double a[3]={0.0};
    double b[3]={0.0};
    double c[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
	for (int k = 0; k < 4; ++k){
	  a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	  b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	  c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	}
      }
    }
    double ua=0.0;
    double va=0.0;
    double ub=0.0;
    double wb=0.0;
    double vc=0.0;
    double wc=0.0;
    hxtOr3DdotProd(u,a,3, &ua);
    hxtOr3DdotProd(v,a,3, &va);
    hxtOr3DdotProd(u,b,3, &ub);
    hxtOr3DdotProd(w,b,3, &wb);
    hxtOr3DdotProd(v,c,3, &vc);
    hxtOr3DdotProd(w,c,3, &wc);
    double uAL[3]={0.0};
    double vAM[3]={0.0};
    double uBL[3]={0.0};
    double wBN[3]={0.0};
    double vCM[3]={0.0};
    double wCN[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int k = 0; k < 3; ++k){
	uAL[i]+=u[k]*AL[k][i];
	vAM[i]+=v[k]*AM[k][i];
	uBL[i]+=u[k]*BL[k][i];
	wBN[i]+=w[k]*BN[k][i];
	vCM[i]+=v[k]*CM[k][i];
	wCN[i]+=w[k]*CN[k][i];
      }
    }
      
    double localMatUU[16]={0.0};
    double localMatUV[16]={0.0};
    double localMatUW[16]={0.0};
    double localMatVU[16]={0.0};
    double localMatVV[16]={0.0};
    double localMatVW[16]={0.0};
    double localMatWU[16]={0.0};
    double localMatWV[16]={0.0};
    double localMatWW[16]={0.0};
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>0.2)
	isTetSing=1;
    }
    if(!isTetSing){
      for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	  for (int k = 0; k < 3; ++k){
	    for (int m = 0; m < 3; ++m){
	      localMatUU[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m])*dphi[j][m]*detj*wG[iG];
	      localMatVV[4*i+j]+= dphi[i][k]*(vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG];
	      localMatWW[4*i+j]+= dphi[i][k]*(wBN[k]*wBN[m]+wCN[k]*wCN[m])*dphi[j][m]*detj*wG[iG];
	    }
	  }
      
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub)*detj*wG[iG];
	  localRhsV[j]+= dphi[j][k]*(vAM[k]*va+vCM[k]*vc)*detj*wG[iG];
	  localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG];
	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(wCN[k]*wc)*detj*wG[iG]; */
	}

      
      
      /* double penality = 0.0; //DBGSmooth */
      for (int k = 0; k < 4; ++k){
	int iu=branchMap[k][0];
	int iv=branchMap[k][1];
	int iw=branchMap[k][2];
	localRhs[4*iu+k]+= localRhsU[k];
	localRhs[4*iv+k]+= localRhsV[k];
	localRhs[4*iw+k]+= localRhsW[k];

	for (int l = 0; l < 4; ++l){
	  int ju=branchMap[l][0];
	  int jv=branchMap[l][1];
	  int jw=branchMap[l][2];
	  /* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	  localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	  localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l];
	  localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l];
	  localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l];
	  localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	  localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l];
	  localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l];
	  localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l];
	  localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
	}
      }
    }
    *volumeElem=detj*wG[iG];
    /* volume+=detj*wG[iG]; */
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus computeLocalOpScalingSmartCoupled(HXTMesh *mesh, double *frames, uint64_t iel, double *localMatrix, double *localRhs, double *volumeElem, int branchMap[4][3]){ //keep
  double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
  int nG=1;
  double *xG;
  HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
  double *wG;
  HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
  getGauss(nG, xG, wG);
  double refDir[9]={0.0};
  double stableDir[3]={0.0};
  hxtOr3DframeToDirections(frameElem, stableDir, refDir);
  /* printf("base before making it direct\n"); */
  /* hxtOr3DprintBase(refDir); */
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag -1\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* /\* //DBG HARD *\/ */
  double dirRadiale[3]={0.0,0.0,1.0};
  hxtNormalizeV(dirRadiale, 3);
  //
  orderForDBG3refDir(refDir);
  hxtOr3DmakeOrientationDirect(refDir);
  /* printf("flag 0\n"); */
  hxtOr3DcheckIfBasisDirect(refDir);
  /* // */
  double eulerElem[3*4]={0.0};
  double dirElem[9*4]={0.0};
  for(int i=0;i<9;i++){
    dirElem[i]=refDir[i];
  }
  for(int k=1;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    hxtOr3DmakeOrientationDirect(dirK);
    hxtOr3DliftBasis(refDir,dirK);
    /* printf("flag 1\n"); */
    hxtOr3DcheckIfBasisDirect(dirK);
    for(int i=0;i<9;i++){
      dirElem[9*k+i]=dirK[i];
    }
  }
    
  uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
  const double dphi[4][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  int flagLoc=1;
  hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
  /* int nRot=0; */
  /* while(flagLoc){ */
  /*   nRot++; */
  /*   if(nRot>2){ */
  /*     printf("ups to many rot needed\n"); */
  /*     exit(0); */
  /*     break; */
  /*   } */
  /*   rotateDirElemTet(dirElem); */
  /*   hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc); */
  /* } */
  /* if(flagLoc){ */
  /*   printf("hum, seem no way to do a rotation to remove no nutation\n"); */
  /*   exit(0); */
  /* } */
  double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
  for(int k=0;k<4;k++){
    getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    double diffTest[3*3]={0.0};//ICI
    for(int j=0;j<3;j++){
      diffTest[j]=dirElem[9*k+j]-u[j];
      diffTest[3+j]=dirElem[9*k+3+j]-v[j];
      diffTest[6+j]=dirElem[9*k+6+j]-w[j];
    }
    double normDiff=0.0;
    hxtNorm2V(diffTest, 9, &normDiff);
    if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
      /* printf("entertest\n"); */
      if(normDiff>1e-2){
	printf("on node %i\n",k);
	printf("normDiff : %g\n",normDiff);
	printf("ok pb ici: normDiff = %g\n",normDiff);
	printf("euler :\n");
	printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
	printf("u:\n");
	printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
	printf("uRebuilt:\n");
	printf("%g %g %g\n",u[0],u[1],u[2]);
	printf("uRef:\n");
	printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
	printf("v:\n");
	printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
	printf("vRebuilt:\n");
	printf("%g %g %g\n",v[0],v[1],v[2]);
	printf("vRef:\n");
	printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
	printf("w:\n");
	printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
	printf("wRebuilt:\n");
	printf("%g %g %g\n",w[0],w[1],w[2]);
	printf("wRef:\n");
	printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
	exit(0);
      }
    }
  }
  /* int branchMap[4][3]; */
  getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
  //ICI test branch map working properly
  for(int k=0;k<4;k++){
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    double dirK[9]={0.0};
    double stableDirK[3]={0.0};
    hxtOr3DframeToDirections(frameK, stableDirK, dirK);
    for(int i=0;i<3;i++){
      double *branchLocKI=dirElem+9*k+3*i;
      double *branchGlobKI = dirK+3*branchMap[k][i];
      double diffTest[3]={0.0};
      hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
      double normDiff=0.0;
      hxtNorm2V(diffTest, 3, &normDiff);
      if(normDiff>1e-10){
	printf("pb branch map\n");
	printf("branch loc :\n");
	printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
	printf("branch glob :\n");
	printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
	exit(0);
      }
    }
  }
  //
    
  double psiElem[4]={0.0};
  double thetaElem[4]={0.0};
  double phiElem[4]={0.0};    
  for(int k=0;k<4;k++){
    psiElem[k]=eulerElem[3*k+0];
    thetaElem[k]=eulerElem[3*k+1];
    phiElem[k]=eulerElem[3*k+2];
  }

  /* //DBG check norm grad theta */
  /* double gradTheta[3]={0.0}; */
  /* for(int i=0;i<3;i++) */
  /*   for(int k=0;k<4;k++) */
  /* 	gradTheta[i]+=dphi[k][i]*phiElem[k]; */
  /* double normGradTheta=0.0; */
  /* hxtNorm2V(gradTheta+2, 1, &normGradTheta); */
  /* if(normGradTheta>1e-1){ */
  /*   printf("normGradTheta : %g\n",normGradTheta); */
  /*   printf("thetaElem: \n"); */
  /*   for(int k=0;k<4;k++) */
  /* 	printf(" %g /",phiElem[k]); */
  /*   printf("\n"); */
  /*   exit(0); */
  /* } */
  /* //DBG check sin(theta) */
  /* double maxSin=0.0; */
  /* for(int k=0;k<4;k++) */
  /*   if(fabs(sin(thetaElem[k]))>maxSin) */
  /* 	maxSin=fabs(sin(thetaElem[k])); */
  /* if(maxSin>1e-2){ */
  /*   printf("maxSin : %g\n",maxSin); */
  /*   exit(0); */
  /* } */
  //Loop on gauss points
  for(int iG=0;iG<nG;iG++){
    double frameG[9]={0.0};
    for(int k=0;k<9;k++)
      for(int l=0;l<4;l++)
	frameG[k]+=frames[9*mesh->tetrahedra.node[4*iel+l]+k]*lagBasisTet(l,xG+3*iG);
    double dirG[9]={0.0};
    double stableDirG[3]={0.0};
    hxtOr3DframeToDirections(frameG, stableDirG, dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 2\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    hxtOr3DliftBasis(refDir,dirG);
    hxtOr3DmakeOrientationDirect(dirG);
    /* printf("flag 3\n"); */
    hxtOr3DcheckIfBasisDirect(dirG);
    double AL[3][3]={{0.0}};
    double AM[3][3]={{0.0}};
    double Aphi[3][3]={{0.0}};
    double Atheta[3][3]={{0.0}};
    double Apsi[3][3]={{0.0}};
    double BL[3][3]={{0.0}};
    double BN[3][3]={{0.0}};
    double Bphi[3][3]={{0.0}};
    double Btheta[3][3]={{0.0}};
    double Bpsi[3][3]={{0.0}};
    double CM[3][3]={{0.0}};
    double CN[3][3]={{0.0}};
    double Cphi[3][3]={{0.0}};
    double Ctheta[3][3]={{0.0}};
    double Cpsi[3][3]={{0.0}};
    double eulerG[3]={0.0};
    for(int k=0;k<3;k++)
      for(int l=0;l<4;l++)
	eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
    //ICI

    getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
    for(int j=0;j<3;j++){
      dirG[j]=u[j];
      dirG[3+j]=v[j];
      dirG[6+j]=w[j];
    }
    computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
    double a[3]={0.0};
    double b[3]={0.0};
    double c[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int j = 0; j < 3; ++j){
	for (int k = 0; k < 4; ++k){
	  a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	  b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	  c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	}
      }
    }
    double ua=0.0;
    double va=0.0;
    double ub=0.0;
    double wb=0.0;
    double vc=0.0;
    double wc=0.0;
    hxtOr3DdotProd(u,a,3, &ua);
    hxtOr3DdotProd(v,a,3, &va);
    hxtOr3DdotProd(u,b,3, &ub);
    hxtOr3DdotProd(w,b,3, &wb);
    hxtOr3DdotProd(v,c,3, &vc);
    hxtOr3DdotProd(w,c,3, &wc);
    /* double uApsi[3]={0.0}; */
    /* double uAtheta[3]={0.0}; */
    /* double uAphi[3]={0.0}; */
    /* double vApsi[3]={0.0}; */
    /* double vAtheta[3]={0.0}; */
    /* double vAphi[3]={0.0}; */
    /* double uBpsi[3]={0.0}; */
    /* double uBtheta[3]={0.0}; */
    /* double uBphi[3]={0.0}; */
    /* double wBpsi[3]={0.0}; */
    /* double wBtheta[3]={0.0}; */
    /* double wBphi[3]={0.0}; */
    /* double vCpsi[3]={0.0}; */
    /* double vCtheta[3]={0.0}; */
    /* double vCphi[3]={0.0}; */
    /* double wCpsi[3]={0.0}; */
    /* double wCtheta[3]={0.0}; */
    /* double wCphi[3]={0.0}; */
    double uAL[3]={0.0};
    double vAM[3]={0.0};
    double uBL[3]={0.0};
    double wBN[3]={0.0};
    double vCM[3]={0.0};
    double wCN[3]={0.0};
    for (int i = 0; i < 3; ++i){
      for (int k = 0; k < 3; ++k){
	/* uApsi[i]+=u[k]*Apsi[k][i]; */
	/* uAtheta[i]+=u[k]*Atheta[k][i]; */
	/* uAphi[i]+=u[k]*Aphi[k][i]; */
	/* vApsi[i]+=v[k]*Apsi[k][i]; */
	/* vAtheta[i]+=v[k]*Atheta[k][i]; */
	/* vAphi[i]+=v[k]*Aphi[k][i]; */
	/* uBpsi[i]+=u[k]*Bpsi[k][i]; */
	/* uBtheta[i]+=u[k]*Btheta[k][i]; */
	/* uBphi[i]+=u[k]*Bphi[k][i]; */
	/* wBpsi[i]+=w[k]*Bpsi[k][i]; */
	/* wBtheta[i]+=w[k]*Btheta[k][i]; */
	/* wBphi[i]+=w[k]*Bphi[k][i]; */
	/* vCpsi[i]+=v[k]*Cpsi[k][i]; */
	/* vCtheta[i]+=v[k]*Ctheta[k][i]; */
	/* vCphi[i]+=v[k]*Cphi[k][i]; */
	/* wCpsi[i]+=w[k]*Cpsi[k][i]; */
	/* wCtheta[i]+=w[k]*Ctheta[k][i]; */
	/* wCphi[i]+=w[k]*Cphi[k][i]; */
	uAL[i]+=u[k]*AL[k][i];
	vAM[i]+=v[k]*AM[k][i];
	uBL[i]+=u[k]*BL[k][i];
	wBN[i]+=w[k]*BN[k][i];
	vCM[i]+=v[k]*CM[k][i];
	wCN[i]+=w[k]*CN[k][i];
      }
    }
      
    double localMatUU[16]={0.0};
    double localMatUV[16]={0.0};
    double localMatUW[16]={0.0};
    double localMatVU[16]={0.0};
    double localMatVV[16]={0.0};
    double localMatVW[16]={0.0};
    double localMatWU[16]={0.0};
    double localMatWV[16]={0.0};
    double localMatWW[16]={0.0};
    double localRhsU[4]={0.0};
    double localRhsV[4]={0.0};
    double localRhsW[4]={0.0};

    int isTetSing=0;
    for (int k = 0; k < 4; k++){
      double qual=0.0;
      double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
      hxtOr3DcomputeQuality(frameK, &qual);
      if(qual>10)
	isTetSing=1;
    }
    if(!isTetSing){
      for (int i = 0; i < 4; ++i)
	for (int j = 0; j < 4; ++j)
	  for (int k = 0; k < 3; ++k){
	    for (int m = 0; m < 3; ++m){
	      localMatUU[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m]+vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG];
	      localMatVV[4*i+j]+= dphi[i][k]*(uAL[k]*uAL[m]+uBL[k]*uBL[m]+vAM[k]*vAM[m]+vCM[k]*vCM[m])*dphi[j][m]*detj*wG[iG];
	      localMatWW[4*i+j]+= dphi[i][k]*(wBN[k]*wBN[m]+wCN[k]*wCN[m])*dphi[j][m]*detj*wG[iG];
	    }
	  }
      
      for (int j = 0; j < 4; ++j)
	for (int k = 0; k < 3; ++k){
	  localRhsU[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub+vAM[k]*va+vCM[k]*vc)*detj*wG[iG];
	  localRhsV[j]+= dphi[j][k]*(uAL[k]*ua+uBL[k]*ub+vAM[k]*va+vCM[k]*vc)*detj*wG[iG];
	  localRhsW[j]+= dphi[j][k]*(wBN[k]*wb+wCN[k]*wc)*detj*wG[iG];
	  /* localRhsW[j]+= dphi[j][k]*(wBN[k]*wb)*detj*wG[iG]; */
	  /* localRhsW[j]+= dphi[j][k]*(wCN[k]*wc)*detj*wG[iG]; */
	}
    }
      
      
    /* double penality = 0.0; //DBGSmooth */
    for (int k = 0; k < 4; ++k){
      int iu=branchMap[k][0];
      int iv=branchMap[k][1];
      int iw=branchMap[k][2];
      localRhs[4*iu+k]+= localRhsU[k];
      localRhs[4*iv+k]+= localRhsV[k];
      localRhs[4*iw+k]+= localRhsW[k];

      for (int l = 0; l < 4; ++l){
	int ju=branchMap[l][0];
	int jv=branchMap[l][1];
	int jw=branchMap[l][2];
	/* localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth */
	localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l];
	localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l];
	localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l];
	localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l];
	localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l];
	localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l];
	localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l];
	localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l];
	localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l];
      }
    }
    *volumeElem=detj*wG[iG];
    /* volume+=detj*wG[iG]; */
  }//end loop on gauss points
  hxtFree(&xG);
  hxtFree(&wG);
  return HXT_STATUS_OK;
}

HXTStatus assembleScalingSysSmart(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *rhs){ //keep
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  for(uint32_t i=0;i<3*mesh->vertices.num;i++){
    rhs[i]=0.0;
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    double localMatrix[(4*3)*(4*3)]={0.0};
    double localRhs[4*3]={0.0};
    double volumeElem=0.0;
    int branchMap[4][3]={{0}};
    computeLocalOpScalingSmart(mesh, frames, iel, localMatrix, localRhs, &volumeElem,branchMap);
    /* computeLocalOpScalingSmartCoupled(mesh, frames, iel, localMatrix, localRhs, &volumeElem,branchMap); */
    volume+=volumeElem;
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus updateRhsScalingSysSmart2(HXTLinearSystem *lsys, HXTOrientation3DScal *or3D, double *scaling, double *rhs){ //keep
  HXTMesh *mesh=or3D->mesh;
  /* double *frames=or3D->frames; */
  for(uint32_t i=0;i<3*mesh->vertices.num;i++){
    rhs[i]=0.0;
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    double updateLocalRhs[4*3]={0.0};
    updateLocalRhsScalingSmart2(or3D, scaling, iel, updateLocalRhs);
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, updateLocalRhs));
  }
  return HXT_STATUS_OK;
}

HXTStatus assembleScalingSysSmart2(HXTLinearSystem *lsys, HXTOrientation3DScal *or3D, double *scaling, double *rhs, double *smoothnessIndicator){ //keep
  HXTMesh *mesh=or3D->mesh;
  /* double *frames=or3D->frames; */
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  for(uint32_t i=0;i<3*mesh->vertices.num;i++){
    rhs[i]=0.0;
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    double localMatrix[(4*3)*(4*3)]={0.0};
    double localRhs[4*3]={0.0};
    double volumeElem=0.0;
    double normGradEulerElem=0.0;
    computeLocalOpScalingSmart2(or3D, scaling, iel, localMatrix, localRhs, &volumeElem, &normGradEulerElem);
    volume+=volumeElem;
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
    if(smoothnessIndicator)
      smoothnessIndicator[iel]=normGradEulerElem;
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus assembleScalingSysSmart3(HXTLinearSystem *lsys, HXTOrientation3DScal *or3D, double *scaling, double *rhs, double *smoothnessIndicator){ //keep
  HXTMesh *mesh=or3D->mesh;
  /* double *frames=or3D->frames; */
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  for(uint32_t i=0;i<3*mesh->vertices.num;i++){
    rhs[i]=0.0;
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    double localMatrix[(4*3)*(4*3)]={0.0};
    double localRhs[4*3]={0.0};
    double volumeElem=0.0;
    double normGradEulerElem=0.0;
    computeLocalOpScalingSmart3(or3D, scaling, iel, localMatrix, localRhs, &volumeElem, &normGradEulerElem);
    volume+=volumeElem;
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
    if(smoothnessIndicator)
      smoothnessIndicator[iel]=normGradEulerElem;
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

/* HXTStatus assembleScalingSysGradPenalty(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *scaling, double *rhs){ //keep */
/*   for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){ */
/*     double localMatrix[(4*3)*(4*3)]={0.0}; */
/*     double localRhs[4*3]={0.0}; */
/*     double volumeElem=0.0; */
/*     int branchMap[4][3]={{0}}; */
/*     /\* computeLocalOpScalingSmart(mesh, frames, iel, localMatrix, localRhs, &volumeElem,branchMap); *\/ */
/*     computeLocalOpScalingSmart2(mesh, frames, scaling, iel, localMatrix, localRhs, &volumeElem,branchMap); */
/*     /\* computeLocalOpScalingSmartCoupled(mesh, frames, iel, localMatrix, localRhs, &volumeElem,branchMap); *\/ */
/*     HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix)); */
/*     HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs)); */
/*   } */
/*   return HXT_STATUS_OK; */
/* } */

HXTStatus assembleDBG2DRect(HXTLinearSystem *lsys, HXTMesh *mesh, double *rhs, double *gradXImposedTri){ //keep
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    rhs[i]=0.0;
  }
  for (uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    double gradXValTri=gradXImposedTri[iel];
    double localMatrix[(1*3)*(1*3)]={0.0};
    double localRhs[1*3]={0.0};
    double volumeElem=0.0;
    /* computeLocalOpScalingSmart(mesh, frames, iel, localMatrix, localRhs, &volumeElem,branchMap); */
    computeLocalOpDBG2DRect(mesh, iel, gradXValTri, localMatrix, localRhs, &volumeElem);
    /* computeLocalOpScalingSmartCoupled(mesh, frames, iel, localMatrix, localRhs, &volumeElem,branchMap); */
    volume+=volumeElem;
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus craftSolutionDBG2DRect1(HXTMesh *mesh, double *scaling){ //keep
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    double x[2]={0.0};
    for (int j = 0; j < 2; j++)
      x[j] = mesh->vertices.coord[4*i+j];
    double l=1.0;
    double L=3.0;
    double gradMax=1.0;
    double gradMaxX=(x[0]-L/3.)*(x[0]-L/3.)*(-6*x[0]/L+5.)*9.*gradMax/(L*L);
    if(x[0]<L/3.)
      scaling[i]=0.0;
    else if((x[0]>=L/3.)&&(x[0]<2.*L/3.))
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*(1./l)*gradMaxX+gradMaxX*l/4.;
    else if(x[0]>=2.*L/3.)
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*gradMax/l+gradMax*l/4.;
    else{
      printf("pb on splitting the domain properly\n");
      exit(0);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus craftSolutionDBG2DRect2(HXTMesh *mesh, double *scaling){ //keep
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    double x[2]={0.0};
    for (int j = 0; j < 2; j++)
      x[j] = mesh->vertices.coord[4*i+j];
    double l=1.0;
    double L=3.0;
    double gradMax=1.0;
    double gradMaxX=(x[0]-L/3.)*(x[0]-L/3.)*(-6*x[0]/L+5.)*9.*gradMax/(L*L);
    if(x[0]<L/3.)
      scaling[i]=0.0;
    else if((x[0]>=L/3.)&&(x[0]<2.*L/3.))
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*(1./l)*gradMaxX;
    else if(x[0]>=2.*L/3.)
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*gradMax/l;
    else{
      printf("pb on splitting the domain properly\n");
      exit(0);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus craftSolutionDBG2DRect3(HXTMesh *mesh, double *scaling){ //keep
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    double x[2]={0.0};
    for (int j = 0; j < 2; j++)
      x[j] = mesh->vertices.coord[4*i+j];
    double l=1.0;
    double L=3.0;
    double gradMax=1.0;
    double gradMaxX=(x[0]-L/3.)*(x[0]-L/3.)*(-6*x[0]/L+5.)*9.*gradMax/(L*L);
    if(x[0]<L/3.)
      scaling[i]=0.0;
    else if((x[0]>=L/3.)&&(x[0]<2.*L/3.))
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*(1./l)*gradMaxX + (l*l/4.)*gradMaxX/3.;
    else if(x[0]>=2.*L/3.)
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*gradMax/l + (l*l/4.)*gradMax/3.;
    else{
      printf("pb on splitting the domain properly\n");
      exit(0);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus craftSolutionDBG2DRect4(HXTMesh *mesh, double *scaling){ //keep
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    double x[2]={0.0};
    for (int j = 0; j < 2; j++)
      x[j] = mesh->vertices.coord[4*i+j];
    double l=1.0;
    double L=3.0;
    double gradMax=1.0;
    double gradMaxX=(x[0]-L/3.)*(x[0]-L/3.)*(-6*x[0]/L+5.)*9.*gradMax/(L*L);
    double fX=cos(2*2*M_PI*x[0]/L);
    if(x[0]<L/3.)
      scaling[i]=0.0 + fX ;
    else if((x[0]>=L/3.)&&(x[0]<2.*L/3.))
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*(1./l)*gradMaxX + (l*l/4.)*gradMaxX/3. + fX ;
    else if(x[0]>=2.*L/3.)
      scaling[i]=-(x[1]-l/2.)*(x[1]-l/2.)*gradMax/l + (l*l/4.)*gradMax/3. + fX ;
    else{
      printf("pb on splitting the domain properly\n");
      exit(0);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus computeIntegrationDBG2DRect(HXTMesh *mesh, double *scaling, double *errorPerTri, double *totalError){
  *totalError=0.0;
  double volumeTot=0.0;
  double *volumePerTri;
  HXT_CHECK(hxtAlignedMalloc(&volumePerTri, sizeof(double)*mesh->triangles.num));
#pragma omp parallel
  {
#pragma omp for nowait
    for (uint64_t iel=0; iel < mesh->triangles.num; ++iel){
      double volumeElem=0.0;
      uint32_t *tri = mesh->triangles.node+iel*3;
      double localScaling[3]={0.0};
      for(int i=0;i<3;i++){
	localScaling[i]=scaling[tri[i]];
      }
      double errorElem=0.0;
      computeLocalErrorDBG2DRect(mesh, iel, localScaling, &errorElem, &volumeElem);
      errorPerTri[iel]=errorElem;
      volumePerTri[iel]=volumeElem;
    }
  }
  for (uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    volumeTot+=volumePerTri[iel];
    *totalError+=errorPerTri[iel];
    errorPerTri[iel]/=volumePerTri[iel];
  }
  *totalError=*totalError;
  HXT_CHECK(hxtAlignedFree(&volumePerTri));
  return HXT_STATUS_OK;
}

HXTStatus writeGradTri(const HXTMesh *mesh, const double *scalarField, const char *fileName, const char* viewName){ //to remove

  FILE* myfile = fopen(fileName,"w");
  viewName==NULL ? fprintf(myfile,"View \"gradient\"{\n") :   fprintf(myfile,"View \"%s\"{\n", viewName);
  // fprintf(myfile,"View \"Cross\"{\n");
  for (uint64_t iel = 0; iel < mesh->triangles.num; ++iel){
    uint32_t *tri = mesh->triangles.node+iel*3;
    double x[3][2]={{0.0}};
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 2; j++)
	x[i][j] = mesh->vertices.coord[4*tri[i]+j];
    double dxdxi[2][2];
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
	dxdxi[j][i] = x[i+1][j] - x[0][j];
    double dxidx[2][2];
    double detj;
    HXT_CHECK(hxtInv2x2(dxdxi, dxidx, &detj));
    detj=fabs(detj);
    const double dphi[3][2] = {
      {-dxidx[0][0]-dxidx[1][0],-dxidx[0][1]-dxidx[1][1]},
      {dxidx[0][0],dxidx[0][1]},
      {dxidx[1][0],dxidx[1][1]}
    };
    
    double xG[3]={(x[0][0]+x[1][0]+x[2][0])/3.,(x[0][1]+x[1][1]+x[2][1])/3.,0.0};
    double gradG[2]={0.0};
    for (int i = 0; i < 2; ++i)
      for (int k = 0; k < 3; ++k)
	gradG[i]+=dphi[k][i]*scalarField[tri[k]];

    /* fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",xG[0],xG[1],0.0,gradG[0],gradG[1],0.0); */
    fprintf(myfile,"VP(%.16g,%.16g,%.16g){%.16g,%.16g,%.16g};\n",xG[0],xG[1],0.0,0.0,gradG[1],0.0);

  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus solveAndWriteDBG2DRect(HXTMesh *mesh){
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type cg -pc_type ilu -ksp_max_it 1000 -ksp_monitor -ksp_info -ksp_rtol 1e-10")); */
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->triangles.num,3,1,mesh->triangles.node,"-ksp_type gmres -ksp_monitor -ksp_max_it 10000 -ksp_info -ksp_rtol 1e-10"));
  /* -ksp_max_it 1 */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_FAILED;
#endif
  double *rhs;
  HXT_CHECK(hxtMalloc(&rhs, sizeof(double)*mesh->vertices.num));
  double *scaling;
  HXT_CHECK(hxtMalloc(&scaling, sizeof(double)*mesh->vertices.num));
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    rhs[i]=0.0;
    scaling[i]=0.0;
  }
  double *gradXImposedTri;
  HXT_CHECK(hxtMalloc(&gradXImposedTri, sizeof(double)*mesh->triangles.num));
  for(uint32_t iel=0;iel<mesh->triangles.num;iel++){
    gradXImposedTri[iel]=0.0;
  }
  for(int k=0;k<30;k++){
    printf("-------------------*************************--------------------------\n");
    assembleDBG2DRect(system, mesh, rhs, gradXImposedTri);
    HXT_CHECK(hxtLinearSystemSolve(system, rhs, scaling));
    computeGradXTri(mesh,scaling,gradXImposedTri);
  }
  /* printf("craft solution\n"); */
  /* craftSolutionDBG2DRect1(mesh, scaling); */
  /* craftSolutionDBG2DRect2(mesh, scaling); */
  /* craftSolutionDBG2DRect3(mesh, scaling); */
  /* craftSolutionDBG2DRect4(mesh, scaling); */
  writeGradTri(mesh, scaling, "grad.pos", NULL);
  double totalError=0.0;
  double *errorPerTri;
  HXT_CHECK(hxtMalloc(&errorPerTri, sizeof(double)*mesh->triangles.num));
  printf("compute error\n");
  computeIntegrationDBG2DRect(mesh, scaling, errorPerTri, &totalError);
  hxtOr3DWritePosScalarTri(mesh, errorPerTri, "errorDBG2DRect.pos");
  printf("totalError on integration : %g\n",totalError);
  double meanValue=0.0;
  for(uint32_t i=0;i<mesh->vertices.num;i++)
    meanValue+=scaling[i];
  meanValue=meanValue/mesh->vertices.num;
  printf("MeanValue : %g\n",meanValue);
  for(uint32_t i=0;i<mesh->vertices.num;i++)
    scaling[i]=exp(scaling[i]);
  hxtOr3DwritePosTriMesh(mesh, scaling, "scalingDBG.pos");
  HXT_CHECK(hxtLinearSystemDelete(&system));
  hxtFree(&scaling);
  hxtFree(&rhs);
  hxtFree(&errorPerTri);
  return HXT_STATUS_OK;
}

HXTStatus assembleBC(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *rhs, double *scalingSurf, uint32_t *indVolToSurf){ //keep
  double volume=0.0;
  for (uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    double *frameElem=frames+9*mesh->triangles.node[3*iel+0];
    uint32_t *triNodes=mesh->triangles.node+3*iel;
    int nG=1;
    double *xG;
    HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
    double *wG;
    HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
    getGauss(nG, xG, wG);
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frameElem, stableDir, refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    double *a=mesh->vertices.coord+4*triNodes[0];
    double *b=mesh->vertices.coord+4*triNodes[1];
    double *c=mesh->vertices.coord+4*triNodes[2];
    double aa[3]={b[0]-a[0],b[1]-a[1],b[2]-a[2]};
    double bb[3]={c[0]-a[0],c[1]-a[1],c[2]-a[2]};
    hxtNormalizeV(aa,3);
    hxtNormalizeV(bb,3);
    double normal[3]={0.0};
    hxtCrossProductV3(aa,bb,normal);
    hxtNormalizeV(normal,3);
    
    moveNormalToLastDir(refDir,normal);
    /* /\* //DBG HARD *\/ */
    /* double dirRadiale[3]={0.0,0.0,1.0}; */
    /* hxtNormalizeV(dirRadiale, 3); */
    /* // */
    /* orderForDBG3refDir(refDir); */
    /* makeOrientationDirect(refDir); */
    /* // */
    double dirElem[9*3]={0.0};
    for(int i=0;i<9;i++){
      dirElem[i]=refDir[i];
    }
    for(int k=1;k<3;k++){
      double *frameK=frames+9*mesh->triangles.node[3*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      hxtOr3DmakeOrientationDirect(dirK);
      hxtOr3DliftBasis(refDir,dirK);
      for(int i=0;i<9;i++){
	dirElem[9*k+i]=dirK[i];
      }
    }
    
    uint32_t *tri = mesh->triangles.node+iel*3;
    double *vert = mesh->vertices.coord;
    double vtri[3*3] = {vert[4*tri[0]+0],vert[4*tri[0]+1],vert[4*tri[0]+2],
    			vert[4*tri[1]+0],vert[4*tri[1]+1],vert[4*tri[1]+2],
    			vert[4*tri[2]+0],vert[4*tri[2]+1],vert[4*tri[2]+2]};

    double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
    			{vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
    			{0,0,0}};

    hxtCrossProductV3(jac[0],jac[1],jac[2]);
    hxtNormalizeV3(jac[2]);
    double gradLag[3][3] = {{-1.,-1.,0.},{1.,0.,0.},{0.,1.,0.}};
    double dJac, invjac[3][3];
    HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
    double detj=fabs(dJac);
    double dphi[3][3] = {{0.0}};
    for(uint32_t i=0; i<3; i++){
      dphi[i][0] = dphi[i][1] = dphi[i][2] = 0;
      for (uint32_t j = 0; j < 3; ++j) {
    	dphi[i][0] += gradLag[i][j]*invjac[0][j];
    	dphi[i][1] += gradLag[i][j]*invjac[1][j];
    	dphi[i][2] += gradLag[i][j]*invjac[2][j];
      }
    }

    double scalSurfLoc[3]={0.0};
    for(int i=0;i<3;i++){
      scalSurfLoc[i]=scalingSurf[indVolToSurf[tri[i]]];
    }
    double gradScalSurf[3]={0.0};
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	gradScalSurf[i]+=dphi[j][i]*scalSurfLoc[j];
      }
    }
    
    int branchMap[3][3];
    getBranchMapElemTri(mesh,dirElem,frames,iel,branchMap);
    //ICI test branch map working properly
    for(int k=0;k<3;k++){
      double *frameK=frames+9*mesh->triangles.node[3*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      for(int i=0;i<3;i++){
	double *branchLocKI=dirElem+9*k+3*i;
	double *branchGlobKI = dirK+3*branchMap[k][i];
	double diffTest[3]={0.0};
	hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
	double normDiff=0.0;
	hxtNorm2V(diffTest, 3, &normDiff);
	if(normDiff>1e-10){
	  printf("pb branch map\n");
	  printf("branch loc :\n");
	  printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
	  printf("branch glob :\n");
	  printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
	  exit(0);
	}
      }
    }

    //Loop on gauss points
    for(int iG=0;iG<nG;iG++){
      double localMatLaplace[9]={0.0};
      double localRhsLaplace[3]={0.0};
      int isTetSing=0;
      for (int k = 0; k < 4; k++){
	double qual=0.0;
	double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
	hxtOr3DcomputeQuality(frameK, &qual);
	if(qual>10)
	  isTetSing=1;
      }

      double penalty = 1.0;
      if(isTetSing){
	printf("tetSing assemblebc");
	exit(0);
      }
      else{
	for (int i = 0; i < 3; ++i)
	  for (int j = 0; j < 3; ++j)
	    for (int k = 0; k < 3; ++k){
	      localMatLaplace[3*i+j]+= penalty*dphi[i][k]*dphi[j][k]*detj*wG[iG];
	    }
      
	for (int i = 0; i < 3; ++i)
	  for (int k = 0; k < 3; ++k)
	    localRhsLaplace[i]+= penalty*dphi[i][k]*gradScalSurf[k]*detj*wG[iG];
      }


      for (int k = 0; k < 3; ++k){
	int nodek = tri[k];
	int iu=branchMap[k][0];
	int iv=branchMap[k][1];
	hxtLinearSystemAddRhsEntry(lsys, rhs, nodek, iu, localRhsLaplace[k]);
	hxtLinearSystemAddRhsEntry(lsys, rhs, nodek, iv, localRhsLaplace[k]);

	for (int l = 0; l < 3; ++l){
	  int nodel=tri[l];
	  int ju=branchMap[l][0];
	  int jv=branchMap[l][1];
	  hxtLinearSystemAddMatrixEntry(lsys, nodek, iu, nodel, ju, localMatLaplace[3*k+l]);
	  hxtLinearSystemAddMatrixEntry(lsys, nodek, iv, nodel, jv, localMatLaplace[3*k+l]);
	}
      }
      volume+=detj*wG[iG];
    }//end loop on gauss points
    hxtFree(&xG);
    hxtFree(&wG);
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus assembleBCUncoupled(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *rhs, double *scalingSurf, uint32_t *indVolToSurf){ //keep
  double volume=0.0;
  for (uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    double *frameElem=frames+9*mesh->triangles.node[3*iel+0];
    uint32_t *triNodes=mesh->triangles.node+3*iel;
    int nG=1;
    double *xG;
    HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
    double *wG;
    HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
    getGauss(nG, xG, wG);
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frameElem, stableDir, refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    double *a=mesh->vertices.coord+4*triNodes[0];
    double *b=mesh->vertices.coord+4*triNodes[1];
    double *c=mesh->vertices.coord+4*triNodes[2];
    double aa[3]={b[0]-a[0],b[1]-a[1],b[2]-a[2]};
    double bb[3]={c[0]-a[0],c[1]-a[1],c[2]-a[2]};
    hxtNormalizeV(aa,3);
    hxtNormalizeV(bb,3);
    double normal[3]={0.0};
    hxtCrossProductV3(aa,bb,normal);
    hxtNormalizeV(normal,3);
    
    moveNormalToLastDir(refDir,normal);
    /* /\* //DBG HARD *\/ */
    /* double dirRadiale[3]={0.0,0.0,1.0}; */
    /* hxtNormalizeV(dirRadiale, 3); */
    /* // */
    /* orderForDBG3refDir(refDir); */
    /* makeOrientationDirect(refDir); */
    /* // */
    double dirElem[9*3]={0.0};
    for(int i=0;i<9;i++){
      dirElem[i]=refDir[i];
    }
    for(int k=1;k<3;k++){
      double *frameK=frames+9*mesh->triangles.node[3*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      hxtOr3DmakeOrientationDirect(dirK);
      hxtOr3DliftBasis(refDir,dirK);
      for(int i=0;i<9;i++){
	dirElem[9*k+i]=dirK[i];
      }
    }
    
    uint32_t *tri = mesh->triangles.node+iel*3;
    double *vert = mesh->vertices.coord;
    double vtri[3*3] = {vert[4*tri[0]+0],vert[4*tri[0]+1],vert[4*tri[0]+2],
    			vert[4*tri[1]+0],vert[4*tri[1]+1],vert[4*tri[1]+2],
    			vert[4*tri[2]+0],vert[4*tri[2]+1],vert[4*tri[2]+2]};

    double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
    			{vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
    			{0,0,0}};

    hxtCrossProductV3(jac[0],jac[1],jac[2]);
    hxtNormalizeV3(jac[2]);
    double gradLag[3][3] = {{-1.,-1.,0.},{1.,0.,0.},{0.,1.,0.}};
    double dJac, invjac[3][3];
    HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
    double detj=fabs(dJac);
    double dphi[3][3] = {{0.0}};
    for(uint32_t i=0; i<3; i++){
      dphi[i][0] = dphi[i][1] = dphi[i][2] = 0;
      for (uint32_t j = 0; j < 3; ++j) {
    	dphi[i][0] += gradLag[i][j]*invjac[0][j];
    	dphi[i][1] += gradLag[i][j]*invjac[1][j];
    	dphi[i][2] += gradLag[i][j]*invjac[2][j];
      }
    }

    int branchMap[3][3];
    getBranchMapElemTri(mesh,dirElem,frames,iel,branchMap);
    
    double scalSurfLoc0[3]={0.0};
    double scalSurfLoc1[3]={0.0};
    for(int i=0;i<3;i++){
      scalSurfLoc0[i]=scalingSurf[3*indVolToSurf[tri[i]]+branchMap[i][0]];
      scalSurfLoc1[i]=scalingSurf[3*indVolToSurf[tri[i]]+branchMap[i][1]];
    }
    double gradScalSurf0[3]={0.0};
    double gradScalSurf1[3]={0.0};
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	gradScalSurf0[i]+=dphi[j][i]*scalSurfLoc0[j];
	gradScalSurf1[i]+=dphi[j][i]*scalSurfLoc1[j];
      }
    }
    
    //ICI test branch map working properly
    for(int k=0;k<3;k++){
      double *frameK=frames+9*mesh->triangles.node[3*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      for(int i=0;i<3;i++){
	double *branchLocKI=dirElem+9*k+3*i;
	double *branchGlobKI = dirK+3*branchMap[k][i];
	double diffTest[3]={0.0};
	hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
	double normDiff=0.0;
	hxtNorm2V(diffTest, 3, &normDiff);
	if(normDiff>1e-10){
	  printf("pb branch map\n");
	  printf("branch loc :\n");
	  printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
	  printf("branch glob :\n");
	  printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
	  exit(0);
	}
      }
    }

    //Loop on gauss points
    for(int iG=0;iG<nG;iG++){
      double localMatLaplace[9]={0.0};
      double localRhsLaplace0[3]={0.0};
      double localRhsLaplace1[3]={0.0};
      int isTetSing=0;
      for (int k = 0; k < 4; k++){
	double qual=0.0;
	double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
	hxtOr3DcomputeQuality(frameK, &qual);
	if(qual>10)
	  isTetSing=1;
      }

      double penalty = 1.0; //DBGSmooth	    
      if(isTetSing){
	printf("tetSing assemblebc");
	exit(0);
      }
      else{
	for (int i = 0; i < 3; ++i)
	  for (int j = 0; j < 3; ++j)
	    for (int k = 0; k < 3; ++k){
	      localMatLaplace[3*i+j]+= penalty*dphi[i][k]*dphi[j][k]*detj*wG[iG];
	    }
      
	for (int i = 0; i < 3; ++i)
	  for (int k = 0; k < 3; ++k){
	    localRhsLaplace0[i]+= penalty*dphi[i][k]*gradScalSurf0[k]*detj*wG[iG];
	    localRhsLaplace1[i]+= penalty*dphi[i][k]*gradScalSurf1[k]*detj*wG[iG];
	  }
      }


      for (int k = 0; k < 3; ++k){
	int nodek = tri[k];
	int iu=branchMap[k][0];
	int iv=branchMap[k][1];
	hxtLinearSystemAddRhsEntry(lsys, rhs, nodek, iu, localRhsLaplace0[k]);
	hxtLinearSystemAddRhsEntry(lsys, rhs, nodek, iv, localRhsLaplace1[k]);

	for (int l = 0; l < 3; ++l){
	  int nodel=tri[l];
	  int ju=branchMap[l][0];
	  int jv=branchMap[l][1];
	  hxtLinearSystemAddMatrixEntry(lsys, nodek, iu, nodel, ju, localMatLaplace[3*k+l]);
	  hxtLinearSystemAddMatrixEntry(lsys, nodek, iv, nodel, jv, localMatLaplace[3*k+l]);
	}
      }
      volume+=detj*wG[iG];
    }//end loop on gauss points
    hxtFree(&xG);
    hxtFree(&wG);
  }
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus assembleScalingSysSurfCoupled(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *rhs, int numNodesSurf){ //keep
  
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  
  for(int i=0;i<1*numNodesSurf;i++){
    rhs[i]=0.0;
  }
  
  for(uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    double localMatrix[(1*3)*(1*3)]={0.0};
    double localRhs[1*3]={0.0};
    double *frameElem=frames+9*mesh->triangles.node[3*iel+0];
    uint32_t *triNodes=mesh->triangles.node+3*iel;
    int nG=1; //Must be one here
    /* int nG=4; */
    double *xG;
    HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
    double *wG;
    HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
    getGauss(nG, xG, wG);
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frameElem, stableDir, refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    double *a=mesh->vertices.coord+4*triNodes[0];
    double *b=mesh->vertices.coord+4*triNodes[1];
    double *c=mesh->vertices.coord+4*triNodes[2];
    double aa[3]={b[0]-a[0],b[1]-a[1],b[2]-a[2]};
    double bb[3]={c[0]-a[0],c[1]-a[1],c[2]-a[2]};
    hxtNormalizeV(aa,3);
    hxtNormalizeV(bb,3);
    double normal[3]={0.0};
    hxtCrossProductV3(aa,bb,normal);
    hxtNormalizeV(normal,3);
    
    moveNormalToLastDir(refDir,normal);
    /* double diffDBG[3]={normal[0]-refDir[6+0],normal[1]-refDir[6+1],normal[2]-refDir[6+2]}; */
    /* double normDiffDBG=sqrt(diffDBG[0]*diffDBG[0]+diffDBG[1]*diffDBG[1]+diffDBG[2]*diffDBG[2]); */
    /* if(normDiffDBG>0.3){ */
    /*   printf("normal not aligned. Crit : %g\n",normDiffDBG); */
    /*   printf("normal :\n"); */
    /*   printf("%g %g %g\n",normal[0],normal[1],normal[2]); */
    /*   printf("last dir :\n"); */
    /*   printf("%g %g %g\n",refDir[6+0],refDir[6+1],refDir[6+2]); */
    /*   exit(0); */
    /* } */
    //mettre normale en dernier ici //DBG
    
    /* /\* //DBG *\/ */
    /* double dirRadiale[3]={mesh->vertices.coord[4*tetNodes[0]+0],mesh->vertices.coord[4*tetNodes[0]+1],0.0}; */
    /* hxtNormalizeV(dirRadiale, 3); */
    /* // */
    /* orderForDBG3refDir(refDir); */
    /* makeOrientationDirect(refDir); */
    /* // */
    double psiElem[3]={0.0};
    double thetaElem[3]={0.0};
    double phiElem[3]={0.0};
    double dirElem[9*3]={0.0};
    for(int i=0;i<9;i++){
      dirElem[i]=refDir[i];
    }
    for(int k=1;k<3;k++){
      double *frameK=frames+9*mesh->triangles.node[3*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      hxtOr3DliftBasis(refDir,dirK);
      for(int i=0;i<9;i++){
    	dirElem[9*k+i]=dirK[i];
      }
    }
    
    /* int branchMap[3][3]; */
    /* getBranchMapElemTri(mesh,dirElem,frames,iel,branchMap); */

    uint32_t *tri = mesh->triangles.node+iel*3;
    double *vert = mesh->vertices.coord;
    double vtri[3*3] = {vert[4*tri[0]+0],vert[4*tri[0]+1],vert[4*tri[0]+2],
    			vert[4*tri[1]+0],vert[4*tri[1]+1],vert[4*tri[1]+2],
    			vert[4*tri[2]+0],vert[4*tri[2]+1],vert[4*tri[2]+2]};

    double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
    			{vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
    			{0,0,0}};

    hxtCrossProductV3(jac[0],jac[1],jac[2]);
    hxtNormalizeV3(jac[2]);
    double gradLag[3][3] = {{-1.,-1.,0.},{1.,0.,0.},{0.,1.,0.}};
    double dJac, invjac[3][3];
    HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
    double detj=fabs(dJac);
    double dphi[3][3] = {{0.0}};
    for(uint32_t i=0; i<3; i++){
      dphi[i][0] = dphi[i][1] = dphi[i][2] = 0;
      for (uint32_t j = 0; j < 3; ++j) {
    	dphi[i][0] += gradLag[i][j]*invjac[0][j];
    	dphi[i][1] += gradLag[i][j]*invjac[1][j];
    	dphi[i][2] += gradLag[i][j]*invjac[2][j];
      }
    }

    int flagLoc=0;
    double eulerElem[3*3]={0.0};
    /* computeEulerElemTri(dirElem,eulerElem,dphi,&flagLoc); */
    hxtOr3DdirectionsToEulerTri(dirElem,dphi,eulerElem,&flagLoc);
    for(int k=0;k<3;k++){
      psiElem[k]=eulerElem[3*k+0];
      thetaElem[k]=eulerElem[3*k+1];
      phiElem[k]=eulerElem[3*k+2];
    }

    //Loop on gauss points
    for(int iG=0;iG<nG;iG++){
      double AL[3][3]={{0.0}};
      double AM[3][3]={{0.0}};
      double Aphi[3][3]={{0.0}};
      double Atheta[3][3]={{0.0}};
      double Apsi[3][3]={{0.0}};
      double BL[3][3]={{0.0}};
      double BN[3][3]={{0.0}};
      double Bphi[3][3]={{0.0}};
      double Btheta[3][3]={{0.0}};
      double Bpsi[3][3]={{0.0}};
      double CM[3][3]={{0.0}};
      double CN[3][3]={{0.0}};
      double Cphi[3][3]={{0.0}};
      double Ctheta[3][3]={{0.0}};
      double Cpsi[3][3]={{0.0}};

      double eulerG[3]={0.0};
      for(int k=0;k<3;k++)
      	for(int l=0;l<3;l++)
      	  eulerG[k]+=eulerElem[3*l+k]*1./3.;
      
      double dirG[9]={0.0};
      double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
      getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      for(int j=0;j<3;j++){
	dirG[j]=u[j];
	dirG[3+j]=v[j];
	dirG[6+j]=w[j];
      }
      computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
      double a[3]={0.0};
      for (int i = 0; i < 3; ++i){
    	for (int j = 0; j < 3; ++j){
    	  for (int k = 0; k < 3; ++k){
	    a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
    	  }
    	}
      }
      double localMatUU[9]={0.0};
      double localRhsU[3]={0.0};
      for (int i = 0; i < 3; ++i)
    	for (int j = 0; j < 3; ++j)
    	  for (int k = 0; k < 3; ++k){
    	    for (int l = 0; l < 3; ++l)
    	      for (int m = 0; m < 3; ++m){
    		localMatUU[3*i+j]+= dphi[i][k]*(AL[l][k]+AM[l][k])*(AL[l][m]+AM[l][m])*dphi[j][m]*detj*wG[iG];
    		/* localMatVV[3*i+j]+= dphi[i][k]*(AL[l][k]+AM[l][k])*(AL[l][m]+AM[l][m])*dphi[j][m]*detj*wG[iG]; */
    	      }
    	  }
      
      for (int j = 0; j < 3; ++j)
    	for (int k = 0; k < 3; ++k)
    	  for (int l = 0; l < 3; ++l){
    	    localRhsU[j]+= dphi[j][k]*((AL[l][k]+AM[l][k])*a[l])*detj*wG[iG];
    	    /* localRhsV[j]+= dphi[j][k]*((AL[l][k]+AM[l][k])*a[l])*detj*wG[iG]; */
    	  }

       for (int k = 0; k < 3; ++k){
    	localRhs[k]+= localRhsU[k];
    	for (int l = 0; l < 3; ++l){
	  localMatrix[3*k+l] += localMatUU[3*k+l];
    	}
      }
      volume+=detj*wG[iG];
    }//end loop on gauss points
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
    hxtFree(&xG);
    hxtFree(&wG);
  }
  double normRHS = 0.0;
  for(int i=0;i<1*numNodesSurf;i++){
    normRHS+=rhs[i]*rhs[i];
  }
  normRHS=sqrt(normRHS);
  printf("norm rhs : %g\n",normRHS);
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus assembleScalingSysSurfUncoupled(HXTLinearSystem *lsys, HXTMesh *mesh, double *frames, double *rhs, int numNodesSurf){ //keep
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double volume=0.0;
  
  for(int i=0;i<3*numNodesSurf;i++){
    rhs[i]=0.0;
  }
  
  for(uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    double localMatrix[(3*3)*(3*3)]={0.0};
    double localRhs[3*3]={0.0};
    double *frameElem=frames+9*mesh->triangles.node[3*iel+0];
    uint32_t *triNodes=mesh->triangles.node+3*iel;
    int nG=1; //Must be one here
    /* int nG=4; */
    double *xG;
    HXT_CHECK(hxtMalloc(&xG, sizeof(double)*3*nG));
    double *wG;
    HXT_CHECK(hxtMalloc(&wG, sizeof(double)*nG));
    getGauss(nG, xG, wG);
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    hxtOr3DframeToDirections(frameElem, stableDir, refDir);
    hxtOr3DmakeOrientationDirect(refDir);
    double *a=mesh->vertices.coord+4*triNodes[0];
    double *b=mesh->vertices.coord+4*triNodes[1];
    double *c=mesh->vertices.coord+4*triNodes[2];
    double aa[3]={b[0]-a[0],b[1]-a[1],b[2]-a[2]};
    double bb[3]={c[0]-a[0],c[1]-a[1],c[2]-a[2]};
    hxtNormalizeV(aa,3);
    hxtNormalizeV(bb,3);
    double normal[3]={0.0};
    hxtCrossProductV3(aa,bb,normal);
    hxtNormalizeV(normal,3);
    
    moveNormalToLastDir(refDir,normal);
    double diffDBG[3]={normal[0]-refDir[6+0],normal[1]-refDir[6+1],normal[2]-refDir[6+2]};
    double normDiffDBG=sqrt(diffDBG[0]*diffDBG[0]+diffDBG[1]*diffDBG[1]+diffDBG[2]*diffDBG[2]);
    if(normDiffDBG>2e-1){
      printf("normal not aligned. Crit : %g\n",normDiffDBG);
      printf("normal :\n");
      printf("%g %g %g\n",normal[0],normal[1],normal[2]);
      printf("last dir :\n");
      printf("%g %g %g\n",refDir[6+0],refDir[6+1],refDir[6+2]);
      printf("norm lastdir : %g\n",sqrt(refDir[6+0]*refDir[6+0]+refDir[6+1]*refDir[6+1]+refDir[6+2]*refDir[6+2]));
      exit(0);
    }
    //mettre normale en dernier ici //DBG
    
    /* /\* //DBG *\/ */
    /* double dirRadiale[3]={mesh->vertices.coord[4*tetNodes[0]+0],mesh->vertices.coord[4*tetNodes[0]+1],0.0}; */
    /* hxtNormalizeV(dirRadiale, 3); */
    /* // */
    /* orderForDBG3refDir(refDir); */
    /* makeOrientationDirect(refDir); */
    /* // */
    double psiElem[3]={0.0};
    double thetaElem[3]={0.0};
    double phiElem[3]={0.0};
    double dirElem[9*3]={0.0};
    for(int i=0;i<9;i++){
      dirElem[i]=refDir[i];
    }
    for(int k=1;k<3;k++){
      double *frameK=frames+9*mesh->triangles.node[3*iel+k];
      double dirK[9]={0.0};
      double stableDirK[3]={0.0};
      hxtOr3DframeToDirections(frameK, stableDirK, dirK);
      hxtOr3DliftBasis(refDir,dirK);
      for(int i=0;i<9;i++){
    	dirElem[9*k+i]=dirK[i];
      }
    }

    uint32_t *tri = mesh->triangles.node+iel*3;
    double *vert = mesh->vertices.coord;
    double vtri[3*3] = {vert[4*tri[0]+0],vert[4*tri[0]+1],vert[4*tri[0]+2],
    			vert[4*tri[1]+0],vert[4*tri[1]+1],vert[4*tri[1]+2],
    			vert[4*tri[2]+0],vert[4*tri[2]+1],vert[4*tri[2]+2]};

    double jac[3][3] = {{vtri[3]-vtri[0],vtri[4]-vtri[1],vtri[5]-vtri[2]},
    			{vtri[6]-vtri[0],vtri[7]-vtri[1],vtri[8]-vtri[2]},
    			{0,0,0}};

    hxtCrossProductV3(jac[0],jac[1],jac[2]);
    hxtNormalizeV3(jac[2]);
    double gradLag[3][3] = {{-1.,-1.,0.},{1.,0.,0.},{0.,1.,0.}};
    double dJac, invjac[3][3];
    HXT_CHECK(hxtInv3x3(jac,invjac,&dJac));
    double detj=fabs(dJac);
    double dphi[3][3] = {{0.0}};
    for(uint32_t i=0; i<3; i++){
      dphi[i][0] = dphi[i][1] = dphi[i][2] = 0;
      for (uint32_t j = 0; j < 3; ++j) {
    	dphi[i][0] += gradLag[i][j]*invjac[0][j];
    	dphi[i][1] += gradLag[i][j]*invjac[1][j];
    	dphi[i][2] += gradLag[i][j]*invjac[2][j];
      }
    }

    int flagLoc=0;
    double eulerElem[3*3]={0.0};
    /* computeEulerElemTri(dirElem,eulerElem,dphi,&flagLoc); */
    hxtOr3DdirectionsToEulerTri(dirElem,dphi,eulerElem,&flagLoc);
    
    for(int k=0;k<3;k++){
      psiElem[k]=eulerElem[3*k+0];
      thetaElem[k]=eulerElem[3*k+1];
      phiElem[k]=eulerElem[3*k+2];
    }

    int branchMap[3][3];
    getBranchMapElemTri(mesh,dirElem,frames,iel,branchMap);
    
    double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
    for(int k=0;k<3;k++){
      getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      double diffTest[3*3]={0.0};//ICI
      for(int j=0;j<3;j++){
    	diffTest[j]=dirElem[9*k+j]-u[j];
    	diffTest[3+j]=dirElem[9*k+3+j]-v[j];
    	diffTest[6+j]=dirElem[9*k+6+j]-w[j];
      }
      double normDiff=0.0;
      hxtNorm2V(diffTest, 9, &normDiff);
      if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
	/* printf("entertest\n"); */
	if(normDiff>1e-2){
	  printf("on node %i\n",k);
	  printf("normDiff : %g\n",normDiff);
	  printf("ok pb ici: normDiff = %g\n",normDiff);
	  printf("euler :\n");
	  printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
	  printf("u:\n");
	  printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
	  printf("uRebuilt:\n");
	  printf("%g %g %g\n",u[0],u[1],u[2]);
	  printf("uRef:\n");
	  printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
	  printf("v:\n");
	  printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
	  printf("vRebuilt:\n");
	  printf("%g %g %g\n",v[0],v[1],v[2]);
	  printf("vRef:\n");
	  printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
	  printf("w:\n");
	  printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
	  printf("wRebuilt:\n");
	  printf("%g %g %g\n",w[0],w[1],w[2]);
	  printf("wRef:\n");
	  printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
	  exit(0);
	}
      }
    }
    
    //Loop on gauss points
    for(int iG=0;iG<nG;iG++){
      double AL[3][3]={{0.0}};
      double AM[3][3]={{0.0}};
      double Aphi[3][3]={{0.0}};
      double Atheta[3][3]={{0.0}};
      double Apsi[3][3]={{0.0}};
      double BL[3][3]={{0.0}};
      double BN[3][3]={{0.0}};
      double Bphi[3][3]={{0.0}};
      double Btheta[3][3]={{0.0}};
      double Bpsi[3][3]={{0.0}};
      double CM[3][3]={{0.0}};
      double CN[3][3]={{0.0}};
      double Cphi[3][3]={{0.0}};
      double Ctheta[3][3]={{0.0}};
      double Cpsi[3][3]={{0.0}};

      double eulerG[3]={0.0};
      for(int k=0;k<3;k++)
      	for(int l=0;l<3;l++)
      	  eulerG[k]+=eulerElem[3*l+k]*1./3.;
      
      double dirG[9]={0.0};
      /* double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3]; */
      getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
      for(int j=0;j<3;j++){
	dirG[j]=u[j];
	dirG[3+j]=v[j];
	dirG[6+j]=w[j];
      }
      computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);

      double a[3]={0.0};
      for (int i = 0; i < 3; ++i){
	for (int j = 0; j < 3; ++j){
	  for (int k = 0; k < 3; ++k){
	    a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	  }
	}
      }

      double localMatUU[9]={0.0};
      double localMatUV[9]={0.0};
      double localMatUW[9]={0.0};
      double localMatVU[9]={0.0};
      double localMatVV[9]={0.0};
      double localMatVW[9]={0.0};
      double localMatWU[9]={0.0};
      double localMatWV[9]={0.0};
      double localMatWW[9]={0.0};
      double localRhsU[3]={0.0};
      double localRhsV[3]={0.0};
      double localRhsW[3]={0.0};
      
      for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
	  for (int k = 0; k < 3; ++k){
	    for (int l = 0; l < 3; ++l)
	      for (int m = 0; m < 3; ++m){
		localMatUU[3*i+j]+= dphi[i][k]*(AL[l][k]*AL[l][m]+BL[l][k]*BL[l][m])*dphi[j][m]*detj*wG[iG];
		localMatUV[3*i+j]+= dphi[i][k]*AL[l][k]*AM[l][m]*dphi[j][m]*detj*wG[iG];
		localMatUW[3*i+j]+= dphi[i][k]*BL[l][k]*BN[l][m]*dphi[j][m]*detj*wG[iG];

		localMatVU[3*i+j]+= dphi[i][k]*AM[l][k]*AL[l][m]*dphi[j][m]*detj*wG[iG];
		localMatVV[3*i+j]+= dphi[i][k]*(AM[l][k]*AM[l][m]+CM[l][k]*CM[l][m])*dphi[j][m]*detj*wG[iG];
		localMatVW[3*i+j]+= dphi[i][k]*CM[l][k]*CN[l][m]*dphi[j][m]*detj*wG[iG];

		localMatWU[3*i+j]+= dphi[i][k]*BN[l][k]*BL[l][m]*dphi[j][m]*detj*wG[iG];
		localMatWV[3*i+j]+= dphi[i][k]*CN[l][k]*CM[l][m]*dphi[j][m]*detj*wG[iG];
		localMatWW[3*i+j]+= dphi[i][k]*(BN[l][k]*BN[l][m]+CN[l][k]*CN[l][m])*dphi[j][m]*detj*wG[iG];
	      }
	  }
      
      for (int j = 0; j < 3; ++j)
	for (int k = 0; k < 3; ++k)
	  for (int l = 0; l < 3; ++l){
	    localRhsU[j]+= dphi[j][k]*(AL[l][k]*a[l]+BL[l][k]*b[l])*detj*wG[iG];
	    localRhsV[j]+= dphi[j][k]*(AM[l][k]*a[l]+CM[l][k]*c[l])*detj*wG[iG];
	    localRhsW[j]+= dphi[j][k]*(BN[l][k]*b[l]+CN[l][k]*c[l])*detj*wG[iG];
	    /* localRhsU[j]+= dphi[j][k]*(AL[l][k]*a[l])*detj*wG[iG]; */
	    /* localRhsV[j]+= dphi[j][k]*(AM[l][k]*a[l])*detj*wG[iG]; */
	    /* localRhsU[j]+= dphi[j][k]*(AL[l][k]+AM[l][k])*a[l]*detj*wG[iG]; */
	    /* localRhsV[j]+= dphi[j][k]*(AL[l][k]+AM[l][k])*a[l]*detj*wG[iG]; */
	  }
      
      for (int k = 0; k < 3; ++k){
    	int iu=branchMap[k][0];
    	int iv=branchMap[k][1];
    	int iw=branchMap[k][2];
	localRhs[3*iu+k]+= localRhsU[k];
	localRhs[3*iv+k]+= localRhsV[k];
	localRhs[3*iw+k]+= localRhsW[k];
    	for (int l = 0; l < 3; ++l){
	  int ju=branchMap[l][0];
	  int jv=branchMap[l][1];
	  int jw=branchMap[l][2];
	  localMatrix[9*(k+3*iu)+l+3*ju] += localMatUU[3*k+l];
	  localMatrix[9*(k+3*iu)+l+3*jv] += localMatUV[3*k+l];
	  localMatrix[9*(k+3*iu)+l+3*jw] += localMatUW[3*k+l];
	  localMatrix[9*(k+3*iv)+l+3*ju] += localMatVU[3*k+l];
	  localMatrix[9*(k+3*iv)+l+3*jv] += localMatVV[3*k+l];
	  localMatrix[9*(k+3*iv)+l+3*jw] += localMatVW[3*k+l];
	  localMatrix[9*(k+3*iw)+l+3*ju] += localMatWU[3*k+l];
	  localMatrix[9*(k+3*iw)+l+3*jv] += localMatWV[3*k+l];
	  localMatrix[9*(k+3*iw)+l+3*jw] += localMatWW[3*k+l];
	  /* localMatrix[9*(k+3*iw)+l+3*jw] += id3v3[3*k+l]; */
    	}
      }
      volume+=detj*wG[iG];
    }//end loop on gauss points
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
    hxtFree(&xG);
    hxtFree(&wG);
  }
  double normRHS = 0.0;
  for(int i=0;i<3*numNodesSurf;i++){
    normRHS+=rhs[i]*rhs[i];
  }
  normRHS=sqrt(normRHS);
  printf("norm rhs : %g\n",normRHS);
  printf("volume Tot : %g\n", volume);
  return HXT_STATUS_OK;
}

HXTStatus craftAnnulusSolScaling(HXTMesh *mesh, double *frames, double *scaling){
  for (uint64_t iv=0; iv < mesh->vertices.num; ++iv){
    double *x=mesh->vertices.coord+4*iv;
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    double *frameNode=frames+9*iv;
    hxtOr3DframeToDirections(frameNode, stableDir, refDir);
    double radialDir[3]={x[0],x[1],0.0};
    for(int i=0;i<3;i++){
      double scalarProd=0.0;
      hxtOr3DdotProd(radialDir,refDir+3*i,3,&scalarProd);
      if(fabs(fabs(refDir[3*i+2])-1)<1e-1)
	scaling[3*iv+i]=0.0;
      /* else if(fabs(scalarProd)>1e-2) */
      /* 	scaling[3*iv+i]=1.0; */
      else
	scaling[3*iv+i]=log(sqrt(x[0]*x[0]+x[1]*x[1]));

      
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus craftFullAnnulusSol(HXTMesh *mesh, double *directions, double *scaling){
  for (uint64_t iv=0; iv < mesh->vertices.num; ++iv){
    double *x=mesh->vertices.coord+4*iv;
    double radius=sqrt(x[0]*x[0]+x[1]*x[1]);
    directions[9*iv+0]=x[0]/radius;
    directions[9*iv+1]=x[1]/radius;
    directions[9*iv+2]=0.0;
    directions[9*iv+3+0]=-x[1]/radius;
    directions[9*iv+3+1]=x[0]/radius;
    directions[9*iv+3+2]=0.0;
    directions[9*iv+6+0]=0.0;
    directions[9*iv+6+1]=0.0;
    directions[9*iv+6+2]=1.0;
    scaling[3*iv+0]=log(radius);
    scaling[3*iv+1]=log(radius);
    scaling[3*iv+2]=log(1.0);
  }
  return HXT_STATUS_OK;
}

HXTStatus computeIntegrationError(HXTMesh *mesh, double *frames, double *scaling, double *errorPerTet, double *totalError){ //keep
  *totalError=0.0;
  double volumeTot=0.0;
  double *volumePerTet;
  HXT_CHECK(hxtAlignedMalloc(&volumePerTet, sizeof(double)*mesh->tetrahedra.num));
#pragma omp parallel
  {
#pragma omp for nowait
    for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
      double localMatrix[(4*3)*(4*3)]={0.0};
      double localRhs[4*3]={0.0};
      double *frameElem=frames+9*mesh->tetrahedra.node[4*iel+0];
      int nG=1;
      /* int nG=4; */
      double *xG;
      hxtMalloc(&xG, sizeof(double)*3*nG);
      double *wG;
      hxtMalloc(&wG, sizeof(double)*nG);
      getGauss(nG, xG, wG);
      double refDir[9]={0.0};
      double stableDir[3]={0.0};
      hxtOr3DframeToDirections(frameElem, stableDir, refDir);
      hxtOr3DmakeOrientationDirect(refDir);
      /* /\* //DBG HARD *\/ */
      double dirRadiale[3]={0.0,0.0,1.0};
      hxtNormalizeV(dirRadiale, 3);
      //
      orderForDBG3refDir(refDir);
      hxtOr3DmakeOrientationDirect(refDir);
      /* // */
      double eulerElem[3*4]={0.0};
      double dirElem[9*4]={0.0};
      for(int i=0;i<9;i++){
	dirElem[i]=refDir[i];
      }
      for(int k=1;k<4;k++){
	double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
	double dirK[9]={0.0};
	double stableDirK[3]={0.0};
	hxtOr3DframeToDirections(frameK, stableDirK, dirK);
	hxtOr3DmakeOrientationDirect(dirK);
	hxtOr3DliftBasis(refDir,dirK);
	for(int i=0;i<9;i++){
	  dirElem[9*k+i]=dirK[i];
	}
      }
    
      uint32_t *tet = mesh->tetrahedra.node+iel*4;
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
      hxtInv3x3(dxdxi, dxidx, &detj);
      detj=fabs(detj);
      const double dphi[4][3] = {
	{-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
	{dxidx[0][0],dxidx[0][1],dxidx[0][2]},
	{dxidx[1][0],dxidx[1][1],dxidx[1][2]},
	{dxidx[2][0],dxidx[2][1],dxidx[2][2]}
      };
      int flagLoc=1;
      hxtOr3DdirectionsToEulerTet(dirElem,dphi,eulerElem,&flagLoc);
      /* int nRot=0; */
      /* printf("rot 0\n"); */
      /* printf("flagLoc : %i\n",flagLoc); */
      /* while(flagLoc){ */
      /*   nRot++; */
      /*   /\* printf("rot %i\n",nRot); *\/ */
      /*   /\* if(nRot>2){ *\/ */
      /*   /\* 	printf("ups\n"); *\/ */
      /*   /\* 	exit(0); *\/ */
      /*   /\* 	break; *\/ */
      /*   /\* } *\/ */
      /*   rotateDirElemTet(dirElem); */
      /*   computeEulerElem2DBG(dirElem,eulerElem,dphi,&flagLoc); */
      /*   /\* printf("flagLoc : %i\n",flagLoc); *\/ */
      /* } */
      double u[3],v[3],w[3],uOrth[3],vOrth[3],wOrth[3],uXY[3],vXY[3],wXY[3],wPi2[3],u1[3];
      for(int k=0;k<4;k++){
	getBuildingVectors(eulerElem+3*k,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
	double diffTest[3*3]={0.0};//ICI
	for(int j=0;j<3;j++){
	  diffTest[j]=dirElem[9*k+j]-u[j];
	  diffTest[3+j]=dirElem[9*k+3+j]-v[j];
	  diffTest[6+j]=dirElem[9*k+6+j]-w[j];
	}
	double normDiff=0.0;
	hxtNorm2V(diffTest, 9, &normDiff);
	if((fabs(eulerElem[3*k+1])>1e-8)&&(fabs(eulerElem[3*k+1]-M_PI)>1e-8)){
	  /* printf("entertest\n"); */
	  if(normDiff>1e-2){
	    printf("on node %i\n",k);
	    printf("normDiff : %g\n",normDiff);
	    printf("ok pb ici: normDiff = %g\n",normDiff);
	    printf("euler :\n");
	    printf("%g %g %g\n",eulerElem[3*k+0],eulerElem[3*k+1],eulerElem[3*k+2]);
	    printf("u:\n");
	    printf("%g %g %g\n",dirElem[9*k+0],dirElem[9*k+1],dirElem[9*k+2]);
	    printf("uRebuilt:\n");
	    printf("%g %g %g\n",u[0],u[1],u[2]);
	    printf("uRef:\n");
	    printf("%g %g %g\n",dirElem[0],dirElem[1],dirElem[2]);
	    printf("v:\n");
	    printf("%g %g %g\n",dirElem[9*k+3],dirElem[9*k+4],dirElem[9*k+5]);
	    printf("vRebuilt:\n");
	    printf("%g %g %g\n",v[0],v[1],v[2]);
	    printf("vRef:\n");
	    printf("%g %g %g\n",dirElem[3],dirElem[4],dirElem[5]);
	    printf("w:\n");
	    printf("%g %g %g\n",dirElem[9*k+6],dirElem[9*k+7],dirElem[9*k+8]);
	    printf("wRebuilt:\n");
	    printf("%g %g %g\n",w[0],w[1],w[2]);
	    printf("wRef:\n");
	    printf("%g %g %g\n",dirElem[6],dirElem[7],dirElem[8]);
	    exit(0);
	  }
	}
      }
      int branchMap[4][3];
      getBranchMapElem(mesh,dirElem,frames,iel,branchMap);
      //ICI test branch map working properly
      for(int k=0;k<4;k++){
	double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
	double dirK[9]={0.0};
	double stableDirK[3]={0.0};
	hxtOr3DframeToDirections(frameK, stableDirK, dirK);
	for(int i=0;i<3;i++){
	  double *branchLocKI=dirElem+9*k+3*i;
	  double *branchGlobKI = dirK+3*branchMap[k][i];
	  double diffTest[3]={0.0};
	  hxtCrossProductV3(branchLocKI,branchGlobKI,diffTest);
	  double normDiff=0.0;
	  hxtNorm2V(diffTest, 3, &normDiff);
	  if(normDiff>1e-10){
	    printf("pb branch map\n");
	    printf("branch loc :\n");
	    printf("%g %g %g\n",branchLocKI[0],branchLocKI[1],branchLocKI[2]);
	    printf("branch glob :\n");
	    printf("%g %g %g\n",branchGlobKI[0],branchGlobKI[1],branchGlobKI[2]);
	    exit(0);
	  }
	}
      }
      //
    
      double psiElem[4]={0.0};
      double thetaElem[4]={0.0};
      double phiElem[4]={0.0};    
      for(int k=0;k<4;k++){
	psiElem[k]=eulerElem[3*k+0];
	thetaElem[k]=eulerElem[3*k+1];
	phiElem[k]=eulerElem[3*k+2];
      }
      //Loop on gauss points
      double volumeElem=0.0;
      for(int iG=0;iG<nG;iG++){
	double frameG[9]={0.0};
	for(int k=0;k<9;k++)
	  for(int l=0;l<4;l++)
	    frameG[k]+=frames[9*mesh->tetrahedra.node[4*iel+l]+k]*lagBasisTet(l,xG+3*iG);
	double dirG[9]={0.0};
	double stableDirG[3]={0.0};
	hxtOr3DframeToDirections(frameG, stableDirG, dirG);
	hxtOr3DmakeOrientationDirect(dirG);
	hxtOr3DliftBasis(refDir,dirG);
	hxtOr3DmakeOrientationDirect(dirG);
	double AL[3][3]={{0.0}};
	double AM[3][3]={{0.0}};
	double Aphi[3][3]={{0.0}};
	double Atheta[3][3]={{0.0}};
	double Apsi[3][3]={{0.0}};
	double BL[3][3]={{0.0}};
	double BN[3][3]={{0.0}};
	double Bphi[3][3]={{0.0}};
	double Btheta[3][3]={{0.0}};
	double Bpsi[3][3]={{0.0}};
	double CM[3][3]={{0.0}};
	double CN[3][3]={{0.0}};
	double Cphi[3][3]={{0.0}};
	double Ctheta[3][3]={{0.0}};
	double Cpsi[3][3]={{0.0}};
	double eulerG[3]={0.0};
	for(int k=0;k<3;k++)
	  for(int l=0;l<4;l++)
	    eulerG[k]+=eulerElem[3*l+k]*lagBasisTet(l,xG+3*iG);
	//ICI

	getBuildingVectors(eulerG,u,v,w,uOrth,vOrth,wOrth,uXY,vXY,wXY,wPi2,u1);
	for(int j=0;j<3;j++){
	  dirG[j]=u[j];
	  dirG[3+j]=v[j];
	  dirG[6+j]=w[j];
	}
	computeLocalOpScaling(AL,AM,Aphi,Atheta,Apsi,BL,BN,Bphi,Btheta,Bpsi,CM,CN,Cphi,Ctheta,Cpsi,eulerG,dirG);
      
	double a[3]={0.0};
	double b[3]={0.0};
	double c[3]={0.0};
	for (int i = 0; i < 3; ++i){
	  for (int j = 0; j < 3; ++j){
	    for (int k = 0; k < 4; ++k){
	      a[i]+=Aphi[i][j]*dphi[k][j]*phiElem[k]+Atheta[i][j]*dphi[k][j]*thetaElem[k]+Apsi[i][j]*dphi[k][j]*psiElem[k];
	      b[i]+=Bphi[i][j]*dphi[k][j]*phiElem[k]+Btheta[i][j]*dphi[k][j]*thetaElem[k]+Bpsi[i][j]*dphi[k][j]*psiElem[k];
	      c[i]+=Cphi[i][j]*dphi[k][j]*phiElem[k]+Ctheta[i][j]*dphi[k][j]*thetaElem[k]+Cpsi[i][j]*dphi[k][j]*psiElem[k];
	    }
	  }
	}
	double localMatLaplace[16]={0.0}; //DBGSmooth
	double localMatUU[16]={0.0};
	double localMatUV[16]={0.0};
	double localMatUW[16]={0.0};
	double localMatVU[16]={0.0};
	double localMatVV[16]={0.0};
	double localMatVW[16]={0.0};
	double localMatWU[16]={0.0};
	double localMatWV[16]={0.0};
	double localMatWW[16]={0.0};
	double localRhsU[4]={0.0};
	double localRhsV[4]={0.0};
	double localRhsW[4]={0.0};
	int isTetSing=0;
	for (int k = 0; k < 4; k++){
	  double qual=0.0;
	  double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
	  hxtOr3DcomputeQuality(frameK, &qual);
	  if(qual>10)
	    isTetSing=1;
	}
      
	if(!isTetSing){
	  for (int i = 0; i < 4; ++i)
	    for (int j = 0; j < 4; ++j)
	      for (int k = 0; k < 3; ++k){
		localMatLaplace[4*i+j]+= dphi[i][k]*dphi[j][k]*detj*wG[iG]; //DBGSmooth
		for (int l = 0; l < 3; ++l)
		  for (int m = 0; m < 3; ++m){
		    localMatUU[4*i+j]+= dphi[i][k]*(AL[l][k]*AL[l][m]+BL[l][k]*BL[l][m])*dphi[j][m]*detj*wG[iG];
		    /* localMatUU[4*i+j]+= dphi[i][k]*((AL[l][k]+AM[l][k])*(AL[l][m]+AM[l][m])+BL[l][k]*BL[l][m])*dphi[j][m]*detj*wG[iG];//HARD DBG */
		    localMatUV[4*i+j]+= dphi[i][k]*AL[l][k]*AM[l][m]*dphi[j][m]*detj*wG[iG];
		    localMatUW[4*i+j]+= dphi[i][k]*BL[l][k]*BN[l][m]*dphi[j][m]*detj*wG[iG];

		    localMatVU[4*i+j]+= dphi[i][k]*AM[l][k]*AL[l][m]*dphi[j][m]*detj*wG[iG];
		    localMatVV[4*i+j]+= dphi[i][k]*(AM[l][k]*AM[l][m]+CM[l][k]*CM[l][m])*dphi[j][m]*detj*wG[iG];
		    /* localMatVV[4*i+j]+= dphi[i][k]*((AL[l][k]+AM[l][k])*(AL[l][m]+AM[l][m])+CM[l][k]*CM[l][m])*dphi[j][m]*detj*wG[iG];//HARD DBG */
		    localMatVW[4*i+j]+= dphi[i][k]*CM[l][k]*CN[l][m]*dphi[j][m]*detj*wG[iG];

		    localMatWU[4*i+j]+= dphi[i][k]*BN[l][k]*BL[l][m]*dphi[j][m]*detj*wG[iG];
		    localMatWV[4*i+j]+= dphi[i][k]*CN[l][k]*CM[l][m]*dphi[j][m]*detj*wG[iG];
		    localMatWW[4*i+j]+= dphi[i][k]*(BN[l][k]*BN[l][m]+CN[l][k]*CN[l][m])*dphi[j][m]*detj*wG[iG];
		  }
	      }
      
	  for (int j = 0; j < 4; ++j)
	    for (int k = 0; k < 3; ++k)
	      for (int l = 0; l < 3; ++l){
		localRhsU[j]+= dphi[j][k]*(AL[l][k]*a[l]+BL[l][k]*b[l])*detj*wG[iG];
		localRhsV[j]+= dphi[j][k]*(AM[l][k]*a[l]+CM[l][k]*c[l])*detj*wG[iG];
		localRhsW[j]+= dphi[j][k]*(BN[l][k]*b[l]+CN[l][k]*c[l])*detj*wG[iG];
	      }

	}
      
	double penality = 0.0; //DBGSmooth
	for (int k = 0; k < 4; ++k){
	  int iu=branchMap[k][0];
	  int iv=branchMap[k][1];
	  int iw=branchMap[k][2];
	  localRhs[4*iu+k]+= localRhsU[k];
	  localRhs[4*iv+k]+= localRhsV[k];
	  localRhs[4*iw+k]+= localRhsW[k];

	  for (int l = 0; l < 4; ++l){
	    int ju=branchMap[l][0];
	    int jv=branchMap[l][1];
	    int jw=branchMap[l][2];
	    //
	    localMatrix[12*(k+4*iu)+l+4*ju] += localMatUU[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth
	    localMatrix[12*(k+4*iu)+l+4*jv] += localMatUV[4*k+l];
	    localMatrix[12*(k+4*iu)+l+4*jw] += localMatUW[4*k+l];
	    localMatrix[12*(k+4*iv)+l+4*ju] += localMatVU[4*k+l];
	    localMatrix[12*(k+4*iv)+l+4*jv] += localMatVV[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth
	    localMatrix[12*(k+4*iv)+l+4*jw] += localMatVW[4*k+l];
	    localMatrix[12*(k+4*iw)+l+4*ju] += localMatWU[4*k+l];
	    localMatrix[12*(k+4*iw)+l+4*jv] += localMatWV[4*k+l];
	    localMatrix[12*(k+4*iw)+l+4*jw] += localMatWW[4*k+l]+penality*localMatLaplace[4*k+l]; //DBGSmooth
	  }
	}
	volumeElem+=detj*wG[iG];
	/* volume+=detj*wG[iG]; */
      }//end loop on gauss points
      volumePerTet[iel]=volumeElem;
      double lU[4*3]={0.0};
      for(int k=0;k<4;k++){
	for(int i=0;i<3;i++){
	  int iu=branchMap[k][i];
	  lU[4*i+k]=scaling[3*tet[k]+iu];
	}
      }
      double ener=0.0;
      for(int i=0;i<12;i++)
	for(int j=0;j<12;j++)
	  for(int k=0;k<12;k++)
	    ener+=((localMatrix[12*i+k]*lU[k]-localRhs[i]))*(localMatrix[12*i+j]*lU[j]-localRhs[i]);
      errorPerTet[iel]=ener;
      hxtFree(&xG);
      hxtFree(&wG);
    }
  }

  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    *totalError+=errorPerTet[iel];
    volumeTot+=volumePerTet[iel];
  }
  *totalError=*totalError/volumeTot;
  HXT_CHECK(hxtAlignedFree(&volumePerTet));
  return HXT_STATUS_OK;
}

int isTetSingular(HXTMesh *mesh, double *frames, int iel){
  int isTetSing=0;
  for (int k = 0; k < 4; k++){
    double qual=0.0;
    double *frameK=frames+9*mesh->tetrahedra.node[4*iel+k];
    hxtOr3DcomputeQuality(frameK, &qual);
    if(qual>0.2)
      isTetSing=1;
  }
  return isTetSing;
}

HXTStatus computeIntegrationErrorSmart(HXTMesh *mesh, double *frames, double *scaling, double *errorPerTet, double *totalError){ //keep
  *totalError=0.0;
  double volumeTot=0.0;
  double *volumePerTet;
  HXT_CHECK(hxtAlignedMalloc(&volumePerTet, sizeof(double)*mesh->tetrahedra.num));
  double *KU;
  HXT_CHECK(hxtAlignedMalloc(&KU, 3*sizeof(double)*mesh->vertices.num));
  double *delta;
  HXT_CHECK(hxtAlignedMalloc(&delta, 3*sizeof(double)*mesh->vertices.num));
  double *rhs;
  HXT_CHECK(hxtAlignedMalloc(&rhs, 3*sizeof(double)*mesh->vertices.num));
  HXTLinearSystem *lsys;
  #ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&lsys,mesh->tetrahedra.num,4,3,mesh->tetrahedra.node,"-ksp_type gmres -ksp_monitor -ksp_max_it 0 -ksp_info -ksp_rtol 1e-2"));
  #else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_FAILED;
  #endif
  #pragma omp parallel
  {
    #pragma omp for nowait
    for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
      double localMatrix[(4*3)*(4*3)]={0.0};
      double localRhs[4*3]={0.0};
      double volumeElem=0.0;
      int branchMap[4][3]={{0}};
      computeLocalOpScalingSmart(mesh, frames, iel, localMatrix, localRhs, &volumeElem, branchMap);
      volumePerTet[iel]=volumeElem;
      uint32_t *tet = mesh->tetrahedra.node+iel*4;
      double lU[4*3]={0.0};
      for(int k=0;k<4;k++){
	for(int i=0;i<3;i++){
	  /* int iu=branchMap[k][i]; */
	  /* lU[4*i+k]=scaling[3*tet[k]+iu]; */
	  lU[4*i+k]=scaling[3*tet[k]+i];
	  /* lU[3*k+i]=scaling[3*tet[k]+iu]; */
	}
      }
      double enerElem=0.0;
      double localKU[4*3]={0.0};
      /* if(!isTetSingular(mesh,frames,iel)){ */
      if(1){
	for(int i=0;i<12;i++)
	  for(int k=0;k<12;k++)
	    localKU[i]+=localMatrix[12*i+k]*lU[k];
	for(int i=0;i<12;i++)
	  enerElem+=(localKU[i]-localRhs[i])*(localKU[i]-localRhs[i]);
      }
      else{
	enerElem=0.0;
      }


      hxtLinearSystemAddToRhs(lsys, KU, iel, localKU);
      hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs);
      /* for(int i=0;i<12;i++) */
      /* ener+=delta[i]*delta[i]; */
      errorPerTet[iel]=sqrt(enerElem)/volumeElem;
    }
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    volumeTot+=volumePerTet[iel];
  }
  for (uint32_t iv=0; iv < mesh->vertices.num; ++iv){
    *totalError+=(KU[iv]-rhs[iv])*(KU[iv]-rhs[iv]);
    /* volumeTot+=volumePerTet[iel]; */
  }
  /* for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){ */
  /*   *totalError+=errorPerTet[iel]*errorPerTet[iel]; */
  /* } */
  *totalError=sqrt(*totalError)/volumeTot;
  /* *totalError=sqrt(*totalError); */
  HXT_CHECK(hxtLinearSystemDelete(&lsys));
  HXT_CHECK(hxtAlignedFree(&volumePerTet));
  HXT_CHECK(hxtAlignedFree(&KU));
  HXT_CHECK(hxtAlignedFree(&delta));
  HXT_CHECK(hxtAlignedFree(&rhs));
  return HXT_STATUS_OK;
}

HXTStatus computeIntegrationErrorSmart2(HXTOrientation3DScal *or3D, HXTMesh *mesh, double *frames, double *scaling, double *errorPerTet, double *totalError){ //keep
  *totalError=0.0;
  double volumeTot=0.0;
  double *volumePerTet;
  HXT_CHECK(hxtAlignedMalloc(&volumePerTet, sizeof(double)*mesh->tetrahedra.num));
#pragma omp parallel
  {
#pragma omp for nowait
    for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
      double volumeElem=0.0;
      uint32_t *tet = mesh->tetrahedra.node+iel*4;
      double localScaling[4*3]={0.0};
      for(int k=0;k<4;k++){
	for(int i=0;i<3;i++){
	  localScaling[4*i+k]=scaling[3*tet[k]+i];
	}
      }
      double errorElem=0.0;
      /* computeLocalErrorScalingSmart(mesh, frames, iel, localScaling, &errorElem, &volumeElem); */
      computeLocalErrorScalingSmart2(or3D, iel, localScaling, &errorElem, &volumeElem);
      volumePerTet[iel]=volumeElem;	
      if(!isTetSingular(mesh,frames,iel)){
	errorPerTet[iel]=errorElem;
      }
      else{
	errorPerTet[iel]=0.0;
      }
    }
  }
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    volumeTot+=volumePerTet[iel];
    *totalError+=errorPerTet[iel];
  }
  *totalError=*totalError/volumeTot;
  HXT_CHECK(hxtAlignedFree(&volumePerTet));
  return HXT_STATUS_OK;
}

HXTStatus frameToScaledCrosses(HXTMesh *mesh, double *scaling, double *frames, double *directions) //keep
{
  int cpt=0;
  for (uint64_t iv=0; iv < mesh->vertices.num; ++iv){
    cpt++;
    double refDir[9]={0.0};
    double stableDir[3]={0.0};
    double *frameNode=frames+9*iv;
    hxtOr3DframeToDirections(frameNode, stableDir, refDir);
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
	directions[9*iv+3*i+j]=refDir[3*i+j]*exp(scaling[3*iv+i]);
    }
  return HXT_STATUS_OK;
}

HXTStatus createSurfArrays(HXTMesh *mesh, uint32_t *nVertSurf, uint32_t **trianglesNodesIndSurf, uint32_t **indVolToSurf) //keep
{
  int *flagVert;
  HXT_CHECK(hxtMalloc(&flagVert, sizeof(int)*mesh->vertices.num));
  for(uint64_t i=0; i < mesh->vertices.num; ++i)
    flagVert[i]=0;
  (*nVertSurf)=0;
  for(uint64_t iel=0; iel < mesh->triangles.num; ++iel){
    for(int k=0;k<3;k++){
      int indVert=mesh->triangles.node[3*iel+k];
      if(!flagVert[indVert]){
	(*nVertSurf)++;
	flagVert[indVert]=1;
      }
    }
  }
  uint32_t *indSurfToVol;
  HXT_CHECK(hxtMalloc(&indSurfToVol, sizeof(uint32_t)*(*nVertSurf)));
  HXT_CHECK(hxtMalloc(indVolToSurf, sizeof(uint32_t)*mesh->vertices.num));
  HXT_CHECK(hxtMalloc(trianglesNodesIndSurf, sizeof(uint32_t)*3*mesh->triangles.num));
  for(uint32_t i=0; i < *nVertSurf; ++i)
    indSurfToVol[i]=-1;
  for(uint32_t i=0; i < mesh->vertices.num; ++i)
    (*indVolToSurf)[i]=-1;
  for(uint64_t i=0; i < mesh->triangles.num; ++i){
    (*trianglesNodesIndSurf)[3*i+0]=-1;
    (*trianglesNodesIndSurf)[3*i+1]=-1;
    (*trianglesNodesIndSurf)[3*i+2]=-1;
  }
  for(uint64_t i=0; i < mesh->vertices.num; ++i)
    flagVert[i]=0;
  int cptVertSurf=0;
  for(uint64_t i=0;i<mesh->triangles.num;i++){
    for(int k=0;k<3;k++){
      int indVert=mesh->triangles.node[3*i+k];
      if(!flagVert[indVert]){
	flagVert[indVert]=1;
	indSurfToVol[cptVertSurf]=indVert;
	(*indVolToSurf)[indVert]=cptVertSurf;
	cptVertSurf++;
      }
      (*trianglesNodesIndSurf)[3*i+k]=(*indVolToSurf)[indVert];
    }
  }
  for(uint64_t i=0;i<mesh->triangles.num;i++){
    for(int k=0;k<3;k++){
      if(indSurfToVol[(*trianglesNodesIndSurf)[3*i+k]]!=mesh->triangles.node[3*i+k]){
  	printf("pb renumerotation 0\n");
  	exit(0);
      }
    }
  }
  for(uint32_t i=0;i<*nVertSurf;i++){
    if((*indVolToSurf)[indSurfToVol[i]]!=i){
      printf("pb renumerotation 1\n");
      exit(0);
    }
  }
  hxtFree(&flagVert);
  hxtFree(&indSurfToVol);  
  return HXT_STATUS_OK;
}

HXTStatus computeSurfaceScaling(HXTMesh *mesh, double *frames, uint32_t nIncSurf, uint32_t nVertSurf, uint32_t *trianglesNodesIndSurf, double **scalingSurf){ //keep
  HXTLinearSystem *systemSurf;
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&systemSurf,mesh->triangles.num,3,nIncSurf,trianglesNodesIndSurf,"-ksp_type cg -ksp_monitor -ksp_info -ksp_rtol 1e-10"));
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_FAILED;
#endif
  double *rhsSurf;
  HXT_CHECK(hxtMalloc(&rhsSurf, sizeof(double)*nIncSurf*nVertSurf));
  HXT_CHECK(hxtMalloc(scalingSurf, sizeof(double)*nIncSurf*nVertSurf));
  for(uint32_t i=0;i<nIncSurf*nVertSurf;i++){
    rhsSurf[i]=0.0;
    (*scalingSurf)[i]=0.0;
  }
  printf("assemble scaling system surf\n");
  assembleScalingSysSurfCoupled(systemSurf, mesh, frames, rhsSurf, nVertSurf);
  /* assembleScalingSysSurfUncoupled(systemSurf, mesh, frames, rhsSurf, nVertSurf); */
  printf("solving system surf\n");
  HXT_CHECK(hxtLinearSystemSolve(systemSurf, rhsSurf, (*scalingSurf)));
  
  /*   // */
  HXT_CHECK(hxtLinearSystemDelete(&systemSurf));
  hxtFree(&rhsSurf);  
  return HXT_STATUS_OK;
}

HXTStatus hxtScaleCrossesFromFramesOld(HXTMesh *mesh, double *frames, double *directionsScaled){
  //Surface scaling
  /* int nIncSurf=1; */
  uint32_t *trianglesNodesIndSurf=NULL;
  uint32_t *indVolToSurf=NULL;
  /* uint32_t nVertSurf=0; */
  /* createSurfArrays(mesh, &nVertSurf, &trianglesNodesIndSurf, &indVolToSurf);  */
  double *scalingSurf=NULL;
  /* computeSurfaceScaling(mesh, frames, nIncSurf, nVertSurf, trianglesNodesIndSurf, &scalingSurf); */
  //Volume scaling
  int nInc=3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type cg -pc_type ilu -ksp_max_it 1000 -ksp_monitor -ksp_info -ksp_rtol 1e-10")); */
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type gmres -ksp_monitor -ksp_max_it 100000 -ksp_info -ksp_rtol 1e-4")); */
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type cg -ksp_monitor -ksp_max_it 100000 -ksp_info -ksp_rtol 1e-4"));
  /* -ksp_max_it 1 */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_FAILED;
#endif
  double *rhs;
  HXT_CHECK(hxtMalloc(&rhs, sizeof(double)*nInc*mesh->vertices.num));
  double *scaling;
  HXT_CHECK(hxtMalloc(&scaling, sizeof(double)*nInc*mesh->vertices.num));
  double *scalingPrec;
  HXT_CHECK(hxtMalloc(&scalingPrec, sizeof(double)*nInc*mesh->vertices.num));
  for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){
    rhs[i]=0.0;
    scaling[i]=0.0;
  }
  for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){
    scalingPrec[i]=0.0;
  }
  //DBG annulus handMade solution
  /* printf("crafting hand made solution for annulus\n"); */
  /* double *directionsAnnulus; */
  /* HXT_CHECK(hxtMalloc(&directionsAnnulus, sizeof(double)*9*mesh->vertices.num)); */
  /* craftFullAnnulusSol(mesh, directionsAnnulus, scaling); */
  /* for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){ */
  /*   scaling[i]=0.0; */
  /* } */
  /* for(uint32_t i=0;i<mesh->vertices.num;i++){ */
  /*   hxtOr3DdirectionsToFrame(directionsAnnulus+9*i, frames+9*i); */
  /* } */
  /* hxtFree(&directionsAnnulus); */
  /* printf("assemble scaling system\n"); */
  /* assembleScalingSysSmart2(system,mesh,frames,scaling,rhs); */
  /* printf("solving system\n"); */
  /* HXT_CHECK(hxtLinearSystemSolve(system, rhs, scaling)); */
  //
  /* assembleScalingSysAllFree(system,mesh,frames,rhs); */
  /* assembleScalingSysSmart(system,mesh,frames,rhs); */
  /* printf("adding boundary condition\n"); */
  /* assembleBC(system,mesh,frames,rhs,scalingSurf,indVolToSurf); */
  /* assembleBCUncoupled(system,mesh,frames,rhs,scalingSurf,indVolToSurf); */
  /* printf("solving system\n"); */
  /* HXT_CHECK(hxtLinearSystemSolve(system, rhs, scaling)); */
  //Test new minimization
  time_t depart, arrivee;
  time(&depart);
  double precisionNewSolver=1e-3;
  int maxItNewSolver=100;
  int nIt=0;
  HXTOrientation3DScal or3D;
  buildOr3DScal(&or3D, mesh, frames, scaling);
  assembleScalingSysSmart2(system,&or3D,scaling,rhs,NULL);
  double normDiff=10.0;
  double totalErrorPrec=1.0e3+1.;
  double totalError=1.0e3;
  double *errorPerTet;
  HXT_CHECK(hxtAlignedMalloc(&errorPerTet, sizeof(double)*mesh->tetrahedra.num));
  /* while(normDiff>=precisionNewSolver&&nIt<maxItNewSolver&&totalErrorPrec>totalError){ */
  while(nIt<maxItNewSolver&&totalErrorPrec>totalError){
  /* while(normDiff>=precisionNewSolver&&nIt<maxItNewSolver){ */
  /* while(nIt<maxItNewSolver){ */
    printf("-------------------************ iter : %i ************---------------\n",nIt);
    updateRhsScalingSysSmart2(system, &or3D, scaling, rhs);
    double *temp;
    temp=scalingPrec;
    scalingPrec=scaling;
    scaling=temp;
    /* assembleScalingSysSmart(system,mesh,frames,rhs); */
    printf("solving system\n");
    HXT_CHECK(hxtLinearSystemSolve(system, rhs, scaling));
    normDiff=0.0;
    for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){
      /* if((scaling[i]-scalingPrec[i])*(scaling[i]-scalingPrec[i])>normDiff) */
      /* 	normDiff=(scaling[i]-scalingPrec[i])*(scaling[i]-scalingPrec[i]); */
      normDiff+=(scaling[i]-scalingPrec[i])*(scaling[i]-scalingPrec[i]);
    }
    normDiff/=nInc*mesh->vertices.num;
    normDiff=sqrt(normDiff);
    printf("-------------------************ prec : %g / criterion : %g  ************---------------\n",normDiff,precisionNewSolver);
    totalErrorPrec=totalError;
    totalError=0.0;
    computeIntegrationErrorSmart2(&or3D,mesh, frames, scaling, errorPerTet, &totalError);
    printf("-------------------************ previous error : %g / current error : %g  ************---------------\n",totalErrorPrec,totalError);
    nIt++;
  }
  if(totalErrorPrec<totalError){
    double *temp;
    temp=scalingPrec;
    scalingPrec=scaling;
    scaling=temp;
    totalError=totalErrorPrec;
  }
  //
  /* printf("grab solution on surf\n"); */
  /* for(uint64_t i=0;i<mesh->triangles.num;i++){ */
  /*   for(int k=0;k<3;k++){ */
  /*     int indVert=mesh->triangles.node[3*i+k]; */
  /*     /\* scaling[3*indVert]=scalingSurf[3*indVolToSurf[indVert]+0]; *\/ */
  /*     /\* scaling[3*indVert+1]=scalingSurf[3*indVolToSurf[indVert]+1]; *\/ */
  /*     /\* scaling[3*indVert+2]=scalingSurf[3*indVolToSurf[indVert]+2]; *\/ */
  /*     scaling[3*indVert]=scalingSurf[indVolToSurf[indVert]]; */
  /*     scaling[3*indVert+1]=scalingSurf[indVolToSurf[indVert]]; */
  /*     scaling[3*indVert+2]=scalingSurf[indVolToSurf[indVert]]; */
  /*     scaling2[indVert]=exp(scalingSurf[indVolToSurf[indVert]]); */
  /*   } */
  /* } */
  /* printf("write scaling at node\n"); */
  /* hxtOr3dWritePosScalarNode(mesh, scaling2, "scaling.pos"); */
  printf("scaling crosses\n");
  double *directions;
  HXT_CHECK(hxtMalloc(&directions, sizeof(double)*9*mesh->vertices.num));
  frameToScaledCrosses(mesh,scaling,frames,directionsScaled);
  printf("compute integration error\n");
  /* totalError=0.0; */
  /* computeIntegrationErrorSmart2(&or3D,mesh, frames, scaling, errorPerTet, &totalError); */
  destroyOr3DScal(&or3D);  
  hxtOr3DWritePosScalarTet(mesh, NULL, errorPerTet, "error.pos");
  printf("totalError on integration : %g\n",totalError);
  time(&arrivee);
  printf("Solving time : %f s. (including io)\n", difftime(arrivee, depart));
  HXT_CHECK(hxtLinearSystemDelete(&system));
  HXT_CHECK(hxtAlignedFree(&errorPerTet));
  hxtFree(&scaling);
  hxtFree(&scalingPrec);
  if(scalingSurf)
    hxtFree(&scalingSurf);
  hxtFree(&rhs);
  hxtFree(&directions);
  if(indVolToSurf)
    hxtFree(&indVolToSurf);
  if(trianglesNodesIndSurf)
    hxtFree(&trianglesNodesIndSurf);
  return HXT_STATUS_OK;
}

HXTStatus scaleCrossesFromFrames(HXTMesh *mesh, double *frames, double *directionsScaled, double *smoothnessIndicator){
  //Volume scaling
  int nInc=3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type cg -pc_type ilu -ksp_max_it 1000 -ksp_monitor -ksp_info -ksp_rtol 1e-10")); */
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type gmres -ksp_monitor -ksp_max_it 100000 -ksp_info -ksp_rtol 1e-4")); */
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type cg -ksp_monitor -ksp_max_it 100000 -ksp_info -ksp_rtol 1e-4"));
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_FAILED;
#endif
  /* double *smoothnessIndicator; */
  /* HXT_CHECK(hxtMalloc(&smoothnessIndicator, sizeof(double)*mesh->tetrahedra.num)); */
  double *rhs;
  HXT_CHECK(hxtMalloc(&rhs, sizeof(double)*nInc*mesh->vertices.num));
  double *scaling;
  HXT_CHECK(hxtMalloc(&scaling, sizeof(double)*nInc*mesh->vertices.num));
  double *scalingPrec;
  HXT_CHECK(hxtMalloc(&scalingPrec, sizeof(double)*nInc*mesh->vertices.num));
  for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){
    rhs[i]=0.0;
    scaling[i]=0.0;
  }
  for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){
    scalingPrec[i]=0.0;
  }
  //Test new minimization
  printf("new scaling solver\n");
  time_t depart, arrivee;
  time(&depart);
  int maxItNewSolver=100;
  int nIt=0;
  HXTOrientation3DScal or3D;
  buildOr3DScal(&or3D, mesh, frames, scaling);
  assembleScalingSysSmart2(system,&or3D,scaling,rhs,smoothnessIndicator);
  double totalErrorPrec=1.0e3+1.;
  double totalError=1.0e3;
  double *errorPerTet;
  HXT_CHECK(hxtAlignedMalloc(&errorPerTet, sizeof(double)*mesh->tetrahedra.num));
  while(nIt<maxItNewSolver&&totalErrorPrec>totalError+1e-12){
    printf("-------------------************ iter : %i ************---------------\n",nIt);
    updateRhsScalingSysSmart2(system, &or3D, scaling, rhs);
    double *temp;
    temp=scalingPrec;
    scalingPrec=scaling;
    scaling=temp;
    printf("solving system\n");
    HXT_CHECK(hxtLinearSystemSolve(system, rhs, scaling));
    totalErrorPrec=totalError;
    totalError=0.0;
    printf("computing integration error\n");
    computeIntegrationErrorSmart2(&or3D,mesh, frames, scaling, errorPerTet, &totalError);
    printf("-------------------************ previous error : %g / current error : %g  / Diff : %g************---------------\n",totalErrorPrec,totalError,totalErrorPrec-totalError);
    nIt++;
  }
  if(totalErrorPrec<totalError){
    double *temp;
    temp=scalingPrec;
    scalingPrec=scaling;
    scaling=temp;
    totalError=totalErrorPrec;
  }
  printf("scaling crosses\n");
  double *directions;
  HXT_CHECK(hxtMalloc(&directions, sizeof(double)*9*mesh->vertices.num));
  frameToScaledCrosses(mesh,scaling,frames,directionsScaled);
  /* printf("compute integration error\n"); */
  /* totalError=0.0; */
  /* computeIntegrationErrorSmart2(&or3D,mesh, frames, scaling, errorPerTet, &totalError); */
  destroyOr3DScal(&or3D);  
  /* hxtOr3DWritePosScalarTet(mesh, NULL, errorPerTet, "error.pos"); */
  /* if(smoothnessIndicator) */
  /*   hxtOr3DWritePosScalarTet(mesh, NULL, smoothnessIndicator, "smoothness.pos"); */
  /* double *directionsScaledElem; */
  /* HXT_CHECK(hxtMalloc(&directionsScaledElem, sizeof(double)*9*mesh->tetrahedra.num)); */
  /* hxtOr3DcrossNodesToElem(mesh, directionsScaled, directionsScaledElem, smoothnessIndicator); */
  /* hxtOr3DWritePosScalarTet(mesh, NULL, smoothnessIndicator, "smoothness.pos"); */
  /* hxtOr3DWritePosCrossesFromDirectionsElem(mesh, directionsScaledElem, "crossesScaledElem.pos", NULL); */
  /* hxtFree(&directionsScaledElem); */
  /* printf("totalError on integration : %g\n",totalError); */
  time(&arrivee);
  printf("Solving time : %f s. (including io)\n", difftime(arrivee, depart));
  HXT_CHECK(hxtLinearSystemDelete(&system));
  HXT_CHECK(hxtAlignedFree(&errorPerTet));
  hxtFree(&scaling);
  hxtFree(&scalingPrec);
  hxtFree(&rhs);
  /* hxtFree(&smoothnessIndicator); */
  hxtFree(&directions);
  /* //Restoring mesh and solution */
  /* cleanMeshRestoreMesh(&cleanMeshObj); */
  /* uint32_t nFieldsSol=9; */
  /* cleanMeshRestoreSolution(&cleanMeshObj,directionsScaled,nFieldsSol); */
  /* cleanMeshRestoreSolution(&cleanMeshObj,frames,nFieldsSol); */
  /* cleanMeshDestroy(&cleanMeshObj); */
  return HXT_STATUS_OK;
}

HXTStatus hxtScaleCrossesFromFrames(HXTMesh *mesh, double *frames, double *directionsScaled, double *smoothnessIndicator){
  //Renumbering nodes if there is alone vertices
  HXTOrientation3DCleanMesh cleanMeshObj;
  buildCleanMesh(&cleanMeshObj,mesh);
  cleanMeshCleanSolution(&cleanMeshObj, frames, 9);
  scaleCrossesFromFrames(mesh, frames, directionsScaled, smoothnessIndicator);
  //Restoring mesh and solution
  cleanMeshRestoreMesh(&cleanMeshObj);
  uint32_t nFieldsSol=9;
  cleanMeshRestoreSolution(&cleanMeshObj,directionsScaled,nFieldsSol);
  cleanMeshRestoreSolution(&cleanMeshObj,frames,nFieldsSol);
  cleanMeshDestroy(&cleanMeshObj);
  return HXT_STATUS_OK;
}

HXTStatus computeBCQuad(HXTMesh *tetMesh, HXTMesh *quadMesh, double *frames, double *scaling, int *flagBC){
  uint32_t *quadToTet;
  uint32_t *tetToQuad;
  HXT_CHECK(hxtMalloc(&quadToTet, quadMesh->vertices.num*sizeof(uint32_t)));
  for(int k=0;k<quadMesh->vertices.num;k++){
    quadToTet[k]=(uint32_t)(-1);
  }
  HXT_CHECK(hxtMalloc(&tetToQuad, tetMesh->vertices.num*sizeof(uint32_t)));
  for(int k=0;k<tetMesh->vertices.num;k++){
    tetToQuad[k]=(uint32_t)(-1);
  }
  //Building normals
  int nNodesOnBnd=0;
  double *normals;
  HXT_CHECK(hxtMalloc(&normals, tetMesh->vertices.num*2*3*sizeof(double)));
  HXT_CHECK(computeBndNormalsScaling(tetMesh, normals));
  for(uint32_t ivT=0; ivT<tetMesh->vertices.num; ivT++){
    double normN=0.0;
    hxtNorm2V(normals+3*ivT, 3, &normN);
    if(normN>1e-6){
      nNodesOnBnd++;
    }
  }
  uint32_t *indTetVertBnd;
  HXT_CHECK(hxtMalloc(&indTetVertBnd, nNodesOnBnd*sizeof(uint32_t)));
  nNodesOnBnd=0;
  for(uint32_t ivT=0; ivT<tetMesh->vertices.num; ivT++){
    double normN=0.0;
    hxtNorm2V(normals+3*ivT, 3, &normN);
    if(normN>1e-6){
      indTetVertBnd[nNodesOnBnd]=ivT;
      nNodesOnBnd++;
    }
  }
  printf("nNodes on boundary : %i\n",nNodesOnBnd);
  //match all quad nodes to tet nodes
  uint32_t *nodeBelongToQuad;
  HXT_CHECK(hxtMalloc(&nodeBelongToQuad, quadMesh->vertices.num*sizeof(uint32_t)));
  for(uint32_t ivQ=0; ivQ<quadMesh->vertices.num; ivQ++)
    nodeBelongToQuad[ivQ]=0;

  int cptMatchingNodes=0;
  for(uint64_t iQ=0; iQ<quadMesh->quads.num; iQ++){
    for(int k=0;k<4;k++){
      uint32_t ivQ = quadMesh->quads.node[4*iQ+k];
      nodeBelongToQuad[ivQ]++;
      double *coordQ = quadMesh->vertices.coord + 4*ivQ;
      for(uint32_t ivTbnd=0; ivTbnd<nNodesOnBnd; ivTbnd++){
	int ivT=indTetVertBnd[ivTbnd];
	double *coordT = tetMesh->vertices.coord + 4*ivT;
	double normDiff = 0.0;
	for(int l=0;l<3;l++)
	  normDiff+=(coordQ[l]-coordT[l])*(coordQ[l]-coordT[l]);
	normDiff=sqrt(normDiff);
	// printf("normDiff : %g\n",normDiff);
	if(normDiff<1e-8){
	  if(quadToTet[ivQ]==(uint32_t)(-1)){
	    quadToTet[ivQ]=ivT;
	    tetToQuad[ivT]=ivQ;
	    cptMatchingNodes++;
	  }
	}
      }
    }
  }
  int cptNNodesInQuads=0;
  for(uint32_t ivQ=0; ivQ<quadMesh->vertices.num; ivQ++){
    if(nodeBelongToQuad[ivQ]>0)
      cptNNodesInQuads++;
  }
  printf("nNodes in boundary quad mesh : %i\n", quadMesh->vertices.num);
  printf("nNodes belonging to quads : %i\n", cptNNodesInQuads);
  printf("--number nodes matching : %i\n",cptMatchingNodes);
  //make a list of all surface nodes (it's the list of quadMesh nodes which have not -1 in quadToTet)
  //for each surface node, extract the crosses directions
  //for each quad of the surface, for each quad node add size of edges to node branch size
  //we add edge length to the closest branch. keep track of the number of addition
  int *nAddScaling;
  HXT_CHECK(hxtMalloc(&nAddScaling, quadMesh->vertices.num*3*sizeof(int)));
  for(uint64_t ivQ=0; ivQ<3*quadMesh->vertices.num; ivQ++)
    nAddScaling[ivQ]=0;
  printf("adding scaling\n");
  for(uint64_t iQ=0; iQ<quadMesh->quads.num; iQ++){
    for(int k=0;k<4;k++){
      uint32_t ivQ = quadMesh->quads.node[4*iQ+k];
      if(quadToTet[ivQ]!=(uint32_t)(-1)){
	uint32_t ivQ1 = quadMesh->quads.node[4*iQ+((k+1)%4)];
	uint32_t ivQ2 = quadMesh->quads.node[4*iQ+((k+3)%4)];
	double *coordQ = quadMesh->vertices.coord + 4*ivQ;
	double *coordQ1 = quadMesh->vertices.coord + 4*ivQ1;
	double *coordQ2 = quadMesh->vertices.coord + 4*ivQ2;
	double d1[3]={0.0};
	double d2[3]={0.0};
	for(int l=0;l<3;l++){
	  d1[l]=coordQ1[l]-coordQ[l];
	  d2[l]=coordQ2[l]-coordQ[l];
	}
	double normD1=0.0;
	double normD2=0.0;
	hxtNorm2V(d1, 3, &normD1);
	hxtNorm2V(d2, 3, &normD2);
	hxtNormalizeV3(d1);
	hxtNormalizeV3(d2);
	//get closest branch l1 et l2
	int l1,l2=-1;
	double *frameNode=frames + 9*quadToTet[ivQ];
	double stableDir[3]={0.0};
	double dirCross[9]={0.0};
	hxtOr3DframeToDirections(frameNode, stableDir, dirCross);
	double maxPS1=0.0;
	double maxPS2=0.0;
	for(int l=0;l<3;l++){
	  double PS1=0.0;
	  double PS2=0.0;
	  hxtOr3DdotProd(d1, dirCross+3*l, 3, &PS1);
	  hxtOr3DdotProd(d2, dirCross+3*l, 3, &PS2);
	  if(fabs(PS1)>maxPS1){
	    l1=l;
	    maxPS1=fabs(PS1);
	  }
	  if(fabs(PS2)>maxPS2){
	    l2=l;
	    maxPS2=fabs(PS2);
	  }
	}
	scaling[3*quadToTet[ivQ]+l1]+=normD1;
	scaling[3*quadToTet[ivQ]+l2]+=normD2;
	nAddScaling[3*ivQ+l1]++;
	nAddScaling[3*ivQ+l2]++;
      }
    }
  }
  printf("taking log\n");
  //take log
  for(uint32_t ivQ=0; ivQ<quadMesh->vertices.num; ivQ++){
    if(quadToTet[ivQ]!=(uint32_t)(-1)){
      for(int k=0;k<3;k++){
	if(nAddScaling[3*ivQ+k]>0){
	  scaling[3*quadToTet[ivQ]+k]/=nAddScaling[3*ivQ+k];
	  scaling[3*quadToTet[ivQ]+k]=log(scaling[3*quadToTet[ivQ]+k]);
	  flagBC[3*quadToTet[ivQ]+k]=1;
	}
      }
    }
  }
  printf("freeing memory\n");
  //done
  HXT_CHECK(hxtFree(&normals));
  HXT_CHECK(hxtFree(&nAddScaling));
  HXT_CHECK(hxtFree(&quadToTet));
  HXT_CHECK(hxtFree(&tetToQuad));
  return HXT_STATUS_OK;
}

HXTStatus scaleCrossesFromFramesQuadBC(HXTMesh *mesh, HXTMesh *quadMesh, double *frames, double *directionsScaled, double *smoothnessIndicator){
  //Volume scaling
  int nInc=3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_monitor -ksp_max_it 10000 -ksp_info -ksp_rtol 1e-12")); */
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type bcgs -ksp_monitor -ksp_max_it 10000 -ksp_info -ksp_rtol 1e-12"));
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_FAILED;
#endif
  double *rhs;
  HXT_CHECK(hxtMalloc(&rhs, sizeof(double)*nInc*mesh->vertices.num));
  double *scaling;
  HXT_CHECK(hxtMalloc(&scaling, sizeof(double)*nInc*mesh->vertices.num));
  for(uint32_t i=0;i<nInc*mesh->vertices.num;i++){
    rhs[i]=0.0;
    scaling[i]=0.0;
  }
  printf("scaling solver with quad BC\n");
  time_t depart, arrivee;
  time(&depart);
  HXTOrientation3DScal or3D;
  buildOr3DScal(&or3D, mesh, frames, scaling);
  /* assembleScalingSysSmart2(system,&or3D,scaling,rhs,smoothnessIndicator); */
  assembleScalingSysSmart3(system,&or3D,scaling,rhs,smoothnessIndicator);
  double totalError=1.0e3;
  double *errorPerTet;
  HXT_CHECK(hxtAlignedMalloc(&errorPerTet, sizeof(double)*mesh->tetrahedra.num));
  //compute BC and put them into double *scaling
  int *flagBC;
  HXT_CHECK(hxtMalloc(&flagBC, sizeof(int)*nInc*mesh->vertices.num));
  for(uint32_t i=0;i<nInc*mesh->vertices.num;i++)
    flagBC[i]=0;
  printf("compute BC\n");
  computeBCQuad(mesh,quadMesh,frames,scaling,flagBC);
  printf("end compute bc********************************\n");
  /* updateRhsScalingSysSmart2(system, &or3D, scaling, rhs); */
  int nDDL=0;
  int nBC=0;
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    for(uint32_t k=0;k<nInc;k++){
      nDDL++;
      if(flagBC[nInc*i+k]>0){
  	nBC++;
  	hxtLinearSystemSetMatrixRowIdentity(system, i, k);
  	hxtLinearSystemSetRhsEntry(system, rhs, i, k, scaling[nInc*i+k]);
      }
    }
  }
  printf("nDDL : %i, nBC : %i\n",nDDL,nBC);
  HXT_CHECK(hxtFree(&flagBC));
  printf("solve\n");
  HXT_CHECK(hxtLinearSystemSolve(system, rhs, scaling));
  printf("end solve\n");
  totalError=0.0;
  printf("computing integration error\n");
  computeIntegrationErrorSmart2(&or3D,mesh, frames, scaling, errorPerTet, &totalError);
  printf("-------------------************ current error : %g************---------------\n",totalError);
  printf("scaling crosses\n");
  double *directions;
  HXT_CHECK(hxtMalloc(&directions, sizeof(double)*9*mesh->vertices.num));
  frameToScaledCrosses(mesh,scaling,frames,directionsScaled);
  destroyOr3DScal(&or3D);  
  time(&arrivee);
  printf("Solving time : %f s. (including io)\n", difftime(arrivee, depart));
  HXT_CHECK(hxtLinearSystemDelete(&system));
  HXT_CHECK(hxtAlignedFree(&errorPerTet));
  hxtFree(&scaling);
  hxtFree(&rhs);
  hxtFree(&directions);
  return HXT_STATUS_OK;
}

HXTStatus hxtScaleCrossesFromFramesQuadBC(HXTMesh *mesh, HXTMesh *quadMesh, double *frames, double *directionsScaled, double *smoothnessIndicator){
  //Renumbering nodes if there is alone vertices
  HXTOrientation3DCleanMesh cleanMeshObj;
  buildCleanMesh(&cleanMeshObj,mesh);
  cleanMeshCleanSolution(&cleanMeshObj, frames, 9);
  scaleCrossesFromFramesQuadBC(mesh, quadMesh, frames, directionsScaled, smoothnessIndicator);
  //Restoring mesh and solution
  cleanMeshRestoreMesh(&cleanMeshObj);
  uint32_t nFieldsSol=9;
  cleanMeshRestoreSolution(&cleanMeshObj,directionsScaled,nFieldsSol);
  cleanMeshRestoreSolution(&cleanMeshObj,frames,nFieldsSol);
  cleanMeshDestroy(&cleanMeshObj);
  return HXT_STATUS_OK;
}
