
Mesh.Algorithm = 1;


/********************************************************************* 
 *
 *  Gmsh tutorial 2
 * 
 *  Includes, Geometrical transformations, Extruded geometries,
 *  Elementary entities (Volumes), Physical entities (Volumes)
 *
 *********************************************************************/

// The first tutorial file will serve as a basis to construct this
// one. It can be included with:

Include "../../tutorial/t1.geo" ;

// There are several possibilities to build a more complex geometry
// from the one previously defined in 't1.geo'.
//
// New points, lines and surfaces can first be directly defined in the
// same way as in 't1.geo':

Point(5) = {0, .4, 0, lc} ;
Line(5) = {4, 5} ;

// But Gmsh also provides geometrical transformation mechanisms to
// move (translate, rotate, ...), add (translate, rotate, ...) or
// extrude (translate, rotate) elementary geometrical entities. For
// example, the point 3 can be moved by 0.05 units on the left with:

Translate {-0.05,0,0} { Point{3} ; }

// The resulting point can also be duplicated and translated by 0.1
// along the y axis:

Translate {0,0.1,0} { Duplicata{ Point{3} ; } }

// Of course, translation, rotation and extrusion commands not only
// apply to points, but also to lines and surfaces. The following
// command extrudes surface 6 defined in 't1.geo', as well as a new
// surface 11, along the z axis by 'h':

h = 0.12 ;
Extrude Surface { 6, {0, 0, h} } ;

Line(7) = {3, 6} ; Line(8) = {6,5} ; Line Loop(10) = {5,-8,-7,3};

Plane Surface(11) = {10};

Extrude Surface { 11, {0, 0, h} } ;

// All these geometrical transformations automatically generate new
// elementary entities. The following commands permit to specify
// manually a characteristic length for some of the automatically
// created points:

Characteristic Length{6,22,2,3,16,12} = lc * 3 ;
