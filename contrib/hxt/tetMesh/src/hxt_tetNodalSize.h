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
HXTStatus hxtDestroyNodalSize(double** nodalSize);

/// Compute sizes at vertices of the mesh from meshSizeFun
HXTStatus hxtComputeNodalSizeFromFunction(HXTMesh* mesh, double* nodalSize,
                                          HXTStatus (*meshSizeFun)(double *coord, size_t n,
                                                                   void* meshSizeData),
                                          void* meshSizeData);

/// Compute sizes at vertices of the mesh from existing edges
HXTStatus hxtComputeNodalSizeFromTrianglesAndLines(HXTMesh* mesh, double* nodalSize);
HXTStatus hxtComputeNodalSizeFromMesh(HXTMesh* mesh, double* nodalSize);



#endif
