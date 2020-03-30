#ifndef HXT_COLLAPSE_EDGE_H
#define HXT_COLLAPSE_EDGE_H

#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

#include "hxt_point_gen_utils.h" // for parent 


HXTStatus hxtRemoveBoundaryVertex(HXTMesh *mesh,
                                  HXTEdges *edges,
                                  HXTPointGenParent *parent,
                                  uint32_t *flagE,
                                  uint32_t *lines2edges,
                                  uint64_t *edges2lines,
                                  uint64_t *lines2triangles,
                                  uint64_t maxNumTriToLine,
                                  uint64_t *vertices2lines,
                                  uint64_t maxNumLinesToVertex,
                                  uint32_t vd,  // vertex to be removed
                                  int *collapsed ); 

HXTStatus hxtRemoveInteriorVertex(HXTMesh *mesh,
                                  HXTEdges *edges,
                                  HXTPointGenParent *parent,
                                  uint32_t *flagE,
                                  uint32_t *lines2edges,
                                  uint64_t *edges2lines,
                                  uint64_t *lines2triangles,
                                  uint64_t maxNumTriToLine,
                                  uint64_t *vertices2lines,
                                  uint64_t maxNumLinesToVertex,
                                  uint32_t vd,  // vertex to be removed
                                  int *collapsed );

#endif


