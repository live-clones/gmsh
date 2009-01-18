// Gmsh project created on Tue Aug  5 18:29:53 2008
r1 = 0.025;     // device radius

h  = 0.01;       // duct height
dh1 = 3*h/10;    // Describe how the duct is split.
dh2 = 2*h/10;
dh3 = 2*h/10;
dh4 = 3*h/10;
mh1 = 3; ph1 = 1; // top quarter duct, vertical mesh count and progression
mh2 = 2; ph2 = 1; //  2nd quarter duct vertical mesh count and progression
mh3 = 2; ph3 = 1; // 3rd quarter duct vertical mesh count and progression
mh4 = 3; ph4 = 1; // 4th / bottom quarter duct vertical mesh count and progression

mr = 8; // mesh density used throughout most of the mesh.
// 'notlinked' sets the mesh starting from upper surface, moving around the outer
// perimeter.  The mesh count is one less than, 'notlinked'.
notlinked = 4;

f  = 40000;      // interest freq
c  = 344;        // celerity
lc = (1/4)*c/f;  //characteristic length for all nodes as function of freq.  Mesh density
s  = 1;          // characteristic length scalar for internal regions.

// Middle surface; extrude from here, up and down.=========================NODES
Point (1) =    {       0     , 0       ,       0 ,  lc/s};    // centre

// Perimeter.
For i In {0:7:1}
   Point(i + 11) = {r1*Cos(2 * Pi * i / 8), 0, r1*Sin(2 * Pi * i / 8), lc/s};
EndFor

// Corners for inner square
t = 0.9;  // bodge to scale inner square to improve element quality.
Point(21) = {t*r1/2,  0,  t*0, lc/s};
Point(22) = {t*r1/2,  0,  t*r1/2, lc/s};
Point(23) = {t*0,     0,  t*r1/2, lc/s};
Point(24) = {-t*r1/2, 0,  t*r1/2, lc/s};
Point(25) = {-t*r1/2, 0,  t*0, lc/s};
Point(26) = {-t*r1/2, 0, -t*r1/2, lc/s};
Point(27) = {t*0,     0, -t*r1/2, lc/s};
Point(28) = {t*r1/2,  0, -t*r1/2, lc/s};

// Interface region. ======================================================NODES
// Centre
// Point(1001) = {r1,  0, 0, lc/s};

// Outer perimeter 
// Perimeter nodes.  From top, up.
For i In {0:4:1}
   Point(1011 + i) = {r1 + h/2*Cos(-Pi/2 + 2 * Pi * i / 8),
      h/2 * Sin(-Pi/2 + 2 * Pi * i / 8), 0, lc/s};
EndFor

// Inner square parts.  Link to extrusions above.
t = 0.9;  // bodge to scale inner square to improve element quality.
Point(1021) = {r1 + 0,       -h/2 + dh4, 0, lc/s};
Point(1022) = {r1 + t * h/4, -h/2 + dh4, 0, lc/s};
Point(1023) = {r1 + t * h/4,    0, 0, lc/s};
Point(1024) = {r1 + t * h/4,  h/2 - dh1, 0, lc/s};
Point(1025) = {r1 + 0,        h/2 - dh1, 0, lc/s};

// Circle creation. =====================================================Circles
l = 1;      // line numbers start from.....
For i In {0:6:1}
   Circle(l)      = { 11 + i , 1, 11 + i + 1};    l = l +1;
EndFor
// close the loop, from node 18 to 11, centre node 1.
Circle(l) = {18, 1, 11};  l = l + 1;

// Interface
l = 11;      // line numbers start from.
For i In {0:3:1}
   Circle(l)      = { 1011 + i , 11, 1011 + i + 1};    l = l +1;
EndFor

// Square creation.  Duct. ==============================================Squares
l = 21;
For i In {0:6:1}
   Line(l)   = {21 + i, 22 + i}; l = l + 1;
EndFor
Line(l)   = {28, 21}; l = l + 1;

// Interface
l = 41;
For i In {0:3:1}
   Line(l)   = {1021 + i, 1022 + i}; l = l + 1;
EndFor

// Lines radiating from square to perimeter. Duct==========================Lines
l=51;
For i In {0:7:1}
   Line(l)   = {21 + i, 11 + i}; l = l + 1;
EndFor

// Lines radiating out from centre point.
Line(61) = {1, 21};
Line(63) = {1, 23};
Line(65) = {1, 25};
Line(67) = {1, 27};

// Interface

l=71;
For i In {0:4:1}
   Line(l)   = {1021 + i, 1011 + i}; l = l + 1;
EndFor

// Lines radiating out from centre point.
Line(81) = {11, 1021};
Line(83) = {11, 1023};
Line(85) = {11, 1025};

// Define closed loops and planes for the shapes just created.  These were
// selected in GMSH, rather than in the script as the negative values control
// the direction of the path. ============================================Planes
// Duct.
Line Loop(86) = {28,-61,67,27};
Plane Surface(87) = {86};
Line Loop(88) = {67,-26,-25,-65};
Plane Surface(89) = {88};
Line Loop(90) = {63,23,24,-65};
Plane Surface(91) = {90};
Line Loop(92) = {21,22,-63,61};
Plane Surface(93) = {92};
Line Loop(94) = {51,-8,-58,28};
Plane Surface(95) = {94};
Line Loop(96) = {58,-7,-57,27};
Plane Surface(97) = {96};
Line Loop(98) = {57,-6,-56,26};
Plane Surface(99) = {98};
Line Loop(100) = {56,-5,-55,25};
Plane Surface(101) = {100};
Line Loop(102) = {55,-4,-54,24};
Plane Surface(103) = {102};
Line Loop(104) = {54,-3,-53,23};
Plane Surface(105) = {104};
Line Loop(106) = {53,-2,-52,22};
Plane Surface(107) = {106};
Line Loop(108) = {52,-1,-51,21};
Plane Surface(109) = {108};
// Interface
Line Loop(110) = {71,11,-72,-41};
Plane Surface(111) = {110};
Line Loop(112) = {12,-73,-42,72};
Plane Surface(113) = {112};
Line Loop(114) = {73,13,-74,-43};
Plane Surface(115) = {114};
Line Loop(116) = {74,14,-75,-44};
Plane Surface(117) = {116};
Line Loop(118) = {81,41,42,-83};
Plane Surface(119) = {118};
Line Loop(120) = {85,-44,-43,-83};
Plane Surface(121) = {120};
//
// The following code is required to make the mesh ordered =====================
//
// Set the lines above, as 'transfinite'.  Duct (setting most of the mesh):
Transfinite Line{1,2,3,4,5,6,7,8} = mr + 1 Using Progression 1.0;  // duct perim
Transfinite Line{21,22,23,24,25,26,27,28} = mr + 1 Using Progression 1.0; // square
Transfinite Line{51,52,53,54,55,56,57,58} = mr + 1 Using Progression 1.0; // radiate
Transfinite Line{61,63,65,67} = mr + 1 Using Progression 1.0; // radiate

// Interface.  Different pattern from duct.
// Moving down, from upper edge next to upper boundary layer in duct.  unlinked.

Transfinite Line{14,44,83,41, 11} = notlinked Using Progression 1.0; 
// moving around curve.
Transfinite Line{71, 72, 73, 74, 75} = mh1+1 Using Progression 1.0;
// moving out, from upper central duct.
Transfinite Line{85, 43, 13} = mh2+1 Using Progression 1.0;
// moving out from lower central duct.
Transfinite Line{81, 42, 12} = mh3+1 Using Progression 1.0;

// Create new, 'transfinite' surfaces.  Matching surface numbers above and
// referencing same node numbers.  Had to inspect
// these from gmsh.  Note, curly brackets, not parentheses.
//            {surface} = {nodes}
Transfinite Surface{87:121:2};

// Without the following recombine, the elements are tri primative.
// Duct.
Recombine Surface{87:121:2};

// End of extra code to get ordered mesh ***************************************
//
// Extrusion.  To this point, the mesh is a 2D disc in the duct plane (to be
// extruded vertically to form the duct thickness), with a
// perpendicular disc at it's edge, to be extruded around to form the interface
// region.

// Extrude {vector} { Surface{n}; Layers{mz} ; Recombine; }
// with surface number(s) n extruded, mesh density mz1.
// Assign result to var[], to allow further work with the new surface, in var[0]
// Entries 0 to 5 are returned for these extruded faces, so steps of 6 to 
// get the faces for different volumes appended to the list.
//
// Extrude to form duct thickness: -------------------------
// upper middle.
num[] = Extrude { 0, dh2, 0} {
           Surface {
              87, 89, 91, 93, 95, 97, 99, 101, 103, 105, 107, 109
              };
           Layers{mh2}; Recombine; 
           };
// top (boundary layer region)
num[] = Extrude { 0, dh1, 0} { 
           Surface{num[0], num[6*1], num[6*2], num[6*3], num[6*4], num[6*5], 
              num[6*6], num[6*7], num[6*8], num[6*9], num[6*10], num[6*11]}; 
           Layers{mh1}; 
           Recombine; 
           };
//lower middle
num[] = Extrude { 0, -dh3, 0} {
           Surface {
              87, 89, 91, 93, 95, 97, 99, 101, 103, 105, 107, 109
              };
           Layers{mh3}; Recombine; 
           };
// bottom boundary layer.
num[] = Extrude {0, -dh4,0} { 
           Surface{
              num[0], num[6*1], num[6*2], num[6*3], num[6*4], num[6*5], 
              num[6*6], num[6*7], num[6*8], num[6*9], num[6*10], num[6*11] 
              };
           Layers{mh4}; Recombine; 
           };
// The duct is now thick.  ---------------------------------

// Interface.  First extrusion segment.
num[] = Extrude {{ 0, 1, 0}, {0, 0, 0}, Pi/4} {
          Surface {
             111, 113, 115, 117, 119, 121
             };
          Layers{mr}; Recombine; 
          };

// Repeat, around the rest of the interface.
For i In {0:6:1}
   num[] = Extrude {{ 0, 1, 0}, {0, 0, 0}, Pi/4} {
         Surface{num[0], num[6*1], num[6*2], num[6*3], num[6*4], num[6*5]}; 
         Layers{mr}; 
         Recombine; 
         };
EndFor
