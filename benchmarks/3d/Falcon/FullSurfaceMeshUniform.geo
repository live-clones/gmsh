Mesh.RemeshParametrization=7; //0=harmonic_circle, 1=conformal, 2=rbf, 3=harmonic_plane, 4=convex_circle, 5=convex_plane, 6=harmonic square
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis
Mesh.Algorithm=6; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)

lc = 0.3;

Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthMin = lc;
Mesh.CharacteristicLengthMax = lc;
Mesh.LcIntegrationPrecision = 1.e-5;
Mesh.MinimumCirclePoints = 50;
Mesh.CharacteristicLengthExtendFromBoundary = 0;
Mesh.CharacteristicLengthFromCurvature = 0;
Mesh.CharacteristicLengthFromPoints = 0;

Merge "FullInitialMeshFalcon.msh";

CreateTopology;

// Make all lines compound:
ll[] = Line "*";
For j In {0 : #ll[]-1}
  Compound Line(1000+j) = ll[j];
  Physical Line(1000+j) = (1000+j);
EndFor

// Make all surfaces compound and physical:
ss[] = Surface "*";
For i In {0 : #ss[]-1}
  Compound Surface(i+1000) = ss[i];
  Physical Surface(i+1) = { i+1000 };
EndFor

