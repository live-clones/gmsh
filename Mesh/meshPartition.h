// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_PARTITION_H_
#define _MESH_PARTITION_H_

#include <vector>
#include "partitionEdge.h"
#include "GFaceCompound.h"
#include "GFace.h"

class GModel;
class GFace;
class Graph;
struct meshPartitionOptions;

/*******************************************************************************
 *
 * Partitioning routines
 *
 ******************************************************************************/

int PartitionGraph(Graph &graph, meshPartitionOptions &options);
int RenumberGraph(Graph &graph, meshPartitionOptions &options);
int PartitionMesh(GModel *const model, meshPartitionOptions &options);
int RenumberMesh(GModel *const model, meshPartitionOptions &options);
int PartitionMeshFace(std::list<GFace*> &cFaces, meshPartitionOptions &options);
int PartitionMeshElements(std::vector<MElement*> &elements, 
                          meshPartitionOptions &options);
bool PartitionZeroGenus(std::list<GFace*> &cFaces, int &nbParts);
int CreatePartitionBoundaries(GModel *model, bool createGhostCells);

void splitBoundaryEdges(GModel *model,
                        std::set<partitionEdge*, Less_partitionEdge> &newEdges);
void createPartitionFaces(GModel *model, GFaceCompound *gf, int num_parts,
                          std::vector<discreteFace*> &pFaces);

#endif
