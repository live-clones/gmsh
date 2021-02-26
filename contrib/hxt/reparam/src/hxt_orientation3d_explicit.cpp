#include "hxt_orientation3d_explicit.h"

extern "C" {
#include "inttypes.h"
// #include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_eigenvectors.h"
#include "hxt_orientation3d_tools.h"
#include "hxt_orientation3d_scaling.h"
#include "hxt_orientation3d_io.h"
#include "hxt_orientation3d_integrability.h"
#include "hxt_orientation3d_cleanMeshStruct.h"
}
// #include "hxt_linear_system.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "Octree.hpp"
#include <ios>
#include <vector>
#include <cstdlib>

typedef struct HXTOrientation3DExplStruct HXTOrientation3DExpl;

class Point3f
{
 public:
  Point3f(float x, float y, float z) : x(x), y(y), z(z)
  {
  }

  float x, y, z;
};

struct HXTOrientation3DExplStruct {
  HXTMesh *mesh;
  double *frames; // frame 9x1
  double *normals; // normals
  //global parameters

  
  //Frames operators
  double **pInvC;
  double **C;
  double **bcMat;
  double **bcD;
  double base[6][6][10];
  double crossProdBase[10][10][6][6];
  double crossProdBaseSym[10][10][6][6];
  //Sorted vertices array for parallelization
  int *sortedVertices;
  int *invSortedVertices;
  int cptVbound=0;
  int cptVint=0;
  double *framesSorted;
  double *normalsSorted;
  //Fixed nodes
  uint32_t *nodesFixed;
  int cptNodesFixed = 0;
  //--Relaxing operators
  int typeRelax=0;
  int maxIter;
  double precision;
  int projectionAfterSolve;
  //Laplacian relaxing operator
  double *multNodes;
  int size[1];
  int *connectivityOp;
  double *relaxOp;
  //Octree relaxing operator
  uint32_t **connectivityOpOct;
  uint32_t *sizeConnOpOct;
};

HXTStatus writeGradNorm(HXTMesh *mesh, int *invSortedInd, double *gradSorted, const char *fileName)
{
  int nVert = mesh->vertices.num;
  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Scaling\"{\n");
  for (uint32_t i = 0; i < mesh->vertices.num; ++i) {
    int iv=invSortedInd[i];
    double gradLoc[9]={0.0};
    for (int k = 0; k < 9; ++k)
      gradLoc[k]=gradSorted[nVert*k + i];
    double *x = mesh->vertices.coord + 4*iv;
    
    double normG=0.0;
    hxtNorm2V(gradLoc, 9, &normG);
    fprintf(myfile,"SP(%.16g,%.16g,%.16g){%.16g};\n",x[0],x[1],x[2],normG);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

HXTStatus writeScalarTetSorted(HXTMesh *mesh, double *framesSorted, int *invSortedVertices, double *scalarField, const char *fileName)
{

  FILE* myfile = fopen(fileName,"w");
  fprintf(myfile,"View \"Energy Error\"{\n");
  int nVert = mesh->vertices.num;
  for (uint64_t i = 0; i < mesh->tetrahedra.num; ++i) {
    double value=0.0;
    int isTetSing=0;
    int sortedInd[4]={0};
    uint32_t *tet = mesh->tetrahedra.node+i*4;
    for(int k=0;k<4;k++)
      sortedInd[k]=invSortedVertices[tet[k]];
    double frame[9]={0.0};
    for(int k=0;k<4;k++){
      for(int l=0;l<9;l++){
	frame[l]=framesSorted[nVert*l+sortedInd[k]];
      }
      double quality=0.0;
      hxtOr3DcomputeQuality(frame,&quality);
      if(quality>10)
	isTetSing=1;
    }

    if(!isTetSing)
      value=scalarField[i];
    else
      value=0.0;

    double *x0 = mesh->vertices.coord + 4*tet[0];
    double *x1 = mesh->vertices.coord + 4*tet[1];
    double *x2 = mesh->vertices.coord + 4*tet[2];
    double *x3 = mesh->vertices.coord + 4*tet[3];
    fprintf(myfile,"SS(%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g,%.16g){%.16g,%.16g,%.16g,%.16g};\n",x0[0],x0[1],x0[2],x1[0],x1[1],x1[2],x2[0],x2[1],x2[2],x3[0],x3[1],x3[2],value,value,value,value);
  }
  fprintf(myfile,"};");
  fclose(myfile);
  return HXT_STATUS_OK;
}

int compIndiceDoubleArray (const void * elem1, const void * elem2)
{
  double **f = static_cast<double**>(const_cast<void*>(elem1));
  double **s = static_cast<double**>(const_cast<void*>(elem2));
  if (**f > **s) return  1;
  if (**f < **s) return -1;
  if (**f == **s) return 0;
  return 0;
}

void NelderMeadSimplex(double *var, int size, double *res, ptrObjectiveFunction ptrFct, double *inputData) //Prototype des fonctions couts : void fctCout(double *inputData, double *var, double *valueFctCout);
{
  int sortedIndices[size+1];
  double newPoint[size];
  double newPoint2[size];
  double evalFctNewPoint[1]={10.0};
  double evalFctNewPoint2[1]={10.0};
  double simplex[size*(size+1)];
  double evalFct[size+1];
  double* indices[size+1];
  for(int i=0;i<size+1;i++)
    indices[i] = evalFct+i;
  for(int i=0;i<size;i++)
    simplex[i] = var[i];
  int it=0;
  for(int j=1;j<size+1;j++){
    for(int i=0;i<size;i++){
      simplex[i+j*size] = var[i];
      if(i==it){
	if(fabs(simplex[i+j*size])>1e-10)
	  simplex[i+j*size] = simplex[i+j*size]*(1.05);
	else
	  simplex[i+j*size] = 2.5e-4;
      }
    }
    it++;
  }
  double criterionVar=1e-6;
  double errVar=1.0;
  it=0;
  while(errVar>criterionVar&&it<10000){
    it++;
    if(it==10000)
      printf("ups nelder\n");
    for(int j=0;j<size+1;j++)
      (*ptrFct)(inputData,simplex+j*size,evalFct+j);
    qsort(indices, size+1, sizeof(indices[0]), compIndiceDoubleArray);
    for(int i=0;i<size+1;i++){
      sortedIndices[i] = indices[i]-evalFct;
    }
    //Reflect
    for(int i=0;i<size;i++){
      newPoint[i] = -1.0*simplex[i+sortedIndices[size]*size];
      for(int j=0;j<size;j++){
	newPoint[i]+=(2.0/size)*simplex[i+sortedIndices[j]*size];
      }
    }
    (*ptrFct)(inputData,newPoint,evalFctNewPoint);
    if(evalFct[sortedIndices[0]]<=*evalFctNewPoint && evalFct[sortedIndices[size-1]]>*evalFctNewPoint){
    /* if(*(*(indices+0))<=*evalFctNewPoint && *(*(indices+size-1))>*evalFctNewPoint){ */
      // Compute err on variables
      errVar=0.0;
      for(int i=0;i<size;i++)
      	errVar += (simplex[i+sortedIndices[size]*size] - newPoint[i])*(simplex[i+sortedIndices[size]*size] - newPoint[i]);
      errVar=sqrt(errVar)/size;
      //Store new point
      for(int i=0;i<size;i++)
	simplex[i+sortedIndices[size]*size] = newPoint[i];
    }
    else if(evalFct[sortedIndices[0]]>*evalFctNewPoint){
      //Expand
      for(int i=0;i<size;i++){
	newPoint2[i] = -2.0*simplex[i+sortedIndices[size]*size];
	for(int j=0;j<size;j++)
	  newPoint2[i]+=(3.0/size)*simplex[i+sortedIndices[j]*size];
      }    
      (*ptrFct)(inputData,newPoint2,evalFctNewPoint2);
      if(*evalFctNewPoint2<*evalFctNewPoint){
	// Compute err on variables
	errVar=0.0;
	for(int i=0;i<size;i++)
	  errVar += (simplex[i+sortedIndices[size]*size] - newPoint2[i])*(simplex[i+sortedIndices[size]*size] - newPoint2[i]);
	errVar=sqrt(errVar)/size;
	//Store new point 2
	for(int i=0;i<size;i++)
	  simplex[i+sortedIndices[size]*size] = newPoint2[i];
      }
      else{
	// Compute err on variables
	errVar=0.0;
	for(int i=0;i<size;i++)
	  errVar += (simplex[i+sortedIndices[size]*size] - newPoint[i])*(simplex[i+sortedIndices[size]*size] - newPoint[i]);
	errVar=sqrt(errVar)/size;
	//Store new point
	for(int i=0;i<size;i++)
	  simplex[i+sortedIndices[size]*size] = newPoint[i];
      }
      
    }
    else if(evalFct[sortedIndices[size-1]]<=*evalFctNewPoint){
      if(evalFct[sortedIndices[size]]>*evalFctNewPoint){
	//Contract outside
	for(int i=0;i<size;i++){
	  newPoint2[i] = 0.5*newPoint[i];
	  for(int j=0;j<size;j++)
	    newPoint2[i]+=(0.5/size)*simplex[i+sortedIndices[j]*size];
	}    
	(*ptrFct)(inputData,newPoint2,evalFctNewPoint2);
	if(*evalFctNewPoint2<*evalFctNewPoint){
	  // Compute err on variables
	  errVar=0.0;
	  for(int i=0;i<size;i++)
	    errVar += (simplex[i+sortedIndices[size]*size] - newPoint2[i])*(simplex[i+sortedIndices[size]*size] - newPoint2[i]);
	  errVar=sqrt(errVar)/size;
	  //Store new point 2
	  for(int i=0;i<size;i++)
	    simplex[i+sortedIndices[size]*size] = newPoint2[i];
	}
	else{
	  //Shrink step
	  for(int i=0;i<size;i++)
	    for(int j=1;j<size+1;j++){
	      simplex[i+sortedIndices[j]*size] = 0.5*(simplex[i+sortedIndices[j]*size]+simplex[i+sortedIndices[0]*size]);    
	    }
	}
      }
      else{
	//Contract inside
	for(int i=0;i<size;i++){
	  newPoint2[i] = 0.5*simplex[i+sortedIndices[size]*size];
	  for(int j=0;j<size;j++)
	    newPoint2[i]+=(0.5/size)*simplex[i+sortedIndices[j]*size];
	}    
	(*ptrFct)(inputData,newPoint2,evalFctNewPoint2);
	if(*evalFctNewPoint2<*evalFctNewPoint){
	  // Compute err on variables
	  errVar=0.0;
	  for(int i=0;i<size;i++)
	    errVar += (simplex[i+sortedIndices[size]*size] - newPoint2[i])*(simplex[i+sortedIndices[size]*size] - newPoint2[i]);
	  errVar=sqrt(errVar)/size;      
	  //Store new point 2
	  for(int i=0;i<size;i++)
	    simplex[i+sortedIndices[size]*size] = newPoint2[i];
	}
	else{
	  //Shrink step
	  for(int i=0;i<size;i++)
	    for(int j=1;j<size+1;j++){
	      simplex[i+sortedIndices[j]*size] = 0.5*(simplex[i+sortedIndices[j]*size]+simplex[i+sortedIndices[0]*size]);    
	    }    
	}
      }
    }
    else{
      printf("*!*!*!* BUG IN MINIMISATION *!*!*!*\n");
      exit(0);
    }
  }
  // Fin loop sur critere
  for(int i=0;i<size;i++)
    res[i] = simplex[i+sortedIndices[0]*size];
}

// void objectiveFunctionTest(double *inputData, double *gamma, double *valueFctCout) //inputData[12] = {vectAtNode[9] , normalAtNode[3]} ; gamma[1] = angle de rotation autour de la normale
// {
//   *valueFctCout = sqrt((*gamma)*(*gamma));
// }

// void objectiveFunctionTest2D(double *inputData, double *gamma, double *valueFctCout) //inputData[12] = {vectAtNode[9] , normalAtNode[3]} ; gamma[1] = angle de rotation autour de la normale
// {
//   *valueFctCout = 0.0;
//   /* for(int i=-10;i<11;i++){ */
//   /*   *valueFctCout = *valueFctCout + exp(-(gamma[0]-gamma[1])*(gamma[0]-gamma[1]) - 2*gamma[0]*gamma[0])*cos(gamma[1])*sin(2*gamma[1]); */
//   /* } */
//   *valueFctCout = 21*exp(-(gamma[0]-gamma[1])*(gamma[0]-gamma[1]) - 2*gamma[0]*gamma[0])*cos(gamma[1])*sin(2*gamma[1]);
    
//   /* *valueFctCout = (gamma[0]+3)*(gamma[0]+3)+(gamma[1]-1)*(gamma[1]-1)+(gamma[2]-1)*(gamma[2]-1); */
// }

void objectiveFunctionBoundaryNormal(double *inputData, double *gamma, double *valueFctCout) //inputData[12] = {vectAtNode[9] , normalAtNode[3]} ; gamma[1] = angle de rotation autour de la normale
{
  double *normal=inputData+9;
  double crossEuler[9]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  hxtOr3DnormalEulerToFrame(normal,*gamma, crossEuler);
  *valueFctCout = 0.0;
  for(int i=0;i<9;i++){
    *valueFctCout+=(inputData[i]-crossEuler[i])*(inputData[i]-crossEuler[i]);
  }
  *valueFctCout = sqrt(*valueFctCout);  
}

void objectiveFunctionBoundary(double *inputData, double *gamma, double *valueFctCout) //inputData[12] = {vectAtNode[9] , normalAtNode[3]} ; gamma[1] = angle de rotation autour de la normale
{
  double *normal=inputData+9;
  double euler[3]={0.,0.,0.};
  euler[0] = atan2(-1.0*normal[0],normal[1]);
  euler[1] = atan2(-1.0*normal[1],normal[2]*cos(euler[0]));
  euler[2] = *gamma;
  double crossEuler[9]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  hxtOr3DeulerToFrame(crossEuler,euler);
  *valueFctCout = 0.0;
  for(int i=0;i<9;i++){
    *valueFctCout+=(inputData[i]-crossEuler[i])*(inputData[i]-crossEuler[i]);
  }
  *valueFctCout = sqrt(*valueFctCout);  
}

void objectiveFunction(double *inputData, double *euler, double *valueFctCout) //inputData[9] = {vectAtNode[9]} ; euler[3] = {alpha,beta,gamma} rotations de la frame de référence
{
  double crossEuler[9]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  hxtOr3DeulerToFrame(crossEuler,euler);
  *valueFctCout = 0.0;
  for(int i=0;i<9;i++){
    *valueFctCout+=(inputData[i]-crossEuler[i])*(inputData[i]-crossEuler[i]);
  }
  *valueFctCout = sqrt(*valueFctCout);
}

HXTStatus projectionOnInterior(double *frames, int nVert, int cptVbound)
{
  #pragma omp for nowait
  for(int iv = cptVbound; iv < nVert; ++iv){
    double frame[9];
    for(int k=0;k<9;k++)
      frame[k] = frames[nVert*k+iv];
    double frameProj[9]={0.0};
    hxtOr3DprojectFrameOnCrossManifold(frame, frameProj);
    for(int k=0;k<9;k++)
      frames[nVert*k+iv] = frameProj[k];
  }
  return HXT_STATUS_OK;
}

HXTStatus projectionOnBoundaryV2(HXTOrientation3DExpl *or3D, double *frames, double *normals, int nVert, int cptVbound, int *sortedVertices, uint32_t *nodeFixed)
{
#pragma omp for nowait
  for(int iv = 0; iv < cptVbound; ++iv){
    int globNotSortedInd = sortedVertices[iv];
    if(!nodeFixed[globNotSortedInd]){
      // double vNormal[3];  
      // for(int k=0;k<3;k++)
      //   vNormal[k] = normals[nVert*k+iv];
      double vNormal2[3];  
      for(int k=0;k<3;k++)
	vNormal2[k] = normals[nVert*3 + nVert*k+iv];
      if((vNormal2[0]*vNormal2[0]+vNormal2[1]*vNormal2[1]+vNormal2[2]*vNormal2[2])<1e-6){      
	int notSortedIv=sortedVertices[iv];
	double frame[9];
	for(int k=0;k<9;k++)
	  frame[k] = frames[nVert*k+iv];
	double v2D[2]={0.0};
	for(int k=0;k<2;k++)
	  for(int l=0;l<9;l++)
	    v2D[k]+=*(or3D->pInvC[notSortedIv]+k*9+l)*(frame[l]-*(or3D->bcD[notSortedIv]+l));
	//normalize v2D
	double normV2D=sqrt(v2D[0]*v2D[0]+v2D[1]*v2D[1]);
	if(normV2D>1e-8){
	  v2D[0]=v2D[0]/normV2D;
	  v2D[1]=v2D[1]/normV2D;
	}
	else{
	  v2D[0]=1.0;
	  v2D[1]=0.0;
	}
	double directionProj[9]={0.0};
	for(int k=0;k<9;k++){
	  directionProj[k] = *(or3D->bcD[notSortedIv]+k);
	  for(int l=0;l<2;l++)
	    directionProj[k]+=*(or3D->C[notSortedIv]+k*2+l)*v2D[l];
	}
	for(int k=0;k<9;k++)
	  frames[nVert*k+iv] = directionProj[k];
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus projectionOnEdges(double *frames, double *normals, int nVert, int cptVbound)
{
#pragma omp for nowait
  for(int iv = 0; iv < cptVbound; ++iv){
    double vNormal[3];  
    for(int k=0;k<3;k++)
      vNormal[k] = normals[nVert*k+iv];
    double vNormal2[3];  
    for(int k=0;k<3;k++)
      vNormal2[k] = normals[nVert*3 + nVert*k+iv];
    if((vNormal2[0]*vNormal2[0]+vNormal2[1]*vNormal2[1]+vNormal2[2]*vNormal2[2])>1e-6){
      double dirCross[9];
      for(int i=0;i<3;i++)
      	dirCross[i] = vNormal[i];
      for(int i=0;i<3;i++)
      	dirCross[3+i] = vNormal2[i];
      dirCross[6] = vNormal[1]*vNormal2[2]-vNormal[2]*vNormal2[1];
      dirCross[7] = vNormal[2]*vNormal2[0]-vNormal[0]*vNormal2[2];
      dirCross[8] = vNormal[0]*vNormal2[1]-vNormal[1]*vNormal2[0];
      double frame[9]={0.0};
      double frameProj[9]={0.0};
      hxtOr3DdirectionsToFrame(dirCross, frame);
      hxtOr3DprojectFrameOnCrossManifold(frame, frameProj);
      for(int k=0;k<9;k++)
    	frames[nVert*k+iv] = frameProj[k];
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus projection(HXTOrientation3DExpl *or3D, HXTMesh *mesh, double *normals, double *frames, int *sortedVertices, int cptVbound, uint32_t *nodeFixed)
{
  #pragma omp parallel
  {
    projectionOnBoundaryV2(or3D,frames,normals,mesh->vertices.num,cptVbound,sortedVertices,nodeFixed);
    projectionOnInterior(frames,mesh->vertices.num,cptVbound);
  }
  return HXT_STATUS_OK;
}

HXTStatus computeCrossOnEdges(HXTMesh *mesh, double *normals, double *frames,int cptVbound)
{
  #pragma omp parallel
  {
    projectionOnEdges(frames,normals,mesh->vertices.num,cptVbound);
  }
  return HXT_STATUS_OK;
}

static HXTStatus stiffnessMatrixOneTetraExplicit(const HXTMesh *mesh, uint32_t tetK, double S[16]){
  uint32_t *tet = &mesh->tetrahedra.node[tetK*4];
  double x[4][4];
  for (int i = 0; i < 4; i++)
    memcpy(x[i], mesh->vertices.coord + 4*tet[i], sizeof(x[i]));
  double dxdxi[3][3];
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      dxdxi[i][j] = x[i+1][j] - x[0][j];
  double dxidx[3][3];
  double detj;
  HXT_CHECK(hxtInv3x3(dxdxi, dxidx, &detj));
  detj=fabs(detj);
  const double dphi[][3] = {
    {-dxidx[0][0]-dxidx[1][0]-dxidx[2][0],-dxidx[0][1]-dxidx[1][1]-dxidx[2][1],-dxidx[0][2]-dxidx[1][2]-dxidx[2][2]},
    {dxidx[0][0],dxidx[0][1],dxidx[0][2]},
    {dxidx[1][0],dxidx[1][1],dxidx[1][2]},
    {dxidx[2][0],dxidx[2][1],dxidx[2][2]}
  };
  double volume = detj/6;
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j) {
      double m = volume*(dphi[i][0]*dphi[j][0]+dphi[i][1]*dphi[j][1]+dphi[i][2]*dphi[j][2]);
      S[4*i+j]=m;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus computeSizeMask(HXTMesh *mesh, int *multMax)
{
  int *multNodesInt;
  HXT_CHECK(hxtMalloc(&multNodesInt, mesh->vertices.num*sizeof(int)));
  for (uint32_t i=0; i < mesh->vertices.num; ++i)
    multNodesInt[i]=0;
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    uint32_t *tet = &mesh->tetrahedra.node[iel*4];
    for (int i = 0; i < 4; ++i){
      multNodesInt[tet[i]]++;
    }
  }
  *multMax=0;
  for (uint32_t i=0; i < mesh->vertices.num; ++i){
    if(multNodesInt[i]>*multMax){
      *multMax=multNodesInt[i];
    }
  }
  *multMax=(*multMax)*3;
  hxtFree(&multNodesInt);
  return HXT_STATUS_OK;
}

HXTStatus createRelaxingOp(HXTMesh *mesh, int *connectivityOp, double *relaxOp, double *multNodes, double *normals, int size)
{
  //relaxOp[size*(numVert-1)+k], k connect indice k
  int add=0;
  int indAdd=-1;
  int nVert=mesh->vertices.num;
  for (uint32_t i=0; i < mesh->vertices.num; ++i)
    multNodes[i]=0.0;
  for (uint64_t iel=0; iel < mesh->tetrahedra.num; ++iel){
    uint32_t *tet = mesh->tetrahedra.node + iel*4;
    double factor=1.0;
    for(int i=0;i<4;i++){
      double vNormal[3];  
      for(int k=0;k<3;k++)
	vNormal[k] = normals[nVert*k+tet[i]];
      if((vNormal[0]*vNormal[0]+vNormal[1]*vNormal[1]+vNormal[2]*vNormal[2])>1e-6){
	factor=1.0;
      }
    }
    double S[16]={0.0};
    stiffnessMatrixOneTetraExplicit(mesh, iel, S);
    for (int i = 0; i < 16; ++i)
      S[i]=factor*S[i];
    for (int i = 0; i < 4; ++i){
      //DBG
      multNodes[tet[i]]+=S[4*i+i];
      //
      for(int k=0;k<4;k++){
	indAdd=-1;
	add=1;
	if(k!=i){
	  for (int j = 0; j < size; ++j){
	    if(tet[k]==(uint32_t)connectivityOp[size*tet[i]+j]){
	      add=0;
	      //DBG
	      relaxOp[size*tet[i]+j]+=S[4*i+k];
	      break;
	    }
	    if((connectivityOp[size*tet[i]+j]==-1)){
	      indAdd=j;
	      //DBG
	      relaxOp[size*tet[i]+j]+=S[4*i+k];
	      break;
	    }
	  }
	  if(add){
	    //DBG
	    /* double dist=0.0; */
	    /* double *coord=mesh->vertices.coord +4*tet[k]; */
	    /* double *coordRef=mesh->vertices.coord +4*tet[i]; */
	    /* for (int l = 0; l < 3; ++l) */
	    /*   dist+=(coord[l]-coordRef[l])*(coord[l]-coordRef[l]); */
	    /* dist=sqrt(dist); */
	    /* relaxOp[size*tet[i]+indAdd]=-1.0; */
	    /* multNodes[tet[i]]+=1; */
	    /* connectivityOp[size*tet[i]+indAdd]=tet[k]; */
	    //laplace jacobi version
	    /* relaxOp[size*tet[i]+j]+=S[4*i+k]; */
	    connectivityOp[size*tet[i]+indAdd]=tet[k];
	    //
	    /* multNodes[tet[i]]++; */
	  }
	}
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus computeAverageEdgeLength(HXTMesh *mesh, int *connectivityOp, int size, double *averageLength){
  *averageLength=0.0;
  int nEdges=0;
  double min=1e8;
  double max=0.0;
  //Computing 2 times each edge but nevermind
  for (uint32_t i=0; i < mesh->vertices.num; ++i){
    for (int j = 0; j < size; ++j){
      if((connectivityOp[size*i+j]==-1))
	break;
      double *v1Coord = mesh->vertices.coord + 4*i;
      double *v2Coord = mesh->vertices.coord + 4*connectivityOp[size*i+j];
      double dx = v1Coord[0]-v2Coord[0];
      double dy = v1Coord[1]-v2Coord[1];
      double dz = v1Coord[2]-v2Coord[2];
      *averageLength+=sqrt(dx*dx+dy*dy+dz*dz);
      if(sqrt(dx*dx+dy*dy+dz*dz)<min)
	min=sqrt(dx*dx+dy*dy+dz*dz);
      if(sqrt(dx*dx+dy*dy+dz*dz)==0){
	printf("indices : %i %i\n",i,connectivityOp[size*i+j]);
	printf("coord1 : %g %g %g\n",v1Coord[0],v1Coord[1],v1Coord[2]);
      	printf("coord2 : %g %g %g\n",v2Coord[0],v2Coord[1],v2Coord[2]);
	exit(0);
      }
      // if(min==0){
      // 	printf("connect : %i\n",connectivityOp[size*i+j]);
      // 	printf("indices : %i %i\n",i,connectivityOp[size*i+j]);
      // 	printf("coord1 : %g %g %g\n",v1Coord[0],v1Coord[1],v1Coord[2]);
      // 	printf("coord2 : %g %g %g\n",v2Coord[0],v2Coord[1],v2Coord[2]);
      // 	exit(0);
      // }
      if(sqrt(dx*dx+dy*dy+dz*dz)>max)
	max=sqrt(dx*dx+dy*dy+dz*dz);
      nEdges++;
    }
  }
  printf("maxLength : %g | minLength : %g\n",max,min);
  *averageLength/=(1.0*nEdges);
  return HXT_STATUS_OK;
}
										 
HXTStatus relaxSolution(HXTMesh *mesh, int *connectivityOp, double *relaxOp, int *sortedVertices, int *invSortedVertices, double *multNodes, int size, double *solution, uint32_t *nodeFixed)
{
  double alpha= 1.0;
  double *solRelaxed;
  HXT_CHECK(hxtMalloc(&solRelaxed, mesh->vertices.num*sizeof(double)));
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      solRelaxed[i]=0.0;

      int iv = sortedVertices[i];
      if(!nodeFixed[iv]){
        for (int j = 0; j < size; ++j){
          if((connectivityOp[size*iv+j]==-1))
            break;
          solRelaxed[i]-=relaxOp[size*iv+j]*solution[invSortedVertices[connectivityOp[size*iv+j]]];
	  /* solRelaxed[i]+=1.0*solution[invSortedVertices[connectivityOp[size*iv+j]]]; */
        }
	if(fabs(multNodes[iv])>1e-10)
	  solRelaxed[i]=solRelaxed[i]/(multNodes[iv]);
	solRelaxed[i]=solRelaxed[i]*alpha+solution[i]*(1-alpha);
      }
      else{
	solRelaxed[i]=solution[i];
      }
    }
    #pragma omp for nowait
    for (uint32_t iv=0; iv < mesh->vertices.num; ++iv)
      solution[iv]=solRelaxed[iv];
  }
  HXT_CHECK(hxtFree(&solRelaxed));
  return HXT_STATUS_OK;
}

HXTStatus relaxSolutionOct(HXTMesh *mesh, uint32_t **connectivityOpOct, int *sortedVertices, int *invSortedVertices, uint32_t *sizeConnOpOct, double *solution, uint32_t *nodeFixed)
{
  double alpha= 1.0;
  double *solRelaxed;
  HXT_CHECK(hxtMalloc(&solRelaxed, mesh->vertices.num*sizeof(double)));
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      solRelaxed[i]=-solution[i];

      int iv = sortedVertices[i];
      if(!nodeFixed[iv]){
        for (uint32_t j = 0; j < sizeConnOpOct[iv]; ++j){
          // if((connectivityOp[size*iv+j]==-1))
          //   break;
          solRelaxed[i]+=solution[invSortedVertices[(connectivityOpOct[iv])[j]]];
	  /* solRelaxed[i]+=1.0*solution[invSortedVertices[connectivityOp[size*iv+j]]]; */
        }
        solRelaxed[i]=solRelaxed[i]/(sizeConnOpOct[iv]-1);
	solRelaxed[i]=solRelaxed[i]*alpha+solution[i]*(1-alpha);
      }
      else{
	solRelaxed[i]=solution[i];
      }
    }
    #pragma omp for nowait
    for (uint32_t iv=0; iv < mesh->vertices.num; ++iv)
      solution[iv]=solRelaxed[iv];
  }
  HXT_CHECK(hxtFree(&solRelaxed));
  return HXT_STATUS_OK;
}

HXTStatus multiplyOp(HXTMesh *mesh, int *connectivityOp, double *relaxOp, int *sortedVertices, int *invSortedVertices, double *multNodes, int size, double *solution, double *solRelaxed, uint32_t *nodeFixed)
{
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      solRelaxed[i]=0.0;
      int iv = sortedVertices[i];
      if(!nodeFixed[iv]){
        for (int j = 0; j < size; ++j){
          if((connectivityOp[size*iv+j]==-1))
            break;
          solRelaxed[i]+=relaxOp[size*iv+j]*solution[invSortedVertices[connectivityOp[size*iv+j]]];
	  /* solRelaxed[i]+=1.0*solution[invSortedVertices[connectivityOp[size*iv+j]]]; */
        }
        solRelaxed[i]+=multNodes[iv]*solution[i];
      }
      else{
	solRelaxed[i]=solution[i];
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus updateSolLinSearch(HXTMesh *mesh, int *connectivityOp, double *relaxOp, int *sortedVertices, int *invSortedVertices, double *multNodes, int size, double *solution, double *grad, uint32_t *nodeFixed)
{
  double *Kg;
  HXT_CHECK(hxtMalloc(&Kg, mesh->vertices.num*sizeof(double)));
  multiplyOp(mesh, connectivityOp, relaxOp, sortedVertices, invSortedVertices, multNodes, size, grad, Kg, nodeFixed);
  double a=-1;
  hxtOr3DdotProd(Kg,solution,mesh->vertices.num,&a);
  double b;
  hxtOr3DdotProd(Kg,grad,mesh->vertices.num,&b);
  double alpha=a/b;
  /* alpha=0.1; */
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      int iv = sortedVertices[i];
      if(!nodeFixed[iv]){
	solution[i] = solution[i]-alpha*grad[i];
      }
    }
  }
  HXT_CHECK(hxtFree(&Kg));
  return HXT_STATUS_OK;
}

HXTStatus updateSolLinSearchInt(HXTMesh *mesh, int *sortedVertices, double *solution, double *grad, uint32_t *nodeFixed)
{
  double alpha=1.0;
  /* alpha=0.1; */
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      int iv = sortedVertices[i];
      if(!nodeFixed[iv]){
	solution[i] = solution[i]-alpha*grad[i];
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus computeGrad(HXTMesh *mesh, int *connectivityOp, double *relaxOp, int *sortedVertices, int *invSortedVertices, double *multNodes, int size, double *solution, double *grad, uint32_t *nodeFixed)
{
  /* #pragma omp parallel */
  /* { */
  /*   #pragma omp for */
  /*   for (int i=0; i < mesh->vertices.num; ++i){ */
  /*     grad[i]=0.0; */
  /*     int iv = sortedVertices[i]; */
  /*     if(!nodeFixed[iv]){ */
  /*       for (int j = 0; j < size; ++j){ */
  /*         if((connectivityOp[size*iv+j]==-1)) */
  /*           break; */
  /*         grad[i]+=relaxOp[size*iv+j]*solution[invSortedVertices[connectivityOp[size*iv+j]]]; */
  /*       } */
  /*       grad[i]+=multNodes[iv]*solution[i]; */
  /*     } */
  /*     else{ */
  /* 	grad[i]=0.0; */
  /*     } */
  /*   } */
  /* } */
  multiplyOp(mesh, connectivityOp, relaxOp, sortedVertices, invSortedVertices, multNodes, size, solution, grad, nodeFixed);
  return HXT_STATUS_OK;
}

// HXTStatus computeGradInt(HXTMesh *mesh, int *sortedVertices, int *invSortedVertices, double *multNodes, int size, double *framesSorted, double *gradSorted, uint32_t *nodeFixed)
// {
//   int nVert=mesh->vertices.num;
//   double *rhsUnassembled=NULL;
//   HXT_CHECK(hxtAlignedMalloc(&(rhsUnassembled), 9*4*mesh->tetrahedra.num*sizeof(double)));
// #pragma omp parallel
//   {
// #pragma omp for
//     for (uint64_t ieT=0; ieT < mesh->tetrahedra.num; ++ieT){
//       double framesElemNew[9*4];
//       uint32_t *tet = &mesh->tetrahedra.node[ieT*4];
//       uint32_t tetSorted[4];
//       for(int k=0;k<4;k++)
// 	tetSorted[k]=invSortedVertices[tet[k]];
//       for(int k=0;k<4;k++)
// 	for(int j=0;j<9;j++)
// 	  framesElemNew[9*k+j] = framesSorted[nVert*j+tetSorted[k]];

//       double epsilon = 1.0;
//       double *grad=rhsUnassembled+ieT*9*4;
//       computeLocalOpIntegrabilityB(mesh, tet, framesElemNew, epsilon, grad, NULL);
//     }
//   }
//   for (uint32_t iv=0; iv < 9*mesh->vertices.num; ++iv)
//     gradSorted[iv]=0.0;
//   for (uint64_t ieT=0; ieT < mesh->tetrahedra.num; ++ieT){
//     uint32_t *tet = mesh->tetrahedra.node+ieT*4;
//     int tetSorted[4];
//     for(int k=0;k<4;k++)
//       tetSorted[k]=invSortedVertices[tet[k]];

//     for(int k=0;k<4;k++){
//       if(!nodeFixed[tet[k]]){
// 	for(int j=0;j<9;j++){
// 	  gradSorted[nVert*j+tetSorted[k]]+=rhsUnassembled[9*4*ieT+j*4+k];
// 	}
//       }
//     }
    
//   }
//   // testGradValue(mesh, sortedVertices, invSortedVertices, framesSorted);
//   return HXT_STATUS_OK;
// }

// HXTStatus projGradOnTangentSpace(HXTOrientation3DExpl *or3D, HXTMesh *mesh,  double *frames, double *grad, int *sortedVertices, int cptVbound) // last version
// {
//   int nVert = mesh->vertices.num;
// #pragma omp parallel
//   {
// #pragma omp for nowait
//     for (int iv=0; iv < nVert; ++iv){
//       double frame[9];
//       double gradLoc[9];
//       for(int k=0;k<9;k++){
// 	frame[k] = frames[nVert*k+iv];
// 	gradLoc[k] = grad[nVert*k+iv];
//       }
//       for(int i=0;i<6;i++){
//       	for(int j=0;j<6;j++){
// 	  double gradPenalty[9]={0.0};
// 	  hxtOr3DgradPenaltyComp(frame, or3D->base, or3D->crossProdBase, or3D->crossProdBaseSym, gradPenalty,i,j);
// 	  // hxtOr3DgradPenalty(frame, or3D->base, or3D->crossProdBase, or3D->crossProdBaseSym, gradPenalty);
// 	  double normalToTspace[9]={0.0};
// 	  double normN=0.0;
// 	  for(int k=0;k<9;k++){
// 	    normalToTspace[k]=gradPenalty[k];
// 	    normN+=normalToTspace[k]*normalToTspace[k];
// 	  }
// 	  normN=sqrt(normN);
// 	  if(normN<1e-8)
// 	    normN=1.0;
// 	  for(int k=0;k<9;k++)
// 	    normalToTspace[k]/=normN;
// 	  double scalarP=0.0;
// 	  for(int k=0;k<9;k++)
// 	    scalarP+=gradLoc[k]*normalToTspace[k];
// 	  for(int k=0;k<9;k++){
// 	    grad[nVert*k+iv]=grad[nVert*k+iv]-scalarP*normalToTspace[k];
// 	  }
// 	  double scalarTest=0.0;
// 	  for(int k=0;k<9;k++)
// 	    scalarTest+=grad[nVert*k+iv]*normalToTspace[k];
// 	  if(scalarTest>1e-8){
// 	    printf("pb proj grad\n");
// 	    exit(0);
// 	  }
	  
//       	}
//       }
      
//       // if(iv<cptVbound){
//       // 	double gradBC[9]={0.0};
//       // 	hxtOr3DgradBoundary(or3D->bcMat[sortedVertices[iv]], or3D->bcD[sortedVertices[iv]], frame, gradBC);
//       // 	normN=0.0;
//       // 	for(int k=0;k<9;k++){
//       // 	  normalToTspace[k]=gradBC[k];
//       // 	  normN+=normalToTspace[k]*normalToTspace[k];
//       // 	}
//       // 	normN=sqrt(normN);
//       // 	if(normN<1e-8)
//       // 	  normN=1.0;
//       // 	for(int k=0;k<9;k++)
//       // 	  normalToTspace[k]/=normN;
//       // 	scalarP=0.0;
//       // 	for(int k=0;k<9;k++)
//       // 	  scalarP+=gradLoc[k]*normalToTspace[k];
//       // 	for(int k=0;k<9;k++){
//       // 	  grad[nVert*k+iv]=grad[nVert*k+iv]-scalarP*normalToTspace[k];
//       // 	}
//       // 	scalarTest=0.0;
//       // 	for(int k=0;k<9;k++)
//       // 	  scalarTest+=grad[nVert*k+iv]*normalToTspace[k];
//       // 	if(scalarTest>1e-8){
//       // 	  printf("pb proj grad\n");
//       // 	  exit(0);
//       // 	}
//       // }
//     }
//   }
//   return HXT_STATUS_OK;
// }

// HXTStatus projGradOnTangentSpace(HXTOrientation3DExpl *or3D, HXTMesh *mesh,  double *frames, double *grad, int *sortedVertices, int cptVbound)
// {
//   int nVert = mesh->vertices.num;
//   #pragma omp parallel
//   {
//     #pragma omp for nowait
//     for (int iv=0; iv < nVert; ++iv){
//       double frame[9];
//       double gradLoc[9];
//       for(int k=0;k<9;k++){
// 	frame[k] = frames[nVert*k+iv];
// 	gradLoc[k] = grad[nVert*k+iv];
//       }
//       double gradPenalty[9]={0.0};
//       double gradBC[9]={0.0};
//       hxtOr3DgradPenalty(frame, or3D->base, or3D->crossProdBase, or3D->crossProdBaseSym, gradPenalty);
//       if(iv<cptVbound)//if node belong to boundary, add bc in grad
//       	hxtOr3DgradBoundary(or3D->bcMat[sortedVertices[iv]], or3D->bcD[sortedVertices[iv]], frame, gradBC);
//       double normalToTspace[9]={0.0};
//       double normN=0.0;
//       for(int k=0;k<9;k++){
// 	normalToTspace[k]=gradBC[k]+gradPenalty[k];
// 	normN+=normalToTspace[k]*normalToTspace[k];
//       }
//       normN=sqrt(normN);
//       for(int k=0;k<9;k++)
// 	normalToTspace[k]/=normN;
//       double scalarP=0.0;
//       for(int k=0;k<9;k++)
// 	scalarP+=gradLoc[k]*normalToTspace[k];
//       for(int k=0;k<9;k++){
// 	grad[nVert*k+iv]=grad[nVert*k+iv]-scalarP*normalToTspace[k];
//       }
//       double scalarTest=0.0;
//       for(int k=0;k<9;k++)
// 	scalarTest+=grad[nVert*k+iv]*normalToTspace[k];
//       if(scalarTest>1e-8){
// 	printf("pb proj grad\n");
// 	exit(0);
//       }
//     }
//   }
//   return HXT_STATUS_OK;
// }

HXTStatus computeEnergy(HXTMesh *mesh, double *energy, int *connectivityOp, double *relaxOp, int *sortedVertices, int *invSortedVertices, double *multNodes, int size, double *solution)
{
  double *solRelaxed;
  HXT_CHECK(hxtMalloc(&solRelaxed, mesh->vertices.num*sizeof(double)));
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      solRelaxed[i]=0.0;
      int iv = sortedVertices[i];
      for (int j = 0; j < size; ++j){
	if((connectivityOp[size*iv+j]==-1))
	  break;
	/* solRelaxed[i]+=(solution[invSortedVertices[connectivityOp[size*iv+j]]]-solution[i])*(solution[invSortedVertices[connectivityOp[size*iv+j]]]-solution[i]); */
	solRelaxed[i]+=relaxOp[size*iv+j]*solution[invSortedVertices[connectivityOp[size*iv+j]]];
      }
      /* solRelaxed[i]=solRelaxed[i]/(1.0*multNodes[iv]); */
      solRelaxed[i]+=multNodes[iv]*solution[i];
    }
  }
  *energy =0.0;
  /* printf("n : %i\n",mesh->vertices.num/1000); */
  /* for (int i=0; i < mesh->vertices.num/1000; ++i) */
  /*   printf("sol : %g\n",solution[i]); */
  for (uint32_t i=0; i < mesh->vertices.num; ++i){
    *energy += solRelaxed[i]*solution[i];
    /* *energy += solRelaxed[i]; */
  }
  /* //DBG */
  /*   *energy += solRelaxed[i]*solRelaxed[i]; */
  /* // */
  *energy = (*energy)/2.0;
  HXT_CHECK(hxtFree(&solRelaxed));
  return HXT_STATUS_OK;
}

HXTStatus computeEnergyOct(HXTMesh *mesh, double *energy, uint32_t **connectivityOpOct, int *sortedVertices, int *invSortedVertices, uint32_t *sizeConnOpOct, double *solution)
{
  double *solRelaxed;
  HXT_CHECK(hxtMalloc(&solRelaxed, mesh->vertices.num*sizeof(double)));
  #pragma omp parallel
  {
    #pragma omp for
    for (uint32_t i=0; i < mesh->vertices.num; ++i){
      solRelaxed[i]=solution[i];
      int iv = sortedVertices[i];
      for (uint32_t j = 0; j < sizeConnOpOct[iv]; ++j){
	// if((connectivityOp[size*iv+j]==-1))
	//   break;
	/* solRelaxed[i]+=(solution[invSortedVertices[connectivityOp[size*iv+j]]]-solution[i])*(solution[invSortedVertices[connectivityOp[size*iv+j]]]-solution[i]); */
	solRelaxed[i]-=solution[invSortedVertices[(connectivityOpOct[iv])[j]]];
      }
      /* solRelaxed[i]=solRelaxed[i]/(1.0*multNodes[iv]); */
      solRelaxed[i]+=(sizeConnOpOct[iv]-1)*solution[i];
    }
  }
  *energy =0.0;
  /* printf("n : %i\n",mesh->vertices.num/1000); */
  /* for (int i=0; i < mesh->vertices.num/1000; ++i) */
  /*   printf("sol : %g\n",solution[i]); */
  for (uint32_t i=0; i < mesh->vertices.num; ++i){
    *energy += solRelaxed[i]*solution[i];
    /* *energy += solRelaxed[i]; */
  }
  /* //DBG */
  /*   *energy += solRelaxed[i]*solRelaxed[i]; */
  /* // */
  *energy = (*energy)/2.0;
  HXT_CHECK(hxtFree(&solRelaxed));
  return HXT_STATUS_OK;
}

HXTStatus addConstraintEnergy(HXTMesh *mesh, double *energy, double *frames)
{
  double energyConstraint=0.0;
  for(uint32_t i=0; i < mesh->vertices.num; ++i){
    double quality=0.0;
    double frame[9];
    for(int k=0; k < 9; ++k)
      frame[k]=frames[mesh->vertices.num*k+i];
    hxtOr3DcomputeQuality(frame, &quality);	
    energyConstraint += quality/2.0;
  }
  *energy+=energyConstraint/mesh->vertices.num;
  return HXT_STATUS_OK;
}

HXTStatus computeBndNormalsExplicit(HXTMesh *mesh, double *normals) {
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

HXTStatus buildOr3DExpl(HXTOrientation3DExpl *or3D, HXTMesh *mesh, double *normals, double *frames)
{
  or3D->mesh=mesh;
  or3D->frames=frames;
  or3D->normals = normals;
  or3D->connectivityOpOct=NULL;
  or3D->sizeConnOpOct=NULL;
  or3D->multNodes=NULL;
  or3D->connectivityOp=NULL;
  or3D->relaxOp=NULL;
  or3D->framesSorted=NULL;
  or3D->normalsSorted=NULL;
  or3D->nodesFixed=NULL;
  or3D->sortedVertices=NULL;
  or3D->invSortedVertices=NULL;
  /* HXT_CHECK(hxtMalloc(&(or3D->normals), mesh->vertices.num*2*3*sizeof(double))); */
  /* HXT_CHECK(computeBndNormalsExplicit(or3D->mesh, or3D->normals)); */
  HXT_CHECK(hxtMalloc(&(or3D->bcMat), mesh->vertices.num*sizeof(double*)));
  HXT_CHECK(hxtAlignedMalloc(&(or3D->pInvC), mesh->vertices.num*sizeof(double*)));
  HXT_CHECK(hxtAlignedMalloc(&(or3D->C), mesh->vertices.num*sizeof(double*)));
  HXT_CHECK(hxtAlignedMalloc(&(or3D->bcD), mesh->vertices.num*sizeof(double*)));
  //Create boundary condition operators at nodes
  for (uint32_t iv = 0; iv < mesh->vertices.num; ++iv){
    double* n;
    n = or3D->normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])>1e-1){
      HXT_CHECK(hxtMalloc(&(or3D->bcMat[iv]), 81*sizeof(double)));
      HXT_CHECK(hxtMalloc(&(or3D->bcD[iv]), 9*sizeof(double)));
      HXT_CHECK(hxtMalloc(&(or3D->pInvC[iv]), 18*sizeof(double)));
      HXT_CHECK(hxtMalloc(&(or3D->C[iv]), 18*sizeof(double)));
      double H[9][9];
      double a,b;
      hxtOr3DeulerAnglesOfNormal(n, &a, &b);
      double C[9][2];
      double D[9];
      hxtOr3DcombinationOnBorder(a, b, C, D);
      /* S = C^T C, iS = S^-1 */
      double S[2][2];
      for(uint8_t i=0;i<2;i++){
	for(uint8_t j=0;j<2;j++){
	  S[i][j]=0;
	  for(uint8_t k=0;k<9;k++){
	    S[i][j] += C[k][i] * C[k][j];
	  }
	}
      }
      double iS[2][2], dS;
      hxtInv2x2(S, iS, &dS);
      /* pInv = (C^T C)^-1 C^T = iS C^T */
      double pInv[2][9];
      for(uint8_t i=0;i<2;i++){
	for(uint8_t j=0;j<9;j++){
	  pInv[i][j]=0;
	  for(uint8_t k=0;k<2;k++){
	    pInv[i][j] += iS[i][k] * C[j][k];
	  }
	}
      }
      hxtOr3DboundaryConstraintMatrix(C, H);
      for (int k = 0; k < 9; ++k){
      	*(or3D->bcD[iv]+k)=D[k];
	for (int l = 0; l < 2; ++l){
	  *(or3D->pInvC[iv]+l*9+k)=pInv[l][k];
	  *(or3D->C[iv]+k*2+l)=C[k][l];
	}
      	for (int l = 0; l < 9; ++l)
      	  *(or3D->bcMat[iv]+9*k+l)=H[k][l];
      }
    }
  }
  hxtOr3DgetBase(or3D->base);
  hxtOr3DcrossProdBase(or3D->base,or3D->crossProdBase,or3D->crossProdBaseSym);
  return HXT_STATUS_OK;
}

HXTStatus destroyOr3DExpl(HXTOrientation3DExpl *or3D)
{
  for (uint32_t iv = 0; iv < or3D->mesh->vertices.num; ++iv){
    double* n;
    n = or3D->normals + 3*iv;
    if(sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2])>1e-1){
      HXT_CHECK(hxtFree(&(or3D->bcMat[iv])));
      HXT_CHECK(hxtFree(&(or3D->bcD[iv])));
      HXT_CHECK(hxtFree(&(or3D->pInvC[iv])));
      HXT_CHECK(hxtFree(&(or3D->C[iv])));
    }
  }
  HXT_CHECK(hxtFree(&(or3D->bcMat)));
  HXT_CHECK(hxtAlignedFree(&(or3D->bcD)));
  HXT_CHECK(hxtAlignedFree(&(or3D->pInvC)));
  HXT_CHECK(hxtAlignedFree(&(or3D->C)));
  
  if(or3D->nodesFixed)
    HXT_CHECK(hxtFree(&or3D->nodesFixed));
  if(or3D->normals)
    HXT_CHECK(hxtFree(&or3D->normals));
  if(or3D->sortedVertices)
    HXT_CHECK(hxtFree(&or3D->sortedVertices));
  if(or3D->invSortedVertices)
    HXT_CHECK(hxtFree(&or3D->invSortedVertices));
  if(or3D->framesSorted)
    HXT_CHECK(hxtAlignedFree(&or3D->framesSorted));
  if(or3D->normalsSorted)
    HXT_CHECK(hxtAlignedFree(&or3D->normalsSorted));
  if(or3D->multNodes)
    HXT_CHECK(hxtFree(&or3D->multNodes));
  if(or3D->connectivityOp)
    HXT_CHECK(hxtFree(&or3D->connectivityOp));
  if(or3D->connectivityOpOct)
    for(uint32_t iv=0;iv<or3D->mesh->vertices.num;iv++)
      HXT_CHECK(hxtFree(&(or3D->connectivityOpOct[iv])));
  if(or3D->connectivityOpOct)
    HXT_CHECK(hxtFree(&or3D->connectivityOpOct));
  if(or3D->sizeConnOpOct)
    HXT_CHECK(hxtFree(&or3D->sizeConnOpOct));
  if(or3D->relaxOp)
    HXT_CHECK(hxtFree(&or3D->relaxOp));

  /* HXT_CHECK(hxtFree(&(or3D->normals))); */
  return HXT_STATUS_OK;
}

HXTStatus setInitialFramesExplicit(HXTMesh *mesh,double *frames, double *normals, int hasToBeInitialized)
{
  if(hasToBeInitialized){
    double *n;
    for (uint32_t iv = 0; iv < mesh->vertices.num; ++iv) {
      n = normals + 3*iv;
      const double normN = n[0]*n[0]+n[1]*n[1]+n[2]*n[2];
      //    DBG
      /* const double normN = 0; */
      //
      if (normN > 1e-6) {
      // if (0) {
	hxtOr3DnormalEulerToFrame(n, 0.0, frames+9*iv);
      }
      else{
	double *d= frames+9*iv;
	// d[0]=1;
	// d[1]=1;
	// d[2]=1;
	/* d[0]=3.0/5.0; */
	/* d[1]=3.0/5.0; */
	/* d[2]=3.0/5.0; */
	d[0]=0.63246;
	d[1]=0.63246;
	d[2]=0.63246;
	// d[0]=0.;
	// d[1]=0.;
	// d[2]=0.;
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

HXTStatus buildSortedVerticesArrays(HXTOrientation3DExpl *or3D){
  HXTMesh *mesh=or3D->mesh;
  double *normals=or3D->normals;
  double *frames=or3D->frames;
  int *sortedVertices;
  HXT_CHECK(hxtMalloc(&sortedVertices, mesh->vertices.num*sizeof(int)));
  int *invSortedVertices;
  HXT_CHECK(hxtMalloc(&invSortedVertices, mesh->vertices.num*sizeof(int)));
  int cptVbound=0;
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    if((normals[3*i+0]*normals[3*i+0]+normals[3*i+1]*normals[3*i+1]+normals[3*i+2]*normals[3*i+2])>1e-1){
      sortedVertices[cptVbound]=i;
      invSortedVertices[i] = cptVbound;
      cptVbound++;
    }
  }
  int cptVint=0;
  for(uint32_t i=0;i<mesh->vertices.num;i++){
    if((normals[3*i+0]*normals[3*i+0]+normals[3*i+1]*normals[3*i+1]+normals[3*i+2]*normals[3*i+2])<=1e-1){
      sortedVertices[cptVbound+cptVint]=i;
      invSortedVertices[i] = cptVbound+cptVint;
      cptVint++;
    }
  }
  double *framesSorted;
  HXT_CHECK(hxtAlignedMalloc(&framesSorted, 9*mesh->vertices.num*sizeof(double)));
  for(int k=0;k<9;k++){
    for(uint32_t i=0;i<mesh->vertices.num;i++)
      framesSorted[mesh->vertices.num*k+i] = frames[9*sortedVertices[i]+k];
  }
  double *normalsSorted;
  HXT_CHECK(hxtAlignedMalloc(&normalsSorted, 2*3*mesh->vertices.num*sizeof(double)));
  for(int k=0;k<3;k++){
    for(uint32_t i=0;i<mesh->vertices.num;i++)
      normalsSorted[mesh->vertices.num*k+i] = normals[3*sortedVertices[i]+k];
    for(uint32_t i=0;i<mesh->vertices.num;i++)
      normalsSorted[mesh->vertices.num*3 + mesh->vertices.num*k+i] = normals[mesh->vertices.num*3 + 3*sortedVertices[i]+k];
  }
  or3D->sortedVertices=sortedVertices;
  or3D->invSortedVertices=invSortedVertices;
  or3D->cptVbound=cptVbound;
  or3D->cptVint=cptVint;
  or3D->framesSorted=framesSorted;
  or3D->normalsSorted=normalsSorted;
  return HXT_STATUS_OK;
}

HXTStatus buildNodesFixed(HXTOrientation3DExpl *or3D, int fixeAllCrossesOnBoundary, int *isBoundaryCondition){
  HXTMesh *mesh=or3D->mesh;
  double *normals=or3D->normals;
  uint32_t *nodeFixed;
  HXT_CHECK(hxtMalloc(&nodeFixed, mesh->vertices.num*sizeof(uint32_t)));
  for(uint32_t i=0;i<mesh->vertices.num;i++)
    nodeFixed[i]=0;
  int cptNodeFixed = 0;
  if(fixeAllCrossesOnBoundary){
    if(isBoundaryCondition){
      for(uint32_t i=0;i<mesh->vertices.num;i++){
	if(isBoundaryCondition[i]){
	  // printf("node fixed\n");
	  nodeFixed[i]=1;
	  cptNodeFixed++;
	}
      }
    }
    else{
      for(uint32_t i=0;i<mesh->vertices.num;i++){
	double normN=0.0;
	for(int k=0;k<3;k++)
	  normN+=normals[3*i+k]*normals[3*i+k];
	normN=sqrt(normN);
	if(normN>1e-6){
	  // printf("node fixed 1\n");
	  nodeFixed[i]=1;
	  cptNodeFixed++;
	}
      }
    }
  }
  else{
    for(uint32_t i=0;i<mesh->vertices.num;i++){
      double normN2=0.0;
      for(int k=0;k<3;k++)
	normN2+=normals[mesh->vertices.num*3 + 3*i+k]*normals[mesh->vertices.num*3 + 3*i+k];
      normN2=sqrt(normN2);
      if(normN2>1e-6){
	// printf("node fixed 2\n");
	nodeFixed[i]=1;
	cptNodeFixed++;
      }
    }
  }
  or3D->nodesFixed=nodeFixed;
  or3D->cptNodesFixed=cptNodeFixed;
  return HXT_STATUS_OK;
}

HXTStatus buildRelaxingOperators(HXTOrientation3DExpl *or3D, double epsilon, int typeRelaxOp, double precision, int maxIter, int P){
  HXTMesh *mesh=or3D->mesh;
  double *normals=or3D->normals;
  or3D->precision=precision;
  or3D->maxIter=maxIter;
  or3D->projectionAfterSolve=P;
  //Gauss-Seidel on laplacian FE operator
  // Create relaxing operator
  double *multNodes;
  HXT_CHECK(hxtMalloc(&multNodes, mesh->vertices.num*sizeof(double)));
  int size[1];
  *size=0;
  HXT_CHECK(computeSizeMask(mesh, size));
  /* printf("size = %i\n",*size); */
  int *connectivityOp;
  HXT_CHECK(hxtMalloc(&connectivityOp, mesh->vertices.num*(*size)*sizeof(int)));
  double *relaxOp;
  HXT_CHECK(hxtMalloc(&relaxOp, mesh->vertices.num*(*size)*sizeof(double)));
  for(int i=0;i<*size;i++)
    for(uint32_t j=0;j<mesh->vertices.num;j++)
      connectivityOp[*size*j+i]=-1;
  for(int i=0;i<*size;i++)
    for(uint32_t j=0;j<mesh->vertices.num;j++){
      relaxOp[*size*j+i]=0.0;
    }
  // printf("create first relax op\n");
  HXT_CHECK(createRelaxingOp(mesh, connectivityOp, relaxOp, multNodes, normals, *size));
  double averageLength=0.0;
  HXT_CHECK(computeAverageEdgeLength(mesh, connectivityOp, *size, &averageLength));
  printf("averageLength : %g\n",averageLength);
  or3D->multNodes=multNodes;
  or3D->size[0]=size[0];
  or3D->connectivityOp=connectivityOp;
  or3D->relaxOp=relaxOp;
  or3D->typeRelax=typeRelaxOp;
  switch(typeRelaxOp){
  case 1: //Replacing value at node by average of values at nodes which are at a distance <= epsilon
    {
      uint32_t **connectivityOpOct;
      uint32_t *sizeConnOpOct;
      // Octree connectivity
      // printf("create octree connectivity\n");
      std::vector<Point3f> vectVertices;
      for(uint32_t j=0;j<mesh->vertices.num;j++){
	float x = (float) mesh->vertices.coord[4*j+0];
	float y = (float) mesh->vertices.coord[4*j+1];
	float z = (float) mesh->vertices.coord[4*j+2];
	vectVertices.push_back(Point3f(x, y, z));
      }
      unibn::Octree<Point3f> octree;
      unibn::OctreeParams params;
      octree.initialize(vectVertices);

      HXT_CHECK(hxtMalloc(&connectivityOpOct, mesh->vertices.num*sizeof(uint32_t*)));
      HXT_CHECK(hxtMalloc(&sizeConnOpOct, mesh->vertices.num*sizeof(uint32_t)));
  
      //build connectivity
      uint32_t max=0;
      uint32_t min=1e8;
      double average=0.0;
      if(epsilon<0)
	epsilon=3*averageLength;
      else if(epsilon==0)
	epsilon=1e-14;
      printf("epsilon : %g\n",epsilon);
      for(uint32_t j=0;j<mesh->vertices.num;j++){
	std::vector<uint32_t> results;
	const Point3f& q = vectVertices[j];
	octree.radiusNeighbors<unibn::L2Distance<Point3f> >(q, (float) epsilon, results);
	size_t nConn = 0;
	for (int l = 0; l < *size; ++l){
	  if((connectivityOp[*size*j+l]==-1))
	    break;
	  nConn++;
	}
	if((results.size()-1)<nConn){
	  results.clear();
	  results.push_back(j);
	  for(size_t k=0;k<nConn;k++){
	    uint32_t connectedInd=(uint32_t) connectivityOp[*size*j+k];
	    results.push_back(connectedInd);
	  }
	}
	HXT_CHECK(hxtMalloc(&(connectivityOpOct[j]), results.size()*sizeof(uint32_t)));
	sizeConnOpOct[j]=results.size();

	for(uint32_t k=0;k<sizeConnOpOct[j];k++)
	  (connectivityOpOct[j])[k]=results[k];
	average+=sizeConnOpOct[j];
	if(sizeConnOpOct[j]>max)
	  max=sizeConnOpOct[j];
	if(sizeConnOpOct[j]<min)
	  min=sizeConnOpOct[j];
      }
      average/=mesh->vertices.num;
      printf("max : %i | min : %i | average : %g\n",max,min,average);
      printf("-----------------------\n");
      or3D->connectivityOpOct=connectivityOpOct;
      or3D->sizeConnOpOct=sizeConnOpOct;
      break;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus or3DrelaxSolution(HXTOrientation3DExpl *or3D){
  int nSmooth=1;
  double *solution;
  switch(or3D->typeRelax){
  case 0: //Gauss-Seidel on laplacian FE operator
    {
      for (int l = 0; l < nSmooth; ++l)
	for (int k = 0; k < 9; ++k){
	  solution = or3D->framesSorted+or3D->mesh->vertices.num*k;
	  HXT_CHECK(relaxSolution(or3D->mesh, or3D->connectivityOp, or3D->relaxOp, or3D->sortedVertices, or3D->invSortedVertices, or3D->multNodes, or3D->size[0], solution, or3D->nodesFixed));
	}

      break;
    }
  case 1: //Replacing value at node by average of values at nodes which are at a distance <= epsilon
    {
      for (int l = 0; l < nSmooth; ++l)
	for (int k = 0; k < 9; ++k){
	  solution = or3D->framesSorted+or3D->mesh->vertices.num*k;
	  HXT_CHECK(relaxSolutionOct(or3D->mesh, or3D->connectivityOpOct, or3D->sortedVertices, or3D->invSortedVertices, or3D->sizeConnOpOct, solution, or3D->nodesFixed));
	}

      break;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus or3DComputeEnergy(HXTOrientation3DExpl *or3D, double *energyTot){
  double energy[9]={0.0};
  for (int k = 0; k < 9; ++k){
    double *solution = or3D->framesSorted+or3D->mesh->vertices.num*k;
    //
    HXT_CHECK(computeEnergy(or3D->mesh, energy+k, or3D->connectivityOp, or3D->relaxOp, or3D->sortedVertices, or3D->invSortedVertices, or3D->multNodes, or3D->size[0], solution));
    //
    // HXT_CHECK(computeEnergyOct(mesh, energy+k, connectivityOpOct, sortedVertices, invSortedVertices, sizeConnOpOct, solution));
  }
  *energyTot=0.0;
  for (int k = 0; k < 9; ++k){
    *energyTot += energy[k];
  }
  return HXT_STATUS_OK;
}

HXTStatus or3DprojectSolOnCrossManifold(HXTOrientation3DExpl *or3D){
  HXT_CHECK(projection(or3D,or3D->mesh, or3D->normalsSorted, or3D->framesSorted, or3D->sortedVertices, or3D->cptVbound,or3D->nodesFixed));
  return HXT_STATUS_OK;
}

HXTStatus computeCriterion(const double *energyList, int ne, double *critPente){
  double energyMobileMean=0.0;
  int sizeMean=9;
  int itMean = 0;
  ((ne) > (sizeMean) ? (itMean=sizeMean) : (itMean=ne));
  for(int i=ne-itMean;i<ne+1;i++){
    energyMobileMean+=energyList[i];
  }
  energyMobileMean/=(itMean+1);
  double pente = 0.0;
  double meanIter = 0.0;
  for(int i=ne-itMean;i<ne+1;i++){
    meanIter += i;
  }
  meanIter/=(itMean+1);
  double sum = 0.0;
  for(int i=ne-itMean;i<ne+1;i++){
    pente += (i-meanIter)*(energyList[i]/energyMobileMean-1);
    sum += (i-meanIter)*(i-meanIter);
  }
  if(ne>0)
    pente/=sum;
  else
    pente = 1.0;
  *critPente=fabs(pente);
  return HXT_STATUS_OK;
}

HXTStatus solveSmoothThenProject(HXTOrientation3DExpl *or3D){
  time_t depart, arrivee;
  HXTMesh *mesh=or3D->mesh;
  int ne = 0;
  int maxIt = or3D->maxIter;
  printf("Vertices number : %i\n",mesh->vertices.num);
  printf("Start explicit solve\n");
  time(&depart);
  double *energyList;
  double precision=or3D->precision;
  double energyTot=precision+1.0;
  HXT_CHECK(hxtMalloc(&energyList, maxIt*sizeof(double)));
  for(int i=0;i<maxIt;i++)
    energyList[i] = -1;
  double critPente=1.0;
  while(((fabs(critPente)>precision&&ne<maxIt))&&energyTot>precision){
    // Projection step
    HXT_CHECK(or3DprojectSolOnCrossManifold(or3D));
    // Relaxing step
    HXT_CHECK(or3DrelaxSolution(or3D));
    HXT_CHECK(or3DComputeEnergy(or3D, &energyTot));
    energyList[ne]=energyTot;
    computeCriterion(energyList, ne, &critPente);
    ne++;
    printf("--- explicit iteration %d, relative error %g | energy: %.20f\n",ne,critPente, energyTot);
  }
  if(or3D->projectionAfterSolve){
    HXT_CHECK(or3DprojectSolOnCrossManifold(or3D));
    int saveTypeRelax=or3D->typeRelax;
    or3D->typeRelax=0;
    or3DrelaxSolution(or3D);
    or3D->typeRelax=saveTypeRelax;
  }
  time(&arrivee);
  printf("Unknown number : %" PRIu32 "\n",mesh->vertices.num*9);
  printf("Tet number : %"  PRIu64 "\n",mesh->tetrahedra.num);
  printf("Nodes number : %" PRIu32 "\n",mesh->vertices.num);
  printf("Solving time : %f s.\n", difftime(arrivee, depart));
  HXT_CHECK(hxtFree(&energyList));
  return HXT_STATUS_OK;
}

HXTStatus transferSolFromSortedToUnsorted(HXTOrientation3DExpl *or3D){
  for(int k=0;k<9;k++){
    for(uint32_t i=0;i<or3D->mesh->vertices.num;i++)
      or3D->frames[9*or3D->sortedVertices[i]+k] = or3D->framesSorted[or3D->mesh->vertices.num*k+i];
  }
  return HXT_STATUS_OK;
}

HXTStatus computeFramesExplicit(HXTMesh *mesh, double *frames, double precision, int maxIter, int framesHasToBeinitialized, int flagFixNodes, double epsilon, int L, int P, int *isBoundaryCondition){
  //flagFixedNodes:
  //0 : crosses fixed at edges
  //1 : crosses fixed on surface
  //Memory allocation
  double *normals;
  HXT_CHECK(hxtMalloc(&normals, mesh->vertices.num*2*3*sizeof(double)));
  HXT_CHECK(computeBndNormalsExplicit(mesh, normals));
  //Solution initialization
  HXT_CHECK(setInitialFramesExplicit(mesh,frames,normals,framesHasToBeinitialized));
  HXTOrientation3DExpl or3D;
  HXT_CHECK(buildOr3DExpl(&or3D, mesh, normals, frames));
  //Sorting nodes for parallelization
  HXT_CHECK(buildSortedVerticesArrays(&or3D));
  HXT_CHECK(buildNodesFixed(&or3D,flagFixNodes,isBoundaryCondition));
  int typeRelaxOp=0;
  if(L)
    typeRelaxOp=0; //Gauss-Seidel on laplacian FE operator
  else
    typeRelaxOp=1; //Average in a region of radius epsilon
  HXT_CHECK(buildRelaxingOperators(&or3D, epsilon, typeRelaxOp, precision, maxIter, P));
  // compute crosses on edges
  if(framesHasToBeinitialized)
    HXT_CHECK(computeCrossOnEdges(mesh, or3D.normalsSorted, or3D.framesSorted, or3D.cptVbound));  
  // Explicit iterations
  HXT_CHECK(solveSmoothThenProject(&or3D));
  double energyTot=0.0;
  HXT_CHECK(or3DComputeEnergy(&or3D, &energyTot));
  HXT_CHECK(addConstraintEnergy(mesh,&energyTot,or3D.framesSorted));
  printf("--- energy final: %g\n", energyTot);
  HXT_CHECK(transferSolFromSortedToUnsorted(&or3D));
  // double *knotchEner;
  // HXT_CHECK(hxtMalloc(&knotchEner, mesh->tetrahedra.num*sizeof(double)));  
  // computeMeshEnergyKnotch(or3D.mesh, or3D.frames, knotchEner);
  // hxtOr3DWritePosScalarTet(mesh, NULL, knotchEner, "knotchEner.pos");
  // HXT_CHECK(hxtFree(&knotchEner));
  //test grad knotch ener
  // testGradValue(or3D.mesh, or3D.invSortedVertices, or3D.framesSorted);
  HXT_CHECK(destroyOr3DExpl(&or3D));
  return HXT_STATUS_OK;
}

HXTStatus hxtComputeFramesExplicit(HXTMesh *mesh, double *frames, double precision, int maxIter, int framesHasToBeinitialized, int flagFixNodes, double epsilon, int L, int P, int *isBoundaryCondition){
  //Renumbering nodes if there is alone vertices
  HXTOrientation3DCleanMesh cleanMeshObj;
  buildCleanMesh(&cleanMeshObj,mesh);
  cleanMeshCleanSolution(&cleanMeshObj, frames, 9);
  computeFramesExplicit(mesh, frames, precision, maxIter, framesHasToBeinitialized, flagFixNodes, epsilon, L, P, isBoundaryCondition);
  //Restoring mesh and solution
  cleanMeshRestoreMesh(&cleanMeshObj);
  uint32_t nFieldsSol=9;
  cleanMeshRestoreSolution(&cleanMeshObj,frames,nFieldsSol);
  cleanMeshDestroy(&cleanMeshObj);
  return HXT_STATUS_OK;
}

HXTStatus fitCrossesToQuadSurfMesh(HXTMesh *quadMesh, HXTMesh *tetMesh, double *frames){
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
  int nNodesOnBnd=0;
  double *normals;
  HXT_CHECK(hxtMalloc(&normals, tetMesh->vertices.num*2*3*sizeof(double)));
  HXT_CHECK(computeBndNormalsExplicit(tetMesh, normals));
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
  printf("number nodes matching : %i\n",cptMatchingNodes);
  printf("Not Matching nodes : \n");
  FILE* myfile = fopen("NODESDBG.pos","w");
  fprintf(myfile,"View \"Quality\"{\n");
  // fprintf(myfile,"View \"constraint check\"{\n");
  double value=10.0;
  for(uint32_t ivT=0; ivT<tetMesh->vertices.num; ivT++){
    if(tetToQuad[ivT]==(uint32_t)(-1)){
      double *x = tetMesh->vertices.coord + 4*ivT;
      fprintf(myfile,"SP(%.16g,%.16g,%.16g){%.16g};\n",x[0],x[1],x[2],value);
    }
  }
  fprintf(myfile,"};");
  fclose(myfile);
  //get all directions given by connectivities at quad nodes
  double *mandel4thQuadMesh;
  HXT_CHECK(hxtMalloc(&mandel4thQuadMesh, quadMesh->vertices.num*36*sizeof(double)));
  double *frameQuadMesh;
  HXT_CHECK(hxtMalloc(&frameQuadMesh, quadMesh->vertices.num*9*sizeof(double)));
  for(uint64_t iQ=0; iQ<quadMesh->quads.num; iQ++){
    for(int k=0;k<4;k++){
      uint32_t ivQ = quadMesh->quads.node[4*iQ+k];
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
      hxtNormalizeV3(d1);
      hxtNormalizeV3(d2);
      double mandel2ndD1[6]={0.0};
      double mandel2ndD2[6]={0.0};
      hxtOr3Dvec3ToMandel2ndDyadic(d1, mandel2ndD1);
      hxtOr3Dvec3ToMandel2ndDyadic(d2, mandel2ndD2);
      double *mandel4th=mandel4thQuadMesh+36*ivQ;
      for(int i = 0; i < 6; i++)
	for(int j = 0; j < 6; j++)
	  mandel4th[6*i+j]+=mandel2ndD1[i]*mandel2ndD1[j]+mandel2ndD2[i]*mandel2ndD2[j];
    }
  }
  for(uint32_t ivQ=0; ivQ<quadMesh->vertices.num; ivQ++){
    if(quadToTet[ivQ]!=(uint32_t)(-1)){
      double normN=0.0;
      hxtNorm2V(normals+3*quadToTet[ivQ], 3, &normN);
      double normN2=0.0;
      hxtNorm2V(normals+3*tetMesh->vertices.num+3*quadToTet[ivQ], 3, &normN2);
      if(normN>1e-6){
	double *mandel4th=mandel4thQuadMesh+36*ivQ;
	double mandel2ndNormal[6]={0.0};
	hxtOr3Dvec3ToMandel2ndDyadic(normals+3*quadToTet[ivQ], mandel2ndNormal);
	for(int i = 0; i < 6; i++)
	  for(int j = 0; j < 6; j++)
	    mandel4th[6*i+j]+=mandel2ndNormal[i]*mandel2ndNormal[j];
      }
      if(normN2>1e-6){
	double *mandel4th=mandel4thQuadMesh+36*ivQ;
	double mandel2ndNormal[6]={0.0};
	hxtOr3Dvec3ToMandel2ndDyadic(normals+3*quadMesh->vertices.num+3*quadToTet[ivQ], mandel2ndNormal);
	for(int i = 0; i < 6; i++)
	  for(int j = 0; j < 6; j++)
	    mandel4th[6*i+j]+=mandel2ndNormal[i]*mandel2ndNormal[j];
      }
    }
  }
  for(uint32_t ivQ=0; ivQ<quadMesh->vertices.num; ivQ++){
    if(quadToTet[ivQ]!=(uint32_t)(-1)){
      double *mandel4th=mandel4thQuadMesh+36*ivQ;
      double frame[9]={0.0};
      double *frameProj=frameQuadMesh+9*ivQ;
      hxtOr3Dmandel4thToFrame(mandel4th, frame);
      hxtOr3DprojectFrameOnCrossManifold(frame, frameProj);
    }
  }
  HXT_CHECK(hxtFree(&mandel4thQuadMesh));
  HXT_CHECK(hxtFree(&normals));
  //transfer data to *frames
  for(uint32_t ivT=0; ivT<quadMesh->vertices.num; ivT++){
    for(int k = 0; k < 9; k++)
      frames[9*ivT+k]=0.0;
  }
  for(uint32_t ivQ=0; ivQ<quadMesh->vertices.num; ivQ++){
    uint32_t ivT=quadToTet[ivQ];
    if(ivT!=(uint32_t)(-1)){
      double *frame=frameQuadMesh+9*ivQ;
      for(int k = 0; k < 9; k++)
	frames[9*ivT+k]=frame[k];
    }
  }
  HXT_CHECK(hxtFree(&indTetVertBnd));
  HXT_CHECK(hxtFree(&quadToTet));
  HXT_CHECK(hxtFree(&tetToQuad));
  return HXT_STATUS_OK;
}

HXTStatus hxtFitCrossesToQuadSurfMesh(HXTMesh *quadMesh, HXTMesh *tetMesh, double *frames){
  HXTOrientation3DCleanMesh cleanMeshObj;
  buildCleanMesh(&cleanMeshObj,tetMesh);
  cleanMeshCleanSolution(&cleanMeshObj, frames, 9);
  fitCrossesToQuadSurfMesh(quadMesh, tetMesh, frames);
  //Restoring mesh and solution
  cleanMeshRestoreMesh(&cleanMeshObj);
  uint32_t nFieldsSol=9;
  cleanMeshRestoreSolution(&cleanMeshObj,frames,nFieldsSol);
  cleanMeshDestroy(&cleanMeshObj);
  return HXT_STATUS_OK;
}
