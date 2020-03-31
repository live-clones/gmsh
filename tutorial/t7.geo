// -----------------------------------------------------------------------------
//
//  Gmsh GEO tutorial 7
//
//  Background mesh
//
// -----------------------------------------------------------------------------

// Mesh sizes can be specified very accurately by providing a background mesh,
// i.e., a post-processing view that contains the target characteristic lengths.

// Merge the first tutorial
Merge "t1.geo";

// Merge a post-processing view containing the target mesh sizes
Merge "t7_bgmesh.pos";

// Apply the view as the current background mesh
Background Mesh View[0];
