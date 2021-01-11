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
                         if the machine and compiler are identical
                         and if given
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

  struct {    
    /* function giving the quality of an element, or NULL to use default function*/
    double (*callback)(double* p0, double* p1, double* p2, double* p3, void* userData);

    void* userData; /* user pointer given to callback */

    double min;  /* Threshold for mesh improvement (Hxt tries to improve all tet
                    with a quality below quality.min */
  } quality;


  struct {
    /* function giving the desired mesh size at a position in space,
       or NULL to use default function*/
    HXTStatus (*callback)(double* coord, uint32_t* volume, size_t n, void* userData);

    void* userData; /* user pointer given to callback */

    /* if we want to insert a point p0 with size s0, and there is a point p1
       with size s1 at a distance d, we check if

       d > fmax(nodalSize.min, fmin(nodalSize.min, 0.5*(s0+s1))) * scaling

      if it is not the case, the point is filtered out
       */
    double min;     /* default value: 0.0                                     */
    double max;     /* default value: DBL_MAX (converted to DBL_MAX if <=0.0) */
    double factor;  /* default value: 1.0     (converted to 1.0 if <=0.0)     */
  } nodalSizes;
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
 *        .quality.min = 0.35,
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
 *                                             .quality.min=0.35 });
 *
 *     This is even shorter than without using a structure.
 */
HXTStatus hxtTetMesh(HXTMesh* mesh,
                     HXTTetMeshOptions* options);

#endif
