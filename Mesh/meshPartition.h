// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PARTITION_H_
#define _PARTITION_H_

#include <vector>
#include "partitionEdge.h"
#include "GFaceCompound.h"
#include "GFace.h"

struct meshPartitionOptions;
struct BoElemGr;
class GModel;
class GFace;
class Graph;

typedef std::vector<BoElemGr> BoElemGrVec;

/*******************************************************************************
 *
 * Partitioning routines
 *
 ******************************************************************************/

int MakeGraph(GModel *const model, Graph &graph,
              BoElemGrVec *const boElemGrVec = 0);
int PartitionGraph(Graph &graph, meshPartitionOptions &options);
int PartitionMesh(GModel *const model, meshPartitionOptions &options);
int PartitionMeshFace(std::list<GFace*> &cFaces, meshPartitionOptions &options);
int CreatePartitionBoundaries (GModel *model);
void splitBoundaryEdges(GModel *model,  std::set<partitionEdge*, Less_partitionEdge> &newEdges);
void createPartitionFaces(GModel *model, GFaceCompound * gf, int num_parts, 
			  std::vector<discreteFace*> &pFaces);

#endif
