SetFactory("OpenCASCADE");

// convert geometry read from STEP file to meters
Geometry.OCCTargetUnit = "M";

// read STEP file and store volume(s)
v() = ShapeFromFile("wing_fuselage.step");
//v() = ShapeFromFile("wing_HKN__step.step");

// get bounding box
bb() = BoundingBox Volume {v()};

// size along x-axis
dx = (bb(3) - bb(0));

// gap to "infinity" box
e = 2 * dx;

// create "infinity" box
Box(3) = {bb(0) - e, bb(1) - e, bb(2) - e,
          bb(3) - bb(0) + 2 * e,
          bb(4) - bb(1) + 2 * e,
          bb(5) - bb(2) + 2 * e};

// carve volume out of box
out() = BooleanDifference{ Volume{3}; Delete; }{ Volume{v()}; Delete; };

// retrieve boundary of new volume
s() = Boundary{ Volume{out()}; };

//  remove boundary of original volume
s1() = Surface In BoundingBox { bb() };
s() -= s1();

// define physical groups
Physical Surface("Infinity", 1) = s();
Physical Surface("Fuselage", 2) = s1();
Physical Volume("Air", 3) = out();

// set base mesh size = dx / 10 on fuselage
p() = PointsOf{ Surface{s1()}; };
Characteristic Length{p()} = dx / 10;

// adapt mesh to curvature, with 20 elements per 2*pi
Mesh.CharacteristicLengthFromCurvature = 1;
Mesh.CharacteristicLengthFromPoints = 1;
Mesh.MinimumElementsPerTwoPi = 20;

// contrain min/max mesh size
Mesh.CharacteristicLengthMin = dx / 100;
Mesh.CharacteristicLengthMax = dx;
