Mesh.Algorithm=7; //1=MeshAdapt, 5=Delaunay, 6=Frontal, 7=BAMG

Mesh.RemeshParametrization=4; //0=harmonic_circle, 1=conformal_spectral, 2=rbf, 3=harmonic_plane, 4=convex_circle, 5=convex_plane, 6=harmonic square, 7=conformal_fe
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.25;
Mesh.CharacteristicLengthFromCurvature=1; //-clcurv
Mesh.CharacteristicLengthMin = 0.01; //-clmin 0.05
Mesh.CharacteristicLengthMax =20.00; //-clmax 4.0
Mesh.LcIntegrationPrecision=1.e-3; //-epslc1d
Mesh.MinimumCirclePoints=50; //default=7
Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthExtendFromBoundary=0;

Merge "BifurcationInput.msh";

CreateTopology;

Compound Surface(20) = {1};

Physical Surface("Wall") = {20};




