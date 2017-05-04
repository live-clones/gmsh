SetFactory("OpenCASCADE");
Block(1) = {-0, 0, 0, 1, 1, 1};


// intersecting:
Rectangle(7) = {0.4, 0.7, 0.2, 0.3, 0.3, 0};
Rectangle(8) = {-0.2, 0.3, 0.5, 0.3, 0.3, 0};
Rectangle(9) = {0.8, -0.2, 0.5, 0.3, 0.3, 0};
Rectangle(10) = {0.3, 0.3, 0.5, 0.3, 0.3, 0};

a() = BooleanFragments{ Volume{1}; Delete; }{ Surface{7:10}; Delete; };
Printf("a = ", a());

//Characteristic Length{Point "*"} = 0.1;
//p() = PointsOf{ Surface{a({1:#a()-1})}; };
//Characteristic Length{p()} = 0.01;
