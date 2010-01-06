// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_PARTITION_OPTIONS_H_
#define _MESH_PARTITION_OPTIONS_H_

struct meshPartitionOptions
{

//--General
  int partitioner;                      // 1 - Chaco
                                        // 2 - METIS
  int num_partitions;

  int renumber;

  bool createPartitionBoundaries;

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
  int edge_matching;                    // 1 - Random matching
                                        // 2 - Heavy-edge matching
                                        // 3 - Sorted heavy-edge matching
  int refine_algorithm;                 // 1 - Random boundary refinement
                                        // 2 - Greedy boundary refinement
                                        // 3 - Random boundary refinement (with
                                        //     minimization of connectivity
                                        //     along sub-domains)

//--NODAL WEIGHT
  std::vector<int> nodalWeights;

//--Constructor

  meshPartitionOptions()
     :
     goal(0)
  { }

//--Default values

  void setDefaults()
  {
    partitioner = 2;
    num_partitions = 1;
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
  }

};

#endif
