#ifndef _HXT_TETREFINE_
#define _HXT_TETREFINE_

#include "hxt_tetDelaunay.h"

/// Creates a structure that allows to look over triangular faces of the 2D mesh
HXTStatus hxtCreateFaceSearchStructure(HXTMesh* mesh, uint32_t **pfaces);

//// creates a mesh with all points of the surface mesh
HXTStatus hxtEmptyMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions);

/// Add points at tets circumcenter in order to fullfill a mesh size constraint 
HXTStatus hxtRefineTetrahedra(HXTMesh* mesh,
                              HXTDelaunayOptions* delOptions,
                              double (*meshSizeFun)(double x, double y, double z,
                                                    void* meshSizeData),
                              void* meshSizeData);

#endif
