// A model of size L (1 by default, set e.g. with "-setnumber L 1e-9") drawn in
// four ways, each printed in tiny_model_<i>.png: gmsh tiny_model.geo -
//
// The pictures should not depend on L: tiny_model.py makes them for sizes from
// 1 to 1e-30 and compares them. Tiny models used to be drawn too small, as a
// dot, or with the 3D arrows unlit (the bounding box was taken for flat or
// empty below 1e-6, and the normals of the glyphs underflowed in the shader).

DefineConstant[ L = 1 ];

// mesh at size 1, then read the mesh back at size L
SetFactory("OpenCASCADE");
Box(1) = {0, 0, 0, 1, 0.7, 0.5};
Cylinder(2) = {0.5, 0.35, -0.1, 0, 0, 0.7, 0.2};
BooleanDifference{ Volume{1}; Delete; }{ Volume{2}; Delete; }
Mesh.MeshSizeMax = 0.12;
Mesh 3;
Mesh.ScalingFactor = L;
Save "tiny_model_tmp.msh";
Mesh.ScalingFactor = 1;
Delete Model;
Merge "tiny_model_tmp.msh";

// a scalar and a vector view on the nodes
Plugin(NewView).NumComp = 1; Plugin(NewView).Type = "NodeData";
Plugin(NewView).Run;
Plugin(MathEval).View = 0;
Plugin(MathEval).Expression0 = Sprintf("Sin(6*x/%g)*Cos(5*y/%g)+z/%g", L, L, L);
Plugin(MathEval).Run;
Delete View[0];
Plugin(NewView).NumComp = 3;
Plugin(NewView).Run;
Plugin(MathEval).View = 1;
Plugin(MathEval).Expression0 = Sprintf("0.3-y/%g", L);
Plugin(MathEval).Expression1 = Sprintf("x/%g-0.5", L);
Plugin(MathEval).Expression2 = "0.3";
Plugin(MathEval).Run;
Delete View[1];

General.SmallAxes = 0; General.Trackball = 0;
General.RotationX = 300; General.RotationY = 20; General.RotationZ = 325;
General.GraphicsWidth = 900; General.GraphicsHeight = 700;

// 1: the mesh
View[0].Visible = 0; View[1].Visible = 0;
Mesh.SurfaceFaces = 1; Mesh.SurfaceEdges = 1; Mesh.VolumeEdges = 0;
Mesh.Nodes = 1;
Print "tiny_model_1.png";

// 2: filled iso-values with light, volume mesh edges
Mesh.SurfaceFaces = 0; Mesh.SurfaceEdges = 0; Mesh.Nodes = 0;
Mesh.VolumeEdges = 1;
View[0].Visible = 1; View[0].IntervalsType = 3; View[0].NbIso = 12;
View[0].Light = 1;
Print "tiny_model_2.png";

// 3: iso-surfaces, 3D arrows and mesh normals
Mesh.VolumeEdges = 0; Mesh.Normals = 20;
View[0].IntervalsType = 1; View[0].LineWidth = 2;
View[1].Visible = 1; View[1].VectorType = 4; View[1].GlyphLocation = 2;
Print "tiny_model_3.png";

// 4: exploded elements, zoomed
Mesh.Normals = 0; View[1].Visible = 0;
View[0].IntervalsType = 2; View[0].ShowElement = 1; View[0].Explode = 0.8;
View[0].DrawSkinOnly = 0;
General.ScaleX = 6; General.ScaleY = 6; General.ScaleZ = 6;
Print "tiny_model_4.png";
