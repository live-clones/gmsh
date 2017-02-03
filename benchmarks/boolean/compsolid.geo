SetFactory("OpenCASCADE");

Mesh.Algorithm = 6;
Mesh.CharacteristicLengthMin = 0.1;
Mesh.CharacteristicLengthMax = 0.1;

DefineConstant[
  sph = {0, Choices{0,1}, Name "Make sphere a single volume"}
  xx = {2.2, Min -1, Max 5, Step 0.01, Name "Sphere position"}
];


Block(1) = {0,0,0, 2,2,2};
Sphere(2) = {xx, 1, 1, 0.5};
Block(3) = {2,0,0, 4,2,2};

BooleanFragments { Volume{1}; Delete; }{ Volume{2,3}; Delete; }

If(sph)
  BooleanUnion { Volume{2}; Delete; }{ Volume{3}; Delete; }
EndIf
