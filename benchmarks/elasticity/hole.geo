lcExt = 0.1;
lcIn = 0.01;
a=0.05;
L=3;

Point(1)={-L/2,-L/2,0,lcExt};
Point(2)={L/2,-L/2,0,lcExt};
Point(3)={L/2,L/2,0,lcExt};
Point(4)={-L/2,L/2,0,lcExt};

Line(1)={1,2};
Line(2)={2,3};
Line(3)={3,4};
Line(4)={4,1};

Point(10) = {0,0,0,lcIn};
Point(11) = {a,0,0,lcIn};
Point(12) = {0,a,0,lcIn};
Point(13) = {-a,0,0,lcIn};
Point(14) = {0,-a,0,lcIn};
Circle (10)= {11,10,12};
Circle (11)= {12,10,13};
Circle (12)= {13,10,14};
Circle (13)= {14,10,11};

Line Loop(1)={1,2,3,4};
Line Loop(2)={10,11,12,13};
Plane Surface(1) = {1,2};

Physical Line("Bottom")={1};
Physical Line("Right")={2};
Physical Line("Top")={3};
Physical Line("Left")={4};
Physical Line("Cicrcle")={10,11,12,13};
Physical Surface("Surface")={1};
Physical Point("Center") = {11};

Mesh.CharacteristicLengthExtendFromBoundary=1;
Mesh.CharacteristicLengthFromPoints=1;
