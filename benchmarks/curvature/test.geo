 Mesh.RemeshParametrization=0; //(0) harmonic (1) conformal
 Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis 
 
 Mesh.Algorithm=1; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)

 //Mesh.CharacteristicLengthFactor= 0.1;
 Mesh.CharacteristicLengthFromPoints = 0;
 Mesh.CharacteristicLengthFromPoints = 0;
 Mesh.CharacteristicLengthMin = 0.01;
 Mesh.CharacteristicLengthMax = 10.00;
 Mesh.LcIntegrationPrecision=1.e-5;
 Mesh.MinimumCirclePoints=20; 
 Mesh.CharacteristicLengthExtendFromBoundary=0;

 Merge "Sphere.stl";
 //Merge "TorusInput.stl";
 //Merge "DistanceFromOrigin.bgm";
 //Merge "hop.bgm";
 //Background Mesh View[0];

 //Field[1] = MathEval;	
 //Field[1].F = "0.1*sqrt(x^2 + y^2 + z^2)";
 //Background Field = 1;

 CreateTopology;

 Compound Surface(20) = {1};

 Physical Surface("Wall") = {20};
