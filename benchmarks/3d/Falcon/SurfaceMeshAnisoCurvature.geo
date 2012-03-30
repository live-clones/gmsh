Mesh.RemeshParametrization=7; //0=harmonic_circle, 1=conformal, 2=rbf, 3=harmonic_plane, 4=convex_circle, 5=convex_plane, 6=harmonic square
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split only with metis 

Mesh.Algorithm=7; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)

Mesh.CharacteristicLengthFromPoints = 0;
Mesh.CharacteristicLengthMin = 0.005;
Mesh.CharacteristicLengthMax = 2.0;
Mesh.LcIntegrationPrecision=1.e-5;
Mesh.MinimumCirclePoints=50;
Mesh.CharacteristicLengthExtendFromBoundary=0;
Mesh.CharacteristicLengthFromCurvature = 1;
Mesh.CharacteristicLengthFromPoints = 0;

Merge "InitialMeshFalcon.msh";


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
  Compound Surface(i+100) = ss[i];
  Physical Surface(i+1) = { i+100 };
EndFor

// The trailing edge of the horizontal tail surface 
// should be an attractor

//Point(100000) = {16.858,2.0482,0.018793,0.1}; 
Point(100000) = {-1.16411804,1.83824622,0.29113513};
Field[1] = Attractor;
Field[1].NodesList = { 100000 };

// Local refinement near the airfoil:
Field[2] = Threshold;
Field[2].IField = 1;
Field[2].DistMin = 0.05;
Field[2].DistMax = 0.3;
Field[2].LcMin = 0.05;
Field[2].LcMax = 1.0;
Field[2].StopAtDistMax = 1;

Background Field = 2;




