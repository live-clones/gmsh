#ifndef HXT_MESH_H_
#define HXT_MESH_H_
#include "hxt_api.h"
#include "hxt_mesh.h"
#include "hxt_bbox.h"
HXTStatus hxtOptimizeTetrahedra(HXTMesh *mesh, HXTBbox* bbox, int maxThreads, double minSize, double qualityThreshold, uint32_t numVerticesConstrained);
#endif
