#include "hxt_orientation3d_NL.h"
/* #include "hxt_orientation3dExplicit.h" */
#include "inttypes.h"
// #include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_linear_system.h"
#include "hxt_non_linear_solver.h"
#include "hxt_orientation3d_tools.h"
#include "hxt_orientation3d_io.h"
#include "hxt_orientation3d_scaling.h"
#include "hxt_orientation3d_integrability.h"
#include "hxt_orientation3d_cleanMeshStruct.h"
#include <math.h>
#include <stdio.h>
#include <time.h>

struct HXTOrientation3DStruct {
  HXTMesh *mesh;
  double *frames; // frame 9x1
  double *normals; // normals
  double **elemMatLapl;
  double *elemDetLapl;
  double **bcMat;
  double **bcD;
  double epsilonGlob;
  double *epsilonLoc;
  double epsilonBC;
  double base[6][6][10];
  double crossProdBase[10][10][6][6];
  double crossProdBaseSym[10][10][6][6];
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

void addHessToLocalMat(double *localMatrix, double Hn[9][9], double detj, double epsilon)
{
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j) {
      for (int l = 0; l < 9; ++l){
	for (int k = 0; k < 9; ++k) {
	  localMatrix[(l*4+i)*36+k*4+j] += 1./4.*1./4.*Hn[l][k]*(1/epsilon)*(detj/6);
	}
      }
    }
  }
}

void addGradToLocalRhs(double *localRhs, double Gn[9], double detj, double epsilon)
{
  double r=0;
  for (int k = 0; k < 9; ++k) {
    r = 1./4.*(Gn[k])*(detj/6)*(1/epsilon);
    for (int i = 0; i < 4; ++i){
      localRhs[k*4+i] += r;
    }
  }
}


void computeGradPenalty(HXTOrientation3D *or3D, double grad[9], double solGauss[9]){
  for (int i = 0; i < 9; ++i)
    grad[i]=0.0;
  double L[6][6]={{0.0}};
  double a[10]={0.0};
  for (int i = 0; i < 9; ++i)
    a[i]=solGauss[i];
  a[9]=sqrt(9.0/5.0);
  for (int k = 0; k < 6; ++k)
    for (int l = k; l < 6; ++l)
      for (int i = 0; i < 10; ++i){
	L[k][l]-=a[i]*or3D->base[k][l][i];
	for (int j = 0; j < 10; ++j)
	  L[k][l]+=a[i]*a[j]*or3D->crossProdBase[i][j][k][l];
      }
  double Gtilde[9][6][6]={{{0.0}}};
  for (int k = 0; k < 6; ++k)
    for (int l = k; l < 6; ++l)
      for (int m = 0; m < 9; ++m){
	Gtilde[m][k][l]-=or3D->base[k][l][m];
	for (int i = 0; i < 10; ++i)
	  Gtilde[m][k][l]+=a[i]*(or3D->crossProdBaseSym[m][i][k][l]);
      }
  for (int m = 0; m < 9; ++m)
    for (int k = 0; k < 6; ++k)
      for (int l = k; l < 6; ++l) 
	grad[m]+=L[k][l]*Gtilde[m][k][l];
  return;
}

void computeHessPenalty(HXTOrientation3D *or3D, double H[9][9], double solGauss[9]){
  for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j)
      H[i][j]=0.0;
  double L[6][6]={{0.0}};
  double a[10]={0.0};
  for (int i = 0; i < 9; ++i)
    a[i]=solGauss[i];
  a[9]=sqrt(9.0/5.0);
  for (int k = 0; k < 6; ++k)
    for (int l = 0; l < 6; ++l)
      for (int i = 0; i < 10; ++i){
	L[k][l]-=a[i]*or3D->base[k][l][i];
	for (int j = 0; j < 10; ++j)
	  L[k][l]+=a[i]*a[j]*or3D->crossProdBase[i][j][k][l];
      }
  double Gtilde[9][6][6]={{{0.0}}};
  double crossProdSymBase[10][10][6][6]={{{{0.0}}}};
  for (int i = 0; i < 10; ++i)
    for (int j = 0; j < 10; ++j)
      for (int k = 0; k < 6; ++k)
	for (int l = 0; l < 6; ++l)
	    crossProdSymBase[i][j][k][l]+=or3D->crossProdBase[i][j][k][l]+or3D->crossProdBase[j][i][k][l];
	  
  for (int k = 0; k < 6; ++k)
    for (int l = 0; l < 6; ++l)
      for (int m = 0; m < 9; ++m){
	Gtilde[m][k][l]-=or3D->base[k][l][m];
	for (int i = 0; i < 10; ++i)
	  Gtilde[m][k][l]+=a[i]*(or3D->crossProdBase[m][i][k][l]+or3D->crossProdBase[i][m][k][l]);
      }
  for (int m = 0; m < 9; ++m)
    for (int n = 0; n < 9; ++n)
      for (int k = 0; k < 6; ++k)
	for (int l = k; l < 6; ++l)
	  H[m][n]+=Gtilde[m][k][l]*Gtilde[n][k][l]+L[k][l]*crossProdSymBase[m][n][k][l];
  
  return;
}

HXTStatus setEpsilon(HXTMesh *mesh, double *epsilon){
  double minLength = -1;
  double maxLength = 0.0;
  double length = 0.;
  for(uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    uint32_t *tet = mesh->tetrahedra.node + 4*iel;
    double *x[4] = {
      mesh->vertices.coord + 4*tet[0],
      mesh->vertices.coord + 4*tet[1],
      mesh->vertices.coord + 4*tet[2],
      mesh->vertices.coord + 4*tet[3],
    };
    for (int i=0; i < 4; ++i) {
      for (int j=i+1; j < 4; ++j) {
	length = sqrt((x[j][0]-x[i][0])*(x[j][0]-x[i][0]) + (x[j][1]-x[i][1])*(x[j][1]-x[i][1]) + (x[j][2]-x[i][2])*(x[j][2]-x[i][2]));
	if(minLength<0)
	  minLength = length;
	else{
	  if(minLength>length)
	    minLength = length;
	  if(maxLength<length)
	    maxLength = length;
	}
      }
    }
  }
  printf("minLenght = %g\n",minLength);
  printf("maxLenght = %g\n",maxLength);
  //DBG
  /* *epsilon = (4*minLength)*(4*minLength); */
  /* *epsilon = (minLength)*(minLength); */
  *epsilon = (maxLength/4.0)*(maxLength/4.0);
  return HXT_STATUS_OK;
}

HXTStatus computeBndNormals(HXTMesh *mesh, double *normals) {
  int *numTriByNode;
  HXT_CHECK(hxtMalloc(&numTriByNode, sizeof(int)*mesh->vertices.num));
  int *isSharp;
  HXT_CHECK(hxtMalloc(&isSharp, sizeof(int)*mesh->vertices.num));
  int *isTooSharp;
  HXT_CHECK(hxtMalloc(&isTooSharp, sizeof(int)*mesh->vertices.num));
  int nEdgSharp=0;
  int nEdgTooSharp=0;
  int nBndEdges=0;
  for(uint32_t i=0; i<mesh->vertices.num; ++i){
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
  for (uint64_t i = 0; i < mesh->vertices.num; ++i) {
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
  for(uint32_t i=0; i<mesh->vertices.num; ++i){
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
  for(uint32_t i=0; i<mesh->vertices.num; ++i){
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

HXTStatus setInitialFrames(HXTMesh *mesh,double *frames, double *normals, int hasToBeInitialized)
{
  if(hasToBeInitialized){
    double *n;
    for (uint32_t iv = 0; iv < mesh->vertices.num; ++iv) {
      n = normals + 3*iv;
      const double normN2 = n[0]*n[0]+n[1]*n[1]+n[2]*n[2];
      if (normN2 > 0.01) {
	  hxtOr3DnormalEulerToFrame(n, 0.0, frames+9*iv);
      }
      else{
	double *d= frames+9*iv;
	d[0]=0.63246;
	d[1]=0.63246;
	d[2]=0.63246;
	/* d[0]=0.; */
	/* d[1]=0.; */
	/* d[2]=0.; */
	d[3]=0.0;
	d[4]=0.0;
	d[5]=0.0;
	d[6]=0.0;
	d[7]=0.0;
	d[8]=0.0;
      }
    }
  }
  return HXT_STATUS_OK;
}

static HXTStatus computeBoundaryGrad(const double *B, const double D[9], const double solNode[9], double rhs[9]) {
  for(uint8_t i=0;i<9;i++){
    rhs[i]=0.0;
    for(uint8_t k=0;k<9;k++){
      rhs[i] += B[i*9+k] * (solNode[k]-D[k]);
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus addBoundaryHessToOp(HXTLinearSystem *lsys, const double *frames, uint32_t iv, HXTOrientation3D *or3D){
  double epsilon = or3D->epsilonBC;
  double *localMatrix;
  HXT_CHECK(hxtMalloc(&localMatrix, sizeof(double)*81));
  double *solElem;
  HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*9));
  for (int i=0; i < 81; ++i)
    localMatrix[i] = 0;
  for (int k=0; k < 9; ++k)
    solElem[k] = frames[9*iv+k];

  for (int l = 0; l < 9; ++l){
    for (int k = 0; k < 9; ++k) {
      localMatrix[l*9+k] = *(or3D->bcMat[iv]+l*9+k)*epsilon;
    }
  }

  for (int k = 0; k < 9; ++k){
    for (int l = 0; l < 9; ++l)
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(lsys, iv, k, iv, l, localMatrix[l*9+k]));
  }
  HXT_CHECK(hxtFree(&localMatrix));
  HXT_CHECK(hxtFree(&solElem));
  return HXT_STATUS_OK;
}

HXTStatus addBoundaryHessToOpEuler(HXTLinearSystem *lsys, const double *eulerSol, uint32_t iv, HXTOrientation3D *or3D){
  double epsilon = or3D->epsilonBC;
  double *localMatrixFrame;
  HXT_CHECK(hxtMalloc(&localMatrixFrame, sizeof(double)*81));
  double *localMatrixEuler;
  HXT_CHECK(hxtMalloc(&localMatrixEuler, sizeof(double)*9));
  double *solElem;
  HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*9));
  for (int i=0; i < 81; ++i)
    localMatrixFrame[i] = 0;
  for (int i=0; i < 9; ++i)
    localMatrixEuler[i] = 0;
  hxtOr3DeulerToFrame(eulerSol+3*iv, solElem);

  for (int l = 0; l < 9; ++l){
    for (int k = 0; k < 9; ++k) {
      localMatrixFrame[l*9+k] = *(or3D->bcMat[iv]+l*9+k)*epsilon;
    }
  }

  double dBdEuler[9][3]={{0.0}};
  hxtOr3DdBdEuler(eulerSol+3*iv, dBdEuler);
  for (int kEul = 0; kEul < 3; ++kEul)
    for (int lEul = 0; lEul < 3; ++lEul)
      for (int k = 0; k < 9; ++k)
	for (int l = 0; l < 9; ++l)
	  localMatrixEuler[kEul*3+lEul] += localMatrixFrame[k*9+l]*dBdEuler[k][kEul]*dBdEuler[l][lEul];
	  
  for (int kEul = 0; kEul < 3; ++kEul){
    for (int lEul = 0; lEul < 3; ++lEul)
      HXT_CHECK(hxtLinearSystemAddMatrixEntry(lsys, iv, kEul, iv, lEul, localMatrixEuler[kEul*3+lEul]));
  }
  HXT_CHECK(hxtFree(&localMatrixFrame));
  HXT_CHECK(hxtFree(&localMatrixEuler));
  HXT_CHECK(hxtFree(&solElem));
  return HXT_STATUS_OK;
}

HXTStatus addBoundaryGradToRhsEuler(HXTLinearSystem *lsys, double *rhs, const double *eulerSol, uint32_t iv, HXTOrientation3D *or3D){
  double epsilon = or3D->epsilonBC;
  double *localRhsFrame;
  HXT_CHECK(hxtMalloc(&localRhsFrame, sizeof(double)*9));
  double *localRhsEuler;
  HXT_CHECK(hxtMalloc(&localRhsEuler, sizeof(double)*3));
  double *solElem;
  HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*9));
  for (int i=0; i < 9; ++i)
    localRhsFrame[i] = 0;
  for (int i=0; i < 3; ++i)
    localRhsEuler[i] = 0;
  hxtOr3DeulerToFrame(eulerSol+3*iv, solElem);

  double R[9]={0.0};
  computeBoundaryGrad(or3D->bcMat[iv], or3D->bcD[iv], solElem, R);
  
  for (int k = 0; k < 9; ++k) {
    localRhsFrame[k] = R[k]*epsilon;
  }

  double dBdEuler[9][3]={{0.0}};
  hxtOr3DdBdEuler(eulerSol+3*iv, dBdEuler);
  for (int kEul = 0; kEul < 3; ++kEul){
    for (int k = 0; k < 9; ++k){
      localRhsEuler[kEul]+=localRhsFrame[k]*dBdEuler[k][kEul];
    }
  }
  for (int kEul = 0; kEul < 3; ++kEul){
    HXT_CHECK(hxtLinearSystemAddRhsEntry(lsys, rhs, iv, kEul, localRhsEuler[kEul]));
  }
  HXT_CHECK(hxtFree(&localRhsFrame));
  HXT_CHECK(hxtFree(&localRhsEuler));
  HXT_CHECK(hxtFree(&solElem));
  return HXT_STATUS_OK;
}

HXTStatus addBoundaryGradToRhs(HXTLinearSystem *lsys, double *rhs, const double *frames, uint32_t iv, HXTOrientation3D *or3D){
  double epsilon = or3D->epsilonBC;
  double *localRhs;
  HXT_CHECK(hxtMalloc(&localRhs, sizeof(double)*9));
  double *solElem;
  HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*9));
  for (int i=0; i < 9; ++i)
    localRhs[i] = 0;
  for (int k=0; k < 9; ++k)
    solElem[k] = frames[9*iv+k];

  double R[9]={0.0};
  computeBoundaryGrad(or3D->bcMat[iv], or3D->bcD[iv], solElem, R);
  
  for (int k = 0; k < 9; ++k) {
    localRhs[k] = R[k]*epsilon;
  }

  for (int k = 0; k < 9; ++k){
    HXT_CHECK(hxtLinearSystemAddRhsEntry(lsys, rhs, iv, k, localRhs[k]));
  }
  HXT_CHECK(hxtFree(&localRhs));
  HXT_CHECK(hxtFree(&solElem));
  return HXT_STATUS_OK;
}

static HXTStatus hxtOr3DH(void *data, const double *frames, HXTLinearSystem *lsys)
{
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double *localMatrix;
  HXT_CHECK(hxtMalloc(&localMatrix, sizeof(double)*16*81));
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i=0; i < 16*81; ++i)
      localMatrix[i] = 0.0;
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 9; ++k)
          localMatrix[(k*4+i)*36+k*4+j] = *(or3D->elemMatLapl[iel]+4*i+j);
      }
    }
    double *solElem;
    HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9));
    for (int i=0; i < 4; ++i)
      for (int k=0; k < 9; ++k)
	solElem[k*4+i] = frames[9*tet[i]+k];
    // Operator constraint A^2=A
    double Hn[9][9];
    double solGauss[9];
    for (int i=0; i < 9; ++i)
      solGauss[i] = 1./4.*(solElem[4*i+0]+solElem[4*i+1]+solElem[4*i+2]+solElem[4*i+3]);
    computeHessPenalty(or3D, Hn, solGauss);
    addHessToLocalMat(localMatrix, Hn, or3D->elemDetLapl[iel], or3D->epsilonLoc[iel]);
    //
    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix));
    HXT_CHECK(hxtFree(&solElem));
  }
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryHessToOp(lsys, frames, iv, or3D);
  }
  HXT_CHECK(hxtFree(&localMatrix));
  return HXT_STATUS_OK;
}

static HXTStatus hxtOr3DHEuler(void *data, const double *eulerSol, HXTLinearSystem *lsys)
{
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  HXT_CHECK(hxtLinearSystemZeroMatrix(lsys));
  double *localMatrixFrame;
  HXT_CHECK(hxtMalloc(&localMatrixFrame, sizeof(double)*16*81));
  double *localMatrixEuler;
  HXT_CHECK(hxtMalloc(&localMatrixEuler, sizeof(double)*16*9));
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i=0; i < 16*81; ++i)
      localMatrixFrame[i] = 0.0;
    for (int i=0; i < 16*9; ++i)
      localMatrixEuler[i] = 0.0;
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 4; ++j){
        for (int k = 0; k < 9; ++k)
          localMatrixFrame[(k*4+i)*36+k*4+j] = *(or3D->elemMatLapl[iel]+4*i+j);
      }
    }
    double *solElem;
    HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9));
    for (int i=0; i < 4; ++i){
      double frameNodeI[9]={0.0};
      hxtOr3DeulerToFrame(eulerSol+3*tet[i], frameNodeI);
      for (int k=0; k < 9; ++k)
  	solElem[k*4+i] = frameNodeI[k];
    }
    double dBdEulerTet[4][9][3]={{{0.0}}};
    for (int i=0; i < 4; ++i){
      double dBdEulerI[9][3]={{0.0}};
      hxtOr3DdBdEuler(eulerSol+3*tet[i], dBdEulerI);
      for (int k = 0; k < 9; ++k)
  	for (int j = 0; j < 3; ++j)
  	  dBdEulerTet[i][k][j]=dBdEulerI[k][j];
    }

    for (int kEul = 0; kEul < 3; ++kEul)
      for (int lEul = 0; lEul < 3; ++lEul)
  	for (int i = 0; i < 4; ++i)
  	  for (int j = 0; j < 4; ++j)
  	    for (int k = 0; k < 9; ++k)
  	      for (int l = 0; l < 9; ++l)
  		localMatrixEuler[(kEul*4+i)*12+(lEul*4+j)] += localMatrixFrame[(k*4+i)*36+l*4+j]*dBdEulerTet[i][k][kEul]*dBdEulerTet[j][l][lEul];

    HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrixEuler));
    HXT_CHECK(hxtFree(&solElem));
  }
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryHessToOpEuler(lsys, eulerSol, iv, or3D);
  }
  HXT_CHECK(hxtFree(&localMatrixFrame));
  HXT_CHECK(hxtFree(&localMatrixEuler));
  return HXT_STATUS_OK;
}

/* static HXTStatus hxtOr3DHNewInt(void *data, const double *frames, HXTLinearSystem *lsys){ */
/*   HXTOrientation3D *or3D = (HXTOrientation3D*)data; */
/*   HXTMesh *mesh = or3D->mesh; */
/*   HXT_CHECK(hxtLinearSystemZeroMatrix(lsys)); */
/*   double *localMatrix; */
/*   HXT_CHECK(hxtMalloc(&localMatrix, sizeof(double)*16*81)); */
/*   for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) { */
/*     uint32_t *tet = &mesh->tetrahedra.node[iel*4]; */
/*     for (int i=0; i < 16*81; ++i) */
/*       localMatrix[i] = 0.0; */
/*     //laplace operator */
/*     /\* for (int i = 0; i < 4; ++i){ *\/ */
/*     /\*   for (int j = 0; j < 4; ++j) { *\/ */
/*     /\*     for (int k = 0; k < 9; ++k) *\/ */
/*     /\*       localMatrix[(k*4+i)*36+k*4+j] = *(or3D->elemMatLapl[iel]+4*i+j); *\/ */
/*     /\*   } *\/ */
/*     /\* } *\/ */
/*     double *solElem; */
/*     HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9)); */
/*     for (int i=0; i < 4; ++i) */
/*       for (int k=0; k < 9; ++k) */
/* 	solElem[k*4+i] = frames[9*tet[i]+k]; */
/*     // Operator constraint A^2=A */
/*     double Hn[9][9]; */
/*     double solGauss[9]; */
/*     for (int i=0; i < 9; ++i) */
/*       solGauss[i] = 1./4.*(solElem[4*i+0]+solElem[4*i+1]+solElem[4*i+2]+solElem[4*i+3]); */
/*     computeHessPenalty(or3D, Hn, solGauss); */
/*     addHessToLocalMat(localMatrix, Hn, or3D->elemDetLapl[iel], or3D->epsilonLoc[iel]); */
/*     //newInt hessian */
/*     double framesElemNew[9*4]; */
/*     for (int i=0; i < 4; ++i) */
/*       for (int k=0; k < 9; ++k) */
/* 	framesElemNew[i*9+k] = frames[9*tet[i]+k]; */
/*     double grad[9*4]={0.0}; */
/*     double Hess[9*4*9*4]={0.0}; */
/*     computeLocalOpIntegrabilityB(mesh, tet, framesElemNew, or3D->epsilonLoc[iel], grad, Hess); */
/*     HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, Hess)); */
/*     // */
/*     HXT_CHECK(hxtLinearSystemAddToMatrix(lsys, iel, iel, localMatrix)); */
/*     HXT_CHECK(hxtFree(&solElem)); */
/*   } */
/*   double *normals=or3D->normals; */
/*   for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){ */
/*     double* n; */
/*     n = normals + 3*iv; */
/*     if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1) */
/*       continue; */
/*     addBoundaryHessToOp(lsys, frames, iv, or3D); */
/*   } */
/*   HXT_CHECK(hxtFree(&localMatrix)); */
/*   return HXT_STATUS_OK; */
/* } */

HXTStatus computeMeshEnergyBC(HXTOrientation3D *or3D, HXTMesh *mesh, const double *frames, double *energyPerNode){
  double epsilonBC=or3D->epsilonBC;
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    energyPerNode[iv]=0.0;
    double enerBC = 0.0;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])>1e-1){
      for(int l=0;l<9;l++)
	for(int k=0;k<9;k++)
	  enerBC+=*(or3D->bcMat[iv]+l*9+k)*(frames[9*iv+l]-*(or3D->bcD[iv]+l))*(frames[9*iv+k]-*(or3D->bcD[iv]+k))*epsilonBC;
      energyPerNode[iv]=enerBC;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus computeMeshEnergyLaplAndPen(HXTOrientation3D *or3D, HXTMesh *mesh, const double *frames, double *energyPerTet){
  uint64_t nTet = mesh->tetrahedra.num;
  for(uint64_t ieT=0;ieT<nTet;ieT++){
    // printf("--- elem %i / %i\n",ieT,nTet);
    uint32_t *tet = mesh->tetrahedra.node+ieT*4;
    //Frames at tet nodes
    double framesElem[9*4]={0.0};
    for(int k=0;k<4;k++){
      for(int l=0;l<9;l++){
	framesElem[9*k+l]=frames[9*tet[k]+l];
      }
    }

    double frameG[9]={0.0};
    for(int k=0;k<4;k++){
      for(int l=0;l<9;l++){
	frameG[l]+=1./4.*framesElem[9*k+l];
      }
    }
    double qualG=0.0;
    hxtOr3DcomputeQuality(frameG, &qualG);
    qualG=0.5*qualG*qualG/(*(or3D->epsilonLoc));
    //laplace energy
    double enerLapl=0.0;
    /* for(int l=0;l<9;l++) */
    /*   for(int i=0;i<4;i++) */
    /* 	for(int j=0;j<4;j++) */
    /* 	  enerLapl+=*(or3D->elemMatLapl[ieT]+4*i+j)*framesElemNew[9*i+l]*framesElemNew[9*j+l]*0.5; */
    energyPerTet[ieT]=enerLapl+qualG;

  }
  
  return HXT_STATUS_OK;
}

/* static HXTStatus hxtOr3DFNewInt(void *data, const double *frames, double *f){ */
/*   HXTOrientation3D *or3D = (HXTOrientation3D*)data; */
/*   HXTMesh *mesh = or3D->mesh; */
/*   int nTet = mesh->tetrahedra.num; */
/*   int nVert = mesh->vertices.num; */
/*   double *intEnerPerTet; */
/*   HXT_CHECK(hxtMalloc(&intEnerPerTet, sizeof(double)*nTet)); */
/*   computeMeshEnergyKnotch(mesh, frames, intEnerPerTet); */
/*   double totalIntEner=0.0; */
/*   for(int ieT=0;ieT<nTet;ieT++){ */
/*     uint32_t *tet = mesh->tetrahedra.node+ieT*4; */
/*     double framesElem[9*4]={0.0}; */
/*     for(int k=0;k<4;k++) */
/*       for(int l=0;l<9;l++) */
/*   	framesElem[9*k+l]=frames[9*tet[k]+l]; */
    
/*     int isTetSing=0; */
/*     for (int k=0; k<4; k++){ */
/*       double qual=0.0; */
/*       hxtOr3DcomputeQuality(framesElem+9*k, &qual); */
/*       if(qual>10) */
/*   	isTetSing=1; */
/*     } */
/*     if(!isTetSing){ */
/*       /\* totalIntEner+=0.5*intEnerPerTet[ieT]/(or3D->epsilonLoc[ieT]); *\/ */
/*       /\* totalIntEner+=0.5*intEnerPerTet[ieT]/sqrt(or3D->epsilonLoc[ieT]); *\/ */
/*       totalIntEner+=0.5*intEnerPerTet[ieT]; */
/*       /\* totalIntEner+=0.5*intEnerPerTet[ieT]; *\/ */
/*     } */
/*   } */
/*   for(int ieT=0;ieT<nTet;ieT++) */
/*     intEnerPerTet[ieT]=0.0; */
/*   computeMeshEnergyLaplAndPen(or3D, mesh, frames, intEnerPerTet); */
/*   for(int ieT=0;ieT<nTet;ieT++){ */
/*     totalIntEner+=intEnerPerTet[ieT]; */
/*   } */
/*   double *intEnerBcPerNode; */
/*   HXT_CHECK(hxtMalloc(&intEnerBcPerNode, sizeof(double)*nVert)); */
/*   computeMeshEnergyBC(or3D, mesh, frames, intEnerBcPerNode); */
/*   for(int iv=0;iv<nVert;iv++){ */
/*     totalIntEner+=0.5*intEnerBcPerNode[iv]; */
/*   } */

/*   (*f)=totalIntEner; */
/*   /\* (*f)=0.0; *\/ */
/*   HXT_CHECK(hxtFree(&intEnerPerTet)); */
/*   HXT_CHECK(hxtFree(&intEnerBcPerNode)); */
/*   return HXT_STATUS_OK; */
/* } */

static HXTStatus hxtOr3DG(void *data, const double *frames, HXTLinearSystem *lsys, double* rhs)
{
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  for(uint32_t i=0; i<9*mesh->vertices.num; ++i)
    rhs[i]=0.0;
  double *localRhs;
  HXT_CHECK(hxtMalloc(&localRhs, sizeof(double)*4*9));
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i=0; i < 4*9; ++i)
      localRhs[i] = 0.0;
    double *solElem;
    HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9));
    for (int i=0; i < 4; ++i)
      for (int k=0; k < 9; ++k)
	solElem[k*4+i] = frames[9*tet[i]+k];
    for (int k = 0; k < 9; ++k){
      for (int i = 0; i < 4; ++i){
	for (int j = 0; j < 4; ++j){
	  localRhs[k*4+i]+=*(or3D->elemMatLapl[iel]+4*i+j)*solElem[k*4+j];
	}
      }
    }
    // Operator constraint A^2=A 
    double Gn[9];
    double solGauss[9];
    for (int i=0; i < 9; ++i)
      solGauss[i] = 1./4.*(solElem[4*i+0]+solElem[4*i+1]+solElem[4*i+2]+solElem[4*i+3]);
    
    computeGradPenalty(or3D, Gn, solGauss);
    addGradToLocalRhs(localRhs, Gn, or3D->elemDetLapl[iel], or3D->epsilonLoc[iel]);
    //
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs));
    HXT_CHECK(hxtFree(&solElem));
  }
  HXT_CHECK(hxtFree(&localRhs));
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryGradToRhs(lsys, rhs, frames, iv, or3D);
  }
  return HXT_STATUS_OK;
}

static HXTStatus hxtOr3DGEuler(void *data, const double *eulerSol, HXTLinearSystem *lsys, double* rhs)
{
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  for(uint32_t i=0; i<3*mesh->vertices.num; ++i)
    rhs[i]=0.0;
  double *localRhsFrame;
  HXT_CHECK(hxtMalloc(&localRhsFrame, sizeof(double)*4*9));
  double *localRhsEuler;
  HXT_CHECK(hxtMalloc(&localRhsEuler, sizeof(double)*4*3));
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i=0; i < 4*9; ++i)
      localRhsFrame[i] = 0.0;
    for (int i=0; i < 4*3; ++i)
      localRhsEuler[i] = 0.0;
    double *solElem;
    HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9));
    for (int i=0; i < 4; ++i){
      double frameNodeI[9]={0.0};
      hxtOr3DeulerToFrame(eulerSol+3*tet[i], frameNodeI);
      for (int k=0; k < 9; ++k)
  	solElem[k*4+i] = frameNodeI[k];
    }
    double dBdEulerTet[4][9][3]={{{0.0}}};
    for (int i=0; i < 4; ++i){
      double dBdEulerI[9][3]={{0.0}};
      hxtOr3DdBdEuler(eulerSol+3*tet[i], dBdEulerI);
      for (int k = 0; k < 9; ++k)
  	for (int j = 0; j < 3; ++j)
  	  dBdEulerTet[i][k][j]=dBdEulerI[k][j];
    }
    for (int k = 0; k < 9; ++k){
      for (int i = 0; i < 4; ++i){
  	for (int j = 0; j < 4; ++j){
  	  localRhsFrame[k*4+i]+=*(or3D->elemMatLapl[iel]+4*i+j)*solElem[k*4+j];
  	}
      }
    }
    for (int kEul = 0; kEul < 3; ++kEul){
      for (int i = 0; i < 4; ++i){
  	for (int k = 0; k < 9; ++k){
  	  localRhsEuler[kEul*4+i]+=localRhsFrame[k*4+i]*dBdEulerTet[i][k][kEul];
  	}
      }
    }
    
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhsEuler));
    HXT_CHECK(hxtFree(&solElem));
  }
  HXT_CHECK(hxtFree(&localRhsFrame));
  HXT_CHECK(hxtFree(&localRhsEuler));
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryGradToRhsEuler(lsys, rhs, eulerSol, iv, or3D);
  }
  return HXT_STATUS_OK;
}

static HXTStatus hxtOr3DGEulerConstScal(void *data, const double *eulerSol, HXTLinearSystem *lsys, double* rhs){
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  for(uint32_t i=0; i<3*mesh->vertices.num; ++i)
    rhs[i]=0.0;
  
  double localRhsEulerLoc[3*4];
  double localRhsEulerGlob[3*4];
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i=0; i < 4*3; ++i)
      localRhsEulerLoc[i] = 0.0;
    for (int i=0; i < 4*3; ++i)
      localRhsEulerGlob[i] = 0.0;
    /* double *eulerGlobElem; */
    /* HXT_CHECK(hxtMalloc(&eulerGlobElem, sizeof(double)*4*3)); */
    /* for (int i=0; i < 4; ++i){ */
    /*   for (int k=0; k < 3; ++k) */
    /* 	eulerGlobElem[k*4+i] = eulerSol[3*tet[i]+k]; */
    /* } */
    double dBdEulerGlobTet[4][9][3]={{{0.0}}};
    for (int i=0; i < 4; ++i){
      double dBdEulerGlobI[9][3]={{0.0}};
      hxtOr3DdBdEuler(eulerSol+3*tet[i], dBdEulerGlobI);
      for (int k = 0; k < 9; ++k)
  	for (int j = 0; j < 3; ++j)
  	  dBdEulerGlobTet[i][k][j]=dBdEulerGlobI[k][j];
    }
    double framesElem[9*4];
    for (int i=0; i < 4; ++i){
      hxtOr3DeulerToFrame(eulerSol+3*tet[i], framesElem+9*i);
    }
    //compute localRhsEulerLoc
    getGradConstScal(mesh, tet, framesElem, localRhsEulerLoc);
    //derivation operators
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

    //compute pInv dBdEulerLocTet and pInv
    double eulerLocElem[3*4]={0.0};
    double gradPsi[3]={0.0};
    double gradTheta[3]={0.0};
    double gradPhi[3]={0.0};
    hxtOr3DframesToEulerDataTet(framesElem, dLdX, eulerLocElem, gradPsi, gradTheta, gradPhi);
    double dEulerdBLocTet[4][3][9]={{{0.0}}};
    for (int i=0; i < 4; ++i){
      double dBdEulerLocI[9][3]={{0.0}};
      hxtOr3DdBdEuler(eulerLocElem+3*i, dBdEulerLocI);
      double dEulerdBLocI[3][9]={{0.0}};
      hxtOr3DpseudoInv9x3(dBdEulerLocI, dEulerdBLocI);
      for (int k = 0; k < 9; ++k)
  	for (int j = 0; j < 3; ++j)
  	  dEulerdBLocTet[i][j][k]=dEulerdBLocI[j][k];
    }
    //compute localRhsEulerGlob
    for (int iN=0; iN < 4; ++iN)
      for (int iEul=0; iEul < 3; ++iEul)
	for (int jEul=0; jEul < 3; ++jEul)
	  for (int b=0; b < 9; ++b)
	    localRhsEulerGlob[iEul*4+iN]+=localRhsEulerLoc[jEul*4+iN]*dEulerdBLocTet[iN][jEul][b]*dBdEulerGlobTet[iN][b][iEul];
    
    //
    
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhsEulerGlob));
    /* HXT_CHECK(hxtFree(&eulerGlobElem)); */
  }
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryGradToRhsEuler(lsys, rhs, eulerSol, iv, or3D);
  }
  return HXT_STATUS_OK;
}

static HXTStatus hxtOr3DGEulerInt(void *data, const double *eulerSol, HXTLinearSystem *lsys, double* rhs){
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  for(uint32_t i=0; i<3*mesh->vertices.num; ++i)
    rhs[i]=0.0;
  
  double localRhsEulerLoc[3*4];
  double localRhsEulerGlob[3*4];
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i=0; i < 4*3; ++i)
      localRhsEulerLoc[i] = 0.0;
    for (int i=0; i < 4*3; ++i)
      localRhsEulerGlob[i] = 0.0;
    /* double *eulerGlobElem; */
    /* HXT_CHECK(hxtMalloc(&eulerGlobElem, sizeof(double)*4*3)); */
    /* for (int i=0; i < 4; ++i){ */
    /*   for (int k=0; k < 3; ++k) */
    /* 	eulerGlobElem[k*4+i] = eulerSol[3*tet[i]+k]; */
    /* } */
    double dBdEulerGlobTet[4][9][3]={{{0.0}}};
    for (int i=0; i < 4; ++i){
      double dBdEulerGlobI[9][3]={{0.0}};
      hxtOr3DdBdEuler(eulerSol+3*tet[i], dBdEulerGlobI);
      for (int k = 0; k < 9; ++k)
  	for (int j = 0; j < 3; ++j)
  	  dBdEulerGlobTet[i][k][j]=dBdEulerGlobI[k][j];
    }
    double framesElem[9*4];
    for (int i=0; i < 4; ++i){
      hxtOr3DeulerToFrame(eulerSol+3*tet[i], framesElem+9*i);
    }
    //compute localRhsEulerLoc
    getGradFDEulerInt(mesh,tet,framesElem,localRhsEulerLoc);
    //derivation operators
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

    //compute pInv dBdEulerLocTet and pInv
    double eulerLocElem[3*4]={0.0};
    double gradPsi[3]={0.0};
    double gradTheta[3]={0.0};
    double gradPhi[3]={0.0};
    hxtOr3DframesToEulerDataTet(framesElem, dLdX, eulerLocElem, gradPsi, gradTheta, gradPhi);
    double dEulerdBLocTet[4][3][9]={{{0.0}}};
    for (int i=0; i < 4; ++i){
      double dBdEulerLocI[9][3]={{0.0}};
      hxtOr3DdBdEuler(eulerLocElem+3*i, dBdEulerLocI);
      double dEulerdBLocI[3][9]={{0.0}};
      hxtOr3DpseudoInv9x3(dBdEulerLocI, dEulerdBLocI);
      for (int k = 0; k < 9; ++k)
  	for (int j = 0; j < 3; ++j)
  	  dEulerdBLocTet[i][j][k]=dEulerdBLocI[j][k];
    }
    //compute localRhsEulerGlob
    for (int iN=0; iN < 4; ++iN)
      for (int iEul=0; iEul < 3; ++iEul)
	for (int jEul=0; jEul < 3; ++jEul)
	  for (int b=0; b < 9; ++b)
	    localRhsEulerGlob[iEul*4+iN]+=localRhsEulerLoc[jEul*4+iN]*dEulerdBLocTet[iN][jEul][b]*dBdEulerGlobTet[iN][b][iEul];
    
    //
    
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhsEulerGlob));
    /* HXT_CHECK(hxtFree(&eulerGlobElem)); */
  }
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryGradToRhsEuler(lsys, rhs, eulerSol, iv, or3D);
  }
  return HXT_STATUS_OK;
}

static HXTStatus getLocalRhsEulerLaplace(void *data, HXTMesh *mesh, const double *eulerSol, uint64_t iel, double localRhsEuler[3*4]){
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  uint32_t *tet = &mesh->tetrahedra.node[iel*4];
  double *localRhsFrame;
  HXT_CHECK(hxtMalloc(&localRhsFrame, sizeof(double)*4*9));
  for (int i=0; i < 4*9; ++i)
    localRhsFrame[i] = 0.0;
  for (int i=0; i < 4*3; ++i)
    localRhsEuler[i] = 0.0;
  double *solElem;
  HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9));
  for (int i=0; i < 4; ++i){
    double frameNodeI[9]={0.0};
    hxtOr3DeulerToFrame(eulerSol+3*tet[i], frameNodeI);
    for (int k=0; k < 9; ++k)
      solElem[k*4+i] = frameNodeI[k];
  }
  double dBdEulerTet[4][9][3]={{{0.0}}};
  for (int i=0; i < 4; ++i){
    double dBdEulerI[9][3]={{0.0}};
    hxtOr3DdBdEuler(eulerSol+3*tet[i], dBdEulerI);
    for (int k = 0; k < 9; ++k)
      for (int j = 0; j < 3; ++j)
	dBdEulerTet[i][k][j]=dBdEulerI[k][j];
  }
  for (int k = 0; k < 9; ++k){
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 4; ++j){
	localRhsFrame[k*4+i]+=*(or3D->elemMatLapl[iel]+4*i+j)*solElem[k*4+j];
      }
    }
  }
  for (int kEul = 0; kEul < 3; ++kEul){
    for (int i = 0; i < 4; ++i){
      for (int k = 0; k < 9; ++k){
	localRhsEuler[kEul*4+i]+=localRhsFrame[k*4+i]*dBdEulerTet[i][k][kEul];
      }
    }
  }
    
  HXT_CHECK(hxtFree(&localRhsFrame));
  HXT_CHECK(hxtFree(&solElem));

  return HXT_STATUS_OK;
}
  
static HXTStatus getLocalRhsEulerInt(HXTMesh *mesh, const double *eulerSol, uint64_t iel, double localRhsEulerGlob[3*4]){
  uint32_t *tet = &mesh->tetrahedra.node[iel*4];
  double localRhsEulerLoc[3*4];
  for (int i=0; i < 4*3; ++i)
    localRhsEulerLoc[i] = 0.0;
  for (int i=0; i < 4*3; ++i)
    localRhsEulerGlob[i] = 0.0;
  /* double *eulerGlobElem; */
  /* HXT_CHECK(hxtMalloc(&eulerGlobElem, sizeof(double)*4*3)); */
  /* for (int i=0; i < 4; ++i){ */
  /*   for (int k=0; k < 3; ++k) */
  /* 	eulerGlobElem[k*4+i] = eulerSol[3*tet[i]+k]; */
  /* } */
  double dBdEulerGlobTet[4][9][3]={{{0.0}}};
  for (int i=0; i < 4; ++i){
    double dBdEulerGlobI[9][3]={{0.0}};
    hxtOr3DdBdEuler(eulerSol+3*tet[i], dBdEulerGlobI);
    for (int k = 0; k < 9; ++k)
      for (int j = 0; j < 3; ++j)
	dBdEulerGlobTet[i][k][j]=dBdEulerGlobI[k][j];
  }
  double framesElem[9*4];
  for (int i=0; i < 4; ++i){
    hxtOr3DeulerToFrame(eulerSol+3*tet[i], framesElem+9*i);
  }
  //compute localRhsEulerLoc
  getGradFDEulerInt(mesh,tet,framesElem,localRhsEulerLoc);
  //derivation operators
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

  //compute pInv dBdEulerLocTet and pInv
  double eulerLocElem[3*4]={0.0};
  double gradPsi[3]={0.0};
  double gradTheta[3]={0.0};
  double gradPhi[3]={0.0};
  hxtOr3DframesToEulerDataTet(framesElem, dLdX, eulerLocElem, gradPsi, gradTheta, gradPhi);
  double dEulerdBLocTet[4][3][9]={{{0.0}}};
  for (int i=0; i < 4; ++i){
    double dBdEulerLocI[9][3]={{0.0}};
    hxtOr3DdBdEuler(eulerLocElem+3*i, dBdEulerLocI);
    double dEulerdBLocI[3][9]={{0.0}};
    hxtOr3DpseudoInv9x3(dBdEulerLocI, dEulerdBLocI);
    for (int k = 0; k < 9; ++k)
      for (int j = 0; j < 3; ++j)
	dEulerdBLocTet[i][j][k]=dEulerdBLocI[j][k];
  }
  //compute localRhsEulerGlob
  for (int iN=0; iN < 4; ++iN)
    for (int iEul=0; iEul < 3; ++iEul)
      for (int jEul=0; jEul < 3; ++jEul)
	for (int b=0; b < 9; ++b)
	  localRhsEulerGlob[iEul*4+iN]+=localRhsEulerLoc[jEul*4+iN]*dEulerdBLocTet[iN][jEul][b]*dBdEulerGlobTet[iN][b][iEul];
    
  //
  return HXT_STATUS_OK;
}

int isTetSingularEuler(HXTMesh *mesh, const double *eulerSol, int iel){
  int isTetSing=0;
  uint32_t *tet = &mesh->tetrahedra.node[iel*4];
  double frameG[9]={0.0};
  for (int k = 0; k < 4; k++){
    double frameK[9]={0.0};
    hxtOr3DeulerToFrame(eulerSol+3*tet[k], frameK);
    for (int i = 0; i < 9; i++)
      frameG[i]+=frameK[i];
  }
  for (int i = 0; i < 9; i++)
    frameG[i]/=4.;
  double qual=0.0;
  hxtOr3DcomputeQuality(frameG, &qual);
  /* if(qual>0.2) */
  if(qual>0.05)
    isTetSing=1;
  
  return isTetSing;
}

static HXTStatus hxtOr3DGEulerMixed(void *data, const double *eulerSol, HXTLinearSystem *lsys, double* rhs){
  HXTOrientation3D *or3D = (HXTOrientation3D*)data;
  HXTMesh *mesh = or3D->mesh;
  for(uint32_t i=0; i<3*mesh->vertices.num; ++i)
    rhs[i]=0.0;
  
  double localRhsEulerGlob[3*4];
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    //If tet singular, laplacian operator
    int isTetSing=isTetSingularEuler(mesh, eulerSol, iel);
    if(isTetSing)
      getLocalRhsEulerLaplace(data, mesh, eulerSol, iel, localRhsEulerGlob);
    //else, int operator
    else
      getLocalRhsEulerInt(mesh, eulerSol, iel, localRhsEulerGlob);
    
    HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhsEulerGlob));
    /* HXT_CHECK(hxtFree(&eulerGlobElem)); */
  }
  double *normals=or3D->normals;
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1)
      continue;
    addBoundaryGradToRhsEuler(lsys, rhs, eulerSol, iv, or3D);
  }
  return HXT_STATUS_OK;
}

/* static HXTStatus hxtOr3DGNewInt(void *data, const double *frames, HXTLinearSystem *lsys, double* rhs){ */
/*   HXTOrientation3D *or3D = (HXTOrientation3D*)data; */
/*   HXTMesh *mesh = or3D->mesh; */
/*   for(uint32_t i=0; i<9*mesh->vertices.num; ++i) */
/*     rhs[i]=0.0; */
/*   double *localRhs; */
/*   HXT_CHECK(hxtMalloc(&localRhs, sizeof(double)*4*9)); */
/*   for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) { */
/*     uint32_t *tet = &mesh->tetrahedra.node[iel*4]; */
/*     for (int i=0; i < 4*9; ++i) */
/*       localRhs[i] = 0.0; */
/*     double *solElem; */
/*     HXT_CHECK(hxtMalloc(&solElem, sizeof(double)*4*9)); */
/*     for (int i=0; i < 4; ++i) */
/*       for (int k=0; k < 9; ++k) */
/* 	solElem[k*4+i] = frames[9*tet[i]+k]; */
/*     //laplace operator */
/*     /\* for (int k = 0; k < 9; ++k){ *\/ */
/*     /\*   for (int i = 0; i < 4; ++i){ *\/ */
/*     /\* 	for (int j = 0; j < 4; ++j){ *\/ */
/*     /\* 	  localRhs[k*4+i]+=*(or3D->elemMatLapl[iel]+4*i+j)*solElem[k*4+j]; *\/ */
/*     /\* 	} *\/ */
/*     /\*   } *\/ */
/*     /\* } *\/ */
/*     // Operator constraint A^2=A  */
/*     double Gn[9]; */
/*     double solGauss[9]; */
/*     for (int i=0; i < 9; ++i) */
/*       solGauss[i] = 1./4.*(solElem[4*i+0]+solElem[4*i+1]+solElem[4*i+2]+solElem[4*i+3]); */
    
/*     computeGradPenalty(or3D, Gn, solGauss); */
/*     addGradToLocalRhs(localRhs, Gn, or3D->elemDetLapl[iel], or3D->epsilonLoc[iel]); */
/*     //newInt gradient */
/*     double framesElemNew[9*4]; */
/*     for (int i=0; i < 4; ++i) */
/*       for (int k=0; k < 9; ++k) */
/* 	framesElemNew[i*9+k] = frames[9*tet[i]+k]; */
/*     double grad[9*4]={0.0}; */
/*     /\* double Hess[9*4*9*4]={0.0}; *\/ */
/*     computeLocalOpIntegrabilityB(mesh, tet, framesElemNew, or3D->epsilonLoc[iel], grad, NULL); */
/*     HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, grad)); */
/*     // */
/*     HXT_CHECK(hxtLinearSystemAddToRhs(lsys, rhs, iel, localRhs)); */
/*     HXT_CHECK(hxtFree(&solElem)); */
/*   } */
/*   HXT_CHECK(hxtFree(&localRhs)); */
/*   double *normals=or3D->normals; */
/*   for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){ */
/*     double* n; */
/*     n = normals + 3*iv; */
/*     if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])<1e-1) */
/*       continue; */
/*     addBoundaryGradToRhs(lsys, rhs, frames, iv, or3D); */
/*   } */
/*   return HXT_STATUS_OK; */
/* } */

HXTStatus computeCrossProdBase(HXTOrientation3D *or3D)
{
  hxtOr3DcrossProdBase(or3D->base, or3D->crossProdBase, or3D->crossProdBaseSym);
  return HXT_STATUS_OK;
}

HXTStatus buildOr3D(HXTOrientation3D *or3D, HXTMesh *mesh, double *frames, double epsilon)
{
  double epsilonBC = 1.0;
  or3D->mesh=mesh;
  if(epsilon<=0)
    setEpsilon(or3D->mesh,&(or3D->epsilonGlob));
  else
    or3D->epsilonGlob=epsilon*epsilon/(16.0);
  printf("epsilon = %g\n",epsilon);
  or3D->epsilonBC=epsilonBC;
  or3D->frames=frames;
  HXT_CHECK(hxtMalloc(&(or3D->normals), mesh->vertices.num*2*3*sizeof(double)));
  HXT_CHECK(computeBndNormals(or3D->mesh, or3D->normals));
  HXT_CHECK(hxtMalloc(&(or3D->elemMatLapl), mesh->tetrahedra.num*sizeof(double*)));
  HXT_CHECK(hxtMalloc(&(or3D->elemDetLapl), mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->epsilonLoc), mesh->tetrahedra.num*sizeof(double)));
  HXT_CHECK(hxtMalloc(&(or3D->bcMat), mesh->vertices.num*sizeof(double*)));
  HXT_CHECK(hxtMalloc(&(or3D->bcD), mesh->vertices.num*sizeof(double*)));
  //Create boundary condition operators at nodes
  for(uint32_t iv=0; iv<mesh->vertices.num; ++iv){
    double* n;
    n = or3D->normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])>1e-1){
      HXT_CHECK(hxtMalloc(&(or3D->bcMat[iv]), 81*sizeof(double)));
      HXT_CHECK(hxtMalloc(&(or3D->bcD[iv]), 9*sizeof(double)));
      double H[9][9];
      double a,b;
      hxtOr3DeulerAnglesOfNormal(n, &a, &b);
      double C[9][2];
      double D[9];
      hxtOr3DcombinationOnBorder(a, b, C, D);
      hxtOr3DboundaryConstraintMatrix(C, H);
      for (int k = 0; k < 9; ++k){
	*(or3D->bcD[iv]+k)=D[k];
	for (int l = 0; l < 9; ++l)
	  *(or3D->bcMat[iv]+9*k+l)=H[k][l];
      }	
    }
  }
  //Create elementary matrices for laplacian
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel) {
    HXT_CHECK(hxtMalloc(&(or3D->elemMatLapl[iel]), 16*sizeof(double)));
    double *localMatrix=or3D->elemMatLapl[iel];
    for (int i=0; i < 16; ++i)
      localMatrix[i] = 0.0;
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    double x[4][4];
    for (int i = 0; i < 4; i++)
      memcpy(x[i], mesh->vertices.coord + 4*tet[i], sizeof(x[i]));
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
	x[i][j] = mesh->vertices.coord[4*tet[i]+j];
    // Local epsilon computation
    double minLength=-1.;
    /* double minLength=0.; */
    double length=0.;
    for (int i=0; i < 4; ++i) {
      for (int j=i+1; j < 4; ++j) {
  	length = sqrt((x[j][0]-x[i][0])*(x[j][0]-x[i][0]) +
                      (x[j][1]-x[i][1])*(x[j][1]-x[i][1]) +
                      (x[j][2]-x[i][2])*(x[j][2]-x[i][2]));
  	if(minLength<0)
  	  minLength = length;
  	else{
  	  /* if(minLength<length)//maxlenght */
  	  if(minLength>length)//minlenght
  	    minLength = length;
  	}
  	/* minLength+=length; */
      }
    }
    /* minLength/=6; */
    minLength*=0.5;
    /* or3D->epsilonLoc[iel] = (minLength)*(minLength); */
    or3D->epsilonLoc[iel] = or3D->epsilonGlob;
    /* double epsilonLoc = epsilon; */
    //
    double dxdxi[3][3];
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        dxdxi[i][j] = x[i+1][j] - x[0][j];
    double dxidx[3][3];
    double detj;
    HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
    detj=fabs(detj);
    or3D->elemDetLapl[iel]=detj;
    const double dphi[][3] = {
      {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
      {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
      {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
      {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
    };
    double volume = detj/6.0;
    for (int i = 0; i < 4; ++i){
      for (int j = 0; j < 4; ++j) {
	localMatrix[i*4+j] = volume*(dphi[i][0]*dphi[j][0]+dphi[i][1]*dphi[j][1]+dphi[i][2]*dphi[j][2]);
      }
    }
  }
  hxtOr3DgetBase(or3D->base);
  computeCrossProdBase(or3D);
  return HXT_STATUS_OK;  
}

HXTStatus destroyOr3D(HXTOrientation3D *or3D)
{
  for(uint32_t iv=0; iv<or3D->mesh->vertices.num; ++iv){
    double* n;
    n = or3D->normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])>1e-1){
      HXT_CHECK(hxtFree(&(or3D->bcMat[iv])));
      HXT_CHECK(hxtFree(&(or3D->bcD[iv])));      
    }
  }
  for (uint64_t iel=0; iel < or3D->mesh->tetrahedra.num; ++iel)
    HXT_CHECK(hxtFree(&(or3D->elemMatLapl[iel])));
  HXT_CHECK(hxtFree(&(or3D->bcMat)));
  HXT_CHECK(hxtFree(&(or3D->bcD)));
  HXT_CHECK(hxtFree(&(or3D->elemMatLapl)));
  HXT_CHECK(hxtFree(&(or3D->elemDetLapl)));
  HXT_CHECK(hxtFree(&(or3D->epsilonLoc)));
  HXT_CHECK(hxtFree(&(or3D->normals)));
  return HXT_STATUS_OK;
}

HXTStatus computeFramesNLinternal(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon){
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,9,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_monitor -ksp_info -ksp_rtol 1e-12"));
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,9,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_info -ksp_rtol 1e-12")); */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_OK;
#endif
  HXTOrientation3D or3D;  
  buildOr3D(&or3D, mesh, frames, epsilon);
  int iterMax = 1000;
  setInitialFrames(mesh,frames,or3D.normals,hasToBeInitialized);
  /* time(&depart); */
  double depart = omp_get_wtime();
  if(!hasToBeInitialized)
    for(uint32_t i = 0; i < mesh->vertices.num; ++i){
      double frameProj[9]={0.0};
      hxtOr3DprojectFrameOnCrossManifold(frames+9*i, frameProj);
      for(int k=0; k<9; ++k) 
	frames[9*i+k]=frameProj[k];
    }
  //Non linear solve
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_scale_type jacobian -snes_qn_monitor -snes_max_it 100 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-10")); */
  HXT_CHECK(hxtNewtonRaphson(system, frames, 9*mesh->vertices.num, iterMax, 1e-10, hxtOr3DG, hxtOr3DH, &or3D));
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_max_it 1000 -snes_rtol 1e-4")); */
  // transfo for posttreatment
  /* time(&arrivee); */

  double arrivee = omp_get_wtime();
  destroyOr3D(&or3D);
  HXT_CHECK(hxtLinearSystemDelete(&system));

  printf("Unknown number : %" PRIu32 "\n",mesh->vertices.num*9);
  printf("Tet number : %" PRIu64 "\n",mesh->tetrahedra.num);
  printf("Nodes number : %" PRIu32 "\n",mesh->vertices.num);
  /* printf("Solving time : %f s.\n", difftime(arrivee, depart)); */
  printf("Solving time : %g s.\n", arrivee-depart);
  return HXT_STATUS_OK;
}

HXTStatus computeFramesNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon){
  //Renumbering nodes if there is alone vertices
  HXTOrientation3DCleanMesh cleanMeshObj;
  buildCleanMesh(&cleanMeshObj,mesh);
  cleanMeshCleanSolution(&cleanMeshObj, frames, 9);
  computeFramesNLinternal(mesh, frames, hasToBeInitialized, epsilon); 
  //Restoring mesh and solution
  cleanMeshRestoreMesh(&cleanMeshObj);
  uint32_t nFieldsSol=9;
  cleanMeshRestoreSolution(&cleanMeshObj,frames,nFieldsSol);
  cleanMeshDestroy(&cleanMeshObj);
  return HXT_STATUS_OK;
}

HXTStatus computeFramesEulerNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon){
  /* time_t depart, arrivee; */
  uint32_t nInc = 3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_monitor -ksp_info -ksp_rtol 1e-12"));
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,9,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_info -ksp_rtol 1e-12")); */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_OK;
#endif
  HXTOrientation3D or3D;  
  buildOr3D(&or3D, mesh, frames, epsilon);
  /* int iterMax = 1000; */
  setInitialFrames(mesh,frames,or3D.normals,hasToBeInitialized);
  /* time(&depart); */
  double depart = omp_get_wtime();
  if(!hasToBeInitialized)
    for(uint32_t i = 0; i < mesh->vertices.num; ++i){
      double frameProj[9]={0.0};
      hxtOr3DprojectFrameOnCrossManifold(frames+9*i, frameProj);
      for(int k=0; k<9; ++k) 
	frames[9*i+k]=frameProj[k];
    }
  double *eulerSol;
  HXT_CHECK(hxtMalloc(&eulerSol, 3*mesh->vertices.num*sizeof(double)));
  //get euler from frames here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    double flagNotUnique=0.0;
    hxtOr3DframeToEuler(frames+9*i, &flagNotUnique, eulerSol+3*i);
  }
  //

  
  //Non linear solve
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_scale_type jacobian -snes_qn_monitor -snes_max_it 100 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-10")); */
  /* HXT_CHECK(hxtNewtonRaphson(system, eulerSol, nInc*mesh->vertices.num, iterMax, 1e-10, hxtOr3DGEuler, hxtOr3DHEuler, &or3D)); */
  HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEuler, hxtOr3DHEuler, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-4"));
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_max_it 1000 -snes_rtol 1e-4")); */
  // transfo for posttreatment
  /* time(&arrivee); */

  //get frames from euler here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    hxtOr3DeulerToFrame(eulerSol+3*i, frames+9*i);
  }
  HXT_CHECK(hxtFree(&eulerSol));
  //
  
  double arrivee = omp_get_wtime();
  destroyOr3D(&or3D);
  HXT_CHECK(hxtLinearSystemDelete(&system));

  printf("Unknown number : %" PRIu32 "\n",mesh->vertices.num*9);
  printf("Tet number : %" PRIu64 "\n",mesh->tetrahedra.num);
  printf("Nodes number : %" PRIu32 "\n",mesh->vertices.num);
  /* printf("Solving time : %f s.\n", difftime(arrivee, depart)); */
  printf("Solving time : %g s.\n", arrivee-depart);
  return HXT_STATUS_OK;
}

HXTStatus computeFramesEulerIntNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon){
  /* time_t depart, arrivee; */
  uint32_t nInc = 3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_monitor -ksp_info -ksp_rtol 1e-12"));
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,9,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_info -ksp_rtol 1e-12")); */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_OK;
#endif
  HXTOrientation3D or3D;  
  buildOr3D(&or3D, mesh, frames, epsilon);
  /* int iterMax = 1000; */
  setInitialFrames(mesh,frames,or3D.normals,hasToBeInitialized);
  /* time(&depart); */
  double depart = omp_get_wtime();
  if(!hasToBeInitialized)
    for(uint32_t i = 0; i < mesh->vertices.num; ++i){
      double frameProj[9]={0.0};
      hxtOr3DprojectFrameOnCrossManifold(frames+9*i, frameProj);
      for(int k=0; k<9; ++k) 
	frames[9*i+k]=frameProj[k];
    }
  double *eulerSol;
  HXT_CHECK(hxtMalloc(&eulerSol, 3*mesh->vertices.num*sizeof(double)));
  //get euler from frames here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    double flagNotUnique=0.0;
    hxtOr3DframeToEuler(frames+9*i, &flagNotUnique, eulerSol+3*i);
  }
  //

  
  //Non linear solve
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_scale_type jacobian -snes_qn_monitor -snes_max_it 100 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-10")); */
  /* HXT_CHECK(hxtNewtonRaphson(system, eulerSol, nInc*mesh->vertices.num, iterMax, 1e-10, hxtOr3DGEuler, hxtOr3DHEuler, &or3D)); */
  HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEulerInt, NULL, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-4"));
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEulerInt, hxtOr3DHEulerInt, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_max_it 1000 -snes_rtol 1e-4")); */
  // transfo for posttreatment
  /* time(&arrivee); */

  //get frames from euler here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    hxtOr3DeulerToFrame(eulerSol+3*i, frames+9*i);
  }
  HXT_CHECK(hxtFree(&eulerSol));
  //
  
  double arrivee = omp_get_wtime();
  destroyOr3D(&or3D);
  HXT_CHECK(hxtLinearSystemDelete(&system));

  printf("Unknown number : %" PRIu32 "\n",mesh->vertices.num*9);
  printf("Tet number : %" PRIu64 "\n",mesh->tetrahedra.num);
  printf("Nodes number : %" PRIu32 "\n",mesh->vertices.num);
  /* printf("Solving time : %f s.\n", difftime(arrivee, depart)); */
  printf("Solving time : %g s.\n", arrivee-depart);
  return HXT_STATUS_OK;
}

HXTStatus computeFramesEulerMixedNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon){
  /* time_t depart, arrivee; */
  uint32_t nInc = 3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_monitor -ksp_info -ksp_rtol 1e-12"));
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,9,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_info -ksp_rtol 1e-12")); */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_OK;
#endif
  HXTOrientation3D or3D;  
  buildOr3D(&or3D, mesh, frames, epsilon);
  /* int iterMax = 1000; */
  setInitialFrames(mesh,frames,or3D.normals,hasToBeInitialized);
  /* time(&depart); */
  double depart = omp_get_wtime();
  if(!hasToBeInitialized)
    for(uint32_t i = 0; i < mesh->vertices.num; ++i){
      double frameProj[9]={0.0};
      hxtOr3DprojectFrameOnCrossManifold(frames+9*i, frameProj);
      for(int k=0; k<9; ++k) 
	frames[9*i+k]=frameProj[k];
    }
  double *eulerSol;
  HXT_CHECK(hxtMalloc(&eulerSol, 3*mesh->vertices.num*sizeof(double)));
  //get euler from frames here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    double flagNotUnique=0.0;
    hxtOr3DframeToEuler(frames+9*i, &flagNotUnique, eulerSol+3*i);
  }
  //

  
  //Non linear solve
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_scale_type jacobian -snes_qn_monitor -snes_max_it 100 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-10")); */
  /* HXT_CHECK(hxtNewtonRaphson(system, eulerSol, nInc*mesh->vertices.num, iterMax, 1e-10, hxtOr3DGEuler, hxtOr3DHEuler, &or3D)); */
  HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEulerMixed, NULL, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-4"));
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEulerInt, hxtOr3DHEulerInt, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_max_it 1000 -snes_rtol 1e-4")); */
  // transfo for posttreatment
  /* time(&arrivee); */

  //get frames from euler here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    hxtOr3DeulerToFrame(eulerSol+3*i, frames+9*i);
  }
  HXT_CHECK(hxtFree(&eulerSol));
  //
  
  double arrivee = omp_get_wtime();
  destroyOr3D(&or3D);
  HXT_CHECK(hxtLinearSystemDelete(&system));

  printf("Unknown number : %" PRIu32 "\n",mesh->vertices.num*9);
  printf("Tet number : %" PRIu64 "\n",mesh->tetrahedra.num);
  printf("Nodes number : %" PRIu32 "\n",mesh->vertices.num);
  /* printf("Solving time : %f s.\n", difftime(arrivee, depart)); */
  printf("Solving time : %g s.\n", arrivee-depart);
  return HXT_STATUS_OK;
}

HXTStatus computeFramesEulerConstScalNL(HXTMesh *mesh, double *frames, int hasToBeInitialized, double epsilon){
  /* time_t depart, arrivee; */
  uint32_t nInc = 3;
  HXTLinearSystem *system;
#ifdef HXT_HAVE_PETSC
  HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,nInc,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_monitor -ksp_info -ksp_rtol 1e-12"));
  /* HXT_CHECK(hxtLinearSystemCreatePETSc(&system,mesh->tetrahedra.num,4,9,mesh->tetrahedra.node,"-ksp_type bcgs -pc_type ilu -ksp_info -ksp_rtol 1e-12")); */
#else
  printf("PETSC needed, aborting\n");
  return HXT_STATUS_OK;
#endif
  HXTOrientation3D or3D;  
  buildOr3D(&or3D, mesh, frames, epsilon);
  /* int iterMax = 1000; */
  setInitialFrames(mesh,frames,or3D.normals,hasToBeInitialized);
  /* time(&depart); */
  double depart = omp_get_wtime();
  if(!hasToBeInitialized)
    for(uint32_t i = 0; i < mesh->vertices.num; ++i){
      double frameProj[9]={0.0};
      hxtOr3DprojectFrameOnCrossManifold(frames+9*i, frameProj);
      for(int k=0; k<9; ++k) 
	frames[9*i+k]=frameProj[k];
    }
  double *eulerSol;
  HXT_CHECK(hxtMalloc(&eulerSol, 3*mesh->vertices.num*sizeof(double)));
  //get euler from frames here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    double flagNotUnique=0.0;
    hxtOr3DframeToEuler(frames+9*i, &flagNotUnique, eulerSol+3*i);
  }
  //

  
  //Non linear solve
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_scale_type jacobian -snes_qn_monitor -snes_max_it 100 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-10")); */
  /* HXT_CHECK(hxtNewtonRaphson(system, eulerSol, nInc*mesh->vertices.num, iterMax, 1e-10, hxtOr3DGEuler, hxtOr3DHEuler, &or3D)); */
  HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEulerConstScal, NULL, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 2000 -snes_rtol 1e-4"));
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, eulerSol, hxtOr3DGEulerInt, hxtOr3DHEulerInt, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_qn_monitor -snes_max_it 1000 -snes_rtol 1e-4")); */
  /* HXT_CHECK(hxtNonLinearSolverPETSc(system, frames, hxtOr3DG, hxtOr3DH, &or3D, "-snes_type qn -snes_qn_type lbfgs -snes_max_it 1000 -snes_rtol 1e-4")); */
  // transfo for posttreatment
  /* time(&arrivee); */

  //get frames from euler here
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    hxtOr3DeulerToFrame(eulerSol+3*i, frames+9*i);
  }
  HXT_CHECK(hxtFree(&eulerSol));
  //
  
  double arrivee = omp_get_wtime();
  destroyOr3D(&or3D);
  HXT_CHECK(hxtLinearSystemDelete(&system));

  printf("Unknown number : %" PRIu32 "\n",mesh->vertices.num*9);
  printf("Tet number : %" PRIu64 "\n",mesh->tetrahedra.num);
  printf("Nodes number : %" PRIu32 "\n",mesh->vertices.num);
  /* printf("Solving time : %f s.\n", difftime(arrivee, depart)); */
  printf("Solving time : %g s.\n", arrivee-depart);
  return HXT_STATUS_OK;
}
