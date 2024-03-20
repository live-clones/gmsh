SetFactory("OpenCASCADE");
Geometry.OCCTargetUnit = "M";
Merge "Part_2.step";
Wire(1) = {3:627, 2};
Extrude { Curve{1}; } Using Wire {1}
Mesh.MeshSizeFromCurvature = 5;
