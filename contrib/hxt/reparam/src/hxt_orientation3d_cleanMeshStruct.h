#ifndef HXT_ORIENTATION3D_CLEANMESHSTRUCT_H
#define HXT_ORIENTATION3D_CLEANMESHSTRUCT_H

#include <stdint.h>
#include "hxt_mesh.h"

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

HXTStatus buildCleanMesh(HXTOrientation3DCleanMesh *cleanMeshObj, HXTMesh *mesh);
HXTStatus cleanMeshRestoreMesh(HXTOrientation3DCleanMesh *cleanMeshObj);
HXTStatus cleanMeshRestoreSolution(HXTOrientation3DCleanMesh *cleanMeshObj, double *solution, uint32_t nFields);
HXTStatus cleanMeshCleanSolution(HXTOrientation3DCleanMesh *cleanMeshObj, double *solution, uint32_t nFields);
HXTStatus cleanMeshDestroy(HXTOrientation3DCleanMesh *cleanMeshObj);

#endif
