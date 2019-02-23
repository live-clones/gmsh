#ifndef _HXT_MESH_3D_
#define _HXT_MESH_3D_

#include "hxt_tetDelaunay.h"

/// Creates a structure that allows to look over triangular faces of the 2D mesh
HXTStatus hxtCreateFaceSearchStructure(HXTMesh* mesh, uint32_t **pfaces);

//// creates a mesh with all points of the surface mesh
HXTStatus hxtEmptyMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions);

/// Compute sizes at vertices of the mesh from a mesh_size function
HXTStatus hxtCreateNodalSizeFromFunction(HXTMesh* mesh, HXTDelaunayOptions* delOptions,
                                         double (*mesh_size)(double x, double y, double z, void* userData),
                                         void* userData);

/// Compute sizes at vertices of the mesh from existing edges
HXTStatus hxtCreateNodalsizeFromTrianglesAndLines(HXTMesh* mesh, HXTDelaunayOptions* delOptions);
HXTStatus hxtCreateNodalsizeFromMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions);
HXTStatus hxtDestroyNodalsize(HXTDelaunayOptions* delOptions);

/// Add points at tets circumcenter in order to fullfill a mesh size constraint 
HXTStatus hxtRefineTetrahedra(HXTMesh* mesh,
                              HXTDelaunayOptions* delOptions,
                              double (*mesh_size)(double x, double y, double z, void* userData),
                              void* userData);

#endif
