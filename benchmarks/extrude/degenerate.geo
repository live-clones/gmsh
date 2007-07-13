lc = 1;
n = 15;

Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,lc};
Point(3) = {2,0,0,lc};
Point(4) = {2,0,0,lc};
Point(5) = {10,0,0,lc};
Point(6) = {11,0,0,lc};
Point(7) = {0,11,0,lc};
Point(8) = {0,10,0,lc};
Point(9) = {0,1,0,lc};
Point(10) = {1,1,0,lc};
Point(11) = {2,1,0,lc};

Line(1) = {1,2};
Line(2) = {2,4};
Line(3) = {4,5};
Line(4) = {5,6};

Circle(5) = {6,1,7};
Circle(6) = {5,1,8};

Line(7) = {7,8};
Line(8) = {8,9};
Line(9) = {9,1};
Line(10) = {9,10};
Line(11) = {4,11};
Line(12) = {11,10};
Line(13) = {10,2};

// Bore
Line Loop(14) = {13,-1,-9,10};
Plane Surface(15) = {14};

Extrude Surface { 15, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 1 } ; 
};


// Induc
Line Loop(16) = {2,11,12,13};
Plane Surface(17) = {16};

Extrude Surface { 17, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 1 } ; 
};

// Air
Line Loop(18) = {-10,-8,-6,-3,11,12};
Plane Surface(19) = {18};

Extrude Surface { 19, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 1 } ; 
};

// AirInf
Line Loop(20) = {-7,-5,-4,6};
Plane Surface(21) = {20};

Extrude Surface { 21, {0,1,0} , {0,0,0} , Pi/2 } { 
  Recombine ; Layers { n, 1 } ; 
};


Symmetry { 0,1,0,0 } { Duplicata{ Surface{158}; } }
