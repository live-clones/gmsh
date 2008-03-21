lc = .1;
Point(1) = {0,0,0,lc};
Point(2) = {1,0,0,lc/200};
Point(3) = {1,1,0,lc};
Point(4) = {0,1,0,lc};
Line(1) = {3,2};
Line(2) = {2,1};
Line(3) = {1,4};
Line(4) = {4,3};
Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};
Point(11) = {0.1, 0.1, 0, lc};
Point(22) = {0.9, 0.9 ,0, lc};
Line(5) = {11,22};

Field[1] = Attractor;
Field[1].NNodesByEdge = 100;
Field[1].EdgesList = {3,5};

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = lc/10;
Field[2].LcMax = lc;
Field[2].DistMin = 0.15;
Field[2].DistMax = 0.3;

Background Field = 2;

// comment this to NOT take into account lc/200 at Point(2):
Mesh.ConstrainedBackgroundMesh = 1;
