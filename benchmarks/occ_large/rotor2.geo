SetFactory("OpenCASCADE");
mm = 1.e-3 ;
deg = Pi / 180. ;
lc = mm * 15. ;

Rext = 1150. / 2. * mm ;
ep = 30. * mm ;

// aubes
la = 150. * mm ;
ra = 75. * mm ;
ha = 250 * mm ;
aout = 25. * deg ;
ain = 56. * deg ;
nba =24;

x1 = 0.; y1 = 0. ; z1 = ep ;
x2 = x1 + 0.; y2 = y1 +  Rext ; z2 = z1;
x3 = x2 - la * Cos(aout); y3 = y2  -la * Sin(aout) ; z3 = z1 ;
x4 = x3 + ra * Sin(aout); y4 = y3 - ra * Cos(aout) ; z4 = z1 ;
x5 = x4 - ra * Sin(aout+ain) ; y5 = y4 + ra * Cos(aout+ain) ; z5 =z1;
x6 = x5 + ep * Sin(aout+ain) ; y6 = y5 - ep * Cos(aout+ain) ; z6 =z1;
x7 = x3 + ep * Sin(aout) ; y7 = y3 - ep * Cos(aout) ; z7 =z1;
x8 = x2 + ep * Sin(aout) ; y8 = y2 - ep * Cos(aout) ; z8 =z1;
x9 = x1 + Rext ; y9 = x1 ; z9 = z1 ;
x10 = x1 ; y10 = x1 + Rext ; z10 = z1 ;
x11 = x1 - Rext ; y11 = x1 ; z11 = z1 ;
x12 = x1 ; y12 = x1 - Rext ; z12= z1 ;


Point(1) = {x1,y1,z1, lc} ;
Point(2) = {x2,y2,z2, lc} ;
Point(3) = {x3,y3,z3, lc} ;
Point(4) = {x4,y4,z4, lc} ;
Point(5) = {x5,y5,z5, lc} ;
Point(6) = {x6,y6,z6, lc} ;
Point(7) = {x7,y7,z7, lc} ;
Point(8) = {x8,y8,z8, lc} ;
Point(9) = {x9,y9,z9, lc} ;
Point(10) = {x10,y10,z10, lc} ;
Point(11) = {x11,y11,z11, lc} ;
Point(12) = {x12,y12,z12, lc} ;


Line(1) = {2,3} ; Circle(2) = {3,4,5};
Line(3) = {5,6} ; Circle(4) = {6,4,7};
Line(5) = {7,8} ; Line(6) = {8,2} ;
Curve Loop(1) = {1,2,3,4,5,6};


Circle(7) = {9,1,10};Circle(8) = {10,1,11};
Circle(9) = {11,1,12};Circle(10) = {12,1,9};
Curve Loop(2) = {7,8,9,10};


Plane Surface(1) = {1};
For i In {1:nba-1}
     Rotate {{0, 0, 1}, {0, 0,z1}, 2.*Pi/nba*i} { Duplicata { Surface{1} ; } }
EndFor
allSurfaces[] = Surface "*";
Extrude {0, 0, ha-2*ep} { Surface{ allSurfaces[]  } ; }

s = news;
Plane Surface(s) = {2};
Extrude {0, 0, -ep} { Surface{ s  };}

Coherence; // fragments everything

Mesh.Algorithm = 6;
