// original model from Zaqueu Ernesto da Silva (zaqueu at les.ufpb.br)
// rewritten by CG

lc = 3;
e = 6; // thickness
w = 30; // width
r = 15; // interior radius
c = 37.5; // half length
h = 8.75; // hole center dist
rh = 4; // home radius

Point(1) = {0, w, 0, lc};
Point(2) = {c-w/2, w, 0, lc};
Point(3) = {0, w, e, lc};
Point(4) = {c-Sqrt((r+e)^2-e^2), w, e, lc};
Point(5) = {c, w, w/2, lc};
Point(6) = {c, w, w/2+e, lc};
Point(7) = {c, w, 0, lc};
Line(1) = {1,2};
Line(2) = {3,4};
Line(3) = {1,3};
Circle(4) = {2,7,5};
Circle(5) = {4,7,6};
Symmetry {1,0,0,-c} { Duplicata { Line{1:5}; } }
Line Loop(11) = {4,-9,-6,8,7,10,-5,-2,-3,1};
Plane Surface(12) = {11};
v[] = Extrude {0,-w,0}{ Surface{12}; };
Delete { Volume{v[1]}; }
Delete { Surface{55,63,43,35}; }

Point(100) = {h, w/2, 0, lc};
Point(101) = {h+rh, w/2, 0, lc};
Point(102) = {h-rh, w/2, 0, lc};
Point(103) = {h, w/2+rh, 0, lc};
Point(104) = {h, w/2-rh, 0, lc};
Circle(65) = {101,100,103};
Circle(66) = {103,100,102};
Circle(67) = {102,100,104};
Circle(68) = {104,100,101};
Extrude {0,0,e}{ Line{65:68}; }
Symmetry {1,0,0,-c} { Duplicata { Surface{72,76,80,84}; } }

Line Loop(104) = {2,50,21,-54};
Line Loop(105) = {73,77,81,69};
Plane Surface(106) = {104,105};
Line Loop(107) = {23,-25,-1,58};
Line Loop(108) = {65,66,67,68};
Plane Surface(109) = {107,108};
Line Loop(110) = {7,42,-18,-38};
Line Loop(111) = {103,98,93,88};
Plane Surface(112) = {110,111};
Line Loop(113) = {16,-34,6,30};
Line Loop(114) = {101,86,91,96};
Plane Surface(115) = {113,114};

Surface Loop(116) = {47,-12,27,31,-115,64,39,112,85,90,95,100,51,-106,59,-109,-84,-72,-76,-80};
Volume(117) = {116};
