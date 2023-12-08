#ifndef HXT_COMBINE_C_API_
#define HXT_COMBINE_C_API_


#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_message.h"
#include "hxt_mesh.h"

/**
* \file hxt_combine_c_api.h C interface of the Combine module
* \author Jeanne Pellerin
*/

/** 
* Opaque structure storing an array of HXTCombineCells
*/
struct HXTCombineCellVector;
typedef HXTIndex *HXTGraph;


HXTStatus HXTCombineCellVectorSize(HXTCombineCellVector *vector, HXTIndex *size);

HXTStatus HXTCombineCellVectorCellVertices(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **vertices, HXTIndex* numVertices);

HXTStatus HXTCombineCellVectorCellInteriorTets(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **tets, HXTIndex* nbTets);

HXTStatus HXTCombineCellVectorCellBoundaryTets(
  HXTCombineCellVector *vector, HXTIndex cellIndex, HXTIndex **tets, HXTIndex* nbTets);

/**
* \defgroup Combine Combination of tetrahedra into hexahedra and prisms
*
* Algorithms to combine tetrahedra in hexahedra and prisms described in the article :
* Pellerin J, Johnen A, Remacle J-F. 
* Identifying combinations of tetrahedra into hexahedra: a vertex based strategy. Procedia Engineering. 2017;203:2–13.
* Proceedings of the 26th International Meshing Roundtable, Barcelona, Spain  [arXiv:1705.02451]
*/

/**
* \addtogroup Combine
* @{
*/

/**
* Identifies all possible combinations of tetrahedra into hexahedra in a given mesh
* that are valid and which quality is above the given theshold.
* 
* The memory for hexahedra is allocated by the function.
* Ownership is transfered to the client.
*/
HXTStatus hxtIdentifyAllHexahedra(
  const HXTMesh* mesh, double qualityThreshold, HXTCombineCellVector* hexahedra);

HXTStatus hxtIdentifyAllPrisms(
  const HXTMesh* mesh, double qualityThreshold, HXTCombineCellVector* prisms);

HXTStatus hxtComputeCellQuality(
  const HXTMesh* mesh, const HXTCombineCellVector *vector, double** qualities);



#ifdef __cplusplus
}
#endif

/**
* @}
*/

#endif
