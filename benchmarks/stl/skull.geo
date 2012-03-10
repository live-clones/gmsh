Mesh.Algorithm = 6; //(1=MeshAdapt, 2=Automatic, 5=Delaunay, 6=Frontal, 7=bamg, 8=delquad)

Mesh.RemeshParametrization=0; //(0=harmonic_circle, 1=conformal, 2=rbf, 3=harmonic_plane, 4=convex_circle, 5=convex_plane, 6=harmonic square" 
Mesh.RemeshAlgorithm=2; //(0) nosplit (1) automatic (2) split metis

Mesh.CharacteristicLengthFactor=0.2;
//Mesh.Algorithm3D = 4; //Frontal (4) Delaunay(1)

Merge "skullU.stl";
CreateTopology;

Compound Surface(200)={1} ;

Surface Loop(300)={200};
Volume(301)={300};

Physical Surface (501)={200};
Physical Volume(502)={301};
