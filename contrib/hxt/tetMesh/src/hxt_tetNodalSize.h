// Hxt - Copyright (C)
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETNODALSIZE_H
#define HXT_TETNODALSIZE_H

#include "hxt_mesh.h"

HXTStatus hxtCreateNodalSize(HXTMesh* mesh, double** nodalSizes_ptr);
HXTStatus hxtDestroyNodalsize(double** nodalSize);

/// Compute sizes at vertices of the mesh from meshSizeFun
HXTStatus hxtComputeNodalSizeFromFunction(HXTMesh* mesh, double* nodalSize,
                                          double (*meshSizeFun)(double x, double y, double z,
                                                                void* meshSizeData),
                                          void* meshSizeData);

/// Compute sizes at vertices of the mesh from existing edges
HXTStatus hxtComputeNodalsizeFromTrianglesAndLines(HXTMesh* mesh, double* nodalSize);
HXTStatus hxtComputeNodalsizeFromMesh(HXTMesh* mesh, double* nodalSize);



#endif
