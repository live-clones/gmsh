/********************************************************************* 
 *
 *  Gmsh tutorial 1
 * 
 *  Variables, elementary entities (points, lines, surfaces), physical
 *  entities (points, lines, surfaces), background mesh
 *
 *********************************************************************/

// The simplest construction of Gmsh's scripting language is the
// `affectation'. The following command defines a new variable `lc':

lc = 0.009;

// This variable can then for example be used in the definition of
// Gmsh's simplest `elementary entity', a `Point'. A Point is defined
// by a list of four numbers: its three coordinates (X, Y and Z), and
// a characteristic length which sets the target element size at the
// point:

Point(1) = {0, 0, 0, 9.e-1 * lc};

// The actual distribution of the mesh element sizes is then obtained
// by interpolation of these characteristic lengths throughout the
// geometry. There are also other possibilities to specify
// characteristic lengths: attractors (see `t7.geo') and background
// meshes (see `bgmesh.pos').

// As can be seen in the previous definition, more complex expressions
// can be constructed from variables and floating point
// constants. Here, the product of the variable `lc' by the constant
// 9.e-1 is given as the fourth argument of the list defining the
// point.

// We can then define some additional points as well as our first
// curve.  Curves are Gmsh's second type of elementery entities, and,
// amongst curves, straight lines are the simplest. A straight line is
// defined by a list of point numbers. In the commands below, for
// example, the line 1 starts at point 1 and ends at point 2:

Point(2) = {.1, 0,  0, lc} ;
Point(3) = {.1, .3, 0, lc} ;
Point(4) = {0,  .3, 0, lc} ;

Line(1) = {1,2} ;
Line(2) = {3,2} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;

// The third elementary entity is the surface. In order to define a
// simple rectangular surface from the four lines defined above, a
// line loop has first to be defined. A line loop is a list of
// connected lines, a sign being associated with each line (depending
// on the orientation of the line):

Line Loop(5) = {4,1,-2,3} ;

// We can then define the surface as a list of line loops (only one
// here, since there are no holes--see `t4.geo'):

Plane Surface(6) = {5} ;

// At this level, Gmsh knows everything to display the rectangular
// surface 6 and to mesh it. An optional step is needed if we want to
// associate specific region numbers to the various elements in the
// mesh (e.g. to the line segments discretizing lines 1 to 4 or to the
// triangles discretizing surface 6). This is achieved by the
// definition of `physical entities'. Physical entities will group
// elements belonging to several elementary entities by giving them a
// common number (a region number), and specifying their orientation.

// We can for example group the points 1 and 2 into the physical
// entity 1:

Physical Point(1) = {1,2} ;

// Consequently, two punctual elements will be saved in the output
// files, both with the region number 1. The mechanism is identical
// for line or surface elements:

Physical Line(10) = {1,2,4} ;

MySurface = 100;
Physical Surface(MySurface) = {6} ;

// All the line elements created during the meshing of lines 1, 2 and
// 4 will be saved in the output file with the region number 10; and
// all the triangular elements resulting from the discretization of
// surface 6 will be given the region number 100.

// Note that, if no physical entities are defined, all the elements in
// the mesh will be directly saved with their default orientation and
// with a region number equal to the number of the elementary entity
// they discretize.
Transfinite Surface {6} = {1,2,3,4};
