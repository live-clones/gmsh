Mesh.CharacteristicLengthFactor=0.1;

Merge "PelvisHEMI_CLASS.msh";
CreateTopology;

//on doit creer volume
//Surface Loop(999)={2,3,4,5};
//Volume(1000)={999};

Compound Line(60)={6};
Compound Line(70)={7};
Compound Line(80)={8};
Compound Line(90)={9};

Compound Surface(100)={2} Boundary {{}};
//Compound Surface(200)={3} Boundary {{}};
Compound Surface(300)={4} Boundary {{}};
Compound Surface(400)={5} Boundary {{}};

//Compound Volume(5000)={1000};


