C = 0.6;
Lup = 0.6;
L = 0.6;
lc = .05;

Point(1) = {0.0, 0.0, -Lup, lc};
Point(2) = {C  , 0.0, -Lup, lc};
Point(3) = {C  , C  , -Lup, lc};
Point(4) = {0.0, C  , -Lup, lc};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};


Line Loop(4) = {1,2,3,4};
Plane Surface(5) = {4};

Extrude {0,0,L} {
  Surface{5};
}

Physical Surface("inlet") = {5};
Physical Surface("outlet") = {27};
Physical Surface("wall") = {14,22};
Physical Surface("symmetry") = {26,18};
Physical Volume("volume") = {1};
