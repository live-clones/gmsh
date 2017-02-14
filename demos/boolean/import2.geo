SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMin = 3;
Mesh.CharacteristicLengthMax = 3;

DefineConstant[
  angle = {90, Name "Parameters/wedge angle"}
];

a() = ShapeFromFile("component8.step");

Cylinder(2) = {0,150,0, 0,200,0, 40, angle*2*Pi/360};

BooleanIntersection{ Volume{a(0)}; Delete; }{ Volume{2}; Delete; }
