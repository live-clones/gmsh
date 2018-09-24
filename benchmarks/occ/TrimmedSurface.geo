SetFactory("OpenCASCADE");

a() = ShapeFromFile("TrimmedSurface.brep");

lc = 2.2626725788082012;
Mesh.Algorithm = 6;
Mesh.CharacteristicLengthExtendFromBoundary = 1;
Mesh.CharacteristicLengthFactor = 1.0;
Mesh.CharacteristicLengthMin = lc;
Mesh.CharacteristicLengthMax = lc;
Mesh.QualityType = 0;

Mesh 2;

// Check out the quality of the mesh
Plugin(AnalyseCurvedMesh).ICNMeasure = 1;
Plugin(AnalyseCurvedMesh).JacobianDeterminant = 0;
Plugin(AnalyseCurvedMesh).IGEMeasure = 0;
Plugin(AnalyseCurvedMesh).DrawPView = 1;
Plugin(AnalyseCurvedMesh).DimensionOfElements = 2;
Plugin(AnalyseCurvedMesh).Run;

minquality = View[PostProcessing.NbViews-1].Min;
If (minquality < 0.4)
  Error("Quality is far too low. It should be 0.4, but is %22.15f instead", minquality);
EndIf
