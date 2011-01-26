Point(1) =  {0,0,0,0.1}; 
Point(2) =  {1,0,0,0.1}; 
Point(3) =  {0,0,1,0.1}; 
Point(4) =  {1,0,1,0.1}; 
Line(1) = {1, 2}; 

Line(2) = {1, 3};
Line(3) = {3, 4};
Line(4) = {4, 2};
Line Loop(5) = {1, -4, -3, -2};
Plane Surface(6) = {5};

tmp1[] = Extrude { Surface{6}; Layers{5, 0.1}; Recombine; Using Index[0]; };
tmp2[] = Extrude { Surface{-6}; Layers{5, 0.1}; Recombine; Using Index[1]; };
