// ======================================================================
// The following settings were copied from benchmarks/step/linkrods.geo
// ======================================================================

Mesh.Algorithm=6; //1=MeshAdapt, 5=Delaunay, 6=Frontal, 7=bamg
Mesh.RemeshParametrization= 1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm = 1; //(0) nosplit (1) automatic (2) split only with metis ///Default: 1 

Mesh.CharacteristicLengthFactor=0.4;
Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthFromCurvature=1; //-clcurv
Mesh.MinimumCirclePoints=45; //default=7
Mesh.CharacteristicLengthMin = 0.01; //-clmin
Mesh.CharacteristicLengthMax = 0.5; //-clmax
Mesh.LcIntegrationPrecision = 1.e-5; //-epslc1d
Mesh.CharacteristicLengthExtendFromBoundary=0;

//Merge "TorusRemeshedBAMG.stl";
//Merge "SimpleTorus.msh";
Merge "TorusInput.stl";
//Merge "occtorus.stl";

CreateTopology;

Compound Surface(20) = {1};
//Compound Surface(100) = {15,19,23,27};
Physical Surface("Wall") = {20};




