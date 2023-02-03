SetFactory("OpenCASCADE");

Point(1)={0,0,0};
Point(2)={1,0,0};
Point(3)={0,0,1};

Circle(1)={2,1,3};
Line(2)={1,2};
Line(3)={1,3};

Curve Loop(1) = {2,1,-3};
Plane Surface(1) = {1};

Extrude { {0,0,1}, {0,0,0}, Pi/2 } { Surface{1}; }

Geometry.OCCFixSmallEdges=1;
HealShapes;


n=21;
Transfinite Curve{:}=n;
Transfinite Surface{:};

Mesh.TransfiniteTri=1;
Mesh.Smoothing = 50;
