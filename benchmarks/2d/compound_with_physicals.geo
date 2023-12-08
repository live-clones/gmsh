//Mesh.CharacteristicLengthFromPoints = 0;
lc=20;
Point(1) = {1.8689e-35,3.99916e-33,0,lc};
Point(2) = {8.33333,9.32267e-32,0,lc};
Point(3) = {16.6667,7.58404e-33,0,lc};
Point(4) = {25.0,-9.38607e-36,0,lc};
Point(5) = {6.903e-33,5.34874,0,lc};
Point(6) = {9.4089,10.8391,0,lc};
Point(7) = {16.7265,10.0288,0,lc};
Point(8) = {25.0479,9.96269,0,lc};
Line(1)={1,2};
Line(2)={2,6};
Line(3)={5,6};
Line(4)={1,5};
Line(5)={2,3};
Line(6)={3,7};
Line(7)={6,7};
Line(8)={3,4};
Line(9)={4,8};
Line(10)={7,8};
Curve Loop(1)={1,2,-3,-4};
Plane Surface(1)={1};
Curve Loop(2)={5,6,-7,-2};
Plane Surface(2)={2};
Curve Loop(3)={8,9,-10,-6};
Plane Surface(3)={3};

Compound Surface{1,2,3};
Physical Surface("setWPsurf")={1,2,3};

Compound Curve{3,7,10};
Physical Curve("setWPtop")={3,7,10};
Compound Curve{1,5,8};
Physical Curve("setWPbot")={1,5,8};
Compound Curve{4};
Physical Curve("setWPleft")={4};
Compound Curve{9};
Physical Curve("setWPright")={9};

// the physicals will will work as well even if we don't reclassify on the
//original surfaces:

// Mesh.CompoundClassify = 0;
