Mesh.CharacteristicLengthFactor=0.05;

//merge the stl triangulation
Merge "artery.stl";
CreateTopology;

Compound Surface(100)={1} Harmonic;

Physical Surface(101)={100};