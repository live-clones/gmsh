Merge "r37_profiles_to_gmsh.STEP";

Surface Loop(1) = {1:14};
Volume(1) = {1};

Mesh.Algorithm = 5;
Mesh.Algorithm3D = 10;

lcmin = .5;
lcmax = 5;

Mesh.MeshSizeMin = lcmin;
Mesh.MeshSizeMax = lcmax;
Mesh.MeshSizeExtendFromBoundary = 0;

Field[1] = Distance;
Field[1].CurvesList = {12, 14, 15, 33, 3, 13};
Field[1].Sampling = 100;

Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = lcmin;
Field[2].SizeMax = lcmax;
Field[2].DistMin = 1;
Field[2].DistMax = 20;

Field[3] = Min;
Field[3].FieldsList = {2};

Background Field = 3;

Mesh 3;

Plugin(BoundaryLayer).Surfaces = "11, 3, 10";
Plugin(BoundaryLayer).Volumes = "1";
Plugin(BoundaryLayer).Thickness = 1./2.3;
Plugin(BoundaryLayer).Size = 1./2.3;
Plugin(BoundaryLayer).Ratio = 1.2;
Plugin(BoundaryLayer).Run;


Save "rotor.msh";
