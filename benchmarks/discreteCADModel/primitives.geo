// The primitives of the discrete CAD modeler: their surfaces triangulated at
// most Geometry.DiscreteTolerance (relative to their size) away from the
// exact ones, then meshed like any other entities
SetFactory("Discrete");
Geometry.DiscreteTolerance = 1e-3;

Box(1) = {0, 0, 0, 1, 1, 1};
Sphere(2) = {2, 0.5, 0.5, 0.5};
Cylinder(3) = {3.5, 0.5, 0, 0, 0, 1, 0.5};
Cone(4) = {5, 0.5, 0, 0, 0, 1, 0.5, 0};
Torus(5) = {7.5, 0.5, 0.5, 1, 0.3};
Rectangle(100) = {0, 2, 0, 1, 1};
Disk(101) = {2, 2.5, 0, 0.5, 0.3};

Mesh.MeshSizeMax = 0.1;
