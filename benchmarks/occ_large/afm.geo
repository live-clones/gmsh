SetFactory("OpenCASCADE");

//Parameters
//+ vertical tip-sample distance
htip = DefineNumber[ 23, Name "Parameters/htip" ];
//+ radius of tip
trad = DefineNumber[ 20, Name "Parameters/trad" ];
//+ radius of quantum dot
qdrad = DefineNumber[ 2.5, Name "Parameters/qdrad" ];
//+ horizontal tip-sample distance
hx = DefineNumber[ 0, Name "Parameters/hx" ];


//Geometry

// tip
Sphere(1)={hx,qdrad+htip+trad,0,trad,-Pi/2,Pi/2,2*Pi};
Sphere(2)={hx,qdrad+htip+trad,0,trad,-Pi/2,Pi/2,Pi};

// tip hemi-sphere
BooleanDifference(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };

// tip cone
// x, y, z, dx, dy, dz, r1, r2, tag = -1, angle = 2*pi
Cone(4) = {hx, qdrad+htip+trad, 0, 0, 60, 0, trad, 50, 2*Pi};

// container
Cylinder(5)={0, 0, 0, 0, 105.5, 0, 100};

// remove the tip from container (no mesh)
BooleanDifference{ Volume{5}; Delete; }{ Volume{3,4}; Delete; }

// dielectric
Cylinder(6) = {0, -4.5, 0, 0, 4.5, 0, 100};

// qd
Sphere(7)={0,qdrad,0,qdrad,-Pi/2,Pi/2,2*Pi};


// No framgents
BooleanFragments { Volume{5}; Delete; }{ Volume{6,7}; Delete; }

Field[1] = Cylinder;
Field[1].VIn = 2; // Mesh size inside cylinder
Field[1].VOut = 5; // Mesh size outside cylinder
Field[1].XCenter = 0;
Field[1].YCenter = -4.5;
Field[1].ZCenter = 0;
Field[1].XAxis = 0;
Field[1].YAxis = 45;
Field[1].ZAxis = 0;
Field[1].Radius = 20;

Field[2] = Cylinder;
Field[2].VIn = 0.5; // Mesh size inside cylinder
Field[2].VOut = 5; // Mesh size outside cylinder
Field[2].XCenter = 0;
Field[2].YCenter = -4.5;
Field[2].ZCenter = 0;
Field[2].XAxis = 0;
Field[2].YAxis = 45;
Field[2].ZAxis = 0;
Field[2].Radius = 6;

Field[3] = Min;
Field[3].FieldsList = {1,2};

Background Field = 3;

Mesh.MeshSizeFromCurvature = 1;
Mesh.MinimumElementsPerTwoPi = 30;
Mesh.Algorithm3D = 10;
Mesh.Algorithm = 2;
