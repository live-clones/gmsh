Mesh.Algorithm = 7; //Bamg
Mesh.Algorithm3D= 7; //mmg3d
lc = 0.1;

Point(1) = {0.0,0.0,0.0,lc};         
Point(2) = {1,0.0,0.0,lc};         
Point(3) = {1,1,0.0,lc};         
Point(4) = {0,1,0.0,lc};         
Line(1) = {4,3};         
Line(2) = {3,2};         
Line(3) = {2,1};         
Line(4) = {1,4};         
Line Loop(5) = {2,3,4,1};         
Plane Surface(6) = {5};         
Extrude Surface { 6, {0,0.0,1} }; 

/*
Field[1] = Attractor;
Field[1].FacesList = {23};
Field[1].NNodesByEdge = 100;

Field[2] = Threshold;
Field[2].IField = 1;
Field[2].DistMax = 0.3;
Field[2].DistMin = 0.05;
Field[2].LcMax = 0.1;
Field[2].LcMin = 0.01;
Background Field = 2;

Field[3] = BoundaryLayer;
Field[3].IField = 1;
Field[3].hfar = 0.1;
Field[3].hwall_n = 0.005;
Field[3].hwall_t = 0.1;
Background Field = 3;
*/

/*
Field[1] = BoundaryLayer;
Field[1].FaceList = {23};
Field[1].hfar = 0.01;
Field[1].hwall_n = 0.005;
Field[1].hwall_t = 0.1;
Field[1].ratio = 1.0;
Field[1].thickness = 0.5;
Background Field = 1;
*/

Field[2] = MathEvalAniso;
Field[2].m11 = "1./(0.1)^2";
Field[2].m12 = "0";
Field[2].m13 = "0";
Field[2].m22 = "y+1/(0.02)^2";
Field[2].m23 = "0";
Field[2].m33 = "1/(0.1)^2";
Background Field = 2;
