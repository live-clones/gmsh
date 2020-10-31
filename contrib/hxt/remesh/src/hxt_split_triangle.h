#ifndef _HXT_SPLIT_TRIANGLE_H_
#define _HXT_SPLIT_TRIANGLE_H_
#include "hxt_tools.h"

#include "hxt_mesh.h"
#include "hxt_edge.h"

HXTStatus hxtSplitBadTriangles (HXTMesh *mesh, HXTEdges *edges, void (*metric)(double *x, void *data, double *m), void *dataForMetric, int *numSplits );
HXTStatus hxtSplitAllTriangles (HXTMesh *mesh, HXTEdges *edges, void (*metric)(double *x, void *data, double *m), void *dataForMetric, int *numSplits );
HXTStatus hxtSplitTriangle  (HXTMesh *mesh, HXTEdges *edges, uint64_t ct, double* bc);

#endif
