/* 
   Gmsh demo file (C) 2000 C. Geuzaine, J.-F. Remacle

   Simple 3D example, with customization commands

   All important comments are marked with "README"
*/

// Definition of some variables

dxCore  =  50.e-3 ;
dyCore  =  50.e-3 ;
dzCore  = 100.e-3 ;
dxGap   =  25.e-3 ;

xInd    =  75.e-3 ;
dxInd   =  25.e-3 ;
dzInd   =  50.e-3 ;

xBox    = 200.e-3 ;

s       = 2. ;
p0      = 12.e-3 *s;
pCorex  =  6.e-3 *s;
pCorez0 =  10.e-3 *s;
pCorez  =  6.e-3 *s;
pInd0   = 6.e-3 *s;
pInd1   = 5.e-3 *s;
pBox    = xBox/6. *s;

sqr2    = 2.^0.5 ;

// Definition of points

Point(1) = { 0, 0, 0, p0} ;
Point(2) = { dxCore, 0, 0, pCorex} ;
Point(3) = { xInd, 0, 0, pInd0} ;
Point(4) = { xInd+dxInd, 0, 0, pInd0} ;
Point(5) = { xBox, 0, 0, pBox} ;

Point(6) = { dxCore, dyCore, 0, pCorex} ;
Point(7) = { dxCore+dxGap/sqr2, dxCore+dxGap/sqr2, 0, pInd0} ;
Point(8) = { dxCore+(dxGap+dxInd)/sqr2, dxCore+(dxGap+dxInd)/sqr2, 0, pInd0} ;
Point(9) = { xBox, xBox, 0, pBox} ;

Point(10) = { xInd, dyCore, 0, pInd0} ;
Point(11) = { xInd+dxInd, dyCore, 0, pInd0} ;


Point(101) = { 0, 0, dzCore, pCorez0} ;
Point(102) = { dxCore, 0, dzCore, pCorez} ;
Point(106) = { dxCore, dyCore, dzCore, pCorez} ;

Point(103) = { xInd, 0, dzInd, pInd1} ;
Point(104) = { xInd+dxInd, 0, dzInd, pInd1} ;
Point(107) = { dxCore+dxGap/sqr2, dxCore+dxGap/sqr2, dzInd, pInd1} ;
Point(108) = { dxCore+(dxGap+dxInd)/sqr2, dxCore+(dxGap+dxInd)/sqr2, dzInd, pInd1} ;
Point(110) = { xInd, dyCore, dzInd, pInd1} ;
Point(111) = { xInd+dxInd, dyCore, dzInd, pInd1} ;

Point(116) = { dxCore, dyCore, dzInd, p0} ;

Point(201) = { 0, 0, xBox, pBox} ;
Point(205) = { xBox, 0, xBox, pBox} ;
Point(209) = { xBox, xBox, xBox, pBox} ;

// Definition of lines

Line(1) = {1,2};  Line(2) = {2,3};   Line(3) = {3,4};
Line(4) = {4,5};  Line(5) = {5,9};   Line(6) = {1,6};
Line(7) = {6,7};  Line(8) = {7,8};   Line(9) = {8,9};
Line(10) = {2,6}; Line(11) = {3,10}; Line(12) = {4,11};

/* README: A circle is always defined counter-clockwise (i.e.
   trigonometric), and specified by 3 points: starting,
   center and end point. Note that these 3 points can not be
   aligned and that the interior angle should be less than 180
   degrees. */

Circle(13) = {10,6,7}; Circle(14) = {11,6,8};

// Some more lines and circles

Line(15) = {101,102}; Line(16) = {102,106};  Line(17) = {101,106};
Line(18) = {1,101};   Line(19) = {101,201};  Line(20) = {201,205};
Line(21) = {201,209}; Line(22) = {205,209};  Line(23) = {103,104};
Line(24) = {103,110}; Line(25) = {104,111};  Line(26) = {107,108};

Circle(27) = {110,116,107};
Circle(28) = {111,116,108};

Line(29) = {2,102};   Line(30) = {6,106};    Line(31) = {3,103};
Line(32) = {4,104};   Line(33) = {10,110};   Line(34) = {11,111};
Line(35) = {7,107};   Line(36) = {8,108};    Line(37) = {5,205};
Line(38) = {9,209};

/* README: Definition of lines loops and plane surfaces. Note that
   there are no internal loops in these surfaces (only one line loop
   per surface) */

Line Loop(39) = {-22,-37,5,38};         Plane Surface(40) = {39};
Line Loop(41) = {-22,-20,21};           Plane Surface(42) = {41};
Line Loop(43) = {-10,-1,6};             Plane Surface(44) = {43};
Line Loop(45) = {7,-13,-11,-2,10};      Plane Surface(46) = {45};
Line Loop(47) = {23,-32,-3,31};         Plane Surface(48) = {47};
Line Loop(49) = {13,8,-14,-12,-3,11};   Plane Surface(50) = {49};
Line Loop(51) = {14,9,-5,-4,12};        Plane Surface(52) = {51};
Line Loop(53) = {-29,-1,18,15};         Plane Surface(54) = {53};
Line Loop(55) = {17,-30,-6,18};         Plane Surface(56) = {55};
Line Loop(57) = {-16,-29,10,30};        Plane Surface(58) = {57};
Line Loop(59) = {-16,-15,17};           Plane Surface(60) = {59};
Line Loop(61) = {-24,-31,11,33};        Plane Surface(62) = {61};
Line Loop(63) = {-25,-32,12,34};        Plane Surface(64) = {63};
Line Loop(65) = {26,-36,-8,35};         Plane Surface(66) = {65};
Line Loop(67) = {27,26,-28,-25,-23,24}; Plane Surface(68) = {67};
Line Loop(69) = {-23,-31,-2,29,-15,19,20,-37,-4,32};
                                        Plane Surface(70) = {69};
Line Loop(71) = {-26,-35,-7,30,-17,19,21,-38,-9,36};
                                        Plane Surface(72) = {71};

/* README: Definition of ruled surfaces. Ruled surfaces must have 3 or
   4 borders (not more, not less). */

Line Loop(73) = {-27,-33,13,35};
Ruled Surface(74) = {73};

Line Loop(75) = {-28,-34,14,36};
Ruled Surface(76) = {75};

// Definition of volumes

Surface Loop(77) = {60,-58,54,-44,-56};
Volume(78) = {77};

Surface Loop(79) = {64,-68,-74,-62,-48,50,66,76};
Volume(80) = {79};

Surface Loop(81) = {64,-68,-74,-62,70,-46,-72,58,-60,42,-40,-52,76};
Volume(82) = {81};

// Some definitions for saving the mesh

Physical Volume (500) = {82} ;
Physical Volume (501) = {78} ;
Physical Volume (502) = {80} ;

Physical Surface (1000) = {40,42} ;
Physical Surface (1001) = {44,46,50,52} ;
Physical Surface (1002) = {70,72,54,56,48,66} ;

Physical Surface (602) = {68,74,62,76,64} ;
Physical Surface (700) = {44,46} ;

Physical Surface (710) = {48} ;
Physical Surface (711) = {66} ;

/* README: most visual parameters can be redefined. Post-processing
   color definitions are made interactively (or loaded at startup in
   an appropriate file, see the interactive help of the color
   widget). GUI colors and fonts can be changed in a standard X
   resource file (.gmshrc in your home directory). */

General.Color.Background = {39, 64, 139} ;
General.Color.Axes =  OrangeRed1; // Color names are the classical X11 names
General.Color.SmallAxes = LightGray;
General.Color.Text = Gray88 ;

Geometry.Color.Points = Yellow;
Geometry.Color.Lines = {255, 255, 255, 128} ; // semi-transparent white
Geometry.Color.Surfaces = {Orange, 60} ; // almost transparent orange
Geometry.Color.Volumes = Green ;
Geometry.Color.PointsSelect = White ;
Geometry.Color.LinesSelect = White ;
Geometry.Color.SurfacesSelect = White ;

Mesh.Color.Points = Black;
Mesh.Color.PointsSupp = Orchid;
Mesh.Color.Lines = Black;
Mesh.Color.One = Gray10 ;
Mesh.Color.Two = Gray20 ;
Mesh.Color.Three = Gray30 ;
Mesh.Color.Four = Gray40 ;
Mesh.Color.Five = Gray50 ;
Mesh.Color.Six = Gray60 ;
Mesh.Color.Seven = Gray70 ;
Mesh.Color.Eight = Gray80 ;
Mesh.Color.Nine = Gray90 ;
Mesh.Color.Ten = Black ;

/* README: X resources can be specified in a '.gmshrc' in your home
   directory or app-defaults directory, or in your .Xdefaults file.
   Here are some default values for the 2 main windows:

   ! Graphic window
   gmshGW*geometry: 700x525+20+30
   gmshGW*fontList: fixed
   gmshGW*background: Grey65
   gmshGW*borderColor: Grey65
   gmshGW*foreground: Black
   gmshGW*highlightColor: Grey66
   
   ! Menu window
   gmshMW*geometry: x525+800+30
   gmshMW*fontList: fixed
   gmshMW*background: Grey65
   gmshMW*borderColor: Grey65
   gmshMW*foreground: Black
   gmshMW*XmText*background: Grey75
   gmshMW*XmText*foreground: Black
   gmshMW*XmTextField*background: Grey75
   gmshMW*XmList*background: Grey75
   gmshMW*selectColor: Yellow
   gmshMW*highlightColor: DarkOrchid 

   Use 'editres' to get the full widget tree and associated resources.
*/
