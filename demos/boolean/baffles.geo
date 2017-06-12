SetFactory("OpenCASCADE");

Box(1) = {-0, 0, 0, 1, 1, 1};

p() = PointsOf{ Volume{1}; };
Characteristic Length{p()} = 0.2;

Rectangle(7) = {0.4, 0.7, 0.2, 0.3, 0.3, 0};
Rectangle(8) = {-0.2, 0.3, 0.5, 0.3, 0.3, 0};
Rectangle(9) = {0.8, -0.2, 0.5, 0.3, 0.3, 0};
Rectangle(10) = {0.3, 0.3, 0.5, 0.3, 0.3, 0};

b() = BooleanFragments{ Volume{1}; Delete; }{ Surface{7:10}; Delete; };

p() = PointsOf{ Surface{b({1:6})}; };
Characteristic Length{p()} = 0.04;
