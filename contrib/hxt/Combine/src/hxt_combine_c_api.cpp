#include "hxt_combine_c_api.h"

#include <vector>
#include "hxt_combine_cell.h"
#include "tet_mesh.h"
#include "hxt_combine_cpp_api.h"


/**
* \author Jeanne Pellerin
*/

using HXTCombine::HXTCombineCell;

struct HXTCombineCellVector {
  std::vector<HXTCombineCell> data;
};


HXTStatus HXTCombineCellVectorSize(HXTCombineCellVector *vector, HXTIndex *size)
{
  *size = vector->data.size();
  return HXT_STATUS_OK;
}

HXTStatus HXTCombineCellVectorCellVertices(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **vertices, HXTIndex* numVertices) 
{
  HXTCombineCell& cell = vector->data[cellIndex];
  *numVertices = cell.nbVertices();
  *vertices = &cell.vertexes[0];
  return HXT_STATUS_OK;
}

HXTStatus HXTCombineCellVectorCellInteriorTets(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **tets, HXTIndex* nbTets)
{
  HXTCombineCell& cell = vector->data[cellIndex];
  *nbTets = cell.nbInteriorTets();
  *tets = &cell.interiorTetrahedra[0];
  return HXT_STATUS_OK;
}

HXTStatus HXTCombineCellVectorCellBoundaryTets(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **tets, HXTIndex* nbTets)
{
  HXTCombineCell& cell = vector->data[cellIndex];
  *nbTets = cell.nbBoundaryTets();
  *tets = &cell.boundaryTetrahedra[0];
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


