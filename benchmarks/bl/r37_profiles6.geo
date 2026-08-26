Merge "r37_profiles_to_gmsh.STEP";

Surface Loop(1) = {1:14};
Volume(1) = {1};

Mesh.Algorithm = 9;
//Mesh.Algorithm3D = 10;
Mesh.RecombineAll = 1;
Mesh.OptimizePyramids = -3;

//MeshAlgorithm Surface {11, 3} = 8;
//Recombine Surface {11,3};


lcmin = .5;
lcmax = 5;

Mesh.MeshSizeMin = lcmin/5;
Mesh.MeshSizeMax = lcmax;
Mesh.MeshSizeExtendFromBoundary = 0;


Field[1] = Distance;
Field[1].CurvesList = {12, 14};
Field[1].Sampling = 100;

Field[11] = Distance;
Field[11].CurvesList = {15, 33, 3, 13};
Field[11].Sampling = 100;

Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = lcmin/5;
Field[2].SizeMax = lcmax;
Field[2].DistMin = 2;
Field[2].DistMax = 20;

Field[22] = Threshold;
Field[22].InField = 11;
Field[22].SizeMin = lcmin;
Field[22].SizeMax = lcmax;
Field[22].DistMin = 1;
Field[22].DistMax = 20;

Field[3] = Min;
Field[3].FieldsList = {2,22};

Background Field = 3;

Mesh 2;

Plugin(BoundaryLayer).Surfaces = "11, 3, 10,5,2,6";
Plugin(BoundaryLayer).Volumes = "1";
Plugin(BoundaryLayer).Thickness = 1/2;
Plugin(BoundaryLayer).Size = 1/200;
Plugin(BoundaryLayer).Ratio = 1.2;
//Plugin(BoundaryLayer).Run;


Save "rotor.msh";
