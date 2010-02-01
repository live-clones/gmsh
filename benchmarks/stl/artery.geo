Mesh.CharacteristicLengthFactor=0.1;
Mesh.Algorithm3D = 4; //Frontal (4) Delaunay(1)

//merge the stl triangulation
Merge "artery.stl";
CreateTopology;

Compound Surface(100)={1} Harmonic;

Physical Surface(101)={100};