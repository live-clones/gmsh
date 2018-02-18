#ifndef _HXT_MESH_3D_
#define _HXT_MESH_3D_

#include <hxt_tools.h>

/// Creates a structure that allows to look over triangular faces of the 2D mesh
HXTStatus hxtCreateFaceSearchStructure(HXTMesh* mesh, uint32_t **pfaces);
//// creates a mesh with all points of the surface mesh
HXTStatus hxtEmptyMesh(HXTMesh* mesh);
/// Compute sizes at vertices of the mesh from existing edges of the tetrahera
HXTStatus hxtComputeMeshSizeFromMesh (HXTMesh* mesh, double **sizes);
/// Verify if all facets are present in a tetrahedrization, missing is the number of missing facets
HXTStatus hxtVerifyBoundary(HXTMesh* mesh, uint32_t *missing);
/// Recover the boundary
HXTStatus hxtRecoverBoundary(HXTMesh* mesh);
/// Starts from an empty 3D mesh and color the different regions 
HXTStatus hxtColorMesh(HXTMesh* mesh, uint32_t *nbColors);
/// Add points at tets circumcenter in order to fullfill a mesh size constraint 
HXTStatus hxtRefineTetrahedra(HXTMesh* mesh, HXTMeshSize* meshsize, double **nodalSizes);

#endif
