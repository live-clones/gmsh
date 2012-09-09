// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_PARTITION_OPTIONS_H_
#define _MESH_PARTITION_OPTIONS_H_

#include <map>

class meshPartitionOptions
{
  public:
  // General
  int partitioner;                      // 1 - Chaco
                                        // 2 - METIS
  int num_partitions;
  int ncon;                             // Number of constraints/different weights
  int renumber;
  bool createPartitionBoundaries;
  bool createGhostCells;

  // Chaco
  int global_method;                    // 1 - Multilevel-KL
                                        // 2 - Spectral
                                        // 3 - Inertial (Disabled)
                                        // 4 - Linear
                                        // 5 - Random
                                        // 6 - Scattered
  int architecture;                     // 0   - hypercube
                                        // 1-3 - dimensional mesh parallel
  int ndims_tot;                        // Number of hypercube dimensions */
  int mesh_dims[3];                     // Number of partitions in each
                                        // dimension for a dimensional
                                        // architecture
  double *goal;                         // Not-implemented (Weights vertices in
                                        // a set)
  int local_method;                     // 1 - Kernighan-Lin
                                        // 2 - None
  int rqi_flag;                         // Eigensolver for spectral partitioner
                                        // 0 - Lanczos
                                        // 1 - Multilevel RQI/Symmlq
  int vmax;                             // Number of vertices in the coarsest
                                        // graph.
  int ndims;                            // Number of divisions at each stage
                                        // 1 - Bisection
                                        // 2 - Quadrisection
                                        // 3 - Octasection
  double eigtol;                        // Tolerance to the eigensolver
  long seed;                            // RNG seed

  // parameters
  int refine_partition;                 // Refine partitions at each level
  int internal_vertices;                // Increase internal vertices
  int refine_map;                       // Refine processor mapping
  int terminal_propogation;             // Run with terminal propogation

  // METIS
  int algorithm;
                                        // 1 - Recursive
                                        // 2 - K-way
                                        // 3 - Nodal weight
                                        // 4 - Multi-Constrained Recursive
                                        // 5 - Multi-Constrained K-way
  int edge_matching;                    // 1 - Random matching
                                        // 2 - Heavy-edge matching
                                        // 3 - Sorted heavy-edge matching
  int refine_algorithm;                 // 1 - Random boundary refinement
                                        // 2 - Greedy boundary refinement
                                        // 3 - Random boundary refinement (with
                                        //     minimization of connectivity
                                        //     along sub-domains)

  // element weights for load-balancing (currently used in METIS algorithm 3)
  int triWeight;
  int quaWeight;
  int tetWeight;
  int priWeight;
  int pyrWeight;
  int hexWeight;

  // NODAL WEIGHT
  std::vector<int> nodalWeights;
  std::map<int, std::vector<int> > vWeightMap;
  std::map<int, int > eWeightMap;
  std::vector<int> tolerance;

 public:
  meshPartitionOptions(){ setDefaults(); }
  ~meshPartitionOptions(){}
  void setAlgorithm(int algo){ algorithm = algo; }
  void setNumOfPartitions(int numPart){ num_partitions = numPart; }
  int getNumOfPartitions(){ return num_partitions; }
  void setNumConstraints(int numConst){ ncon = numConst; }
  int getNumConstraints(){ return ncon; }
  std::map<int, std::vector<int> > &getWeightMapV(){ return vWeightMap; }
  std::map<int, int > &getWeightMapE(){ return eWeightMap; }
  void setDefaults()
  {
    partitioner = 2;
    num_partitions=1;
    ncon = 0;
    renumber = 0;
    global_method = 1;
    architecture = 1;
    ndims_tot = 2;
    mesh_dims[0] = 4;
    mesh_dims[1] = 1;
    mesh_dims[2] = 1;
    goal = 0;
    local_method = 1;
    rqi_flag = 1;
    vmax = 250;
    ndims = 1;
    eigtol = 1.E-3;
    seed = 7654321L;
    refine_partition = false;
    internal_vertices = false;
    refine_map = true;
    terminal_propogation = false;
    algorithm = 1;
    edge_matching = 3;
    refine_algorithm = 3;
    createPartitionBoundaries = true;
    createGhostCells = true;
    triWeight = 1;
    quaWeight = 1;
    tetWeight = 1;
    priWeight = 1;
    pyrWeight = 1;
    hexWeight = 1;
  }
};

#endif
