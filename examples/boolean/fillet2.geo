SetFactory("OpenCASCADE");

Mesh.MeshSizeMin = 1;
Mesh.MeshSizeMax = 1;

a() = ShapeFromFile("component8.step");

f() = Boundary{ Volume{a()}; };
e() = Unique(Boundary{ Surface{f()}; });

Fillet{a()}{e()}{1}
