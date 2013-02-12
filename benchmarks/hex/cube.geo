Mesh.Algorithm = 9; //8 = delquad or 9= 2D R-tree
Mesh.Algorithm3D = 9; // 3D R-tree
Mesh.Recombine3DAll = 1; 
Mesh.Smoothing = 0;

c1 = 0.25; //125;
c2 = 0.05;
Point(1) = {1, 1, -1, c2};
Point(2) = {-1, 1, -1, c1};
Point(3) = {-1, -1, -1, c1};
Point(4) = {1, -1, -1, c1};
Point(5) = {1, 1, 1, c1};
Point(6) = {-1, 1, 1, c1};
Point(7) = {1, -1, 1, c1};
Point(8) = {-1, -1, 1, c1};
Line(1) = {7, 5};
Line(2) = {5, 6};
Line(3) = {6, 8};
Line(4) = {8, 7};
Line(5) = {7, 4};
Line(6) = {4, 1};
Line(7) = {1, 5};
Line(8) = {1, 2};
Line(9) = {2, 6};
Line(10) = {8, 3};
Line(11) = {3, 2};
Line(12) = {3, 4};
Line Loop(13) = {1, -7, -6, -5};
Plane Surface(14) = {13};
Line Loop(15) = {8, 9, -2, -7};
Plane Surface(16) = {15};
Line Loop(17) = {11, 9, 3, 10};
Plane Surface(18) = {17};
Line Loop(19) = {4, 5, -12, -10};
Plane Surface(20) = {19};
Line Loop(21) = {12, 6, 8, -11};
Plane Surface(22) = {21};
Line Loop(23) = {1, 2, 3, 4};
Plane Surface(24) = {23};
Surface Loop(25) = {14, 24, 16, 22, 20, 18};
Volume(26) = {25};

//Recombine Volume {26};

