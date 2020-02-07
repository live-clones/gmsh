
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
Extrude {{0,1,0}, {-2,0,0}, 2*Pi/3} {Surface {6}; }
Extrude {{0,1,0}, {-2,0,0}, 2*Pi/3} {Surface {28}; }
Extrude {{0,1,0}, {-2,0,0}, 2*Pi/3} {Surface {50}; }
