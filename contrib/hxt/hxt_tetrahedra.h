#ifndef _HXT_TETRAHEDRA_
#define _HXT_TETRAHEDRA_

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"
#include "hxt_vertices.h"

/* reserve place for tetrahedra assuming ntet tetrahedra will be added to the triangulation
 * it is efficient to give ntet = ~10 times the number of vertices to be added
 * as in average, the number of tetrahedra is ~6.5x greater than the number of vertices
 */
HXTStatus hxtTetrahedraReserve(HXTMesh* mesh, uint64_t ntet);

/* verify the consistency of a tetrahedral mesh */
HXTStatus hxtTetrahedraVerify(HXTMesh* mesh);



typedef struct HXTDelaunayOptions_struct{
  hxtBbox* bbox;              // if NULL, the bbox is recomputed internally
                              // else it mush contain the bounding box of all vertices

  double* nodalSizes;         // if NULL, doesn't restrict nodalSize
                              // else contains the minimum mesh size at each vertex
                              // if the insertion of a vertex create an edge smaller than
                              // the average nodalSize of its endpoints, the vertex is not inserted

  uint32_t numVerticesInMesh; // the number of vertices in the mesh

  int verbosity;              // verbosity=0: don't print information
                              // verbosity=1: print basic information on each pass
                              // verbosity=2: print everything
} HXTDelaunayOptions;


/* insert only vertices of index nodeInfo[i].nodes (does not change ordering of vertices !)
 *
 * this function modifies
 *     mesh->tetrahedra.*
 *     mesh->vertices[*].dist
 *     hxtNodeInfo ordering will change
 *     hxtNodeInfo[*].index will change
 *     hxtNodeInfo[*].status = HXT_STATUS_TRUE  if the vertex was successfully inserted
 *     hxtNodeInfo[*].status = HXT_STATUS_FALSE if the vertex was not inserted
                              (insertion would break the nodalSize or the vertex is already in the mesh)
 *     hxtNodeInfo[*].status = HXT_STATUS_TRYAGAIN if an error occured before the vertex could be inserted
 */
HXTStatus hxtDelaunaySteadyVertices(HXTMesh* mesh, HXTDelaunayOptions* options, hxtNodeInfo* nodeInfo, uint64_t nToInsert);


/* insert vertices from numVerticesInMesh to mesh->vertices.num
 *
 * this function modifies
 *     mesh->tetrahedra.*
 *     mesh->vertices[*].dist
 *     mesh->vertices can be reordered
 *     vertices that could not be inserted are deleted from mesh->vertices !
 *              (their insertion would break the nodalSize or the vertex is a duplicate)
 *
 * DO NOT USE THIS FUNCTION IF OTHER STUFF DEPENDS ON THE VERTICES TO INSERT
 *
 * However, this version is a little bit faster...
 */
HXTStatus hxtDelaunay(HXTMesh* mesh, HXTDelaunayOptions* options);


/* remove tetrahedra whose color are HXT_DELETED_COLOR */
HXTStatus hxtRemoveDeleted(HXTMesh* mesh);

#ifdef __cplusplus
}
#endif

#endif

