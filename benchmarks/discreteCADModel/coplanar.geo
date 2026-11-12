// Boolean operations of the discrete CAD modeler with coplanar faces: glued,
// flush, identical
SetFactory("Discrete");
Geometry.DiscreteTolerance = 1e-3;

// two boxes glued on a part of a face
Box(1) = {0, 0, 0, 1, 1, 1};
Box(2) = {1, 0.25, 0.25, 1, 0.5, 0.5};
v() = BooleanUnion{ Volume{1}; Delete; }{ Volume{2}; Delete; };

// a slot flush with a face
Box(3) = {3, 0, 0, 1, 1, 1};
Box(4) = {3.5, 0.25, -0.5, 0.5, 0.5, 2};
v() = BooleanDifference{ Volume{3}; Delete; }{ Volume{4}; Delete; };

// a cylinder standing on a box, a blind hole
Box(5) = {5, 0, 0, 1, 1, 1};
Cylinder(6) = {5.5, 0.5, 1, 0, 0, 1, 0.3};
v() = BooleanUnion{ Volume{5}; Delete; }{ Volume{6}; Delete; };
Box(7) = {7, 0, 0, 1, 1, 1};
Cylinder(8) = {7.5, 0.5, 0, 0, 0, 0.5, 0.3};
v() = BooleanDifference{ Volume{7}; Delete; }{ Volume{8}; Delete; };

// a pipe with a flush flange
Cylinder(9) = {9, 0.5, 0.5, 1, 0, 0, 0.3};
Cylinder(10) = {9, 0.5, 0.5, 0.1, 0, 0, 0.5};
v() = BooleanUnion{ Volume{9}; Delete; }{ Volume{10}; Delete; };

// identical boxes
Box(11) = {11, 0, 0, 1, 1, 1};
Box(12) = {11, 0, 0, 1, 1, 1};
v() = BooleanIntersection{ Volume{11}; Delete; }{ Volume{12}; Delete; };

Mesh.MeshSizeMax = 0.1;
