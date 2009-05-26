Mesh.CharacteristicLengthFactor = 0.1;

Merge "sp2tmp01_1.stl";
Merge "sp2tmp01_2.stl";
Merge "sp2tmp01_3.stl";

// remove duplicate mesh vertices
Coherence Mesh;

Surface Loop(1)={1,2};
Surface Loop(2)={-2,3};
Volume(1)={1};
Volume(2)={2};
