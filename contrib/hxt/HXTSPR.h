/*  This file is part of HXTSPR.                                            *
                                                                            *
    HXTSPR is free software: you can redistribute it and/or modify          *
    it under the terms of the GNU General Public License as published by    *
    the Free Software Foundation, either version 3 of the License, or       *
    (at your option) any later version.                                     *
                                                                            *
    HXTSPR is distributed in the hope that it will be useful,               *
    but WITHOUT ANY WARRANTY; without even the implied warranty of          *
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
    GNU General Public License for more details.                            *
                                                                            *
    You should have received a copy of the GNU General Public License       *
    along with HXTSPR.  If not, see <http://www.gnu.org/licenses/>.         *
                                                                            *
    See the COPYING file for the GNU General Public License .               *
                                                                            *
Author: Célestin Marot (celestin.marot@uclouvain.be)                        */


#ifndef _HXTSPR_
#define _HXTSPR_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetSync.h"
#include "hxt_tetPartition.h"
#include "hxt_tetQuality.h"
#include "hxt_tetOptiDate.h"
#include "hxt_bbox.h"


/* /!\ Warning /!\ This version is a modified version of HXTSPR
 *
 * One must call exactinit() correctly before
 * being able to use any function defined here
 */

// defines to set/unset the main optimizations
#define SPR_SAVE_ORIENT3D

#define SPR_MAX_PTS 32
#define SPR_MAX_EDGES ((SPR_MAX_PTS*SPR_MAX_PTS - SPR_MAX_PTS)/2) //496
#define SPR_MAX_TETS ((SPR_MAX_PTS*SPR_MAX_PTS - 3*SPR_MAX_PTS - 2)/2) //463

/* The cavity must be formed from a breadth first search,
 * meaning the original triangulation of the cavity
 * is connected through unconstrained triangles.
 * If we don't add any constrained face, it means that all
 * triangulations of the cavity will also be connected.
 * through unconstrained triangles.
 * A connected set of tetrahedra has at most 2*tet+2
 * boundary/constrained triangles (that's a tube of tet.)
 *
 * !!You can only add one additional constrained
 * triangle to recover!!, that's why there is at most
 * 2*SPR_MAX_TETS+4 triangles in the triangulation...
 */
#define SPR_MAX_TRIANGLES 1024 //(2*SPR_MAX_TETS+4) //928


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

  /* Constrained edges
   * hxtSPR() might shuffle what you put in here */
  struct {
    SPREdge array[SPR_MAX_EDGES];
    int num;
  } edges;

  /* Boundary triangles + constrained triangles (appearing twice)
   *
   * Nodes of boundary triangles must appear in a counter-clockwise order
   * when seen from the interior of the cavity.
   * boundary triangles must form closed a closed surface.
   * Actually, there might be multiple closed surfaces but it is better to
   * tetrahedralize them separately...
   *
   * Interior, constrained triangles must appear in both counter-clockwise
   * and clockwise order (when seen from anywhere obviously...)
   *
   * hxtSPR() might shuffle what you put in here */
  struct {
    SPRTriangle array[SPR_MAX_TRIANGLES];
    int num;
  } triangles;

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
 * in the search tree by setting max_search_nodes somewhere around SPR_MAX_TRIANGLES
 *
 * To call hxtSPR, fill the cavity structure as described in the structure
 * declaration, and, if there is no error (return value is 0),
 * get the resulting tetrahedralization in cavity->tetrahedra
 *
 *
 */
HXTStatus hxtSPR(SPRCavity* cavity);



typedef struct {
  HXTDeleted* deleted;
  HXTPartition* partition;
  HXTTetQualities* quality;
  HXTTetDates* date;
  uint16_t dateOfLastCheck;
  uint16_t dateOfLastCreation;
  HXT2Sync* toSync;
  // unsigned char* verticesMap;
  uint64_t maxSearchNodes;
} HXTSPRData;



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
 *
 * It is meant to be used for mesh optimization in hxt_tetOpti.c
 */
HXTStatus hxtSPR_opti(HXTSPRData* data,
                      uint64_t badTet);



#ifdef __cplusplus
}
#endif

#endif
