// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETREFINE_H
#define HXT_TETREFINE_H

#include "hxt_tetDelaunay.h"

//// creates a mesh with all points of the surface mesh
HXTStatus hxtEmptyMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions);

/// Add points at tets circumcenter in order to fulfill a mesh size constraint 
HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTDelaunayOptions* delOptions);

// /// Add points at tets circumcenter in order to fulfill a mesh size constraint only in tets colored with tet_color (for alpha shape)
// HXTStatus hxtRefineColoredTetrahedra(HXTMesh* mesh, HXTDelaunayOptions* delOptions, uint32_t tet_color);

int getBestCenter(double p[4][4], double nodalSize[4], double center[4], HXTNodalSizes* ns);

#endif
