/*********************************************************************
 *
 *  Gmsh tutorial 14
 *
 *  Homology computation
 *
 *********************************************************************/

// Homology computation in Gmsh finds representative chains of
// (relative) homology spaces using a mesh of a model. Those
// representatives generate the (relative) homology spaces of the
// model. Alternatively, Gmsh can only look for the ranks of the
// (relative) homology spaces, the Betti numbers of the model.

// The generators chains are stored in a given .msh-file as physical
// groups, whose mesh elements are oriented such that their
// coefficients are 1 in the generator chain.

// Create an example geometry

m = 0.5; // mesh characteristic length
h = 2; // height in the z-direction

Point(1) = {0, 0, 0, m};   Point(2) = {10, 0, 0, m};
Point(3) = {10, 10, 0, m}; Point(4) = {0, 10, 0, m};
Point(5) = {4, 4, 0, m};   Point(6) = {6, 4, 0, m};
Point(7) = {6, 6, 0, m};   Point(8) = {4, 6, 0, m};

Point(9) = {2, 0, 0, m};   Point(10) = {8, 0, 0, m};
Point(11) = {2, 10, 0, m}; Point(12) = {8, 10, 0, m};

Line(1) = {1, 9};  Line(2) = {9, 10}; Line(3) = {10, 2};
Line(4) = {2, 3};  Line(5) = {3, 12}; Line(6) = {12, 11};
Line(7) = {11, 4}; Line(8) = {4, 1};  Line(9) = {5, 6};
Line(10) = {6, 7}; Line(11) = {7, 8}; Line(12) = {8, 5};

Line Loop(13) = {6, 7, 8, 1, 2, 3, 4, 5};
Line Loop(14) = {11, 12, 9, 10};
Plane Surface(15) = {13, 14};

Extrude {0, 0, h}{ Surface{15}; }

// Create physical groups, which are used to define the domain of the
// homology computation and the subdomain of the relative homology
// computation.

// Whole domain
Physical Volume(1) = {1};

// Four "terminals" of the model
Physical Surface(70) = {36};
Physical Surface(71) = {44};
Physical Surface(72) = {52};
Physical Surface(73) = {60};

// Whole domain surface
bnd[] = Boundary{ Volume{1}; };
Physical Surface(80) = bnd[];

// Complement of the domain surface respect to the four terminals
bnd[] -= {36, 44, 52, 60};
Physical Surface(75) = bnd[];

// Find generators of relative homology spaces of the domain modulo
// the four terminals.
Homology {{1}, {70, 71, 72, 73}};

// Find the corresponding thin cuts, generators of relative homology
// spaces modulo the non-terminal domain surface.
Homology {{1}, {75}};

// Find the corresponding thick cuts.
Cohomology {{1}, {70, 71, 72, 73}};

// More examples:
//  Homology {1};
//  Homology;
//  Homology {{1}, {80}};
//  Homology {{}, {80}};
