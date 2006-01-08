// fails only for lc=0.55 - otherwise works great!
lc = 0.55;
r = 2.0;
e = 0.8;
rb = r+e;
teta = 15.0*Pi/180.0;
d = 1.0;
L = r/Sin(teta);
L2 = (rb+d)/Sin(teta);
rc = rb+d;
// generatrice
Point(1) = {0, L, 0, lc};
Point(2) = {r*Cos(teta), r*Sin(teta), 0, lc};
Point(3) = {0, -r, 0, lc};
Point(4) = {0, 0, 0, lc};
Point(5) = {0, -rb, 0,lc};
Point(6) = {rb*Cos(teta), rb*Sin(teta), 0,lc};
Point(7) = {e*Cos(teta), L+e*Sin(teta), 0, lc};
Point(8) = {0, L+e, 0, lc};
Point(9) = {0, L2, 0, lc};
Point(10) = {rc*Cos(teta), rc*Sin(teta), 0, lc};
Point(11) = {0, -rc, 0, lc};

Line(1) = {6, 7};
Circle(2) = {7, 1, 8};
Line(3) = {8, 1};
Line(4) = {2, 1};
Circle(5) = {3, 4, 2};
Line(6) = {3, 5};
Circle(7) = {5, 4, 6};
Line(8) = {10,9};
Line(9) = {9,8};
Line(10) = {5,11};
Circle(11) = {11,4,10};

Line Loop(1) = {1, 2, 3, -4, -5, 6, 7};
Line Loop(2) = {8, 9, -2, -1, -7, 10, 11};
Plane Surface(1) = {1};
Plane Surface(2) = {2};
Extrude Surface {1, {0.0,1.0,0.0}, {0.0,0.0,0.0},
2*Pi/3};
Extrude Surface {38, {0.0,1.0,0.0}, {0.0,0.0,0.0},
2*Pi/3};
Extrude Surface {65, {0.0,1.0,0.0}, {0.0,0.0,0.0},
2*Pi/3};
Extrude Surface {2, {0.0,1.0,0.0}, {0.0,0.0,0.0},
2*Pi/3};
Extrude Surface {118, {0.0,1.0,0.0}, {0.0,0.0,0.0},
2*Pi/3};
Extrude Surface {145, {0.0,1.0,0.0}, {0.0,0.0,0.0},
2*Pi/3};
