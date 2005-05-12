lc=0.8;
R=4;
r=1;
h=Sqrt(r*(2*R+r));
Point(1) = {-r,0,0,lc};
Point(2) = {0,0,r,lc};
Point(4) = {0,0,-r,lc};
Point(5) = {0,0,0,lc};
Point(6) = {0,h,0,lc};
Point(7) = {-R,0,0,lc};
Point(8) = {-R,R+r,0,lc};
Circle(1) = {1,5,2};
Circle(2) = {4,5,1};
Circle(3) = {6,7,8};
Ellipse(4) = {2,5,6,6};
Ellipse(5) = {4,5,6,6};
Extrude Line {1, {0,0,1}, {-R,0,0}, Pi/2};
Extrude Line {2, {0,0,1}, {-R,0,0}, Pi/2};
Extrude Line {6, {0,0,1}, {-R,R,0}, -Pi/2};
Extrude Line {10, {0,0,1}, {-R,R,0}, -Pi/2};
Extrude Line {14, {0,0,1}, {-R,R,0}, -Pi/2};
Extrude Line {17, {0,0,1}, {-R,R,0}, -Pi/2};
Line Loop(1) = {3,4,-8,20};
Line Loop(2) = {-3,23,11,-5};
Ruled Surface(1) = {1};
Ruled Surface(2) = {2};
Physical Surface(1) = {1,2,9,13,16,19,22,25};

//Lower Left Quarter
l1[] = Symmetry {0, 1, 0, 0} { Duplicata{ Surface{1,2,9,13,16,19,22,25}; } };
Physical Surface(2) = - {l1[]};

//Upper Right Quarter
l2[] = Symmetry {1, 0, 0, 0} { Duplicata{ Surface{1,2,9,13,16,19,22,25}; } };
Physical Surface(3) = - {l2[]};

//Lower Right Quarter
l3[] = Rotate { {0,0,1}, {0,0,0}, Pi } { Duplicata{ Surface{1,2,9,13,16,19,22,25}; } };
Physical Surface(4) = {l3[]};
