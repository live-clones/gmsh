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

/// Add points at tets circumcenter in order to fullfill a mesh size constraint 
HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTDelaunayOptions* delOptions);

#endif
