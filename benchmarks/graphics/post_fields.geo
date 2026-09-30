// scalar, vector and tensor node data on the mesh of mesh_3d.geo (N sets
// its size): View[0] scalar, View[1] vector, View[2] tensor, the first shown
Include "mesh_3d.geo";
Mesh.SurfaceEdges = 0; Mesh.VolumeEdges = 0;
Geometry.Curves = 0; Geometry.Points = 0;
Plugin(NewView).NumComp = 1; Plugin(NewView).Type = "NodeData";
Plugin(NewView).Run;
Plugin(MathEval).View = 0;
Plugin(MathEval).Expression0 = "Sin(3*x)*Cos(2*y)+z";
Plugin(MathEval).Expression1 = ""; Plugin(MathEval).Expression2 = "";
Plugin(MathEval).Expression3 = ""; Plugin(MathEval).Expression4 = "";
Plugin(MathEval).Expression5 = ""; Plugin(MathEval).Expression6 = "";
Plugin(MathEval).Expression7 = ""; Plugin(MathEval).Expression8 = "";
Plugin(MathEval).Run;
Plugin(MathEval).Expression0 = "y-0.5"; Plugin(MathEval).Expression1 = "0.5-x";
Plugin(MathEval).Expression2 = "0.3*z";
Plugin(MathEval).Run;
Plugin(MathEval).Expression0 = "1+x"; Plugin(MathEval).Expression1 = "0.2*y";
Plugin(MathEval).Expression2 = "0"; Plugin(MathEval).Expression3 = "0.2*y";
Plugin(MathEval).Expression4 = "1+y"; Plugin(MathEval).Expression5 = "0";
Plugin(MathEval).Expression6 = "0"; Plugin(MathEval).Expression7 = "0";
Plugin(MathEval).Expression8 = "0.5+z";
Plugin(MathEval).Run;
Delete View[0];
View[1].Visible = 0; View[2].Visible = 0;
