SetFactory('OpenCASCADE');

Geometry.OCCTargetUnit = "M";
/*
Sphere(1) = {0.0,0.0,0.0,30.0,-Pi/2,Pi/2,Pi/8};
Cylinder(2) = {0.0,0.0,-30.0,0.0,0.0,60,2};

BooleanDifference{Volume{1};Delete;}{Volume{2};Delete;}

MeshSize{:} = 1.5;
MeshSize{3:4} = 0.5;

Rotate{{0,0,1},{0,0,0},7/16*Pi}{Point{1:4}; Line{1:6}; Surface{1:4}; Volume{1};}

Periodic Surface {2} = {4} Rotate{{0,0,1},{0,0,0},Pi/8};
*/

RR = 30.0;
ll = 1.0;

Point(1) = {0.0,0.0,0.0}; //this is the center
Point(2) = {0.0,0.0,RR}; //top
Point(3) = {0.0,0.0,-RR}; //bottom
Point(4) = {RR*Sin(Pi/16),RR*Cos(Pi/16),0.0};



Circle(1) = {2,1,4};
Circle(2) = {4,1,3};
Line(3) = {3,2};
BooleanUnion{Line{1};Delete;}{Line{2};Delete;}
Delete{Point{1};}

Curve Loop(6) = {1,3};

Plane Surface(1) = {6};


Extrude{{0,0,1},{0.0,0.0,0.0},Pi/8}{Surface{1};}

Cylinder(2) = {0.0,0.0,-30.0,0.0,0.0,60,2};
BooleanDifference{Volume{1};Delete;}{Volume{2};Delete;}

MeshSize{:} = 4*ll;
MeshSize{1:2} = ll;
/*
Periodic Line {3} = {1} Rotate{{0,0,1},{0,0,0},Pi/8};
Periodic Line {6} = {5} Rotate{{0,0,1},{0,0,0},Pi/8};
*/

Geometry.OCCBoundsUseStl = 1;
Periodic Surface {4} = {2} Rotate{{0,0,1},{0,0,0},Pi/8};
