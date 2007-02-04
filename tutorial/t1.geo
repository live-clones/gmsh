/********************************************************************* 
 *
 *  Gmsh tutorial 1
 * 
 *  Variables, elementary entities (points, lines, surfaces), physical
 *  entities (points, lines, surfaces)
 *
 *********************************************************************/

// The simplest construction in Gmsh's scripting language is the
// `affectation'. The following command defines a new variable `lc':

lc = 0.009;

// This variable can then be used in the definition of Gmsh's simplest
// `elementary entity', a `Point'. A Point is defined by a list of
// four numbers: three coordinates (X, Y and Z), and a characteristic
// length (lc) that sets the target element size at the point:

Point(1) = {0, 0, 0, lc};

// The distribution of the mesh element sizes is then obtained by
// interpolation of these characteristic lengths throughout the
// geometry. Another method to specify characteristic lengths is to
// use a background mesh (see `t7.geo' and `bgmesh.pos').

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
// mesh file, both with the region number 1. The mechanism is
// identical for line or surface elements:

MyLine = 99;
Physical Line(MyLine) = {1,2,4} ;

Physical Surface("My fancy surface label") = {6} ;

// All the line elements created during the meshing of lines 1, 2 and
// 4 will be saved in the output mesh file with the region number 99;
// and all the triangular elements resulting from the discretization
// of surface 6 will be given an automatic region number (100,
// associated with the label "My fancy surface label").

// Note that if no physical entities are defined, then all the
// elements in the mesh will be saved "as is", with their default
// orientation.
