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

tmp[] = Translate {0, 0.1, 0} { Duplicata{ Point{3}; } } ;

// In this case, we assigned the result of the Translate command to a
// list, so that we can retrieve the number of the newly created point
// and use it to create new lines and a new surface:

Line(7) = {3,tmp[0]};
Line(8) = {tmp[0],5};
Line Loop(10) = {5,-8,-7,3};
Plane Surface(11) = {10};

// Of course, these transformation commands not only apply to points,
// but also to lines and surfaces. We can for example translate a copy
// of surface 6 by 0.12 units along the z axis and define some
// additional lines and surfaces with:

h = 0.12;
Translate {0, 0, h} { Duplicata{ Surface{6}; } }

Line(106) = {1,8};
Line(107) = {2,12};
Line(108) = {3,16};
Line(109) = {4,7};

Line Loop(110) = {1,107,-103,-106}; Plane Surface(111) = {110};
Line Loop(112) = {2,107,104,-108};  Plane Surface(113) = {112};
Line Loop(114) = {3,109,-105,-108}; Plane Surface(115) = {114};
Line Loop(116) = {4,106,-102,-109}; Plane Surface(117) = {116};

// Volumes are the fourth type of elementary entities in Gmsh. In the
// same way one defines line loops to build surfaces, one has to
// define surface loops (i.e. `shells') to build volumes. The
// following volume does not have holes and thus consists of a single
// surface loop:

Surface Loop(118) = {117,-6,111,-113,101,115};
Volume(119) = {118};

// Another way to define a volume is by extruding a surface. The
// following command extrudes the surface 11 along the z axis and
// automatically creates a new volume:

Extrude Surface { 11, {0, 0, h} };

// All these geometrical transformations automatically generate new
// elementary entities. The following command permits to manually
// specify a characteristic length for some of the new points:

Characteristic Length {tmp[0], 2, 12, 3, 16, 6, 22} = lc * 4;

// Note that, if the transformation tools are handy to create complex
// geometries, it is also sometimes useful to generate the `flat'
// geometry, with an explicit list of all elementary entities. This
// can be achieved by selecting the `File->Save as->Gmsh unrolled
// geometry' menu or by typing
//
// > gmsh t2.geo -0
//
// on the command line.

// To save all the tetrahedra discretizing the volumes 119 and 120
// with a common region number, we finally define a physical
// volume:

Physical Volume (1) = {119,120};
