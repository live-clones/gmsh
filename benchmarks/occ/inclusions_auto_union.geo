SetFactory("OpenCASCADE");
lc = 3 * 1e-2;

// CIRCLE

Disk(1) = {0.35,0.35,0,0.15,0.15};

// CIRCLE

Disk(2) = {0.35,0.7,0,0.2,0.1};

// CIRCLE

Disk(3) = {0.8,0.3,0,0.1,0.1};

// CIRCLE

Disk(4) = {0.6,0.6,0,0.2,0.1};

// UNIT CELL

Rectangle(5) = {0,0,0,1,1};

cell() = BooleanDifference{Surface{5}; }{ Surface{1:4}; Delete; };
s() = BooleanFragments{Surface{5}; Delete; }{ Surface{cell()}; Delete; };
s() -= cell();
Physical Surface("material", 1) = s();
Physical Surface("unit cell", 2) = cell();
Color Blue{Physical Surface{1};}
Color Red{Physical Surface{2};}
Mesh.MshFileVersion = 2;
