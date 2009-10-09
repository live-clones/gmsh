lc = 0.7;
Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,lc};
Point(3) = {0,1,0,lc};
Point(4) = {0,-1,0,lc};
Point(5) = {-1,0,0,lc};
Circle(1) = {2,1,3};
Circle(2) = {3,1,5};
Circle(3) = {5,1,4};
Circle(4) = {4,1,2};
Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};
Extrude Surface {6, {0,1,0}, {-2,0,0}, 2*Pi/3};
Extrude Surface {28, {0,1,0}, {-2,0,0}, 2*Pi/3};
Extrude Surface {50, {0,1,0}, {-2,0,0}, 2*Pi/3};
Surface Loop(72) = {45,23,67,71,49,27,15,59,37,41,19,63};

//Compound Surface(100)={45,23,67,71,49,27,15,59,37,41,19,63};

//Volume(73) = {72};
