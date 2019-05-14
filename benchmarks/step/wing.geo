SetFactory("OpenCASCADE");

Geometry.OCCTargetUnit = "M";

v() = ShapeFromFile("wing_fuselage.step");
Box(3) = {-5, -5, -5, 10, 10, 10};
out() = BooleanDifference{ Volume{3}; Delete; }{ Volume{v()}; Delete; };

s() = Boundary{ Volume{out()}; };
s1() = Surface In BoundingBox{-2,-2,-2,4,4,4};
s() -= s1();

Physical Surface("Infinity", 1) = s();
Physical Surface("Fuselage", 2) = s1();
Physical Volume("Air", 3) = out();

p() = PointsOf{ Surface{s1()}; };
Characteristic Length{p()} = 0.02;

Mesh.CharacteristicLengthFromCurvature = 1;
Mesh.CharacteristicLengthFromPoints = 1;
Mesh.MinimumCirclePoints = 20;

Mesh.CharacteristicLengthMin = 0.002;
Mesh.CharacteristicLengthMax = 1;
Mesh.Algorithm = 6;
