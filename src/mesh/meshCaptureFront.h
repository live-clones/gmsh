#ifndef _MESH_CAPTURE_FRONT
#define _MESH_CAPTURE_FRONT
/**
   Assume a mesh and, for each vertex, a tag is an info about a "phase"
   Phase 0 is a front ... we want to create a mesh that divides the domain
   in elements that are either in one phase or partially on the front.
   Can be used for space time meshing.

   Implemented in 2D, 3D and soon 4D
*/
void meshCaptureFront (const std::vector<int> &nodes, const std::vector<int> &phases);
#endif
