#include "hxt_quadMultiBlock.h"

extern "C"
{
#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_tools.h"
#include "hxt_edge.h"
#include <stdlib.h> //qsort
#include <stdio.h> //fopen, fclose
}
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include "hxt_qmbSingularity.h"
#include "hxt_qmbCorner.h"
#include "hxt_qmbBoundary.h"
#include "hxt_qmbBoundaryLine.h"
#include "hxt_qmbSeparatrice.h"
#include "hxt_qmbSepGroup.h"
#include "hxt_qmbQuadGenerator.h"
#include "hxt_qmbMultiBlock.h"
//gmsh stuff
#include "gmsh.h"

using namespace std;

// HXTStatus hxtQuadMultiBlockTest(HXTMesh *mesh, int nbTurns, double critNorm, int flagTypePos, const char *fileName,  const char *geoFile){
// HXTStatus hxtQuadMultiBlockTest(HXTMesh *mesh, int nbTurns, double critNorm, int flagTypePos, const char *fileName,  const char *geoFile){
//   QuadGenerator qGen(mesh, nbTurns, critNorm, flagTypePos, fileName);
//   qGen.computeSeparatrices(geoFile);
//   qGen.splitTriMeshOnMBDecomp();
  
//   return HXT_STATUS_OK;
// }

// include crit norm!!!
HXTStatus hxtQuadMultiBlockGetSingInfo(HXTMesh *mesh, int tagCrossField, std::string geoFileName){
  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreate(mesh,&edges));
  double *crossfield;
  HXT_CHECK(hxtMalloc(&crossfield,2*edges->numEdges*sizeof(double)));
  std::string dataType;
  std::vector<std::size_t> tags;
  std::vector<std::vector<double>> data;
  double time;
  int numComponents;
  gmsh::view::getModelData(tagCrossField, 0, dataType, tags, data, time, numComponents);
  if (dataType == "ElementData" && tags.size() == mesh->triangles.num){
    for(uint64_t i=0; i<tags.size(); i++){
      if(data[i].size() != 3) {
	std::cout<<"data size should be 3"<<std::endl;
      }
      for(int j=0; j<3; j++){
	double theta = (data[i])[j];
	uint64_t globalEdg = edges->tri2edg[3*i+j];
	uint32_t v1=mesh->triangles.node[3*i+(j)];
	uint32_t v2=mesh->triangles.node[3*i+(j+1)%3];
	crossfield[2*globalEdg+0] = cos(4.0*theta);
	crossfield[2*globalEdg+1] = sin(4.0*theta);
      }
    }
  }else {
    std::cout<<"problem with 'theta' view, mesh contains "<< mesh->triangles.num<<" triangles but "<<tags.size()<< " tags in view "<<std::endl;
  }

  //collapsing norm for finding singularities
  double *crossfield2;
  HXT_CHECK(hxtMalloc(&crossfield2,2*edges->numEdges*sizeof(double)));
  for(uint64_t i=0; i<edges->numEdges; i++){
    double sumCos=0.0;
    double sumSin=0.0;
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;
    int nAverage=0;
    double sign=1.0;
    for(int t=0; t<2; t++){// for each triangle
      uint64_t numTri = edges->edg2tri[2*i+t];  
      if (numTri != (uint64_t)-1){
	double U[3]={0.}, V[3]={0.}, n[3]={0.};
	uint32_t vtri[3] = {mesh->triangles.node[3*numTri+0],mesh->triangles.node[3*numTri+1],mesh->triangles.node[3*numTri+2]};
	HXT_CHECK(QuadGenerator::trianglebasis(mesh,vtri,U,V,n));
	if(n[2]>0)
	  sign=1.0;
	else
	  sign=-1.0;
	for(int j=0; j<3; j++){
	  uint32_t edgJ=edges->tri2edg[3*numTri+j];
	  if(edgJ!=i){
	    double *v0J = mesh->vertices.coord +4*edges->node[2*edgJ+0];
	    double *v1J = mesh->vertices.coord +4*edges->node[2*edgJ+1];
	    double eJ[3] = {v1J[0]-v0J[0],v1J[1]-v0J[1],v1J[2]-v0J[2]};
	    double normJ = sqrt(eJ[0]*eJ[0]+eJ[1]*eJ[1]+eJ[2]*eJ[2]);
	    eJ[0] /= normJ; eJ[1] /= normJ; eJ[2] /= normJ;
	    double alpha = sign*atan2(eJ[1],eJ[0]);
	    double cosEJglob=crossfield[2*edgJ+0]*cos(4.0*alpha)-crossfield[2*edgJ+1]*sin(4.0*alpha);
	    double sinEJglob=crossfield[2*edgJ+0]*sin(4.0*alpha)+crossfield[2*edgJ+1]*cos(4*alpha);
	    sumCos+=cosEJglob;
	    sumSin+=sinEJglob;
	    nAverage++;
	  }
	}
      } 
    }
    double cosEGlob=sumCos/(double)nAverage;
    double sinEGlob=sumSin/(double)nAverage;
    double alphaEdg = sign*atan2(e[1],e[0]);
    crossfield2[2*i+0]=cosEGlob*cos(-4.0*alphaEdg)-sinEGlob*sin(-4.0*alphaEdg);
    crossfield2[2*i+1]=cosEGlob*sin(-4.0*alphaEdg)+sinEGlob*cos(-4.0*alphaEdg);
  }
  double *normSmoothed;
  HXT_CHECK(hxtMalloc(&normSmoothed,edges->numEdges*sizeof(double)));
  for(uint64_t i=0; i<edges->numEdges; i++){
    normSmoothed[i]=sqrt(crossfield2[2*i+0]*crossfield2[2*i+0]+crossfield2[2*i+1]*crossfield2[2*i+1]);
  }
  HXT_CHECK(hxtFree(&crossfield2));  
  for(uint64_t i=0; i<edges->numEdges; i++){
    crossfield[2*i+0]=crossfield[2*i+0]*normSmoothed[i];
    crossfield[2*i+1]=crossfield[2*i+1]*normSmoothed[i];
  }
  FILE* myfile = fopen("myCrosses.pos","w");
  fprintf(myfile,"View \"Direction field\"{\n");
  for(uint64_t i=0; i<edges->numEdges; i++){
    double Ue, Ve;
    Ue = crossfield[2*i+0];
    Ve = crossfield[2*i+1];
    double ne = sqrt(Ue*Ue + Ve*Ve);
    double theta = atan2(Ve,Ue)/4.0;
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;

    for(int t=0; t<2; t++){// for each triangle
      uint64_t numtri = edges->edg2tri[2*i+t];
      if (numtri != (uint64_t)-1){
        double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};
        uint32_t vtri[3] = { mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
        HXT_CHECK(QuadGenerator::trianglebasis(mesh,vtri,U,V,n));	
        double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
        for(int nb=0; nb<4; nb++){  
          theta += 2.*M_PI/4.;
          double c = cos(theta)*ne, s = sin(theta)*ne;
          fprintf(myfile,"VP(%f,%f,%f){%f,%f,%f};\n",(v0[0]+v1[0])/2.,(v0[1]+v1[1])/2.,(v0[2]+v1[2])/2.,c*e[0]+s*f[0],c*e[1]+s*f[1],c*e[2]+s*f[2]);
        }
      }// end if
    }//end for t
  }// end edges
  fprintf(myfile,"};");
  fclose(myfile);

  int nbTurns=4;
  double critNorm=0.8; //to be optional from user?
  int flagTypePos=1;
  const char *fileName="myCrosses.pos";
  QuadGenerator qGen(mesh, nbTurns, critNorm, flagTypePos, fileName);
  qGen.prepareGeoFile(geoFileName, crossfield);
  
  return HXT_STATUS_OK;
}






HXTStatus hxtQuadMultiBlockDBG(HXTMesh *mesh, int tagCrossField, HXTMesh **splitMesh){
  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreate(mesh,&edges));
  double *crossfield;
  HXT_CHECK(hxtMalloc(&crossfield,2*edges->numEdges*sizeof(double)));
  std::string dataType;
  std::vector<std::size_t> tags;
  std::vector<std::vector<double>> data;
  double time;
  int numComponents;
  gmsh::view::getModelData(tagCrossField, 0, dataType, tags, data, time, numComponents);
  if (dataType == "ElementData" && tags.size() == mesh->triangles.num){
    for(uint64_t i=0; i<tags.size(); i++){
      if(data[i].size() != 3) {
	std::cout<<"data size should be 3"<<std::endl;
	// return false;
      }
      for(int j=0; j<3; j++){
	double theta = (data[i])[j];
	uint64_t globalEdg = edges->tri2edg[3*i+j];
	uint32_t v1=mesh->triangles.node[3*i+(j)];
	uint32_t v2=mesh->triangles.node[3*i+(j+1)%3];
	crossfield[2*globalEdg+0] = cos(4.0*theta);
	crossfield[2*globalEdg+1] = sin(4.0*theta);
      }
    }
  }else {
    std::cout<<"problem with 'theta' view, mesh contains "<< mesh->triangles.num<<" triangles but "<<tags.size()<< " tags in view "<<std::endl;
    // return false;
  }

  //collapsing norm for finding singularities
  double *crossfield2;
  HXT_CHECK(hxtMalloc(&crossfield2,2*edges->numEdges*sizeof(double)));
  for(uint64_t i=0; i<edges->numEdges; i++){
    double sumCos=0.0;
    double sumSin=0.0;
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;
    int nAverage=0;
    double sign=1.0;
    for(int t=0; t<2; t++){// for each triangle
      uint64_t numTri = edges->edg2tri[2*i+t];  
      if (numTri != (uint64_t)-1){
	double U[3]={0.}, V[3]={0.}, n[3]={0.};
	uint32_t vtri[3] = {mesh->triangles.node[3*numTri+0],mesh->triangles.node[3*numTri+1],mesh->triangles.node[3*numTri+2]};
	HXT_CHECK(QuadGenerator::trianglebasis(mesh,vtri,U,V,n));
	if(n[2]>0)
	  sign=1.0;
	else
	  sign=-1.0;
	for(int j=0; j<3; j++){
	  uint32_t edgJ=edges->tri2edg[3*numTri+j];
	  if(edgJ!=i){
	    // //get global edge number
	    // uint32_t vtri[3] = {mesh->triangles.node[3*numTri+0],mesh->triangles.node[3*numTri+1],mesh->triangles.node[3*numTri+2]};
	    // int edgNumG = -1;
	    // for(int k=0; k<3; k++) // looking for global edge numbering
	    //   if( (vtri[(edgJ+0)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+0] || vtri[(edgJ+0)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+1]) &&
	    // 	  (vtri[(edgJ+1)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+0] || vtri[(edgJ+1)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+1]) )
	    // 	edgNumG = edges->tri2edg[3*numTri+k];
	    double *v0J = mesh->vertices.coord +4*edges->node[2*edgJ+0];
	    double *v1J = mesh->vertices.coord +4*edges->node[2*edgJ+1];
	    double eJ[3] = {v1J[0]-v0J[0],v1J[1]-v0J[1],v1J[2]-v0J[2]};
	    double normJ = sqrt(eJ[0]*eJ[0]+eJ[1]*eJ[1]+eJ[2]*eJ[2]);
	    eJ[0] /= normJ; eJ[1] /= normJ; eJ[2] /= normJ;
	    // double fJ[3] = {n[1]*eJ[2]-n[2]*eJ[1], n[2]*eJ[0]-n[0]*eJ[2], n[0]*eJ[1]-n[1]*eJ[0]};
	    double alpha = sign*atan2(eJ[1],eJ[0]);
	    double cosEJglob=crossfield[2*edgJ+0]*cos(4.0*alpha)-crossfield[2*edgJ+1]*sin(4.0*alpha);
	    double sinEJglob=crossfield[2*edgJ+0]*sin(4.0*alpha)+crossfield[2*edgJ+1]*cos(4*alpha);
	    sumCos+=cosEJglob;
	    sumSin+=sinEJglob;
	    nAverage++;
	  }
	}
      } 
    }
    double cosEGlob=sumCos/(double)nAverage;
    double sinEGlob=sumSin/(double)nAverage;
    double alphaEdg = sign*atan2(e[1],e[0]);
    crossfield2[2*i+0]=cosEGlob*cos(-4.0*alphaEdg)-sinEGlob*sin(-4.0*alphaEdg);
    crossfield2[2*i+1]=cosEGlob*sin(-4.0*alphaEdg)+sinEGlob*cos(-4.0*alphaEdg);
  }
  double *normSmoothed;
  HXT_CHECK(hxtMalloc(&normSmoothed,edges->numEdges*sizeof(double)));
  for(uint64_t i=0; i<edges->numEdges; i++){
    normSmoothed[i]=sqrt(crossfield2[2*i+0]*crossfield2[2*i+0]+crossfield2[2*i+1]*crossfield2[2*i+1]);
  }
  HXT_CHECK(hxtFree(&crossfield2));  
  for(uint64_t i=0; i<edges->numEdges; i++){
    crossfield[2*i+0]=crossfield[2*i+0]*normSmoothed[i];
    crossfield[2*i+1]=crossfield[2*i+1]*normSmoothed[i];
  }
  FILE* myfile = fopen("myCrossesCR.pos","w");
  fprintf(myfile,"View \"Direction field\"{\n");
  for(uint64_t i=0; i<edges->numEdges; i++){
    double Ue, Ve;
    Ue = crossfield[2*i+0];
    Ve = crossfield[2*i+1];
    double ne = sqrt(Ue*Ue + Ve*Ve);
    double theta = atan2(Ve,Ue)/4.0;
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;

    for(int t=0; t<2; t++){// for each triangle
      uint64_t numtri = edges->edg2tri[2*i+t];
      if (numtri != (uint64_t)-1){
        double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};
        uint32_t vtri[3] = { mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
        HXT_CHECK(QuadGenerator::trianglebasis(mesh,vtri,U,V,n));	
        double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
        for(int nb=0; nb<4; nb++){  
          theta += 2.*M_PI/4.;
          double c = cos(theta)*ne, s = sin(theta)*ne;
          fprintf(myfile,"VP(%f,%f,%f){%f,%f,%f};\n",(v0[0]+v1[0])/2.,(v0[1]+v1[1])/2.,(v0[2]+v1[2])/2.,c*e[0]+s*f[0],c*e[1]+s*f[1],c*e[2]+s*f[2]);
        }
      }// end if
    }//end for t
  }// end edges
  fprintf(myfile,"};");
  fclose(myfile);

  int nbTurns=4;
  double critNorm=0.8;
  int flagTypePos=1;
  const char *fileName="myCrossesCR.pos";
  QuadGenerator qGen(mesh, nbTurns, critNorm, flagTypePos, fileName);
  qGen.computeSeparatrices(crossfield);
  qGen.splitTriMeshOnMBDecomp();
  (*splitMesh)=qGen.getSplitTriMeshOnMBDecomp();
  
  // HXTMesh *tempMesh;
  // tempMesh=qGen.getSplitTriMeshOnMBDecomp();
  // //copy mesh to return it
  // // vertices
  // splitMesh->vertices.num = tempMesh->vertices.num;
  // HXT_CHECK(hxtAlignedMalloc(&(splitMesh->vertices.coord),4*(splitMesh->vertices.num)*sizeof(double)));
  // for(uint64_t i=0; i<splitMesh->vertices.num; i++){
  //   for(int t=0; t<3; t++)
  //     splitMesh->vertices.coord[4*i+t] = tempMesh->vertices.coord[4*i+t];
  //   splitMesh->vertices.coord[4*i+3] = 0.0;
  // }
  // // triangles
  // splitMesh->triangles.num = tempMesh->triangles.num;
  // HXT_CHECK(hxtAlignedMalloc(&(splitMesh->triangles.node),3*(splitMesh->triangles.num)*sizeof(uint64_t)));
  // for(uint64_t i=0; i<splitMesh->triangles.num; i++)
  //   for(int t=0; t<3; t++)
  //     splitMesh->triangles.node[3*i+t] = tempMesh->triangles.node[3*i+t];
  // // lines
  // splitMesh->lines.num = tempMesh->lines.num;
  // HXT_CHECK(hxtAlignedMalloc(&(splitMesh->lines.node),2*(splitMesh->lines.num)*sizeof(uint32_t)));
  // HXT_CHECK(hxtAlignedMalloc(&(splitMesh->lines.colors),(splitMesh->lines.num)*sizeof(uint16_t)));
  // for(uint64_t i=0; i<splitMesh->lines.num; i++){
  //   for(int t=0; t<2; t++)
  //     splitMesh->lines.node[2*i+t] = tempMesh->lines.node[2*i+t];
  //   splitMesh->lines.colors[i] = tempMesh->lines.colors[i];
  // }

  HXT_CHECK(hxtFree(&crossfield));
  return HXT_STATUS_OK;
}





HXTStatus hxtQuadMultiBlockSplitWithPrescribedSing(HXTMesh *mesh, int tagCrossField, HXTMesh **splitMesh){
  HXTEdges *edges;
  HXT_CHECK(hxtEdgesCreate(mesh,&edges));
  double *crossfield;
  HXT_CHECK(hxtMalloc(&crossfield,2*edges->numEdges*sizeof(double)));
  std::string dataType;
  std::vector<std::size_t> tags;
  std::vector<std::vector<double>> data;
  double time;
  int numComponents;
  gmsh::view::getModelData(tagCrossField, 0, dataType, tags, data, time, numComponents);
  if (dataType == "ElementData" && tags.size() == mesh->triangles.num){
    for(uint64_t i=0; i<tags.size(); i++){
      if(data[i].size() != 3) {
	std::cout<<"data size should be 3"<<std::endl;
	// return false;
      }
      for(int j=0; j<3; j++){
	double theta = (data[i])[j];
	uint64_t globalEdg = edges->tri2edg[3*i+j];
	uint32_t v1=mesh->triangles.node[3*i+(j)];
	uint32_t v2=mesh->triangles.node[3*i+(j+1)%3];
	crossfield[2*globalEdg+0] = cos(4.0*theta);
	crossfield[2*globalEdg+1] = sin(4.0*theta);
      }
    }
  }else {
    std::cout<<"problem with 'theta' view, mesh contains "<< mesh->triangles.num<<" triangles but "<<tags.size()<< " tags in view "<<std::endl;
    // return false;
  }

  //collapsing norm for finding singularities
  double *crossfield2;
  HXT_CHECK(hxtMalloc(&crossfield2,2*edges->numEdges*sizeof(double)));
  for(uint64_t i=0; i<edges->numEdges; i++){
    double sumCos=0.0;
    double sumSin=0.0;
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;
    int nAverage=0;
    double sign=1.0;
    for(int t=0; t<2; t++){// for each triangle
      uint64_t numTri = edges->edg2tri[2*i+t];  
      if (numTri != (uint64_t)-1){
	double U[3]={0.}, V[3]={0.}, n[3]={0.};
	uint32_t vtri[3] = {mesh->triangles.node[3*numTri+0],mesh->triangles.node[3*numTri+1],mesh->triangles.node[3*numTri+2]};
	HXT_CHECK(QuadGenerator::trianglebasis(mesh,vtri,U,V,n));
	if(n[2]>0)
	  sign=1.0;
	else
	  sign=-1.0;
	for(int j=0; j<3; j++){
	  uint32_t edgJ=edges->tri2edg[3*numTri+j];
	  if(edgJ!=i){
	    // //get global edge number
	    // uint32_t vtri[3] = {mesh->triangles.node[3*numTri+0],mesh->triangles.node[3*numTri+1],mesh->triangles.node[3*numTri+2]};
	    // int edgNumG = -1;
	    // for(int k=0; k<3; k++) // looking for global edge numbering
	    //   if( (vtri[(edgJ+0)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+0] || vtri[(edgJ+0)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+1]) &&
	    // 	  (vtri[(edgJ+1)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+0] || vtri[(edgJ+1)%3] == edges->node[2*edges->tri2edg[3*numTri+k]+1]) )
	    // 	edgNumG = edges->tri2edg[3*numTri+k];
	    double *v0J = mesh->vertices.coord +4*edges->node[2*edgJ+0];
	    double *v1J = mesh->vertices.coord +4*edges->node[2*edgJ+1];
	    double eJ[3] = {v1J[0]-v0J[0],v1J[1]-v0J[1],v1J[2]-v0J[2]};
	    double normJ = sqrt(eJ[0]*eJ[0]+eJ[1]*eJ[1]+eJ[2]*eJ[2]);
	    eJ[0] /= normJ; eJ[1] /= normJ; eJ[2] /= normJ;
	    // double fJ[3] = {n[1]*eJ[2]-n[2]*eJ[1], n[2]*eJ[0]-n[0]*eJ[2], n[0]*eJ[1]-n[1]*eJ[0]};
	    double alpha = sign*atan2(eJ[1],eJ[0]);
	    double cosEJglob=crossfield[2*edgJ+0]*cos(4.0*alpha)-crossfield[2*edgJ+1]*sin(4.0*alpha);
	    double sinEJglob=crossfield[2*edgJ+0]*sin(4.0*alpha)+crossfield[2*edgJ+1]*cos(4*alpha);
	    sumCos+=cosEJglob;
	    sumSin+=sinEJglob;
	    nAverage++;
	  }
	}
      } 
    }
    double cosEGlob=sumCos/(double)nAverage;
    double sinEGlob=sumSin/(double)nAverage;
    double alphaEdg = sign*atan2(e[1],e[0]);
    crossfield2[2*i+0]=cosEGlob*cos(-4.0*alphaEdg)-sinEGlob*sin(-4.0*alphaEdg);
    crossfield2[2*i+1]=cosEGlob*sin(-4.0*alphaEdg)+sinEGlob*cos(-4.0*alphaEdg);
  }
  double *normSmoothed;
  HXT_CHECK(hxtMalloc(&normSmoothed,edges->numEdges*sizeof(double)));
  for(uint64_t i=0; i<edges->numEdges; i++){
    normSmoothed[i]=sqrt(crossfield2[2*i+0]*crossfield2[2*i+0]+crossfield2[2*i+1]*crossfield2[2*i+1]);
  }
  HXT_CHECK(hxtFree(&crossfield2));  
  for(uint64_t i=0; i<edges->numEdges; i++){
    crossfield[2*i+0]=crossfield[2*i+0]*normSmoothed[i];
    crossfield[2*i+1]=crossfield[2*i+1]*normSmoothed[i];
  }
  FILE* myfile = fopen("myCrossesH.pos","w");
  fprintf(myfile,"View \"Direction field\"{\n");
  for(uint64_t i=0; i<edges->numEdges; i++){
    double Ue, Ve;
    Ue = crossfield[2*i+0];
    Ve = crossfield[2*i+1];
    double ne = sqrt(Ue*Ue + Ve*Ve);
    double theta = atan2(Ve,Ue)/4.0;
    double *v0 = mesh->vertices.coord +4*edges->node[2*i+0];
    double *v1 = mesh->vertices.coord +4*edges->node[2*i+1];
    double e[3] = {v1[0]-v0[0],v1[1]-v0[1],v1[2]-v0[2]};
    double norm = sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
    e[0] /= norm; e[1] /= norm; e[2] /= norm;

    for(int t=0; t<2; t++){// for each triangle
      uint64_t numtri = edges->edg2tri[2*i+t];
      if (numtri != (uint64_t)-1){
        double U[3] = {0.}, V[3] = {0.}, n[3]= {0.};
        uint32_t vtri[3] = { mesh->triangles.node[3*numtri+0],mesh->triangles.node[3*numtri+1],mesh->triangles.node[3*numtri+2]};
        HXT_CHECK(QuadGenerator::trianglebasis(mesh,vtri,U,V,n));	
        double f[3] = {n[1]*e[2]-n[2]*e[1], n[2]*e[0]-n[0]*e[2], n[0]*e[1]-n[1]*e[0]};
        for(int nb=0; nb<4; nb++){  
          theta += 2.*M_PI/4.;
          double c = cos(theta)*ne, s = sin(theta)*ne;
          fprintf(myfile,"VP(%f,%f,%f){%f,%f,%f};\n",(v0[0]+v1[0])/2.,(v0[1]+v1[1])/2.,(v0[2]+v1[2])/2.,c*e[0]+s*f[0],c*e[1]+s*f[1],c*e[2]+s*f[2]);
        }
      }// end if
    }//end for t
  }// end edges
  fprintf(myfile,"};");
  fclose(myfile);

  
  int nbTurns=4;
  double critNorm=0.8;
  int flagTypePos=1;
  const char *fileName="myCrossesH.pos";
  QuadGenerator qGen(mesh, nbTurns, critNorm, flagTypePos, fileName);
  qGen.computeSeparatricesOnExistingSing(crossfield);
  qGen.splitTriMeshOnMBDecomp();
  (*splitMesh)=qGen.getSplitTriMeshOnMBDecomp();

  HXT_CHECK(hxtFree(&crossfield));
  return HXT_STATUS_OK;
}
