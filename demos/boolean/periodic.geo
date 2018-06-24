SetFactory("OpenCASCADE");

R = 2;
Box(1) = {0,0,0, R,R,R};
Torus(2) = {3,0,0, 1.5, 1, Pi/3};

pts() = PointsOf{ Volume{1, 2}; };

Characteristic Length{ pts() } = 0.4;

Characteristic Length{ 2 } = 0.01;

Periodic Surface{6} = {5} Translate{0,0,R};
// This is a shortcut for:
// Periodic Surface{6} = {5} Affine{1,0,0,0, 0,1,0,0, 0,0,1,R};

Periodic Surface{9} = {8} Rotate{{0,0,1}, {3,0,0}, Pi/3 };
// The rotation could of course also be given directly through the affine
// transformation matrix
