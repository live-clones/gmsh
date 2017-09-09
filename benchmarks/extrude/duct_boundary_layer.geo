lc = 0.2;
Point(1) = {0.0,0.0,0.0,lc};
Point(2) = {1,0.0,0.0,lc};
Point(3) = {1,1,0.0,lc};
Point(4) = {0,1,0.0,lc};
Line(1) = {4,3};
Line(2) = {3,2};
Line(3) = {2,1};
Line(4) = {1,4};
Line Loop(1) = {2,3,4,1};
Plane Surface(1) = {1};

// create a cube
Extrude {0,0.0,3} { Surface{1}; }

// remove the volume
Delete { Volume{1}; }

// extrude the boundary of the cube inwards by 0.05, with 5 layers of elements
Extrude { Surface{26, -1, 13, 17, 21, 25}; Layers{5, 0.05}; }

// create inner volume
Surface Loop(159) = {92, 158, 70, 48, 136, 114};
Volume(160) = {159};

General.ExpertMode = 1; // disable warning about mixing Delaunay and extrusion
