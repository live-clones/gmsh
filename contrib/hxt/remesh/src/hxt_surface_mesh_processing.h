#ifndef HXT_SURFACE_MESH_PROCESSING_H
#define HXT_SURFACE_MESH_PROCESSING_H

#include "hxt_mesh.h"

HXTStatus hxtSurfaceQuadSingularitiesOutput(HXTMesh *mesh);

HXTStatus hxtSurfaceMeshSplitFullQuad(HXTMesh *mesh);

HXTStatus hxtSurfaceMeshSplitQuads(HXTMesh *mesh, uint16_t *color);

HXTStatus hxtSurfaceQuadSize(HXTMesh *mesh);

HXTStatus hxtHexMeshBoundary(HXTMesh *mesh);

HXTStatus hxtSurfaceQuadColorBipartite(HXTMesh *mesh);

HXTStatus hxtSurfaceMeshExportTriangleQuality(HXTMesh *nmesh, const double *sizemap);


#endif
