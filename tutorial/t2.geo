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

Translate {-0.05,0,0} { Point{3}; }

// The resulting point can also be duplicated and translated by 0.1
// along the y axis:

Translate {0,0.1,0} { Duplicata{ Point{3}; } }

// Of course, these transformation commands not only apply to points,
// but also to lines and surfaces. The following command extrudes the
// surface 6 defined in `t1.geo', as well as a new surface 11, along
// the z axis:

h = 0.12;
Extrude Surface { 6, {0, 0, h} };

Line(7) = {3, 6};
Line(8) = {6,5};

Line Loop(10) = {5,-8,-7,3};
Plane Surface(11) = {10};

Extrude Surface { 11, {0, 0, h} };

// All these geometrical transformations automatically generate new
// elementary entities. The following command permits to manually
// specify a characteristic length for some of the new points:

Characteristic Length {6, 22, 2, 3, 16, 12} = lc * 2;

// Note that, if the transformation tools are handy to create complex
// geometries, it is also sometimes useful to generate the `flat'
// geometry, with an explicit list of all elementary entities. This
// can be achieved by selecting the `File->Save as->Gmsh unrolled
// geometry' menu or by typing
//
// > gmsh t2.geo -0
//
// on the command line.

// Volumes are the fourth type of elementary entities in Gmsh. In the
// same way one defines line loops to build surfaces, one has to
// define surface loops (i.e. `shells') to build volumes. The
// following volumes don't have holes and thus consist of single
// surface loops:

Surface Loop(145) = {121,11,131,135,139,144};
Volume(146) = {145};

Surface Loop(146) = {121,6,109,113,117,122};
Volume(147) = {146};

// To save all the tetrahedra discretizing the volumes 146 and 147
// with a common region number, we finally define a physical
// volume:

Physical Volume (1) = {146,147};
