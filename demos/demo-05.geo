/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   Trivial 3D example

   All important comments are marked with "README"
*/

/* README: You can specify a global scaling factor for all
   characteristic lengths in the geometry with the command line option
   '-clscale'

   With -clscale 1, this example produces a mesh of 2126 Nodes and
   10221 Elements (in 3.61706 seconds on my DEC alpha 666MHz)

   With -clscale 0.2 (i.e. all characteristic lengths a divided by 5),
   this example produces a mesh of 169932 Nodes, and 1005779 (in
   1095.95 s) */

lcar1 = .1;
lcar2 = .0005;

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

Surface Loop(40) = {35,31,29,37,33,23,39,25,27};
Volume(41) = {40};

// Save volumic elements in region 1000

Physical Volume (1000) = {41} ;

// Save parts of the surface mesh in regions 2000 and 2001, e.g. to 
// impose boundary conditions

Physical Surface (2000) = {23,25,39} ;
Physical Surface (2001) = {29,31,35} ;



