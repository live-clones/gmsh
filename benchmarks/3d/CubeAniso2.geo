lc = 0.1;

Merge "CubeAniso2D.msh";

Surface Loop(100) = {6, 15, 19, 23, 27, 28};
Volume(1) = {100};

Field[2] = MathEvalAniso;
Field[2].m11 = "1./(0.1)^2";
Field[2].m12 = "0";
Field[2].m13 = "0";
Field[2].m22 = "1/(0.1*(y+0.01))^2";
Field[2].m23 = "0";
Field[2].m33 = "1/(0.1)^2";
Background Field = 2;

Mesh.Algorithm3D = 7;
Mesh.Optimize = 0;
