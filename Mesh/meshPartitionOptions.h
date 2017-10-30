// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_PARTITION_OPTIONS_H_
#define _MESH_PARTITION_OPTIONS_H_

struct meshPartitionOptions
{
  public:
  // General
  std::string outputDir;
  unsigned short num_partitions;
  bool createPartitionBoundaries;
  bool createGhostCells;
  bool writePartitionMeshes;
  bool writeTopologyFile;

  // METIS
  int algorithm;
                                        // 1 - Recursive
                                        // 2 - K-way
  int edge_matching;                    // 1 - Random matching
                                        // 2 - Sorted heavy-edge matching
  int refine_algorithm;                 // 1 - FM-based cut refinement
                                        // 2 - Greedy-based cut and volume refinement
                                        // 3 - Two-sided node FM refinement
                                        // 4 - One-sided node FM refinement

  // element weights for load-balancing (currently used in METIS algorithm 3)
  int triWeight;
  int quaWeight;
  int tetWeight;
  int hexWeight;
  int priWeight;
  int pyrWeight;
  int trihWeight;

  void setDefaults()
  {
    num_partitions = 2;
    createPartitionBoundaries = true;
    createGhostCells = false;
    writePartitionMeshes = true;
    writeTopologyFile = true;
    algorithm = 2;
    edge_matching = 2;
    refine_algorithm = 2;
    
    triWeight = 1;
    quaWeight = 1;
    tetWeight = 1;
    hexWeight = 1;
    priWeight = 1;
    pyrWeight = 1;
    trihWeight = 0;
  }
};

#endif
