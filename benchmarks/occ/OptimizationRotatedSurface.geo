SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 3.0;
Mesh.CharacteristicLengthMax = 3.0;
Mesh.QualityType = 0;

Disk(1) = {0.5, 0.5, 0, 5, 5};
Disk(2) = {0.5, 0.5, 0, 4.5, 4.5};

// WITH this rotation below seconds order mesh optimization fails, WITHOUT it succeeds
Rotate { {1,0,0}, {0,0,0}, Pi/2 } { Surface{1:2}; }

BooleanFragments{ Surface{1:2}; Delete; }{}

Recursive Delete {
  Surface{2};
}

Mesh 2;

SetOrder 2;
OptimizeMesh "HighOrder";

// Check out the quality of the mesh
Plugin(AnalyseMeshQuality).ICNMeasure = 1;
Plugin(AnalyseMeshQuality).JacobianDeterminant = 0;
Plugin(AnalyseMeshQuality).IGEMeasure = 0;
Plugin(AnalyseMeshQuality).CreateView = 1;
Plugin(AnalyseMeshQuality).DimensionOfElements = 2;
Plugin(AnalyseMeshQuality).Run;

minquality = View[PostProcessing.NbViews-1].Min;
If (minquality < 0.1)
  Error("Quality is far too low. It should be 0.1, but is %22.15f instead", minquality);
EndIf
