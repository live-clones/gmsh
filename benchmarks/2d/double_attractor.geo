Mesh.CharacteristicLengthFactor=2;

//begin "my example"
lowPr =   0.1;

Point(1) = {0,0,0,lowPr};
Point(2) = {1,0,0,lowPr};
Point(3) = {1,1,0,lowPr};
Point(4) = {0,1,0,lowPr};
Point(5) = {0.5,0.5,0,0};

// points to see where the DistMax and DistMin are
Point(6) = {0.05+0.5,0.5,0,lowPr};
Point(7) = {0.2+0.5,0.5,0,lowPr};
Point(8) = {0.3+0.5,0.5,0,lowPr};
Point(9) = {0.5+0.5,0.5,0,lowPr};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Line Loop(5) = {1,2,3,4};
Plane Surface(6) = {5};

Field[1] = Attractor;
Field[1].NodesList = {5};

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].LcMin = 0.001;
Field[2].LcMax = 0.005;
Field[2].DistMin = 0.05;
Field[2].DistMax = 0.2;
Field[2].StopAtDistMax = 1; // don't impose element size outside DistMax
//Field[2].Sigmoid = 1; // use sigmoid instead of linear interpol

Field[3] = Attractor;
Field[3].NodesList = {5};

Field[4] = Threshold;
Field[4].IField = 3;
Field[4].LcMin = 0.005;
Field[4].LcMax = 0.1;
Field[4].DistMin = 0.3;
Field[4].DistMax = 0.5;

Field[5] = Min;
Field[5].FieldsList = {2,4};

Background Field = 5;

