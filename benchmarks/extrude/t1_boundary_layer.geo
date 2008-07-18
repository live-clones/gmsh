lc = 0.05;
Point(1) = {0, 0, 0, lc};
Point(2) = {.1, 0,  0, lc} ;
Point(3) = {.1, .3, 0, lc} ;
Point(4) = {0,  .3, 0, lc} ;
Point(5) = {.1, 0, .2, lc} ;
Point(6) = {0,  0, .2, lc} ;

Line(1) = {1,2} ;
Line(2) = {3,2} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;
Line(5) = {2,5};
Line(6) = {5,6};
Line(7) = {6,1};

Line Loop(5) = {4,1,-2,3} ;
Plane Surface(6) = {5} ;

// this is ok, but not always possible (e.g. if the surface had been
// created automatically by extrusion)
//Line Loop(7) = - {5,6,7,1};
Line Loop(7) = {5,6,7,1};

Plane Surface(8) = {7};

// the minus sign inverts the orientation of surface 8
Extrude { Surface{6, -8}; Layers{5, 0.01}; Recombine; }
