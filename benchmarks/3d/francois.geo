r = 2.24; 
Point(1) = {0.0,0.0,0.0,.2};   
Point(2) = {r,.0,0.0,.2};   
Point(3) = {-r,0.0,0.0,.2};   
Point(4) = {0,r,0.0,.2};   
Point(5) = {0,-r,0.0,.2};   
Circle(1) = {2,1,4};   
Circle(2) = {4,1,3};   
Circle(3) = {3,1,5};   
Circle(4) = {5,1,2};   
Point(6) = {10,10,0.0,1};   
Point(7) = {-10,10,0.0,1};   
Point(8) = {-10,-10,0.0,1};   
Point(9) = {10,-10,0.0,1};   
Line(5) = {8,7};   
Line(6) = {7,6};   
Line(7) = {6,9};   
Line(8) = {9,8};   
Line Loop(9) = {6,7,8,5};   
Line Loop(10) = {4,1,2,3};   
Plane Surface(11) = {9,10};   
Extrude Surface {11, {0,0.0,2.0}}
{
   Layers { {2,1,2} , {100,200,100} , {.05,.95,1.} } ;
};
Coherence; 
Physical Surface(54) = {53};
Physical Surface(55) = {11};
Physical Surface(56) = {40,44,48,52};
Physical Surface(57) = {53};

//Surface Loop(58) = {53,24,11,28,32,36,40,44,48,52};
//Complex Volume(59) = {58};
