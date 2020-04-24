#ifndef _HXT_SPLIT_EDGE_H_
#define _HXT_SPLIT_EDGE_H_
#include "hxt_tools.h"
#include "hxt_mesh.h"
#include "hxt_edge.h"

HXTStatus hxtSplitLongInteriorEdges (HXTMesh *mesh, HXTEdges *edges, void (*metric)(double *x, void *data, double *m), void *dataForMetric, int *numSplits );
HXTStatus hxtSplitLongBoundaryEdges (HXTMesh *mesh, HXTEdges *edges, void (*metric)(double *x, void *data, double *m), void *dataForMetric, int *numSplits );
HXTStatus hxtSplitAllEdges (HXTMesh *mesh, HXTEdges *edges, void (*metric)(double *x, void *data, double *m), void *dataForMetric, int *numSplits );

HXTStatus hxtSplitEdge  (HXTMesh *mesh, HXTEdges *edges, uint32_t ce, uint32_t *ne, double point );

HXTStatus hxtSplitBoundaryEdge  (HXTMesh *mesh, HXTEdges *edges, uint32_t ce, double point );

HXTStatus hxtSplitBoundaryLine(HXTMesh *mesh, 
                               HXTEdges *edges, 
                               uint32_t ce,         // boundary edge to be splitted 
                               double *newpoint,    // coords of new point (instead of parameter)
                               uint64_t numTris,    // number of adjacent triangles
                               uint64_t *triangles, // adjacent triangles
                               uint32_t *ne         // new boundary edge (half line)
                               );


#endif
