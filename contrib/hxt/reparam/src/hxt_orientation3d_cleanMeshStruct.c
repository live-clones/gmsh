#include <stdint.h>
#include "hxt_mesh.h"
#include "hxt_tools.h"

typedef struct HXTOrientation3DCleanMeshStruct HXTOrientation3DCleanMesh;

struct HXTOrientation3DCleanMeshStruct {
  HXTMesh *mesh;
  uint8_t isMeshWithAloneVertices;
  uint32_t nNodes;
  //Vertices save
  uint32_t verticesNumSave;
  uint32_t verticesSizeSave;
  double *verticesCoordSave;
  //line save
  uint32_t lineSizeSave;
  uint32_t *lineNodeSave;
  //triangle save
  uint32_t triangleSizeSave;
  uint32_t *triangleNodeSave;
  //tetrahedra save
  uint32_t tetrahedraSizeSave;
  uint32_t *tetrahedraNodeSave;
  //correspondance arrays
  uint32_t *oldToNewNodes;
  uint32_t *newToOldNodes;
};

HXTStatus buildCleanMesh(HXTOrientation3DCleanMesh *cleanMeshObj, HXTMesh *mesh){
  cleanMeshObj->mesh=mesh;
  cleanMeshObj->verticesCoordSave=NULL;
  cleanMeshObj->lineNodeSave=NULL;
  cleanMeshObj->triangleNodeSave=NULL;
  cleanMeshObj->tetrahedraNodeSave=NULL;
  cleanMeshObj->oldToNewNodes=NULL;
  cleanMeshObj->newToOldNodes=NULL;
  uint32_t *useNode;
  HXT_CHECK(hxtMalloc(&useNode, sizeof(uint32_t)*mesh->vertices.num));
  for(uint32_t iN=0;iN<mesh->vertices.num;iN++){
    useNode[iN]=0;
  }
  for(uint32_t iL=0;iL<mesh->lines.num;iL++)
    for(uint32_t k=0;k<2;k++)
      useNode[mesh->lines.node[2*iL+k]]+=1;
  for(uint32_t iT=0;iT<mesh->triangles.num;iT++)
    for(uint32_t k=0;k<3;k++)
      useNode[mesh->triangles.node[3*iT+k]]+=1;
  for(uint32_t iT=0;iT<mesh->tetrahedra.num;iT++)
    for(uint32_t k=0;k<4;k++)
      useNode[mesh->tetrahedra.node[4*iT+k]]+=1;
  cleanMeshObj->isMeshWithAloneVertices=0;
  cleanMeshObj->nNodes=0;
  for(uint32_t iN=0;iN<mesh->vertices.num;iN++){
    if(useNode[iN]>0){
      cleanMeshObj->nNodes++;
    }
  }
  printf("nCleaned nodes : %i\n",cleanMeshObj->nNodes);
  printf("nNodes in mesh : %i\n",mesh->vertices.num);
  if(cleanMeshObj->nNodes<mesh->vertices.num)
    cleanMeshObj->isMeshWithAloneVertices=1;
  if(!(cleanMeshObj->isMeshWithAloneVertices)){
    hxtFree(&useNode);
    return HXT_STATUS_OK; // No alone vertices. Return
  }
  HXT_CHECK(hxtMalloc(&(cleanMeshObj->oldToNewNodes), sizeof(uint32_t)*mesh->vertices.num));
  HXT_CHECK(hxtMalloc(&(cleanMeshObj->newToOldNodes), sizeof(uint32_t)*cleanMeshObj->nNodes));
  uint32_t currentInd=0;
  for(uint32_t iN=0;iN<mesh->vertices.num;iN++){
    if(useNode[iN]>0){
      cleanMeshObj->oldToNewNodes[iN]=currentInd;
      cleanMeshObj->newToOldNodes[currentInd]=iN;
      currentInd++;
    }
  }
  hxtFree(&useNode);
  //vertices coord with new numerotation
  double *newNodesCoord;
  HXT_CHECK(hxtMalloc(&newNodesCoord, sizeof(double)*4*cleanMeshObj->nNodes));
  for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++){
    for(uint32_t k=0;k<4;k++)
      newNodesCoord[4*iN+k]=mesh->vertices.coord[4*cleanMeshObj->newToOldNodes[iN]+k];
  }
  //lines with new numerotation
  uint32_t *newLinesNode;
  HXT_CHECK(hxtMalloc(&newLinesNode, sizeof(uint32_t)*2*mesh->lines.num));
  for(uint32_t iL=0;iL<mesh->lines.num;iL++){
    for(uint32_t k=0;k<2;k++)
      newLinesNode[2*iL+k]=cleanMeshObj->oldToNewNodes[mesh->lines.node[2*iL+k]];
  }
  //triangles with new numerotation
  uint32_t *newTriangleNode;
  HXT_CHECK(hxtMalloc(&newTriangleNode, sizeof(uint32_t)*3*mesh->triangles.num));
  for(uint32_t iT=0;iT<mesh->triangles.num;iT++){
    for(uint32_t k=0;k<3;k++)
      newTriangleNode[3*iT+k]=cleanMeshObj->oldToNewNodes[mesh->triangles.node[3*iT+k]];
  }
  //tetrahedra with new numerotation
  uint32_t *newTetrahedraNode;
  HXT_CHECK(hxtMalloc(&newTetrahedraNode, sizeof(uint32_t)*4*mesh->tetrahedra.num));
  for(uint32_t iT=0;iT<mesh->tetrahedra.num;iT++){
    for(uint32_t k=0;k<4;k++)
      newTetrahedraNode[4*iT+k]=cleanMeshObj->oldToNewNodes[mesh->tetrahedra.node[4*iT+k]];
  }
  //saving current structures
  cleanMeshObj->verticesNumSave=mesh->vertices.num;
  cleanMeshObj->verticesSizeSave=mesh->vertices.size;
  cleanMeshObj->verticesCoordSave=mesh->vertices.coord;
  cleanMeshObj->lineSizeSave=mesh->lines.size;
  cleanMeshObj->lineNodeSave=mesh->lines.node;
  cleanMeshObj->triangleSizeSave=mesh->triangles.size;
  cleanMeshObj->triangleNodeSave=mesh->triangles.node;
  cleanMeshObj->tetrahedraSizeSave=mesh->tetrahedra.size;
  cleanMeshObj->tetrahedraNodeSave=mesh->tetrahedra.node;
  //new numerotation in mesh
  mesh->vertices.num=cleanMeshObj->nNodes;
  mesh->vertices.size=cleanMeshObj->nNodes;
  mesh->vertices.coord=newNodesCoord;
  mesh->lines.size=mesh->lines.num;
  mesh->lines.node=newLinesNode;
  mesh->triangles.size=mesh->triangles.num;
  mesh->triangles.node=newTriangleNode;
  mesh->tetrahedra.size=mesh->tetrahedra.num;
  mesh->tetrahedra.node=newTetrahedraNode;

  return HXT_STATUS_OK;
}

HXTStatus cleanMeshRestoreMesh(HXTOrientation3DCleanMesh *cleanMeshObj){
  HXTMesh *mesh = cleanMeshObj->mesh;
  if(!(cleanMeshObj->isMeshWithAloneVertices))
    return HXT_STATUS_OK;
  //restoring saved structures
  if(cleanMeshObj->verticesCoordSave){
    mesh->vertices.num=cleanMeshObj->verticesNumSave;
    mesh->vertices.size=cleanMeshObj->verticesSizeSave;
    hxtFree(&(mesh->vertices.coord));
    mesh->vertices.coord=cleanMeshObj->verticesCoordSave;
  }
  if(cleanMeshObj->lineNodeSave){
    mesh->lines.size=cleanMeshObj->lineSizeSave;
    hxtFree(&(mesh->lines.node));
    mesh->lines.node=cleanMeshObj->lineNodeSave;
  }
  if(cleanMeshObj->triangleNodeSave){
    mesh->triangles.size=cleanMeshObj->triangleSizeSave;
    hxtFree(&(mesh->triangles.node));
    mesh->triangles.node=cleanMeshObj->triangleNodeSave;
  }
  if(cleanMeshObj->tetrahedraNodeSave){
    mesh->tetrahedra.size=cleanMeshObj->tetrahedraSizeSave;
    hxtFree(&(mesh->tetrahedra.node));
    mesh->tetrahedra.node=cleanMeshObj->tetrahedraNodeSave;
  }
  return HXT_STATUS_OK;
}

HXTStatus cleanMeshRestoreSolution(HXTOrientation3DCleanMesh *cleanMeshObj, double *solution, uint32_t nFields){
  if(!(cleanMeshObj->isMeshWithAloneVertices))
    return HXT_STATUS_OK;
  double *restoredSolution;
  HXT_CHECK(hxtMalloc(&restoredSolution, sizeof(double)*nFields*cleanMeshObj->verticesNumSave));
  for(uint32_t iN=0;iN<cleanMeshObj->verticesNumSave;iN++)
    for(uint32_t k=0;k<nFields;k++)
      restoredSolution[nFields*iN+k]=0.0;
  for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++){
    for(uint32_t k=0;k<nFields;k++)
      restoredSolution[nFields*cleanMeshObj->newToOldNodes[iN]+k]=solution[nFields*iN+k];
  }
  for(uint32_t iN=0;iN<cleanMeshObj->verticesNumSave;iN++)
    for(uint32_t k=0;k<nFields;k++)
      solution[nFields*iN+k]=restoredSolution[nFields*iN+k];
  hxtFree(&restoredSolution);
  return HXT_STATUS_OK;
}

HXTStatus cleanMeshCleanSolution(HXTOrientation3DCleanMesh *cleanMeshObj, double *solution, uint32_t nFields){
  if(!(cleanMeshObj->isMeshWithAloneVertices))
    return HXT_STATUS_OK;
  double *cleanedSolution;
  HXT_CHECK(hxtMalloc(&cleanedSolution, sizeof(double)*nFields*cleanMeshObj->nNodes));
  for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++)
    for(uint32_t k=0;k<nFields;k++)
      cleanedSolution[nFields*iN+k]=0.0;
  for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++){
    for(uint32_t k=0;k<nFields;k++)
      cleanedSolution[nFields*iN+k]=solution[nFields*cleanMeshObj->newToOldNodes[iN]+k];
  }
  for(uint32_t iN=0;iN<cleanMeshObj->nNodes;iN++)
    for(uint32_t k=0;k<nFields;k++)
      solution[nFields*iN+k]=cleanedSolution[nFields*iN+k];
  hxtFree(&cleanedSolution);
  return HXT_STATUS_OK;
}

HXTStatus cleanMeshDestroy(HXTOrientation3DCleanMesh *cleanMeshObj){
  if(cleanMeshObj->oldToNewNodes)
    hxtFree(&(cleanMeshObj->oldToNewNodes));
  if(cleanMeshObj->newToOldNodes)
    hxtFree(&(cleanMeshObj->newToOldNodes));
  return HXT_STATUS_OK;
}
