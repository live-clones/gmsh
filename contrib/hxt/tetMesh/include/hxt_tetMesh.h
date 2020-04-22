// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETMESH_H
#define HXT_TETMESH_H

#include "hxt_mesh.h"


typedef struct {
  int defaultThreads;  /* Number of threads used for parallel work.
                         If defaultThreads<=0, uses OMP_NUM_THREADS
                         environment variable */
  int delaunayThreads; /* Overrides the maximum number of threads 
                         only for Delaunay insertion. If the domain
                         could have very ill-shaped partition, it
                         might be interesting to have less thread for
                         the Delaunay than for the rest of operations

                         - `delaunayThreads>0`: use `delaunayThreads` threads
                         - `delaunayThreads=0`: use the default nbr. of threads
                         - `delaunayThreads<0`: use OMP_NUM_PROCS */
  int improveThreads;  /* Same as above but for mesh improvements operations */
  int reproducible;    /*The output mesh will be identical with this option
                         if given
                          - the same vertices in the same order
                          - the same number of threads
                         WARNING: This option slows down the mesh generation
                         except with 1 thread */
  int verbosity;       /* Verbosity level of output messages
                         - verbosity=0: print no information
                         - verbosity=1: print some information
                         - verbosity=2: print all information */
  int stat;            /* Print timing and statistics (Boolean option) */
  int refine;          /* Refine the mesh by adding vertices in the interio
                          (Boolean option) */
  int optimize;        /* Add a mesh improvement step that will increase
                          the quality of the mesh by topological tranformations
                          above the threshold given by `qualityMin`
                          (Boolean option) */

  double qualityMin;   /* Threshold for mesh improvement */

  /* function giving the quality of an element, or NULL to use default function*/
  double (*qualityFun)(double* p0,double* p1, double* p2, double* p3,
                       void* qualityData);
  void* qualityData;   /* user pointer to give to qualityFun */

  /* function giving the desired mesh size at a position in space,
     or NULL to use default function*/
  double (*meshSizeFun)(double x, double y, double z,
                        void* meshSizeData);
  void* meshSizeData;  /* user pointer to give to meshSizeFun */

  /* function to recover missing features in a mesh */
  HXTStatus (*recoveryFun)(HXTMesh* mesh, void* recoveryData);
  void* recoveryData;  /* user pointer to give to recoveryFun */
} HXTTetMeshOptions;


/* We use a structure to give arguments, this has several advantages:
 *
 *  1. It implifies calling the function multiple time with the same arguments
 *  2. You  can use designated initializer like this:
 *
 *      HXTMesh3dOptions options = {
 *        .verbosity = 1,
 *        .stat = 1,
 *        .refine = 1,
 *        .optimize = 1,
 *        .qualityMin = 0.35,
 *        .recoveryFun = hxt_boundary_recovery
 *      }
 *
 *    Everything that is not explicitely initialized is set to zero.
 *    => You wont have to change anything if the order of arguments changes
 *    or if another option is added (because options always have 0 as sane default).
 *  3. With compound litteral, you can give argument directly in the function, like this:
 *
 *     hxtTetMesh3d(mesh, &(HXTMesh3dOptions) {.refine=1,
 *                                             .optimize=1,
 *                                             .stat=1,
 *                                             .qualityMin=1,
 *                                             .bndRecovery=hxt_boundary_recovery });
 *
 *     This is even shorter than without using a structure.
 */
HXTStatus hxtTetMesh(HXTMesh* mesh,
                     HXTTetMeshOptions* options);

#endif
