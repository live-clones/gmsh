/********************************************************************* 
 *
 *  Gmsh tutorial 6
 * 
 *  Transfinite meshes
 *
 *********************************************************************/

// We use the geometry from the first tutorial as a basis for this
// tutorial:
Include "t1.geo";

// Put 20 equidistant points on curve 4
Transfinite Line{4} = 20 ; 

// Put 20 points with a refinement toward the extremities on curve 2
Transfinite Line{2} = 20 Using Bump 0.05;

// Put 30 points following a geometric progression on curve 1
// (reversed) and on curve 3
Transfinite Line{-1,3} = 30 Using Progression 1.2;

// Define the Surface as transfinite, by specifying the four corners
// of the transfinite interpolation
Transfinite Surface{6} = {1,2,3,4};

// Please note that the list on the right hand side refers to points,
// not curves. The way triangles are generated can be controlled by
// appending "Left", "Right" or "Alternate" after the list.

// Recombine the transfinite mesh into quads
Recombine Surface{6};

// Apply an elliptic smoother to the grid
Mesh.Smoothing = 100;
