// an example of a purely hexahedral mesh

lc = 0.3;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {1,1,0.0,0.5*lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};

Transfinite Line{1:4} = 5;
Transfinite Surface{6} = {1,2,3,4};
Recombine Surface{6};
Extrude Surface { 6, {0,0.0,1} } { Layers{5,1}; Recombine;};
