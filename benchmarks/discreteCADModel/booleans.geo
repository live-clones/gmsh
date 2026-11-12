// The boolean operations of the discrete CAD modeler: exact on the
// triangulations of the volumes, the surfaces of the results keeping the
// parametrizations of those they come from
SetFactory("Discrete");
Geometry.DiscreteTolerance = 1e-3;

// a box with a spherical corner removed
Box(1) = {0, 0, 0, 1, 1, 1};
Sphere(2) = {1, 1, 1, 0.5};
BooleanDifference(3) = { Volume{1}; Delete; }{ Volume{2}; Delete; };

// a tube, drilled across the seams of its cylinders
Cylinder(4) = {2.5, 0.5, 0, 0, 0, 1, 0.5};
Cylinder(5) = {2.5, 0.5, -0.5, 0, 0, 2, 0.3};
BooleanDifference(6) = { Volume{4}; Delete; }{ Volume{5}; Delete; };
Cylinder(7) = {1.7, 0.5, 0.5, 1.6, 0, 0, 0.1};
BooleanDifference(8) = { Volume{6}; Delete; }{ Volume{7}; Delete; };

// two fused spheres
Sphere(9) = {4.5, 0.5, 0.5, 0.5};
Sphere(10) = {5, 0.5, 0.5, 0.5};
v() = BooleanUnion{ Volume{9}; Delete; }{ Volume{10}; Delete; };

// half a cylinder, without its seam
Cylinder(11) = {7, 0.5, 0, 0, 0, 1, 0.5};
Box(12) = {7, -0.5, 0.25, 1, 2, 0.5};
BooleanIntersection(13) = { Volume{11}; Delete; }{ Volume{12}; Delete; };

// three quarters of a torus
Torus(14) = {9.5, 0.5, 0.5, 1, 0.3};
Box(15) = {9.5, 0.5, -0.5, 2, 2, 2};
BooleanDifference(16) = { Volume{14}; Delete; }{ Volume{15}; Delete; };

Mesh.MeshSizeMax = 0.1;
