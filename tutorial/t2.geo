/********************************************************************* 
 *
 *  Gmsh tutorial 2
 * 
 *  Includes, geometrical transformations, extruded geometries,
 *  elementary entities (volumes), physical entities (volumes)
 *
 *********************************************************************/

// We first include the previous tutorial file, in order to use it as
// a basis for this one:

Include "t1.geo";

// We can then add new points and lines in the same way as we did in
// `t1.geo':

Point(5) = {0, .4, 0, lc};
Line(5) = {4, 5};

// But Gmsh also provides tools to tranform (translate, rotate, etc.)
// elementary entities or copies of elementary entities. For example,
// the point 3 can be moved by 0.05 units to the left with:

Translate {-0.05, 0, 0} { Point{3}; }

// The resulting point can also be duplicated and translated by 0.1
// along the y axis:

Translate {0, 0.1, 0} { Duplicata{ Point{3}; } }

// This command created a new point with an automatically assigned
// id. This id can be obtained using the graphical user interface by
// hovering the mouse over it and looking at the bottom of the graphic
// window: in this case, the new point has id "6". Point 6 can then be
// used to create new entities, e.g.:

Line(7) = {3, 6};
Line(8) = {6, 5};
Line Loop(10) = {5,-8,-7,3};
Plane Surface(11) = {10};

// Using the graphical user interface to obtain the ids of newly
// created entities can sometimes be cumbersome. It can then be
// advantageous to use the return value of the transformation commands
// directly. For example, the Translate command returns a list
// containing the ids of the translated entities. For example, we can
// translate copies of the two surfaces 6 and 11 to the right with the
// following command:

my_new_surfs[] = Translate {0.12, 0, 0} { Duplicata{ Surface{6, 11}; } };

// my_new_surfs[] (note the square brackets) denotes a list, which in
// this case contains the ids of the two new surfaces (check
// `Tools->Message console' to see the message):

Printf("New surfaces '%g' and '%g'", my_new_surfs[0], my_new_surfs[1]);

// In Gmsh lists use square brackets for their definition (mylist[] =
// {1,2,3};) as well as to access their elements (myotherlist[] =
// {mylist[0], mylist[2]};). Note that list indexing starts at 0.

// Volumes are the fourth type of elementary entities in Gmsh. In the
// same way one defines line loops to build surfaces, one has to
// define surface loops (i.e. `shells') to build volumes. The
// following volume does not have holes and thus consists of a single
// surface loop:

Point(100) = {0., 0.3, 0.13, lc};  Point(101) = {0.08, 0.3, 0.1, lc};
Point(102) = {0.08, 0.4, 0.1, lc}; Point(103) = {0., 0.4, 0.13, lc};

Line(110) = {4, 100};   Line(111) = {3, 101};
Line(112) = {6, 102};   Line(113) = {5, 103};
Line(114) = {103, 100}; Line(115) = {100, 101};
Line(116) = {101, 102}; Line(117) = {102, 103};

Line Loop(118) = {115, -111, 3, 110};  Plane Surface(119) = {118};
Line Loop(120) = {111, 116, -112, -7}; Plane Surface(121) = {120};
Line Loop(122) = {112, 117, -113, -8}; Plane Surface(123) = {122};
Line Loop(124) = {114, -110, 5, 113};  Plane Surface(125) = {124};
Line Loop(126) = {115, 116, 117, 114}; Plane Surface(127) = {126};

Surface Loop(128) = {127, 119, 121, 123, 125, 11};
Volume(129) = {128};

// When a volume can be extruded from a surface, it is usually easier
// to use the Extrude command directly instead of creating all the
// points, lines and surfaces by hand. For example, the following
// command extrudes the surface 11 along the z axis and automatically
// creates a new volume (as well as all the needed points, lines and
// surfaces):

Extrude {0, 0, 0.12} { Surface{my_new_surfs[1]}; }

// The following command permits to manually assign a characteristic
// length to some of the new points:

Characteristic Length {103, 105, 109, 102, 28, 24, 6, 5} = lc * 3;

// Note that, if the transformation tools are handy to create complex
// geometries, it is also sometimes useful to generate the `flat'
// geometry, with an explicit list of all elementary entities. This
// can be achieved by selecting the `File->Save as->Gmsh unrolled
// geometry' menu or by typing
//
// > gmsh t2.geo -0
//
// on the command line.

// To save all the tetrahedra discretizing the volumes 129 and 130
// with a common region number, we finally define a physical
// volume:

Physical Volume (1) = {129,130};
