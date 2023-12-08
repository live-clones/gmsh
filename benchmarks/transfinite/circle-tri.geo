Point(1)={0,0,0};
Point(2)={1,0,0};
a=Pi/3;
Rotate{{0,0,1},{0,0,0},a}{Duplicata{Point{2};}}
Rotate{{0,0,1},{0,0,0},a}{Duplicata{Point{3};}}
Rotate{{0,0,1},{0,0,0},a}{Duplicata{Point{4};}}
Rotate{{0,0,1},{0,0,0},a}{Duplicata{Point{5};}}
Rotate{{0,0,1},{0,0,0},a}{Duplicata{Point{6};}}

Circle(1)={2,1,3};
Circle(2)={3,1,4};
Circle(3)={4,1,5};
Circle(4)={5,1,6};
Circle(5)={6,1,7};
Circle(6)={7,1,2};

Line(7)={1,2};
Line(8)={1,3};
Line(9)={1,4};
Line(10)={1,5};
Line(11)={1,6};
Line(12)={1,7};


Curve Loop(1) = {7,1,-8};
Plane Surface(1) = {1};
Curve Loop(2) = {8,2,-9};
Plane Surface(2) = {2};
Curve Loop(3) = {9,3,-10};
Plane Surface(3) = {3};
Curve Loop(4) = {10,4,-11};
Plane Surface(4) = {4};
Curve Loop(5) = {11,5,-12};
Plane Surface(5) = {5};
Curve Loop(6) = {12,6,-7};
Plane Surface(6) = {6};


Translate{2.2,0,0}{Duplicata{Point{1:7};}}

Line(13)={2+7,3+7};
Line(14)={3+7,4+7};
Line(15)={4+7,5+7};
Line(16)={5+7,6+7};
Line(17)={6+7,7+7};
Line(18)={7+7,2+7};
Line(19)={1+7,2+7};
Line(20)={1+7,3+7};
Line(21)={1+7,4+7};
Line(22)={1+7,5+7};
Line(23)={1+7,6+7};
Line(24)={1+7,7+7};

Curve Loop(7) = {7+12,1+12,-8-12};
Plane Surface(7) = {7};
Curve Loop(8) = {8+12,2+12,-9-12};
Plane Surface(8) = {8};
Curve Loop(9) = {9+12,3+12,-10-12};
Plane Surface(9) = {9};
Curve Loop(10) = {10+12,4+12,-11-12};
Plane Surface(10) = {10};
Curve Loop(11) = {11+12,5+12,-12-12};
Plane Surface(11) = {11};
Curve Loop(12) = {12+12,6+12,-7-12};
Plane Surface(12) = {12};


n=8;
Transfinite Curve{:}=n;


Mesh.TransfiniteTri=1;
Transfinite Surface{:};
Mesh.Smoothing = 0;


