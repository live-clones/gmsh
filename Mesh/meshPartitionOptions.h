// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
#include <map>
#include "GModel.h"
#include "meshPartition.h"
#include "fullMatrix.h" 
#ifndef _MESH_PARTITION_OPTIONS_H_
#define _MESH_PARTITION_OPTIONS_H_

class meshPartitionOptions
{
  private:

  public:

//--General

    int partitioner;                      // 1 - Chaco
                                          // 2 - METIS
    int num_partitions;
     
    int ncon;                             // Number of constraints/different weights

    int renumber;

    bool createPartitionBoundaries;
    bool createGhostCells;

//--Chaco

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
  
  //--METIS
  
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
    int partitionByExtrusion;            // if true, all extruded elements belong
                                         // to the same partition as the source element
  
    // element weights for load-balancing (currently used in METIS algorithm 3) 
    
    int triWeight;  
    int quaWeight;
    int tetWeight;
    int priWeight;
    int pyrWeight;
    int hexWeight;
  
  //--NODAL WEIGHT
    std::vector<int> nodalWeights;

    std::map<int, std::vector<int> > weightMap;
  
  
  public:
  
  //--Constructor

    meshPartitionOptions();

  //--Default values

    void setDefaults();
    void setAlgorithm(int algo);
    void setNumOfPartitions(int numPart){num_partitions=numPart;};
    int getNumOfPartitions(){return num_partitions;};
    void setNumConstraints(int numConst){ncon=numConst;};
    int getNumConstraints(){return ncon;};
    void partition(GModel *model);
    std::map<int,  std::vector<int> >& getWeightMap(){return weightMap;};
    static void registerBindings(binding *b);
};

#endif
