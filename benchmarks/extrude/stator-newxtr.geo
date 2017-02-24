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

rec = DefineNumber[1, Choices{0,1}, Name "Recombine?" ];

// 1st gap

Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {2}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {4}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {6}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {8}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {10}; Recombine rec; Layers { 1 } ;}

// 1st piezo
ne[] = {1,1,1,nArc,1,1,1};
nd[] = {0.02, 0.05, 0.09, 0.91, 0.95, 0.98, 1};
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {37};  Recombine rec; Layers { ne[], nd[]} ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {59};  Recombine rec; Layers { ne[], nd[]} ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {81};  Recombine rec; Layers { ne[], nd[]} ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {103}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {125}; Recombine rec; Layers { ne[], nd[] } ;}

// 2nd gap

Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {147}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {169}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {191}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {213}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {235}; Recombine rec; Layers { 1 } ;}

// 2nd pizeo

Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {257}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {279}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {301}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {323}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {345}; Recombine rec; Layers { ne[], nd[] } ;}

// 3rd gap

Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {257+110}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {279+110}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {301+110}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {323+110}; Recombine rec; Layers { 1 } ;}
Extrude {{0,0,1}, {0,0,0}, Pi/180}{ Surface {345+110}; Recombine rec; Layers { 1 } ;}

// 3rd piezo

Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {257+220}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {279+220}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {301+220}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {323+220}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {345+220}; Recombine rec; Layers { ne[], nd[] } ;}

// 4th gap

Extrude  {{0,0,1}, {0,0,0}, Pi/180}{ Surface {257+330}; Recombine rec; Layers { 1 } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/180}{ Surface {279+330}; Recombine rec; Layers { 1 } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/180}{ Surface {301+330}; Recombine rec; Layers { 1 } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/180}{ Surface {323+330}; Recombine rec; Layers { 1 } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/180}{ Surface {345+330}; Recombine rec; Layers { 1 } ;}

// 4th pizeo

Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {257+440}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {279+440}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {301+440}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {323+440}; Recombine rec; Layers { ne[], nd[] } ;}
Extrude  {{0,0,1}, {0,0,0}, Pi/2-Pi/180}{ Surface {345+440}; Recombine rec; Layers { ne[], nd[] } ;}

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
