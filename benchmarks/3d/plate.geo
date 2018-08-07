h = 0.02;
Point(1) = {0,0,0,3*h};
Point(2) = {1,0,0,3*h};
Point(3) = {1,1,0,3*h};
Point(4) = {0,1,0,3*h};
Line(1) = {1,4};
Line(2) = {4,3};
Line(3) = {3,2};
Line(4) = {2,1};
Line Loop(5) = {4,1,2,3};
Plane Surface(6) = {5};
Extrude {0,0,h}{ Surface {6}; }
Characteristic Length {4,1,2,3} = 1;
