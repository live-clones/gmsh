lc = 0.1 ;
lc2 = lc * 5 ;
Point(1) =  {0,0,0,lc}; 
Point(2) =  {1,0,0,lc}; 
Point(3) =  {0,1,0,lc}; 
Point(4) =  {-1,0,0,lc}; 
Point(5) =  {0,-1,0,lc}; 

Circle(1) = {2, 1, 3}; 
Circle(2) = {3, 1, 4}; 
Circle(3) = {4, 1, 5}; 
Circle(4) = {5, 1, 2}; 

d=4;
Point(1000) = {d,d,0,lc2};
Point(1001) = {-d,d,0,lc2};
Point(1002) = {-d,-d,0,lc2};
Point(1003) = {d,-d,0,lc2};
Line(5) = {1000,1001};
Line(6) = {1001,1002};
Line(7) = {1002,1003};
Line(8) = {1003,1000};

tmp[] = Extrude { Line{1:4}; Layers{5, 0.1}; Recombine; };

Line Loop(9) = {6,7,8,5};
Line Loop(10) = {tmp[0],tmp[4],tmp[8],tmp[12]};
Plane Surface(11) = {9,10};
