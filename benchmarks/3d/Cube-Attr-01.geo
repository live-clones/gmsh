lc = 0.2;
Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,lc};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(5) = {2,3,4,1};
Plane Surface(6) = {5};
Extrude Surface {6, {0,0.0,1}};
                     
Surface Loop(29) = {23,6,15,19,28,27};
Volume(30) = {29};
                
Point(16) = {-.5,.5,.5,1.0};
Point(17) = {1.5,.5,.8,1.0};
Line(30) = {16,17};

Point(18) = {-.2,.7,1.3,1.0};
Point(19) = {1.22,.1,-.8,1.0};
Line(31) = {18,19};

Field[1] = Attractor;
Field[1].NNodesByEdge = 100;
Field[1].NodesList = {1,4,5,6,10,14};
Field[1].EdgesList = {30,31};

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = lc/10;
Field[2].LcMax = lc;
Field[2].DistMin = 0.1;
Field[2].DistMax = 0.2;

Background Field = 2;
