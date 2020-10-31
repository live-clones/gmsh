#ifndef _HXT_SWAP_EDGE_H_
#define _HXT_SWAP_EDGE_H_
#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"


int isEdgeOrientedInTriangle (HXTMesh *mesh, 
                              HXTEdges *edges, 
                              uint64_t ct, 
                              uint32_t ce);

HXTStatus hxtMeshValidity2d (HXTMesh *mesh, 
                             int *isValid );

HXTStatus hxtSwapEdges      (HXTMesh *mesh, 
                             HXTEdges *edges, 
                             void (*metric)(double *x, void *data, double *m), 
                             void *dataForMetric, 
                             uint64_t *edges2lines,
                             uint64_t maxNumTriToLine,
                             uint64_t *lines2triangles,
                             int *numSwaps );

HXTStatus hxtTempPrintSwap  (HXTMesh *mesh,
                             HXTEdges *edges,
                             uint32_t ce,
                             int when);

HXTStatus hxtSwapEdge       (HXTMesh *mesh,  
                             HXTEdges *edges, 
                             void (*metric)(double *x, void *data, double *m), 
                             void *dataForMetric, 
                             uint64_t *edges2lines,
                             uint64_t maxNumTriToLine,
                             uint64_t *lines2triangles,
                             double angle,
                             uint32_t ce, // edge to be swapped
                             int *swapped);

HXTStatus hxtSwapEdge_old   (HXTMesh *mesh, 
                             HXTEdges *edges, 
                             void (*metric)(double *x, void *data, double *m), 
                             void *dataForMetric, 
                             int *swapped, 
                             uint32_t i );

#endif
