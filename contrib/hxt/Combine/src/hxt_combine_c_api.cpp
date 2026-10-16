#include "hxt_combine_c_api.h"

#include <vector>
#include "hxt_combine_cell.h"
#include "tet_mesh.h"
#include "hxt_combine_cpp_api.h"


/**
* \author Jeanne Pellerin
*/

using HXTCombine::HXTCombineCell;
using HXTCombine::HXTCombineCellArray;

struct HXTCombineCellVector {
  HXTCombineCellArray data;
};


HXTStatus HXTCombineCellVectorSize(HXTCombineCellVector *vector, HXTIndex *size)
{
  *size = vector->data.size();
  return HXT_STATUS_OK;
}

HXTStatus HXTCombineCellVectorCellVertices(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **vertices, HXTIndex* numVertices) 
{
  HXTCombineCell cell = vector->data[cellIndex];
  *numVertices = cell.nbVertices();
  *vertices = const_cast<HXTIndex*>(cell.vertexes);
  return HXT_STATUS_OK;
}

HXTStatus HXTCombineCellVectorCellInteriorTets(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **tets, HXTIndex* nbTets)
{
  HXTCombineCell cell = vector->data[cellIndex];
  *nbTets = cell.nbInteriorTets();
  *tets = const_cast<HXTIndex*>(cell.interiorTetrahedra);
  return HXT_STATUS_OK;
}

HXTStatus HXTCombineCellVectorCellBoundaryTets(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **tets, HXTIndex* nbTets)
{
  HXTCombineCell cell = vector->data[cellIndex];
  *nbTets = cell.nbBoundaryTets();
  *tets = const_cast<HXTIndex*>(cell.boundaryTetrahedra);
  return HXT_STATUS_OK;
}


HXTStatus hxtIdentifyAllHexahedra(
  const HXTMesh* mesh, double qualityThreshold, HXTCombineCellVector* hexahedra)
{
  HXTCombine::TetMeshForCombining fullMesh(mesh);
  HXTCombine::computePotentialHexes(fullMesh, qualityThreshold, hexahedra->data);
  return HXT_STATUS_OK;
}

HXTStatus hxtIdentifyAllPrisms(
  const HXTMesh* mesh, double qualityThreshold, HXTCombineCellVector* prisms)
{
  HXTCombine::TetMeshForCombining fullMesh(mesh);
  HXTCombine::computePotentialPrisms(fullMesh, qualityThreshold, prisms->data);
  return HXT_STATUS_OK;
}

HXTStatus hxtComputeCellQuality(
  const HXTMesh* mesh, const HXTCombineCellVector *vector, double** qualities)
{
  HXT_CHECK(hxtMalloc((void**)qualities, sizeof(**qualities)*vector->data.size()));
  HXTCombine::TetMeshWrapper wrapped(mesh);
  HXTCombine::computeCellQualityVector(wrapped, vector->data, *qualities);
  return HXT_STATUS_OK;
}


