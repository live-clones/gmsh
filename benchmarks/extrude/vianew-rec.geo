// characteristic lengths for the domain:
L = 0.25; // feature width
A = 4.0; // aspect ratio

// characteristic lengths:
lcbot = L / 4;
lclev = L / 4;
lctop = L / 2;

/*** Points: ***/

// Points on surface level (z = 0.0):
// points along x-axis (y = 0):
Point( 1) = {0.0*L, 0.0*L,   0.0, lclev};
Point( 2) = {1.5*L, 0.0*L,   0.0, lclev};
Point( 3) = {2.5*L, 0.0*L,   0.0, lclev};
Point( 4) = {4.0*L, 0.0*L,   0.0, lclev};
// points along x = L:
Point( 5) = {4.0*L, 1.5*L,   0.0, lclev};
Point( 6) = {4.0*L, 2.5*L,   0.0, lclev};
Point( 7) = {4.0*L, 4.0*L,   0.0, lclev};
// points along y = L:
Point( 8) = {2.5*L, 4.0*L,   0.0, lclev};
Point( 9) = {1.5*L, 4.0*L,   0.0, lclev};
Point(10) = {0.0*L, 4.0*L,   0.0, lclev};
// points along y-axis (x = 0):
Point(11) = {0.0*L, 2.5*L,   0.0, lclev};
Point(12) = {0.0*L, 1.5*L,   0.0, lclev};
// points in the interior:
Point(13) = {1.5*L, 1.5*L,   0.0, lclev};
Point(14) = {2.5*L, 1.5*L,   0.0, lclev};
Point(15) = {2.5*L, 2.5*L,   0.0, lclev};
Point(16) = {1.5*L, 2.5*L,   0.0, lclev};

/*** Lines: ***/
// lines along the outside:
Line( 1) = { 1,  2};
Line( 2) = { 2,  3};
Line( 3) = { 3,  4};
Line( 4) = { 4,  5};
Line( 5) = { 5,  6};
Line( 6) = { 6,  7};
Line( 7) = { 7,  8};
Line( 8) = { 8,  9};
Line( 9) = { 9, 10};
Line(10) = {10, 11};
Line(11) = {11, 12};
Line(12) = {12,  1};
// lines along the inside:
Line(13) = {13, 14};
Line(14) = {14, 15};
Line(15) = {15, 16};
Line(16) = {16, 13};
// lines connecting inside and outside:
Line(17) = { 2, 13};
Line(18) = { 3, 14};
Line(19) = { 5, 14};
Line(20) = { 6, 15};
Line(21) = { 8, 15};
Line(22) = { 9, 16};
Line(23) = {11, 16};
Line(24) = {12, 13};

Line Loop(25) = {  1,  17, -24,  12}; Ruled Surface(26) = {25};
Line Loop(27) = {  2,  18, -13, -17}; Ruled Surface(28) = {27};
Line Loop(29) = {  3,   4,  19, -18}; Ruled Surface(30) = {29};
Line Loop(31) = {  5,  20, -14, -19}; Ruled Surface(32) = {31};
Line Loop(33) = {  6,   7,  21, -20}; Ruled Surface(34) = {33};
Line Loop(35) = {  8,  22, -15, -21}; Ruled Surface(36) = {35};
Line Loop(37) = {  9,  10,  23, -22}; Ruled Surface(38) = {37};
Line Loop(39) = { 11,  24, -16, -23}; Ruled Surface(40) = {39};
Line Loop(41) = { 13,  14,  15,  16}; Ruled Surface(42) = {41};

// number of points on lines
NPint = 4; // number of points on interior lines
NPout = 4; // number of points on outside lines

Transfinite Line {13, 14, 15, 16, 2, 5, 8, 11} = NPint;
Transfinite Line {1,3,4,6,7,9,10,12,17,18,19,20,21,22,23,24} = NPout;
Transfinite Surface {26} = {  1,  2, 13, 12};
Transfinite Surface {28} = {  2,  3, 14, 13};
Transfinite Surface {30} = {  3,  4,  5, 14};
Transfinite Surface {32} = {  5,  6, 15, 14};
Transfinite Surface {34} = {  6,  7,  8, 15};
Transfinite Surface {36} = {  15, 16, 9, 8};
//Transfinite Surface {36} = {  8,  9, 16, 15}; causes swapping to fail in non-recombined case...
Transfinite Surface {38} = {  9, 10, 11, 16};
Transfinite Surface {40} = { 11, 12, 13, 16};
Transfinite Surface {42} = { 13, 14, 15, 16};

Recombine Surface {26,28,30,32,34,36,38,40,42};

// number of layers:
NLdn = 8;
NLup = 3;

// extrude down first:
Extrude {0,0,-A*L} {
  Surface{42};
  Layers { {NLdn}, {9001}, {1} } ; 
  Recombine;
}

// extrude up second:
Extrude {0,0,L} {
  Surface { 26:42:2 };
  Layers { {NLup}, {9000}, {1} }; 
  Recombine;
}

// wafer surface including surfaces that are extruded downwards:
Physical Surface(1001) = {26,28,30,32,34,36,38,40, 51,55,59,63,64};
Physical Surface(1009) = {73,95,117,121,139,161,165,183,205,209,227,85, 86,108,130,152,174,196,218,240,262};
Physical Volume(2001)  = {9000,9001};
