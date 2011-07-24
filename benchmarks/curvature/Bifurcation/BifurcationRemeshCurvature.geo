Mesh.Algorithm=7; //1=MeshAdapt, 5=Delaunay, 6=Frontal, 7=BAMG
Mesh.CharacteristicLengthFactor=0.35;
Mesh.CharacteristicLengthFromCurvature=1; //-clcurv
Mesh.CharacteristicLengthMin = 0.05; //-clmin 0.05
Mesh.CharacteristicLengthMax = 3.00; //-clmax 4.0
Mesh.LcIntegrationPrecision=1.e-5; //-epslc1d
Mesh.MinimumCirclePoints=30; //default=7
Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthExtendFromBoundary=0;

Merge "BifurcationInput.msh";

CreateTopology;

Compound Surface(20) = {1};
Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis ///Default: 1 

Physical Surface("Wall") = {20};




