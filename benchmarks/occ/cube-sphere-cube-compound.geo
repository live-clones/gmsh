SetFactory("OpenCASCADE");
a() = ShapeFromFile("cube-sphere-cube-compound.brep");
//Recursive Delete{ Volume{1,3}; }
BooleanFragments{ Volume{a()}; Delete; }{}
//Save "bb.step";
