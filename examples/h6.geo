h = 0.1;
h2 = 0.031;
Point(1) = { 0.00000E+00, 0.00000E+00, 0.0 , h2};
Point(2) = { 1.00000E-01, 0.00000E+00, 0.0 , h2};
Point(3) = { 0.00000E+00, 4.00000E-01, 0.00000E+00,h2};
Point(4) = { 0.00000E+00, 0.00000E+00, 0.00000E+00,h2};
Point(5) = { 1.00000E-01, 4.00000E-01, 0.00000E+00,h2};
Line(1) = Liste[1,3];
Line(2) = Liste[3,5];
Line(3) = Liste[5,2];
Line(4) = Liste[2,1];
Boucle(5) = Liste[2,3,4,1];
Zone(6) = Liste[5];

AIR = 1 ;
CLD = 2 ;
Physical Volume(AIR) = Liste [-6];
Physical Volume(CLD) = Liste [4];
