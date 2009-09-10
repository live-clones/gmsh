Mesh.CharacteristicLengthFactor=1.0;

Merge "Torus2_CLASS.msh"; 
CreateTopology;

Compound Line(100)={1};
Compound Line(200)={2};

Compound Surface(1000)={150} Boundary {{}};
Compound Surface(2000)={250} Boundary {{}};
