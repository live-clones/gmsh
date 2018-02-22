SetFactory("OpenCASCADE");
a() = ShapeFromFile("mesh_T106_V3.step");
b() = BooleanFragments{ Surface{a()}; Delete; }{};
Surface Loop(1) = {b()};
Volume(1) = {1};
