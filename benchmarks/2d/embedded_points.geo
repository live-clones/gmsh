/*********************************************************************
 *
 *  Open Pit Model
 *
 *********************************************************************/

// The simplest construction in Gmsh's scripting language is the
// `affectation'. The following command defines a new variable `lc':

lc = 10;
lcfine = 10;
lctransition = 1;
lcfinetransition = 1;

// This variable can then be used in the definition of Gmsh's simplest
// `elementary entity', a `Point'. A Point is defined by a list of
// four numbers: three coordinates (X, Y and Z), and a characteristic
// length (lc) that sets the target element size at the point:
// The distribution of the mesh element sizes is then obtained by
// interpolation of these characteristic lengths throughout the
// geometry. Another method to specify characteristic lengths is to
// use a background mesh (see `t7.geo' and `bgmesh.pos').

// We can then define some additional points as well as our first
// curve.  Curves are Gmsh's second type of elementery entities, and,
// amongst curves, straight lines are the simplest. A straight line is
// defined by a list of point numbers. In the commands below, for
// example, the line 1 starts at point 1 and ends at point 2:

Point(1) = {0, 190, 0, lc};

Point(2) = {157, 190, 0, lcfine};
Point(3) = {164.3, 170, 0, lcfine};
Point(4) = {172.8, 170, 0, lcfine};
Point(5) = {180.1, 150, 0, lcfine};
Point(6) = {188.6, 150, 0, lcfine};
Point(7) = {195.9, 130, 0, lcfine};
Point(8) = {204.4, 130, 0, lcfine};
Point(9) = {211.7, 110, 0, lcfine};
Point(10) = {220.2, 110, 0, lcfine};
Point(11) = {227.5, 90, 0, lcfine};
Point(12) = {236, 90, 0, lcfine};
Point(13) = {243.3, 70, 0, lcfine};

Point(14) = {350, 70, 0, lc};
Point(15) = {350, 0, 0, lc};
Point(16) = {0, 0, 0, lc};

// Dummy points used for higher control on element sizes
// created using For loops
// First sets of points with smaller characteristic lengths
x = 105 ; y = 185 ;

For t In {17:30}
	Point(t) = {x, y, 0, lcfinetransition} ;
	y -= 10.0;
EndFor

y=45;
For t In {31:48}
	Point(t) = {x, y, 0, lcfinetransition} ;
	x += 10.0;
EndFor

x=275;
For t In {49:50}
	y += 10.0;
	Point(t) = {x, y, 0, lcfinetransition} ;

EndFor

// Second sets of points with larger characteristic lengths
For t In {17:31}
	Translate {-20, 0, 0} { Duplicata{ Point{t}; } }
EndFor
For t In {31:48}
	Translate {0, -20, 0} { Duplicata{ Point{t}; } }
EndFor
For t In {48:51}
	Translate {+20, 0, 0} { Duplicata{ Point{t}; } }
EndFor

// The following command permits to manually assign a characteristic
// length to some of the new points:
For t In {52:87}
	Characteristic Length {t} = lctransition;
EndFor

// Model Boundaries
Line(1) = {1,2} ;
Line(2) = {2,3} ;
Line(3) = {3,4} ;
Line(4) = {4,5} ;
Line(5) = {5,6} ;
Line(6) = {6,7} ;
Line(7) = {7,8} ;
Line(8) = {8,9} ;
Line(9) = {9,10} ;
Line(10) = {10,11} ;
Line(11) = {11,12} ;
Line(12) = {12,13} ;
Line(13) = {13,14} ;
Line(14) = {14,15} ;
Line(15) = {15,16} ;
Line(16) = {16,1} ;

// The third elementary entity is the surface. In order to define a
// simple rectangular surface from the four lines defined above, a
// line loop has first to be defined. A line loop is a list of
// connected lines, a sign being associated with each line (depending
// on the orientation of the line):

Line Loop(17) = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13, -14, -15, -16} ;

// We can then define the surface as a list of line loops (only one
// here, since there are no holes--see `t4.geo'):

Plane Surface(1) = {17} ;

// Define a physical entity, otherwise Gmsh may export
// a lot of different element types in the exported .inp file
// (Y-GUI can't open the .inp file)
Physical Surface("surface 1") = {1} ;

// Adding dummy nodes to the surface for more control over element sizes
For t In {17:86}
	Point{t} In Surface{1} ;
EndFor

// Mesh smoothing
//Mesh.Smoothing = 10;

// Flag to save Node Sets (NSETs) in the inp file
Mesh.SaveGroupsOfNodes = 1;

//Mesh.Algorithm = 1;


// Get total number of Lines and Surfaces
// ll[] = Line {:};
// ss[] = Surface {:} ;
// pp[] = Point {:};
// Printf("Number of Lines in the geometry: %g", #ll[]) ;
// Printf("Number of Surfaces in the geometry : %g", #ss[]) ;
// Printf("Number of Points in the geometry : %g", #pp[]) ;
