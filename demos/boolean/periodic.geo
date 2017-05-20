SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMax = 0.4;

R = 2;
Box(1) = {0,0,0, R,R,R};
pts() = PointsOf{Volume{1};};

Characteristic Length{pts(0)} = 0.01;

Periodic Surface{2} = {1} Translate{R,0,0};
