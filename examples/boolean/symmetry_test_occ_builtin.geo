Geometry.Normals = 40;

SetFactory("Built-in");
Point(1) = {0.1,0,0};
Point(2) = {1.1,0,0};
Point(3) = {1.1,1,0};
Point(4) = {0.1,1,0};
Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line Loop(1) = {1,2,3,4};
Plane Surface(1) = {1};
e() = Extrude {0,0,1} {
  Surface{1};
};
Symmetry {1, 0, 0, 0} {
  Duplicata { Volume{e(1)}; }
}

SetFactory("OpenCASCADE");
Box(100) = {0.1, 2, 0, 1, 1, 1};
Symmetry {1, 0, 0, 0} {
  Duplicata { Volume{100}; }
}
