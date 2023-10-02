Merge "hybrid_part.msh";

Point(5) = {.3, 0, 0};
Point(6) = {.3,  .3, 0} ;

Line(5) = {2,5};
Line(6) = {5,6};
Line(7) = {6,3};

Line Loop(2) = {5, 6, 7, -2} ;
Plane Surface(2) = {2} ;
