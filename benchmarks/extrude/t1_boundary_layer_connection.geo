lc = 0.01;
Point(1) = {0, 0, 0, lc};
Point(2) = {.1, 0,  0, lc} ;
Point(3) = {.1, .3, 0, lc} ;
Point(4) = {0,  .3, 0, lc} ;

Line(1) = {1,2} ;
Line(2) = {3,2} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;

Line Loop(5) = {4,1,-2,3} ;
Plane Surface(6) = {5} ;

Extrude { Surface{6}; Layers{5, 0.01}; Recombine; }

Point(100) = {0,  0, 0.15, lc} ;
Point(101) = {.1, 0, 0.15, lc} ;
/*
Line(100) = {8, 100};
Line(101) = {12, 101};
Line(102) = {100, 101};
Line Loop(100) = {9,101,-102,-100};
Plane Surface(100) = 100;
*/
