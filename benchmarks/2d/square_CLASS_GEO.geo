Mesh.CharacteristicLengthFactor=6;

Merge "square_CLASS.msh";
CreateTopology;

//Compound Line(100)={1};
//Compound Line(200)={2};
//Compound Line(300)={3};
//Compound Line(400)={4};

Compound Line(150)={1,2};
Compound Line(160)={3,4};

Compound Surface(170)={10} Boundary {{}};