// the mesh nodes should match the points below

Point(1) = {0,0,0,1};
Point(2) = {1,0,0,1};
Point(3) = {3,0,0,1};
Point(4) = {7,0,0,1};
Point(5) = {15,0,0,1};

Point(6) = {0,0.2,0,1};
Point(7) = {15,0.2,0,1};
Line(1) = {6,7};
Transfinite Line {1} = 5 Using Progression 2;
