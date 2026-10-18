// fistula: quad surface mesh of an artery/vein anastomosis (curved tubes, small radius).
// Run: see the Flow parameter below.

SetFactory("OpenCASCADE");
Ra_radius = 1.5;
Cv_radius = 1.25;
R_anastomose_big = 5;
R_anastomose_small = Ra_radius - 0.2;
h = 10;
length_vein = 25;
position_on_artery_anastomose = length_vein + h;

theta = Pi/2;
radius_elbow = (h - Ra_radius)/(1 - Cos(theta));
center_circle_x_coord = -(radius_elbow -h);


SetFactory("OpenCASCADE");
Cylinder(1) = {0, 0, 0, 65, 0, 0, Ra_radius, 2*Pi};

Ellipse(4) = {position_on_artery_anastomose, 0, 0, R_anastomose_big , R_anastomose_small, 0, 2*Pi};

Cylinder(2) = {0, 0, h, length_vein, 0, 0, Cv_radius, 2*Pi};

Curve Loop(7) = {5};
Curve Loop(9) = {4};

Ellipse(10) = {0.95*position_on_artery_anastomose, 0, 5, 0.8*R_anastomose_big , R_anastomose_small, 0, 2*Pi};
Curve Loop(10) = 10;

ThruSections(3) = {7,10,9} ;
BooleanUnion(4) = { Volume{1,2}; Delete; }{ Volume{3}; Delete; };

// Target edge length in model units (equal bounds give uniform sizing).
DefineConstant[
  lc = {1, Min 0.5, Max 5, Step 0.25, Name "Parameters/Target edge length"}
];

Mesh.MeshSizeMin = lc;
Mesh.MeshSizeMax = lc;
Mesh.RandomSeed = 1;
Mesh.SaveAll = 1;
Mesh.SaveParametric = 1;

// Flow: 0 = PACK, Blossom, cavity optimizer      run with   gmsh fistula.geo -2
//       1 = Frontal-Delaunay, Q-Morph            run with   gmsh fistula.geo -
//       2 = PACK, Q-Morph, cavity optimizer      run with   gmsh fistula.geo -2
// (flow 1 meshes inside the script: with -2, Gmsh would mesh again afterwards
// and discard Q-Morph.)
DefineConstant[
  flow = {0, Choices {0 = "PACK + Blossom", 1 = "Frontal-Delaunay + Q-Morph",
                      2 = "PACK + Q-Morph"},
          Name "Parameters/Flow"}
];
If(flow == 1)
  Mesh.Algorithm = 6; // Frontal-Delaunay
  Mesh 2;
  OptimizeMesh "QMorph";
  Save "fistula.msh";
Else
  Mesh.Algorithm = 9; // PACK
  Mesh.PackSizemapMethod = 3;
  Mesh.PackPatterns = 0;
  Mesh.AlgorithmSwitchOnFailure = 0;
  Mesh.RecombineAll = 1;
  Mesh.RecombinationAlgorithm = 1; // Blossom
  Mesh.RecombineMinimumQuality = 0;
  Mesh.PackCleanupMethod = 1;
  Mesh.PackRecombination = (flow == 2); // 0: Blossom, 1: Q-Morph
EndIf
