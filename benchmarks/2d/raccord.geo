Include "raccord.phy";
r1 = 30.; h1 = 100.; h2 = 150.; al0 = 30.;
al1 = al0 / 180. * 3.1415;
dd1 = 3.;
Point(1) = {0,0,0,dd1};
Point(2) = {r1,0,0,dd1};
Point(3) = {0,0,r1 / Sin(al1),dd1};
Point(4) = {0,r1,(r1 / Tan(al1)) - (r1 / Sin(al1)),dd1};
Point(5) = {0.,0,(-1 * h1),dd1};
Point(6) = {r1,0,(-1 * h1),dd1};
Point(7) = {0,r1,(-1 * h1),dd1};
Point(8) = {0.,h2 * Sin(al1),h2 * Cos(al1),dd1};
Point(9) = {r1,h2 * Sin(al1),h2 * Cos(al1),dd1};
Point(10) = {0.,(h2 * Sin(al1))-(r1*Cos(al1)),(h2 * Cos(al1))+(r1*Sin(al1)),dd1};
Point(11) = {0.,(h2 * Sin(al1))+(r1*Cos(al1)),(h2 * Cos(al1))-(r1*Sin(al1)),dd1};
Ellipsis(1) = {3,1,3,2};
Ellipsis(2) = {2,1,4,4};
Circle(3) = {7,5,6};
Line(4) = {4,7};
Line(5) = {2,6};
Line Loop(6) = {2,4,3,-5};
Ruled Surface(7) = {6};
Circle(8) = {10,8,9};
Circle(9) = {9,8,11};
Line(10) = {10,3};
Line(11) = {9,2};
Line(12) = {11,4};
Line Loop(13) = {-2,-11,9,12};
Ruled Surface(14) = {13};
Line Loop(15) = {-1,-10,8,11};
Ruled Surface(16) = {15};
//Recombine Surface{7,14,16};
Symmetry { 0,1,0,0 } {
  Duplicata { Surface{14}; }
}
Symmetry { 0,1,0,0 } {
  Duplicata { Surface{16}; }
}
Symmetry { 0,1,0,0 } {
  Duplicata { Surface{7}; }
}
Symmetry { 1,0,0,0 } {
  Duplicata { Surface{16}; }
}
Symmetry { 1,0,0,0 } {
  Duplicata { Surface{14}; }
}
Symmetry { 1,0,0,0 } {
  Duplicata { Surface{17}; }
}
Symmetry { 1,0,0,0 } {
  Duplicata { Surface{22}; }
}
Symmetry { 1,0,0,0 } {
  Duplicata { Surface{7}; }
}
Symmetry { 1,0,0,0 } {
  Duplicata { Surface{26}; }
}
Physical Surface(5600) = {39,43,22,17,30,35,14,16,52,26,7,47};
Physical Line(5700) = {50,3,29,55};
Physical Line(5800) = {42,46,25,20};
Physical Line(5900) = {33,8,9,38};
