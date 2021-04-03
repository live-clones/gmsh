// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_VERTICES_H
#define HXT_VERTICES_H

#include "hxt_mesh.h"
#include "hxt_bbox.h"

/**
* \file hxt_vertices.h
* Compute Hilbert/Moore indices of an array of vertices and sort them.
* \author Célestin Marot
*/

/**
 * \struct HXTVertex
 * \brief Contain coordinates and a padding that can be used as a temporary value.
 *
 * We can cast mesh->vertices.coord to a HXTVertex
 * in order to use the 4th coordinate as a temporary value
 * of different types. It is used for sorting and for the Delaunay partitions.
 */
typedef struct {
  double coord[3];
  union {
    uint64_t hilbertDist;
    uint32_t index;
    HXTStatus status;
  } padding;
} HXTVertex;


/**
 * \struct HXTNodeInfo
 * \brief Simple structure with a vertex index, a Hilbert/Moore coordinate and a status
 *
 * Simple structure with a vertex index, a Hilbert/Moore coordinate and a status
 * For example, when vertices cannot be moved, we sort that structure instead.
 */
typedef struct {
  uint64_t hilbertDist;
  uint32_t node;
  HXTStatus status; // is the vertex inserted ? true, false or try_again
} HXTNodeInfo;


/**
 * \brief Compute the Hilbert/Moore index of each vertex in `vertices`
 * \param bbox: a bounding box that contain all the given vertices
 * \param vertices: the vertices coordinates
 * \param n: the number of vertices
 * \param shift[3]: a value between 0 and 1 that commands how the Hilbert/Moore curve is deformed in each dimension.
 *  {0.5, 0.5, 0.5} is the undeformed Hilbert/Moore curve.
 *
 * \details Compute the Hilbert/Moore index of each vertex in its \ref HXTVertex.padding.hilbertDist structure member.
 *          A deformation of the Hilbert/Moore curve can be done with the shift parameter
 */
HXTStatus hxtMoore(HXTBbox* bbox, HXTVertex* vertices, const uint32_t n, const double shift[3]);


/**
 * Sort all the vertices following their \ref HXTVertex.padding.hilbertDist structure member.
 *
 * \param vertices: pointer to an array of vertices
 * \param n: number of vertices in the array
 * \param nbits: the maximum number of bits set in the \ref HXTVertex.padding.hilbertDist structure member.
 */
HXTStatus hxtVerticesSort(HXTVertex* const vertices, const uint32_t n);

/**
 * Same as hxtVerticesSort(), but sort \ref HXTNodeInfo following their hilbertDist structure member.
 */
HXTStatus hxtNodeInfoSort(HXTNodeInfo* const array, const uint32_t n);

/**
 * Shuffle vertices given in an array of \ref HXTVertex in a pseudo-random fashion (always the same random sequence).
 */
HXTStatus hxtVerticesShuffle(HXTVertex* const vertices, const uint32_t n);

/**
 * Shuffle vertices given in an array of \ref HXTNodeInfo in a pseudo-random fashion (always the same random sequence).
 */
HXTStatus hxtNodeInfoShuffle(HXTNodeInfo* const array, const uint32_t n);

#endif
