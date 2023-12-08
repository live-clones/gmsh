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
  int defaultThreads;  /* Default number of threads used for parallel work.
                          If defaultThreads<=0, uses OMP_NUM_THREADS
                          environment variable */
  int delaunayThreads; /* Overrides the maximum number of threads 
                          only for Delaunay insertion. If the domain
                          could have very ill-shaped partition, it
                          might be interesting to have less thread for
                          the Delaunay than for the rest of operations
                           - `delaunayThreads>0`: use `delaunayThreads` threads
                           - `delaunayThreads=0`: use the default nbr. of thrds
                           - `delaunayThreads<0`: use OMP_NUM_PROCS */
  int improveThreads;  /* Same as above but for mesh improvements operations */
  int reproducible;    /* The output mesh will be identical with this option
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
  int refine;          /* Refine the mesh by adding vertices in the interior
                          (Boolean option) */
  int optimize;        /* Add a mesh improvement step that will increase
                          the quality of the mesh by topological transformations
                          above the threshold given by `qualityMin`
                          (Boolean option) */
  double toleranceInitialDelaunay; /* A parameter given to tetgen that is a tolerance 
				      for deciding if a distance is actually 0 */
  
  struct {    
    /* function giving the quality of an element, or NULL for Gamma: v */
    double (*callback)(double* p0, double* p1, double* p2, double* p3, void* userData);
    void* userData; /* user pointer given to callback */
    double min;  /* Threshold for mesh improvement (Hxt tries to improve all tet
                    with a quality below quality.min */
  } quality;


  struct {
    /* function giving the desired mesh size at a position in space
      or NULL for interpolation: v */
    HXTStatus (*callback)(double* coord, uint32_t* volume, size_t n, void* userData);
    void* userData; /* user pointer given to callback */

    /* if we want to insert a point p0 with size s0, and there is a point p1
       with size s1 at a distance d, we check if
       `d > fmax(nodalSize.min, fmin(nodalSize.min, 0.5*(s0+s1))) * scaling`
       if it is not the case, the point is filtered out
    */
    double min;     /* default value: 0.0                                     */
    double max;     /* default value: DBL_MAX (converted to DBL_MAX if <=0.0) */
    double factor;  /* default value: 1.0     (converted to 1.0 if <=0.0)     */
  } nodalSizes;
} HXTTetMeshOptions;


/** Function: hxtTetMesh
 *  ====================
 * 
 * Given a surface mesh that bounds some volumes, this function
 *  - computes a tetrahedralization of the volumes
 *  - optionally refines the tetrahedralization by adding new points, according
 *    to a mesh sizing function
 *  - optimize the quality of tetrahedra according to a quality function
 *
 * The input/output mesh is described in APPENDIX A.
 * The input option structure is described at the `HXTTetMeshOptions` structure
 * definition.
 * The return status is described in core/inc/hxt_message.h
 * A note on the use of structures as function argument in C99 is described in
 * APPENDIX B.
 * 
 * How to cite:
 *     Marot, C, Pellerin, J, Remacle, J‐F. One machine, one minute, three
 *     billion tetrahedra. Int J Numer Methods Eng. 2019; 117: 967– 990.
 *     https://doi.org/10.1002/nme.5987
 *
 * @brief computes a 3D tetrahedral mesh from a 2D triangle mesh
 * @param[in, out] mesh is both used for input 2D mesh and output 3D mesh
 * @param[in] options contains all the possible parameters of hxtTetMesh
 * @return HXT_STATUS_OK if the function created a correct 3D mesh
 */
HXTStatus hxtTetMesh(HXTMesh* mesh,
                     HXTTetMeshOptions* options);


/* APPENDIX A: mesh
 * ================
 *
 * The `HXTMesh` mesh structure is used both as input 2D mesh and as output 3D
 * mesh. It must be filled as follow for hxtTetMesh to work
 * correctly.
 *
 * NOTE: any array of size 0 can be a NULL pointer
 * SPECIAL CHARACTERS AT START OF LINE: ! # @
 *         !x <=> `x` will not be used (neither read from nor written to)
 *         @x <=> `x` should be set to 0 or NULL as input, but will contain
 *                further information when the function returns
 * -----------------------------------------------------------------------------
 * mesh->vertices
 *---------------
 * mesh->vertices.num:     nb. of vertices
 * mesh->vertices.size:    capacity, in vertices, of the following array
 * mesh->vertices.coord[]: allocated with hxtAlignedMalloc(), 4 coords per point
 *                         4th coordinate is the local mesh size or 0 if the
 *                         mesh size at this point is to be interpolated. The
 *                         first `mesh->vertices.num` vertices will not be
 *                         modified by hxtTetMesh(), except for their 4th
 *                         coordinate which is used internally by hxtTetMesh().
 *                         New vertices might be added at the end of the array
 *                         by hxtTetMesh(), therefore `mesh->vertices.coord[]`
 *                         might be reallocated to another memory address.
 *
 * mesh->tetrahedra
 *---------------
 * @mesh->tetrahedra.num:     nbr. of tetrahedra
 * @mesh->tetrahedra.size:    capacity, in tetrahedra, of the following array
 * @mesh->tetrahedra.node[]:  allocated with hxtAlignedMalloc(), 4 nodes per tet
 * @mesh->tetrahedra.neigh[]: allocated with hxtAlignedMalloc() with the same
 *                            capacity as tetrahedra.node[], contains adjacency
 *                            information. More specifically:
 *                            `mesh->tetrahedra.neigh[4*t0 + i] = 4*t1 + j`
 *                            means that the facet opposite to the ith node of
 *                            tet t0 is adjacent to the the jth node of tet t1.
 *                            Therefore, we must also have:
 *                            `mesh->tetrahedra.neigh[4*t1 + j] = 4*t0 + i`
 * @mesh->tetrahedra.color:   allocated with hxtAlignedMalloc() with the same
 *                            capacity (counted in number of tet.) as
 *                            tetrahedra.node[], 1 color per tet.
 *                            The color is the ID of the volumes that contains
 *                            the tet.
 * @mesh->tetrahedra.flag:    allocated with hxtAlignedMalloc() with the same
 *                            capacity (counted in number of tet.) as
 *                            tetrahedra.node[], 1 flag per tet., see
 *                            *hxt_tetFlag.h* for more details.
 *
 * mesh->triangles
 *---------------
 * mesh->triangles.num:     nbr. of triangles
 * mesh->triangles.size:    capacity, in triangles, of the following array
 * mesh->triangles.node[]:  allocated with hxtAlignedMalloc(), 3 nodes per tri.
 * mesh->triangles.color[]: either NULL or allocated with hxtAlignedMalloc()
 *                           with same capacity (counted in number of triangles)
 *                           as triangles.node[], 1 color per triangle if !NULL
 *                           
 * mesh->lines
 *---------------
 * mesh->lines.num:    nbr. of embedded edges
 * mesh->lines.size:   capacity, in edges, of the following array
 * mesh->lines.node[]: allocated with hxtAlignedMalloc(), 2 nodes per edge,
 *                      only edges that are not on in triangles are needed
 * !mesh->lines.color[]
 *
 * mesh->points
 *---------------
 * mesh->points.num:  nbr. of embedded points
 * mesh->points.size: capacity, in points, of the following array
 * mesh->points.node: allocated with hxtAlignedMalloc(), 1 node per point,
 *                     only pts that are not in triangles or lines are needed
 * !mesh->points.color[]
 *
 * mesh->brep
 *---------------
 * mesh->brep.numVolumes:             the number of volumes to refine or 0.
 *                                    If mesh->brep.numVolumes == 0, HXT refines
 *                                    all volumes and colors them as it wants.
 *                                    In that case, it will also fill the
 *                                    mesh->brep structure accordingly.
 *                                    If mesh->brep.numVolumes != 0, the
 *                                    mesh->brep structure is not modified.
 * mesh->brep.numSurfacesPerVolume[]: allocated with hxtALignedMalloc(), the 
 *                                    nbr. of bounding surfaces for each
 *                                    aforementioned volume
 * mesh->brep.surfacesPerVolume[];    allocated with hxtALignedMalloc(), the
 *                                    colors of each aforementioned bounding
 *                                    surface, for each surface and each volume
 * !mesh->brep.numSurfaces
 * !mesh->brep.numCurvesPerSurface
 * !mesh->brep.curvesPerSurface
 * !mesh->brep.numCurves
 * !mesh->brep.endPointsOfCurves
 * !mesh->brep.numPoints
 * !mesh->brep.points
 */


/* APPENDIX B: using structures as function argument in C99
 * ========================================================
 *
 * We use a single `HXTTetMeshOptions` structure for options, instead of multiple.
 * function arguments. This has several advantages:
 *
 * 1. It simplifies calling the function multiple time with the same arguments
 * 2. You  can use designated initializer like this:
 *    ```
 *    HXTMesh3dOptions options = {
 *      .verbosity = 1,
 *      .stat = 1,
 *      .refine = 1,
 *      .optimize = 1,
 *      .quality.min = 0.35,
 *    }
 *    ```
 *    Everything that is not explicitly initialized is set to zero.
 *    => You wont have to change anything if the order of arguments changes or if
 *    another option is added (because our options always have 0 as sane default).
 * 3. With compound literals, you can give argument directly in the function, like this:
 *    ```
 *    hxtTetMesh3d(mesh, &(HXTMesh3dOptions) {.refine=1,
 *                                            .optimize=1,
 *                                            .stat=1,
 *                                            .quality.min=0.35 });
 *    ```
 *    This is even shorter than without using a structure.
 */
#endif
