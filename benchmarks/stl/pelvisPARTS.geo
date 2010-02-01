Mesh.CharacteristicLengthFactor=0.1;

Merge "pelvis_CLASS.msh";
CreateTopology;

Compound Line(60)={6};
Compound Line(70)={7};
Compound Line(80)={8};
Compound Line(90)={9};

Compound Surface(100)={2}; // NoSplit;
Compound Surface(200)={3}; // NoSplit;
Compound Surface(300)={4}; // NoSplit;
Compound Surface(400)={5}; // NoSplit;

Surface Loop(500)={100,200,300,400};
Volume(501)={500};

Physical Surface(555)={100,200,300,400};
Physical Volume(666)={501};