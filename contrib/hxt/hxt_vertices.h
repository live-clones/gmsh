#ifndef _HEXTREME_VERTICES_
#define _HEXTREME_VERTICES_

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
 * \struct hxtNodeInfo
 * \brief Simple structure with a vertex index, a Hilbert/Moore coordinate and a status
 *
 * Simple structure with a vertex index, a Hilbert/Moore coordinate and a status
 * For example, when vertices cannot be moved, we sort that structure instead.
 */
typedef struct {
  uint64_t hilbertDist;
  uint32_t node;
  HXTStatus status; // is the vertex inserted ? true, false or try_again
} hxtNodeInfo;


/**
 * \brief Evaluate the number of bits for the Hilbert/Moore indices
 * \param n: number of points
 * \return number of bits of Hilbert/Moore indices for a good enough resolution of points coordinates
 *
 * \details This function is aimed to work with Delaunay insertion.
 * Given a number of points from a supposedly almost uniform distribution,
 * this function guess what is the level of the Hilbert/Moore curve
 * needed such that the Delaunay insertion performs well.
 */
uint32_t hxtAdvisedHilbertBits(const uint32_t n);

/**
 * Same as hxtAdvisedHilbertBits() but with much more information
 * \param bbox: the bounding box of the mesh
 * \param sizeStart: estimated mesh size at a previous time Tstart
 * \param sizeEnd: estimated mesh size in the future time Tend
 * \param numStart: number of vertices in the mesh at Tstart
 * \param numStart: number of vertices in the mesh at Tend
 * \param numInMesh: number of vertices in the mesh now
 * \param numToSort: number of point to insert/sort at this insertion step
 */
uint32_t hxtAdvancedHilbertBits(HXTBbox* bbox, double sizeStart, double sizeEnd, uint32_t numStart, uint32_t numEnd, uint32_t numInMesh, uint32_t numToSort, uint32_t nthreads);

/**
 * \brief Compute the Hilbert/Moore index of each vertex in `vertices`
 * \param bbox: a bounding box that contain all the given vertices
 * \param vertices: the vertices coordinates
 * \param n: the number of vertices
 * \param[in,out] nbits: Sugested number of bits of the resulting Hilbert/Moore indices. The real number of bits used is returned.
 * \param shift[3]: a value between 0 and 1 that commands how the Hilbert/Moore curve is deformed in each dimension.
 *  {0.5, 0.5, 0.5} is the underformed Hilbert/Moore curve.
 *
 * \details Compute the Hilbert/Moore index of each vertex in its \ref HXTVertex.padding.hilbertDist structure member.
 *          The size of the Hilbert/Moore index in bits can be suggested. Use nbits=0 if you don't want to suggest anything.
 *          If the size of the resulting Hilbert/Moore indices differ, the value of nbits is set to the real size in bits.
 *          A deformation of the Hilbert/Moore curve can be done with the shift parameter
 */
HXTStatus hxtVerticesHilbertDist(HXTBbox* bbox, HXTVertex* vertices, const uint32_t n, uint32_t* nbits, const double shift[3]);


/**
 * Sort all the vertices following their \ref HXTVertex.padding.hilbertDist structure member.
 *
 * \param vertices: pointer to an array of vertices
 * \param n: number of vertices in the array
 * \param nbits: the maximum number of bits set in the \ref HXTVertex.padding.hilbertDist structure member.
 */
HXTStatus hxtVerticesSort(HXTVertex* const vertices, const uint32_t n, uint32_t nbits);

/**
 * Same as hxtVerticesSort(), but sort \ref hxtNodeInfo following their hilbertDist structure member.
 */
HXTStatus hxtNodeInfoSort(hxtNodeInfo* const array, const uint32_t n, uint32_t nbits);

/**
 * Shuffle vertices given in an array of \ref HXTVertex in a pseudo-random fashion (always the same random sequence).
 */
HXTStatus hxtVerticesShuffle(HXTVertex* const vertices, const uint32_t n);

/**
 * Shuffle vertices given in an array of \ref hxtNodeInfo in a pseudo-random fashion (always the same random sequence).
 */
HXTStatus hxtNodeInfoShuffle(hxtNodeInfo* const array, const uint32_t n);

#endif
