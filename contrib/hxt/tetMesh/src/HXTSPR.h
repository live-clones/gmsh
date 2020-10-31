// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot


#ifndef HXTSPR_H
#define HXTSPR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetOptiUtils.h"

/* /!\ Warning /!\ This version is a modified version of HXTSPR
 *
 * One must call exactinit() correctly before
 * being able to use any function defined here
 */

// defines to set/unset the main optimizations
#define SPR_SAVE_ORIENT3D



#define SPR_MAX_PTS 32

/* From the book of Cheng et al. 'Delaunay Mesh Generation'
 * A triangulation of n vertices in R^3 has at most `ntet=(n^2 − 3n − 2)/2` tetrahedra,
 * at most nedg=(n^2 − n)/2` edges (this is simply the 2-combination of n)
 * and at most `ntri=n^2 − 3n = 2*ntet+2` triangles */
#define SPR_MAX_TETS ((SPR_MAX_PTS*SPR_MAX_PTS - 3*SPR_MAX_PTS - 2)/2) //463

/* In pratices however, the number of triangles will certainly never be greater than 500
 * because the different constraints of the SPR make the upper bound impossible to be reached
 * Same argument for constrained interior triangles and edges */
#define SPR_MAX_BNDTRIANGLES 500
#define SPR_MAX_CITRIANGLES 100
#define SPR_MAX_CIEDGES 100


/* structure for the points (32 bytes)*/
typedef struct {
  double coord[3];     // the coordinates of the vertex (unchanged by hxtSPR)
  uint32_t userID;     // a user identifier for the vertex (unchanged by hxtSPR)
  uint16_t valence;    // used internally by the SPR function
  uint8_t is_interior; // used internally by the SPR function
  uint8_t is_optional; // not implemented yet (marks optional interior pts)
} SPRPoint;

/* structure for the interior, constrained edges (2 bytes)*/
typedef struct {
  uint8_t node[2];
} SPREdge;

/* structure for the boundary triangles and the constrained triangles (4 bytes)
 * the fourth node is used internally by the SPR function  */
typedef struct {
  uint8_t node[4];
} SPRTriangle;

/* a tet has the same structure as a face (4 bytes),
 * except the fourth node is more useful to you */
typedef SPRTriangle SPRTet;


/* internal structure for a single step of the SPR function */
typedef struct {
  uint8_t candidate[SPR_MAX_PTS-3]; // candidate points
  SPRTet tet;  // base face or entire tet if created
  int numCandidates;
  double quality; // quality before inserting this tet
} SPRStep;


/* This is the main structure defining your cavity.
 * You might want to allocate this heavy structure on the heap ! */
typedef struct {
  /* set max_search_nodes to limit the number of nodes in the search tree
   * (as explained in the comments above the prototype of hxtSPR() )
   * num_search_nodes will be set to the number of tree nodes visited by the SPR
   * algorithm */
  uint64_t max_search_nodes;
  uint64_t num_search_nodes;

  /* Points on boundary + interiors points (all points)
   * hxtSPR() might shuffle what you put in here */
  struct {
    SPRPoint array[SPR_MAX_PTS];
    int num;
  } points;

  /* Constrained Interior edges
   * hxtSPR() might shuffle what you put in here */
  struct {
    SPREdge array[SPR_MAX_CIEDGES];
    int num;
  } CIEdges;

  /* Constrained Interior triangles
   * hxtSPR() might shuffle what you put in here */
  struct {
    SPRTriangle array[SPR_MAX_CITRIANGLES];
    int num;
  } CITriangles;

  /* Boundary triangles
   *
   * Nodes of boundary triangles must appear in a counter-clockwise order
   * when seen from the interior of the cavity.
   * boundary triangles must form closed a closed surface.
   * Actually, there might be multiple closed surfaces but it is better to
   * tetrahedralize them separately...
   *
   * hxtSPR() might shuffle what you put in here */
  struct {
    SPRTriangle array[SPR_MAX_BNDTRIANGLES];
    int num;
  } bndTriangles;

  /* After the SPR, `tetrahedra.array` will contain the `tetrahedra.num`
   * tetrahedra of the best tetrahedralization found, or be left unchanged
   * if no tetrahedralization has a worse tet. with a quality above
   * `tetrahedra.quality`. Note that `tetrahedra.quality` must be greater
   * than or equal to zero, and it will be updated by hxtSPR to contain
   * the quality of the tetrahedralization (the quality of its worse tet.)
   *
   * The tetrahedra will be oriented such that orient3d(a, b, c, d) < 0
   * for a tet `SPRTet tet = {{a,b,c,d}};` */
  struct {
    SPRTet array[SPR_MAX_TETS];
    int num;
    double quality; // known lower bound on quality or 0
  } tetrahedra;

  // quality function
  struct {
    double (*function)(double* p0, double* p1, double* p2, double* p3,
                       void* userData);
    void* userData;
  } quality;


  /* up to this point, you should not fill the structure yourself
   * these are all internal stuffs */
  struct {
    SPRStep array[SPR_MAX_TETS];
    int num;
  } steps;

  struct {
    double qualities[SPR_MAX_PTS*
                     (SPR_MAX_PTS-1)*
                     (SPR_MAX_PTS-2)*
                     (SPR_MAX_PTS-3)
                     /24];
    uint16_t faces[SPR_MAX_PTS*SPR_MAX_PTS*SPR_MAX_PTS];
#ifdef SPR_SAVE_ORIENT3D
    uint32_t orient3d[SPR_MAX_PTS*SPR_MAX_PTS*SPR_MAX_PTS*SPR_MAX_PTS/16+1];
#endif
  } map;
} SPRCavity;


/* hxtSPR fills the cavity with its best possible tetrahedralization in the
 * sense that the quality of the worst tetrahedron is maximized.
 *
 * At its core, hxtSPR uses a branch and bound algorithm explained in the paper
 * "Optimal Tetrahedralization for Small Polyhedron: A New Local Transformation
 * Strategy for 3-D Mesh Generation and Mesh Improvement"
 * by Liu Jianfei, Sun Shuli and Wang Dachuan
 *
 * It was however heavily optimized, as explained in the paper for the
 * 28th IMR called "Reviving the Search for Optimal Tetrahedralizations"
 * by Marot Célestin, Verhetsel Kilian and Jean-François Remacle.
 *
 * Generally, the healthier the cavity, the faster hxtSPR will return.
 * By a "healthy" cavity, we mean a cavity with a lot of possible
 * tetrahedralizations and multiple high-quality ones.
 *
 * SPR will typically find a tetrahedralization very quickly if one exists,
 * However, there may not exist any tetrahedralization, or the cavity may
 * only have one very poor tetrahedralization (with lots of poor tet.)
 * that the SPR will not find quickly.
 *
 * If you only want to find high-quality tetrahedralization, or if you don't
 * want to waste time for poor quality result anyway, limit the number of nodes
 * in the search tree by setting max_search_nodes somewhere around 500
 *
 * To call hxtSPR, fill the cavity structure as described in the structure
 * declaration, and, if there is no error (return value is 0),
 * get the resulting tetrahedralization in cavity->tetrahedra
 *
 *
 */
HXTStatus hxtSPR(SPRCavity* cavity);


/* hxtSPR_opti() performs an optimization of the quality of a mesh
 * by growing a cavity around the tetrahedron `badTet`
 * and applying hxtSPR repeatedly.
 * Contrarily to hxtSPR, which is a standalone function,
 * requiring no other data-structure knowledge than SPRCavity,
 * hxtSPR_opti() requires a valid mesh, with constraints flags set
 * (see hxt_tetFlag.h), with partitions defined in data->partition,
 * (see hxt_tetPartitions.h) and corresponding hilbert distance
 * computed in the padding of each vertex
 * (see vertices.h -> HXTVertex -> padding.hilbertDist)
 *
 * However, this function requires no knowledge of how SPR works,
 * and no knowledge of the SPRCavity structure.
 *
 * It is meant to be used for mesh optimization in hxt_tetOpti.c
 *
 * Possible return status:
 *    - HXT_STATUS_OK         (on success: cavity improved)
 *    - HXT_STATUS_ERROR      (on error)
 *    - HXT_STATUS_CONFLICT   (on conflict with other partition)
 *    - HXT_STATUS_INTERNAL   (on failure: cavity not improved)
 *
 */
HXTStatus hxtSPR_opti(ThreadLocal* local,
                      uint64_t badTet);



#ifdef __cplusplus
}
#endif

#endif
