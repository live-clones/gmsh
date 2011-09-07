Merge "BifurcationRemeshCurvatureReclassified.msh";
CreateTopology;
Line Loop(100) = {3};
Plane Surface(200) = {100};
Line Loop(101) = {4};
Plane Surface(201) = {101};
Line Loop(102) = {5};
Plane Surface(202) = {102};

Surface Loop(30) = {21, 200, 201, 202};
Volume(1) = {30};
Physical Volume ("Volume") = {1};
Physical Surface ("Wall") = {21};
Physical Surface ("Side") = {200, 201, 202}
