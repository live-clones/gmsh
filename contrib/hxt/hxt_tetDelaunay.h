#ifndef _HXT_TETDELAUNAY_
#define _HXT_TETDELAUNAY_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_tetPartition.h"

/**
* \file hxt_tetDelaunay.h Delaunay tetrahedrization
* \author Célestin Marot
*/

/**
 * \struct HXTDelaunayOptions
 * 
 * Options for the Delaunay functions hxtDelaunay() and hxtDelaunaySteadyVertices()
 * 
 *
 */
typedef struct {
  HXTBbox* bbox;              /**< The bounding box for all vertices.
                               *  - if bbox==NULL, the bbox is recomputed internally;
                               *  - if bbox!=NULL, bbox must contain all vertices */

  double* nodalSizes;         /**<
                               *  - if nodalSize==NULL, doesn't restrict nodalSize;
                               *  - if nodalSize!=NULL, nodalSize contains the minimum
                               *  mesh size at each vertex.\n
                               *  If the insertion of a vertex create an edge smaller than
                               * the average nodalSize of its endpoints, the vertex is
                               * not inserted
                               *  \warning a segmentation fault will occur if a vertex
                               * doesn't have a corresponding mesh size */

  uint32_t numVerticesInMesh; /**< The number of vertices in the mesh (all vertices below this point are not (re-)inserted */

  int verbosity;              /**<
                               *  - if verbosity<=0: don't print information.
                               *  - if verbosity==1: print basic information on each pass
                               *  - if verbosity>=2: print everything */

  int reproducible;           /**< If reproducible!=0, the Delaunay use a reproducible tetrahedra order
                               * in order to be totally deterministic.
                               * \warning this takes time !
                               * It requires a total reordering of tetrahedra at the end to get a reproducible order\n
                               * except if `delaunayThreads==1 || (delaunayThreads==0 && omp_get_max_threads()==1)`\n
                               * in which case it is reproducible anyway */

  int delaunayThreads;        /**< number of threads for the delaunay insertion
                               *  - if delaunayThreads==0, it will use omp_get_max_threads()
                               *  - if delaunayThreads<0, it will uses omp_get_num_procs() */
} HXTDelaunayOptions;


/**
 * \brief Delaunay of a set of vertices that does not modify their order
 * \details This perform the insertion of the vertices whose indices are
 * given in nodeInfo (in the \ref hxtNodeInfo.node wtructure member)\n
 * This function does not change the order of vertices in the mesh.\n
 * \ref hxtNodeInfo.status will be modified by the function to tell
 * if the vertex was successfully inserted or not.
 *  - nodeInfo[i].status==HXT_STATUS_TRUE  if the vertex was successfully inserted.
 *  - nodeInfo[i].status==HXT_STATUS_FALSE  if the vertex was not inserted.
 *  - nodeInfo[i].status==HXT_STATUS_TRYAGAIN  if an error occured before the vertex could be inserted
 *
 * \warning
 *  - the order of nodeInfo will change
 *  - hxtNodeInfo[i].hilbertDist will change
 *  - mesh->tetrahedra.* will change
 *  - mesh->vertices.coord[4*i+3] will change
 *
 * \param mesh: a valid Delaunay mesh
 * \param options: options to give to the Delaunay algorithm \ref HXTDelaunayOptions (here options->numVerticesInMesh is useless)
 * \param[in, out] nodeInfo: the indices of the vertices to insert in the tetrahedral mesh.
 * \param nToInsert: the number of element in nodeInfo, hence the number of vertices to insert.
 */
HXTStatus hxtDelaunaySteadyVertices(HXTMesh* mesh, HXTDelaunayOptions* options, hxtNodeInfo* nodeInfo, uint64_t nToInsert);


/**
 * \brief Delaunay of a set of vertices
 * \details This perform the insertion of the vertices
 * from numVerticesInMesh to mesh->vertices.num\n
 *
 * \warning
 *  - the order of mesh->vertices will change
 *  - hxtNodeInfo[i].hilbertDist will change
 *  - mesh->tetrahedra.* will change
 *  - mesh->vertices.coord[4*i+3] will change
 *  - vertices that could not be inserted are deleted from mesh->vertices !
 *
 * \param mesh: a valid Delaunay mesh
 * \param options: options to give to the Delaunay algorithm \ref HXTDelaunayOptions
 */
HXTStatus hxtDelaunay(HXTMesh* mesh, HXTDelaunayOptions* options);


/**
 * \brief just add one vertex in the mesh
 * \details This perform the single insertion of the vertex vta (vertex to add) in the mesh given by mesh
 *          To avoid repetitive allocations and effort to directly eliminate deleted tetrahedra from the mesh,
 *          an array of deleted tetrahedra must be given in argument.
 *          When all insertions are performed, you may remove deleted tetrahedra from the mesh using
 *          hxtRemoveDeleted(mesh), and free the array using hxtAlignedFree(deleted);
 *          This function only works on one thread and is always reproducible
 *          => options->reproducible and options->delaunayThreads are useless
 *
 * \param mesh: a valid Delaunay mesh
 * \param options: options to give to the Delaunay algorithm \ref HXTDelaunayOptions (here options->numVerticesInMesh is useless)
 * \param vtaNodeInfo[in, out]: the index of the vertex to insert in the tetrahedral mesh
 *                              (see \ref hxtDelaunaySteadyVertices to understand how it gets filled)
 * \param deleted: a valid pointer to an array of deleted tetrahedra (that must be marked as deleted as well => see hxt_tetFlag.c)
 *                 If the array is not NULL, it must have been allocated with hxtAlignedMalloc.
 *                 In cases where the size of the array is not enough, the array may be reallocated
 *                 and moved to another location by hxtDelaunayAddOne.
 * \param numDeleted: valid pointer to the number of deleted tetrahedra in the array
 * \param sizeDeleted: valid pointer to the allocated size (in element => nbr. byte/8) of the deleted array
 * \param buffer: a buffer reused by hxtDelaunayAddOne. The first time you use it, buffer should point to NULL
 *                when you will not used hxtDelaunayAddOne anymore, use hxtDelaunayFreeBuffer to free it
 */
// HXTStatus hxtDelaunayAddOne(HXTMesh* mesh, HXTDelaunayOptions* options, hxtNodeInfo* vtaNodeInfo,
//                             uint64_t** deleted, size_t* numDeleted, size_t* sizeDeleted, void** buffer);

// HXTStatus hxtDelaunayFreeBuffer(void** buffer);


HXTStatus walking2Cavity(HXTMesh* mesh, HXTPartition* partition, uint64_t* __restrict__ curTet, const uint32_t vta);


#ifdef __cplusplus
}
#endif

#endif

