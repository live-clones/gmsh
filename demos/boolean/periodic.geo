SetFactory("OpenCASCADE");

Mesh.CharacteristicLengthMax = 0.4;

R = 2;
Block(1) = {0,0,0, R,R,R};
s() = Abs(Boundary{Volume{1};});
l() = Unique(Abs(Boundary{Surface{s()};}));
pts() = Unique(Abs(Boundary{Line{l()};}));

Characteristic Length{pts(0)} = 0.01;

Periodic Surface{2} = {1} Translate{R,0,0};
