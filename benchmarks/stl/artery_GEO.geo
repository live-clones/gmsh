Mesh.CharacteristicLengthFactor=0.15;

//merge the stl triangulation
Merge "artery.stl";

CreateTopology;

Compound Line(10) = {1};
Compound Line(20) = {2};
Compound Line(30) = {3};
Compound Surface(110)={1};

//Line Loop(11)={10};
//Plane Surface(12)={10};
//Line Loop(21)={20};
//Plane Surface(22)={21};
//Line Loop(31)={30};
//Plane Surface(23)={3};

//Create a Volume defined by a surface loop
//Surface Loop(100)={1,10,20,30};
//Volume(101)={100};

//REMESHING THE INITIAL TRIANGULATION in 2D then 3D

//Compound Volume(111)={101};