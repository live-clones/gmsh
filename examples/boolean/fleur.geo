a = 0.71;
b = 0.145;
NrOfPetals = 12;
L = 4;

SetFactory("OpenCASCADE");
Rectangle(1) = {-L/2, -L/2, 0, L, L, 0};
Disk(2) = {a, 0, 0, a, b};
petals() = {2};
For t In {1:NrOfPetals-1}
  petals() += Rotate {{0, 0, 1}, {0, 0, 1}, 2*Pi/NrOfPetals*t} {
    Duplicata { Surface{2}; }
  };
EndFor

BooleanUnion(100) = { Surface{petals(0)}; Delete; }{
  Surface{petals({1:NrOfPetals-1})}; Delete;
};

BooleanDifference(200) = { Surface{1}; Delete; }{ Surface{100}; Delete; };

Physical Surface(1000) = {200};

Mesh.MeshSizeFromCurvature = 15;
Mesh.MeshSizeMax = 0.1;
