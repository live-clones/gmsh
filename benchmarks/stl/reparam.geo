
Mesh.CharacteristicLengthFactor=0.5;
Geometry.Lines = 0;

Merge "reparam_input.msh";
CreateTopology;

Compound Line(1000)={1};
Compound Line(2000)={2};
Compound Line(3000)={3};
Compound Line(4000)={4};
Compound Surface(-1000)={5};
