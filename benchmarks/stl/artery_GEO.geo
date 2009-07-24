Mesh.CharacteristicLengthFactor=0.15;

//merge the stl triangulation
Merge "artery.stl";

CreateTopology;

//Create Inlet and outler surfaces
Line Loop(1) = {1};
Line Loop(2) = {2};
Line Loop(3) = {3};
Plane Surface(10)={1};
Plane Surface(20)={2};
Plane Surface(30)={3};

//Create a Volume defined by a surface loop
Surface Loop(100)={1,10,20,30};
Volume(101)={100};

//REMESHING THE INITIAL TRIANGULATION in 2D then 3D
Compound Surface(110)={1} Boundary {{3},{1,2},{},{}};
Compound Volume(111)={101};