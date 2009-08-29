Mesh.CharacteristicLengthFactor=0.1;

Merge "PelvisARTHUR_CLASS.msh";
CreateTopology;

Surface Loop(1002)={2,3};
Volume(1003)={1002};

Compound Line(10)={4};
Compound Line(20)={5};

Compound Surface(200)={2};
Compound Surface(400)={3};

Compound Volume(2000) = {1003};
