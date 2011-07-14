// ======================================================================
// The following settings were copied from benchmarks/step/linkrods.geo
// ======================================================================

Mesh.RemeshAlgorithm=6; //1=MeshAdapt, 5=Delaunay, 6=Frontal
Mesh.RemeshParametrization= 1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm = 1;

Mesh.CharacteristicLengthFactor=0.2;
Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthFromCurvature=1; //-clcurv
Mesh.CharacteristicLengthMin = 0.2; //-clmin
Mesh.CharacteristicLengthMax = 3.0; //-clmax
Mesh.LcIntegrationPrecision = 1.e-5; //-epslc1d

Mesh.MinimumCirclePoints=15; //default=7
Mesh.CharacteristicLengthExtendFromBoundary=0;

//Merge "TorusRemeshedBAMG.stl";
//Merge "SimpleTorus.msh";
Merge "TorusInput.stl";

CreateTopology;

Compound Surface(20) = {1};
//Compound Surface(100) = {15,19,23,27};
Physical Surface("Wall") = {20};




