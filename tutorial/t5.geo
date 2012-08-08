/*********************************************************************
 *
 *  Gmsh tutorial 5
 *
 *  Characteristic lengths, arrays of variables, functions, loops
 *
 *********************************************************************/

// We start by defining some target mesh sizes:

lcar1 = .1;
lcar2 = .0005;
lcar3 = .055;

// If we wanted to change these mesh sizes globally (without changing
// the above definitions), we could give a global scaling factor for
// all characteristic lengths on the command line with the `-clscale'
// option (or with `Mesh.CharacteristicLengthFactor' in an option
// file). For example, with:
//
// > gmsh t5.geo -clscale 1
//
// this input file produces a mesh of approximately 1,300 nodes and
// 11,000 tetrahedra. With
//
// > gmsh t5.geo -clscale 0.2
//
// the mesh counts approximately 350,000 nodes and 2.1 million
// tetrahedra. You can check mesh statistics in the graphical user
// interface with the `Tools->Statistics' menu.

// We proceed by defining some elementary entities describing a
// truncated cube:

Point(1) = {0.5,0.5,0.5,lcar2}; Point(2) = {0.5,0.5,0,lcar1};
Point(3) = {0,0.5,0.5,lcar1};   Point(4) = {0,0,0.5,lcar1};
Point(5) = {0.5,0,0.5,lcar1};   Point(6) = {0.5,0,0,lcar1};
Point(7) = {0,0.5,0,lcar1};     Point(8) = {0,1,0,lcar1};
Point(9) = {1,1,0,lcar1};       Point(10) = {0,0,1,lcar1};
Point(11) = {0,1,1,lcar1};      Point(12) = {1,1,1,lcar1};
Point(13) = {1,0,1,lcar1};      Point(14) = {1,0,0,lcar1};

Line(1) = {8,9};    Line(2) = {9,12};  Line(3) = {12,11};
Line(4) = {11,8};   Line(5) = {9,14};  Line(6) = {14,13};
Line(7) = {13,12};  Line(8) = {11,10}; Line(9) = {10,13};
Line(10) = {10,4};  Line(11) = {4,5};  Line(12) = {5,6};
Line(13) = {6,2};   Line(14) = {2,1};  Line(15) = {1,3};
Line(16) = {3,7};   Line(17) = {7,2};  Line(18) = {3,4};
Line(19) = {5,1};   Line(20) = {7,8};  Line(21) = {6,14};

Line Loop(22) = {-11,-19,-15,-18};   Plane Surface(23) = {22};
Line Loop(24) = {16,17,14,15};       Plane Surface(25) = {24};
Line Loop(26) = {-17,20,1,5,-21,13}; Plane Surface(27) = {26};
Line Loop(28) = {-4,-1,-2,-3};       Plane Surface(29) = {28};
Line Loop(30) = {-7,2,-5,-6};        Plane Surface(31) = {30};
Line Loop(32) = {6,-9,10,11,12,21};  Plane Surface(33) = {32};
Line Loop(34) = {7,3,8,9};           Plane Surface(35) = {34};
Line Loop(36) = {-10,18,-16,-20,4,-8}; Plane Surface(37) = {36};
Line Loop(38) = {-14,-13,-12,19};    Plane Surface(39) = {38};

// Instead of using included files, we now use a user-defined function
// in order to carve some holes in the cube:

Function CheeseHole

  // In the following commands we use the reserved variable name
  // `newp', which automatically selects a new point number. This
  // number is chosen as the highest current point number, plus
  // one. (Note that, analogously to `newp', the variables `newc',
  // `news', `newv' and `newreg' select the highest number amongst
  // currently defined curves, surfaces, volumes and `any entities
  // other than points', respectively.)

  p1 = newp; Point(p1) = {x,  y,  z,  lcar3} ;
  p2 = newp; Point(p2) = {x+r,y,  z,  lcar3} ;
  p3 = newp; Point(p3) = {x,  y+r,z,  lcar3} ;
  p4 = newp; Point(p4) = {x,  y,  z+r,lcar3} ;
  p5 = newp; Point(p5) = {x-r,y,  z,  lcar3} ;
  p6 = newp; Point(p6) = {x,  y-r,z,  lcar3} ;
  p7 = newp; Point(p7) = {x,  y,  z-r,lcar3} ;

  c1 = newreg; Circle(c1) = {p2,p1,p7}; c2 = newreg; Circle(c2) = {p7,p1,p5};
  c3 = newreg; Circle(c3) = {p5,p1,p4}; c4 = newreg; Circle(c4) = {p4,p1,p2};
  c5 = newreg; Circle(c5) = {p2,p1,p3}; c6 = newreg; Circle(c6) = {p3,p1,p5};
  c7 = newreg; Circle(c7) = {p5,p1,p6}; c8 = newreg; Circle(c8) = {p6,p1,p2};
  c9 = newreg; Circle(c9) = {p7,p1,p3}; c10 = newreg; Circle(c10) = {p3,p1,p4};
  c11 = newreg; Circle(c11) = {p4,p1,p6}; c12 = newreg; Circle(c12) = {p6,p1,p7};

  // We need non-plane surfaces to define the spherical holes. Here we
  // use ruled surfaces, which can have 3 or 4 sides:

  l1 = newreg; Line Loop(l1) = {c5,c10,c4};   Ruled Surface(newreg) = {l1};
  l2 = newreg; Line Loop(l2) = {c9,-c5,c1};   Ruled Surface(newreg) = {l2};
  l3 = newreg; Line Loop(l3) = {c12,-c8,-c1}; Ruled Surface(newreg) = {l3};
  l4 = newreg; Line Loop(l4) = {c8,-c4,c11};  Ruled Surface(newreg) = {l4};
  l5 = newreg; Line Loop(l5) = {-c10,c6,c3};  Ruled Surface(newreg) = {l5};
  l6 = newreg; Line Loop(l6) = {-c11,-c3,c7}; Ruled Surface(newreg) = {l6};
  l7 = newreg; Line Loop(l7) = {-c2,-c7,-c12};Ruled Surface(newreg) = {l7};
  l8 = newreg; Line Loop(l8) = {-c6,-c9,c2};  Ruled Surface(newreg) = {l8};

  // We then store the surface loops identification numbers in a list
  // for later reference (we will need these to define the final
  // volume):

  theloops[t] = newreg ;

  Surface Loop(theloops[t]) = {l8+1,l5+1,l1+1,l2+1,l3+1,l7+1,l6+1,l4+1};

  thehole = newreg ;
  Volume(thehole) = theloops[t] ;

Return

// We can use a `For' loop to generate five holes in the cube:

x = 0 ; y = 0.75 ; z = 0 ; r = 0.09 ;

For t In {1:5}

  x += 0.166 ;
  z += 0.166 ;

  // We call the `CheeseHole' function:

  Call CheeseHole ;

  // We define a physical volume for each hole:

  Physical Volume (t) = thehole ;

  // We also print some variables on the terminal (note that, since
  // all variables are treated internally as floating point numbers,
  // the format string should only contain valid floating point format
  // specifiers like `%g', `%f', '%e', etc.):

  Printf("Hole %g (center = {%g,%g,%g}, radius = %g) has number %g!",
	 t, x, y, z, r, thehole) ;

EndFor

// We can then define the surface loop for the exterior surface of the
// cube:

theloops[0] = newreg ;

Surface Loop(theloops[0]) = {35,31,29,37,33,23,39,25,27} ;

// The volume of the cube, without the 5 holes, is now defined by 6
// surface loops: the first surface loop defines the exterior surface;
// the surface loops other than the first one define holes.  (Again,
// to reference an array of variables, its identifier is followed by
// square brackets):

Volume(186) = {theloops[]} ;

// We finally define a physical volume for the elements discretizing
// the cube, without the holes (whose elements were already tagged
// with numbers 1 to 5 in the `For' loop):

Physical Volume (10) = 186 ;
