l1=0.1;
Point(1) = {0,0,0,l1};
Point(2) = {1,0,0,l1};
Point(3) = {1,1,0,l1};
Point(4) = {0,1,0,l1};
Point(5) = {0,0,1,l1};
Point(6) = {0,1,1,l1};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Ruled Surface(6) = {5};

// This is OK
/*
Line(7) = {6,4};
Line(8) = {1,5};
Line(9) = {5,6};
Line Loop(10) = {7,-4,8,9};
Ruled Surface(11) = {10};
Rotate {{0,1,0}, {0,0,0}, Pi/4} { Surface{6,11}; }
*/

// This will fail, since at the moment we use the extrusion formula to
// interpolate the surface (which is wrong since the surface has been
// transformed). We do this so that we can create exact surfaces of
// revolution... One more shortcoming of our little CAD engine :-)
Extrude {0,0,1}{ Line{4}; }
Rotate {{0,1,0}, {0,0,0}, Pi/4} { Surface{6,10}; }
