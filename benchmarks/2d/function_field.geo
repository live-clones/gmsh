
lc = 1;
Point(1) = {0, 0, 0, lc};
Point(2) = {1, 0,  0, lc} ;
Point(3) = {1, 1, 0, lc} ;
Point(4) = {0, 1, 0, lc} ;
Line(1) = {1,2} ;
Line(2) = {3,2} ;
Line(3) = {3,4} ;
Line(4) = {4,1} ;
Line Loop(5) = {4,1,-2,3} ;
Plane Surface(6) = {5} ;

Function Field(1) = "Cos(2*3.14*x)/5 + 0.21";
Characteristic Length Field{1};
