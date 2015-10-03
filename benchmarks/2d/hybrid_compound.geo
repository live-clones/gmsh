Merge "hybrid_part.msh";
CreateTopology;

Compound Line(100) = {14};
Compound Surface(101) = {16};

lc = 1e-2;
Point(1) = {0, 0, 0, lc};
Point(4) = {0, .3, 0, lc} ;

Line(1) = {1,11} ;
Line(3) = {14,4} ;
Line(4) = {4,1} ;

Line Loop(5) = {-4,-1,100,-3} ;
Plane Surface(6) = {5} ;
