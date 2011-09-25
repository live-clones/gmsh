/********************************************************************* 
 *
 *  Gmsh tutorial 11
 * 
 *  Unstructured quadrangular meshes
 *
 *********************************************************************/

// We have seen in tutorials t3 and t6 that extruded and transfinite
// meshes can be "recombined" into quads/prisms/hexahedra by using the
// "Recombine" keyword. Unstructured meshes can be recombined in the
// same way. Let's define a simple geometry with an analytical mesh
// size field:

Point(1) = {-1.25, -.5, 0}; Point(2) = {-1.25, 1.25, 0};
Point(3) = {1.25, -.5, 0};  Point(4) = {1.25, 1.25, 0};

Line(1) = {1, 2}; Line(2) = {2, 4};
Line(3) = {4, 3}; Line(4) = {3, 1};

Line Loop(4) = {1,2, 3, 4}; Plane Surface(100) = {4};

Field[1] = MathEval;
Field[1].F = "0.01*(1.0+30.*(y-x*x)*(y-x*x) + (1-x)*(1-x))";
Background Field = 1;

// To generate quadrangles instead of triangles, we can simply add
Recombine Surface{100};

// If we'd had several surfaces, we could have used 'Recombine Surface
// "*";'. Yet another way would be to specify the global option
// "Mesh.RecombineAll = 1;".

// The default recombination algorithm is called "Blossom": it uses a
// minimum cost perfect matching algorithm to generate fully
// quadrilateral meshes from triangulations. More details about the
// algorithm can be found in the following paper: J.-F. Remacle,
// J. Lambrechts, B. Seny, E. Marchandise, A. Johnen and C. Geuzaine,
// "Blossom-Quad: a non-uniform quadrilateral mesh generator using a
// minimum cost perfect matching algorithm", International Journal for
// Numerical Methods in Engineering, 2011 (in press).

// For even better quadrilateral meshes, you can try the experimental
// "Delaunay for quads" (DelQuad) meshing algorithm: DelQuad is a
// triangulation algorithm that enables to create right triangles
// almost everywhere. Uncomment the following line to try DelQuad:

// Mesh.Algorithm = 8; // DelQuad (experimental)
