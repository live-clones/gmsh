SetFactory("OpenCASCADE");
Merge "rod.brep";

Field[1] = Distance;
Field[1].SurfacesList = {1, 5};

Field[2] = Threshold;
Field[2].InField = 1;
Field[2].SizeMin = 0.001;
Field[2].SizeMax = 0.01;
Field[2].DistMin = 0.01;
Field[2].DistMax = 0.02;
Background Field = 2;
