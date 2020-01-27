#ifndef _HXT_TETNODALSIZE_
#define _HXT_TETNODALSIZE_

#include "hxt_mesh.h"

/// Compute sizes at vertices of the mesh from meshSizeFun
HXTStatus hxtCreateNodalSizeFromFunction(HXTMesh* mesh, double** nodalSize,
                                         double (*meshSizeFun)(double x, double y, double z,
                                                               void* meshSizeData),
                                         void* meshSizeData);

/// Compute sizes at vertices of the mesh from existing edges
HXTStatus hxtCreateNodalsizeFromTrianglesAndLines(HXTMesh* mesh, double** nodalSize);
HXTStatus hxtCreateNodalsizeFromMesh(HXTMesh* mesh, double** nodalSize);
HXTStatus hxtDestroyNodalsize(double** nodalSize);

#endif