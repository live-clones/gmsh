/********************************************************************* 
 *
 *  Gmsh tutorial 5
 * 
 *  Characteristic lengths, Arrays of variables, Functions, Loops
 *
 *********************************************************************/

// This defines some characteristic lengths:

lcar1 = .1;
lcar2 = .0005;
lcar3 = .075;

// In order to change these lengths globally (without changing the
// file), a global scaling factor for all characteristic lengths can
// be specified on the command line with the option '-clscale'. For
// example, with:
//
// > gmsh t5 -clscale 1
//
// this example produces a mesh of approximately 2000 nodes and
// 10,000 tetrahedra (in 3 seconds on an alpha workstation running at
// 666MHz). With 
//
// > gmsh t5 -clscale 0.2
//
// (i.e. with all characteristic lengths divided by 5), the mesh
// counts approximately 170,000 nodes and one million tetrahedra
// (and the computation takes 16 minutes on the same machine :-( So
// there is still a lot of work to do to achieve decent performance
// with Gmsh...)

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

Line Loop(22) = {11,19,15,18};       Plane Surface(23) = {22};
Line Loop(24) = {16,17,14,15};       Plane Surface(25) = {24};
Line Loop(26) = {-17,20,1,5,-21,13}; Plane Surface(27) = {26};
Line Loop(28) = {4,1,2,3};           Plane Surface(29) = {28};
Line Loop(30) = {7,-2,5,6};          Plane Surface(31) = {30};
Line Loop(32) = {6,-9,10,11,12,21};  Plane Surface(33) = {32};
Line Loop(34) = {7,3,8,9};           Plane Surface(35) = {34};
Line Loop(36) = {10,-18,16,20,-4,8}; Plane Surface(37) = {36};
Line Loop(38) = {-14,-13,-12,19};    Plane Surface(39) = {38};

// Instead of using included files, one can also define functions. In
// the following function, the reserved variable 'newp' is used, which
// automatically selects a new point number. This number is chosen as
// the highest current point number, plus one. Analogously to 'newp',
// there exists a variable 'newreg' which selects the highest number
// of all entities other than points, plus one.

// Note: there are no local variables. This will be changed in a
// future version of Gmsh.

Function CheeseHole 

  p1 = newp; Point(p1) = {x,  y,  z,  lcar3} ;
  p2 = newp; Point(p2) = {x+r,y,  z,  lcar3} ;
  p3 = newp; Point(p3) = {x,  y+r,z,  lcar3} ;
  p4 = newp; Point(p4) = {x,  y,  z+r,lcar3} ;
  p5 = newp; Point(p5) = {x-r,y,  z,  lcar3} ;
  p6 = newp; Point(p6) = {x,  y-r,z,  lcar3} ;
  p7 = newp; Point(p7) = {x,  y,  z-r,lcar3} ;

  c1 = newreg; Circle(c1) = {p2,p1,p7};
  c2 = newreg; Circle(c2) = {p7,p1,p5};
  c3 = newreg; Circle(c3) = {p5,p1,p4};
  c4 = newreg; Circle(c4) = {p4,p1,p2};
  c5 = newreg; Circle(c5) = {p2,p1,p3};
  c6 = newreg; Circle(c6) = {p3,p1,p5};
  c7 = newreg; Circle(c7) = {p5,p1,p6};
  c8 = newreg; Circle(c8) = {p6,p1,p2};
  c9 = newreg; Circle(c9) = {p7,p1,p3};
  c10 = newreg; Circle(c10) = {p3,p1,p4};
  c11 = newreg; Circle(c11) = {p4,p1,p6};
  c12 = newreg; Circle(c12) = {p6,p1,p7};

// All surfaces are not plane... Here is the way to define ruled
// surfaces (which have 3 or 4 borders):

  l1 = newreg; Line Loop(l1) = {c5,c10,c4};   Ruled Surface(newreg) = {l1};
  l2 = newreg; Line Loop(l2) = {c9,-c5,c1};   Ruled Surface(newreg) = {l2};
  l3 = newreg; Line Loop(l3) = {-c12,c8,c1};  Ruled Surface(newreg) = {l3};
  l4 = newreg; Line Loop(l4) = {c8,-c4,c11};  Ruled Surface(newreg) = {l4};
  l5 = newreg; Line Loop(l5) = {-c10,c6,c3};  Ruled Surface(newreg) = {l5};
  l6 = newreg; Line Loop(l6) = {-c11,-c3,c7}; Ruled Surface(newreg) = {l6};
  l7 = newreg; Line Loop(l7) = {c2,c7,c12};   Ruled Surface(newreg) = {l7};
  l8 = newreg; Line Loop(l8) = {-c6,-c9,c2};  Ruled Surface(newreg) = {l8};

// Arrays of variables can be manipulated in the same way as classical
// variables. Warning: accessing an uninitialized element in an array
// will produce an unpredictable result.

  theloops[t] = newreg ; 

  Surface Loop(theloops[t]) = {l8+1, l5+1, l1+1, l2+1, -(l3+1), -(l7+1), l6+1, l4+1};

  thehole = newreg ; 
  Volume(thehole) = theloops[t] ;

Return


x = 0 ; y = 0.75 ; z = 0 ; r = 0.09 ;

// A For loop is used to generate five holes in the cube:

For t In {1:5}

  x += 0.166 ; 
  z += 0.166 ; 

// This command calls the function CheeseHole. Note that, instead of
// defining a function, we could have define a file containing the
// same code, and used the Include command to include this file.

  Call CheeseHole ;

// A physical volume is defined for each cheese hole

  Physical Volume (t) = thehole ;
 
// The Printf function permits to print the value of variables on the
// terminal:

  Printf("The cheese hole has number %g!", thehole) ;

EndFor

// This is the surface loop for the exterior surface of the cube:

theloops[0] = newreg ;

Surface Loop(theloops[0]) = {35,31,29,37,33,23,39,25,27} ;

// The volume of the cube, without the 5 cheese holes, is defined by 6
// surface loops (the exterior surface and the five interior loops).
// To reference an array of variables, its identifier is followed by
// '[]':

Volume(186) = {theloops[]} ;

// This physical volume assigns the region number 10 to the tetrahedra
// paving the cube (but not the holes, whose elements were tagged from
// 1 to 5 in the 'For' loop)

Physical Volume (10) = 186 ;

