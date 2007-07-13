lc =0.001;
s=1;

h0 = 2.0e-3; //3.e-3;
t1 = 1.0e-3; //3.9e-3;
t2 = 1.0e-3;
Wd = 6.e-3;
R = 27.5e-3;
r = 14.0e-3;

nArc = 15;
nSeg1 =2 ; // Side of Stator and Tooth (Vertical)
nSeg2 =2 ; // Piezo
nSeg3 =6;//5 ; // Long radius 
nSeg4 =4;//3 ; // Wd

Point(1) = {0.,       0.,       0.,  lc} ;
Point(2) = {r,        0.,       0.,  lc} ;
Point(3) = {(R-Wd/2), 0.,       0.,  lc} ; 
Point(4) = {(R+Wd/2), 0.,       0.,  lc} ;

Point(5) = {0.,       0.,       t1,  lc} ;
Point(6) = {r,        0.,       t1,  lc} ;
Point(7) = {(R-Wd/2), 0.,       t1,  lc} ;
Point(8) = {(R+Wd/2), 0.,       t1,  lc} ;

Point(9) = {0.,       0.,  (t1+h0),  lc};
Point(10)={(R-Wd/2),  0.,  (t1+h0),  lc};
Point(11)={(R+Wd/2),  0.,  (t1+h0),  lc};

Point(12) = {0.,       0.,     -t2,  lc} ;
Point(13) = {r,        0.,     -t2,  lc} ;
Point(14) = {(R-Wd/2), 0.,     -t2,  lc} ;
Point(15) = {(R+Wd/2), 0.,     -t2,  lc} ;

Line(1) = {2,3} ;
Line(2) = {3,4} ;
Line(3) = {6,7} ;
Line(4) = {7,8} ; 
Line(5) = {10,11} ;

Line(6) = {13,14} ;
Line(7) = {14,15} ;
Line(8) = {2,6} ;
Line(9) = {3,7} ;
Line(10) = {4,8} ;
Line(11) = {7,10} ;
Line(12) = {8,11} ;
Line(13) = {13,2} ;
Line(14) = {14,3} ;
Line(15) = {15,4} ;

Line Loop(1) = {3,-9,-1,8}; //surface centrale
Plane Surface(2) = {1};
Line Loop(3) = {4,-10,-2,9};
Plane Surface(4) = {3};
Line Loop(5) = {5,-12,-4,11};
Plane Surface(6) = {5};
Line Loop(7) = {1,-14,-6,13};
Plane Surface(8) = {7};
Line Loop(9) = {2,-15,-7,14};
Plane Surface(10) = {9};

// 1st gap

Extrude Surface {2, {0,0,1}, {0,0,0}, Pi/180}{  Layers { 1 } ;};
Extrude Surface {4, {0,0,1}, {0,0,0}, Pi/180}{  Layers { 1 } ;};
Extrude Surface {6, {0,0,1}, {0,0,0}, Pi/180}{  Layers { 1 } ;};
Extrude Surface {8, {0,0,1}, {0,0,0}, Pi/180}{  Layers { 1 } ;};
Extrude Surface {10, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};

// 1st piezo
ne[] = {1,1,1,nArc,1,1,1};
nd[] = {0.02, 0.05, 0.09, 0.91, 0.95, 0.98, 1};
Extrude Surface {37, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{  Layers { ne[], nd[]} ;};
Extrude Surface {59, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{  Layers { ne[], nd[]} ;};
Extrude Surface {81, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{  Layers { ne[], nd[]} ;};
Extrude Surface {103, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{  Layers { ne[], nd[] } ;};
Extrude Surface {125, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{  Layers { ne[], nd[] } ;};

// 2nd gap

Extrude Surface {147, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {169, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {191, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {213, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {235, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};

// 2nd pizeo

Extrude Surface {257, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {279, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {301, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {323, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {345, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};

// 3rd gap

Extrude Surface {257+110, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {279+110, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {301+110, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {323+110, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {345+110, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};

// 3rd piezo

Extrude Surface {257+220, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {279+220, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {301+220, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {323+220, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {345+220, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};

// 4th gap

Extrude Surface {257+330, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {279+330, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {301+330, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {323+330, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};
Extrude Surface {345+330, {0,0,1}, {0,0,0}, Pi/180}{ Layers { 1 } ;};

// 4th pizeo

Extrude Surface {257+440, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {279+440, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {301+440, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {323+440, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};
Extrude Surface {345+440, {0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Layers { ne[], nd[] } ;};

PZTA = 1000;
PZTB = 1500;

Stator = 2000; 

Electrode1 = 1001;
Electrode2 = 1002;
Electrode3 = 1003;
Electrode4 = 1004;
Electrode_Upper1 = 1005;
Electrode_Upper2 = 1006;
Electrode_Upper3 = 1007;
Electrode_Upper4 = 1008;

Inner_Cylinder = 1009;

Point99 =  1010;
Point101 = 1011;
Cover = 1012;


