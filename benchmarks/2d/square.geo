//Field[1] = Attractor;
//Field[1].EdgesList = {1};
//Field[1].NNodesByEdge = 10;
//Background Field = 1;

Field[1] = MathEval;
Field[1].F = "1.0"; //0.1*x+0.1";
Background Field = 1;

//Mesh.CharacteristicLengthFactor=1.0;

lc=0.1;
Point(1) = {0, 0, 0}; //,lc};
Point(2) = {0, 10, 0}; //,lc};
Point(3) = {10, 10, 0}; //,lc};
Point(4) = {10, 0, 0}; //,lc};
Line(1) = {2, 3};
Line(2) = {3, 4};
Line(3) = {4, 1};
Line(4) = {1, 2};

Line Loop(5) = {1, 2, 3, 4};
Plane Surface(10) = {5};

//----------------------

//Compound Line(10)={1,2,3,4};
//Compound Surface(100)={10};

Physical Surface(100)={10};
Physical Line(200)={1,2,3,4};




