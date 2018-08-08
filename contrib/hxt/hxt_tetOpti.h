#ifndef HXT_MESH_H_
#define HXT_MESH_H_
#include "hxt_api.h"
#include "hxt_mesh.h"
HXTStatus hxtOptimizeTetrahedra(HXTMesh *mesh, HXTBbox* bbox, double minSize, double qualityThreshold, uint32_t numVerticesConstrained);
#endif
