Mesh.Algorithm=1; //1=MeshAdapt, 5=Delaunay, 6=Frontal

Mesh.RemeshParametrization=1; //(0) harmonic (1) conformal 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis 

Mesh.CharacteristicLengthFactor=0.06;

Mesh.CharacteristicLengthFromCurvature =  1; //-clcurv
Mesh.CharacteristicLengthMin = 0.5; //-clmin 0.05
Mesh.CharacteristicLengthMax = 5.0; //-clmax 4.0
Mesh.LcIntegrationPrecision=1.e-5; //-epslc1d
Mesh.MinimumCirclePoints=7; //default=7
Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthExtendFromBoundary=0;

Merge "BifurcationInput.msh";
CreateTopology;

Compound Line(100)={1};
Compound Line(200)={2};
Compound Line(300)={3};

Compound Surface(20) = {1};

Physical Line("old")={1,2,3};
Physical Line("inout")={100,200,300};
Physical Surface("Wall") = {20};




