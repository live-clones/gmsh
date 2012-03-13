Mesh.Algorithm = 6; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)

Mesh.RemeshParametrization=0; //(0=harmonic_circle, 1=conformal, 2=rbf, 3=harmonic_plane, 4=convex_circle, 5=convex_plane, 6=harmonic square" 
Mesh.RemeshAlgorithm=1; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.1;

Merge "artery.stl";
CreateTopology;

Compound Surface(100)={1};
Compound Line(1001)={1};
Compound Line(1002)={2};
Compound Line(1003)={3};

Physical Surface(101)={100};
