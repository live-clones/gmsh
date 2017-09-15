/*********************************************************************
 *
 *  Gmsh tutorial 17
 *
 *  Anisotropic background mesh
 *
 *********************************************************************/

// Characteristic lengths can be specified very accuractely by providing a
// background mesh, i.e., a post-processing view that contains the target mesh
// sizes. Here, the background mesh is represented as a metric tensor field
// defined on a square. One should use bamg as 2d mesh generator to enable
// anisotropic meshes in 2D.

// --> the square  

Point(1) = {-1, -1, 0, 1.0};
Point(2) = {1, -1, 0, 1.0};
Point(3) = {1, 1, 0, 1.0};
Point(4) = {-1, 1, 0, 1.0};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Line Loop(1) = {1, 2, 3, 4};
Plane Surface(1) = {1};

// Merge a post-processing view containing the target anisotropic mesh sizes
Merge "t17.pos";

// Apply the view as the current background mesh
Background Mesh View[0];

// Use bamg
Mesh.SmoothRatio = 3;
Mesh.AnisoMax = 1000;

Mesh.Algorithm=7;