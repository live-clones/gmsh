/********************************************************************* 
 *
 *  Gmsh tutorial 7
 * 
 *  Background mesh
 *
 *********************************************************************/

// Characteristic lengths can be specified very accuractely by
// providing a background mesh, i.e., a post-processing view that
// contains the target mesh sizes.

// Merge the first tutorial
Merge "t1.geo";

// Merge a post-processing view containing the target mesh sizes
Merge "bgmesh.pos";

// Apply the view as the current background mesh
Background Mesh View[0];
