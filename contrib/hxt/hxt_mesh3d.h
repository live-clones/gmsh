#ifndef _HXT_MESH_3D_
#define _HXT_MESH_3D_

#include "hxt_tetrahedra.h"

/// Creates a structure that allows to look over triangular faces of the 2D mesh
HXTStatus hxtCreateFaceSearchStructure(HXTMesh* mesh, uint32_t **pfaces);
//// creates a mesh with all points of the surface mesh
HXTStatus hxtEmptyMesh(HXTMesh* mesh, HXTDelaunayOptions* delOptions);
/// Compute sizes at vertices of the mesh from existing edges of the tetrahera
HXTStatus hxtComputeMeshSizeFromTrianglesAndLines (HXTMesh* mesh, HXTDelaunayOptions* delOptions);
HXTStatus hxtComputeMeshSizeFromMesh (HXTMesh* mesh, HXTDelaunayOptions* delOptions);
/// Gives a unique color to each enclosed volume
HXTStatus hxtColorMesh(HXTMesh* mesh, uint16_t *nbColors);
/// Recover the boundary
HXTStatus hxtRecoverBoundary(HXTMesh* mesh);
/// Add points at tets circumcenter in order to fullfill a mesh size constraint 
HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTDelaunayOptions* delOptions, HXTMeshSize* meshsize);

#endif
