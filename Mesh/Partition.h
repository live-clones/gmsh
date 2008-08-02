// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
#ifndef _PARTITION_H_
#define _PARTITION_H_

struct PartitionOptions;
struct BoElemGr;
class GModel;
class Graph;

typedef std::vector<BoElemGr> BoElemGrVec;


/*******************************************************************************
 *
 * Partitioning routines
 *
 ******************************************************************************/

int MakeGraph(GModel *const model, Graph &graph,
              BoElemGrVec *const boElemGrVec = 0);
int PartitionGraph(Graph &graph, PartitionOptions &options);
int PartitionMesh(GModel *const model, PartitionOptions &options);

#endif
