lc = 0.007 ;
Point(1) = {0,  0,  0, 9.e-1 * lc} ;
Point(2) = {.1, 0,  0, lc} ;
Point(3) = {.1, .3, 0, lc} ;
Point(4) = {0,  .3, 0, lc} ;

//Line(1) = {1,2} ;
//Line(2) = {3,2} ;
//Line(3) = {3,4} ;
//Line(4) = {4,1} ;

//Line Loop(5) = {4,1,-2,3} ;
//Plane Surface(6) = {5} ;

Line(101) = {2,4};
Line(102) = {1,3};

Intersect;


