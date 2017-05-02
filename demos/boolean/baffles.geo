SetFactory("OpenCASCADE");
Block(1) = {-0, 0, 0, 1, 1, 1};

// intersecting:
Rectangle(7) = {0.4, 0.7, 0.2, 0.3, 0.3, 0};
Rectangle(8) = {-0.2, 0.3, 0.5, 0.3, 0.3, 0};
Rectangle(9) = {0.8, -0.2, 0.5, 0.3, 0.3, 0};
BooleanFragments{ Volume{1}; Delete; }{ Surface{7:9}; Delete; }

// fully inside
Rectangle(30) = {0.3, 0.3, 0.5, 0.3, 0.3, 0};
Surface {30} In Volume{1};
